# Totem Boosts

![](https://i.imgur.com/VKmx5s9.gif)

Introduced in Gen 7, totem boosts allow you to set up a boss battle with a wild Pokemon that starts the battle with boosted (or lowered!) stats.

## Usage

This is very simple to set up: it uses a scripting command, `settotemboost` to set up the stat changes for any battler.

```
settotemboost battler, atkBoost, defBoost, speedBoost, spatkBoost, spdefBoost, accBoost, evasBoost
```

- `battler`: the battler position to gain the totem boost where:
  - 0: player left
  - 1: opponent left
  - 2: player right (unused in single battles)
  - 3: opponent right (unused in single battles)
  - This boost only applies to the Pokemon in that position at the beginning of a battle.
- `*Boost`: amount to boost each stat, ranges from -6 to +6

`totemboost_atk1` is a similar macro, which applies +1 to all stats for the declared battler position. `totemboost_atk2` applies +2.

### Notes

You can assign arguments up until the last stat you want changed, and the rest will default to 0!

## Example

![](https://i.imgur.com/VKmx5s9.gif)

```
EventScript_TotemTest::
    settotemboost 1, 1, 0, -2
    setwildbattle SPECIES_ARMALDO
    dowildbattle
    end
```
