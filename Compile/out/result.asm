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
#FUNC, void, , testdo
testdo:
add $fp, $sp, 0
subi $sp, $sp, 260
#VAR, int, , i
#LI, 0, , $temp0
li $t0, 0
sw $t0, -132($fp)
#LVAR, $temp0, , i
lw $t0, -132($fp)
move $t2, $t0
#LAB, , , $label1
$label1:
#LVAR, i, , $temp1
move $t0, $t2
sw $t0, -136($fp)
#LVAR, i, , $temp2
move $t0, $t2
sw $t0, -140($fp)
#SARY, _var_int_arr_1, $temp1, $temp2
lw $t0, -136($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t1, -140($fp)
sw $t1, ($t0)
#LVAR, i, , $temp3
move $t0, $t2
sw $t0, -144($fp)
#LI, 1, , $temp4
li $t0, 1
sw $t0, -148($fp)
#ADD, $temp3, $temp4, $temp3
lw $t0, -144($fp)
lw $t1, -148($fp)
add $t0, $t0, $t1
sw $t0, -144($fp)
#LVAR, $temp3, , i
lw $t0, -144($fp)
move $t2, $t0
#LAB, , , $label0
$label0:
#LVAR, i, , $temp5
move $t0, $t2
sw $t0, -152($fp)
#LI, 15, , $temp6
li $t0, 15
sw $t0, -156($fp)
#BGT, $temp5, $temp6, $label2
lw $t0, -152($fp)
lw $t1, -156($fp)
bgt $t0, $t1, $label2
#JUMP, , , $label1
j $label1
#LAB, , , $label2
$label2:
#LI, 0, , $temp7
li $t0, 0
sw $t0, -160($fp)
#LVAR, $temp7, , i
lw $t0, -160($fp)
move $t2, $t0
#LAB, , , $label4
$label4:
#LVAR, i, , $temp8
move $t0, $t2
sw $t0, -164($fp)
#VAR, int, , $temp9
#LI, 2, , $temp10
li $t0, 2
sw $t0, -172($fp)
#LVAR, i, , $temp11
move $t0, $t2
sw $t0, -176($fp)
#MUL, $temp10, $temp11, $temp10
lw $t0, -172($fp)
lw $t1, -176($fp)
mult $t0, $t1
mflo $t0
sw $t0, -172($fp)
#LVAR, i, , $temp12
move $t0, $t2
sw $t0, -180($fp)
#SUB, $temp10, $temp12, $temp10
lw $t0, -172($fp)
lw $t1, -180($fp)
sub $t0, $t0, $t1
sw $t0, -172($fp)
#LARY, _var_int_arr_1, $temp10, $temp9
lw $t0, -172($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -168($fp)
#VAR, int, , $temp13
#LI, 9, , $temp14
li $t0, 9
sw $t0, -188($fp)
#LI, 2, , $temp15
li $t0, 2
sw $t0, -192($fp)
#LI, 3, , $temp16
li $t0, 3
sw $t0, -196($fp)
#MUL, $temp15, $temp16, $temp15
lw $t0, -192($fp)
lw $t1, -196($fp)
mult $t0, $t1
mflo $t0
sw $t0, -192($fp)
#ADD, $temp14, $temp15, $temp14
lw $t0, -188($fp)
lw $t1, -192($fp)
add $t0, $t0, $t1
sw $t0, -188($fp)
#LVAR, i, , $temp17
move $t0, $t2
sw $t0, -200($fp)
#SUB, $temp14, $temp17, $temp14
lw $t0, -188($fp)
lw $t1, -200($fp)
sub $t0, $t0, $t1
sw $t0, -188($fp)
#LARY, _var_int_arr_1, $temp14, $temp13
lw $t0, -188($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -184($fp)
#ADD, $temp9, $temp13, $temp9
lw $t0, -168($fp)
lw $t1, -184($fp)
add $t0, $t0, $t1
sw $t0, -168($fp)
#SARY, _var_int_arr_1, $temp8, $temp9
lw $t0, -164($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t1, -168($fp)
sw $t1, ($t0)
#LVAR, i, , $temp18
move $t0, $t2
sw $t0, -204($fp)
#LI, 1, , $temp19
li $t0, 1
sw $t0, -208($fp)
#ADD, $temp18, $temp19, $temp18
lw $t0, -204($fp)
lw $t1, -208($fp)
add $t0, $t0, $t1
sw $t0, -204($fp)
#LVAR, $temp18, , i
lw $t0, -204($fp)
move $t2, $t0
#LAB, , , $label3
$label3:
#LVAR, i, , $temp20
move $t0, $t2
sw $t0, -212($fp)
#LI, 15, , $temp21
li $t0, 15
sw $t0, -216($fp)
#BGT, $temp20, $temp21, $label5
lw $t0, -212($fp)
lw $t1, -216($fp)
bgt $t0, $t1, $label5
#JUMP, , , $label4
j $label4
#LAB, , , $label5
$label5:
#VAR, int, , $temp22
#LI, 1, , $temp23
li $t0, 1
sw $t0, -224($fp)
#LARY, _var_int_arr_1, $temp23, $temp22
lw $t0, -224($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -220($fp)
#VAR, int, , $temp24
#LI, 5, , $temp25
li $t0, 5
sw $t0, -232($fp)
#LARY, _var_int_arr_1, $temp25, $temp24
lw $t0, -232($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -228($fp)
#BNE, $temp22, $temp24, $label6
lw $t0, -220($fp)
lw $t1, -228($fp)
bne $t0, $t1, $label6
#JUMP, , , $label7
j $label7
#LAB, , , $label6
$label6:
#PRT, 1, , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp26
li $t0, 1
sw $t0, -236($fp)
#LVAR, $temp26, , error
lw $t0, -236($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label7
$label7:
#VAR, int, , $temp27
#LI, 15, , $temp28
li $t0, 15
sw $t0, -244($fp)
#LARY, _var_int_arr_1, $temp28, $temp27
lw $t0, -244($fp)
mul $t0, $t0, 4
la $t1, _var_int_arr_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -240($fp)
#LI, 30, , $temp29
li $t0, 30
sw $t0, -248($fp)
#BNE, $temp27, $temp29, $label8
lw $t0, -240($fp)
lw $t1, -248($fp)
bne $t0, $t1, $label8
#PRT, 1, , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label9
j $label9
#LAB, , , $label8
$label8:
#PRT, 1, , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp30
li $t0, 1
sw $t0, -252($fp)
#LVAR, $temp30, , error
lw $t0, -252($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label9
$label9:
#REN, , , 
addi $sp, $sp, 260
jr $ra
#FUNC, void, , testarithmetic
testarithmetic:
add $fp, $sp, 0
subi $sp, $sp, 240
#CON, int, 100, standard
li $t2, 100
#CON, int, 10, ten
li $t3, 10
#VAR, int, , temp
#LI, -10, , $temp31
li $t0, -10
sw $t0, -140($fp)
#LI, 0, , $temp32
li $t0, 0
sw $t0, -144($fp)
#SUB, $temp32, $temp31, $temp31
lw $t0, -144($fp)
lw $t1, -140($fp)
sub $t0, $t0, $t1
sw $t0, -140($fp)
#LI, 10, , $temp33
li $t0, 10
sw $t0, -148($fp)
#SUB, $temp31, $temp33, $temp31
lw $t0, -140($fp)
lw $t1, -148($fp)
sub $t0, $t0, $t1
sw $t0, -140($fp)
#LVAR, ten, , $temp34
move $t0, $t3
sw $t0, -152($fp)
#LVAR, _const_char_1, , $temp35
la $t1, _const_char_1
lw $t0, 0($t1)
sw $t0, -156($fp)
#LVAR, _const_char_0, , $temp36
la $t1, _const_char_0
lw $t0, 0($t1)
sw $t0, -160($fp)
#SUB, $temp35, $temp36, $temp35
lw $t0, -156($fp)
lw $t1, -160($fp)
sub $t0, $t0, $t1
sw $t0, -156($fp)
#MUL, $temp34, $temp35, $temp34
lw $t0, -152($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -152($fp)
#LVAR, _const_int_2, , $temp37
la $t1, _const_int_2
lw $t0, 0($t1)
sw $t0, -168($fp)
#DIV, $temp34, $temp37, $temp34
lw $t0, -152($fp)
lw $t1, -168($fp)
div $t0, $t1
mflo $t0
sw $t0, -152($fp)
#ADD, $temp31, $temp34, $temp31
lw $t0, -140($fp)
lw $t1, -152($fp)
add $t0, $t0, $t1
sw $t0, -140($fp)
#LVAR, standard, , $temp38
move $t0, $t2
sw $t0, -172($fp)
#LVAR, ten, , $temp39
move $t0, $t3
sw $t0, -176($fp)
#LVAR, _const_int_2, , $temp40
la $t1, _const_int_2
lw $t0, 0($t1)
sw $t0, -180($fp)
#ADD, $temp39, $temp40, $temp39
lw $t0, -176($fp)
lw $t1, -180($fp)
add $t0, $t0, $t1
sw $t0, -176($fp)
#LVAR, _const_int_1, , $temp41
la $t1, _const_int_1
lw $t0, 0($t1)
sw $t0, -184($fp)
#SUB, $temp39, $temp41, $temp39
lw $t0, -176($fp)
lw $t1, -184($fp)
sub $t0, $t0, $t1
sw $t0, -176($fp)
#DIV, $temp38, $temp39, $temp38
lw $t0, -172($fp)
lw $t1, -176($fp)
div $t0, $t1
mflo $t0
sw $t0, -172($fp)
#ADD, $temp31, $temp38, $temp31
lw $t0, -140($fp)
lw $t1, -172($fp)
add $t0, $t0, $t1
sw $t0, -140($fp)
#LVAR, $temp31, , temp
lw $t0, -140($fp)
move $t4, $t0
#LVAR, temp, , $temp42
move $t0, $t4
sw $t0, -192($fp)
#LI, 0, , $temp43
li $t0, 0
sw $t0, -196($fp)
#BEQ, $temp42, $temp43, $label10
lw $t0, -192($fp)
lw $t1, -196($fp)
beq $t0, $t1, $label10
#PRT, 1, , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label11
j $label11
#LAB, , , $label10
$label10:
#PRT, 1, , 3
li $v0, 4
la $a0, $string3
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp44
li $t0, 1
sw $t0, -200($fp)
#LVAR, $temp44, , error
lw $t0, -200($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label11
$label11:
#LVAR, standard, , $temp45
move $t0, $t2
sw $t0, -204($fp)
#LVAR, _const_int_1, , $temp46
la $t1, _const_int_1
lw $t0, 0($t1)
sw $t0, -208($fp)
#LI, 15, , $temp47
li $t0, 15
sw $t0, -212($fp)
#MUL, $temp46, $temp47, $temp46
lw $t0, -208($fp)
lw $t1, -212($fp)
mult $t0, $t1
mflo $t0
sw $t0, -208($fp)
#ADD, $temp45, $temp46, $temp45
lw $t0, -204($fp)
lw $t1, -208($fp)
add $t0, $t0, $t1
sw $t0, -204($fp)
#LVAR, ten, , $temp48
move $t0, $t3
sw $t0, -220($fp)
#DIV, $temp45, $temp48, $temp45
lw $t0, -204($fp)
lw $t1, -220($fp)
div $t0, $t1
mflo $t0
sw $t0, -204($fp)
#LVAR, $temp45, , temp
lw $t0, -204($fp)
move $t4, $t0
#LVAR, temp, , $temp49
move $t0, $t4
sw $t0, -224($fp)
#LI, 11, , $temp50
li $t0, 11
sw $t0, -228($fp)
#BNE, $temp49, $temp50, $label12
lw $t0, -224($fp)
lw $t1, -228($fp)
bne $t0, $t1, $label12
#PRT, 1, , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label13
j $label13
#LAB, , , $label12
$label12:
#PRT, 1, , 5
li $v0, 4
la $a0, $string5
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp51
li $t0, 1
sw $t0, -232($fp)
#LVAR, $temp51, , error
lw $t0, -232($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label13
$label13:
#REN, , , 
addi $sp, $sp, 240
jr $ra
#FUNC, void, , testvalue
testvalue:
add $fp, $sp, 0
subi $sp, $sp, 176
#LI, 0, , $temp52
li $t0, 0
sw $t0, -128($fp)
#LI, 0, , $temp53
li $t0, 0
sw $t0, -132($fp)
#SUB, $temp53, $temp52, $temp52
lw $t0, -132($fp)
lw $t1, -128($fp)
sub $t0, $t0, $t1
sw $t0, -128($fp)
#LVAR, $temp52, , _var_int_0
lw $t0, -128($fp)
la $t1, _var_int_0
sw $t0, 0($t1)
#LVAR, _var_int_0, , $temp54
la $t1, _var_int_0
lw $t0, 0($t1)
sw $t0, -136($fp)
#LVAR, _const_int_0, , $temp55
la $t1, _const_int_0
lw $t0, 0($t1)
sw $t0, -140($fp)
#BNE, $temp54, $temp55, $label14
lw $t0, -136($fp)
lw $t1, -140($fp)
bne $t0, $t1, $label14
#LVAR, _var_int_0, , $temp56
la $t1, _var_int_0
lw $t0, 0($t1)
sw $t0, -144($fp)
#LVAR, _const_int_1, , $temp57
la $t1, _const_int_1
lw $t0, 0($t1)
sw $t0, -148($fp)
#BGE, $temp56, $temp57, $label16
lw $t0, -144($fp)
lw $t1, -148($fp)
bge $t0, $t1, $label16
#LVAR, _var_int_0, , $temp58
la $t1, _var_int_0
lw $t0, 0($t1)
sw $t0, -152($fp)
#LVAR, _const_int_2, , $temp59
la $t1, _const_int_2
lw $t0, 0($t1)
sw $t0, -156($fp)
#BLE, $temp58, $temp59, $label18
lw $t0, -152($fp)
lw $t1, -156($fp)
ble $t0, $t1, $label18
#PRT, 1, , 6
li $v0, 4
la $a0, $string6
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label19
j $label19
#LAB, , , $label18
$label18:
#PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp60
li $t0, 1
sw $t0, -160($fp)
#LVAR, $temp60, , error
lw $t0, -160($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label19
$label19:
#JUMP, , , $label17
j $label17
#LAB, , , $label16
$label16:
#PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp61
li $t0, 1
sw $t0, -164($fp)
#LVAR, $temp61, , error
lw $t0, -164($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label17
$label17:
#JUMP, , , $label15
j $label15
#LAB, , , $label14
$label14:
#PRT, 1, , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp62
li $t0, 1
sw $t0, -168($fp)
#LVAR, $temp62, , error
lw $t0, -168($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label15
$label15:
#REN, , , 
addi $sp, $sp, 176
jr $ra
#FUNC, void, , testcaseinsensitive
testcaseinsensitive:
add $fp, $sp, 0
subi $sp, $sp, 168
#VAR, int, , temp
#LI, 0, , $temp63
li $t0, 0
sw $t0, -132($fp)
#LI, 0, , $temp64
li $t0, 0
sw $t0, -136($fp)
#SUB, $temp64, $temp63, $temp63
lw $t0, -136($fp)
lw $t1, -132($fp)
sub $t0, $t0, $t1
sw $t0, -132($fp)
#LVAR, $temp63, , temp
lw $t0, -132($fp)
move $t2, $t0
#LVAR, _const_int_1, , $temp65
la $t1, _const_int_1
lw $t0, 0($t1)
sw $t0, -140($fp)
#LVAR, $temp65, , temp
lw $t0, -140($fp)
move $t2, $t0
#LVAR, temp, , $temp66
move $t0, $t2
sw $t0, -144($fp)
#LI, 0, , $temp67
li $t0, 0
sw $t0, -148($fp)
#BNE, $temp66, $temp67, $label21
lw $t0, -144($fp)
lw $t1, -148($fp)
bne $t0, $t1, $label21
#PRT, 1, , 10
li $v0, 4
la $a0, $string10
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp68
li $t0, 1
sw $t0, -152($fp)
#LVAR, $temp68, , error
lw $t0, -152($fp)
la $t1, error
sw $t0, 0($t1)
#JUMP, , , $label20
j $label20
#LAB, , , $label21
$label21:
#LI, 1, , $temp69
li $t0, 1
sw $t0, -156($fp)
#BNE, $temp66, $temp69, $label22
lw $t0, -144($fp)
lw $t1, -156($fp)
bne $t0, $t1, $label22
#PRT, 1, , 11
li $v0, 4
la $a0, $string11
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label20
j $label20
#LAB, , , $label22
$label22:
#PRT, 1, , 12
li $v0, 4
la $a0, $string12
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp70
li $t0, 1
sw $t0, -160($fp)
#LVAR, $temp70, , error
lw $t0, -160($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label20
$label20:
#REN, , , 
addi $sp, $sp, 168
jr $ra
#FUNC, void, , testswitch
testswitch:
add $fp, $sp, 4
subi $sp, $sp, 168
#PARA, int, , i
#VAR, int, , temp
#LVAR, i, , $temp71
lw $t0, 0($fp)
sw $t0, -136($fp)
#LVAR, $temp71, , temp
lw $t0, -136($fp)
move $t2, $t0
#LI, 1, , $temp72
li $t0, 1
sw $t0, -140($fp)
#LVAR, $temp72, , _var_int_1
lw $t0, -140($fp)
la $t1, _var_int_1
sw $t0, 0($t1)
#LVAR, temp, , $temp73
move $t0, $t2
sw $t0, -144($fp)
#LVAR, _const_int_2, , $temp74
la $t1, _const_int_2
lw $t0, 0($t1)
sw $t0, -148($fp)
#ADD, $temp73, $temp74, $temp73
lw $t0, -144($fp)
lw $t1, -148($fp)
add $t0, $t0, $t1
sw $t0, -144($fp)
#LVAR, _var_int_1, , $temp75
la $t1, _var_int_1
lw $t0, 0($t1)
sw $t0, -152($fp)
#LVAR, _const_int_1, , $temp76
la $t1, _const_int_1
lw $t0, 0($t1)
sw $t0, -156($fp)
#MUL, $temp75, $temp76, $temp75
lw $t0, -152($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -152($fp)
#ADD, $temp73, $temp75, $temp73
lw $t0, -144($fp)
lw $t1, -152($fp)
add $t0, $t0, $t1
sw $t0, -144($fp)
#LI, 1, , $temp77
li $t0, 1
sw $t0, -160($fp)
#BNE, $temp73, $temp77, $label24
lw $t0, -144($fp)
lw $t1, -160($fp)
bne $t0, $t1, $label24
#PRT, 1, , 13
li $v0, 4
la $a0, $string13
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label23
j $label23
#LAB, , , $label24
$label24:
#PRT, 1, , 14
li $v0, 4
la $a0, $string14
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp78
li $t0, 1
sw $t0, -164($fp)
#LVAR, $temp78, , error
lw $t0, -164($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label23
$label23:
#REN, , , 
addi $sp, $sp, 172
jr $ra
#FUNC, void, , testif
testif:
add $fp, $sp, 0
subi $sp, $sp, 152
#LVAR, _const_char_1, , $temp79
la $t1, _const_char_1
lw $t0, 0($t1)
sw $t0, -128($fp)
#LVAR, _const_char_0, , $temp80
la $t1, _const_char_0
lw $t0, 0($t1)
sw $t0, -132($fp)
#SUB, $temp79, $temp80, $temp79
lw $t0, -128($fp)
lw $t1, -132($fp)
sub $t0, $t0, $t1
sw $t0, -128($fp)
#LI, 2, , $temp81
li $t0, 2
sw $t0, -136($fp)
#LI, 3, , $temp82
li $t0, 3
sw $t0, -140($fp)
#MUL, $temp81, $temp82, $temp81
lw $t0, -136($fp)
lw $t1, -140($fp)
mult $t0, $t1
mflo $t0
sw $t0, -136($fp)
#BEQ, $temp79, $temp81, $label25
lw $t0, -128($fp)
lw $t1, -136($fp)
beq $t0, $t1, $label25
#PRT, 1, , 15
li $v0, 4
la $a0, $string15
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp83
li $t0, 1
sw $t0, -144($fp)
#LVAR, $temp83, , error
lw $t0, -144($fp)
la $t1, error
sw $t0, 0($t1)
#JUMP, , , $label26
j $label26
#LAB, , , $label25
$label25:
#PRT, 1, , 16
li $v0, 4
la $a0, $string16
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label26
$label26:
#REN, , , 
addi $sp, $sp, 152
jr $ra
#FUNC, void, , calrecursive
calrecursive:
add $fp, $sp, 8
subi $sp, $sp, 264
#PARA, int, , cur_pointer
#PARA, int, , min
#VAR, int, , i
#LVAR, cur_pointer, , $temp84
lw $t0, 0($fp)
sw $t0, -140($fp)
#LVAR, amount, , $temp85
la $t1, amount
lw $t0, 0($t1)
sw $t0, -144($fp)
#BNE, $temp84, $temp85, $label27
lw $t0, -140($fp)
lw $t1, -144($fp)
bne $t0, $t1, $label27
#VAR, int, , $temp86
#LI, 0, , $temp87
li $t0, 0
sw $t0, -152($fp)
#LARY, f, $temp87, $temp86
lw $t0, -152($fp)
mul $t0, $t0, 4
la $t1, f
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -148($fp)
#PRT, 0, , $temp86
li $v0, 1
lw $a0, -148($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp88
li $t0, 1
sw $t0, -156($fp)
#LVAR, $temp88, , i
lw $t0, -156($fp)
move $t2, $t0
#LVAR, i, , $temp89
move $t0, $t2
sw $t0, -160($fp)
#LVAR, amount, , $temp90
la $t1, amount
lw $t0, 0($t1)
sw $t0, -164($fp)
#BGE, $temp89, $temp90, $label29
lw $t0, -160($fp)
lw $t1, -164($fp)
bge $t0, $t1, $label29
#LAB, , , $label32
$label32:
#VAR, int, , $temp91
#LVAR, i, , $temp92
move $t0, $t2
sw $t0, -172($fp)
#LARY, f, $temp92, $temp91
lw $t0, -172($fp)
mul $t0, $t0, 4
la $t1, f
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -168($fp)
#PRT, 0, , $temp91
li $v0, 1
lw $a0, -168($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, i, , $temp93
move $t0, $t2
sw $t0, -176($fp)
#LI, 1, , $temp94
li $t0, 1
sw $t0, -180($fp)
#ADD, $temp93, $temp94, $temp93
lw $t0, -176($fp)
lw $t1, -180($fp)
add $t0, $t0, $t1
sw $t0, -176($fp)
#LVAR, $temp93, , i
lw $t0, -176($fp)
move $t2, $t0
#LAB, , , $label31
$label31:
#LVAR, i, , $temp95
move $t0, $t2
sw $t0, -184($fp)
#LVAR, amount, , $temp96
la $t1, amount
lw $t0, 0($t1)
sw $t0, -188($fp)
#BGE, $temp95, $temp96, $label33
lw $t0, -184($fp)
lw $t1, -188($fp)
bge $t0, $t1, $label33
#JUMP, , , $label32
j $label32
#LAB, , , $label33
$label33:
#JUMP, , , $label30
j $label30
#LAB, , , $label29
$label29:
#LAB, , , $label30
$label30:
#PRT, 1, , 17
li $v0, 4
la $a0, $string17
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 272
jr $ra
#JUMP, , , $label28
j $label28
#LAB, , , $label27
$label27:
#LAB, , , $label28
$label28:
#LVAR, min, , $temp97
lw $t0, -4($fp)
sw $t0, -192($fp)
#LVAR, $temp97, , i
lw $t0, -192($fp)
move $t2, $t0
#LVAR, i, , $temp98
move $t0, $t2
sw $t0, -196($fp)
#LVAR, cur_pointer, , $temp99
lw $t0, 0($fp)
sw $t0, -200($fp)
#LVAR, numbers_to_be_selected, , $temp100
la $t1, numbers_to_be_selected
lw $t0, 0($t1)
sw $t0, -204($fp)
#ADD, $temp99, $temp100, $temp99
lw $t0, -200($fp)
lw $t1, -204($fp)
add $t0, $t0, $t1
sw $t0, -200($fp)
#LVAR, amount, , $temp101
la $t1, amount
lw $t0, 0($t1)
sw $t0, -208($fp)
#SUB, $temp99, $temp101, $temp99
lw $t0, -200($fp)
lw $t1, -208($fp)
sub $t0, $t0, $t1
sw $t0, -200($fp)
#LI, 1, , $temp102
li $t0, 1
sw $t0, -212($fp)
#ADD, $temp99, $temp102, $temp99
lw $t0, -200($fp)
lw $t1, -212($fp)
add $t0, $t0, $t1
sw $t0, -200($fp)
#BGT, $temp98, $temp99, $label34
lw $t0, -196($fp)
lw $t1, -200($fp)
bgt $t0, $t1, $label34
#LAB, , , $label37
$label37:
#LVAR, cur_pointer, , $temp103
lw $t0, 0($fp)
sw $t0, -216($fp)
#LVAR, i, , $temp104
move $t0, $t2
sw $t0, -220($fp)
#SARY, f, $temp103, $temp104
lw $t0, -216($fp)
mul $t0, $t0, 4
la $t1, f
add $t0, $t0, $t1 
lw $t1, -220($fp)
sw $t1, ($t0)
#LVAR, cur_pointer, , $temp105
lw $t0, 0($fp)
sw $t0, -224($fp)
#LI, 1, , $temp106
li $t0, 1
sw $t0, -228($fp)
#ADD, $temp105, $temp106, $temp105
lw $t0, -224($fp)
lw $t1, -228($fp)
add $t0, $t0, $t1
sw $t0, -224($fp)
#PUSH, , , $temp105
lw $t0, -224($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, i, , $temp107
move $t0, $t2
sw $t0, -232($fp)
#LI, 1, , $temp108
li $t0, 1
sw $t0, -236($fp)
#ADD, $temp107, $temp108, $temp107
lw $t0, -232($fp)
lw $t1, -236($fp)
add $t0, $t0, $t1
sw $t0, -232($fp)
#PUSH, , , $temp107
lw $t0, -232($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , calrecursive
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal calrecursive
lw $8, -40($sp)
lw $9, -44($sp)
lw $10, -48($sp)
lw $11, -52($sp)
lw $12, -56($sp)
lw $13, -60($sp)
lw $14, -64($sp)
lw $15, -68($sp)
lw $16, -72($sp)
lw $17, -76($sp)
lw $18, -80($sp)
lw $19, -84($sp)
lw $20, -88($sp)
lw $21, -92($sp)
lw $22, -96($sp)
lw $23, -100($sp)
lw $24, -104($sp)
lw $25, -108($sp)
lw $fp ,-128($sp)
lw $ra ,-132($sp)
#LVAR, i, , $temp109
move $t0, $t2
sw $t0, -240($fp)
#LI, 1, , $temp110
li $t0, 1
sw $t0, -244($fp)
#ADD, $temp109, $temp110, $temp109
lw $t0, -240($fp)
lw $t1, -244($fp)
add $t0, $t0, $t1
sw $t0, -240($fp)
#LVAR, $temp109, , i
lw $t0, -240($fp)
move $t2, $t0
#LAB, , , $label36
$label36:
#LVAR, i, , $temp111
move $t0, $t2
sw $t0, -248($fp)
#LVAR, cur_pointer, , $temp112
lw $t0, 0($fp)
sw $t0, -252($fp)
#LVAR, numbers_to_be_selected, , $temp113
la $t1, numbers_to_be_selected
lw $t0, 0($t1)
sw $t0, -256($fp)
#ADD, $temp112, $temp113, $temp112
lw $t0, -252($fp)
lw $t1, -256($fp)
add $t0, $t0, $t1
sw $t0, -252($fp)
#LVAR, amount, , $temp114
la $t1, amount
lw $t0, 0($t1)
sw $t0, -260($fp)
#SUB, $temp112, $temp114, $temp112
lw $t0, -252($fp)
lw $t1, -260($fp)
sub $t0, $t0, $t1
sw $t0, -252($fp)
#LI, 1, , $temp115
li $t0, 1
sw $t0, -264($fp)
#ADD, $temp112, $temp115, $temp112
lw $t0, -252($fp)
lw $t1, -264($fp)
add $t0, $t0, $t1
sw $t0, -252($fp)
#BGT, $temp111, $temp112, $label38
lw $t0, -248($fp)
lw $t1, -252($fp)
bgt $t0, $t1, $label38
#JUMP, , , $label37
j $label37
#LAB, , , $label38
$label38:
#JUMP, , , $label35
j $label35
#LAB, , , $label34
$label34:
#LAB, , , $label35
$label35:
#REN, , , 
addi $sp, $sp, 272
jr $ra
#FUNC, void, , initpermutation
initpermutation:
add $fp, $sp, 8
subi $sp, $sp, 164
#PARA, int, , var
#PARA, int, , lenth
#VAR, int, , i
#LI, 0, , $temp116
li $t0, 0
sw $t0, -140($fp)
#LVAR, $temp116, , i
lw $t0, -140($fp)
move $t2, $t0
#LAB, , , $label40
$label40:
#LVAR, i, , $temp117
move $t0, $t2
sw $t0, -144($fp)
#LVAR, var, , $temp118
lw $t0, 0($fp)
sw $t0, -148($fp)
#SARY, f, $temp117, $temp118
lw $t0, -144($fp)
mul $t0, $t0, 4
la $t1, f
add $t0, $t0, $t1 
lw $t1, -148($fp)
sw $t1, ($t0)
#LVAR, i, , $temp119
move $t0, $t2
sw $t0, -152($fp)
#LI, 1, , $temp120
li $t0, 1
sw $t0, -156($fp)
#ADD, $temp119, $temp120, $temp119
lw $t0, -152($fp)
lw $t1, -156($fp)
add $t0, $t0, $t1
sw $t0, -152($fp)
#LVAR, $temp119, , i
lw $t0, -152($fp)
move $t2, $t0
#LAB, , , $label39
$label39:
#LVAR, i, , $temp121
move $t0, $t2
sw $t0, -160($fp)
#LVAR, lenth, , $temp122
lw $t0, -4($fp)
sw $t0, -164($fp)
#BGT, $temp121, $temp122, $label41
lw $t0, -160($fp)
lw $t1, -164($fp)
bgt $t0, $t1, $label41
#JUMP, , , $label40
j $label40
#LAB, , , $label41
$label41:
#REN, , , 
addi $sp, $sp, 172
jr $ra
#REN, , , 
addi $sp, $sp, 172
jr $ra
#FUNC, int, , seqsum
seqsum:
add $fp, $sp, 4
subi $sp, $sp, 160
#PARA, int, , i
#LVAR, i, , $temp123
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 1, , $temp124
li $t0, 1
sw $t0, -136($fp)
#BNE, $temp123, $temp124, $label42
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, $label42
#LI, 1, , $temp125
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp125
lw $v0, -140($fp)
addi $sp, $sp, 164
jr $ra
#JUMP, , , $label43
j $label43
#LAB, , , $label42
$label42:
#LVAR, i, , $temp126
lw $t0, 0($fp)
sw $t0, -144($fp)
#LVAR, i, , $temp128
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 1, , $temp129
li $t0, 1
sw $t0, -152($fp)
#SUB, $temp128, $temp129, $temp128
lw $t0, -148($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -148($fp)
#PUSH, , , $temp128
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , seqsum
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $8, -36($sp)
lw $9, -40($sp)
lw $10, -44($sp)
lw $11, -48($sp)
lw $12, -52($sp)
lw $13, -56($sp)
lw $14, -60($sp)
lw $15, -64($sp)
lw $16, -68($sp)
lw $17, -72($sp)
lw $18, -76($sp)
lw $19, -80($sp)
lw $20, -84($sp)
lw $21, -88($sp)
lw $22, -92($sp)
lw $23, -96($sp)
lw $24, -100($sp)
lw $25, -104($sp)
lw $fp ,-124($sp)
lw $ra ,-128($sp)
#VOF, seqsum, , $temp127
sw $v0, -156($fp)
#ADD, $temp126, $temp127, $temp126
lw $t0, -144($fp)
lw $t1, -156($fp)
add $t0, $t0, $t1
sw $t0, -144($fp)
#RET, , , $temp126
lw $v0, -144($fp)
addi $sp, $sp, 164
jr $ra
#LAB, , , $label43
$label43:
#FUNC, void, , printtable
printtable:
add $fp, $sp, 0
subi $sp, $sp, 132
#PRT, 1, , 18
li $v0, 4
la $a0, $string18
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 19
li $v0, 4
la $a0, $string19
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 20
li $v0, 4
la $a0, $string20
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 21
li $v0, 4
la $a0, $string21
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 22
li $v0, 4
la $a0, $string22
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 132
jr $ra
#FUNC, int, , and
and:
add $fp, $sp, 8
subi $sp, $sp, 160
#PARA, int, , a
#PARA, int, , b
#LVAR, b, , $temp130
lw $t0, -4($fp)
sw $t0, -136($fp)
#LI, 4, , $temp131
li $t0, 4
sw $t0, -140($fp)
#BNE, $temp130, $temp131, $label44
lw $t0, -136($fp)
lw $t1, -140($fp)
bne $t0, $t1, $label44
#LI, 0, , $temp132
li $t0, 0
sw $t0, -144($fp)
#RET, , , $temp132
lw $v0, -144($fp)
addi $sp, $sp, 168
jr $ra
#JUMP, , , $label45
j $label45
#LAB, , , $label44
$label44:
#LVAR, a, , $temp133
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 0, , $temp134
li $t0, 0
sw $t0, -152($fp)
#BNE, $temp133, $temp134, $label46
lw $t0, -148($fp)
lw $t1, -152($fp)
bne $t0, $t1, $label46
#LI, 1, , $temp135
li $t0, 1
sw $t0, -156($fp)
#RET, , , $temp135
lw $v0, -156($fp)
addi $sp, $sp, 168
jr $ra
#JUMP, , , $label47
j $label47
#LAB, , , $label46
$label46:
#LI, 0, , $temp136
li $t0, 0
sw $t0, -160($fp)
#RET, , , $temp136
lw $v0, -160($fp)
addi $sp, $sp, 168
jr $ra
#LAB, , , $label47
$label47:
#LAB, , , $label45
$label45:
#FUNC, char, , helpchar
helpchar:
add $fp, $sp, 0
subi $sp, $sp, 144
#VAR, char, , temp
#LI, 45, , $temp137
li $t0, 45
sw $t0, -132($fp)
#LVAR, $temp137, , temp
lw $t0, -132($fp)
move $t2, $t0
#LVAR, temp, , $temp138
move $t0, $t2
sw $t0, -136($fp)
#RET, , , $temp138
lw $v0, -136($fp)
addi $sp, $sp, 144
jr $ra
#FUNC, void, , typecorrosion
typecorrosion:
add $fp, $sp, 0
subi $sp, $sp, 204
#VAR, int, , temp
#VAR, char, , _char
#LI, 105, , $temp139
li $t0, 105
sw $t0, -136($fp)
#LVAR, $temp139, , _char
lw $t0, -136($fp)
move $t3, $t0
#LI, 8, , $temp140
li $t0, 8
sw $t0, -140($fp)
#LVAR, $temp140, , temp
lw $t0, -140($fp)
move $t2, $t0
#LI, 72, , $temp141
li $t0, 72
sw $t0, -144($fp)
#PRT, 0, , $temp141
li $v0, 11
lw $a0, -144($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, _char, , $temp142
move $t0, $t3
sw $t0, -148($fp)
#PRT, 0, , $temp142
li $v0, 11
lw $a0, -148($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#CALL, , , helpchar
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal helpchar
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#VOF, helpchar, , $temp143
sw $v0, -152($fp)
#PRT, 0, , $temp143
li $v0, 11
lw $a0, -152($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 23
li $v0, 4
la $a0, $string23
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 2, , $temp144
li $t0, 2
sw $t0, -156($fp)
#PRT, 0, , $temp144
li $v0, 1
lw $a0, -156($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 2, , $temp145
li $t0, 2
sw $t0, -160($fp)
#LI, 1009, , $temp146
li $t0, 1009
sw $t0, -164($fp)
#MUL, $temp145, $temp146, $temp145
lw $t0, -160($fp)
lw $t1, -164($fp)
mult $t0, $t1
mflo $t0
sw $t0, -160($fp)
#LI, 1, , $temp147
li $t0, 1
sw $t0, -168($fp)
#SUB, $temp145, $temp147, $temp145
lw $t0, -160($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -160($fp)
#LI, 2017, , $temp148
li $t0, 2017
sw $t0, -172($fp)
#SUB, $temp145, $temp148, $temp145
lw $t0, -160($fp)
lw $t1, -172($fp)
sub $t0, $t0, $t1
sw $t0, -160($fp)
#PRT, 0, , $temp145
li $v0, 1
lw $a0, -160($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 99, , $temp149
li $t0, 99
sw $t0, -176($fp)
#LI, 97, , $temp150
li $t0, 97
sw $t0, -180($fp)
#SUB, $temp149, $temp150, $temp149
lw $t0, -176($fp)
lw $t1, -180($fp)
sub $t0, $t0, $t1
sw $t0, -176($fp)
#LI, 98, , $temp151
li $t0, 98
sw $t0, -184($fp)
#LI, 97, , $temp152
li $t0, 97
sw $t0, -188($fp)
#SUB, $temp151, $temp152, $temp151
lw $t0, -184($fp)
lw $t1, -188($fp)
sub $t0, $t0, $t1
sw $t0, -184($fp)
#SUB, $temp149, $temp151, $temp149
lw $t0, -176($fp)
lw $t1, -184($fp)
sub $t0, $t0, $t1
sw $t0, -176($fp)
#PRT, 0, , $temp149
li $v0, 1
lw $a0, -176($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, temp, , $temp153
move $t0, $t2
sw $t0, -196($fp)
#PRT, 0, , $temp153
li $v0, 1
lw $a0, -196($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 204
jr $ra
#FUNC, void, , testemptyfunction
testemptyfunction:
add $fp, $sp, 0
subi $sp, $sp, 132
#REN, , , 
addi $sp, $sp, 132
jr $ra
#FUNC, void, , teststructure
teststructure:
add $fp, $sp, 20
subi $sp, $sp, 192
#PARA, int, , a
#PARA, int, , b
#PARA, char, , c
#PARA, char, , d
#PARA, char, , e
#VAR, int, , t1
#VAR, int, , t2
#LVAR, a, , $temp154
lw $t0, 0($fp)
sw $t0, -156($fp)
#LVAR, b, , $temp155
lw $t0, -4($fp)
sw $t0, -160($fp)
#ADD, $temp154, $temp155, $temp154
lw $t0, -156($fp)
lw $t1, -160($fp)
add $t0, $t0, $t1
sw $t0, -156($fp)
#LVAR, d, , $temp156
lw $t0, -12($fp)
sw $t0, -164($fp)
#ADD, $temp154, $temp156, $temp154
lw $t0, -156($fp)
lw $t1, -164($fp)
add $t0, $t0, $t1
sw $t0, -156($fp)
#LVAR, c, , $temp157
lw $t0, -8($fp)
sw $t0, -168($fp)
#SUB, $temp154, $temp157, $temp154
lw $t0, -156($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -156($fp)
#LVAR, c, , $temp158
lw $t0, -8($fp)
sw $t0, -172($fp)
#LVAR, e, , $temp159
lw $t0, -16($fp)
sw $t0, -176($fp)
#SUB, $temp158, $temp159, $temp158
lw $t0, -172($fp)
lw $t1, -176($fp)
sub $t0, $t0, $t1
sw $t0, -172($fp)
#SUB, $temp154, $temp158, $temp154
lw $t0, -156($fp)
lw $t1, -172($fp)
sub $t0, $t0, $t1
sw $t0, -156($fp)
#LI, 66666, , $temp160
li $t0, 66666
sw $t0, -184($fp)
#BNE, $temp154, $temp160, $label49
lw $t0, -156($fp)
lw $t1, -184($fp)
bne $t0, $t1, $label49
#PRT, 1, , 24
li $v0, 4
la $a0, $string24
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp161
li $t0, 0
sw $t0, -188($fp)
#LVAR, $temp161, , t1
lw $t0, -188($fp)
move $t2, $t0
#LI, 0, , $temp162
li $t0, 0
sw $t0, -192($fp)
#LVAR, $temp162, , t2
lw $t0, -192($fp)
move $t3, $t0
#JUMP, , , $label48
j $label48
#LAB, , , $label49
$label49:
#LI, 0, , $temp163
li $t0, 0
sw $t0, -196($fp)
#BNE, $temp154, $temp163, $label50
lw $t0, -156($fp)
lw $t1, -196($fp)
bne $t0, $t1, $label50
#PRT, 1, , 25
li $v0, 4
la $a0, $string25
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp164
li $t0, 1
sw $t0, -200($fp)
#LVAR, $temp164, , error
lw $t0, -200($fp)
la $t1, error
sw $t0, 0($t1)
#JUMP, , , $label48
j $label48
#LAB, , , $label50
$label50:
#LI, 1, , $temp165
li $t0, 1
sw $t0, -204($fp)
#LVAR, $temp165, , error
lw $t0, -204($fp)
la $t1, error
sw $t0, 0($t1)
#LAB, , , $label48
$label48:
#REN, , , 
addi $sp, $sp, 212
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 316
#VAR, char, , choice
#VAR, int, , select
#LI, 0, , $temp166
li $t0, 0
sw $t0, -136($fp)
#LVAR, $temp166, , error
lw $t0, -136($fp)
la $t1, error
sw $t0, 0($t1)
#LI, 48, , $temp167
li $t0, 48
sw $t0, -140($fp)
#LVAR, $temp167, , _char
lw $t0, -140($fp)
la $t1, _char
sw $t0, 0($t1)
#LAB, , , $label52
$label52:
#CALL, , , printtable
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal printtable
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#READ, , , select
li $v0, 5
syscall
move $t3, $v0
#LVAR, select, , $temp168
move $t0, $t3
sw $t0, -144($fp)
#LI, 0, , $temp169
li $t0, 0
sw $t0, -148($fp)
#BNE, $temp168, $temp169, $label55
lw $t0, -144($fp)
lw $t1, -148($fp)
bne $t0, $t1, $label55
#CALL, , , testvalue
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testvalue
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#CALL, , , testarithmetic
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testarithmetic
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#CALL, , , testif
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testif
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#LI, 1, , $temp170
li $t0, 1
sw $t0, -152($fp)
#LVAR, _const_int_2, , $temp171
la $t1, _const_int_2
lw $t0, 0($t1)
sw $t0, -156($fp)
#MUL, $temp170, $temp171, $temp170
lw $t0, -152($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -152($fp)
#LI, 0, , $temp172
li $t0, 0
sw $t0, -160($fp)
#SUB, $temp172, $temp170, $temp170
lw $t0, -160($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -152($fp)
#PUSH, , , $temp170
lw $t0, -152($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testswitch
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testswitch
lw $8, -36($sp)
lw $9, -40($sp)
lw $10, -44($sp)
lw $11, -48($sp)
lw $12, -52($sp)
lw $13, -56($sp)
lw $14, -60($sp)
lw $15, -64($sp)
lw $16, -68($sp)
lw $17, -72($sp)
lw $18, -76($sp)
lw $19, -80($sp)
lw $20, -84($sp)
lw $21, -88($sp)
lw $22, -92($sp)
lw $23, -96($sp)
lw $24, -100($sp)
lw $25, -104($sp)
lw $fp ,-124($sp)
lw $ra ,-128($sp)
#JUMP, , , $label54
j $label54
#LAB, , , $label55
$label55:
#LI, 1, , $temp173
li $t0, 1
sw $t0, -164($fp)
#BNE, $temp168, $temp173, $label56
lw $t0, -144($fp)
lw $t1, -164($fp)
bne $t0, $t1, $label56
#PRT, 1, , 26
li $v0, 4
la $a0, $string26
syscall
li $v0, 4
la $a0,$enter
syscall
#CALL, , , typecorrosion
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal typecorrosion
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#PRT, 1, , 27
li $v0, 4
la $a0, $string27
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 28
li $v0, 4
la $a0, $string28
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 29
li $v0, 4
la $a0, $string29
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label54
j $label54
#LAB, , , $label56
$label56:
#LI, 2, , $temp174
li $t0, 2
sw $t0, -168($fp)
#BNE, $temp168, $temp174, $label57
lw $t0, -144($fp)
lw $t1, -168($fp)
bne $t0, $t1, $label57
#LI, 49, , $temp175
li $t0, 49
sw $t0, -172($fp)
#LVAR, $temp175, , _var_char_0
lw $t0, -172($fp)
la $t1, _var_char_0
sw $t0, 0($t1)
#LI, 50, , $temp176
li $t0, 50
sw $t0, -176($fp)
#LVAR, $temp176, , _var_char_1
lw $t0, -176($fp)
la $t1, _var_char_1
sw $t0, 0($t1)
#LI, 12345, , $temp177
li $t0, 12345
sw $t0, -180($fp)
#LVAR, $temp177, , _var_int_0
lw $t0, -180($fp)
la $t1, _var_int_0
sw $t0, 0($t1)
#LI, 54321, , $temp178
li $t0, 54321
sw $t0, -184($fp)
#LVAR, $temp178, , _var_int_1
lw $t0, -184($fp)
la $t1, _var_int_1
sw $t0, 0($t1)
#CALL, , , testdo
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testdo
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#CALL, , , testemptyfunction
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal testemptyfunction
lw $8, -32($sp)
lw $9, -36($sp)
lw $10, -40($sp)
lw $11, -44($sp)
lw $12, -48($sp)
lw $13, -52($sp)
lw $14, -56($sp)
lw $15, -60($sp)
lw $16, -64($sp)
lw $17, -68($sp)
lw $18, -72($sp)
lw $19, -76($sp)
lw $20, -80($sp)
lw $21, -84($sp)
lw $22, -88($sp)
lw $23, -92($sp)
lw $24, -96($sp)
lw $25, -100($sp)
lw $fp ,-120($sp)
lw $ra ,-124($sp)
#LVAR, _var_int_0, , $temp179
la $t1, _var_int_0
lw $t0, 0($t1)
sw $t0, -188($fp)
#PUSH, , , $temp179
lw $t0, -188($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, _var_int_1, , $temp180
la $t1, _var_int_1
lw $t0, 0($t1)
sw $t0, -192($fp)
#PUSH, , , $temp180
lw $t0, -192($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, _var_char_0, , $temp181
la $t1, _var_char_0
lw $t0, 0($t1)
sw $t0, -196($fp)
#PUSH, , , $temp181
lw $t0, -196($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, _var_char_1, , $temp182
la $t1, _var_char_1
lw $t0, 0($t1)
sw $t0, -200($fp)
#PUSH, , , $temp182
lw $t0, -200($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, _char, , $temp183
la $t1, _char
lw $t0, 0($t1)
sw $t0, -204($fp)
#PUSH, , , $temp183
lw $t0, -204($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , teststructure
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal teststructure
lw $8, -52($sp)
lw $9, -56($sp)
lw $10, -60($sp)
lw $11, -64($sp)
lw $12, -68($sp)
lw $13, -72($sp)
lw $14, -76($sp)
lw $15, -80($sp)
lw $16, -84($sp)
lw $17, -88($sp)
lw $18, -92($sp)
lw $19, -96($sp)
lw $20, -100($sp)
lw $21, -104($sp)
lw $22, -108($sp)
lw $23, -112($sp)
lw $24, -116($sp)
lw $25, -120($sp)
lw $fp ,-140($sp)
lw $ra ,-144($sp)
#JUMP, , , $label54
j $label54
#LAB, , , $label57
$label57:
#LI, 3, , $temp184
li $t0, 3
sw $t0, -208($fp)
#BNE, $temp168, $temp184, $label58
lw $t0, -144($fp)
lw $t1, -208($fp)
bne $t0, $t1, $label58
#PRT, 1, , 30
li $v0, 4
la $a0, $string30
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 31
li $v0, 4
la $a0, $string31
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , choice
li $v0, 12
syscall
move $t2, $v0
#LVAR, choice, , $temp185
move $t0, $t2
sw $t0, -212($fp)
#LI, 80, , $temp186
li $t0, 80
sw $t0, -216($fp)
#BNE, $temp185, $temp186, $label60
lw $t0, -212($fp)
lw $t1, -216($fp)
bne $t0, $t1, $label60
#PRT, 1, , 32
li $v0, 4
la $a0, $string32
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , numbers_to_be_selected
li $v0, 5
syscall
la $t1, numbers_to_be_selected
sw $v0, 0($t1)
#READ, , , amount
li $v0, 5
syscall
la $t1, amount
sw $v0, 0($t1)
#PRT, 1, , 17
li $v0, 4
la $a0, $string17
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, amount, , $temp187
la $t1, amount
lw $t0, 0($t1)
sw $t0, -220($fp)
#LI, 1, , $temp188
li $t0, 1
sw $t0, -224($fp)
#ADD, $temp187, $temp188, $temp187
lw $t0, -220($fp)
lw $t1, -224($fp)
add $t0, $t0, $t1
sw $t0, -220($fp)
#LVAR, max, , $temp189
la $t1, max
lw $t0, 0($t1)
sw $t0, -228($fp)
#BLE, $temp187, $temp189, $label61
lw $t0, -220($fp)
lw $t1, -228($fp)
ble $t0, $t1, $label61
#PRT, 1, , 33
li $v0, 4
la $a0, $string33
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
li $v0,10
syscall
#JUMP, , , $label62
j $label62
#LAB, , , $label61
$label61:
#LAB, , , $label62
$label62:
#LI, 0, , $temp190
li $t0, 0
sw $t0, -232($fp)
#PUSH, , , $temp190
lw $t0, -232($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, amount, , $temp191
la $t1, amount
lw $t0, 0($t1)
sw $t0, -236($fp)
#LI, 1, , $temp192
li $t0, 1
sw $t0, -240($fp)
#ADD, $temp191, $temp192, $temp191
lw $t0, -236($fp)
lw $t1, -240($fp)
add $t0, $t0, $t1
sw $t0, -236($fp)
#PUSH, , , $temp191
lw $t0, -236($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , initpermutation
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal initpermutation
lw $8, -40($sp)
lw $9, -44($sp)
lw $10, -48($sp)
lw $11, -52($sp)
lw $12, -56($sp)
lw $13, -60($sp)
lw $14, -64($sp)
lw $15, -68($sp)
lw $16, -72($sp)
lw $17, -76($sp)
lw $18, -80($sp)
lw $19, -84($sp)
lw $20, -88($sp)
lw $21, -92($sp)
lw $22, -96($sp)
lw $23, -100($sp)
lw $24, -104($sp)
lw $25, -108($sp)
lw $fp ,-128($sp)
lw $ra ,-132($sp)
#LI, 0, , $temp193
li $t0, 0
sw $t0, -244($fp)
#PUSH, , , $temp193
lw $t0, -244($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 1, , $temp194
li $t0, 1
sw $t0, -248($fp)
#PUSH, , , $temp194
lw $t0, -248($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , calrecursive
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal calrecursive
lw $8, -40($sp)
lw $9, -44($sp)
lw $10, -48($sp)
lw $11, -52($sp)
lw $12, -56($sp)
lw $13, -60($sp)
lw $14, -64($sp)
lw $15, -68($sp)
lw $16, -72($sp)
lw $17, -76($sp)
lw $18, -80($sp)
lw $19, -84($sp)
lw $20, -88($sp)
lw $21, -92($sp)
lw $22, -96($sp)
lw $23, -100($sp)
lw $24, -104($sp)
lw $25, -108($sp)
lw $fp ,-128($sp)
lw $ra ,-132($sp)
#JUMP, , , $label59
j $label59
#LAB, , , $label60
$label60:
#LI, 83, , $temp195
li $t0, 83
sw $t0, -252($fp)
#BNE, $temp185, $temp195, $label63
lw $t0, -212($fp)
lw $t1, -252($fp)
bne $t0, $t1, $label63
#PRT, 1, , 34
li $v0, 4
la $a0, $string34
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , select
li $v0, 5
syscall
move $t3, $v0
#LVAR, select, , $temp197
move $t0, $t3
sw $t0, -256($fp)
#PUSH, , , $temp197
lw $t0, -256($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , seqsum
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $8, -36($sp)
lw $9, -40($sp)
lw $10, -44($sp)
lw $11, -48($sp)
lw $12, -52($sp)
lw $13, -56($sp)
lw $14, -60($sp)
lw $15, -64($sp)
lw $16, -68($sp)
lw $17, -72($sp)
lw $18, -76($sp)
lw $19, -80($sp)
lw $20, -84($sp)
lw $21, -88($sp)
lw $22, -92($sp)
lw $23, -96($sp)
lw $24, -100($sp)
lw $25, -104($sp)
lw $fp ,-124($sp)
lw $ra ,-128($sp)
#VOF, seqsum, , $temp196
sw $v0, -260($fp)
#PRT, 2, 35, $temp196
li $v0, 4
la $a0, $string35
syscall
li $v0, 1
lw $a0, -260($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 10, , $temp199
li $t0, 10
sw $t0, -264($fp)
#PUSH, , , $temp199
lw $t0, -264($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , seqsum
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal seqsum
lw $8, -36($sp)
lw $9, -40($sp)
lw $10, -44($sp)
lw $11, -48($sp)
lw $12, -52($sp)
lw $13, -56($sp)
lw $14, -60($sp)
lw $15, -64($sp)
lw $16, -68($sp)
lw $17, -72($sp)
lw $18, -76($sp)
lw $19, -80($sp)
lw $20, -84($sp)
lw $21, -88($sp)
lw $22, -92($sp)
lw $23, -96($sp)
lw $24, -100($sp)
lw $25, -104($sp)
lw $fp ,-124($sp)
lw $ra ,-128($sp)
#VOF, seqsum, , $temp198
sw $v0, -268($fp)
#LI, 55, , $temp200
li $t0, 55
sw $t0, -272($fp)
#BNE, $temp198, $temp200, $label64
lw $t0, -268($fp)
lw $t1, -272($fp)
bne $t0, $t1, $label64
#PRT, 1, , 36
li $v0, 4
la $a0, $string36
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label65
j $label65
#LAB, , , $label64
$label64:
#LI, 1, , $temp201
li $t0, 1
sw $t0, -276($fp)
#LVAR, $temp201, , error
lw $t0, -276($fp)
la $t1, error
sw $t0, 0($t1)
#PRT, 1, , 37
li $v0, 4
la $a0, $string37
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label65
$label65:
#LI, 3, , $temp202
li $t0, 3
sw $t0, -280($fp)
#LVAR, $temp202, , select
lw $t0, -280($fp)
move $t3, $t0
#JUMP, , , $label59
j $label59
#LAB, , , $label63
$label63:
#PRT, 1, , 38
li $v0, 4
la $a0, $string38
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label59
$label59:
#JUMP, , , $label54
j $label54
#LAB, , , $label58
$label58:
#LI, 4, , $temp203
li $t0, 4
sw $t0, -284($fp)
#BNE, $temp168, $temp203, $label66
lw $t0, -144($fp)
lw $t1, -284($fp)
bne $t0, $t1, $label66
#JUMP, , , $label54
j $label54
#LAB, , , $label66
$label66:
#PRT, 1, , 38
li $v0, 4
la $a0, $string38
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label54
$label54:
#LAB, , , $label51
$label51:
#LVAR, error, , $temp205
la $t1, error
lw $t0, 0($t1)
sw $t0, -288($fp)
#PUSH, , , $temp205
lw $t0, -288($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, select, , $temp206
move $t0, $t3
sw $t0, -292($fp)
#PUSH, , , $temp206
lw $t0, -292($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , and
sw $8, -32($sp)
sw $9, -36($sp)
sw $10, -40($sp)
sw $11, -44($sp)
sw $12, -48($sp)
sw $13, -52($sp)
sw $14, -56($sp)
sw $15, -60($sp)
sw $16, -64($sp)
sw $17, -68($sp)
sw $18, -72($sp)
sw $19, -76($sp)
sw $20, -80($sp)
sw $21, -84($sp)
sw $22, -88($sp)
sw $23, -92($sp)
sw $24, -96($sp)
sw $25, -100($sp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal and
lw $8, -40($sp)
lw $9, -44($sp)
lw $10, -48($sp)
lw $11, -52($sp)
lw $12, -56($sp)
lw $13, -60($sp)
lw $14, -64($sp)
lw $15, -68($sp)
lw $16, -72($sp)
lw $17, -76($sp)
lw $18, -80($sp)
lw $19, -84($sp)
lw $20, -88($sp)
lw $21, -92($sp)
lw $22, -96($sp)
lw $23, -100($sp)
lw $24, -104($sp)
lw $25, -108($sp)
lw $fp ,-128($sp)
lw $ra ,-132($sp)
#VOF, and, , $temp204
sw $v0, -296($fp)
#LI, 0, , $temp207
li $t0, 0
sw $t0, -300($fp)
#BEQ, $temp204, $temp207, $label53
lw $t0, -296($fp)
lw $t1, -300($fp)
beq $t0, $t1, $label53
#JUMP, , , $label52
j $label52
#LAB, , , $label53
$label53:
#LVAR, error, , $temp208
la $t1, error
lw $t0, 0($t1)
sw $t0, -304($fp)
#LI, 1, , $temp209
li $t0, 1
sw $t0, -308($fp)
#BLT, $temp208, $temp209, $label67
lw $t0, -304($fp)
lw $t1, -308($fp)
blt $t0, $t1, $label67
#PRT, 1, , 39
li $v0, 4
la $a0, $string39
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label68
j $label68
#LAB, , , $label67
$label67:
#PRT, 1, , 40
li $v0, 4
la $a0, $string40
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label68
$label68:
#PRT, 1, , 41
li $v0, 4
la $a0, $string41
syscall
li $v0, 4
la $a0,$enter
syscall
