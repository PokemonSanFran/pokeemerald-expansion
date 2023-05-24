# Debug Configuration

This page documents the configurations found in [`include/config/debug.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/debug.h).

## Overworld Debug

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `DEBUG_OVERWORLD_MENU` - Type: True / False
    - When `TRUE`, the Overworld Debug Menu can be used. [[More Info]](../developer_features/debugMenu.md)
    - The Overworld Debug Menu is opened when all of the following conditions are met at the same time.
        1. `DEBUG_OVERWORLD_MENU` is `TRUE`
        2. The player holds down the buttons defined in `DEBUG_OVERWORLD_HELD_KEYS `
        3. The player performs the trigger defined in `DEBUG_OVERWORLD_TRIGGER_EVENT `

||Values List|Examples|
|---|---|---|
|`DEBUG_OVERWORLD_HELD_KEYS `|[include/field_control_avatar.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/field_control_avatar.h)|`pressedAButton`,`pressedStartButton`,`pressedSelectButton`,`heldDirection`,`tookStep`,`pressedBButton`|
|`DEBUG_OVERWORLD_TRIGGER_EVENT `|[include/gba/io_reg.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/gba/io_reg.h)|`R_BUTTON`, `R_BUTTON + A_BUTTON`, `DPAD_ANY`|

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `DEBUG_OVERWORLD_IN_MENU` - Type: True / False

    - When `TRUE`, `DEBUG_OVERWORLD_HELD_KEYS` and `DEBUG_OVERWORLD_TRIGGER_EVENT` are ignored, and an option to open the Overworld Debug Menu is added to the Start Menu.

    ---

## Battle Debug Menu

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

* `DEBUG_BATTLE_MENU` - Type: True / False

    - When `TRUE`, and the player is in battle, pressing SELECT opens the Battle Debug Menu. [[More Info]](../developer_features/battleDebugMenu.md)

    ---

## Pokémon Debug

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

* `DEBUG_POKEMON_MENU` - Type: True / False
    * When `TRUE` and the player is on the Pokémon summary screen, pressing SELECT opens the Sprite Debug Menu. [[More Info]](../developer_features/spriteDebugMenu.md)
