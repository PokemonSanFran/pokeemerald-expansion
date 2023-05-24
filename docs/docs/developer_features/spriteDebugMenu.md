# Sprite Debug Menu
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

The Sprite Debug Menu is a series of menus that allow developers to quickly debug and test how Pokémon look in battle.

## Enabling the Sprite Debug Menu
The Battle Debug Menu is enabled by default, but can be toggled in [`include/config/debug.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/debug.h). Once enabled, pressing SELECT on the Pokémon Summary Screen will open the Sprite Debug Menu.

## Functionality
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

### Main Menu

The Main Menu is used to change the displayed Pokémon.

#### Anatomy
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

This selected Pokémon’s:
1. **Species ID**
2. **Species Name**
3. **Back Sprite**
4. **Front Sprite**
5. **Species Footprint**
6. **Species Icon**
7. **Back Animation**: The animation that plays when the player sends out the Pokémon.
8. **Front Animation**: The animation that plays when the opponent sends out the Pokémon.
9. **Battle Background**
10. **Currently Displayed Background**: The currently active background’s name.
11. **Form Indicator**: Displays when the Pokémon has multiple forms.

#### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Change value of selected digit|
|Left or Right|Change selected digit|
|A|Go to Submenu 1|
|B|Return to overworld|
|L|Play the back animation|
|R|Play the front animation|
|START|Change the sprites to Shiny|

### Submenu 1
Submenu 1 allows the developer to change the:
1. back and front animations for the displayed Pokémon
2. battle background
3. form of the Pokémon

#### Anatomy
Same as Main Menu.

#### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Change between options|
|Left or Right|Change values of the options|
|A|Go to Submenu 2|
|B|Go to Main Menu|
|L|Play the back animation|
|R|Play the front animation|
|START|Change the sprites to Shiny|

### Submenu 2
Submenu 2 allows the developer to change the:
1. Vertical value of the back sprite
2. Vertical value of the front sprite
3. Elevation value of the front sprite

#### Anatomy
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>
1. **Original Back Coordinate**
2. **Current Back Coordinate**
3. **Original Front Coordinate**
4. **Current Front Coordinate**
5. **Original Elevation Coordinate**
6. **Current Elevation Coordinate**

#### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Change between options|
|Left or Right|Change values of the options|
|B|Go to Submenu 1|
|L|Play the back animation|
|R|Play the front animation|
|START|Change the sprites to Shiny|