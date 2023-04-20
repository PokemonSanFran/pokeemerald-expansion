## Debug Configirations (include/config/debug.h)
### Overworld Debug

`DEBUG_OVERWORLD_MENU` - Type: True / False
    - Allows the use of the Overworld Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
		- `TRUE`: True
		- `FALSE`: False

`DEBUG_OVERWORLD_HELD_KEYS` - Type: True / False
    - When `DEBUG_OVERWORLD_MENU` is `TRUE`, and the player is in the overworld, holding the button(s) defined here, and performing the trigger defined in `DEBUG_OVERWORLD_TRIGGER_EVENT`, will open the Overworld Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
    - Some examples include:
        - `R_BUTTON`
        - `R_BUTTON + A_BUTTON`
        - `DPAD_ANY`

`DEBUG_OVERWORLD_TRIGGER_EVENT` - Type: True / False
    - When `DEBUG_OVERWORLD_MENU` is `TRUE`, and the player is in the overworld, holding the button(s) defined in `DEBUG_OVERWORLD_HELD_KEYS`, and performing the trigger defined in here, will open the Overworld Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
    - Some examples include:
        - `pressedAButton`
        - `pressedStartButton`
        - `pressedSelectButton`
        - `heldDirection`
        - `tookStep`
        - `pressedBButton`

`DEBUG_OVERWORLD_IN_MENU` - Type: True / False
    - Ignores `DEBUG_OVERWORLD_HELD_KEYS`, and `DEBUG_OVERWORLD_TRIGGER_EVENT` and adds an item to the Start Menu which opens the Overworld Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- `TRUE`: True
		- `FALSE`: False

### Battle Debug Menu

`DEBUG_BATTLE_MENU` - Type: True / False
    - When the player is in battle, pressing SELECT opens the Battle Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
		- `TRUE`: True
		- `FALSE`: False

### Pokémon Debug

`DEBUG_POKEMON_MENU` - Type: True / False
    - When the player is on the Pokemon summary screen, pressing SELECT opens the Sprite Debug Menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
		- `TRUE`: True
		- `FALSE`: False
