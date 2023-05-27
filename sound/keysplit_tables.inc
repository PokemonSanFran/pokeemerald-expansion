@ Due to the way mks4agb (Nintendo's tool) works, key split table labels can
@ appear before the actual start of the key split table data. If you look at
@ the first keysplit table (KeySplitTable1), you'll notice it's offset backwards
@ by 36 bytes. This is because the key split tables don't map instruments
@ for the entire note range (0-127)--they only map subsets, and the upper
@ and lower ranges aren't necessarily 0 or 127.
@
@ For example if a key split table maps an note range of 10-20, then the key
@ split table label will be offset 10 bytes before the actual key split data
@ begins. Therefore, the notes naturally map to the key split table without
@ any extra offset calculation.

.set KeySplitTable1, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 1  @ 55
	.byte 1  @ 56
	.byte 1  @ 57
	.byte 1  @ 58
	.byte 1  @ 59
	.byte 1  @ 60
	.byte 1  @ 61
	.byte 1  @ 62
	.byte 1  @ 63
	.byte 1  @ 64
	.byte 1  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 2  @ 70
	.byte 2  @ 71
	.byte 2  @ 72
	.byte 2  @ 73
	.byte 2  @ 74
	.byte 2  @ 75
	.byte 2  @ 76
	.byte 2  @ 77
	.byte 2  @ 78
	.byte 2  @ 79
	.byte 2  @ 80
	.byte 2  @ 81
	.byte 2  @ 82
	.byte 2  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 3  @ 91
	.byte 3  @ 92
	.byte 3  @ 93
	.byte 3  @ 94
	.byte 3  @ 95
	.byte 3  @ 96
	.byte 3  @ 97
	.byte 3  @ 98
	.byte 3  @ 99
	.byte 3  @ 100
	.byte 3  @ 101
	.byte 3  @ 102
	.byte 3  @ 103
	.byte 3  @ 104
	.byte 3  @ 105
	.byte 3  @ 106
	.byte 3  @ 107

.set KeySplitTable2, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 0  @ 66
	.byte 0  @ 67
	.byte 0  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 2  @ 81
	.byte 2  @ 82
	.byte 2  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 2  @ 91
	.byte 2  @ 92
	.byte 2  @ 93
	.byte 2  @ 94
	.byte 2  @ 95
	.byte 2  @ 96
	.byte 2  @ 97
	.byte 2  @ 98
	.byte 2  @ 99
	.byte 2  @ 100
	.byte 2  @ 101
	.byte 2  @ 102
	.byte 2  @ 103
	.byte 2  @ 104
	.byte 2  @ 105
	.byte 2  @ 106
	.byte 2  @ 107

.set KeySplitTable3, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 2  @ 84
	.byte 2  @ 85
	.byte 2  @ 86
	.byte 2  @ 87
	.byte 2  @ 88
	.byte 2  @ 89
	.byte 2  @ 90
	.byte 2  @ 91
	.byte 2  @ 92
	.byte 2  @ 93
	.byte 2  @ 94
	.byte 2  @ 95
	.byte 2  @ 96
	.byte 2  @ 97
	.byte 2  @ 98
	.byte 2  @ 99
	.byte 2  @ 100
	.byte 2  @ 101
	.byte 2  @ 102
	.byte 2  @ 103
	.byte 2  @ 104
	.byte 2  @ 105
	.byte 2  @ 106
	.byte 2  @ 107

.set KeySplitTable4, . - 24
	.byte 0  @ 24
	.byte 0  @ 25
	.byte 0  @ 26
	.byte 0  @ 27
	.byte 0  @ 28
	.byte 0  @ 29
	.byte 0  @ 30
	.byte 0  @ 31
	.byte 0  @ 32
	.byte 0  @ 33
	.byte 0  @ 34
	.byte 0  @ 35
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 1  @ 42
	.byte 1  @ 43
	.byte 1  @ 44
	.byte 1  @ 45
	.byte 1  @ 46
	.byte 1  @ 47
	.byte 1  @ 48
	.byte 1  @ 49
	.byte 1  @ 50
	.byte 1  @ 51
	.byte 1  @ 52
	.byte 1  @ 53
	.byte 1  @ 54
	.byte 1  @ 55
	.byte 1  @ 56
	.byte 1  @ 57
	.byte 1  @ 58
	.byte 1  @ 59
	.byte 1  @ 60
	.byte 1  @ 61
	.byte 1  @ 62
	.byte 1  @ 63
	.byte 1  @ 64
	.byte 1  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 1  @ 84
	.byte 1  @ 85
	.byte 1  @ 86
	.byte 1  @ 87
	.byte 1  @ 88
	.byte 1  @ 89
	.byte 1  @ 90
	.byte 1  @ 91
	.byte 1  @ 92
	.byte 1  @ 93
	.byte 1  @ 94
	.byte 1  @ 95
	.byte 1  @ 96
	.byte 1  @ 97
	.byte 1  @ 98
	.byte 1  @ 99
	.byte 1  @ 100
	.byte 1  @ 101
	.byte 1  @ 102
	.byte 1  @ 103
	.byte 1  @ 104
	.byte 1  @ 105
	.byte 1  @ 106
	.byte 1  @ 107

.set KeySplitTable5, . - 36
	.byte 0  @ 36
	.byte 0  @ 37
	.byte 0  @ 38
	.byte 0  @ 39
	.byte 0  @ 40
	.byte 0  @ 41
	.byte 0  @ 42
	.byte 0  @ 43
	.byte 0  @ 44
	.byte 0  @ 45
	.byte 0  @ 46
	.byte 0  @ 47
	.byte 0  @ 48
	.byte 0  @ 49
	.byte 0  @ 50
	.byte 0  @ 51
	.byte 0  @ 52
	.byte 0  @ 53
	.byte 0  @ 54
	.byte 0  @ 55
	.byte 0  @ 56
	.byte 0  @ 57
	.byte 0  @ 58
	.byte 0  @ 59
	.byte 0  @ 60
	.byte 0  @ 61
	.byte 0  @ 62
	.byte 0  @ 63
	.byte 0  @ 64
	.byte 0  @ 65
	.byte 1  @ 66
	.byte 1  @ 67
	.byte 1  @ 68
	.byte 1  @ 69
	.byte 1  @ 70
	.byte 1  @ 71
	.byte 1  @ 72
	.byte 1  @ 73
	.byte 1  @ 74
	.byte 1  @ 75
	.byte 1  @ 76
	.byte 1  @ 77
	.byte 1  @ 78
	.byte 1  @ 79
	.byte 1  @ 80
	.byte 1  @ 81
	.byte 1  @ 82
	.byte 1  @ 83
	.byte 1  @ 84
	.byte 1  @ 85
	.byte 1  @ 86
	.byte 1  @ 87
	.byte 1  @ 88
	.byte 1  @ 89
	.byte 1  @ 90
	.byte 1  @ 91
	.byte 1  @ 92
	.byte 1  @ 93
	.byte 1  @ 94
	.byte 1  @ 95
	.byte 1  @ 96
	.byte 1  @ 97
	.byte 1  @ 98
	.byte 1  @ 99
	.byte 1  @ 100
	.byte 1  @ 101
	.byte 1  @ 102
	.byte 1  @ 103
	.byte 1  @ 104
	.byte 1  @ 105
	.byte 1  @ 106
	.byte 1  @ 107

Keysplit_0_1_2_3_42_49_56_63:
	.incbin "sound/notecharts/Keysplit_0_1_2_3_42_49_56_63.bin"

Keysplit_0_1_45_55:
	.incbin "sound/notecharts/Keysplit_0_1_45_55.bin"

Keysplit_0_12_44_56_68:
	.incbin "sound/notecharts/Keysplit_0_12_44_56_68.bin"

Keysplit_3_7_11_39_47_57_83_99_107_117:
	.incbin "sound/notecharts/Keysplit_3_7_11_39_47_57_83_99_107_117.bin"

Keysplit_11_23_44_56_68:
	.incbin "sound/notecharts/Keysplit_11_23_44_56_68.bin"

Keysplit_11_63_69_75:
	.incbin "sound/notecharts/Keysplit_11_63_69_75.bin"

Keysplit_29_41_53_65_80_92:
	.incbin "sound/notecharts/Keysplit_29_41_53_65_80_92.bin"

Keysplit_30_46:
	.incbin "sound/notecharts/Keysplit_30_46.bin"

Keysplit_33_45:
	.incbin "sound/notecharts/Keysplit_33_45.bin"

Keysplit_36_52_67_80:
	.incbin "sound/notecharts/Keysplit_36_52_67_80.bin"

Keysplit_37_52_62_76:
	.incbin "sound/notecharts/Keysplit_37_52_62_76.bin"

Keysplit_41:
	.incbin "sound/notecharts/Keysplit_41.bin"

Keysplit_43_55_67:
	.incbin "sound/notecharts/Keysplit_43_55_67.bin"

Keysplit_43_55_67_79:
	.incbin "sound/notecharts/Keysplit_43_55_67_79.bin"

Keysplit_44_56:
	.incbin "sound/notecharts/Keysplit_44_56.bin"

Keysplit_44_56_68:
	.incbin "sound/notecharts/Keysplit_44_56_68.bin"

Keysplit_44_56_68_80:
	.incbin "sound/notecharts/Keysplit_44_56_68_80.bin"

Keysplit_45_53_63:
	.incbin "sound/notecharts/Keysplit_45_53_63.bin"

Keysplit_47:
	.incbin "sound/notecharts/Keysplit_47.bin"

Keysplit_47_59:
	.incbin "sound/notecharts/Keysplit_47_59.bin"

Keysplit_48_57:
	.incbin "sound/notecharts/Keysplit_48_57.bin"

Keysplit_50_58_66_75:
	.incbin "sound/notecharts/Keysplit_50_58_66_75.bin"

Keysplit_51_59_69:
	.incbin "sound/notecharts/Keysplit_51_59_69.bin"

Keysplit_52_64:
	.incbin "sound/notecharts/Keysplit_52_64.bin"

Keysplit_54_66:
	.incbin "sound/notecharts/Keysplit_54_66.bin"

Keysplit_54_66_78:
	.incbin "sound/notecharts/Keysplit_54_66_78.bin"

Keysplit_55_64:
	.incbin "sound/notecharts/Keysplit_55_64.bin"

Keysplit_55_67_79:
	.incbin "sound/notecharts/Keysplit_55_67_79.bin"

Keysplit_56_65_71:
	.incbin "sound/notecharts/Keysplit_56_65_71.bin"

Keysplit_56_68:
	.incbin "sound/notecharts/Keysplit_56_68.bin"

Keysplit_56_68_80:
	.incbin "sound/notecharts/Keysplit_56_68_80.bin"

Keysplit_57_65:
	.incbin "sound/notecharts/Keysplit_57_65.bin"

Keysplit_57_69_81:
	.incbin "sound/notecharts/Keysplit_57_69_81.bin"

Keysplit_57_77:
	.incbin "sound/notecharts/Keysplit_57_77.bin"

Keysplit_58_65_72:
	.incbin "sound/notecharts/Keysplit_58_65_72.bin"

Keysplit_58_67:
	.incbin "sound/notecharts/Keysplit_58_67.bin"

Keysplit_59:
	.incbin "sound/notecharts/Keysplit_59.bin"

Keysplit_59_71_79_86:
	.incbin "sound/notecharts/Keysplit_59_71_79_86.bin"

Keysplit_60_67_73:
	.incbin "sound/notecharts/Keysplit_60_67_73.bin"

Keysplit_60_72:
	.incbin "sound/notecharts/Keysplit_60_72.bin"

Keysplit_62:
	.incbin "sound/notecharts/Keysplit_62.bin"

Keysplit_63_70:
	.incbin "sound/notecharts/Keysplit_63_70.bin"

Keysplit_63_71:
	.incbin "sound/notecharts/Keysplit_63_71.bin"

Keysplit_64:
	.incbin "sound/notecharts/Keysplit_64.bin"

Keysplit_65_70_77:
	.incbin "sound/notecharts/Keysplit_65_70_77.bin"

Keysplit_66_75:
	.incbin "sound/notecharts/Keysplit_66_75.bin"

Keysplit_66_77:
	.incbin "sound/notecharts/Keysplit_66_77.bin"

Keysplit_67_73:
	.incbin "sound/notecharts/Keysplit_67_73.bin"

Keysplit_67_74_80:
	.incbin "sound/notecharts/Keysplit_67_74_80.bin"

Keysplit_67_74_82:
	.incbin "sound/notecharts/Keysplit_67_74_82.bin"

Keysplit_67_76:
	.incbin "sound/notecharts/Keysplit_67_76.bin"

Keysplit_68:
	.incbin "sound/notecharts/Keysplit_68.bin"

Keysplit_68_77:
	.incbin "sound/notecharts/Keysplit_68_77.bin"

Keysplit_68_80:
	.incbin "sound/notecharts/Keysplit_68_80.bin"

Keysplit_70_80:
	.incbin "sound/notecharts/Keysplit_70_80.bin"

Keysplit_71:
	.incbin "sound/notecharts/Keysplit_71.bin"

Keysplit_80:
	.incbin "sound/notecharts/Keysplit_80.bin"

Keysplit_80_92:
	.incbin "sound/notecharts/Keysplit_80_92.bin"

Keysplit_84_94:
	.incbin "sound/notecharts/Keysplit_84_94.bin"
