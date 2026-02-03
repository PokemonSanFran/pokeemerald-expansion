DebugBXPY::
# 3 "data/scripts/bxpy.pory"
	givemon SPECIES_BULBASAUR, 0, 0
# 4 "data/scripts/bxpy.pory"
	givemon SPECIES_PIKACHU, 0, 0
# 5 "data/scripts/bxpy.pory"
	givemon SPECIES_CHARIZARD, 0, 0
# 6 "data/scripts/bxpy.pory"
	givemon SPECIES_BULBASAUR, 0, 0
# 7 "data/scripts/bxpy.pory"
	givemon SPECIES_BULBASAUR, 0, 0
# 8 "data/scripts/bxpy.pory"
	givemon SPECIES_BULBASAUR, 0, 0
# 9 "data/scripts/bxpy.pory"
	bringxpicky 0, 6, 4, TRAINER_WALLACE, , DebugBXPY_Text_0
	return


BXPY_Script_CheckErrors::
# 14 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge
# 15 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_2
BXPY_Script_CheckErrors_1:
# 21 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough
# 22 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_5
BXPY_Script_CheckErrors_4:
# 28 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseSpecies
# 29 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_8
BXPY_Script_CheckErrors_7:
# 35 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseItem
# 36 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_11
BXPY_Script_CheckErrors_10:
# 42 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseUbers
# 43 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_14
BXPY_Script_CheckErrors_13:
# 49 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_16
	return

BXPY_Script_CheckErrors_2:
# 17 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_0, MSGBOX_AUTOCLOSE
# 18 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_1

BXPY_Script_CheckErrors_5:
# 24 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_1, MSGBOX_AUTOCLOSE
# 25 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_4

BXPY_Script_CheckErrors_8:
# 31 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_2, MSGBOX_AUTOCLOSE
# 32 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_7

BXPY_Script_CheckErrors_11:
# 38 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_3, MSGBOX_AUTOCLOSE
# 39 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_10

BXPY_Script_CheckErrors_14:
# 45 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_4, MSGBOX_AUTOCLOSE
# 46 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_13

BXPY_Script_CheckErrors_16:
# 51 "data/scripts/bxpy.pory"
	release
	end


DebugBXPY_Text_0:
# 9 "data/scripts/bxpy.pory"
	.string "yes$"

BXPY_Script_CheckErrors_Text_0:
# 17 "data/scripts/bxpy.pory"
	.string "You have too many Pokemon in your\n"
	.string "party. You cannot have more than\l"
	.string "{STR_VAR_1}.$"

BXPY_Script_CheckErrors_Text_1:
# 24 "data/scripts/bxpy.pory"
	.string "You must have {STR_VAR_1} healthy\n"
	.string "Pokemon in your party to battle!$"

BXPY_Script_CheckErrors_Text_2:
# 31 "data/scripts/bxpy.pory"
	.string "All of the Pokemon in your party must be\n"
	.string "of unique species.\l"
	.string "{STR_VAR_1}\l"
	.string "appear more than once.$"

BXPY_Script_CheckErrors_Text_3:
# 38 "data/scripts/bxpy.pory"
	.string "All of the held items in your party must\n"
	.string "be unique.\n"
	.string "{STR_VAR_1} appear more than once.$"

BXPY_Script_CheckErrors_Text_4:
# 45 "data/scripts/bxpy.pory"
	.string "Some Pokemon are restricted from\n"
	.string "entering. You cannot bring\n"
	.string "{STR_VAR_1}.$"
