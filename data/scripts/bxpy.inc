DebugBXPY::
# 3 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE01_GET
# 4 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE02_GET
# 5 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE03_GET
# 6 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE04_GET
# 7 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE05_GET
# 8 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE06_GET
# 9 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE07_GET
# 10 "data/scripts/bxpy.pory"
	setflag FLAG_BADGE08_GET
# 11 "data/scripts/bxpy.pory"
	givemon SPECIES_EXEGGUTOR, 100, 1
# 12 "data/scripts/bxpy.pory"
	givemon SPECIES_CLEFABLE, 100, 2
# 13 "data/scripts/bxpy.pory"
	givemon SPECIES_SLOWBRO, 100, 3
# 14 "data/scripts/bxpy.pory"
	givemon SPECIES_ELECTIVIRE, 100, 4
# 15 "data/scripts/bxpy.pory"
	givemon SPECIES_NINETALES, 100, 5
# 16 "data/scripts/bxpy.pory"
	givemon SPECIES_PINSIR, 100, ITEM_PINSIRITE
# 17 "data/scripts/bxpy.pory"
	setflag FLAG_SYS_POKEMON_GET
# 18 "data/scripts/bxpy.pory"
	bringxpicky 0, 6, 3, TRAINER_WALLACE, DebugBXPY_Text_0, TRAINER_STEVEN, DebugBXPY_Text_0
	return


BXPY_Script_CheckErrors::
# 23 "data/scripts/bxpy.pory"
	setvar VAR_TEMP_0, 0
# 25 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeTooLarge
# 26 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_2
BXPY_Script_CheckErrors_1:
# 33 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_BringSizeNotEnough
# 34 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_5
BXPY_Script_CheckErrors_4:
# 41 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseSpecies
# 42 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_8
BXPY_Script_CheckErrors_7:
# 49 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseItem
# 50 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_11
BXPY_Script_CheckErrors_10:
# 57 "data/scripts/bxpy.pory"
	callnative BXPY_OverworldRun_ErrorCheck_ClauseUbers
# 58 "data/scripts/bxpy.pory"
	compare VAR_RESULT, 0
	goto_if_ne BXPY_Script_CheckErrors_14
BXPY_Script_CheckErrors_13:
# 65 "data/scripts/bxpy.pory"
	compare VAR_TEMP_0, 0
	goto_if_gt BXPY_Script_CheckErrors_16
	return

BXPY_Script_CheckErrors_2:
# 28 "data/scripts/bxpy.pory"
	addvar VAR_TEMP_0, 1
# 29 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_0, MSGBOX_AUTOCLOSE
# 30 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_1

BXPY_Script_CheckErrors_5:
# 36 "data/scripts/bxpy.pory"
	addvar VAR_TEMP_0, 1
# 37 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_1, MSGBOX_AUTOCLOSE
# 38 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_4

BXPY_Script_CheckErrors_8:
# 44 "data/scripts/bxpy.pory"
	addvar VAR_TEMP_0, 1
# 45 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_2, MSGBOX_AUTOCLOSE
# 46 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_7

BXPY_Script_CheckErrors_11:
# 52 "data/scripts/bxpy.pory"
	addvar VAR_TEMP_0, 1
# 53 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_3, MSGBOX_AUTOCLOSE
# 54 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_10

BXPY_Script_CheckErrors_14:
# 60 "data/scripts/bxpy.pory"
	addvar VAR_TEMP_0, 1
# 61 "data/scripts/bxpy.pory"
	msgbox BXPY_Script_CheckErrors_Text_4, MSGBOX_AUTOCLOSE
# 62 "data/scripts/bxpy.pory"
	closemessage
	goto BXPY_Script_CheckErrors_13

BXPY_Script_CheckErrors_16:
# 67 "data/scripts/bxpy.pory"
	release
	end


DebugBXPY_Text_0:
# 18 "data/scripts/bxpy.pory"
	.string "yes$"

BXPY_Script_CheckErrors_Text_0:
# 29 "data/scripts/bxpy.pory"
	.string "You have too many Pokemon in your\n"
	.string "party. You cannot have more than\l"
	.string "{STR_VAR_1}.$"

BXPY_Script_CheckErrors_Text_1:
# 37 "data/scripts/bxpy.pory"
	.string "You must have {STR_VAR_1} healthy\n"
	.string "Pokemon in your party to battle!$"

BXPY_Script_CheckErrors_Text_2:
# 45 "data/scripts/bxpy.pory"
	.string "All of the Pokemon in your party must be\n"
	.string "of unique species.\l"
	.string "{STR_VAR_1}\l"
	.string "appear more than once.$"

BXPY_Script_CheckErrors_Text_3:
# 53 "data/scripts/bxpy.pory"
	.string "All of the held items in your party must\n"
	.string "be unique.\l"
	.string "{STR_VAR_1}\l"
	.string "appear more than once.$"

BXPY_Script_CheckErrors_Text_4:
# 61 "data/scripts/bxpy.pory"
	.string "Some Pokemon are restricted from\n"
	.string "entering. You cannot bring\l"
	.string "{STR_VAR_1}.$"
