.data
$enter: .asciiz "\n"
.text
j main
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 152
#LI, 99, , $temp0
li $t0, 99
sw $t0, -128($fp)
#LI, 97, , $temp1
li $t0, 97
sw $t0, -132($fp)
#SUB, $temp0, $temp1, $temp0
lw $t0, -128($fp)
lw $t1, -132($fp)
sub $t0, $t0, $t1
sw $t0, -128($fp)
#LI, 98, , $temp2
li $t0, 98
sw $t0, -136($fp)
#LI, 97, , $temp3
li $t0, 97
sw $t0, -140($fp)
#SUB, $temp2, $temp3, $temp2
lw $t0, -136($fp)
lw $t1, -140($fp)
sub $t0, $t0, $t1
sw $t0, -136($fp)
#SUB, $temp0, $temp2, $temp0
lw $t0, -128($fp)
lw $t1, -136($fp)
sub $t0, $t0, $t1
sw $t0, -128($fp)
#PRT, 0, , $temp0
li $v0, 11
lw $a0, -128($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
li $v0,10
syscall
