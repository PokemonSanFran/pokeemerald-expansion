#ifndef GUARD_BXPY_H
#define GUARD_BXPY_H

#include "constants/bxpy.h"

void BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge(void);
void BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough(void);
void BXPY_OverworldRun_ErrorCheck_ClauseSpecies(void);
void BXPY_OverworldRun_ErrorCheck_ClauseItem(void);
void BXPY_OverworldRun_ErrorCheck_ClauseUbers(void);
void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partner);
void BXPY_TryHealAfterBattle(void);
void BXPY_TryHealBeforeBattle(void);

#endif // GUARD_BXPY_H
