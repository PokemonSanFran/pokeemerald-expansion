#include "global.h"
#include "battle_main.h"
#include "battle_partner.h"
#include "battle_setup.h"
#include "bg.h"
#include "bxpy.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "item.h"
#include "load_save.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "random.h"
#include "scanline_effect.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "ui_bxpy.h"
#include "window.h"
#include "constants/battle.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static EWRAM_DATA u32 playerEnteredMons[PARTY_SIZE] = {0};
static EWRAM_DATA u32 playerEnteredMonsCounter = 0;

static enum BXPYHealModes BXPY_GetHealMode(void);
static bool8 BXPY_ShouldHealBeforeBattle(void);
static bool8 BXPY_ShouldHealAfterBattle(void);
static void BXPY_ErrorCheck_BringSizeTooLarge(void);
static void BXPY_ErrorCheck_BringSizeNotEnough(void);
static void BXPY_FormatProblemListList(u32 *ids, u32 count, const u8 *(*getName)(u16));
static u32 BXPY_GetUniqueDuplicates(u32 *inputList, u32 inputCount, u32 *uniqueDuplicates);
static void BXPY_ErrorCheck_ClauseSpecies(void);
static void BXPY_ErrorCheck_ClauseItem(void);
static void BXPY_ErrorCheck_ClauseSpecialPokemon(void);
static void Debug_BXPY_PrintArguments(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);
static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);
static void BXPY_PrepareEnemyParty(u32 bringSize, u32 battleFlags);
static void BXPY_GetPlayerEnterMons(u32* enteredMons, u32 pickSize);
static void BXPY_GetEnemyEnterMons(u32* enteredMons, u32 pickSize);
static void BXPY_PrepareParty(u32 pickSize);
static void BXPY_DeleteNonAliveMons(void);
static void BXPY_SelectPartyMembers(struct Pokemon *party, u32* enteredMons);
static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType);
static bool8 BXPY_IsSummaryScreenForEnemy(enum PokemonSummaryScreenMode mode);

static void (*const sBXPYErrorCheckFuncs[])(void) =
{
    [BXPY_ERROR_BRING_SIZE_TOO_LARGE] = BXPY_ErrorCheck_BringSizeTooLarge,
    [BXPY_ERROR_BRING_SIZE_NOT_ENOUGH] = BXPY_ErrorCheck_BringSizeNotEnough,
    [BXPY_ERROR_CLAUSE_SPECIES] = BXPY_ErrorCheck_ClauseSpecies,
    [BXPY_ERROR_CLAUSE_ITEM] = BXPY_ErrorCheck_ClauseItem,
    [BXPY_ERROR_CLAUSE_SPECIAL_POKEMON] = BXPY_ErrorCheck_ClauseSpecialPokemon,
};

STATIC_ASSERT((B_VAR_BXPY != 0 && B_VAR_BXPY <= VARS_END) || BXPY_RETAIN_CHANGES == FALSE, BVarSkyBattleMustBeSetForBXPYToRun);

void BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_BRING_SIZE_TOO_LARGE]();
}

void BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_BRING_SIZE_NOT_ENOUGH]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseSpecies(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_SPECIES]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseItem(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_ITEM]();
}

void BXPY_OverworldRun_ErrorCheck_ClauseSpecialPokemon(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_SPECIAL_POKEMON]();
}

static enum BXPYHealModes BXPY_GetHealMode(void)
{
    return BXPY_HEAL;
}

static bool8 BXPY_ShouldHealBeforeBattle(void)
{
    enum BXPYHealModes mode = BXPY_GetHealMode();
    return (mode == BXPY_HEAL_BEFORE_BATTLE || mode == BXPY_HEAL_ALWAYS);
}

void BXPY_TryHealBeforeBattle(void)
{
    if (BXPY_ShouldHealBeforeBattle())
        HealPlayerParty();
}

static bool8 BXPY_ShouldHealAfterBattle(void)
{
    enum BXPYHealModes mode = BXPY_GetHealMode();
    return (mode == BXPY_HEAL_AFTER_BATTLE || mode == BXPY_HEAL_ALWAYS);
}

