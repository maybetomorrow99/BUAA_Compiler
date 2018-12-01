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
$string0: .asciiz "test_factorial"
$enter: .asciiz "\n"
.text
j main
#FUNC, int, , test_factorial
test_factorial:
add $fp, $sp, 4
subi $sp, $sp, 160
#PARA, int, , n
#LVAR, n, , $temp0
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 0, , $temp1
li $t0, 0
sw $t0, -136($fp)
#BNE, $temp0, $temp1, label0
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, label0
#LI, 1, , $temp2
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp2
lw $v0, -140($fp)
addi $sp, $sp, 164
jr $ra
#JUMP, , , label1
j label1
#LAB, , , label0
label0:
#LVAR, n, , $temp3
lw $t0, 0($fp)
sw $t0, -144($fp)
#LVAR, n, , $temp5
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 1, , $temp6
li $t0, 1
sw $t0, -152($fp)
#SUB, $temp5, $temp6, $temp5
lw $t0, -148($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -148($fp)
#PUSH, , , $temp5
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
#VOF, test_factorial, , $temp4
sw $v0, -156($fp)
#MUL, $temp3, $temp4, $temp3
lw $t0, -144($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -144($fp)
#RET, , , $temp3
lw $v0, -144($fp)
addi $sp, $sp, 164
jr $ra
#LAB, , , label1
label1:
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 176
#CON, int, 3, con_int_3
li $t2, 3
#CON, int, 44, con_int_4
li $t3, 44
#CON, int, -555, con_int_5
li $t4, -555
#VAR, char, , var_char_res
#VAR, int, , var_int_res
#PC, , , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 3, , $temp8
li $t0, 3
sw $t0, -148($fp)
#PUSH, , , $temp8
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
#VOF, test_factorial, , $temp7
sw $v0, -152($fp)
#LVAR, $temp7, , var_int_res
lw $t0, -152($fp)
move $t6, $t0
#LVAR, var_int_res, , $temp9
move $t0 $t6
sw $t0, -156($fp)
#PI, , , $temp9
li $v0, 1
lw $a0, -156($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 5, , $temp11
li $t0, 5
sw $t0, -160($fp)
#PUSH, , , $temp11
lw $t0, -160($fp)
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
#VOF, test_factorial, , $temp10
sw $v0, -164($fp)
#LVAR, $temp10, , var_int_res
lw $t0, -164($fp)
move $t6, $t0
#LVAR, var_int_res, , $temp12
move $t0 $t6
sw $t0, -168($fp)
#PI, , , $temp12
li $v0, 1
lw $a0, -168($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
li $v0,10
syscall
