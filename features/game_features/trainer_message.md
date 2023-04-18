## Mid Battle Trainer Messages
<img src="" alt="Trainer Jared showing off two of the Trainer Slide scenarios" height=160px width=240px>
Introduced in Generation 4, Mid Battle Trainer Messages are lines of dialogue spoken by the opponent when the opponent:
    - the opponent sends in their final Pokemon.
    - the opponent's last Pokemon has low HP.
    - the opponent's first Pokemon is sent out.

**Usage**:

Dialogue lines can be created and declared anywhere in the game, but it is reccomended to place them in `src/battle_messages.c` 

```diff
static const u8 sText_PkmnHungOnWithX[] = _("{B_DEF_NAME_WITH_PREFIX} hung on\nusing its {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("You throw a BALL now, right?\nI… I'll do my best!");

+static const u8 sText_WellIllBe[] = _("Well I'll be! Sure didn't see that coming.");
+static const u8 sText_HeHHehHeh[] = _("Heh heh heh… You're unprepared for\nthis. We'll knock you down!");
+static const u8 sText_PerhapsImThe[] = _("Perhaps I'm the one who was\nunprepared?");
```

Next, a Trainer slide struct is created in `src/battle_message.c`. If the develoepr does not want to use a specific dialogue scenario, `NULL` can be entered instead of a string.

```diff
static const struct TrainerSlide sTrainerSlides[] =
{
    +{
        +.trainerId = TRAINER_JARED,
        +.msgLastSwitchIn = sText_WellIllBe,
        +.msgLastLowHp = sText_HeHHehHeh,
        +.msgFirstDown = NULL,
    +}
};
```