void BXPY_TryHealAfterBattle(void)
{
    if (FlagGet(B_FLAG_BXPY))
        return;

    if (!BXPY_ShouldHealAfterBattle())
        return;

    HealPlayerParty();
}

static void BXPY_ErrorCheck_BringSizeTooLarge(void)
{
    gSpecialVar_Result = FALSE;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 maxSize = (VarGet(VAR_BXPY_PARTNER) == PARTNER_NONE) ? bringSize : (bringSize / 2);
    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount <=maxSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,maxSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(maxSize));
}

static void BXPY_ErrorCheck_BringSizeNotEnough(void)
{
    gSpecialVar_Result = FALSE;

    if (BXPY_FORCE_MINIMUM_MONS == FALSE)
        return;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 maxSize = (VarGet(VAR_BXPY_PARTNER) == PARTNER_NONE) ? bringSize : (bringSize / 2);

    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount >= maxSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,bringSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(bringSize));
}

static void BXPY_FormatProblemListList(u32 *ids, u32 count, const u8 *(*getName)(u16))
{
    StringCopy(gStringVar1,COMPOUND_STRING(""));

    for (u32 i = 0; i < count; i++)
    {
        if (i > 0)
        {
            if (i == count - 1)
                StringAppend(gStringVar1, COMPOUND_STRING(" & "));
            else
                StringAppend(gStringVar1, COMPOUND_STRING(",\l"));
        }

        StringAppend(gStringVar1, getName(ids[i]));
    }
}

static u32 BXPY_GetUniqueDuplicates(u32 *inputList, u32 inputCount, u32 *uniqueDuplicates)
{
    u32 duplicateCount = 0;

    for (u32 i = 0; i < inputCount; i++)
    {
        for (u32 j = i + 1; j < inputCount; j++)
        {

            if (inputList[i] == inputList[j])
            {
                bool32 alreadyFlagged = FALSE;
                for (u32 k = 0; k < duplicateCount; k++)
                {
                    if (uniqueDuplicates[k] == inputList[i])
                        alreadyFlagged = TRUE;
                }

                if (!alreadyFlagged)
                    uniqueDuplicates[duplicateCount++] = inputList[i];

                break;
            }
        }
    }
    return duplicateCount;
}

static void BXPY_ErrorCheck_ClauseSpecies(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_SPECIES == FALSE)
        return;

    u32 speciesList[PARTY_SIZE] = {0};
    u32 uniqueDuplicates[PARTY_SIZE] = {0};
    u32 partyCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG)
            speciesList[partyCount++] = species;
    }

    u32 duplicateCount = BXPY_GetUniqueDuplicates(speciesList, partyCount, uniqueDuplicates);

    if (duplicateCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(uniqueDuplicates, duplicateCount, GetSpeciesName);
}

static void BXPY_ErrorCheck_ClauseItem(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_ITEMS == FALSE)
        return;
    u32 itemList[PARTY_SIZE] = {0};
    u32 uniqueDuplicates[PARTY_SIZE] = {0};
    u32 itemCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
            itemList[itemCount++] = item;
    }

    u32 duplicateCount = BXPY_GetUniqueDuplicates(itemList, itemCount, uniqueDuplicates);

    if (duplicateCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(uniqueDuplicates, duplicateCount, GetItemName);
}

static void BXPY_ErrorCheck_ClauseSpecialPokemon(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_SPECIAL_POKEMON == FALSE)
        return;

    u32 bannedMons[PARTY_SIZE];
    u32 bannedCount = 0;

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;

        if ((!gSpeciesInfo[species].isMythical) && (!gSpeciesInfo[species].isFrontierBanned))
            continue;

        bool32 alreadyAdded = FALSE;
        for (u32 k = 0; k < bannedCount; k++)
            if (bannedMons[k] == species)
                alreadyAdded = TRUE;

        if (!alreadyAdded)
            bannedMons[bannedCount++] = species;
    }

    if (bannedCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(bannedMons, bannedCount, GetSpeciesName);
}

