.data
max_num: .word 1024
$string0: .asciiz " x = "
$string1: .asciiz " y = "
$string2: .asciiz " SWAP x = "
$string3: .asciiz " SWAP y = "
$string4: .asciiz " OVERFLOW!          "
$string5: .asciiz " complete number: "
$string6: .asciiz "  "
$string7: .asciiz "          "
$string8: .asciiz " ---------------------------------------------------------------          "
$string9: .asciiz " b = "
$string10: .asciiz " "
$string11: .asciiz "          The total is "
$string12: .asciiz " 10! = "
$enter: .asciiz "\n"
.text
j main
# FUNC, int, , factorial
factorial:
addu $fp, $sp, 4
subi $sp, $sp, 156
lw $s0, 0($fp)
# PARA, int, , n
# BGT, n, 1, $label0
li $t0, 1
#clearReg(3)
bgt $s0, $t0, $label0
# RET, , , 1
li $v0, 1
addi $sp, $sp, 160
jr $ra
# JUMP, , , $label1
#clearReg(3)
j $label1
# LAB, , , $label0
#clearReg(3)
$label0:
# SUB, n, 1, $temp4
subi $t0, $s0, 1
# PUSH, , , $temp4
sw $t0, ($sp)
subi $sp, $sp, 4
# CALL, , , factorial
#clearRegs(1)
sw $s0, 0($fp)
sw $t0, -144($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal factorial
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, 0($fp)
# VOF, factorial, , $temp2
move $t0, $v0
# MUL, n, $temp2, $temp5
mul $t1, $s0, $t0
# RET, , , $temp5
move $v0, $t1
addi $sp, $sp, 160
jr $ra
# LAB, , , $label1
#clearReg(3)
$label1:
# FUNC, int, , mod
mod:
addu $fp, $sp, 8
subi $sp, $sp, 144
lw $s0, 0($fp)
lw $s1, -4($fp)
# PARA, int, , x
# PARA, int, , y
# DIV, x, y, $temp6
div $s0, $s1
mflo $t0
# MUL, $temp6, y, $temp7
mul $t1, $t0, $s1
# SUB, x, $temp7, x
subu $s0, $s0, $t1
# RET, , , x
move $v0, $s0
addi $sp, $sp, 152
jr $ra
# FUNC, void, , swap
swap:
addu $fp, $sp, 8
subi $sp, $sp, 136
lw $s0, 0($fp)
lw $s1, -4($fp)
# PARA, int, , x
# PARA, int, , y
# VAR, int, , temp
# PRT, 2, 0, x
li $v0, 4
la $a0, $string0
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 2, 1, y
li $v0, 4
la $a0, $string1
syscall
li $v0, 1
move $a0, $s1
syscall
li $v0, 4
la $a0, $enter
syscall
# LVAR, x, , temp
move $s2, $s0
# LVAR, y, , x
move $s0, $s1
# LVAR, temp, , y
move $s1, $s2
# PRT, 2, 2, x
li $v0, 4
la $a0, $string2
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 2, 3, y
li $v0, 4
la $a0, $string3
syscall
li $v0, 1
move $a0, $s1
syscall
li $v0, 4
la $a0, $enter
syscall
# REN, , , 
addi $sp, $sp, 144
jr $ra
# FUNC, void, , complete_num
complete_num:
addu $fp, $sp, 4
subi $sp, $sp, 924
# PARA, int, , val
# ARY, int, 128, k
# VAR, int, , i
# VAR, int, , j
# VAR, int, , n
# VAR, int, , s
# VAR, int, , x1
# VAR, int, , m
# VAR, int, , k2
# VAR, int, , h
# VAR, int, , leap
# VAR, int, , x2
# VAR, int, , a
# VAR, int, , b
# VAR, int, , c
# LVAR, val, , j
lw $t0, 0($fp)
move $s1, $t0
# LAB, , , $label3
#clearReg(3)
$label3:
# SUB, 0, 1, $temp11
# LI, -1, , n
li $s4, -1
# LVAR, j, , s
move $t0, $s1
# LI, 1, , i
li $s0, 1
# LAB, , , $label6
#clearReg(3)
$label6:
# DIV, j, i, $temp13
div $s1, $s0
mflo $t0
# MUL, $temp13, i, x1
mul $t1, $t0, $s0
# PUSH, , , j
sw $s1, ($sp)
subi $sp, $sp, 4
# PUSH, , , i
sw $s0, ($sp)
subi $sp, $sp, 4
# CALL, , , mod
#clearRegs(1)
sw $s0, -644($fp)
sw $s1, -648($fp)
sw $s2, -664($fp)
sw $s3, -684($fp)
sw $s4, -652($fp)
sw $s5, -688($fp)
sw $s6, -672($fp)
sw $s7, -676($fp)
sw $t0, -712($fp)
sw $t1, -660($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal mod
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -644($fp)
lw $s1, -648($fp)
lw $s2, -664($fp)
lw $s3, -684($fp)
lw $s4, -652($fp)
lw $s5, -688($fp)
lw $s6, -672($fp)
lw $s7, -676($fp)
# VOF, mod, , $temp15
move $t0, $v0
# LI, 0, , $temp16
li $t1, 0
# BNE, $temp15, $temp16, $label8
#clearReg(3)
bne $t0, $t1, $label8
# ADD, n, 1, n
addi $s4, $s4, 1
# SUB, s, i, s
lw $t0, -656($fp)
subu $t0, $t0, $s0
# BLT, n, 128, $label10
li $t1, 128
#clearReg(3)
blt $s4, $t1, $label10
# PRT, 1, , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label11
#clearReg(3)
j $label11
# LAB, , , $label10
#clearReg(3)
$label10:
# SARY, k, n, i
sll $a2, $s4, 2
addi $a3, $fp, -132
subu $a3, $a3, $a2
sw $s0, ($a3)
# LAB, , , $label11
#clearReg(3)
$label11:
# JUMP, , , $label9
#clearReg(3)
j $label9
# LAB, , , $label8
#clearReg(3)
$label8:
# LAB, , , $label9
#clearReg(3)
$label9:
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label5
#clearReg(3)
$label5:
# BGE, i, j, $label7
#clearReg(3)
bge $s0, $s1, $label7
# JUMP, , , $label6
#clearReg(3)
j $label6
# LAB, , , $label7
#clearReg(3)
$label7:
# LI, 0, , $temp23
li $t0, 0
# BNE, s, $temp23, $label12
lw $t1, -656($fp)
#clearReg(3)
bne $t1, $t0, $label12
# PRT, 2, 5, j
li $v0, 4
la $a0, $string5
syscall
li $v0, 1
move $a0, $s1
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 0, , i
li $s0, 0
# LAB, , , $label15
#clearReg(3)
$label15:
# LARY, k, i, $temp25
sll $a2, $s0, 2
addi $a3, $fp, -132
subu $a3, $a3, $a2
lw $t0, ($a3)
# PRT, 2, 6, $temp25
li $v0, 4
la $a0, $string6
syscall
li $v0, 1
move $a0, $t0
syscall
li $v0, 4
la $a0, $enter
syscall
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label14
#clearReg(3)
$label14:
# BGT, i, n, $label16
#clearReg(3)
bgt $s0, $s4, $label16
# JUMP, , , $label15
#clearReg(3)
j $label15
# LAB, , , $label16
#clearReg(3)
$label16:
# PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label13
#clearReg(3)
j $label13
# LAB, , , $label12
#clearReg(3)
$label12:
# LAB, , , $label13
#clearReg(3)
$label13:
# ADD, j, 1, j
addi $s1, $s1, 1
# LAB, , , $label2
#clearReg(3)
$label2:
# BGE, j, 1024, $label4
li $t0, 1024
#clearReg(3)
bge $s1, $t0, $label4
# JUMP, , , $label3
#clearReg(3)
j $label3
# LAB, , , $label4
#clearReg(3)
$label4:
# PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 0, , a
li $s3, 0
# LI, 0, , i
li $s0, 0
# LAB, , , $label18
#clearReg(3)
$label18:
# MUL, a, i, b
mul $s5, $s3, $s0
# MUL, j, n, c
mul $t0, $s1, $s4
# MUL, a, i, a
mul $s3, $s3, $s0
# ADD, a, b, $temp35
addu $t1, $s3, $s5
# ADD, $temp35, c, a
addu $s3, $t1, $t0
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label17
#clearReg(3)
$label17:
# BGE, i, 1024, $label19
li $t0, 1024
#clearReg(3)
bge $s0, $t0, $label19
# JUMP, , , $label18
#clearReg(3)
j $label18
# LAB, , , $label19
#clearReg(3)
$label19:
# LVAR, a, , b
move $s5, $s3
# LI, 0, , i
li $s0, 0
# LAB, , , $label21
#clearReg(3)
$label21:
# ADD, b, i, b
addu $s5, $s5, $s0
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label20
#clearReg(3)
$label20:
# BGE, i, 1024, $label22
li $t0, 1024
#clearReg(3)
bge $s0, $t0, $label22
# JUMP, , , $label21
#clearReg(3)
j $label21
# LAB, , , $label22
#clearReg(3)
$label22:
# PRT, 2, 9, b
li $v0, 4
la $a0, $string9
syscall
li $v0, 1
move $a0, $s5
syscall
li $v0, 4
la $a0, $enter
syscall
# PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0, $enter
syscall
# LI, 0, , h
li $s6, 0
# LI, 1, , leap
li $s7, 1
# LI, 2, , m
li $s2, 2
# LAB, , , $label24
#clearReg(3)
$label24:
# DIV, m, 2, k2
li $t0, 2
div $s2, $t0
mflo $t1
# LI, 2, , i
li $s0, 2
# LAB, , , $label27
#clearReg(3)
$label27:
# DIV, m, i, $temp49
div $s2, $s0
mflo $t0
# MUL, $temp49, i, x2
mul $t1, $t0, $s0
# PUSH, , , m
sw $s2, ($sp)
subi $sp, $sp, 4
# PUSH, , , i
sw $s0, ($sp)
subi $sp, $sp, 4
# CALL, , , mod
#clearRegs(1)
sw $s0, -644($fp)
sw $s1, -648($fp)
sw $s2, -664($fp)
sw $s3, -684($fp)
sw $s4, -652($fp)
sw $s5, -688($fp)
sw $s6, -672($fp)
sw $s7, -676($fp)
sw $t0, -856($fp)
sw $t1, -680($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal mod
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -644($fp)
lw $s1, -648($fp)
lw $s2, -664($fp)
lw $s3, -684($fp)
lw $s4, -652($fp)
lw $s5, -688($fp)
lw $s6, -672($fp)
lw $s7, -676($fp)
# VOF, mod, , $temp51
move $t0, $v0
# LI, 0, , $temp52
li $t1, 0
# BNE, $temp51, $temp52, $label29
#clearReg(3)
bne $t0, $t1, $label29
# LI, 0, , leap
li $s7, 0
# JUMP, , , $label30
#clearReg(3)
j $label30
# LAB, , , $label29
#clearReg(3)
$label29:
# LAB, , , $label30
#clearReg(3)
$label30:
# ADD, i, 1, i
addi $s0, $s0, 1
# LAB, , , $label26
#clearReg(3)
$label26:
# BGT, i, k2, $label28
lw $t0, -668($fp)
#clearReg(3)
bgt $s0, $t0, $label28
# JUMP, , , $label27
#clearReg(3)
j $label27
# LAB, , , $label28
#clearReg(3)
$label28:
# BNE, leap, 1, $label31
li $t0, 1
#clearReg(3)
bne $s7, $t0, $label31
# PRT, 2, 10, m
li $v0, 4
la $a0, $string10
syscall
li $v0, 1
move $a0, $s2
syscall
li $v0, 4
la $a0, $enter
syscall
# ADD, h, 1, h
addi $s6, $s6, 1
# DIV, h, 10, $temp60
li $t0, 10
div $s6, $t0
mflo $t1
# MUL, $temp60, 10, x2
mul $t2, $t1, $t0
# BNE, x2, h, $label33
#clearReg(3)
bne $t2, $s6, $label33
# PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0, $enter
syscall
# JUMP, , , $label34
#clearReg(3)
j $label34
# LAB, , , $label33
#clearReg(3)
$label33:
# LAB, , , $label34
#clearReg(3)
$label34:
# JUMP, , , $label32
#clearReg(3)
j $label32
# LAB, , , $label31
#clearReg(3)
$label31:
# LAB, , , $label32
#clearReg(3)
$label32:
# LI, 1, , leap
li $s7, 1
# ADD, m, 1, m
addi $s2, $s2, 1
# LAB, , , $label23
#clearReg(3)
$label23:
# BGT, m, 1024, $label25
li $t0, 1024
#clearReg(3)
bgt $s2, $t0, $label25
# JUMP, , , $label24
#clearReg(3)
j $label24
# LAB, , , $label25
#clearReg(3)
$label25:
# PRT, 2, 11, h
li $v0, 4
la $a0, $string11
syscall
li $v0, 1
move $a0, $s6
syscall
li $v0, 4
la $a0, $enter
syscall
# REN, , , 
addi $sp, $sp, 928
jr $ra
# FUNC, void, , main
main:
addu $fp, $sp, 0
subi $sp, $sp, 156
# VAR, int, , n
# PUSH, , , 10
li $t0, 10
sw $t0, ($sp)
subi $sp, $sp, 4
# CALL, , , factorial
#clearRegs(1)
sw $s0, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal factorial
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, -128($fp)
# VOF, factorial, , $temp66
move $t0, $v0
# LVAR, $temp66, , n
move $s0, $t0
# PRT, 2, 12, n
li $v0, 4
la $a0, $string12
syscall
li $v0, 1
move $a0, $s0
syscall
li $v0, 4
la $a0, $enter
syscall
# PUSH, , , 5
li $t1, 5
sw $t1, ($sp)
subi $sp, $sp, 4
# PUSH, , , 10
li $t2, 10
sw $t2, ($sp)
subi $sp, $sp, 4
# CALL, , , swap
#clearRegs(1)
sw $s0, -128($fp)
sw $t0, -136($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal swap
lw $fp ,-128($sp)
lw $ra ,-132($sp)
lw $s0, -128($fp)
# PUSH, , , 2
li $t0, 2
sw $t0, ($sp)
subi $sp, $sp, 4
# CALL, , , complete_num
#clearRegs(1)
sw $s0, -128($fp)
sw $fp ,-120($sp)
sw $ra ,-124($sp)
jal complete_num
lw $fp ,-124($sp)
lw $ra ,-128($sp)
lw $s0, -128($fp)
