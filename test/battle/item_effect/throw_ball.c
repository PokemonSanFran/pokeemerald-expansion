#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Ball Animations: Show all Ball animations")
{
    u16 ball = 0;
    PARAMETRIZE { ball = BALL_STRANGE; }
    PARAMETRIZE { ball = BALL_POKE; }
    PARAMETRIZE { ball = BALL_GREAT; }
    PARAMETRIZE { ball = BALL_ULTRA; }
    PARAMETRIZE { ball = BALL_MASTER; }
    PARAMETRIZE { ball = BALL_PREMIER; }
    PARAMETRIZE { ball = BALL_HEAL; }
    PARAMETRIZE { ball = BALL_NET; }
    PARAMETRIZE { ball = BALL_NEST; }
    PARAMETRIZE { ball = BALL_DIVE; }
    PARAMETRIZE { ball = BALL_DUSK; }
    PARAMETRIZE { ball = BALL_TIMER; }
    PARAMETRIZE { ball = BALL_QUICK; }
    PARAMETRIZE { ball = BALL_REPEAT; }
    PARAMETRIZE { ball = BALL_LUXURY; }
    PARAMETRIZE { ball = BALL_LEVEL; }
    PARAMETRIZE { ball = BALL_LURE; }
    PARAMETRIZE { ball = BALL_MOON; }
    PARAMETRIZE { ball = BALL_FRIEND; }
    PARAMETRIZE { ball = BALL_LOVE; }
    PARAMETRIZE { ball = BALL_FAST; }
    PARAMETRIZE { ball = BALL_HEAVY; }
    PARAMETRIZE { ball = BALL_DREAM; }
    PARAMETRIZE { ball = BALL_SAFARI; }
    PARAMETRIZE { ball = BALL_SPORT; }
    PARAMETRIZE { ball = BALL_PARK; }
    PARAMETRIZE { ball = BALL_BEAST; }
    PARAMETRIZE { ball = BALL_CHERISH; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ball(ball); }
        OPPONENT(SPECIES_WOBBUFFET) {Ball(ball);}
    } WHEN {
        TURN { MOVE(player, MOVE_HELPING_HAND); MOVE(opponent, MOVE_HELPING_HAND); }
    } SCENE {
        SEND_IN_MESSAGE("Wobbuffet");
    }
}

WILD_BATTLE_TEST("Ball Animations: Show all Ball catch animations")
{
    u16 throw = 0;
    PARAMETRIZE { throw = ITEM_STRANGE_BALL;}
    PARAMETRIZE { throw = ITEM_POKE_BALL;}
    PARAMETRIZE { throw = ITEM_GREAT_BALL;}
    PARAMETRIZE { throw = ITEM_ULTRA_BALL;}
    PARAMETRIZE { throw = ITEM_MASTER_BALL;}
    PARAMETRIZE { throw = ITEM_PREMIER_BALL;}
    PARAMETRIZE { throw = ITEM_HEAL_BALL;}
    PARAMETRIZE { throw = ITEM_NET_BALL;}
    PARAMETRIZE { throw = ITEM_NEST_BALL;}
    PARAMETRIZE { throw = ITEM_DIVE_BALL;}
    PARAMETRIZE { throw = ITEM_DUSK_BALL;}
    PARAMETRIZE { throw = ITEM_TIMER_BALL;}
    PARAMETRIZE { throw = ITEM_QUICK_BALL;}
    PARAMETRIZE { throw = ITEM_REPEAT_BALL;}
    PARAMETRIZE { throw = ITEM_LUXURY_BALL;}
    PARAMETRIZE { throw = ITEM_LEVEL_BALL;}
    PARAMETRIZE { throw = ITEM_LURE_BALL;}
    PARAMETRIZE { throw = ITEM_MOON_BALL;}
    PARAMETRIZE { throw = ITEM_FRIEND_BALL;}
    PARAMETRIZE { throw = ITEM_LOVE_BALL;}
    PARAMETRIZE { throw = ITEM_FAST_BALL;}
    PARAMETRIZE { throw = ITEM_HEAVY_BALL;}
    PARAMETRIZE { throw = ITEM_DREAM_BALL;}
    PARAMETRIZE { throw = ITEM_SAFARI_BALL;}
    PARAMETRIZE { throw = ITEM_SPORT_BALL;}
    PARAMETRIZE { throw = ITEM_PARK_BALL;}
    PARAMETRIZE { throw = ITEM_BEAST_BALL;}
    PARAMETRIZE { throw = ITEM_CHERISH_BALL;}

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, throw, partyIndex: 0); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    }
}
TO_DO_BATTLE_TEST("Poke Balls can't be thrown when there's 2 opposing wild battlers")
TO_DO_BATTLE_TEST("Poke Balls can't be thrown when there's no space in the Pokemon Storage System")
TO_DO_BATTLE_TEST("Poke Balls can't be thrown when an opposing wild battler is in a semi-invulnerable state")
TO_DO_BATTLE_TEST("Poke Balls can't be thrown when B_FLAG_NO_CATCHING is set")
