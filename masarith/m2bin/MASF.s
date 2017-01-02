	.comm MASF_s, 16
	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "MASF.mod",100,0,0,.LBB0
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
	.globl	MathLib_entierL
	.globl	MathLib_entier
	.globl	MathLib_realL
	.globl	MathLib_real
	.globl	MathLib_arctanL
	.globl	MathLib_arctan
	.globl	MathLib_cosL
	.globl	MathLib_cos
	.globl	MathLib_sinL
	.globl	MathLib_sin
	.globl	MathLib_lnL
	.globl	MathLib_ln
	.globl	MathLib_expL
	.globl	MathLib_exp
	.globl	MathLib_sqrtL
	.globl	MathLib_sqrt
	.globl	SACRN_RNWRIT
	.globl	SACRN_RNSUM
	.globl	SACRN_RNSIGN
	.globl	SACRN_RNRED
	.globl	SACRN_RNREAD
	.globl	SACRN_RNRAND
	.globl	SACRN_RNQ
	.globl	SACRN_RNP2
	.globl	SACRN_RNPROD
	.globl	SACRN_RNNUM
	.globl	SACRN_RNNEG
	.globl	SACRN_RNINV
	.globl	SACRN_RNINT
	.globl	SACRN_RNFLOR
	.globl	SACRN_RNFCL2
	.globl	SACRN_RNDWR
	.globl	SACRN_RNDIF
	.globl	SACRN_RNDEN
	.globl	SACRN_RNCOMP
	.globl	SACRN_RNCEIL
	.globl	SACRN_RNABS
	.globl	SACRN_RIRNP
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
	.globl	MASF
	.globl	MASF_InitFLOAT
	.globl	MASF_SQRT
	.globl	MASF_LOG
	.globl	MASF_LN
	.globl	MASF_EXPF
	.globl	MASF_ARCTAN
	.globl	MASF_TAN
	.globl	MASF_COS
	.globl	MASF_SIN
	.globl	MASF_RNFF
	.globl	MASF_FFRN
	.globl	MASF_FFINT
	.globl	MASF_FLOG10
	.globl	MASF_FEXP
	.globl	MASF_IFF
	.globl	MASF_FFGI
	.stabs "MASF_InitFLOAT:F16",36,0,0,MASF_InitFLOAT
	.align 4
MASF_InitFLOAT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,252,.LN1-MASF_InitFLOAT		# line 252, column 1
.LBB1:
.LN2:
	.stabn  68,0,254,.LN2-MASF_InitFLOAT		# line 254, column 12
	pushl	$15
	pushl	$2
	call	MASELEM_MASEXP
	addl	$8, %esp
	movl	%eax,MASF_s + 8 
.LN3:
	.stabn  68,0,256,.LN3-MASF_InitFLOAT		# line 256, column 12
	pushl	$29
	pushl	$2
	call	MASELEM_MASEXP
	addl	$8, %esp
	pushl	%eax
	call	MASF_FFGI
	addl	$4, %esp
	fstps	MASF_s
.LN4:
	.stabn  68,0,257,.LN4-MASF_InitFLOAT		# line 257, column 13
	pushl	$15
	pushl	$2
	call	MASELEM_MASEXP
	addl	$8, %esp
	pushl	%eax
	call	MASF_FFGI
	addl	$4, %esp
	fstps	MASF_s + 4
.LN5:
	.stabn  68,0,259,.LN5-MASF_InitFLOAT		# line 259, column 12
	pushl	$29
	pushl	$2
	call	SACI_IEXP
	addl	$8, %esp
	movl	%eax,MASF_s + 12 
.LN6:
	.stabn  68,0,260,.LN6-MASF_InitFLOAT		# line 260, column 0
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabn 192,0,0,.LBB1-MASF_InitFLOAT
	.stabn 224,0,0,.LBE1-MASF_InitFLOAT
	.stabs "MASF_SQRT:F7",36,0,0,MASF_SQRT
	.align 4
MASF_SQRT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab2, %esp
.LN7:
	.stabn  68,0,243,.LN7-MASF_SQRT		# line 243, column 1
