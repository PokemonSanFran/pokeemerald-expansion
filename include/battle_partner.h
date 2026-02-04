#ifndef BATTLE_PARTNER_H
#define BATTLE_PARTNER_H

#include "difficulty.h"
#include "constants/battle_partner.h"

extern const struct Trainer gBattlePartners[DIFFICULTY_COUNT][PARTNER_COUNT];

// Start bringXpickY
//void FillPartnerParty(u16 trainerId);
void FillPartnerParty(u16 trainerId, u32 partnerPartyStart);
// End bringXpickY

#endif // BATTLE_PARTNER_H
