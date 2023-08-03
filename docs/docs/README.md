[TOC]

# How to see the manual right now

You can [view pages on GitHub directly](https://github.com/PokemonSanFran/pokeemerald-expansion/tree/features.md/docs/docs), *but* it is not an accurate representation of how they'll look in the manual itself. To see the manual in all its glory:

1. Clone this repo: https://github.com/PokemonSanFran/pokeemerald-expansion/tree/features.md
1. Navigate to `docs/` in your terminal and run 
    1. `./script/setup.sh ` or `./script/zsh_setup.sh` if you use zsh
    1. `./script/serve.sh`  or `./script/zsh_serve.sh` if you use zsh
    1. open [http://127.0.0.1:8000/](http://127.0.0.1:8000/) in a browser

# How to help and give feedback

* If you have insight or an opinion, use the [Discord channel](https://discord.com/channels/419213663107416084/1136732669057716355) to weigh in on any of the discussion points listed below.
* If you're willing and able to contribute to any of the TODOs, please let pkmnsnfrn know! ⚠️ **This is the most important piece right now.**

# Discussion Topics

## Top Level Pages

There are some features specifically called out in [Egg's original post](https://www.pokecommunity.com/showthread.php?t=417820), or the [Github README](https://github.com/rh-hideout/pokeemerald-expansion#readme) but I don't think they need top-level pages in the documentation.

| Egg                            | README                                     |
| ------------------------------ | ------------------------------------------ |
| Triple Pokemon Types in-battle | Physical / Special / Status Category Split |
| Dual-type moves                | New Evolution Methods                      |
| Experience on catch            | Updated National Dex                       |
| Faster battle intro            |                                            |

**If there's no strong feedback, I'm not going to add any more new pages.**

---

## Wiki vs Manual

I believe the goal of this documentation is 

1. What are the features of expansion?
2. How does a developer interface with the features of expansion?

I believe that tutorials like "how to add a new type" should be **referenced** in our documentation but are not in scope for inclusion in the documentation.

📖: I think the page should be moved to the manual and deleted from the wiki.

📚: I think the page should stay as is, on the wiki.

❌: I think the page should be deleted.

| Page                                                         | Old  | New  |
| ------------------------------------------------------------ | ---- | ---- |
| [About the Project](https://github.com/rh-hideout/pokeemerald-expansion/wiki/About-the-Project) | 📚    | 📖    |
| [Addenda](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Addenda) | 📚    | ❌    |
| [AI Logic](https://github.com/rh-hideout/pokeemerald-expansion/wiki/AI-Logic) | 📚    | 📚    |
| [Credits](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) | 📚    | 📖    |
| [How to add a new Pokémon species](https://github.com/rh-hideout/pokeemerald-expansion/wiki/How-to-add-a-new-Pok%C3%A9mon-species) | 📚    | 📚    |
| [How to add a new trainer class](https://github.com/rh-hideout/pokeemerald-expansion/wiki/How-to-add-a-new-trainer-class) | 📚    | 📚    |
| [New Battle Script Commands Macros](https://github.com/rh-hideout/pokeemerald-expansion/wiki/New-Battle-Script-Commands-Macros) | 📚    | 📚    |
| [Totem Boosts](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Totem-Boosts) | 📚    | 📖    |

**If there's no strong feedback, I'm going to execute what's listed here.**

---
## Expansion Credits

It's not sustainable to list everybody who has helped with expansion, as nice as that would be. My proposal for that page:

1. Maintainers
2. Alphabetical or Chronological List of Non-Code Contributions / Resources Used
    1. Should be specific about what was provided or taken

3. A link to the [contributors page](https://github.com/rh-hideout/pokeemerald-expansion/graphs/contributors) for all code contributions

**If there's no strong feedback, I'm going to execute what's listed here.**

---

## Videos vs Gif

I want to use videos instead of gifs, as people can pause and rewind them to see the things they actually care about. I'm unsure if this will work unless we can find an external hosting solution since the .mp4 files are going to balloon the size of the repository greatly.

If videos don't work, its not hard to just convert them all to gifs later.

<video width="480" height="320" controls>
  <source src="../img/placeholder.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>

**If there's no strong feedback, I'm going to include the raw videos in the repo itself, unless the repo goes to some ridiculous and unmanageable size, at which case I will reevaluate.**

---

## Feedback Collection

I would like people to give suggestions and improvements to the wording and explanation of certain topics. Originally, I was going to create a series of Google Docs for that people could add comments and suggestions, and then I would port those suggestions to the repo itself.

This is a lot of work for me, and I don't want to do that if its going to go to waste.

### Options

We can do any of the following. Please [vote on Discord](https://discord.com/channels/419213663107416084/1093302480395309099) and discuss there.

A) Go through with the Google Doc plan

B) Let people give feedback via Discord and PRs

C) Skip this step entirely, people can just open PRs later

D) something else

**If there's no strong feedback, I'm going to skip this step entirely.**

# TODO

## Manual Writing

- [ ] [`battleDebugMenu.md`](developer_features/battleDebugMenu.md) is unfinished. I don't know enough about expansion to continue, and [Discord wasn't able to help](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915).
- [ ] [`customBattleScripts.md`](developer_features/customBattleScripts.md) not started. I don't know enough about it to continue.
- [ ] [`tests.md`](developer_features/tests.md) is unfinished. If MGriffin doesn't start this by the time I finish images, I will use [`test_battle.h`](https://github.com/PokemonSanFran/pokeemerald-expansion/blob/features.md/test/test_battle.h) as a starting point.
- [ ] [`improvedAI.md`](game_features/improved_ai.md) is unfinished. I don't know enough about expansion to continue, and [Discord wasn't able to help](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972).
- [ ] Refactor [`credits.md`](credits.md)  based on discussion.

## Recordings

- [ ] Create a list of videos/gifs to record. **⬅️ psf is here**
- [ ] Figure out how to control damage rolls to influence recording outcomes
- [ ] Record videos and embed them into pages.

## Feedback

- [ ] Implement feedback collection method or skip this step, pending discussion.
- [ ] Implement feedback. 

## Final Check

- [ ] I am three months behind upcoming. I need to merge and then document new features between now and then.

## Deployment

- [ ] Open PR against upcoming.
- [ ] Handoff to a maintainer to handle deploying/working build process in CI pipeline.
- [ ] Delete irrelevant wiki pages based on discussion.

# Recording List (in progress)

### Configurations

- [Battle](configurations/battle.md)
    - `B_CRIT_MULTIPLIER`
        - [ ] Critical hit dealing 2x damage

        - [ ] Critical hit dealing 1.5x damage
    - `B_PARALYSIS_SPEED`
        - [ ] Paralysis reducing speed by 50%

        - [ ] Paralysis reducing speed by 75%


    - `B_WHITEOUT_MONEY`
        - [ ] Player whites out and loses half money
        - [ ] Player whites ut and loses variable money
    - `B_EXP_CATCH`
        - Get experience from catch
        - Get no experience from catch
    - `B_TRAINER_EXP_MULTIPLIER`
        - Show EXP from trainer battle versus wild when on
        - Show EXP from trainer battle versus wild when off
    - `B_SPLIT_EXP`
        - send out Pokemon, switch, score KO, see EXP is split by 2
        - send out Pokemon, switch, score KO, see EXP is not split
    - `B_SCALED_EXP`
        - Show EXP is scaled by level diff when on
        - Show EXP is not scaled by level diff
    - `B_BADGE_BOOST`
        - Show badges, look at pokemon stats, has boost
        - Show badges, look at pokemon stats, no boost
    - `B_MAX_LEVEL_EV_GAINS`
        - Score kill at Level 100, look at stats, see stat change because of EV
        - Score kill at Level 100, look at stats, see no stat change
    - `B_RECALCULATE_STATS`
        - Score kill, look at stats, see stat change because of EV
        - Score kill, look at stats, see no stat change, deposit in PC, look at stats, see stat change
    - `B_BURN_DAMAGE`
        - Show burn damage when on
        - Show burn damage when off
    - `B_BURN_FACADE_DMG`
        - Show Burned facade damage when on
        - Show Burned facade damage when off
    - `B_BINDING_DAMAGE`
        - Show binding damage when on
        - Show binding damage when off
    - `B_PAYBACK_SWITCH_BOOST`
        - Use Payback, target switches, show damage
        - Use Payback, target doesn't switch, do not show damage
    - `B_HIDDEN_POWER_DMG`
        - Show damage is based on IVs
        - Show damage is always 60 BP
    - `B_ROUGH_SKIN_DMG`
        - Show rough skin is 1/8
        - Show rough skin is 1/16
    - `B_KNOCK_OFF_DMG`
        - Show increased Knock Off
        - Show not-increased Knock Off
    - `B_SPORT_DMG_REDUCTION`
        - Show 67% damage reduction
        - Show 50% damage reduction
    - `B_EXPLOSION_DEFENSE`
        - Show explosion defense drop does more damage
        - Show explosion no defense drop does less damage
    - `B_PARENTAL_BOND_DMG`
        - Show second hit reduced by 3/4
        - Show second hit reduced by 1/2
    - `B_MULTIPLE_TARGETS_DMG`
        - Show Earthquake hitting multiple targets and doing 1/2
        - Show Earthquake hitting multiple targets and doing 1/4
    - `B_GHOSTS_ESCAPE`
        - Show Mean Look and then Ghost switch
        - Show Mean Look and then Ghost can't switch
    - `B_PARALYZE_ELECTRIC`
        - Stun Spore on electric type works
        - Stun Spores on electric type fails
    - `B_POWDER_GRASS`
        - Powder move on grass type works
        - Powder move on grass type fails
    - `B_STEEL_RESISTANCES`
        - Dark move hitting Steel type, not very effective
        - Dark move hitting steel type, neutral damage
    - `B_PRANKSTER_DARK_TYPES`
        - Opponent is dark, prankster mon uses move, goes first
        - Opponent is dark, prankster mon uses move, does not go first
    - `B_SHEER_COLD_IMMUNITY`
        - Sheer cold hits and kills ice type
        - sheer cold hits and does not impact ice type
    - `B_ROOST_PURE_FLYING`
        - chatot uses roost, check types, is typeless
        - chatot uses roost, check types, is normal
    - `B_TAILWIND_TURNS`
        - use tailwind, check turn counter, see 4
        - use tailwind, check turn counter, see 3
    - `B_SPORT_TURNS`
        - use move, switch out, check turn counter, stays same
        - use move, switch out, check turn counter, is 0
    - `B_MEGA_EVO_TURN_ORDER` 
        - metagross mega evolves, goes first
        - metagross mega evolves, goes second
    - `B_RECALC_TURN_AFTER_ACTIONS`
        - ???
    - `B_FAINT_SWITCH_IN`
        - Double battle, ally faints, switch in right away
        - double battle, all faints, switch in at end of turn
    - `B_UPDATED_MOVE_DATA`
        - Show Tailwind PP at 15
        - Show tailwind PP at 30
    - `B_UPDATED_MOVE_TYPES`
        - Show Moonlight as Fairy
        - Show Moonlight as Normal
    - `B_PHYSICAL_SPECIAL_SPLIT`
        - Show Bite reflected by Mirror Coat
        - Show Bite not reflected bt Mirror Coat
    - `B_RECOIL_IF_MISS_DMG`
        - ???
    - `B_KLUTZ_FLING_INTERACTION`
        - klutz mon can use fling
        - klutz mon can't use fling
    - `B_UPDATED_CONVERSION`
        - porygon knows beam bolt and conversion
            - conversion goes to first move (beam)
            - conversion goes to second move (tbolt)
    - `B_PP_REDUCED_BY_SPITE`
        - mon uses move, oppnent uses Spite
            - PP is -2
            - PP is -4
    - `B_TOXIC_NEVER_MISS`
        - poison pokemon knows toxic with -6 ACC, opponent is +6 EVA, holding a bright powder
            - toxic misses
            - toxic hits
    - `B_MINIMIZE_DMG_ACC`
    - `B_BLIZZARD_HAIL`
    - `B_SHEER_COLD_ACC`
    - `B_FELL_STINGER_STAT_RAISE`
    - `B_KINGS_SHIELD_LOWER_ATK`
    - `B_SPEED_BUFFING_RAPID_SPIN`
    - `B_CHARGE_SPDEF_RAISE`
    - `B_MINIMIZE_EVASION`
    - `B_GROWTH_STAT_RAISE`
    - `B_SOUND_SUBSTITUTE`
    - `B_INCINERATE_GEMS`
    - `B_CAN_SPITE_FAIL`
    - `B_CRASH_IF_TARGET_IMMUNE`
    - `B_MEMENTO_FAIL`
    - `B_GLARE_GHOST`
    - `B_SKILL_SWAP`
    - `B_BRICK_BREAK`
    - `B_WISH_HP_SOURCE`
    - `B_RAMPAGE_CANCELLING`
    - `B_HEAL_BLOCKING`
    - `B_ROOTED_GROUNDING`
    - `B_METRONOME_MOVES`
    - `B_TELEPORT_BEHAVIOR`
    - `B_BEAT_UP`
    - `B_DARK_VOID_FAIL`
    - `B_BURN_HIT_THAW`
    - `B_HEALING_WISH_SWITCH`
    - `B_DEFOG_CLEARS_TERRAIN`
    - `B_STOCKPILE_RAISES_DEFS`
    - `B_EXPANDED_ABILITY_NAMES`
    - `TRUE`
    - `FALSE`
    - `B_ABILITY_WEATHER`
    - `B_GALE_WINGS`
    - `B_STANCE_CHANGE_FAIL`
    - `B_SHADOW_TAG_ESCAPE`
    - `B_MOODY_ACC_EVASION`
    - `B_FLASH_FIRE_FROZEN`
    - `B_SYNCHRONIZE_NATURE`
    - `B_SYNCHRONIZE_TOXIC`
    - `B_UPDATED_INTIMIDATE`
    - `B_OBLIVIOUS_TAUNT`
    - `B_STURDY`
    - `B_PLUS_MINUS_INTERACTION`
    - `B_WEATHER_FORMS`
    - `B_SYMBIOSIS_GEMS`
    - `B_CHECK_IF_CHARGED_UP`
    - `B_ABSORBING_ABILITY_STRING`
    - `B_HP_BERRIES`
    - `B_BERRIES_INSTANT`
    - `B_CONFUSE_BERRIES_HEAL`
    - `B_X_ITEMS_BUFF`
    - `B_MENTAL_HERB`
    - `B_TRAINERS_KNOCK_OFF_ITEMS`
    - `B_SOUL_DEW_BOOST`
    - `B_NET_BALL_MODIFIER`
    - `B_DIVE_BALL_MODIFIER`
    - `B_NEST_BALL_MODIFIER`
    - `B_REPEAT_BALL_MODIFIER`
    - `B_TIMER_BALL_MODIFIER`
    - `B_DUSK_BALL_MODIFIER`
    - `B_QUICK_BALL_MODIFIER`
    - `B_LURE_BALL_MODIFIER`
    - `B_HEAVY_BALL_MODIFIER`
    - `B_DREAM_BALL_MODIFIER`
    - `B_SPORT_BALL_MODIFIER`
    - `B_SERENE_GRACE_BOOST`
    - `B_FLAG_INVERSE_BATTLE`
    - `B_FLAG_FORCE_DOUBLE_WILD`
    - `B_SMART_WILD_AI_FLAG`
    - `B_FLAG_NO_BAG_USE`
    - `B_FLAG_NO_CATCHING`
    - `VAR_TERRAIN`
    - `STATUS_FIELD_GRASSY_TERRAIN`
    - `STATUS_FIELD_MISTY_TERRAIN`
    - `STATUS_FIELD_ELECTRIC_TERRAIN`
    - `STATUS_FIELD_PSYCHIC_TERRAI`
    - `B_VAR_WILD_AI_FLAGS`
    - `B_TERRAIN_BG_CHANGE`
    - `B_THUNDERSTORM_TERRAIN`
    - `B_TERRAIN_TYPE_BOOST`
    - `B_SECRET_POWER_EFFECT`
    - `B_SECRET_POWER_ANIMATION`
    - `B_NATURE_POWER_MOVES`
    - `B_CAMOUFLAGE_TYPES`
    - `B_ABILITY_POP_UP`
    - `TRUE`
    - `FALSE`
    - `B_FAST_INTRO`
    - `TRUE`
    - `FALSE`
    - `B_FAST_HP_DRAIN`
    - `TRUE`
    - `FALSE`
    - `B_SHOW_TARGETS`
    - `B_SHOW_SPLIT_ICON`
    - `B_HIDE_HEALTHBOX_IN_ANIMS`
    - `B_EXPANDED_MOVE_NAMES`
    - `TRUE`
    - `FALSE`
    - `B_WAIT_TIME_MULTIPLIER`
    - `B_SEMI_INVULNERABLE_CATCH`
    - `B_CATCHING_CHARM_BOOST`
    - `B_CRITICAL_CAPTURE`
    - `B_LAST_USED_BALL`
    - `B_LAST_USED_BALL_BUTTON`
    - `R_BUTTON`
    - `R_BUTTON 
    - `DPAD_ANY`
    - `B_DOUBLE_WILD_CHANCE`
    - `B_MULTI_BATTLE_WHITEOUT`
    - `B_EVOLUTION_AFTER_WHITEOUT`
    - `B_WILD_NATURAL_ENEMIES`
    - `B_AFFECTION_MECHANICS`
    - `B_TRAINER_CLASS_POKE_BALLS`
    - `B_OBEDIENCE_MECHANICS`

- [Debug](configurations/debug.md)

- [General](configurations/general.md)

- [Item](configurations/item.md)

- [Overview](configurations/index.md)

- [Overworld](configurations/overworld.md)

- [Pokémon](configurations/pokemon.md)

### Developer Features

- [Battle Debug Menu](developer_features/battleDebugMenu.md)
- [Custom Battle Scripts](developer_features/customBattleScripts.md)
- [Debug Menu](developer_features/debugMenu.md)
- [Sprite Debug Menu](developer_features/spriteDebugMenu.md)
- [Tests](developer_features/tests.md)
- [Trainer Control](developer_features/trainerControl.md)

### Game Features

- [Abilities and Types](game_features/abiltiesandtypes.md)
- [Battle Slide](game_features/battle_slide.md)
- [Expanded Doubles](game_features/expanded_doubles.md)
- [Generation Gimmicks](game_features/generation_gimmicks.md)
- [Improved AI](game_features/improved_ai.md)
- [Items](game_features/items.md)
- [Moves](game_features/moves.md)
- [Pokémon](game_features/pokemon.md)
- [Totem Boosts](game_features/totemBoosts.md)
- [Trainer Messages](game_features/trainer_message.md)