static void Debug_BXPY_PrintArguments(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    return;
    DebugPrintf("battleType %d",battleType);
    DebugPrintf("bringSize %d",bringSize);
    DebugPrintf("pickSize %d",pickSize);
    DebugPrintf("trainerA %d",trainerA);
    DebugPrintf("loseTextA %S",loseTextA);
    DebugPrintf("trainerB %d",trainerB);
    if (loseTextB != NULL)
        DebugPrintf("loseTextB %S",loseTextB);
    DebugPrintf("partner %d",partnerId);
}

static void Debug_BXPY_PrintUIStuff()
{
    DebugPrintf("I selected Slot %d for Party Slot %d", (playerEnteredMonsCounter - 1), playerEnteredMons[(playerEnteredMonsCounter - 1)]);
    for (u32 i = 0; i < PARTY_SIZE; i++)
        DebugPrintf("slot%d %d", i, playerEnteredMons[i]);
}

// Entry point for the BXPY GUI
void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    playerEnteredMonsCounter = 0;
    for (u32 i = 0; i < PARTY_SIZE; i++)
        playerEnteredMons[i] = PARTY_SIZE;
    Debug_BXPY_PrintArguments(battleType,bringSize,pickSize,trainerA,loseTextA,trainerB,loseTextB,partnerId);
    BXPY_InitTrainerBattleParams(trainerA,loseTextA,trainerB,loseTextB,partnerId);
    CheckBXPYMenu();
}

void BXPY_SetupBattle(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize)
{
    u32 battleFlags = BXPY_ConvertBattleTypeToFlags(battleType);
    BXPY_PrepareEnemyParty(bringSize,battleFlags);
    BXPY_PrepareParty(pickSize);

    u32 enemyEnteredMons[PARTY_SIZE] = {PARTY_SIZE};

    // BXPY_GetPlayerEnterMons(playerEnteredMons,pickSize);
    BXPY_GetEnemyEnterMons(enemyEnteredMons,pickSize);
    BXPY_SelectPartyMembers(gPlayerParty,playerEnteredMons);
    BXPY_SelectPartyMembers(gEnemyParty,enemyEnteredMons);

    BattleSetup_StartBXPYBattle(battleFlags);
}

/*
UI Stuff 
*/

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

static bool8 BXPY_UI_InitBgs(void);
static bool8 BXPY_LoadGraphics(void);
// static void BXPY_UI_Init(MainCallback callback);
// static void FadeToBXPYcreen(u8 taskId);
static void BXPY_RunSetup(void);
static bool8 BXPY_DoGfxSetup(void);
static void BXPY_FadeAndBail(void);
static void Task_BXPYWaitFadeAndBail(u8 taskId);
static void BXPY_UI_InitWindows(void);
static void Task_BXPYWaitFadeIn(u8 taskId);
static void Task_BXPYMain(u8 taskId);
static void SelectorCallback(struct Sprite *sprite);
static void SampleUi_DrawMonIcon();
static u8 CreateSelector(void);
static void DestroySelector(void);

static const u32 sBXPYBgTiles[] = INCBIN_U32("graphics/ui_bxpy/bxpy_bg.4bpp.smol");
static const u32 sBXPYBgTilemap[] = INCBIN_U32("graphics/ui_bxpy/bxpy_bg.bin.smolTM");
static const u16 sBXPYBgPalette[] = INCBIN_U16("graphics/ui_bxpy/bxpy_bg.gbapal");

#define TAG_ARROW_SELECTOR 30005
#define TAG_HOLD_ITEM 30006
#define TAG_MON_SELECTOR 30007

static const u16 sSelector_Pal[] = INCBIN_U16("graphics/ui_bxpy/arrow_selector.gbapal");
static const u32 sSelector_Gfx[] = INCBIN_U32("graphics/ui_bxpy/arrow_selector.4bpp.smol");

