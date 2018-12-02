.data
a1: .word -10
b1: .word 5
c1: .word 56
d1: .word 45
d2: .word 65
i: .space 4
j: .space 4
k: .space 4
intarray: .word 0: 10
op: .space 4
chararray: .word 0: 11
$string0: .asciiz "test expr\n"
$string1: .asciiz "print string and expr, got char: "
$string2: .asciiz " !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
$enter: .asciiz "\n"
.text
j main
#FUNC, int, , add
add:
add $fp, $sp, 20
subi $sp, $sp, 152
#PARA, int, , a1
#PARA, int, , b
#PARA, int, , c
#PARA, int, , d
#PARA, char, , k
#LVAR, a1, , $temp0
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
#LVAR, d, , $temp3
lw $t0, -12($fp)
sw $t0, -160($fp)
#ADD, $temp0, $temp3, $temp0
lw $t0, -148($fp)
lw $t1, -160($fp)
add $t0, $t0, $t1
sw $t0, -148($fp)
#LVAR, k, , $temp4
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
#FUNC, char, , get
get:
add $fp, $sp, 0
subi $sp, $sp, 152
#VAR, char, , $temp5
#LVAR, k, , $temp6
la $t1, k
lw $t0, 0($t1)
sw $t0, -132($fp)
#LI, 0, , $temp7
li $t0, 0
sw $t0, -136($fp)
#SUB, $temp7, $temp6, $temp6
lw $t0, -136($fp)
lw $t1, -132($fp)
sub $t0, $t0, $t1
sw $t0, -132($fp)
#LI, 2, , $temp8
li $t0, 2
sw $t0, -140($fp)
#LVAR, k, , $temp9
la $t1, k
lw $t0, 0($t1)
sw $t0, -144($fp)
#MUL, $temp8, $temp9, $temp8
lw $t0, -140($fp)
lw $t1, -144($fp)
mult $t0, $t1
mflo $t0
sw $t0, -140($fp)
#ADD, $temp6, $temp8, $temp6
lw $t0, -132($fp)
lw $t1, -140($fp)
add $t0, $t0, $t1
sw $t0, -132($fp)
#LARY, chararray, $temp6, $temp5
lw $t0, -132($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -128($fp)
#RET, , , $temp5
lw $v0, -128($fp)
addi $sp, $sp, 152
jr $ra
#FUNC, int, , return_3
return_3:
add $fp, $sp, 0
subi $sp, $sp, 136
#LI, 3, , $temp10
li $t0, 3
sw $t0, -128($fp)
#RET, , , $temp10
lw $v0, -128($fp)
addi $sp, $sp, 136
jr $ra
#FUNC, int, , fib
fib:
add $fp, $sp, 4
subi $sp, $sp, 180
#PARA, int, , n
#LVAR, n, , $temp11
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 0, , $temp12
li $t0, 0
sw $t0, -136($fp)
#BGE, $temp11, $temp12, label0
lw $t0, -132($fp)
lw $t1, -136($fp)
bge $t0, $t1, label0
#LI, 0, , $temp13
li $t0, 0
sw $t0, -140($fp)
#RET, , , $temp13
lw $v0, -140($fp)
addi $sp, $sp, 184
jr $ra
#JUMP, , , label1
j label1
#LAB, , , label0
label0:
#LVAR, n, , $temp14
lw $t0, 0($fp)
sw $t0, -144($fp)
#LI, 0, , $temp15
li $t0, 0
sw $t0, -148($fp)
#BEQ, $temp14, $temp15, label2
lw $t0, -144($fp)
lw $t1, -148($fp)
beq $t0, $t1, label2
#LVAR, n, , $temp17
lw $t0, 0($fp)
sw $t0, -152($fp)
#LI, 1, , $temp18
li $t0, 1
sw $t0, -156($fp)
#SUB, $temp17, $temp18, $temp17
lw $t0, -152($fp)
lw $t1, -156($fp)
sub $t0, $t0, $t1
sw $t0, -152($fp)
#PUSH, , , $temp17
lw $t0, -152($fp)
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
#VOF, fib, , $temp16
sw $v0, -160($fp)
#LVAR, n, , $temp20
lw $t0, 0($fp)
sw $t0, -164($fp)
#LI, 2, , $temp21
li $t0, 2
sw $t0, -168($fp)
#SUB, $temp20, $temp21, $temp20
lw $t0, -164($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -164($fp)
#PUSH, , , $temp20
lw $t0, -164($fp)
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
#VOF, fib, , $temp19
sw $v0, -172($fp)
#ADD, $temp16, $temp19, $temp16
lw $t0, -160($fp)
lw $t1, -172($fp)
add $t0, $t0, $t1
sw $t0, -160($fp)
#RET, , , $temp16
lw $v0, -160($fp)
addi $sp, $sp, 184
jr $ra
#JUMP, , , label3
j label3
#LAB, , , label2
label2:
#LI, 1, , $temp22
li $t0, 1
sw $t0, -176($fp)
#RET, , , $temp22
lw $v0, -176($fp)
addi $sp, $sp, 184
jr $ra
#LAB, , , label3
label3:
#LAB, , , label1
label1:
#FUNC, void, , testexpr
testexpr:
add $fp, $sp, 0
subi $sp, $sp, 300
#PC, , , 0
li $v0, 4
la $a0, $string0
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp23
li $t0, 0
sw $t0, -128($fp)
#LVAR, a1, , $temp25
la $t1, a1
lw $t0, 0($t1)
sw $t0, -132($fp)
#LVAR, b1, , $temp26
la $t1, b1
lw $t0, 0($t1)
sw $t0, -136($fp)
#MUL, $temp25, $temp26, $temp25
lw $t0, -132($fp)
lw $t1, -136($fp)
mult $t0, $t1
mflo $t0
sw $t0, -132($fp)
#PUSH, , , $temp25
lw $t0, -132($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, a1, , $temp27
la $t1, a1
lw $t0, 0($t1)
sw $t0, -140($fp)
#LVAR, b1, , $temp28
la $t1, b1
lw $t0, 0($t1)
sw $t0, -144($fp)
#DIV, $temp27, $temp28, $temp27
lw $t0, -140($fp)
lw $t1, -144($fp)
div $t0, $t1
mflo $t0
sw $t0, -140($fp)
#PUSH, , , $temp27
lw $t0, -140($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, b1, , $temp29
la $t1, b1
lw $t0, 0($t1)
sw $t0, -148($fp)
#LVAR, a1, , $temp30
la $t1, a1
lw $t0, 0($t1)
sw $t0, -152($fp)
#DIV, $temp29, $temp30, $temp29
lw $t0, -148($fp)
lw $t1, -152($fp)
div $t0, $t1
mflo $t0
sw $t0, -148($fp)
#PUSH, , , $temp29
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, d1, , $temp31
la $t1, d1
lw $t0, 0($t1)
sw $t0, -156($fp)
#PUSH, , , $temp31
lw $t0, -156($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, d2, , $temp32
la $t1, d2
lw $t0, 0($t1)
sw $t0, -164($fp)
#PUSH, , , $temp32
lw $t0, -164($fp)
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
lw $8, -52($sp)
lw $9, -56($sp)
lw $10, -60($sp)
lw $11, -64($sp)
lw $12, -68($sp)
lw $13, -72($sp)
lw $14, -76($sp)
lw $15, -80($sp)
lw $16, -84($sp)
lw $17, -88($sp)
lw $18, -92($sp)
lw $19, -96($sp)
lw $20, -100($sp)
lw $21, -104($sp)
lw $22, -108($sp)
lw $23, -112($sp)
lw $24, -116($sp)
lw $25, -120($sp)
lw $fp ,-140($sp)
lw $ra ,-144($sp)
#VOF, add, , $temp24
sw $v0, -168($fp)
#SARY, intarray, $temp23, $temp24
lw $t0, -128($fp)
mul $t0, $t0, 4
la $t1, intarray
add $t0, $t0, $t1 
lw $t1, -168($fp)
sw $t1, ($t0)
#LI, 1, , $temp33
li $t0, 1
sw $t0, -172($fp)
#LI, 1, , $temp34
li $t0, 1
sw $t0, -176($fp)
#LI, 2, , $temp35
li $t0, 2
sw $t0, -180($fp)
#ADD, $temp34, $temp35, $temp34
lw $t0, -176($fp)
lw $t1, -180($fp)
add $t0, $t0, $t1
sw $t0, -176($fp)
#LI, 2, , $temp36
li $t0, 2
sw $t0, -184($fp)
#LI, 3, , $temp37
li $t0, 3
sw $t0, -188($fp)
#LVAR, c1, , $temp38
la $t1, c1
lw $t0, 0($t1)
sw $t0, -192($fp)
#LI, 2, , $temp39
li $t0, 2
sw $t0, -196($fp)
#LI, 1, , $temp41
li $t0, 1
sw $t0, -200($fp)
#PUSH, , , $temp41
lw $t0, -200($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , return_3
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
jal return_3
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
#VOF, return_3, , $temp42
sw $v0, -204($fp)
#PUSH, , , $temp42
lw $t0, -204($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#VAR, int, , $temp43
#LI, 0, , $temp44
li $t0, 0
sw $t0, -212($fp)
#LARY, intarray, $temp44, $temp43
lw $t0, -212($fp)
mul $t0, $t0, 4
la $t1, intarray
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -208($fp)
#PUSH, , , $temp43
lw $t0, -208($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 65, , $temp45
li $t0, 65
sw $t0, -216($fp)
#LI, 0, , $temp46
li $t0, 0
sw $t0, -224($fp)
#SUB, $temp46, $temp45, $temp45
lw $t0, -224($fp)
lw $t1, -216($fp)
sub $t0, $t0, $t1
sw $t0, -216($fp)
#PUSH, , , $temp45
lw $t0, -216($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 65, , $temp47
li $t0, 65
sw $t0, -228($fp)
#PUSH, , , $temp47
lw $t0, -228($fp)
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
lw $8, -52($sp)
lw $9, -56($sp)
lw $10, -60($sp)
lw $11, -64($sp)
lw $12, -68($sp)
lw $13, -72($sp)
lw $14, -76($sp)
lw $15, -80($sp)
lw $16, -84($sp)
lw $17, -88($sp)
lw $18, -92($sp)
lw $19, -96($sp)
lw $20, -100($sp)
lw $21, -104($sp)
lw $22, -108($sp)
lw $23, -112($sp)
lw $24, -116($sp)
lw $25, -120($sp)
lw $fp ,-140($sp)
lw $ra ,-144($sp)
#VOF, add, , $temp40
sw $v0, -232($fp)
#LI, 40, , $temp48
li $t0, 40
sw $t0, -236($fp)
#SUB, $temp40, $temp48, $temp40
lw $t0, -232($fp)
lw $t1, -236($fp)
sub $t0, $t0, $t1
sw $t0, -232($fp)
#LVAR, k, , $temp49
la $t1, k
lw $t0, 0($t1)
sw $t0, -240($fp)
#SUB, $temp40, $temp49, $temp40
lw $t0, -232($fp)
lw $t1, -240($fp)
sub $t0, $t0, $t1
sw $t0, -232($fp)
#MUL, $temp39, $temp40, $temp39
lw $t0, -196($fp)
lw $t1, -232($fp)
mult $t0, $t1
mflo $t0
sw $t0, -196($fp)
#DIV, $temp38, $temp39, $temp38
lw $t0, -192($fp)
lw $t1, -196($fp)
div $t0, $t1
mflo $t0
sw $t0, -192($fp)
#ADD, $temp37, $temp38, $temp37
lw $t0, -188($fp)
lw $t1, -192($fp)
add $t0, $t0, $t1
sw $t0, -188($fp)
#MUL, $temp36, $temp37, $temp36
lw $t0, -184($fp)
lw $t1, -188($fp)
mult $t0, $t1
mflo $t0
sw $t0, -184($fp)
#ADD, $temp34, $temp36, $temp34
lw $t0, -176($fp)
lw $t1, -184($fp)
add $t0, $t0, $t1
sw $t0, -176($fp)
#SARY, intarray, $temp33, $temp34
lw $t0, -172($fp)
mul $t0, $t0, 4
la $t1, intarray
add $t0, $t0, $t1 
lw $t1, -176($fp)
sw $t1, ($t0)
#LI, 2, , $temp50
li $t0, 2
sw $t0, -256($fp)
#LVAR, k, , $temp52
la $t1, k
lw $t0, 0($t1)
sw $t0, -260($fp)
#PUSH, , , $temp52
lw $t0, -260($fp)
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
#VOF, fib, , $temp51
sw $v0, -264($fp)
#SARY, intarray, $temp50, $temp51
lw $t0, -256($fp)
mul $t0, $t0, 4
la $t1, intarray
add $t0, $t0, $t1 
lw $t1, -264($fp)
sw $t1, ($t0)
#LI, 0, , $temp53
li $t0, 0
sw $t0, -268($fp)
#LVAR, $temp53, , j
lw $t0, -268($fp)
la $t1, j
sw $t0, 0($t1)
#LAB, , , label5
label5:
#VAR, int, , $temp54
#LVAR, j, , $temp55
la $t1, j
lw $t0, 0($t1)
sw $t0, -276($fp)
#LARY, intarray, $temp55, $temp54
lw $t0, -276($fp)
mul $t0, $t0, 4
la $t1, intarray
add $t0, $t0, $t1 
lw $t0, ($t0)
sw $t0, -272($fp)
#PI, , , $temp54
li $v0, 1
lw $a0, -272($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, j, , $temp56
la $t1, j
lw $t0, 0($t1)
sw $t0, -280($fp)
#LI, 1, , $temp57
li $t0, 1
sw $t0, -284($fp)
#ADD, $temp56, $temp57, $temp56
lw $t0, -280($fp)
lw $t1, -284($fp)
add $t0, $t0, $t1
sw $t0, -280($fp)
#LVAR, $temp56, , j
lw $t0, -280($fp)
la $t1, j
sw $t0, 0($t1)
#LAB, , , label4
label4:
#LVAR, j, , $temp58
la $t1, j
lw $t0, 0($t1)
sw $t0, -288($fp)
#LI, 2, , $temp59
li $t0, 2
sw $t0, -292($fp)
#BGT, $temp58, $temp59, label6
lw $t0, -288($fp)
lw $t1, -292($fp)
bgt $t0, $t1, label6
#JUMP, , , label5
j label5
#LAB, , , label6
label6:
#REN, , , 
addi $sp, $sp, 300
jr $ra
#FUNC, void, , testempty
testempty:
add $fp, $sp, 0
subi $sp, $sp, 132
#REN, , , 
addi $sp, $sp, 132
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 400
#CON, int, 10, max
li $t2, 10
#VAR, int, , x
#VAR, int, , y
#VAR, int, , z
#VAR, char, , tem
#LI, 0, , $temp60
li $t0, 0
sw $t0, -148($fp)
#LVAR, $temp60, , i
lw $t0, -148($fp)
la $t1, i
sw $t0, 0($t1)
#LI, 0, , $temp61
li $t0, 0
sw $t0, -152($fp)
#LVAR, $temp61, , k
lw $t0, -152($fp)
la $t1, k
sw $t0, 0($t1)
#LVAR, max, , $temp62
move $t0 $t2
sw $t0, -156($fp)
#LVAR, $temp62, , z
lw $t0, -156($fp)
move $t5, $t0
#LI, 0, , $temp63
li $t0, 0
sw $t0, -160($fp)
#LI, 104, , $temp64
li $t0, 104
sw $t0, -164($fp)
#SARY, chararray, $temp63, $temp64
lw $t0, -160($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -164($fp)
sw $t1, ($t0)
#LI, 1, , $temp65
li $t0, 1
sw $t0, -168($fp)
#LI, 0, , $temp66
li $t0, 0
sw $t0, -172($fp)
#SUB, $temp66, $temp65, $temp65
lw $t0, -172($fp)
lw $t1, -168($fp)
sub $t0, $t0, $t1
sw $t0, -168($fp)
#LI, 101, , $temp67
li $t0, 101
sw $t0, -176($fp)
#SARY, chararray, $temp65, $temp67
lw $t0, -168($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -176($fp)
sw $t1, ($t0)
#LI, 2, , $temp68
li $t0, 2
sw $t0, -180($fp)
#LI, 108, , $temp69
li $t0, 108
sw $t0, -184($fp)
#SARY, chararray, $temp68, $temp69
lw $t0, -180($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -184($fp)
sw $t1, ($t0)
#LI, 3, , $temp70
li $t0, 3
sw $t0, -188($fp)
#LI, 108, , $temp71
li $t0, 108
sw $t0, -192($fp)
#SARY, chararray, $temp70, $temp71
lw $t0, -188($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -192($fp)
sw $t1, ($t0)
#LI, 4, , $temp72
li $t0, 4
sw $t0, -196($fp)
#LI, 111, , $temp73
li $t0, 111
sw $t0, -200($fp)
#SARY, chararray, $temp72, $temp73
lw $t0, -196($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -200($fp)
sw $t1, ($t0)
#LI, 5, , $temp74
li $t0, 5
sw $t0, -204($fp)
#LI, 95, , $temp75
li $t0, 95
sw $t0, -208($fp)
#SARY, chararray, $temp74, $temp75
lw $t0, -204($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -208($fp)
sw $t1, ($t0)
#LI, 6, , $temp76
li $t0, 6
sw $t0, -212($fp)
#LI, 119, , $temp77
li $t0, 119
sw $t0, -216($fp)
#SARY, chararray, $temp76, $temp77
lw $t0, -212($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -216($fp)
sw $t1, ($t0)
#LI, 7, , $temp78
li $t0, 7
sw $t0, -220($fp)
#LI, 111, , $temp79
li $t0, 111
sw $t0, -224($fp)
#SARY, chararray, $temp78, $temp79
lw $t0, -220($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -224($fp)
sw $t1, ($t0)
#LI, 8, , $temp80
li $t0, 8
sw $t0, -228($fp)
#LI, 114, , $temp81
li $t0, 114
sw $t0, -232($fp)
#SARY, chararray, $temp80, $temp81
lw $t0, -228($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -232($fp)
sw $t1, ($t0)
#LI, 9, , $temp82
li $t0, 9
sw $t0, -236($fp)
#LI, 108, , $temp83
li $t0, 108
sw $t0, -240($fp)
#SARY, chararray, $temp82, $temp83
lw $t0, -236($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -240($fp)
sw $t1, ($t0)
#LI, 10, , $temp84
li $t0, 10
sw $t0, -244($fp)
#LI, 100, , $temp85
li $t0, 100
sw $t0, -248($fp)
#SARY, chararray, $temp84, $temp85
lw $t0, -244($fp)
mul $t0, $t0, 4
la $t1, chararray
add $t0, $t0, $t1 
lw $t1, -248($fp)
sw $t1, ($t0)
#READ, , , x
li $v0, 5
syscall
move $t3, $v0
#READ, , , y
li $v0, 5
syscall
move $t4, $v0
#READ, , , op
li $v0, 12
syscall
la $t1, op
sw $v0, 0($t1)
#LVAR, op, , $temp86
la $t1, op
lw $t0, 0($t1)
sw $t0, -252($fp)
#LI, 43, , $temp87
li $t0, 43
sw $t0, -256($fp)
#BNE, $temp86, $temp87, label8
lw $t0, -252($fp)
lw $t1, -256($fp)
bne $t0, $t1, label8
#LVAR, x, , $temp88
move $t0 $t3
sw $t0, -260($fp)
#LVAR, y, , $temp89
move $t0 $t4
sw $t0, -264($fp)
#ADD, $temp88, $temp89, $temp88
lw $t0, -260($fp)
lw $t1, -264($fp)
add $t0, $t0, $t1
sw $t0, -260($fp)
#LVAR, $temp88, , z
lw $t0, -260($fp)
move $t5, $t0
#LVAR, z, , $temp90
move $t0 $t5
sw $t0, -268($fp)
#LI, 1, , $temp91
li $t0, 1
sw $t0, -272($fp)
#BNE, $temp90, $temp91, label10
lw $t0, -268($fp)
lw $t1, -272($fp)
bne $t0, $t1, label10
#LVAR, k, , $temp92
la $t1, k
lw $t0, 0($t1)
sw $t0, -276($fp)
#LI, 1, , $temp93
li $t0, 1
sw $t0, -280($fp)
#ADD, $temp92, $temp93, $temp92
lw $t0, -276($fp)
lw $t1, -280($fp)
add $t0, $t0, $t1
sw $t0, -276($fp)
#LVAR, $temp92, , k
lw $t0, -276($fp)
la $t1, k
sw $t0, 0($t1)
#JUMP, , , label9
j label9
#LAB, , , label10
label10:
#LI, 2, , $temp94
li $t0, 2
sw $t0, -284($fp)
#BNE, $temp90, $temp94, label11
lw $t0, -268($fp)
lw $t1, -284($fp)
bne $t0, $t1, label11
#LVAR, k, , $temp95
la $t1, k
lw $t0, 0($t1)
sw $t0, -288($fp)
#LI, 2, , $temp96
li $t0, 2
sw $t0, -292($fp)
#ADD, $temp95, $temp96, $temp95
lw $t0, -288($fp)
lw $t1, -292($fp)
add $t0, $t0, $t1
sw $t0, -288($fp)
#LVAR, $temp95, , k
lw $t0, -288($fp)
la $t1, k
sw $t0, 0($t1)
#JUMP, , , label9
j label9
#LAB, , , label11
label11:
#LVAR, k, , $temp97
la $t1, k
lw $t0, 0($t1)
sw $t0, -296($fp)
#LI, 3, , $temp98
li $t0, 3
sw $t0, -300($fp)
#ADD, $temp97, $temp98, $temp97
lw $t0, -296($fp)
lw $t1, -300($fp)
add $t0, $t0, $t1
sw $t0, -296($fp)
#LVAR, $temp97, , k
lw $t0, -296($fp)
la $t1, k
sw $t0, 0($t1)
#LAB, , , label9
label9:
#JUMP, , , label7
j label7
#LAB, , , label8
label8:
#LI, 45, , $temp99
li $t0, 45
sw $t0, -304($fp)
#BNE, $temp86, $temp99, label12
lw $t0, -252($fp)
lw $t1, -304($fp)
bne $t0, $t1, label12
#LVAR, x, , $temp100
move $t0 $t3
sw $t0, -308($fp)
#LVAR, y, , $temp101
move $t0 $t4
sw $t0, -312($fp)
#SUB, $temp100, $temp101, $temp100
lw $t0, -308($fp)
lw $t1, -312($fp)
sub $t0, $t0, $t1
sw $t0, -308($fp)
#LVAR, $temp100, , z
lw $t0, -308($fp)
move $t5, $t0
#LVAR, z, , $temp102
move $t0 $t5
sw $t0, -316($fp)
#LI, 0, , $temp103
li $t0, 0
sw $t0, -320($fp)
#BNE, $temp102, $temp103, label13
lw $t0, -316($fp)
lw $t1, -320($fp)
bne $t0, $t1, label13
#LVAR, k, , $temp104
la $t1, k
lw $t0, 0($t1)
sw $t0, -324($fp)
#LI, 4, , $temp105
li $t0, 4
sw $t0, -328($fp)
#ADD, $temp104, $temp105, $temp104
lw $t0, -324($fp)
lw $t1, -328($fp)
add $t0, $t0, $t1
sw $t0, -324($fp)
#LVAR, $temp104, , k
lw $t0, -324($fp)
la $t1, k
sw $t0, 0($t1)
#JUMP, , , label14
j label14
#LAB, , , label13
label13:
#LVAR, k, , $temp106
la $t1, k
lw $t0, 0($t1)
sw $t0, -332($fp)
#LI, 5, , $temp107
li $t0, 5
sw $t0, -336($fp)
#ADD, $temp106, $temp107, $temp106
lw $t0, -332($fp)
lw $t1, -336($fp)
add $t0, $t0, $t1
sw $t0, -332($fp)
#LVAR, $temp106, , k
lw $t0, -332($fp)
la $t1, k
sw $t0, 0($t1)
#LAB, , , label14
label14:
#JUMP, , , label7
j label7
#LAB, , , label12
label12:
#LVAR, x, , $temp108
move $t0 $t3
sw $t0, -340($fp)
#LVAR, y, , $temp109
move $t0 $t4
sw $t0, -344($fp)
#MUL, $temp108, $temp109, $temp108
lw $t0, -340($fp)
lw $t1, -344($fp)
mult $t0, $t1
mflo $t0
sw $t0, -340($fp)
#LVAR, $temp108, , z
lw $t0, -340($fp)
move $t5, $t0
#LVAR, z, , $temp110
move $t0 $t5
sw $t0, -348($fp)
#LI, 0, , $temp111
li $t0, 0
sw $t0, -352($fp)
#BLT, $temp110, $temp111, label15
lw $t0, -348($fp)
lw $t1, -352($fp)
blt $t0, $t1, label15
#LVAR, k, , $temp112
la $t1, k
lw $t0, 0($t1)
sw $t0, -356($fp)
#LI, 6, , $temp113
li $t0, 6
sw $t0, -360($fp)
#ADD, $temp112, $temp113, $temp112
lw $t0, -356($fp)
lw $t1, -360($fp)
add $t0, $t0, $t1
sw $t0, -356($fp)
#LVAR, $temp112, , k
lw $t0, -356($fp)
la $t1, k
sw $t0, 0($t1)
#JUMP, , , label16
j label16
#LAB, , , label15
label15:
#LVAR, k, , $temp114
la $t1, k
lw $t0, 0($t1)
sw $t0, -364($fp)
#LI, 7, , $temp115
li $t0, 7
sw $t0, -368($fp)
#ADD, $temp114, $temp115, $temp114
lw $t0, -364($fp)
lw $t1, -368($fp)
add $t0, $t0, $t1
sw $t0, -364($fp)
#LVAR, $temp114, , k
lw $t0, -364($fp)
la $t1, k
sw $t0, 0($t1)
#LAB, , , label16
label16:
#LAB, , , label7
label7:
#CALL, , , get
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
jal get
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
#VOF, get, , $temp116
sw $v0, -372($fp)
#LVAR, $temp116, , tem
lw $t0, -372($fp)
move $t6, $t0
#LVAR, tem, , $temp117
move $t0 $t6
sw $t0, -376($fp)
#LI, 95, , $temp118
li $t0, 95
sw $t0, -384($fp)
#BEQ, $temp117, $temp118, label17
lw $t0, -376($fp)
lw $t1, -384($fp)
beq $t0, $t1, label17
#PC, , , 1
li $v0, 4
la $a0, $string1
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, tem, , $temp119
move $t0 $t6
sw $t0, -392($fp)
#PI, , , $temp119
li $v0, 11
lw $a0, -392($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , label18
j label18
#LAB, , , label17
label17:
#PC, , , 2
li $v0, 4
la $a0, $string2
syscall
li $v0, 4
la $a0,$enter
syscall
#LAB, , , label18
label18:
#CALL, , , testexpr
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
jal testexpr
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
#CALL, , , testempty
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
jal testempty
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
