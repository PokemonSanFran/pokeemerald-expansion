## Battle Configirations (include/config/battle.h)
### Calculations 

- `B_CRIT_CHANCE` - Type: Generation Toggle
    - Each time the user increases their critical hit stage, the probability of landing of a critical chance increases to 1 over N. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Probability_2)
        - >= `GEN_7`: 24, 8, 2, 1, 1
        - `GEN_6`: 16,8,2,1,1
        - <= `GEN_5`: 16,8,4,3,2

- `B_CRIT_MULTIPLIER` - Type: Generation Toggle
    - Critical hits multiply their damage by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Critical_hit#Damage_2)
        - >= `GEN_6`: 2
        - <= `GEN_5`: 1.5

- `B_PARALYSIS_SPEED` - Type: Generation Toggle
    - Paralysis reduces the afflicted Pokemon's Speed by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - >= `GEN_7`: 50%
        - <= `GEN_6`: 75%

- `B_CONFUSION_SELF_DMG_CHANCE` - Type: Generation Toggle
    - The likelihood of a Confused Pokemon hurting themselves in confusion is: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - >= `GEN_7`: 33.3%
        - <= `GEN_6`: 50%

- `B_MULTI_HIT_CHANCE` - Type: Generation Toggle
    -  The percent chance of a multi-hit move getting multiple hits uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - >= `GEN_5`: Gen 5
        - <= `GEN_4`: Gen 1

- `B_WHITEOUT_MONEY` - Type: Generation Toggle
    - After whiting out, the player's money is reduced by: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
        - >= `GEN_4`: a formula
        - <= `GEN_3`: 50%

### Experience and Stat

- `B_EXP_CATCH` - Type: Generation Toggle
    - When the player catches a Pokemon in battle, the experienced gained by the player Pokemon is:
        - >= `GEN_6`: the same as knocking out said Pokemon.
        - <= `GEN_5`: zero.

- `B_TRAINER_EXP_MULTIPLIER` - Type: Generation Toggle
    - The experience gained from trainer battles versus wild battles is multiplied by:
        - >= `GEN_7`: 1
        - <= `GEN_6`: 1.5

- `B_SPLIT_EXP` - Type: Generation Toggle
    - Pokemon that participated in battle but did not deliever the knockout will recieve the total experience from the fight multiplied by:
        - >= `GEN_6`: 1
        - <= `GEN_5`: 1/N, where N is the number of Pokemon that experience is being split with.

- `B_SCALED_EXP` - Type: Generation Toggle
    - Experience gained in battle is weighed by the difference in Level between the Pokemon that was knocked out and the Pokemon that is recieving the experience.
        - >= `GEN_7`: True
        - = `GEN_6`: False
        - = `GEN_5`: True
        - <= `GEN_4`: False

- `B_BADGE_BOOST` - Type: Generation Toggle
    - Recieving Gym Badges boost the stats of a player's Pokemon.
        - >= `GEN_4`: False
        - <= `GEN_3`: True

- `B_MAX_LEVEL_EV_GAINS` - Type: Generation Toggle
    - When a Pokemon reaches Level 100, the ability for a Pokemon to recieve Effort Values:
        - >= `GEN_5`: functions as normal.
        - <= `GEN_4`: is removed.

- `B_RECALCULATE_STATS` - Type: Generation Toggle
    - The stats for each Pokemon who participate in battle are recalculated: 
        - >= `GEN_5`: at the end of each battle
        - <= `GEN_4`: when the Pokemon is placed in a PC box.

### Damage 

- `B_BURN_DAMAGE` - Type: Generation Toggle
    - In between turns, Burned Pokemon will recieve damage equal to N of their total HP.
        - >= `GEN_7`: 1/16th
        - <= `GEN_6`: 1/8th

- `B_BURN_FACADE_DMG` - Type: Generation Toggle
    - A Burned Pokemon using the move Facade will have their damage from physical attacks reduced by
        - >= `GEN_6`: 0%
        - <= `GEN_5`: 50%

- `B_BINDING_DAMAGE` - Type: Generation Toggle
    - In between turns, Pokemon recieving binding damage will recieve damage equal to N of their total HP.
        - >= `GEN_6`: 1/8 (1/6 with Binding Band)
        - <= `GEN_5`: 1/16 (1/8 with Binding Band)

