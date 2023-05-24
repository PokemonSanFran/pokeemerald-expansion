## Trainer Control

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Trainer Control allows developers to explicitly define the parties for opposing Trainers, by creating a new struct type called `TrainerMonCustomized`.

## Usage 

Opposing Trainer parties are defined in [`src/data/trainer_parties.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/src/data/trainer_parties.h). To use Trainer Control, developers can either edit an existing party or add a new one. Each member of the struct corresponds to a different aspect of a Pokémon.

Developers do not need to define every aspect of every Pokémon. If aspects are left blank, they will be automatically filled with defaults, detailed below.

| Struct member | Constants                                                    | Behavior When Invalid/Blank                                  |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| .species      | [Species Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/species.h) | Pokémon is not included.                                     |
| .nickname     | `COMPOUND_STRING("Nickname")`                                | Pokémon has no nickname.                                     |
| .gender       | [Gender Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/trainers.h) | Defaults to Male or the default gender for that species.     |
| .heldItem     | [Item Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/items.h) | Defaults to `ITEM_NONE`.                                     |
| .ability      | [Ability Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/abilities.h) | Defaults to the Pokémon's first Ability slot.                |
| .lvl          | 0 ≤ Integer ≤ 100                                            | Defaults to Level 0.                                         |
| .isShiny      | `TRUE` or `FALSE`                                            | Defaults to not Shiny.                                       |
| .friendship   | 0 ≤ Integer ≤ 255                                            | Defaults to 0.                                               |
| .ball         | [Item Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/items.h) | Defaults to `ITEM_POKE_BALL`.                                |
| .ev           | 0 ≤ Integer ≤ 255                                            |                                                              |
| .iv           | 0 ≤ Integer ≤ 31                                             |                                                              |
| .moves        | [Moves Constant](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/moves.h) | Defaults to the last four Level Up moves depending on species' level. |

## Example

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

The following shows how to create two Pokémon from sugarhigh's ["Life Orb Crawdaunt and Seismitoad + Zapdos Rain" team](https://pokepast.es/5193200d72df25df).

#### [`include/constants/trainer_parties.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/trainer_parties.h)

```c
static const structTrainerMonCustomized sParty_Sawyer1[] = {
    {
        .species = SPECIES_PELIPPER,
        .nickname = COMPOUND_STRING("Let's in t"), // The maximum number of characters is  `POKEMON_NAME_LENGTH`
        .gender = MALE,
        .heldItem = ITEM_DAMP_ROCK,
        .ability = ABILITY_DRIZZLE,
        .lvl = 100,
        .isShiny = FALSE,
        .friendship = 255,
        .ball = ITEM_GREAT_BALL,
        .ev = TRAINER_PARTY_EVS(248,0,8,0,0,252),
        .iv = TRAINER_PARTY_IVS(31,31,31,31,31,31),
        .moves = {
            MOVE_HURRICANE,
            MOVE_U_TURN,
            MOVE_DEFOG,
            MOVE_ROOST}
    },
    {
        .species = SPECIES_ZAPDOS,
        .heldItem = ITEM_HEAVY_DUTY_BOOTS,
        .ability = ABILITY_STATIC,
        .lvl = 100,
        .isShiny = TRUE,
        .friendship = 255,
        .ball = ITEM_MASTER_BALL,
        .ev = TRAINER_PARTY_EVS(0,0,0,252,252,4),
        .nature = TRAINER_PARTY_NATURE(NATURE_TIMID),
        .iv = TRAINER_PARTY_IVS(31,0,31,31,31,31),
        .moves = {
            MOVE_HURRICANE,
            MOVE_THUNDER,
            MOVE_WEATHER_BALL,
            MOVE_ROOST}
    },
};
```

#### [src/data/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/src/data/trainers.h)

```diff
    [TRAINER_SAWYER_1] =
    {
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("SAWYER"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
-       .party = NO_ITEM_DEFAULT_MOVES(sParty_Sawyer1),
+       .party = EVERYTHING_CUSTOMIZED(sParty_Sawyer1),
    },
```
