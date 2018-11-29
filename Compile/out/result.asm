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
test_if:
subi $sp, $sp, 28
sw $ra, 0($sp)
lw $t0, 4($sp)
sw $t0, 12($sp)
lw $t0, 8($sp)
sw $t0, 16($sp)
lw $t0, 12($sp)
lw $t1, 16($sp)
bltz $t0, $t1, label0
li $t0, 97
sw $t0, 20($sp)
lw $v0, 20($sp)
lw $ra, 0($sp)
addi $sp, $sp, 28
jr $ra
j label1
label0:
li $t0, 98
sw $t0, 24($sp)
lw $v0, 24($sp)
lw $ra, 0($sp)
addi $sp, $sp, 28
jr $ra
label1:
main:
subi $sp, $sp, 52
sw $ra, 0($sp)
li $t0, 3
sw $t0, 4($sp)
li $t0, 44
sw $t0, 8($sp)
li $t0, -555
sw $t0, 12($sp)
li $t0, 1
sw $t0, 20($sp)
li $t0, 2
sw $t0, 24($sp)
jal test_if
