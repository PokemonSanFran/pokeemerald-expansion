#ifndef GUARD_CONSTANTS_TRAINER_SLIDE_H
#define GUARD_CONSTANTS_TRAINER_SLIDE_H

enum ComparisonOperators
{
    LESS_THAN,
    EQUAL,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL,
};

enum TrainerSlideType
{
    TRAINER_SLIDE_BEFORE_FIRST_TURN,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE,
    TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN,
    TRAINER_SLIDE_ENEMY_MON_UNAFFECTED,
    TRAINER_SLIDE_LAST_SWITCHIN,
    TRAINER_SLIDE_LAST_HALF_HP,
    TRAINER_SLIDE_LAST_LOW_HP,
    TRAINER_SLIDE_MEGA_EVOLUTION,
    TRAINER_SLIDE_Z_MOVE,
    TRAINER_SLIDE_DYNAMAX,
    TRAINER_SLIDE_COUNT,
};

enum TrainerSlideTargets
{
    TRAINER_SLIDE_TARGET_NONE,
    TRAINER_SLIDE_TARGET_TRAINER_A,
    TRAINER_SLIDE_TARGET_TRAINER_B,
};

#define MULTI_PARTY_SIZE (PARTY_SIZE / 2)

#endif // GUARD_CONSTANTS_TRAINER_SLIDE_H