static const u16 sHoldIcon_Pal[] = INCBIN_U16("graphics/ui_bxpy/hold_icon.gbapal");
static const u32 sHoldIcon_Gfx[] = INCBIN_U32("graphics/ui_bxpy/hold_icon.4bpp.smol");

static const u16 sMonSelectorSlot1_Pal[] = INCBIN_U16("graphics/ui_bxpy/mon_selector_slot_1.gbapal");
static const u32 sMonSelectorSlot1_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_1.4bpp.smol");
static const u32 sMonSelectorSlot2_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_2.4bpp.smol");
static const u32 sMonSelectorSlot3_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_3.4bpp.smol");
static const u32 sMonSelectorSlot4_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_4.4bpp.smol");
static const u32 sMonSelectorSlot5_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_5.4bpp.smol");
static const u32 sMonSelectorSlot6_Gfx[] = INCBIN_U32("graphics/ui_bxpy/mon_selector_slot_6.4bpp.smol");

#define BXPY_BG_BASE 1
#define BXPY_MENUS 0

static const struct BgTemplate sBXPYBGtemplates[] = {
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

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_ARROW_SELECTOR,
    .paletteTag = TAG_ARROW_SELECTOR,
    .oam = &sOamData_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorCallback
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

struct SpriteCordsStruct {
    u8 x;
    u8 y;
};

#define PLAYER_SELECTOR_X_START 6
#define PLAYER_SELECTOR_Y_START 18
#define PLAYER_SELECTOR_Y_OFFSET 24
static void SelectorCallback(struct Sprite *sprite)
{
    struct SpriteCordsStruct spriteCords[6][1] = {
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*0}},
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*1}},
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*2}},
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*3}},
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*4}},
        {{PLAYER_SELECTOR_X_START, PLAYER_SELECTOR_Y_START + PLAYER_SELECTOR_Y_OFFSET*5}},
    };

    sprite->invisible = FALSE;
    sprite->data[0] = 0;

    // sBXPYDataPtr->selectedStat = sBXPYDataPtr->selector_x + (sBXPYDataPtr->selector_y * 2);

    sprite->x = spriteCords[sBXPYDataPtr->selector_y][sBXPYDataPtr->selector_x].x;
    sprite->y = spriteCords[sBXPYDataPtr->selector_y][sBXPYDataPtr->selector_x].y;

    // DebugPrintf("%d", sBXPYDataPtr->selectedStat);
}

void CheckBXPYMenu(void)
{
    CreateTask(Task_OpenBXPYMenu, 10);
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
        // u16 item = GetMonData(&gPlayerParty[index], MON_DATA_HELD_ITEM);
        // if (item)
        //     if (sBXPYDataPtr->heldItemSpriteId[index] == 0xFF)
        //         sBXPYDataPtr->heldItemSpriteId[index] = CreateSprite(&sSpriteTemplate_HoldItem, PLAYER_MON_SLOT_X, PLAYER_MON_SLOT_Y + (PLAYER_MON_SLOT_Y_OFFSET * index) + 9, 0);

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

void BXPY_UI_Init(MainCallback callback)
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
    
    SetMainCallback2(BXPY_RunSetup);
}

void Task_OpenBXPYMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        BXPY_UI_Init(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        DestroyTask(taskId);
    }
}

static void BXPY_RunSetup(void)
{
    while (1)
    {
        if (BXPY_DoGfxSetup() == TRUE)
            break;
    }
}

