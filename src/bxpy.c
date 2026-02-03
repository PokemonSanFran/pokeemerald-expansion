#include "global.h"
#include "pokemon.h"
#include "bxpy.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "load_save.h"
#include "string_util.h"
#include "tv.h"
#include "item.h"
#include "script_pokemon_util.h"

static void BXPY_ErrorCheck_BringSizeTooLarge(void);
static void BXPY_ErrorCheck_BringSizeNotEnough(void);
static void BXPY_ErrorCheck_ClauseSpecies(void);
static void BXPY_ErrorCheck_ClauseItem(void);
static void BXPY_ErrorCheck_ClauseUbers(void);

static void (*const sBXPYErrorCheckFuncs[])(void) =
{
    [BXPY_ERROR_BRING_SIZE_TOO_LARGE] = BXPY_ErrorCheck_BringSizeTooLarge,
    [BXPY_ERROR_BRING_SIZE_NOT_ENOUGH] = BXPY_ErrorCheck_BringSizeNotEnough,
    [BXPY_ERROR_CLAUSE_SPECIES] = BXPY_ErrorCheck_ClauseSpecies,
    [BXPY_ERROR_CLAUSE_ITEM] = BXPY_ErrorCheck_ClauseItem,
    [BXPY_ERROR_CLAUSE_UBERS] = BXPY_ErrorCheck_ClauseUbers,
};

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

void BXPY_OverworldRun_ErrorCheck_ClauseUbers(void)
{
    sBXPYErrorCheckFuncs[BXPY_ERROR_CLAUSE_UBERS]();
}

enum BXPYHealModes BXPY_GetHealMode(void)
{
    return BXPY_HEAL;
}

bool8 BXPY_ShouldHealBeforeBattle(void)
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
    if (BXPY_ShouldHealAfterBattle())
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
    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount >= bringSize)
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

static void BXPY_ErrorCheck_ClauseUbers(void)
{
    gSpecialVar_Result = FALSE;
    if (BXPY_CLAUSE_UBERS == FALSE)
        return;

    u32 bannedMons[PARTY_SIZE];
    u32 bannedCount = 0;
    u32 restrictedMons[] =
    {
        SPECIES_MEWTWO,
        SPECIES_LUGIA,
        SPECIES_HO_OH,
        SPECIES_KYOGRE,
        SPECIES_GROUDON,
        SPECIES_RAYQUAZA,
        SPECIES_DIALGA,
        SPECIES_DIALGA_ORIGIN,
        SPECIES_PALKIA,
        SPECIES_PALKIA_ORIGIN,
        SPECIES_GIRATINA_ALTERED,
        SPECIES_GIRATINA_ORIGIN,
        SPECIES_RESHIRAM,
        SPECIES_ZEKROM,
        SPECIES_KYUREM,
        SPECIES_KYUREM_BLACK,
        SPECIES_KYUREM_WHITE,
        SPECIES_COSMOG,
        SPECIES_COSMOEM,
        SPECIES_SOLGALEO,
        SPECIES_LUNALA,
        SPECIES_NECROZMA,
        SPECIES_NECROZMA_DUSK_MANE,
        SPECIES_NECROZMA_DAWN_WINGS,
        SPECIES_ZACIAN,
        SPECIES_ZACIAN_CROWNED,
        SPECIES_ZAMAZENTA,
        SPECIES_ZAMAZENTA_CROWNED,
        SPECIES_ETERNATUS,
        SPECIES_CALYREX,
        SPECIES_CALYREX_ICE,
        SPECIES_CALYREX_SHADOW,
        SPECIES_KORAIDON,
        SPECIES_MIRAIDON,
        SPECIES_TERAPAGOS,
    };

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;

        for (u32 j = 0; j < ARRAY_COUNT(restrictedMons); j++)
        {
            if (species != restrictedMons[j] && (!gSpeciesInfo[species].isMythical))
                continue;

            bool32 alreadyAdded = FALSE;
            for (u32 k = 0; k < bannedCount; k++)
                if (bannedMons[k] == species)
                    alreadyAdded = TRUE;

            if (!alreadyAdded)
                bannedMons[bannedCount++] = species;

            break;
        }
    }

    if (bannedCount == 0)
        return;

    gSpecialVar_Result = TRUE;
    BXPY_FormatProblemListList(bannedMons, bannedCount, GetSpeciesName);
}

void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partner)
{
    DebugPrintf("battleType %d",battleType);
    DebugPrintf("bringSize %d",bringSize);
    DebugPrintf("pickSize %d",pickSize);
    DebugPrintf("trainerA %d",trainerA);
    DebugPrintf("loseTextA %S",loseTextA);
    DebugPrintf("trainerB %d",trainerB);
    if (loseTextB != NULL)
        DebugPrintf("loseTextB %S",loseTextB);
    DebugPrintf("partner %d",partner);

    BXPY_PrepareParty();
    return;
}

void BXPY_PrepareParty(void)
{
    SavePlayerParty();
    BXPY_ZeroFaintedMons();
}

void BXPY_ZeroFaintedMons(void)
{
    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        u32 hp = GetMonData(&gPlayerParty[i], MON_DATA_HP);
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE || species == SPECIES_EGG || hp == 0)
            ZeroMonData(&gPlayerParty[i]);
    }
    CompactPartySlots();
}
