# Overworld Debug Menu
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

The Overworld Debug Menu is a series of menus that allow develoeprs to quickly debug and test functionality within their game.

## Enabling the Overworld Debug Menu
By default, the Overworld Debug Menu is opened by pressing `R_BUTTON` and holding `START`. The menu itself and the buttons to open it can be changed in [`include/config/debug.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/debug.h).

## Constant Navigation
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Within `pokeemerald-expansion`, all of the moves, Pokémon, items, and maps are all represented by numbers. For example, `ITEM_POTION` is a constant that represents `28`, and `SPECIES_SERVINE` is 496. Most constants are defined in [`include/constants`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming//include/constants).

The Overworld debug menus allow the developer to scroll through the menus to choose the number corresponding to what is desired.

## Anatomy and Interactions
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

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

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

|Buttons|Selected Number|Increment|
|---|---|---|
|2x Right|1|**100**|
|4x Up|**401**|100|
|Left|401|**10**|
|2x Up|**421**|10|
|Left|421|**1**|
|4x Down|**417**|1|

## Functionality
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Scroll through list of options|
|A|Enter submenu or make selection|
|B|Go back one menu|

### Utilities
This is an assortment of commonly used scripts.

#### Heal Party
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Heals the player's party as if they had visited a [Pokémon Center](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Center).

#### Fly to map
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Opens `CB2_OpenFlyMap` and sets all of the `FLAG_VISITED_*` flags, allowing the player to [Fly](https://bulbapedia.bulbagarden.net/wiki/Fly_(move)#Outside_of_battle) anywhere.

#### Warp to map warp
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Prompts the player to select a [map group id](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/map_groups.h), [a mapsec id](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/region_map_sections.h), and a warp id, and then warps the player to the chosen location. This uses Constant Navigation.

#### Toggle Running Shoes
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Toggles `FLAG_SYS_B_DASH`. When set, the player can hold B to use the [Running Shoes](https://bulbapedia.bulbagarden.net/wiki/Running_Shoes).

#### Poison all mons
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Inflicts all Pokémon in the party with the [Poison status condition](https://bulbapedia.bulbagarden.net/wiki/Status_condition).

#### SaveBlock Space
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Shows a `message` with the available space in [`SaveBlock1`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/global.h), [`SaveBlock2`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/global.h), and [`PokémonStorage`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/pokemon_storage_system.h).

#### Set weather

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Prompts the player to choose a [weather condition](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/weather.h) that will be immediately applied to the overworld. This uses Constant Navigation.

#### Check Wall Clock
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Runs `PlayersHouse_2F_EventScript_CheckWallClock`, allowing the player to see the current time.

#### Set Wall Clock
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Runs `PlayersHouse_2F_EventScript_SetWallClock`, allowing the player to change the current time.

#### Watch Credits
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Runs `CB2_StartCreditsSequence`, which runs the credits as if the player has just entered the [Hall of Fame](https://bulbapedia.bulbagarden.net/wiki/Hall_of_Fame).

#### Trainer name
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Gives the player a randomly generated name based on their [gender](https://bulbapedia.bulbagarden.net/wiki/Gender#In_the_games), and then allows the player to manually set a name for the naming screen.

#### Toggle T. Gender
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Toggles the player's [gender](https://bulbapedia.bulbagarden.net/wiki/Gender#In_the_games).

#### New Trainer Id
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Randomly generates a new [Trainer ID](https://bulbapedia.bulbagarden.net/wiki/Trainer_ID_number) for the player.

#### Clear Storage Boxes
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Deletes all the Pokémon in the [Pokémon Storage System](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Storage_System).

### Scripts
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Debug_Script_1 through 8 are all blank scripts that can be written by the developer. They use `pokeemerald`'s scripting language, and are defined and stored in [`data/scripts/debug.inc`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/data/scripts/debug.inc).

### Flags
An assortment of common toggled flags. Constants are listed in [`include/constants/flags.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/flags.h).

#### Set Flag XXXX
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Shows the status of the currently displayed flag. Selecting a flag will toggle that flag. Uses Constant Navigation. 

#### All Pokédex Flags

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Changes the player's [Pokédex](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9dex) status for all Pokémon to Seen and Caught.

#### ON/OFF scripts
On/Off scripts toggle a specific flag, which when `TRUE`, unlocks different functionality.

