# Items
## Enabling / Disabling / Configuration

Move related configurations are in [`item.h`](../../include/config/item.h). [[Documentation]](../configurations/item.md)

## Usage and Examples

### Shop

![Gif of the player's Pokemon learning and then using a post Gen 3 move](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

The script files where each individual shop is defined can be edited to add any items, including those from newer generations. For the shop in Rustboro City, the corressponding file is `data/maps/RustboroCity_Mart/scripts.inc`.

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
![Gif of the player's Pokemon learning and then using a post Gen 3 move](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
Items in the overworld can also be edited bt changing the constant associated with specific object. Overworld items are listed in `data/scripts/item_ball_scripts.inc`.

**Usage**:

```diff
PetalburgCity_EventScript_ItemMaxRevive::
+	finditem ITEM_LIFE_ORB
-	finditem ITEM_MAX_REVIVE
	end
```