static void BXPY_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void BXPY_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 BXPY_DoGfxSetup(void)
{
    switch(gMain.state)
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
        if (BXPY_UI_InitBgs())
        {
            sBXPYDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            BXPY_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (BXPY_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
        LoadSpritePalette(&sSpritePal_Selector);
        SampleUi_DrawMonIcon();
        gMain.state++;
        break;
    case 5:
        BXPY_UI_InitWindows();
        // PrintTitleToWindowMainState();
        // sBXPYDataPtr->inputMode = INPUT_SELECT_STAT;
        PrintStaticInfo();
        // UpdateTextBox();
        CreateSelector();
        gMain.state++;
        break;
    case 6:
        CreateTask(Task_BXPYWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(BXPY_VBlankCB);
        SetMainCallback2(BXPY_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void BXPY_FreeResources(void)
{
    DestroySelector();
    for (u32 i = 0; i < (PARTY_SIZE * 2); i++)
        FreeResourcesAndDestroySprite(&gSprites[sBXPYDataPtr->monIconSpriteId[i]], sBXPYDataPtr->monIconSpriteId[i]);
    try_free(sBXPYDataPtr);
    try_free(sBXPYBgBuffer);
    FreeAllWindowBuffers();
}

static void Task_BXPYWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBXPYDataPtr->savedCallback);
        BXPY_FreeResources();
        DestroyTask(taskId);
    }
}

static void BXPY_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_BXPYWaitFadeAndBail, 0);
    SetVBlankCallback(BXPY_VBlankCB);
    SetMainCallback2(BXPY_MainCB);
}

static bool8 BXPY_UI_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBXPYBgBuffer = Alloc(0x800);
    if (sBXPYBgBuffer == NULL)
        return FALSE;
    
    memset(sBXPYBgBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBXPYBGtemplates, NELEMS(sBXPYBGtemplates));
    SetBgTilemapBuffer(1, sBXPYBgBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 BXPY_LoadGraphics(void)
{
    switch (sBXPYDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sBXPYBgTiles, 0, 0, 0);
        sBXPYDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sBXPYBgTilemap, sBXPYBgBuffer);
            sBXPYDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sBXPYBgPalette, 0, 32);
        sBXPYDataPtr->gfxLoadState++;
        break;
    default:
        sBXPYDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void BXPY_UI_InitWindows(void)
{
    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_1, 0);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    
    ScheduleBgCopyTilemapToVram(2);
}

static void Task_BXPYWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_BXPYMain;
}

static void Task_BXPYTurnOff(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sBXPYDataPtr->savedCallback);
        BXPY_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_BXPYMain(u8 taskId)
{
    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        if (sBXPYDataPtr->selector_y == 0)
            sBXPYDataPtr->selector_y = 5;
        else
            sBXPYDataPtr->selector_y--;
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        if (sBXPYDataPtr->selector_y == 5)
            sBXPYDataPtr->selector_y = 0;
        else
            sBXPYDataPtr->selector_y++;
    }
    if (JOY_NEW(A_BUTTON))
    {
        if (playerEnteredMonsCounter < 4)
        {
            PlaySE(SE_SELECT);
            playerEnteredMons[playerEnteredMonsCounter] = sBXPYDataPtr->selector_y;
            playerEnteredMonsCounter++;
        } else {
            PlaySE(SE_SELECT);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_BXPYTurnOff;
        }
        Debug_BXPY_PrintUIStuff();
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_BXPYTurnOff;
    }
}

#define PLAYER_MON_ICON_SLOT_1_X            20
#define PLAYER_MON_ICON_SLOT_1_Y            12
#define PLAYER_MON_ICON_SLOT_1_Y_OFFSET     24
#define OPPONENT_MON_ICON_SLOT_1_X          176
#define OPPONENT_MON_ICON_SLOT_1_Y          32
#define OPPONENT_MON_ICON_SLOT_1_X_OFFSET   32
#define OPPONENT_MON_ICON_SLOT_1_Y_OFFSET   32

