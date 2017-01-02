	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "MASCOMB.mod",100,0,0,.LBB0
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
	.globl	LISTTOOLS_UPCASE
	.globl	LISTTOOLS_LSRCHQ
	.globl	LISTTOOLS_LPAIRS
	.globl	LISTTOOLS_LIST6
	.globl	LISTTOOLS_CLISTFA
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
	.globl	MASCOMB
	.globl	MASCOMB_PVFLISTS
	.globl	MASCOMB_INVPERM
	.stabs "MASCOMB_PVFLISTS:F7",36,0,0,MASCOMB_PVFLISTS
	.align 4
MASCOMB_PVFLISTS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,50,.LN1-MASCOMB_PVFLISTS		# line 50, column 1
.LBB1:
.LN2:
	.stabn  68,0,51,.LN2-MASCOMB_PVFLISTS		# line 51, column 10
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab2
.Lab3:
.LN3:
	.stabn  68,0,53,.LN3-MASCOMB_PVFLISTS		# line 53, column 17
	leal	12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN4:
	.stabn  68,0,54,.LN4-MASCOMB_PVFLISTS		# line 54, column 18
	pushl	-12(%ebp)
	pushl	8(%ebp)
	pushl	-8(%ebp)
	call	LISTTOOLS_LSRCHQ
	addl	$8, %esp
	pushl	%eax
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.Lab2:
.LN5:
	.stabn  68,0,52,.LN5-MASCOMB_PVFLISTS		# line 52, column 20
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab3
.Lab4:
.LN6:
	.stabn  68,0,56,.LN6-MASCOMB_PVFLISTS		# line 56, column 9
	pushl	-12(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	leave
	ret
.LN7:
	.stabn  68,0,57,.LN7-MASCOMB_PVFLISTS		# line 57, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 12
	.stabs "P:7",128,0,4,-12
	.stabs "a:7",128,0,4,-8
	.stabs "list2:p7",160,0,4,12
	.stabs "list1:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-MASCOMB_PVFLISTS
	.stabn 224,0,0,.LBE1-MASCOMB_PVFLISTS
	.stabs "MASCOMB_INVPERM:F7",36,0,0,MASCOMB_INVPERM
	.align 4
MASCOMB_INVPERM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab5, %esp
.LN8:
	.stabn  68,0,31,.LN8-MASCOMB_INVPERM		# line 31, column 1
.LBB2:
.LN9:
	.stabn  68,0,33,.LN9-MASCOMB_INVPERM		# line 33, column 10
	pushl	8(%ebp)
	call	MASSTOR_LENGTH
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN10:
	.stabn  68,0,34,.LN10-MASCOMB_INVPERM		# line 34, column 10
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-8(%ebp) 
.LN11:
	.stabn  68,0,36,.LN11-MASCOMB_INVPERM		# line 36, column 9
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
	cmpl	$1,-24(%ebp)
	jl	.Lab6
	movl	$1,-16(%ebp) 
	movl	-24(%ebp),%eax
	movl	%eax,-28(%ebp) 
.Lab7:
.LN12:
	.stabn  68,0,36,.LN12-MASCOMB_INVPERM		# line 36, column 27
	pushl	-8(%ebp)
	pushl	$0
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN13:
	.stabn  68,0,36,.LN13-MASCOMB_INVPERM		# line 36, column 9
	movl	-16(%ebp),%eax
	cmpl	-28(%ebp),%eax
	jge	.Lab6
	incl	-16(%ebp) 
	jmp	.Lab7
.Lab6:
.LN14:
	.stabn  68,0,38,.LN14-MASCOMB_INVPERM		# line 38, column 9
	movl	-20(%ebp),%eax
	movl	%eax,-32(%ebp) 
	cmpl	$1,-32(%ebp)
	jl	.Lab8
	movl	$1,-16(%ebp) 
	movl	-32(%ebp),%eax
	movl	%eax,-36(%ebp) 
.Lab9:
.LN15:
	.stabn  68,0,39,.LN15-MASCOMB_INVPERM		# line 39, column 17
	leal	8(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN16:
	.stabn  68,0,40,.LN16-MASCOMB_INVPERM		# line 40, column 17
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	SACLIST_SLELT
	addl	$12, %esp
.LN17:
	.stabn  68,0,38,.LN17-MASCOMB_INVPERM		# line 38, column 9
	movl	-16(%ebp),%eax
	cmpl	-36(%ebp),%eax
	jge	.Lab8
	incl	-16(%ebp) 
	jmp	.Lab9
.Lab8:
.LN18:
	.stabn  68,0,42,.LN18-MASCOMB_INVPERM		# line 42, column 9
	movl	-8(%ebp),%eax
	leave
	ret
.LN19:
	.stabn  68,0,43,.LN19-MASCOMB_INVPERM		# line 43, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab5 = 36
	.stabs "n:7",128,0,4,-20
	.stabs "i:7",128,0,4,-16
	.stabs "pos:7",128,0,4,-12
	.stabs "L:7",128,0,4,-8
	.stabs "perm:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-MASCOMB_INVPERM
	.stabn 224,0,0,.LBE2-MASCOMB_INVPERM
	.stabs "MASCOMB:F16",36,0,0,MASCOMB
	.align 4
MASCOMB:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab10, %esp
.LN20:
	.stabn  68,0,59,.LN20-MASCOMB		# line 59, column 1
.LBB3:
.LN21:
	.stabn  68,0,60,.LN21-MASCOMB		# line 60, column 0
.LBE3:
	leave
	ret
	.Lab10 = 4
	.stabn 192,0,0,.LBB3-MASCOMB
	.stabn 224,0,0,.LBE3-MASCOMB