.LBB2:
.LN8:
	.stabn  68,0,245,.LN8-MASF_SQRT		# line 245, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN9:
	.stabn  68,0,245,.LN9-MASF_SQRT		# line 245, column 20
	flds	-12(%ebp)
	fsqrt
	fstps	-12(%ebp)
.LN10:
	.stabn  68,0,245,.LN10-MASF_SQRT		# line 245, column 32
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN11:
	.stabn  68,0,246,.LN11-MASF_SQRT		# line 246, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN12:
	.stabn  68,0,247,.LN12-MASF_SQRT		# line 247, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab2 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-MASF_SQRT
	.stabn 224,0,0,.LBE2-MASF_SQRT
	.stabs "MASF_LOG:F7",36,0,0,MASF_LOG
	.align 4
MASF_LOG:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab3, %esp
.LN13:
	.stabn  68,0,232,.LN13-MASF_LOG		# line 232, column 1
.LBB3:
.LN14:
	.stabn  68,0,234,.LN14-MASF_LOG		# line 234, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN15:
	.stabn  68,0,234,.LN15-MASF_LOG		# line 234, column 20
	fldl	RealLn2_
	flds	-12(%ebp)
	fyl2x
	fldl	RealLn2_
	.data
	.align 4
.Lab4:
	.long	1092616192		# +0.09999999999999998E2
	.text
	flds	.Lab4
	fyl2x
	fdivrp	%st,%st(1)
	fstps	-12(%ebp)
.LN16:
	.stabn  68,0,234,.LN16-MASF_LOG		# line 234, column 39
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN17:
	.stabn  68,0,235,.LN17-MASF_LOG		# line 235, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN18:
	.stabn  68,0,236,.LN18-MASF_LOG		# line 236, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab3 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-MASF_LOG
	.stabn 224,0,0,.LBE3-MASF_LOG
	.stabs "MASF_LN:F7",36,0,0,MASF_LN
	.align 4
MASF_LN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab5, %esp
.LN19:
	.stabn  68,0,221,.LN19-MASF_LN		# line 221, column 1
.LBB4:
.LN20:
	.stabn  68,0,223,.LN20-MASF_LN		# line 223, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN21:
	.stabn  68,0,223,.LN21-MASF_LN		# line 223, column 20
	fldl	RealLn2_
	flds	-12(%ebp)
	fyl2x
	fstps	-12(%ebp)
.LN22:
	.stabn  68,0,223,.LN22-MASF_LN		# line 223, column 30
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN23:
	.stabn  68,0,224,.LN23-MASF_LN		# line 224, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN24:
	.stabn  68,0,225,.LN24-MASF_LN		# line 225, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab5 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-MASF_LN
	.stabn 224,0,0,.LBE4-MASF_LN
	.stabs "MASF_EXPF:F7",36,0,0,MASF_EXPF
	.align 4
MASF_EXPF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab6, %esp
.LN25:
	.stabn  68,0,210,.LN25-MASF_EXPF		# line 210, column 1
.LBB5:
.LN26:
	.stabn  68,0,212,.LN26-MASF_EXPF		# line 212, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN27:
	.stabn  68,0,212,.LN27-MASF_EXPF		# line 212, column 20
	flds	-12(%ebp)
	fmull	RealLog2e_
	fld	%st
	fldcw	fpucw_round_to_nearest
	frndint
	fld	%st
	fsubr	%st(2),%st
	f2xm1
	fadds	RealOne_
	fscale
	fstp	%st(1)
	fstp	%st(1)
	fstps	-12(%ebp)
.LN28:
	.stabn  68,0,212,.LN28-MASF_EXPF		# line 212, column 31
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN29:
	.stabn  68,0,213,.LN29-MASF_EXPF		# line 213, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN30:
	.stabn  68,0,214,.LN30-MASF_EXPF		# line 214, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab6 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB5-MASF_EXPF
	.stabn 224,0,0,.LBE5-MASF_EXPF
	.stabs "MASF_ARCTAN:F7",36,0,0,MASF_ARCTAN
	.align 4
MASF_ARCTAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab7, %esp
.LN31:
	.stabn  68,0,199,.LN31-MASF_ARCTAN		# line 199, column 1
