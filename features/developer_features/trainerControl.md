## Trainer Control
Trainer Control allows developers to explicitly define the parties for opposing Trainers, by creating a new struct type called `TrainerMonCustomized`.

### Usage 
Opposing Trainer parties are defined in `src/data/trainer_parties.h`. To use Trainer Control, developers can either edit an existing party or add a new one. Each member of the struct corresponds to a different aspect of a Pokemon.

|Struct member|Constants|Behavior When Absent|
|---|---|---|
|.species|[Species Constant](../include/constants/species.h)|Pokemon is not included.|
|.nickname|`COMPOUND_STRING("Nickname")`|Pokemon has no nickname.|
|.gender|[Gender Constant](../include/constants/trainers.h)|Defaults to Male or the default gender for that species.|
|.heldItem|[Item Constant](../include/constants/items.h)|Defaults to `ITEM_NONE`.|
|.ability|[Ability Constant](../include/constants/abilities.h)|Defaults to the Pokemon's first Ability slot.|
|.lvl|0 ≤ Integer ≤ 100|Defaults to Level 0.|
|.isShiny|[ Constant](../include/constants/.h)|Defaults to not Shiny.|
|.friendship|[ Constant](../include/constants/.h)||
|.ball|[ Constant](../include/constants/.h)|Defaults to `ITEM_POKE_BALL`.|
|.ev|0 ≤ Integer ≤ 255||Defaults to 0 for all values.|
|.iv|0 ≤ Integer ≤ 31||Defaults to 0 for all values.|
|.moves|[ Constant](../include/constants/.h)|Defaults to the last four Level Up moves depending on species' level.|

### Example
The following shows how to build two Pokemon from sugarhigh's ["Life Orb Crawdaunt and Seismitoad + Zapdos Rain" team](https://pokepast.es/5193200d72df25df).

#### `include/constants/trainer_parties.h`

```c
static const structTrainerMonCustomized sParty_Sawyer1[] = {
    {
        .species = SPECIES_PELIPPER,
        .nickname = COMPOUND_STRING("Let's in t"),
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

#### src/data/trainers.h

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

```
```
