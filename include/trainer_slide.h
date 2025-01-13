#ifndef GUARD_TRAINER_SLIDE_H
#define GUARD_TRAINER_SLIDE_H

#include "constants/trainer_slide.h"

struct MessageStatus
{
    u32 messageInitalized;
    u32 messagePlayed;
};

enum TrainerSlideTargets ShouldDoTrainerSlide(u32, enum TrainerSlideType);
void SetTrainerSlideMessage(enum DifficultyLevel, u32, u32);
void TryInitalizeFirstSTABMoveTrainerSlide(u32, u32, u32);
void TryInitalizeTrainerSlidePlayerLandsFirstCriticalHit(u32);
void TryInitalizeTrainerSlideEnemyLandsFirstCriticalHit(u32);
void TryInitalizeTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32);
void TryInitalizeTrainerSlideEnemyMonUnaffected(u32);
bool32 IsTrainerSlideInitialized(enum TrainerSlideType);
bool32 IsTrainerSlidePlayed(enum TrainerSlideType);
void InitalizeTrainerSlide(enum TrainerSlideType);
void MarkTrainerSlideAsPlayed(enum TrainerSlideType);

#endif // GUARD_TRAINER_SLIDE_H