.LBB6:
.LN32:
	.stabn  68,0,201,.LN32-MASF_ARCTAN		# line 201, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN33:
	.stabn  68,0,201,.LN33-MASF_ARCTAN		# line 201, column 20
	flds	-12(%ebp)
	flds	RealOne_
	fpatan
	fstps	-12(%ebp)
.LN34:
	.stabn  68,0,201,.LN34-MASF_ARCTAN		# line 201, column 34
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN35:
	.stabn  68,0,202,.LN35-MASF_ARCTAN		# line 202, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN36:
	.stabn  68,0,203,.LN36-MASF_ARCTAN		# line 203, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab7 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB6-MASF_ARCTAN
	.stabn 224,0,0,.LBE6-MASF_ARCTAN
	.stabs "MASF_TAN:F7",36,0,0,MASF_TAN
	.align 4
MASF_TAN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab8, %esp
.LN37:
	.stabn  68,0,183,.LN37-MASF_TAN		# line 183, column 1
.LBB7:
.LN38:
	.stabn  68,0,185,.LN38-MASF_TAN		# line 185, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN39:
	.stabn  68,0,185,.LN39-MASF_TAN		# line 185, column 20
	flds	-12(%ebp)
	fcos
	fstps	-12(%ebp)
.LN40:
	.stabn  68,0,186,.LN40-MASF_TAN		# line 186, column 7
	flds	-12(%ebp)
	.data
	.align 4
.Lab12:
	.long	0		# +0.0E0
	.text
	fcomps	.Lab12
	fstsw	%ax
	sahf
	je	.Lab11
.Lab10:
.LN41:
	.stabn  68,0,186,.LN41-MASF_TAN		# line 186, column 25
	flds	-12(%ebp)
	fsin
	fdivs	-12(%ebp) 
	fstps	-12(%ebp)
.LN42:
	.stabn  68,0,186,.LN42-MASF_TAN		# line 186, column 38
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
	jmp	.Lab9
.Lab11:
.LN43:
	.stabn  68,0,187,.LN43-MASF_TAN		# line 187, column 16
	flds	-12(%ebp)
	fsin
	fstps	-12(%ebp)
.LN44:
	.stabn  68,0,188,.LN44-MASF_TAN		# line 188, column 15
	flds	-12(%ebp)
	.data
	.align 4
.Lab16:
	.long	0		# +0.0E0
	.text
	fcomps	.Lab16
	fstsw	%ax
	sahf
	jae	.Lab15
.Lab14:
.LN45:
	.stabn  68,0,188,.LN45-MASF_TAN		# line 188, column 32
	pushl	$0
	pushl	$-1
	call	SACLIST_LIST2
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
	jmp	.Lab13
.Lab15:
.LN46:
	.stabn  68,0,189,.LN46-MASF_TAN		# line 189, column 24
	pushl	$0
	pushl	$1
	call	SACLIST_LIST2
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab13:
.Lab9:
.LN47:
	.stabn  68,0,191,.LN47-MASF_TAN		# line 191, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN48:
	.stabn  68,0,192,.LN48-MASF_TAN		# line 192, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab8 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB7-MASF_TAN
	.stabn 224,0,0,.LBE7-MASF_TAN
	.stabs "MASF_COS:F7",36,0,0,MASF_COS
	.align 4
MASF_COS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab17, %esp
.LN49:
	.stabn  68,0,172,.LN49-MASF_COS		# line 172, column 1
.LBB8:
.LN50:
	.stabn  68,0,174,.LN50-MASF_COS		# line 174, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN51:
	.stabn  68,0,174,.LN51-MASF_COS		# line 174, column 20
	flds	-12(%ebp)
	fcos
	fstps	-12(%ebp)
.LN52:
	.stabn  68,0,174,.LN52-MASF_COS		# line 174, column 31
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN53:
	.stabn  68,0,175,.LN53-MASF_COS		# line 175, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN54:
	.stabn  68,0,176,.LN54-MASF_COS		# line 176, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab17 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB8-MASF_COS
	.stabn 224,0,0,.LBE8-MASF_COS
	.stabs "MASF_SIN:F7",36,0,0,MASF_SIN
	.align 4
