	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maskern/",100,0,0,.LBB0
	.stabs "MASELEM.mod",100,0,0,.LBB0
.LBB0:
	.stabs "BOOLEAN:t1=eTRUE:1,FALSE:0,;",0x80,0,0,0
	.stabs "CHAR:t2=r2;0;255;",0x80,0,0,0
	.stabs "SHORTCARD:t3=r3;0;65535;",0x80,0,0,0
	.stabs "LONGCARD:t4=r4;0;-1;",0x80,0,0,0
	.stabs "CARDINAL:t5=r5;0;-1;",0x80,0,0,0
	.stabs "SHORTINT:t6=r6;-32768;32767;",0x80,0,0,0
	.stabs "LONGINT:t7=r7;-2147483648;2147483647;",0x80,0,0,0
	.stabs "INTEGER:t8=r8;-2147483648;2147483647;",0x80,0,0,0
	.stabs "REAL:t9=r8;4;0;",0x80,0,0,0
	.stabs "LONGREAL:t10=r8;8;0;",0x80,0,0,0
	.stabs "BITSET:t11=r4;0;-1",0x80,0,0,0
	.stabs "WORD:t13=r13;0;255;",0x80,0,0,0
	.stabs "BYTE:t14=r2;0;255",0x80,0,0,0
	.stabs "VOID:t16=16",0x80,0,0,0
	.stabs "ADDRESS:t15=*16",0x80,0,0,0
	.stabs "PROC:t12=*f16;",0x80,0,0,0
	.globl	MASELEM
	.globl	MASELEM_MASSIGN
	.globl	MASELEM_MASREM
	.globl	MASELEM_MASQREM
	.globl	MASELEM_MASODD
	.globl	MASELEM_MASMIN
	.globl	MASELEM_MASMAX
	.globl	MASELEM_MASEXP
	.globl	MASELEM_MASEVEN
	.globl	MASELEM_MASABS
	.stabs "MASELEM_MASSIGN:F7",36,0,0,MASELEM_MASSIGN
	.align 4
MASELEM_MASSIGN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,115,.LN1-MASELEM_MASSIGN		# line 115, column 1
.LBB1:
.LN2:
	.stabn  68,0,116,.LN2-MASELEM_MASSIGN		# line 116, column 7
	cmpl	$0,8(%ebp)
	jle	.Lab4
.Lab3:
.LN3:
	.stabn  68,0,116,.LN3-MASELEM_MASSIGN		# line 116, column 22
	movl	$1,-8(%ebp) 
	jmp	.Lab2
.Lab4:
.LN4:
	.stabn  68,0,117,.LN4-MASELEM_MASSIGN		# line 117, column 10
	cmpl	$0,8(%ebp)
	jge	.Lab7
.Lab6:
.LN5:
	.stabn  68,0,117,.LN5-MASELEM_MASSIGN		# line 117, column 25
	movl	$-1,-8(%ebp) 
	jmp	.Lab5
.Lab7:
.LN6:
	.stabn  68,0,117,.LN6-MASELEM_MASSIGN		# line 117, column 37
	movl	$0,-8(%ebp) 
.Lab5:
.Lab2:
.LN7:
	.stabn  68,0,119,.LN7-MASELEM_MASSIGN		# line 119, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN8:
	.stabn  68,0,120,.LN8-MASELEM_MASSIGN		# line 120, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 8
	.stabs "s:7",128,0,4,-8
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-MASELEM_MASSIGN
	.stabn 224,0,0,.LBE1-MASELEM_MASSIGN
	.stabs "MASELEM_MASREM:F7",36,0,0,MASELEM_MASREM
	.align 4
MASELEM_MASREM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab8, %esp
.LN9:
	.stabn  68,0,107,.LN9-MASELEM_MASREM		# line 107, column 1
.LBB2:
.LN10:
	.stabn  68,0,108,.LN10-MASELEM_MASREM		# line 108, column 8
	movl	8(%ebp),%eax
	movl	12(%ebp),%ebx
	cdq
	idivl	%ebx
	movl	%eax,-8(%ebp) 
.LN11:
	.stabn  68,0,108,.LN11-MASELEM_MASREM		# line 108, column 20
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	imull	12(%ebp),%eax 
 	subl	%eax,%ebx 
	movl	%ebx,-12(%ebp) 
.LN12:
	.stabn  68,0,108,.LN12-MASELEM_MASREM		# line 108, column 29
	movl	-12(%ebp),%eax
	leave
	ret
.LN13:
	.stabn  68,0,109,.LN13-MASELEM_MASREM		# line 109, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab8 = 12
	.stabs "r:7",128,0,4,-12
	.stabs "q:7",128,0,4,-8
	.stabs "b:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-MASELEM_MASREM
	.stabn 224,0,0,.LBE2-MASELEM_MASREM
	.stabs "MASELEM_MASQREM:F16",36,0,0,MASELEM_MASQREM
	.align 4
