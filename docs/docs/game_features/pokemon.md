# Pokémon
<!--primarina using scald, actvating steam engine-->

<!--gen 4 - occa berry-->
<!--gen 5 - scald-->
<!--gen 6 - fairy type-->
<!--gen 7 - primarina-->
<!--gen 8 - steam engine and coalassal-->

## Enabling / Disabling / Configuration
Pokemon related configurations are in [`pokemon.h`](../features/config/pokemon.h). [[Documentation]](../configurations/pokemon.md)

## Usage and Examples
### Wild Pokemon
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Developers can edit [`src/data/wild_encounters.json`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/wild_encounters.json) or use [Porymap](https://github.com/huderlem/porymap) to edit the wild Pokemon that appear on each route. New Pokemon can be set the same way old Pokemon are.

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
-                 "species": "SPECIES_WURMPLE"
+                 "species: "SPECIES_BURMY"
              },
```

### Starter Pokemon
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

The Pokemon declared as starters can be changed by the developer by editing [`src/starter_choose.c`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/starter_choose.c).

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