- `B_PSYWAVE_DMG` - Type: Generation Toggle
    -  The damage for the move Psywave uses the formula from:
        - >= `GEN_5`: Generation 5
        - = `GEN_4`: Generation 3
        - = `GEN_3`: Generation 3

- `B_PAYBACK_SWITCH_BOOST` - Type: Generation Toggle
    - If the damage from the move Payback is to be doubled, and the target switches out, the damage is
        - >= `GEN_5`: no longer doubled
        - <= `GEN_4`: still doubled

- `B_HIDDEN_POWER_DMG` - Type: Generation Toggle
    - Hidden Power's base power is:
        - >= `GEN_6`: always 60
        - <= `GEN_5`: determined by the attacking Pokemon's IVs

- `B_ROUGH_SKIN_DMG` - Type: Generation Toggle
    - The damage dealt to the aattacking Pokemon from Rough Skin or Iron Barbs is equal to N of their total HP.
        - >= `GEN_4`: 1/8
        - <= `GEN_3`: 1/16

- `B_KNOCK_OFF_DMG` - Type: Generation Toggle
    - When the move Knock Off removes an item from the targeted Pokemon, the damage from Knock Off is increased by
        - >= `GEN_6`: 50%
        - <= `GEN_5`: 0%

- `B_SPORT_DMG_REDUCTION` - Type: Generation Toggle
    - Damage from Fire/Electric moves under the effects of Water/Mud Sport are reduced by
        - >= `GEN_5`: 67%
        - <= `GEN_4`: 50%

- `B_EXPLOSION_DEFENSE` - Type: Generation Toggle
    - Pokemon that are targeted by Self-Destruct and Explosion have their Defense reduced by
        - >= `GEN_5`: 0%
        - <= `GEN_4`: 50%

- `B_PARENTAL_BOND_DMG` - Type: Generation Toggle
    - Parental Bond's second hit gets its damage by reducing the initial hit's damage by
        - >= `GEN_7`: 75%
        - <= `GEN_6`: 50%

- `B_MULTIPLE_TARGETS_DMG` - Type: Generation Toggle
    - Damage dealt to multiple targets at once is reduced by:
        - >= `GEN_4`: 75%
        - <= `GEN_3`: 50%

