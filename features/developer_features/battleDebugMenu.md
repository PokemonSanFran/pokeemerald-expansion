## Battle Debug Menu
<img src="" alt="" height=160px width=240px>
The Battle Debug Menu is a series of menus that allow developers to quickly debug and test various battle mechanics. Once a battle has started, developers can view and modify properties of a battle to help verify that their functionality is working correctly.

### Enabling the Battle Debug Menu
The Battle Debug Menu is enabled by default, but can be toggled in `include/config/debug.h`. Once enabled, pressing SELECT on the Fight Menu in battle will open the Battle Debug Menu.

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

#### Status 1 / Status 2 / Status 3 / Status 4 / Side Status
For the selected Pokemon, developers can change its status effects, or the status effects for that Pokemon's side of the field. 

##### On / Off
When these are set to 1, the selected Pokemon is affected by the listed status.

##### Number of Turns
The selected Pokemon is affected by the listed status for N turns. This value will be decremented at the beginning of the next turn.

##### Other
Specific effect is described.

|Page|Status|Effect Type|
|---|---|---|
|1|**Sleep**|Number of turns|
|1|**Poison**|On/Off|
|1|**Burn**|On/Off|
|1|**Freeze**|On/Off|
|1|**Paralysis**|On/Off|
|1|**Toxic Poison**|On/Off|
|1|**Toxic Counter**| Pokemon loses ((N+1)/16) HP at the end of the turn.|
|1|**Frostbite**|On/Off|
|2|**Confusion**|On/Off|
|2|**Flinch**|Pokemon is going to flinch next turn.|
|2|**Uproar**|Number of Turns|
|2|**Bide**|Pokemon releases stored Bide energy in N turns.|
|2|**Lock Confuse**| //TODO wtf is this|
|2|**Multiple Turns**|Number of Turns| 
|2|**Focus Energy**|On/Off|
|2|**Recharge**|Pokemon is recharging from their last move, and will not attack this turn.|
|2|**Rage**|On/Off|
|2|**Substitute**| //TODO wtf is this|
|2|**Destiny bond**|On/Off|
|2|**Can't escape**|On/Off|
|2|**Nightmares**|On/Off|
|2|**Cursed**|On/Off|
|2|**Foresighted**|On/Off|
|2|**Defense Curled**|On/Off|
|2|**Tormented**|On/Off|
|3|**Sure Hit**| //TODO what the hell is this|
|3|**Minimized**|On/Off|
|3|**Charged Up**|On/Off|
|3|**Rooted**|On/Off|
|3|**Yawn**| //TODO wtf is this|
|3|**Imprison**| //TODO How does this work? Pokemon is under imprison but no moves are actually disabled?|
|3|**No Crit**| //TODO what the hell is this|
|3|**Gastro Acid**| //TODO is this "under the effects of gastro acid or has ability supressed"
|3|**Smacked Down**|On/Off|
|3|**Miracle Eyed**|On/Off|
|3|**Aqua Ring**|On/Off|
|3|**Laser Focus**|On/Off|
|4|**Electrified**|On/Off|
|Side|**Reflect**|Number of Turns|
|Side|**Light Screen**|Number of Turns|
|Side|**Spikes**||
|Side|**Safeguard**|Number of Turns|
|Side|**Mist**|Number of Turns|
|Side|Aurora **Veil**|Number of Turns|
|Side|Lucky **Chant**|Number of Turns|
|Side|**Tailwind**|Number of Turns|
|Side|**Stealth Rock**|On/Off|
|Side|**Toxic Spikes**|//TODO what the hell is this
|Side|**Sticky Web**|On/Off|

#### AI
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

More information on these flags can be found in `features/game_features/improved_ai.md`

#### AI Pts/Dmg
<img src="" alt="" height=160px width=240px>
##### Anatomy
1. **Selected Pokemon**: The selected Pokemon's position on the battlefield.
2. **Pokemon Moves**: The moves for the selected Pokemon.
3. **Pokemon on Field**: The other Pokemon on the field.
4. **Points**: The number of points this move has for this Pokemon.
5. **Damage**: The approximate amount of damage this option will choose.

#### AI Info
<img src="" alt="" height=160px width=240px>
##### Anatomy
1. **Selected Pokemon**: The selected Pokemon's position on the battlefield.
2. **Pokemon on Field**: The other Pokemon on the field.
3. **Ability**: When the AI knows the Ability of this Pokemon, it is shown here.
4. **Hold Item**: When the AI knows the held item of this Pokemon, it is shown here.
5. **Hold Item Effect**: When the AI knows the effect an item is having on this Pokemon, it is shown here.

//TODO why does the ability for Pikachu change every time I enter this screen

#### AI Party
<img src="" alt="" height=160px width=240px>
//TODO come back after frostbite bug is fixed

#### Various
**Show HP**: Shows the current / Max HP for the selected Pokemon on the main battle screen.

**Substitue HP**: Creates a Substitute with N remaning HP for the selected Pokemon.

**In Love**: The selected Pokemon is infatuated.

https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915
