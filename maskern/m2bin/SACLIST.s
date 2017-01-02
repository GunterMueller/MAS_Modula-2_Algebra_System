	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maskern/",100,0,0,.LBB0
	.stabs "SACLIST.mod",100,0,0,.LBB0
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
	.globl	MASBIOS_EStreamKind
	.globl	MASBIOS_OStreamKind
	.globl	MASBIOS_IStreamKind
	.globl	MASBIOS_TAB
	.globl	MASBIOS_SWRITE
	.globl	MASBIOS_StorSummary
	.globl	MASBIOS_Summary
	.globl	MASBIOS_SOUNIT
	.globl	MASBIOS_SOLINE
	.globl	MASBIOS_SIUNIT
	.globl	MASBIOS_SILINE
	.globl	MASBIOS_MASORDI
	.globl	MASBIOS_MASORD
	.globl	MASBIOS_MASCHR
	.globl	MASBIOS_SLIST
	.globl	MASBIOS_LISTS
	.globl	MASBIOS_LETTER
	.globl	MASBIOS_GWRITE
	.globl	MASBIOS_GREAD
	.globl	MASBIOS_DIGIT
	.globl	MASBIOS_DIBUFF
	.globl	MASBIOS_CUNIT
	.globl	MASBIOS_CloseBIOS
	.globl	MASBIOS_CWRITE
	.globl	MASBIOS_CREADB
	.globl	MASBIOS_CREAD
	.globl	MASBIOS_BLINES
	.globl	MASBIOS_BKSP
	.globl	MASELEM_MASSIGN
	.globl	MASELEM_MASREM
	.globl	MASELEM_MASQREM
	.globl	MASELEM_MASODD
	.globl	MASELEM_MASMIN
	.globl	MASELEM_MASMAX
	.globl	MASELEM_MASEXP
	.globl	MASELEM_MASEVEN
	.globl	MASELEM_MASABS
	.globl	SACLIST
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
	.stabs "SACLIST_THIRD:F7",36,0,0,SACLIST_THIRD
	.align 4
SACLIST_THIRD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,594,.LN1-SACLIST_THIRD		# line 594, column 1
.LBB1:
.LN2:
	.stabn  68,0,595,.LN2-SACLIST_THIRD		# line 595, column 10
	pushl	8(%ebp)
	call	SACLIST_RED2
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN3:
	.stabn  68,0,595,.LN3-SACLIST_THIRD		# line 595, column 23
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN4:
	.stabn  68,0,595,.LN4-SACLIST_THIRD		# line 595, column 37
	movl	-8(%ebp),%eax
	leave
	ret
.LN5:
	.stabn  68,0,596,.LN5-SACLIST_THIRD		# line 596, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACLIST_THIRD
	.stabn 224,0,0,.LBE1-SACLIST_THIRD
	.stabs "SACLIST_SUFFIX:F7",36,0,0,SACLIST_SUFFIX
	.align 4
SACLIST_SUFFIX:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab2, %esp
.LN6:
	.stabn  68,0,585,.LN6-SACLIST_SUFFIX		# line 585, column 1
.LBB2:
.LN7:
	.stabn  68,0,586,.LN7-SACLIST_SUFFIX		# line 586, column 10
	pushl	12(%ebp)
	call	MASSTOR_LIST1
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN8:
	.stabn  68,0,586,.LN8-SACLIST_SUFFIX		# line 586, column 25
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN9:
	.stabn  68,0,586,.LN9-SACLIST_SUFFIX		# line 586, column 40
	movl	-12(%ebp),%eax
	leave
	ret
.LN10:
	.stabn  68,0,587,.LN10-SACLIST_SUFFIX		# line 587, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab2 = 12
	.stabs "LP:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACLIST_SUFFIX
	.stabn 224,0,0,.LBE2-SACLIST_SUFFIX
	.stabs "SACLIST_SLELT:F16",36,0,0,SACLIST_SLELT
	.align 4
SACLIST_SLELT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab3, %esp
.LN11:
	.stabn  68,0,574,.LN11-SACLIST_SLELT		# line 574, column 1