### Type settings
`B_GHOSTS_ESCAPE` - Type: Generation Toggle
    - Abilities like Shadow Tag or moves like Mean Look fail on Ghost-type Pokémon. They can also escape any Wild Battle. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_PARALYZE_ELECTRIC` - Type: Generation Toggle
    - Electric-type Pokémon can't be paralyzed. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_POWDER_GRASS` - Type: Generation Toggle
    - Grass-type Pokémon are immune to powder and spore moves. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_STEEL_RESISTANCES` - Type: Generation Toggle
    - Steel-type Pokémon are resistant to Dark-type and Ghost-type moves. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: False
        - <= `GEN_5`: True

`B_PRANKSTER_DARK_TYPES` - Type: Generation Toggle
    - Prankster-elevated status moves do not affect Dark type Pokémon. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True
        - <= `GEN_6`: False

`B_SHEER_COLD_IMMUNITY` - Type: Generation Toggle
    - Ice-types are immune to Sheer Cold. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True
        - <= `GEN_6`: False

`B_ROOST_PURE_FLYING` - Type: Generation Toggle
    - Roost makes pure Flying-types into Normal-type. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True
        - <= `GEN_6`: False

### Turn settings
`B_BINDING_TURNS` - Type: Generation Toggle
    - Binding moves last for a duration of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 4-5 turns
        - <= `GEN_4`: 2-5 turns

`B_UPROAR_TURNS` - Type: Generation Toggle
    - Uproar lasts for a duration of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 3 turns
        - <= `GEN_4`: 2-5 turns

`B_DISABLE_TURNS` - Type: Generation Toggle
    - The effects of Disable last for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 4 turns
        - = `GEN_4`: 4 - 7 turns
        - = `GEN_3`: 2 - 5 turns

`B_TAILWIND_TURNS` - Type: Generation Toggle
    - The effects of Tailwind last for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 4 turns
        - <= `GEN_4`: 3 turns

`B_SLEEP_TURNS` - Type: Generation Toggle
    - The duration of the Sleep status lasts for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 1 - 3 turns
        - <= `GEN_4`: 2 - 5 turns

`B_TAUNT_TURNS` - Type: Generation Toggle
    - The effects of Taunt lasts for [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 3 turns if the user acts before the target, or 4 turns if the target acted before the user
        - = `GEN_4`: 3 - 5 turns
        - <= `GEN_3`: 2 turns

`B_SPORT_TURNS` - Type: Generation Toggle
    - The effects of Mud / Water Sport last for[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: 5 turns, even if the user switches out
        - <= `GEN_5`: //TODO

`B_MEGA_EVO_TURN_ORDER` - Type: Generation Toggle
    - A Pokemon's turn order is determined by its Speed [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: after Mega Evolution
        - <= `GEN_5`: before Mega Evolution

`B_RECALC_TURN_AFTER_ACTIONS` - Type: Generation Toggle
    - Switching or using a move will affect the current turn's order of actions. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: True
        - <= `GEN_7`: False

`B_FAINT_SWITCH_IN` - Type: Generation Toggle
    - When a Pokemon faints in battle, it is replaced [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: at the end of the current turn.
        - <= `GEN_3`: at the end of the current action.

### Move data settings
`B_UPDATED_MOVE_DATA` - Type: Generation Toggle
    - All moves use the data (Power, Accuracy, PP, stat change, targets, chance of secondary effects) from the generation that is set here. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`B_UPDATED_MOVE_TYPES` - Type: Generation Toggle
    - All moves use the types from the generation that is set here. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

dealdeal  `B_PHYSICAL_SPECIAL_SPLIT` - Type: Generation Toggle
    - Moves are assigned a classification (Physical / Special / Status) [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: On a move by move basis
        - <= `GEN_3`: based on their type

`B_RECOIL_IF_MISS_DMG` - Type: Generation Toggle
    - When the moves High Jump Kick and Jump Kick miss their target, the user takes damage equal to 1/2 of their total HP [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: at all times
        - <= `GEN_4`: if the move would deal damage greater than the target's max HP divided by 2.

`B_KLUTZ_FLING_INTERACTION` - Type: Generation Toggle
    - Pokemon with the Ability Klutz cannot use Fling. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: True
        - <= `GEN_4`: False

`B_UPDATED_CONVERSION` - Type: Generation Toggle
    - Conversion changes the user's type to match the type of [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: the user's first move
        - <= `GEN_5`: one of the user's moves, chosen at random.

`B_PP_REDUCED_BY_SPITE` - Type: Generation Toggle
    - The effects of Spite reduces the target's last move's PP by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: 4
        - = `GEN_3`: 2 to 5

### Move accuracy settings
`B_TOXIC_NEVER_MISS` - Type: Generation Toggle
    - If Toxic is used by a Poison-type Pokemon, it will never miss. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_MINIMIZE_DMG_ACC` - Type: Generation Toggle
    - Moves that causes double damage to minimized Pokémon will also skip accuracy checks.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_BLIZZARD_HAIL` - Type: Generation Toggle
    - Blizzard bypasses accuracy checks if it's hailing. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_SHEER_COLD_ACC` - Type: Generation Toggle
    - If the user is an Ice-type, the base chance of Sheer Cold hitting the target is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 20% 
        - <= `GEN_6`: 30%


### Move stat change settings
`B_FELL_STINGER_STAT_RAISE` - Type: Generation Toggle
    - When damage from Fell Stinger causes the target to faint, the user's Attack is raised by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 3 stages
        - <= `GEN_6`: 2 stages

`B_KINGS_SHIELD_LOWER_ATK` - Type: Generation Toggle
    - The effect's of King's Shield reduces the Attack of the attacking Pokemon by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 1 stage
        - <= `GEN_7`: 2 stages

`B_SPEED_BUFFING_RAPID_SPIN` - Type: Generation Toggle
    - Rapid Spin raises the user's Speed by 1 stage. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: True
        - <= `GEN_7`: False

`B_CHARGE_SPDEF_RAISE` - Type: Generation Toggle
    - Charge raises the user's Special Defense by 1 stage. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: True
        - <= `GEN_4`: False

`B_MINIMIZE_EVASION` - Type: Generation Toggle
    - Minimize raises evasion by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 2 stages
        - <= `GEN_4`: 1 stage

