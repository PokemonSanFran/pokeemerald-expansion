# INTRODUCTION
`pokeemerald-expansion` is a modification of pret's decomp project, `pokeemerald`. This modification has several goals:

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

# GAME FEATURES
## New Pokémon / Items / Moves / Abilities / Types
primarina using scald, actvating steam engine

gen 4 - occa berry
gen 5 - scald
gen 6 - fairy type
gen 7 - primarina
gen 8 - steam engine and coalassal

## Mega Evolution

## Z-Moves

## Dynamax

## Terastallization

## Raids

## Ability Slide

## Mid Battle Trainer Messages

## Scripted Multi Battles

## Improved Battle Artifical Intelligence

# CONFIGURATION FILES
## CONFIG TYPES
### Generation Toggles

### True / False

### Var / Flags

## General Configuration (include/config.h)

## Battle Configirations (include/config/battle.h)
### Calculations 

- `B_CRIT_CHANCE` - Type: Generation Toggle
Each time the user increases their critical hit stage, the probability of landing of a critical chance increases to 1 over N. [\[More Info\]]()
    - => `GEN_7`: 24, 8, 2, 1, 1
    - `GEN_6`: 16,8,2,1,1
    - `GEN_5`: 16,8,4,3,2

- `B_CRIT_MULTIPLIER` - Type: Generation Toggle
Critical hits multiply their damage by: [\[More Info\]]()
    - => `GEN_6`: 2
    - =< `GEN_5`: 1.5

### Abilities

- `B_EXPANDED_ABILITY_NAMES` - Type: True / False
Ability names are N characters long. [\[More Info\]]()
    - `TRUE`: 16
    - `FALSE`: 12

### Var Settings

- `VAR_TERRAIN` - Type: Var / Flag
When this var is set via a script, X Terrain is automatically set for the duration at the beginning of the next battle. This behavior persists until the flag is cleared. [\[More Info\]]()
    - `STATUS_FIELD_GRASSY_TERRAIN`: Grassy Terrain
    - `STATUS_FIELD_MISTY_TERRAIN`: Misty Terrain
    - `STATUS_FIELD_ELECTRIC_TERRAIN`: Electric Terrain
    - `STATUS_FIELD_PSYCHIC_TERRAI`: Psychic Terrain

### Flag Settings

- `B_FLAG_INVERSE_BATTLE` - Type: Var / Flag
When this flag is set via a script, the type effectiveness interactions are reversed. For example, Fire becomes super effective against water. [\[More Info\]]()

# DEVELOPER FEATURES

## Debug Menu

## Trainer Control

## Debugging 

## Bug Fixes
