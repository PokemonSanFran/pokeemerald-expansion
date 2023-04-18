## Expanded Double Battle Support
`pokeemerald` supports Single Trainer Double Battles, and Link / Battle Tower Multi Battles. `pokeemerald-expansion` builds upon this system, allowing for a number of different battle types.

**Usage**: All battle types are executed via script, and take different parameters, such as partners and opponents.


### `choose_mons`
<img src="" alt="" height=160px width=240px>
Each of the battle macros is intended to be used alongisde `choose_mons`, which has the player select three Pokemon to be used in the upcoming battle. Developers may also opt for the `fixed` variants (`multi_fixed_2_vs_2`,`multi_fixed_2_vs_1`,`multi_fixed_wild`), which will automatically choose the first three Pokemon in the player's party.

### `multi_2_vs_2`
<img src="" alt="" height=160px width=240px>
Player and a partner versus two opposing Trainers.

```
    choose_mons
    multi_2_vs_2 TRAINER_SHELLY_SEAFLOOR_CAVERN,gText_StatSharply,TRAINER_TABITHA_MOSSDEEP,gText_StatSharply,TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```

### `multi_2_vs_1`
<img src="" alt="" height=160px width=240px>
Player and a partner versus one opposing Trainer.

```
    choose_mons
    multi_2_vs_2 TRAINER_SHELLY_SEAFLOOR_CAVERN,gText_StatSharply,TRAINER_TABITHA_MOSSDEEP,gText_StatSharply,TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```

### `multi_wild`
<img src="" alt="" height=160px width=240px>
Player and a partner versus wild Pokemon.

```
    choose_mons
    setwildbattle SPECIES_DRACOVISH, 50, ITEM_NONE, SPECIES_VOLCARONA, 50, ITEM_NONE
    multi_wild TRAINER_MAY_LILYCOVE_TORCHIC,TRAINER_BACK_PIC_MAY
```