`B_GROWTH_STAT_RAISE` - Type: Generation Toggle
    - Growth's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: Growth raises Attack and Special Attack by one stage. In sunlight, these effects are doubled.
        - <= `GEN_4`: Growth raises Special Attack by one stage. In sunlight, these are not amplified.


### Other move settings
`B_SOUND_SUBSTITUTE` - Type: Generation Toggle
    - Sound moves bypass Substitute. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_INCINERATE_GEMS` - Type: Generation Toggle
    - Incinerate can destroy Gems. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_CAN_SPITE_FAIL` - Type: Generation Toggle
    - Spite fails if the target's last move only has 1 remaining PP. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: False
        - = `GEN_3`: True

`B_CRASH_IF_TARGET_IMMUNE` - Type: Generation Toggle
    - If the target of Jump Kick or High Jump Kick is immune, the target be will dealt damage as if the move missed. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_MEMENTO_FAIL` - Type: Generation Toggle
    - Memento fails if there is no target or if the target is protected or behind substitute. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_GLARE_GHOST` - Type: Generation Toggle
    - Ghost-type Pokemon are immune to Glare. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: False 
        - = `GEN_3`: True 

`B_SKILL_SWAP` - Type: Generation Toggle
    -  After Skill Swap was successful, if an Ability that normall activates on switch in was affected, it immediately activates. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_BRICK_BREAK` - Type: Generation Toggle
    - Brick Break gains new properties between generations.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: If the target is immune to Brick Break, screens are not removed.
        - >= `GEN_4`: An ally's screen can be broken by Brick Break.
        - = `GEN_3`: An ally's screen can not be broken by Brick Break. If the target is immune to Brick Break, screens are removed. 

`B_WISH_HP_SOURCE` - Type: Generation Toggle
    - Wish heals half of the Max HP of the [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: user
        - <= `GEN_4`: target

`B_RAMPAGE_CANCELLING` - Type: Generation Toggle
    - When a Pokemon is rampaging and its attack fails, the rampage will [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: be cancelled, except on the last turn.
        - <= `GEN_4`: not be affected.

`B_HEAL_BLOCKING` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: Heal Block prevents the usage of HP-draining moves.
        - >= `GEN_5`: Heal Block prevents healing from Black Sludge, Leftovers, and Shell Bell. Heal Block prevents the consumption of HP-restoring Berries or Berry Juice.
        - <= `GEN_4`: Heal Block allows the usage of HP-draining moves. Heal Block allows the consumption of HP-restoring Berries or Berry Juice.
                                              
`B_ROOTED_GROUNDING` - Type: Generation Toggle
    - Ingrain causes the affected Pokémon to become grounded. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_METRONOME_MOVES` - Type: Generation Toggle
    - Metronome will randomly choose from the generation that is defined here, and every generation prior to it. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`B_TELEPORT_BEHAVIOR` - Type: Generation Toggle
    - Teleport allows the user to swap out with another party member. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True
        - <= `GEN_6`: False

`B_BEAT_UP` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`:  Beat Up uses its Gen 5 formula to calculate damage. Beat Up deals Dark-Type damage. Beat Up does not announce each member of the user's party.
        - <= `GEN_4`: Beat Up uses its Gen 2 formula to calculate damage. Beat Up deals typeless damage. Beat Up announce each member of the user's party.

`B_DARK_VOID_FAIL` - Type: Generation Toggle
    - When a Pokemon other than Darkrai uses the move Dark Void, the move will fail. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True 
        - <= `GEN_6`: False

`B_BURN_HIT_THAW` - Type: Generation Toggle
    - When a non-Fire type damaging move with a chance to cause Burn hits a Frozen target, there is a chance the target will be defrosted. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_HEALING_WISH_SWITCH` - Type: Generation Toggle
    - Heal Block's mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: Healing Wish's effect will be stored until a statused or hurt ally is sent out.
        - <= `GEN_5`: The Pokemon recieving the Healing Wish is sent out at the end of the turn.
        - <= `GEN_4`: The Pokemon recieving the Healing Wish will be immedatiately sent out, and the effect will instantly activate. 
                                              
