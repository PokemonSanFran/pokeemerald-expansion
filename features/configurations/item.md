## Item Configuration (include/config/item.h)

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_SHINY_CHARM_REROLLS` - Type: Set Value
    - When the player has the Shiny Charm, this value is the max number of times the game will attempt to generate a Shiny Pokemon. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
	
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_KEY_FOSSILS` - Type: Generation Toggle
    - Helix Fossil, Dome Fossil, Old Amber, Root Fossil, and Claw Fossil are stored in the [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_4`: Items Bag pocket
        - = `GEN_3`: Key Items Bag pocket

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_KEY_ESCAPE_ROPE` - Type: Generation Toggle
    - Escape Rope is stored in the  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_8`: Key Items Bag pocket
        - <= `GEN_7`: Items Bag pocket

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_HEALTH_RECOVERY` - Type: Generation Toggle
    - These items heal N HP.

|Item| \>= `GEN_7` N Value|<= `GEN_6` N Value|
|---|---|---|
|Super Potion|60|50|
|Hyper Potion|120|200|
|Fresh Water|30|50|
|Soda Pop|50|60|
|Lemonade|70|80|
|Energy Powder|60|50|
|Energy Root|120|200|

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_SITRUS_BERRY_HEAL` - Type: Generation Toggle
	- Sitrus Berry heals N HP. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_4`: 1/4 of the user's max HP
        - = `GEN_3`: 30 HP

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_VITAMIN_EV_CAP` - Type: Generation Toggle
    - Vitamins can no longer be used on a Pokemon that has N EVs in a specific stat. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
		- >= `GEN_8`: 252
        - <= `GEN_7`: 100


### TM Configurations

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_REUSABLE_TMS` - Type: True / False
    - When `TRUE`, Technical Machines can be used an unlimited number of times, instead of only once. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)


## Repel/Lure config

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `VAR_LAST_REPEL_LURE_USED` - Type: Var / Flag
    - When this var is set, the last Repel or Lure used by the player is remembered. When the effects of a Repel or Lure expire, the game will ask the player if they want to use another one. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `I_REPEL_LURE_MENU` - Type: True / False    
    - When `TRUE` and the effects of a Repel or Lure expires, the game will show a menu of Repels or Lures to the player, which can be selected for immediate use. The functionality of `VAR_LAST_REPEL_LURE_USED` is disabled. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)