MASF_SIN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab18, %esp
.LN55:
	.stabn  68,0,161,.LN55-MASF_SIN		# line 161, column 1
.LBB9:
.LN56:
	.stabn  68,0,163,.LN56-MASF_SIN		# line 163, column 8
	pushl	8(%ebp)
	call	MASF_FFRN
	addl	$4, %esp
	fstps	-12(%ebp)
.LN57:
	.stabn  68,0,163,.LN57-MASF_SIN		# line 163, column 20
	flds	-12(%ebp)
	fsin
	fstps	-12(%ebp)
.LN58:
	.stabn  68,0,163,.LN58-MASF_SIN		# line 163, column 31
	pushl	-12(%ebp)
	call	MASF_RNFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN59:
	.stabn  68,0,164,.LN59-MASF_SIN		# line 164, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN60:
	.stabn  68,0,165,.LN60-MASF_SIN		# line 165, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab18 = 12
	.stabs "f:9",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB9-MASF_SIN
	.stabn 224,0,0,.LBE9-MASF_SIN
	.stabs "MASF_RNFF:F7",36,0,0,MASF_RNFF
	.align 4
MASF_RNFF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab19, %esp
.LN61:
	.stabn  68,0,142,.LN61-MASF_RNFF		# line 142, column 1
.LBB10:
.LN62:
	.stabn  68,0,143,.LN62-MASF_RNFF		# line 143, column 32
	movl	8(%ebp),%eax
	movl	%eax,-20(%ebp)
.LN63:
	.stabn  68,0,144,.LN63-MASF_RNFF		# line 144, column 8
	pushl	-20(%ebp)
	call	MASF_FLOG10
	addl	$4, %esp
	.data
	.align 4
.Lab20:
	.long	1065353216		# +0.09999999999999998E1
	.text
	fadds	.Lab20 
	fstps	-28(%ebp)
.LN64:
	.stabn  68,0,144,.LN64-MASF_RNFF		# line 144, column 26
	pushl	-28(%ebp)
	call	MASF_IFF
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN65:
	.stabn  68,0,145,.LN65-MASF_RNFF		# line 145, column 8
	pushl	-12(%ebp)
	.data
	.align 4
.Lab21:
	.long	1092616192		# +0.09999999999999998E2
	.text
	pushl	.Lab21
	call	MASF_FEXP
	addl	$8, %esp
	fstps	-24(%ebp)
.LN66:
	.stabn  68,0,145,.LN66-MASF_RNFF		# line 145, column 25
	pushl	-12(%ebp)
	pushl	$10
	call	SACI_IEXP
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN67:
	.stabn  68,0,147,.LN67-MASF_RNFF		# line 147, column 7
	cmpl	$0,-12(%ebp)
	jl	.Lab24
.Lab23:
.LN68:
	.stabn  68,0,147,.LN68-MASF_RNFF		# line 147, column 23
	flds	-20(%ebp)
	fdivs	-24(%ebp) 
	fstps	-20(%ebp)
.LN69:
	.stabn  68,0,147,.LN69-MASF_RNFF		# line 147, column 31
	flds	MASF_s
	fmuls	-20(%ebp) 
	fstps	-20(%ebp)
.LN70:
	.stabn  68,0,148,.LN70-MASF_RNFF		# line 148, column 23
	pushl	-20(%ebp)
	call	MASF_IFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN71:
	.stabn  68,0,149,.LN71-MASF_RNFF		# line 149, column 23
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	SACI_IPROD
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN72:
	.stabn  68,0,149,.LN72-MASF_RNFF		# line 149, column 38
	pushl	MASF_s + 12
	pushl	-8(%ebp)
	call	SACRN_RNRED
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
	jmp	.Lab22
.Lab24:
.LN73:
	.stabn  68,0,150,.LN73-MASF_RNFF		# line 150, column 23
	flds	-24(%ebp)
	fmuls	-20(%ebp) 
	fstps	-20(%ebp)
.LN74:
	.stabn  68,0,150,.LN74-MASF_RNFF		# line 150, column 31
	flds	MASF_s
	fmuls	-20(%ebp) 
	fstps	-20(%ebp)
