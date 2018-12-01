.data
zero: .word 0
neg: .word -1
pos: .word 1
c: .word 99
cc: .word 67
plus: .word 43
_plus: .word 45
mul: .word 42
_mul: .word 47
n_u_m_0: .word 48
a1var: .space 4
a2var: .space 4
arrayintvar: .word 0: 10
c1var: .space 4
c2var: .space 4
arraycharvar: .word 0: 10
$string0: .asciiz ""
$string1: .asciiz " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
$string2: .asciiz "IO i:"
$string3: .asciiz "beq10"
$string4: .asciiz "bge1"
$string5: .asciiz "ble-1"
$string6: .asciiz "bgt1"
$string7: .asciiz "blt1"
$string8: .asciiz "bne0"
$string9: .asciiz "beq0bgt?"
$string10: .asciiz "ble?"
$string11: .asciiz "hi"
$string12: .asciiz "result"
$string13: .asciiz "fibo(fn):"
$enter: .asciiz "\n"
.text
j main
#FUNC, void, , testio
testio:
add $fp, $sp, 0
subi $sp, $sp, 284
#CON, int, 10, iiii
li $t2, 10
#VAR, int, , i
#ARY, int, 10, iarray
#VAR, char, , ch
#ARY, char, 10, charray
#PC, , , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#PC, , , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0,$enter
syscall
#READ, , , i
li $v0, 5
syscall
move $t3, $v0
#READ, , , ch
li $v0, 12
syscall
sw $v0, -176($fp)
#LI, 0, , $temp0
li $t0, 0
sw $t0, -220($fp)
#LVAR, i, , $temp1
move $t0 $t3
sw $t0, -224($fp)
#SARY, iarray, $temp0, $temp1
lw $t0, -220($fp)
mul $t0, $t0, 4
addi $t1, $fp, -136
sub $t0, $t1, $t0
lw $t1, -224($fp)
sw $t1, ($t0)
#LI, 0, , $temp2
li $t0, 0
sw $t0, -228($fp)
#LVAR, ch, , $temp3
lw $t0, -176($fp)
sw $t0, -232($fp)
#SARY, charray, $temp2, $temp3
lw $t0, -228($fp)
mul $t0, $t0, 4
addi $t1, $fp, -180
sub $t0, $t1, $t0
lw $t1, -232($fp)
sw $t1, ($t0)
#PC, , , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, i, , $temp4
move $t0 $t3
sw $t0, -236($fp)
#PI, , , $temp4
li $v0, 1
lw $a0, -236($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, ch, , $temp5
lw $t0, -176($fp)
sw $t0, -240($fp)
#PI, , , $temp5
li $v0, 11
lw $a0, -240($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#VAR, char, , $temp6
#LI, 0, , $temp7
li $t0, 0
sw $t0, -248($fp)
#LARY, charray, $temp7, $temp6
lw $t0, -248($fp)
mul $t0, $t0, 4
addi $t1, $fp, -180
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -244($fp)
#PI, , , $temp6
li $v0, 11
lw $a0, -244($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, neg, , $temp8
la $t1, neg
lw $t0, 0($t1)
sw $t0, -252($fp)
#LVAR, ch, , $temp9
lw $t0, -176($fp)
sw $t0, -256($fp)
#ADD, $temp8, $temp9, $temp8
lw $t0, -252($fp)
lw $t1, -256($fp)
add $t0, $t0, $t1
sw $t0, -252($fp)
#PI, , , $temp8
li $v0, 1
lw $a0, -252($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#VAR, char, , $temp10
#LI, 0, , $temp11
li $t0, 0
sw $t0, -264($fp)
#LARY, charray, $temp11, $temp10
lw $t0, -264($fp)
mul $t0, $t0, 4
addi $t1, $fp, -180
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -260($fp)
#LVAR, pos, , $temp12
la $t1, pos
lw $t0, 0($t1)
sw $t0, -268($fp)
#LVAR, neg, , $temp13
la $t1, neg
lw $t0, 0($t1)
sw $t0, -272($fp)
#SUB, $temp12, $temp13, $temp12
lw $t0, -268($fp)
lw $t1, -272($fp)
sub $t0, $t0, $t1
sw $t0, -268($fp)
#MUL, $temp10, $temp12, $temp10
lw $t0, -260($fp)
lw $t1, -268($fp)
mult $t0, $t1
mflo $t0
sw $t0, -260($fp)
#PI, , , $temp10
li $v0, 1
lw $a0, -260($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 284
jr $ra
#FUNC, void, , testif
testif:
add $fp, $sp, 8
subi $sp, $sp, 216
#PARA, int, , a
#PARA, char, , ch
#VAR, int, , ch2
#LVAR, ch, , $temp14
lw $t0, -4($fp)
sw $t0, -140($fp)
#LVAR, ch, , $temp15
lw $t0, -4($fp)
sw $t0, -144($fp)
#ADD, $temp14, $temp15, $temp14
lw $t0, -140($fp)
lw $t1, -144($fp)
add $t0, $t0, $t1
sw $t0, -140($fp)
#LVAR, $temp14, , ch2
lw $t0, -140($fp)
move $t2, $t0
#LVAR, a, , $temp16
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 10, , $temp17
li $t0, 10
sw $t0, -152($fp)
#BNE, $temp16, $temp17, label0
lw $t0, -148($fp)
lw $t1, -152($fp)
bne $t0, $t1, label0
#PC, , , 3
li $v0, 4
la $a0, $string3
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 224
jr $ra
#JUMP, , , label1
j label1
#LAB, , , label0
label0:
#LVAR, a, , $temp18
lw $t0, 0($fp)
sw $t0, -156($fp)
#LI, 1, , $temp19
li $t0, 1
sw $t0, -160($fp)
#BLT, $temp18, $temp19, label2
lw $t0, -156($fp)
lw $t1, -160($fp)
blt $t0, $t1, label2
#PC, , , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label3
j label3
#LAB, , , label2
label2:
#LVAR, a, , $temp20
lw $t0, 0($fp)
sw $t0, -164($fp)
#LI, 1, , $temp21
li $t0, 1
sw $t0, -168($fp)
#LI, 0, , $temp22
li $t0, 0
sw $t0, -172($fp)
#SUB, $temp22, $temp21, $temp21
lw $t0, -172($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#BGT, $temp20, $temp21, label4
lw $t0, -164($fp)
lw $t1, -168($fp)
bgt $t0, $t1, label4
#PC, , , 5
li $v0, 4
la $a0, $string5
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label5
j label5
#LAB, , , label4
label4:
#LVAR, a, , $temp23
lw $t0, 0($fp)
sw $t0, -176($fp)
#LI, 1, , $temp24
li $t0, 1
sw $t0, -180($fp)
#BLE, $temp23, $temp24, label6
lw $t0, -176($fp)
lw $t1, -180($fp)
ble $t0, $t1, label6
#PC, , , 6
li $v0, 4
la $a0, $string6
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label7
j label7
#LAB, , , label6
label6:
#LVAR, a, , $temp25
lw $t0, 0($fp)
sw $t0, -184($fp)
#LI, 1, , $temp26
li $t0, 1
sw $t0, -188($fp)
#LI, 0, , $temp27
li $t0, 0
sw $t0, -192($fp)
#SUB, $temp27, $temp26, $temp26
lw $t0, -192($fp)
lw $t1, -188($fp)
sub $t0, $t0, $t1
sw $t0, -188($fp)
#BGE, $temp25, $temp26, label8
lw $t0, -184($fp)
lw $t1, -188($fp)
bge $t0, $t1, label8
#PC, , , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label9
j label9
#LAB, , , label8
label8:
#LVAR, a, , $temp28
lw $t0, 0($fp)
sw $t0, -196($fp)
#LI, 0, , $temp29
li $t0, 0
sw $t0, -200($fp)
#BEQ, $temp28, $temp29, label10
lw $t0, -196($fp)
lw $t1, -200($fp)
beq $t0, $t1, label10
#PC, , , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label11
j label11
#LAB, , , label10
label10:
#LVAR, ch2, , $temp30
move $t0 $t2
sw $t0, -204($fp)
#LI, 126, , $temp31
li $t0, 126
sw $t0, -208($fp)
#BLE, $temp30, $temp31, label12
lw $t0, -204($fp)
lw $t1, -208($fp)
ble $t0, $t1, label12
#LVAR, a, , $temp32
lw $t0, 0($fp)
sw $t0, -212($fp)
#LI, 0, , $temp33
li $t0, 0
sw $t0, -216($fp)
#BEQ, $temp32, $temp33, label14
lw $t0, -212($fp)
lw $t1, -216($fp)
beq $t0, $t1, label14
#PC, , , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label15
j label15
#LAB, , , label14
label14:
#PC, , , 9
li $v0, 4
la $a0, $string9
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label15
label15:
#JUMP, , , label13
j label13
#LAB, , , label12
label12:
#PC, , , 10
li $v0, 4
la $a0, $string10
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label13
label13:
#LAB, , , label11
label11:
#LAB, , , label9
label9:
#LAB, , , label7
label7:
#LAB, , , label5
label5:
#LAB, , , label3
label3:
#LAB, , , label1
label1:
#FUNC, void, , testdowhile
testdowhile:
add $fp, $sp, 0
subi $sp, $sp, 188
#VAR, int, , n
#LI, 1, , $temp34
li $t0, 1
sw $t0, -132($fp)
#LVAR, $temp34, , n
lw $t0, -132($fp)
move $t2, $t0
#LAB, , , label17
label17:
#LVAR, n, , $temp35
move $t0 $t2
sw $t0, -136($fp)
#LI, 2, , $temp36
li $t0, 2
sw $t0, -140($fp)
#MUL, $temp35, $temp36, $temp35
lw $t0, -136($fp)
lw $t1, -140($fp)
mult $t0, $t1
mflo $t0
sw $t0, -136($fp)
#LVAR, $temp35, , n
lw $t0, -136($fp)
move $t2, $t0
#LAB, , , label16
label16:
#LVAR, n, , $temp37
move $t0 $t2
sw $t0, -144($fp)
#LI, 20, , $temp38
li $t0, 20
sw $t0, -148($fp)
#BGE, $temp37, $temp38, label18
lw $t0, -144($fp)
lw $t1, -148($fp)
bge $t0, $t1, label18
#JUMP, , , label17
j label17
#LAB, , , label18
label18:
#LAB, , , label20
label20:
#LVAR, n, , $temp39
move $t0 $t2
sw $t0, -152($fp)
#LI, 1, , $temp40
li $t0, 1
sw $t0, -156($fp)
#SUB, $temp39, $temp40, $temp39
lw $t0, -152($fp)
lw $t1, -156($fp)
sub $t0, $t0, $t1
sw $t0, -152($fp)
#LVAR, $temp39, , n
lw $t0, -152($fp)
move $t2, $t0
#LVAR, n, , $temp41
move $t0 $t2
sw $t0, -160($fp)
#LI, 1, , $temp42
li $t0, 1
sw $t0, -164($fp)
#DIV, $temp41, $temp42, $temp41
lw $t0, -160($fp)
lw $t1, -164($fp)
div $t0, $t1
mflo $t0
sw $t0, -160($fp)
#LI, 1, , $temp43
li $t0, 1
sw $t0, -168($fp)
#BLT, $temp41, $temp43, label22
lw $t0, -160($fp)
lw $t1, -168($fp)
blt $t0, $t1, label22
#JUMP, , , label23
j label23
#LAB, , , label22
label22:
#PC, , , 11
li $v0, 4
la $a0, $string11
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, n, , $temp44
move $t0 $t2
sw $t0, -172($fp)
#PI, , , $temp44
li $v0, 1
lw $a0, -172($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label23
label23:
#LAB, , , label19
label19:
#LVAR, n, , $temp45
move $t0 $t2
sw $t0, -176($fp)
#LI, 0, , $temp46
li $t0, 0
sw $t0, -180($fp)
#BEQ, $temp45, $temp46, label21
lw $t0, -176($fp)
lw $t1, -180($fp)
beq $t0, $t1, label21
#JUMP, , , label20
j label20
#LAB, , , label21
label21:
#REN, , , 
addi $sp, $sp, 188
jr $ra
#FUNC, void, , testswitch
testswitch:
add $fp, $sp, 0
subi $sp, $sp, 284
#VAR, int, , x
#VAR, int, , y
#VAR, char, , ch
#LI, 3, , $temp47
li $t0, 3
sw $t0, -140($fp)
#LVAR, $temp47, , y
lw $t0, -140($fp)
move $t3, $t0
#READ, , , x
li $v0, 5
syscall
move $t2, $v0
#LVAR, x, , $temp48
move $t0 $t2
sw $t0, -144($fp)
#LVAR, x, , $temp49
move $t0 $t2
sw $t0, -148($fp)
#ADD, $temp48, $temp49, $temp48
lw $t0, -144($fp)
lw $t1, -148($fp)
add $t0, $t0, $t1
sw $t0, -144($fp)
#LVAR, x, , $temp50
move $t0 $t2
sw $t0, -152($fp)
#SUB, $temp48, $temp50, $temp48
lw $t0, -144($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -144($fp)
#LI, 0, , $temp51
li $t0, 0
sw $t0, -156($fp)
#BNE, $temp48, $temp51, label25
lw $t0, -144($fp)
lw $t1, -156($fp)
bne $t0, $t1, label25
#LI, 43, , $temp52
li $t0, 43
sw $t0, -160($fp)
#LVAR, $temp52, , ch
lw $t0, -160($fp)
move $t4, $t0
#JUMP, , , label24
j label24
#LAB, , , label25
label25:
#LI, 1, , $temp53
li $t0, 1
sw $t0, -164($fp)
#BNE, $temp48, $temp53, label26
lw $t0, -144($fp)
lw $t1, -164($fp)
bne $t0, $t1, label26
#LI, 45, , $temp54
li $t0, 45
sw $t0, -168($fp)
#LVAR, $temp54, , ch
lw $t0, -168($fp)
move $t4, $t0
#JUMP, , , label24
j label24
#LAB, , , label26
label26:
#LI, -1, , $temp55
li $t0, -1
sw $t0, -172($fp)
#BNE, $temp48, $temp55, label27
lw $t0, -144($fp)
lw $t1, -172($fp)
bne $t0, $t1, label27
#LI, 42, , $temp56
li $t0, 42
sw $t0, -176($fp)
#LVAR, $temp56, , ch
lw $t0, -176($fp)
move $t4, $t0
#JUMP, , , label24
j label24
#LAB, , , label27
label27:
#LI, 95, , $temp57
li $t0, 95
sw $t0, -180($fp)
#LVAR, $temp57, , ch
lw $t0, -180($fp)
move $t4, $t0
#LAB, , , label24
label24:
#LVAR, ch, , $temp58
move $t0 $t4
sw $t0, -184($fp)
#LI, 43, , $temp59
li $t0, 43
sw $t0, -188($fp)
#BNE, $temp58, $temp59, label29
lw $t0, -184($fp)
lw $t1, -188($fp)
bne $t0, $t1, label29
#LI, 100, , $temp60
li $t0, 100
sw $t0, -192($fp)
#LVAR, $temp60, , a2var
lw $t0, -192($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label28
j label28
#LAB, , , label29
label29:
#LI, 45, , $temp61
li $t0, 45
sw $t0, -196($fp)
#BNE, $temp58, $temp61, label30
lw $t0, -184($fp)
lw $t1, -196($fp)
bne $t0, $t1, label30
#LI, 50, , $temp62
li $t0, 50
sw $t0, -200($fp)
#LVAR, $temp62, , a2var
lw $t0, -200($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label28
j label28
#LAB, , , label30
label30:
#LI, 42, , $temp63
li $t0, 42
sw $t0, -204($fp)
#BNE, $temp58, $temp63, label31
lw $t0, -184($fp)
lw $t1, -204($fp)
bne $t0, $t1, label31
#LI, 25, , $temp64
li $t0, 25
sw $t0, -208($fp)
#LVAR, $temp64, , a2var
lw $t0, -208($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label28
j label28
#LAB, , , label31
label31:
#LI, 47, , $temp65
li $t0, 47
sw $t0, -212($fp)
#BNE, $temp58, $temp65, label32
lw $t0, -184($fp)
lw $t1, -212($fp)
bne $t0, $t1, label32
#LI, 10, , $temp66
li $t0, 10
sw $t0, -216($fp)
#LVAR, $temp66, , a2var
lw $t0, -216($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label28
j label28
#LAB, , , label32
label32:
#LI, 95, , $temp67
li $t0, 95
sw $t0, -220($fp)
#BNE, $temp58, $temp67, label33
lw $t0, -184($fp)
lw $t1, -220($fp)
bne $t0, $t1, label33
#LVAR, x, , $temp68
move $t0 $t2
sw $t0, -224($fp)
#LVAR, x, , $temp69
move $t0 $t2
sw $t0, -228($fp)
#MUL, $temp68, $temp69, $temp68
lw $t0, -224($fp)
lw $t1, -228($fp)
mult $t0, $t1
mflo $t0
sw $t0, -224($fp)
#LVAR, $temp68, , x
lw $t0, -224($fp)
move $t2, $t0
#LVAR, x, , $temp70
move $t0 $t2
sw $t0, -232($fp)
#LVAR, y, , $temp71
move $t0 $t3
sw $t0, -236($fp)
#SUB, $temp70, $temp71, $temp70
lw $t0, -232($fp)
lw $t1, -236($fp)
sub $t0, $t0, $t1
sw $t0, -232($fp)
#LI, 0, , $temp72
li $t0, 0
sw $t0, -240($fp)
#BNE, $temp70, $temp72, label34
lw $t0, -232($fp)
lw $t1, -240($fp)
bne $t0, $t1, label34
#LI, 9, , $temp73
li $t0, 9
sw $t0, -244($fp)
#LVAR, $temp73, , a2var
lw $t0, -244($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label35
j label35
#LAB, , , label34
label34:
#LI, 5, , $temp74
li $t0, 5
sw $t0, -248($fp)
#LVAR, $temp74, , a2var
lw $t0, -248($fp)
la $t1, a2var
sw $t0, 0($t1)
#LAB, , , label35
label35:
#JUMP, , , label28
j label28
#LAB, , , label33
label33:
#LVAR, y, , $temp75
move $t0 $t3
sw $t0, -252($fp)
#LVAR, y, , $temp76
move $t0 $t3
sw $t0, -256($fp)
#MUL, $temp75, $temp76, $temp75
lw $t0, -252($fp)
lw $t1, -256($fp)
mult $t0, $t1
mflo $t0
sw $t0, -252($fp)
#LVAR, $temp75, , y
lw $t0, -252($fp)
move $t3, $t0
#LVAR, x, , $temp77
move $t0 $t2
sw $t0, -260($fp)
#LVAR, y, , $temp78
move $t0 $t3
sw $t0, -264($fp)
#DIV, $temp77, $temp78, $temp77
lw $t0, -260($fp)
lw $t1, -264($fp)
div $t0, $t1
mflo $t0
sw $t0, -260($fp)
#LI, 0, , $temp79
li $t0, 0
sw $t0, -268($fp)
#BNE, $temp77, $temp79, label36
lw $t0, -260($fp)
lw $t1, -268($fp)
bne $t0, $t1, label36
#LI, 8, , $temp80
li $t0, 8
sw $t0, -272($fp)
#LVAR, $temp80, , a2var
lw $t0, -272($fp)
la $t1, a2var
sw $t0, 0($t1)
#JUMP, , , label37
j label37
#LAB, , , label36
label36:
#LI, 4, , $temp81
li $t0, 4
sw $t0, -276($fp)
#LVAR, $temp81, , a2var
lw $t0, -276($fp)
la $t1, a2var
sw $t0, 0($t1)
#LAB, , , label37
label37:
#LAB, , , label28
label28:
#REN, , , 
addi $sp, $sp, 284
jr $ra
#FUNC, int, , itrue
itrue:
add $fp, $sp, 0
subi $sp, $sp, 136
#LI, 1, , $temp82
li $t0, 1
sw $t0, -128($fp)
#RET, , , $temp82
lw $v0, -128($fp)
addi $sp, $sp, 136
jr $ra
#FUNC, char, , chtrue
chtrue:
add $fp, $sp, 0
subi $sp, $sp, 136
#LI, 97, , $temp83
li $t0, 97
sw $t0, -128($fp)
#RET, , , $temp83
lw $v0, -128($fp)
addi $sp, $sp, 136
jr $ra
#FUNC, void, , empty
empty:
add $fp, $sp, 0
subi $sp, $sp, 132
#REN, , , 
addi $sp, $sp, 132
jr $ra
#FUNC, void, , testexpression
testexpression:
add $fp, $sp, 0
subi $sp, $sp, 268
#VAR, int, , i
#ARY, int, 10, array
#VAR, int, , result
#LVAR, a2var, , $temp84
la $t1, a2var
lw $t0, 0($t1)
sw $t0, -176($fp)
#LVAR, $temp84, , i
lw $t0, -176($fp)
move $t2, $t0
#LI, 1, , $temp85
li $t0, 1
sw $t0, -180($fp)
#LI, 10, , $temp86
li $t0, 10
sw $t0, -184($fp)
#SARY, array, $temp85, $temp86
lw $t0, -180($fp)
mul $t0, $t0, 4
addi $t1, $fp, -132
sub $t0, $t1, $t0
lw $t1, -184($fp)
sw $t1, ($t0)
#LVAR, neg, , $temp87
la $t1, neg
lw $t0, 0($t1)
sw $t0, -188($fp)
#LI, 0, , $temp88
li $t0, 0
sw $t0, -192($fp)
#SUB, $temp88, $temp87, $temp87
lw $t0, -192($fp)
lw $t1, -188($fp)
sub $t0, $t0, $t1
sw $t0, -188($fp)
#LVAR, i, , $temp89
move $t0 $t2
sw $t0, -196($fp)
#LI, 2, , $temp90
li $t0, 2
sw $t0, -200($fp)
#DIV, $temp89, $temp90, $temp89
lw $t0, -196($fp)
lw $t1, -200($fp)
div $t0, $t1
mflo $t0
sw $t0, -196($fp)
#ADD, $temp87, $temp89, $temp87
lw $t0, -188($fp)
lw $t1, -196($fp)
add $t0, $t0, $t1
sw $t0, -188($fp)
#LVAR, i, , $temp91
move $t0 $t2
sw $t0, -204($fp)
#LVAR, zero, , $temp92
la $t1, zero
lw $t0, 0($t1)
sw $t0, -208($fp)
#MUL, $temp91, $temp92, $temp91
lw $t0, -204($fp)
lw $t1, -208($fp)
mult $t0, $t1
mflo $t0
sw $t0, -204($fp)
#SUB, $temp87, $temp91, $temp87
lw $t0, -188($fp)
lw $t1, -204($fp)
sub $t0, $t0, $t1
sw $t0, -188($fp)
#LVAR, $temp87, , result
lw $t0, -188($fp)
sw $t0, -172($fp)
#LVAR, pos, , $temp93
la $t1, pos
lw $t0, 0($t1)
sw $t0, -212($fp)
#VAR, int, , $temp94
#CALL, , , itrue
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
jal itrue
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
#VOF, itrue, , $temp95
sw $v0, -220($fp)
#LARY, array, $temp95, $temp94
lw $t0, -220($fp)
mul $t0, $t0, 4
addi $t1, $fp, -132
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -216($fp)
#MUL, $temp93, $temp94, $temp93
lw $t0, -212($fp)
lw $t1, -216($fp)
mult $t0, $t1
mflo $t0
sw $t0, -212($fp)
#LI, 3, , $temp96
li $t0, 3
sw $t0, -224($fp)
#MUL, $temp93, $temp96, $temp93
lw $t0, -212($fp)
lw $t1, -224($fp)
mult $t0, $t1
mflo $t0
sw $t0, -212($fp)
#LVAR, c, , $temp97
la $t1, c
lw $t0, 0($t1)
sw $t0, -228($fp)
#MUL, $temp93, $temp97, $temp93
lw $t0, -212($fp)
lw $t1, -228($fp)
mult $t0, $t1
mflo $t0
sw $t0, -212($fp)
#LVAR, i, , $temp98
move $t0 $t2
sw $t0, -232($fp)
#LVAR, pos, , $temp99
la $t1, pos
lw $t0, 0($t1)
sw $t0, -236($fp)
#LVAR, pos, , $temp100
la $t1, pos
lw $t0, 0($t1)
sw $t0, -240($fp)
#ADD, $temp99, $temp100, $temp99
lw $t0, -236($fp)
lw $t1, -240($fp)
add $t0, $t0, $t1
sw $t0, -236($fp)
#MUL, $temp98, $temp99, $temp98
lw $t0, -232($fp)
lw $t1, -236($fp)
mult $t0, $t1
mflo $t0
sw $t0, -232($fp)
#CALL, , , itrue
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
jal itrue
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
#VOF, itrue, , $temp101
sw $v0, -248($fp)
#ADD, $temp98, $temp101, $temp98
lw $t0, -232($fp)
lw $t1, -248($fp)
add $t0, $t0, $t1
sw $t0, -232($fp)
#MUL, $temp93, $temp98, $temp93
lw $t0, -212($fp)
lw $t1, -232($fp)
mult $t0, $t1
mflo $t0
sw $t0, -212($fp)
#LVAR, result, , $temp102
lw $t0, -172($fp)
sw $t0, -256($fp)
#MUL, $temp93, $temp102, $temp93
lw $t0, -212($fp)
lw $t1, -256($fp)
mult $t0, $t1
mflo $t0
sw $t0, -212($fp)
#LVAR, $temp93, , result
lw $t0, -212($fp)
sw $t0, -172($fp)
#PC, , , 12
li $v0, 4
la $a0, $string12
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, result, , $temp103
lw $t0, -172($fp)
sw $t0, -260($fp)
#PI, , , $temp103
li $v0, 1
lw $a0, -260($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 268
jr $ra
#FUNC, int, , fibo
fibo:
add $fp, $sp, 4
subi $sp, $sp, 180
#PARA, int, , n
#LVAR, n, , $temp104
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 0, , $temp105
li $t0, 0
sw $t0, -136($fp)
#BNE, $temp104, $temp105, label38
lw $t0, -132($fp)
lw $t1, -136($fp)
bne $t0, $t1, label38
#LI, 0, , $temp106
li $t0, 0
sw $t0, -140($fp)
#RET, , , $temp106
lw $v0, -140($fp)
addi $sp, $sp, 184
jr $ra
#JUMP, , , label39
j label39
#LAB, , , label38
label38:
#LVAR, n, , $temp107
lw $t0, 0($fp)
sw $t0, -144($fp)
#LI, 1, , $temp108
li $t0, 1
sw $t0, -148($fp)
#BNE, $temp107, $temp108, label40
lw $t0, -144($fp)
lw $t1, -148($fp)
bne $t0, $t1, label40
#LI, 1, , $temp109
li $t0, 1
sw $t0, -152($fp)
#RET, , , $temp109
lw $v0, -152($fp)
addi $sp, $sp, 184
jr $ra
#JUMP, , , label41
j label41
#LAB, , , label40
label40:
#LVAR, n, , $temp111
lw $t0, 0($fp)
sw $t0, -156($fp)
#LI, 1, , $temp112
li $t0, 1
sw $t0, -160($fp)
#SUB, $temp111, $temp112, $temp111
lw $t0, -156($fp)
lw $t1, -160($fp)
sub $t0, $t0, $t1
sw $t0, -156($fp)
#PUSH, , , $temp111
lw $t0, -156($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fibo
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
jal fibo
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
#VOF, fibo, , $temp110
sw $v0, -164($fp)
#LVAR, n, , $temp114
lw $t0, 0($fp)
sw $t0, -168($fp)
#LI, 2, , $temp115
li $t0, 2
sw $t0, -172($fp)
#SUB, $temp114, $temp115, $temp114
lw $t0, -168($fp)
lw $t1, -172($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#PUSH, , , $temp114
lw $t0, -168($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fibo
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
jal fibo
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
#VOF, fibo, , $temp113
sw $v0, -176($fp)
#ADD, $temp110, $temp113, $temp110
lw $t0, -164($fp)
lw $t1, -176($fp)
add $t0, $t0, $t1
sw $t0, -164($fp)
#RET, , , $temp110
lw $v0, -164($fp)
addi $sp, $sp, 184
jr $ra
#LAB, , , label41
label41:
#LAB, , , label39
label39:
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 156
#VAR, int, , fn
#CALL, , , testio
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
jal testio
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
#READ, , , a1var
li $v0, 5
syscall
la $t1, a1var
sw $v0, 0($t1)
#LI, 104, , $temp116
li $t0, 104
sw $t0, -132($fp)
#LVAR, $temp116, , c1var
lw $t0, -132($fp)
la $t1, c1var
sw $t0, 0($t1)
#LVAR, a1var, , $temp117
la $t1, a1var
lw $t0, 0($t1)
sw $t0, -136($fp)
#PUSH, , , $temp117
lw $t0, -136($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 104, , $temp118
li $t0, 104
sw $t0, -140($fp)
#PUSH, , , $temp118
lw $t0, -140($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
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
#CALL, , , testdowhile
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
jal testdowhile
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
#CALL, , , testswitch
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
jal testswitch
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
#CALL, , , itrue
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
jal itrue
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
#CALL, , , chtrue
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
jal chtrue
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
#CALL, , , empty
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
jal empty
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
#CALL, , , testexpression
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
jal testexpression
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
#READ, , , fn
li $v0, 5
syscall
move $t2, $v0
#PC, , , 13
li $v0, 4
la $a0, $string13
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, fn, , $temp122
move $t0 $t2
sw $t0, -144($fp)
#PUSH, , , $temp122
lw $t0, -144($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , fibo
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
jal fibo
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
#VOF, fibo, , $temp121
sw $v0, -148($fp)
#PI, , , $temp121
li $v0, 1
lw $a0, -148($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