`B_DEFOG_CLEARS_TERRAIN` - Type: Generation Toggle
    - Defog clears active Terrain. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: True
        - <= `GEN_7`: False

`B_STOCKPILE_RAISES_DEFS` - Type: Generation Toggle
    - Stockpile raises Defense and Sp.Defense stats, which are negated once Spit Up or Swallow is used. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False


### Ability settings
- `B_EXPANDED_ABILITY_NAMES` - Type: True / False
    - Ability names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12
      
`B_ABILITY_WEATHER` - Type: Generation Toggle
    - Sand Stream, Snow Warning, Sunny Day, and Rain Dance summon their respective weather for N turns. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: 5
        - <= `GEN_5`: ∞

`B_GALE_WINGS` - Type: Generation Toggle
    - Gale Wings activates when the user's HP is at N. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 100
        - <= `GEN_6`: Any

`B_STANCE_CHANGE_FAIL` - Type: Generation Toggle
    - Stance Change fails if the Pokémon is unable to use a move because of confusion, paralysis, etc.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: True
        - <= `GEN_6`: False

`B_SHADOW_TAG_ESCAPE` - Type: Generation Toggle
    - When both sides of a battle are affected by Shadow Tag, both sides are able to switch.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_MOODY_ACC_EVASION` - Type: Generation Toggle
    - Moody can modify evasion or accuracy. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: False
        - <= `GEN_7`: True

`B_FLASH_FIRE_FROZEN` - Type: Generation Toggle
    - Flash Fire triggers when user is frozen. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: True
        - <= `GEN_4`: False

`B_SYNCHRONIZE_NATURE` - Type: Generation Toggle
    - When the first Pokemon in the party has Synchronize, the odds that wild Pokemon will have a Nature that matches the first Pokemon are [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 100%
        - <= `GEN_7`: 50%

`B_SYNCHRONIZE_TOXIC` - Type: Generation Toggle
    -  When a Pokemon with Synchronize is badly poisoned, Synchronize will inflict the opponent with [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: the badly poisoned status
        - <= `GEN_4`: poisoned status

`B_UPDATED_INTIMIDATE` - Type: Generation Toggle
    - Intimidate activates Rattled, and is blocked by Inner Focus, Scrappy, Own Tempo, and Oblivious. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: True
        - <= `GEN_7`: False

`B_OBLIVIOUS_TAUNT` - Type: Generation Toggle
    - Oblivious blocks the effect of Taunt. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: True
        - <= `GEN_5`: False

`B_STURDY` - Type: Generation Toggle
    - If a Pokemon has Sturdy and has full HP and is hit by a non one-hit knockout move that would knock it out [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`: Sturdy will leave it with 1 HP.
        - >= `GEN_`: Sturdy will not activate.

