#include "global.h"
#include "battle.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "pokemon_icon.h"
#include "pokedex.h"
#include "trainer_pokemon_sprites.h"
#include "field_effect.h"
#include "field_screen_effect.h"

struct BXPYResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 mode;
    u16 monIconSpriteId[PARTY_SIZE * 2];
    u16 heldItemSpriteId[PARTY_SIZE * 2];
    u16 selectorSpriteId;
    u16 speciesID;
    u16 selectedStat;
    u16 selector_x;
    u16 selector_y;
    u16 inputMode;
};

static EWRAM_DATA struct BXPYResources *sBXPYDataPtr = NULL;
static EWRAM_DATA u8 *sBXPYBgBuffer = NULL;

static bool8 BPXY_InitBgs(void);
static bool8 BPXY_LoadGraphics(void);
static void BPXY_Init(MainCallback callback);
static void FadeToBPXYcreen(u8 taskId);
static void BPXY_RunSetup(void);
static bool8 BPXY_DoGfxSetup(void);
static void BPXY_FadeAndBail(void);
static void BPXY_InitWindows(void);
static void Task_BPXYWaitFadeIn(u8 taskId);
static void Task_BPXYMain(u8 taskId);
static void SelectorCallback(struct Sprite *sprite);
static void SampleUi_DrawMonIcon();
static u8 CreateSelector(void);
static void DestroySelector(void);

static const u32 sBPXYBgTiles[] = INCBIN_U32("graphics/ui_bxpy/bxpy_bg.4bpp.smol");
static const u32 sBPXYBgTilemap[] = INCBIN_U32("graphics/ui_bxpy/bxpy_bg.bin.smolTM");
static const u16 sBPXYBgPalette[] = INCBIN_U16("graphics/ui_bxpy/bxpy_bg.gbapal");

#define TAG_ARROW_SELECTOR 30005
#define TAG_HOLD_ITEM 30006

static const u16 sSelector_Pal[] = INCBIN_U16("graphics/ui_bxpy/arrow_selector.gbapal");
static const u32 sSelector_Gfx[] = INCBIN_U32("graphics/ui_bxpy/arrow_selector.4bpp.smol");

static const u16 sHoldIcon_Pal[] = INCBIN_U16("graphics/ui_bxpy/hold_icon.gbapal");
static const u32 sHoldIcon_Gfx[] = INCBIN_U32("graphics/ui_bxpy/hold_icon.4bpp.smol");

#define BPXY_BG_BASE 1
#define BPXY_MENUS 0

static const struct BgTemplate sBPXYBGtemplates[] = {
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .priority = 0
    }
};

enum WindowIds
{
    WINDOW_1,
    PLAYER_PARTY,
    WINDOW_3,
    WINDOW_4,
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [PLAYER_PARTY] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 4,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 15,         // width (per 8 pixels)
        .height = 19,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    DUMMY_WIN_TEMPLATE
};

static const struct OamData sOamData_Selector =
{
    .size = SPRITE_SIZE(8x8),
    .shape = SPRITE_SHAPE(8x8),
    .priority = 1,
};

static const struct CompressedSpriteSheet sSpriteSheet_Selector =
{
    .data = sSelector_Gfx,
    .size = 8*8*4/2,
    .tag = TAG_ARROW_SELECTOR,
};

static const struct SpritePalette sSpritePal_Selector =
{
    .data = sSelector_Pal,
    .tag = TAG_ARROW_SELECTOR
};

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_ARROW_SELECTOR,
    .paletteTag = TAG_ARROW_SELECTOR,
    .oam = &sOamData_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorCallback
};

static const struct SpritePalette sSpritePal_HoldItem =
{
    .data = sHoldIcon_Pal,
    .tag = TAG_HOLD_ITEM
};

static const struct SpriteTemplate sSpriteTemplate_HoldItem =
{
    .tileTag = TAG_HOLD_ITEM,
    .paletteTag = TAG_HOLD_ITEM,
    .oam = &sOamData_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorCallback
};

struct SpriteCordsStruct {
    u8 x;
    u8 y;
};

static const struct OamData sOamData_Menu_Data =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
};

static void SelectorCallback(struct Sprite *sprite)
{
    struct SpriteCordsStruct spriteCords[6][1] = {
        {{16, 47 + 0}},
        {{16, 47 + 18}},
        {{16, 47 + 36}},
        {{16, 47 + 54}},
    };

    sprite->invisible = FALSE;
    sprite->data[0] = 0;

    // sBXPYDataPtr->selectedStat = sBXPYDataPtr->selector_x + (sBXPYDataPtr->selector_y * 2);

    sprite->x = spriteCords[sBXPYDataPtr->selector_y][sBXPYDataPtr->selector_x].x;
    sprite->y = spriteCords[sBXPYDataPtr->selector_y][sBXPYDataPtr->selector_x].y;

    // DebugPrintf("%d", sBXPYDataPtr->selectedStat);
}

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};