MASELEM_MASQREM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN14:
	.stabn  68,0,98,.LN14-MASELEM_MASQREM		# line 98, column 1
.LBB3:
.LN15:
	.stabn  68,0,99,.LN15-MASELEM_MASQREM		# line 99, column 8
	movl	16(%ebp),%ecx
	movl	8(%ebp),%eax
	movl	12(%ebp),%ebx
	cdq
	idivl	%ebx
	movl	%eax,(%ecx) 
.LN16:
	.stabn  68,0,99,.LN16-MASELEM_MASQREM		# line 99, column 20
	movl	20(%ebp),%ecx
	movl	8(%ebp),%ebx
	movl	16(%ebp),%eax
	movl	(%eax),%eax
	imull	12(%ebp),%eax 
 	subl	%eax,%ebx 
	movl	%ebx,(%ecx) 
.LN17:
	.stabn  68,0,99,.LN17-MASELEM_MASQREM		# line 99, column 29
	leave
	ret
.LN18:
	.stabn  68,0,100,.LN18-MASELEM_MASQREM		# line 100, column 0
.LBE3:
	leave
	ret
	.Lab9 = 4
	.stabs "r:v7",160,0,4,20
	.stabs "q:v7",160,0,4,16
	.stabs "b:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-MASELEM_MASQREM
	.stabn 224,0,0,.LBE3-MASELEM_MASQREM
	.stabs "MASELEM_MASODD:F1",36,0,0,MASELEM_MASODD
	.align 4
MASELEM_MASODD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab10, %esp
.LN19:
	.stabn  68,0,88,.LN19-MASELEM_MASODD		# line 88, column 1
.LBB4:
.LN20:
	.stabn  68,0,89,.LN20-MASELEM_MASODD		# line 89, column 8
	movb	$0,-5(%ebp) 
.LN21:
	.stabn  68,0,90,.LN21-MASELEM_MASODD		# line 90, column 7
	movl	8(%ebp),%eax
	movl	$2,%ebx
	cdq
	idivl	%ebx
	cmpl	$0,%edx
	je	.Lab11
.Lab12:
.LN22:
	.stabn  68,0,90,.LN22-MASELEM_MASODD		# line 90, column 31
	movb	$1,-5(%ebp) 
.Lab11:
.LN23:
	.stabn  68,0,91,.LN23-MASELEM_MASODD		# line 91, column 7
	movb	-5(%ebp),%al
	leave
	ret
.LN24:
	.stabn  68,0,92,.LN24-MASELEM_MASODD		# line 92, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab10 = 8
	.stabs "t:1",128,0,1,-5
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-MASELEM_MASODD
	.stabn 224,0,0,.LBE4-MASELEM_MASODD
	.stabs "MASELEM_MASMIN:F7",36,0,0,MASELEM_MASMIN
	.align 4
MASELEM_MASMIN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab13, %esp
.LN25:
	.stabn  68,0,78,.LN25-MASELEM_MASMIN		# line 78, column 1
.LBB5:
.LN26:
	.stabn  68,0,79,.LN26-MASELEM_MASMIN		# line 79, column 7
	movl	8(%ebp),%eax
	cmpl	12(%ebp),%eax
	jg	.Lab16
.Lab15:
.LN27:
	.stabn  68,0,79,.LN27-MASELEM_MASMIN		# line 79, column 23
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab14
.Lab16:
.LN28:
	.stabn  68,0,79,.LN28-MASELEM_MASMIN		# line 79, column 34
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab14:
.LN29:
	.stabn  68,0,80,.LN29-MASELEM_MASMIN		# line 80, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN30:
	.stabn  68,0,81,.LN30-MASELEM_MASMIN		# line 81, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab13 = 8
	.stabs "c:7",128,0,4,-8
	.stabs "b:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-MASELEM_MASMIN
	.stabn 224,0,0,.LBE5-MASELEM_MASMIN
	.stabs "MASELEM_MASMAX:F7",36,0,0,MASELEM_MASMAX
	.align 4
MASELEM_MASMAX:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab17, %esp
.LN31:
	.stabn  68,0,68,.LN31-MASELEM_MASMAX		# line 68, column 1
.LBB6:
.LN32:
	.stabn  68,0,69,.LN32-MASELEM_MASMAX		# line 69, column 7
	movl	8(%ebp),%eax
	cmpl	12(%ebp),%eax
	jl	.Lab20
.Lab19:
.LN33:
	.stabn  68,0,69,.LN33-MASELEM_MASMAX		# line 69, column 23
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab18
.Lab20:
.LN34:
	.stabn  68,0,69,.LN34-MASELEM_MASMAX		# line 69, column 34
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab18:
.LN35:
	.stabn  68,0,70,.LN35-MASELEM_MASMAX		# line 70, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN36:
	.stabn  68,0,71,.LN36-MASELEM_MASMAX		# line 71, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab17 = 8
	.stabs "c:7",128,0,4,-8
	.stabs "b:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-MASELEM_MASMAX
	.stabn 224,0,0,.LBE6-MASELEM_MASMAX
	.stabs "MASELEM_MASEXP:F7",36,0,0,MASELEM_MASEXP
	.align 4
