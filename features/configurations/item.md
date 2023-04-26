## Item Configuration (include/config/item.h)

`I_SHINY_CHARM_REROLLS` - Type: Set Value
    - When the player has the `ITEM_SHINY_CHARM`, this value is the max number of times the game will attempt to generate a Shiny Pokemon. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
	
`I_KEY_FOSSILS` - Type: Generation Toggle
    - `ITEM_HELIX_FOSSIL`, `ITEM_DOME_FOSSIL`, `ITEM_OLD_AMBER`, `ITEM_ROOT_FOSSIL`, and `ITEM_CLAW_FOSSIL` are stored in the [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_4`: Items Bag pocket
        - = `GEN_3`: Key Items Bag pocket

`I_KEY_ESCAPE_ROPE` - Type: Generation Toggle
    - `ITEM_ESCAPE_ROPE` is stored in the  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_8`: Key Items Bag pocket
        - <= `GEN_7`: Items Bag pocket

`I_HEALTH_RECOVERY` - Type: Generation Toggle
    - `ITEM_SUPER_POTION`, `ITEM_HYPER_POTION`, `ITEM_FRESH_WATER`, `ITEM_LEMONADE`, `ITEM_ENERGY_POWDER` and `ITEM_ENERGY_ROOT` heal N HP. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_7`: 60, 120, 30, 50, 70, 60, and 120
        - <= `GEN_6`: 50, 200, 50, 60, 80, 50, and 200

`I_SITRUS_BERRY_HEAL` - Type: Generation Toggle
	- `ITEM_SITRUS_BERRY` heals N HP. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_4`: 1/4 of the user's max HP
        - = `GEN_3`: 30 HP

`I_VITAMIN_EV_CAP` - Type: Generation Toggle
    - Vitamins can no longer be used on a Pokemon that has N EVs in a specific stat. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_8`: 252
        - <= `GEN_7`: 100


### TM Configurations
`I_REUSABLE_TMS` - Type: True / False
    - Techincal Machines can be used an unlimited number of times. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- `TRUE`: True
        - `FALSE`: False


## Repel/Lure config

`VAR_LAST_REPEL_LURE_USED` - Type: Var / Flag
    - When this var is set, the last Repel or Lure used by the player is remembered. When the effects of a Repel or Lure expire, the game will ask the player if they want to use another one. This is disabled when `I_REPEL_LURE_MENU` is `TRUE`. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)

`I_REPEL_LURE_MENU` - Type: True / False    
    - When the effects of a Repel or Lure expires, the game will show a menu of Repels or Lures to the player, which can be selected for immediate use. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- `TRUE`: True
        - `FALSE`: False

