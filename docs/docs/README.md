[TOC]

# How to see the manual right now

You can [view pages on Github directly](https://github.com/PokemonSanFran/pokeemerald-expansion/tree/features.md/docs/docs), *but* it is not an accurate representation of how they'll look in the manual itself. To see the manual in all its glory:

1. Clone this repo: https://github.com/PokemonSanFran/pokeemerald-expansion/tree/features.md
1. Navigate to `docs/` in your terminal and run 
    1. `./script/setup.sh ` or `./script/zsh_setup.sh` if you use zsh
    1. `./script/serve.sh`  or `./script/zsh_serve.sh` if you use zsh
    1. open [http://127.0.0.1:8000/](http://127.0.0.1:8000/) in a browser

# How to help and give feedback

* If you have insight or an opinion, use the [Discord channel](https://discord.com/channels/419213663107416084/1093302480395309099) to weigh in on any of the discussion points listed below.
* If you're willing and able to contribute to any of the TODOs, please let psf#2936 know! ⚠️ **This is the most important piece right now.**

# Discussion Topics

## Top Level Pages

There are some features specifically called out in [Egg's original post](https://www.pokecommunity.com/showthread.php?t=417820), or the [Github README](https://github.com/rh-hideout/pokeemerald-expansion#readme) but I don't think they need top level pages in documentation.

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

I don't think its sustainable to list everybody who has helped with expansion, as nice as that would be. My proposal for that page:

1. Maintainers
2. Alphabetical or Chronological List of Non-Code Contributions / Resources Used
    1. Should be specific about what was provided or taken

3. A link to the [contributors page](https://github.com/rh-hideout/pokeemerald-expansion/graphs/contributors) for all code contributions

**If there's no strong feedback, I'm going to execute what's listed here.**

---

## Videos vs Gif

I would like to use videos instead of gifs, as people can pause and rewind them to see the things they actually care about. I'm unsure if this will work unless we can find an external hosting solution, since the .mp4 files are going to greatly balloon the size of the repository.

If videos don't work, its not hard to just convert them all to gifs later.

<video width="480" height="320" controls>
  <source src="https://user-images.githubusercontent.com/77138753/240500859-036fff47-d644-4ce7-9356-a384bd3857a5.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>
**If there's no strong feedback, I'm going to include the raw videos in the repo itself, unless the repo goes to some ridiculous and unmanagable size, at which case I will reevaluate.**

---

## Feedback Collection

I would like people to give suggestions and improvements to the wording and explanation of certain topics. Originally, I was going to create a series of Google Docs for that people could add comments and suggestions to, and then I would port those suggestions to the repo itself.

This is a lot of work for me, and I don't want to do that if its going to go to waste.

### Options

We can do any of the following. Please [vote on Discord](https://discord.com/channels/419213663107416084/1093302480395309099) and discuss there.

🅰️) Go through with the Google Doc plan
🅱️) Let people give feedback via Discord and PRs
🇨) Skip this step entirely, people can just open PRs later
🇩) something else

**If there's no strong feedback, I'm going to skip this step entirely.**

# TODO

## Manual Writing

- [ ] [`battleDebugMenu.md`](developer_features/battleDebugMenu.md) is unfinished. I don't know enough about expansion to continue, and [Discord wasn't able to help](https://discord.com/channels/419213663107416084/1077168246555430962/1104182927635533915).
- [ ] [`customBattleScripts.md`](developer_features/customBattleScripts.md) not started. I don't know enough about it to continue.
- [ ] [`tests.md`](developer_features/tests.md) is unfinished. If MGriffin doesn't start this by the time I finish images, I will use [`test_battle.h`](https://github.com/PokemonSanFran/pokeemerald-expansion/blob/features.md/test/test_battle.h) as a starting point.
- [ ] [`improvedAI.md`](game_features/improved_ai.md) is unfinished. I don't know enough about expansion to continue, and [Discord wasn't able to help](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972).
- [ ] Refactor [`credits.md`](credits.md)  based on discussion.

## Recordings

- [ ] Create list of videos/gifs to record. **⬅️ psf is here**
- [ ] Record videos and embed into pages.

## Feedback

- [ ] Implement feedback collection method or skip this step, pending discussion.
- [ ] Imeplement feedback. 

## Final Check

- [ ] I am three months behind upcoming. I need to merge and then document new features between now and then.

## Deployment

- [ ] Open PR against upcoming.
- [ ] Hand off to a maintainer to handle deploying / working build process in CI pipeline.
- [ ] Delete irrelevant wiki pages based on dicussion.

# Recording List (in progress)

### Configurations

- [Battle](configurations/battle.md)
    - `B_CRIT_MULTIPLIER`
        - [ ] Critical hit dealing 2x damage
        
        - [ ] Critical hit dealing 1.5x damage
        
    - `B_PARALYSIS_SPEED`
        - [ ] Paralysis reducing speed by 50%
        
        - [ ] Paralysis reducint speed by 75%
    
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
