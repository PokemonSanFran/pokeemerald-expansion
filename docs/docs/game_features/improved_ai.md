# Improved Battle Artificial Intelligence

`pokeemerald-expaansion` provides a number of improves to the battle AI, allowing for more interesting and engaging battles within a developer's game.

## AI Overview

When in battle, the AI has a score for each of its move, and two special actions (fleeing, or "watching" in the Safari Zone). Each action's score is calculated using the AI functions in [`src/battle_main.c`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/src/battle_main.c), which in turn are contorlled by the AI Flags defined for that Trainer. If no flags are set, the AI will just randomly pick one of its moves.

## AI Flags

|Flag Constant| Function | Behavior Description |
| ---| --- | --- |
|`AI_FLAG_CHECK_BAD_MOVE`|`AI_CheckBadMove`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_TRY_TO_FAINT`|`AI_TryToFaint`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_CHECK_VIABILITY`|`AI_CheckViability`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_SETUP_FIRST_TURN`|`AI_SetupFirstTurn`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_RISKY`|`AI_Risky`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_PREFER_STRONGEST_MOVE`|`AI_PreferStrongestMove`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_PREFER_BATON_PASS`|`AI_PreferBatonPass`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_DOUBLE_BATTLE`|`AI_DoubleBattle`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_HP_AWARE`|`AI_HPAware`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|
|`AI_FLAG_NEGATE_UNAWARE`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI is NOT aware of negating effects like wonder room, mold breaker, etc|
|`AI_FLAG_WILL_SUICIDE`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI will use explosion / self destruct / final gambit / etc|
|`AI_FLAG_HELP_PARTNER`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI can try to help partner. If not set, will tend not to target partner|
|`AI_FLAG_PREFER_STATUS_MOVES`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI gets a score bonus for status moves. Should be combined with `AI_FLAG_CHECK_BAD_MOVE` to prevent using only status moves|
|`AI_FLAG_STALL`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI stalls battle and prefers secondary damage/trapping/etc.|
|`AI_FLAG_SCREENER`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI prefers screening effects like reflect, mist, etc.|
|`AI_FLAG_SMART_SWITCHING`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI includes a lot more switching checks|
|`AI_FLAG_ACE_POKEMON`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI has an Ace Pokémon. The last Pokémon in the party will not be used until it's the last one remaining.|
|`AI_FLAG_OMNISCIENT`|[???](https://discord.com/channels/419213663107416084/1077168246555430962/1107518667710799972)|AI has full knowledge of player moves, abilities, hold items|

## Usage

Trainers and their AI Flags are defined in [`src/data/trainers.h`](https://github.com/rh-hideout/pokeemerald-expansion/tree/upcoming/src/data/trainers.h) in the member `.aiFlags`.

## Example

| Original Wallace Behavior                                    | Modified Wallace Behavior                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![Gif of the player's Pokémon learning and then using a post Gen 3 move](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png) | ![Gif of the player's Pokémon learning and then using a post Gen 3 move](https://archives.bulbagarden.net/media/upload/f/f9/Fire_Blast_III.png) |

```diff
[TRAINER_WALLACE] =
{
    .trainerClass = TRAINER_CLASS_CHAMPION,
    .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
    .trainerPic = TRAINER_PIC_CHAMPION_WALLACE,
    .trainerName = _("WALLACE"),
    .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
    .doubleBattle = FALSE,
-    .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
+    .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY | AI_FLAG_SCREENER | AI_FLAG_SMART_SWITCHING | AI_FLAG_ACE_POKEMON
    .party = ITEM_CUSTOM_MOVES(sParty_Wallace),
},
```

This change will modify Champion Wallace's AI. In addition to his default behaviors (`AI_FLAG_CHECK_BAD_MOVE`, `AI_FLAG_TRY_TO_FAINT` and `AI_FLAG_CHECK_VIABILITY`), he will also prefer moves like Reflect, Light Screen, and Mist, and more heavily weight the value of switching Pokémon. He will also never send out his Milotic until it is his last Pokémon.