|Script Name|Flag Toggled|Behavior when `TRUE`|Example|
|---|---|---|---|
|Pokédex ON/OFF|`FLAG_SYS_POKEDEX_GET`|[Pokédex](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9dex) is available from the Start Menu.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|NatDex ON/OFF|`FLAG_SYS_NATIONAL_DEX`|[National Dex](https://bulbapedia.bulbagarden.net/wiki/National_Pok%C3%A9dex) is available.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|PokéNav ON/OFF|`FLAG_SYS_POKEDEX_GET`|[Pokénav](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9Nav) is available from the [Start Menu](https://bulbapedia.bulbagarden.net/wiki/Menu).|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|Fly Flags ON/OFF|`FLAG_VISITED_`|Allow the player to [Fly](https://bulbapedia.bulbagarden.net/wiki/Fly_(move)#Outside_of_battle) to any location.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|All badges ON/OFF|`FLAG_BADGE0*_GET`|Give the player that specific [badge](https://bulbapedia.bulbagarden.net/wiki/Badge).|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|Frontier Pass ON/OFF|`FLAG_SYS_FRONTIER_PASS`|[Frontier Pass](https://bulbapedia.bulbagarden.net/wiki/Trainer_Card_(game)#Frontier_Pass) is available from the [Start Menu](https://bulbapedia.bulbagarden.net/wiki/Menu).|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|Collision ON/OFF|`OW_FLAG_NO_COLLISION`|Objects in the overworld will ignore metatile collision values.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|Encounter ON/OFF|`OW_FLAG_NO_ENCOUNTER`|Wild Pokémon encounters are disabled.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|TrainerSee ON/OFF|`OW_FLAG_NO_TRAINER_SEE`|Trainers will not battle the player unless explicitly spoken to.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|BagUse ON/OFF|`B_FLAG_NO_BAG_USE`|Ability to use the bag in battle is disabled.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|
|Catching ON/OFF|`B_FLAG_NO_CATCHING`|Ability to throw Poké Balls is disabled.|<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>|

### Variables
Constants are listed in [`include/constants/vars.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/vars.h).

#### Set Vars XXXX
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Shows the value of the currently displayed var. Selecting a var will toggle that flag. Uses Constant Navigation. 

### Give X
Gives the player certain items.

#### Give item XXXX
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Gives the player any item with any quantity. Uses Constant Navigation.

#### Give all TMs
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Gives the player one of every item with  the following conditions:
- has a value between (including) `ITEM_TM01` and `ITEM_HM08`.
- the item is associated with a `BattleMoveId`.
- the player's bag does not already have this item

#### Pkm(lvl)
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Choose a Pokémon and its level. The Pokémon is added to the player's party (or the first free box slot). Uses Constant Navigation.

#### Pkm(l,s,n,a,IV,mov)
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Choose a Pokémon and its level, shininess, nature, ability, IVs, and Moves. Uses Constant Navigation.

#### Max Money
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Sets the player's [money](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Dollar) to `MAX_MONEY`.

#### Max Coins
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Sets the player's number of [coins](https://bulbapedia.bulbagarden.net/wiki/Coin) to `MAX_COINS`.

#### Max Battle Points
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Sets the player's number of [Battle Points](https://bulbapedia.bulbagarden.net/wiki/Battle_Point) to `MAX_BATTLE_FRONTIER_POINTS`.

#### Daycare Egg
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

If the player has two Pokémon in the [Day Care](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Day_Care) that can make an [egg](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Egg), they will immediately produce one.

#### Fill Pc
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Create one of each Pokémon species / form at Level 100. Place them in the PC boxes until all of the open slots are filled.

#### CHEAT Start
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Runs the script `Debug_CheatStart`, which sets a number of different flags, vars and runs a number of functions to simulate a player with partial progress through `pokeemerald`.

### Sound
#### Effects
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Plays the sound effect being shown, using the list in [`include/constants/songs.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/songs.h) up to `END_SE`. Uses Constant Navigation.

#### Music
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Plays the music being shown, using the list in [`include/constants/songs.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/songs.h) beginning at `START_MUS`. Uses Constant Navigation.

### Access PC
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Boots up the PC, allowing the player to access the [Pokémon Storage System](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Storage_System), [`{PLAYER}`’s PC](https://bulbapedia.bulbagarden.net/wiki/PC#Item_Storage_System), or [Hall of Fame](https://bulbapedia.bulbagarden.net/wiki/Hall_of_Fame) records.