MASELEM_MASEXP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab21, %esp
.LN37:
	.stabn  68,0,57,.LN37-MASELEM_MASEXP		# line 57, column 1
.LBB7:
.LN38:
	.stabn  68,0,58,.LN38-MASELEM_MASEXP		# line 58, column 9
	movl	$1,-8(%ebp) 
.LN39:
	.stabn  68,0,59,.LN39-MASELEM_MASEXP		# line 59, column 7
	movl	12(%ebp),%eax
	movl	%eax,-16(%ebp) 
	cmpl	$1,-16(%ebp)
	jl	.Lab22
	movl	$1,-12(%ebp) 
	movl	-16(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab23:
.LN40:
	.stabn  68,0,59,.LN40-MASELEM_MASEXP		# line 59, column 27
	movl	-8(%ebp),%eax
	imull	8(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN41:
	.stabn  68,0,59,.LN41-MASELEM_MASEXP		# line 59, column 7
	movl	-12(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jge	.Lab22
	incl	-12(%ebp) 
	jmp	.Lab23
.Lab22:
.LN42:
	.stabn  68,0,60,.LN42-MASELEM_MASEXP		# line 60, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN43:
	.stabn  68,0,61,.LN43-MASELEM_MASEXP		# line 61, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab21 = 20
	.stabs "IL:7",128,0,4,-12
	.stabs "CL:7",128,0,4,-8
	.stabs "b:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-MASELEM_MASEXP
	.stabn 224,0,0,.LBE7-MASELEM_MASEXP
	.stabs "MASELEM_MASEVEN:F1",36,0,0,MASELEM_MASEVEN
	.align 4
MASELEM_MASEVEN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab24, %esp
.LN44:
	.stabn  68,0,46,.LN44-MASELEM_MASEVEN		# line 46, column 1
.LBB8:
.LN45:
	.stabn  68,0,47,.LN45-MASELEM_MASEVEN		# line 47, column 8
	movb	$1,-5(%ebp) 
.LN46:
	.stabn  68,0,48,.LN46-MASELEM_MASEVEN		# line 48, column 7
	movl	8(%ebp),%eax
	movl	$2,%ebx
	cdq
	idivl	%ebx
	cmpl	$0,%edx
	je	.Lab25
.Lab26:
.LN47:
	.stabn  68,0,48,.LN47-MASELEM_MASEVEN		# line 48, column 31
	movb	$0,-5(%ebp) 
.Lab25:
.LN48:
	.stabn  68,0,49,.LN48-MASELEM_MASEVEN		# line 49, column 7
	movb	-5(%ebp),%al
	leave
	ret
.LN49:
	.stabn  68,0,50,.LN49-MASELEM_MASEVEN		# line 50, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab24 = 8
	.stabs "t:1",128,0,1,-5
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-MASELEM_MASEVEN
	.stabn 224,0,0,.LBE8-MASELEM_MASEVEN
	.stabs "MASELEM_MASABS:F7",36,0,0,MASELEM_MASABS
	.align 4
MASELEM_MASABS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab27, %esp
.LN50:
	.stabn  68,0,36,.LN50-MASELEM_MASABS		# line 36, column 1
.LBB9:
.LN51:
	.stabn  68,0,37,.LN51-MASELEM_MASABS		# line 37, column 7
	cmpl	$0,8(%ebp)
	jl	.Lab30
.Lab29:
.LN52:
	.stabn  68,0,37,.LN52-MASELEM_MASABS		# line 37, column 23
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab28
.Lab30:
.LN53:
	.stabn  68,0,37,.LN53-MASELEM_MASABS		# line 37, column 34
	movl	8(%ebp),%eax
	negl	%eax
	movl	%eax,-8(%ebp) 
.Lab28:
.LN54:
	.stabn  68,0,38,.LN54-MASELEM_MASABS		# line 38, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN55:
	.stabn  68,0,39,.LN55-MASELEM_MASABS		# line 39, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab27 = 8
	.stabs "b:7",128,0,4,-8
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-MASELEM_MASABS
	.stabn 224,0,0,.LBE9-MASELEM_MASABS
	.stabs "MASELEM:F16",36,0,0,MASELEM
	.align 4
MASELEM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab31, %esp
.LN56:
	.stabn  68,0,123,.LN56-MASELEM		# line 123, column 1
.LBB10:
.LN57:
	.stabn  68,0,124,.LN57-MASELEM		# line 124, column 0
.LBE10:
	leave
	ret
	.Lab31 = 4
	.stabn 192,0,0,.LBB10-MASELEM
	.stabn 224,0,0,.LBE10-MASELEM