static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

#define PLAYER_MON_SLOT_X 4
#define PLAYER_MON_SLOT_Y 6
#define PLAYER_MON_SLOT_Y_OFFSET 24
#define MENU_WINDOW_FONT FONT_BLACK

static void PrintStaticInfo()
{
    u8 text[16];
    FillWindowPixelBuffer(PLAYER_PARTY, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    for (u32 index = 0; index < PARTY_SIZE; index++)
    {
        // Print Nickname
        GetMonData(&gPlayerParty[index], MON_DATA_NICKNAME, gStringVar2);
        if (StringLength(gStringVar2) > 10)
            AddTextPrinterParameterized4(PLAYER_PARTY, FONT_SMALL_NARROWER, PLAYER_MON_SLOT_X, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index), 0, 0, sMenuWindowFontColors[MENU_WINDOW_FONT], TEXT_SKIP_DRAW, gStringVar2);
        else
            AddTextPrinterParameterized4(PLAYER_PARTY, FONT_SMALL, PLAYER_MON_SLOT_X, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index), 0, 0, sMenuWindowFontColors[MENU_WINDOW_FONT], TEXT_SKIP_DRAW, gStringVar2);

        // Is Mon holding item?
        u16 item = GetMonData(&gPlayerParty[index], MON_DATA_HELD_ITEM);
        if (item)
            if (sBXPYDataPtr->heldItemSpriteId[index] == 0xFF)
                sBXPYDataPtr->heldItemSpriteId[index] = CreateSprite(&sSpriteTemplate_HoldItem, PLAYER_MON_SLOT_X, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index) + 9, 0);

        gSprites[sBXPYDataPtr->heldItemSpriteId[index]].invisible = FALSE;
        StartSpriteAnim(&gSprites[sBXPYDataPtr->heldItemSpriteId[index]], 0);
        
        // Print Level
        text[0] = CHAR_EXTRA_SYMBOL;
        text[1] = CHAR_LV_2;
        u32 lvl = GetMonData(&gPlayerParty[index], MON_DATA_LEVEL);
        ConvertIntToDecimalStringN(text + 2, lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringCopyPadded(gStringVar2, gStringVar2, CHAR_SPACE, 10);
        AddTextPrinterParameterized4(PLAYER_PARTY, FONT_SMALL, PLAYER_MON_SLOT_X + 10, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index) + 9, 0, 0, sMenuWindowFontColors[MENU_WINDOW_FONT], TEXT_SKIP_DRAW, text);

        // Print HP
        u8 text[16];
        u32 currentHP = GetMonData(&gPlayerParty[index], MON_DATA_HP);
        u32 maxHP = GetMonData(&gPlayerParty[index], MON_DATA_MAX_HP);
        ConvertIntToDecimalStringN(text, currentHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
        text[3] = CHAR_SLASH;
        ConvertIntToDecimalStringN(text + 4, maxHP, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(PLAYER_PARTY, FONT_SMALL, PLAYER_MON_SLOT_X + 70, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index) + 9, 0, 0, sMenuWindowFontColors[MENU_WINDOW_FONT], TEXT_SKIP_DRAW, text);
    }

    PutWindowTilemap(PLAYER_PARTY);
    CopyWindowToVram(PLAYER_PARTY, 3);
}

static void UpdateTextBox()
{
}

