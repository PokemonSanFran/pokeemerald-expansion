# Moves

## Enabling / Disabling / Configuration

Move related configurations are in [`include/config/battle.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/battle.h). [[Documentation]](../configurations/battle.md)

Pokémon related configurations are in [`include/config/pokemon.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/pokemon.h). [[Documentation]](../configurations/pokemon.md)

## Physical and Special Split

By default, moves are assigned their [damage category](https://bulbapedia.bulbagarden.net/wiki/Damage_category) from the most recent generation. This can be changed or disabled in [battle.h](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/include/config/battle.h). [[Documentation]](../configurations/battle.md)

## Learnsets
<p align="center"><video width="240" height="160" controls muter><source src="../../img/placeholder.mp4" type="video/mp4">Your browser does not support the video tag.</video></p>

Pokémon that were introduced in Generation 7 or earlier have their learnsets from [Ultra Sun and Ultra Moon](https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_Ultra_Sun_and_Ultra_Moon). Pokémon introduced after Generation 7 have their learnsets from the game they first debuted in. In both cases, these learnsets include their new moves.

This can be easily changed with programs like [PoryMoves](https://github.com/AsparagusEduardo/PoryMoves), which allow developers to control which game's information is used to inform learnsets.
