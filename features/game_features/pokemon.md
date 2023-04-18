## New Pokémon / Items / Moves / Abilities / Types
<!--
primarina using scald, actvating steam engine

gen 4 - occa berry
gen 5 - scald
gen 6 - fairy type
gen 7 - primarina
gen 8 - steam engine and coalassal
-->
Using `pokeemerald-expansion` gives the developer the ability to use Pokemon, Items, Moves, Abilities and Types from main-series games after `pokeemerald`.

**Usage**: After installation, `pokeemerald-expansion` makes no changes to the core gameplay of `pokeemerald`. Develoeprs wanting to use these new features can do so with ease.

### Pokemon
#### Wild Pokemon
<img src="https://i.imgur.com/QBy5iNW.png" alt="Gif of the player running into a wild Burmy on Hoenn Route 101" height=160px width=240px>
Developers can edit `src/data/wild_encounters.json` or use [Porymap]() to edit the wild Pokemon that appear on each route. New Pokemon can be set the same way old Pokemon are.

**Usage**:
```diff
        {
          "map": "MAP_ROUTE101",
          "base_label": "gRoute101",
          "land_mons": {
            "encounter_rate": 20,
            "mons": [
              {
                "min_level": 2,
                "max_level": 2,
                - "species": "SPECIES_WURMPLE"
                + "species: "SPECIES_BURMY"
              },
```

#### Starter Pokemon
<img src="https://i.imgur.com/QBy5iNW.png" alt="Gif of new starter Pokemon" height=160px width=240px>
The Pokemon declared as starters can be changed by the developer by editing `src/starter_choose.c`.

**Usage**:
```diff
static const u16 sStarterMon[STARTER_MON_COUNT] =
{
    - SPECIES_TREECKO,
    - SPECIES_TORCHIC,
    - SPECIES_MUDKIP,
    + SPECIES_PIPLUP,
    + SPECIES_ROWLET,
    + SPECIES_LITTEN,
};
