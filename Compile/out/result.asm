.data
con: .word 10
glb: .space 4
$enter: .asciiz "\n"
.text
j main
# FUNC, void, , testmap
testmap:
add $fp, $sp, 0
subi $sp, $sp, 176
# VAR, int, , a
# VAR, int, , b
# VAR, int, , c
# LI, 3, , a
li $s2, 3
# LI, 2, , b
li $s1, 2
# LI, 3, , c
li $s0, 3
# LI, 2, , b
li $s1, 2
# LI, 3, , c
li $s0, 3
# LI, 3, , c
li $s0, 3
# REN, , , 
addi $sp, $sp, 176
jr $ra
# FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 384
# CON, int, 20, loc_con
li $t0, 20
sw $t0, -128($fp)
# VAR, int, , a
# VAR, int, , b
# VAR, int, , c
# VAR, int, , d
# ARY, int, 10, array
# VAR, char, , ch
# ADD, 10, glb, a
la $t1, glb
lw $t1, 0($t1)
add $s0, $t1, 10
# ADD, a, 2, a
add $s0, $s0, 2
# LI, 2, , b
li $s2, 2
# LI, 3, , c
li $s1, 3
# SUB, 0, 1, $temp16
# LI, -1, , d
li $s3, -1
# ADD, a, b, $temp17
add $t2, $s0, $s2
# ADD, $temp17, c, c
add $s1, $t2, $s1
# PRT, 0, , c
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# MUL, a, b, $temp19
mult $s0, $s2
mflo $t3
# MUL, $temp19, c, $temp20
mult $t3, $s1
mflo $t4
# MUL, a, b, $temp21
mult $s0, $s2
mflo $t5
# ADD, $temp20, $temp21, $temp22
add $t6, $t4, $t5
# ADD, a, 1, $temp24
add $t7, $s0, 1
# ADD, $temp22, $temp24, $temp25
add $t8, $t6, $t7
# ADD, $temp25, 5, c
add $s1, $t8, 5
# PRT, 0, , c
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# ADD, a, b, $temp30
add $t9, $s0, $s2
# ADD, a, b, $temp31
add $t0, $s0, $s2
# ADD, $temp30, $temp31, $temp32
add $t1, $t9, $t0
# ADD, a, 1, $temp34
add $t2, $s0, 1
# ADD, $temp32, $temp34, d
add $s3, $t1, $t2
# PRT, 0, , d
li $v0, 1
lw $a0, -144($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# LI, 97, , ch
li $s4, 97
# PRT, 0, , ch
li $v0, 11
lw $a0, -188($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
# ADD, c, 20, $temp37
add $t3, $s1, 20
# ADD, $temp37, 3, $temp39
add $t4, $t3, 3
# SUB, $temp39, 1, $temp41
sub $t5, $t4, 1
# ADD, $temp41, 190, $temp53
add $t6, $t5, 190
# ADD, $temp53, b, a
add $s0, $t6, $s2
# REN, , , 
li $v0,10
syscall
