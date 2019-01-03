.data
_const_int_0: .word 0
_const_int_1: .word 1
_const_int_2: .word -3
_const_char_0: .word 42
_const_char_1: .word 48
max: .word 1000
error: .space 4
numbers_to_be_selected: .space 4
amount: .space 4
f: .word 0: 1000
_var_int_0: .space 4
_var_int_arr_0: .word 0: 1
_var_int_1: .space 4
_var_int_arr_1: .word 0: 16
_var_char_0: .space 4
_var_char_arr_0: .word 0: 1
_var_char_1: .space 4
_var_char_arr_1: .word 0: 16
_char: .space 4
$string0: .asciiz "Error in Array & Loop Check!"
$string1: .asciiz "Array & Loop Check Succeed!"
$string2: .asciiz "Arithmetic Check Succeed!"
$string3: .asciiz "Arithmetic Check Failed!"
$string4: .asciiz "Division Check Passed!"
$string5: .asciiz "Error in Division Unit!"
$string6: .asciiz "Value Assignment Succeed!"
$string7: .asciiz "Negative Assignment Failed!"
$string8: .asciiz "Positive Assignment Failed!"
$string9: .asciiz "Basic Assignment Failed!"
$string10: .asciiz "Case Sensitive Detected!"
$string11: .asciiz "Case Insensitive Passed!"
$string12: .asciiz "Error in testing Case Insensitive!"
$string13: .asciiz "Switch Parse Check Succeed!"
$string14: .asciiz "Switch Logic Error!"
$string15: .asciiz "If Statement Error!"
$string16: .asciiz "Passed If Statement Testing!"
$string17: .asciiz ""
$string18: .asciiz "INPUT 0: Basic Test        [Arithmetic, Case Inseneitive, Control Flow Logics]"
$string19: .asciiz "INPUT 1: Value Type Test   [Char Return, Char Operation, Char Conversion, Escape Char]"
$string20: .asciiz "INPUT 2: Structure Test    [Loop, Array, Structures]"
$string21: .asciiz "INPUT 3: Recursive Test    [Permutation, Sequential Sum]"
$string22: .asciiz "INPUT 4: Exit Program"
$string23: .asciiz " "
$string24: .asciiz "Structure Check Succeed!"
$string25: .asciiz "Error In Register Name!"
$string26: .asciiz "The Following Test Should Output 'Hi- 2018'"
$string27: .asciiz "This Test Should Output '\\n\\t\\r~!@#$%^&*`' Rather Than Escape Them"
$string28: .asciiz "#t1"
$string29: .asciiz "$t1"
$string30: .asciiz "INPUT P: Permutation Output"
$string31: .asciiz "INPUT S: Sequential Sum"
$string32: .asciiz "INPUT INT0 INT1: Select INT1 From INT0 To Do Permutation"
$string33: .asciiz "ERROR!"
$string34: .asciiz "INPUT N: Calculate Sum From 1 To N"
$string35: .asciiz "Sequential Sum Result is: "
$string36: .asciiz "Recursive Check Succeed!"
$string37: .asciiz "Error in Recursive Check!"
$string38: .asciiz "Illigal Input Detected!"
$string39: .asciiz "Critical Error Occurred During Testing..."
$string40: .asciiz "Test Passed!"
$string41: .asciiz "Test End"
$enter: .asciiz "\n"
.text
j main
# FUNC, void, , testdo
testdo:
addu $fp, $sp, 0
subi $sp, $sp, 252
# VAR, int, , i
# LI, 0, , i
li $s0, 0
# LAB, , , $label1
#clearReg(3)
$label1:
# SARY, _var_int_arr_1, i, i
sll $s0, $s0, 2
la $t0, _var_int_arr_1
addu $t0, $t0, $s0
sra $s0, $s0, 2
sw $s0, ($t0)
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label0
#clearReg(3)
$label0:
# BGT, i, 15, $label2
li $t0, 15
#clearReg(3)
bgt $s0, $t0, $label2
# JUMP, , , $label1
#clearReg(3)
j $label1
# LAB, , , $label2
#clearReg(3)
$label2:
# LI, 0, , i
li $s0, 0
# LAB, , , $label4
#clearReg(3)
$label4:
# MUL, 2, i, $temp7
li $t0, 2
mult $t0, $s0
mflo $t1
# SUB, $temp7, i, $temp8
subu $t2, $t1, $s0
# LARY, _var_int_arr_1, $temp8, $temp5
sll $t2, $t2, 2
la $t3, _var_int_arr_1
addu $t3, $t3, $t2
sra $t2, $t2, 2
lw $t4, ($t3)
# SUB, 15, i, $temp15
li $t6, 15
subu $t5, $t6, $s0
# LARY, _var_int_arr_1, $temp15, $temp9
sll $t5, $t5, 2
la $t3, _var_int_arr_1
addu $t3, $t3, $t5
sra $t5, $t5, 2
lw $t7, ($t3)
# ADD, $temp5, $temp9, $temp16
addu $t8, $t4, $t7
# SARY, _var_int_arr_1, i, $temp16
sll $s0, $s0, 2
la $t3, _var_int_arr_1
addu $t3, $t3, $s0
sra $s0, $s0, 2
sw $t8, ($t3)
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label3
#clearReg(3)
$label3:
# BGT, i, 15, $label5
li $t0, 15
#clearReg(3)
bgt $s0, $t0, $label5
# JUMP, , , $label4
#clearReg(3)
j $label4
# LAB, , , $label5
#clearReg(3)
$label5:
# LARY, _var_int_arr_1, 1, $temp20
li $t0, 1
sll $t0, $t0, 2
la $t1, _var_int_arr_1
addu $t1, $t1, $t0
sra $t0, $t0, 2
lw $t2, ($t1)
# LARY, _var_int_arr_1, 5, $temp22
li $t3, 5
sll $t3, $t3, 2
la $t1, _var_int_arr_1
addu $t1, $t1, $t3
sra $t3, $t3, 2
lw $t4, ($t1)
# BNE, $temp20, $temp22, $label6
#clearReg(3)
bne $t2, $t4, $label6
# JUMP, , , $label7
#clearReg(3)
j $label7
# LAB, , , $label6
#clearReg(3)
$label6:
# PRT, 1, , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label7
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label7:
# LARY, _var_int_arr_1, 15, $temp25
li $t0, 15
sll $t0, $t0, 2
la $t1, _var_int_arr_1
addu $t1, $t1, $t0
sra $t0, $t0, 2
lw $t2, ($t1)
# BNE, $temp25, 30, $label8
li $t3, 30
#clearReg(3)
bne $t2, $t3, $label8
# PRT, 1, , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label9
#clearReg(3)
j $label9
# LAB, , , $label8
#clearReg(3)
$label8:
# PRT, 1, , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label9
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label9:
# REN, , , 
addi $sp, $sp, 252
jr $ra
# FUNC, void, , testarithmetic
testarithmetic:
addu $fp, $sp, 0
subi $sp, $sp, 224
# CON, int, 100, standard
li $t0, 100
sw $t0, -128($fp)
# CON, int, 10, ten
li $t1, 10
sw $t0, -132($fp)
# VAR, int, , temp
# SUB, 0, -10, $temp31
# ADD, $temp33, -20, $temp37
lw $t2, -156($fp)
addi $t3, $t2, -20
# ADD, $temp37, 16, temp
addi $s0, $t3, 16
# BEQ, temp, 0, $label10
li $t4, 0
#clearReg(3)
sw $t0, -128($fp)
sw $t1, -132($fp)
beq $s0, $t4, $label10
# PRT, 1, , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label11
#clearReg(3)
j $label11
# LAB, , , $label10
#clearReg(3)
$label10:
# PRT, 1, , 3
li $v0, 4
la $a0, $string3
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label11
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label11:
# LI, 11, , temp
li $s0, 11
# BNE, temp, 11, $label12
li $t0, 11
#clearReg(3)
bne $s0, $t0, $label12
# PRT, 1, , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label13
#clearReg(3)
j $label13
# LAB, , , $label12
#clearReg(3)
$label12:
# PRT, 1, , 5
li $v0, 4
la $a0, $string5
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label13
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label13:
# REN, , , 
addi $sp, $sp, 224
jr $ra
# FUNC, void, , testvalue
testvalue:
addu $fp, $sp, 0
subi $sp, $sp, 156
# LI, 0, , $temp49
li $t0, 0
# SUB, 0, $temp49, _var_int_0
li $t2, 0
subu $t1, $t2, $t0
# BNE, _var_int_0, _const_int_0, $label14
la $t4, _const_int_0
lw $t3, 0($t4)
#clearReg(3)
la $t4, _var_int_0
sw $t1, 0($t4)
la $t4, _const_int_0
sw $t3, 0($t4)
bne $t1, $t3, $label14
# BGE, _var_int_0, 1, $label16
la $t1, _var_int_0
lw $t0, 0($t1)
li $t2, 1
#clearReg(3)
la $t1, _var_int_0
sw $t0, 0($t1)
bge $t0, $t2, $label16
# BLE, _var_int_0, -3, $label18
la $t1, _var_int_0
lw $t0, 0($t1)
li $t2, -3
#clearReg(3)
la $t1, _var_int_0
sw $t0, 0($t1)
ble $t0, $t2, $label18
# PRT, 1, , 6
li $v0, 4
la $a0, $string6
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label19
#clearReg(3)
j $label19
# LAB, , , $label18
#clearReg(3)
$label18:
# PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label19
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label19:
# JUMP, , , $label17
#clearReg(3)
j $label17
# LAB, , , $label16
#clearReg(3)
$label16:
# PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label17
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label17:
# JUMP, , , $label15
#clearReg(3)
j $label15
# LAB, , , $label14
#clearReg(3)
$label14:
# PRT, 1, , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label15
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label15:
# REN, , , 
addi $sp, $sp, 156
jr $ra
# FUNC, void, , testcaseinsensitive
testcaseinsensitive:
addu $fp, $sp, 0
subi $sp, $sp, 164
# VAR, int, , temp
# LI, 0, , $temp55
li $t0, 0
# SUB, 0, $temp55, temp
li $t1, 0
subu $s0, $t1, $t0
# LI, 1, , temp
li $s0, 1
# LI, 0, , $temp58
li $t2, 0
# BNE, temp, $temp58, $label21
#clearReg(3)
bne $s0, $t2, $label21
# PRT, 1, , 10
li $v0, 4
la $a0, $string10
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# JUMP, , , $label20
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
j $label20
# LAB, , , $label21
#clearReg(3)
$label21:
# LI, 1, , $temp60
li $t0, 1
# BNE, temp, $temp60, $label22
#clearReg(3)
bne $s0, $t0, $label22
# PRT, 1, , 11
li $v0, 4
la $a0, $string11
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label20
#clearReg(3)
j $label20
# LAB, , , $label22
#clearReg(3)
$label22:
# PRT, 1, , 12
li $v0, 4
la $a0, $string12
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label20
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label20:
# REN, , , 
addi $sp, $sp, 164
jr $ra
# FUNC, void, , testswitch
testswitch:
addu $fp, $sp, 4
subi $sp, $sp, 160
lw $s1, 0($fp)
# PARA, int, , i
# VAR, int, , temp
# LVAR, i, , temp
move $s0, $s1
# LI, 1, , _var_int_1
li $t0, 1
# ADD, temp, -3, $temp63
addi $t1, $s0, -3
# MUL, _var_int_1, 1, $temp64
li $t2, 1
mult $t0, $t2
mflo $t3
# ADD, $temp63, $temp64, $temp65
addu $t4, $t1, $t3
# LI, 1, , $temp66
li $t5, 1
# BNE, $temp65, $temp66, $label24
#clearReg(3)
la $t6, _var_int_1
sw $t0, 0($t6)
sw $t4, -148($fp)
bne $t4, $t5, $label24
# PRT, 1, , 13
li $v0, 4
la $a0, $string13
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label23
#clearReg(3)
j $label23
# LAB, , , $label24
#clearReg(3)
$label24:
# PRT, 1, , 14
li $v0, 4
la $a0, $string14
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# LAB, , , $label23
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label23:
# REN, , , 
addi $sp, $sp, 164
jr $ra
# FUNC, void, , testif
testif:
addu $fp, $sp, 0
subi $sp, $sp, 152
# BEQ, 6, 6, $label25
li $t0, 6
#clearReg(3)
beq $t0, $t0, $label25
# PRT, 1, , 15
li $v0, 4
la $a0, $string15
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# JUMP, , , $label26
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
j $label26
# LAB, , , $label25
#clearReg(3)
$label25:
# PRT, 1, , 16
li $v0, 4
la $a0, $string16
syscall
li $v0, 4
la $a0, $enter
syscall
# LAB, , , $label26
#clearReg(3)
$label26:
# REN, , , 
addi $sp, $sp, 152
jr $ra
# FUNC, void, , calrecursive
calrecursive:
addu $fp, $sp, 8
subi $sp, $sp, 216
lw $s1, 0($fp)
lw $s2, -4($fp)
# PARA, int, , cur_pointer
# PARA, int, , min
# VAR, int, , i
# BNE, cur_pointer, amount, $label27
la $t1, amount
lw $t0, 0($t1)
#clearReg(3)
la $t1, amount
sw $t0, 0($t1)
bne $s1, $t0, $label27
# LI, 0, , $temp74
li $t0, 0
# LARY, f, $temp74, $temp73
sll $t0, $t0, 2
la $t1, f
addu $t1, $t1, $t0
sra $t0, $t0, 2
lw $t2, ($t1)
# PRT, 0, , $temp73
li $v0, 1
move $a0, $t2
syscall
li $v0, 4
la $a0,$enter
syscall
# LI, 1, , i
li $s0, 1
# BGE, i, amount, $label29
la $t1, amount
lw $t3, 0($t1)
#clearReg(3)
la $t1, amount
sw $t3, 0($t1)
bge $s0, $t3, $label29
# LAB, , , $label32
#clearReg(3)
$label32:
# LARY, f, i, $temp76
sll $s0, $s0, 2
la $t0, f
addu $t0, $t0, $s0
sra $s0, $s0, 2
lw $t1, ($t0)
# PRT, 0, , $temp76
li $v0, 1
move $a0, $t1
syscall
li $v0, 4
la $a0,$enter
syscall
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label31
#clearReg(3)
$label31:
# BGE, i, amount, $label33
la $t1, amount
lw $t0, 0($t1)
#clearReg(3)
la $t1, amount
sw $t0, 0($t1)
bge $s0, $t0, $label33
# JUMP, , , $label32
#clearReg(3)
j $label32
# LAB, , , $label33
#clearReg(3)
$label33:
# JUMP, , , $label30
#clearReg(3)
j $label30
# LAB, , , $label29
#clearReg(3)
$label29:
# LAB, , , $label30
#clearReg(3)
$label30:
# PRT, 1, , 17
li $v0, 4
la $a0, $string17
syscall
li $v0, 4
la $a0, $enter
syscall
# REN, , , 
addi $sp, $sp, 224
jr $ra
# JUMP, , , $label28
#clearReg(3)
j $label28
# LAB, , , $label27
#clearReg(3)
$label27:
# LAB, , , $label28
#clearReg(3)
$label28:
# LVAR, min, , i
move $s0, $s2
# ADD, cur_pointer, numbers_to_be_selected, $temp79
la $t1, numbers_to_be_selected
lw $t0, 0($t1)
addu $t2, $s1, $t0
# SUB, $temp79, amount, $temp80
la $t1, amount
lw $t3, 0($t1)
subu $t4, $t2, $t3
# ADD, $temp80, 1, $temp82
addi $t5, $t4, 1
# BGT, i, $temp82, $label34
#clearReg(3)
la $t1, numbers_to_be_selected
sw $t0, 0($t1)
la $t1, amount
sw $t3, 0($t1)
bgt $s0, $t5, $label34
# LAB, , , $label37
#clearReg(3)
$label37:
# SARY, f, cur_pointer, i
sll $s1, $s1, 2
la $t0, f
addu $t0, $t0, $s1
sra $s1, $s1, 2
sw $s0, ($t0)
# ADD, cur_pointer, 1, $temp84
addi $t1, $s1, 1
# PUSH, , , $temp84
sw $t1, ($sp)
subi $sp, $sp, 4
# ADD, i, 1, $temp86
addi $t2, $s0, 1
# PUSH, , , $temp86
sw $t2, ($sp)
subi $sp, $sp, 4
# CALL, , , calrecursive
#clearRegs(1)
sw $s0, -136($fp)
sw $s1, 0($fp)
sw $s2, -4($fp)
sw $t1, -184($fp)
sw $t2, -192($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal calrecursive
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -136($fp)
lw $s1, 0($fp)
lw $s2, -4($fp)
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label36
#clearReg(3)
$label36:
# ADD, cur_pointer, numbers_to_be_selected, $temp89
la $t1, numbers_to_be_selected
lw $t0, 0($t1)
addu $t2, $s1, $t0
# SUB, $temp89, amount, $temp90
la $t1, amount
lw $t3, 0($t1)
subu $t4, $t2, $t3
# ADD, $temp90, 1, $temp92
addi $t5, $t4, 1
# BGT, i, $temp92, $label38
#clearReg(3)
la $t1, numbers_to_be_selected
sw $t0, 0($t1)
la $t1, amount
sw $t3, 0($t1)
bgt $s0, $t5, $label38
# JUMP, , , $label37
#clearReg(3)
j $label37
# LAB, , , $label38
#clearReg(3)
$label38:
# JUMP, , , $label35
#clearReg(3)
j $label35
# LAB, , , $label34
#clearReg(3)
$label34:
# LAB, , , $label35
#clearReg(3)
$label35:
# REN, , , 
addi $sp, $sp, 224
jr $ra
# FUNC, void, , initpermutation
initpermutation:
addu $fp, $sp, 8
subi $sp, $sp, 148
lw $s1, -4($fp)
lw $s2, 0($fp)
# PARA, int, , var
# PARA, int, , lenth
# VAR, int, , i
# LI, 0, , i
li $s0, 0
# LAB, , , $label40
#clearReg(3)
$label40:
# SARY, f, i, var
sll $s0, $s0, 2
la $t0, f
addu $t0, $t0, $s0
sra $s0, $s0, 2
sw $s2, ($t0)
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label39
#clearReg(3)
$label39:
# BGT, i, lenth, $label41
#clearReg(3)
bgt $s0, $s1, $label41
# JUMP, , , $label40
#clearReg(3)
j $label40
# LAB, , , $label41
#clearReg(3)
$label41:
# REN, , , 
addi $sp, $sp, 156
jr $ra
# REN, , , 
addi $sp, $sp, 156
jr $ra
# FUNC, int, , seqsum
seqsum:
addu $fp, $sp, 4
subi $sp, $sp, 156
lw $s0, 0($fp)
# PARA, int, , i
# BNE, i, 1, $label42
li $t0, 1
#clearReg(3)
bne $s0, $t0, $label42
# RET, , , 1
li $v0, 1
addi $sp, $sp, 160
jr $ra
# JUMP, , , $label43
#clearReg(3)
j $label43
# LAB, , , $label42
#clearReg(3)
$label42:
# SUB, i, 1, $temp100
subi $t0, $s0, 1
# PUSH, , , $temp100
sw $t0, ($sp)
subi $sp, $sp, 4
# CALL, , , seqsum
#clearRegs(1)
sw $s0, 0($fp)
sw $t0, -144($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, 0($fp)
# VOF, seqsum, , $temp98
move $t0, $v0
# ADD, i, $temp98, $temp101
addu $t1, $s0, $t0
# RET, , , $temp101
move $v0, $t1
addi $sp, $sp, 160
jr $ra
# LAB, , , $label43
#clearReg(3)
$label43:
# FUNC, void, , printtable
printtable:
addu $fp, $sp, 0
subi $sp, $sp, 132
# PRT, 1, , 18
li $v0, 4
la $a0, $string18
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 19
li $v0, 4
la $a0, $string19
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 20
li $v0, 4
la $a0, $string20
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 21
li $v0, 4
la $a0, $string21
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 22
li $v0, 4
la $a0, $string22
syscall
li $v0, 4
la $a0, $enter
syscall
# REN, , , 
addi $sp, $sp, 132
jr $ra
# FUNC, int, , and
and:
addu $fp, $sp, 8
subi $sp, $sp, 152
lw $s0, 0($fp)
lw $s1, -4($fp)
# PARA, int, , a
# PARA, int, , b
# BNE, b, 4, $label44
li $t0, 4
#clearReg(3)
bne $s1, $t0, $label44
# LI, 0, , $temp103
li $t0, 0
# RET, , , $temp103
move $v0, $t0
addi $sp, $sp, 160
jr $ra
# JUMP, , , $label45
#clearReg(3)
j $label45
# LAB, , , $label44
#clearReg(3)
$label44:
# LI, 0, , $temp104
li $t0, 0
# BNE, a, $temp104, $label46
#clearReg(3)
bne $s0, $t0, $label46
# RET, , , 1
li $v0, 1
addi $sp, $sp, 160
jr $ra
# JUMP, , , $label47
#clearReg(3)
j $label47
# LAB, , , $label46
#clearReg(3)
$label46:
# LI, 0, , $temp106
li $t0, 0
# RET, , , $temp106
move $v0, $t0
addi $sp, $sp, 160
jr $ra
# LAB, , , $label47
#clearReg(3)
$label47:
# LAB, , , $label45
#clearReg(3)
$label45:
# FUNC, char, , helpchar
helpchar:
addu $fp, $sp, 0
subi $sp, $sp, 140
# VAR, char, , temp
# LI, 45, , temp
li $s0, 45
# RET, , , temp
move $v0, $s0
addi $sp, $sp, 140
jr $ra
# FUNC, void, , typecorrosion
typecorrosion:
addu $fp, $sp, 0
subi $sp, $sp, 216
# VAR, int, , temp
# VAR, char, , _char
# LI, 105, , _char
li $s0, 105
# LI, 8, , temp
li $s1, 8
# LI, 72, , $temp110
li $t0, 72
# PRT, 0, , $temp110
li $v0, 11
move $a0, $t0
syscall
li $v0, 4
la $a0,$enter
syscall
# PRT, 0, , _char
li $v0, 11
move $a0, $s0
syscall
li $v0, 4
la $a0,$enter
syscall
# CALL, , , helpchar
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $t0, -144($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal helpchar
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# VOF, helpchar, , $temp111
move $t0, $v0
# PRT, 0, , $temp111
li $v0, 11
move $a0, $t0
syscall
li $v0, 4
la $a0,$enter
syscall
# PRT, 1, , 23
li $v0, 4
la $a0, $string23
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 0, , 2
li $v0, 1
li $a0, 2
syscall
li $v0, 4
la $a0,$enter
syscall
# PRT, 0, , $temp119
li $v0, 1
lw $t1, -180($fp)
move $a0, $t1
syscall
li $v0, 4
la $a0,$enter
syscall
# LI, 99, , $temp120
li $t2, 99
# LI, 97, , $temp121
li $t3, 97
# SUB, $temp120, $temp121, $temp122
subu $t4, $t2, $t3
# LI, 98, , $temp123
li $t5, 98
# LI, 97, , $temp124
li $t6, 97
# SUB, $temp123, $temp124, $temp125
subu $t7, $t5, $t6
# SUB, $temp122, $temp125, $temp126
subu $t8, $t4, $t7
# PRT, 0, , $temp126
li $v0, 1
move $a0, $t8
syscall
li $v0, 4
la $a0,$enter
syscall
# PRT, 0, , temp
li $v0, 1
move $a0, $s1
syscall
li $v0, 4
la $a0,$enter
syscall
# REN, , , 
addi $sp, $sp, 216
jr $ra
# FUNC, void, , testemptyfunction
testemptyfunction:
addu $fp, $sp, 0
subi $sp, $sp, 132
# REN, , , 
addi $sp, $sp, 132
jr $ra
# FUNC, void, , teststructure
teststructure:
addu $fp, $sp, 20
subi $sp, $sp, 184
lw $s0, -8($fp)
lw $s1, 0($fp)
lw $s2, -4($fp)
lw $s3, -12($fp)
lw $s4, -16($fp)
# PARA, int, , a
# PARA, int, , b
# PARA, char, , c
# PARA, char, , d
# PARA, char, , e
# VAR, int, , t1
# VAR, int, , t2
# ADD, a, b, $temp127
addu $t0, $s1, $s2
# ADD, $temp127, d, $temp128
addu $t1, $t0, $s3
# SUB, $temp128, c, $temp129
subu $t2, $t1, $s0
# SUB, c, e, $temp130
subu $t3, $s0, $s4
# SUB, $temp129, $temp130, $temp131
subu $t4, $t2, $t3
# LI, 66666, , $temp132
li $t5, 66666
# BNE, $temp131, $temp132, $label49
#clearReg(3)
sw $t4, -172($fp)
bne $t4, $t5, $label49
# PRT, 1, , 24
li $v0, 4
la $a0, $string24
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 0, , t1
li $s5, 0
# LI, 0, , t2
li $s6, 0
# JUMP, , , $label48
#clearReg(3)
j $label48
# LAB, , , $label49
#clearReg(3)
$label49:
# LI, 0, , $temp135
li $t0, 0
# BNE, $temp131, $temp135, $label50
lw $t1, -172($fp)
#clearReg(3)
sw $t1, -172($fp)
bne $t1, $t0, $label50
# PRT, 1, , 25
li $v0, 4
la $a0, $string25
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 1, , error
li $t0, 1
# JUMP, , , $label48
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
j $label48
# LAB, , , $label50
#clearReg(3)
$label50:
# LI, 1, , error
li $t0, 1
# LAB, , , $label48
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label48:
# REN, , , 
addi $sp, $sp, 204
jr $ra
# FUNC, void, , main
main:
addu $fp, $sp, 0
subi $sp, $sp, 268
# VAR, char, , choice
# VAR, int, , select
# LI, 0, , error
li $t0, 0
# LI, 48, , _char
li $t1, 48
# LAB, , , $label52
#clearReg(3)
la $t2, error
sw $t0, 0($t2)
la $t2, _char
sw $t1, 0($t2)
$label52:
# CALL, , , printtable
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal printtable
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# READ, , , select
li $v0, 5
syscall
move $s0, $v0
# LI, 0, , $temp140
li $t0, 0
# BNE, select, $temp140, $label55
#clearReg(3)
bne $s0, $t0, $label55
# CALL, , , testvalue
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testvalue
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# CALL, , , testarithmetic
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testarithmetic
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# CALL, , , testif
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testif
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# SUB, 0, -3, $temp144
# PUSH, , , 3
li $t0, 3
sw $t0, ($sp)
subi $sp, $sp, 4
# CALL, , , testswitch
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testswitch
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# JUMP, , , $label54
#clearReg(3)
j $label54
# LAB, , , $label55
#clearReg(3)
$label55:
# LI, 1, , $temp145
li $t0, 1
# BNE, select, $temp145, $label56
#clearReg(3)
bne $s0, $t0, $label56
# PRT, 1, , 26
li $v0, 4
la $a0, $string26
syscall
li $v0, 4
la $a0, $enter
syscall
# CALL, , , typecorrosion
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal typecorrosion
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# PRT, 1, , 27
li $v0, 4
la $a0, $string27
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 28
li $v0, 4
la $a0, $string28
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 29
li $v0, 4
la $a0, $string29
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label54
#clearReg(3)
j $label54
# LAB, , , $label56
#clearReg(3)
$label56:
# LI, 2, , $temp146
li $t0, 2
# BNE, select, $temp146, $label57
#clearReg(3)
bne $s0, $t0, $label57
# LI, 49, , _var_char_0
li $t0, 49
# LI, 50, , _var_char_1
li $t1, 50
# LI, 12345, , _var_int_0
li $t2, 12345
# LI, 54321, , _var_int_1
li $t3, 54321
# CALL, , , testdo
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
la $t4, _var_char_0
sw $t0, 0($t4)
la $t4, _var_char_1
sw $t1, 0($t4)
la $t4, _var_int_0
sw $t2, 0($t4)
la $t4, _var_int_1
sw $t3, 0($t4)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testdo
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# CALL, , , testemptyfunction
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testemptyfunction
lw $fp ,-120($sp)
lw $ra ,-124($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# PUSH, , , _var_int_0
la $t1, _var_int_0
lw $t0, 0($t1)
sw $t0, ($sp)
subi $sp, $sp, 4
# PUSH, , , _var_int_1
la $t1, _var_int_1
lw $t2, 0($t1)
sw $t2, ($sp)
subi $sp, $sp, 4
# PUSH, , , _var_char_0
la $t1, _var_char_0
lw $t3, 0($t1)
sw $t3, ($sp)
subi $sp, $sp, 4
# PUSH, , , _var_char_1
la $t1, _var_char_1
lw $t4, 0($t1)
sw $t4, ($sp)
subi $sp, $sp, 4
# PUSH, , , _char
la $t1, _char
lw $t5, 0($t1)
sw $t5, ($sp)
subi $sp, $sp, 4
# CALL, , , teststructure
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
la $t1, _var_int_0
sw $t0, 0($t1)
la $t1, _var_int_1
sw $t2, 0($t1)
la $t1, _var_char_0
sw $t3, 0($t1)
la $t1, _var_char_1
sw $t4, 0($t1)
la $t1, _char
sw $t5, 0($t1)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal teststructure
lw $fp ,-140($sp)
lw $ra ,-144($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# JUMP, , , $label54
#clearReg(3)
j $label54
# LAB, , , $label57
#clearReg(3)
$label57:
# LI, 3, , $temp151
li $t0, 3
# BNE, select, $temp151, $label58
#clearReg(3)
bne $s0, $t0, $label58
# PRT, 1, , 30
li $v0, 4
la $a0, $string30
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 31
li $v0, 4
la $a0, $string31
syscall
li $v0, 4
la $a0, $enter
syscall
# READ, , , choice
li $v0, 12
syscall
move $s1, $v0
# LI, 80, , $temp152
li $t0, 80
# BNE, choice, $temp152, $label60
#clearReg(3)
bne $s1, $t0, $label60
# PRT, 1, , 32
li $v0, 4
la $a0, $string32
syscall
li $v0, 4
la $a0, $enter
syscall
# READ, , , numbers_to_be_selected
li $v0, 5
syscall
move $t0, $v0
# READ, , , amount
li $v0, 5
syscall
move $t1, $v0
# PRT, 1, , 17
li $v0, 4
la $a0, $string17
syscall
li $v0, 4
la $a0, $enter
syscall
# ADD, amount, 1, $temp154
addi $t2, $t1, 1
# BLE, $temp154, 1000, $label61
li $t3, 1000
#clearReg(3)
la $t4, numbers_to_be_selected
sw $t0, 0($t4)
la $t4, amount
sw $t1, 0($t4)
ble $t2, $t3, $label61
# PRT, 1, , 33
li $v0, 4
la $a0, $string33
syscall
li $v0, 4
la $a0, $enter
syscall
# REN, , , 
li $v0,10
syscall
# JUMP, , , $label62
#clearReg(3)
j $label62
# LAB, , , $label61
#clearReg(3)
$label61:
# LAB, , , $label62
#clearReg(3)
$label62:
# LI, 0, , $temp155
li $t0, 0
# PUSH, , , $temp155
sw $t0, ($sp)
subi $sp, $sp, 4
# ADD, amount, 1, $temp157
la $t2, amount
lw $t1, 0($t2)
addi $t3, $t1, 1
# PUSH, , , $temp157
sw $t3, ($sp)
subi $sp, $sp, 4
# CALL, , , initpermutation
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $t0, -204($fp)
la $t2, amount
sw $t1, 0($t2)
sw $t3, -212($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal initpermutation
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# LI, 0, , $temp158
li $t0, 0
# PUSH, , , $temp158
sw $t0, ($sp)
subi $sp, $sp, 4
# PUSH, , , 1
li $t1, 1
sw $t1, ($sp)
subi $sp, $sp, 4
# CALL, , , calrecursive
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $t0, -216($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal calrecursive
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# JUMP, , , $label59
#clearReg(3)
j $label59
# LAB, , , $label60
#clearReg(3)
$label60:
# LI, 83, , $temp160
li $t0, 83
# BNE, choice, $temp160, $label63
#clearReg(3)
bne $s1, $t0, $label63
# PRT, 1, , 34
li $v0, 4
la $a0, $string34
syscall
li $v0, 4
la $a0, $enter
syscall
# READ, , , select
li $v0, 5
syscall
move $s0, $v0
# PUSH, , , select
sw $s0, ($sp)
subi $sp, $sp, 4
# CALL, , , seqsum
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# VOF, seqsum, , $temp161
move $t0, $v0
# PRT, 2, 35, $temp161
li $v0, 4
la $a0, $string35
syscall
li $v0, 1
move $a0, $t0
syscall
li $v0, 4
la $a0, $enter
syscall
# PUSH, , , 10
li $t1, 10
sw $t1, ($sp)
subi $sp, $sp, 4
# CALL, , , seqsum
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
sw $t0, -228($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# VOF, seqsum, , $temp162
move $t0, $v0
# BNE, $temp162, 55, $label64
li $t1, 55
#clearReg(3)
bne $t0, $t1, $label64
# PRT, 1, , 36
li $v0, 4
la $a0, $string36
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label65
#clearReg(3)
j $label65
# LAB, , , $label64
#clearReg(3)
$label64:
# LI, 1, , error
li $t0, 1
# PRT, 1, , 37
li $v0, 4
la $a0, $string37
syscall
li $v0, 4
la $a0, $enter
syscall
# LAB, , , $label65
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
$label65:
# LI, 3, , select
li $s0, 3
# JUMP, , , $label59
#clearReg(3)
j $label59
# LAB, , , $label63
#clearReg(3)
$label63:
# PRT, 1, , 38
li $v0, 4
la $a0, $string38
syscall
li $v0, 4
la $a0, $enter
syscall
# LAB, , , $label59
#clearReg(3)
$label59:
# JUMP, , , $label54
#clearReg(3)
j $label54
# LAB, , , $label58
#clearReg(3)
$label58:
# LI, 4, , $temp167
li $t0, 4
# BNE, select, $temp167, $label66
#clearReg(3)
bne $s0, $t0, $label66
# JUMP, , , $label54
#clearReg(3)
j $label54
# LAB, , , $label66
#clearReg(3)
$label66:
# PRT, 1, , 38
li $v0, 4
la $a0, $string38
syscall
li $v0, 4
la $a0, $enter
syscall
# LAB, , , $label54
#clearReg(3)
$label54:
# LAB, , , $label51
#clearReg(3)
$label51:
# PUSH, , , error
la $t1, error
lw $t0, 0($t1)
sw $t0, ($sp)
subi $sp, $sp, 4
# PUSH, , , select
sw $s0, ($sp)
subi $sp, $sp, 4
# CALL, , , and
#clearRegs(1)
sw $s0, -132($fp)
sw $s1, -128($fp)
la $t1, error
sw $t0, 0($t1)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal and
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -132($fp)
lw $s1, -128($fp)
# VOF, and, , $temp168
move $t0, $v0
# BEQ, $temp168, 0, $label53
li $t1, 0
#clearReg(3)
beq $t0, $t1, $label53
# JUMP, , , $label52
#clearReg(3)
j $label52
# LAB, , , $label53
#clearReg(3)
$label53:
# BLT, error, 1, $label67
la $t1, error
lw $t0, 0($t1)
li $t2, 1
#clearReg(3)
la $t1, error
sw $t0, 0($t1)
blt $t0, $t2, $label67
# PRT, 1, , 39
li $v0, 4
la $a0, $string39
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label68
#clearReg(3)
j $label68
# LAB, , , $label67
#clearReg(3)
$label67:
# PRT, 1, , 40
li $v0, 4
la $a0, $string40
syscall
li $v0, 4
la $a0, $enter
syscall
# LAB, , , $label68
#clearReg(3)
$label68:
# PRT, 1, , 41
li $v0, 4
la $a0, $string41
syscall
li $v0, 4
la $a0, $enter
syscall
