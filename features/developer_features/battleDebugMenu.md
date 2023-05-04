## Battle Debug Menu
<img src="" alt="" height=160px width=240px>
A Battle Debug Menu is a series of menus that allow developers to quickly debug and test various battle mechanics. Once a battle has started, developers can view and modify properties of a battle to help verify that their functionality is working correctly.

### Enabling the Battle Debug Menu
The Battle Debug Menu is enabled by default, but can be toggled in `include/config/debug.h`.

### Functionality
<img src="" alt="" height=160px width=240px>
Pressing UP or DOWN will scroll through the list of properties for a Pokemon.

#### Anatomy
1. **Party Index**: The selected Pokemon's position on the battlefield.
2. **Pokemon Name**: The selected Pokemon's name.
3. **Properties** List of properties for that Pokemon.

#### Button Interactions
|Button|Interaction|
|---|---|
|UpDown|Scroll through list of properties|
|A|Enter submenu or make selection|
|B|Go back one menu|
|L|Go to previous Pokemon's position on battlefield.
|R| Go to next Pokemon's position on battlefield.
|SELECT|Return to battle

#### Move / Ability / Item
<img src="" alt="" height=160px width=240px>
Selecting a move with A allows the developer to change the ID of the move that specific move slot. A list of moves and their IDs are found in `include/constants/moves.h`. Once the ID is changed, pressing A or B returns the cursor to the list of moves.

When a new move is chosen, the PP for that move is not changed or destroyed.

Selecting "All" allows the developer to change all of the move slots to be the same move.

Ability and Item work similarly, corresponding to the constants set `include/constants/abilities.h` and `include/constants/items.h`.

//TODO What does Effect Overrride?

#### PP
For the selected Pokemon, selecting one of the four moves allows the developer to change the PP of that specific move.

#### Types
This displays the first, second, and third types of the selected Pokemon. Selecting a type will allow the developer to change it, using the list of types in `include/constants/pokemon.h`.

Pokemon like Charmander have their default Types shown as Fire / Fire.

Pokemon only have a third type when it is added by moves like Forest's Curse and Trick or Treat.

#### Stats
For the selected Pokemon, selecting one of the stats will allow the developer to change the raw stat value.

#### Stat Stages
For the selected Pokemon, selecting one of the stats will allow to develop to adjust the stage modification applied to each stat. The value being edited goes from 0 to 12, which correspond to -6 and +6 respectively.

Selecting "All" allows the developer to change all of the stats to apply the same stage modification.

#### Status 1 / Status 2 / Status 3 / Status 4
For the selected Pokemon, developers can change its status effects.

### Examples

