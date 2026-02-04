#ifndef GUARD_BXPY_H
#define GUARD_BXPY_H

#include "constants/bxpy.h"

void BXPY_Init(enum BXPYBattleTypes battleType, u32 bringSize, u32 pickSize, u32 trainerA, const u8 *loseTextA, u32 trainerB, const u8* loseTextB, u32 partner);
void BXPY_TryHealAfterBattle(void);

#endif // GUARD_BXPY_H
