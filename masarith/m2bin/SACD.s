	.comm SACD_s, 288
	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "SACD.mod",100,0,0,.LBB0
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
	.globl	MASELEM_MASSIGN
	.globl	MASELEM_MASREM
	.globl	MASELEM_MASQREM
	.globl	MASELEM_MASODD
	.globl	MASELEM_MASMIN
	.globl	MASELEM_MASMAX
	.globl	MASELEM_MASEXP
	.globl	MASELEM_MASEVEN
	.globl	MASELEM_MASABS
	.globl	SACD
	.globl	SACD_DSQRTF
	.globl	SACD_DRANN
	.globl	SACD_DRAN
	.globl	SACD_DQR
	.globl	SACD_DPR
	.globl	SACD_DPCC
	.globl	SACD_DLOG2
	.globl	SACD_DGCD
	.globl	SACD_DEGCD
	.globl	SACD_BITRAN
	.globl	SACD_BEGIN2
	.stabs "SACD_DSQRTF:F16",36,0,0,SACD_DSQRTF
	.align 4
SACD_DSQRTF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,227,.LN1-SACD_DSQRTF		# line 227, column 1
.LBB1:
.LN2:
	.stabn  68,0,229,.LN2-SACD_DSQRTF		# line 229, column 7
	cmpl	$0,8(%ebp)
	jne	.Lab2
.Lab3:
.LN3:
	.stabn  68,0,229,.LN3-SACD_DSQRTF		# line 229, column 24
	movl	12(%ebp),%eax
	movl	$0,(%eax) 
.LN4:
	.stabn  68,0,229,.LN4-SACD_DSQRTF		# line 229, column 31
	movl	16(%ebp),%eax
	movl	$0,(%eax) 
.LN5:
	.stabn  68,0,229,.LN5-SACD_DSQRTF		# line 229, column 36
	leave
	ret