`B_PLUS_MINUS_INTERACTION` - Type: Generation Toggle
    - Plus and Minus can be activated by an ally having [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: either ability 
        - <= `GEN_4`: the opposing ability 

`B_WEATHER_FORMS` - Type: Generation Toggle
    - When a Pokemon has Flower Gift or Forecast, they can only transform when they have those abilities, and when those abilities are lost or disabled, those Pokemon revert into their base form. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: True
        - <= `GEN_4`: False

`B_SYMBIOSIS_GEMS` - Type: Generation Toggle
    - After a Pokemon consumes a Gem, an item from an ally with Symbiosis occurs [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: after the attack
        - <= `GEN_6`: before the attack

`B_CHECK_IF_CHARGED_UP` - Type: True / False
    - Abilities that "Charge" the user will not activate if the user is already Charged. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: True
        - `FALSE`: False
      
`B_ABSORBING_ABILITY_STRING` - Type: Generation Toggle
    - The message that dislays when abilities absorb moves of a certain type is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: generic across all stat increases and decreases
        - <= `GEN_4`: specfic for each increase and decrease


### Item settings
`B_HP_BERRIES` - Type: Generation Toggle
    - Berries which restore HP activate [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: immediately after HP drops to less than 51%
        - <= `GEN_3`: the end of the turn when the holder's HP drops to less than 51%

`B_BERRIES_INSTANT` - Type: Generation Toggle
    - Berries that Pokemon are eligible to consume will be consumed [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`: as soon as the Pokemon switches in
        - <= `GEN_`: at the turn or move end

`B_CONFUSE_BERRIES_HEAL` - Type: Generation Toggle
    - Confusion berries mechanics change between generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: Confusion berries restore 1/3 of the user's maximum HP and activates when the user's HP drops below 26%.
        - = `GEN_7`: Confusion berries restore 50% of the user's maximum HP and activates when the user's HP drops below 26%.
        - <= `GEN_6`: Confusion berries restore 12.5% of the user's maximum HP and activates when the user's HP drops below 51%.

`B_X_ITEMS_BUFF` - Type: Generation Toggle
    - X Items raise its respective stat by N stages. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 2
        - <= `GEN_6`: 1

`B_MENTAL_HERB` - Type: Generation Toggle
    - Mental Herb cures Infatuation and [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: Taunt, Encore, Torment, Heal Block, and Disable
        - <= `GEN_4`: nothing else

`B_TRAINERS_KNOCK_OFF_ITEMS` - Type: True / False
    - If TRUE, trainers can steal/swap your items (non-berries are restored after battle). In vanilla games  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`:
        - `FALSE`:
// TODO what does this do when false
      
`B_SOUL_DEW_BOOST` - Type: Generation Toggle
    - Soul Dew boosts Latios and Latias' [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: Psychic and Dragon-type moves
        - <= `GEN_6`: Special Attack and Special Defense 

`B_NET_BALL_MODIFIER` - Type: Generation Toggle
    - Net Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 5x
        - <= `GEN_6`: 3x

`B_DIVE_BALL_MODIFIER` - Type: Generation Toggle
    - Dive Ball's catch multiplier is applied when the player is diving, [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: surfing or fishing
        - = `GEN_3`: and nothing else

`B_NEST_BALL_MODIFIER` - Type: Generation Toggle
    - Nest Ball's formula uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - <= `GEN_4`: Generation 3

`B_REPEAT_BALL_MODIFIER` - Type: Generation Toggle
    - Repeat Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 3.5x
        - <= `GEN_6`: 3x

`B_TIMER_BALL_MODIFIER` - Type: Generation Toggle
    - Every turn, Timer Ball's catch multiplier increases by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 0.3
        - <= `GEN_4`: 0.1

`B_DUSK_BALL_MODIFIER` - Type: Generation Toggle
    - Dusk Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 3x
        - <= `GEN_6`: 3.5x

`B_QUICK_BALL_MODIFIER` - Type: Generation Toggle
    - Quick Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: 5x
        - <= `GEN_4`: 4x

`B_LURE_BALL_MODIFIER` - Type: Generation Toggle
    - Lure Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: 5x
        - <= `GEN_6`: 3x

`B_HEAVY_BALL_MODIFIER` - Type: Generation Toggle
    - Heavy Ball's formula uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: Generation 7
        - >= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

`B_DREAM_BALL_MODIFIER` - Type: Generation Toggle
    - Dream Ball's catch multiplier when the target is asleep or has the ability Comatose is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 4x
        - <= `GEN_7`: 1x

`B_SPORT_BALL_MODIFIER` - Type: Generation Toggle
    - Sport Ball's catch multiplier is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 1x
        - <= `GEN_7`: 1.5x

`B_SERENE_GRACE_BOOST` - Type: Generation Toggle
    - Serene Grace boosts the flinch chance of King's Rock and Razor Fang. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: True
        - <= `GEN_4`: False


### Flag settings
- `B_FLAG_INVERSE_BATTLE` - Type: Var / Flag
    -  When this flag is set, the type effectiveness interactions are reversed. For example, Fire becomes super effective against water. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
`B_FLAG_FORCE_DOUBLE_WILD` - Type: Var / Flag
    - When this flag is set, all land and surfing wild battles will be double battles.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
    
`B_SMART_WILD_AI_FLAG` - Type: Var / Flag
    - When this flag is set, wild Pokemon will use the AI behavior defined by `B_VAR_WILD_AI_FLAGS`. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
`B_FLAG_NO_BAG_USE` - Type: Var / Flag
    - When this flag is set, the ability to use the bag in battle is disabled.  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
   
`B_FLAG_NO_CATCHING` - Type: Var / Flag
    - When this flag is set, the ability to throw Pokeballs is disabled. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)    

### Var Settings
- `VAR_TERRAIN` - Type: Var / Flag
    - When this var is set, the Terrain is automatically set for the duration at the beginning of the next battle. This behavior persists until the variable is set to 0. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Terrain)

        - `STATUS_FIELD_GRASSY_TERRAIN`: Grassy Terrain
        - `STATUS_FIELD_MISTY_TERRAIN`: Misty Terrain
        - `STATUS_FIELD_ELECTRIC_TERRAIN`: Electric Terrain
        - `STATUS_FIELD_PSYCHIC_TERRAI`: Psychic Terrain

`B_VAR_WILD_AI_FLAGS` - Type: Var / Flag
    - When this var is greater than 0 or less than 15, this var controls the behavior of wild Pokemon when `B_SMART_WILD_AI_FLAG` is set. The behaviors are defined in `sBattleAiFuncTable`. For each behavior in the table's default state, Wild Pokemon will:
        - = `0`: `AI_FLAG_CHECK_BAD_MOVE`:  describe AI logic here
        - = `1`: `AI_FLAG_TRY_TO_FAINT`:  describe AI logic here 
        - = `2`: `AI_FLAG_CHECK_VIABILITY`:  describe AI logic here 
        - = `3`: `AI_FLAG_SETUP_FIRST_TURN`:  describe AI logic here 
        - = `4`: `AI_FLAG_RISKY`:  describe AI logic here 
        - = `5`: `AI_FLAG_PREFER_STRONGEST_MOVE`:  describe AI logic here 
        - = `6`: `AI_FLAG_PREFER_BATON_PASS`:  describe AI logic here 
        - = `7`: `AI_FLAG_DOUBLE_BATTLE`:  describe AI logic here 
        - = `8`: `AI_FLAG_HP_AWARE`:  describe AI logic here 
        - = `9`: `AI_FLAG_NEGATE_UNAWARE`:  describe AI logic here 
        - = `10`: `AI_FLAG_WILL_SUICIDE`:  describe AI logic here 
        - = `11`: `AI_FLAG_HELP_PARTNER`:  describe AI logic here
        - >= `15`: This will behave as if the var is set to 0.
// TODO how the fuck does this work

### Terrain settings
`B_TERRAIN_BG_CHANGE` - Type: True / False
    - If set to TRUE, terrain moves permanently change the default battle background until the effect fades. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`:
        - `FALSE`:
      
`B_THUNDERSTORM_TERRAIN` - Type: True / False
    - When the overworld's weather is set to `WEATHER_RAIN_THUNDERSTORM`,  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: Electric Terrain will be permanently set when a battle begins.
        - `FALSE`: Terrain is not set set when a battle begins.
      
`B_TERRAIN_TYPE_BOOST` - Type: Generation Toggle
    - Terrain boosts the damage of their correspodning moves by [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 30%
        - <= `GEN_7`: 50%

`B_SECRET_POWER_EFFECT` - Type: Generation Toggle
    -  The effects for Secret Power uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

`B_SECRET_POWER_ANIMATION` - Type: Generation Toggle
    - The animation for Secret Power uses the formula from: [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - >= `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

`B_NATURE_POWER_MOVES` - Type: Generation Toggle
    - The move called by Nature Power uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: Generation 7
        - = `GEN_6`: Generation 6
        - = `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3

`B_CAMOUFLAGE_TYPES` - Type: Generation Toggle
    - The type assigned by the move Camouflage uses the formula from [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_5`: Generation 5
        - = `GEN_4`: Generation 4
        - = `GEN_3`: Generation 3


### Interface settings
`B_ABILITY_POP_UP` - Type: True / False
    - When Abilities are activated, their names are displayed in [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: a battle slide
        - `FALSE`: the standard message box
 
`B_FAST_INTRO` - Type: True / False
    - Battle intro text prints [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: as Pokemon animations are playing
        - `FALSE`: after Pokemon animations have finished
 
`B_FAST_HP_DRAIN` - Type: True / False
    - The speed at which HP drains from the HP Bar is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: variable, based on the max HP of the Pokemon 
        - `FALSE`: constant 
 
`B_SHOW_TARGETS` - Type: True / False
    - When a move has multiple targets, they will all be shown when the cursor is hovering over said move in the fight menu. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: True
        - `FALSE`: False
 
`B_SHOW_SPLIT_ICON` - Type: True / False
    - An icon on the Move's summary to indicate the move's classification is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: shown
        - `FALSE`: not shown
 
`B_HIDE_HEALTHBOX_IN_ANIMS` - Type: True / False
    - During move animations, health boxes are [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: shown
        - `FALSE`: not shown
 
`B_EXPANDED_MOVE_NAMES` - Type: True / False
    - Move names are N characters long.
        - `TRUE`: 16
        - `FALSE`: 12

`B_WAIT_TIME_MULTIPLIER` - Type: Set Value
    - This value is the base number of frames for pauses within battles - lower values will result in faster battles. Long, Medium, and Short pauses multiply this value by 4, 3 and 2 respectively. The default value in `pokeemerald` is 16. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

### Catching settings
`B_SEMI_INVULNERABLE_CATCH` - Type: Generation Toggle
    - Pokemon that are in a semi-invulnerale state cannot be targeted for Pokeball capture. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - = `GEN_3`: False

`B_CATCHING_CHARM_BOOST` - Type: Set Value
    - When the player has the Catching Charm, this value increses the odds of a Critical Capture by N%. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`B_CRITICAL_CAPTURE` - Type: True / False
    - Critical Capture is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: enabled
        - `FALSE`: disabled
      
`B_LAST_USED_BALL` - Type: True / False
    - "Last Used Ball" is [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: enabled
        - `FALSE`: disabled
      
`B_LAST_USED_BALL_BUTTON` - Type: Set Value
    - When `B_LAST_USED_BALL` is `TRUE`, this button (or combination of buttons) will trigger throwing the last used ball. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/)
    - Some examples include:
        - `R_BUTTON`
        - `R_BUTTON + A_BUTTON`
        - `DPAD_ANY`

### Other settings
`B_DOUBLE_WILD_CHANCE` - Type: Set Value
    - % chance of encountering two Pokémon in a Wild Encounter. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - Options:

`B_MULTI_BATTLE_WHITEOUT` - Type: Generation Toggle
    - In Gen4+, multi battles end when the Player and also their Partner don't have any more Pokémon to fight. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`:
        - <= `GEN_`:

`B_EVOLUTION_AFTER_WHITEOUT` - Type: Generation Toggle
    - In Gen6+, Pokemon that qualify for evolution after battle will evolve even if the player loses. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`:
        - <= `GEN_`:

`B_WILD_NATURAL_ENEMIES` - Type: True / False
    - If set to TRUE, certain wild mon species will attack other species when partnered in double wild battles ( [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`:
        - `FALSE`:
      
`B_AFFECTION_MECHANICS` - Type: True / False
    - In Gen6+, there's a stat called affection that can trigger different effects in battle. From LGPE onwards,  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`:
        - `FALSE`:
     
`B_TRAINER_CLASS_POKE_BALLS` - Type: Generation Toggle
    - In Gen7+, trainers will use certain types of Poké Balls depending on their trainer class. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`:
        - <= `GEN_`:

`B_OBEDIENCE_MECHANICS` - Type: Generation Toggle
    - In PLA+ (here Gen8+), obedience restrictions also apply to non-outsider Pokémon, albeit based on their level  [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_`:
        - <= `GEN_`:


### Animation Settings
When these are set to TRUE, the new particles or palettes are used for the defined constant.

|Config|Constant|Old|New|
|---|---|---|---|
|`B_NEW_SWORD_PARTICLE`|`ANIM_TAG_SWORD`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_LEECH_SEED_PARTICLE`|`ANIM_TAG_SEED`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_HORN_ATTACK_PARTICLE`|`ANIM_TAG_HORN_HIT`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_LEAF_PARTICLE`|`ANIM_TAG_LEAF`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_EMBER_PARTICLES`|`ANIM_TAG_SMALL_EMBER`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_MEAN_LOOK_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_TEETH_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_HANDS_FEET_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_SPIKES_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_FLY_BUBBLE_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_CURSE_NAIL_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_BATON_PASS_BALL_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_MORNING_SUN_STAR_PARTICLE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_IMPACT_PALETTE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
|`B_NEW_SURF_PARTICLE_PALETTE`|`ANIM_TAG`|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|![](https://archives.bulbagarden.net/media/upload/2/2f/Charge_III.png)|
