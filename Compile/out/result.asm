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
.text
test_if:
subi $sp, $sp, 156
lw $t0, -132($fp)
sw $t0, -140($fp)
lw $t0, -136($fp)
sw $t0, -144($fp)
lw $t0, -140($fp)
lw $t1, -144($fp)
blt $t0, $t1, label0
li $t0, 97
sw $t0, -148($fp)
j label1
label0:
li $t0, 98
sw $t0, -152($fp)
label1:
main:
subi $sp, $sp, 180
li $t3, 3
li $t4, 44
li $t5, -555
li $t0, 1
sw $t0, -148($fp)
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
li $t0, 2
sw $t0, -152($fp)
lw $t0, -152($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
jal test_if
sw $t0, -156($fp)
lw $t0, -156($fp)
