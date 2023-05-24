# Pokémon Configuration

This page documents the configurations found in [`pokemon.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/pokemon.h).

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_UPDATED_TYPES` - Type: Generation Toggle  
    - Pokémon use the Types assigned to them in the defined generation. This most notably impacts Pokémon that gained a Fairy-type during Generation 6. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Category:Pok%C3%A9mon_that_have_had_their_type_changed)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_UPDATED_STATS` - Type: Generation Toggle  
    - Pokémon use the stats assigned to them in the defined generation. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Base_stats#Between_generations)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_UPDATED_ABILITIES` - Type: Generation Toggle  
    - Pokémon use the abilities assigned to them in the defined generation. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_Ability)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_UPDATED_EGG_GROUPS` - Type: Generation Toggle  
    - Pokémon use the egg groups assigned to them in the defined generation. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_Egg_Group)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_NIDORAN_M_DITTO_BREED` - Type: - Generation Toggle  

    - When Nidoran♂ or Volbeat breed with a Ditto, the offspring can be: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_breeding#Gender-counterpart_species)
        - \>= `GEN_5`: Nidoran♀ or Nidoran♂/Volbeat or Illumise
        - <= `GEN_4`: only Nidoran♂/only Volbeat

    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_INCENSE_BREEDING` - Type: Generation Toggle  
    - Cross-generation Baby Pokémon require Incense being held by the parents to be obtained via breeding. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_breeding#Incense_breeding)
        - \>= `GEN_9`: True
        - <= `GEN_8`: False
    
    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_EGG_HATCH_LEVEL` - Type: Generation Toggle  
    - Pokémon hatch at Level: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_breeding#What_will_hatch)
        - \>= `GEN_4`: 1
        - = `GEN_3`: 5
    
    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_BALL_INHERITING` - Type: Generation Toggle  
    - The mechanics of Poké Ball breeding inheritance have changed over the generations. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_breeding#Inheriting_Pok.C3.A9_Balls)
        - \>= `GEN_7`: When the mother and father are the same species, Eggs from the Daycare can inherit the Poké Ball from either parent. If they are different species, the Egg will inherit the Poké Ball from the mother.
        - = `GEN_6`: Eggs from the Daycare will inheirit the Poké Ball from the mother.
        - <= `GEN_5`: Eggs from the Daycare are placed in Poké Balls.
    
    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_SHEDINJA_BALL` - Type: Generation Toggle  
    - When Nincada evolves, the resulting Shedinja: [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Shedinja_(Pok%C3%A9mon)#Trivia)
        - \>= `GEN_4`: will use one of the regular Poké Balls in the player's bag. Shedinja will not spawn if there is no spare Poké Ball.
        - <= `GEN_3`: will inheirit the Nincada's Poké Ball.
    
    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_KADABRA_EVERSTONE` - Type: Generation Toggle  
    - Kadabra can evolve even when holding an Everstone. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Everstone#Generation_IV_onwards)
        - \>= `GEN_4`: True
        - <= `GEN_3`: False
    
    ---
    
    ![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_HIPPO_GENDER_DIFF_ICONS` - Type: True / False        
    - When `TRUE`, Hippopotas and Hippowdon female variants will use a custom icon instead of the same icons as their male variants. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Hippopotas_(Pok%C3%A9mon)#Biology)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_SHUCKLE_BERRY_JUICE` - Type: True / False        
    - When `TRUE` and Shuckle is holding an Oran Berry, after every battle, there is a 1/16 chance that the item will turn into Berry Juice. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Berry_Juice#Acquisition)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_LEGENDARY_PERFECT_IVS` - Type: Generation Toggle  
    - Ultra Beasts, Legendary, and Mythical Pokémon that are found in the wild or given to the player will be guaranteed to have N perfect IVs. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Individual_values#Influence)
        - \>= `GEN_8`: 3
        - <= `GEN_7`: 0

    ---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_FLAG_FORCE_SHINY` - Type: Var / Flag     
    - When this flag is set, Pokémon that are found in the wild or given to the player will be guaranteed to be Shiny. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Shiny_Pok%C3%A9mon)

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `P_FLAG_FORCE_NO_SHINY` - Type: Var / Flag     
    - When this flag is set, Pokémon that are found in the wild or given to the player will be guaranteed to be NOT Shiny. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Shiny_Pok%C3%A9mon)

---

## Enabling Pokémon Generations

When a generation is set to `TRUE`, the developer can reference these Pokémon in battles and scripts. Cross regional formes use the original Pokémon's generation, but cross regional evolutions rely on the evolved Pokémon's generation.

| Constant          | Pokémon introduced in these games are included               |
| ----------------- | ------------------------------------------------------------ |
| `P_GEN_4_POKEMON` | Diamond, Pearl, Platinum, Heart Gold, or Soul Silver         |
| `P_GEN_5_POKEMON` | Black, White, Black 2, White 2                               |
| `P_GEN_6_POKEMON` | X, Y, Omega Ruby, Alpha Sapphire                             |
| `P_GEN_7_POKEMON` | Sun, Moon, Ultra Sun, Ultra Moon, Let's Go Pikachu!, Let's Go Eevee! |
| `P_GEN_8_POKEMON` | Sword, Shield, Brilliant Diamond, Shining Pearl, Legends Arceus |
| `P_GEN_9_POKEMON` | Scarlet, Violet                                              |

### Example

```
#define P_GEN_7_POKEMON             TRUE        // Generation 7 Pokémon (SM, USUM, LGPE)
#define P_GEN_8_POKEMON             TRUE        // Generation 8 Pokémon (SwSh, BDSP, LA)
```

Galarian Meowth and Alolan Meowth will be available, but Galarian Meowth will not evolve into Perrserker.

If a developer disables a generation previous to other enabled generations, then the disabled Pokémon will need to be manually commented out in [`include/constants/pokedex.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/constants/pokedex.h).

### Example

```
#define P_GEN_4_POKEMON             FALSE        // Generation 4 Pokémon (DPPt, HGSS)
#define P_GEN_5_POKEMON             TRUE        // Generation 5 Pokémon (BW, B2W2)
```

In this case, the Pokémon from Generation 4 need to be commented out.

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
