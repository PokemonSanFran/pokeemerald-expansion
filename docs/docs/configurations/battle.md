# Battle Configuration

This page documents the configurations found in [`include/config/battle.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/battle.h).

## Calculations

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

* `B_CRIT_CHANCE` - Type: Generation Toggle
    * The chances of landing a critical hit when the user increases their critical hit stage changes between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Probability_2)

| Stage | <=`GEN_5` | `GEN_6` | >=`GEN_7` |
| ----- | --------- | ------- | --------- |
| +0    | 1/16      | 1/16    | 1/24      |
| +1    | 1/8       | 1/8     | 1/8       |
| +2    | 1/4       | 1/2     | 1/2       |
| +3    | 1/3       | 1/1     | 1/1       |
| >= +4 | 1/2       | 1/1     | 1/1       |

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CRIT_MULTIPLIER` - Type: Generation Toggle
    - Critical hits multiply their damage by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Damage_2)
        - \>= `GEN_6`: 2
        - <= `GEN_5`: 1.5

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PARALYSIS_SPEED` - Type: Generation Toggle
    - Paralysis reduces the afflicted Pokémon's Speed by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Paralysis_(status_condition)#Effect)
        - \>= `GEN_7`: 50%
        - <= `GEN_6`: 75%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CONFUSION_SELF_DMG_CHANCE` - Type: Generation Toggle
    - The likelihood of a Confused Pokémon hurting themselves in confusion is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Confusion_(status_condition)#Effect)
        - \>= `GEN_7`: 33.3%
        - <= `GEN_6`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MULTI_HIT_CHANCE` - Type: Generation Toggle
    -  The percent chance of a multi-hit move getting multiple hits uses the formula from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Multi-strike_move#Effect)
        - \>= `GEN_5`: Gen 5
        - <= `GEN_4`: Gen 1

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_WHITEOUT_MONEY` - Type: Generation Toggle
    - After whiting out, the player's money is reduced by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Black_out#Formula_for_money_lost)
        - \>= `GEN_4`: a formula
        - <= `GEN_3`: 50%

