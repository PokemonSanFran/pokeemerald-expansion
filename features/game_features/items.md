## New Pokémon / Items / Moves / Abilities / Types
<!--
primarina using scald, actvating steam engine

gen 4 - occa berry
gen 5 - scald
gen 6 - fairy type
gen 7 - primarina
gen 8 - steam engine and coalassal
-->
Using `pokeemerald-expansion` gives the developer the ability to use Pokemon, Items, Moves, Abilities and Types from main-series games after `pokeemerald`.

**Usage**: After installation, `pokeemerald-expansion` makes no changes to the core gameplay of `pokeemerald`. Develoeprs wanting to use these new features can do so with ease.

### Items
#### Shop
<img src="" alt="Gif of the player buying from a shop that has one item from each generation after Emerald" height=160px width=240px>
The script files where each individual shop is defined can be edited to add any items, including those from newer generations. For the shop in Rustboro City, the corressponding file is `data/maps/RustboroCity_Mart/scripts.inc`.

**Usage**:
```diff
RustboroCity_Mart_Pokemart_Expanded:
    +.2byte ITEM_CHOPLE_BERRY
    +.2byte ITEM_WATER_GEM
    +2byte ITEM_LOPUNNITE
    +2byte ITEM_N_SOLARIZER
    +2byte ITEM_ASSAULT_VEST
    .2byte ITEM_POKE_BALL
```

#### Item Ball
<img src="" alt="Gif of the player picking up an item ball with a new item inside" height=160px width=240px>
Items in the overworld can also be edited bt changing the constant associated with specific object. Overworld items are listed in `data/scripts/item_ball_scripts.inc`.

**Usage**:

##### 
```diff
PetalburgCity_EventScript_ItemMaxRevive::
    +finditem ITEM_LIFE_ORB
	-finditem ITEM_MAX_REVIVE
	end
```
