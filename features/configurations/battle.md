## Battle Configuration (include/config/battle.h)
### Calculations 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CRIT_CHANCE` - Type: Generation Toggle
    - Each time the user increases their critical hit stage, the probability of landing of a critical chance increases to 1 over N. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Probability_2)
        - >= `GEN_7`: 24, 8, 2, 1, 1
        - `GEN_6`: 16,8,2,1,1
        - <= `GEN_5`: 16,8,4,3,2

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CRIT_MULTIPLIER` - Type: Generation Toggle
    - Critical hits multiply their damage by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Damage_2)
        - \>= `GEN_6`: 2
        - <= `GEN_5`: 1.5

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PARALYSIS_SPEED` - Type: Generation Toggle
    - Paralysis reduces the afflicted Pokemon's Speed by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - \>= `GEN_7`: 50%
        - <= `GEN_6`: 75%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CONFUSION_SELF_DMG_CHANCE` - Type: Generation Toggle
    - The likelihood of a Confused Pokemon hurting themselves in confusion is: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - \>= `GEN_7`: 33.3%
        - <= `GEN_6`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MULTI_HIT_CHANCE` - Type: Generation Toggle
    -  The percent chance of a multi-hit move getting multiple hits uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - \>= `GEN_5`: Gen 5
        - <= `GEN_4`: Gen 1

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_WHITEOUT_MONEY` - Type: Generation Toggle
    - After whiting out, the player's money is reduced by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - \>= `GEN_4`: a formula
        - <= `GEN_3`: 50%

### Experience and Stat

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_EXP_CATCH` - Type: Generation Toggle
    - When the player catches a Pokemon in battle, the experienced gained by the player Pokemon is:
        - \>= `GEN_6`: the same as knocking out said Pokemon.
        - <= `GEN_5`: zero.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TRAINER_EXP_MULTIPLIER` - Type: Generation Toggle
    - The experience gained from trainer battles versus wild battles is multiplied by:
        - \>= `GEN_7`: 1
        - <= `GEN_6`: 1.5

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SPLIT_EXP` - Type: Generation Toggle
    - Pokemon that participated in battle but did not deliever the knockout will recieve the total experience from the fight multiplied by:
        - \>= `GEN_6`: 1
        - <= `GEN_5`: 1/N, where N is the number of Pokemon that experience is being split with.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SCALED_EXP` - Type: Generation Toggle
    - Experience gained in battle is weighed by the difference in Level between the Pokemon that was knocked out and the Pokemon that is recieving the experience.
        - \>= `GEN_7`: True
        - = `GEN_6`: False
        - = `GEN_5`: True
        - <= `GEN_4`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BADGE_BOOST` - Type: Generation Toggle
    - Recieving Gym Badges boost the stats of a player's Pokemon.
        - \>= `GEN_4`: False
        - <= `GEN_3`: True

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MAX_LEVEL_EV_GAINS` - Type: Generation Toggle
    - When a Pokemon reaches Level 100, the ability for a Pokemon to recieve Effort Values:
        - \>= `GEN_5`: functions as normal.
        - <= `GEN_4`: is removed.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_RECALCULATE_STATS` - Type: Generation Toggle
    - The stats for each Pokemon who participate in battle are recalculated: 
        - \>= `GEN_5`: at the end of each battle
        - <= `GEN_4`: when the Pokemon is placed in a PC box.