## Experience and Stat

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_EXP_CATCH` - Type: Generation Toggle
    - When the player catches a Pokémon in battle, the experienced gained by the player Pokémon is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Experience#Experience_gain_in_battle)
        - \>= `GEN_6`: the same as knocking out said Pokémon.
        - <= `GEN_5`: zero.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TRAINER_EXP_MULTIPLIER` - Type: Generation Toggle
    - The experience gained from trainer battles versus wild battles is multiplied by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Experience#Gain_formula)
        - \>= `GEN_7`: 1
        - <= `GEN_6`: 1.5

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SPLIT_EXP` - Type: Generation Toggle
    - Pokémon that participated in battle but did not deliver the knockout will receive the total experience from the fight multiplied by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Experience#Gain_formula)
        - \>= `GEN_6`: 1
        - <= `GEN_5`: 1/N, where N is the number of Pokémon that experience is being split with.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SCALED_EXP` - Type: Generation Toggle
    - Experience gained in battle is weighed by the difference in Level between the Pokémon that was knocked out and the Pokémon that is recieving the experience. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Experience#Gain_formula)
        - \>= `GEN_7`: True
        - = `GEN_6`: False
        - = `GEN_5`: True
        - <= `GEN_4`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BADGE_BOOST` - Type: Generation Toggle
    - Receiving Gym Badges boost the stats of a player's Pokémon. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Badge#Stat_boost)
        - \>= `GEN_4`: False
        - <= `GEN_3`: True

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MAX_LEVEL_EV_GAINS` - Type: Generation Toggle
    - When a Pokémon reaches Level 100, the ability for a Pokémon to receive Effort Values: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Effort_values#Generation_V)
        - \>= `GEN_5`: functions as normal.
        - <= `GEN_4`: is removed.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_RECALCULATE_STATS` - Type: Generation Toggle
    - The stats for each Pokémon who participate in battle are recalculated: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Effort_values#Generation_V)
        - \>= `GEN_5`: at the end of each battle
        - <= `GEN_4`: when the Pokémon is placed in a PC box.

## Damage 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BURN_DAMAGE` - Type: Generation Toggle
    - In between turns, Burned Pokémon will receive damage equal to N of their total HP. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Burn_(status_condition)#Effect)
        - \>= `GEN_7`: 1/16th
        - <= `GEN_6`: 1/8th

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BURN_FACADE_DMG` - Type: Generation Toggle
    - A Burned Pokémon using the move Facade will have their damage from physical attacks reduced by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Burn_(status_condition)#Generation_VI)
        - \>= `GEN_6`: 0%
        - <= `GEN_5`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BINDING_DAMAGE` - Type: Generation Toggle
    - In between turns, Pokémon receiving binding damage will receive damage equal to N of their total HP. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Binding_Band#Generation_VI_onward)
        - \>= `GEN_6`: 1/8 (1/6 with Binding Band)
        - <= `GEN_5`: 1/16 (1/8 with Binding Band)

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PSYWAVE_DMG` - Type: Generation Toggle
    -  The damage for the move Psywave uses the formula from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Psywave_(move)#Effect)
        - \>= `GEN_5`: Generation 5
        - <= `GEN_4`: Generation 3

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PAYBACK_SWITCH_BOOST` - Type: Generation Toggle
    - If the damage from the move Payback is to be doubled, and the target switches out, the damage is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Payback_(move)#Generation_V_onwards)
        - \>= `GEN_5`: no longer doubled
        - <= `GEN_4`: still doubled

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HIDDEN_POWER_DMG` - Type: Generation Toggle
    - Hidden Power's base power is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Hidden_Power_(move)#Effect)
        - \>= `GEN_6`: always 60
        - <= `GEN_5`: determined by the attacking Pokémon's IVs

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ROUGH_SKIN_DMG` - Type: Generation Toggle
    - The damage dealt to the attacking Pokémon from Rough Skin or Iron Barbs is equal to N of their total HP. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Rough_Skin_(Ability)#Generation_IV_onward)
        - \>= `GEN_4`: 1/8
        - <= `GEN_3`: 1/16

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_KNOCK_OFF_DMG` - Type: Generation Toggle
    - When the move Knock Off removes an item from the targeted Pokémon, the damage from Knock Off is increased by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Knock_Off_(move)#Generation_VI_onwards)
        - \>= `GEN_6`: 50%
        - <= `GEN_5`: 0%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SPORT_DMG_REDUCTION` - Type: Generation Toggle
    - Damage from Fire/Electric moves under the effects of Water/Mud Sport are reduced by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Mud_Sport_(move)#Generation_V)
        - \>= `GEN_5`: 67%
        - <= `GEN_4`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_EXPLOSION_DEFENSE` - Type: Generation Toggle
    - Pokémon that are targeted by Self-Destruct and Explosion have their Defense reduced by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Explosion_(move)#Generation_V)
        - \>= `GEN_5`: 0%
        - <= `GEN_4`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PARENTAL_BOND_DMG` - Type: Generation Toggle
    - Parental Bond's second hit gets its damage by reducing the initial hit's damage by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Parental_Bond_(Ability)#Generation_VII_onward)
        - \>= `GEN_7`: 75%
        - <= `GEN_6`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MULTIPLE_TARGETS_DMG` - Type: Generation Toggle
    - Damage dealt to multiple targets at once is reduced by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Double_Battle#Effects_on_moves)
        - \>= `GEN_4`: 75%
        - <= `GEN_3`: 50%

## Type settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_GHOSTS_ESCAPE` - Type: Generation Toggle
    - Abilities like Shadow Tag or moves like Mean Look fail on Ghost-type Pokémon. They can also escape any Wild Battle. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Ghost_(type)#Generation_VI_onwards) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PARALYZE_ELECTRIC` - Type: Generation Toggle
    - Electric-type Pokémon can't be paralyzed. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Electric_(type)#Generation_II_onwards) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_POWDER_GRASS` - Type: Generation Toggle
    - Grass-type Pokémon are immune to powder and spore moves. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Grass_(type)#Generation_II_onwards) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_STEEL_RESISTANCES` - Type: Generation Toggle
    - Steel-type Pokémon are resistant to Dark-type and Ghost-type moves. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Steel_(type)#Generations_II_to_V) 
        - \>= `GEN_6`: False
        - <= `GEN_5`: True

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PRANKSTER_DARK_TYPES` - Type: Generation Toggle
    - Prankster-elevated status moves do not affect Dark type Pokémon. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Dark_(type)#Generation_VI_onwards) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SHEER_COLD_IMMUNITY` - Type: Generation Toggle
    - Ice-types are immune to Sheer Cold. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Ice_(type)#Generation_II_onwards) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ROOST_PURE_FLYING` - Type: Generation Toggle
    - When a pure Flying-type Pokémon uses Roost, their type changes to [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Flying_(type)#Defense) 
        - \>= `GEN_7`: Normal
        - <= `GEN_6`: Type-less

## Turn settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BINDING_TURNS` - Type: Generation Toggle
    - Binding moves last for a duration of [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Category:Binding_moves) 
        - \>= `GEN_5`: 4-5 turns
        - <= `GEN_4`: 2-5 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_UPROAR_TURNS` - Type: Generation Toggle
    - Uproar lasts for a duration of [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Uproar_(move)#Generation_V_onwards) 
        - \>= `GEN_5`: 3 turns
        - <= `GEN_4`: 2-5 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DISABLE_TURNS` - Type: Generation Toggle
    - The effects of Disable last for [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Disable_(move)#Generation_IV) 
        - \>= `GEN_5`: 4 turns
        - = `GEN_4`: 4 - 7 turns
        - = `GEN_3`: 2 - 5 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TAILWIND_TURNS` - Type: Generation Toggle
    - The effects of Tailwind last for [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Tailwind_(move)#Generation_V) 
        - \>= `GEN_5`: 4 turns
        - <= `GEN_4`: 3 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SLEEP_TURNS` - Type: Generation Toggle
    - The duration of the Sleep status lasts for [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Sleep_(status_condition)#Generation_V) 
        - \>= `GEN_5`: 1 - 3 turns
        - <= `GEN_4`: 2 - 5 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TAUNT_TURNS` - Type: Generation Toggle
    - The effects of Taunt lasts for [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Taunt_(move)#Generation_IV) 
        - \>= `GEN_5`: 3 turns if the user acts before the target, or 4 turns if the target acted before the user: [More Info]
        - = `GEN_4`: 3 - 5 turns
        - <= `GEN_3`: 2 turns

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SPORT_TURNS` - Type: Generation Toggle
    - The effects of Mud / Water Sport last for: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Water_Sport_(move)#Generations_VI_and_VII) 
        - \>= `GEN_6`: 5 turns, even if the user switches out
        - <= `GEN_5`: as long as the user is on the field

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MEGA_EVO_TURN_ORDER`	 - Type: Generation Toggle
    - A Pokémon's turn order is determined by its Speed: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Mega_Evolution#Generation_VII) 
        - \>= `GEN_7`: after Mega Evolution
        - <= `GEN_6`: before Mega Evolution

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_RECALC_TURN_AFTER_ACTIONS` - Type: Generation Toggle
    - Switching or using a move will affect the current turn's order of actions.
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FAINT_SWITCH_IN` - Type: Generation Toggle
    - When a Pokémon faints in battle, it is replaced [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_battle#Fight) 
        - \>= `GEN_4`: at the end of the current turn.
        - <= `GEN_3`: at the end of the current action.

## Move data settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_UPDATED_MOVE_DATA` - Type: Generation Toggle
    - Moves that change their data (Power, Accuracy, PP, stat change, targets, chance of secondary effects) will use this toggle to determine which generation's data to abide by.
        - **Example**: [Tailwind](https://bulbapedia.bulbagarden.net/wiki/Tailwind_(move)#Generation_VI_onwards) has had its PP changed between generations. If `B_UPDATED_MOVE_DATA` >= `GEN_6`, Tailwind's PP is 15. Otherwise it is 30.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_UPDATED_MOVE_TYPES` - Type: Generation Toggle
    - Moves that change their type will use this toggle to determine which generation's data to abide by.
        - **Example**: [Moonlight](https://bulbapedia.bulbagarden.net/wiki/Moonlight_(move)#Generation_VI_onwards) has had its type changed between generations. If `B_UPDATED_MOVE_TYPES` >= `GEN_6`, Moonlight is a Fairy-type move. Otherwise it is Normal-type.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PHYSICAL_SPECIAL_SPLIT` - Type: Generation Toggle
    - Moves are assigned a damage category (Physical / Special / Status): [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Damage_category#Physical.2FSpecial_split) 
        - \>= `GEN_4`: On a move by move basis
        - <= `GEN_3`: based on their type

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_RECOIL_IF_MISS_DMG` - Type: Generation Toggle
    - When the moves High Jump Kick and Jump Kick miss their target, the user takes damage equal to 1/2 of their total HP [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Jump_Kick_(move)#Generations_V_to_VII) 
        - \>= `GEN_5`: at all times
        - <= `GEN_4`: if the move would deal damage greater than the target's max HP divided by 2.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_KLUTZ_FLING_INTERACTION` - Type: Generation Toggle
    - Pokémon with the Ability Klutz cannot use Fling. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Klutz_(Ability)#Generation_V) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_UPDATED_CONVERSION` - Type: Generation Toggle
    - Conversion changes the user's type to match the type of: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Conversion_(move)#Generations_VI_and_VII) 
        - \>= `GEN_6`: the user's first move
        - <= `GEN_5`: one of the user's moves, chosen at random.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PP_REDUCED_BY_SPITE` - Type: Generation Toggle
    - The effects of Spite reduces the target's last move's PP by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Spite_(move)#Generation_IV) 
        - \>= `GEN_4`: 4
        - = `GEN_3`: 2 to 5

## Move accuracy settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TOXIC_NEVER_MISS` - Type: Generation Toggle
    - If Toxic is used by a Poison-type Pokémon, it will never miss. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Toxic_(move)#Generation_VI_onwards) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MINIMIZE_DMG_ACC` - Type: Generation Toggle
    - Moves that causes double damage to minimized Pokémon will also skip accuracy checks. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Category:Moves_that_become_stronger_against_a_Minimized_target) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BLIZZARD_HAIL` - Type: Generation Toggle
    - Blizzard bypasses accuracy checks if it's hailing. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Blizzard_(move)#Generations_IV_and_V) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SHEER_COLD_ACC` - Type: Generation Toggle
    - If the user is an Ice-type, the base chance of Sheer Cold hitting the target is [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Sheer_Cold_(move)#Generation_VII_onwards) 
        - \>= `GEN_7`: 20% 
        - <= `GEN_6`: 30%


## Move stat change settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FELL_STINGER_STAT_RAISE` - Type: Generation Toggle
    - When damage from Fell Stinger causes the target to faint, the user's Attack is raised by [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Fell_Stinger_(move)#Generation_VII_onwards) 
        - \>= `GEN_7`: 3 stages
        - <= `GEN_6`: 2 stages

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_KINGS_SHIELD_LOWER_ATK` - Type: Generation Toggle
    - The effect's of King's Shield reduces the Attack of the attacking Pokémon by [[More Info]](https://bulbapedia.bulbagarden.net/wiki/King%27s_Shield_(move)#Effect) 
        - \>= `GEN_8`: 1 stage
        - <= `GEN_7`: 2 stages

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SPEED_BUFFING_RAPID_SPIN` - Type: Generation Toggle
    - Rapid Spin raises the user's Speed by 1 stage. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Rapid_Spin_(move)#Generation_VIII_onwards) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CHARGE_SPDEF_RAISE` - Type: Generation Toggle
    - Charge raises the user's Special Defense by 1 stage. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Charge_(move)#Generation_IV-VIII) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MINIMIZE_EVASION` - Type: Generation Toggle
    - Minimize raises evasion by [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Minimize_(move)#Generation_V) 
        - \>= `GEN_5`: 2 stages
        - <= `GEN_4`: 1 stage

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_GROWTH_STAT_RAISE` - Type: Generation Toggle
    - Growth's mechanics change between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Growth_(move)#Generation_V) 
        - \>= `GEN_5`: Growth raises Attack and Special Attack by one stage. In sunlight, these effects are doubled.
        - <= `GEN_4`: Growth raises Special Attack by one stage. In sunlight, these are not amplified.


## Other move settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SOUND_SUBSTITUTE` - Type: Generation Toggle
    - Sound moves bypass Substitute. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Category:Sound-based_moves) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_INCINERATE_GEMS` - Type: Generation Toggle
    - Incinerate can destroy Gems. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Incinerate_(move)#Generation_VI_onwards) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CAN_SPITE_FAIL` - Type: Generation Toggle
    - Spite fails if the target's last move only has 1 remaining PP. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Spite_(move)#Generation_IV) 
        - \>= `GEN_4`: False
        - = `GEN_3`: True

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CRASH_IF_TARGET_IMMUNE` - Type: Generation Toggle
    - If the target of Jump Kick or High Jump Kick is immune, the user will be dealt damage as if the move missed. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/High_Jump_Kick_(move)#Generation_IV) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MEMENTO_FAIL` - Type: Generation Toggle
    - Memento fails if there is no target or if the target is protected or behind substitute. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Memento_(move)#Generation_IV_onward) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_GLARE_GHOST` - Type: Generation Toggle
    - Ghost-type Pokémon are immune to Glare. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Ghost_(type)#Generations_II_to_V) 
        - \>= `GEN_4`: False 
        - = `GEN_3`: True 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SKILL_SWAP` - Type: Generation Toggle
    -  After Skill Swap was successful, if an Ability that normally activates on switch in was affected, it immediately activates. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Skill_Swap_(move)#Generation_IV) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BRICK_BREAK` - Type: Generation Toggle
    - Brick Break gains new properties between generations: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Brick_Break_(move)#Generation_IV) 
        - \>= `GEN_5`: If the target is immune to Brick Break, screens are not removed.
        - \>= `GEN_4`: An ally's screen can be broken by Brick Break.
        - = `GEN_3`: An ally's screen can not be broken by Brick Break. If the target is immune to Brick Break, screens are removed. 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_WISH_HP_SOURCE` - Type: Generation Toggle
    - Wish heals half of the Max HP of the: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Wish_(move)#Generation_V) 
        - \>= `GEN_5`: user
        - <= `GEN_4`: target

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_RAMPAGE_CANCELLING` - Type: Generation Toggle
    - When a Pokémon is rampaging and its attack fails, the rampage will: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Outrage_(move)#Generation_V) 
        - \>= `GEN_5`: be cancelled, except on the last turn.
        - <= `GEN_4`: not be affected.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HEAL_BLOCKING` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Heal_Block_(move)#Effect) 
        - \>= `GEN_6`: Heal Block prevents the usage of HP-draining moves.
        - \>= `GEN_5`: Heal Block prevents healing from Black Sludge, Leftovers, and Shell Bell. Heal Block prevents the consumption of HP-restoring Berries or Berry Juice.
        - <= `GEN_4`: Heal Block allows the usage of HP-draining moves. Heal Block allows the consumption of HP-restoring Berries or Berry Juice.
                                                        

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ROOTED_GROUNDING` - Type: Generation Toggle
    - Ingrain causes the affected Pokémon to become grounded. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Ingrain_(move)#Generations_IV_and_V) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_METRONOME_MOVES` - Type: Generation Toggle
    - Metronome will randomly choose from the generation that is defined here, and every generation prior to it.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TELEPORT_BEHAVIOR` - Type: Generation Toggle
    - Teleport allows the user to swap out with another party member. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Teleport_(move)#Generation_VII) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BEAT_UP` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Beat_Up_(move)#Generation_V_onwards) 
        - \>= `GEN_5`:  Beat Up uses its Gen 5 formula to calculate damage. Beat Up deals Dark-Type damage. Beat Up does not announce each member of the user's party.
        - <= `GEN_4`: Beat Up uses its Gen 2 formula to calculate damage. Beat Up deals typeless damage. Beat Up announce each member of the user's party.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DARK_VOID_FAIL` - Type: Generation Toggle
    - When a Pokémon other than Darkrai uses the move Dark Void, the move will fail. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Dark_Void_(move)#Generation_VII) 
        - \>= `GEN_7`: True 
        - <= `GEN_6`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BURN_HIT_THAW` - Type: Generation Toggle
    - When a non-Fire type damaging move with a chance to cause Burn hits a Frozen target, there is a chance the target will be defrosted. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Freeze_(status_condition)#Curing) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HEALING_WISH_SWITCH` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Healing_Wish_(move)#Generation_V_to_VII) 
        - \>= `GEN_8`: Healing Wish's effect will be stored until an ally that is damaged or affected by status is sent out.
        - <= `GEN_5`: The Pokémon receiving the Healing Wish is sent out at the end of the turn.
        - <= `GEN_4`: The Pokémon recieving the Healing Wish will be immedatiately sent out, and the effect will instantly activate. 
                                                        

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DEFOG_CLEARS_TERRAIN` - Type: Generation Toggle
    - Defog clears active Terrain. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Defog_(move)#Generation_VIII_onwards) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_STOCKPILE_RAISES_DEFS` - Type: Generation Toggle
    - Stockpile raises Defense and Special Defense stats, which are negated once Spit Up or Swallow is used. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Stockpile_(move)#Generation_IV_onwards) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False


## Ability settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_EXPANDED_ABILITY_NAMES` - Type: True / False
    - Ability names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ABILITY_WEATHER` - Type: Generation Toggle
    - Sand Stream, Snow Warning, Drought, and Drizzle summon their respective weather for N turns. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Drizzle_(Ability)#Generation_VI_onward) 
        - \>= `GEN_6`: 5
        - <= `GEN_5`: ∞

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_GALE_WINGS` - Type: Generation Toggle
    - Gale Wings activates when the user's HP is at N. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Gale_Wings_(Ability)#Generation_VII_onwards) 
        - \>= `GEN_7`: 100%
        - <= `GEN_6`: Any

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_STANCE_CHANGE_FAIL` - Type: Generation Toggle
    - Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc.  [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Stance_Change_(Ability)#Generation_VII_onward) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SHADOW_TAG_ESCAPE` - Type: Generation Toggle
    - When both sides of a battle are affected by Shadow Tag, both sides are able to switch. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Shadow_Tag_(Ability)#Generation_IV_onward) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MOODY_ACC_EVASION` - Type: Generation Toggle
    - Moody can modify evasion and/or accuracy. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Moody_(Ability)) 
        - \>= `GEN_8`: False
        - <= `GEN_7`: True

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FLASH_FIRE_FROZEN` - Type: Generation Toggle
    - Flash Fire triggers when user is frozen. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Flash_Fire_(Ability)#Generation_V_onwards) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SYNCHRONIZE_NATURE` - Type: Generation Toggle
    - When the first Pokémon in the party has Synchronize, the odds that wild Pokémon will have a Nature that matches the first Pokémon are: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Synchronize_(Ability)#Generation_VIII) 
        - \>= `GEN_8`: 100%
        - <= `GEN_7`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SYNCHRONIZE_TOXIC` - Type: Generation Toggle
    -  When a Pokémon with Synchronize is badly poisoned, Synchronize will inflict the opponent with: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Synchronize_(Ability)#Generation_V_onward) 
        - \>= `GEN_5`: the badly poisoned status
        - <= `GEN_4`: poisoned status

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_UPDATED_INTIMIDATE` - Type: Generation Toggle
    - Intimidate activates Rattled, and is blocked by Inner Focus, Scrappy, Own Tempo, and Oblivious. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Intimidate_(Ability)#Generation_VIII_onward) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_OBLIVIOUS_TAUNT` - Type: Generation Toggle
    - Oblivious blocks the effect of Taunt. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Oblivious_(Ability)#Generation_VI_to_VII) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_STURDY` - Type: Generation Toggle
    - If a Pokémon has Sturdy and has full HP and is hit by a non one-hit knockout move that would knock it out: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Sturdy_(Ability)#Generation_V_onward) 
        - \>= `GEN_`: Sturdy will leave it with 1 HP.
        - \>= `GEN_`: Sturdy will not activate.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_PLUS_MINUS_INTERACTION` - Type: Generation Toggle
    - Plus and Minus are activated by an ally having: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Plus_(Ability)#Generation_V_onward) 
        - \>= `GEN_5`: Plus or Minus
        - <= `GEN_4`: the opposing ability 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_WEATHER_FORMS` - Type: Generation Toggle
    - When a Pokémon has Flower Gift or Forecast, they can only transform when they have those abilities. When those abilities are lost or disabled, those Pokémon revert into their base form. [[More Info]]() 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SYMBIOSIS_GEMS` - Type: Generation Toggle
    - After a Pokémon consumes a Gem, an item from an ally with Symbiosis is transferred: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Symbiosis_(Ability)#Generation_VI) 
        - \>= `GEN_7`: after the attack
        - <= `GEN_6`: before the attack

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CHECK_IF_CHARGED_UP` - Type: True / False
    - When `TRUE`, Abilities that "Charge" the user will not activate if the user is already Charged. [More Info] 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ABSORBING_ABILITY_STRING` - Type: Generation Toggle
    - The message that displays when abilities absorb moves of a certain type is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Charge_(move)#Generation_IX) 
        - \>= `GEN_5`: generic across all stat increases and decreases
        - <= `GEN_4`: specific for each increase and decrease


## Item settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HP_BERRIES` - Type: Generation Toggle
    - Berries which restore HP activate [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Oran_Berry#Generation_IV_onward) 
        - \>= `GEN_4`: immediately after HP drops to less than 51%
        - <= `GEN_3`: the end of the turn when the holder's HP drops to less than 51%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_BERRIES_INSTANT` - Type: Generation Toggle
    - Berries that Pokémon are eligible for consumption will be consumed:
        - \>= `GEN_4`: as soon as the Pokémon switches in
        - <= `GEN_3`: at the turn or move end

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CONFUSE_BERRIES_HEAL` - Type: Generation Toggle
    - Confusion berries mechanics change between generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Wiki_Berry#Generation_VII) 
        - \>= `GEN_8`: Confusion berries restore 1/3 of the user's maximum HP and activates when the user's HP drops below 26%.
        - = `GEN_7`: Confusion berries restore 50% of the user's maximum HP and activates when the user's HP drops below 26%.
        - <= `GEN_6`: Confusion berries restore 12.5% of the user's maximum HP and activates when the user's HP drops below 51%.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_X_ITEMS_BUFF` - Type: Generation Toggle
    - Battle Items raise their respective stat by N stages.  [[More Info]](https://bulbapedia.bulbagarden.net/wiki/X_Attack#Generation_VII_onward)
        - \>= `GEN_7`: 2
        - <= `GEN_6`: 1

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MENTAL_HERB` - Type: Generation Toggle
    - Mental Herb cures Infatuation: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Mental_Herb#Generation_V_onward) 
        - \>= `GEN_5`: as well as Taunt, Encore, Torment, Heal Block, and Disable
        - <= `GEN_4`: and nothing else

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TRAINERS_KNOCK_OFF_ITEMS` - Type: True / False
    - When `TRUE`, opposing trainers can steal the player's items. Items that are [berries](https://bulbapedia.bulbagarden.net/wiki/Berry) are restored after battle.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SOUL_DEW_BOOST` - Type: Generation Toggle
    - Soul Dew boosts Latios and Latias': [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Soul_Dew#Generation_VII_onward) 
        - \>= `GEN_7`: Psychic and Dragon-type moves
        - <= `GEN_6`: Special Attack and Special Defense 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_NET_BALL_MODIFIER` - Type: Generation Toggle
    - Net Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Net_Ball#Generation_VII_onward) 
        - \>= `GEN_7`: 5x
        - <= `GEN_6`: 3x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DIVE_BALL_MODIFIER` - Type: Generation Toggle
    - Dive Ball's catch multiplier is applied when the player is diving,: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Dive_Ball#Generation_IV_to_VIII) 
        - \>= `GEN_4`: surfing or fishing
        - = `GEN_3`: and nothing else

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_NEST_BALL_MODIFIER` - Type: Generation Toggle
    - Nest Ball's catch formula uses the formula from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Nest_Ball#Effect)
        - \>= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - <= `GEN_4`: Generation 3

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_REPEAT_BALL_MODIFIER` - Type: Generation Toggle
    - Repeat Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Repeat_Ball#Generation_VII) 
        - \>= `GEN_7`: 3.5x
        - <= `GEN_6`: 3x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TIMER_BALL_MODIFIER` - Type: Generation Toggle
    - Every turn, Timer Ball's catch multiplier increases by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Timer_Ball#Effect) 
        - \>= `GEN_5`: 0.3
        - <= `GEN_4`: 0.1

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DUSK_BALL_MODIFIER` - Type: Generation Toggle
    - Dusk Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Dusk_Ball#Generation_VII_onward) 
        - \>= `GEN_7`: 3x
        - <= `GEN_6`: 3.5x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_QUICK_BALL_MODIFIER` - Type: Generation Toggle
    - Quick Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Quick_Ball#Generation_V_onward) 
        - \>= `GEN_5`: 5x
        - <= `GEN_4`: 4x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_LURE_BALL_MODIFIER` - Type: Generation Toggle
    - Lure Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Lure_Ball#Effect) 
        - \>= `GEN_7`: 5x
        - <= `GEN_6`: 3x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HEAVY_BALL_MODIFIER` - Type: Generation Toggle
    - Heavy Ball's formula uses the formula from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Heavy_Ball#Effect) 
        - \>= `GEN_7`: Generation 7
        - \>= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DREAM_BALL_MODIFIER` - Type: Generation Toggle
    - Dream Ball's catch multiplier when the target is asleep or has the ability Comatose is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Dream_Ball#Generation_VIII_onward) 
        - \>= `GEN_8`: 4x
        - <= `GEN_7`: 1x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SPORT_BALL_MODIFIER` - Type: Generation Toggle
    - Sport Ball's catch multiplier is: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Sport_Ball#Generation_VIII_onward) 
        - \>= `GEN_8`: 1x
        - <= `GEN_7`: 1.5x

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SERENE_GRACE_BOOST` - Type: Generation Toggle
    - Serene Grace boosts the flinch chance of King's Rock and Razor Fang. [More Info] 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False


## Flag settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FLAG_INVERSE_BATTLE` - Type: Var / Flag
    -  When this flag is set in game, the type effectiveness interactions are reversed. For example, Fire becomes super effective against water. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FLAG_FORCE_DOUBLE_WILD` - Type: Var / Flag
    - When this flag is set in game, all land and surfing wild battles will be double battles. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Double_Battle#In_the_games) 

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SMART_WILD_AI_FLAG` - Type: Var / Flag
    - When this flag is set in game, wild Pokémon will use the AI behavior defined by `B_VAR_WILD_AI_FLAGS`.

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FLAG_NO_BAG_USE` - Type: Var / Flag
    - When this flag is set in game, the ability to use the bag in battle is disabled.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FLAG_NO_CATCHING` - Type: Var / Flag
    - When this flag is set in game, the ability to throw Pokéballs is disabled.

## Var Settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `VAR_TERRAIN` - Type: Var / Flag
    - When this var is set in game, the Terrain is automatically set for the duration at the beginning of the next battle. This behavior persists until the variable is set to 0. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Terrain#Effects) 

        - `STATUS_FIELD_GRASSY_TERRAIN`: Grassy Terrain
        - `STATUS_FIELD_MISTY_TERRAIN`: Misty Terrain
        - `STATUS_FIELD_ELECTRIC_TERRAIN`: Electric Terrain
        - `STATUS_FIELD_PSYCHIC_TERRAI`: Psychic Terrain

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_VAR_WILD_AI_FLAGS` - Type: Var / Flag
    - When this var set in game and is greater than 0 or less than 15, this var controls the behavior of wild Pokémon when `B_SMART_WILD_AI_FLAG` is set. The behaviors are defined in `sBattleAiFuncTable`, and described in [game_features/improved_ai](../game_features/improved_ai). For each behavior in the table's default state, Wild Pokémon will:
        - = `0`: `AI_FLAG_CHECK_BAD_MOVE`
        - = `1`: `AI_FLAG_TRY_TO_FAINT`
        - = `2`: `AI_FLAG_CHECK_VIABILITY`
        - = `3`: `AI_FLAG_SETUP_FIRST_TURN`
        - = `4`: `AI_FLAG_RISKY`
        - = `5`: `AI_FLAG_PREFER_STRONGEST_MOVE`
        - = `6`: `AI_FLAG_PREFER_BATON_PASS`
        - = `7`: `AI_FLAG_DOUBLE_BATTLE`
        - = `8`: `AI_FLAG_HP_AWARE`
        - = `9`: `AI_FLAG_NEGATE_UNAWARE`
        - = `10`: `AI_FLAG_WILL_SUICIDE`
        - = `11`: `AI_FLAG_HELP_PARTNER`
        - \>= `15`: This will behave as if the var is set to 0.

## Terrain settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TERRAIN_BG_CHANGE` - Type: True / False
    - When `TRUE`, when terrain changes, the battle background changes to match until the change fades.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_THUNDERSTORM_TERRAIN` - Type: True / False
    - When `TRUE` _and_ the overworld's weather is set to `WEATHER_RAIN_THUNDERSTORM`, Electric Terrain will be permanently set when a battle begins. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Rain#Thunderstorm_2) 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TERRAIN_TYPE_BOOST` - Type: Generation Toggle
    - Terrain boosts the damage of their corresponding moves by: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Terrain#Effects) 
        - \>= `GEN_8`: 30%
        - <= `GEN_7`: 50%

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SECRET_POWER_EFFECT` - Type: Generation Toggle
    -  The effects for Secret Power uses the environment table from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Secret_Power_(move)#In_battle) 
        - \>= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SECRET_POWER_ANIMATION` - Type: Generation Toggle
    - The animation for Secret Power uses the environment table from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Secret_Power_(move)#In_battle) 
        - \>= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - \>= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_NATURE_POWER_MOVES` - Type: Generation Toggle
    - The move called by Nature Power uses the environment table from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Nature_Power_(move)#Effect) 
        - \>= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

---

<p align="center">
  <video width="240" height="160" controls>
    <source src="../../img/placeholder.mp4" type="video/mp4">
  Your browser does not support the video tag.
  </video>
</p>

- `B_CAMOUFLAGE_TYPES` - Type: Generation Toggle
    - The type assigned by the move Camouflage uses the environment table from: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Camouflage_(move)#Effect) 
        - \>= `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3


## Interface settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_ABILITY_POP_UP` - Type: True / False
    - Abilities are announced via: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Generation_V#Alterations_from_Generation_IV) 
        - `TRUE`: a Battle Slide message 
        - `FALSE`: the standard message box

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FAST_INTRO` - Type: True / False
    - Battle intro text prints:
        - `TRUE`: as Pokémon animations are playing
        - `FALSE`: after Pokémon animations have finished

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_FAST_HP_DRAIN` - Type: True / False
    - The speed at which HP drains from the HP Bar is:
        - `TRUE`: variable, based on the max HP of the Pokémon 
        - `FALSE`: constant 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SHOW_TARGETS` - Type: True / False
    - When `TRUE` _and_ a move has multiple targets, the targets will all be shown when the cursor is hovering over said move in the move menu.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SHOW_SPLIT_ICON` - Type: True / False
    - When `TRUE`, an icon on the Move's summary to indicate the move's classification is shown. 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_HIDE_HEALTHBOX_IN_ANIMS` - Type: True / False
    - When `TRUE`, health boxes are shown during move animations.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_EXPANDED_MOVE_NAMES` - Type: True / False
    - Move names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_WAIT_TIME_MULTIPLIER` - Type: Set Value
    - This value is the base number of frames for pauses within battles - lower values will result in faster battles. Long, Medium, and Short pauses multiply this value by 4, 3 and 2 respectively. The default value in `pokeemerald` is 16.

## Catching settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_SEMI_INVULNERABLE_CATCH` - Type: Generation Toggle
    - Pokémon that are in a semi-invulnerable state cannot be targeted for Pokeball capture. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Semi-invulnerable_turn#Generation_IV_onward) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CATCHING_CHARM_BOOST` - Type: Set Value
    - When the player has the Catching Charm, this value increases the odds of a Critical Capture by N%. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Catching_Charm) 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_CRITICAL_CAPTURE` - Type: True / False
    - When `TRUE`, Critical Capture is enabled. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Catch_rate#Critical_capture)

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_LAST_USED_BALL` - Type: True / False
    - When `TRUE`, "Last Used Ball" is enabled.

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_LAST_USED_BALL_BUTTON` - Type: Set Value
    - When `B_LAST_USED_BALL` is `TRUE`, the button (or combination of buttons) set here will trigger throwing the last used ball. [More Info]
    - Some examples include:
        - `R_BUTTON`
        - `R_BUTTON + A_BUTTON`
        - `DPAD_ANY`

## Other settings

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_DOUBLE_WILD_CHANCE` - Type: Set Value
    - When a wild battle is initiated, this value is the N% chance that the battle will be a Double Battle. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Double_Battle#In_the_games) 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_MULTI_BATTLE_WHITEOUT` - Type: Generation Toggle
    - During a Multi Battle, when the player has no Pokémon available to fight, but their partner has Pokémon available to fight, the battle: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Multi_Battle#Trivia) 
        - \>= `GEN_4`: continues until one side has no Pokémon
        - = `GEN_3`: is lost by the player

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_EVOLUTION_AFTER_WHITEOUT` - Type: Generation Toggle
    - When a Pokémon has reached the criteria for evolution during battle, but then the player then loses the battle, the Pokémon will: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Fainting#In_the_core_series) 
        - \>= `GEN_6`: immediately evolve
        - <= `GEN_5`: not evolve

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_WILD_NATURAL_ENEMIES` - Type: True / False
    - When `TRUE` _and_ wild Pokémon that are naturally antagonistic to each other (according to the Pokédex) are partnered in a Double Battle, they will attack each other. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_food#Pok.C3.A9mon_eating_other_Pok.C3.A9mon) 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_AFFECTION_MECHANICS` - Type: True / False
    - When `TRUE`, in Battle Friendship Bonuses are active. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Friendship#Generation_VIII) 

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_TRAINER_CLASS_POKE_BALLS` - Type: Generation Toggle
    - Each Trainer Class will send out their Pokémon: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Breeder_(Trainer_class)) 
        - \>= `GEN_8`: Poke Balls depending on the class. For example, Breeders use Heal Balls, while Fisherman use Dive Balls.
        - = `GEN_7`: Poke Balls depending on the class. For example, Breeders use Friend Balls, while Fisherman use Lure Balls.
        - <= `GEN_6`: regular Poke Balls

---

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

- `B_OBEDIENCE_MECHANICS` - Type: Generation Toggle
    - Obedience restrictions are placed on Pokémon whose OT belongs to the player, based on the level the Pokémon was met. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Obedience#In_the_games) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

## Animation Settings

When these are set to `TRUE`, the new particles or palettes are used for the defined constant.

| Config                            | Constant                       | Old                                                          | New                                                          |
| --------------------------------- | ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `B_NEW_SWORD_PARTICLE`            | `ANIM_TAG_SWORD`               | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_LEECH_SEED_PARTICLE`       | `ANIM_TAG_SEED`                | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_HORN_ATTACK_PARTICLE`      | `ANIM_TAG_HORN_HIT`            | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_LEAF_PARTICLE`             | `ANIM_TAG_LEAF`                | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_EMBER_PARTICLES`           | `ANIM_TAG_SMALL_EMBER`         | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_MEAN_LOOK_PARTICLE`        | `ANIM_TAG_EYE`                 | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_TEETH_PARTICLE`            | `ANIM_TAG_SHARP_TEETH`         | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_HANDS_FEET_PARTICLE`       | `ANIM_TAG_HANDS_AND_FEET`      | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_SPIKES_PARTICLE`           | `ANIM_TAG_SPIKES`              | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_FLY_BUBBLE_PARTICLE`       | `ANIM_TAG_ROUND_SHADOW`        | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_CURSE_NAIL_PARTICLE`       | `ANIM_TAG_NAIL`                | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_BATON_PASS_BALL_PARTICLE`  | `ANIM_TAG_POKEBALL`            | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_MORNING_SUN_STAR_PARTICLE` | `ANIM_TAG_GREEN_STAR`          | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_IMPACT_PALETTE`            | `ANIM_TAG_IMPACT`              | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
| `B_NEW_SURF_PARTICLE_PALETTE`     | `gBattleAnimSpritePal_NewSurf` | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) | ![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png) |
