	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "SACM.mod",100,0,0,.LBB0
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
	.globl	SACI_IWRITE
	.globl	SACI_ITRUNC
	.globl	SACI_ISUM
	.globl	SACI_ISSUM
	.globl	SACI_ISQRT
	.globl	SACI_ISIGNF
	.globl	SACI_ISEG
	.globl	SACI_IROOT
	.globl	SACI_IREM
	.globl	SACI_IREAD
	.globl	SACI_IRAND
	.globl	SACI_IQR
	.globl	SACI_IQ
	.globl	SACI_IPRODK
	.globl	SACI_IPROD
	.globl	SACI_IPOWER
	.globl	SACI_IORD2
	.globl	SACI_IODD
	.globl	SACI_INEG
	.globl	SACI_IMP2
	.globl	SACI_IMIN
	.globl	SACI_IMAX
	.globl	SACI_ILWRIT
	.globl	SACI_ILOG2
	.globl	SACI_ILCOMB
	.globl	SACI_ILCM
	.globl	SACI_IHEGCD
	.globl	SACI_IGCDCF
	.globl	SACI_IGCD
	.globl	SACI_IFCL2
	.globl	SACI_IEXP
	.globl	SACI_IEVEN
	.globl	SACI_IEGCD
	.globl	SACI_IDREM
	.globl	SACI_IDQR
	.globl	SACI_IDQ
	.globl	SACI_IDP2
	.globl	SACI_IDPR
	.globl	SACI_IDIPR2
	.globl	SACI_IDIF
	.globl	SACI_IDEGCD
	.globl	SACI_ICOMP
	.globl	SACI_IABSF
	.globl	SACI_AADV
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
	.globl	SACM
	.globl	SACM_SMFMI
	.globl	SACM_MISUM
	.globl	SACM_MIRAN
	.globl	SACM_MIQ
	.globl	SACM_MIPROD
	.globl	SACM_MINEG
	.globl	SACM_MIINV
	.globl	SACM_MIHOM
	.globl	SACM_MIEXP
	.globl	SACM_MIDIF
	.globl	SACM_MIDCRA
	.globl	SACM_MDSUM
	.globl	SACM_MDRAN
	.globl	SACM_MDQ
	.globl	SACM_MDPROD
	.globl	SACM_MDNEG
	.globl	SACM_MDLCRA
	.globl	SACM_MDINV
	.globl	SACM_MDHOM
	.globl	SACM_MDEXP
	.globl	SACM_MDDIF
	.globl	SACM_MDCRA
	.stabs "SACM_SMFMI:F7",36,0,0,SACM_SMFMI
	.align 4
SACM_SMFMI:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,304,.LN1-SACM_SMFMI		# line 304, column 1
.LBB1:
.LN2:
	.stabn  68,0,305,.LN2-SACM_SMFMI		# line 305, column 8
	pushl	8(%ebp)
	pushl	12(%ebp)
	call	SACI_IDIF
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN3:
	.stabn  68,0,306,.LN3-SACM_SMFMI		# line 306, column 7
	pushl	-8(%ebp)
	call	SACI_INEG
	addl	$4, %esp
	pushl	%eax
	pushl	12(%ebp)
	call	SACI_ICOMP
	addl	$8, %esp
	cmpl	$0,%eax
	jg	.Lab2
.Lab3:
.LN4:
	.stabn  68,0,306,.LN4-SACM_SMFMI		# line 306, column 38
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab2:
.LN5:
	.stabn  68,0,307,.LN5-SACM_SMFMI		# line 307, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN6:
	.stabn  68,0,308,.LN6-SACM_SMFMI		# line 308, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 8
	.stabs "B:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB1-SACM_SMFMI
	.stabn 224,0,0,.LBE1-SACM_SMFMI
	.stabs "SACM_MISUM:F7",36,0,0,SACM_MISUM
	.align 4
SACM_MISUM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab4, %esp
.LN7:
	.stabn  68,0,293,.LN7-SACM_MISUM		# line 293, column 1
.LBB2:
.LN8:
	.stabn  68,0,294,.LN8-SACM_MISUM		# line 294, column 8
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	SACI_ISUM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN9:
	.stabn  68,0,294,.LN9-SACM_MISUM		# line 294, column 23
	pushl	8(%ebp)
	pushl	-8(%ebp)
	call	SACI_IDIF
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN10:
	.stabn  68,0,295,.LN10-SACM_MISUM		# line 295, column 7
	pushl	-12(%ebp)
	call	SACI_ISIGNF
	addl	$4, %esp
	cmpl	$0,%eax
	jl	.Lab5
.Lab6:
.LN11:
	.stabn  68,0,295,.LN11-SACM_MISUM		# line 295, column 32
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab5:
.LN12:
	.stabn  68,0,296,.LN12-SACM_MISUM		# line 296, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN13:
	.stabn  68,0,297,.LN13-SACM_MISUM		# line 297, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab4 = 12
	.stabs "CP:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabs "B:p7",160,0,4,16
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACM_MISUM
	.stabn 224,0,0,.LBE2-SACM_MISUM
	.stabs "SACM_MIRAN:F7",36,0,0,SACM_MIRAN
	.align 4
SACM_MIRAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab7, %esp
.LN14:
	.stabn  68,0,283,.LN14-SACM_MIRAN		# line 283, column 1
