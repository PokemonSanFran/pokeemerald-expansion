# INTRODUCTION

`pokeemerald-expansion` is a modification of pret's decomp project, `pokeemereald`. This modification has several goals:

- Allow fangame developers that are using `pokeemerald` as a base to quickly and easily use key features from [main series](https://bulbapedia.bulbagarden.net/wiki/Core_series) Pokemon games.
- Reduce the barrier of entry for fangame developers to get into decomplilation hacking.
- Provide fangame developers a collection of optional quality of life (QoL) improvements to improve developer and player experience.

`pokeemerald-expansion` is a collection of different features, fixes and modifications from hundreds of different developers, artists and players to help make a comprensive experience.

This document's goal is to detail all of the features available to developers that have chosen to use `pokeemerald-expansion`. 

## OPTIONALITY
One of the best features of `pokeemerald-expansion` is that all of the features listed below are optional. If developers do not want to use a feature listed here, they can fairly easily disable or remove it from their project. `pokeemerald-expansion` allows develoeprs to pick and choose which featues they want to use.

## VERSION
This document is accurate as of Version 1.4.2 (Mar 29 2023), and will be updated as new features as added.

## READING THIS DOCUMENT

All of the features in this document are roughly organized by category, and then is shown as follows:

// TODO Anatomy pic

    A. **Top Level Category**: The group of feature that this feature belongs with.
    B. **Sub-category**: A subgroup of features that this feature belongs with.
    C. **Feature Name**
    D. **Gif or image of feature**: A gif showing the video in action.
    E. **Feature Description**: A short description of how the feature works.
    F. **How to use**: How the developer can enable, configure, or use this feature.

# POKEMON

## SPECIES AND FORMS

# ITEMS

# MOVES AND BATTLE

## BATTLE

## CALCULATIONS
### Critical Hit Chance
//gif of sirfetch'd holding a leek, using slash and getting 3 crits in a row
The chances of critical hits landing have changed throughout the generations, and this configuration allows the developers to pick which generation's rules are followed.
[More Info]()
**Usage**: Developers can change the value of `B_CRIT_CHANCE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Critical Hit Damage Multiplier
//Gif
Starting in Generation 6, critical hit damage is multiplied by 1.5 instead of 2.
[More Info]()
**Usage**: Developers can change the value of `B_CRIT_MULTIPLIER` in `include/config/battle.h`, which will make this change for all battles in the game.

### Paralysis Speed Redction
//Gif
Starting in Generation 7, the speed of a Pokémon that is paralyzed is decreased by 50% instead of 75%.
[More Info]()
**Usage**: Developers can change the value of `B_PARALYSIS_SPEED` in `include/config/battle.h`, which will make this change for all battles in the game.

### Confusion Self-Damage
//Gif
Starting in Generation 7, the damage a Pokémon takes when it hits itself in confusion was reduced from 50% to 33%.
[More Info]()
**Usage**: Developers can change the value of `B_CONFUSION_SELF_DMG_CHANCE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Multi-Hit Move Probability
//Gif
Starting in Generation 5, the percentage chance of the determined number of hits changes.
[More Info]()
**Usage**: Developers can change the value of `B_MULTI_HIT_CHANCE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Whiteout Money
//Gif
Starting in Generation 7, the amount of money lost by losing a battle is determined by the amount of badges earned instead of dividing the player's money in half.
[More Info]()
**Usage**: Developers can change the value of `B_WHITEOUT_MONEY` in `include/config/battle.h`, which will make this change for all battles in the game.

## EXPERIENCE AND STATS
### Catch Experience
//Gif
Starting in Generation 6, the player's Pokémon get experience when the player catches a Pokémon.
[More Info]()
**Usage**: Developers can change the value of `B_EXP_CATCH` in `include/config/battle.h`, which will make this change for all battles in the game.

### Trainer Experience Multiplier
//Gif
Starting in Generation 7, Trainer Battles do not multiply gained experience by 1.5 as they did in previous generations.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all battles in the game.

### Participant Experience Split
//Gif
Starting in Generation 6, all participating Pokémon recieve full experiencein battle, instead of a percentage of the total gained experience.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all battles in the game.

### Scaled Experience Gain
//Gif
Starting in Generation 7 (and also in Generation 5), the experience a Pokémon gains in battle changed based on the difference between the defeated Pokémon's level and the Pokémon gaining experience.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all battles in the game.

### Badge Boost
//Gif
Starting in Generation 4, Gym Badges no longer boost a player's Pokémon's stats.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all Pokémon.

### Level 100 EV Gain
//Gif
Starting in Generation 5, Pokémon can gain EVs even when they are Level 100.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all Pokémon.

### Recalculate Stats
//Gif
Starting in Generation 5, Pokémon stat are recalculated after every battle they participate in, as opposed to recalculating when they are put in the PC.
[More Info]()
**Usage**: Developers can change the value of `` in `include/config/battle.h`, which will make this change for all Pokémon.

## DAMAGE
### Burn
//Gif
Starting in Generation 7, burned Pokémon lose 1/16th of their max HP after every turn, instead of 1/8th.
[More Info]()
**Usage**: Developers can change the value of `B_BURN_DAMAGE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Facade
//Gif
Starting in Generation 6, burn's effect of reducing the Attack stat no longer applies when the burned Pokémon uses the move Facade.
[More Info]()
**Usage**: Developers can change the value of `B_BURN_FACADE_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Binding Moves
//Gif
Starting in Generation 6, binding move deal 1/8 of the target Pokémon's max HP instead of 1/16. (With Binding Band, 1/6 and 1/8 respectively.)
[More Info]()
**Usage**: Developers can change the value of `B_BINDING_DAMAGE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Psywave
//Gif
In every generation, the formula to calculate Psywave's damage changes.
[More Info]()
**Usage**: Developers can change the value of `B_PSYWAVE_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Payback
//Gif
Starting in Generation 5, if the opponent switches out, Payback's damage will no longer be doubled.
[More Info]()
**Usage**: Developers can change the value of `B_PAYBACK_SWITCH_BOOST` in `include/config/battle.h`, which will make this change for all battles in the game.

### Hidden Power's Base Power
//Gif
Starting in Generation 6, Hidden Power's base power was set to always be 60, as opposed to being determined by the Pokémon's IVs.
[More Info]()
**Usage**: Developers can change the value of `B_HIDDEN_POWER_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Rough Skin / Iron Barbs
//Gif
Starting in Generation 4, Rough Skin and Iron Barb's contact damage is 1/8th of attacking Pokémon's max HP instead of 1/16th.
[More Info]()
**Usage**: Developers can change the value of `B_ROUGH_SKIN_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Knock Off
//Gif
Starting in Generation 6, Knock Off deals 50% more damage when the target Pokémon loses their item as a result of Knock Off.
[More Info]()
**Usage**: Developers can change the value of `B_KNOCK_OFF_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Water Sport / Mud Sport Reduction
//Gif
Starting in Generation 5, Water/Mud Sport reduce Fire/Electric-type damage by 67% instead of 50%.
[More Info]()
**Usage**: Developers can change the value of `B_SPORT_DMG_REDUCTION` in `include/config/battle.h`, which will make this change for all battles in the game.

### Explosion Defense
//Gif
Starting in Generation 5, Self-Destruct and Explosion no longer halves the targets' defense.
[More Info]()
**Usage**: Developers can change the value of `B_EXPLOSION_DEFENSE` in `include/config/battle.h`, which will make this change for all battles in the game.

### Parental Bond
//Gif
Starting in Generation 7, Parental Bond's second hit does 25% of the initial hits damage, as opposed to 50%.
[More Info]()
**Usage**: Developers can change the value of `B_PARENTAL_BOND_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

### Multi Target Damage
//Gif
Starting in Generation 4, damage dealt by moves that hit multiple targets at once is reduced to 75%, as opposed, it was 50%.
[More Info]()
**Usage**: Developers can change the value of `B_MULTIPLE_TARGETS_DMG` in `include/config/battle.h`, which will make this change for all battles in the game.

## TYPE INTERACTIONS
### Ghost Trapping Immunity
//Gif
Starting in Generation 6, Ghost-type can escape any Wild Battle, and are immune to trapping abilities or moves (Shadow Tag or Mean Look).
[More Info]()
**Usage**: Developers can change the value of `B_GHOSTS_ESCAPE` in `include/config/battle.h`, which will make this change for all battles in the game.


### Electric Paralysis Immunity
//Gif
Starting in Generation 6, Electric-type Pokémon can't be paralyzed.
[More Info]()
**Usage**: Developers can change the value of `B_PARALYZE_ELECTRIC` in `include/config/battle.h`, which will make this change for all battles in the game.


### Grass Powder Immunity
//Gif
Starting in Generation 6, Grass-type Pokémon are immune to powder and spore moves.
[More Info]()
**Usage**: Developers can change the value of `B_POWDER_GRASS` in `include/config/battle.h`, which will make this change for all battles in the game.


### Steel Resistances
//Gif
Starting in Generation 6, Steel-type Pokémon no longer resist Dark-type and Ghost-type moves.
[More Info]()
**Usage**: Developers can change the value of `B_STEEL_RESISTANCES` in `include/config/battle.h`, which will make this change for all battles in the game.


### Dark Prankster Immunity
//Gif
Starting in Generation 7, Dark-type Pokémon are now immune to attacking Pokémon's moves that gain priority due to Prankster, including moves called by moves that call other moves (such as Assist and Nature Power) and excluding moves that are repeated as a result of Prankster-affected Instruct or moves that occur earlier than their usual order due to Prankster-affected After You.

[More Info]()
**Usage**: Developers can change the value of `B_PRANKSTER_DARK_TYPES` in `include/config/battle.h`, which will make this change for all battles in the game.


### Ice Sheer Cold Immunity
//Gif
Starting in Generation 7, Ice-types are immune to Sheer Cold.
//
[More Info]()
**Usage**: Developers can change the value of `B_SHEER_COLD_IMMUNITY` in `include/config/battle.h`, which will make this change for all battles in the game.


### Roost Type Conversion
//Gif
Starting in Generation 5, if a pure Flying-type Pokémon successfully uses Roost, it will become Normal-type until the end of the turn.
[More Info]()
**Usage**: Developers can change the value of `B_ROOST_PURE_FLYING` in `include/config/battle.h`, which will make this change for all battles in the game.

## BATTLE TURNS
### Binding
//Gif
Starting in Generation 5, binding moves last for 4-5 turns instead of 2-5 turns. (With Grip Claw, 7 and 5 turns respectively.)
[More Info]()
**Usage**: Developers can change the value of `B_BINDING_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Uproar
//Gif
Starting in Generation 5, Uproar lasts for 3 turns instead of 2-5 turns.
[More Info]()
**Usage**: Developers can change the value of `B_UPROAR_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Disable
//Gif
In every generation, the length of Disable's effect on the target changes.
[More Info]()
**Usage**: Developers can change the value of `B_DISABLE_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Tailwind
//Gif
Starting in Generation 5, Tailwind lasts 4 turns instead of 3.
[More Info]()
**Usage**: Developers can change the value of `B_TAILWIND_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Sleep
//Gif
Starting in Generation 5, Pokémon stay asleep for 1-3 turns instead of 2-5 turns.
[More Info]()
**Usage**: Developers can change the value of `B_SLEEP_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Taunt
//Gif
Starting in Generation 5, the duration of Taunt is now three turns if the user acts before the target, or four turns if the target acted before the user. The number of turns also changes in Generation 3 and Generation 4.
[More Info]()
**Usage**: Developers can change the value of `B_TAUNT_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Water Sport / Mud Sport
//Gif
Starting in Generation 6, Water / Mud Sport is now active for five turns, even if the user switches out.
[More Info]()
**Usage**: Developers can change the value of `B_SPORT_TURNS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Mega Evolution Order
//Gif
Starting in Generation 7, a Pokémon's Speed after it undergoes Mega Evolution or Primal Reversion is used to determine turn order, not its Speed before the transformation.
[More Info]()
**Usage**: Developers can change the value of `B_MEGA_EVO_TURN_ORDER` in `include/config/battle.h`, which will make this change for all battles in the game.

### Recalcuate Order
//Gif
Starting in Generation 8, switching or using a move affects the current turn's order of actions, as opposed to turn order only changing between turns.
[More Info]()
**Usage**: Developers can change the value of `B_RECALC_TURN_AFTER_ACTIONS` in `include/config/battle.h`, which will make this change for all battles in the game.

### Replace Fainted Ally Order
//Gif
Starting in Generation 4, sending out a Pokémon to replaced a fainted ally happens at the end of the turn instead of after each action.
[More Info]()
**Usage**: Developers can change the value of `B_FAINT_SWITCH_IN` in `include/config/battle.h`, which will make this change for all battles in the game.

## MOVE DATA

## MOVE ACCURACY

## MOVE STATS

## OTHER MOVE SETTINGS

## ABILITY

## BATTLE ITEMS

## SPECIAL BATTLES

## BATTLE TERRAIN

## BATTLE USER INTERFACE

## CAPTURE

## OTHER

## ANIMATIONS
- The following moves have updates to their animations to look nicer:
//TODO get full list of moves
    - Swords Dance
    - Leech Sede
    - Horn Attack
    - Ember
    - Bite / Crunch
    - chop/kick/pounch
    - Spikes
    - Fly
    - Curse
    - Baton Pass
    - Morning Sun
    - impacts
    - Surf

# OVERWORLD

# DEVELOPER FEATURES
