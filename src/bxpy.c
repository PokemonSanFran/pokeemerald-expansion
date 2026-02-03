#include "global.h"
#include "pokemon.h"
#include "bxpy.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "tv.h"

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

static void BXPY_ErrorCheck_BringSizeTooLarge(void)
{
    gSpecialVar_Result = FALSE;

    if (VarGet(VAR_BXPY_PARTNER) == PARTNER_NONE)
        return;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 maxSize = bringSize / 2;
    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount <=maxSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,maxSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(maxSize));
}

static void BXPY_ErrorCheck_BringSizeNotEnough(void)
{
    gSpecialVar_Result = FALSE;

    u32 bringSize = VarGet(VAR_BXPY_BRING_SIZE);
    u32 partyCount = CountPartyAliveNonEggMonsExcept(PARTY_SIZE);

    if (partyCount >= bringSize)
        return;

    gSpecialVar_Result = TRUE;

    ConvertIntToDecimalStringN(gStringVar1,bringSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(bringSize));
}

static void BXPY_ErrorCheck_ClauseSpecies(void)
{
    u32 countArray[PARTY_SIZE] = {0};
    u32 partyArray[PARTY_SIZE] = {SPECIES_EGG};
    u32 stringCount = 0;
    u8* stringArray[3] =
    {
        gStringVar1,
        gStringVar2,
        gStringVar3,
    };

    gSpecialVar_Result = TRUE;

    if (BXPY_CLAUSE_SPECIES == TRUE)
        return;

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        u32 species = GetMonData(&gPlayerParty[partyIndex],MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE)
            continue;

        partyArray[partyIndex] = species;
    }


    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        for (u32 secondIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        {
            u32 species = GetMonData(&gPlayerParty[secondIndex],MON_DATA_SPECIES_OR_EGG);
            if (species != partyArray[partyIndex])
            {
                if (secondIndex != (PARTY_SIZE - 1))
                    continue;

                partyArray[partyIndex] = SPECIES_EGG;
            }
        }

    }

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        u32 species = partyArray[partyIndex];

        if (species == SPECIES_EGG)
            continue;

        for (u32 secondIndex = 0; secondIndex < PARTY_SIZE; secondIndex++)
        {
            if (secondIndex == partyIndex)
                continue;

            if (partyArray[secondIndex] == species)
                partyArray[secondIndex] = SPECIES_EGG;
        }
    }

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
    {
        u32 species = partyArray[partyIndex];

        if (species == SPECIES_EGG)
            continue;

        StringCopy(stringArray[stringCount++],GetSpeciesName(species));
    }

    switch(stringCount)
    {
        case 0:
            return;
        default:
        case 1:
            gSpecialVar_Result = TRUE;
            return;
        case 2:
            StringExpandPlaceholders(gStringVar4,COMPOUND_STRING("{STR_VAR_1}\l& {STR_VAR_2}"));
            StringCopy(gStringVar1,gStringVar4);
            gSpecialVar_Result = TRUE;
            return;
        case 3:
            StringExpandPlaceholders(gStringVar4,COMPOUND_STRING("{STR_VAR_1},\l{STR_VAR_2},\l& {STR_VAR_3}"));
            StringCopy(gStringVar1,gStringVar4);
            gSpecialVar_Result = TRUE;
            return;
    }
}


static void BXPY_ErrorCheck_ClauseItem(void)
{
    gSpecialVar_Result = FALSE;
}

static void BXPY_ErrorCheck_ClauseUbers(void)
{
    gSpecialVar_Result = FALSE;
}
