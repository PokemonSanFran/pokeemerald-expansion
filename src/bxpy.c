#include "global.h"
#include "pokemon.h"
#include "bxpy.h"
#include "task.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "load_save.h"
#include "string_util.h"
#include "tv.h"
#include "item.h"
#include "battle_frontier.h"
#include "script_pokemon_util.h"
#include "battle_setup.h"
#include "battle_partner.h"
#include "random.h"
#include "battle_frontier.h"
#include "battle_main.h"
#include "battle_special.h"
#include "constants/battle.h"

static void BXPY_ErrorCheck_BringSizeTooLarge(void);
static void BXPY_ErrorCheck_BringSizeNotEnough(void);
static void BXPY_ErrorCheck_ClauseSpecies(void);
static void BXPY_ErrorCheck_ClauseItem(void);
static void BXPY_ErrorCheck_ClauseUbers(void);
static void BXPY_PrepareEnemyParty(u32 trainerA, u32 trainerB, u32 bringSize, u32 battleFlags);
static void BXPY_PrepareParty(u32 partnerId, u32 pickSize);
static void BXPY_GetPlayerEnterMons(u32* enteredMons, u32 pickSize);
static void BXPY_GetEnemyEnterMons(u32* enteredMons, u32 pickSize);
static void BXPY_SelectPartyMembers(struct Pokemon *party, u32* enteredMons);
static void BXPY_ZeroFaintedMons(void);
static enum BXPYBattleTypes BXPY_UpdateBattleType(enum BXPYBattleTypes battleType, u32 trainerB, u32 partnerId);
static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType);
static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId);

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

void Debug_BXPY_PrintArguments(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
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

void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    //Debug_BXPY_PrintArguments(battleType,bringSize,pickSize,trainerA,loseTextA,trainerB,loseTextB,partnerId);
    u32 battleFlags = BXPY_ConvertBattleTypeToFlags(battleType);
    battleType = BXPY_UpdateBattleType(battleType, trainerB, partnerId);

    BXPY_InitTrainerBattleParams(trainerA,loseTextA,trainerB,loseTextB,partnerId);
    BXPY_PrepareEnemyParty(trainerA, trainerB, bringSize,battleFlags);
    BXPY_PrepareParty(partnerId, pickSize);

    u32 playerEnteredMons[PARTY_SIZE] = {PARTY_SIZE};
    u32 enemyEnteredMons[PARTY_SIZE] = {PARTY_SIZE};

    BXPY_GetPlayerEnterMons(playerEnteredMons,pickSize);
    BXPY_GetEnemyEnterMons(enemyEnteredMons,pickSize);
    BXPY_SelectPartyMembers(gPlayerParty,playerEnteredMons);
    BXPY_SelectPartyMembers(gEnemyParty,enemyEnteredMons);

    BattleSetup_StartBXPYBattle(battleFlags);
}

static void BXPY_InitTrainerBattleParams(u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partnerId)
{
    InitTrainerBattleParameter();

    TRAINER_BATTLE_PARAM.opponentA = trainerA;
    TRAINER_BATTLE_PARAM.defeatTextA = (u8*)loseTextA;

    if (trainerB == TRAINER_NONE)
        return;

    TRAINER_BATTLE_PARAM.opponentB = trainerB;
    TRAINER_BATTLE_PARAM.defeatTextB = (u8*)loseTextB;

    if (partnerId == PARTNER_NONE)
        return;

    gPartnerTrainerId = TRAINER_PARTNER(partnerId);
}

static void BXPY_PrepareEnemyParty(u32 trainerA, u32 trainerB, u32 bringSize, u32 battleFlags)
{
    TRAINER_BATTLE_PARAM.opponentA = trainerA;
    TRAINER_BATTLE_PARAM.opponentB = trainerB;

    ZeroEnemyPartyMons();
    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &gTrainers[GetCurrentDifficultyLevel()][trainerA], TRUE, battleFlags);

    if (trainerB == TRAINER_NONE)
        return;

    CreateNPCTrainerPartyFromTrainer(gEnemyParty, &gTrainers[GetCurrentDifficultyLevel()][trainerB], FALSE, battleFlags);
}

static void BXPY_GetPlayerEnterMons(u32* enteredMons, u32 pickSize)
{
    u32 mons[PARTY_SIZE] = {0, 1, 2, 3, 4, 5};

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        enteredMons[i] = PARTY_SIZE;
    }

    Shuffle(mons, PARTY_SIZE, sizeof(mons[0]));

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        if (i < pickSize)
            enteredMons[i] = mons[i];
        else
            enteredMons[i] = PARTY_SIZE;
    }
}

static void BXPY_GetEnemyEnterMons(u32* enteredMons, u32 pickSize)
{
    BXPY_GetPlayerEnterMons(enteredMons, pickSize);
}

static void BXPY_PrepareParty(u32 partnerId, u32 pickSize)
{
    SavePlayerParty();
    BXPY_ZeroFaintedMons();

    if (partnerId == PARTNER_NONE)
        return;

    FillPartnerParty(partnerId, (pickSize/2));
}

static void BXPY_ZeroFaintedMons(void)
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

static enum BXPYBattleTypes BXPY_UpdateBattleType(enum BXPYBattleTypes battleType, u32 trainerB, u32 partnerId)
{
    bool32 hasSecondEnemy = (trainerB != TRAINER_NONE);
    bool32 hasPartner = (partnerId != PARTNER_NONE);

    if (hasSecondEnemy && hasPartner)
        return BXPY_BATTLE_MULTI_2v2;
    else if (hasSecondEnemy && !hasPartner)
        return BXPY_BATTLE_MULTI_1v2;
    else if (!hasSecondEnemy && hasPartner)
        return BXPY_BATTLE_MULTI_2v1;
    else
        return battleType;
}

static u32 BXPY_ConvertBattleTypeToFlags(enum BXPYBattleTypes battleType)
{
    switch (battleType)
    {
        default:
        case BXPY_BATTLE_SINGLE:
            return BATTLE_TYPE_TRAINER;
        case BXPY_BATTLE_DOUBLE:
            return (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_TRAINER);
        case BXPY_BATTLE_MULTI_2v2:
        case BXPY_BATTLE_MULTI_1v2:
        case BXPY_BATTLE_MULTI_2v1:
            return (BATTLE_TYPE_MULTI | BATTLE_TYPE_TRAINER);
    }
}
