# BUGFIXES
`pokeemerald` has a number of bugs that are present in the retail versions of the game. When a developer has uncommented `BUGFIX` in `include/config.h`, the community accepted fixes for these bugs are applied.

## `data/contest_ai_scripts.s`
* Contest AI will now use a move when the audience is close to full excitement and the AI is going first.

## `data/maps/BattleFrontier_BattleTowerLobby/scripts.inc`
* Players can no longer save their party and quit without having saved the PC (this prevents the Emerald Battle Tower cloning glitch).

## `data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc`
* Grunt2 in the Mossdeep Space Center will now face the correct direction to unblock the stairs. 

## `data/scripts/trainer_hill.inc`
* The warp script in Trainer Hill now properly ends.

## `src/battle_anim_sound_tasks.c`
* When in a Contest and a high pitched or double cry is set to be played, the correct value is reported for gAnimVisualTaskCount
//TODO please explain like I'm five

## `src/battle_dome.c`
* Dome Trainers now have proper IVs, instead of always being 3.
* Moves with no effect now return 8 instead of 0.

## `src/battle_factory_screen.c`
* The Pokemon's OT ID and personality are now properly used for creating a Pokemon's sprite. 

## `src/battle_main.c`
* When Roar is used by a roaming Pokemon, the roamer will no longer accidently be set as inactive (as if the player had defeated or captured it).

## `src/battle_pyramid.c`
* The memory allocated to the Battle Pyramid's floor layout is properly freed.

## `src/battle_tower.c`
* When recording new Records for the Battle Tower, the length of the player's name uses the correct value, instead of accidently using the length of the trainer ID.
* The IVs in the rented Pokemon in the Battle Factory are now calculated using the winstreak of the Battle Factory, instead of the Battle Tower.
* The 4th Pokemon in the player's party can now recieve a Ribbon from the Battle Tower.
* Steven's Pokemon use the intended personality value.

## `src/battle_util.c`
* The escape factor in the Safari Zone is properly evaluated, which prevents the Pokeblock throw glitch. 

## `src/berry_blender.c`
* Berry Blender NPCs can no longer get "Best" when blending at a low speed. 
* The music's tempo now properly increases when a player hits.

## `src/berry_crush.c`
* When hiding the game's display, the screen no longer fades twice. 
* The correct number of sparkles will now appear during the minigame, instead of just 0, 1 or 4.

## `src/contest_ai.c`
* Allows the AI to properly judge moves based on their effect, instead of just the move itself. 

## `src/daycare.c`
* When an IV is chosen to be inheirited, the IV picked for inheiritance cannot be repeated (also normalizing the likelihood of HP and DEF being chosen).

## `src/dodrio_berry_picking.c`
* The difficulty of the shared columns between players is correctly set.
* The game will not start until all players are ready when playing again.
* Memory is freed when leaving a screen with Dodrio on it.

## `src/egg_hatch.c`
* The egg hatch animation now shows all in-progress frames instead of skipping the last one.

## `src/event_object_movement.c`
* When looking for an overworld palette that is not in the table `sObjectEventSpritePalettes`, the game no longer infinitely loops.
* When failing to load an object event, `0xFF` is returned instead of `OBJ_EVENT_PAL_TAG_NONE`.

## `src/field_tasks.c`
* When the player steps on the Fortree bridges, the first step is now lowered, regardless of what the player was previously on.

## `src/fldeff_cut.c`
* Players can no longer use Cut on grass that is on a metatile with a collosion of 0 - 3.

## `src/frontier_pass.c`
* The Frontier Pass background no longer loads 208 colors instead of the intended 128.

## `src/intro.c`
* The correct number of bubbles are created around Kyogre's fins.

## `src/item_menu_icons.c`
* The item being scrolled to in the Bag menu no longer loads the incorrect palette.

## `src/main.c`
* The Random Number Generator is properly seeded using the Real Time Clock.

## `src/metatile_behavior.c`
* Player is no longer to emerge on a water door (which causes the Dive glitch)Player is no longer to emerge on a water door (which causes the Dive glitch).

## `src/pokeball.c`
* Pokeball animations now properly shrink during trades.

## `src/pokedex_area_screen.c`
* The Area screen now correctly uses the size of fishing encounters when calculating how many fishing spots to display.

## `src/pokemon.c`
* Natures can now properly calculate Nature affected stats that are greater than 595 for a positive nature and 728 for a negative nature. 

## `src/pokemon_animation.c`
*  //TODO I'm faking my way through most of these descriptions, but I absolutely do not understand this one.

## `src/pokemon_storage_system.c`
* When retrieving a boxed Pokemon's level, the function will now longer always return zero.

## `src/pokenav_ribbons_summary.c`
* When leaving the Ribbon Summary screen, the window ID is properly freed.

## `src/region_map.c`
* When diving on Route 125 for Marine Cave, the name for Route 129 is no longer shown.

## `src/roamer.c`
* A roaming Pokemon's cool, beauty, and cuteness stats are no longer used to set its status.

## `src/rotating_gate.c`
* The arms of the rotating gates in the Fortree Gym will no longer collide with metatiles with an elevation of 0 - 3.

## `src/roulette.c`
* The animation for changing the number of credits is properly terminated.

## `src/script_pokemon_util.c`
* The script for setting a Pokemon's move to a slot will no longer accidently go out of bounds.

## `src/siirtc.c`
*  //TODO I'm faking my way through most of these descriptions, but I absolutely do not understand this one.

## `src/union_room.c`
* The Awaiting Communication is properly passed to gStringVar4. 
* When a link leader is being established after a member leaves, the number of remaining playes is properly read.