.Lab2:
.LN6:
	.stabn  68,0,230,.LN6-SACD_DSQRTF		# line 230, column 42
	pushl	8(%ebp)
	call	SACD_DLOG2
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN7:
	.stabn  68,0,230,.LN7-SACD_DSQRTF		# line 230, column 58
	movl	$1,%eax
 	addl	-20(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN8:
	.stabn  68,0,231,.LN8-SACD_DSQRTF		# line 231, column 9
	movl	-16(%ebp),%eax
	sarl	$1, %eax 
	movl	%eax,-12(%ebp) 
.LN9:
	.stabn  68,0,231,.LN9-SACD_DSQRTF		# line 231, column 24
	movl	12(%ebp),%ebx
	movl	$1,%eax
 	addl	-12(%ebp),%eax 
	.data
	.align 4
.Lab4:
	.long	1,64
	.text
	boundl	%eax,.Lab4
	movl	SACD_s + 16(,%eax,4),%eax
	movl	%eax,(%ebx) 
.Lab5:
.LN10:
	.stabn  68,0,233,.LN10-SACD_DSQRTF		# line 233, column 12
	leal	-24(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	movl	12(%ebp),%eax
	pushl	(%eax)
	pushl	8(%ebp)
	call	MASELEM_MASQREM
	addl	$16, %esp
.LN11:
	.stabn  68,0,234,.LN11-SACD_DSQRTF		# line 234, column 12
	movl	12(%ebp),%eax
	movl	(%eax),%eax
	cmpl	-8(%ebp),%eax
	jg	.Lab7
.Lab8:
.LN12:
	.stabn  68,0,234,.LN12-SACD_DSQRTF		# line 234, column 32
	movl	12(%ebp),%ebx
	movl	12(%ebp),%eax
	movl	(%eax),%eax
	imull	(%ebx),%eax 
	movl	%eax,-16(%ebp) 
.LN13:
	.stabn  68,0,234,.LN13-SACD_DSQRTF		# line 234, column 44
	movl	8(%ebp),%eax
 	subl	-16(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN14:
	.stabn  68,0,234,.LN14-SACD_DSQRTF		# line 234, column 56
	movl	16(%ebp),%eax
	pushl	%eax
	pushl	-16(%ebp)
	call	MASELEM_MASSIGN
	addl	$4, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN15:
	.stabn  68,0,235,.LN15-SACD_DSQRTF		# line 235, column 15
	leave
	ret
.Lab7:
.LN16:
	.stabn  68,0,236,.LN16-SACD_DSQRTF		# line 236, column 15
	movl	12(%ebp),%ebx
	movl	-8(%ebp),%eax
 	addl	(%ebx),%eax 
	movl	%eax,-16(%ebp) 
.LN17:
	.stabn  68,0,236,.LN17-SACD_DSQRTF		# line 236, column 26
	movl	12(%ebp),%ebx
	movl	-16(%ebp),%eax
	sarl	$1, %eax 
	movl	%eax,(%ebx) 
	jmp	.Lab5
.Lab6:
.LN18:
	.stabn  68,0,238,.LN18-SACD_DSQRTF		# line 238, column 7
	leave
	ret
.LN19:
	.stabn  68,0,239,.LN19-SACD_DSQRTF		# line 239, column 0
.LBE1:
	leave
	ret
	.Lab1 = 24
	.stabs "RL:7",128,0,4,-24
	.stabs "KL:7",128,0,4,-20
	.stabs "J1Y:7",128,0,4,-16
	.stabs "HL:7",128,0,4,-12
	.stabs "CL:7",128,0,4,-8
	.stabs "TL:v7",160,0,4,16
	.stabs "BL:v7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACD_DSQRTF
	.stabn 224,0,0,.LBE1-SACD_DSQRTF
	.stabs "SACD_DRANN:F7",36,0,0,SACD_DRANN
	.align 4
SACD_DRANN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN20:
	.stabn  68,0,215,.LN20-SACD_DRANN		# line 215, column 1
.LBB2:
.LN21:
	.stabn  68,0,216,.LN21-SACD_DRANN		# line 216, column 7
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	SACD_s + 280
	pushl	SACD_s + 284
	call	SACD_DPR
	addl	$16, %esp
.LN22:
	.stabn  68,0,216,.LN22-SACD_DRANN		# line 216, column 33
	movl	SACD_s + 276,%eax
 	addl	-8(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN23:
	.stabn  68,0,217,.LN23-SACD_DRANN		# line 217, column 7
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab10
.Lab11:
.LN24:
	.stabn  68,0,217,.LN24-SACD_DRANN		# line 217, column 28
	movl	-8(%ebp),%eax
 	subl	MASSTOR_s,%eax 
	movl	%eax,-8(%ebp) 
.Lab10:
.LN25:
	.stabn  68,0,218,.LN25-SACD_DRANN		# line 218, column 12
	movl	-8(%ebp),%eax
	movl	%eax,SACD_s + 284 
.LN26:
	.stabn  68,0,218,.LN26-SACD_DRANN		# line 218, column 18
	movl	-8(%ebp),%eax
	leave
	ret
.LN27:
	.stabn  68,0,219,.LN27-SACD_DRANN		# line 219, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab9 = 12
	.stabs "TL:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabn 192,0,0,.LBB2-SACD_DRANN
	.stabn 224,0,0,.LBE2-SACD_DRANN
	.stabs "SACD_DRAN:F7",36,0,0,SACD_DRAN
	.align 4
SACD_DRAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab12, %esp
.LN28:
	.stabn  68,0,201,.LN28-SACD_DRAN		# line 201, column 1
.LBB3:
.LN29:
	.stabn  68,0,202,.LN29-SACD_DRAN		# line 202, column 10
	call	SACD_DRANN
	movl	%eax,-12(%ebp) 
.LN30:
	.stabn  68,0,202,.LN30-SACD_DRAN		# line 202, column 23
	movl	$0,-28(%ebp) 
.LN31:
	.stabn  68,0,202,.LN31-SACD_DRAN		# line 202, column 31
	shll	$1, -12(%ebp)
.LN32:
	.stabn  68,0,203,.LN32-SACD_DRAN		# line 203, column 7
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab13
.Lab14:
.LN33:
	.stabn  68,0,203,.LN33-SACD_DRAN		# line 203, column 29
	movl	$1,-28(%ebp) 
.LN34:
	.stabn  68,0,203,.LN34-SACD_DRAN		# line 203, column 37
	movl	-12(%ebp),%eax
 	subl	MASSTOR_s,%eax 
	movl	%eax,-12(%ebp) 
.Lab13:
.LN35:
	.stabn  68,0,204,.LN35-SACD_DRAN		# line 204, column 10
	movl	-12(%ebp),%eax
	movl	SACD_s + 8,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-12(%ebp) 
.LN36:
	.stabn  68,0,204,.LN36-SACD_DRAN		# line 204, column 30
	call	SACD_DRANN
	movl	%eax,-16(%ebp) 
.LN37:
	.stabn  68,0,204,.LN37-SACD_DRAN		# line 204, column 44
	movl	-16(%ebp),%eax
	movl	SACD_s + 16,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-16(%ebp) 
.LN38:
	.stabn  68,0,204,.LN38-SACD_DRAN		# line 204, column 64
	movl	SACD_s + 8,%eax
	imull	-12(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN39:
	.stabn  68,0,205,.LN39-SACD_DRAN		# line 205, column 9
	movl	-16(%ebp),%eax
 	addl	-24(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN40:
	.stabn  68,0,206,.LN40-SACD_DRAN		# line 206, column 7
	cmpl	$1,-28(%ebp)
	jne	.Lab15
.Lab16:
.LN41:
	.stabn  68,0,206,.LN41-SACD_DRAN		# line 206, column 24
	movl	-8(%ebp),%eax
	negl	%eax
	movl	%eax,-8(%ebp) 
.Lab15:
.LN42:
	.stabn  68,0,207,.LN42-SACD_DRAN		# line 207, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN43:
	.stabn  68,0,208,.LN43-SACD_DRAN		# line 208, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab12 = 28
	.stabs "SL:7",128,0,4,-28
	.stabs "J1Y:7",128,0,4,-24
	.stabs "IDUM:7",128,0,4,-20
	.stabs "AL2:7",128,0,4,-16
	.stabs "AL1:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabn 192,0,0,.LBB3-SACD_DRAN
	.stabn 224,0,0,.LBE3-SACD_DRAN
	.stabs "SACD_DQR:F16",36,0,0,SACD_DQR
	.align 4
SACD_DQR:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab17, %esp
.LN44:
	.stabn  68,0,179,.LN44-SACD_DQR		# line 179, column 1
.LBB4:
.LN45:
	.stabn  68,0,181,.LN45-SACD_DQR		# line 181, column 7
	cmpl	$0,8(%ebp)
	jne	.Lab18
.Lab19:
.LN46:
	.stabn  68,0,181,.LN46-SACD_DQR		# line 181, column 23
	pushl	24(%ebp)
	pushl	20(%ebp)
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	MASELEM_MASQREM
	addl	$16, %esp
.LN47:
	.stabn  68,0,181,.LN47-SACD_DQR		# line 181, column 46
	leave
	ret
.Lab18:
.LN48:
	.stabn  68,0,182,.LN48-SACD_DQR		# line 182, column 40
	pushl	8(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN49:
	.stabn  68,0,182,.LN49-SACD_DQR		# line 182, column 59
	pushl	12(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN50:
	.stabn  68,0,183,.LN50-SACD_DQR		# line 183, column 10
	pushl	16(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN51:
	.stabn  68,0,184,.LN51-SACD_DQR		# line 184, column 34
	movl	$0,-20(%ebp) 
.LN52:
	.stabn  68,0,185,.LN52-SACD_DQR		# line 185, column 7
	movl	SACD_s + 4,%eax
	movl	%eax,-28(%ebp) 
	cmpl	$1,-28(%ebp)
	jl	.Lab20
	movl	$1,-24(%ebp) 
	movl	-28(%ebp),%eax
	movl	%eax,-32(%ebp) 
.Lab21:
.LN53:
	.stabn  68,0,185,.LN53-SACD_DQR		# line 185, column 41
	shll	$1, -12(%ebp)
.LN54:
	.stabn  68,0,185,.LN54-SACD_DQR		# line 185, column 58
	shll	$1, -8(%ebp)
.LN55:
	.stabn  68,0,186,.LN55-SACD_DQR		# line 186, column 11
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab22
.Lab23:
.LN56:
	.stabn  68,0,186,.LN56-SACD_DQR		# line 186, column 36
	movl	-8(%ebp),%eax
 	subl	MASSTOR_s,%eax 
	movl	%eax,-8(%ebp) 
.LN57:
	.stabn  68,0,186,.LN57-SACD_DQR		# line 186, column 53
	incl	-12(%ebp)
.Lab22:
.LN58:
	.stabn  68,0,187,.LN58-SACD_DQR		# line 187, column 14
	shll	$1, -20(%ebp)
.LN59:
	.stabn  68,0,188,.LN59-SACD_DQR		# line 188, column 11
	movl	-12(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jl	.Lab24
.Lab25:
.LN60:
	.stabn  68,0,188,.LN60-SACD_DQR		# line 188, column 35
	movl	-12(%ebp),%eax
 	subl	-16(%ebp),%eax 
	movl	%eax,-12(%ebp) 
.LN61:
	.stabn  68,0,188,.LN61-SACD_DQR		# line 188, column 50
	incl	-20(%ebp)
.Lab24:
.LN62:
	.stabn  68,0,185,.LN62-SACD_DQR		# line 185, column 7
	movl	-24(%ebp),%eax
	cmpl	-32(%ebp),%eax
	jge	.Lab20
	incl	-24(%ebp) 
	jmp	.Lab21
.Lab20:
.LN63:
	.stabn  68,0,191,.LN63-SACD_DQR		# line 191, column 7
	cmpl	$0,8(%ebp)
	jge	.Lab26
.Lab27:
.LN64:
	.stabn  68,0,191,.LN64-SACD_DQR		# line 191, column 26
	movl	-20(%ebp),%eax
	negl	%eax
	movl	%eax,-20(%ebp) 
.LN65:
	.stabn  68,0,191,.LN65-SACD_DQR		# line 191, column 38
	movl	-12(%ebp),%eax
	negl	%eax
	movl	%eax,-12(%ebp) 
.Lab26:
.LN66:
	.stabn  68,0,192,.LN66-SACD_DQR		# line 192, column 7
	cmpl	$0,16(%ebp)
	jge	.Lab28
.Lab29:
.LN67:
	.stabn  68,0,192,.LN67-SACD_DQR		# line 192, column 25
	movl	-20(%ebp),%eax
	negl	%eax
	movl	%eax,-20(%ebp) 
.Lab28:
.LN68:
	.stabn  68,0,193,.LN68-SACD_DQR		# line 193, column 9
	movl	20(%ebp),%ebx
	movl	-20(%ebp),%eax
	movl	%eax,(%ebx) 
.LN69:
	.stabn  68,0,193,.LN69-SACD_DQR		# line 193, column 18
	movl	24(%ebp),%ebx
	movl	-12(%ebp),%eax
	movl	%eax,(%ebx) 
.LN70:
	.stabn  68,0,194,.LN70-SACD_DQR		# line 194, column 7
	leave
	ret
.LN71:
	.stabn  68,0,195,.LN71-SACD_DQR		# line 195, column 0
.LBE4:
	leave
	ret
	.Lab17 = 32
	.stabs "IL:7",128,0,4,-24
	.stabs "QLP:7",128,0,4,-20
	.stabs "BLP:7",128,0,4,-16
	.stabs "ALP1:7",128,0,4,-12
	.stabs "ALP0:7",128,0,4,-8
	.stabs "RL:v7",160,0,4,24
	.stabs "QL:v7",160,0,4,20
	.stabs "BL:p7",160,0,4,16
	.stabs "AL0:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACD_DQR
	.stabn 224,0,0,.LBE4-SACD_DQR
	.stabs "SACD_DPR:F16",36,0,0,SACD_DPR
	.align 4
SACD_DPR:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab30, %esp
.LN72:
	.stabn  68,0,151,.LN72-SACD_DPR		# line 151, column 1
.LBB5:
.LN73:
	.stabn  68,0,152,.LN73-SACD_DPR		# line 152, column 10
	movl	8(%ebp),%eax
	movl	SACD_s + 16,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-12(%ebp) 
.LN74:
	.stabn  68,0,152,.LN74-SACD_DPR		# line 152, column 29
	movl	SACD_s + 16,%eax
	imull	-12(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN75:
	.stabn  68,0,152,.LN75-SACD_DPR		# line 152, column 45
	movl	8(%ebp),%eax
 	subl	-60(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN76:
	.stabn  68,0,152,.LN76-SACD_DPR		# line 152, column 58
	movl	12(%ebp),%eax
	movl	SACD_s + 16,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-20(%ebp) 
.LN77:
	.stabn  68,0,153,.LN77-SACD_DPR		# line 153, column 10
	movl	SACD_s + 16,%eax
	imull	-20(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN78:
	.stabn  68,0,153,.LN78-SACD_DPR		# line 153, column 26
	movl	12(%ebp),%eax
 	subl	-60(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN79:
	.stabn  68,0,154,.LN79-SACD_DPR		# line 154, column 10
	movl	-16(%ebp),%eax
	imull	-8(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN80:
	.stabn  68,0,154,.LN80-SACD_DPR		# line 154, column 24
	movl	-16(%ebp),%eax
	imull	-12(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN81:
	.stabn  68,0,154,.LN81-SACD_DPR		# line 154, column 38
	movl	-20(%ebp),%eax
	imull	-8(%ebp),%eax 
	movl	%eax,-64(%ebp) 
.LN82:
	.stabn  68,0,154,.LN82-SACD_DPR		# line 154, column 52
	movl	-64(%ebp),%eax
 	addl	-60(%ebp),%eax 
	movl	%eax,-36(%ebp) 
.LN83:
	.stabn  68,0,155,.LN83-SACD_DPR		# line 155, column 10
	movl	-20(%ebp),%eax
	imull	-12(%ebp),%eax 
	movl	%eax,-48(%ebp) 
.LN84:
	.stabn  68,0,156,.LN84-SACD_DPR		# line 156, column 7
	movl	-24(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab33
.Lab32:
.LN85:
	.stabn  68,0,156,.LN85-SACD_DPR		# line 156, column 31
	movl	$1,-32(%ebp) 
.LN86:
	.stabn  68,0,156,.LN86-SACD_DPR		# line 156, column 40
	movl	-24(%ebp),%eax
 	subl	MASSTOR_s,%eax 
	movl	%eax,-28(%ebp) 
	jmp	.Lab31
.Lab33:
.LN87:
	.stabn  68,0,157,.LN87-SACD_DPR		# line 157, column 10
	movl	MASSTOR_s,%eax
	negl	%eax
	cmpl	%eax,-24(%ebp)
	jg	.Lab36
.Lab35:
.LN88:
	.stabn  68,0,157,.LN88-SACD_DPR		# line 157, column 35
	movl	$-1,-32(%ebp) 
.LN89:
	.stabn  68,0,157,.LN89-SACD_DPR		# line 157, column 45
	movl	MASSTOR_s,%eax
 	addl	-24(%ebp),%eax 
	movl	%eax,-28(%ebp) 
	jmp	.Lab34
.Lab36:
.LN90:
	.stabn  68,0,157,.LN90-SACD_DPR		# line 157, column 66
	movl	$0,-32(%ebp) 
.LN91:
	.stabn  68,0,158,.LN91-SACD_DPR		# line 158, column 17
	movl	-24(%ebp),%eax
	movl	%eax,-28(%ebp) 
.Lab34:
.Lab31:
.LN92:
	.stabn  68,0,160,.LN92-SACD_DPR		# line 160, column 11
	movl	-36(%ebp),%eax
	movl	SACD_s + 8,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-44(%ebp) 
.LN93:
	.stabn  68,0,160,.LN93-SACD_DPR		# line 160, column 31
	movl	SACD_s + 8,%eax
	imull	-44(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN94:
	.stabn  68,0,160,.LN94-SACD_DPR		# line 160, column 49
	movl	-36(%ebp),%eax
 	subl	-60(%ebp),%eax 
	movl	%eax,-40(%ebp) 
.LN95:
	.stabn  68,0,161,.LN95-SACD_DPR		# line 161, column 10
	movl	-32(%ebp),%eax
 	addl	-48(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN96:
	.stabn  68,0,161,.LN96-SACD_DPR		# line 161, column 25
	movl	-44(%ebp),%eax
 	addl	-60(%ebp),%eax 
	movl	%eax,-52(%ebp) 
.LN97:
	.stabn  68,0,162,.LN97-SACD_DPR		# line 162, column 7
	movl	SACD_s + 8,%eax
	cmpl	SACD_s + 16,%eax
	je	.Lab37
.Lab38:
.LN98:
	.stabn  68,0,162,.LN98-SACD_DPR		# line 162, column 33
	movl	-48(%ebp),%eax
 	addl	-52(%ebp),%eax 
	movl	%eax,-52(%ebp) 
.Lab37:
.LN99:
	.stabn  68,0,163,.LN99-SACD_DPR		# line 163, column 10
	movl	SACD_s + 16,%eax
	imull	-40(%ebp),%eax 
	movl	%eax,-60(%ebp) 
.LN100:
	.stabn  68,0,163,.LN100-SACD_DPR		# line 163, column 27
	movl	-28(%ebp),%eax
 	addl	-60(%ebp),%eax 
	movl	%eax,-56(%ebp) 
.LN101:
	.stabn  68,0,164,.LN101-SACD_DPR		# line 164, column 7
	movl	-56(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab41
.Lab40:
.LN102:
	.stabn  68,0,164,.LN102-SACD_DPR		# line 164, column 29
	movl	16(%ebp),%ebx
	movl	$1,%eax
 	addl	-52(%ebp),%eax 
	movl	%eax,(%ebx) 
.LN103:
	.stabn  68,0,164,.LN103-SACD_DPR		# line 164, column 40
	movl	20(%ebp),%ebx
	movl	-56(%ebp),%eax
 	subl	MASSTOR_s,%eax 
	movl	%eax,(%ebx) 
	jmp	.Lab39
.Lab41:
.LN104:
	.stabn  68,0,165,.LN104-SACD_DPR		# line 165, column 10
	movl	MASSTOR_s,%eax
	negl	%eax
	cmpl	%eax,-56(%ebp)
	jg	.Lab44
.Lab43:
.LN105:
	.stabn  68,0,165,.LN105-SACD_DPR		# line 165, column 33
	movl	16(%ebp),%ebx
	movl	-52(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,(%ebx) 
.LN106:
	.stabn  68,0,165,.LN106-SACD_DPR		# line 165, column 44
	movl	20(%ebp),%ebx
	movl	MASSTOR_s,%eax
 	addl	-56(%ebp),%eax 
	movl	%eax,(%ebx) 
	jmp	.Lab42
.Lab44:
.LN107:
	.stabn  68,0,165,.LN107-SACD_DPR		# line 165, column 63
	movl	16(%ebp),%ebx
	movl	-52(%ebp),%eax
	movl	%eax,(%ebx) 
.LN108:
	.stabn  68,0,166,.LN108-SACD_DPR		# line 166, column 15
	movl	20(%ebp),%ebx
	movl	-56(%ebp),%eax
	movl	%eax,(%ebx) 
.Lab42:
.Lab39:
.LN109:
	.stabn  68,0,168,.LN109-SACD_DPR		# line 168, column 7
	leave
	ret
.LN110:
	.stabn  68,0,169,.LN110-SACD_DPR		# line 169, column 0
.LBE5:
	leave
	ret
	.Lab30 = 64
	.stabs "J2Y:7",128,0,4,-64
	.stabs "J1Y:7",128,0,4,-60
	.stabs "DLP:7",128,0,4,-56
	.stabs "CLP:7",128,0,4,-52
	.stabs "CL2:7",128,0,4,-48
	.stabs "CL11:7",128,0,4,-44
	.stabs "CL10:7",128,0,4,-40
	.stabs "CL1:7",128,0,4,-36
	.stabs "CL01:7",128,0,4,-32
	.stabs "CL00:7",128,0,4,-28
	.stabs "CL0:7",128,0,4,-24
	.stabs "BL1:7",128,0,4,-20
	.stabs "BL0:7",128,0,4,-16
	.stabs "AL1:7",128,0,4,-12
	.stabs "AL0:7",128,0,4,-8
	.stabs "DL:v7",160,0,4,20
	.stabs "CL:v7",160,0,4,16
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-SACD_DPR
	.stabn 224,0,0,.LBE5-SACD_DPR
	.stabs "SACD_DPCC:F16",36,0,0,SACD_DPCC
	.align 4
SACD_DPCC:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab45, %esp
.LN111:
	.stabn  68,0,135,.LN111-SACD_DPCC		# line 135, column 1
.LBB6:
.LN112:
	.stabn  68,0,136,.LN112-SACD_DPCC		# line 136, column 9
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN113:
	.stabn  68,0,136,.LN113-SACD_DPCC		# line 136, column 19
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN114:
	.stabn  68,0,136,.LN114-SACD_DPCC		# line 136, column 28
	movl	16(%ebp),%eax
	movl	$1,(%eax) 
.LN115:
	.stabn  68,0,136,.LN115-SACD_DPCC		# line 136, column 36
	movl	20(%ebp),%eax
	movl	$0,(%eax) 
.LN116:
	.stabn  68,0,136,.LN116-SACD_DPCC		# line 136, column 43
	movl	24(%ebp),%eax
	movl	$0,(%eax) 
.LN117:
	.stabn  68,0,136,.LN117-SACD_DPCC		# line 136, column 51
	movl	28(%ebp),%eax
	movl	$1,(%eax) 
.Lab46:
.LN118:
	.stabn  68,0,137,.LN118-SACD_DPCC		# line 137, column 16
	movl	-8(%ebp),%eax
	movl	-12(%ebp),%ebx
	cdq
	idivl	%ebx
	movl	%eax,-24(%ebp) 
.LN119:
	.stabn  68,0,137,.LN119-SACD_DPCC		# line 137, column 33
	movl	-12(%ebp),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.LN120:
	.stabn  68,0,137,.LN120-SACD_DPCC		# line 137, column 47
	movl	-8(%ebp),%eax
 	subl	-20(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN121:
	.stabn  68,0,137,.LN121-SACD_DPCC		# line 137, column 60
	movl	20(%ebp),%eax
	movl	(%eax),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.LN122:
	.stabn  68,0,138,.LN122-SACD_DPCC		# line 138, column 18
	movl	16(%ebp),%eax
	movl	(%eax),%eax
 	subl	-20(%ebp),%eax 
	movl	%eax,-28(%ebp) 
.LN123:
	.stabn  68,0,138,.LN123-SACD_DPCC		# line 138, column 31
	movl	28(%ebp),%eax
	movl	(%eax),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.LN124:
	.stabn  68,0,138,.LN124-SACD_DPCC		# line 138, column 45
	movl	24(%ebp),%eax
	movl	(%eax),%eax
 	subl	-20(%ebp),%eax 
	movl	%eax,-32(%ebp) 
.LN125:
	.stabn  68,0,139,.LN125-SACD_DPCC		# line 139, column 14
	pushl	-32(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	cmpl	%eax,-16(%ebp)
	jl	.Lab49
.Lab50:
	movl	-12(%ebp),%eax
 	subl	-16(%ebp),%eax 
	pushl	%eax
	movl	28(%ebp),%eax
	movl	(%eax),%eax
 	subl	-32(%ebp),%eax 
	pushl	%eax
	call	MASELEM_MASABS
	addl	$4, %esp
	popl	%ebx
	cmpl	%eax,%ebx
	jge	.Lab48
.Lab49:
.LN126:
	.stabn  68,0,140,.LN126-SACD_DPCC		# line 140, column 22
	leave
	ret
.Lab48:
.LN127:
	.stabn  68,0,141,.LN127-SACD_DPCC		# line 141, column 16
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN128:
	.stabn  68,0,141,.LN128-SACD_DPCC		# line 141, column 26
	movl	-16(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN129:
	.stabn  68,0,141,.LN129-SACD_DPCC		# line 141, column 36
	movl	16(%ebp),%ebx
	movl	20(%ebp),%eax
	movl	(%eax),%eax
	movl	%eax,(%ebx) 
.LN130:
	.stabn  68,0,141,.LN130-SACD_DPCC		# line 141, column 46
	movl	20(%ebp),%ebx
	movl	-28(%ebp),%eax
	movl	%eax,(%ebx) 
.LN131:
	.stabn  68,0,141,.LN131-SACD_DPCC		# line 141, column 56
	movl	24(%ebp),%ebx
	movl	28(%ebp),%eax
	movl	(%eax),%eax
	movl	%eax,(%ebx) 
.LN132:
	.stabn  68,0,141,.LN132-SACD_DPCC		# line 141, column 66
	movl	28(%ebp),%ebx
	movl	-32(%ebp),%eax
	movl	%eax,(%ebx) 
	jmp	.Lab46
.Lab47:
.LN133:
	.stabn  68,0,143,.LN133-SACD_DPCC		# line 143, column 7
	leave
	ret
.LN134:
	.stabn  68,0,144,.LN134-SACD_DPCC		# line 144, column 0
.LBE6:
	leave
	ret
	.Lab45 = 32
	.stabs "VLPP:7",128,0,4,-32
	.stabs "ULPP:7",128,0,4,-28
	.stabs "QL:7",128,0,4,-24
	.stabs "J1Y:7",128,0,4,-20
	.stabs "ALPP:7",128,0,4,-16
	.stabs "ALP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "VLP:v7",160,0,4,28
	.stabs "VL:v7",160,0,4,24
	.stabs "ULP:v7",160,0,4,20
	.stabs "UL:v7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-SACD_DPCC
	.stabn 224,0,0,.LBE6-SACD_DPCC
	.stabs "SACD_DLOG2:F7",36,0,0,SACD_DLOG2
	.align 4
SACD_DLOG2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab51, %esp
.LN135:
	.stabn  68,0,117,.LN135-SACD_DLOG2		# line 117, column 1
.LBB7:
.LN136:
	.stabn  68,0,119,.LN136-SACD_DLOG2		# line 119, column 7
	cmpl	$0,8(%ebp)
	jne	.Lab52
.Lab53:
.LN137:
	.stabn  68,0,119,.LN137-SACD_DLOG2		# line 119, column 24
	movl	$0,-24(%ebp) 
.LN138:
	.stabn  68,0,119,.LN138-SACD_DLOG2		# line 119, column 29
	movl	-24(%ebp),%eax
	leave
	ret
.Lab52:
.LN139:
	.stabn  68,0,120,.LN139-SACD_DLOG2		# line 120, column 10
	pushl	8(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN140:
	.stabn  68,0,121,.LN140-SACD_DLOG2		# line 121, column 28
	movl	$1,-12(%ebp) 
.LN141:
	.stabn  68,0,121,.LN141-SACD_DLOG2		# line 121, column 35
	movl	$1,%eax
 	addl	SACD_s + 4,%eax 
	movl	%eax,-20(%ebp) 
.Lab54:
.LN142:
	.stabn  68,0,122,.LN142-SACD_DLOG2		# line 122, column 17
	movl	-20(%ebp),%eax
 	addl	-12(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN143:
	.stabn  68,0,122,.LN143-SACD_DLOG2		# line 122, column 28
	movl	-16(%ebp),%eax
	sarl	$1, %eax 
	movl	%eax,-24(%ebp) 
.LN144:
	.stabn  68,0,123,.LN144-SACD_DLOG2		# line 123, column 14
	movl	-8(%ebp),%ebx
	movl	-24(%ebp),%eax
	.data
	.align 4
.Lab59:
	.long	1,64
	.text
	boundl	%eax,.Lab59
	cmpl	SACD_s + 16(,%eax,4),%ebx
	jl	.Lab58
.Lab57:
.LN145:
	.stabn  68,0,123,.LN145-SACD_DLOG2		# line 123, column 50
	movl	-24(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab56
.Lab58:
.LN146:
	.stabn  68,0,123,.LN146-SACD_DLOG2		# line 123, column 63
	movl	-24(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab56:
.LN147:
	.stabn  68,0,124,.LN147-SACD_DLOG2		# line 124, column 26
	movl	-20(%ebp),%eax
 	subl	-12(%ebp),%eax 
	cmpl	$1,%eax
	jne	.Lab54
.Lab55:
.LN148:
	.stabn  68,0,125,.LN148-SACD_DLOG2		# line 125, column 9
	movl	-12(%ebp),%eax
	movl	%eax,-24(%ebp) 
.LN149:
	.stabn  68,0,125,.LN149-SACD_DLOG2		# line 125, column 15
	movl	-24(%ebp),%eax
	leave
	ret
.LN150:
	.stabn  68,0,126,.LN150-SACD_DLOG2		# line 126, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab51 = 24
	.stabs "NL:7",128,0,4,-24
	.stabs "JL:7",128,0,4,-20
	.stabs "J1Y:7",128,0,4,-16
	.stabs "IL:7",128,0,4,-12
	.stabs "ALB:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-SACD_DLOG2
	.stabn 224,0,0,.LBE7-SACD_DLOG2
	.stabs "SACD_DGCD:F7",36,0,0,SACD_DGCD
	.align 4
SACD_DGCD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab60, %esp
.LN151:
	.stabn  68,0,106,.LN151-SACD_DGCD		# line 106, column 1
.LBB8:
.LN152:
	.stabn  68,0,107,.LN152-SACD_DGCD		# line 107, column 10
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN153:
	.stabn  68,0,107,.LN153-SACD_DGCD		# line 107, column 19
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab61
.Lab62:
.LN154:
	.stabn  68,0,108,.LN154-SACD_DGCD		# line 108, column 28
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	MASELEM_MASREM
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN155:
	.stabn  68,0,108,.LN155-SACD_DGCD		# line 108, column 50
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN156:
	.stabn  68,0,108,.LN156-SACD_DGCD		# line 108, column 60
	movl	-16(%ebp),%eax
	movl	%eax,-12(%ebp) 
.Lab61:
.LN157:
	.stabn  68,0,108,.LN157-SACD_DGCD		# line 108, column 17
	cmpl	$0,-12(%ebp)
	jne	.Lab62
.Lab63:
.LN158:
	.stabn  68,0,109,.LN158-SACD_DGCD		# line 109, column 9
	movl	-8(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN159:
	.stabn  68,0,109,.LN159-SACD_DGCD		# line 109, column 16
	movl	-20(%ebp),%eax
	leave
	ret
.LN160:
	.stabn  68,0,110,.LN160-SACD_DGCD		# line 110, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab60 = 20
	.stabs "CL:7",128,0,4,-20
	.stabs "AL3:7",128,0,4,-16
	.stabs "AL2:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-SACD_DGCD
	.stabn 224,0,0,.LBE8-SACD_DGCD
	.stabs "SACD_DEGCD:F16",36,0,0,SACD_DEGCD
	.align 4
SACD_DEGCD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab64, %esp
.LN161:
	.stabn  68,0,93,.LN161-SACD_DEGCD		# line 93, column 1
.LBB9:
.LN162:
	.stabn  68,0,94,.LN162-SACD_DEGCD		# line 94, column 10
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN163:
	.stabn  68,0,94,.LN163-SACD_DEGCD		# line 94, column 19
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN164:
	.stabn  68,0,94,.LN164-SACD_DEGCD		# line 94, column 28
	movl	$1,-28(%ebp) 
.LN165:
	.stabn  68,0,94,.LN165-SACD_DEGCD		# line 94, column 36
	movl	$0,-32(%ebp) 
.LN166:
	.stabn  68,0,94,.LN166-SACD_DEGCD		# line 94, column 44
	movl	$0,-40(%ebp) 
.LN167:
	.stabn  68,0,94,.LN167-SACD_DEGCD		# line 94, column 52
	movl	$1,-44(%ebp) 
	jmp	.Lab65
.Lab66:
.LN168:
	.stabn  68,0,95,.LN168-SACD_DEGCD		# line 95, column 25
	leal	-16(%ebp),%eax
	pushl	%eax
	leal	-24(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	MASELEM_MASQREM
	addl	$16, %esp
.LN169:
	.stabn  68,0,95,.LN169-SACD_DEGCD		# line 95, column 53
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN170:
	.stabn  68,0,95,.LN170-SACD_DEGCD		# line 95, column 63
	movl	-16(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN171:
	.stabn  68,0,96,.LN171-SACD_DEGCD		# line 96, column 16
	movl	-32(%ebp),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.LN172:
	.stabn  68,0,96,.LN172-SACD_DEGCD		# line 96, column 29
	movl	-28(%ebp),%eax
 	subl	-20(%ebp),%eax 
	movl	%eax,-36(%ebp) 
.LN173:
	.stabn  68,0,96,.LN173-SACD_DEGCD		# line 96, column 43
	movl	-32(%ebp),%eax
	movl	%eax,-28(%ebp) 
.LN174:
	.stabn  68,0,96,.LN174-SACD_DEGCD		# line 96, column 53
	movl	-36(%ebp),%eax
	movl	%eax,-32(%ebp) 
.LN175:
	.stabn  68,0,96,.LN175-SACD_DEGCD		# line 96, column 63
	movl	-44(%ebp),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.LN176:
	.stabn  68,0,97,.LN176-SACD_DEGCD		# line 97, column 16
	movl	-40(%ebp),%eax
 	subl	-20(%ebp),%eax 
	movl	%eax,-48(%ebp) 
.LN177:
	.stabn  68,0,97,.LN177-SACD_DEGCD		# line 97, column 30
	movl	-44(%ebp),%eax
	movl	%eax,-40(%ebp) 
.LN178:
	.stabn  68,0,97,.LN178-SACD_DEGCD		# line 97, column 40
	movl	-48(%ebp),%eax
	movl	%eax,-44(%ebp) 
.Lab65:
.LN179:
	.stabn  68,0,95,.LN179-SACD_DEGCD		# line 95, column 17
	cmpl	$0,-12(%ebp)
	jne	.Lab66
.Lab67:
.LN180:
	.stabn  68,0,98,.LN180-SACD_DEGCD		# line 98, column 9
	movl	16(%ebp),%ebx
	movl	-8(%ebp),%eax
	movl	%eax,(%ebx) 
.LN181:
	.stabn  68,0,98,.LN181-SACD_DEGCD		# line 98, column 18
	movl	20(%ebp),%ebx
	movl	-28(%ebp),%eax
	movl	%eax,(%ebx) 
.LN182:
	.stabn  68,0,98,.LN182-SACD_DEGCD		# line 98, column 27
	movl	24(%ebp),%ebx
	movl	-40(%ebp),%eax
	movl	%eax,(%ebx) 
.LN183:
	.stabn  68,0,98,.LN183-SACD_DEGCD		# line 98, column 34
	leave
	ret
.LN184:
	.stabn  68,0,99,.LN184-SACD_DEGCD		# line 99, column 0
.LBE9:
	leave
	ret
	.Lab64 = 48
	.stabs "VL3:7",128,0,4,-48
	.stabs "VL2:7",128,0,4,-44
	.stabs "VL1:7",128,0,4,-40
	.stabs "UL3:7",128,0,4,-36
	.stabs "UL2:7",128,0,4,-32
	.stabs "UL1:7",128,0,4,-28
	.stabs "QL:7",128,0,4,-24
	.stabs "J1Y:7",128,0,4,-20
	.stabs "AL3:7",128,0,4,-16
	.stabs "AL2:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "VL:v7",160,0,4,24
	.stabs "UL:v7",160,0,4,20
	.stabs "CL:v7",160,0,4,16
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-SACD_DEGCD
	.stabn 224,0,0,.LBE9-SACD_DEGCD
	.stabs "SACD_BITRAN:F7",36,0,0,SACD_BITRAN
	.align 4
SACD_BITRAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab68, %esp
.LN185:
	.stabn  68,0,81,.LN185-SACD_BITRAN		# line 81, column 1
.LBB10:
.LN186:
	.stabn  68,0,82,.LN186-SACD_BITRAN		# line 82, column 9
	call	SACD_DRANN
	movl	%eax,-8(%ebp) 
.LN187:
	.stabn  68,0,82,.LN187-SACD_BITRAN		# line 82, column 22
	shll	$1, -8(%ebp)
.LN188:
	.stabn  68,0,83,.LN188-SACD_BITRAN		# line 83, column 7
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab71
.Lab70:
.LN189:
	.stabn  68,0,83,.LN189-SACD_BITRAN		# line 83, column 28
	movl	$1,-12(%ebp) 
	jmp	.Lab69
.Lab71:
.LN190:
	.stabn  68,0,83,.LN190-SACD_BITRAN		# line 83, column 40
	movl	$0,-12(%ebp) 
.Lab69:
.LN191:
	.stabn  68,0,84,.LN191-SACD_BITRAN		# line 84, column 7
	movl	-12(%ebp),%eax
	leave
	ret
.LN192:
	.stabn  68,0,85,.LN192-SACD_BITRAN		# line 85, column 0
	call	ReturnErr_
.LBE10:
	leave
	ret
	.Lab68 = 16
	.stabs "IDUM:7",128,0,4,-16
	.stabs "BL:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabn 192,0,0,.LBB10-SACD_BITRAN
	.stabn 224,0,0,.LBE10-SACD_BITRAN
	.stabs "SACD_BEGIN2:F16",36,0,0,SACD_BEGIN2
	.align 4
SACD_BEGIN2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab72, %esp
.LN193:
	.stabn  68,0,48,.LN193-SACD_BEGIN2		# line 48, column 1
.LBB11:
.LN194:
	.stabn  68,0,51,.LN194-SACD_BEGIN2		# line 51, column 9
	movl	$1,-8(%ebp) 
.LN195:
	.stabn  68,0,51,.LN195-SACD_BEGIN2		# line 51, column 16
	movl	$1,-28(%ebp) 
	jmp	.Lab73
.Lab74:
.LN196:
	.stabn  68,0,52,.LN196-SACD_BEGIN2		# line 52, column 44
	movl	-8(%ebp),%ebx
	.data
	.align 4
.Lab76:
	.long	1,64
	.text
	boundl	%ebx,.Lab76
	movl	-28(%ebp),%eax
	movl	%eax,SACD_s + 16(,%ebx,4) 
.LN197:
	.stabn  68,0,53,.LN197-SACD_BEGIN2		# line 53, column 15
	incl	-8(%ebp)
.LN198:
	.stabn  68,0,53,.LN198-SACD_BEGIN2		# line 53, column 25
	shll	$1, -28(%ebp)
.Lab73:
.LN199:
	.stabn  68,0,52,.LN199-SACD_BEGIN2		# line 52, column 16
	movl	-28(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab74
.Lab75:
.LN200:
	.stabn  68,0,54,.LN200-SACD_BEGIN2		# line 54, column 11
	movl	-8(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,SACD_s + 4 
.LN201:
	.stabn  68,0,54,.LN201-SACD_BEGIN2		# line 54, column 22
	movl	$0,SACD_s + 12 
.LN202:
	.stabn  68,0,54,.LN202-SACD_BEGIN2		# line 54, column 29
	movl	MASSTOR_s,%eax
	movl	%eax,-28(%ebp) 
.Lab77:
.LN203:
	.stabn  68,0,55,.LN203-SACD_BEGIN2		# line 55, column 16
	movl	-28(%ebp),%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-28(%ebp) 
.LN204:
	.stabn  68,0,55,.LN204-SACD_BEGIN2		# line 55, column 32
	incl	SACD_s + 12
.LN205:
	.stabn  68,0,56,.LN205-SACD_BEGIN2		# line 56, column 23
	cmpl	$10,-28(%ebp)
	jge	.Lab77
.Lab78:
.LN206:
	.stabn  68,0,57,.LN206-SACD_BEGIN2		# line 57, column 12
	movl	$1,SACD_s 
.LN207:
	.stabn  68,0,58,.LN207-SACD_BEGIN2		# line 58, column 7
	movl	SACD_s + 12,%eax
	movl	%eax,-32(%ebp) 
	cmpl	$1,-32(%ebp)
	jl	.Lab79
	movl	$1,-8(%ebp) 
	movl	-32(%ebp),%eax
	movl	%eax,-36(%ebp) 
.Lab80:
.LN208:
	.stabn  68,0,58,.LN208-SACD_BEGIN2		# line 58, column 32
	movl	SACD_s,%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,SACD_s 
.LN209:
	.stabn  68,0,58,.LN209-SACD_BEGIN2		# line 58, column 7
	movl	-8(%ebp),%eax
	cmpl	-36(%ebp),%eax
	jge	.Lab79
	incl	-8(%ebp) 
	jmp	.Lab80
.Lab79:
.LN210:
	.stabn  68,0,59,.LN210-SACD_BEGIN2		# line 59, column 10
	movl	SACD_s + 4,%eax
	sarl	$1, %eax 
	movl	%eax,-12(%ebp) 
.LN211:
	.stabn  68,0,59,.LN211-SACD_BEGIN2		# line 59, column 27
	incl	-12(%ebp)
.LN212:
	.stabn  68,0,59,.LN212-SACD_BEGIN2		# line 59, column 41
	movl	-12(%ebp),%eax
	.data
	.align 4
.Lab81:
	.long	1,64
	.text
	boundl	%eax,.Lab81
	movl	SACD_s + 16(,%eax,4),%eax
	movl	%eax,SACD_s + 8 
.LN213:
	.stabn  68,0,60,.LN213-SACD_BEGIN2		# line 60, column 12
	movl	MASSTOR_s,%eax
	movl	SACD_s + 8,%ebx
	cdq
	idivl	%ebx
	movl	%eax,SACD_s + 16 
.LN214:
	.stabn  68,0,62,.LN214-SACD_BEGIN2		# line 62, column 10
	pushl	$3
	pushl	$5
	pushl	$6
	pushl	$2
	pushl	$9
	pushl	$5
	pushl	$1
	pushl	$4
	pushl	$1
	pushl	$3
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-12(%ebp) 
.LN215:
	.stabn  68,0,63,.LN215-SACD_BEGIN2		# line 63, column 10
	pushl	$4
	pushl	$8
	pushl	$3
	pushl	$2
	pushl	$3
	pushl	$9
	pushl	$7
	pushl	$9
	pushl	$8
	pushl	$5
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-16(%ebp) 
.LN216:
	.stabn  68,0,63,.LN216-SACD_BEGIN2		# line 63, column 42
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN217:
	.stabn  68,0,63,.LN217-SACD_BEGIN2		# line 63, column 61
	movl	$0,-24(%ebp) 
	jmp	.Lab82
.Lab83:
.LN218:
	.stabn  68,0,64,.LN218-SACD_BEGIN2		# line 64, column 35
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-28(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN219:
	.stabn  68,0,64,.LN219-SACD_BEGIN2		# line 64, column 51
	movl	-24(%ebp),%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,-12(%ebp) 
.LN220:
	.stabn  68,0,64,.LN220-SACD_BEGIN2		# line 64, column 62
	movl	-28(%ebp),%eax
 	addl	-12(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.Lab82:
.LN221:
	.stabn  68,0,64,.LN221-SACD_BEGIN2		# line 64, column 16
	movl	MASSTOR_s,%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	cmpl	%eax,-24(%ebp)
	jl	.Lab83
.Lab84:
.LN222:
	.stabn  68,0,65,.LN222-SACD_BEGIN2		# line 65, column 9
	sarl	$3, -24(%ebp)
.LN223:
	.stabn  68,0,65,.LN223-SACD_BEGIN2		# line 65, column 24
	movl	-24(%ebp),%eax
	leal	(,%eax,8),%eax
	movl	%eax,-12(%ebp) 
.LN224:
	.stabn  68,0,65,.LN224-SACD_BEGIN2		# line 65, column 37
	movl	$5,%eax
 	addl	-12(%ebp),%eax 
	movl	%eax,SACD_s + 280 
.LN225:
	.stabn  68,0,66,.LN225-SACD_BEGIN2		# line 66, column 10
	pushl	$4
	pushl	$5
	pushl	$6
	pushl	$8
	pushl	$4
	pushl	$2
	pushl	$3
	pushl	$1
	pushl	$1
	pushl	$2
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-12(%ebp) 
.LN226:
	.stabn  68,0,67,.LN226-SACD_BEGIN2		# line 67, column 10
	pushl	$0
	pushl	$0
	pushl	$0
	pushl	$0
	pushl	$1
	pushl	$7
	pushl	$8
	pushl	$1
	pushl	$5
	pushl	$0
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-16(%ebp) 
.LN227:
	.stabn  68,0,67,.LN227-SACD_BEGIN2		# line 67, column 42
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN228:
	.stabn  68,0,67,.LN228-SACD_BEGIN2		# line 67, column 61
	movl	$0,-24(%ebp) 
.LN229:
	.stabn  68,0,68,.LN229-SACD_BEGIN2		# line 68, column 7
	movl	SACD_s + 12,%eax
	movl	%eax,-40(%ebp) 
	cmpl	$1,-40(%ebp)
	jl	.Lab85
	movl	$1,-8(%ebp) 
	movl	-40(%ebp),%eax
	movl	%eax,-44(%ebp) 
.Lab86:
.LN230:
	.stabn  68,0,68,.LN230-SACD_BEGIN2		# line 68, column 27
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-28(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN231:
	.stabn  68,0,68,.LN231-SACD_BEGIN2		# line 68, column 43
	movl	-24(%ebp),%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,-12(%ebp) 
.LN232:
	.stabn  68,0,68,.LN232-SACD_BEGIN2		# line 68, column 54
	movl	-28(%ebp),%eax
 	addl	-12(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN233:
	.stabn  68,0,68,.LN233-SACD_BEGIN2		# line 68, column 7
	movl	-8(%ebp),%eax
	cmpl	-44(%ebp),%eax
	jge	.Lab85
	incl	-8(%ebp) 
	jmp	.Lab86
.Lab85:
.LN234:
	.stabn  68,0,69,.LN234-SACD_BEGIN2		# line 69, column 7
	leal	-28(%ebp),%eax
	pushl	%eax
	leal	SACD_s + 276,%eax
	pushl	%eax
	pushl	SACD_s
	pushl	$0
	pushl	-24(%ebp)
	call	SACD_DQR
	addl	$20, %esp
.LN235:
	.stabn  68,0,70,.LN235-SACD_BEGIN2		# line 70, column 7
	pushl	SACD_s + 276
	call	MASELEM_MASEVEN
	addl	$4, %esp
	cmpb	$0,%al
	je	.Lab87
.Lab88:
.LN236:
	.stabn  68,0,70,.LN236-SACD_BEGIN2		# line 70, column 33
	incl	SACD_s + 276
.Lab87:
.LN237:
	.stabn  68,0,71,.LN237-SACD_BEGIN2		# line 71, column 10
	pushl	$9
	pushl	$4
	pushl	$6
	pushl	$6
	pushl	$5
	pushl	$1
	pushl	$2
	pushl	$7
	pushl	$7
	pushl	$5
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-12(%ebp) 
.LN238:
	.stabn  68,0,72,.LN238-SACD_BEGIN2		# line 72, column 10
	pushl	$0
	pushl	$6
	pushl	$0
	pushl	$6
	pushl	$8
	pushl	$2
	pushl	$3
	pushl	$5
	pushl	$1
	pushl	$0
	call	SACLIST_LIST10
	addl	$40, %esp
	movl	%eax,-16(%ebp) 
.LN239:
	.stabn  68,0,72,.LN239-SACD_BEGIN2		# line 72, column 42
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN240:
	.stabn  68,0,72,.LN240-SACD_BEGIN2		# line 72, column 61
	movl	$0,-24(%ebp) 
.LN241:
	.stabn  68,0,73,.LN241-SACD_BEGIN2		# line 73, column 7
	movl	SACD_s + 12,%eax
	movl	%eax,-48(%ebp) 
	cmpl	$1,-48(%ebp)
	jl	.Lab89
	movl	$1,-8(%ebp) 
	movl	-48(%ebp),%eax
	movl	%eax,-52(%ebp) 
.Lab90:
.LN242:
	.stabn  68,0,73,.LN242-SACD_BEGIN2		# line 73, column 27
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-28(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN243:
	.stabn  68,0,73,.LN243-SACD_BEGIN2		# line 73, column 43
	movl	-24(%ebp),%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,-12(%ebp) 
.LN244:
	.stabn  68,0,73,.LN244-SACD_BEGIN2		# line 73, column 54
	movl	-28(%ebp),%eax
 	addl	-12(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN245:
	.stabn  68,0,73,.LN245-SACD_BEGIN2		# line 73, column 7
	movl	-8(%ebp),%eax
	cmpl	-52(%ebp),%eax
	jge	.Lab89
	incl	-8(%ebp) 
	jmp	.Lab90
.Lab89:
.LN246:
	.stabn  68,0,74,.LN246-SACD_BEGIN2		# line 74, column 12
	movl	-24(%ebp),%eax
	movl	%eax,SACD_s + 284 
.LN247:
	.stabn  68,0,75,.LN247-SACD_BEGIN2		# line 75, column 7
	leave
	ret
.LN248:
	.stabn  68,0,76,.LN248-SACD_BEGIN2		# line 76, column 0
.LBE11:
	leave
	ret
	.Lab72 = 52
	.stabs "TL:7",128,0,4,-28
	.stabs "ML:7",128,0,4,-24
	.stabs "L:7",128,0,4,-20
	.stabs "J2Y:7",128,0,4,-16
	.stabs "J1Y:7",128,0,4,-12
	.stabs "IL:7",128,0,4,-8
	.stabn 192,0,0,.LBB11-SACD_BEGIN2
	.stabn 224,0,0,.LBE11-SACD_BEGIN2
	.stabs "SACD:F16",36,0,0,SACD
	.align 4
SACD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab91, %esp
.LN249:
	.stabn  68,0,242,.LN249-SACD		# line 242, column 1
.LBB12:
.LN250:
	.stabn  68,0,245,.LN250-SACD		# line 245, column 1
	call	SACD_BEGIN2
.LN251:
	.stabn  68,0,246,.LN251-SACD		# line 246, column 0
.LBE12:
	leave
	ret
	.Lab91 = 4
	.stabn 192,0,0,.LBB12-SACD
	.stabn 224,0,0,.LBE12-SACD
	.stabs "SACD_s:Gs288RTERM:7,2272,32;RMULT:7,2240,32;RINC:7,2208,32;THETA:7,0,32;ZETA:7,32,32;DELTA:7,64,32;ETA:7,96,32;EPSIL:7,128,32;TABP2:17=ar4;1;64;7,160,2048;;",32,0,0,0