.LN75:
	.stabn  68,0,151,.LN75-MASF_RNFF		# line 151, column 23
	pushl	-20(%ebp)
	call	MASF_IFF
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN76:
	.stabn  68,0,152,.LN76-MASF_RNFF		# line 152, column 23
	pushl	MASF_s + 12
	pushl	-16(%ebp)
	call	SACI_IPROD
	addl	$8, %esp
	movl	%eax,-16(%ebp) 
.LN77:
	.stabn  68,0,152,.LN77-MASF_RNFF		# line 152, column 42
	pushl	-16(%ebp)
	pushl	-8(%ebp)
	call	SACRN_RNRED
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.Lab22:
.LN78:
	.stabn  68,0,153,.LN78-MASF_RNFF		# line 153, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN79:
	.stabn  68,0,154,.LN79-MASF_RNFF		# line 154, column 0
	call	ReturnErr_
.LBE10:
	leave
	ret
	.Lab19 = 28
	.stabs "l:9",128,0,4,-28
	.stabs "i:9",128,0,4,-24
	.stabs "f:9",128,0,4,-20
	.stabs "E:7",128,0,4,-16
	.stabs "I:7",128,0,4,-12
	.stabs "R:7",128,0,4,-8
	.stabs "F:p9",160,0,4,8
	.stabn 192,0,0,.LBB10-MASF_RNFF
	.stabn 224,0,0,.LBE10-MASF_RNFF
	.stabs "MASF_FFRN:F9",36,0,0,MASF_FFRN
	.align 4
MASF_FFRN:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab25, %esp
.LN80:
	.stabn  68,0,126,.LN80-MASF_FFRN		# line 126, column 1
.LBB11:
.LN81:
	.stabn  68,0,127,.LN81-MASF_FFRN		# line 127, column 18
	movl	$0,-16(%ebp)
.LN82:
	.stabn  68,0,128,.LN82-MASF_FFRN		# line 128, column 7
	cmpl	$0,8(%ebp)
	jne	.Lab26
.Lab27:
.LN83:
	.stabn  68,0,128,.LN83-MASF_FFRN		# line 128, column 21
	flds	-16(%ebp)
	leave
	ret
.Lab26:
.LN84:
	.stabn  68,0,130,.LN84-MASF_FFRN		# line 130, column 8
	pushl	8(%ebp)
	call	SACRN_RNDEN
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.LN85:
	.stabn  68,0,130,.LN85-MASF_FFRN		# line 130, column 21
	pushl	8(%ebp)
	call	SACRN_RNNUM
	addl	$4, %esp
	movl	%eax,-12(%ebp) 
.LN86:
	.stabn  68,0,131,.LN86-MASF_FFRN		# line 131, column 9
	pushl	-8(%ebp)
	call	MASF_FFINT
	addl	$4, %esp
	fstps	-20(%ebp)
.LN87:
	.stabn  68,0,131,.LN87-MASF_FFRN		# line 131, column 23
	pushl	-12(%ebp)
	call	MASF_FFINT
	addl	$4, %esp
	fstps	-24(%ebp)
.LN88:
	.stabn  68,0,132,.LN88-MASF_FFRN		# line 132, column 8
	flds	-24(%ebp)
	fdivs	-20(%ebp) 
	fstps	-16(%ebp)
.LN89:
	.stabn  68,0,133,.LN89-MASF_FFRN		# line 133, column 7
	flds	-16(%ebp)
	leave
	ret
.LN90:
	.stabn  68,0,134,.LN90-MASF_FFRN		# line 134, column 0
	call	ReturnErr_
.LBE11:
	leave
	ret
	.Lab25 = 24
	.stabs "fn:9",128,0,4,-24
	.stabs "fd:9",128,0,4,-20
	.stabs "f:9",128,0,4,-16
	.stabs "n:7",128,0,4,-12
	.stabs "d:7",128,0,4,-8
	.stabs "A:p7",160,0,4,8
	.stabn 192,0,0,.LBB11-MASF_FFRN
	.stabn 224,0,0,.LBE11-MASF_FFRN
	.stabs "MASF_FFINT:F9",36,0,0,MASF_FFINT
	.align 4
