# Configuration Files
The majority of the features provided by `pokeemerald-expansion` are optional. If developers do not want to use a feature, they can easily disable or remove it from their project.

The files which control these configurations can be found in `include/config/` and `include/config/config.h`. Developers open these files, change the options values, save the file, and compile their game, and the changes will immediately take effect.

The pages in this section details the types of options value, and how they are used. Below describes the different types of configs and how to interact with them.

## Config Types
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

> use whatever the latest generation is. 

Developers can manually change the definition of latest, so if they want all mechanics set to `GEN_LATEST` to be Generation 6, they can set:
```c
#define GEN_LATEST GEN_6
```

and all values with `GEN_LATEST` will use Generation 6.

### True / False
Some options can be turned explicitly turned on or off. These are controlled by changing the option value to `TRUE` or `FALSE` in the appropriate file.

#### Example
After Pokémon Emerald's copyright screen in the intro plays, there is a custom RHH intro created for the pokeemerald-expansion. If a developer does not want this intro to play, they can change the value to `FALSE`.

```c
#define EXPANSION_INTRO   FALSE
```

### Var / Flags
Some options are only available when assigned to one of the game's flags or variables, allowing them to be changed during gameplay.  When those flags are set, or the variables are changed, their effects in the game immediately take place. Once the flags are cleared or the variables are set back to their original value, the functionality is turned off.

#### Example
[Avery's](https://bulbapedia.bulbagarden.net/wiki/Avery#Third_battle) final Dojo Battle in Pokémon Shield starts with Psychic Terrain being immediately set. To emulate this, the developer would first assign `VAR_TERRAIN` to an in-game variable in `include/config/battle.h`.

```c
#define VAR_TERRAIN                 VAR_UNUSED_0x4083 
```

Then, in the game's scripts, the player would set this variable to Psychic Terrain before the battle starts. We also need to set back to normal after battle.

```
setvar VAR_UNUSED_0x4083,STATUS_FIELD_PSYCHIC_TERRAIN
trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
setvar VAR_UNUSED_0x4083,0
```

Flags work in the same way - they are set to a flag, and then turned on or off via a script or C code.
