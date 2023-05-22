# Sprite Debug Menu
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

The Sprite Debug Menu is a series of menus that allow developers to quickly debug and test how Pokemon look in battle.

## Enabling the Sprite Debug Menu
The Battle Debug Menu is enabled by default, but can be toggled in [`include/config/debug.h`](../include/config/debug.h). Once enabled, pressing SELECT on the Pokemon Summary Screen will open the Sprite Debug Menu.

## Functionality
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

### Main Menu
The Main Menu is used to change the displayed Pokemon.

#### Anatomy
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

This selected Pokemon’s:
1. **Species ID**
2. **Species Name**
3. **Back Sprite**
4. **Front Sprite**
5. **Species Footprint**
6. **Species Icon**
7. **Back Animation**: The animation that plays when the player sends out the Pokemon.
8. **Front Animation**: The animation that plays when the opponent sends out the Pokemon.
9. **Battle Background**
10. **Currently Displayed Background**: The currently active background’s name.
11. **Form Indicator**: Displays when the Pokemon has multiple forms.

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
1. back and front animations for the displayed Pokemon
2. battle background
3. form of the Pokemon

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
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
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