### Damage 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BURN_DAMAGE` - Type: Generation Toggle
    - In between turns, Burned Pokemon will recieve damage equal to N of their total HP.
        - \>= `GEN_7`: 1/16th
        - <= `GEN_6`: 1/8th

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BURN_FACADE_DMG` - Type: Generation Toggle
    - A Burned Pokemon using the move Facade will have their damage from physical attacks reduced by
        - \>= `GEN_6`: 0%
        - <= `GEN_5`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BINDING_DAMAGE` - Type: Generation Toggle
    - In between turns, Pokemon recieving binding damage will recieve damage equal to N of their total HP.
        - \>= `GEN_6`: 1/8 (1/6 with Binding Band)
        - <= `GEN_5`: 1/16 (1/8 with Binding Band)

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PSYWAVE_DMG` - Type: Generation Toggle
    -  The damage for the move Psywave uses the formula from:
        - \>= `GEN_5`: Generation 5
        - = `GEN_4`: Generation 3
        - = `GEN_3`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PAYBACK_SWITCH_BOOST` - Type: Generation Toggle
    - If the damage from the move Payback is to be doubled, and the target switches out, the damage is
        - \>= `GEN_5`: no longer doubled
        - <= `GEN_4`: still doubled

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HIDDEN_POWER_DMG` - Type: Generation Toggle
    - Hidden Power's base power is:
        - \>= `GEN_6`: always 60
        - <= `GEN_5`: determined by the attacking Pokemon's IVs

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ROUGH_SKIN_DMG` - Type: Generation Toggle
    - The damage dealt to the aattacking Pokemon from Rough Skin or Iron Barbs is equal to N of their total HP.
        - \>= `GEN_4`: 1/8
        - <= `GEN_3`: 1/16

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_KNOCK_OFF_DMG` - Type: Generation Toggle
    - When the move Knock Off removes an item from the targeted Pokemon, the damage from Knock Off is increased by
        - \>= `GEN_6`: 50%
        - <= `GEN_5`: 0%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SPORT_DMG_REDUCTION` - Type: Generation Toggle
    - Damage from Fire/Electric moves under the effects of Water/Mud Sport are reduced by
        - \>= `GEN_5`: 67%
        - <= `GEN_4`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_EXPLOSION_DEFENSE` - Type: Generation Toggle
    - Pokemon that are targeted by Self-Destruct and Explosion have their Defense reduced by
        - \>= `GEN_5`: 0%
        - <= `GEN_4`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PARENTAL_BOND_DMG` - Type: Generation Toggle
    - Parental Bond's second hit gets its damage by reducing the initial hit's damage by
        - \>= `GEN_7`: 75%
        - <= `GEN_6`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MULTIPLE_TARGETS_DMG` - Type: Generation Toggle
    - Damage dealt to multiple targets at once is reduced by:
        - \>= `GEN_4`: 75%
        - <= `GEN_3`: 50%

### Type settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_GHOSTS_ESCAPE` - Type: Generation Toggle
    - Abilities like Shadow Tag or moves like Mean Look fail on Ghost-type Pokémon. They can also escape any Wild Battle. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PARALYZE_ELECTRIC` - Type: Generation Toggle
    - Electric-type Pokémon can't be paralyzed. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_POWDER_GRASS` - Type: Generation Toggle
    - Grass-type Pokémon are immune to powder and spore moves. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_STEEL_RESISTANCES` - Type: Generation Toggle
    - Steel-type Pokémon are resistant to Dark-type and Ghost-type moves. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: False
        - <= `GEN_5`: True

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PRANKSTER_DARK_TYPES` - Type: Generation Toggle
    - Prankster-elevated status moves do not affect Dark type Pokémon. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SHEER_COLD_IMMUNITY` - Type: Generation Toggle
    - Ice-types are immune to Sheer Cold. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ROOST_PURE_FLYING` - Type: Generation Toggle
    - When a pure Flying-type Pokemon uses Roost, their type changes to [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: Normal
        - <= `GEN_6`: Type-less

### Turn settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BINDING_TURNS` - Type: Generation Toggle
    - Binding moves last for a duration of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 4-5 turns
        - <= `GEN_4`: 2-5 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_UPROAR_TURNS` - Type: Generation Toggle
    - Uproar lasts for a duration of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 3 turns
        - <= `GEN_4`: 2-5 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DISABLE_TURNS` - Type: Generation Toggle
    - The effects of Disable last for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 4 turns
        - = `GEN_4`: 4 - 7 turns
        - = `GEN_3`: 2 - 5 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TAILWIND_TURNS` - Type: Generation Toggle
    - The effects of Tailwind last for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 4 turns
        - <= `GEN_4`: 3 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SLEEP_TURNS` - Type: Generation Toggle
    - The duration of the Sleep status lasts for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 1 - 3 turns
        - <= `GEN_4`: 2 - 5 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TAUNT_TURNS` - Type: Generation Toggle
    - The effects of Taunt lasts for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 3 turns if the user acts before the target, or 4 turns if the target acted before the user
        - = `GEN_4`: 3 - 5 turns
        - <= `GEN_3`: 2 turns

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SPORT_TURNS` - Type: Generation Toggle
    - The effects of Mud / Water Sport last for[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: 5 turns, even if the user switches out
        - <= `GEN_5`: as long as the user is on the field

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MEGA_EVO_TURN_ORDER` - Type: Generation Toggle
    - A Pokemon's turn order is determined by its Speed [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: after Mega Evolution
        - <= `GEN_5`: before Mega Evolution

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_RECALC_TURN_AFTER_ACTIONS` - Type: Generation Toggle
    - Switching or using a move will affect the current turn's order of actions. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FAINT_SWITCH_IN` - Type: Generation Toggle
    - When a Pokemon faints in battle, it is replaced [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: at the end of the current turn.
        - <= `GEN_3`: at the end of the current action.

### Move data settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_UPDATED_MOVE_DATA` - Type: Generation Toggle
    - All moves use the data (Power, Accuracy, PP, stat change, targets, chance of secondary effects) from the generation that is set here. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_UPDATED_MOVE_TYPES` - Type: Generation Toggle
    - All moves use the types from the generation that is set here. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PHYSICAL_SPECIAL_SPLIT` - Type: Generation Toggle
    - Moves are assigned a classification (Physical / Special / Status) [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: On a move by move basis
        - <= `GEN_3`: based on their type

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_RECOIL_IF_MISS_DMG` - Type: Generation Toggle
    - When the moves High Jump Kick and Jump Kick miss their target, the user takes damage equal to 1/2 of their total HP [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: at all times
        - <= `GEN_4`: if the move would deal damage greater than the target's max HP divided by 2.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_KLUTZ_FLING_INTERACTION` - Type: Generation Toggle
    - Pokemon with the Ability Klutz cannot use Fling. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_UPDATED_CONVERSION` - Type: Generation Toggle
    - Conversion changes the user's type to match the type of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: the user's first move
        - <= `GEN_5`: one of the user's moves, chosen at random.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PP_REDUCED_BY_SPITE` - Type: Generation Toggle
    - The effects of Spite reduces the target's last move's PP by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: 4
        - = `GEN_3`: 2 to 5

### Move accuracy settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TOXIC_NEVER_MISS` - Type: Generation Toggle
    - If Toxic is used by a Poison-type Pokemon, it will never miss. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MINIMIZE_DMG_ACC` - Type: Generation Toggle
    - Moves that causes double damage to minimized Pokémon will also skip accuracy checks.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BLIZZARD_HAIL` - Type: Generation Toggle
    - Blizzard bypasses accuracy checks if it's hailing. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SHEER_COLD_ACC` - Type: Generation Toggle
    - If the user is an Ice-type, the base chance of Sheer Cold hitting the target is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 20% 
        - <= `GEN_6`: 30%


### Move stat change settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FELL_STINGER_STAT_RAISE` - Type: Generation Toggle
    - When damage from Fell Stinger causes the target to faint, the user's Attack is raised by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 3 stages
        - <= `GEN_6`: 2 stages

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_KINGS_SHIELD_LOWER_ATK` - Type: Generation Toggle
    - The effect's of King's Shield reduces the Attack of the attacking Pokemon by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: 1 stage
        - <= `GEN_7`: 2 stages

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SPEED_BUFFING_RAPID_SPIN` - Type: Generation Toggle
    - Rapid Spin raises the user's Speed by 1 stage. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CHARGE_SPDEF_RAISE` - Type: Generation Toggle
    - Charge raises the user's Special Defense by 1 stage. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MINIMIZE_EVASION` - Type: Generation Toggle
    - Minimize raises evasion by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 2 stages
        - <= `GEN_4`: 1 stage

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_GROWTH_STAT_RAISE` - Type: Generation Toggle
    - Growth's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: Growth raises Attack and Special Attack by one stage. In sunlight, these effects are doubled.
        - <= `GEN_4`: Growth raises Special Attack by one stage. In sunlight, these are not amplified.


### Other move settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SOUND_SUBSTITUTE` - Type: Generation Toggle
    - Sound moves bypass Substitute. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_INCINERATE_GEMS` - Type: Generation Toggle
    - Incinerate can destroy Gems. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CAN_SPITE_FAIL` - Type: Generation Toggle
    - Spite fails if the target's last move only has 1 remaining PP. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: False
        - = `GEN_3`: True

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CRASH_IF_TARGET_IMMUNE` - Type: Generation Toggle
    - If the target of Jump Kick or High Jump Kick is immune, the user will be dealt damage as if the move missed. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MEMENTO_FAIL` - Type: Generation Toggle
    - Memento fails if there is no target or if the target is protected or behind substitute. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_GLARE_GHOST` - Type: Generation Toggle
    - Ghost-type Pokemon are immune to Glare. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: False 
        - = `GEN_3`: True 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SKILL_SWAP` - Type: Generation Toggle
    -  After Skill Swap was successful, if an Ability that normall activates on switch in was affected, it immediately activates. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BRICK_BREAK` - Type: Generation Toggle
    - Brick Break gains new properties between generations.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: If the target is immune to Brick Break, screens are not removed.
        - \>= `GEN_4`: An ally's screen can be broken by Brick Break.
        - = `GEN_3`: An ally's screen can not be broken by Brick Break. If the target is immune to Brick Break, screens are removed. 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_WISH_HP_SOURCE` - Type: Generation Toggle
    - Wish heals half of the Max HP of the [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: user
        - <= `GEN_4`: target

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_RAMPAGE_CANCELLING` - Type: Generation Toggle
    - When a Pokemon is rampaging and its attack fails, the rampage will [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: be cancelled, except on the last turn.
        - <= `GEN_4`: not be affected.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HEAL_BLOCKING` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: Heal Block prevents the usage of HP-draining moves.
        - \>= `GEN_5`: Heal Block prevents healing from Black Sludge, Leftovers, and Shell Bell. Heal Block prevents the consumption of HP-restoring Berries or Berry Juice.
        - <= `GEN_4`: Heal Block allows the usage of HP-draining moves. Heal Block allows the consumption of HP-restoring Berries or Berry Juice.
                                              
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ROOTED_GROUNDING` - Type: Generation Toggle
    - Ingrain causes the affected Pokémon to become grounded. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_METRONOME_MOVES` - Type: Generation Toggle
    - Metronome will randomly choose from the generation that is defined here, and every generation prior to it. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TELEPORT_BEHAVIOR` - Type: Generation Toggle
    - Teleport allows the user to swap out with another party member. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BEAT_UP` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`:  Beat Up uses its Gen 5 formula to calculate damage. Beat Up deals Dark-Type damage. Beat Up does not announce each member of the user's party.
        - <= `GEN_4`: Beat Up uses its Gen 2 formula to calculate damage. Beat Up deals typeless damage. Beat Up announce each member of the user's party.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DARK_VOID_FAIL` - Type: Generation Toggle
    - When a Pokemon other than Darkrai uses the move Dark Void, the move will fail. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: True 
        - <= `GEN_6`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BURN_HIT_THAW` - Type: Generation Toggle
    - When a non-Fire type damaging move with a chance to cause Burn hits a Frozen target, there is a chance the target will be defrosted. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HEALING_WISH_SWITCH` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: Healing Wish's effect will be stored until a statused or hurt ally is sent out.
        - <= `GEN_5`: The Pokemon recieving the Healing Wish is sent out at the end of the turn.
        - <= `GEN_4`: The Pokemon recieving the Healing Wish will be immedatiately sent out, and the effect will instantly activate. 
                                              
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DEFOG_CLEARS_TERRAIN` - Type: Generation Toggle
    - Defog clears active Terrain. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_STOCKPILE_RAISES_DEFS` - Type: Generation Toggle
    - Stockpile raises Defense and Sp.Defense stats, which are negated once Spit Up or Swallow is used. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False


### Ability settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_EXPANDED_ABILITY_NAMES` - Type: True / False
    - Ability names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12
      
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ABILITY_WEATHER` - Type: Generation Toggle
    - Sand Stream, Snow Warning, Drought, and Drizzle summon their respective weather for N turns. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: 5
        - <= `GEN_5`: ∞

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_GALE_WINGS` - Type: Generation Toggle
    - Gale Wings activates when the user's HP is at N. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 100%
        - <= `GEN_6`: Any

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_STANCE_CHANGE_FAIL` - Type: Generation Toggle
    - Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: True
        - <= `GEN_6`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SHADOW_TAG_ESCAPE` - Type: Generation Toggle
    - When both sides of a battle are affected by Shadow Tag, both sides are able to switch. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MOODY_ACC_EVASION` - Type: Generation Toggle
    - Moody can modify evasion and/or accuracy. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: False
        - <= `GEN_7`: True

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FLASH_FIRE_FROZEN` - Type: Generation Toggle
    - Flash Fire triggers when user is frozen. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SYNCHRONIZE_NATURE` - Type: Generation Toggle
    - When the first Pokemon in the party has Synchronize, the odds that wild Pokemon will have a Nature that matches the first Pokemon are [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: 100%
        - <= `GEN_7`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SYNCHRONIZE_TOXIC` - Type: Generation Toggle
    -  When a Pokemon with Synchronize is badly poisoned, Synchronize will inflict the opponent with [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: the badly poisoned status
        - <= `GEN_4`: poisoned status

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_UPDATED_INTIMIDATE` - Type: Generation Toggle
    - Intimidate activates Rattled, and is blocked by Inner Focus, Scrappy, Own Tempo, and Oblivious. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_OBLIVIOUS_TAUNT` - Type: Generation Toggle
    - Oblivious blocks the effect of Taunt. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: True
        - <= `GEN_5`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_STURDY` - Type: Generation Toggle
    - If a Pokemon has Sturdy and has full HP and is hit by a non one-hit knockout move that would knock it out [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_`: Sturdy will leave it with 1 HP.
        - \>= `GEN_`: Sturdy will not activate.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_PLUS_MINUS_INTERACTION` - Type: Generation Toggle
    - Plus and Minus are activated by an ally having [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: Plus or Minus
        - <= `GEN_4`: the opposing ability 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_WEATHER_FORMS` - Type: Generation Toggle
    - When a Pokemon has Flower Gift or Forecast, they can only transform when they have those abilities. When those abilities are lost or disabled, those Pokemon revert into their base form. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SYMBIOSIS_GEMS` - Type: Generation Toggle
    - After a Pokemon consumes a Gem, an item from an ally with Symbiosis is transferred [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: after the attack
        - <= `GEN_6`: before the attack

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CHECK_IF_CHARGED_UP` - Type: True / False
    - When `TRUE`, Abilities that "Charge" the user will not activate if the user is already Charged. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ABSORBING_ABILITY_STRING` - Type: Generation Toggle
    - The message that displays when abilities absorb moves of a certain type is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: generic across all stat increases and decreases
        - <= `GEN_4`: specific for each increase and decrease


### Item settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HP_BERRIES` - Type: Generation Toggle
    - Berries which restore HP activate [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: immediately after HP drops to less than 51%
        - <= `GEN_3`: the end of the turn when the holder's HP drops to less than 51%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_BERRIES_INSTANT` - Type: Generation Toggle
    - Berries that Pokemon are eligible for consumption will be consumed [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_`: as soon as the Pokemon switches in
        - <= `GEN_`: at the turn or move end

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CONFUSE_BERRIES_HEAL` - Type: Generation Toggle
    - Confusion berries mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: Confusion berries restore 1/3 of the user's maximum HP and activates when the user's HP drops below 26%.
        - = `GEN_7`: Confusion berries restore 50% of the user's maximum HP and activates when the user's HP drops below 26%.
        - <= `GEN_6`: Confusion berries restore 12.5% of the user's maximum HP and activates when the user's HP drops below 51%.

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_X_ITEMS_BUFF` - Type: Generation Toggle
    - Battle Items raise their respective stat by N stages. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Battle_item) 
        - \>= `GEN_7`: 2
        - <= `GEN_6`: 1

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MENTAL_HERB` - Type: Generation Toggle
    - Mental Herb cures Infatuation [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: as well as Taunt, Encore, Torment, Heal Block, and Disable
        - <= `GEN_4`: and nothing else

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TRAINERS_KNOCK_OFF_ITEMS` - Type: True / False
    - When `TRUE`, opposing trainers can steal the player's items. Items that are [berries](https://bulbapedia.bulbagarden.net/wiki/Berry) are restored after battle.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
      
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SOUL_DEW_BOOST` - Type: Generation Toggle
    - Soul Dew boosts Latios and Latias' [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: Psychic and Dragon-type moves
        - <= `GEN_6`: Special Attack and Special Defense 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_NET_BALL_MODIFIER` - Type: Generation Toggle
    - Net Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 5x
        - <= `GEN_6`: 3x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DIVE_BALL_MODIFIER` - Type: Generation Toggle
    - Dive Ball's catch multiplier is applied when the player is diving, [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: surfing or fishing
        - = `GEN_3`: and nothing else

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_NEST_BALL_MODIFIER` - Type: Generation Toggle
    - Nest Ball's catch formula uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Nest_Ball#Effect) 
        - \>= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - <= `GEN_4`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_REPEAT_BALL_MODIFIER` - Type: Generation Toggle
    - Repeat Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 3.5x
        - <= `GEN_6`: 3x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TIMER_BALL_MODIFIER` - Type: Generation Toggle
    - Every turn, Timer Ball's catch multiplier increases by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 0.3
        - <= `GEN_4`: 0.1

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DUSK_BALL_MODIFIER` - Type: Generation Toggle
    - Dusk Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 3x
        - <= `GEN_6`: 3.5x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_QUICK_BALL_MODIFIER` - Type: Generation Toggle
    - Quick Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: 5x
        - <= `GEN_4`: 4x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_LURE_BALL_MODIFIER` - Type: Generation Toggle
    - Lure Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: 5x
        - <= `GEN_6`: 3x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HEAVY_BALL_MODIFIER` - Type: Generation Toggle
    - Heavy Ball's formula uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: Generation 7
        - \>= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DREAM_BALL_MODIFIER` - Type: Generation Toggle
    - Dream Ball's catch multiplier when the target is asleep or has the ability Comatose is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: 4x
        - <= `GEN_7`: 1x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SPORT_BALL_MODIFIER` - Type: Generation Toggle
    - Sport Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: 1x
        - <= `GEN_7`: 1.5x

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SERENE_GRACE_BOOST` - Type: Generation Toggle
    - Serene Grace boosts the flinch chance of King's Rock and Razor Fang. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: True
        - <= `GEN_4`: False


### Flag settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FLAG_INVERSE_BATTLE` - Type: Var / Flag
    -  When this flag is set in game, the type effectiveness interactions are reversed. For example, Fire becomes super effective against water. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FLAG_FORCE_DOUBLE_WILD` - Type: Var / Flag
    - When this flag is set in game, all land and surfing wild battles will be double battles.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
    
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SMART_WILD_AI_FLAG` - Type: Var / Flag
    - When this flag is set in game, wild Pokemon will use the AI behavior defined by `B_VAR_WILD_AI_FLAGS`. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FLAG_NO_BAG_USE` - Type: Var / Flag
    - When this flag is set in game, the ability to use the bag in battle is disabled.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FLAG_NO_CATCHING` - Type: Var / Flag
    - When this flag is set in game, the ability to throw Pokeballs is disabled. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)    

### Var Settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `VAR_TERRAIN` - Type: Var / Flag
    - When this var is set in game, the Terrain is automatically set for the duration at the beginning of the next battle. This behavior persists until the variable is set to 0. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Terrain)

        - `STATUS_FIELD_GRASSY_TERRAIN`: Grassy Terrain
        - `STATUS_FIELD_MISTY_TERRAIN`: Misty Terrain
        - `STATUS_FIELD_ELECTRIC_TERRAIN`: Electric Terrain
        - `STATUS_FIELD_PSYCHIC_TERRAI`: Psychic Terrain

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_VAR_WILD_AI_FLAGS` - Type: Var / Flag
    - When this var set in game and is greater than 0 or less than 15, this var controls the behavior of wild Pokemon when `B_SMART_WILD_AI_FLAG` is set. The behaviors are defined in `sBattleAiFuncTable`, and described in [game_features/improved_ai](../game_features/improved_ai). For each behavior in the table's default state, Wild Pokemon will:
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

### Terrain settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TERRAIN_BG_CHANGE` - Type: True / False
    - When `TRUE`, when terrain changes, the battle background changes to match until the change fades. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
      
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_THUNDERSTORM_TERRAIN` - Type: True / False
    - When `TRUE` _and_ the overworld's weather is set to `WEATHER_RAIN_THUNDERSTORM`, Electric Terrain will be permanently set when a battle begins. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
      
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TERRAIN_TYPE_BOOST` - Type: Generation Toggle
    - Terrain boosts the damage of their corresponding moves by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: 30%
        - <= `GEN_7`: 50%

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SECRET_POWER_EFFECT` - Type: Generation Toggle
    -  The effects for Secret Power uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SECRET_POWER_ANIMATION` - Type: Generation Toggle
    - The animation for Secret Power uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - \>= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_NATURE_POWER_MOVES` - Type: Generation Toggle
    - The move called by Nature Power uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CAMOUFLAGE_TYPES` - Type: Generation Toggle
    - The type assigned by the move Camouflage uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3


### Interface settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_ABILITY_POP_UP` - Type: True / False
    - Abilities are announced via [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: a Battle Slide message 
        - `FALSE`: the standard message box
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FAST_INTRO` - Type: True / False
    - Battle intro text prints [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: as Pokemon animations are playing
        - `FALSE`: after Pokemon animations have finished
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_FAST_HP_DRAIN` - Type: True / False
    - The speed at which HP drains from the HP Bar is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: variable, based on the max HP of the Pokemon 
        - `FALSE`: constant 
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SHOW_TARGETS` - Type: True / False
    - When `TRUE` _and_ a move has multiple targets, the targets will all be shown when the cursor is hovering over said move in the move menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SHOW_SPLIT_ICON` - Type: True / False
    - When `TRUE`, an icon on the Move's summary to indicate the move's classification is shown. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_HIDE_HEALTHBOX_IN_ANIMS` - Type: True / False
    - When `TRUE`, health boxes are shown during move animations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
 
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_EXPANDED_MOVE_NAMES` - Type: True / False
    - Move names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_WAIT_TIME_MULTIPLIER` - Type: Set Value
    - This value is the base number of frames for pauses within battles - lower values will result in faster battles. Long, Medium, and Short pauses multiply this value by 4, 3 and 2 respectively. The default value in `pokeemerald` is 16. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

### Catching settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_SEMI_INVULNERABLE_CATCH` - Type: Generation Toggle
    - Pokemon that are in a semi-invulnerale state cannot be targeted for Pokeball capture. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: True
        - = `GEN_3`: False

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CATCHING_CHARM_BOOST` - Type: Set Value
    - When the player has the Catching Charm, this value increses the odds of a Critical Capture by N%. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_CRITICAL_CAPTURE` - Type: True / False
    - When `TRUE`, Critical Capture is enabled. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
      
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_LAST_USED_BALL` - Type: True / False
    - When `TRUE`, "Last Used Ball" is enabled. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_LAST_USED_BALL_BUTTON` - Type: Set Value
    - When `B_LAST_USED_BALL` is `TRUE`, the button (or combination of buttons) set here will trigger throwing the last used ball. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
    - Some examples include:
        - `R_BUTTON`
        - `R_BUTTON + A_BUTTON`
        - `DPAD_ANY`

### Other settings
![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_DOUBLE_WILD_CHANCE` - Type: Set Value
    - When a wild battle is initiated, this value is the N% chance that the battle will be a Double Battle. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_MULTI_BATTLE_WHITEOUT` - Type: Generation Toggle
    - During a Multi Battle, when the player has no Pokemon available to fight, but their partner has Pokemon available to fight, the battle [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_4`: continues until one side has no Pokemon
        - = `GEN_3`: is lost by the player

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_EVOLUTION_AFTER_WHITEOUT` - Type: Generation Toggle
    - When a Pokemon has reached the criteria for evolution during battle, but then the player then loses the battle, the Pokemon will [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_6`: immediately evolve
        - <= `GEN_5`: not evolve

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_WILD_NATURAL_ENEMIES` - Type: True / False
    - When `TRUE` _and_ wild Pokemon that are naturally antagonistic to each other (according to the Pokedex) are partnered in a Double Battle, they will attack each other. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_AFFECTION_MECHANICS` - Type: True / False
    - When `TRUE`, in Battle Friendship Bonuses are active. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_TRAINER_CLASS_POKE_BALLS` - Type: Generation Toggle
    - Each Trainer Class will send out their Pokemon [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: Poke Balls depending on the class. For example, Breeders use Heal Balls, while Fisherman use Dive Balls.
        - = `GEN_7`: Poke Balls depending on the class. For example, Breeders use Friend Balls, while Fisherman use Lure Balls.
        - <= `GEN_6`: regular Poke Balls

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
- `B_OBEDIENCE_MECHANICS` - Type: Generation Toggle
    - Obedience restrictions are placed on Pokemon whose OT belongs to the player, based on the level the Pokemon was met. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - \>= `GEN_8`: True
        - <= `GEN_7`: False


### Animation Settings
When these are set to `TRUE`, the new particles or palettes are used for the defined constant.

|Config|Constant|Old|New|
|---|---|---|---|
|`B_NEW_SWORD_PARTICLE`|`ANIM_TAG_SWORD`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_LEECH_SEED_PARTICLE`|`ANIM_TAG_SEED`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_HORN_ATTACK_PARTICLE`|`ANIM_TAG_HORN_HIT`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_LEAF_PARTICLE`|`ANIM_TAG_LEAF`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_EMBER_PARTICLES`|`ANIM_TAG_SMALL_EMBER`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_MEAN_LOOK_PARTICLE`|`ANIM_TAG_EYE`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_TEETH_PARTICLE`|`ANIM_TAG_SHARP_TEETH`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_HANDS_FEET_PARTICLE`|`ANIM_TAG_HANDS_AND_FEET`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_SPIKES_PARTICLE`|`ANIM_TAG_SPIKES`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_FLY_BUBBLE_PARTICLE`|`ANIM_TAG_ROUND_SHADOW`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_CURSE_NAIL_PARTICLE`|`ANIM_TAG_NAIL`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_BATON_PASS_BALL_PARTICLE`|`ANIM_TAG_POKEBALL`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_MORNING_SUN_STAR_PARTICLE`|`ANIM_TAG_GREEN_STAR`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_IMPACT_PALETTE`|`ANIM_TAG_IMPACT`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_SURF_PARTICLE_PALETTE`|`gBattleAnimSpritePal_NewSurf`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
