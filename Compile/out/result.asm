.data
a: .word 1
b: .word 2
c: .word 97
x: .space 4
y: .space 4
_y1: .space 4
_z1: .space 4
judge: .space 4
$string0: .asciiz "wrongwhile1"
$string1: .asciiz "wrongwhile2"
$string2: .asciiz "wrongwhile3"
$string3: .asciiz "wrong1"
$string4: .asciiz "wrong2"
$string5: .asciiz "wrong3"
$string6: .asciiz "wrong4"
$string7: .asciiz "wrong5"
$string8: .asciiz "wrong6"
$string9: .asciiz "wrong7"
$string10: .asciiz "wrong8"
$string11: .asciiz "wrong9"
$string12: .asciiz "wrong10"
$string13: .asciiz "wrong11"
$string14: .asciiz "wrong12"
$string15: .asciiz "wrongt7t8neq\\n\\t\\r"
$string16: .asciiz "wrong\\n"
$string17: .asciiz "right\\n"
$enter: .asciiz "\n"
.text
j main
#FUNC, void, , init
init:
add $fp, $sp, 4
subi $sp, $sp, 136
#PARA, int, , m
#LVAR, m, , $temp0
lw $t0, 0($fp)
sw $t0, -132($fp)
#LVAR, $temp0, , x
lw $t0, -132($fp)
la $t1, x
sw $t0, 0($t1)
#REN, , , 
addi $sp, $sp, 140
jr $ra
#REN, , , 
addi $sp, $sp, 140
jr $ra
#FUNC, int, , add
add:
add $fp, $sp, 8
subi $sp, $sp, 140
#PARA, int, , m
#PARA, int, , n
#LVAR, m, , $temp1
lw $t0, 0($fp)
sw $t0, -136($fp)
#LVAR, n, , $temp2
lw $t0, -4($fp)
sw $t0, -140($fp)
#ADD, $temp1, $temp2, $temp1
lw $t0, -136($fp)
lw $t1, -140($fp)
add $t0, $t0, $t1
sw $t0, -136($fp)
#RET, , , $temp1
lw $v0, -136($fp)
addi $sp, $sp, 148
jr $ra
#FUNC, int, , addx
addx:
add $fp, $sp, 0
subi $sp, $sp, 160
#LVAR, x, , $temp3
la $t1, x
lw $t0, 0($t1)
sw $t0, -128($fp)
#LI, 1, , $temp4
li $t0, 1
sw $t0, -132($fp)
#ADD, $temp3, $temp4, $temp3
lw $t0, -128($fp)
lw $t1, -132($fp)
add $t0, $t0, $t1
sw $t0, -128($fp)
#LVAR, $temp3, , x
lw $t0, -128($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp5
la $t1, x
lw $t0, 0($t1)
sw $t0, -136($fp)
#LI, 99, , $temp6
li $t0, 99
sw $t0, -140($fp)
#BEQ, $temp5, $temp6, $label0
lw $t0, -136($fp)
lw $t1, -140($fp)
beq $t0, $t1, $label0
#LI, 100, , $temp7
li $t0, 100
sw $t0, -144($fp)
#LI, 0, , $temp8
li $t0, 0
sw $t0, -148($fp)
#SUB, $temp8, $temp7, $temp7
lw $t0, -148($fp)
lw $t1, -144($fp)
sub $t0, $t0, $t1
sw $t0, -144($fp)
#RET, , , $temp7
lw $v0, -144($fp)
addi $sp, $sp, 160
jr $ra
#JUMP, , , $label1
j $label1
#LAB, , , $label0
$label0:
#LI, 100, , $temp9
li $t0, 100
sw $t0, -152($fp)
#RET, , , $temp9
lw $v0, -152($fp)
addi $sp, $sp, 160
jr $ra
#LAB, , , $label1
$label1:
#FUNC, int, , addx1
addx1:
add $fp, $sp, 0
subi $sp, $sp, 144
#LVAR, x, , $temp10
la $t1, x
lw $t0, 0($t1)
sw $t0, -128($fp)
#LI, 1, , $temp11
li $t0, 1
sw $t0, -132($fp)
#ADD, $temp10, $temp11, $temp10
lw $t0, -128($fp)
lw $t1, -132($fp)
add $t0, $t0, $t1
sw $t0, -128($fp)
#LVAR, $temp10, , x
lw $t0, -128($fp)
la $t1, x
sw $t0, 0($t1)
#LI, 0, , $temp12
li $t0, 0
sw $t0, -136($fp)
#RET, , , $temp12
lw $v0, -136($fp)
addi $sp, $sp, 144
jr $ra
#FUNC, char, , tolow
tolow:
add $fp, $sp, 4
subi $sp, $sp, 144
#PARA, char, , c
#VAR, char, , d
#LVAR, c, , $temp13
lw $t0, 0($fp)
sw $t0, -136($fp)
#LVAR, $temp13, , d
lw $t0, -136($fp)
move $t2, $t0
#LVAR, d, , $temp14
move $t0, $t2
sw $t0, -140($fp)
#RET, , , $temp14
lw $v0, -140($fp)
addi $sp, $sp, 148
jr $ra
#FUNC, int, , fib
fib:
add $fp, $sp, 4
subi $sp, $sp, 212
#PARA, int, , x
#LVAR, x, , $temp15
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 1, , $temp16
li $t0, 1
sw $t0, -136($fp)
#BNE, $temp15, $temp16, $label2
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, $label2
#LI, 1, , $temp17
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp17
lw $v0, -140($fp)
addi $sp, $sp, 216
jr $ra
#JUMP, , , $label3
j $label3
#LAB, , , $label2
$label2:
#LVAR, x, , $temp18
lw $t0, 0($fp)
sw $t0, -144($fp)
#LI, 2, , $temp19
li $t0, 2
sw $t0, -148($fp)
#BNE, $temp18, $temp19, $label4
lw $t0, -144($fp)
lw $t1, -148($fp)
bne $t0, $t1, $label4
#LI, 1, , $temp20
li $t0, 1
sw $t0, -152($fp)
#RET, , , $temp20
lw $v0, -152($fp)
addi $sp, $sp, 216
jr $ra
#JUMP, , , $label5
j $label5
#LAB, , , $label4
$label4:
#LVAR, x, , $temp21
lw $t0, 0($fp)
sw $t0, -156($fp)
#LI, 100, , $temp22
li $t0, 100
sw $t0, -160($fp)
#LI, 0, , $temp23
li $t0, 0
sw $t0, -164($fp)
#SUB, $temp23, $temp22, $temp22
lw $t0, -164($fp)
lw $t1, -160($fp)
sub $t0, $t0, $t1
sw $t0, -160($fp)
#BNE, $temp21, $temp22, $label6
lw $t0, -156($fp)
lw $t1, -160($fp)
bne $t0, $t1, $label6
#LI, 100, , $temp24
li $t0, 100
sw $t0, -168($fp)
#LI, 0, , $temp25
li $t0, 0
sw $t0, -172($fp)
#SUB, $temp25, $temp24, $temp24
lw $t0, -172($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#RET, , , $temp24
lw $v0, -168($fp)
addi $sp, $sp, 216
jr $ra
#JUMP, , , $label7
j $label7
#LAB, , , $label6
$label6:
#LAB, , , $label7
$label7:
#LAB, , , $label5
$label5:
#LAB, , , $label3
$label3:
#LVAR, x, , $temp26
lw $t0, 0($fp)
sw $t0, -176($fp)
#LI, 2, , $temp27
li $t0, 2
sw $t0, -180($fp)
#BNE, $temp26, $temp27, $label8
lw $t0, -176($fp)
lw $t1, -180($fp)
bne $t0, $t1, $label8
#LI, 1, , $temp28
li $t0, 1
sw $t0, -184($fp)
#RET, , , $temp28
lw $v0, -184($fp)
addi $sp, $sp, 216
jr $ra
#JUMP, , , $label9
j $label9
#LAB, , , $label8
$label8:
#LAB, , , $label9
$label9:
#LVAR, x, , $temp30
lw $t0, 0($fp)
sw $t0, -188($fp)
#LI, 1, , $temp31
li $t0, 1
sw $t0, -192($fp)
#SUB, $temp30, $temp31, $temp30
lw $t0, -188($fp)
lw $t1, -192($fp)
sub $t0, $t0, $t1
sw $t0, -188($fp)
#PUSH, , , $temp30
lw $t0, -188($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp29
sw $v0, -196($fp)
#LVAR, x, , $temp33
lw $t0, 0($fp)
sw $t0, -200($fp)
#LI, 2, , $temp34
li $t0, 2
sw $t0, -204($fp)
#SUB, $temp33, $temp34, $temp33
lw $t0, -200($fp)
lw $t1, -204($fp)
sub $t0, $t0, $t1
sw $t0, -200($fp)
#PUSH, , , $temp33
lw $t0, -200($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp32
sw $v0, -208($fp)
#ADD, $temp29, $temp32, $temp29
lw $t0, -196($fp)
lw $t1, -208($fp)
add $t0, $t0, $t1
sw $t0, -196($fp)
#RET, , , $temp29
lw $v0, -196($fp)
addi $sp, $sp, 216
jr $ra
#FUNC, void, , testif
testif:
add $fp, $sp, 0
subi $sp, $sp, 328
#LVAR, x, , $temp35
la $t1, x
lw $t0, 0($t1)
sw $t0, -128($fp)
#LI, 98, , $temp36
li $t0, 98
sw $t0, -132($fp)
#LI, 97, , $temp37
li $t0, 97
sw $t0, -136($fp)
#SUB, $temp36, $temp37, $temp36
lw $t0, -132($fp)
lw $t1, -136($fp)
sub $t0, $t0, $t1
sw $t0, -132($fp)
#BNE, $temp35, $temp36, $label10
lw $t0, -128($fp)
lw $t1, -132($fp)
bne $t0, $t1, $label10
#LI, 1, , $temp38
li $t0, 1
sw $t0, -140($fp)
#LVAR, $temp38, , y
lw $t0, -140($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label11
j $label11
#LAB, , , $label10
$label10:
#LI, 2, , $temp39
li $t0, 2
sw $t0, -144($fp)
#LVAR, $temp39, , y
lw $t0, -144($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label11
$label11:
#LVAR, y, , $temp40
la $t1, y
lw $t0, 0($t1)
sw $t0, -148($fp)
#LI, 1, , $temp41
li $t0, 1
sw $t0, -152($fp)
#BEQ, $temp40, $temp41, $label12
lw $t0, -148($fp)
lw $t1, -152($fp)
beq $t0, $t1, $label12
#LI, 0, , $temp42
li $t0, 0
sw $t0, -156($fp)
#LVAR, $temp42, , judge
lw $t0, -156($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label13
j $label13
#LAB, , , $label12
$label12:
#LAB, , , $label13
$label13:
#LVAR, x, , $temp43
la $t1, x
lw $t0, 0($t1)
sw $t0, -160($fp)
#LI, 1, , $temp44
li $t0, 1
sw $t0, -164($fp)
#BLT, $temp43, $temp44, $label14
lw $t0, -160($fp)
lw $t1, -164($fp)
blt $t0, $t1, $label14
#LI, 3, , $temp45
li $t0, 3
sw $t0, -168($fp)
#LVAR, $temp45, , y
lw $t0, -168($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label15
j $label15
#LAB, , , $label14
$label14:
#LI, 4, , $temp46
li $t0, 4
sw $t0, -172($fp)
#LVAR, $temp46, , y
lw $t0, -172($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label15
$label15:
#LVAR, y, , $temp47
la $t1, y
lw $t0, 0($t1)
sw $t0, -176($fp)
#LI, 3, , $temp48
li $t0, 3
sw $t0, -180($fp)
#BEQ, $temp47, $temp48, $label16
lw $t0, -176($fp)
lw $t1, -180($fp)
beq $t0, $t1, $label16
#LI, 0, , $temp49
li $t0, 0
sw $t0, -184($fp)
#LVAR, $temp49, , judge
lw $t0, -184($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label17
j $label17
#LAB, , , $label16
$label16:
#LAB, , , $label17
$label17:
#LVAR, x, , $temp50
la $t1, x
lw $t0, 0($t1)
sw $t0, -188($fp)
#LI, 1, , $temp51
li $t0, 1
sw $t0, -192($fp)
#ADD, $temp50, $temp51, $temp50
lw $t0, -188($fp)
lw $t1, -192($fp)
add $t0, $t0, $t1
sw $t0, -188($fp)
#LVAR, $temp50, , x
lw $t0, -188($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp52
la $t1, x
lw $t0, 0($t1)
sw $t0, -196($fp)
#LI, 1, , $temp53
li $t0, 1
sw $t0, -200($fp)
#BGT, $temp52, $temp53, $label18
lw $t0, -196($fp)
lw $t1, -200($fp)
bgt $t0, $t1, $label18
#LI, 5, , $temp54
li $t0, 5
sw $t0, -204($fp)
#LVAR, $temp54, , y
lw $t0, -204($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label19
j $label19
#LAB, , , $label18
$label18:
#LI, 6, , $temp55
li $t0, 6
sw $t0, -208($fp)
#LVAR, $temp55, , y
lw $t0, -208($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label19
$label19:
#LVAR, y, , $temp56
la $t1, y
lw $t0, 0($t1)
sw $t0, -212($fp)
#LI, 6, , $temp57
li $t0, 6
sw $t0, -216($fp)
#BEQ, $temp56, $temp57, $label20
lw $t0, -212($fp)
lw $t1, -216($fp)
beq $t0, $t1, $label20
#LI, 0, , $temp58
li $t0, 0
sw $t0, -220($fp)
#LVAR, $temp58, , judge
lw $t0, -220($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label21
j $label21
#LAB, , , $label20
$label20:
#LAB, , , $label21
$label21:
#LVAR, x, , $temp59
la $t1, x
lw $t0, 0($t1)
sw $t0, -224($fp)
#LI, 1, , $temp60
li $t0, 1
sw $t0, -228($fp)
#BLE, $temp59, $temp60, $label22
lw $t0, -224($fp)
lw $t1, -228($fp)
ble $t0, $t1, $label22
#LI, 7, , $temp61
li $t0, 7
sw $t0, -232($fp)
#LVAR, $temp61, , y
lw $t0, -232($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label23
j $label23
#LAB, , , $label22
$label22:
#LI, 8, , $temp62
li $t0, 8
sw $t0, -236($fp)
#LVAR, $temp62, , y
lw $t0, -236($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label23
$label23:
#LVAR, y, , $temp63
la $t1, y
lw $t0, 0($t1)
sw $t0, -240($fp)
#LI, 7, , $temp64
li $t0, 7
sw $t0, -244($fp)
#BEQ, $temp63, $temp64, $label24
lw $t0, -240($fp)
lw $t1, -244($fp)
beq $t0, $t1, $label24
#LI, 0, , $temp65
li $t0, 0
sw $t0, -248($fp)
#LVAR, $temp65, , judge
lw $t0, -248($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label25
j $label25
#LAB, , , $label24
$label24:
#LAB, , , $label25
$label25:
#LVAR, x, , $temp66
la $t1, x
lw $t0, 0($t1)
sw $t0, -252($fp)
#LI, 0, , $temp67
li $t0, 0
sw $t0, -256($fp)
#BGE, $temp66, $temp67, $label26
lw $t0, -252($fp)
lw $t1, -256($fp)
bge $t0, $t1, $label26
#LI, 9, , $temp68
li $t0, 9
sw $t0, -260($fp)
#LVAR, $temp68, , y
lw $t0, -260($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label27
j $label27
#LAB, , , $label26
$label26:
#LI, 10, , $temp69
li $t0, 10
sw $t0, -264($fp)
#LVAR, $temp69, , y
lw $t0, -264($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label27
$label27:
#LVAR, y, , $temp70
la $t1, y
lw $t0, 0($t1)
sw $t0, -268($fp)
#LI, 10, , $temp71
li $t0, 10
sw $t0, -272($fp)
#BEQ, $temp70, $temp71, $label28
lw $t0, -268($fp)
lw $t1, -272($fp)
beq $t0, $t1, $label28
#LI, 0, , $temp72
li $t0, 0
sw $t0, -276($fp)
#LVAR, $temp72, , judge
lw $t0, -276($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label29
j $label29
#LAB, , , $label28
$label28:
#LAB, , , $label29
$label29:
#LI, 8, , $temp74
li $t0, 8
sw $t0, -280($fp)
#PUSH, , , $temp74
lw $t0, -280($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp73
sw $v0, -284($fp)
#LI, 1, , $temp75
li $t0, 1
sw $t0, -288($fp)
#SUB, $temp73, $temp75, $temp73
lw $t0, -284($fp)
lw $t1, -288($fp)
sub $t0, $t0, $t1
sw $t0, -284($fp)
#LVAR, $temp73, , x
lw $t0, -284($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp76
la $t1, x
lw $t0, 0($t1)
sw $t0, -292($fp)
#LI, 20, , $temp77
li $t0, 20
sw $t0, -296($fp)
#BEQ, $temp76, $temp77, $label30
lw $t0, -292($fp)
lw $t1, -296($fp)
beq $t0, $t1, $label30
#LI, 11, , $temp78
li $t0, 11
sw $t0, -300($fp)
#LVAR, $temp78, , y
lw $t0, -300($fp)
la $t1, y
sw $t0, 0($t1)
#JUMP, , , $label31
j $label31
#LAB, , , $label30
$label30:
#LI, 12, , $temp79
li $t0, 12
sw $t0, -304($fp)
#LVAR, $temp79, , y
lw $t0, -304($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label31
$label31:
#LVAR, y, , $temp80
la $t1, y
lw $t0, 0($t1)
sw $t0, -308($fp)
#LI, 12, , $temp81
li $t0, 12
sw $t0, -312($fp)
#BEQ, $temp80, $temp81, $label32
lw $t0, -308($fp)
lw $t1, -312($fp)
beq $t0, $t1, $label32
#LI, 0, , $temp82
li $t0, 0
sw $t0, -316($fp)
#LVAR, $temp82, , judge
lw $t0, -316($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label33
j $label33
#LAB, , , $label32
$label32:
#LAB, , , $label33
$label33:
#LI, 2, , $temp83
li $t0, 2
sw $t0, -320($fp)
#LVAR, $temp83, , x
lw $t0, -320($fp)
la $t1, x
sw $t0, 0($t1)
#REN, , , 
addi $sp, $sp, 328
jr $ra
#FUNC, int, , testcase1
testcase1:
add $fp, $sp, 4
subi $sp, $sp, 156
#PARA, int, , x
#LVAR, x, , $temp84
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 1, , $temp85
li $t0, 1
sw $t0, -136($fp)
#BNE, $temp84, $temp85, $label35
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, $label35
#LI, 1, , $temp86
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp86
lw $v0, -140($fp)
addi $sp, $sp, 160
jr $ra
#JUMP, , , $label34
j $label34
#LAB, , , $label35
$label35:
#LI, 2, , $temp87
li $t0, 2
sw $t0, -144($fp)
#BNE, $temp84, $temp87, $label36
lw $t0, -132($fp)
lw $t1, -144($fp)
bne $t0, $t1, $label36
#LI, 2, , $temp88
li $t0, 2
sw $t0, -148($fp)
#RET, , , $temp88
lw $v0, -148($fp)
addi $sp, $sp, 160
jr $ra
#JUMP, , , $label34
j $label34
#LAB, , , $label36
$label36:
#LI, 3, , $temp89
li $t0, 3
sw $t0, -152($fp)
#RET, , , $temp89
lw $v0, -152($fp)
addi $sp, $sp, 160
jr $ra
#LAB, , , $label34
$label34:
#FUNC, int, , testcase2
testcase2:
add $fp, $sp, 4
subi $sp, $sp, 148
#PARA, char, , x
#LVAR, x, , $temp90
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 97, , $temp91
li $t0, 97
sw $t0, -136($fp)
#BNE, $temp90, $temp91, $label38
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, $label38
#LI, 1, , $temp92
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp92
lw $v0, -140($fp)
addi $sp, $sp, 152
jr $ra
#JUMP, , , $label37
j $label37
#LAB, , , $label38
$label38:
#LI, 2, , $temp93
li $t0, 2
sw $t0, -144($fp)
#RET, , , $temp93
lw $v0, -144($fp)
addi $sp, $sp, 152
jr $ra
#LAB, , , $label37
$label37:
#FUNC, void, , test_do_while
test_do_while:
add $fp, $sp, 4
subi $sp, $sp, 280
#PARA, int, , a
#LAB, , , $label40
$label40:
#CALL, , , addx1
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
jal addx1
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
#LAB, , , $label39
$label39:
#LVAR, x, , $temp95
la $t1, x
lw $t0, 0($t1)
sw $t0, -132($fp)
#LI, 3, , $temp96
li $t0, 3
sw $t0, -136($fp)
#LI, 2, , $temp97
li $t0, 2
sw $t0, -140($fp)
#ADD, $temp96, $temp97, $temp96
lw $t0, -136($fp)
lw $t1, -140($fp)
add $t0, $t0, $t1
sw $t0, -136($fp)
#BGE, $temp95, $temp96, $label41
lw $t0, -132($fp)
lw $t1, -136($fp)
bge $t0, $t1, $label41
#JUMP, , , $label40
j $label40
#LAB, , , $label41
$label41:
#LVAR, x, , $temp98
la $t1, x
lw $t0, 0($t1)
sw $t0, -144($fp)
#LI, 5, , $temp99
li $t0, 5
sw $t0, -148($fp)
#BEQ, $temp98, $temp99, $label42
lw $t0, -144($fp)
lw $t1, -148($fp)
beq $t0, $t1, $label42
#PRT, 1, , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp100
li $t0, 0
sw $t0, -152($fp)
#LVAR, $temp100, , judge
lw $t0, -152($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label43
j $label43
#LAB, , , $label42
$label42:
#LAB, , , $label43
$label43:
#LI, 3, , $temp101
li $t0, 3
sw $t0, -156($fp)
#LVAR, $temp101, , y
lw $t0, -156($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label45
$label45:
#LVAR, x, , $temp102
la $t1, x
lw $t0, 0($t1)
sw $t0, -160($fp)
#LI, 1, , $temp103
li $t0, 1
sw $t0, -164($fp)
#ADD, $temp102, $temp103, $temp102
lw $t0, -160($fp)
lw $t1, -164($fp)
add $t0, $t0, $t1
sw $t0, -160($fp)
#LVAR, $temp102, , x
lw $t0, -160($fp)
la $t1, x
sw $t0, 0($t1)
#LAB, , , $label44
$label44:
#LVAR, x, , $temp104
la $t1, x
lw $t0, 0($t1)
sw $t0, -168($fp)
#LI, 2, , $temp105
li $t0, 2
sw $t0, -172($fp)
#LI, 3, , $temp106
li $t0, 3
sw $t0, -176($fp)
#MUL, $temp105, $temp106, $temp105
lw $t0, -172($fp)
lw $t1, -176($fp)
mult $t0, $t1
mflo $t0
sw $t0, -172($fp)
#LI, 2, , $temp107
li $t0, 2
sw $t0, -180($fp)
#LI, 1, , $temp108
li $t0, 1
sw $t0, -184($fp)
#DIV, $temp107, $temp108, $temp107
lw $t0, -180($fp)
lw $t1, -184($fp)
div $t0, $t1
mflo $t0
sw $t0, -180($fp)
#ADD, $temp105, $temp107, $temp105
lw $t0, -172($fp)
lw $t1, -180($fp)
add $t0, $t0, $t1
sw $t0, -172($fp)
#BGE, $temp104, $temp105, $label46
lw $t0, -168($fp)
lw $t1, -172($fp)
bge $t0, $t1, $label46
#JUMP, , , $label45
j $label45
#LAB, , , $label46
$label46:
#LVAR, x, , $temp109
la $t1, x
lw $t0, 0($t1)
sw $t0, -192($fp)
#LI, 8, , $temp110
li $t0, 8
sw $t0, -196($fp)
#BEQ, $temp109, $temp110, $label47
lw $t0, -192($fp)
lw $t1, -196($fp)
beq $t0, $t1, $label47
#LI, 0, , $temp111
li $t0, 0
sw $t0, -200($fp)
#LVAR, $temp111, , judge
lw $t0, -200($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label48
j $label48
#LAB, , , $label47
$label47:
#LAB, , , $label48
$label48:
#LAB, , , $label50
$label50:
#LAB, , , $label53
$label53:
#LVAR, x, , $temp112
la $t1, x
lw $t0, 0($t1)
sw $t0, -204($fp)
#LI, 1, , $temp113
li $t0, 1
sw $t0, -208($fp)
#SUB, $temp112, $temp113, $temp112
lw $t0, -204($fp)
lw $t1, -208($fp)
sub $t0, $t0, $t1
sw $t0, -204($fp)
#LVAR, $temp112, , x
lw $t0, -204($fp)
la $t1, x
sw $t0, 0($t1)
#LAB, , , $label52
$label52:
#LVAR, x, , $temp114
la $t1, x
lw $t0, 0($t1)
sw $t0, -212($fp)
#LI, 1, , $temp115
li $t0, 1
sw $t0, -216($fp)
#LI, 2, , $temp116
li $t0, 2
sw $t0, -220($fp)
#LI, 3, , $temp117
li $t0, 3
sw $t0, -224($fp)
#SUB, $temp116, $temp117, $temp116
lw $t0, -220($fp)
lw $t1, -224($fp)
sub $t0, $t0, $t1
sw $t0, -220($fp)
#ADD, $temp115, $temp116, $temp115
lw $t0, -216($fp)
lw $t1, -220($fp)
add $t0, $t0, $t1
sw $t0, -216($fp)
#BLT, $temp114, $temp115, $label54
lw $t0, -212($fp)
lw $t1, -216($fp)
blt $t0, $t1, $label54
#JUMP, , , $label53
j $label53
#LAB, , , $label54
$label54:
#LVAR, y, , $temp118
la $t1, y
lw $t0, 0($t1)
sw $t0, -236($fp)
#LI, 1, , $temp119
li $t0, 1
sw $t0, -240($fp)
#SUB, $temp118, $temp119, $temp118
lw $t0, -236($fp)
lw $t1, -240($fp)
sub $t0, $t0, $t1
sw $t0, -236($fp)
#LVAR, $temp118, , y
lw $t0, -236($fp)
la $t1, y
sw $t0, 0($t1)
#LAB, , , $label49
$label49:
#LVAR, y, , $temp120
la $t1, y
lw $t0, 0($t1)
sw $t0, -244($fp)
#LI, 1, , $temp121
li $t0, 1
sw $t0, -248($fp)
#BLT, $temp120, $temp121, $label51
lw $t0, -244($fp)
lw $t1, -248($fp)
blt $t0, $t1, $label51
#JUMP, , , $label50
j $label50
#LAB, , , $label51
$label51:
#LVAR, x, , $temp122
la $t1, x
lw $t0, 0($t1)
sw $t0, -252($fp)
#LI, 3, , $temp123
li $t0, 3
sw $t0, -256($fp)
#LI, 0, , $temp124
li $t0, 0
sw $t0, -260($fp)
#SUB, $temp124, $temp123, $temp123
lw $t0, -260($fp)
lw $t1, -256($fp)
sub $t0, $t0, $t1
sw $t0, -256($fp)
#BEQ, $temp122, $temp123, $label55
lw $t0, -252($fp)
lw $t1, -256($fp)
beq $t0, $t1, $label55
#PRT, 1, , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp125
li $t0, 0
sw $t0, -264($fp)
#LVAR, $temp125, , judge
lw $t0, -264($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label56
j $label56
#LAB, , , $label55
$label55:
#LAB, , , $label56
$label56:
#LVAR, y, , $temp126
la $t1, y
lw $t0, 0($t1)
sw $t0, -268($fp)
#LI, 0, , $temp127
li $t0, 0
sw $t0, -272($fp)
#BEQ, $temp126, $temp127, $label57
lw $t0, -268($fp)
lw $t1, -272($fp)
beq $t0, $t1, $label57
#PRT, 1, , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp128
li $t0, 0
sw $t0, -276($fp)
#LVAR, $temp128, , judge
lw $t0, -276($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label58
j $label58
#LAB, , , $label57
$label57:
#LAB, , , $label58
$label58:
#REN, , , 
addi $sp, $sp, 284
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 1440
#CON, int, 1, t1
li $t2, 1
#CON, int, 2, t2
li $t3, 2
#CON, char, 97, t3
li $t4, 97
#CON, int, 123, tt1
li $t5, 123
#CON, int, -909, tt2
li $t6, -909
#VAR, int, , t4
#VAR, int, , t5
#ARY, int, 100, aa
#VAR, int, , t6
#VAR, char, , t7
#VAR, char, , t8
#ARY, char, 100, t9
#LI, 1, , $temp129
li $t0, 1
sw $t0, -968($fp)
#LVAR, $temp129, , judge
lw $t0, -968($fp)
la $t1, judge
sw $t0, 0($t1)
#LVAR, t3, , $temp130
move $t0, $t4
sw $t0, -972($fp)
#LVAR, $temp130, , t7
lw $t0, -972($fp)
sw $t0, -560($fp)
#LI, 10, , $temp131
li $t0, 10
sw $t0, -976($fp)
#LVAR, t7, , $temp133
lw $t0, -560($fp)
sw $t0, -980($fp)
#PUSH, , , $temp133
lw $t0, -980($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , tolow
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
jal tolow
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
#VOF, tolow, , $temp132
sw $v0, -984($fp)
#SARY, t9, $temp131, $temp132
lw $t0, -976($fp)
mul $t0, $t0, 4
addi $t1, $fp, -568
sub $t0, $t1, $t0
lw $t1, -984($fp)
sw $t1, ($t0)
#LI, 10, , $temp134
li $t0, 10
sw $t0, -988($fp)
#LI, 5, , $temp136
li $t0, 5
sw $t0, -992($fp)
#PUSH, , , $temp136
lw $t0, -992($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp135
sw $v0, -996($fp)
#SARY, aa, $temp134, $temp135
lw $t0, -988($fp)
mul $t0, $t0, 4
addi $t1, $fp, -156
sub $t0, $t1, $t0
lw $t1, -996($fp)
sw $t1, ($t0)
#LI, 3, , $temp138
li $t0, 3
sw $t0, -1000($fp)
#PUSH, , , $temp138
lw $t0, -1000($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp137
sw $v0, -1004($fp)
#LVAR, $temp137, , t4
lw $t0, -1004($fp)
move $t7, $t0
#VAR, char, , $temp139
#LI, 10, , $temp140
li $t0, 10
sw $t0, -1012($fp)
#LARY, t9, $temp140, $temp139
lw $t0, -1012($fp)
mul $t0, $t0, 4
addi $t1, $fp, -568
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -1008($fp)
#VAR, char, , $temp141
#LI, 10, , $temp142
li $t0, 10
sw $t0, -1020($fp)
#LARY, aa, $temp142, $temp141
lw $t0, -1020($fp)
mul $t0, $t0, 4
addi $t1, $fp, -156
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -1016($fp)
#LI, -1, , $temp143
li $t0, -1
sw $t0, -1024($fp)
#MUL, $temp141, $temp143, $temp141
lw $t0, -1016($fp)
lw $t1, -1024($fp)
mult $t0, $t1
mflo $t0
sw $t0, -1016($fp)
#LVAR, t4, , $temp144
move $t0, $t7
sw $t0, -1028($fp)
#MUL, $temp141, $temp144, $temp141
lw $t0, -1016($fp)
lw $t1, -1028($fp)
mult $t0, $t1
mflo $t0
sw $t0, -1016($fp)
#ADD, $temp139, $temp141, $temp139
lw $t0, -1008($fp)
lw $t1, -1016($fp)
add $t0, $t0, $t1
sw $t0, -1008($fp)
#LI, 8, , $temp145
li $t0, 8
sw $t0, -1036($fp)
#LI, 4, , $temp146
li $t0, 4
sw $t0, -1040($fp)
#DIV, $temp145, $temp146, $temp145
lw $t0, -1036($fp)
lw $t1, -1040($fp)
div $t0, $t1
mflo $t0
sw $t0, -1036($fp)
#DIV, $temp139, $temp145, $temp139
lw $t0, -1008($fp)
lw $t1, -1036($fp)
div $t0, $t1
mflo $t0
sw $t0, -1008($fp)
#LI, 48, , $temp147
li $t0, 48
sw $t0, -1048($fp)
#SUB, $temp139, $temp147, $temp139
lw $t0, -1008($fp)
lw $t1, -1048($fp)
sub $t0, $t0, $t1
sw $t0, -1008($fp)
#LVAR, tt1, , $temp148
move $t0, $t5
sw $t0, -1052($fp)
#ADD, $temp139, $temp148, $temp139
lw $t0, -1008($fp)
lw $t1, -1052($fp)
add $t0, $t0, $t1
sw $t0, -1008($fp)
#LI, -118, , $temp149
li $t0, -118
sw $t0, -1056($fp)
#LI, 0, , $temp150
li $t0, 0
sw $t0, -1060($fp)
#SUB, $temp150, $temp149, $temp149
lw $t0, -1060($fp)
lw $t1, -1056($fp)
sub $t0, $t0, $t1
sw $t0, -1056($fp)
#BEQ, $temp139, $temp149, $label59
lw $t0, -1008($fp)
lw $t1, -1056($fp)
beq $t0, $t1, $label59
#PRT, 1, , 3
li $v0, 4
la $a0, $string3
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp151
li $t0, 0
sw $t0, -1064($fp)
#LVAR, $temp151, , judge
lw $t0, -1064($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label60
j $label60
#LAB, , , $label59
$label59:
#LVAR, tt2, , $temp152
move $t0, $t6
sw $t0, -1068($fp)
#LI, 48, , $temp154
li $t0, 48
sw $t0, -1072($fp)
#PUSH, , , $temp154
lw $t0, -1072($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , tolow
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
jal tolow
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
#VOF, tolow, , $temp153
sw $v0, -1076($fp)
#ADD, $temp152, $temp153, $temp152
lw $t0, -1068($fp)
lw $t1, -1076($fp)
add $t0, $t0, $t1
sw $t0, -1068($fp)
#LI, 861, , $temp155
li $t0, 861
sw $t0, -1080($fp)
#LI, 0, , $temp156
li $t0, 0
sw $t0, -1084($fp)
#SUB, $temp156, $temp155, $temp155
lw $t0, -1084($fp)
lw $t1, -1080($fp)
sub $t0, $t0, $t1
sw $t0, -1080($fp)
#BEQ, $temp152, $temp155, $label61
lw $t0, -1068($fp)
lw $t1, -1080($fp)
beq $t0, $t1, $label61
#LVAR, tt2, , $temp157
move $t0, $t6
sw $t0, -1088($fp)
#LI, 48, , $temp159
li $t0, 48
sw $t0, -1092($fp)
#PUSH, , , $temp159
lw $t0, -1092($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , tolow
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
jal tolow
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
#VOF, tolow, , $temp158
sw $v0, -1096($fp)
#ADD, $temp157, $temp158, $temp157
lw $t0, -1088($fp)
lw $t1, -1096($fp)
add $t0, $t0, $t1
sw $t0, -1088($fp)
#PRT, 2, 4, $temp157
li $v0, 4
la $a0, $string4
syscall
li $v0, 1
lw $a0, -1088($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp160
li $t0, 0
sw $t0, -1100($fp)
#LVAR, $temp160, , judge
lw $t0, -1100($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label62
j $label62
#LAB, , , $label61
$label61:
#LAB, , , $label62
$label62:
#LAB, , , $label60
$label60:
#LI, 2, , $temp161
li $t0, 2
sw $t0, -1104($fp)
#PUSH, , , $temp161
lw $t0, -1104($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , init
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
jal init
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
#LVAR, x, , $temp162
la $t1, x
lw $t0, 0($t1)
sw $t0, -1108($fp)
#LI, 2, , $temp163
li $t0, 2
sw $t0, -1112($fp)
#BEQ, $temp162, $temp163, $label63
lw $t0, -1108($fp)
lw $t1, -1112($fp)
beq $t0, $t1, $label63
#PRT, 1, , 5
li $v0, 4
la $a0, $string5
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp164
li $t0, 0
sw $t0, -1116($fp)
#LVAR, $temp164, , judge
lw $t0, -1116($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label64
j $label64
#LAB, , , $label63
$label63:
#LAB, , , $label64
$label64:
#LI, 9, , $temp166
li $t0, 9
sw $t0, -1120($fp)
#LI, 3, , $temp167
li $t0, 3
sw $t0, -1124($fp)
#DIV, $temp166, $temp167, $temp166
lw $t0, -1120($fp)
lw $t1, -1124($fp)
div $t0, $t1
mflo $t0
sw $t0, -1120($fp)
#PUSH, , , $temp166
lw $t0, -1120($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#VAR, char, , $temp168
#LI, 10, , $temp169
li $t0, 10
sw $t0, -1132($fp)
#LARY, aa, $temp169, $temp168
lw $t0, -1132($fp)
mul $t0, $t0, 4
addi $t1, $fp, -156
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -1128($fp)
#PUSH, , , $temp168
lw $t0, -1128($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , add
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
jal add
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
#VOF, add, , $temp165
sw $v0, -1136($fp)
#LI, 8, , $temp170
li $t0, 8
sw $t0, -1140($fp)
#BEQ, $temp165, $temp170, $label65
lw $t0, -1136($fp)
lw $t1, -1140($fp)
beq $t0, $t1, $label65
#PRT, 1, , 6
li $v0, 4
la $a0, $string6
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp171
li $t0, 0
sw $t0, -1144($fp)
#LVAR, $temp171, , judge
lw $t0, -1144($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label66
j $label66
#LAB, , , $label65
$label65:
#LI, 10, , $temp173
li $t0, 10
sw $t0, -1148($fp)
#PUSH, , , $temp173
lw $t0, -1148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp172
sw $v0, -1152($fp)
#LI, 55, , $temp174
li $t0, 55
sw $t0, -1156($fp)
#BEQ, $temp172, $temp174, $label67
lw $t0, -1152($fp)
lw $t1, -1156($fp)
beq $t0, $t1, $label67
#PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp175
li $t0, 0
sw $t0, -1160($fp)
#LVAR, $temp175, , judge
lw $t0, -1160($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label68
j $label68
#LAB, , , $label67
$label67:
#LAB, , , $label68
$label68:
#LAB, , , $label66
$label66:
#LVAR, t7, , $temp177
lw $t0, -560($fp)
sw $t0, -1164($fp)
#PUSH, , , $temp177
lw $t0, -1164($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , tolow
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
jal tolow
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
#VOF, tolow, , $temp176
sw $v0, -1168($fp)
#LVAR, b, , $temp180
la $t1, b
lw $t0, 0($t1)
sw $t0, -1172($fp)
#LI, 0, , $temp181
li $t0, 0
sw $t0, -1176($fp)
#SUB, $temp181, $temp180, $temp180
lw $t0, -1176($fp)
lw $t1, -1172($fp)
sub $t0, $t0, $t1
sw $t0, -1172($fp)
#PUSH, , , $temp180
lw $t0, -1172($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 4, , $temp182
li $t0, 4
sw $t0, -1180($fp)
#LVAR, a, , $temp183
la $t1, a
lw $t0, 0($t1)
sw $t0, -1184($fp)
#MUL, $temp182, $temp183, $temp182
lw $t0, -1180($fp)
lw $t1, -1184($fp)
mult $t0, $t1
mflo $t0
sw $t0, -1180($fp)
#PUSH, , , $temp182
lw $t0, -1180($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , add
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
jal add
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
#VOF, add, , $temp179
sw $v0, -1188($fp)
#PUSH, , , $temp179
lw $t0, -1188($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp178
sw $v0, -1192($fp)
#ADD, $temp176, $temp178, $temp176
lw $t0, -1168($fp)
lw $t1, -1192($fp)
add $t0, $t0, $t1
sw $t0, -1168($fp)
#LVAR, $temp176, , x
lw $t0, -1168($fp)
la $t1, x
sw $t0, 0($t1)
#CALL, , , addx
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
jal addx
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
#VOF, addx, , $temp184
sw $v0, -1196($fp)
#LI, 100, , $temp185
li $t0, 100
sw $t0, -1200($fp)
#BEQ, $temp184, $temp185, $label69
lw $t0, -1196($fp)
lw $t1, -1200($fp)
beq $t0, $t1, $label69
#PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp186
li $t0, 0
sw $t0, -1204($fp)
#LVAR, $temp186, , judge
lw $t0, -1204($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label70
j $label70
#LAB, , , $label69
$label69:
#LAB, , , $label70
$label70:
#LI, 1, , $temp187
li $t0, 1
sw $t0, -1208($fp)
#LVAR, $temp187, , x
lw $t0, -1208($fp)
la $t1, x
sw $t0, 0($t1)
#CALL, , , testif
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
jal testif
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
#LVAR, x, , $temp189
la $t1, x
lw $t0, 0($t1)
sw $t0, -1212($fp)
#PUSH, , , $temp189
lw $t0, -1212($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase1
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
jal testcase1
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
#VOF, testcase1, , $temp188
sw $v0, -1216($fp)
#LI, 2, , $temp190
li $t0, 2
sw $t0, -1220($fp)
#BEQ, $temp188, $temp190, $label71
lw $t0, -1216($fp)
lw $t1, -1220($fp)
beq $t0, $t1, $label71
#PRT, 1, , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp191
li $t0, 0
sw $t0, -1224($fp)
#LVAR, $temp191, , judge
lw $t0, -1224($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label72
j $label72
#LAB, , , $label71
$label71:
#LAB, , , $label72
$label72:
#LI, 3, , $temp194
li $t0, 3
sw $t0, -1228($fp)
#PUSH, , , $temp194
lw $t0, -1228($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp193
sw $v0, -1232($fp)
#LI, 1, , $temp196
li $t0, 1
sw $t0, -1236($fp)
#PUSH, , , $temp196
lw $t0, -1236($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase1
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
jal testcase1
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
#VOF, testcase1, , $temp195
sw $v0, -1240($fp)
#SUB, $temp193, $temp195, $temp193
lw $t0, -1232($fp)
lw $t1, -1240($fp)
sub $t0, $t0, $t1
sw $t0, -1232($fp)
#PUSH, , , $temp193
lw $t0, -1232($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 1, , $temp197
li $t0, 1
sw $t0, -1244($fp)
#PUSH, , , $temp197
lw $t0, -1244($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , add
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
jal add
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
#VOF, add, , $temp192
sw $v0, -1248($fp)
#LVAR, $temp192, , x
lw $t0, -1248($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp199
la $t1, x
lw $t0, 0($t1)
sw $t0, -1252($fp)
#LI, 1, , $temp200
li $t0, 1
sw $t0, -1256($fp)
#SUB, $temp199, $temp200, $temp199
lw $t0, -1252($fp)
lw $t1, -1256($fp)
sub $t0, $t0, $t1
sw $t0, -1252($fp)
#PUSH, , , $temp199
lw $t0, -1252($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase1
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
jal testcase1
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
#VOF, testcase1, , $temp198
sw $v0, -1260($fp)
#LVAR, t1, , $temp201
move $t0, $t2
sw $t0, -1264($fp)
#LI, 0, , $temp202
li $t0, 0
sw $t0, -1268($fp)
#SUB, $temp202, $temp201, $temp201
lw $t0, -1268($fp)
lw $t1, -1264($fp)
sub $t0, $t0, $t1
sw $t0, -1264($fp)
#LVAR, t2, , $temp203
move $t0, $t3
sw $t0, -1272($fp)
#ADD, $temp201, $temp203, $temp201
lw $t0, -1264($fp)
lw $t1, -1272($fp)
add $t0, $t0, $t1
sw $t0, -1264($fp)
#BEQ, $temp198, $temp201, $label73
lw $t0, -1260($fp)
lw $t1, -1264($fp)
beq $t0, $t1, $label73
#PRT, 1, , 10
li $v0, 4
la $a0, $string10
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp204
li $t0, 0
sw $t0, -1276($fp)
#LVAR, $temp204, , judge
lw $t0, -1276($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label74
j $label74
#LAB, , , $label73
$label73:
#LAB, , , $label74
$label74:
#LI, 1, , $temp205
li $t0, 1
sw $t0, -1280($fp)
#LI, 0, , $temp206
li $t0, 0
sw $t0, -1284($fp)
#SUB, $temp206, $temp205, $temp205
lw $t0, -1284($fp)
lw $t1, -1280($fp)
sub $t0, $t0, $t1
sw $t0, -1280($fp)
#LVAR, $temp205, , x
lw $t0, -1280($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp208
la $t1, x
lw $t0, 0($t1)
sw $t0, -1288($fp)
#PUSH, , , $temp208
lw $t0, -1288($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase1
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
jal testcase1
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
#VOF, testcase1, , $temp207
sw $v0, -1292($fp)
#VAR, int, , $temp209
#LI, 10, , $temp210
li $t0, 10
sw $t0, -1300($fp)
#LARY, aa, $temp210, $temp209
lw $t0, -1300($fp)
mul $t0, $t0, 4
addi $t1, $fp, -156
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -1296($fp)
#LI, 0, , $temp211
li $t0, 0
sw $t0, -1304($fp)
#SUB, $temp211, $temp209, $temp209
lw $t0, -1304($fp)
lw $t1, -1296($fp)
sub $t0, $t0, $t1
sw $t0, -1296($fp)
#LI, 6, , $temp213
li $t0, 6
sw $t0, -1308($fp)
#PUSH, , , $temp213
lw $t0, -1308($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp212
sw $v0, -1312($fp)
#ADD, $temp209, $temp212, $temp209
lw $t0, -1296($fp)
lw $t1, -1312($fp)
add $t0, $t0, $t1
sw $t0, -1296($fp)
#BEQ, $temp207, $temp209, $label75
lw $t0, -1292($fp)
lw $t1, -1296($fp)
beq $t0, $t1, $label75
#PRT, 1, , 11
li $v0, 4
la $a0, $string11
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp214
li $t0, 0
sw $t0, -1316($fp)
#LVAR, $temp214, , judge
lw $t0, -1316($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label76
j $label76
#LAB, , , $label75
$label75:
#LAB, , , $label76
$label76:
#LI, 0, , $temp215
li $t0, 0
sw $t0, -1320($fp)
#LVAR, $temp215, , x
lw $t0, -1320($fp)
la $t1, x
sw $t0, 0($t1)
#LVAR, x, , $temp216
la $t1, x
lw $t0, 0($t1)
sw $t0, -1324($fp)
#PUSH, , , $temp216
lw $t0, -1324($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , test_do_while
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
jal test_do_while
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
#READ, , , t5
li $v0, 5
syscall
move $t8, $v0
#READ, , , t6
li $v0, 5
syscall
sw $v0, -556($fp)
#LVAR, t5, , $temp218
move $t0, $t8
sw $t0, -1328($fp)
#LI, 1, , $temp219
li $t0, 1
sw $t0, -1332($fp)
#SUB, $temp218, $temp219, $temp218
lw $t0, -1328($fp)
lw $t1, -1332($fp)
sub $t0, $t0, $t1
sw $t0, -1328($fp)
#PUSH, , , $temp218
lw $t0, -1328($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp217
sw $v0, -1336($fp)
#LVAR, t6, , $temp220
lw $t0, -556($fp)
sw $t0, -1340($fp)
#ADD, $temp217, $temp220, $temp217
lw $t0, -1336($fp)
lw $t1, -1340($fp)
add $t0, $t0, $t1
sw $t0, -1336($fp)
#LI, 5, , $temp221
li $t0, 5
sw $t0, -1344($fp)
#BEQ, $temp217, $temp221, $label77
lw $t0, -1336($fp)
lw $t1, -1344($fp)
beq $t0, $t1, $label77
#PRT, 1, , 12
li $v0, 4
la $a0, $string12
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp222
li $t0, 0
sw $t0, -1348($fp)
#LVAR, $temp222, , judge
lw $t0, -1348($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label78
j $label78
#LAB, , , $label77
$label77:
#LAB, , , $label78
$label78:
#LI, 97, , $temp223
li $t0, 97
sw $t0, -1352($fp)
#LVAR, $temp223, , t8
lw $t0, -1352($fp)
sw $t0, -564($fp)
#LVAR, t8, , $temp225
lw $t0, -564($fp)
sw $t0, -1356($fp)
#PUSH, , , $temp225
lw $t0, -1356($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase2
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
jal testcase2
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
#VOF, testcase2, , $temp224
sw $v0, -1360($fp)
#LI, 0, , $temp226
li $t0, 0
sw $t0, -1364($fp)
#SUB, $temp226, $temp224, $temp224
lw $t0, -1364($fp)
lw $t1, -1360($fp)
sub $t0, $t0, $t1
sw $t0, -1360($fp)
#LVAR, t6, , $temp228
lw $t0, -556($fp)
sw $t0, -1368($fp)
#PUSH, , , $temp228
lw $t0, -1368($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fib
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
jal fib
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
#VOF, fib, , $temp227
sw $v0, -1372($fp)
#LI, 0, , $temp229
li $t0, 0
sw $t0, -1376($fp)
#SUB, $temp229, $temp227, $temp227
lw $t0, -1376($fp)
lw $t1, -1372($fp)
sub $t0, $t0, $t1
sw $t0, -1372($fp)
#BEQ, $temp224, $temp227, $label79
lw $t0, -1360($fp)
lw $t1, -1372($fp)
beq $t0, $t1, $label79
#PRT, 1, , 13
li $v0, 4
la $a0, $string13
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp230
li $t0, 0
sw $t0, -1380($fp)
#LVAR, $temp230, , judge
lw $t0, -1380($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label80
j $label80
#LAB, , , $label79
$label79:
#LAB, , , $label80
$label80:
#LI, 98, , $temp231
li $t0, 98
sw $t0, -1384($fp)
#LVAR, $temp231, , t8
lw $t0, -1384($fp)
sw $t0, -564($fp)
#LVAR, t8, , $temp233
lw $t0, -564($fp)
sw $t0, -1388($fp)
#PUSH, , , $temp233
lw $t0, -1388($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , testcase2
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
jal testcase2
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
#VOF, testcase2, , $temp232
sw $v0, -1392($fp)
#LVAR, t6, , $temp234
lw $t0, -556($fp)
sw $t0, -1396($fp)
#BEQ, $temp232, $temp234, $label81
lw $t0, -1392($fp)
lw $t1, -1396($fp)
beq $t0, $t1, $label81
#PRT, 1, , 14
li $v0, 4
la $a0, $string14
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp235
li $t0, 0
sw $t0, -1400($fp)
#LVAR, $temp235, , judge
lw $t0, -1400($fp)
la $t1, judge
sw $t0, 0($t1)
#JUMP, , , $label82
j $label82
#LAB, , , $label81
$label81:
#LAB, , , $label82
$label82:
#READ, , , t8
li $v0, 12
syscall
sw $v0, -564($fp)
#READ, , , t7
li $v0, 12
syscall
sw $v0, -560($fp)
#LVAR, t8, , $temp236
lw $t0, -564($fp)
sw $t0, -1404($fp)
#LI, 0, , $temp237
li $t0, 0
sw $t0, -1408($fp)
#SUB, $temp236, $temp237, $temp236
lw $t0, -1404($fp)
lw $t1, -1408($fp)
sub $t0, $t0, $t1
sw $t0, -1404($fp)
#LVAR, t7, , $temp238
lw $t0, -560($fp)
sw $t0, -1412($fp)
#LVAR, t3, , $temp239
move $t0, $t4
sw $t0, -1416($fp)
#ADD, $temp238, $temp239, $temp238
lw $t0, -1412($fp)
lw $t1, -1416($fp)
add $t0, $t0, $t1
sw $t0, -1412($fp)
#LI, 97, , $temp240
li $t0, 97
sw $t0, -1420($fp)
#SUB, $temp238, $temp240, $temp238
lw $t0, -1412($fp)
lw $t1, -1420($fp)
sub $t0, $t0, $t1
sw $t0, -1412($fp)
#BEQ, $temp236, $temp238, $label83
lw $t0, -1404($fp)
lw $t1, -1412($fp)
beq $t0, $t1, $label83
#PRT, 1, , 15
li $v0, 4
la $a0, $string15
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label84
j $label84
#LAB, , , $label83
$label83:
#LAB, , , $label84
$label84:
#LVAR, judge, , $temp241
la $t1, judge
lw $t0, 0($t1)
sw $t0, -1424($fp)
#LI, 0, , $temp242
li $t0, 0
sw $t0, -1428($fp)
#BNE, $temp241, $temp242, $label85
lw $t0, -1424($fp)
lw $t1, -1428($fp)
bne $t0, $t1, $label85
#PRT, 1, , 16
li $v0, 4
la $a0, $string16
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label86
j $label86
#LAB, , , $label85
$label85:
#LVAR, x, , $temp243
la $t1, x
lw $t0, 0($t1)
sw $t0, -1432($fp)
#PRT, 2, 17, $temp243
li $v0, 4
la $a0, $string17
syscall
li $v0, 1
lw $a0, -1432($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , $label86
$label86:
