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
_abcdefghigklmnopqrstuvwxyz: .space 4
abcdefghijklmnopqrstuvwxyz1234567890: .space 4
$string0: .asciiz "test_if"
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
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 196
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
#PC, , , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , var_int_1
li $v0, 5
syscall
la $t1, var_int_1
sw $v0, 0($t1)
#READ, , , var_int_2
li $v0, 5
syscall
la $t1, var_int_2
sw $v0, 0($t1)
#LVAR, var_int_1, , $temp5
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -160($fp)
#PUSH, , , $temp5
lw $t0, -160($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, var_int_2, , $temp6
la $t1, var_int_2
lw $t0, 0($t1)
sw $t0, -164($fp)
#PUSH, , , $temp6
lw $t0, -164($fp)
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
#VOF, test_if, , $temp4
sw $v0, -168($fp)
#LVAR, $temp4, , var_char_res
lw $t0, -168($fp)
move $t6, $t0
#LVAR, var_char_res, , $temp7
move $t0 $t6
sw $t0, -172($fp)
#PI, , , $temp7
li $v0, 11
lw $a0, -172($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, var_int_2, , $temp9
la $t1, var_int_2
lw $t0, 0($t1)
sw $t0, -176($fp)
#PUSH, , , $temp9
lw $t0, -176($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, var_int_1, , $temp10
la $t1, var_int_1
lw $t0, 0($t1)
sw $t0, -180($fp)
#PUSH, , , $temp10
lw $t0, -180($fp)
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
#VOF, test_if, , $temp8
sw $v0, -184($fp)
#LVAR, $temp8, , var_char_res
lw $t0, -184($fp)
move $t6, $t0
#LVAR, var_char_res, , $temp11
move $t0 $t6
sw $t0, -188($fp)
#PI, , , $temp11
li $v0, 11
lw $a0, -188($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
