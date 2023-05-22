# Overworld Debug Menu
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

The Overworld Debug Menu is a series of menus that allow develoeprs to quickly debug and test functionality within their game.

## Enabling the Overworld Debug Menu
By default, the Overworld Debug Menu is opened by pressing `R_BUTTON` and holding `START`. The menu itself and the buttons to open it can be changed in [`include/config/debug.h`](include/config/debug.h).

## Constant Navigation
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Within `pokeemerald-expansion`, all of the moves, Pokemon, items, and maps are all represented by numbers. For example, `ITEM_POTION` is a constant that represents `28`, and `SPECIES_SERVINE` is 496. Most constants are defined in [`include/constants`](../include/constants).

The Overworld debug menus allow the developer to scroll through the menus to choose the number corresponding to what is desired.

## Anatomy and Interactions
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

1. **Selected Number**: The constant that is currently selected by the menu.
2. **Constant Name**: In this context, the name of the selected context.
3. **Increment**: When the constant is increased, the number displayed here is the amount by which it is increased by.
|Button|Interaction|
|---|---|
|Up|Increase the constant by the number displayed in the increment.|
|Down|Decrease the constant by the number displayed in the increment.|
|Left|Divide the current increment by 10.|
|Right|Multiply the current increment by 10.|
|A|Enter submenu or make selection|
|B|Go back one menu|

### Example
The Overworld Debug Menu can be used to give the player a Pachirisu.

After opening the relevant option, `SPECIES_PACHIRISU` is the constant for `417`. To get to 417 from 1, one would press:

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

|Buttons|Selected Number|Increment|
|---|---|---|
|2x Right|1|**100**|
|4x Up|**401**|100|
|Left|401|**10**|
|2x Up|**421**|10|
|Left|421|**1**|
|4x Down|**417**|1|

## Functionality
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Scroll through list of options|
|A|Enter submenu or make selection|
|B|Go back one menu|

### Utilities
This is an assortment of commonly used scripts.

#### Heal Party
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Heals the player's party as if they had visited a Pokemon Center.

#### Fly to map
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Opens `CB2_OpenFlyMap` and sets all of the `FLAG_VISITED_*` flags, allowing the player to Fly anywhere.

#### Warp to map warp
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Prompts the player to select a [map group id](../../include/constants/map_groups.h), [a mapsec id](../../include/constants/region_map_sections.h), and a warp id, and then warps the player to the chosen location. This uses Constant Navigation.

#### Toggle Running Shoes
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Toggles `FLAG_SYS_B_DASH`. When set, the player can hold B to use the Running Shoes.

#### Poison all mons
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Inflicts all Pokemon in the party with the Poison status condition.

#### SaveBlock Space
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Shows a `message` with the available space in [`SaveBlock1`](../include/global.h), [`SaveBlock2`](../include/global.h), and [`PokemonStorage`](../include/pokemon_storage_system.h).

#### Set weather
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Prompts the player to choose a [weather condition](../../include/constants/weather.h) that will be immediately applied to the overworld. This uses Constant Navigation.

#### Check Wall Clock
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Runs `PlayersHouse_2F_EventScript_CheckWallClock`, allowing the player to see the current time.

#### Set Wall Clock
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Runs `PlayersHouse_2F_EventScript_SetWallClock`, allowing the player to change the current time.

#### Watch Credits
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Runs `CB2_StartCreditsSequence`, which runs the credits as if the player has just entered the Hall of Fame.

#### Trainer name
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Gives the player a randomly generated name based on their chosen gender, and then allows the player to manually set a name for the naming screen.

#### Toggle T. Gender
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Toggles the player's gender.

#### New Trainer Id
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Randomly generates a new Trainer ID for the player.

#### Clear Storage Boxes
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Deletes all the Pokemon in the player's storage boxes.

### Scripts
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Debug_Script_1 through 8 are all blank scripts that can be written by the developer. They use `pokeemerald`'s scripting language, and are defined and stored in [`data/scripts/debug.inc`](../data/scripts/debug.inc).

