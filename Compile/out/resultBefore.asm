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
#FUNC, int, , factorial
factorial:
add $fp, $sp, 4
subi $sp, $sp, 160
#PARA, int, , n
#LVAR, n, , $temp0
lw $t0, 0($fp)
sw $t0, -132($fp)
#LI, 1, , $temp1
li $t0, 1
sw $t0, -136($fp)
#BGT, $temp0, $temp1, $label0
lw $t0, -132($fp)
lw $t1, -136($fp)
bgt $t0, $t1, $label0
#LI, 1, , $temp2
li $t0, 1
sw $t0, -140($fp)
#RET, , , $temp2
lw $v0, -140($fp)
addi $sp, $sp, 164
jr $ra
#JUMP, , , $label1
j $label1
#LAB, , , $label0
$label0:
#LVAR, n, , $temp3
lw $t0, 0($fp)
sw $t0, -144($fp)
#LVAR, n, , $temp5
lw $t0, 0($fp)
sw $t0, -148($fp)
#LI, 1, , $temp6
li $t0, 1
sw $t0, -152($fp)
#SUB, $temp5, $temp6, $temp5
lw $t0, -148($fp)
lw $t1, -152($fp)
sub $t0, $t0, $t1
sw $t0, -148($fp)
#PUSH, , , $temp5
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , factorial
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal factorial
lw $4, -20($sp)
lw $5, -24($sp)
lw $6, -28($sp)
lw $7, -32($sp)
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
#VOF, factorial, , $temp4
sw $v0, -156($fp)
#MUL, $temp3, $temp4, $temp3
lw $t0, -144($fp)
lw $t1, -156($fp)
mult $t0, $t1
mflo $t0
sw $t0, -144($fp)
#RET, , , $temp3
lw $v0, -144($fp)
addi $sp, $sp, 164
jr $ra
#LAB, , , $label1
$label1:
#FUNC, int, , mod
mod:
add $fp, $sp, 8
subi $sp, $sp, 152
#PARA, int, , x
#PARA, int, , y
#LVAR, x, , $temp7
lw $t0, 0($fp)
sw $t0, -136($fp)
#LVAR, x, , $temp8
lw $t0, 0($fp)
sw $t0, -140($fp)
#LVAR, y, , $temp9
lw $t0, -4($fp)
sw $t0, -144($fp)
#DIV, $temp8, $temp9, $temp8
lw $t0, -140($fp)
lw $t1, -144($fp)
div $t0, $t1
mflo $t0
sw $t0, -140($fp)
#LVAR, y, , $temp10
lw $t0, -4($fp)
sw $t0, -148($fp)
#MUL, $temp8, $temp10, $temp8
lw $t0, -140($fp)
lw $t1, -148($fp)
mult $t0, $t1
mflo $t0
sw $t0, -140($fp)
#SUB, $temp7, $temp8, $temp7
lw $t0, -136($fp)
lw $t1, -140($fp)
sub $t0, $t0, $t1
sw $t0, -136($fp)
#LVAR, $temp7, , x
lw $t0, -136($fp)
sw $t0, 0($fp)
#LVAR, x, , $temp11
lw $t0, 0($fp)
sw $t0, -152($fp)
#RET, , , $temp11
lw $v0, -152($fp)
addi $sp, $sp, 160
jr $ra
#FUNC, void, , swap
swap:
add $fp, $sp, 8
subi $sp, $sp, 164
#PARA, int, , x
#PARA, int, , y
#VAR, int, , temp
#LVAR, x, , $temp12
lw $t0, 0($fp)
sw $t0, -140($fp)
#PRT, 2, 0, $temp12
li $v0, 4
la $a0, $string0
syscall
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, y, , $temp13
lw $t0, -4($fp)
sw $t0, -144($fp)
#PRT, 2, 1, $temp13
li $v0, 4
la $a0, $string1
syscall
li $v0, 1
lw $a0, -144($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, x, , $temp14
lw $t0, 0($fp)
sw $t0, -148($fp)
#LVAR, $temp14, , temp
lw $t0, -148($fp)
move $t2, $t0
#LVAR, y, , $temp15
lw $t0, -4($fp)
sw $t0, -152($fp)
#LVAR, $temp15, , x
lw $t0, -152($fp)
sw $t0, 0($fp)
#LVAR, temp, , $temp16
move $t0, $t2
sw $t0, -156($fp)
#LVAR, $temp16, , y
lw $t0, -156($fp)
sw $t0, -4($fp)
#LVAR, x, , $temp17
lw $t0, 0($fp)
sw $t0, -160($fp)
#PRT, 2, 2, $temp17
li $v0, 4
la $a0, $string2
syscall
li $v0, 1
lw $a0, -160($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, y, , $temp18
lw $t0, -4($fp)
sw $t0, -164($fp)
#PRT, 2, 3, $temp18
li $v0, 4
la $a0, $string3
syscall
li $v0, 1
lw $a0, -164($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 172
jr $ra
#FUNC, void, , complete_num
complete_num:
add $fp, $sp, 4
subi $sp, $sp, 1080
#PARA, int, , val
#ARY, int, 128, k
#VAR, int, , i
#VAR, int, , j
#VAR, int, , n
#VAR, int, , s
#VAR, int, , x1
#VAR, int, , m
#VAR, int, , k2
#VAR, int, , h
#VAR, int, , leap
#VAR, int, , x2
#VAR, int, , a
#VAR, int, , b
#VAR, int, , c
#LVAR, val, , $temp19
lw $t0, 0($fp)
sw $t0, -696($fp)
#LVAR, $temp19, , j
lw $t0, -696($fp)
sw $t0, -648($fp)
#LAB, , , $label3
$label3:
#LI, 1, , $temp20
li $t0, 1
sw $t0, -700($fp)
#LI, 0, , $temp21
li $t0, 0
sw $t0, -704($fp)
#SUB, $temp21, $temp20, $temp20
lw $t0, -704($fp)
lw $t1, -700($fp)
sub $t0, $t0, $t1
sw $t0, -700($fp)
#LVAR, $temp20, , n
lw $t0, -700($fp)
sw $t0, -652($fp)
#LVAR, j, , $temp22
lw $t0, -648($fp)
sw $t0, -708($fp)
#LVAR, $temp22, , s
lw $t0, -708($fp)
sw $t0, -656($fp)
#LI, 1, , $temp23
li $t0, 1
sw $t0, -712($fp)
#LVAR, $temp23, , i
lw $t0, -712($fp)
sw $t0, -644($fp)
#LAB, , , $label6
$label6:
#LVAR, j, , $temp24
lw $t0, -648($fp)
sw $t0, -716($fp)
#LVAR, i, , $temp25
lw $t0, -644($fp)
sw $t0, -720($fp)
#DIV, $temp24, $temp25, $temp24
lw $t0, -716($fp)
lw $t1, -720($fp)
div $t0, $t1
mflo $t0
sw $t0, -716($fp)
#LVAR, i, , $temp26
lw $t0, -644($fp)
sw $t0, -724($fp)
#MUL, $temp24, $temp26, $temp24
lw $t0, -716($fp)
lw $t1, -724($fp)
mult $t0, $t1
mflo $t0
sw $t0, -716($fp)
#LVAR, $temp24, , x1
lw $t0, -716($fp)
sw $t0, -660($fp)
#LVAR, j, , $temp28
lw $t0, -648($fp)
sw $t0, -728($fp)
#PUSH, , , $temp28
lw $t0, -728($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, i, , $temp29
lw $t0, -644($fp)
sw $t0, -732($fp)
#PUSH, , , $temp29
lw $t0, -732($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , mod
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal mod
lw $4, -24($sp)
lw $5, -28($sp)
lw $6, -32($sp)
lw $7, -36($sp)
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
#VOF, mod, , $temp27
sw $v0, -736($fp)
#LI, 0, , $temp30
li $t0, 0
sw $t0, -740($fp)
#BNE, $temp27, $temp30, $label8
lw $t0, -736($fp)
lw $t1, -740($fp)
bne $t0, $t1, $label8
#LVAR, n, , $temp31
lw $t0, -652($fp)
sw $t0, -744($fp)
#LI, 1, , $temp32
li $t0, 1
sw $t0, -748($fp)
#ADD, $temp31, $temp32, $temp31
lw $t0, -744($fp)
lw $t1, -748($fp)
add $t0, $t0, $t1
sw $t0, -744($fp)
#LVAR, $temp31, , n
lw $t0, -744($fp)
sw $t0, -652($fp)
#LVAR, s, , $temp33
lw $t0, -656($fp)
sw $t0, -752($fp)
#LVAR, i, , $temp34
lw $t0, -644($fp)
sw $t0, -756($fp)
#SUB, $temp33, $temp34, $temp33
lw $t0, -752($fp)
lw $t1, -756($fp)
sub $t0, $t0, $t1
sw $t0, -752($fp)
#LVAR, $temp33, , s
lw $t0, -752($fp)
sw $t0, -656($fp)
#LVAR, n, , $temp35
lw $t0, -652($fp)
sw $t0, -760($fp)
#LI, 128, , $temp36
li $t0, 128
sw $t0, -764($fp)
#BLT, $temp35, $temp36, $label10
lw $t0, -760($fp)
lw $t1, -764($fp)
blt $t0, $t1, $label10
#PRT, 1, , 4
li $v0, 4
la $a0, $string4
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label11
j $label11
#LAB, , , $label10
$label10:
#LVAR, n, , $temp37
lw $t0, -652($fp)
sw $t0, -768($fp)
#LVAR, i, , $temp38
lw $t0, -644($fp)
sw $t0, -772($fp)
#SARY, k, $temp37, $temp38
lw $t0, -768($fp)
mul $t0, $t0, 4
addi $t1, $fp, -132
sub $t0, $t1, $t0
lw $t1, -772($fp)
sw $t1, ($t0)
#LAB, , , $label11
$label11:
#JUMP, , , $label9
j $label9
#LAB, , , $label8
$label8:
#LAB, , , $label9
$label9:
#LVAR, i, , $temp39
lw $t0, -644($fp)
sw $t0, -776($fp)
#LI, 1, , $temp40
li $t0, 1
sw $t0, -780($fp)
#ADD, $temp39, $temp40, $temp39
lw $t0, -776($fp)
lw $t1, -780($fp)
add $t0, $t0, $t1
sw $t0, -776($fp)
#LVAR, $temp39, , i
lw $t0, -776($fp)
sw $t0, -644($fp)
#LAB, , , $label5
$label5:
#LVAR, i, , $temp41
lw $t0, -644($fp)
sw $t0, -784($fp)
#LVAR, j, , $temp42
lw $t0, -648($fp)
sw $t0, -788($fp)
#BGE, $temp41, $temp42, $label7
lw $t0, -784($fp)
lw $t1, -788($fp)
bge $t0, $t1, $label7
#JUMP, , , $label6
j $label6
#LAB, , , $label7
$label7:
#LVAR, s, , $temp43
lw $t0, -656($fp)
sw $t0, -792($fp)
#LI, 0, , $temp44
li $t0, 0
sw $t0, -796($fp)
#BNE, $temp43, $temp44, $label12
lw $t0, -792($fp)
lw $t1, -796($fp)
bne $t0, $t1, $label12
#LVAR, j, , $temp45
lw $t0, -648($fp)
sw $t0, -800($fp)
#PRT, 2, 5, $temp45
li $v0, 4
la $a0, $string5
syscall
li $v0, 1
lw $a0, -800($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp46
li $t0, 0
sw $t0, -804($fp)
#LVAR, $temp46, , i
lw $t0, -804($fp)
sw $t0, -644($fp)
#LAB, , , $label15
$label15:
#VAR, int, , $temp47
#LVAR, i, , $temp48
lw $t0, -644($fp)
sw $t0, -812($fp)
#LARY, k, $temp48, $temp47
lw $t0, -812($fp)
mul $t0, $t0, 4
addi $t1, $fp, -132
sub $t0, $t1, $t0
lw $t0, ($t0)
sw $t0, -808($fp)
#PRT, 2, 6, $temp47
li $v0, 4
la $a0, $string6
syscall
li $v0, 1
lw $a0, -808($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, i, , $temp49
lw $t0, -644($fp)
sw $t0, -816($fp)
#LI, 1, , $temp50
li $t0, 1
sw $t0, -820($fp)
#ADD, $temp49, $temp50, $temp49
lw $t0, -816($fp)
lw $t1, -820($fp)
add $t0, $t0, $t1
sw $t0, -816($fp)
#LVAR, $temp49, , i
lw $t0, -816($fp)
sw $t0, -644($fp)
#LAB, , , $label14
$label14:
#LVAR, i, , $temp51
lw $t0, -644($fp)
sw $t0, -824($fp)
#LVAR, n, , $temp52
lw $t0, -652($fp)
sw $t0, -828($fp)
#BGT, $temp51, $temp52, $label16
lw $t0, -824($fp)
lw $t1, -828($fp)
bgt $t0, $t1, $label16
#JUMP, , , $label15
j $label15
#LAB, , , $label16
$label16:
#PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label13
j $label13
#LAB, , , $label12
$label12:
#LAB, , , $label13
$label13:
#LVAR, j, , $temp53
lw $t0, -648($fp)
sw $t0, -832($fp)
#LI, 1, , $temp54
li $t0, 1
sw $t0, -836($fp)
#ADD, $temp53, $temp54, $temp53
lw $t0, -832($fp)
lw $t1, -836($fp)
add $t0, $t0, $t1
sw $t0, -832($fp)
#LVAR, $temp53, , j
lw $t0, -832($fp)
sw $t0, -648($fp)
#LAB, , , $label2
$label2:
#LVAR, j, , $temp55
lw $t0, -648($fp)
sw $t0, -840($fp)
#LVAR, max_num, , $temp56
la $t1, max_num
lw $t0, 0($t1)
sw $t0, -844($fp)
#BGE, $temp55, $temp56, $label4
lw $t0, -840($fp)
lw $t1, -844($fp)
bge $t0, $t1, $label4
#JUMP, , , $label3
j $label3
#LAB, , , $label4
$label4:
#PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp57
li $t0, 0
sw $t0, -848($fp)
#LVAR, $temp57, , a
lw $t0, -848($fp)
sw $t0, -684($fp)
#LI, 0, , $temp58
li $t0, 0
sw $t0, -852($fp)
#LVAR, $temp58, , i
lw $t0, -852($fp)
sw $t0, -644($fp)
#LAB, , , $label18
$label18:
#LVAR, a, , $temp59
lw $t0, -684($fp)
sw $t0, -856($fp)
#LVAR, i, , $temp60
lw $t0, -644($fp)
sw $t0, -860($fp)
#MUL, $temp59, $temp60, $temp59
lw $t0, -856($fp)
lw $t1, -860($fp)
mult $t0, $t1
mflo $t0
sw $t0, -856($fp)
#LVAR, $temp59, , b
lw $t0, -856($fp)
sw $t0, -688($fp)
#LVAR, j, , $temp61
lw $t0, -648($fp)
sw $t0, -864($fp)
#LVAR, n, , $temp62
lw $t0, -652($fp)
sw $t0, -868($fp)
#MUL, $temp61, $temp62, $temp61
lw $t0, -864($fp)
lw $t1, -868($fp)
mult $t0, $t1
mflo $t0
sw $t0, -864($fp)
#LVAR, $temp61, , c
lw $t0, -864($fp)
sw $t0, -692($fp)
#LVAR, a, , $temp63
lw $t0, -684($fp)
sw $t0, -872($fp)
#LVAR, i, , $temp64
lw $t0, -644($fp)
sw $t0, -876($fp)
#MUL, $temp63, $temp64, $temp63
lw $t0, -872($fp)
lw $t1, -876($fp)
mult $t0, $t1
mflo $t0
sw $t0, -872($fp)
#LVAR, $temp63, , a
lw $t0, -872($fp)
sw $t0, -684($fp)
#LVAR, a, , $temp65
lw $t0, -684($fp)
sw $t0, -880($fp)
#LVAR, b, , $temp66
lw $t0, -688($fp)
sw $t0, -884($fp)
#ADD, $temp65, $temp66, $temp65
lw $t0, -880($fp)
lw $t1, -884($fp)
add $t0, $t0, $t1
sw $t0, -880($fp)
#LVAR, c, , $temp67
lw $t0, -692($fp)
sw $t0, -888($fp)
#ADD, $temp65, $temp67, $temp65
lw $t0, -880($fp)
lw $t1, -888($fp)
add $t0, $t0, $t1
sw $t0, -880($fp)
#LVAR, $temp65, , a
lw $t0, -880($fp)
sw $t0, -684($fp)
#LVAR, i, , $temp68
lw $t0, -644($fp)
sw $t0, -892($fp)
#LI, 1, , $temp69
li $t0, 1
sw $t0, -896($fp)
#ADD, $temp68, $temp69, $temp68
lw $t0, -892($fp)
lw $t1, -896($fp)
add $t0, $t0, $t1
sw $t0, -892($fp)
#LVAR, $temp68, , i
lw $t0, -892($fp)
sw $t0, -644($fp)
#LAB, , , $label17
$label17:
#LVAR, i, , $temp70
lw $t0, -644($fp)
sw $t0, -900($fp)
#LVAR, max_num, , $temp71
la $t1, max_num
lw $t0, 0($t1)
sw $t0, -904($fp)
#BGE, $temp70, $temp71, $label19
lw $t0, -900($fp)
lw $t1, -904($fp)
bge $t0, $t1, $label19
#JUMP, , , $label18
j $label18
#LAB, , , $label19
$label19:
#LVAR, a, , $temp72
lw $t0, -684($fp)
sw $t0, -908($fp)
#LVAR, $temp72, , b
lw $t0, -908($fp)
sw $t0, -688($fp)
#LI, 0, , $temp73
li $t0, 0
sw $t0, -912($fp)
#LVAR, $temp73, , i
lw $t0, -912($fp)
sw $t0, -644($fp)
#LAB, , , $label21
$label21:
#LVAR, b, , $temp74
lw $t0, -688($fp)
sw $t0, -916($fp)
#LVAR, i, , $temp75
lw $t0, -644($fp)
sw $t0, -920($fp)
#ADD, $temp74, $temp75, $temp74
lw $t0, -916($fp)
lw $t1, -920($fp)
add $t0, $t0, $t1
sw $t0, -916($fp)
#LVAR, $temp74, , b
lw $t0, -916($fp)
sw $t0, -688($fp)
#LVAR, i, , $temp76
lw $t0, -644($fp)
sw $t0, -924($fp)
#LI, 1, , $temp77
li $t0, 1
sw $t0, -928($fp)
#ADD, $temp76, $temp77, $temp76
lw $t0, -924($fp)
lw $t1, -928($fp)
add $t0, $t0, $t1
sw $t0, -924($fp)
#LVAR, $temp76, , i
lw $t0, -924($fp)
sw $t0, -644($fp)
#LAB, , , $label20
$label20:
#LVAR, i, , $temp78
lw $t0, -644($fp)
sw $t0, -932($fp)
#LVAR, max_num, , $temp79
la $t1, max_num
lw $t0, 0($t1)
sw $t0, -936($fp)
#BGE, $temp78, $temp79, $label22
lw $t0, -932($fp)
lw $t1, -936($fp)
bge $t0, $t1, $label22
#JUMP, , , $label21
j $label21
#LAB, , , $label22
$label22:
#LVAR, b, , $temp80
lw $t0, -688($fp)
sw $t0, -940($fp)
#PRT, 2, 9, $temp80
li $v0, 4
la $a0, $string9
syscall
li $v0, 1
lw $a0, -940($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#PRT, 1, , 8
li $v0, 4
la $a0, $string8
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 0, , $temp81
li $t0, 0
sw $t0, -944($fp)
#LVAR, $temp81, , h
lw $t0, -944($fp)
sw $t0, -672($fp)
#LI, 1, , $temp82
li $t0, 1
sw $t0, -948($fp)
#LVAR, $temp82, , leap
lw $t0, -948($fp)
sw $t0, -676($fp)
#LI, 2, , $temp83
li $t0, 2
sw $t0, -952($fp)
#LVAR, $temp83, , m
lw $t0, -952($fp)
sw $t0, -664($fp)
#LAB, , , $label24
$label24:
#LVAR, m, , $temp84
lw $t0, -664($fp)
sw $t0, -956($fp)
#LI, 2, , $temp85
li $t0, 2
sw $t0, -960($fp)
#DIV, $temp84, $temp85, $temp84
lw $t0, -956($fp)
lw $t1, -960($fp)
div $t0, $t1
mflo $t0
sw $t0, -956($fp)
#LVAR, $temp84, , k2
lw $t0, -956($fp)
sw $t0, -668($fp)
#LI, 2, , $temp86
li $t0, 2
sw $t0, -964($fp)
#LVAR, $temp86, , i
lw $t0, -964($fp)
sw $t0, -644($fp)
#LAB, , , $label27
$label27:
#LVAR, m, , $temp87
lw $t0, -664($fp)
sw $t0, -968($fp)
#LVAR, i, , $temp88
lw $t0, -644($fp)
sw $t0, -972($fp)
#DIV, $temp87, $temp88, $temp87
lw $t0, -968($fp)
lw $t1, -972($fp)
div $t0, $t1
mflo $t0
sw $t0, -968($fp)
#LVAR, i, , $temp89
lw $t0, -644($fp)
sw $t0, -976($fp)
#MUL, $temp87, $temp89, $temp87
lw $t0, -968($fp)
lw $t1, -976($fp)
mult $t0, $t1
mflo $t0
sw $t0, -968($fp)
#LVAR, $temp87, , x2
lw $t0, -968($fp)
sw $t0, -680($fp)
#LVAR, m, , $temp91
lw $t0, -664($fp)
sw $t0, -980($fp)
#PUSH, , , $temp91
lw $t0, -980($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LVAR, i, , $temp92
lw $t0, -644($fp)
sw $t0, -984($fp)
#PUSH, , , $temp92
lw $t0, -984($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , mod
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal mod
lw $4, -24($sp)
lw $5, -28($sp)
lw $6, -32($sp)
lw $7, -36($sp)
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
#VOF, mod, , $temp90
sw $v0, -988($fp)
#LI, 0, , $temp93
li $t0, 0
sw $t0, -992($fp)
#BNE, $temp90, $temp93, $label29
lw $t0, -988($fp)
lw $t1, -992($fp)
bne $t0, $t1, $label29
#LI, 0, , $temp94
li $t0, 0
sw $t0, -996($fp)
#LVAR, $temp94, , leap
lw $t0, -996($fp)
sw $t0, -676($fp)
#JUMP, , , $label30
j $label30
#LAB, , , $label29
$label29:
#LAB, , , $label30
$label30:
#LVAR, i, , $temp95
lw $t0, -644($fp)
sw $t0, -1000($fp)
#LI, 1, , $temp96
li $t0, 1
sw $t0, -1004($fp)
#ADD, $temp95, $temp96, $temp95
lw $t0, -1000($fp)
lw $t1, -1004($fp)
add $t0, $t0, $t1
sw $t0, -1000($fp)
#LVAR, $temp95, , i
lw $t0, -1000($fp)
sw $t0, -644($fp)
#LAB, , , $label26
$label26:
#LVAR, i, , $temp97
lw $t0, -644($fp)
sw $t0, -1008($fp)
#LVAR, k2, , $temp98
lw $t0, -668($fp)
sw $t0, -1012($fp)
#BGT, $temp97, $temp98, $label28
lw $t0, -1008($fp)
lw $t1, -1012($fp)
bgt $t0, $t1, $label28
#JUMP, , , $label27
j $label27
#LAB, , , $label28
$label28:
#LVAR, leap, , $temp99
lw $t0, -676($fp)
sw $t0, -1016($fp)
#LI, 1, , $temp100
li $t0, 1
sw $t0, -1020($fp)
#BNE, $temp99, $temp100, $label31
lw $t0, -1016($fp)
lw $t1, -1020($fp)
bne $t0, $t1, $label31
#LVAR, m, , $temp101
lw $t0, -664($fp)
sw $t0, -1024($fp)
#PRT, 2, 10, $temp101
li $v0, 4
la $a0, $string10
syscall
li $v0, 1
lw $a0, -1024($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LVAR, h, , $temp102
lw $t0, -672($fp)
sw $t0, -1028($fp)
#LI, 1, , $temp103
li $t0, 1
sw $t0, -1032($fp)
#ADD, $temp102, $temp103, $temp102
lw $t0, -1028($fp)
lw $t1, -1032($fp)
add $t0, $t0, $t1
sw $t0, -1028($fp)
#LVAR, $temp102, , h
lw $t0, -1028($fp)
sw $t0, -672($fp)
#LVAR, h, , $temp104
lw $t0, -672($fp)
sw $t0, -1036($fp)
#LI, 10, , $temp105
li $t0, 10
sw $t0, -1040($fp)
#DIV, $temp104, $temp105, $temp104
lw $t0, -1036($fp)
lw $t1, -1040($fp)
div $t0, $t1
mflo $t0
sw $t0, -1036($fp)
#LI, 10, , $temp106
li $t0, 10
sw $t0, -1044($fp)
#MUL, $temp104, $temp106, $temp104
lw $t0, -1036($fp)
lw $t1, -1044($fp)
mult $t0, $t1
mflo $t0
sw $t0, -1036($fp)
#LVAR, $temp104, , x2
lw $t0, -1036($fp)
sw $t0, -680($fp)
#LVAR, x2, , $temp107
lw $t0, -680($fp)
sw $t0, -1048($fp)
#LVAR, h, , $temp108
lw $t0, -672($fp)
sw $t0, -1052($fp)
#BNE, $temp107, $temp108, $label33
lw $t0, -1048($fp)
lw $t1, -1052($fp)
bne $t0, $t1, $label33
#PRT, 1, , 7
li $v0, 4
la $a0, $string7
syscall
li $v0, 4
la $a0,$enter
syscall
#JUMP, , , $label34
j $label34
#LAB, , , $label33
$label33:
#LAB, , , $label34
$label34:
#JUMP, , , $label32
j $label32
#LAB, , , $label31
$label31:
#LAB, , , $label32
$label32:
#LI, 1, , $temp109
li $t0, 1
sw $t0, -1056($fp)
#LVAR, $temp109, , leap
lw $t0, -1056($fp)
sw $t0, -676($fp)
#LVAR, m, , $temp110
lw $t0, -664($fp)
sw $t0, -1060($fp)
#LI, 1, , $temp111
li $t0, 1
sw $t0, -1064($fp)
#ADD, $temp110, $temp111, $temp110
lw $t0, -1060($fp)
lw $t1, -1064($fp)
add $t0, $t0, $t1
sw $t0, -1060($fp)
#LVAR, $temp110, , m
lw $t0, -1060($fp)
sw $t0, -664($fp)
#LAB, , , $label23
$label23:
#LVAR, m, , $temp112
lw $t0, -664($fp)
sw $t0, -1068($fp)
#LVAR, max_num, , $temp113
la $t1, max_num
lw $t0, 0($t1)
sw $t0, -1072($fp)
#BGT, $temp112, $temp113, $label25
lw $t0, -1068($fp)
lw $t1, -1072($fp)
bgt $t0, $t1, $label25
#JUMP, , , $label24
j $label24
#LAB, , , $label25
$label25:
#LVAR, h, , $temp114
lw $t0, -672($fp)
sw $t0, -1076($fp)
#PRT, 2, 11, $temp114
li $v0, 4
la $a0, $string11
syscall
li $v0, 1
lw $a0, -1076($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#REN, , , 
addi $sp, $sp, 1084
jr $ra
#FUNC, void, , main
main:
add $fp, $sp, 0
subi $sp, $sp, 160
#VAR, int, , n
#LI, 10, , $temp116
li $t0, 10
sw $t0, -132($fp)
#PUSH, , , $temp116
lw $t0, -132($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , factorial
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal factorial
lw $4, -20($sp)
lw $5, -24($sp)
lw $6, -28($sp)
lw $7, -32($sp)
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
#VOF, factorial, , $temp115
sw $v0, -136($fp)
#LVAR, $temp115, , n
lw $t0, -136($fp)
move $t2, $t0
#LVAR, n, , $temp117
move $t0, $t2
sw $t0, -140($fp)
#PRT, 2, 12, $temp117
li $v0, 4
la $a0, $string12
syscall
li $v0, 1
lw $a0, -140($fp)
syscall
li $v0, 4
la $a0,$enter
syscall
#LI, 5, , $temp118
li $t0, 5
sw $t0, -144($fp)
#PUSH, , , $temp118
lw $t0, -144($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#LI, 10, , $temp119
li $t0, 10
sw $t0, -148($fp)
#PUSH, , , $temp119
lw $t0, -148($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , swap
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal swap
lw $4, -24($sp)
lw $5, -28($sp)
lw $6, -32($sp)
lw $7, -36($sp)
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
#LI, 2, , $temp120
li $t0, 2
sw $t0, -152($fp)
#PUSH, , , $temp120
lw $t0, -152($fp)
sw $t0, ($sp)
subi $sp, $sp, 4
#CALL, , , complete_num
sw $4, -16($sp)
sw $5, -20($sp)
sw $6, -24($sp)
sw $7, -28($sp)
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
jal complete_num
lw $4, -20($sp)
lw $5, -24($sp)
lw $6, -28($sp)
lw $7, -32($sp)
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