.LBB3:
.LN15:
	.stabn  68,0,284,.LN15-SACM_MIRAN		# line 284, column 10
	pushl	8(%ebp)
	call	SACI_ILOG2
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN16:
	.stabn  68,0,284,.LN16-SACM_MIRAN		# line 284, column 25
	movl	SACD_s + 4,%eax
 	addl	-8(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN17:
	.stabn  68,0,284,.LN17-SACM_MIRAN		# line 284, column 40
	pushl	-8(%ebp)
	call	SACI_IRAND
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN18:
	.stabn  68,0,284,.LN18-SACM_MIRAN		# line 284, column 55
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACM_MIHOM
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN19:
	.stabn  68,0,285,.LN19-SACM_MIRAN		# line 285, column 7
	movl	-12(%ebp),%eax
	leave
	ret
.LN20:
	.stabn  68,0,286,.LN20-SACM_MIRAN		# line 286, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab7 = 12
	.stabs "R:7",128,0,4,-12
	.stabs "J1Y:7",128,0,4,-8
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-SACM_MIRAN
	.stabn 224,0,0,.LBE3-SACM_MIRAN
	.stabs "SACM_MIQ:F7",36,0,0,SACM_MIQ
	.align 4
SACM_MIQ:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab8, %esp
.LN21:
	.stabn  68,0,274,.LN21-SACM_MIQ		# line 274, column 1
.LBB4:
.LN22:
	.stabn  68,0,275,.LN22-SACM_MIQ		# line 275, column 10
	pushl	16(%ebp)
	pushl	8(%ebp)
	call	SACM_MIINV
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN23:
	.stabn  68,0,275,.LN23-SACM_MIQ		# line 275, column 25
	pushl	-12(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACM_MIPROD
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.LN24:
	.stabn  68,0,275,.LN24-SACM_MIQ		# line 275, column 44
	movl	-8(%ebp),%eax
	leave
	ret
.LN25:
	.stabn  68,0,276,.LN25-SACM_MIQ		# line 276, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab8 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabs "B:p7",160,0,4,16
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACM_MIQ
	.stabn 224,0,0,.LBE4-SACM_MIQ
	.stabs "SACM_MIPROD:F7",36,0,0,SACM_MIPROD
	.align 4
SACM_MIPROD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN26:
	.stabn  68,0,265,.LN26-SACM_MIPROD		# line 265, column 1
.LBB5:
.LN27:
	.stabn  68,0,266,.LN27-SACM_MIPROD		# line 266, column 10
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	SACI_IPROD
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN28:
	.stabn  68,0,266,.LN28-SACM_MIPROD		# line 266, column 25
	pushl	8(%ebp)
	pushl	-12(%ebp)
	call	SACI_IREM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN29:
	.stabn  68,0,266,.LN29-SACM_MIPROD		# line 266, column 40
	movl	-8(%ebp),%eax
	leave
	ret
.LN30:
	.stabn  68,0,267,.LN30-SACM_MIPROD		# line 267, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab9 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "C:7",128,0,4,-8
	.stabs "B:p7",160,0,4,16
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-SACM_MIPROD
	.stabn 224,0,0,.LBE5-SACM_MIPROD
	.stabs "SACM_MINEG:F7",36,0,0,SACM_MINEG
	.align 4
SACM_MINEG:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab10, %esp
.LN31:
	.stabn  68,0,255,.LN31-SACM_MINEG		# line 255, column 1
.LBB6:
.LN32:
	.stabn  68,0,256,.LN32-SACM_MINEG		# line 256, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab13
.Lab12:
.LN33:
	.stabn  68,0,256,.LN33-SACM_MINEG		# line 256, column 22
	movl	$0,-8(%ebp) 
	jmp	.Lab11
.Lab13:
.LN34:
	.stabn  68,0,256,.LN34-SACM_MINEG		# line 256, column 33
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACI_IDIF
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab11:
.LN35:
	.stabn  68,0,257,.LN35-SACM_MINEG		# line 257, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN36:
	.stabn  68,0,258,.LN36-SACM_MINEG		# line 258, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab10 = 8
	.stabs "B:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-SACM_MINEG
	.stabn 224,0,0,.LBE6-SACM_MINEG
	.stabs "SACM_MIINV:F7",36,0,0,SACM_MIINV
	.align 4
SACM_MIINV:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab14, %esp
.LN37:
	.stabn  68,0,244,.LN37-SACM_MIINV		# line 244, column 1
.LBB7:
.LN38:
	.stabn  68,0,245,.LN38-SACM_MIINV		# line 245, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab17
.Lab16:
.LN39:
	.stabn  68,0,245,.LN39-SACM_MIINV		# line 245, column 24
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACD_DEGCD
	addl	$20, %esp
	jmp	.Lab15
.Lab17:
.LN40:
	.stabn  68,0,245,.LN40-SACM_MIINV		# line 245, column 48
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACI_IHEGCD
	addl	$16, %esp
.Lab15:
.LN41:
	.stabn  68,0,246,.LN41-SACM_MIINV		# line 246, column 7
	pushl	-8(%ebp)
	call	SACI_ISIGNF
	addl	$4, %esp
	cmpl	$0,%eax
	jge	.Lab18
.Lab19:
.LN42:
	.stabn  68,0,246,.LN42-SACM_MIINV		# line 246, column 30
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACI_ISUM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab18:
.LN43:
	.stabn  68,0,247,.LN43-SACM_MIINV		# line 247, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN44:
	.stabn  68,0,248,.LN44-SACM_MIINV		# line 248, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab14 = 16
	.stabs "UL:7",128,0,4,-16
	.stabs "C:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-SACM_MIINV
	.stabn 224,0,0,.LBE7-SACM_MIINV
	.stabs "SACM_MIHOM:F7",36,0,0,SACM_MIHOM
	.align 4
SACM_MIHOM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab20, %esp
.LN45:
	.stabn  68,0,233,.LN45-SACM_MIHOM		# line 233, column 1
.LBB8:
.LN46:
	.stabn  68,0,234,.LN46-SACM_MIHOM		# line 234, column 9
	pushl	8(%ebp)
	pushl	12(%ebp)
	call	SACI_IREM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN47:
	.stabn  68,0,235,.LN47-SACM_MIHOM		# line 235, column 7
	pushl	-8(%ebp)
	call	SACI_ISIGNF
	addl	$4, %esp
	cmpl	$0,%eax
	jge	.Lab21
.Lab22:
.LN48:
	.stabn  68,0,235,.LN48-SACM_MIHOM		# line 235, column 32
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACI_ISUM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab21:
.LN49:
	.stabn  68,0,236,.LN49-SACM_MIHOM		# line 236, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN50:
	.stabn  68,0,237,.LN50-SACM_MIHOM		# line 237, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab20 = 8
	.stabs "AS:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-SACM_MIHOM
	.stabn 224,0,0,.LBE8-SACM_MIHOM
	.stabs "SACM_MIEXP:F7",36,0,0,SACM_MIEXP
	.align 4
SACM_MIEXP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab23, %esp
.LN51:
	.stabn  68,0,213,.LN51-SACM_MIEXP		# line 213, column 1
.LBB9:
.LN52:
	.stabn  68,0,215,.LN52-SACM_MIEXP		# line 215, column 7
	movl	8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab24
.Lab26:
	movl	16(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab24
.Lab25:
.LN53:
	.stabn  68,0,215,.LN53-SACM_MIEXP		# line 215, column 42
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACM_MDEXP
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.LN54:
	.stabn  68,0,215,.LN54-SACM_MIEXP		# line 215, column 58
	movl	-8(%ebp),%eax
	leave
	ret
.Lab24:
.LN55:
	.stabn  68,0,218,.LN55-SACM_MIEXP		# line 218, column 7
	cmpl	$0,16(%ebp)
	jne	.Lab27
.Lab28:
.LN56:
	.stabn  68,0,218,.LN56-SACM_MIEXP		# line 218, column 22
	movl	$1,-8(%ebp) 
.LN57:
	.stabn  68,0,218,.LN57-SACM_MIEXP		# line 218, column 27
	movl	-8(%ebp),%eax
	leave
	ret
.Lab27:
.LN58:
	.stabn  68,0,219,.LN58-SACM_MIEXP		# line 219, column 7
	cmpl	$1,16(%ebp)
	jne	.Lab29
.Lab30:
.LN59:
	.stabn  68,0,219,.LN59-SACM_MIEXP		# line 219, column 22
	movl	12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN60:
	.stabn  68,0,219,.LN60-SACM_MIEXP		# line 219, column 27
	movl	-8(%ebp),%eax
	leave
	ret
.Lab29:
.LN61:
	.stabn  68,0,221,.LN61-SACM_MIEXP		# line 221, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab31
.Lab32:
.LN62:
	.stabn  68,0,221,.LN62-SACM_MIEXP		# line 221, column 22
	movl	$0,-8(%ebp) 
.LN63:
	.stabn  68,0,221,.LN63-SACM_MIEXP		# line 221, column 27
	movl	-8(%ebp),%eax
	leave
	ret
.Lab31:
.LN64:
	.stabn  68,0,222,.LN64-SACM_MIEXP		# line 222, column 22
	leal	-16(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	$2
	pushl	16(%ebp)
	call	SACI_IDQR
	addl	$16, %esp
.LN65:
	.stabn  68,0,222,.LN65-SACM_MIEXP		# line 222, column 40
	pushl	-12(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACM_MIEXP
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.LN66:
	.stabn  68,0,223,.LN66-SACM_MIEXP		# line 223, column 8
	pushl	-8(%ebp)
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACM_MIPROD
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.LN67:
	.stabn  68,0,224,.LN67-SACM_MIEXP		# line 224, column 7
	cmpl	$1,-16(%ebp)
	jne	.Lab33
.Lab34:
.LN68:
	.stabn  68,0,224,.LN68-SACM_MIEXP		# line 224, column 23
	pushl	12(%ebp)
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACM_MIPROD
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.Lab33:
.LN69:
	.stabn  68,0,225,.LN69-SACM_MIEXP		# line 225, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN70:
	.stabn  68,0,226,.LN70-SACM_MIEXP		# line 226, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab23 = 16
	.stabs "TL:7",128,0,4,-16
	.stabs "NP:7",128,0,4,-12
	.stabs "B:7",128,0,4,-8
	.stabs "N:p7",160,0,4,16
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-SACM_MIEXP
	.stabn 224,0,0,.LBE9-SACM_MIEXP
	.stabs "SACM_MIDIF:F7",36,0,0,SACM_MIDIF
	.align 4
SACM_MIDIF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab35, %esp
.LN71:
	.stabn  68,0,202,.LN71-SACM_MIDIF		# line 202, column 1
.LBB10:
.LN72:
	.stabn  68,0,203,.LN72-SACM_MIDIF		# line 203, column 8
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	SACI_IDIF
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN73:
	.stabn  68,0,204,.LN73-SACM_MIDIF		# line 204, column 7
	pushl	-8(%ebp)
	call	SACI_ISIGNF
	addl	$4, %esp
	cmpl	$0,%eax
	jge	.Lab36
.Lab37:
.LN74:
	.stabn  68,0,204,.LN74-SACM_MIDIF		# line 204, column 30
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACI_ISUM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab36:
.LN75:
	.stabn  68,0,205,.LN75-SACM_MIDIF		# line 205, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN76:
	.stabn  68,0,206,.LN76-SACM_MIDIF		# line 206, column 0
	call	ReturnErr_
.LBE10:
	leave
	ret
	.Lab35 = 8
	.stabs "C:7",128,0,4,-8
	.stabs "B:p7",160,0,4,16
	.stabs "A:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB10-SACM_MIDIF
	.stabn 224,0,0,.LBE10-SACM_MIDIF
	.stabs "SACM_MIDCRA:F7",36,0,0,SACM_MIDCRA
	.align 4
SACM_MIDCRA:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab38, %esp
.LN77:
	.stabn  68,0,189,.LN77-SACM_MIDCRA		# line 189, column 1
.LBB11:
.LN78:
	.stabn  68,0,190,.LN78-SACM_MIDCRA		# line 190, column 20
	pushl	20(%ebp)
	pushl	12(%ebp)
	call	SACM_MDHOM
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN79:
	.stabn  68,0,190,.LN79-SACM_MIDCRA		# line 190, column 37
	pushl	-8(%ebp)
	pushl	24(%ebp)
	pushl	12(%ebp)
	call	SACM_MDDIF
	addl	$12, %esp
	movl	%eax,-20(%ebp) 
.LN80:
	.stabn  68,0,191,.LN80-SACM_MIDCRA		# line 191, column 7
	cmpl	$0,-20(%ebp)
	jne	.Lab39
.Lab40:
.LN81:
	.stabn  68,0,191,.LN81-SACM_MIDCRA		# line 191, column 24
	movl	20(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN82:
	.stabn  68,0,191,.LN82-SACM_MIDCRA		# line 191, column 29
	movl	-12(%ebp),%eax
	leave
	ret
.Lab39:
.LN83:
	.stabn  68,0,192,.LN83-SACM_MIDCRA		# line 192, column 27
	pushl	16(%ebp)
	pushl	-20(%ebp)
	pushl	12(%ebp)
	call	SACM_MDPROD
	addl	$12, %esp
	movl	%eax,-16(%ebp) 
.LN84:
	.stabn  68,0,193,.LN84-SACM_MIDCRA		# line 193, column 7
	movl	-16(%ebp),%eax
 	addl	-16(%ebp),%eax 
	cmpl	12(%ebp),%eax
	jle	.Lab41
.Lab42:
.LN85:
	.stabn  68,0,193,.LN85-SACM_MIDCRA		# line 193, column 28
	movl	-16(%ebp),%eax
 	subl	12(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.Lab41:
.LN86:
	.stabn  68,0,194,.LN86-SACM_MIDCRA		# line 194, column 10
	pushl	-16(%ebp)
	pushl	8(%ebp)
	call	SACI_IDPR
	addl	$8, %esp
	movl	%eax,-24(%ebp) 
.LN87:
	.stabn  68,0,194,.LN87-SACM_MIDCRA		# line 194, column 26
	pushl	20(%ebp)
	pushl	-24(%ebp)
	call	SACI_ISUM
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN88:
	.stabn  68,0,194,.LN88-SACM_MIDCRA		# line 194, column 41
	movl	-12(%ebp),%eax
	leave
	ret
.LN89:
	.stabn  68,0,195,.LN89-SACM_MIDCRA		# line 195, column 0
	call	ReturnErr_
.LBE11:
	leave
	ret
	.Lab38 = 24
	.stabs "J1Y:7",128,0,4,-24
	.stabs "DL:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "AS:7",128,0,4,-12
	.stabs "ALB:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,24
	.stabs "A:p7",160,0,4,20
	.stabs "MLP:p7",160,0,4,16
	.stabs "ML:p7",160,0,4,12
	.stabs "M:p7",160,0,4,8
	.stabn 192,0,0,.LBB11-SACM_MIDCRA
	.stabn 224,0,0,.LBE11-SACM_MIDCRA
	.stabs "SACM_MDSUM:F7",36,0,0,SACM_MDSUM
	.align 4
SACM_MDSUM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab43, %esp
.LN90:
	.stabn  68,0,174,.LN90-SACM_MDSUM		# line 174, column 1
.LBB12:
.LN91:
	.stabn  68,0,175,.LN91-SACM_MDSUM		# line 175, column 9
	movl	16(%ebp),%eax
 	addl	12(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN92:
	.stabn  68,0,175,.LN92-SACM_MDSUM		# line 175, column 21
	movl	-8(%ebp),%eax
 	subl	8(%ebp),%eax 
	movl	%eax,-12(%ebp) 
.LN93:
	.stabn  68,0,176,.LN93-SACM_MDSUM		# line 176, column 7
	cmpl	$0,-12(%ebp)
	jl	.Lab44
.Lab45:
.LN94:
	.stabn  68,0,176,.LN94-SACM_MDSUM		# line 176, column 26
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.Lab44:
.LN95:
	.stabn  68,0,177,.LN95-SACM_MDSUM		# line 177, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN96:
	.stabn  68,0,178,.LN96-SACM_MDSUM		# line 178, column 0
	call	ReturnErr_
.LBE12:
	leave
	ret
	.Lab43 = 12
	.stabs "CLP:7",128,0,4,-12
	.stabs "CL:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,16
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB12-SACM_MDSUM
	.stabn 224,0,0,.LBE12-SACM_MDSUM
	.stabs "SACM_MDRAN:F7",36,0,0,SACM_MDRAN
	.align 4
SACM_MDRAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab46, %esp
.LN97:
	.stabn  68,0,161,.LN97-SACM_MDRAN		# line 161, column 1
.LBB13:
.LN98:
	.stabn  68,0,162,.LN98-SACM_MDRAN		# line 162, column 10
	call	SACD_DRAN
	movl	%eax,-32(%ebp) 
.LN99:
	.stabn  68,0,162,.LN99-SACM_MDRAN		# line 162, column 23
	pushl	-32(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-20(%ebp) 
.LN100:
	.stabn  68,0,162,.LN100-SACM_MDRAN		# line 162, column 38
	leal	-36(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	pushl	-20(%ebp)
	call	SACD_DPR
	addl	$16, %esp
.LN101:
	.stabn  68,0,163,.LN101-SACM_MDRAN		# line 163, column 7
	movl	8(%ebp),%eax
	cmpl	SACD_s + 8,%eax
	jg	.Lab47
.Lab48:
.LN102:
	.stabn  68,0,163,.LN102-SACM_MDRAN		# line 163, column 27
	movl	-8(%ebp),%eax
	leave
	ret
.Lab47:
.LN103:
	.stabn  68,0,164,.LN103-SACM_MDRAN		# line 164, column 10
	movl	-8(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN104:
	.stabn  68,0,164,.LN104-SACM_MDRAN		# line 164, column 19
	call	SACD_DRAN
	movl	%eax,-32(%ebp) 
.LN105:
	.stabn  68,0,164,.LN105-SACM_MDRAN		# line 164, column 32
	pushl	-32(%ebp)
	call	MASELEM_MASABS
	addl	$4, %esp
	movl	%eax,-24(%ebp) 
.LN106:
	.stabn  68,0,164,.LN106-SACM_MDRAN		# line 164, column 47
	leal	-16(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	pushl	-24(%ebp)
	call	SACD_DPR
	addl	$16, %esp
.LN107:
	.stabn  68,0,165,.LN107-SACM_MDRAN		# line 165, column 7
	movl	-16(%ebp),%eax
 	addl	-12(%ebp),%eax 
	cmpl	MASSTOR_s,%eax
	jl	.Lab49
.Lab50:
.LN108:
	.stabn  68,0,165,.LN108-SACM_MDRAN		# line 165, column 33
	incl	-8(%ebp)
.Lab49:
.LN109:
	.stabn  68,0,166,.LN109-SACM_MDRAN		# line 166, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN110:
	.stabn  68,0,167,.LN110-SACM_MDRAN		# line 167, column 0
	call	ReturnErr_
.LBE13:
	leave
	ret
	.Lab46 = 36
	.stabs "TL:7",128,0,4,-36
	.stabs "J1Y:7",128,0,4,-32
	.stabs "IDUM:7",128,0,4,-28
	.stabs "DL2:7",128,0,4,-24
	.stabs "DL1:7",128,0,4,-20
	.stabs "AL2:7",128,0,4,-16
	.stabs "AL1:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB13-SACM_MDRAN
	.stabn 224,0,0,.LBE13-SACM_MDRAN
	.stabs "SACM_MDQ:F7",36,0,0,SACM_MDQ
	.align 4
SACM_MDQ:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab51, %esp
.LN111:
	.stabn  68,0,152,.LN111-SACM_MDQ		# line 152, column 1
.LBB14:
.LN112:
	.stabn  68,0,153,.LN112-SACM_MDQ		# line 153, column 10
	pushl	16(%ebp)
	pushl	8(%ebp)
	call	SACM_MDINV
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN113:
	.stabn  68,0,153,.LN113-SACM_MDQ		# line 153, column 28
	pushl	-12(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACM_MDPROD
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.LN114:
	.stabn  68,0,153,.LN114-SACM_MDQ		# line 153, column 49
	movl	-8(%ebp),%eax
	leave
	ret
.LN115:
	.stabn  68,0,154,.LN115-SACM_MDQ		# line 154, column 0
	call	ReturnErr_
.LBE14:
	leave
	ret
	.Lab51 = 12
	.stabs "J1Y:7",128,0,4,-12
	.stabs "CL:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,16
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB14-SACM_MDQ
	.stabn 224,0,0,.LBE14-SACM_MDQ
	.stabs "SACM_MDPROD:F7",36,0,0,SACM_MDPROD
	.align 4
SACM_MDPROD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab52, %esp
.LN116:
	.stabn  68,0,143,.LN116-SACM_MDPROD		# line 143, column 1
.LBB15:
.LN117:
	.stabn  68,0,144,.LN117-SACM_MDPROD		# line 144, column 7
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	16(%ebp)
	pushl	12(%ebp)
	call	SACD_DPR
	addl	$16, %esp
.LN118:
	.stabn  68,0,144,.LN118-SACM_MDPROD		# line 144, column 27
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-20(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	pushl	-12(%ebp)
	pushl	-16(%ebp)
	call	SACD_DQR
	addl	$20, %esp
.LN119:
	.stabn  68,0,144,.LN119-SACM_MDPROD		# line 144, column 50
	movl	-8(%ebp),%eax
	leave
	ret
.LN120:
	.stabn  68,0,145,.LN120-SACM_MDPROD		# line 145, column 0
	call	ReturnErr_
.LBE15:
	leave
	ret
	.Lab52 = 20
	.stabs "QL:7",128,0,4,-20
	.stabs "CL1:7",128,0,4,-16
	.stabs "CL0:7",128,0,4,-12
	.stabs "CL:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,16
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB15-SACM_MDPROD
	.stabn 224,0,0,.LBE15-SACM_MDPROD
	.stabs "SACM_MDNEG:F7",36,0,0,SACM_MDNEG
	.align 4
SACM_MDNEG:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab53, %esp
.LN121:
	.stabn  68,0,133,.LN121-SACM_MDNEG		# line 133, column 1
.LBB16:
.LN122:
	.stabn  68,0,134,.LN122-SACM_MDNEG		# line 134, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab56
.Lab55:
.LN123:
	.stabn  68,0,134,.LN123-SACM_MDNEG		# line 134, column 24
	movl	$0,-8(%ebp) 
	jmp	.Lab54
.Lab56:
.LN124:
	.stabn  68,0,134,.LN124-SACM_MDNEG		# line 134, column 36
	movl	8(%ebp),%eax
 	subl	12(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.Lab54:
.LN125:
	.stabn  68,0,135,.LN125-SACM_MDNEG		# line 135, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN126:
	.stabn  68,0,136,.LN126-SACM_MDNEG		# line 136, column 0
	call	ReturnErr_
.LBE16:
	leave
	ret
	.Lab53 = 8
	.stabs "BL:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB16-SACM_MDNEG
	.stabn 224,0,0,.LBE16-SACM_MDNEG
	.stabs "SACM_MDLCRA:F7",36,0,0,SACM_MDLCRA
	.align 4
SACM_MDLCRA:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab57, %esp
.LN127:
	.stabn  68,0,119,.LN127-SACM_MDLCRA		# line 119, column 1
.LBB17:
.LN128:
	.stabn  68,0,120,.LN128-SACM_MDLCRA		# line 120, column 11
	pushl	8(%ebp)
	pushl	12(%ebp)
	call	SACM_MDINV
	addl	$8, %esp
	movl	%eax,-32(%ebp) 
.LN129:
	.stabn  68,0,120,.LN129-SACM_MDLCRA		# line 120, column 30
	movl	MASSTOR_s,%eax
	movl	%eax,-20(%ebp) 
.LN130:
	.stabn  68,0,120,.LN130-SACM_MDLCRA		# line 120, column 41
	movl	16(%ebp),%eax
	movl	%eax,-24(%ebp) 
	jmp	.Lab58
.Lab59:
.LN131:
	.stabn  68,0,121,.LN131-SACM_MDLCRA		# line 121, column 27
	leal	-24(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	-24(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN132:
	.stabn  68,0,121,.LN132-SACM_MDLCRA		# line 121, column 48
	movl	20(%ebp),%eax
	movl	%eax,-28(%ebp) 
	jmp	.Lab61
.Lab62:
.LN133:
	.stabn  68,0,122,.LN133-SACM_MDLCRA		# line 122, column 33
	leal	-28(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	-28(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN134:
	.stabn  68,0,123,.LN134-SACM_MDLCRA		# line 123, column 21
	pushl	-16(%ebp)
	pushl	-12(%ebp)
	pushl	-32(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACM_MDCRA
	addl	$20, %esp
	movl	%eax,-8(%ebp) 
.LN135:
	.stabn  68,0,123,.LN135-SACM_MDLCRA		# line 123, column 53
	pushl	-20(%ebp)
	pushl	-8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	movl	%eax,-20(%ebp) 
.Lab61:
.LN136:
	.stabn  68,0,122,.LN136-SACM_MDLCRA		# line 122, column 23
	movl	-28(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab62
.Lab63:
.Lab58:
.LN137:
	.stabn  68,0,121,.LN137-SACM_MDLCRA		# line 121, column 17
	movl	-24(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab59
.Lab60:
.LN138:
	.stabn  68,0,125,.LN138-SACM_MDLCRA		# line 125, column 7
	movl	-20(%ebp),%eax
	leave
	ret
.LN139:
	.stabn  68,0,126,.LN139-SACM_MDLCRA		# line 126, column 0
	call	ReturnErr_
.LBE17:
	leave
	ret
	.Lab57 = 32
	.stabs "MLP1:7",128,0,4,-32
	.stabs "LP2:7",128,0,4,-28
	.stabs "LP1:7",128,0,4,-24
	.stabs "L:7",128,0,4,-20
	.stabs "AL2:7",128,0,4,-16
	.stabs "AL1:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "L2:p7",160,0,4,20
	.stabs "L1:p7",160,0,4,16
	.stabs "ML2:p7",160,0,4,12
	.stabs "ML1:p7",160,0,4,8
	.stabn 192,0,0,.LBB17-SACM_MDLCRA
	.stabn 224,0,0,.LBE17-SACM_MDLCRA
	.stabs "SACM_MDINV:F7",36,0,0,SACM_MDINV
	.align 4
SACM_MDINV:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab64, %esp
.LN140:
	.stabn  68,0,101,.LN140-SACM_MDINV		# line 101, column 1
.LBB18:
.LN141:
	.stabn  68,0,102,.LN141-SACM_MDINV		# line 102, column 10
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN142:
	.stabn  68,0,102,.LN142-SACM_MDINV		# line 102, column 19
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN143:
	.stabn  68,0,102,.LN143-SACM_MDINV		# line 102, column 28
	movl	$0,-32(%ebp) 
.LN144:
	.stabn  68,0,102,.LN144-SACM_MDINV		# line 102, column 36
	movl	$1,-36(%ebp) 
	jmp	.Lab65
.Lab66:
.LN145:
	.stabn  68,0,103,.LN145-SACM_MDINV		# line 103, column 27
	movl	-8(%ebp),%eax
	movl	-12(%ebp),%ebx
	cdq
	idivl	%ebx
	movl	%eax,-28(%ebp) 
.LN146:
	.stabn  68,0,103,.LN146-SACM_MDINV		# line 103, column 45
	movl	-12(%ebp),%eax
	imull	-28(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN147:
	.stabn  68,0,103,.LN147-SACM_MDINV		# line 103, column 58
	movl	-8(%ebp),%eax
 	subl	-24(%ebp),%eax 
	movl	%eax,-16(%ebp) 
.LN148:
	.stabn  68,0,104,.LN148-SACM_MDINV		# line 104, column 16
	movl	-36(%ebp),%eax
	imull	-28(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN149:
	.stabn  68,0,104,.LN149-SACM_MDINV		# line 104, column 29
	movl	-32(%ebp),%eax
 	subl	-24(%ebp),%eax 
	movl	%eax,-40(%ebp) 
.LN150:
	.stabn  68,0,104,.LN150-SACM_MDINV		# line 104, column 43
	movl	-12(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN151:
	.stabn  68,0,104,.LN151-SACM_MDINV		# line 104, column 53
	movl	-16(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN152:
	.stabn  68,0,104,.LN152-SACM_MDINV		# line 104, column 63
	movl	-36(%ebp),%eax
	movl	%eax,-32(%ebp) 
.LN153:
	.stabn  68,0,105,.LN153-SACM_MDINV		# line 105, column 16
	movl	-40(%ebp),%eax
	movl	%eax,-36(%ebp) 
.Lab65:
.LN154:
	.stabn  68,0,103,.LN154-SACM_MDINV		# line 103, column 17
	cmpl	$1,-12(%ebp)
	jne	.Lab66
.Lab67:
.LN155:
	.stabn  68,0,106,.LN155-SACM_MDINV		# line 106, column 7
	cmpl	$0,-36(%ebp)
	jl	.Lab70
.Lab69:
.LN156:
	.stabn  68,0,106,.LN156-SACM_MDINV		# line 106, column 26
	movl	-36(%ebp),%eax
	movl	%eax,-20(%ebp) 
	jmp	.Lab68
.Lab70:
.LN157:
	.stabn  68,0,106,.LN157-SACM_MDINV		# line 106, column 40
	movl	8(%ebp),%eax
 	addl	-36(%ebp),%eax 
	movl	%eax,-20(%ebp) 
.Lab68:
.LN158:
	.stabn  68,0,107,.LN158-SACM_MDINV		# line 107, column 7
	movl	-20(%ebp),%eax
	leave
	ret
.LN159:
	.stabn  68,0,108,.LN159-SACM_MDINV		# line 108, column 0
	call	ReturnErr_
.LBE18:
	leave
	ret
	.Lab64 = 40
	.stabs "VL3:7",128,0,4,-40
	.stabs "VL2:7",128,0,4,-36
	.stabs "VL1:7",128,0,4,-32
	.stabs "QL:7",128,0,4,-28
	.stabs "J1Y:7",128,0,4,-24
	.stabs "BL:7",128,0,4,-20
	.stabs "AL3:7",128,0,4,-16
	.stabs "AL2:7",128,0,4,-12
	.stabs "AL1:7",128,0,4,-8
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB18-SACM_MDINV
	.stabn 224,0,0,.LBE18-SACM_MDINV
	.stabs "SACM_MDHOM:F7",36,0,0,SACM_MDHOM
	.align 4
SACM_MDHOM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab71, %esp
.LN160:
	.stabn  68,0,90,.LN160-SACM_MDHOM		# line 90, column 1
.LBB19:
.LN161:
	.stabn  68,0,91,.LN161-SACM_MDHOM		# line 91, column 7
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	pushl	12(%ebp)
	call	SACI_IDQR
	addl	$16, %esp
.LN162:
	.stabn  68,0,92,.LN162-SACM_MDHOM		# line 92, column 7
	cmpl	$0,-8(%ebp)
	jge	.Lab72
.Lab73:
.LN163:
	.stabn  68,0,92,.LN163-SACM_MDHOM		# line 92, column 24
	movl	8(%ebp),%eax
 	addl	-8(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.Lab72:
.LN164:
	.stabn  68,0,93,.LN164-SACM_MDHOM		# line 93, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN165:
	.stabn  68,0,94,.LN165-SACM_MDHOM		# line 94, column 0
	call	ReturnErr_
.LBE19:
	leave
	ret
	.Lab71 = 12
	.stabs "Q:7",128,0,4,-12
	.stabs "BL:7",128,0,4,-8
	.stabs "A:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB19-SACM_MDHOM
	.stabn 224,0,0,.LBE19-SACM_MDHOM
	.stabs "SACM_MDEXP:F7",36,0,0,SACM_MDEXP
	.align 4
SACM_MDEXP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab74, %esp
.LN166:
	.stabn  68,0,75,.LN166-SACM_MDEXP		# line 75, column 1
.LBB20:
.LN167:
	.stabn  68,0,77,.LN167-SACM_MDEXP		# line 77, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab75
.Lab77:
	cmpl	$0,16(%ebp)
	jle	.Lab75
.Lab76:
.LN168:
	.stabn  68,0,77,.LN168-SACM_MDEXP		# line 77, column 39
	movl	$0,-8(%ebp) 
.LN169:
	.stabn  68,0,77,.LN169-SACM_MDEXP		# line 77, column 44
	movl	-8(%ebp),%eax
	leave
	ret
.Lab75:
.LN170:
	.stabn  68,0,78,.LN170-SACM_MDEXP		# line 78, column 22
	movl	$1,-8(%ebp) 
.LN171:
	.stabn  68,0,78,.LN171-SACM_MDEXP		# line 78, column 29
	movl	12(%ebp),%eax
	movl	%eax,-12(%ebp) 
.LN172:
	.stabn  68,0,78,.LN172-SACM_MDEXP		# line 78, column 38
	movl	16(%ebp),%eax
	movl	%eax,-16(%ebp) 
	jmp	.Lab78
.Lab79:
.LN173:
	.stabn  68,0,80,.LN173-SACM_MDEXP		# line 80, column 13
	movl	-16(%ebp),%eax
	andl	$1,%eax
	xorl	$1,%eax
	jnz	.Lab81
.Lab82:
.LN174:
	.stabn  68,0,80,.LN174-SACM_MDEXP		# line 80, column 32
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	pushl	8(%ebp)
	call	SACM_MDPROD
	addl	$12, %esp
	movl	%eax,-8(%ebp) 
.Lab81:
.LN175:
	.stabn  68,0,81,.LN175-SACM_MDEXP		# line 81, column 15
	pushl	-12(%ebp)
	pushl	-12(%ebp)
	pushl	8(%ebp)
	call	SACM_MDPROD
	addl	$12, %esp
	movl	%eax,-12(%ebp) 
.LN176:
	.stabn  68,0,81,.LN176-SACM_MDEXP		# line 81, column 38
	sarl	$1, -16(%ebp)
.Lab78:
.LN177:
	.stabn  68,0,79,.LN177-SACM_MDEXP		# line 79, column 17
	cmpl	$0,-16(%ebp)
	jne	.Lab79
.Lab80:
.LN178:
	.stabn  68,0,82,.LN178-SACM_MDEXP		# line 82, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN179:
	.stabn  68,0,83,.LN179-SACM_MDEXP		# line 83, column 0
	call	ReturnErr_
.LBE20:
	leave
	ret
	.Lab74 = 16
	.stabs "NLP:7",128,0,4,-16
	.stabs "CL:7",128,0,4,-12
	.stabs "BL:7",128,0,4,-8
	.stabs "NL:p7",160,0,4,16
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB20-SACM_MDEXP
	.stabn 224,0,0,.LBE20-SACM_MDEXP
	.stabs "SACM_MDDIF:F7",36,0,0,SACM_MDDIF
	.align 4
SACM_MDDIF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab83, %esp
.LN180:
	.stabn  68,0,64,.LN180-SACM_MDDIF		# line 64, column 1
.LBB21:
.LN181:
	.stabn  68,0,65,.LN181-SACM_MDDIF		# line 65, column 9
	movl	12(%ebp),%eax
 	subl	16(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN182:
	.stabn  68,0,66,.LN182-SACM_MDDIF		# line 66, column 7
	cmpl	$0,-8(%ebp)
	jge	.Lab84
.Lab85:
.LN183:
	.stabn  68,0,66,.LN183-SACM_MDDIF		# line 66, column 24
	movl	8(%ebp),%eax
 	addl	-8(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.Lab84:
.LN184:
	.stabn  68,0,67,.LN184-SACM_MDDIF		# line 67, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN185:
	.stabn  68,0,68,.LN185-SACM_MDDIF		# line 68, column 0
	call	ReturnErr_
.LBE21:
	leave
	ret
	.Lab83 = 8
	.stabs "CL:7",128,0,4,-8
	.stabs "BL:p7",160,0,4,16
	.stabs "AL:p7",160,0,4,12
	.stabs "ML:p7",160,0,4,8
	.stabn 192,0,0,.LBB21-SACM_MDDIF
	.stabn 224,0,0,.LBE21-SACM_MDDIF
	.stabs "SACM_MDCRA:F7",36,0,0,SACM_MDCRA
	.align 4
SACM_MDCRA:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab86, %esp
.LN186:
	.stabn  68,0,52,.LN186-SACM_MDCRA		# line 52, column 1
.LBB22:
.LN187:
	.stabn  68,0,53,.LN187-SACM_MDCRA		# line 53, column 22
	pushl	12(%ebp)
	pushl	20(%ebp)
	call	MASELEM_MASREM
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN188:
	.stabn  68,0,53,.LN188-SACM_MDCRA		# line 53, column 43
	pushl	-12(%ebp)
	pushl	24(%ebp)
	pushl	12(%ebp)
	call	SACM_MDDIF
	addl	$12, %esp
	movl	%eax,-20(%ebp) 
.LN189:
	.stabn  68,0,54,.LN189-SACM_MDCRA		# line 54, column 7
	cmpl	$0,-20(%ebp)
	jne	.Lab87
.Lab88:
.LN190:
	.stabn  68,0,54,.LN190-SACM_MDCRA		# line 54, column 24
	movl	20(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN191:
	.stabn  68,0,54,.LN191-SACM_MDCRA		# line 54, column 31
	movl	-8(%ebp),%eax
	leave
	ret
.Lab87:
.LN192:
	.stabn  68,0,55,.LN192-SACM_MDCRA		# line 55, column 28
	movl	16(%ebp),%eax
	imull	-20(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN193:
	.stabn  68,0,55,.LN193-SACM_MDCRA		# line 55, column 41
	pushl	12(%ebp)
	pushl	-24(%ebp)
	call	MASELEM_MASREM
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN194:
	.stabn  68,0,55,.LN194-SACM_MDCRA		# line 55, column 63
	movl	-16(%ebp),%eax
	imull	8(%ebp),%eax 
	movl	%eax,-24(%ebp) 
.LN195:
	.stabn  68,0,56,.LN195-SACM_MDCRA		# line 56, column 9
	movl	20(%ebp),%eax
 	addl	-24(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN196:
	.stabn  68,0,56,.LN196-SACM_MDCRA		# line 56, column 20
	movl	-8(%ebp),%eax
	leave
	ret
.LN197:
	.stabn  68,0,57,.LN197-SACM_MDCRA		# line 57, column 0
	call	ReturnErr_
.LBE22:
	leave
	ret
	.Lab86 = 24
	.stabs "J1Y:7",128,0,4,-24
	.stabs "DL:7",128,0,4,-20
	.stabs "BL:7",128,0,4,-16
	.stabs "ALB:7",128,0,4,-12
	.stabs "AL:7",128,0,4,-8
	.stabs "AL2:p7",160,0,4,24
	.stabs "AL1:p7",160,0,4,20
	.stabs "MLP1:p7",160,0,4,16
	.stabs "ML2:p7",160,0,4,12
	.stabs "ML1:p7",160,0,4,8
	.stabn 192,0,0,.LBB22-SACM_MDCRA
	.stabn 224,0,0,.LBE22-SACM_MDCRA
	.stabs "SACM:F16",36,0,0,SACM
	.align 4
SACM:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab89, %esp
.LN198:
	.stabn  68,0,311,.LN198-SACM		# line 311, column 1
.LBB23:
.LN199:
	.stabn  68,0,312,.LN199-SACM		# line 312, column 0
.LBE23:
	leave
	ret
	.Lab89 = 4
	.stabn 192,0,0,.LBB23-SACM
	.stabn 224,0,0,.LBE23-SACM
