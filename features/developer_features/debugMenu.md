## Debug Menu
<img src="" alt="" height=160px width=240px>
The Debug Menu is a series of menus that allow develoeprs to quickly debug and test functionality within their game. This debug menu is called in the overworld.

### Enabling the Debug Menu
The Debug Menu is enabled by default, but can be toggled in `include/config/debug.h`. Once enabled, the Debug Menu is opened by pressing R_BUTTON and START, but this can be changed through different options in `include/config/debug.h`.

### Functionality
<img src="" alt="" height=160px width=240px>
Pressing UP or DOWN will scroll through the difffernt menu options.

#### Button Interactions
|Button|Interaction|
|---|---|
|UpDown|Scroll through list of options|
|A|Enter submenu or make selection|
|B|Go back one menu|

#### Constant Navigation
<img src="" alt="" height=160px width=240px>
Within `pokeemerald-expansion`, all of the moves, Pokemon, items, and maps are all represented by numbers. For example, `ITEM_POTION` is a constant that represents `28`, and `SPECIES_SERVINE` is 496. Most constants are defined in `include/constants`.

The debug menus allow the developer to scroll through the menus to choose the number corresponding to what is desired.

##### Anatomy
<img src="" alt="" height=160px width=240px>
1. **Selected Number**: The constant that is currently selected by the menu.
2. **Constant Name**: In this context, the name of the selected context.
3. **Increment**: When the constant is increased, the number displayed here is the amount by which it is increased by.

##### Button Interactions
|Button|Interaction|
|---|---|
|Up|Increase the constant by the number displayed in the increment.|
|Down|Decrease the constant by the number displayed in the increment.|
|Left|Divide the current increment by 10.|
|Right|Multiply the current increment by 10.|
|A|Enter submenu or make selection|
|B|Go back one menu|

#### Example
The Debug Menu can be used to give the player a Pachirisu.

After opening the relevant option, `SPECIES_PACHIRISU` is the constant for `417`. To get to 417 from 1, one would press:
<img src="" alt="" height=160px width=240px>|
|Buttons|Selected Number|Increment|
|---|---|---|
|2x Right|1|**100**|
|4x Up|**|401**|100|
|Left|401|**10**|
|2x Up|**421**|10|
|Left|421|**1**|
|4x Down|**417**|1|

#### Utilities
This is an assortment of commonly used scripts.

##### Heal Party
<img src="" alt="" height=160px width=240px>
Heals the player's party as if they had visited a Pokemon Center.

##### Fly to map
<img src="" alt="" height=160px width=240px>
Opens `CB2_OpenFlyMap` and sets all of the `FLAG_VISITED_*` flags, allowing the player to Fly anywhere.

##### Warp to map warp
<img src="" alt="" height=160px width=240px>
Prompts the player to select a [map group id](../../include/constants/map_groups.h), [a mapsec id](../../include/constants/region_map_sections.h), and a warp id, and then warps the player to the chosen location. This uses Constant Navigation.

##### Toggle Running Shoes
<img src="" alt="" height=160px width=240px>
Toggles `FLAG_SYS_B_DASH`. When set, the player can hold B to use the Running Shoes.

##### Poison all mons
<img src="" alt="" height=160px width=240px>
Inflicts all Pokemon in the party with the Poison status condition.

##### SaveBlock Space
<img src="" alt="" height=160px width=240px>
Shows a `message` with the available space in [`SaveBlock1`](), [`SaveBlock2`](), and `Pokemon Storage`.
//TODO figure out link

##### Set weather
<img src="" alt="" height=160px width=240px>
Prompts the player to choose a [weather condition](../../include/constants/weather.h) that will be immiedaitely applied to the overworld. This uses Constant Navigation.

##### Check Wall Clock
<img src="" alt="" height=160px width=240px>
Runs `PlayersHouse_2F_EventScript_CheckWallClock`, allowing the player to see the current time.

##### Set Wall Clock
<img src="" alt="" height=160px width=240px>
Runs `PlayersHouse_2F_EventScript_SetWallClock`, allowing the player to change the current time.

##### Watch Credits
<img src="" alt="" height=160px width=240px>
Runs `CB2_StartCreditsSequence`, which runs the credits as if the player has just entered the Hall of Fame.

##### Trainer name
<img src="" alt="" height=160px width=240px>
Gives the player a randomly generated name based on their chosen gender, and then allows the player to manually set a name for the naming screen.

##### Toggle T. Gender
<img src="" alt="" height=160px width=240px>
Toggles the player's gender.

##### New Trainer Id
<img src="" alt="" height=160px width=240px>
Randomly generates a new Trainer ID for the player.

##### Clear Storage Boxes
<img src="" alt="" height=160px width=240px>
Deletes all the Pokemon in the player's storage boxes.

