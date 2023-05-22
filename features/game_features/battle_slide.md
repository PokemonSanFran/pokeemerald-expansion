# Battle Slide Message
![Gif of a a Fairy-typed Gardevoir with a new ability](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)
Introduced in Generation 5, Battle Slide Messages are used to inform the player about the impacts of moves or abilities in battle.

## Enabling / Disabling / Configuration

By default, Battle Slide Messages are enabled, but can be disabled in [`battle.h`](../../include/config/battle.h). [[Documentation]](../configurations/battle.md)

## Usage

Battle Slide Messages occur when `showabilitypopup` is called in a battle script.

## Example

![Gif of a a Fairy-typed Gardevoir with a new ability](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png)

For example, when a Pokemon with the Ability [Good As Gold](https://bulbapedia.bulbagarden.net/wiki/Good_as_Gold_(Ability)) is hit with Sleep Powder, the following script activates:

```
BattleScript_GoodAsGoldActivates::
	attackstring
	ppreduce
	showabilitypopup BS_TARGET
	pause B_WAIT_TIME_SHORT
	printstring STRINGID_ITDOESNTAFFECT
	waitmessage B_WAIT_TIME_MED
	goto BattleScript_MoveEnd
```