.LBB3:
.LN12:
	.stabn  68,0,575,.LN12-SACLIST_SLELT		# line 575, column 9
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN13:
	.stabn  68,0,576,.LN13-SACLIST_SLELT		# line 576, column 7
	movl	12(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,-16(%ebp) 
	cmpl	$1,-16(%ebp)
	jl	.Lab4
	movl	$1,-12(%ebp) 
	movl	-16(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab5:
.LN14:
	.stabn  68,0,576,.LN14-SACLIST_SLELT		# line 576, column 30
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN15:
	.stabn  68,0,576,.LN15-SACLIST_SLELT		# line 576, column 7
	movl	-12(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jge	.Lab4
	incl	-12(%ebp) 
	jmp	.Lab5
.Lab4:
.LN16:
	.stabn  68,0,577,.LN16-SACLIST_SLELT		# line 577, column 7
	pushl	16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN17:
	.stabn  68,0,577,.LN17-SACLIST_SLELT		# line 577, column 22
	leave
	ret
.LN18:
	.stabn  68,0,578,.LN18-SACLIST_SLELT		# line 578, column 0
.LBE3:
	leave
	ret
	.Lab3 = 20
	.stabs "JL:7",128,0,4,-12
	.stabs "AP:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,16
	.stabs "IL:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-SACLIST_SLELT
	.stabn 224,0,0,.LBE3-SACLIST_SLELT
	.stabs "SACLIST_SECOND:F7",36,0,0,SACLIST_SECOND
	.align 4
SACLIST_SECOND:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab6, %esp
.LN19:
	.stabn  68,0,565,.LN19-SACLIST_SECOND		# line 565, column 1
.LBB4:
.LN20:
	.stabn  68,0,566,.LN20-SACLIST_SECOND		# line 566, column 10
	pushl	8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN21:
	.stabn  68,0,566,.LN21-SACLIST_SECOND		# line 566, column 22
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN22:
	.stabn  68,0,566,.LN22-SACLIST_SECOND		# line 566, column 36
	movl	-8(%ebp),%eax
	leave
	ret
.LN23:
	.stabn  68,0,567,.LN23-SACLIST_SECOND		# line 567, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab6 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACLIST_SECOND
	.stabn 224,0,0,.LBE4-SACLIST_SECOND
	.stabs "SACLIST_RED4:F7",36,0,0,SACLIST_RED4
	.align 4
SACLIST_RED4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab7, %esp
.LN24:
	.stabn  68,0,556,.LN24-SACLIST_RED4		# line 556, column 1
.LBB5:
.LN25:
	.stabn  68,0,557,.LN25-SACLIST_RED4		# line 557, column 10
	pushl	8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN26:
	.stabn  68,0,557,.LN26-SACLIST_RED4		# line 557, column 23
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN27:
	.stabn  68,0,557,.LN27-SACLIST_RED4		# line 557, column 38
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN28:
	.stabn  68,0,557,.LN28-SACLIST_RED4		# line 557, column 51
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN29:
	.stabn  68,0,557,.LN29-SACLIST_RED4		# line 557, column 63
	movl	-12(%ebp),%eax
	leave
	ret
.LN30:
	.stabn  68,0,558,.LN30-SACLIST_RED4		# line 558, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab7 = 12
	.stabs "M:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-SACLIST_RED4
	.stabn 224,0,0,.LBE5-SACLIST_RED4
	.stabs "SACLIST_RED3:F7",36,0,0,SACLIST_RED3
	.align 4
SACLIST_RED3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab8, %esp
.LN31:
	.stabn  68,0,547,.LN31-SACLIST_RED3		# line 547, column 1
.LBB6:
.LN32:
	.stabn  68,0,548,.LN32-SACLIST_RED3		# line 548, column 10
	pushl	8(%ebp)
	call	SACLIST_RED2
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN33:
	.stabn  68,0,548,.LN33-SACLIST_RED3		# line 548, column 22
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN34:
	.stabn  68,0,548,.LN34-SACLIST_RED3		# line 548, column 34
	movl	-12(%ebp),%eax
	leave
	ret
.LN35:
	.stabn  68,0,549,.LN35-SACLIST_RED3		# line 549, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab8 = 12
	.stabs "M:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-SACLIST_RED3
	.stabn 224,0,0,.LBE6-SACLIST_RED3
	.stabs "SACLIST_RED2:F7",36,0,0,SACLIST_RED2
	.align 4
SACLIST_RED2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN36:
	.stabn  68,0,538,.LN36-SACLIST_RED2		# line 538, column 1
.LBB7:
.LN37:
	.stabn  68,0,539,.LN37-SACLIST_RED2		# line 539, column 10
	pushl	8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN38:
	.stabn  68,0,539,.LN38-SACLIST_RED2		# line 539, column 22
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN39:
	.stabn  68,0,539,.LN39-SACLIST_RED2		# line 539, column 34
	movl	-12(%ebp),%eax
	leave
	ret
.LN40:
	.stabn  68,0,540,.LN40-SACLIST_RED2		# line 540, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab9 = 12
	.stabs "LP:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-SACLIST_RED2
	.stabn 224,0,0,.LBE7-SACLIST_RED2
	.stabs "SACLIST_REDUCT:F7",36,0,0,SACLIST_REDUCT
	.align 4
SACLIST_REDUCT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab10, %esp
.LN41:
	.stabn  68,0,528,.LN41-SACLIST_REDUCT		# line 528, column 1
.LBB8:
.LN42:
	.stabn  68,0,529,.LN42-SACLIST_REDUCT		# line 529, column 8
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN43:
	.stabn  68,0,530,.LN43-SACLIST_REDUCT		# line 530, column 7
	movl	12(%ebp),%eax
	movl	%eax,-16(%ebp) 
	cmpl	$1,-16(%ebp)
	jl	.Lab11
	movl	$1,-12(%ebp) 
	movl	-16(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab12:
.LN44:
	.stabn  68,0,530,.LN44-SACLIST_REDUCT		# line 530, column 27
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN45:
	.stabn  68,0,530,.LN45-SACLIST_REDUCT		# line 530, column 7
	movl	-12(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jge	.Lab11
	incl	-12(%ebp) 
	jmp	.Lab12
.Lab11:
.LN46:
	.stabn  68,0,531,.LN46-SACLIST_REDUCT		# line 531, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN47:
	.stabn  68,0,532,.LN47-SACLIST_REDUCT		# line 532, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab10 = 20
	.stabs "JL:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabs "IL:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-SACLIST_REDUCT
	.stabn 224,0,0,.LBE8-SACLIST_REDUCT
	.stabs "SACLIST_PAIR:F7",36,0,0,SACLIST_PAIR
	.align 4
SACLIST_PAIR:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab13, %esp
.LN48:
	.stabn  68,0,515,.LN48-SACLIST_PAIR		# line 515, column 1
.LBB9:
.LN49:
	.stabn  68,0,516,.LN49-SACLIST_PAIR		# line 516, column 9
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN50:
	.stabn  68,0,516,.LN50-SACLIST_PAIR		# line 516, column 16
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN51:
	.stabn  68,0,516,.LN51-SACLIST_PAIR		# line 516, column 22
	movl	MASSTOR_s,%eax
	movl	%eax,-24(%ebp) 
	jmp	.Lab14
.Lab15:
.LN52:
	.stabn  68,0,517,.LN52-SACLIST_PAIR		# line 517, column 44
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN53:
	.stabn  68,0,518,.LN53-SACLIST_PAIR		# line 518, column 13
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN54:
	.stabn  68,0,518,.LN54-SACLIST_PAIR		# line 518, column 29
	pushl	-24(%ebp)
	pushl	-8(%ebp)
	pushl	-16(%ebp)
	call	SACLIST_COMP2
	addl	$12, %esp
	movl	%eax,-24(%ebp) 
.Lab14:
.LN55:
	.stabn  68,0,517,.LN55-SACLIST_PAIR		# line 517, column 25
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab16
.Lab17:
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab15
.Lab16:
.LN56:
	.stabn  68,0,519,.LN56-SACLIST_PAIR		# line 519, column 8
	pushl	-24(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN57:
	.stabn  68,0,519,.LN57-SACLIST_PAIR		# line 519, column 18
	movl	-24(%ebp),%eax
	leave
	ret
.LN58:
	.stabn  68,0,520,.LN58-SACLIST_PAIR		# line 520, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab13 = 24
	.stabs "C:7",128,0,4,-24
	.stabs "BP:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "B:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-SACLIST_PAIR
	.stabn 224,0,0,.LBE9-SACLIST_PAIR
	.stabs "SACLIST_OWRITE:F16",36,0,0,SACLIST_OWRITE
	.align 4
SACLIST_OWRITE:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab18, %esp
.LN59:
	.stabn  68,0,504,.LN59-SACLIST_OWRITE		# line 504, column 1
.LBB10:
.LN60:
	.stabn  68,0,505,.LN60-SACLIST_OWRITE		# line 505, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab21
.Lab20:
.LN61:
	.stabn  68,0,505,.LN61-SACLIST_OWRITE		# line 505, column 24
	pushl	8(%ebp)
	call	SACLIST_AWRITE
	addl	$4, %esp
	jmp	.Lab19
.Lab21:
.LN62:
	.stabn  68,0,505,.LN62-SACLIST_OWRITE		# line 505, column 40
	pushl	8(%ebp)
	call	SACLIST_LWRITE
	addl	$4, %esp
.Lab19:
.LN63:
	.stabn  68,0,506,.LN63-SACLIST_OWRITE		# line 506, column 7
	leave
	ret
.LN64:
	.stabn  68,0,507,.LN64-SACLIST_OWRITE		# line 507, column 0
.LBE10:
	leave
	ret
	.Lab18 = 4
	.stabs "B:p7",160,0,4,8
	.stabn 192,0,0,.LBB10-SACLIST_OWRITE
	.stabn 224,0,0,.LBE10-SACLIST_OWRITE
	.stabs "SACLIST_OREAD:F7",36,0,0,SACLIST_OREAD
	.align 4
SACLIST_OREAD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab22, %esp
.LN65:
	.stabn  68,0,495,.LN65-SACLIST_OREAD		# line 495, column 1
.LBB11:
.LN66:
	.stabn  68,0,496,.LN66-SACLIST_OREAD		# line 496, column 31
	call	MASBIOS_CREADB
	movl	%eax,-12(%ebp) 
.LN67:
	.stabn  68,0,496,.LN67-SACLIST_OREAD		# line 496, column 43
	call	MASBIOS_BKSP
.LN68:
	.stabn  68,0,497,.LN68-SACLIST_OREAD		# line 497, column 7
	pushl	$40
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-12(%ebp)
	jne	.Lab25
.Lab24:
.LN69:
	.stabn  68,0,497,.LN69-SACLIST_OREAD		# line 497, column 32
	call	SACLIST_LREAD
	movl	%eax,-8(%ebp) 
	jmp	.Lab23
.Lab25:
.LN70:
	.stabn  68,0,497,.LN70-SACLIST_OREAD		# line 497, column 49
	call	SACLIST_AREAD
	movl	%eax,-8(%ebp) 
.Lab23:
.LN71:
	.stabn  68,0,498,.LN71-SACLIST_OREAD		# line 498, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN72:
	.stabn  68,0,499,.LN72-SACLIST_OREAD		# line 499, column 0
	call	ReturnErr_
.LBE11:
	leave
	ret
	.Lab22 = 16
	.stabs "IDUM:7",128,0,4,-16
	.stabs "C:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabn 192,0,0,.LBB11-SACLIST_OREAD
	.stabn 224,0,0,.LBE11-SACLIST_OREAD
	.stabs "SACLIST_ORDER:F7",36,0,0,SACLIST_ORDER
	.align 4
SACLIST_ORDER:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab26, %esp
.LN73:
	.stabn  68,0,481,.LN73-SACLIST_ORDER		# line 481, column 1
.LBB12:
.LN74:
	.stabn  68,0,482,.LN74-SACLIST_ORDER		# line 482, column 25
	movl	$0,-20(%ebp) 
.LN75:
	.stabn  68,0,483,.LN75-SACLIST_ORDER		# line 483, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab27
.Lab28:
.LN76:
	.stabn  68,0,483,.LN76-SACLIST_ORDER		# line 483, column 25
	movl	-20(%ebp),%eax
	leave
	ret
.Lab27:
.LN77:
	.stabn  68,0,484,.LN77-SACLIST_ORDER		# line 484, column 25
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab29
.Lab30:
.LN78:
	.stabn  68,0,485,.LN78-SACLIST_ORDER		# line 485, column 27
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN79:
	.stabn  68,0,485,.LN79-SACLIST_ORDER		# line 485, column 48
	pushl	-8(%ebp)
	call	SACLIST_ORDER
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN80:
	.stabn  68,0,486,.LN80-SACLIST_ORDER		# line 486, column 15
	pushl	-16(%ebp)
	pushl	-20(%ebp)
	call	MASELEM_MASMAX
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.Lab29:
.LN81:
	.stabn  68,0,485,.LN81-SACLIST_ORDER		# line 485, column 17
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab30
.Lab31:
.LN82:
	.stabn  68,0,487,.LN82-SACLIST_ORDER		# line 487, column 9
	incl	-20(%ebp)
.LN83:
	.stabn  68,0,487,.LN83-SACLIST_ORDER		# line 487, column 17
	movl	-20(%ebp),%eax
	leave
	ret
.LN84:
	.stabn  68,0,488,.LN84-SACLIST_ORDER		# line 488, column 0
	call	ReturnErr_
.LBE12:
	leave
	ret
	.Lab26 = 20
	.stabs "NL:7",128,0,4,-20
	.stabs "J1Y:7",128,0,4,-16
	.stabs "ALP:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB12-SACLIST_ORDER
	.stabn 224,0,0,.LBE12-SACLIST_ORDER
	.stabs "SACLIST_MEMBER:F7",36,0,0,SACLIST_MEMBER
	.align 4
SACLIST_MEMBER:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab32, %esp
.LN85:
	.stabn  68,0,469,.LN85-SACLIST_MEMBER		# line 469, column 1
.LBB13:
.LN86:
	.stabn  68,0,470,.LN86-SACLIST_MEMBER		# line 470, column 9
	movl	$0,-16(%ebp) 
.LN87:
	.stabn  68,0,470,.LN87-SACLIST_MEMBER		# line 470, column 16
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab33
.Lab34:
.LN88:
	.stabn  68,0,471,.LN88-SACLIST_MEMBER		# line 471, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN89:
	.stabn  68,0,471,.LN89-SACLIST_MEMBER		# line 471, column 44
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACLIST_EQUAL
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN90:
	.stabn  68,0,472,.LN90-SACLIST_MEMBER		# line 472, column 13
	cmpl	$1,-16(%ebp)
	jne	.Lab36
.Lab37:
.LN91:
	.stabn  68,0,472,.LN91-SACLIST_MEMBER		# line 472, column 28
	movl	-16(%ebp),%eax
	leave
	ret
.Lab36:
.Lab33:
.LN92:
	.stabn  68,0,471,.LN92-SACLIST_MEMBER		# line 471, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab34
.Lab35:
.LN93:
	.stabn  68,0,474,.LN93-SACLIST_MEMBER		# line 474, column 7
	movl	-16(%ebp),%eax
	leave
	ret
.LN94:
	.stabn  68,0,475,.LN94-SACLIST_MEMBER		# line 475, column 0
	call	ReturnErr_
.LBE13:
	leave
	ret
	.Lab32 = 16
	.stabs "TL:7",128,0,4,-16
	.stabs "LP:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "L:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB13-SACLIST_MEMBER
	.stabn 224,0,0,.LBE13-SACLIST_MEMBER
	.stabs "SACLIST_LWRITE:F16",36,0,0,SACLIST_LWRITE
	.align 4
SACLIST_LWRITE:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab38, %esp
.LN95:
	.stabn  68,0,454,.LN95-SACLIST_LWRITE		# line 454, column 1
.LBB14:
.LN96:
	.stabn  68,0,455,.LN96-SACLIST_LWRITE		# line 455, column 23
	.data
.Lab39:
 	.ascii	"(\000"
	.text
	pushl	$1
	leal	.Lab39,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN97:
	.stabn  68,0,455,.LN97-SACLIST_LWRITE		# line 455, column 38
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab40
.Lab41:
.LN98:
	.stabn  68,0,457,.LN98-SACLIST_LWRITE		# line 457, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN99:
	.stabn  68,0,458,.LN99-SACLIST_LWRITE		# line 458, column 13
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab45
.Lab44:
.LN100:
	.stabn  68,0,458,.LN100-SACLIST_LWRITE		# line 458, column 31
	pushl	-8(%ebp)
	call	SACLIST_AWRITE
	addl	$4, %esp
	jmp	.Lab43
.Lab45:
.LN101:
	.stabn  68,0,458,.LN101-SACLIST_LWRITE		# line 458, column 48
	pushl	-8(%ebp)
	call	SACLIST_LWRITE
	addl	$4, %esp
.Lab43:
.LN102:
	.stabn  68,0,459,.LN102-SACLIST_LWRITE		# line 459, column 13
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	je	.Lab46
.Lab47:
.LN103:
	.stabn  68,0,459,.LN103-SACLIST_LWRITE		# line 459, column 32
	.data
.Lab48:
 	.ascii	",\000"
	.text
	pushl	$1
	leal	.Lab48,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.Lab46:
.Lab40:
.LN104:
	.stabn  68,0,457,.LN104-SACLIST_LWRITE		# line 457, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab41
.Lab42:
.LN105:
	.stabn  68,0,461,.LN105-SACLIST_LWRITE		# line 461, column 19
	.data
.Lab49:
 	.ascii	")\000"
	.text
	pushl	$1
	leal	.Lab49,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN106:
	.stabn  68,0,461,.LN106-SACLIST_LWRITE		# line 461, column 32
	leave
	ret
.LN107:
	.stabn  68,0,462,.LN107-SACLIST_LWRITE		# line 462, column 0
.LBE14:
	leave
	ret
	.Lab38 = 12
	.stabs "LP:7",128,0,4,-12
	.stabs "L1:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB14-SACLIST_LWRITE
	.stabn 224,0,0,.LBE14-SACLIST_LWRITE
	.stabs "SACLIST_LSRCH:F7",36,0,0,SACLIST_LSRCH
	.align 4
SACLIST_LSRCH:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab50, %esp
.LN108:
	.stabn  68,0,442,.LN108-SACLIST_LSRCH		# line 442, column 1
.LBB15:
.LN109:
	.stabn  68,0,443,.LN109-SACLIST_LSRCH		# line 443, column 9
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN110:
	.stabn  68,0,443,.LN110-SACLIST_LSRCH		# line 443, column 16
	movl	$1,-16(%ebp) 
	jmp	.Lab51
.Lab52:
.LN111:
	.stabn  68,0,444,.LN111-SACLIST_LSRCH		# line 444, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN112:
	.stabn  68,0,445,.LN112-SACLIST_LSRCH		# line 445, column 13
	movl	8(%ebp),%eax
	cmpl	-8(%ebp),%eax
	jne	.Lab54
.Lab55:
.LN113:
	.stabn  68,0,445,.LN113-SACLIST_LSRCH		# line 445, column 30
	movl	-16(%ebp),%eax
	leave
	ret
.Lab54:
.LN114:
	.stabn  68,0,446,.LN114-SACLIST_LSRCH		# line 446, column 15
	incl	-16(%ebp)
.Lab51:
.LN115:
	.stabn  68,0,444,.LN115-SACLIST_LSRCH		# line 444, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab52
.Lab53:
.LN116:
	.stabn  68,0,447,.LN116-SACLIST_LSRCH		# line 447, column 9
	movl	$0,-16(%ebp) 
.LN117:
	.stabn  68,0,447,.LN117-SACLIST_LSRCH		# line 447, column 14
	movl	-16(%ebp),%eax
	leave
	ret
.LN118:
	.stabn  68,0,448,.LN118-SACLIST_LSRCH		# line 448, column 0
	call	ReturnErr_
.LBE15:
	leave
	ret
	.Lab50 = 16
	.stabs "IL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB15-SACLIST_LSRCH
	.stabn 224,0,0,.LBE15-SACLIST_LSRCH
	.stabs "SACLIST_LREAD:F7",36,0,0,SACLIST_LREAD
	.align 4
SACLIST_LREAD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab56, %esp
.LN119:
	.stabn  68,0,411,.LN119-SACLIST_LREAD		# line 411, column 1
.LBB16:
.LN120:
	.stabn  68,0,412,.LN120-SACLIST_LREAD		# line 412, column 32
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
.LN121:
	.stabn  68,0,412,.LN121-SACLIST_LREAD		# line 412, column 41
	call	MASBIOS_CREADB
	movl	%eax,-8(%ebp) 
.LN122:
	.stabn  68,0,413,.LN122-SACLIST_LREAD		# line 413, column 7
	pushl	$40
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	je	.Lab57
.Lab58:
.LN123:
	.stabn  68,0,414,.LN123-SACLIST_LREAD		# line 414, column 10
	.data
.Lab59:
 	.ascii	"ERROR FOUND BY LREAD.\000"
	.text
	pushl	$21
	leal	.Lab59,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN124:
	.stabn  68,0,414,.LN124-SACLIST_LREAD		# line 414, column 43
	call	MASBIOS_DIBUFF
.LN125:
	.stabn  68,0,415,.LN125-SACLIST_LREAD		# line 415, column 10
	movl	-16(%ebp),%eax
	leave
	ret
.Lab57:
.Lab60:
.LN126:
	.stabn  68,0,416,.LN126-SACLIST_LREAD		# line 416, column 13
	call	MASBIOS_CREADB
	movl	%eax,-8(%ebp) 
.LN127:
	.stabn  68,0,417,.LN127-SACLIST_LREAD		# line 417, column 12
	pushl	$41
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	jne	.Lab64
.Lab63:
.LN128:
	.stabn  68,0,417,.LN128-SACLIST_LREAD		# line 417, column 37
	pushl	-16(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN129:
	.stabn  68,0,417,.LN129-SACLIST_LREAD		# line 417, column 47
	movl	-16(%ebp),%eax
	leave
	ret
	jmp	.Lab62
.Lab64:
.LN130:
	.stabn  68,0,418,.LN130-SACLIST_LREAD		# line 418, column 15
	pushl	$40
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	jne	.Lab67
.Lab66:
.LN131:
	.stabn  68,0,418,.LN131-SACLIST_LREAD		# line 418, column 39
	call	MASBIOS_BKSP
.LN132:
	.stabn  68,0,418,.LN132-SACLIST_LREAD		# line 418, column 47
	call	SACLIST_LREAD
	movl	%eax,-20(%ebp) 
	jmp	.Lab65
.Lab67:
.LN133:
	.stabn  68,0,419,.LN133-SACLIST_LREAD		# line 419, column 18
	pushl	$43
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	je	.Lab69
.Lab72:
	pushl	$45
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	je	.Lab69
.Lab71:
	pushl	-8(%ebp)
	call	MASBIOS_DIGIT
	addl	$4, %esp
	cmpb	$0,%al
	je	.Lab70
.Lab69:
.LN134:
	.stabn  68,0,422,.LN134-SACLIST_LREAD		# line 422, column 26
	call	MASBIOS_BKSP
.LN135:
	.stabn  68,0,422,.LN135-SACLIST_LREAD		# line 422, column 34
	call	SACLIST_AREAD
	movl	%eax,-20(%ebp) 
	jmp	.Lab68
.Lab70:
.LN136:
	.stabn  68,0,423,.LN136-SACLIST_LREAD		# line 423, column 26
	.data
.Lab73:
 	.ascii	"ERROR FOUND BY LREAD.\000"
	.text
	pushl	$21
	leal	.Lab73,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN137:
	.stabn  68,0,423,.LN137-SACLIST_LREAD		# line 423, column 59
	call	MASBIOS_DIBUFF
.LN138:
	.stabn  68,0,424,.LN138-SACLIST_LREAD		# line 424, column 27
	pushl	-16(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN139:
	.stabn  68,0,424,.LN139-SACLIST_LREAD		# line 424, column 37
	movl	-16(%ebp),%eax
	leave
	ret
.Lab68:
.Lab65:
.Lab62:
.LN140:
	.stabn  68,0,427,.LN140-SACLIST_LREAD		# line 427, column 13
	pushl	-16(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN141:
	.stabn  68,0,427,.LN141-SACLIST_LREAD		# line 427, column 28
	call	MASBIOS_CREADB
	movl	%eax,-8(%ebp) 
.LN142:
	.stabn  68,0,428,.LN142-SACLIST_LREAD		# line 428, column 12
	pushl	$41
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	jne	.Lab76
.Lab75:
.LN143:
	.stabn  68,0,428,.LN143-SACLIST_LREAD		# line 428, column 36
	call	MASBIOS_BKSP
	jmp	.Lab74
.Lab76:
.LN144:
	.stabn  68,0,429,.LN144-SACLIST_LREAD		# line 429, column 15
	pushl	$44
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-8(%ebp)
	je	.Lab77
.Lab78:
.LN145:
	.stabn  68,0,430,.LN145-SACLIST_LREAD		# line 430, column 18
	.data
.Lab79:
 	.ascii	"ERROR FOUND BY LREAD.\000"
	.text
	pushl	$21
	leal	.Lab79,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN146:
	.stabn  68,0,430,.LN146-SACLIST_LREAD		# line 430, column 51
	call	MASBIOS_DIBUFF
.LN147:
	.stabn  68,0,431,.LN147-SACLIST_LREAD		# line 431, column 19
	pushl	-16(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN148:
	.stabn  68,0,431,.LN148-SACLIST_LREAD		# line 431, column 29
	movl	-16(%ebp),%eax
	leave
	ret
.Lab77:
.Lab74:
	jmp	.Lab60
.Lab61:
.LN149:
	.stabn  68,0,432,.LN149-SACLIST_LREAD		# line 432, column 0
	call	ReturnErr_
.LBE16:
	leave
	ret
	.Lab56 = 20
	.stabs "L1:7",128,0,4,-20
	.stabs "L:7",128,0,4,-16
	.stabs "IDUM:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabn 192,0,0,.LBB16-SACLIST_LREAD
	.stabn 224,0,0,.LBE16-SACLIST_LREAD
	.stabs "SACLIST_LIST5:F7",36,0,0,SACLIST_LIST5
	.align 4
SACLIST_LIST5:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab80, %esp
.LN150:
	.stabn  68,0,401,.LN150-SACLIST_LIST5		# line 401, column 1
.LBB17:
.LN151:
	.stabn  68,0,402,.LN151-SACLIST_LIST5		# line 402, column 10
	pushl	MASSTOR_s
	pushl	24(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN152:
	.stabn  68,0,402,.LN152-SACLIST_LIST5		# line 402, column 31
	pushl	-8(%ebp)
	pushl	20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN153:
	.stabn  68,0,402,.LN153-SACLIST_LIST5		# line 402, column 51
	pushl	-8(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN154:
	.stabn  68,0,403,.LN154-SACLIST_LIST5		# line 403, column 10
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN155:
	.stabn  68,0,403,.LN155-SACLIST_LIST5		# line 403, column 28
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN156:
	.stabn  68,0,403,.LN156-SACLIST_LIST5		# line 403, column 45
	movl	-12(%ebp),%eax
	leave
	ret
.LN157:
	.stabn  68,0,404,.LN157-SACLIST_LIST5		# line 404, column 0
	call	ReturnErr_
.LBE17:
	leave
	ret
	.Lab80 = 12
	.stabs "L:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "AL5:p7",160,0,4,24
	.stabs "AL4:p7",160,0,4,20
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB17-SACLIST_LIST5
	.stabn 224,0,0,.LBE17-SACLIST_LIST5
	.stabs "SACLIST_LIST4:F7",36,0,0,SACLIST_LIST4
	.align 4
SACLIST_LIST4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab81, %esp
.LN158:
	.stabn  68,0,391,.LN158-SACLIST_LIST4		# line 391, column 1
.LBB18:
.LN159:
	.stabn  68,0,392,.LN159-SACLIST_LIST4		# line 392, column 10
	pushl	MASSTOR_s
	pushl	20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN160:
	.stabn  68,0,392,.LN160-SACLIST_LIST4		# line 392, column 31
	pushl	-8(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN161:
	.stabn  68,0,392,.LN161-SACLIST_LIST4		# line 392, column 51
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN162:
	.stabn  68,0,393,.LN162-SACLIST_LIST4		# line 393, column 8
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN163:
	.stabn  68,0,393,.LN163-SACLIST_LIST4		# line 393, column 25
	movl	-12(%ebp),%eax
	leave
	ret
.LN164:
	.stabn  68,0,394,.LN164-SACLIST_LIST4		# line 394, column 0
	call	ReturnErr_
.LBE18:
	leave
	ret
	.Lab81 = 12
	.stabs "L:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "AL4:p7",160,0,4,20
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB18-SACLIST_LIST4
	.stabn 224,0,0,.LBE18-SACLIST_LIST4
	.stabs "SACLIST_LIST3:F7",36,0,0,SACLIST_LIST3
	.align 4
SACLIST_LIST3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab82, %esp
.LN165:
	.stabn  68,0,381,.LN165-SACLIST_LIST3		# line 381, column 1
.LBB19:
.LN166:
	.stabn  68,0,382,.LN166-SACLIST_LIST3		# line 382, column 10
	pushl	MASSTOR_s
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN167:
	.stabn  68,0,382,.LN167-SACLIST_LIST3		# line 382, column 31
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN168:
	.stabn  68,0,382,.LN168-SACLIST_LIST3		# line 382, column 49
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN169:
	.stabn  68,0,383,.LN169-SACLIST_LIST3		# line 383, column 7
	movl	-12(%ebp),%eax
	leave
	ret
.LN170:
	.stabn  68,0,384,.LN170-SACLIST_LIST3		# line 384, column 0
	call	ReturnErr_
.LBE19:
	leave
	ret
	.Lab82 = 12
	.stabs "L:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB19-SACLIST_LIST3
	.stabn 224,0,0,.LBE19-SACLIST_LIST3
	.stabs "SACLIST_LIST2:F7",36,0,0,SACLIST_LIST2
	.align 4
SACLIST_LIST2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab83, %esp
.LN171:
	.stabn  68,0,373,.LN171-SACLIST_LIST2		# line 373, column 1
.LBB20:
.LN172:
	.stabn  68,0,374,.LN172-SACLIST_LIST2		# line 374, column 10
	pushl	MASSTOR_s
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN173:
	.stabn  68,0,374,.LN173-SACLIST_LIST2		# line 374, column 28
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN174:
	.stabn  68,0,374,.LN174-SACLIST_LIST2		# line 374, column 44
	movl	-12(%ebp),%eax
	leave
	ret
.LN175:
	.stabn  68,0,375,.LN175-SACLIST_LIST2		# line 375, column 0
	call	ReturnErr_
.LBE20:
	leave
	ret
	.Lab83 = 12
	.stabs "L:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB20-SACLIST_LIST2
	.stabn 224,0,0,.LBE20-SACLIST_LIST2
	.stabs "SACLIST_LIST10:F7",36,0,0,SACLIST_LIST10
	.align 4
SACLIST_LIST10:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab84, %esp
.LN176:
	.stabn  68,0,362,.LN176-SACLIST_LIST10		# line 362, column 1
.LBB21:
.LN177:
	.stabn  68,0,363,.LN177-SACLIST_LIST10		# line 363, column 10
	pushl	MASSTOR_s
	pushl	44(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN178:
	.stabn  68,0,363,.LN178-SACLIST_LIST10		# line 363, column 32
	pushl	-8(%ebp)
	pushl	40(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN179:
	.stabn  68,0,363,.LN179-SACLIST_LIST10		# line 363, column 52
	pushl	-8(%ebp)
	pushl	36(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN180:
	.stabn  68,0,364,.LN180-SACLIST_LIST10		# line 364, column 10
	pushl	-8(%ebp)
	pushl	32(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN181:
	.stabn  68,0,364,.LN181-SACLIST_LIST10		# line 364, column 30
	pushl	-8(%ebp)
	pushl	28(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN182:
	.stabn  68,0,364,.LN182-SACLIST_LIST10		# line 364, column 50
	pushl	-8(%ebp)
	pushl	24(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN183:
	.stabn  68,0,365,.LN183-SACLIST_LIST10		# line 365, column 10
	pushl	-8(%ebp)
	pushl	20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN184:
	.stabn  68,0,365,.LN184-SACLIST_LIST10		# line 365, column 30
	pushl	-8(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN185:
	.stabn  68,0,365,.LN185-SACLIST_LIST10		# line 365, column 50
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN186:
	.stabn  68,0,366,.LN186-SACLIST_LIST10		# line 366, column 8
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN187:
	.stabn  68,0,366,.LN187-SACLIST_LIST10		# line 366, column 25
	movl	-12(%ebp),%eax
	leave
	ret
.LN188:
	.stabn  68,0,367,.LN188-SACLIST_LIST10		# line 367, column 0
	call	ReturnErr_
.LBE21:
	leave
	ret
	.Lab84 = 12
	.stabs "L:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "AL10:p7",160,0,4,44
	.stabs "AL9:p7",160,0,4,40
	.stabs "AL8:p7",160,0,4,36
	.stabs "AL7:p7",160,0,4,32
	.stabs "AL6:p7",160,0,4,28
	.stabs "AL5:p7",160,0,4,24
	.stabs "AL4:p7",160,0,4,20
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB21-SACLIST_LIST10
	.stabn 224,0,0,.LBE21-SACLIST_LIST10
	.stabs "SACLIST_LINSRT:F7",36,0,0,SACLIST_LINSRT
	.align 4
SACLIST_LINSRT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab85, %esp
.LN189:
	.stabn  68,0,346,.LN189-SACLIST_LINSRT		# line 346, column 1
.LBB22:
.LN190:
	.stabn  68,0,348,.LN190-SACLIST_LINSRT		# line 348, column 7
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab86
.Lab87:
.LN191:
	.stabn  68,0,348,.LN191-SACLIST_LINSRT		# line 348, column 24
	pushl	8(%ebp)
	call	MASSTOR_LIST1
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN192:
	.stabn  68,0,348,.LN192-SACLIST_LINSRT		# line 348, column 37
	movl	-20(%ebp),%eax
	leave
	ret
.Lab86:
.LN193:
	.stabn  68,0,350,.LN193-SACLIST_LINSRT		# line 350, column 7
	pushl	12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	cmpl	%eax,8(%ebp)
	jge	.Lab88
.Lab89:
.LN194:
	.stabn  68,0,350,.LN194-SACLIST_LINSRT		# line 350, column 30
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN195:
	.stabn  68,0,350,.LN195-SACLIST_LINSRT		# line 350, column 44
	movl	-20(%ebp),%eax
	leave
	ret
.Lab88:
.LN196:
	.stabn  68,0,351,.LN196-SACLIST_LINSRT		# line 351, column 27
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN197:
	.stabn  68,0,351,.LN197-SACLIST_LINSRT		# line 351, column 35
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab90
.Lab91:
.LN198:
	.stabn  68,0,352,.LN198-SACLIST_LINSRT		# line 352, column 54
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN199:
	.stabn  68,0,353,.LN199-SACLIST_LINSRT		# line 353, column 16
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.Lab90:
.LN200:
	.stabn  68,0,352,.LN200-SACLIST_LINSRT		# line 352, column 26
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab92
.Lab93:
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	cmpl	%eax,8(%ebp)
	jge	.Lab91
.Lab92:
.LN201:
	.stabn  68,0,354,.LN201-SACLIST_LINSRT		# line 354, column 9
	pushl	-12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN202:
	.stabn  68,0,354,.LN202-SACLIST_LINSRT		# line 354, column 25
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN203:
	.stabn  68,0,354,.LN203-SACLIST_LINSRT		# line 354, column 39
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN204:
	.stabn  68,0,354,.LN204-SACLIST_LINSRT		# line 354, column 44
	movl	-20(%ebp),%eax
	leave
	ret
.LN205:
	.stabn  68,0,355,.LN205-SACLIST_LINSRT		# line 355, column 0
	call	ReturnErr_
.LBE22:
	leave
	ret
	.Lab85 = 20
	.stabs "B:7",128,0,4,-20
	.stabs "AS:7",128,0,4,-16
	.stabs "APP:7",128,0,4,-12
	.stabs "AP:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB22-SACLIST_LINSRT
	.stabn 224,0,0,.LBE22-SACLIST_LINSRT
	.stabs "SACLIST_LINS:F16",36,0,0,SACLIST_LINS
	.align 4
SACLIST_LINS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab94, %esp
.LN206:
	.stabn  68,0,333,.LN206-SACLIST_LINS		# line 333, column 1
.LBB23:
.LN207:
	.stabn  68,0,334,.LN207-SACLIST_LINS		# line 334, column 10
	pushl	12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN208:
	.stabn  68,0,334,.LN208-SACLIST_LINS		# line 334, column 21
	pushl	-12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN209:
	.stabn  68,0,334,.LN209-SACLIST_LINS		# line 334, column 37
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN210:
	.stabn  68,0,334,.LN210-SACLIST_LINS		# line 334, column 48
	leave
	ret
.LN211:
	.stabn  68,0,335,.LN211-SACLIST_LINS		# line 335, column 0
.LBE23:
	leave
	ret
	.Lab94 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "A:7",128,0,4,-8
	.stabs "L:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB23-SACLIST_LINS
	.stabn 224,0,0,.LBE23-SACLIST_LINS
	.stabs "SACLIST_LEROT:F7",36,0,0,SACLIST_LEROT
	.align 4
SACLIST_LEROT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab95, %esp
.LN212:
	.stabn  68,0,316,.LN212-SACLIST_LEROT		# line 316, column 1
.LBB24:
.LN213:
	.stabn  68,0,317,.LN213-SACLIST_LEROT		# line 317, column 19
	movl	8(%ebp),%eax
	movl	%eax,-28(%ebp) 
.LN214:
	.stabn  68,0,318,.LN214-SACLIST_LEROT		# line 318, column 7
	movl	12(%ebp),%eax
	cmpl	16(%ebp),%eax
	jne	.Lab96
.Lab97:
.LN215:
	.stabn  68,0,318,.LN215-SACLIST_LEROT		# line 318, column 23
	movl	-28(%ebp),%eax
	leave
	ret
.Lab96:
.LN216:
	.stabn  68,0,319,.LN216-SACLIST_LEROT		# line 319, column 23
	movl	8(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN217:
	.stabn  68,0,320,.LN217-SACLIST_LEROT		# line 320, column 7
	movl	12(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,-32(%ebp) 
	cmpl	$1,-32(%ebp)
	jl	.Lab98
	movl	$1,-16(%ebp) 
	movl	-32(%ebp),%eax
	movl	%eax,-36(%ebp) 
.Lab99:
.LN218:
	.stabn  68,0,320,.LN218-SACLIST_LEROT		# line 320, column 30
	pushl	-20(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN219:
	.stabn  68,0,320,.LN219-SACLIST_LEROT		# line 320, column 7
	movl	-16(%ebp),%eax
	cmpl	-36(%ebp),%eax
	jge	.Lab98
	incl	-16(%ebp) 
	jmp	.Lab99
.Lab98:
.LN220:
	.stabn  68,0,321,.LN220-SACLIST_LEROT		# line 321, column 7
	leal	-24(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN221:
	.stabn  68,0,322,.LN221-SACLIST_LEROT		# line 322, column 7
	movl	12(%ebp),%eax
	movl	%eax,-40(%ebp) 
	movl	16(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,-44(%ebp) 
	movl	-40(%ebp),%eax
	cmpl	-44(%ebp),%eax
	jg	.Lab100
	movl	-40(%ebp),%eax
	movl	%eax,-16(%ebp) 
	movl	-44(%ebp),%eax
	movl	%eax,-48(%ebp) 
.Lab101:
.LN222:
	.stabn  68,0,322,.LN222-SACLIST_LEROT		# line 322, column 31
	pushl	-24(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN223:
	.stabn  68,0,322,.LN223-SACLIST_LEROT		# line 322, column 45
	pushl	-8(%ebp)
	pushl	-24(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN224:
	.stabn  68,0,322,.LN224-SACLIST_LEROT		# line 322, column 63
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN225:
	.stabn  68,0,323,.LN225-SACLIST_LEROT		# line 323, column 14
	pushl	-24(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN226:
	.stabn  68,0,322,.LN226-SACLIST_LEROT		# line 322, column 7
	movl	-16(%ebp),%eax
	cmpl	-48(%ebp),%eax
	jge	.Lab100
	incl	-16(%ebp) 
	jmp	.Lab101
.Lab100:
.LN227:
	.stabn  68,0,324,.LN227-SACLIST_LEROT		# line 324, column 7
	pushl	-8(%ebp)
	pushl	-20(%ebp)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN228:
	.stabn  68,0,324,.LN228-SACLIST_LEROT		# line 324, column 22
	movl	-28(%ebp),%eax
	leave
	ret
.LN229:
	.stabn  68,0,325,.LN229-SACLIST_LEROT		# line 325, column 0
	call	ReturnErr_
.LBE24:
	leave
	ret
	.Lab95 = 48
	.stabs "M:7",128,0,4,-28
	.stabs "LPP:7",128,0,4,-24
	.stabs "LP:7",128,0,4,-20
	.stabs "KL:7",128,0,4,-16
	.stabs "BL:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "JL:p7",160,0,4,16
	.stabs "IL:p7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB24-SACLIST_LEROT
	.stabn 224,0,0,.LBE24-SACLIST_LEROT
	.stabs "SACLIST_LELT:F7",36,0,0,SACLIST_LELT
	.align 4
SACLIST_LELT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab102, %esp
.LN230:
	.stabn  68,0,303,.LN230-SACLIST_LELT		# line 303, column 1
.LBB25:
.LN231:
	.stabn  68,0,304,.LN231-SACLIST_LELT		# line 304, column 9
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN232:
	.stabn  68,0,305,.LN232-SACLIST_LELT		# line 305, column 7
	movl	12(%ebp),%eax
 	subl	$1,%eax 
	movl	%eax,-20(%ebp) 
	cmpl	$1,-20(%ebp)
	jl	.Lab103
	movl	$1,-16(%ebp) 
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
.Lab104:
.LN233:
	.stabn  68,0,305,.LN233-SACLIST_LELT		# line 305, column 30
	pushl	-12(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN234:
	.stabn  68,0,305,.LN234-SACLIST_LELT		# line 305, column 7
	movl	-16(%ebp),%eax
	cmpl	-24(%ebp),%eax
	jge	.Lab103
	incl	-16(%ebp) 
	jmp	.Lab104
.Lab103:
.LN235:
	.stabn  68,0,306,.LN235-SACLIST_LELT		# line 306, column 9
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN236:
	.stabn  68,0,306,.LN236-SACLIST_LELT		# line 306, column 22
	movl	-8(%ebp),%eax
	leave
	ret
.LN237:
	.stabn  68,0,307,.LN237-SACLIST_LELT		# line 307, column 0
	call	ReturnErr_
.LBE25:
	leave
	ret
	.Lab102 = 24
	.stabs "JL:7",128,0,4,-16
	.stabs "AP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "IL:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB25-SACLIST_LELT
	.stabn 224,0,0,.LBE25-SACLIST_LELT
	.stabs "SACLIST_LEINST:F7",36,0,0,SACLIST_LEINST
	.align 4
SACLIST_LEINST:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab105, %esp
.LN238:
	.stabn  68,0,290,.LN238-SACLIST_LEINST		# line 290, column 1
.LBB26:
.LN239:
	.stabn  68,0,292,.LN239-SACLIST_LEINST		# line 292, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab106
.Lab107:
.LN240:
	.stabn  68,0,292,.LN240-SACLIST_LEINST		# line 292, column 23
	pushl	8(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.LN241:
	.stabn  68,0,292,.LN241-SACLIST_LEINST		# line 292, column 37
	movl	-20(%ebp),%eax
	leave
	ret
.Lab106:
.LN242:
	.stabn  68,0,293,.LN242-SACLIST_LEINST		# line 293, column 21
	movl	8(%ebp),%eax
	movl	%eax,-20(%ebp) 
.LN243:
	.stabn  68,0,293,.LN243-SACLIST_LEINST		# line 293, column 28
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN244:
	.stabn  68,0,294,.LN244-SACLIST_LEINST		# line 294, column 7
	movl	12(%ebp),%eax
	movl	%eax,-24(%ebp) 
	cmpl	$2,-24(%ebp)
	jl	.Lab108
	movl	$2,-16(%ebp) 
	movl	-24(%ebp),%eax
	movl	%eax,-28(%ebp) 
.Lab109:
.LN245:
	.stabn  68,0,294,.LN245-SACLIST_LEINST		# line 294, column 28
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN246:
	.stabn  68,0,294,.LN246-SACLIST_LEINST		# line 294, column 7
	movl	-16(%ebp),%eax
	cmpl	-28(%ebp),%eax
	jge	.Lab108
	incl	-16(%ebp) 
	jmp	.Lab109
.Lab108:
.LN247:
	.stabn  68,0,295,.LN247-SACLIST_LEINST		# line 295, column 10
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN248:
	.stabn  68,0,295,.LN248-SACLIST_LEINST		# line 295, column 24
	pushl	-12(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN249:
	.stabn  68,0,295,.LN249-SACLIST_LEINST		# line 295, column 40
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN250:
	.stabn  68,0,295,.LN250-SACLIST_LEINST		# line 295, column 54
	movl	-20(%ebp),%eax
	leave
	ret
.LN251:
	.stabn  68,0,296,.LN251-SACLIST_LEINST		# line 296, column 0
	call	ReturnErr_
.LBE26:
	leave
	ret
	.Lab105 = 28
	.stabs "L:7",128,0,4,-20
	.stabs "JL:7",128,0,4,-16
	.stabs "APP:7",128,0,4,-12
	.stabs "AP:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,16
	.stabs "IL:p7",160,0,4,12
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB26-SACLIST_LEINST
	.stabn 224,0,0,.LBE26-SACLIST_LEINST
	.stabs "SACLIST_LAST:F7",36,0,0,SACLIST_LAST
	.align 4
SACLIST_LAST:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab110, %esp
.LN252:
	.stabn  68,0,277,.LN252-SACLIST_LAST		# line 277, column 1
.LBB27:
.LN253:
	.stabn  68,0,278,.LN253-SACLIST_LAST		# line 278, column 9
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN254:
	.stabn  68,0,278,.LN254-SACLIST_LAST		# line 278, column 17
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab111
.Lab112:
.LN255:
	.stabn  68,0,279,.LN255-SACLIST_LAST		# line 279, column 29
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN256:
	.stabn  68,0,279,.LN256-SACLIST_LAST		# line 279, column 39
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.Lab111:
.LN257:
	.stabn  68,0,279,.LN257-SACLIST_LAST		# line 279, column 17
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab112
.Lab113:
.LN258:
	.stabn  68,0,280,.LN258-SACLIST_LAST		# line 280, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN259:
	.stabn  68,0,281,.LN259-SACLIST_LAST		# line 281, column 0
	call	ReturnErr_
.LBE27:
	leave
	ret
	.Lab110 = 12
	.stabs "LPP:7",128,0,4,-12
	.stabs "LP:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB27-SACLIST_LAST
	.stabn 224,0,0,.LBE27-SACLIST_LAST
	.stabs "SACLIST_FOURTH:F7",36,0,0,SACLIST_FOURTH
	.align 4
SACLIST_FOURTH:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab114, %esp
.LN260:
	.stabn  68,0,268,.LN260-SACLIST_FOURTH		# line 268, column 1
.LBB28:
.LN261:
	.stabn  68,0,269,.LN261-SACLIST_FOURTH		# line 269, column 10
	pushl	8(%ebp)
	call	SACLIST_RED3
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN262:
	.stabn  68,0,269,.LN262-SACLIST_FOURTH		# line 269, column 23
	pushl	-12(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN263:
	.stabn  68,0,269,.LN263-SACLIST_FOURTH		# line 269, column 37
	movl	-8(%ebp),%eax
	leave
	ret
.LN264:
	.stabn  68,0,270,.LN264-SACLIST_FOURTH		# line 270, column 0
	call	ReturnErr_
.LBE28:
	leave
	ret
	.Lab114 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB28-SACLIST_FOURTH
	.stabn 224,0,0,.LBE28-SACLIST_FOURTH
	.stabs "SACLIST_FIRST4:F16",36,0,0,SACLIST_FIRST4
	.align 4
SACLIST_FIRST4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab115, %esp
.LN265:
	.stabn  68,0,258,.LN265-SACLIST_FIRST4		# line 258, column 1
.LBB29:
.LN266:
	.stabn  68,0,259,.LN266-SACLIST_FIRST4		# line 259, column 7
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN267:
	.stabn  68,0,259,.LN267-SACLIST_FIRST4		# line 259, column 22
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN268:
	.stabn  68,0,259,.LN268-SACLIST_FIRST4		# line 259, column 38
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	20(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN269:
	.stabn  68,0,259,.LN269-SACLIST_FIRST4		# line 259, column 57
	movl	24(%ebp),%eax
	pushl	%eax
	pushl	-8(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN270:
	.stabn  68,0,260,.LN270-SACLIST_FIRST4		# line 260, column 7
	leave
	ret
.LN271:
	.stabn  68,0,261,.LN271-SACLIST_FIRST4		# line 261, column 0
.LBE29:
	leave
	ret
	.Lab115 = 8
	.stabs "LP:7",128,0,4,-8
	.stabs "AL4:v7",160,0,4,24
	.stabs "AL3:v7",160,0,4,20
	.stabs "AL2:v7",160,0,4,16
	.stabs "AL1:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB29-SACLIST_FIRST4
	.stabn 224,0,0,.LBE29-SACLIST_FIRST4
	.stabs "SACLIST_FIRST3:F16",36,0,0,SACLIST_FIRST3
	.align 4
SACLIST_FIRST3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab116, %esp
.LN272:
	.stabn  68,0,249,.LN272-SACLIST_FIRST3		# line 249, column 1
.LBB30:
.LN273:
	.stabn  68,0,250,.LN273-SACLIST_FIRST3		# line 250, column 7
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACLIST_ADV2
	addl	$16, %esp
.LN274:
	.stabn  68,0,250,.LN274-SACLIST_FIRST3		# line 250, column 30
	movl	20(%ebp),%eax
	pushl	%eax
	pushl	-8(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN275:
	.stabn  68,0,250,.LN275-SACLIST_FIRST3		# line 250, column 43
	leave
	ret
.LN276:
	.stabn  68,0,251,.LN276-SACLIST_FIRST3		# line 251, column 0
.LBE30:
	leave
	ret
	.Lab116 = 8
	.stabs "LP:7",128,0,4,-8
	.stabs "AL3:v7",160,0,4,20
	.stabs "AL2:v7",160,0,4,16
	.stabs "AL1:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB30-SACLIST_FIRST3
	.stabn 224,0,0,.LBE30-SACLIST_FIRST3
	.stabs "SACLIST_FIRST2:F16",36,0,0,SACLIST_FIRST2
	.align 4
SACLIST_FIRST2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab117, %esp
.LN277:
	.stabn  68,0,240,.LN277-SACLIST_FIRST2		# line 240, column 1
.LBB31:
.LN278:
	.stabn  68,0,241,.LN278-SACLIST_FIRST2		# line 241, column 7
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN279:
	.stabn  68,0,241,.LN279-SACLIST_FIRST2		# line 241, column 23
	movl	16(%ebp),%eax
	pushl	%eax
	pushl	-8(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN280:
	.stabn  68,0,241,.LN280-SACLIST_FIRST2		# line 241, column 36
	leave
	ret
.LN281:
	.stabn  68,0,242,.LN281-SACLIST_FIRST2		# line 242, column 0
.LBE31:
	leave
	ret
	.Lab117 = 8
	.stabs "LP:7",128,0,4,-8
	.stabs "BL:v7",160,0,4,16
	.stabs "AL:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB31-SACLIST_FIRST2
	.stabn 224,0,0,.LBE31-SACLIST_FIRST2
	.stabs "SACLIST_EXTENT:F7",36,0,0,SACLIST_EXTENT
	.align 4
SACLIST_EXTENT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab118, %esp
.LN282:
	.stabn  68,0,226,.LN282-SACLIST_EXTENT		# line 226, column 1
.LBB32:
.LN283:
	.stabn  68,0,227,.LN283-SACLIST_EXTENT		# line 227, column 25
	movl	$0,-20(%ebp) 
.LN284:
	.stabn  68,0,228,.LN284-SACLIST_EXTENT		# line 228, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab119
.Lab120:
.LN285:
	.stabn  68,0,228,.LN285-SACLIST_EXTENT		# line 228, column 25
	movl	-20(%ebp),%eax
	leave
	ret
.Lab119:
.LN286:
	.stabn  68,0,229,.LN286-SACLIST_EXTENT		# line 229, column 25
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab121
.Lab122:
.LN287:
	.stabn  68,0,230,.LN287-SACLIST_EXTENT		# line 230, column 27
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN288:
	.stabn  68,0,230,.LN288-SACLIST_EXTENT		# line 230, column 48
	pushl	-8(%ebp)
	call	SACLIST_EXTENT
	addl	$4, %esp
	movl	%eax,-16(%ebp) 
.LN289:
	.stabn  68,0,231,.LN289-SACLIST_EXTENT		# line 231, column 16
	movl	-16(%ebp),%eax
 	addl	-20(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN290:
	.stabn  68,0,231,.LN290-SACLIST_EXTENT		# line 231, column 28
	movl	$1,%eax
 	addl	-16(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.Lab121:
.LN291:
	.stabn  68,0,230,.LN291-SACLIST_EXTENT		# line 230, column 17
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab122
.Lab123:
.LN292:
	.stabn  68,0,232,.LN292-SACLIST_EXTENT		# line 232, column 7
	movl	-20(%ebp),%eax
	leave
	ret
.LN293:
	.stabn  68,0,233,.LN293-SACLIST_EXTENT		# line 233, column 0
	call	ReturnErr_
.LBE32:
	leave
	ret
	.Lab118 = 20
	.stabs "NL:7",128,0,4,-20
	.stabs "J1Y:7",128,0,4,-16
	.stabs "ALP:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB32-SACLIST_EXTENT
	.stabn 224,0,0,.LBE32-SACLIST_EXTENT
	.stabs "SACLIST_EQUAL:F7",36,0,0,SACLIST_EQUAL
	.align 4
SACLIST_EQUAL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab124, %esp
.LN294:
	.stabn  68,0,208,.LN294-SACLIST_EQUAL		# line 208, column 1
.LBB33:
.LN295:
	.stabn  68,0,209,.LN295-SACLIST_EQUAL		# line 209, column 54
	movl	$0,-24(%ebp) 
.LN296:
	.stabn  68,0,210,.LN296-SACLIST_EQUAL		# line 210, column 7
	movl	8(%ebp),%eax
	cmpl	12(%ebp),%eax
	jne	.Lab125
.Lab126:
.LN297:
	.stabn  68,0,210,.LN297-SACLIST_EQUAL		# line 210, column 25
	movl	$1,-24(%ebp) 
.LN298:
	.stabn  68,0,210,.LN298-SACLIST_EQUAL		# line 210, column 30
	movl	-24(%ebp),%eax
	leave
	ret
.Lab125:
.LN299:
	.stabn  68,0,212,.LN299-SACLIST_EQUAL		# line 212, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab128
.Lab129:
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab127
.Lab128:
.LN300:
	.stabn  68,0,212,.LN300-SACLIST_EQUAL		# line 212, column 42
	movl	-24(%ebp),%eax
	leave
	ret
.Lab127:
.LN301:
	.stabn  68,0,213,.LN301-SACLIST_EQUAL		# line 213, column 25
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN302:
	.stabn  68,0,213,.LN302-SACLIST_EQUAL		# line 213, column 34
	movl	12(%ebp),%eax
	movl	%eax,-20(%ebp) 
	jmp	.Lab130
.Lab131:
.LN303:
	.stabn  68,0,214,.LN303-SACLIST_EQUAL		# line 214, column 46
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN304:
	.stabn  68,0,215,.LN304-SACLIST_EQUAL		# line 215, column 13
	leal	-20(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN305:
	.stabn  68,0,216,.LN305-SACLIST_EQUAL		# line 216, column 13
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	SACLIST_EQUAL
	addl	$8, %esp
	cmpl	$0,%eax
	jne	.Lab133
.Lab134:
.LN306:
	.stabn  68,0,216,.LN306-SACLIST_EQUAL		# line 216, column 40
	movl	-24(%ebp),%eax
	leave
	ret
.Lab133:
.LN307:
	.stabn  68,0,217,.LN307-SACLIST_EQUAL		# line 217, column 13
	movl	-12(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jne	.Lab135
.Lab136:
.LN308:
	.stabn  68,0,217,.LN308-SACLIST_EQUAL		# line 217, column 33
	movl	$1,-24(%ebp) 
.LN309:
	.stabn  68,0,217,.LN309-SACLIST_EQUAL		# line 217, column 38
	movl	-24(%ebp),%eax
	leave
	ret
.Lab135:
.Lab130:
.LN310:
	.stabn  68,0,214,.LN310-SACLIST_EQUAL		# line 214, column 26
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab132
.Lab137:
	movl	-20(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab131
.Lab132:
.LN311:
	.stabn  68,0,219,.LN311-SACLIST_EQUAL		# line 219, column 7
	movl	-24(%ebp),%eax
	leave
	ret
.LN312:
	.stabn  68,0,220,.LN312-SACLIST_EQUAL		# line 220, column 0
	call	ReturnErr_
.LBE33:
	leave
	ret
	.Lab124 = 24
	.stabs "TL:7",128,0,4,-24
	.stabs "BLP:7",128,0,4,-20
	.stabs "BL1:7",128,0,4,-16
	.stabs "ALP:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB33-SACLIST_EQUAL
	.stabn 224,0,0,.LBE33-SACLIST_EQUAL
	.stabs "SACLIST_CONC:F7",36,0,0,SACLIST_CONC
	.align 4
SACLIST_CONC:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab138, %esp
.LN313:
	.stabn  68,0,195,.LN313-SACLIST_CONC		# line 195, column 1
.LBB34:
.LN314:
	.stabn  68,0,196,.LN314-SACLIST_CONC		# line 196, column 21
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN315:
	.stabn  68,0,197,.LN315-SACLIST_CONC		# line 197, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab139
.Lab140:
.LN316:
	.stabn  68,0,197,.LN316-SACLIST_CONC		# line 197, column 24
	movl	-8(%ebp),%eax
	leave
	ret
.Lab139:
.LN317:
	.stabn  68,0,198,.LN317-SACLIST_CONC		# line 198, column 21
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN318:
	.stabn  68,0,199,.LN318-SACLIST_CONC		# line 199, column 7
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab141
.Lab142:
.LN319:
	.stabn  68,0,199,.LN319-SACLIST_CONC		# line 199, column 24
	movl	-8(%ebp),%eax
	leave
	ret
.Lab141:
.LN320:
	.stabn  68,0,200,.LN320-SACLIST_CONC		# line 200, column 33
	pushl	8(%ebp)
	call	SACLIST_LAST
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN321:
	.stabn  68,0,200,.LN321-SACLIST_CONC		# line 200, column 45
	pushl	12(%ebp)
	pushl	-12(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN322:
	.stabn  68,0,200,.LN322-SACLIST_CONC		# line 200, column 58
	movl	-8(%ebp),%eax
	leave
	ret
.LN323:
	.stabn  68,0,201,.LN323-SACLIST_CONC		# line 201, column 0
	call	ReturnErr_
.LBE34:
	leave
	ret
	.Lab138 = 12
	.stabs "LP:7",128,0,4,-12
	.stabs "L:7",128,0,4,-8
	.stabs "L2:p7",160,0,4,12
	.stabs "L1:p7",160,0,4,8
	.stabn 192,0,0,.LBB34-SACLIST_CONC
	.stabn 224,0,0,.LBE34-SACLIST_CONC
	.stabs "SACLIST_COMP4:F7",36,0,0,SACLIST_COMP4
	.align 4
SACLIST_COMP4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab143, %esp
.LN324:
	.stabn  68,0,185,.LN324-SACLIST_COMP4		# line 185, column 1
.LBB35:
.LN325:
	.stabn  68,0,186,.LN325-SACLIST_COMP4		# line 186, column 10
	pushl	24(%ebp)
	pushl	20(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN326:
	.stabn  68,0,186,.LN326-SACLIST_COMP4		# line 186, column 28
	pushl	-8(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN327:
	.stabn  68,0,186,.LN327-SACLIST_COMP4		# line 186, column 48
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN328:
	.stabn  68,0,187,.LN328-SACLIST_COMP4		# line 187, column 8
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN329:
	.stabn  68,0,187,.LN329-SACLIST_COMP4		# line 187, column 25
	movl	-12(%ebp),%eax
	leave
	ret
.LN330:
	.stabn  68,0,188,.LN330-SACLIST_COMP4		# line 188, column 0
	call	ReturnErr_
.LBE35:
	leave
	ret
	.Lab143 = 12
	.stabs "M:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,24
	.stabs "AL4:p7",160,0,4,20
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB35-SACLIST_COMP4
	.stabn 224,0,0,.LBE35-SACLIST_COMP4
	.stabs "SACLIST_COMP3:F7",36,0,0,SACLIST_COMP3
	.align 4
SACLIST_COMP3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab144, %esp
.LN331:
	.stabn  68,0,176,.LN331-SACLIST_COMP3		# line 176, column 1
.LBB36:
.LN332:
	.stabn  68,0,177,.LN332-SACLIST_COMP3		# line 177, column 10
	pushl	20(%ebp)
	pushl	16(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN333:
	.stabn  68,0,177,.LN333-SACLIST_COMP3		# line 177, column 28
	pushl	-8(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN334:
	.stabn  68,0,177,.LN334-SACLIST_COMP3		# line 177, column 46
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN335:
	.stabn  68,0,177,.LN335-SACLIST_COMP3		# line 177, column 63
	movl	-12(%ebp),%eax
	leave
	ret
.LN336:
	.stabn  68,0,178,.LN336-SACLIST_COMP3		# line 178, column 0
	call	ReturnErr_
.LBE36:
	leave
	ret
	.Lab144 = 12
	.stabs "M:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,20
	.stabs "AL3:p7",160,0,4,16
	.stabs "AL2:p7",160,0,4,12
	.stabs "AL1:p7",160,0,4,8
	.stabn 192,0,0,.LBB36-SACLIST_COMP3
	.stabn 224,0,0,.LBE36-SACLIST_COMP3
	.stabs "SACLIST_COMP2:F7",36,0,0,SACLIST_COMP2
	.align 4
SACLIST_COMP2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab145, %esp
.LN337:
	.stabn  68,0,167,.LN337-SACLIST_COMP2		# line 167, column 1
.LBB37:
.LN338:
	.stabn  68,0,168,.LN338-SACLIST_COMP2		# line 168, column 10
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN339:
	.stabn  68,0,168,.LN339-SACLIST_COMP2		# line 168, column 25
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN340:
	.stabn  68,0,168,.LN340-SACLIST_COMP2		# line 168, column 41
	movl	-12(%ebp),%eax
	leave
	ret
.LN341:
	.stabn  68,0,169,.LN341-SACLIST_COMP2		# line 169, column 0
	call	ReturnErr_
.LBE37:
	leave
	ret
	.Lab145 = 12
	.stabs "M:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "L:p7",160,0,4,16
	.stabs "BL:p7",160,0,4,12
	.stabs "AL:p7",160,0,4,8
	.stabn 192,0,0,.LBB37-SACLIST_COMP2
	.stabn 224,0,0,.LBE37-SACLIST_COMP2
	.stabs "SACLIST_CLOUT:F16",36,0,0,SACLIST_CLOUT
	.align 4
SACLIST_CLOUT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab146, %esp
.LN342:
	.stabn  68,0,155,.LN342-SACLIST_CLOUT		# line 155, column 1
.LBB38:
.LN343:
	.stabn  68,0,156,.LN343-SACLIST_CLOUT		# line 156, column 9
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab147
.Lab148:
.LN344:
	.stabn  68,0,157,.LN344-SACLIST_CLOUT		# line 157, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN345:
	.stabn  68,0,158,.LN345-SACLIST_CLOUT		# line 158, column 13
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jge	.Lab150
.Lab151:
.LN346:
	.stabn  68,0,158,.LN346-SACLIST_CLOUT		# line 158, column 29
	pushl	-8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.Lab150:
.Lab147:
.LN347:
	.stabn  68,0,157,.LN347-SACLIST_CLOUT		# line 157, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab148
.Lab149:
.LN348:
	.stabn  68,0,159,.LN348-SACLIST_CLOUT		# line 159, column 7
	leave
	ret
.LN349:
	.stabn  68,0,160,.LN349-SACLIST_CLOUT		# line 160, column 0
.LBE38:
	leave
	ret
	.Lab146 = 12
	.stabs "LP:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB38-SACLIST_CLOUT
	.stabn 224,0,0,.LBE38-SACLIST_CLOUT
	.stabs "SACLIST_CINV:F7",36,0,0,SACLIST_CINV
	.align 4
SACLIST_CINV:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab152, %esp
.LN350:
	.stabn  68,0,143,.LN350-SACLIST_CINV		# line 143, column 1
.LBB39:
.LN351:
	.stabn  68,0,144,.LN351-SACLIST_CINV		# line 144, column 8
	movl	MASSTOR_s,%eax
	movl	%eax,-16(%ebp) 
.LN352:
	.stabn  68,0,144,.LN352-SACLIST_CINV		# line 144, column 18
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab153
.Lab154:
.LN353:
	.stabn  68,0,145,.LN353-SACLIST_CINV		# line 145, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN354:
	.stabn  68,0,145,.LN354-SACLIST_CINV		# line 145, column 42
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.Lab153:
.LN355:
	.stabn  68,0,145,.LN355-SACLIST_CINV		# line 145, column 16
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab154
.Lab155:
.LN356:
	.stabn  68,0,146,.LN356-SACLIST_CINV		# line 146, column 7
	movl	-16(%ebp),%eax
	leave
	ret
.LN357:
	.stabn  68,0,147,.LN357-SACLIST_CINV		# line 147, column 0
	call	ReturnErr_
.LBE39:
	leave
	ret
	.Lab152 = 16
	.stabs "M:7",128,0,4,-16
	.stabs "LP:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB39-SACLIST_CINV
	.stabn 224,0,0,.LBE39-SACLIST_CINV
	.stabs "SACLIST_CCONC:F7",36,0,0,SACLIST_CCONC
	.align 4
SACLIST_CCONC:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab156, %esp
.LN358:
	.stabn  68,0,129,.LN358-SACLIST_CCONC		# line 129, column 1
.LBB40:
.LN359:
	.stabn  68,0,130,.LN359-SACLIST_CCONC		# line 130, column 30
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN360:
	.stabn  68,0,131,.LN360-SACLIST_CCONC		# line 131, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab157
.Lab158:
.LN361:
	.stabn  68,0,131,.LN361-SACLIST_CCONC		# line 131, column 24
	movl	-8(%ebp),%eax
	leave
	ret
.Lab157:
.LN362:
	.stabn  68,0,132,.LN362-SACLIST_CCONC		# line 132, column 8
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN363:
	.stabn  68,0,133,.LN363-SACLIST_CCONC		# line 133, column 7
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab159
.Lab160:
.LN364:
	.stabn  68,0,133,.LN364-SACLIST_CCONC		# line 133, column 24
	movl	-8(%ebp),%eax
	leave
	ret
.Lab159:
.LN365:
	.stabn  68,0,134,.LN365-SACLIST_CCONC		# line 134, column 38
	pushl	8(%ebp)
	call	SACLIST_CINV
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN366:
	.stabn  68,0,134,.LN366-SACLIST_CCONC		# line 134, column 51
	pushl	-12(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN367:
	.stabn  68,0,135,.LN367-SACLIST_CCONC		# line 135, column 7
	pushl	12(%ebp)
	pushl	-12(%ebp)
	call	MASSTOR_SRED
	addl	$8, %esp
.LN368:
	.stabn  68,0,135,.LN368-SACLIST_CCONC		# line 135, column 21
	movl	-8(%ebp),%eax
	leave
	ret
.LN369:
	.stabn  68,0,136,.LN369-SACLIST_CCONC		# line 136, column 0
	call	ReturnErr_
.LBE40:
	leave
	ret
	.Lab156 = 12
	.stabs "LP1:7",128,0,4,-12
	.stabs "L:7",128,0,4,-8
	.stabs "L2:p7",160,0,4,12
	.stabs "L1:p7",160,0,4,8
	.stabn 192,0,0,.LBB40-SACLIST_CCONC
	.stabn 224,0,0,.LBE40-SACLIST_CCONC
	.stabs "SACLIST_AWRITE:F16",36,0,0,SACLIST_AWRITE
	.align 4
SACLIST_AWRITE:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab161, %esp
.LN370:
	.stabn  68,0,112,.LN370-SACLIST_AWRITE		# line 112, column 1
.LBB41:
.LN371:
	.stabn  68,0,114,.LN371-SACLIST_AWRITE		# line 114, column 7
	cmpl	$0,8(%ebp)
	jge	.Lab164
.Lab163:
.LN372:
	.stabn  68,0,114,.LN372-SACLIST_AWRITE		# line 114, column 23
	movl	8(%ebp),%eax
	negl	%eax
	movl	%eax,-88(%ebp) 
.LN373:
	.stabn  68,0,114,.LN373-SACLIST_AWRITE		# line 114, column 29
	.data
.Lab165:
 	.ascii	"-\000"
	.text
	pushl	$1
	leal	.Lab165,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
	jmp	.Lab162
.Lab164:
.LN374:
	.stabn  68,0,114,.LN374-SACLIST_AWRITE		# line 114, column 49
	movl	8(%ebp),%eax
	movl	%eax,-88(%ebp) 
.Lab162:
.LN375:
	.stabn  68,0,115,.LN375-SACLIST_AWRITE		# line 115, column 32
	movl	$0,-100(%ebp) 
.Lab166:
.LN376:
	.stabn  68,0,116,.LN376-SACLIST_AWRITE		# line 116, column 15
	movl	-88(%ebp),%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-92(%ebp) 
.LN377:
	.stabn  68,0,116,.LN377-SACLIST_AWRITE		# line 116, column 29
	incl	-100(%ebp)
.LN378:
	.stabn  68,0,116,.LN378-SACLIST_AWRITE		# line 116, column 39
	movl	-92(%ebp),%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,-96(%ebp) 
.LN379:
	.stabn  68,0,116,.LN379-SACLIST_AWRITE		# line 116, column 51
	movl	-100(%ebp),%ebx
	.data
	.align 4
.Lab168:
	.long	1,20
	.text
	boundl	%ebx,.Lab168
	movl	-88(%ebp),%eax
 	subl	-96(%ebp),%eax 
	movl	%eax,-88(%ebp,%ebx,4) 
.LN380:
	.stabn  68,0,116,.LN380-SACLIST_AWRITE		# line 116, column 63
	movl	-92(%ebp),%eax
	movl	%eax,-88(%ebp) 
.LN381:
	.stabn  68,0,117,.LN381-SACLIST_AWRITE		# line 117, column 23
	cmpl	$0,-88(%ebp)
	jne	.Lab166
.Lab167:
.Lab169:
.LN382:
	.stabn  68,0,119,.LN382-SACLIST_AWRITE		# line 119, column 14
	movl	-100(%ebp),%eax
	.data
	.align 4
.Lab171:
	.long	1,20
	.text
	boundl	%eax,.Lab171
	pushl	-88(%ebp,%eax,4)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN383:
	.stabn  68,0,119,.LN383-SACLIST_AWRITE		# line 119, column 29
	decl	-100(%ebp)
.LN384:
	.stabn  68,0,120,.LN384-SACLIST_AWRITE		# line 120, column 22
	cmpl	$0,-100(%ebp)
	jne	.Lab169
.Lab170:
.LN385:
	.stabn  68,0,121,.LN385-SACLIST_AWRITE		# line 121, column 7
	leave
	ret
.LN386:
	.stabn  68,0,122,.LN386-SACLIST_AWRITE		# line 122, column 0
.LBE41:
	leave
	ret
	.Lab161 = 100
	.stabs "N:7",128,0,4,-100
	.stabs "J1Y:7",128,0,4,-96
	.stabs "Q:7",128,0,4,-92
	.stabs "AP:7",128,0,4,-88
	.stabs "D:17=ar4;1;20;7",128,0,80,-84
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB41-SACLIST_AWRITE
	.stabn 224,0,0,.LBE41-SACLIST_AWRITE
	.stabs "SACLIST_AREAD:F7",36,0,0,SACLIST_AREAD
	.align 4
SACLIST_AREAD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab172, %esp
.LN387:
	.stabn  68,0,77,.LN387-SACLIST_AREAD		# line 77, column 1
.LBB42:
.LN388:
	.stabn  68,0,78,.LN388-SACLIST_AREAD		# line 78, column 47
	movl	$1,-24(%ebp) 
.LN389:
	.stabn  68,0,78,.LN389-SACLIST_AREAD		# line 78, column 53
	call	MASBIOS_CREADB
	movl	%eax,-12(%ebp) 
.LN390:
	.stabn  68,0,79,.LN390-SACLIST_AREAD		# line 79, column 7
	pushl	$43
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-12(%ebp)
	jne	.Lab175
.Lab174:
.LN391:
	.stabn  68,0,79,.LN391-SACLIST_AREAD		# line 79, column 32
	call	MASBIOS_CREAD
	movl	%eax,-12(%ebp) 
	jmp	.Lab173
.Lab175:
.LN392:
	.stabn  68,0,80,.LN392-SACLIST_AREAD		# line 80, column 10
	pushl	$45
	call	MASBIOS_MASORD
	addl	$4, %esp
	cmpl	%eax,-12(%ebp)
	jne	.Lab178
.Lab177:
.LN393:
	.stabn  68,0,80,.LN393-SACLIST_AREAD		# line 80, column 35
	call	MASBIOS_CREAD
	movl	%eax,-12(%ebp) 
.LN394:
	.stabn  68,0,80,.LN394-SACLIST_AREAD		# line 80, column 47
	movl	$-1,-24(%ebp) 
	jmp	.Lab176
.Lab178:
.LN395:
	.stabn  68,0,81,.LN395-SACLIST_AREAD		# line 81, column 13
	pushl	-12(%ebp)
	call	MASBIOS_DIGIT
	addl	$4, %esp
	cmpb	$1,%al
	je	.Lab179
.Lab180:
.LN396:
	.stabn  68,0,83,.LN396-SACLIST_AREAD		# line 83, column 33
	.data
.Lab181:
 	.ascii	"ERROR FOUND BY AREAD.\000"
	.text
	pushl	$21
	leal	.Lab181,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN397:
	.stabn  68,0,84,.LN397-SACLIST_AREAD		# line 84, column 22
	call	MASBIOS_DIBUFF
.LN398:
	.stabn  68,0,85,.LN398-SACLIST_AREAD		# line 85, column 22
	movl	$0,%eax
	leave
	ret
.Lab179:
.Lab176:
.Lab173:
.LN399:
	.stabn  68,0,89,.LN399-SACLIST_AREAD		# line 89, column 37
	movl	$0,-8(%ebp) 
.LN400:
	.stabn  68,0,89,.LN400-SACLIST_AREAD		# line 89, column 43
	movl	MASSTOR_s,%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	movl	%eax,-16(%ebp) 
.Lab182:
.LN401:
	.stabn  68,0,90,.LN401-SACLIST_AREAD		# line 90, column 14
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jle	.Lab184
.Lab185:
.LN402:
	.stabn  68,0,91,.LN402-SACLIST_AREAD		# line 91, column 28
	.data
.Lab186:
 	.ascii	"ERROR FOUND BY AREAD.\000"
	.text
	pushl	$21
	leal	.Lab186,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN403:
	.stabn  68,0,92,.LN403-SACLIST_AREAD		# line 92, column 17
	call	MASBIOS_DIBUFF
.LN404:
	.stabn  68,0,93,.LN404-SACLIST_AREAD		# line 93, column 17
	movl	$0,%eax
	leave
	ret
.Lab184:
.LN405:
	.stabn  68,0,95,.LN405-SACLIST_AREAD		# line 95, column 17
	movl	-8(%ebp),%eax
	shll	$1, %eax
	leal	(%eax,%eax,4),%eax
	movl	%eax,-20(%ebp) 
.LN406:
	.stabn  68,0,95,.LN406-SACLIST_AREAD		# line 95, column 26
	movl	-12(%ebp),%eax
 	addl	-20(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN407:
	.stabn  68,0,96,.LN407-SACLIST_AREAD		# line 96, column 14
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jl	.Lab187
.Lab188:
.LN408:
	.stabn  68,0,97,.LN408-SACLIST_AREAD		# line 97, column 28
	.data
.Lab189:
 	.ascii	"ERROR FOUND BY AREAD.\000"
	.text
	pushl	$21
	leal	.Lab189,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN409:
	.stabn  68,0,98,.LN409-SACLIST_AREAD		# line 98, column 17
	call	MASBIOS_DIBUFF
.LN410:
	.stabn  68,0,99,.LN410-SACLIST_AREAD		# line 99, column 17
	movl	$0,%eax
	leave
	ret
.Lab187:
.LN411:
	.stabn  68,0,101,.LN411-SACLIST_AREAD		# line 101, column 15
	call	MASBIOS_CREAD
	movl	%eax,-12(%ebp) 
.LN412:
	.stabn  68,0,102,.LN412-SACLIST_AREAD		# line 102, column 20
	pushl	-12(%ebp)
	call	MASBIOS_DIGIT
	addl	$4, %esp
	cmpb	$1,%al
	je	.Lab182
.Lab183:
.LN413:
	.stabn  68,0,103,.LN413-SACLIST_AREAD		# line 103, column 8
	movl	-8(%ebp),%eax
	imull	-24(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN414:
	.stabn  68,0,103,.LN414-SACLIST_AREAD		# line 103, column 15
	call	MASBIOS_BKSP
.LN415:
	.stabn  68,0,103,.LN415-SACLIST_AREAD		# line 103, column 21
	movl	-8(%ebp),%eax
	leave
	ret
.LN416:
	.stabn  68,0,104,.LN416-SACLIST_AREAD		# line 104, column 0
	call	ReturnErr_
.LBE42:
	leave
	ret
	.Lab172 = 24
	.stabs "S:7",128,0,4,-24
	.stabs "J1Y:7",128,0,4,-20
	.stabs "I:7",128,0,4,-16
	.stabs "C:7",128,0,4,-12
	.stabs "A:7",128,0,4,-8
	.stabn 192,0,0,.LBB42-SACLIST_AREAD
	.stabn 224,0,0,.LBE42-SACLIST_AREAD
	.stabs "SACLIST_ADV4:F16",36,0,0,SACLIST_ADV4
	.align 4
SACLIST_ADV4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab190, %esp
.LN417:
	.stabn  68,0,67,.LN417-SACLIST_ADV4		# line 67, column 1
.LBB43:
.LN418:
	.stabn  68,0,68,.LN418-SACLIST_ADV4		# line 68, column 7
	pushl	28(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN419:
	.stabn  68,0,68,.LN419-SACLIST_ADV4		# line 68, column 22
	pushl	28(%ebp)
	pushl	16(%ebp)
	movl	28(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN420:
	.stabn  68,0,68,.LN420-SACLIST_ADV4		# line 68, column 38
	pushl	28(%ebp)
	pushl	20(%ebp)
	movl	28(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN421:
	.stabn  68,0,68,.LN421-SACLIST_ADV4		# line 68, column 54
	pushl	28(%ebp)
	pushl	24(%ebp)
	movl	28(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN422:
	.stabn  68,0,69,.LN422-SACLIST_ADV4		# line 69, column 7
	leave
	ret
.LN423:
	.stabn  68,0,70,.LN423-SACLIST_ADV4		# line 70, column 0
.LBE43:
	leave
	ret
	.Lab190 = 4
	.stabs "LP:v7",160,0,4,28
	.stabs "AL4:v7",160,0,4,24
	.stabs "AL3:v7",160,0,4,20
	.stabs "AL2:v7",160,0,4,16
	.stabs "AL1:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB43-SACLIST_ADV4
	.stabn 224,0,0,.LBE43-SACLIST_ADV4
	.stabs "SACLIST_ADV3:F16",36,0,0,SACLIST_ADV3
	.align 4
SACLIST_ADV3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab191, %esp
.LN424:
	.stabn  68,0,59,.LN424-SACLIST_ADV3		# line 59, column 1
.LBB44:
.LN425:
	.stabn  68,0,60,.LN425-SACLIST_ADV3		# line 60, column 7
	pushl	24(%ebp)
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACLIST_ADV2
	addl	$16, %esp
.LN426:
	.stabn  68,0,60,.LN426-SACLIST_ADV3		# line 60, column 27
	pushl	24(%ebp)
	pushl	20(%ebp)
	movl	24(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN427:
	.stabn  68,0,60,.LN427-SACLIST_ADV3		# line 60, column 43
	leave
	ret
.LN428:
	.stabn  68,0,61,.LN428-SACLIST_ADV3		# line 61, column 0
.LBE44:
	leave
	ret
	.Lab191 = 4
	.stabs "LP:v7",160,0,4,24
	.stabs "AL3:v7",160,0,4,20
	.stabs "AL2:v7",160,0,4,16
	.stabs "AL1:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB44-SACLIST_ADV3
	.stabn 224,0,0,.LBE44-SACLIST_ADV3
	.stabs "SACLIST_ADV2:F16",36,0,0,SACLIST_ADV2
	.align 4
SACLIST_ADV2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab192, %esp
.LN429:
	.stabn  68,0,51,.LN429-SACLIST_ADV2		# line 51, column 1
.LBB45:
.LN430:
	.stabn  68,0,52,.LN430-SACLIST_ADV2		# line 52, column 7
	pushl	20(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN431:
	.stabn  68,0,52,.LN431-SACLIST_ADV2		# line 52, column 21
	pushl	20(%ebp)
	pushl	16(%ebp)
	movl	20(%ebp),%eax
	pushl	(%eax)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN432:
	.stabn  68,0,52,.LN432-SACLIST_ADV2		# line 52, column 36
	leave
	ret
.LN433:
	.stabn  68,0,53,.LN433-SACLIST_ADV2		# line 53, column 0
.LBE45:
	leave
	ret
	.Lab192 = 4
	.stabs "LP:v7",160,0,4,20
	.stabs "BL:v7",160,0,4,16
	.stabs "AL:v7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB45-SACLIST_ADV2
	.stabn 224,0,0,.LBE45-SACLIST_ADV2
	.stabs "SACLIST:F16",36,0,0,SACLIST
	.align 4
SACLIST:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab193, %esp
.LN434:
	.stabn  68,0,599,.LN434-SACLIST		# line 599, column 1
.LBB46:
.LN435:
	.stabn  68,0,600,.LN435-SACLIST		# line 600, column 0
.LBE46:
	leave
	ret
	.Lab193 = 4
	.stabn 192,0,0,.LBB46-SACLIST
	.stabn 224,0,0,.LBE46-SACLIST
