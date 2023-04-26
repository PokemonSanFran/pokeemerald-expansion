## Pokemon Configuration (include/config/pokemon.h)

`P_UPDATED_TYPES` - Type: Generation Toggle  
	- Pokemon use the Types assigned to them in the defined generation. This most notably impacts Pokemon that gained a Fairy-type during Generation 6. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`P_UPDATED_STATS` - Type: Generation Toggle  
    - Pokemon use the stats assigned to them in the defined generation.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`P_UPDATED_ABILITIES` - Type: Generation Toggle  
    - Pokemon use the abilities assigned to them in the defined generation.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

`P_UPDATED_EGG_GROUPS` - Type: Generation Toggle  
    - Pokemon use the egg groups assigned to them in the defined generation.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 


//TODO whats the percent chance here?
`P_NIDORAN_M_DITTO_BREED` - Type: Generation Toggle  
    - When Nidoran♂ or Volbeat breed with a Ditto, the offspring can be
        = >= `GEN_5`: Nidoran♀ or Nidoran♂ / Volbeat or Illumise
        = <= `GEN_4`: Nidoran♂ / Volbeat

`P_INCENSE_BREEDING` - Type: Generation Toggle  
	- Cross-generation Baby Pokémon require Incense being held by the parents to be obtained via breeding. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_9`: True
        - <= `GEN_8`: False

`P_EGG_HATCH_LEVEL` - Type: Generation Toggle  
	- Pokemon hatch at Level [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: 1
        - = `GEN_3`: 5

`P_BALL_INHERITING` - Type: Generation Toggle  
    - The mechanics of Pokeball breeding inheirtance have changed over the generations. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_7`: When the mother and father are the same species, Eggs from the Daycare can inheirit the Poke Ball from either parent. If they are different species, the Egg will inheirit the Poke Ball from the mother.
        - = `GEN_6`: Eggs from the Daycare will inheirit the Poke Ball from the mother.
        - <= `GEN_5`: Eggs from the Daycare are placed in Poke Balls.


`P_SHEDINJA_BALL` - Type: Generation Toggle  
    - When Nincada evolves, the resulting Shedinja [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: will use one of the regular Poke Balls in the player's bag. Shedinja will not spawn if there is no spare Poke Ball.
        - <= `GEN_3`: will inheirit the Nincada's Poke Ball.%

`P_KADABRA_EVERSTONE` - Type: Generation Toggle  
	- Kadabra can evolve even when holding an Everstone. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_4`: True
        - <= `GEN_3`: False

`P_HIPPO_GENDER_DIFF_ICONS` - Type: True / False        
	- Hippopotas and Hippowdon female variants will use [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: custom icons
        - `FALSE`: the same icons as the male variants 

`P_SHUCKLE_BERRY_JUICE` - Type: True / False        
    - When `SPECIES_SHUCKLE` is holding an `ITEM_ORAN_BERRY`, after every battle, there is a N chance that the item will turn into `ITEM_BERRY_JUICE`. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - `TRUE`: 1/16
        - `FALSE`: 0%

`P_LEGENDARY_PERFECT_IVS` - Type: Generation Toggle  
    - Ultra Beasts, Legendary, and Mythical Pokemon that are found in the wild or given to the player will be guarenteed to have N perfect IVs. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
        - >= `GEN_8`: 3
        - <= `GEN_7`: 0


`P_FLAG_FORCE_SHINY` - Type: Var / Flag     
    - When this flag is set, Pokemon that are found in the wild or given to the player will be guarenteed to be Shiny. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 
	
`P_FLAG_FORCE_NO_SHINY` - Type: Var / Flag     
    - When this flag is set, Pokemon that are found in the wild or given to the player will be guarenteed to be NOT Shiny. [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/) 

### Enable Pokemon Generations

When a generation is set to `TRUE`, the developer can reference these Pokemon in battles and scripts. Cross regional formes use the original Pokemon's generation, but cross regional evolutions rely on the evolved Pokemon's generation.

#### Example

`P_GEN_7_POKEMON` == `FALSE`
`P_GEN_8_POKEMON` == `FALSE`

Galarian Meowth and Alolan Meowth will be available, but Galarian Meowth will not evolve into Perrserker.

If a developer disables a generation previous to other enabled generations, then the disabled Pokemon will need to be manually commmented out in `include/constants/pokedex.h`.

#### Example

`P_GEN_4_POKEMON` == `FALSE`
`P_GEN_5_POKEMON` == `TRUE`

In this case, the Pokemon from Gen 4 need to be commented out.

```diff
-    NATIONAL_DEX_TURTWIG,
-    NATIONAL_DEX_GROTLE,
-    NATIONAL_DEX_TORTERRA,
-    NATIONAL_DEX_CHIMCHAR,
-    NATIONAL_DEX_MONFERNO,
-    NATIONAL_DEX_INFERNAPE,
-    NATIONAL_DEX_PIPLUP,
-    NATIONAL_DEX_PRINPLUP,
-    NATIONAL_DEX_EMPOLEON,
-    NATIONAL_DEX_STARLY,
+    //NATIONAL_DEX_TURTWIG,
+    //NATIONAL_DEX_GROTLE,
+    //NATIONAL_DEX_TORTERRA,
+    //NATIONAL_DEX_CHIMCHAR,
+    //NATIONAL_DEX_MONFERNO,
+    //NATIONAL_DEX_INFERNAPE,
+    //NATIONAL_DEX_PIPLUP,
+    //NATIONAL_DEX_PRINPLUP,
+    //NATIONAL_DEX_EMPOLEON,
+    //NATIONAL_DEX_STARLY,
```

When `TRUE`, Pokemon introduced in corresponding games are enabled.

`P_GEN_4_POKEMON`: Diamond, Pearl, Platinum, Heart Gold, or Soul Silver
`P_GEN_5_POKEMON`: Black, White, Black 2, White 2
`P_GEN_6_POKEMON`: X, Y, Omega Ruby and Alpha Sapphire
`P_GEN_7_POKEMON`: Sun, Moon, Ultra Sun, Ultra Moon, Let's Go Pikachu! and Let's Go Eevee!
`P_GEN_8_POKEMON`: Sword, Shield, Brilliant Diamond, Shining Pearl, and Legends: Arceus
`P_GEN_9_POKEMON`: Scarlet and Violet
