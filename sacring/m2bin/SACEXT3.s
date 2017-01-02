	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/sacring/",100,0,0,.LBB0
	.stabs "SACEXT3.mod",100,0,0,.LBB0
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
	.globl	SACLIST_THIRD
	.globl	SACLIST_SUFFIX
	.globl	SACLIST_SLELT
	.globl	SACLIST_SECOND
	.globl	SACLIST_RED4
	.globl	SACLIST_RED3
	.globl	SACLIST_RED2
	.globl	SACLIST_REDUCT
	.globl	SACLIST_PAIR
	.globl	SACLIST_OWRITE
	.globl	SACLIST_OREAD
	.globl	SACLIST_ORDER
	.globl	SACLIST_MEMBER
	.globl	SACLIST_LWRITE
	.globl	SACLIST_LSRCH
	.globl	SACLIST_LREAD
	.globl	SACLIST_LIST5
	.globl	SACLIST_LIST4
	.globl	SACLIST_LIST3
	.globl	SACLIST_LIST2
	.globl	SACLIST_LIST10
	.globl	SACLIST_LINSRT
	.globl	SACLIST_LINS
	.globl	SACLIST_LEROT
	.globl	SACLIST_LELT
	.globl	SACLIST_LEINST
	.globl	SACLIST_LAST
	.globl	SACLIST_FOURTH
	.globl	SACLIST_FIRST4
	.globl	SACLIST_FIRST3
	.globl	SACLIST_FIRST2
	.globl	SACLIST_EXTENT
	.globl	SACLIST_EQUAL
	.globl	SACLIST_CONC
	.globl	SACLIST_COMP4
	.globl	SACLIST_COMP3
	.globl	SACLIST_COMP2
	.globl	SACLIST_CLOUT
	.globl	SACLIST_CINV
	.globl	SACLIST_CCONC
	.globl	SACLIST_AWRITE
	.globl	SACLIST_AREAD
	.globl	SACLIST_ADV4
	.globl	SACLIST_ADV3
	.globl	SACLIST_ADV2
	.globl	MASSTOR_TIME
	.globl	MASSTOR_SRED
	.globl	MASSTOR_SFIRST
	.globl	MASSTOR_RED
	.globl	MASSTOR_LISTVAR
	.globl	MASSTOR_LIST1
	.globl	MASSTOR_LENGTH
	.globl	MASSTOR_INV
	.globl	MASSTOR_NEWQUE
	.globl	MASSTOR_FIRST
	.globl	MASSTOR_ENQUE
	.globl	MASSTOR_EMPTYQUE
	.globl	MASSTOR_DEQUE
	.globl	MASSTOR_COMP
	.globl	MASSTOR_CLOCK
	.globl	MASSTOR_CELLS
	.globl	MASSTOR_ADV
	.globl	SACEXT3
	.globl	SACEXT3_PERMCY
	.globl	SACEXT3_CPLEXN
	.stabs "SACEXT3_PERMCY:F7",36,0,0,SACEXT3_PERMCY
	.align 4
SACEXT3_PERMCY:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,74,.LN1-SACEXT3_PERMCY		# line 74, column 1
.LBB1:
.LN2:
	.stabn  68,0,75,.LN2-SACEXT3_PERMCY		# line 75, column 9
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
.LN3:
	.stabn  68,0,76,.LN3-SACEXT3_PERMCY		# line 76, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab2
.Lab3:
.LN4:
	.stabn  68,0,76,.LN4-SACEXT3_PERMCY		# line 76, column 23
	movl	-16(%ebp),%eax
	leave
	ret
.Lab2:
.LN5:
	.stabn  68,0,77,.LN5-SACEXT3_PERMCY		# line 77, column 7
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
	jmp	.Lab4