static void SampleUi_DrawMonIcon()
{
    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentA], FALSE, BATTLE_TYPE_TRAINER);
    u16 speciesId;
    for (u8 index = 0; index < PARTY_SIZE; index++)
    {
        speciesId = GetMonData(&gPlayerParty[index], MON_DATA_SPECIES, NULL);
        sBXPYDataPtr->monIconSpriteId[index] = CreateMonIcon(speciesId, SpriteCB_MonIcon, PLAYER_MON_ICON_SLOT_1_X, PLAYER_MON_ICON_SLOT_1_Y + (PLAYER_MON_ICON_SLOT_1_Y_OFFSET * index), 0, 0);
        speciesId = GetMonData(&gEnemyParty[index], MON_DATA_SPECIES);
        sBXPYDataPtr->monIconSpriteId[index] = CreateMonIcon(speciesId, SpriteCB_MonIcon, OPPONENT_MON_ICON_SLOT_1_X + (OPPONENT_MON_ICON_SLOT_1_X_OFFSET * (index % 2)), OPPONENT_MON_ICON_SLOT_1_Y + (OPPONENT_MON_ICON_SLOT_1_Y_OFFSET * (index / 2)), 0, 0);
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

/*
Misc Functions
*/
static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    InitTrainerBattleParameter();

    TRAINER_BATTLE_PARAM.opponentA = trainerA;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8*)loseTextA;

    if (partnerId != PARTNER_NONE)
        gPartnerTrainerId = TRAINER_PARTNER(partnerId);

    if (trainerB == TRAINER_NONE)
        return;

    TRAINER_BATTLE_PARAM.opponentB = trainerB;
    TRAINER_BATTLE_PARAM.defeatTextB = (u8*)loseTextB;
}

static void BXPY_PrepareEnemyParty(u32 bringSize, u32 battleFlags)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerPartyFromTrainer(&gEnemyParty[0], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentA], TRUE, battleFlags);

    if (TRAINER_BATTLE_PARAM.opponentB == TRAINER_NONE)
        return;

    CreateNPCTrainerPartyFromTrainer(&gEnemyParty[PARTY_SIZE/2], &gTrainers[GetCurrentDifficultyLevel()][TRAINER_BATTLE_PARAM.opponentB], FALSE, battleFlags);
}

static void BXPY_GetPlayerEnterMons(u32* enteredMons, u32 pickSize)
{
    u32 mons[PARTY_SIZE] = {0, 1, 2, 3, 4, 5};

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = PARTY_SIZE;

    // Start BXPY TODO Replace with Pawkkie's logic and UI output
    Shuffle(mons, ARRAY_COUNT(mons), sizeof(mons[0]));

    for (u32 i = 0; i < PARTY_SIZE; i++)
        enteredMons[i] = (i < pickSize) ? mons[i] : PARTY_SIZE;
    // End BXPY TODO Replace with Pawkkie's logic and UI output
}

static void BXPY_GetEnemyEnterMons(u32* enteredMons, u32 pickSize)
{
    BXPY_GetPlayerEnterMons(enteredMons, pickSize);
}

static void BXPY_PrepareParty(u32 pickSize)
{
    SavePlayerParty();
    BXPY_DeleteNonAliveMons();

    if (gPartnerTrainerId == PARTNER_NONE)
        return;

    FillPartnerParty(gPartnerTrainerId, pickSize/2);
}

static void BXPY_DeleteNonAliveMons(void)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_NONE || species == SPECIES_EGG)
            ZeroMonData(&gPlayerParty[i]);

        u32 hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
        if (hp == 0)
            ZeroMonData(&gPlayerParty[i]);
    }
    CompactPartySlots();
}

static void BXPY_SelectPartyMembers(struct Pokemon *party, u32* enteredMons)
{
    struct Pokemon tempParty[PARTY_SIZE];
    u32 participatingPokemonSlot = 0;
    VarSet(B_VAR_SKY_BATTLE,0);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&tempParty[i]);

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 slot = enteredMons[i];
        if (slot == PARTY_SIZE)
            continue;

        participatingPokemonSlot += 1 << slot;
        VarSet(B_VAR_SKY_BATTLE,participatingPokemonSlot);

        CopyMon(&tempParty[i],&party[slot],sizeof(struct Pokemon));
    }

    for (u32 i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party[i]);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        CopyMon(&party[i],&tempParty[i],sizeof(struct Pokemon));
}

