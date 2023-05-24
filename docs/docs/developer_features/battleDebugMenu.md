# Battle Debug Menu

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

The Battle Debug Menu is a series of menus that allow developers to quickly debug and test various battle mechanics. Once a battle has started, developers can view and modify properties of a battle to help verify that their functionality is working correctly.

## Enabling the Battle Debug Menu
The Battle Debug Menu is enabled by default, but can be toggled in [`include/config/debug.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/debug.h). Once enabled, pressing SELECT on the Fight Menu in battle will open the Battle Debug Menu.

## Functionality

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

### Anatomy
1. **Party Index**: The selected Pokémon's position on the battlefield.
2. **Pokémon Name**: The selected Pokémon's name.
3. **Properties** List of properties for that Pokémon.

### Button Interactions
|Button|Interaction|
|---|---|
|Up or Down|Scroll through list of properties|
|A|Enter submenu or make selection|
|B|Go back one menu|
|L|Go to previous Pokémon's position on battlefield.|
|R| Go to next Pokémon's position on battlefield.|
|SELECT|Return to battle|

### Move / Ability / Item

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Selecting a move with A allows the developer to change the ID of the move that specific move slot. A list of moves and their IDs are found in [`include/constants/moves.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/moves.h). Once the ID is changed, pressing A or B returns the cursor to the list of moves.

When a new move is chosen, the PP for that move is not changed or destroyed.

Selecting "All" allows the developer to change all of the move slots to be the same move.

Ability and Item work similarly, corresponding to the constants set [`include/constants/abilities.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/abilities.h) and [`include/constants/items.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/items.h).

### PP
For the selected Pokémon, selecting one of the four moves allows the developer to change the PP of that specific move.

