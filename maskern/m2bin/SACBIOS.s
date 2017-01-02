	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/maskern/",100,0,0,.LBB0
	.stabs "SACBIOS.mod",100,0,0,.LBB0
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
	.globl	SACBIOS
	.globl	SACBIOS_CWRIT6
	.globl	SACBIOS_CWRIT5
	.globl	SACBIOS_CWRIT4
	.globl	SACBIOS_CWRIT3
	.globl	SACBIOS_CWRIT2
	.stabs "SACBIOS_CWRIT6:F16",36,0,0,SACBIOS_CWRIT6
	.align 4
SACBIOS_CWRIT6:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,74,.LN1-SACBIOS_CWRIT6		# line 74, column 1
.LBB1:
.LN2:
	.stabn  68,0,75,.LN2-SACBIOS_CWRIT6		# line 75, column 7
	pushl	8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN3:
	.stabn  68,0,75,.LN3-SACBIOS_CWRIT6		# line 75, column 19
	pushl	12(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN4:
	.stabn  68,0,75,.LN4-SACBIOS_CWRIT6		# line 75, column 31
	pushl	16(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN5:
	.stabn  68,0,75,.LN5-SACBIOS_CWRIT6		# line 75, column 43
	pushl	20(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN6:
	.stabn  68,0,75,.LN6-SACBIOS_CWRIT6		# line 75, column 55
	pushl	24(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN7:
	.stabn  68,0,76,.LN7-SACBIOS_CWRIT6		# line 76, column 7
	pushl	28(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN8:
	.stabn  68,0,76,.LN8-SACBIOS_CWRIT6		# line 76, column 19
	leave
	ret
.LN9:
	.stabn  68,0,77,.LN9-SACBIOS_CWRIT6		# line 77, column 0
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabs "C6:p7",160,0,4,28
	.stabs "C5:p7",160,0,4,24
	.stabs "C4:p7",160,0,4,20
	.stabs "C3:p7",160,0,4,16
	.stabs "C2:p7",160,0,4,12
	.stabs "C1:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACBIOS_CWRIT6
	.stabn 224,0,0,.LBE1-SACBIOS_CWRIT6
	.stabs "SACBIOS_CWRIT5:F16",36,0,0,SACBIOS_CWRIT5
	.align 4
SACBIOS_CWRIT5:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab2, %esp
.LN10:
	.stabn  68,0,65,.LN10-SACBIOS_CWRIT5		# line 65, column 1
.LBB2:
.LN11:
	.stabn  68,0,66,.LN11-SACBIOS_CWRIT5		# line 66, column 7
	pushl	8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN12:
	.stabn  68,0,66,.LN12-SACBIOS_CWRIT5		# line 66, column 19
	pushl	12(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN13:
	.stabn  68,0,66,.LN13-SACBIOS_CWRIT5		# line 66, column 31
	pushl	16(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN14:
	.stabn  68,0,66,.LN14-SACBIOS_CWRIT5		# line 66, column 43
	pushl	20(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN15:
	.stabn  68,0,66,.LN15-SACBIOS_CWRIT5		# line 66, column 55
	pushl	24(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN16:
	.stabn  68,0,67,.LN16-SACBIOS_CWRIT5		# line 67, column 7
	leave
	ret
.LN17:
	.stabn  68,0,68,.LN17-SACBIOS_CWRIT5		# line 68, column 0
.LBE2:
	leave
	ret
	.Lab2 = 4
	.stabs "C5:p7",160,0,4,24
	.stabs "C4:p7",160,0,4,20
	.stabs "C3:p7",160,0,4,16
	.stabs "C2:p7",160,0,4,12
	.stabs "C1:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACBIOS_CWRIT5
	.stabn 224,0,0,.LBE2-SACBIOS_CWRIT5
	.stabs "SACBIOS_CWRIT4:F16",36,0,0,SACBIOS_CWRIT4
	.align 4
SACBIOS_CWRIT4:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab3, %esp
.LN18:
	.stabn  68,0,57,.LN18-SACBIOS_CWRIT4		# line 57, column 1
.LBB3:
.LN19:
	.stabn  68,0,58,.LN19-SACBIOS_CWRIT4		# line 58, column 7
	pushl	8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN20:
	.stabn  68,0,58,.LN20-SACBIOS_CWRIT4		# line 58, column 19
	pushl	12(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN21:
	.stabn  68,0,58,.LN21-SACBIOS_CWRIT4		# line 58, column 31
	pushl	16(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN22:
	.stabn  68,0,58,.LN22-SACBIOS_CWRIT4		# line 58, column 43
	pushl	20(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN23:
	.stabn  68,0,58,.LN23-SACBIOS_CWRIT4		# line 58, column 55
	leave
	ret
.LN24:
	.stabn  68,0,59,.LN24-SACBIOS_CWRIT4		# line 59, column 0
.LBE3:
	leave
	ret
	.Lab3 = 4
	.stabs "C4:p7",160,0,4,20
	.stabs "C3:p7",160,0,4,16
	.stabs "C2:p7",160,0,4,12
	.stabs "C1:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-SACBIOS_CWRIT4
	.stabn 224,0,0,.LBE3-SACBIOS_CWRIT4
	.stabs "SACBIOS_CWRIT3:F16",36,0,0,SACBIOS_CWRIT3
	.align 4
SACBIOS_CWRIT3:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab4, %esp
.LN25:
	.stabn  68,0,49,.LN25-SACBIOS_CWRIT3		# line 49, column 1
.LBB4:
.LN26:
	.stabn  68,0,50,.LN26-SACBIOS_CWRIT3		# line 50, column 7
	pushl	8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN27:
	.stabn  68,0,50,.LN27-SACBIOS_CWRIT3		# line 50, column 19
	pushl	12(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN28:
	.stabn  68,0,50,.LN28-SACBIOS_CWRIT3		# line 50, column 31
	pushl	16(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN29:
	.stabn  68,0,50,.LN29-SACBIOS_CWRIT3		# line 50, column 43
	leave
	ret
.LN30:
	.stabn  68,0,51,.LN30-SACBIOS_CWRIT3		# line 51, column 0
.LBE4:
	leave
	ret
	.Lab4 = 4
	.stabs "C3:p7",160,0,4,16
	.stabs "C2:p7",160,0,4,12
	.stabs "C1:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACBIOS_CWRIT3
	.stabn 224,0,0,.LBE4-SACBIOS_CWRIT3
	.stabs "SACBIOS_CWRIT2:F16",36,0,0,SACBIOS_CWRIT2
	.align 4
SACBIOS_CWRIT2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab5, %esp
.LN31:
	.stabn  68,0,41,.LN31-SACBIOS_CWRIT2		# line 41, column 1
.LBB5:
.LN32:
	.stabn  68,0,42,.LN32-SACBIOS_CWRIT2		# line 42, column 7
	pushl	8(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN33:
	.stabn  68,0,42,.LN33-SACBIOS_CWRIT2		# line 42, column 19
	pushl	12(%ebp)
	call	MASBIOS_CWRITE
	addl	$4, %esp
.LN34:
	.stabn  68,0,42,.LN34-SACBIOS_CWRIT2		# line 42, column 31
	leave
	ret
.LN35:
	.stabn  68,0,43,.LN35-SACBIOS_CWRIT2		# line 43, column 0
.LBE5:
	leave
	ret
	.Lab5 = 4
	.stabs "C2:p7",160,0,4,12
	.stabs "C1:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-SACBIOS_CWRIT2
	.stabn 224,0,0,.LBE5-SACBIOS_CWRIT2
	.stabs "SACBIOS:F16",36,0,0,SACBIOS
	.align 4
SACBIOS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab6, %esp
.LN36:
	.stabn  68,0,80,.LN36-SACBIOS		# line 80, column 1
.LBB6:
.LN37:
	.stabn  68,0,81,.LN37-SACBIOS		# line 81, column 0
.LBE6:
	leave
	ret
	.Lab6 = 4
	.stabn 192,0,0,.LBB6-SACBIOS
	.stabn 224,0,0,.LBE6-SACBIOS
