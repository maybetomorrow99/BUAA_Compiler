.data
con_int_1: .word 1
con_int_2: .word 2
con_char_1: .word 97
con_char_2: .word 98
var_int_1: .space 4
var_int_2: .space 4
var_int_array_1: .word 0: 101
var_int_array_2: .word 0: 101
var_char_1: .space 4
var_char_array: .word 0: 101
$string0: .asciiz "apple"
$string1: .asciiz "ali"
$string2: .asciiz "boy"
$string3: .asciiz "cat"
$string4: .asciiz "<"
$string5: .asciiz "<="
$string6: .asciiz ">"
$string7: .asciiz ">="
$string8: .asciiz "!="
$string9: .asciiz "=="
$string10: .asciiz "The result is "
$string11: .asciiz "test_if"
$string12: .asciiz "test_factorial"
$string13: .asciiz "test_while"
$string14: .asciiz "test_switch_char"
$string15: .asciiz "test_relation"
$string16: .asciiz "test_expression"
$string17: .asciiz "Please input 1~6"
$enter: .asciiz "\n"
.text
j main
#FUNC, char, , test_if
test_if:
add $fp, $sp, 8
subi $sp, $sp, 148
#PARA, int, , a
#PARA, int, , b
#LVAR, a, , $temp0
lw $t0, 0($fp)
sw $t0, -136($fp)
#LVAR, b, , $temp1
lw $t0, -4($fp)
sw $t0, -140($fp)
#BLT, $temp0, $temp1, label0
lw $t0, -136($fp)
lw $t1, -140($fp)
blt $t0, $t1, label0
#LI, 97, , $temp2
li $t0, 97
sw $t0, -144($fp)
#RET, , , $temp2
lw $v0, -144($fp)
addi $sp, $sp, 156
jr $ra
#JUMP, , , label1
j label1
#LAB, , , label0
label0:
#LI, 98, , $temp3
li $t0, 98
sw $t0, -148($fp)
#RET, , , $temp3
lw $v0, -148($fp)
addi $sp, $sp, 156
jr $ra
#LAB, , , label1
label1:
#FUNC, int, , test_factorial
test_factorial:
add $fp, $sp, 4
subi $sp, $sp, 160
#PARA, int, , n
#LVAR, n, , $temp4
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 0, , $temp5
li $t0, 0
sw $t0, -136($fp)
#BNE, $temp4, $temp5, label2
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, label2
#LI, 1, , $temp6
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp6
lw $v0, -140($fp)
addi $sp, $sp, 164
jr $ra
#JUMP, , , label3
j label3
#LAB, , , label2
label2:
#LVAR, n, , $temp7
lw $t0, 0($fp)
sw $t0, -144($fp)
#LVAR, n, , $temp9
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 1, , $temp10
li $t0, 1
sw $t0, -152($fp)
#SUB, $temp9, $temp10, $temp9
lw $t0, -148($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -148($fp)
#PUSH, , , $temp9
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_factorial
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
jal test_factorial
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
#VOF, test_factorial, , $temp8
sw $v0, -156($fp)
#MUL, $temp7, $temp8, $temp7
lw $t0, -144($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -144($fp)
#RET, , , $temp7
lw $v0, -144($fp)
addi $sp, $sp, 164
jr $ra
#LAB, , , label3
label3:
#FUNC, int, , test_while
test_while:
add $fp, $sp, 0
subi $sp, $sp, 160
#LI, 3, , $temp11
li $t0, 3
sw $t0, -128($fp)
#LVAR, $temp11, , var_int_1
lw $t0, -128($fp)
la $t1, var_int_1
sw $t0, 0($t1)
#LAB, , , label5
label5:
#LVAR, var_int_1, , $temp12
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -132($fp)
#LI, 1, , $temp13
li $t0, 1
sw $t0, -136($fp)
#SUB, $temp12, $temp13, $temp12
lw $t0, -132($fp)
lw $t1, -136($fp)
sub $t0, $t0, $t1
sw $t0, -132($fp)
#LVAR, $temp12, , var_int_1
lw $t0, -132($fp)
la $t1, var_int_1
sw $t0, 0($t1)
#LVAR, var_int_1, , $temp14
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -140($fp)
#PI, , , $temp14
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label4
label4:
#LVAR, var_int_1, , $temp15
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -144($fp)
#LI, 0, , $temp16
li $t0, 0
sw $t0, -148($fp)
#BEQ, $temp15, $temp16, label6
lw $t0, -144($fp)
lw $t1, -148($fp)
beq $t0, $t1, label6
#JUMP, , , label5
j label5
#LAB, , , label6
label6:
#LI, 666, , $temp17
li $t0, 666
sw $t0, -152($fp)
#RET, , , $temp17
lw $v0, -152($fp)
addi $sp, $sp, 160
jr $ra
#FUNC, void, , test_switch_char
test_switch_char:
add $fp, $sp, 4
subi $sp, $sp, 144
#PARA, char, , c
#LVAR, c, , $temp18
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 97, , $temp19
li $t0, 97
sw $t0, -136($fp)
#BNE, $temp18, $temp19, label8
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, label8
#PC, , , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#PC, , , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label7
j label7
#LAB, , , label8
label8:
#LI, 98, , $temp20
li $t0, 98
sw $t0, -140($fp)
#BNE, $temp18, $temp20, label9
lw $t0, -132($fp)
lw $t1, -140($fp)
bne $t0, $t1, label9
#PC, , , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label7
j label7
#LAB, , , label9
label9:
#PC, , , 3
li $v0, 4
la $a0, $string3
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label7
label7:
#REN, , , 
addi $sp, $sp, 148
jr $ra
#FUNC, void, , test_relation
test_relation:
add $fp, $sp, 4
subi $sp, $sp, 180
#PARA, int, , n
#LVAR, n, , $temp21
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 3, , $temp22
li $t0, 3
sw $t0, -136($fp)
#BGE, $temp21, $temp22, label10
lw $t0, -132($fp)
lw $t1, -136($fp)
bge $t0, $t1, label10
#PC, , , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label11
j label11
#LAB, , , label10
label10:
#LAB, , , label11
label11:
#LVAR, n, , $temp23
lw $t0, 0($fp)
sw $t0, -140($fp)
#LI, 4, , $temp24
li $t0, 4
sw $t0, -144($fp)
#BGT, $temp23, $temp24, label12
lw $t0, -140($fp)
lw $t1, -144($fp)
bgt $t0, $t1, label12
#PC, , , 5
li $v0, 4
la $a0, $string5
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label13
j label13
#LAB, , , label12
label12:
#LAB, , , label13
label13:
#LVAR, n, , $temp25
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 5, , $temp26
li $t0, 5
sw $t0, -152($fp)
#BLE, $temp25, $temp26, label14
lw $t0, -148($fp)
lw $t1, -152($fp)
ble $t0, $t1, label14
#PC, , , 6
li $v0, 4
la $a0, $string6
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label15
j label15
#LAB, , , label14
label14:
#LAB, , , label15
label15:
#LVAR, n, , $temp27
lw $t0, 0($fp)
sw $t0, -156($fp)
#LI, 6, , $temp28
li $t0, 6
sw $t0, -160($fp)
#BLT, $temp27, $temp28, label16
lw $t0, -156($fp)
lw $t1, -160($fp)
blt $t0, $t1, label16
#PC, , , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label17
j label17
#LAB, , , label16
label16:
#LAB, , , label17
label17:
#LVAR, n, , $temp29
lw $t0, 0($fp)
sw $t0, -164($fp)
#LI, 7, , $temp30
li $t0, 7
sw $t0, -168($fp)
#BEQ, $temp29, $temp30, label18
lw $t0, -164($fp)
lw $t1, -168($fp)
beq $t0, $t1, label18
#PC, , , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label19
j label19
#LAB, , , label18
label18:
#LAB, , , label19
label19:
#LVAR, n, , $temp31
lw $t0, 0($fp)
sw $t0, -172($fp)
#LI, 8, , $temp32
li $t0, 8
sw $t0, -176($fp)
#BNE, $temp31, $temp32, label20
lw $t0, -172($fp)
lw $t1, -176($fp)
bne $t0, $t1, label20
#PC, , , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label21
j label21
#LAB, , , label20
label20:
#LAB, , , label21
label21:
#REN, , , 
addi $sp, $sp, 184
jr $ra
#FUNC, int, , test_para
test_para:
add $fp, $sp, 20
subi $sp, $sp, 152
#PARA, int, , a
#PARA, int, , b
#PARA, int, , c
#PARA, int, , con_int_1
#PARA, int, , con_int_2
#LVAR, a, , $temp33
lw $t0, 0($fp)
sw $t0, -148($fp)
#LVAR, b, , $temp34
lw $t0, -4($fp)
sw $t0, -152($fp)
#ADD, $temp33, $temp34, $temp33
lw $t0, -148($fp)
lw $t1, -152($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, c, , $temp35
lw $t0, -8($fp)
sw $t0, -156($fp)
#ADD, $temp33, $temp35, $temp33
lw $t0, -148($fp)
lw $t1, -156($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, con_int_1, , $temp36
lw $t0, -12($fp)
sw $t0, -160($fp)
#ADD, $temp33, $temp36, $temp33
lw $t0, -148($fp)
lw $t1, -160($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, con_int_2, , $temp37
lw $t0, -16($fp)
sw $t0, -164($fp)
#ADD, $temp33, $temp37, $temp33
lw $t0, -148($fp)
lw $t1, -164($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#RET, , , $temp33
lw $v0, -148($fp)
addi $sp, $sp, 172
jr $ra
#FUNC, void, , test_expression
test_expression:
add $fp, $sp, 0
subi $sp, $sp, 220
#LI, 1, , $temp38
li $t0, 1
sw $t0, -128($fp)
#LVAR, con_int_2, , $temp39
la $t1, con_int_2
lw $t0, 0($t1)
sw $t0, -132($fp)
#LI, 1, , $temp40
li $t0, 1
sw $t0, -136($fp)
#DIV, $temp39, $temp40, $temp39
lw $t0, -132($fp)
lw $t1, -136($fp)
div $t0, $t1
mflo $t0
sw $t0, -132($fp)
#LI, 1, , $temp41
li $t0, 1
sw $t0, -140($fp)
#ADD, $temp39, $temp41, $temp39
lw $t0, -132($fp)
lw $t1, -140($fp)
add $t0, $t0, $t1
sw $t0, -132($fp)
#LI, 1, , $temp43
li $t0, 1
sw $t0, -144($fp)
#PUSH, , , $temp43
lw $t0, -144($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 2, , $temp44
li $t0, 2
sw $t0, -148($fp)
#PUSH, , , $temp44
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 3, , $temp45
li $t0, 3
sw $t0, -152($fp)
#PUSH, , , $temp45
lw $t0, -152($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 4, , $temp46
li $t0, 4
sw $t0, -156($fp)
#PUSH, , , $temp46
lw $t0, -156($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 5, , $temp47
li $t0, 5
sw $t0, -160($fp)
#PUSH, , , $temp47
lw $t0, -160($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_para
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
jal test_para
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
#VOF, test_para, , $temp42
sw $v0, -164($fp)
#ADD, $temp39, $temp42, $temp39
lw $t0, -132($fp)
lw $t1, -164($fp)
add $t0, $t0, $t1
sw $t0, -132($fp)
#SARY, var_int_array_1, $temp38, $temp39
lw $t0, -128($fp)
mul $t0, $t0, 4
la $t1, var_int_array_1
add $t0, $t0, $t1 
lw $t1, -132($fp)
sw $t1, ($t0)
#PC, , , 10
li $v0, 4
la $a0, $string10
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, con_int_1, , $temp48
la $t1, con_int_1
lw $t0, 0($t1)
sw $t0, -168($fp)
#LI, 0, , $temp49
li $t0, 0
sw $t0, -172($fp)
#SUB, $temp49, $temp48, $temp48
lw $t0, -172($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#VAR, char, , $temp50
#LI, 1, , $temp51
li $t0, 1
sw $t0, -180($fp)
#LARY, var_int_array_1, $temp51, $temp50
lw $t0, -180($fp)
mul $t0, $t0, 4
la $t1, var_int_array_1
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -176($fp)
#SUB, $temp48, $temp50, $temp48
lw $t0, -168($fp)
lw $t1, -176($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#LI, 5, , $temp52
li $t0, 5
sw $t0, -184($fp)
#ADD, $temp48, $temp52, $temp48
lw $t0, -168($fp)
lw $t1, -184($fp)
add $t0, $t0, $t1
sw $t0, -168($fp)
#LI, 97, , $temp53
li $t0, 97
sw $t0, -188($fp)
#ADD, $temp48, $temp53, $temp48
lw $t0, -168($fp)
lw $t1, -188($fp)
add $t0, $t0, $t1
sw $t0, -168($fp)
#LI, 3, , $temp55
li $t0, 3
sw $t0, -192($fp)
#PUSH, , , $temp55
lw $t0, -192($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_factorial
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
jal test_factorial
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
#VOF, test_factorial, , $temp54
sw $v0, -196($fp)
#ADD, $temp48, $temp54, $temp48
lw $t0, -168($fp)
lw $t1, -196($fp)
add $t0, $t0, $t1
sw $t0, -168($fp)
#LI, -1, , $temp56
li $t0, -1
sw $t0, -200($fp)
#LI, 2, , $temp57
li $t0, 2
sw $t0, -204($fp)
#LI, 1, , $temp58
li $t0, 1
sw $t0, -208($fp)
#ADD, $temp57, $temp58, $temp57
lw $t0, -204($fp)
lw $t1, -208($fp)
add $t0, $t0, $t1
sw $t0, -204($fp)
#MUL, $temp56, $temp57, $temp56
lw $t0, -200($fp)
lw $t1, -204($fp)
mult $t0, $t1
mflo $t0
sw $t0, -200($fp)
#ADD, $temp48, $temp56, $temp48
lw $t0, -168($fp)
lw $t1, -200($fp)
add $t0, $t0, $t1
sw $t0, -168($fp)
#PI, , , $temp48
li $v0, 1
lw $a0, -168($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 220
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 256
#CON, int, 3, con_int_3
li $t2, 3
#CON, int, 44, con_int_4
li $t3, 44
#CON, int, -555, con_int_5
li $t4, -555
#VAR, int, , var_int_res
#VAR, char, , var_char_res
#VAR, int, , var_int_3
#VAR, int, , var_int_4
#VAR, int, , op
#LI, 4, , $temp59
li $t0, 4
sw $t0, -160($fp)
#LVAR, $temp59, , var_int_1
lw $t0, -160($fp)
la $t1, var_int_1
sw $t0, 0($t1)
#READ, , , op
li $v0, 5
syscall
sw $v0, -156($fp)
#LVAR, op, , $temp60
lw $t0, -156($fp)
sw $t0, -164($fp)
#LI, 1, , $temp61
li $t0, 1
sw $t0, -168($fp)
#BNE, $temp60, $temp61, label23
lw $t0, -164($fp)
lw $t1, -168($fp)
bne $t0, $t1, label23
#PC, , , 11
li $v0, 4
la $a0, $string11
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, con_int_5, , $temp63
move $t0 $t4
sw $t0, -172($fp)
#PUSH, , , $temp63
lw $t0, -172($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, con_int_3, , $temp64
move $t0 $t2
sw $t0, -176($fp)
#PUSH, , , $temp64
lw $t0, -176($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_if
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
jal test_if
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
#VOF, test_if, , $temp62
sw $v0, -180($fp)
#LVAR, $temp62, , var_char_res
lw $t0, -180($fp)
move $t6, $t0
#LVAR, var_char_res, , $temp65
move $t0 $t6
sw $t0, -184($fp)
#PI, , , $temp65
li $v0, 11
lw $a0, -184($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, con_int_4, , $temp67
move $t0 $t3
sw $t0, -188($fp)
#PUSH, , , $temp67
lw $t0, -188($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, con_int_3, , $temp68
move $t0 $t2
sw $t0, -192($fp)
#PUSH, , , $temp68
lw $t0, -192($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_if
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
jal test_if
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
#VOF, test_if, , $temp66
sw $v0, -196($fp)
#LVAR, $temp66, , var_char_res
lw $t0, -196($fp)
move $t6, $t0
#LVAR, var_char_res, , $temp69
move $t0 $t6
sw $t0, -200($fp)
#PI, , , $temp69
li $v0, 11
lw $a0, -200($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#PC, , , 12
li $v0, 4
la $a0, $string12
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, var_int_1, , $temp71
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -204($fp)
#PUSH, , , $temp71
lw $t0, -204($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_factorial
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
jal test_factorial
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
#VOF, test_factorial, , $temp70
sw $v0, -208($fp)
#LVAR, $temp70, , var_int_res
lw $t0, -208($fp)
move $t5, $t0
#LVAR, var_int_res, , $temp72
move $t0 $t5
sw $t0, -212($fp)
#PI, , , $temp72
li $v0, 1
lw $a0, -212($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label22
j label22
#LAB, , , label23
label23:
#LI, 2, , $temp73
li $t0, 2
sw $t0, -216($fp)
#BNE, $temp60, $temp73, label24
lw $t0, -164($fp)
lw $t1, -216($fp)
bne $t0, $t1, label24
#PC, , , 13
li $v0, 4
la $a0, $string13
syscall
li $v0, 4
la $a0,$enter
syscall
#CALL, , , test_while
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
jal test_while
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
#VOF, test_while, , $temp74
sw $v0, -220($fp)
#LVAR, $temp74, , var_int_res
lw $t0, -220($fp)
move $t5, $t0
#LVAR, var_int_res, , $temp75
move $t0 $t5
sw $t0, -224($fp)
#PI, , , $temp75
li $v0, 1
lw $a0, -224($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#PC, , , 14
li $v0, 4
la $a0, $string14
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, con_char_1, , $temp76
la $t1, con_char_1
lw $t0, 0($t1)
sw $t0, -228($fp)
#PUSH, , , $temp76
lw $t0, -228($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_switch_char
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
jal test_switch_char
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
#LVAR, con_char_2, , $temp77
la $t1, con_char_2
lw $t0, 0($t1)
sw $t0, -232($fp)
#PUSH, , , $temp77
lw $t0, -232($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_switch_char
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
jal test_switch_char
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
#LI, 99, , $temp78
li $t0, 99
sw $t0, -236($fp)
#PUSH, , , $temp78
lw $t0, -236($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_switch_char
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
jal test_switch_char
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
#JUMP, , , label22
j label22
#LAB, , , label24
label24:
#LI, 3, , $temp79
li $t0, 3
sw $t0, -240($fp)
#BNE, $temp60, $temp79, label25
lw $t0, -164($fp)
lw $t1, -240($fp)
bne $t0, $t1, label25
#PC, , , 15
li $v0, 4
la $a0, $string15
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , var_int_1
li $v0, 5
syscall
la $t1, var_int_1
sw $v0, 0($t1)
#LVAR, con_int_1, , $temp80
la $t1, con_int_1
lw $t0, 0($t1)
sw $t0, -244($fp)
#PUSH, , , $temp80
lw $t0, -244($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_relation
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
jal test_relation
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
#READ, , , var_int_1
li $v0, 5
syscall
la $t1, var_int_1
sw $v0, 0($t1)
#LI, 8, , $temp81
li $t0, 8
sw $t0, -248($fp)
#PUSH, , , $temp81
lw $t0, -248($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_relation
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
jal test_relation
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
#PC, , , 16
li $v0, 4
la $a0, $string16
syscall
li $v0, 4
la $a0,$enter
syscall
#CALL, , , test_expression
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
jal test_expression
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
#JUMP, , , label22
j label22
#LAB, , , label25
label25:
#PC, , , 17
li $v0, 4
la $a0, $string17
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label22
label22:
#REN, , , 
li $v0,10
syscall
