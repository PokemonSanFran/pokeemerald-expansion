# Items
## Enabling / Disabling / Configuration

Move related configurations are in [`include/config/item.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/item.h). [[Documentation]](../configurations/item.md)

## Usage and Examples

### Shop

<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

The script files where each individual shop is defined can be edited to add any items, including those from newer generations. For the shop in Rustboro City, the corresponding file is `data/maps/RustboroCity_Mart/scripts.inc`.

**Usage**:

```diff
+RustboroCity_Mart_Pokemart_Expanded:
+    .2byte ITEM_CHOPLE_BERRY
+    .2byte ITEM_WATER_GEM
+    .2byte ITEM_LOPUNNITE
+    .2byte ITEM_N_SOLARIZER
+    .2byte ITEM_ASSAULT_VEST
+    .2byte ITEM_POKE_BALL
```

### Item Ball
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>
Items in the overworld can also be edited by changing the constant associated with specific object. Overworld items are listed in `data/scripts/item_ball_scripts.inc`.

**Usage**:

```diff
PetalburgCity_EventScript_ItemMaxRevive::
+	finditem ITEM_LIFE_ORB
-	finditem ITEM_MAX_REVIVE
	end
```
