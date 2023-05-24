# Instructions

1. Please clone this repo: https://github.com/PokemonSanFran/pokeemerald-expansion/tree/features.md
1. Navigate to `docs/` and run 
    1. `script/setup.sh`
    1. `/script/serve.sh` 
    1. open [http://127.0.0.1:8000/](http://127.0.0.1:8000/) in a browser

1. I'm working through [fileChecklist.md](fileChecklist.md) right now.
    1. As of May 24, that means making a list of videos we'll need for each page.


---

# Top Level Pages

The following features are in [Egg's original post](https://www.pokecommunity.com/showthread.php?t=417820), but I don't think need top level pages in documentation.

* Triple Pokemon Types in-battle
* Dual-type moves
* Experience on catch
* Faster battle intro

The following features are in the [Github README](https://github.com/rh-hideout/pokeemerald-expansion#readme), but I don't think need top level pages in documentation.

* Physical/Special/Status Category Split.
* New evolution methods.
* Updates National Dex incorporating all the new species.

---

# Wiki vs Manual

I believe the goal of this documentation is 

1. What are the features of expansion?
2. How does a developer interface with the features of expansion?

I believe that tutorials like "how to add a new type" should be **referenced** in our documentation but are not in scope for inclusion in the documentation.

📖: I think the page should be moved to the manual and deleted.

📚: I think the page should stay as is.

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

---

# Videos vs Gif

I have opted for use of videos instead of gifs. Videos allow the user to pause and rewind specific parts of each video. I'm not sure how we will handle _hosting_ of this video at this stage, but I think that's a problem we can come to later, and worst case scenario, we can convert everything to a gif.

<video width="480" height="320" controls>
  <source src="https://user-images.githubusercontent.com/77138753/240500859-036fff47-d644-4ce7-9356-a384bd3857a5.mp4" type="video/mp4">
Your browser does not support the video tag.
</video>
