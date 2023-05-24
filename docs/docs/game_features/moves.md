# Moves

## Enabling / Disabling / Configuration

Move related configurations are in [`include/config/battle.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/battle.h). [[Documentation]](../configurations/battle.md)

Pokémon related configurations are in [`include/config/pokemon.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/pokemon.h). [[Documentation]](../configurations/pokemon.md)

## Physical and Special Split

By default, moves are assigned their [damage category](https://bulbapedia.bulbagarden.net/wiki/Damage_category) from the most recent generation. This can be changed or disabled in [battle.h](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/battle.h). [[Documentation]](../configurations/battle.md)

## Learnsets
![Gif of the player's Pokémon learning and then using a post Gen 3 move](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

Pokémon that were introduced in Generation 7 or earlier have their learnsets from [Ultra Sun and Ultra Moon](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Ultra_Sun_and_Ultra_Moon). Pokémon introduced after Generation 7 have their learnsets from the game they first debuted in. In both cases, these learnsets include their new moves.

This can be easily changed with programs like [PoryMoves](https://github.com/AsparagusEduardo/PoryMoves), which allow developers to control which game's information is used to inform learnsets.
