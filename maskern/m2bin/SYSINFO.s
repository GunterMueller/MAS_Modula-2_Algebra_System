	.comm SYSINFO_s, 4
	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maskern/",100,0,0,.LBB0
	.stabs "SYSINFO.mod",100,0,0,.LBB0
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
	.globl	SYSINFO
	.globl	SYSINFO_SysInfoWrite
	.globl	SYSINFO_SysInfoSum
	.globl	SYSINFO_SysInfoStop
	.globl	SYSINFO_SysInfoStart
	.stabs "SYSINFO_SysInfoWrite:F16",36,0,0,SYSINFO_SysInfoWrite
	.align 4
SYSINFO_SysInfoWrite:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,94,.LN1-SYSINFO_SysInfoWrite		# line 94, column 1
.LBB1:
	leal	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN2:
	.stabn  68,0,96,.LN2-SYSINFO_SysInfoWrite		# line 96, column 17
	.data
.Lab2:
 	.ascii	"SysInfo: Time: \000"
	.text
	pushl	$15
	leal	.Lab2,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN3:
	.stabn  68,0,97,.LN3-SYSINFO_SysInfoWrite		# line 97, column 17
	movl	-8(%ebp),%eax
	pushl	8(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN4:
	.stabn  68,0,98,.LN4-SYSINFO_SysInfoWrite		# line 98, column 17
	movl	-8(%ebp),%eax
	cmpl	$0,(%eax)
	jle	.Lab5
.Lab4:
.LN5:
	.stabn  68,0,99,.LN5-SYSINFO_SysInfoWrite		# line 99, column 25
	.data
.Lab6:
 	.ascii	" ms plus \000"
	.text
	pushl	$9
	leal	.Lab6,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN6:
	.stabn  68,0,100,.LN6-SYSINFO_SysInfoWrite		# line 100, column 25
	movl	-8(%ebp),%eax
	pushl	16(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN7:
	.stabn  68,0,101,.LN7-SYSINFO_SysInfoWrite		# line 101, column 25
	.data
.Lab7:
 	.ascii	" ms garbage collection time. \000"
	.text
	pushl	$29
	leal	.Lab7,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
	jmp	.Lab3
.Lab5:
.LN8:
	.stabn  68,0,103,.LN8-SYSINFO_SysInfoWrite		# line 103, column 25
	.data
.Lab8:
 	.ascii	" ms.\000"
	.text
	pushl	$4
	leal	.Lab8,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.Lab3:
.LN9:
	.stabn  68,0,105,.LN9-SYSINFO_SysInfoWrite		# line 105, column 17
	pushl	$0
	call	MASBIOS_BLINES
	addl	$4, %esp
.LN10:
	.stabn  68,0,106,.LN10-SYSINFO_SysInfoWrite		# line 106, column 17
	cmpb	$0,SYSINFO_s
	je	.Lab9
.Lab10:
.LN11:
	.stabn  68,0,107,.LN11-SYSINFO_SysInfoWrite		# line 107, column 25
	.data
.Lab11:
 	.ascii	"         \000"
	.text
	pushl	$9
	leal	.Lab11,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN12:
	.stabn  68,0,108,.LN12-SYSINFO_SysInfoWrite		# line 108, column 25
	.data
.Lab12:
 	.ascii	"Cells: \000"
	.text
	pushl	$7
	leal	.Lab12,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN13:
	.stabn  68,0,109,.LN13-SYSINFO_SysInfoWrite		# line 109, column 25
	movl	-8(%ebp),%eax
	pushl	12(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN14:
	.stabn  68,0,110,.LN14-SYSINFO_SysInfoWrite		# line 110, column 25
	.data
.Lab13:
 	.ascii	" cells used of \000"
	.text
	pushl	$15
	leal	.Lab13,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN15:
	.stabn  68,0,111,.LN15-SYSINFO_SysInfoWrite		# line 111, column 25
	pushl	MASSTOR_s + 12
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN16:
	.stabn  68,0,112,.LN16-SYSINFO_SysInfoWrite		# line 112, column 25
	.data
.Lab14:
 	.ascii	" cells.\000"
	.text
	pushl	$7
	leal	.Lab14,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN17:
	.stabn  68,0,113,.LN17-SYSINFO_SysInfoWrite		# line 113, column 25
	pushl	$0
	call	MASBIOS_BLINES
	addl	$4, %esp
.Lab9:
.LN18:
	.stabn  68,0,115,.LN18-SYSINFO_SysInfoWrite		# line 115, column 17
	movl	-8(%ebp),%eax
	cmpl	$0,(%eax)
	jle	.Lab15
.Lab16:
.LN19:
	.stabn  68,0,116,.LN19-SYSINFO_SysInfoWrite		# line 116, column 25
	.data
.Lab17:
 	.ascii	"         \000"
	.text
	pushl	$9
	leal	.Lab17,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN20:
	.stabn  68,0,117,.LN20-SYSINFO_SysInfoWrite		# line 117, column 25
	.data
.Lab18:
 	.ascii	"GC: \000"
	.text
	pushl	$4
	leal	.Lab18,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN21:
	.stabn  68,0,118,.LN21-SYSINFO_SysInfoWrite		# line 118, column 25
	movl	-8(%ebp),%eax
	pushl	4(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN22:
	.stabn  68,0,119,.LN22-SYSINFO_SysInfoWrite		# line 119, column 25
	.data
.Lab19:
 	.ascii	" cells reclaimed in \000"
	.text
	pushl	$20
	leal	.Lab19,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN23:
	.stabn  68,0,120,.LN23-SYSINFO_SysInfoWrite		# line 120, column 25
	movl	-8(%ebp),%eax
	pushl	16(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN24:
	.stabn  68,0,121,.LN24-SYSINFO_SysInfoWrite		# line 121, column 25
	.data
.Lab20:
 	.ascii	" ms with \000"
	.text
	pushl	$9
	leal	.Lab20,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.LN25:
	.stabn  68,0,122,.LN25-SYSINFO_SysInfoWrite		# line 122, column 25
	movl	-8(%ebp),%eax
	pushl	(%eax)
	call	SACLIST_AWRITE
	addl	$4, %esp
.LN26:
	.stabn  68,0,123,.LN26-SYSINFO_SysInfoWrite		# line 123, column 25
	movl	-8(%ebp),%eax
	cmpl	$1,(%eax)
	jle	.Lab23
.Lab22:
.LN27:
	.stabn  68,0,124,.LN27-SYSINFO_SysInfoWrite		# line 124, column 33
	.data
.Lab24:
 	.ascii	" gc's.\000"
	.text
	pushl	$6
	leal	.Lab24,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
	jmp	.Lab21
.Lab23:
.LN28:
	.stabn  68,0,126,.LN28-SYSINFO_SysInfoWrite		# line 126, column 33
	.data
.Lab25:
 	.ascii	" gc.\000"
	.text
	pushl	$4
	leal	.Lab25,%eax
	pushl	%eax
	call	MASBIOS_SWRITE
	addl	$8, %esp
.Lab21:
.LN29:
	.stabn  68,0,128,.LN29-SYSINFO_SysInfoWrite		# line 128, column 25
	pushl	$0
	call	MASBIOS_BLINES
	addl	$4, %esp
.Lab15:
.LN30:
	.stabn  68,0,129,.LN30-SYSINFO_SysInfoWrite		# line 129, column 0
.LBE1:
	leave
	ret
	.Lab1 = 8
	.stabs "SYSINFO:t17=s20GarbageCollectionTime:7,128,32;UsedCells:7,96,32;Time:7,64,32;ReclaimedCells:7,32,32;GarbageCollections:7,0,32;;",128,0,0,0
	.stabs "s:p17",160,0,20,8
	.stabn 192,0,0,.LBB1-SYSINFO_SysInfoWrite
	.stabn 224,0,0,.LBE1-SYSINFO_SysInfoWrite
	.stabs "SYSINFO_SysInfoSum:F16",36,0,0,SYSINFO_SysInfoSum
	.align 4
SYSINFO_SysInfoSum:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab26, %esp
.LN31:
	.stabn  68,0,79,.LN31-SYSINFO_SysInfoSum		# line 79, column 1
.LBB2:
	movl	48(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN32:
	.stabn  68,0,81,.LN32-SYSINFO_SysInfoSum		# line 81, column 21
	movl	-8(%ebp),%ebx
	movl	36(%ebp),%eax
 	addl	16(%ebp),%eax 
	movl	%eax,8(%ebx) 
.LN33:
	.stabn  68,0,82,.LN33-SYSINFO_SysInfoSum		# line 82, column 35
	movl	-8(%ebp),%ebx
	movl	28(%ebp),%eax
 	addl	8(%ebp),%eax 
	movl	%eax,(%ebx) 
.LN34:
	.stabn  68,0,83,.LN34-SYSINFO_SysInfoSum		# line 83, column 31
	movl	-8(%ebp),%ebx
	movl	32(%ebp),%eax
 	addl	12(%ebp),%eax 
	movl	%eax,4(%ebx) 
.LN35:
	.stabn  68,0,84,.LN35-SYSINFO_SysInfoSum		# line 84, column 17
	cmpb	$0,SYSINFO_s
	je	.Lab27
.Lab28:
.LN36:
	.stabn  68,0,84,.LN36-SYSINFO_SysInfoSum		# line 84, column 40
	movl	-8(%ebp),%ebx
	movl	40(%ebp),%eax
 	addl	20(%ebp),%eax 
	movl	%eax,12(%ebx) 
.Lab27:
.LN37:
	.stabn  68,0,85,.LN37-SYSINFO_SysInfoSum		# line 85, column 38
	movl	-8(%ebp),%ebx
	movl	44(%ebp),%eax
 	addl	24(%ebp),%eax 
	movl	%eax,16(%ebx) 
.LN38:
	.stabn  68,0,86,.LN38-SYSINFO_SysInfoSum		# line 86, column 0
.LBE2:
	leave
	ret
	.Lab26 = 8
	.stabs "s:v17",160,0,20,48
	.stabs "b:p17",160,0,20,28
	.stabs "a:p17",160,0,20,8
	.stabn 192,0,0,.LBB2-SYSINFO_SysInfoSum
	.stabn 224,0,0,.LBE2-SYSINFO_SysInfoSum
	.stabs "SYSINFO_SysInfoStop:F16",36,0,0,SYSINFO_SysInfoStop
	.align 4
SYSINFO_SysInfoStop:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab29, %esp
.LN39:
	.stabn  68,0,65,.LN39-SYSINFO_SysInfoStop		# line 65, column 1
.LBB3:
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN40:
	.stabn  68,0,67,.LN40-SYSINFO_SysInfoStop		# line 67, column 21
	movl	-8(%ebp),%eax
	pushl	%eax
	call	MASSTOR_TIME
 	movl	%eax, %ebx
	movl	-8(%ebp),%eax
 	subl	8(%eax),%ebx 
	popl	%eax
	movl	%ebx,8(%eax) 
.LN41:
	.stabn  68,0,68,.LN41-SYSINFO_SysInfoStop		# line 68, column 35
	movl	-8(%ebp),%ecx
	movl	MASSTOR_s + 16,%ebx
	movl	-8(%ebp),%eax
 	subl	(%eax),%ebx 
	movl	%ebx,(%ecx) 
.LN42:
	.stabn  68,0,69,.LN42-SYSINFO_SysInfoStop		# line 69, column 31
	movl	-8(%ebp),%ecx
	movl	MASSTOR_s + 20,%ebx
	movl	-8(%ebp),%eax
 	subl	4(%eax),%ebx 
	movl	%ebx,4(%ecx) 
.LN43:
	.stabn  68,0,70,.LN43-SYSINFO_SysInfoStop		# line 70, column 17
	cmpb	$0,SYSINFO_s
	je	.Lab30
.Lab31:
.LN44:
	.stabn  68,0,70,.LN44-SYSINFO_SysInfoStop		# line 70, column 40
	movl	-8(%ebp),%eax
	pushl	%eax
	call	MASSTOR_CELLS
 	movl	%eax, %ebx
	movl	-8(%ebp),%eax
 	subl	12(%eax),%ebx 
	popl	%eax
	movl	%ebx,12(%eax) 
.Lab30:
.LN45:
	.stabn  68,0,71,.LN45-SYSINFO_SysInfoStop		# line 71, column 38
	movl	-8(%ebp),%ecx
	movl	MASSTOR_s + 32,%ebx
	movl	-8(%ebp),%eax
 	subl	16(%eax),%ebx 
	movl	%ebx,16(%ecx) 
.LN46:
	.stabn  68,0,72,.LN46-SYSINFO_SysInfoStop		# line 72, column 0
.LBE3:
	leave
	ret
	.Lab29 = 8
	.stabs "s:v17",160,0,20,8
	.stabn 192,0,0,.LBB3-SYSINFO_SysInfoStop
	.stabn 224,0,0,.LBE3-SYSINFO_SysInfoStop
	.stabs "SYSINFO_SysInfoStart:F16",36,0,0,SYSINFO_SysInfoStart
	.align 4
SYSINFO_SysInfoStart:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab32, %esp
.LN47:
	.stabn  68,0,49,.LN47-SYSINFO_SysInfoStart		# line 49, column 1
.LBB4:
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN48:
	.stabn  68,0,51,.LN48-SYSINFO_SysInfoStart		# line 51, column 21
	movl	-8(%ebp),%eax
	pushl	%eax
	call	MASSTOR_TIME
	popl	%ebx
	movl	%eax,8(%ebx) 
.LN49:
	.stabn  68,0,52,.LN49-SYSINFO_SysInfoStart		# line 52, column 35
	movl	-8(%ebp),%ebx
	movl	MASSTOR_s + 16,%eax
	movl	%eax,(%ebx) 
.LN50:
	.stabn  68,0,53,.LN50-SYSINFO_SysInfoStart		# line 53, column 31
	movl	-8(%ebp),%ebx
	movl	MASSTOR_s + 20,%eax
	movl	%eax,4(%ebx) 
.LN51:
	.stabn  68,0,54,.LN51-SYSINFO_SysInfoStart		# line 54, column 17
	cmpb	$0,SYSINFO_s
	je	.Lab33
.Lab34:
.LN52:
	.stabn  68,0,54,.LN52-SYSINFO_SysInfoStart		# line 54, column 40
	movl	-8(%ebp),%eax
	pushl	%eax
	call	MASSTOR_CELLS
	popl	%ebx
	movl	%eax,12(%ebx) 
.Lab33:
.LN53:
	.stabn  68,0,55,.LN53-SYSINFO_SysInfoStart		# line 55, column 38
	movl	-8(%ebp),%ebx
	movl	MASSTOR_s + 32,%eax
	movl	%eax,16(%ebx) 
.LN54:
	.stabn  68,0,56,.LN54-SYSINFO_SysInfoStart		# line 56, column 0
.LBE4:
	leave
	ret
	.Lab32 = 8
	.stabs "s:v17",160,0,20,8
	.stabn 192,0,0,.LBB4-SYSINFO_SysInfoStart
	.stabn 224,0,0,.LBE4-SYSINFO_SysInfoStart
	.stabs "SYSINFO:F16",36,0,0,SYSINFO
	.align 4
SYSINFO:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab35, %esp
.LN55:
	.stabn  68,0,133,.LN55-SYSINFO		# line 133, column 1
.LBB5:
.LN56:
	.stabn  68,0,134,.LN56-SYSINFO		# line 134, column 14
	movb	$0,SYSINFO_s 
.LN57:
	.stabn  68,0,135,.LN57-SYSINFO		# line 135, column 0
.LBE5:
	leave
	ret
	.Lab35 = 4
	.stabn 192,0,0,.LBB5-SYSINFO
	.stabn 224,0,0,.LBE5-SYSINFO
	.stabs "SYSINFO_s:Gs1Cells:1,0,8;;",32,0,0,0