MASF_FFINT:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab28, %esp
.LN91:
	.stabn  68,0,110,.LN91-MASF_FFINT		# line 110, column 1
.LBB12:
.LN92:
	.stabn  68,0,111,.LN92-MASF_FFINT		# line 111, column 18
	movl	$0,-16(%ebp)
.LN93:
	.stabn  68,0,112,.LN93-MASF_FFINT		# line 112, column 7
	cmpl	$0,8(%ebp)
	jne	.Lab29
.Lab30:
.LN94:
	.stabn  68,0,112,.LN94-MASF_FFINT		# line 112, column 21
	flds	-16(%ebp)
	leave
	ret
.Lab29:
.LN95:
	.stabn  68,0,113,.LN95-MASF_FFINT		# line 113, column 8
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN96:
	.stabn  68,0,113,.LN96-MASF_FFINT		# line 113, column 13
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s,%eax
	jge	.Lab31
.Lab32:
.LN97:
	.stabn  68,0,113,.LN97-MASF_FFINT		# line 113, column 31
	pushl	-8(%ebp)
	call	MASSTOR_LIST1
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.Lab31:
.LN98:
	.stabn  68,0,114,.LN98-MASF_FFINT		# line 114, column 32
	pushl	-8(%ebp)
	call	SACLIST_CINV
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
	jmp	.Lab33
.Lab34:
.LN99:
	.stabn  68,0,115,.LN99-MASF_FFINT		# line 115, column 25
	leal	-8(%ebp),%eax
	pushl	%eax
	leal	-12(%ebp),%eax
	pushl	%eax
	pushl	-8(%ebp)
	call	MASSTOR_ADV
	addl	$12, %esp
.LN100:
	.stabn  68,0,116,.LN100-MASF_FFINT		# line 116, column 14
	flds	MASF_s
	fmuls	-16(%ebp) 
	pushl	-12(%ebp)
	fstpl	-24(%ebp)
	call	MASF_FFGI
	addl	$4, %esp
	faddl	-24(%ebp)
	fstps	-16(%ebp)
.Lab33:
.LN101:
	.stabn  68,0,115,.LN101-MASF_FFINT		# line 115, column 15
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab34
.Lab35:
.LN102:
	.stabn  68,0,117,.LN102-MASF_FFINT		# line 117, column 7
	flds	-16(%ebp)
	leave
	ret
.LN103:
	.stabn  68,0,118,.LN103-MASF_FFINT		# line 118, column 0
	call	ReturnErr_
.LBE12:
	leave
	ret
	.Lab28 = 24
	.stabs "f:9",128,0,4,-16
	.stabs "a:7",128,0,4,-12
	.stabs "A:7",128,0,4,-8
	.stabs "N:p7",160,0,4,8
	.stabn 192,0,0,.LBB12-MASF_FFINT
	.stabn 224,0,0,.LBE12-MASF_FFINT
	.stabs "MASF_FLOG10:F9",36,0,0,MASF_FLOG10
	.align 4
MASF_FLOG10:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab36, %esp
.LN104:
	.stabn  68,0,101,.LN104-MASF_FLOG10		# line 101, column 1
.LBB13:
.LN105:
	.stabn  68,0,101,.LN105-MASF_FLOG10		# line 101, column 7
	fldl	RealLn2_
	flds	8(%ebp)
	fyl2x
	fldl	RealLn2_
	.data
	.align 4
.Lab37:
	.long	1092616192		# +0.09999999999999998E2
	.text
	flds	.Lab37
	fyl2x
	fdivrp	%st,%st(1)
	leave
	ret
.LN106:
	.stabn  68,0,102,.LN106-MASF_FLOG10		# line 102, column 0
	call	ReturnErr_
.LBE13:
	leave
	ret
	.Lab36 = 4
	.stabs "F:p9",160,0,4,8
	.stabn 192,0,0,.LBB13-MASF_FLOG10
	.stabn 224,0,0,.LBE13-MASF_FLOG10
	.stabs "MASF_FEXP:F9",36,0,0,MASF_FEXP
	.align 4
MASF_FEXP:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab38, %esp
.LN107:
	.stabn  68,0,88,.LN107-MASF_FEXP		# line 88, column 1