static void BPXY_Init(MainCallback callback)
{
    if ((sBXPYDataPtr = AllocZeroed(sizeof(struct BXPYResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // initialize stuff
    sBXPYDataPtr->gfxLoadState = 0;
    sBXPYDataPtr->savedCallback = callback;
    sBXPYDataPtr->selectorSpriteId = 0xFF;
    sBXPYBgBuffer = AllocZeroed(BG_SCREEN_SIZE);
    
    SetMainCallback2(BPXY_RunSetup);
}

void Task_OpenBXPYMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        BPXY_Init(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        DestroyTask(taskId);
    }
}

void CheckBPXYMenu(void)
{
    CreateTask(Task_OpenBXPYMenu, 10);
}

static void FadeToBPXYcreen(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            SetMainCallback2(BPXY_RunSetup);
            DestroyTask(taskId);
        }
        break;
    }
}

static void BPXY_RunSetup(void)
{
    while (1)
    {
        if (BPXY_DoGfxSetup() == TRUE)
            break;
    }
}

static void BPXY_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void BPXY_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 BPXY_DoGfxSetup(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (BPXY_InitBgs())
        {
            sBXPYDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            BPXY_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (BPXY_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        // LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
        // LoadSpritePalette(&sSpritePal_Selector);
        SampleUi_DrawMonIcon();
        gMain.state++;
        break;
    case 5:
        BPXY_InitWindows();
        // PrintTitleToWindowMainState();
        // sBXPYDataPtr->inputMode = INPUT_SELECT_STAT;
        PrintStaticInfo();
        UpdateTextBox();
        CreateSelector();
        gMain.state++;
        break;
    case 6:
        CreateTask(Task_BPXYWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(BPXY_VBlankCB);
        SetMainCallback2(BPXY_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void BPXY_FreeResources(void)
{
    DestroySelector();
    for (u32 i = 0; i < (PARTY_SIZE * 2); i++)
        FreeResourcesAndDestroySprite(&gSprites[sBXPYDataPtr->monIconSpriteId[i]], sBXPYDataPtr->monIconSpriteId[i]);
    try_free(sBXPYDataPtr);
    try_free(sBXPYBgBuffer);
    FreeAllWindowBuffers();
}


static void Task_BPXYWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBXPYDataPtr->savedCallback);
        BPXY_FreeResources();
        DestroyTask(taskId);
    }
}

static void BPXY_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_BPXYWaitFadeAndBail, 0);
    SetVBlankCallback(BPXY_VBlankCB);
    SetMainCallback2(BPXY_MainCB);
}

static bool8 BPXY_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBXPYBgBuffer = Alloc(0x800);
    if (sBXPYBgBuffer == NULL)
        return FALSE;
    
    memset(sBXPYBgBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBPXYBGtemplates, NELEMS(sBPXYBGtemplates));
    SetBgTilemapBuffer(1, sBXPYBgBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 BPXY_LoadGraphics(void)
{
    switch (sBXPYDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sBPXYBgTiles, 0, 0, 0);
        sBXPYDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sBPXYBgTilemap, sBXPYBgBuffer);
            sBXPYDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sBPXYBgPalette, 0, 32);
        sBXPYDataPtr->gfxLoadState++;
        break;
    default:
        sBXPYDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void BPXY_InitWindows(void)
{
    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_1, 0);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    
    ScheduleBgCopyTilemapToVram(2);
}

static void Task_BPXYWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_BPXYMain;
}

static void Task_BPXYTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBXPYDataPtr->savedCallback);
        BPXY_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_BPXYMain(u8 taskId)
{
    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        if (sBXPYDataPtr->selector_y == 0)
            sBXPYDataPtr->selector_y = 3;
        else
            sBXPYDataPtr->selector_y--;
        UpdateTextBox();
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        if (sBXPYDataPtr->selector_y == 3)
            sBXPYDataPtr->selector_y = 0;
        else
            sBXPYDataPtr->selector_y++;
        UpdateTextBox();
    }
    if (JOY_NEW(A_BUTTON))
    {
        switch (sBXPYDataPtr->selector_y)
        {
            case 0:
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_BPXYTurnOff;
                break;
            case 1:
                PlaySE(SE_SELECT);
                // SetMainCallback2(CB2_InitPartyMenu);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                // sBXPYDataPtr->savedCallback = Task_CheckParty;
                gTasks[taskId].func = Task_BPXYTurnOff;
                break;
            case 2:
                PlaySE(SE_FAILURE);
                break;
            default:
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_BPXYTurnOff;
                break;
        }
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_BPXYTurnOff;
    }
}

#define PLAYER_MON_ICON_SLOT_1_X     20
#define PLAYER_MON_ICON_SLOT_1_Y     12
#define PLAYER_MON_ICON_SLOT_1_Y_OFFSET     24

static void SampleUi_DrawMonIcon()
{
    for (u32 index = 0; index < (PARTY_SIZE * 2); index++)
    {
        if (index < PARTY_SIZE)
        {
            u16 speciesId = GetMonData(&gPlayerParty[index], MON_DATA_SPECIES, NULL);
            sBXPYDataPtr->monIconSpriteId[index] = CreateMonIcon(speciesId, SpriteCB_MonIcon, PLAYER_MON_ICON_SLOT_1_X, PLAYER_MON_ICON_SLOT_1_Y + (PLAYER_MON_ICON_SLOT_1_Y_OFFSET * index), 0, 0);
        }
    }

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
    // gSprites[sBXPYDataPtr->monIconSpriteId[index]].oam.priority = 0;
}

static u8 CreateSelector()
{
    if (sBXPYDataPtr->selectorSpriteId == 0xFF)
        sBXPYDataPtr->selectorSpriteId = CreateSprite(&sSpriteTemplate_Selector, 188, 30, 0);

    gSprites[sBXPYDataPtr->selectorSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sBXPYDataPtr->selectorSpriteId], 0);
    return sBXPYDataPtr->selectorSpriteId;
}

static void DestroySelector()
{
    if (sBXPYDataPtr->selectorSpriteId != 0xFF)
        DestroySprite(&gSprites[sBXPYDataPtr->selectorSpriteId]);
    sBXPYDataPtr->selectorSpriteId = 0xFF;
}