static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType)
{
    bool32 hasSecondEnemy = (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE);
    bool32 hasPartner = (gPartnerTrainerId != PARTNER_NONE);

    if (hasSecondEnemy && hasPartner)
        return (BATTLE_TYPE_MULTI | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (hasSecondEnemy && !hasPartner)
        return (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (!hasSecondEnemy && hasPartner)
        return (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER); // from battle_setup.c
    else if (battleType == BXPY_BATTLE_SINGLE)
        return BATTLE_TYPE_TRAINER;
    else
        return (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER);
}

static bool8 BXPY_IsSummaryScreenForEnemy(enum PokemonSummaryScreenMode mode)
{
    return (mode == SUMMARY_MODE_BXPY);
}

bool8 BXPY_ShouldHideEnemyAbility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ABILITY);
}

bool8 BXPY_ShouldHideEnemyNature(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE);
}

bool8 BXPY_ShouldHideEnemyIndividualValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    if (stats != SUMMARY_SKILLS_MODE_IVS)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV);
}

bool8 BXPY_ShouldHideEnemyEffortValues(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    if (stats != SUMMARY_SKILLS_MODE_EVS)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV);
}

bool8 BXPY_ShouldHideEnemyTeraType(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_GIMMICK_TERA);
}

enum Type BXPY_TransformPageInfoType(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species)
{
    if (spriteArrayId == SUMMARY_SCREEN_SPRITE_ID_TYPE_TERA)
        return (BXPY_ShouldHideEnemyTeraType(mode)) ? TYPE_MYSTERY : originalTypeId;

    if (spriteArrayId != SUMMARY_SCREEN_SPRITE_ID_TYPE_1 && spriteArrayId != SUMMARY_SCREEN_SPRITE_ID_TYPE_2)
        return originalTypeId;

    switch (BXPY_SummaryScreen_SpeciesVisibility(mode))
    {
        case BXPY_SPECIES_HIDE:
            return TYPE_MYSTERY;
        case BXPY_SPECIES_SHOW_BASE:
            u32 typeIndex = spriteArrayId - SPRITE_ARR_ID_TYPE;
            return GetSpeciesType(GET_BASE_SPECIES_ID(species), typeIndex);
        default:
        case BXPY_SPECIES_SHOW_TRUE:
            return originalTypeId;
    }
}

enum Type BXPY_TransformPageBattleMoves(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId)
{
    if (spriteArrayId < SUMMARY_SCREEN_SPRITE_ID_TYPE_MOVE_1 || spriteArrayId > SUMMARY_SCREEN_SPRITE_ID_TYPE_MOVE_4)
        return originalTypeId;

    if (BXPY_ShouldHideEnemyMoves(mode))
        return TYPE_MYSTERY;

    return originalTypeId;
}

enum Type BXPY_TransformTypeIfHidden(enum PokemonSummaryScreenMode mode, enum Type originalTypeId, u32 spriteArrayId, u32 species, enum PokemonSummaryScreenPage page)
{
    if (!BXPY_IsSummaryScreenForEnemy(mode))
        return originalTypeId;

    switch (page)
    {
        case PSS_PAGE_INFO:
            return BXPY_TransformPageInfoType(mode, originalTypeId, spriteArrayId, species);
        case PSS_PAGE_BATTLE_MOVES:
            return BXPY_TransformPageBattleMoves(mode, originalTypeId, spriteArrayId);
        default:
            return originalTypeId;
    }
}

bool8 BXPY_ShouldHideEnemyMoves(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_MOVE);
}

enum BXPYTeamPreviewItemModes BXPY_GetEnemyItemVisibilityLevel(void)
{
    return BXPY_TEAM_PREVIEW_SHOW_ENEMY_ITEM;
}

bool8 BXPY_SummaryScreen_ItemVisibility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return BXPY_ITEM_SHOW_ITEM;

    return BXPY_GetEnemyItemVisibilityLevel();
}

bool8 BXPY_SummaryScreen_ShouldHideItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_NO_VISIBILITY);
}

bool8 BXPY_SummaryScreen_ShouldShowHiddenItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_SHOW_POSSESSION);
}