.LBB14:
.LN108:
	.stabn  68,0,89,.LN108-MASF_FEXP		# line 89, column 7
	flds	8(%ebp)
	.data
	.align 4
.Lab41:
	.long	0		# +0.0E0
	.text
	fcomps	.Lab41
	fstsw	%ax
	sahf
	jne	.Lab39
.Lab40:
.LN109:
	.stabn  68,0,89,.LN109-MASF_FEXP		# line 89, column 23
	flds	8(%ebp)
	leave
	ret
.Lab39:
.LN110:
	.stabn  68,0,90,.LN110-MASF_FEXP		# line 90, column 8
	movl	$1065353216,-12(%ebp)
.LN111:
	.stabn  68,0,91,.LN111-MASF_FEXP		# line 91, column 7
	cmpl	$0,12(%ebp)
	jne	.Lab42
.Lab43:
.LN112:
	.stabn  68,0,91,.LN112-MASF_FEXP		# line 91, column 21
	flds	-12(%ebp)
	leave
	ret
.Lab42:
.LN113:
	.stabn  68,0,92,.LN113-MASF_FEXP		# line 92, column 7
	cmpl	$0,12(%ebp)
	jge	.Lab44
.Lab45:
.LN114:
	.stabn  68,0,92,.LN114-MASF_FEXP		# line 92, column 22
	movl	12(%ebp),%eax
	negl	%eax
	movl	%eax,12(%ebp) 
.LN115:
	.stabn  68,0,92,.LN115-MASF_FEXP		# line 92, column 29
	.data
	.align 4
.Lab46:
	.long	1065353216		# +0.09999999999999998E1
	.text
	flds	.Lab46
	fdivs	-12(%ebp) 
	fstps	-12(%ebp)
.Lab44:
.LN116:
	.stabn  68,0,93,.LN116-MASF_FEXP		# line 93, column 7
	movl	12(%ebp),%eax
	movl	%eax,-16(%ebp) 
	cmpl	$1,-16(%ebp)
	jl	.Lab47
	movl	$1,-8(%ebp) 
	movl	-16(%ebp),%eax
	movl	%eax,-20(%ebp) 
.Lab48:
.LN117:
	.stabn  68,0,93,.LN117-MASF_FEXP		# line 93, column 25
	flds	8(%ebp)
	fmuls	-12(%ebp) 
	fstps	-12(%ebp)
.LN118:
	.stabn  68,0,93,.LN118-MASF_FEXP		# line 93, column 7
	movl	-8(%ebp),%eax
	cmpl	-20(%ebp),%eax
	jge	.Lab47
	incl	-8(%ebp) 
	jmp	.Lab48
.Lab47:
.LN119:
	.stabn  68,0,94,.LN119-MASF_FEXP		# line 94, column 7
	flds	-12(%ebp)
	leave
	ret
.LN120:
	.stabn  68,0,95,.LN120-MASF_FEXP		# line 95, column 0
	call	ReturnErr_
.LBE14:
	leave
	ret
	.Lab38 = 20
	.stabs "f:9",128,0,4,-12
	.stabs "i:7",128,0,4,-8
	.stabs "N:p7",160,0,4,12
	.stabs "F:p9",160,0,4,8
	.stabn 192,0,0,.LBB14-MASF_FEXP
	.stabn 224,0,0,.LBE14-MASF_FEXP
	.stabs "MASF_IFF:F7",36,0,0,MASF_IFF
	.align 4
MASF_IFF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab49, %esp
.LN121:
	.stabn  68,0,72,.LN121-MASF_IFF		# line 72, column 1
.LBB15:
.LN122:
	.stabn  68,0,74,.LN122-MASF_IFF		# line 74, column 7
	flds	8(%ebp)
	.data
	.align 4
.Lab53:
	.long	0		# +0.0E0
	.text
	fcomps	.Lab53
	fstsw	%ax
	sahf
	jb	.Lab52
.Lab51:
.LN123:
	.stabn  68,0,74,.LN123-MASF_IFF		# line 74, column 25
	movl	8(%ebp),%eax
	movl	%eax,-16(%ebp)