.Lab5:
.LN6:
	.stabn  68,0,78,.LN6-SACEXT3_PERMCY		# line 78, column 26
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN7:
	.stabn  68,0,78,.LN7-SACEXT3_PERMCY		# line 78, column 44
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.Lab4:
.LN8:
	.stabn  68,0,78,.LN8-SACEXT3_PERMCY		# line 78, column 16
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab5
.Lab6:
.LN9:
	.stabn  68,0,79,.LN9-SACEXT3_PERMCY		# line 79, column 9
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN10:
	.stabn  68,0,79,.LN10-SACEXT3_PERMCY		# line 79, column 27
	pushl	-16(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN11:
	.stabn  68,0,79,.LN11-SACEXT3_PERMCY		# line 79, column 38
	movl	-16(%ebp),%eax
	leave
	ret
.LN12:
	.stabn  68,0,80,.LN12-SACEXT3_PERMCY		# line 80, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 20
	.stabs "PS:7",128,0,4,-20
	.stabs "PP:7",128,0,4,-16
	.stabs "PL1:7",128,0,4,-12
	.stabs "PL:7",128,0,4,-8
	.stabs "P:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACEXT3_PERMCY
	.stabn 224,0,0,.LBE1-SACEXT3_PERMCY
	.stabs "SACEXT3_CPLEXN:F16",36,0,0,SACEXT3_CPLEXN
	.align 4
SACEXT3_CPLEXN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab7, %esp
.LN13:
	.stabn  68,0,54,.LN13-SACEXT3_CPLEXN		# line 54, column 1
.LBB2:
.LN14:
	.stabn  68,0,55,.LN14-SACEXT3_CPLEXN		# line 55, column 9
	movl	$1,-24(%ebp) 
.LN15:
	.stabn  68,0,55,.LN15-SACEXT3_CPLEXN		# line 55, column 15
	movl	12(%ebp),%ebx
	movl	MASSTOR_s,%eax
	movl	%eax,(%ebx) 
.LN16:
	.stabn  68,0,55,.LN16-SACEXT3_CPLEXN		# line 55, column 25
	movl	8(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab8:
.LN17:
	.stabn  68,0,56,.LN17-SACEXT3_CPLEXN		# line 56, column 14
	leal	-16(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	SACLIST_FIRST2
	addl	$12, %esp
.LN18:
	.stabn  68,0,57,.LN18-SACEXT3_CPLEXN		# line 57, column 14
	cmpl	$1,-24(%ebp)
	jne	.Lab12
.Lab11:
.LN19:
	.stabn  68,0,57,.LN19-SACEXT3_CPLEXN		# line 57, column 29
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN20:
	.stabn  68,0,58,.LN20-SACEXT3_CPLEXN		# line 58, column 17
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab15
.Lab14:
.LN21:
	.stabn  68,0,58,.LN21-SACEXT3_CPLEXN		# line 58, column 35
	pushl	-12(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN22:
	.stabn  68,0,58,.LN22-SACEXT3_CPLEXN		# line 58, column 52
	movl	$0,-24(%ebp) 
	jmp	.Lab13
.Lab15:
.LN23:
	.stabn  68,0,59,.LN23-SACEXT3_CPLEXN		# line 59, column 20
	pushl	-16(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.Lab13:
	jmp	.Lab10
.Lab12:
.LN24:
	.stabn  68,0,60,.LN24-SACEXT3_CPLEXN		# line 60, column 23
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.Lab10:
.LN25:
	.stabn  68,0,61,.LN25-SACEXT3_CPLEXN		# line 61, column 15
	movl	12(%ebp),%eax
	pushl	%eax
	movl	12(%ebp),%eax
	pushl	(%eax)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN26:
	.stabn  68,0,61,.LN26-SACEXT3_CPLEXN		# line 61, column 30
	pushl	-20(%ebp)
	call	SACLIST_RED2
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN27:
	.stabn  68,0,62,.LN27-SACEXT3_CPLEXN		# line 62, column 24
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab8
.Lab9:
.LN28:
	.stabn  68,0,63,.LN28-SACEXT3_CPLEXN		# line 63, column 8
	movl	12(%ebp),%eax
	pushl	%eax
	movl	12(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_INV
	addl	$4, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN29:
	.stabn  68,0,64,.LN29-SACEXT3_CPLEXN		# line 64, column 7
	cmpl	$0,-24(%ebp)
	jne	.Lab18
.Lab17:
.LN30:
	.stabn  68,0,64,.LN30-SACEXT3_CPLEXN		# line 64, column 23
	movl	16(%ebp),%ebx
	movl	8(%ebp),%eax
	movl	%eax,(%ebx) 
	jmp	.Lab16
.Lab18:
.LN31:
	.stabn  68,0,64,.LN31-SACEXT3_CPLEXN		# line 64, column 34
	movl	16(%ebp),%ebx
	movl	MASSTOR_s,%eax
	movl	%eax,(%ebx) 
.Lab16:
.LN32:
	.stabn  68,0,65,.LN32-SACEXT3_CPLEXN		# line 65, column 7
	leave
	ret
.LN33:
	.stabn  68,0,66,.LN33-SACEXT3_CPLEXN		# line 66, column 0
.LBE2:
	leave
	ret
	.Lab7 = 24
	.stabs "TL:7",128,0,4,-24
	.stabs "LP:7",128,0,4,-20
	.stabs "L2:7",128,0,4,-16
	.stabs "L1:7",128,0,4,-12
	.stabs "A:7",128,0,4,-8
	.stabs "M:v7",160,0,4,16
	.stabs "I:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACEXT3_CPLEXN
	.stabn 224,0,0,.LBE2-SACEXT3_CPLEXN
	.stabs "SACEXT3:F16",36,0,0,SACEXT3
	.align 4
SACEXT3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab19, %esp
.LN34:
	.stabn  68,0,83,.LN34-SACEXT3		# line 83, column 1
.LBB3:
.LN35:
	.stabn  68,0,84,.LN35-SACEXT3		# line 84, column 0
.LBE3:
	leave
	ret
	.Lab19 = 4
	.stabn 192,0,0,.LBB3-SACEXT3
	.stabn 224,0,0,.LBE3-SACEXT3