bool8 BXPY_SummaryScreen_ShouldShowFullItem(enum PokemonSummaryScreenMode mode)
{
    return (BXPY_GetEnemyItemVisibilityLevel() == BXPY_ITEM_SHOW_ITEM);
}

const u8 *BXPY_ReturnItemText(enum Item item)
{
    static const u8 sText_Unknown[] = COMPOUND_STRING("Unknown");
    static const u8 sText_Question[] = COMPOUND_STRING("???");
    static const u8 sText_None[] = COMPOUND_STRING("NONE");
    bool32 hasItem = (item != ITEM_NONE);

    switch (BXPY_GetEnemyItemVisibilityLevel())
    {
        default:
        case BXPY_ITEM_SHOW_ITEM:
            if (hasItem)
                return GetItemName(item);
            else
                return sText_None;
        case BXPY_ITEM_NO_VISIBILITY:
            return sText_Unknown;
        case BXPY_ITEM_SHOW_POSSESSION:
            if (hasItem)
                return sText_Question;
            else
                return sText_None;
    }
    return sText_Unknown;
}

enum BXPYTeamPreviewSpeciesModes BXPY_GetEnemySpeciesVisibilityLevel(void)
{
    return BXPY_TEAM_PREVIEW_SHOW_ENEMY_SPECIES;
}

enum BXPYTeamPreviewSpeciesModes BXPY_SummaryScreen_SpeciesVisibility(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return BXPY_SPECIES_SHOW_TRUE;

    return BXPY_GetEnemySpeciesVisibilityLevel();
}

bool8 BXPY_SummaryScreen_ShowBaseSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_SHOW_BASE);
}

bool8 BXPY_SummaryScreen_HideSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_HIDE);
}

bool8 BXPY_SummaryScreen_ShowTrueSpecies(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return (BXPY_GetEnemySpeciesVisibilityLevel() == BXPY_SPECIES_SHOW_TRUE);
}

bool8 BXPY_TeamPreview_ShouldHideEnemyGender(void)
{
    return !(BXPY_TEAM_PREVIEW_SHOW_ENEMY_GENDER);
}

bool8 BXPY_SummaryScreen_ShouldHideEnemyGender(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return BXPY_TeamPreview_ShouldHideEnemyGender();
}

u32 BXPY_SummaryScreen_TransformSpeciesId(enum PokemonSummaryScreenMode mode, u32 originalSpeciesId)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return originalSpeciesId;

    return BXPY_TeamPreview_TransformSpeciesId(originalSpeciesId);
}

u32 BXPY_TeamPreview_TransformSpeciesId(u32 originalSpeciesId)
{
    switch (BXPY_GetEnemySpeciesVisibilityLevel())
    {
        case BXPY_SPECIES_SHOW_TRUE:
            return originalSpeciesId;
        case BXPY_SPECIES_SHOW_BASE:
            return GET_BASE_SPECIES_ID(originalSpeciesId);
        default:
        case BXPY_SPECIES_HIDE:
            return SPECIES_NONE;
    }
}

bool8 BXPY_TeamPreview_ShouldHideEnemyLevel(void)
{
    return !(BXPY_TEAM_PREVIEW_SHOW_ENEMY_LEVEL);
}

bool8 BXPY_SummaryScreen_ShouldHideEnemyLevel(enum PokemonSummaryScreenMode mode)
{
    if (BXPY_IsSummaryScreenForEnemy(mode) == FALSE)
        return FALSE;

    return BXPY_TeamPreview_ShouldHideEnemyLevel();
}

bool8 BXPY_SummaryScreen_ShouldHideStats(enum PokemonSummaryScreenMode mode, enum PokemonSummarySkillsMode stats)
{
    if (stats != SUMMARY_SKILLS_MODE_STATS)
        return FALSE;

    if (BXPY_SummaryScreen_ShouldHideEnemyLevel(mode))
        return TRUE;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV == TRUE)
        return FALSE;

    if (BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV == TRUE)
        return FALSE;

    return (!BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE);
}

