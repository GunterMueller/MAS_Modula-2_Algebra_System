	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "SACSET.mod",100,0,0,.LBB0
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
	.globl	SACSET
	.globl	SACSET_USUN
	.globl	SACSET_USINT
	.globl	SACSET_USDIFF
	.globl	SACSET_USCOMP
	.globl	SACSET_SUNION
	.globl	SACSET_SINTER
	.globl	SACSET_SDIFF
	.globl	SACSET_SCOMP
	.globl	SACSET_LBIM
	.globl	SACSET_LBIBS
	.globl	SACSET_LBIBMS
	.stabs "SACSET_USUN:F7",36,0,0,SACSET_USUN
	.align 4
SACSET_USUN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,227,.LN1-SACSET_USUN		# line 227, column 1
.LBB1:
.LN2:
	.stabn  68,0,228,.LN2-SACSET_USUN		# line 228, column 10
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACSET_USDIFF
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN3:
	.stabn  68,0,228,.LN3-SACSET_USUN		# line 228, column 26
	pushl	12(%ebp)
	pushl	-12(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN4:
	.stabn  68,0,228,.LN4-SACSET_USUN		# line 228, column 41
	movl	-8(%ebp),%eax
	leave
	ret
.LN5:
	.stabn  68,0,229,.LN5-SACSET_USUN		# line 229, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACSET_USUN
	.stabn 224,0,0,.LBE1-SACSET_USUN
	.stabs "SACSET_USINT:F7",36,0,0,SACSET_USINT
	.align 4
SACSET_USINT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab2, %esp
.LN6:
	.stabn  68,0,214,.LN6-SACSET_USINT		# line 214, column 1
.LBB2:
.LN7:
	.stabn  68,0,215,.LN7-SACSET_USINT		# line 215, column 9
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN8:
	.stabn  68,0,215,.LN8-SACSET_USINT		# line 215, column 15
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
	jmp	.Lab3
.Lab4:
.LN9:
	.stabn  68,0,216,.LN9-SACSET_USINT		# line 216, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN10:
	.stabn  68,0,217,.LN10-SACSET_USINT		# line 217, column 13
	pushl	12(%ebp)
	pushl	-8(%ebp)
	call	SACLIST_MEMBER
	addl	$8, %esp
	cmpl	$1,%eax
	jne	.Lab6
.Lab7:
.LN11:
	.stabn  68,0,217,.LN11-SACSET_USINT		# line 217, column 39
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.Lab6:
.Lab3:
.LN12:
	.stabn  68,0,216,.LN12-SACSET_USINT		# line 216, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab4
.Lab5:
.LN13:
	.stabn  68,0,219,.LN13-SACSET_USINT		# line 219, column 7
	movl	-16(%ebp),%eax
	leave
	ret
.LN14:
	.stabn  68,0,220,.LN14-SACSET_USINT		# line 220, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab2 = 16
	.stabs "C:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACSET_USINT
	.stabn 224,0,0,.LBE2-SACSET_USINT
	.stabs "SACSET_USDIFF:F7",36,0,0,SACSET_USDIFF
	.align 4
SACSET_USDIFF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab8, %esp
.LN15:
	.stabn  68,0,201,.LN15-SACSET_USDIFF		# line 201, column 1
.LBB3:
.LN16:
	.stabn  68,0,202,.LN16-SACSET_USDIFF		# line 202, column 9
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN17:
	.stabn  68,0,202,.LN17-SACSET_USDIFF		# line 202, column 15
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
	jmp	.Lab9
.Lab10:
.LN18:
	.stabn  68,0,203,.LN18-SACSET_USDIFF		# line 203, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN19:
	.stabn  68,0,204,.LN19-SACSET_USDIFF		# line 204, column 13
	pushl	12(%ebp)
	pushl	-8(%ebp)
	call	SACLIST_MEMBER
	addl	$8, %esp
	cmpl	$0,%eax
	jne	.Lab12
.Lab13:
.LN20:
	.stabn  68,0,204,.LN20-SACSET_USDIFF		# line 204, column 39
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.Lab12:
.Lab9:
.LN21:
	.stabn  68,0,203,.LN21-SACSET_USDIFF		# line 203, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab10
.Lab11:
.LN22:
	.stabn  68,0,206,.LN22-SACSET_USDIFF		# line 206, column 7
	movl	-16(%ebp),%eax
	leave
	ret
.LN23:
	.stabn  68,0,207,.LN23-SACSET_USDIFF		# line 207, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab8 = 16
	.stabs "C:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-SACSET_USDIFF
	.stabn 224,0,0,.LBE3-SACSET_USDIFF
	.stabs "SACSET_USCOMP:F7",36,0,0,SACSET_USCOMP
	.align 4
SACSET_USCOMP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab14, %esp
.LN24:
	.stabn  68,0,191,.LN24-SACSET_USCOMP		# line 191, column 1
.LBB4:
.LN25:
	.stabn  68,0,192,.LN25-SACSET_USCOMP		# line 192, column 7
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACLIST_MEMBER
	addl	$8, %esp
	cmpl	$1,%eax
	jne	.Lab17
.Lab16:
.LN26:
	.stabn  68,0,192,.LN26-SACSET_USCOMP		# line 192, column 34
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab15
.Lab17:
.LN27:
	.stabn  68,0,192,.LN27-SACSET_USCOMP		# line 192, column 46
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab15:
.LN28:
	.stabn  68,0,193,.LN28-SACSET_USCOMP		# line 193, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN29:
	.stabn  68,0,194,.LN29-SACSET_USCOMP		# line 194, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab14 = 8
	.stabs "LP:7",128,0,4,-8
	.stabs "L:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACSET_USCOMP
	.stabn 224,0,0,.LBE4-SACSET_USCOMP
	.stabs "SACSET_SUNION:F7",36,0,0,SACSET_SUNION
	.align 4
SACSET_SUNION:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab18, %esp
.LN30:
	.stabn  68,0,171,.LN30-SACSET_SUNION		# line 171, column 1
.LBB5:
.LN31:
	.stabn  68,0,172,.LN31-SACSET_SUNION		# line 172, column 9
	movl	MASSTOR_s,%eax
	movl	%eax,-28(%ebp) 
.LN32:
	.stabn  68,0,172,.LN32-SACSET_SUNION		# line 172, column 19
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN33:
	.stabn  68,0,172,.LN33-SACSET_SUNION		# line 172, column 26
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
	jmp	.Lab19
.Lab20:
.LN34:
	.stabn  68,0,173,.LN34-SACSET_SUNION		# line 173, column 46
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN35:
	.stabn  68,0,174,.LN35-SACSET_SUNION		# line 174, column 15
	pushl	-20(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN36:
	.stabn  68,0,175,.LN36-SACSET_SUNION		# line 175, column 13
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jne	.Lab24
.Lab23:
.LN37:
	.stabn  68,0,175,.LN37-SACSET_SUNION		# line 175, column 31
	pushl	-28(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-28(%ebp) 
.LN38:
	.stabn  68,0,175,.LN38-SACSET_SUNION		# line 175, column 48
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN39:
	.stabn  68,0,176,.LN39-SACSET_SUNION		# line 176, column 18
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
	jmp	.Lab22
.Lab24:
.LN40:
	.stabn  68,0,177,.LN40-SACSET_SUNION		# line 177, column 16
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jge	.Lab27
.Lab26:
.LN41:
	.stabn  68,0,177,.LN41-SACSET_SUNION		# line 177, column 34
	pushl	-28(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-28(%ebp) 
.LN42:
	.stabn  68,0,177,.LN42-SACSET_SUNION		# line 177, column 51
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab25
.Lab27:
.LN43:
	.stabn  68,0,178,.LN43-SACSET_SUNION		# line 178, column 21
	pushl	-28(%ebp)
	pushl	-16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-28(%ebp) 
.LN44:
	.stabn  68,0,178,.LN44-SACSET_SUNION		# line 178, column 38
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.Lab25:
.Lab22:
.Lab19:
.LN45:
	.stabn  68,0,173,.LN45-SACSET_SUNION		# line 173, column 25
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab21
.Lab28:
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab20
.Lab21:
.LN46:
	.stabn  68,0,181,.LN46-SACSET_SUNION		# line 181, column 7
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab29
.Lab30:
.LN47:
	.stabn  68,0,181,.LN47-SACSET_SUNION		# line 181, column 26
	movl	-20(%ebp),%eax
	movl	%eax,-12(%ebp) 
.Lab29:
.LN48:
	.stabn  68,0,182,.LN48-SACSET_SUNION		# line 182, column 7
	movl	-28(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab33
.Lab32:
.LN49:
	.stabn  68,0,182,.LN49-SACSET_SUNION		# line 182, column 25
	movl	-12(%ebp),%eax
	movl	%eax,-24(%ebp) 
	jmp	.Lab31
.Lab33:
.LN50:
	.stabn  68,0,182,.LN50-SACSET_SUNION		# line 182, column 37
	pushl	-28(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN51:
	.stabn  68,0,182,.LN51-SACSET_SUNION		# line 182, column 48
	pushl	-12(%ebp)
	pushl	-28(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.Lab31:
.LN52:
	.stabn  68,0,183,.LN52-SACSET_SUNION		# line 183, column 7
	movl	-24(%ebp),%eax
	leave
	ret
.LN53:
	.stabn  68,0,184,.LN53-SACSET_SUNION		# line 184, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab18 = 28
	.stabs "CP:7",128,0,4,-28
	.stabs "C:7",128,0,4,-24
	.stabs "BP:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-SACSET_SUNION
	.stabn 224,0,0,.LBE5-SACSET_SUNION
	.stabs "SACSET_SINTER:F7",36,0,0,SACSET_SINTER
	.align 4
SACSET_SINTER:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab34, %esp
.LN54:
	.stabn  68,0,154,.LN54-SACSET_SINTER		# line 154, column 1
.LBB6:
.LN55:
	.stabn  68,0,155,.LN55-SACSET_SINTER		# line 155, column 9
	movl	MASSTOR_s,%eax
	movl	%eax,-28(%ebp) 
.LN56:
	.stabn  68,0,155,.LN56-SACSET_SINTER		# line 155, column 19
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN57:
	.stabn  68,0,155,.LN57-SACSET_SINTER		# line 155, column 26
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
	jmp	.Lab35
.Lab36:
.LN58:
	.stabn  68,0,156,.LN58-SACSET_SINTER		# line 156, column 46
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN59:
	.stabn  68,0,157,.LN59-SACSET_SINTER		# line 157, column 15
	pushl	-20(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN60:
	.stabn  68,0,158,.LN60-SACSET_SINTER		# line 158, column 13
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jne	.Lab40
.Lab39:
.LN61:
	.stabn  68,0,158,.LN61-SACSET_SINTER		# line 158, column 31
	pushl	-28(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-28(%ebp) 
.LN62:
	.stabn  68,0,158,.LN62-SACSET_SINTER		# line 158, column 48
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN63:
	.stabn  68,0,159,.LN63-SACSET_SINTER		# line 159, column 18
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
	jmp	.Lab38
.Lab40:
.LN64:
	.stabn  68,0,160,.LN64-SACSET_SINTER		# line 160, column 16
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jge	.Lab43
.Lab42:
.LN65:
	.stabn  68,0,160,.LN65-SACSET_SINTER		# line 160, column 34
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab41
.Lab43:
.LN66:
	.stabn  68,0,160,.LN66-SACSET_SINTER		# line 160, column 52
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.Lab41:
.Lab38:
.Lab35:
.LN67:
	.stabn  68,0,156,.LN67-SACSET_SINTER		# line 156, column 25
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab37
.Lab44:
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab36
.Lab37:
.LN68:
	.stabn  68,0,163,.LN68-SACSET_SINTER		# line 163, column 8
	pushl	-28(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN69:
	.stabn  68,0,163,.LN69-SACSET_SINTER		# line 163, column 19
	movl	-24(%ebp),%eax
	leave
	ret
.LN70:
	.stabn  68,0,164,.LN70-SACSET_SINTER		# line 164, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab34 = 28
	.stabs "CP:7",128,0,4,-28
	.stabs "C:7",128,0,4,-24
	.stabs "BP:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-SACSET_SINTER
	.stabn 224,0,0,.LBE6-SACSET_SINTER
	.stabs "SACSET_SDIFF:F7",36,0,0,SACSET_SDIFF
	.align 4
SACSET_SDIFF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab45, %esp
.LN71:
	.stabn  68,0,136,.LN71-SACSET_SDIFF		# line 136, column 1
.LBB7:
.LN72:
	.stabn  68,0,137,.LN72-SACSET_SDIFF		# line 137, column 9
	movl	MASSTOR_s,%eax
	movl	%eax,-28(%ebp) 
.LN73:
	.stabn  68,0,137,.LN73-SACSET_SDIFF		# line 137, column 19
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN74:
	.stabn  68,0,137,.LN74-SACSET_SDIFF		# line 137, column 26
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
	jmp	.Lab46
.Lab47:
.LN75:
	.stabn  68,0,138,.LN75-SACSET_SDIFF		# line 138, column 46
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN76:
	.stabn  68,0,139,.LN76-SACSET_SDIFF		# line 139, column 15
	pushl	-20(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN77:
	.stabn  68,0,140,.LN77-SACSET_SDIFF		# line 140, column 13
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jne	.Lab51
.Lab50:
.LN78:
	.stabn  68,0,140,.LN78-SACSET_SDIFF		# line 140, column 31
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN79:
	.stabn  68,0,140,.LN79-SACSET_SDIFF		# line 140, column 44
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
	jmp	.Lab49
.Lab51:
.LN80:
	.stabn  68,0,141,.LN80-SACSET_SDIFF		# line 141, column 16
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jge	.Lab54
.Lab53:
.LN81:
	.stabn  68,0,141,.LN81-SACSET_SDIFF		# line 141, column 34
	pushl	-28(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-28(%ebp) 
.LN82:
	.stabn  68,0,141,.LN82-SACSET_SDIFF		# line 141, column 51
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab52
.Lab54:
.LN83:
	.stabn  68,0,142,.LN83-SACSET_SDIFF		# line 142, column 21
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.Lab52:
.Lab49:
.Lab46:
.LN84:
	.stabn  68,0,138,.LN84-SACSET_SDIFF		# line 138, column 25
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab48
.Lab55:
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab47
.Lab48:
.LN85:
	.stabn  68,0,145,.LN85-SACSET_SDIFF		# line 145, column 7
	movl	-28(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab58
.Lab57:
.LN86:
	.stabn  68,0,145,.LN86-SACSET_SDIFF		# line 145, column 25
	movl	-12(%ebp),%eax
	movl	%eax,-24(%ebp) 
	jmp	.Lab56
.Lab58:
.LN87:
	.stabn  68,0,145,.LN87-SACSET_SDIFF		# line 145, column 37
	pushl	-28(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN88:
	.stabn  68,0,145,.LN88-SACSET_SDIFF		# line 145, column 48
	pushl	-12(%ebp)
	pushl	-28(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.Lab56:
.LN89:
	.stabn  68,0,146,.LN89-SACSET_SDIFF		# line 146, column 7
	movl	-24(%ebp),%eax
	leave
	ret
.LN90:
	.stabn  68,0,147,.LN90-SACSET_SDIFF		# line 147, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab45 = 28
	.stabs "CP:7",128,0,4,-28
	.stabs "C:7",128,0,4,-24
	.stabs "BP:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-SACSET_SDIFF
	.stabn 224,0,0,.LBE7-SACSET_SDIFF
	.stabs "SACSET_SCOMP:F7",36,0,0,SACSET_SCOMP
	.align 4
SACSET_SCOMP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab59, %esp
.LN91:
	.stabn  68,0,119,.LN91-SACSET_SCOMP		# line 119, column 1
.LBB8:
.LN92:
	.stabn  68,0,120,.LN92-SACSET_SCOMP		# line 120, column 27
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN93:
	.stabn  68,0,120,.LN93-SACSET_SCOMP		# line 120, column 34
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab60
.Lab61:
.LN94:
	.stabn  68,0,123,.LN94-SACSET_SCOMP		# line 123, column 13
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-20(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN95:
	.stabn  68,0,124,.LN95-SACSET_SCOMP		# line 124, column 13
	movl	8(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jne	.Lab63
.Lab64:
.LN96:
	.stabn  68,0,124,.LN96-SACSET_SCOMP		# line 124, column 31
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN97:
	.stabn  68,0,124,.LN97-SACSET_SCOMP		# line 124, column 36
	movl	-8(%ebp),%eax
	leave
	ret
.Lab63:
.LN98:
	.stabn  68,0,125,.LN98-SACSET_SCOMP		# line 125, column 13
	movl	8(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jle	.Lab67
.Lab66:
.LN99:
	.stabn  68,0,125,.LN99-SACSET_SCOMP		# line 125, column 31
	pushl	-8(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
	jmp	.Lab65
.Lab67:
.LN100:
	.stabn  68,0,126,.LN100-SACSET_SCOMP		# line 126, column 32
	pushl	-8(%ebp)
	pushl	8(%ebp)
	pushl	-20(%ebp)
	call	SACLIST_COMP2
	addl	$12, %esp
	movl	%eax,-16(%ebp) 
.LN101:
	.stabn  68,0,126,.LN101-SACSET_SCOMP		# line 126, column 53
	pushl	-8(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN102:
	.stabn  68,0,127,.LN102-SACSET_SCOMP		# line 127, column 29
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN103:
	.stabn  68,0,127,.LN103-SACSET_SCOMP		# line 127, column 43
	movl	-8(%ebp),%eax
	leave
	ret
.Lab65:
.Lab60:
.LN104:
	.stabn  68,0,122,.LN104-SACSET_SCOMP		# line 122, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab61
.Lab62:
.LN105:
	.stabn  68,0,129,.LN105-SACSET_SCOMP		# line 129, column 22
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN106:
	.stabn  68,0,129,.LN106-SACSET_SCOMP		# line 129, column 39
	pushl	-8(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN107:
	.stabn  68,0,129,.LN107-SACSET_SCOMP		# line 129, column 50
	movl	-8(%ebp),%eax
	leave
	ret
.LN108:
	.stabn  68,0,130,.LN108-SACSET_SCOMP		# line 130, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab59 = 20
	.stabs "BL:7",128,0,4,-20
	.stabs "LPP:7",128,0,4,-16
	.stabs "LS:7",128,0,4,-12
	.stabs "LP:7",128,0,4,-8
	.stabs "L:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-SACSET_SCOMP
	.stabn 224,0,0,.LBE8-SACSET_SCOMP
	.stabs "SACSET_LBIM:F7",36,0,0,SACSET_LBIM
	.align 4
SACSET_LBIM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab68, %esp
.LN109:
	.stabn  68,0,98,.LN109-SACSET_LBIM		# line 98, column 1
.LBB9:
.LN110:
	.stabn  68,0,99,.LN110-SACSET_LBIM		# line 99, column 27
	movl	8(%ebp),%eax
	movl	%eax,-28(%ebp) 
.LN111:
	.stabn  68,0,99,.LN111-SACSET_LBIM		# line 99, column 36
	movl	12(%ebp),%eax
	movl	%eax,-32(%ebp) 
.LN112:
	.stabn  68,0,99,.LN112-SACSET_LBIM		# line 99, column 43
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-16(%ebp) 
.LN113:
	.stabn  68,0,99,.LN113-SACSET_LBIM		# line 99, column 52
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-24(%ebp) 
	jmp	.Lab69
.Lab70:
.LN114:
	.stabn  68,0,102,.LN114-SACSET_LBIM		# line 102, column 13
	leal	-36(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-28(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN115:
	.stabn  68,0,102,.LN115-SACSET_LBIM		# line 102, column 32
	leal	-40(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	-32(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN116:
	.stabn  68,0,103,.LN116-SACSET_LBIM		# line 103, column 13
	movl	-8(%ebp),%eax
	cmpl	-12(%ebp),%eax
	jge	.Lab74
.Lab73:
.LN117:
	.stabn  68,0,103,.LN117-SACSET_LBIM		# line 103, column 33
	movl	-28(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN118:
	.stabn  68,0,103,.LN118-SACSET_LBIM		# line 103, column 43
	movl	-36(%ebp),%eax
	movl	%eax,-28(%ebp) 
	jmp	.Lab72
.Lab74:
.LN119:
	.stabn  68,0,104,.LN119-SACSET_LBIM		# line 104, column 33
	movl	-32(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN120:
	.stabn  68,0,104,.LN120-SACSET_LBIM		# line 104, column 43
	movl	-40(%ebp),%eax
	movl	%eax,-32(%ebp) 
.Lab72:
.LN121:
	.stabn  68,0,105,.LN121-SACSET_LBIM		# line 105, column 13
	movl	-24(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab77
.Lab76:
.LN122:
	.stabn  68,0,105,.LN122-SACSET_LBIM		# line 105, column 32
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
.LN123:
	.stabn  68,0,105,.LN123-SACSET_LBIM		# line 105, column 39
	movl	-20(%ebp),%eax
	movl	%eax,-16(%ebp) 
	jmp	.Lab75
.Lab77:
.LN124:
	.stabn  68,0,106,.LN124-SACSET_LBIM		# line 106, column 30
	pushl	-20(%ebp)
	pushl	-24(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN125:
	.stabn  68,0,106,.LN125-SACSET_LBIM		# line 106, column 45
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
.Lab75:
.Lab69:
.LN126:
	.stabn  68,0,101,.LN126-SACSET_LBIM		# line 101, column 26
	movl	-28(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab71
.Lab78:
	movl	-32(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab70
.Lab71:
.LN127:
	.stabn  68,0,108,.LN127-SACSET_LBIM		# line 108, column 20
	movl	-32(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab79
.Lab80:
.LN128:
	.stabn  68,0,108,.LN128-SACSET_LBIM		# line 108, column 42
	movl	-32(%ebp),%eax
	movl	%eax,-28(%ebp) 
.Lab79:
.LN129:
	.stabn  68,0,109,.LN129-SACSET_LBIM		# line 109, column 7
	movl	-24(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab83
.Lab82:
.LN130:
	.stabn  68,0,109,.LN130-SACSET_LBIM		# line 109, column 25
	movl	-20(%ebp),%eax
	movl	%eax,-16(%ebp) 
	jmp	.Lab81
.Lab83:
.LN131:
	.stabn  68,0,110,.LN131-SACSET_LBIM		# line 110, column 24
	pushl	-28(%ebp)
	pushl	-24(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.Lab81:
.LN132:
	.stabn  68,0,111,.LN132-SACSET_LBIM		# line 111, column 7
	movl	-16(%ebp),%eax
	leave
	ret
.LN133:
	.stabn  68,0,112,.LN133-SACSET_LBIM		# line 112, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab68 = 40
	.stabs "LPP2:7",128,0,4,-40
	.stabs "LPP1:7",128,0,4,-36
	.stabs "LP2:7",128,0,4,-32
	.stabs "LP1:7",128,0,4,-28
	.stabs "LS:7",128,0,4,-24
	.stabs "LP:7",128,0,4,-20
	.stabs "L:7",128,0,4,-16
	.stabs "AL2:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "L2:p7",160,0,4,12
	.stabs "L1:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-SACSET_LBIM
	.stabn 224,0,0,.LBE9-SACSET_LBIM
	.stabs "SACSET_LBIBS:F16",36,0,0,SACSET_LBIBS
	.align 4
SACSET_LBIBS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab84, %esp
.LN134:
	.stabn  68,0,76,.LN134-SACSET_LBIBS		# line 76, column 1
.LBB10:
.LN135:
	.stabn  68,0,78,.LN135-SACSET_LBIBS		# line 78, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab85
.Lab86:
.LN136:
	.stabn  68,0,78,.LN136-SACSET_LBIBS		# line 78, column 23
	leave
	ret
.Lab85:
.LN137:
	.stabn  68,0,79,.LN137-SACSET_LBIBS		# line 79, column 26
	movl	MASSTOR_s,%eax
	movl	%eax,-24(%ebp) 
.Lab87:
.LN138:
	.stabn  68,0,80,.LN138-SACSET_LBIBS		# line 80, column 16
	movl	8(%ebp),%eax
	movl	%eax,-16(%ebp) 
.LN139:
	.stabn  68,0,80,.LN139-SACSET_LBIBS		# line 80, column 24
	pushl	-16(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN140:
	.stabn  68,0,80,.LN140-SACSET_LBIBS		# line 80, column 38
	pushl	-16(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN141:
	.stabn  68,0,80,.LN141-SACSET_LBIBS		# line 80, column 53
	movl	MASSTOR_s,%eax
	movl	%eax,-28(%ebp) 
	jmp	.Lab89
.Lab90:
.LN142:
	.stabn  68,0,81,.LN142-SACSET_LBIBS		# line 81, column 36
	pushl	-20(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN143:
	.stabn  68,0,82,.LN143-SACSET_LBIBS		# line 82, column 20
	movl	-8(%ebp),%eax
	cmpl	-12(%ebp),%eax
	jle	.Lab94
.Lab93:
.LN144:
	.stabn  68,0,82,.LN144-SACSET_LBIBS		# line 82, column 39
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN145:
	.stabn  68,0,83,.LN145-SACSET_LBIBS		# line 83, column 23
	pushl	-8(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN146:
	.stabn  68,0,83,.LN146-SACSET_LBIBS		# line 83, column 42
	movl	-20(%ebp),%eax
	movl	%eax,-28(%ebp) 
	jmp	.Lab92
.Lab94:
.LN147:
	.stabn  68,0,83,.LN147-SACSET_LBIBS		# line 83, column 57
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab92:
.LN148:
	.stabn  68,0,84,.LN148-SACSET_LBIBS		# line 84, column 22
	movl	-20(%ebp),%eax
	movl	%eax,-16(%ebp) 
.LN149:
	.stabn  68,0,84,.LN149-SACSET_LBIBS		# line 84, column 32
	pushl	-16(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.Lab89:
.LN150:
	.stabn  68,0,81,.LN150-SACSET_LBIBS		# line 81, column 24
	movl	-20(%ebp),%eax
	cmpl	-24(%ebp),%eax
	jne	.Lab90
.Lab91:
.LN151:
	.stabn  68,0,85,.LN151-SACSET_LBIBS		# line 85, column 15
	movl	-28(%ebp),%eax
	movl	%eax,-24(%ebp) 
.LN152:
	.stabn  68,0,86,.LN152-SACSET_LBIBS		# line 86, column 22
	movl	-24(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab87
.Lab88:
.LN153:
	.stabn  68,0,87,.LN153-SACSET_LBIBS		# line 87, column 7
	leave
	ret
.LN154:
	.stabn  68,0,88,.LN154-SACSET_LBIBS		# line 88, column 0
.LBE10:
	leave
	ret
	.Lab84 = 28
	.stabs "MP:7",128,0,4,-28
	.stabs "M:7",128,0,4,-24
	.stabs "LPP:7",128,0,4,-20
	.stabs "LP:7",128,0,4,-16
	.stabs "ALPP:7",128,0,4,-12
	.stabs "ALP:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB10-SACSET_LBIBS
	.stabn 224,0,0,.LBE10-SACSET_LBIBS
	.stabs "SACSET_LBIBMS:F7",36,0,0,SACSET_LBIBMS
	.align 4
SACSET_LBIBMS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab95, %esp
.LN155:
	.stabn  68,0,48,.LN155-SACSET_LBIBMS		# line 48, column 1
.LBB11:
.LN156:
	.stabn  68,0,49,.LN156-SACSET_LBIBMS		# line 49, column 25
	movl	$10,-80(%ebp) 
.LN157:
	.stabn  68,0,49,.LN157-SACSET_LBIBMS		# line 49, column 33
	pushl	8(%ebp)
	call	MASSTOR_LENGTH
	addl	$4, %esp
	movl	%eax,-64(%ebp) 
.LN158:
	.stabn  68,0,50,.LN158-SACSET_LBIBMS		# line 50, column 7
	movl	-64(%ebp),%eax
	cmpl	-80(%ebp),%eax
	jge	.Lab96
.Lab97:
.LN159:
	.stabn  68,0,50,.LN159-SACSET_LBIBMS		# line 50, column 23
	pushl	8(%ebp)
	call	SACSET_LBIBS
	addl	$4, %esp
.LN160:
	.stabn  68,0,50,.LN160-SACSET_LBIBMS		# line 50, column 34
	movl	8(%ebp),%eax
	movl	%eax,-56(%ebp) 
.LN161:
	.stabn  68,0,50,.LN161-SACSET_LBIBMS		# line 50, column 39
	movl	-56(%ebp),%eax
	leave
	ret
.Lab96:
.LN162:
	.stabn  68,0,51,.LN162-SACSET_LBIBMS		# line 51, column 32
	movl	$0,-32(%ebp) 
.LN163:
	.stabn  68,0,51,.LN163-SACSET_LBIBMS		# line 51, column 39
	movl	$1,-60(%ebp) 
.LN164:
	.stabn  68,0,51,.LN164-SACSET_LBIBMS		# line 51, column 46
	movl	-64(%ebp),%eax
	movl	%eax,-68(%ebp) 
.Lab98:
.LN165:
	.stabn  68,0,52,.LN165-SACSET_LBIBMS		# line 52, column 16
	incl	-32(%ebp)
.LN166:
	.stabn  68,0,52,.LN166-SACSET_LBIBMS		# line 52, column 26
	shll	$1, -60(%ebp)
.LN167:
	.stabn  68,0,52,.LN167-SACSET_LBIBMS		# line 52, column 37
	sarl	$1, -68(%ebp)
.LN168:
	.stabn  68,0,53,.LN168-SACSET_LBIBMS		# line 53, column 23
	movl	-68(%ebp),%eax
	cmpl	-80(%ebp),%eax
	jge	.Lab98
.Lab99:
.LN169:
	.stabn  68,0,54,.LN169-SACSET_LBIBMS		# line 54, column 10
	movl	-68(%ebp),%eax
	imull	-60(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN170:
	.stabn  68,0,54,.LN170-SACSET_LBIBMS		# line 54, column 21
	movl	-64(%ebp),%eax
 	subl	-24(%ebp),%eax 
	movl	%eax,-76(%ebp) 
.LN171:
	.stabn  68,0,54,.LN171-SACSET_LBIBMS		# line 54, column 32
	movl	MASSTOR_s,%eax
	movl	%eax,-8(%ebp) 
.LN172:
	.stabn  68,0,54,.LN172-SACSET_LBIBMS		# line 54, column 42
	movl	8(%ebp),%eax
	movl	%eax,-44(%ebp) 
.LN173:
	.stabn  68,0,55,.LN173-SACSET_LBIBMS		# line 55, column 7
	movl	-60(%ebp),%eax
	movl	%eax,-84(%ebp) 
	cmpl	$1,-84(%ebp)
	jl	.Lab100
	movl	$1,-20(%ebp) 
	movl	-84(%ebp),%eax
	movl	%eax,-88(%ebp) 
.Lab101:
.LN174:
	.stabn  68,0,56,.LN174-SACSET_LBIBMS		# line 56, column 11
	movl	-20(%ebp),%eax
	cmpl	-76(%ebp),%eax
	jg	.Lab104
.Lab103:
.LN175:
	.stabn  68,0,56,.LN175-SACSET_LBIBMS		# line 56, column 31
	movl	-68(%ebp),%eax
	movl	%eax,-72(%ebp) 
	jmp	.Lab102
.Lab104:
.LN176:
	.stabn  68,0,56,.LN176-SACSET_LBIBMS		# line 56, column 45
	movl	-68(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,-72(%ebp) 
.Lab102:
.LN177:
	.stabn  68,0,57,.LN177-SACSET_LBIBMS		# line 57, column 14
	movl	-44(%ebp),%eax
	movl	%eax,-48(%ebp) 
.LN178:
	.stabn  68,0,58,.LN178-SACSET_LBIBMS		# line 58, column 11
	movl	-72(%ebp),%eax
	movl	%eax,-92(%ebp) 
	cmpl	$1,-92(%ebp)
	jl	.Lab105
	movl	$1,-28(%ebp) 
	movl	-92(%ebp),%eax
	movl	%eax,-96(%ebp) 
.Lab106:
.LN179:
	.stabn  68,0,58,.LN179-SACSET_LBIBMS		# line 58, column 34
	pushl	-48(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-48(%ebp) 
.LN180:
	.stabn  68,0,58,.LN180-SACSET_LBIBMS		# line 58, column 11
	movl	-28(%ebp),%eax
	cmpl	-96(%ebp),%eax
	jge	.Lab105
	incl	-28(%ebp) 
	jmp	.Lab106
.Lab105:
.LN181:
	.stabn  68,0,59,.LN181-SACSET_LBIBMS		# line 59, column 15
	pushl	-48(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-52(%ebp) 
.LN182:
	.stabn  68,0,59,.LN182-SACSET_LBIBMS		# line 59, column 27
	pushl	MASSTOR_s + 8
	pushl	-48(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN183:
	.stabn  68,0,59,.LN183-SACSET_LBIBMS		# line 59, column 42
	pushl	-44(%ebp)
	call	SACSET_LBIBS
	addl	$4, %esp
.LN184:
	.stabn  68,0,59,.LN184-SACSET_LBIBMS		# line 59, column 54
	pushl	-8(%ebp)
	pushl	-44(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN185:
	.stabn  68,0,60,.LN185-SACSET_LBIBMS		# line 60, column 13
	movl	-52(%ebp),%eax
	movl	%eax,-44(%ebp) 
.LN186:
	.stabn  68,0,55,.LN186-SACSET_LBIBMS		# line 55, column 7
	movl	-20(%ebp),%eax
	cmpl	-88(%ebp),%eax
	jge	.Lab100
	incl	-20(%ebp) 
	jmp	.Lab101
.Lab100:
.LN187:
	.stabn  68,0,62,.LN187-SACSET_LBIBMS		# line 62, column 7
	movl	-32(%ebp),%eax
	movl	%eax,-100(%ebp) 
	cmpl	$1,-100(%ebp)
	jl	.Lab107
	movl	$1,-20(%ebp) 
	movl	-100(%ebp),%eax
	movl	%eax,-104(%ebp) 
.Lab108:
.LN188:
	.stabn  68,0,62,.LN188-SACSET_LBIBMS		# line 62, column 27
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
.LN189:
	.stabn  68,0,62,.LN189-SACSET_LBIBMS		# line 62, column 37
	movl	-8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.Lab109:
.LN190:
	.stabn  68,0,63,.LN190-SACSET_LBIBMS		# line 63, column 18
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-40(%ebp),%eax
	pushl	%eax
	leal	-36(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	SACLIST_ADV2
	addl	$16, %esp
.LN191:
	.stabn  68,0,63,.LN191-SACSET_LBIBMS		# line 63, column 39
	pushl	-40(%ebp)
	pushl	-36(%ebp)
	call	SACSET_LBIM
	addl	$8, %esp
	movl	%eax,-36(%ebp) 
.LN192:
	.stabn  68,0,63,.LN192-SACSET_LBIBMS		# line 63, column 55
	pushl	-16(%ebp)
	pushl	-36(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN193:
	.stabn  68,0,64,.LN193-SACSET_LBIBMS		# line 64, column 27
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab109
.Lab110:
.LN194:
	.stabn  68,0,65,.LN194-SACSET_LBIBMS		# line 65, column 12
	movl	-16(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN195:
	.stabn  68,0,62,.LN195-SACSET_LBIBMS		# line 62, column 7
	movl	-20(%ebp),%eax
	cmpl	-104(%ebp),%eax
	jge	.Lab107
	incl	-20(%ebp) 
	jmp	.Lab108
.Lab107:
.LN196:
	.stabn  68,0,66,.LN196-SACSET_LBIBMS		# line 66, column 8
	pushl	-8(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-56(%ebp) 
.LN197:
	.stabn  68,0,66,.LN197-SACSET_LBIBMS		# line 66, column 20
	movl	-56(%ebp),%eax
	leave
	ret
.LN198:
	.stabn  68,0,67,.LN198-SACSET_LBIBMS		# line 67, column 0
	call	ReturnErr_
.LBE11:
	leave
	ret
	.Lab95 = 104
	.stabs "TL:7",128,0,4,-80
	.stabs "RL:7",128,0,4,-76
	.stabs "QLP:7",128,0,4,-72
	.stabs "QL:7",128,0,4,-68
	.stabs "NL:7",128,0,4,-64
	.stabs "ML:7",128,0,4,-60
	.stabs "M:7",128,0,4,-56
	.stabs "LPPP:7",128,0,4,-52
	.stabs "LPP:7",128,0,4,-48
	.stabs "LP:7",128,0,4,-44
	.stabs "L2:7",128,0,4,-40
	.stabs "L1:7",128,0,4,-36
	.stabs "KL:7",128,0,4,-32
	.stabs "JL:7",128,0,4,-28
	.stabs "J1Y:7",128,0,4,-24
	.stabs "IL:7",128,0,4,-20
	.stabs "C:7",128,0,4,-16
	.stabs "BP:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB11-SACSET_LBIBMS
	.stabn 224,0,0,.LBE11-SACSET_LBIBMS
	.stabs "SACSET:F16",36,0,0,SACSET
	.align 4
SACSET:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab111, %esp
.LN199:
	.stabn  68,0,232,.LN199-SACSET		# line 232, column 1
.LBB12:
.LN200:
	.stabn  68,0,233,.LN200-SACSET		# line 233, column 0
.LBE12:
	leave
	ret
	.Lab111 = 4
	.stabn 192,0,0,.LBB12-SACSET
	.stabn 224,0,0,.LBE12-SACSET
