	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/sacring/",100,0,0,.LBB0
	.stabs "SACEXT6.mod",100,0,0,.LBB0
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
	.globl	SACPFAC_MPIQHS
	.globl	SACPFAC_MPIQHL
	.globl	SACPFAC_MPIQH
	.globl	SACPFAC_MIPISE
	.globl	SACPFAC_ISFPF
	.globl	SACPFAC_IPIQH
	.globl	SACPFAC_IPGFCB
	.globl	SACPFAC_IPFAC
	.globl	SACPFAC_IPCEVP
	.globl	SACEXT5_MUPRC
	.globl	SACEXT5_IUPRC
	.globl	SACEXT5_ISPSFB
	.globl	SACEXT5_IPSFBA
	.globl	SACEXT5_IPPSC
	.globl	SACEXT5_IPLCPP
	.globl	SACEXT5_IPDSCR
	.globl	SACEXT5_IPCSFB
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
	.globl	SACEXT6
	.globl	SACEXT6_IPFSFB
	.stabs "SACEXT6_IPFSFB:F7",36,0,0,SACEXT6_IPFSFB
	.align 4
SACEXT6_IPFSFB:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,49,.LN1-SACEXT6_IPFSFB		# line 49, column 1
.LBB1:
.LN2:
	.stabn  68,0,50,.LN2-SACEXT6_IPFSFB		# line 50, column 50
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACEXT5_IPCSFB
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN3:
	.stabn  68,0,51,.LN3-SACEXT6_IPFSFB		# line 51, column 39
	movl	MASSTOR_s,%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab2
.Lab3:
.LN4:
	.stabn  68,0,52,.LN4-SACEXT6_IPFSFB		# line 52, column 26
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN5:
	.stabn  68,0,52,.LN5-SACEXT6_IPFSFB		# line 52, column 43
	pushl	-12(%ebp)
	pushl	8(%ebp)
	call	SACPFAC_ISFPF
	addl	$8, %esp
	movl	%eax,-24(%ebp) 
.LN6:
	.stabn  68,0,53,.LN6-SACEXT6_IPFSFB		# line 53, column 15
	pushl	-8(%ebp)
	pushl	-24(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN7:
	.stabn  68,0,53,.LN7-SACEXT6_IPFSFB		# line 53, column 29
	movl	-16(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab2:
.LN8:
	.stabn  68,0,52,.LN8-SACEXT6_IPFSFB		# line 52, column 16
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab3
.Lab4:
.LN9:
	.stabn  68,0,54,.LN9-SACEXT6_IPFSFB		# line 54, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN10:
	.stabn  68,0,55,.LN10-SACEXT6_IPFSFB		# line 55, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 24
	.stabs "L:7",128,0,4,-24
	.stabs "BS:7",128,0,4,-20
	.stabs "BP:7",128,0,4,-16
	.stabs "B1:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "RL:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACEXT6_IPFSFB
	.stabn 224,0,0,.LBE1-SACEXT6_IPFSFB
	.stabs "SACEXT6:F16",36,0,0,SACEXT6
	.align 4
SACEXT6:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab5, %esp
.LN11:
	.stabn  68,0,58,.LN11-SACEXT6		# line 58, column 1
.LBB2:
.LN12:
	.stabn  68,0,59,.LN12-SACEXT6		# line 59, column 0
.LBE2:
	leave
	ret
	.Lab5 = 4
	.stabn 192,0,0,.LBB2-SACEXT6
	.stabn 224,0,0,.LBE2-SACEXT6