### Types
This displays the first, second, and third types of the selected Pokémon. Selecting a type will allow the developer to change it, using the list of types in [`include/constants/pokemon.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/pokemon.h).

Pokémon like Charmander have their default Types shown as Fire / Fire.

Pokémon only have a third type when it is added by moves like [Forest's Curse](https://bulbapedia.bulbagarden.net/wiki/Forest%27s_Curse_(move)) and [Trick or Treat.](https://bulbapedia.bulbagarden.net/wiki/Trick-or-Treat_(move))

### Stats
For the selected Pokémon, selecting one of the stats will allow the developer to change the raw stat value.

### Stat Stages
For the selected Pokémon, selecting one of the stats will allow to develop to adjust the stage modification applied to each stat. The value being edited goes from 0 to 12, which correspond to -6 and +6 respectively.

Selecting "All" allows the developer to change all of the stats to apply the same stage modification.

### Status 1 / Status 2 / Status 3 / Status 4 / Side Status
For the selected Pokémon, developers can change its status effects, or the status effects for that Pokémon's side of the field. There are different types of effects:

* **On / Off**: When these are set to 1, the selected Pokémon is affected by the listed status.

* **Number of Turns**: The selected Pokémon is affected by the listed status for N turns. This value will be decremented at the beginning of the next turn.

* **Other**: Specific effect is described.

|Page|Status|Effect Type|
|---|---|---|
|1|**Sleep**|Number of turns|
|1|**[Poison](https://bulbapedia.bulbagarden.net/wiki/Poison_(status_condition))**|On/Off|
|1|**[Burn](https://bulbapedia.bulbagarden.net/wiki/Burn_(status_condition))**|On/Off|
|1|**[Freeze](https://bulbapedia.bulbagarden.net/wiki/Freeze_(status_condition))**|On/Off|
|1|**[Paralysis](https://bulbapedia.bulbagarden.net/wiki/Paralysis_(status_condition))**|On/Off|
|1|[**Toxic Poison**](https://bulbapedia.bulbagarden.net/wiki/Poison_(status_condition))|On/Off|
|1|[**Toxic Counter**](https://bulbapedia.bulbagarden.net/wiki/Poison_(status_condition))| Pokémon loses ((N+1)/16) HP at the end of the turn.|
|1|**[Frostbite](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Frostbite)**|On/Off|
|2|**[Confusion](https://bulbapedia.bulbagarden.net/wiki/Confusion_(status_condition))**|On/Off|
|2|**[Flinch](https://bulbapedia.bulbagarden.net/wiki/Flinch)**|Pokémon is going to flinch next turn.|
|2|**[Uproar](https://bulbapedia.bulbagarden.net/wiki/Uproar_(move))**|Number of Turns|
|2|**[Bide](https://bulbapedia.bulbagarden.net/wiki/Bide_(move))**|Pokémon releases stored Bide energy in N turns.|
|2|[**Rampaging**](https://bulbapedia.bulbagarden.net/wiki/Category:Moves_that_confuse_the_user_due_to_fatigue)|Number of turns Pokémon is locked into a [rampage](https://bulbapedia.bulbagarden.net/wiki/Rampage).|
|2|[**Multiple Turns**](https://bulbapedia.bulbagarden.net/wiki/Category:Consecutively_executed_moves)|Number of turns Pokémon is locked into a [consecutively executed move](https://bulbapedia.bulbagarden.net/wiki/Category:Consecutively_executed_moves) |
|2|[**Getting Pumped**](https://bulbapedia.bulbagarden.net/wiki/Focus_Energy_(move))|On/Off|
|2|**[Recharge](https://bulbapedia.bulbagarden.net/wiki/Recharge)**|Pokémon is recharging from their last move, and will not attack this turn.|
|2|**[Rage](https://bulbapedia.bulbagarden.net/wiki/Rage_(move))**|On/Off|
|2|**[Substitute](https://bulbapedia.bulbagarden.net/wiki/Substitute_(move))**|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|2|**[Destiny bond](https://bulbapedia.bulbagarden.net/wiki/Destiny_Bond_(move))**|On/Off|
|2|[**Can't escape**](https://bulbapedia.bulbagarden.net/wiki/Escape_prevention)|On/Off|
|2|[**Nightmares**](https://bulbapedia.bulbagarden.net/wiki/Nightmare_(move))|On/Off|
|2|**[Cursed](https://bulbapedia.bulbagarden.net/wiki/Curse_(move))**|On/Off|
|2|**[Foresighted](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Identified)**|On/Off|
|2|[**Defense Curl**](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Defense_Curl)|On/Off|
|2|**[Tormented](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Torment)**|On/Off|
|3|**Sure Hit**|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|3|**[Minimized](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Minimize)**|On/Off|
|3|[**Charged Up**](https://bulbapedia.bulbagarden.net/wiki/Charge_(move))|On/Off|
|3|[**Rooting**](https://bulbapedia.bulbagarden.net/wiki/Ingrain_(move))|On/Off|
|3|**[Drowsy](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Drowsy_2)**|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|3|[**Imprison**](https://bulbapedia.bulbagarden.net/wiki/Imprison_(move))|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|3|**No Crit**|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|3|[**Gastro Acid**](https://bulbapedia.bulbagarden.net/wiki/Status_condition#Ability_suppression)|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|3|**[Grounded](https://bulbapedia.bulbagarden.net/wiki/Grounded)**|On/Off|
|3|[**Miracle Eyed**](https://bulbapedia.bulbagarden.net/wiki/Miracle_Eye_(move))|On/Off|
|3|[**Aqua Ring**](https://bulbapedia.bulbagarden.net/wiki/Aqua_Ring_(move))|On/Off|
|3|[**Laser Focus**](https://bulbapedia.bulbagarden.net/wiki/Laser_Focus_(move))|On/Off|
|4|**Electrified**|On/Off|
|Side|**[Reflect](https://bulbapedia.bulbagarden.net/wiki/Reflect_(move))**|Number of Turns|
|Side|[**Light Screen**](https://bulbapedia.bulbagarden.net/wiki/Light_Screen_(move))|Number of Turns|
|Side|**[Spikes](https://bulbapedia.bulbagarden.net/wiki/Spikes_(move))**|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|Side|**[Safeguard](https://bulbapedia.bulbagarden.net/wiki/Safeguard_(move))**|Number of Turns|
|Side|**[Mist](https://bulbapedia.bulbagarden.net/wiki/Mist_(move))**|Number of Turns|
|Side|[**Aurora Veil**](https://bulbapedia.bulbagarden.net/wiki/Aurora_Veil_(move))|Number of Turns|
|Side|[**Lucky Chant**](https://bulbapedia.bulbagarden.net/wiki/Lucky_Chant_(move))|Number of Turns|
|Side|**[Tailwind](https://bulbapedia.bulbagarden.net/wiki/Tailwind_(move))**|Number of Turns|
|Side|[**Stealth Rock**](https://bulbapedia.bulbagarden.net/wiki/Stealth_Rock_(move))|On/Off|
|Side|[**Toxic Spikes**](https://bulbapedia.bulbagarden.net/wiki/Toxic_Spikes_(move))|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915)|
|Side|[**Sticky Web**](https://bulbapedia.bulbagarden.net/wiki/Sticky_Web_(move))|On/Off|

### AI

Lists the flags that are currently enabled for the AI the player is battling against. Each flag outlines a specific behavior, and impacts the points of all of the options of the AI. The AI generally chooses the option that has the most points.

Setting a flag to `1` turns the flag on, and `0` turns it off.

Only the following flags are accessible: 
* `AI_FLAG_CHECK_BAD_MOVE`
* `AI_FLAG_TRY_TO_FAINT`
* `AI_FLAG_CHECK_VIABILITY`
* `AI_FLAG_SETUP_FIRST_TURN`
* `AI_FLAG_RISKY`
* `AI_FLAG_PREFER_STRONGEST_MOVE`
* `AI_FLAG_PREFER_BATON_PASS`
* `AI_FLAG_DOUBLE_BATTLE `
* `AI_FLAG_HP_AWARE`

More information on these flags can be found in [improvedAi.md](../game_features/improved_ai.md)

### AI Pts/Dmg
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

#### Anatomy
1. **Selected Pokémon**: The selected Pokémon's position on the battlefield.
2. **Pokémon Moves**: The moves for the selected Pokémon.
3. **Pokémon on Field**: The other Pokémon on the field.
4. **Points**: The number of points this move has for this Pokémon.
5. **Damage**: The approximate amount of damage this option will choose.

### AI Info
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Displays what the AI currently knows about the player’s Pokémon.

#### Anatomy
1. **Selected Pokémon**: The selected Pokémon's position on the battlefield.
2. **Pokémon on Field**: The other Pokémon on the field.
3. **Ability**: When the AI knows the Ability of this Pokémon, it is shown here. If it does not know, it randomly shows one of the abilities for this Pokémon.
4. **Hold Item**: When the AI knows the held item of this Pokémon, it is shown here.

### AI Party
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Displays what the AI currently knows about the player’s party.

#### Anatomy
1. **Pokémon Icon and Status**: The Pokémon’s icon and its current status (blank if none).
2. **Level / Gender**: The Pokémon’s level and gender.
3. **Ability**: When the AI knows the Ability of this Pokémon, it is shown here. If it does not know, it is blank.
4. **Moves** The Pokémon’s known moves.
5. **Hold Item**: When the AI knows the held item of this Pokémon, it is shown here.
6. **Switch In Count**: The number of times this Pokémon has been switched in.

### Various
**Show HP**: Shows the current / Max HP for the selected Pokémon on the main battle screen.

**Substitute HP**: Creates a [Substitute](https://bulbapedia.bulbagarden.net/wiki/Substitute_(move)) with N remaining HP for the selected Pokémon.

**In Love**: The selected Pokémon is [infatuated](https://bulbapedia.bulbagarden.net/wiki/Infatuation).
