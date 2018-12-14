.data
con_int_1: .word 1
con_int_2: .word 2
$enter: .asciiz "\n"
.text
j main
#FUNC, int, , test_para
test_para:
add $fp, $sp, 20
subi $sp, $sp, 152
#PARA, char, , a
#PARA, int, , b
#PARA, int, , c
#PARA, int, , con_int_1
#PARA, int, , con_int_2
#LVAR, a, , $temp0
lw $t0, 0($fp)
sw $t0, -148($fp)
#LVAR, b, , $temp1
lw $t0, -4($fp)
sw $t0, -152($fp)
#ADD, $temp0, $temp1, $temp0
lw $t0, -148($fp)
lw $t1, -152($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, c, , $temp2
lw $t0, -8($fp)
sw $t0, -156($fp)
#ADD, $temp0, $temp2, $temp0
lw $t0, -148($fp)
lw $t1, -156($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, con_int_1, , $temp3
lw $t0, -12($fp)
sw $t0, -160($fp)
#ADD, $temp0, $temp3, $temp0
lw $t0, -148($fp)
lw $t1, -160($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, con_int_2, , $temp4
lw $t0, -16($fp)
sw $t0, -164($fp)
#ADD, $temp0, $temp4, $temp0
lw $t0, -148($fp)
lw $t1, -164($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#RET, , , $temp0
lw $v0, -148($fp)
addi $sp, $sp, 172
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 244
#VAR, int, , a
#VAR, int, , b
#VAR, int, , c
#VAR, int, , d
#VAR, char, , ch
#ARY, int, 10, array
#VAR, int, , $temp5
#LVAR, a, , $temp6
move $t0, $t2
sw $t0, -192($fp)
#LARY, array, $temp6, $temp5
lw $t0, -192($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -188($fp)
#LVAR, $temp5, , a
lw $t0, -188($fp)
move $t2, $t0
#VAR, int, , $temp7
#LI, 2, , $temp8
li $t0, 2
sw $t0, -200($fp)
#LARY, array, $temp8, $temp7
lw $t0, -200($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -196($fp)
#LVAR, $temp7, , a
lw $t0, -196($fp)
move $t2, $t0
#LVAR, a, , $temp9
move $t0, $t2
sw $t0, -204($fp)
#LVAR, a, , $temp10
move $t0, $t2
sw $t0, -208($fp)
#SARY, array, $temp9, $temp10
lw $t0, -204($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t1, -208($fp)
sw $t1, ($t0)
#LVAR, con_int_1, , $temp11
la $t1, con_int_1
lw $t0, 0($t1)
sw $t0, -212($fp)
#LI, 5, , $temp12
li $t0, 5
sw $t0, -216($fp)
#SARY, array, $temp11, $temp12
lw $t0, -212($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t1, -216($fp)
sw $t1, ($t0)
#LI, 3, , $temp13
li $t0, 3
sw $t0, -220($fp)
#LI, 4, , $temp14
li $t0, 4
sw $t0, -224($fp)
#SARY, array, $temp13, $temp14
lw $t0, -220($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t1, -224($fp)
sw $t1, ($t0)
#LI, 1, , $temp15
li $t0, 1
sw $t0, -228($fp)
#LI, 0, , $temp16
li $t0, 0
sw $t0, -232($fp)
#SUB, $temp16, $temp15, $temp15
lw $t0, -232($fp)
lw $t1, -228($fp)
sub $t0, $t0, $t1
sw $t0, -228($fp)
#LI, 10, , $temp17
li $t0, 10
sw $t0, -236($fp)
#SARY, array, $temp15, $temp17
lw $t0, -228($fp)
mul $t0, $t0, 4
addi $t1, $fp, -148
sub $t0, $t1, $t0
lw $t1, -236($fp)
sw $t1, ($t0)
#REN, , , 
li $v0,10
syscall