### Flags
An assortment of common toggled flags. Constants are listed in [`../include/constants/flags.h`](../include/constants/flags.h).

#### Set Flag XXXX
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Shows the status of the currently displayed flag. Selecting a flag will toggle that flag. Uses Constant Navigation. 

#### All Pokédex Flags
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Changes the player's Pokedex status for all Pokemon to Seen and Caught.

#### ON/OFF scripts
On/Off scripts toggle a specific flag, which when `TRUE`, unlocks different functionality.

|Script Name|Flag Toggled|Behavior when `TRUE`|Example
|---|---|---|---|
|Pokédex ON/OFF|`FLAG_SYS_POKEDEX_GET`|Pokedex is available from the Start Menu.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|NatDex ON/OFF|`FLAG_SYS_NATIONAL_DEX`|National Dex is available.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|PokéNav ON/OFF|`FLAG_SYS_POKEDEX_GET`|Pokenav is available from the Start Menu.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|Fly Flags ON/OFF|`FLAG_VISITED_`|Allow the player to Fly to any location.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|All badges ON/OFF|`FLAG_BADGE0*_GET`|Give the player that specific badge.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|Frontier Pass ON/OFF|`FLAG_SYS_FRONTIER_PASS`|Frontier Pass is available from the Start Menu.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|Collision ON/OFF|`OW_FLAG_NO_COLLISION`|Objects in the overorld will ignore metatile collision values.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|Encounter ON/OFF|`OW_FLAG_NO_ENCOUNTER`|Wild Pokemon encounters are disabled.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|TrainerSee ON/OFF|`OW_FLAG_NO_TRAINER_SEE`|Trainers will not battle the player unless explicitly spoken to.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|BagUse ON/OFF|`B_FLAG_NO_BAG_USE`|Ability to use the bag in battle is disabled.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|
|Catching ON/OFF|`B_FLAG_NO_CATCHING`|Ability to throw Pokeballs is disabled.|![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)|

### Variables
Constants are listed in [`../include/constants/vars.h`](../include/constants/vars.h).

#### Set Vars XXXX
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Shows the value of the currently displayed var. Selecting a var will toggle that flag. Uses Constant Navigation. 

### Give X
Gives the player certain items.

#### Give item XXXX
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Gives the player any item with any quantity. Uses Constant Navigation.

#### Give all TMs
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Gives the player one of every item with  the following conditions:
- has a value between (including) `ITEM_TM01` and `ITEM_HM08`.
- the item is associated with a BattleMoveId.
- the player's bag does not already have this item

#### Pkm(lvl)
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Choose a Pokemon and its level. The Pokemon is added to the player's party(or the first free box slot). Uses Constant Navigation.

#### Pkm(l,s,n,a,IV,mov)
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Choose a Pokemon and its level, shininess, nature, ability, IVs, and Moves. Uses Constant Navigation.

#### Max Money
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Sets the player's money to `MAX_MONEY`.

#### Max Coins
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Sets the player's number of coins to `MAX_COINS`.

#### Max Battle Points
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Sets the player's number of Battle Points to `MAX_BATTLE_FRONTIER_POINTS`.

#### Daycare Egg
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

If the player has two Pokemon in the Day Care that can make an egg, they will immediately produce one.

#### Fill Pc
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Create one of each Pokemon species / form at Level 100. Place them in the PC boxes until all of the open slots are filled.

#### CHEAT Start
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Runs the script `Debug_CheatStart`, which sets a number of different flags, vars and runs a number of functions to simulate a player with partial progress through `pokeemerald`.

### Sound
#### Effects
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Plays the sound effect being shown, using the list in [`include/constants/songs.h`](../include/constants/songs.h) up to `END_SE`. Uses Constant Navigation.

#### Music
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Plays the music being shown, using the list in [`include/constants/songs.h`](../include/constants/songs.h) beginning at `START_MUS`. Uses Constant Navigation.

### Access PC
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Boots up the PC, allowing the player to access the Pokemon Storage System, `{PLAYER}`’s PC, or Hall of Fame records.