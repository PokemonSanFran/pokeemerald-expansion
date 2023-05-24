# Overworld Configuration

This page documents the configurations found in [`include/config/overworld.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/overworld.h).

## Movement

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `OW_RUNNING_INDOORS` - Type: Generation Toggle
    - When inside buildings, players can run. [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Running_Shoes#Effect)
        - \>= `GEN_4`: True
        - = `GEN_3`: False

## Other Settings

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `OW_POISON_DAMAGE` - Type: Generation Toggle
    - When in the overworld, the player's poisoned Pokémon [[More Info]](https://bulbapedia.bulbagarden.net/wiki/Poison_(status_condition)#Generation_IV)
        - \>= `GEN_5`: do not take damage
        - = `GEN_4`: lose 1 HP every 4 steps, and are cured of Poison when that Pokémon only has one HP remaining
        - = `GEN_3`: lose 1 HP every 4 steps until they faint

## Overworld Flags 

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `OW_FLAG_NO_ENCOUNTER` - Type: Var / Flag
    - When this flag is set in game, wild Pokémon encounters are disabled.

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `OW_FLAG_NO_TRAINER_SEE` - Type: Var / Flag
    - When this flag is set in game, trainers will not battle the player unless explicitly spoken to.

---

![](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

- `OW_FLAG_NO_COLLISION` - Type: Var / Flag
    - When this flag is set in game, object in the overworld will ignore metatile collision values.
