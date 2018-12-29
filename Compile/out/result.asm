.data
$enter: .asciiz "\n"
.text
j main
# FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 288
# VAR, int, , a
# VAR, int, , b
# VAR, int, , c
# VAR, int, , d
# ARY, int, 10, array
# LI, 1, , $temp0
li $t0, 1
sw $t0, -184($fp)
# LI, 0, , $temp1
li $t0, 0
sw $t0, -188($fp)
# SUB, $temp1, $temp0, $temp2
lw $t0, -188($fp)
lw $t1, -184($fp)
sub $t0, $t0, $t1
sw $t0, -192($fp)
# LI, 2, , $temp3
li $t0, 2
sw $t0, -196($fp)
# ADD, $temp2, $temp3, a
lw $t0, -192($fp)
lw $t1, -196($fp)
add $t0, $t0, $t1
move $t2, $t0
# LI, 2, , b
li $t0, 2
sw $t0, -132($fp)
# LI, 3, , c
li $t0, 3
sw $t0, -136($fp)
# LI, 1, , $temp7
li $t0, 1
sw $t0, -212($fp)
# LI, 0, , $temp8
li $t0, 0
sw $t0, -216($fp)
# SUB, $temp8, $temp7, d
lw $t0, -216($fp)
lw $t1, -212($fp)
sub $t0, $t0, $t1
move $t5, $t0
# ADD, a, b, $temp10
move $t0, $t2
move $t1, $t3
add $t0, $t0, $t1
sw $t0, -224($fp)
# ADD, $temp10, c, c
lw $t0, -224($fp)
move $t1, $t4
add $t0, $t0, $t1
move $t4, $t0
# PRT, 0, , c
li $v0, 1
lw $a0, -136($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# MUL, a, b, $temp12
move $t0, $t2
move $t1, $t3
mult $t0, $t1
mflo $t0
sw $t0, -232($fp)
# MUL, $temp12, c, $temp13
lw $t0, -232($fp)
move $t1, $t4
mult $t0, $t1
mflo $t0
sw $t0, -236($fp)
# MUL, a, b, $temp14
move $t0, $t2
move $t1, $t3
mult $t0, $t1
mflo $t0
sw $t0, -240($fp)
# ADD, $temp13, $temp14, $temp15
lw $t0, -236($fp)
lw $t1, -240($fp)
add $t0, $t0, $t1
sw $t0, -244($fp)
# LI, 1, , $temp16
li $t0, 1
sw $t0, -248($fp)
# ADD, a, $temp16, $temp17
move $t0, $t2
lw $t1, -248($fp)
add $t0, $t0, $t1
sw $t0, -252($fp)
# ADD, $temp15, $temp17, c
lw $t0, -244($fp)
lw $t1, -252($fp)
add $t0, $t0, $t1
move $t4, $t0
# PRT, 0, , c
li $v0, 1
lw $a0, -136($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# ADD, a, b, $temp19
move $t0, $t2
move $t1, $t3
add $t0, $t0, $t1
sw $t0, -260($fp)
# ADD, a, b, $temp20
move $t0, $t2
move $t1, $t3
add $t0, $t0, $t1
sw $t0, -264($fp)
# ADD, $temp19, $temp20, $temp21
lw $t0, -260($fp)
lw $t1, -264($fp)
add $t0, $t0, $t1
sw $t0, -268($fp)
# LI, 1, , $temp22
li $t0, 1
sw $t0, -272($fp)
# ADD, a, $temp22, $temp23
move $t0, $t2
lw $t1, -272($fp)
add $t0, $t0, $t1
sw $t0, -276($fp)
# ADD, $temp21, $temp23, d
lw $t0, -268($fp)
lw $t1, -276($fp)
add $t0, $t0, $t1
move $t5, $t0
# PRT, 0, , d
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# REN, , , 
li $v0,10
syscall
