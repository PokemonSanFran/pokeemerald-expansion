## Overworld Configuration (include/config/overworld.h)

### Movement

`OW_RUNNING_INDOORS` - Type: Generation Toggle
    - When inside buildsings, players can run.[\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
        - >= `GEN_4`: True
        - = `GEN_3`: False

### Other Settings
    
`OW_POISON_DAMAGE` - Type: Generation Toggle
    - When in the overworld, the player's Poisoned Pokemon [\[More Info\]](https://bulbapedia.bulbagarden.net/wiki/Inverse_Battle)
        - >= `GEN_5`: do not take damage
        - = `GEN_4`: lose 1 HP every 4 steps, and are cured of Poison whenthat Pokemon only has one HP remaining.
        - = `GEN_3`: lose 1 HP every 4 steps until they faint.

### Overworld Flags 
`OW_FLAG_NO_ENCOUNTER` - Type: Var / Flag
    - When this flag is set, wild Pokemon encounters are disabled.

`OW_FLAG_NO_TRAINER_SEE` - Type: Var / Flag
    - When this flag is set, trainers will not battle the player unless explicitly spoken to.

`OW_FLAG_NO_COLLISION` - Type: Var / Flag
    - When this flag is set, objecs in the overworld will ignore metatile collision values.