#### Scripts
<img src="" alt="" height=160px width=240px>
Debug_Script_1 through 8 are all scripts that are written by a developer. They use `pokeemerald`'s scripting language, and are defined and stored in `data/scripts/debug.inc`.

#### Flags
An assortment of common toggled flags. Constants are listed in `include/constants/flags.h`.

##### Set Flag XXXX
<img src="" alt="" height=160px width=240px>
Shows the status of the currently displayed flag. Selecting a flag will toggle that flag. Uses Constant Navigation. 

##### All Pokédex Flags
<img src="" alt="" height=160px width=240px>
Changes the player's Pokedex status for all Pokemon to Seen and Caught.

##### Pokédex ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `FLAG_SYS_POKEDEX_GET`. When `TRUE`, the Pokedex is available from the Start Menu.

##### NatDex ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `FLAG_SYS_NATIONAL_DEX`. When `TRUE`, the National Dex is avaialble.

##### PokéNav ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `FLAG_SYS_POKEDEX_GET`. When `TRUE`, the Pokenav is available from the Start Menu.

##### Fly Flags ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles the `FLAG_VISITED_*` flags, which when `TRUE`, allow the player to Fly to those locations.

##### All badges ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles each of the `FLAG_BADGE0*_GET` flags, which when `TRUE`, give the player that specific badge.

##### Frontier Pass ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `FLAG_SYS_FRONTIER_PASS`, which when `TRUE` allows the player to access the Frontier Pass from the Start Menu.

##### Collision ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `OW_FLAG_NO_COLLISION`, which when `TRUE`, objects in the overorld will ignore metatile collision values.

##### Encounter ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `OW_FLAG_NO_ENCOUNTER`, which when `TRUE` wild Pokemon encounters are disabled.

##### TrainerSee ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `OW_FLAG_NO_TRAINER_SEE`, which when `TRUE` trainers will not battle the player unless explicitly spoken to.

##### BagUse ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `B_FLAG_NO_BAG_USE`, which when `TRUE` the ability to use the bag in battle is disabled.

##### Catching ON/OFF
<img src="" alt="" height=160px width=240px>
Toggles `B_FLAG_NO_CATCHING`, which when `TRUE` the ability to throw Pokeballs is disabled. 

#### Variables
Constants are listed in `include/constants/vars.h`.

##### Set Vars XXXX
<img src="" alt="" height=160px width=240px>
Shows the value of the currently displayed var. Selecting a var will toggle that flag. Uses Constant Navigation. 

#### Give X
<img src="" alt="" height=160px width=240px>
Give the player certain items.

##### Give item XXXX
<img src="" alt="" height=160px width=240px>
Gives the player any item with any quantity. Uses Constant Navigation.

##### Give all TMs
<img src="" alt="" height=160px width=240px>
Gives the player one of every item with  the following conditions:
- has a value between (including) `ITEM_TM01` and `ITEM_HM08`.
- the item is associated with a BattleMoveId.
- the player's bag does not already have this item

##### Pkm(lvl)
<img src="" alt="" height=160px width=240px>
Choose a Pokemon and its level. The Pokemon is added to the player's party(or the first free box slot). Uses Constant Navigation.

##### Pkm(l,s,n,a,IV,mov)
<img src="" alt="" height=160px width=240px>
Choose a Pokemon and its level, shininess, nature, ability, IVs, and Moves. Uses Constant Navigation.

##### Max Money
<img src="" alt="" height=160px width=240px>
//TODO open PR to make this MAX_MONEY instead of 999999
Sets the player's money to ¥999999.

##### Max Coins
<img src="" alt="" height=160px width=240px>
Sets the player's number of coins to 9999.

##### Max Battle Points
<img src="" alt="" height=160px width=240px>
Sets the player's number of BP to `MAX_BATTLE_FRONTIER_POINTS`.

##### Daycare Egg
<img src="" alt="" height=160px width=240px>
If the player has two Pokemon in the Day Care that can make an egg, they will immediately produce one.

##### Fill Pc
<img src="" alt="" height=160px width=240px>
Create one of each Pokemon species / form at Level 100. Place them in the PC boxes until all of the open slots are filled.

##### CHEAT Start
<img src="" alt="" height=160px width=240px>
Runs the script `Debug_CheatStart`, which sets a number of different flags, vars and runs a number of functions to simulate a player with partial progress through Pokemon Emerald.

#### Sound
##### Effects
<img src="" alt="" height=160px width=240px>
Plays the sound effect being shown, using the list in `include/constants/songs.h` up to `END_SE`. Using Constant Navigation.

##### Music
<img src="" alt="" height=160px width=240px>
Plays the music being shown, using the list in `include/constants/songs.h` beginning  at `START_MUS`. Using Constant Navigation.

#### Access PC
<img src="" alt="" height=160px width=240px>
Boots up the PC, allowing the player to access the Pokemon Storage System, {PLAYER}'s PC, or Hall of Fame records.
