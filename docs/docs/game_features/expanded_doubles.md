# Expanded Double Battle Support
`pokeemerald` supports Single Trainer [Double Battles](https://bulbapedia.bulbagarden.net/wiki/Double_Battle), and [Link](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Center#Pok.C3.A9mon_Cable_Club) / [Battle Tower](https://bulbapedia.bulbagarden.net/wiki/Multi_Battle#Battle_facilities) [Multi Battles](https://bulbapedia.bulbagarden.net/wiki/Multi_Battle). `pokeemerald-expansion` builds upon this system, allowing for a number of different battle types.

## Usage

All battle types are executed via script, and take different parameters, such as partners and opponents.


### `choose_mons`
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Each of the battle macros is intended to be used alongside `choose_mons`, which has the player select three Pokémon to be used in the upcoming battle. Developers may also opt for the `fixed` variants (`multi_fixed_2_vs_2`,`multi_fixed_2_vs_1`,`multi_fixed_wild`), which will automatically choose the first three Pokémon in the player's party.

### `multi_2_vs_2`
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Player and a partner versus two opposing Trainers.

```
choose_mons
multi_2_vs_2 TRAINER_SHELLY_SEAFLOOR_CAVERN,gText_StatSharply,TRAINER_TABITHA_MOSSDEEP,gText_StatSharply,TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```

### `multi_2_vs_1`
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Player and a partner versus one opposing Trainer.

```
choose_mons
multi_2_vs_2 TRAINER_SHELLY_SEAFLOOR_CAVERN,gText_StatSharply,TRAINER_TABITHA_MOSSDEEP,gText_StatSharply,TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```

### `multi_wild`
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Player and a partner versus wild Pokémon.

```
choose_mons
setwildbattle SPECIES_DRACOVISH, 50, ITEM_NONE, SPECIES_VOLCARONA, 50, ITEM_NONE
multi_wild TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```
