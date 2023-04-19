# INTRODUCTION
[`pokeemerald-expansion`](https://github.com/rh-hideout/pokeemerald-expansion/) is a modification of pret's decomp project, [`pokeemerald`](https://github.com/pret/pokeemerald). This modification has several goals:

- Allow fangame developers that are using `pokeemerald` as a base to quickly and easily use key features from [main series](https://bulbapedia.bulbagarden.net/wiki/Core_series) Pokémon games.
- Reduce the barrier of entry for fangame developers to get into decomplilation hacking.
- Provide fangame developers a collection of optional quality of life (QoL) improvements to improve developer and player experience.

`pokeemerald-expansion` is a collection of different features, fixes and modifications from hundreds of different developers, artists and players to help make a comprensive experience.

This document's goal is to detail all of the features available to developers that have chosen to use `pokeemerald-expansion`. 

## VERSION
This document is accurate as of Version 1.4.2 (Mar 29 2023), and will be updated as new features as added.

## READING THIS DOCUMENT
All of the features in this document are roughly organized by category, and then is shown as follows:

<img src="https://i.imgur.com/QBy5iNW.png" height=50% width=50%>

A. **Category**: The group of feature that this feature belongs with.

B. **Feature Name**

C. **Gif or image of feature**: A gif showing the video in action.

D. **Feature Description**: A short description of how the feature works.

E. **How to use**: How the developer can enable, configure, or use this feature.

# GAME FEATURES
## New Pokémon / Items / Moves / Abilities / Types
<!--
primarina using scald, actvating steam engine

gen 4 - occa berry
gen 5 - scald
gen 6 - fairy type
gen 7 - primarina
gen 8 - steam engine and coalassal
-->

## Generational Gimmicks
Each generation of Pokémon after Gen 5 has a major mechanic unique to that generation that influences battle.

Over the course of a battle, the player can only execute _one_ of each Generational Gimmick. Furtherfore, a player's Pokémon can only execute one Generational Gimmick per battle.

### Example
Leon has commanded his Charizard to Dynamax during his battle against Blue. Leon cannot Dynamax any more Pokémon during this battle. Charizard cannot use a Z-Move, Mega Evolve, or any other such Gimmick during this battle.

## Mega Evolution

## Z-Moves
![Arcanine using Inferno Overdrive](https://user-images.githubusercontent.com/77138753/230175242-e1f1f3f1-66b5-4604-b79f-ab9fa992c41a.gif)

Introduced in Generation 7, Pokémon can use powerful Z-Moves based on the Z-Crystal they are holding. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Z-Move)

**Usage**: When the following conditions are met, the player can press START on the move selection menu in battle, and then select the highlighted Z-Move:

    - Pokémon is holding a Z-Crystal.
        - If species specific, the Z-Crystal is being held by the qualifying Pokémon.
    - Pokémon knows a move that can be powered up by the Z-Crystal.
    - Player has `ITEM_Z_POWER_RING` in their Bag.
    - Player has not used a generation gimmick during this battle.

Enemy Trainers can also use Z-Moves when the Pokémon is holding the appropriate crystal.

## Dynamax

## Terastallization

## Raids

## Battle Slide Message
Introduced in Generation 5, Battle Slide Messages are used to inform the player about the impacts of moves or abilities in battle.

**Usage**: Battle Slide Messages do not need to be enabled or disabled and work automatically.

## Mid Battle Trainer Messages

## Scripted Multi Battles

## Improved Battle Artifical Intelligence

## Day / Night System

# CONFIGURATION FILES
One of the best features of `pokeemerald-expansion` is that all of the features listed below are optional. If developers do not want to use a feature listed here, they can fairly easily disable or remove it from their project. `pokeemerald-expansion` allows develoeprs to pick and choose which featues they want to use.

The files which control these configurations can be found in `include/config/` and `include/config/config.h`. Developers simply open these files, change the options values, save, and compile their game, and the changes will immediately take effect.

The following sections details the types of options value, and how they are used.

## CONFIG TYPES
### Generation Toggles
Each generation of Pokémon have slightly different changes and mechanics from the latest. `pokeemerald-expansion` allows developers to pick and choose which generation's rules are applied for specific mechanics. `pokeemerald-expansion` supports unique mechanics from every Generation 3 and beyond.

Generations are listed in `include/config.h`. 

#### Example
A developer wants Pokémon to hatch from Eggs at Level 5, as they did in Generations 1 -3, instead of Level 1, as they do starting in Generation 4. To do so, the developer changes the following line in `include/config/pokemon.h`:

```c
#define P_EGG_HATCH_LEVEL           GEN_3
```

If they want to change it back, they can simply change the file to any of the following:

```c
#define P_EGG_HATCH_LEVEL           GEN_4
```
```c
#define P_EGG_HATCH_LEVEL           GEN_5
```
```c
#define P_EGG_HATCH_LEVEL           GEN_LATEST
```

`GEN_LATEST` is the default value for most options, and means 

> use whatever the latest generation is

. Developers can manually change the definition of latest, so if they want all mechanics set to `GEN_LATEST` to be Generation 6, they can set:
```c
#define GEN_LATEST GEN_6
```

and all values with `GEN_LATEST` will use Generation 6.

### True / False
Some options can be turned explicitly turned on or off. These arre controlled by changing the option value to `TRUE` or `FALSE` in the appropriate file.

#### Example
After Pokémon Emerald's copyright screen in the intro plays, there is a custom RHH intro created for the pokeemerald-expansion. If a developer does not want this intro to play, they can change the value to `FALSE`.

```c
#define EXPANSION_INTRO   FALSE
```

### Var / Flags
Some options are only available when assigned to one of the game's flags or variables, allowing them to be changed during gameplay.  When those flags are set, or the variables are changed, their effects in the game immediately take place. Once the flags are cleared or the variables are set back to their original value, the functionality is turned off.

#### Example
[Avery's](https://bulbapedia.bulbagarden.net/wiki/Avery#Third_battle) final Dojo Battle in Pokémon Shield starts with Psychic Terrain being immedaitely set. To emulate this, the developer would first assign `VAR_TERRAIN` to an ingame variable in `include/config/battle.h`.

```c
#define VAR_TERRAIN                 VAR_UNUSED_0x4083 
```

Then, winth the game's scripts, the player would set this variable to Psychic Terrain before the battle starts. We also need to set back to normal after battle.

```c
setvar VAR_UNUSED_0x4083,STATUS_FIELD_PSYCHIC_TERRAIN
trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
setvar VAR_UNUSED_0x4083,0
```

Flags work in the same way - they are set to a flag, and then turned on or off via a script or C code.

## General Configuration (include/config.h)

## Battle Configirations (include/config/battle.h)
### Calculations 

- `B_CRIT_CHANCE` - Type: Generation Toggle
    - Each time the user increases their critical hit stage, the probability of landing of a critical chance increases to 1 over N. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Probability_2)
        - => `GEN_7`: 24, 8, 2, 1, 1
        - `GEN_6`: 16,8,2,1,1
        - `GEN_5`: 16,8,4,3,2

- `B_CRIT_MULTIPLIER` - Type: Generation Toggle
    - Critical hits multiply their damage by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Damage_2)
        - => `GEN_6`: 2
        - =< `GEN_5`: 1.5

---

### Abilities

- `B_EXPANDED_ABILITY_NAMES` - Type: True / False
    - Ability names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12

---

### Var Settings

- `VAR_TERRAIN` - Type: Var / Flag
    - When this var is set via a script, X Terrain is automatically set for the duration at the beginning of the next battle. This behavior persists until the flag is cleared. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Terrain)

        - `STATUS_FIELD_GRASSY_TERRAIN`: Grassy Terrain
        - `STATUS_FIELD_MISTY_TERRAIN`: Misty Terrain
        - `STATUS_FIELD_ELECTRIC_TERRAIN`: Electric Terrain
        - `STATUS_FIELD_PSYCHIC_TERRAI`: Psychic Terrain

---

### Flag Settings

- `B_FLAG_INVERSE_BATTLE` - Type: Var / Flag
    -  When this flag is set via a script, the type effectiveness interactions are reversed. For example, Fire becomes super effective against water. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)

---

# DEVELOPER FEATURES

## Debug Menu

## Battle Debug Menu

## Trainer Control

## Debugging 

## Bug Fixes