.LN124:
	.stabn  68,0,74,.LN124-MASF_IFF		# line 74, column 31
	movl	$1,-12(%ebp) 
	jmp	.Lab50
.Lab52:
.LN125:
	.stabn  68,0,74,.LN125-MASF_IFF		# line 74, column 41
	flds	8(%ebp)
	fchs 
	fstps	-16(%ebp)
.LN126:
	.stabn  68,0,74,.LN126-MASF_IFF		# line 74, column 48
	movl	$-1,-12(%ebp) 
.Lab50:
	jmp	.Lab54
.Lab55:
.LN127:
	.stabn  68,0,75,.LN127-MASF_IFF		# line 75, column 28
	flds	-16(%ebp)
	fdivs	MASF_s 
	fstps	-16(%ebp)
.LN128:
	.stabn  68,0,75,.LN128-MASF_IFF		# line 75, column 40
	pushl	MASF_s + 12
	pushl	-12(%ebp)
	call	SACI_IPROD
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.Lab54:
.LN129:
	.stabn  68,0,75,.LN129-MASF_IFF		# line 75, column 15
	flds	-16(%ebp)
	fcomps	MASF_s
	fstsw	%ax
	sahf
	jae	.Lab55
.Lab56:
.LN130:
	.stabn  68,0,77,.LN130-MASF_IFF		# line 77, column 8
	flds	-16(%ebp)
	fldcw	fpucw_round_to_neginf
	fistpl	-8(%ebp)
.LN131:
	.stabn  68,0,79,.LN131-MASF_IFF		# line 79, column 8
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	SACI_IPROD
	addl	$8, %esp
	movl	%eax,-12(%ebp) 
.LN132:
	.stabn  68,0,79,.LN132-MASF_IFF		# line 79, column 22
	movl	-12(%ebp),%eax
	leave
	ret
.LN133:
	.stabn  68,0,80,.LN133-MASF_IFF		# line 80, column 0
	call	ReturnErr_
.LBE15:
	leave
	ret
	.Lab49 = 16
	.stabs "f:9",128,0,4,-16
	.stabs "h:7",128,0,4,-12
	.stabs "g:7",128,0,4,-8
	.stabs "F:p9",160,0,4,8
	.stabn 192,0,0,.LBB15-MASF_IFF
	.stabn 224,0,0,.LBE15-MASF_IFF
	.stabs "MASF_FFGI:F9",36,0,0,MASF_FFGI
	.align 4
MASF_FFGI:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab57, %esp
.LN134:
	.stabn  68,0,62,.LN134-MASF_FFGI		# line 62, column 1
.LBB16:
.LN135:
	.stabn  68,0,63,.LN135-MASF_FFGI		# line 63, column 8
	fildl	8(%ebp)
	fstps	-8(%ebp)
.LN136:
	.stabn  68,0,63,.LN136-MASF_FFGI		# line 63, column 19
	flds	-8(%ebp)
	leave
	ret
.LN137:
	.stabn  68,0,64,.LN137-MASF_FFGI		# line 64, column 0
	call	ReturnErr_
.LBE16:
	leave
	ret
	.Lab57 = 8
	.stabs "f:9",128,0,4,-8
	.stabs "N:p7",160,0,4,8
	.stabn 192,0,0,.LBB16-MASF_FFGI
	.stabn 224,0,0,.LBE16-MASF_FFGI
	.stabs "MASF:F16",36,0,0,MASF
	.align 4
MASF:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab58, %esp
.LN138:
	.stabn  68,0,263,.LN138-MASF		# line 263, column 1
.LBB17:
.LN139:
	.stabn  68,0,265,.LN139-MASF		# line 265, column 1
	call	MASF_InitFLOAT
.LN140:
	.stabn  68,0,266,.LN140-MASF		# line 266, column 0
.LBE17:
	leave
	ret
	.Lab58 = 4
	.stabn 192,0,0,.LBB17-MASF
	.stabn 224,0,0,.LBE17-MASF
	.stabs "MASF_s:Gs16FBETA:9,0,32;FBETAH:9,32,32;BETAH:7,64,32;IBETA:7,96,32;;",32,0,0,0
