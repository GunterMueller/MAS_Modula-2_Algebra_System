	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maskern/",100,0,0,.LBB0
	.stabs "LISTTOOLS.mod",100,0,0,.LBB0
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
	.globl	LISTTOOLS
	.globl	LISTTOOLS_UPCASE
	.globl	LISTTOOLS_LSRCHQ
	.globl	LISTTOOLS_LPAIRS
	.globl	LISTTOOLS_LIST6
	.globl	LISTTOOLS_CLISTFA
	.stabs "LISTTOOLS_UPCASE:F7",36,0,0,LISTTOOLS_UPCASE
	.align 4
LISTTOOLS_UPCASE:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,100,.LN1-LISTTOOLS_UPCASE		# line 100, column 1
.LBB1:
.LN2:
	.stabn  68,0,101,.LN2-LISTTOOLS_UPCASE		# line 101, column 15
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab2
.Lab3:
.LN3:
	.stabn  68,0,103,.LN3-LISTTOOLS_UPCASE		# line 103, column 17
	leal	8(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN4:
	.stabn  68,0,104,.LN4-LISTTOOLS_UPCASE		# line 104, column 17
	pushl	-8(%ebp)
	call	MASBIOS_LETTER
	addl	$4, %esp
	cmpb	$0,%al
	je	.Lab7
.Lab8:
	pushl	-8(%ebp)
	call	MASELEM_MASEVEN
	addl	$4, %esp
	cmpb	$0,%al
	je	.Lab7
.Lab6:
.LN5:
	.stabn  68,0,105,.LN5-LISTTOOLS_UPCASE		# line 105, column 31
	pushl	-12(%ebp)
	movl	$1,%eax
 	addl	-8(%ebp),%eax 
	pushl	%eax
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
	jmp	.Lab5
.Lab7:
.LN6:
	.stabn  68,0,107,.LN6-LISTTOOLS_UPCASE		# line 107, column 31
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.Lab5:
.Lab2:
.LN7:
	.stabn  68,0,102,.LN7-LISTTOOLS_UPCASE		# line 102, column 20
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab3
.Lab4:
.LN8:
	.stabn  68,0,110,.LN8-LISTTOOLS_UPCASE		# line 110, column 9
	pushl	-12(%ebp)
	call	MASSTOR_INV
	addl	$4, %esp
	leave
	ret
.LN9:
	.stabn  68,0,111,.LN9-LISTTOOLS_UPCASE		# line 111, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 12
	.stabs "result:7",128,0,4,-12
	.stabs "c:7",128,0,4,-8
	.stabs "clist:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-LISTTOOLS_UPCASE
	.stabn 224,0,0,.LBE1-LISTTOOLS_UPCASE
	.stabs "LISTTOOLS_LSRCHQ:F7",36,0,0,LISTTOOLS_LSRCHQ
	.align 4
LISTTOOLS_LSRCHQ:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN10:
	.stabn  68,0,83,.LN10-LISTTOOLS_LSRCHQ		# line 83, column 1
.LBB2:
.LN11:
	.stabn  68,0,84,.LN11-LISTTOOLS_LSRCHQ		# line 84, column 10
	movl	$0,-12(%ebp) 
	jmp	.Lab10
.Lab11:
.LN12:
	.stabn  68,0,86,.LN12-LISTTOOLS_LSRCHQ		# line 86, column 18
	incl	-12(%ebp)
.LN13:
	.stabn  68,0,87,.LN13-LISTTOOLS_LSRCHQ		# line 87, column 17
	leal	12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN14:
	.stabn  68,0,88,.LN14-LISTTOOLS_LSRCHQ		# line 88, column 17
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACLIST_EQUAL
	addl	$8, %esp
	cmpl	$1,%eax
	jne	.Lab13
.Lab14:
.LN15:
	.stabn  68,0,88,.LN15-LISTTOOLS_LSRCHQ		# line 88, column 38
	movl	-12(%ebp),%eax
	leave
	ret
.Lab13:
.Lab10:
.LN16:
	.stabn  68,0,85,.LN16-LISTTOOLS_LSRCHQ		# line 85, column 16
	movl	12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab11
.Lab12:
.LN17:
	.stabn  68,0,90,.LN17-LISTTOOLS_LSRCHQ		# line 90, column 9
	movl	$0,%eax
	leave
	ret
.LN18:
	.stabn  68,0,91,.LN18-LISTTOOLS_LSRCHQ		# line 91, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab9 = 12
	.stabs "i:7",128,0,4,-12
	.stabs "b:7",128,0,4,-8
	.stabs "L:p7",160,0,4,12
	.stabs "a:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-LISTTOOLS_LSRCHQ
	.stabn 224,0,0,.LBE2-LISTTOOLS_LSRCHQ
	.stabs "LISTTOOLS_LPAIRS:F7",36,0,0,LISTTOOLS_LPAIRS
	.align 4
LISTTOOLS_LPAIRS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab15, %esp
.LN19:
	.stabn  68,0,62,.LN19-LISTTOOLS_LPAIRS		# line 62, column 1
.LBB3:
.LN20:
	.stabn  68,0,63,.LN20-LISTTOOLS_LPAIRS		# line 63, column 15
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-8(%ebp) 
	jmp	.Lab16
.Lab17:
.LN21:
	.stabn  68,0,65,.LN21-LISTTOOLS_LPAIRS		# line 65, column 17
	leal	8(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN22:
	.stabn  68,0,66,.LN22-LISTTOOLS_LPAIRS		# line 66, column 24
	movl	8(%ebp),%eax
	movl	%eax,-12(%ebp) 
	jmp	.Lab19
.Lab20:
.LN23:
	.stabn  68,0,68,.LN23-LISTTOOLS_LPAIRS		# line 68, column 25
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-20(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN24:
	.stabn  68,0,69,.LN24-LISTTOOLS_LPAIRS		# line 69, column 31
	pushl	-8(%ebp)
	pushl	-20(%ebp)
	pushl	-16(%ebp)
	call	SACLIST_LIST2
	addl	$8, %esp
	pushl	%eax
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab19:
.LN25:
	.stabn  68,0,67,.LN25-LISTTOOLS_LPAIRS		# line 67, column 30
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab20
.Lab21:
.Lab16:
.LN26:
	.stabn  68,0,64,.LN26-LISTTOOLS_LPAIRS		# line 64, column 16
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab17
.Lab18:
.LN27:
	.stabn  68,0,72,.LN27-LISTTOOLS_LPAIRS		# line 72, column 9
	movl	-8(%ebp),%eax
	leave
	ret
.LN28:
	.stabn  68,0,73,.LN28-LISTTOOLS_LPAIRS		# line 73, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab15 = 20
	.stabs "second:7",128,0,4,-20
	.stabs "first:7",128,0,4,-16
	.stabs "pointer:7",128,0,4,-12
	.stabs "result:7",128,0,4,-8
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-LISTTOOLS_LPAIRS
	.stabn 224,0,0,.LBE3-LISTTOOLS_LPAIRS
	.stabs "LISTTOOLS_LIST6:F7",36,0,0,LISTTOOLS_LIST6
	.align 4
LISTTOOLS_LIST6:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab22, %esp
.LN29:
	.stabn  68,0,53,.LN29-LISTTOOLS_LIST6		# line 53, column 1
.LBB4:
.LN30:
	.stabn  68,0,54,.LN30-LISTTOOLS_LIST6		# line 54, column 9
	pushl	28(%ebp)
	pushl	24(%ebp)
	pushl	20(%ebp)
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	SACLIST_LIST5
	addl	$20, %esp
	pushl	%eax
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	leave
	ret
.LN31:
	.stabn  68,0,55,.LN31-LISTTOOLS_LIST6		# line 55, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab22 = 4
	.stabs "a6:p7",160,0,4,28
	.stabs "a5:p7",160,0,4,24
	.stabs "a4:p7",160,0,4,20
	.stabs "a3:p7",160,0,4,16
	.stabs "a2:p7",160,0,4,12
	.stabs "a1:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-LISTTOOLS_LIST6
	.stabn 224,0,0,.LBE4-LISTTOOLS_LIST6
	.stabs "LISTTOOLS_CLISTFA:F7",36,0,0,LISTTOOLS_CLISTFA
	.align 4
LISTTOOLS_CLISTFA:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab23, %esp
.LN32:
	.stabn  68,0,34,.LN32-LISTTOOLS_CLISTFA		# line 34, column 1
.LBB5:
.LN33:
	.stabn  68,0,35,.LN33-LISTTOOLS_CLISTFA		# line 35, column 15
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-8(%ebp) 
.LN34:
	.stabn  68,0,36,.LN34-LISTTOOLS_CLISTFA		# line 36, column 9
	cmpl	$0,8(%ebp)
	jge	.Lab26
.Lab25:
.LN35:
	.stabn  68,0,37,.LN35-LISTTOOLS_CLISTFA		# line 37, column 22
	movb	$1,-9(%ebp) 
.LN36:
	.stabn  68,0,38,.LN36-LISTTOOLS_CLISTFA		# line 38, column 21
	movl	8(%ebp),%eax
	negl	%eax
	movl	%eax,8(%ebp) 
	jmp	.Lab24
.Lab26:
.LN37:
	.stabn  68,0,40,.LN37-LISTTOOLS_CLISTFA		# line 40, column 22
	movb	$0,-9(%ebp) 
.Lab24:
.Lab27:
.LN38:
	.stabn  68,0,43,.LN38-LISTTOOLS_CLISTFA		# line 43, column 23
	pushl	-8(%ebp)
	movl	8(%ebp),%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	pushl	%edx
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN39:
	.stabn  68,0,44,.LN39-LISTTOOLS_CLISTFA		# line 44, column 21
	movl	8(%ebp),%eax
	movl	$10,%ebx
	cdq
	idivl	%ebx
	movl	%eax,8(%ebp) 
.LN40:
	.stabn  68,0,45,.LN40-LISTTOOLS_CLISTFA		# line 45, column 19
	cmpl	$0,8(%ebp)
	jne	.Lab27
.Lab28:
.LN41:
	.stabn  68,0,46,.LN41-LISTTOOLS_CLISTFA		# line 46, column 9
	cmpb	$0,-9(%ebp)
	je	.Lab29
.Lab30:
.LN42:
	.stabn  68,0,46,.LN42-LISTTOOLS_CLISTFA		# line 46, column 29
	pushl	-8(%ebp)
	pushl	$45
	call	MASBIOS_MASORD
	addl	$4, %esp
	pushl	%eax
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab29:
.LN43:
	.stabn  68,0,47,.LN43-LISTTOOLS_CLISTFA		# line 47, column 9
	movl	-8(%ebp),%eax
	leave
	ret
.LN44:
	.stabn  68,0,48,.LN44-LISTTOOLS_CLISTFA		# line 48, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab23 = 12
	.stabs "minus:1",128,0,1,-9
	.stabs "result:7",128,0,4,-8
	.stabs "atom:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-LISTTOOLS_CLISTFA
	.stabn 224,0,0,.LBE5-LISTTOOLS_CLISTFA
	.stabs "LISTTOOLS:F16",36,0,0,LISTTOOLS
	.align 4
LISTTOOLS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab31, %esp
.LN45:
	.stabn  68,0,114,.LN45-LISTTOOLS		# line 114, column 1
.LBB6:
.LN46:
	.stabn  68,0,115,.LN46-LISTTOOLS		# line 115, column 0
.LBE6:
	leave
	ret
	.Lab31 = 4
	.stabn 192,0,0,.LBB6-LISTTOOLS
	.stabn 224,0,0,.LBE6-LISTTOOLS
