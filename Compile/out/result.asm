.data
a: .space 4
$enter: .asciiz "\n"
.text
j main
#FUNC, void, , test
test:
add $fp, $sp, 0
subi $sp, $sp, 136
#LI, 97, , $temp0
li $t0, 97
sw $t0, -128($fp)
#PRT, 0, , $temp0
li $v0, 11
lw $a0, -128($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 136
jr $ra
#FUNC, int, , b
b:
add $fp, $sp, 0
subi $sp, $sp, 140
#LI, 98, , $temp1
li $t0, 98
sw $t0, -128($fp)
#PRT, 0, , $temp1
li $v0, 11
lw $a0, -128($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 1, , $temp2
li $t0, 1
sw $t0, -132($fp)
#RET, , , $temp2
lw $v0, -132($fp)
addi $sp, $sp, 140
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 132
#CALL, , , b
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
jal b
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
#CALL, , , test
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
jal test
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
#REN, , , 
li $v0,10
syscall
