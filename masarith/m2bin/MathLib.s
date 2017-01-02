	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masarith/",100,0,0,.LBB0
	.stabs "MathLib.mod",100,0,0,.LBB0
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
	.globl	MathLib
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
	.globl	MathLib_sqrtL_TwoPower
	.globl	MathLib_sqrt
	.globl	MathLib_sinus
	.globl	MathLib_sarctan
	.globl	MathLib_sarctan_xatan
	.globl	MathLib_modf
	.globl	MathLib_ldexp
	.globl	MathLib_frexp
	.globl	MathLib_Float
	.globl	MathLib_Trunc
	.stabs "MathLib_entierL:F7",36,0,0,MathLib_entierL
	.align 4
MathLib_entierL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,361,.LN1-MathLib_entierL		# line 361, column 3
.LBB1:
.LN2:
	.stabn  68,0,362,.LN2-MathLib_entierL		# line 362, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab5:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab5
	fstsw	%ax
	sahf
	jb	.Lab4
.Lab3:
.LN3:
	.stabn  68,0,363,.LN3-MathLib_entierL		# line 363, column 7
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_Trunc
	addl	$8, %esp
	leave
	ret
	jmp	.Lab2
.Lab4:
.LN4:
	.stabn  68,0,364,.LN4-MathLib_entierL		# line 364, column 5
	fldl	8(%ebp)
	fchs 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_Trunc
	addl	$8, %esp
	pushl	%eax
	call	MathLib_Float
	addl	$4, %esp
	fchs 
	fcompl	8(%ebp)
	fstsw	%ax
	sahf
	jne	.Lab8
.Lab7:
.LN5:
	.stabn  68,0,365,.LN5-MathLib_entierL		# line 365, column 7
	fldl	8(%ebp)
	fchs 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_Trunc
	addl	$8, %esp
	negl	%eax
	leave
	ret
	jmp	.Lab6
.Lab8:
.LN6:
	.stabn  68,0,368,.LN6-MathLib_entierL		# line 368, column 7
	fldl	8(%ebp)
	fchs 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_Trunc
	addl	$8, %esp
	negl	%eax
 	subl	$1,%eax 
	leave
	ret
.Lab6:
.Lab2:
.LN7:
	.stabn  68,0,369,.LN7-MathLib_entierL		# line 369, column 0
	call	ReturnErr_
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB1-MathLib_entierL
	.stabn 224,0,0,.LBE1-MathLib_entierL
	.stabs "MathLib_entier:F7",36,0,0,MathLib_entier
	.align 4
MathLib_entier:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab9, %esp
.LN8:
	.stabn  68,0,355,.LN8-MathLib_entier		# line 355, column 3
.LBB2:
.LN9:
	.stabn  68,0,356,.LN9-MathLib_entier		# line 356, column 5
	flds	8(%ebp)
	subl	$4,%esp
	fldcw	fpucw_round_to_neginf
	fistpl	(%esp)
	popl	%eax
	leave
	ret
.LN10:
	.stabn  68,0,357,.LN10-MathLib_entier		# line 357, column 0
	call	ReturnErr_
.LBE2:
	leave
	ret
	.Lab9 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB2-MathLib_entier
	.stabn 224,0,0,.LBE2-MathLib_entier
	.stabs "MathLib_realL:F10",36,0,0,MathLib_realL
	.align 4
MathLib_realL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab10, %esp
.LN11:
	.stabn  68,0,346,.LN11-MathLib_realL		# line 346, column 3
.LBB3:
.LN12:
	.stabn  68,0,347,.LN12-MathLib_realL		# line 347, column 5
	cmpl	$0,8(%ebp)
	jge	.Lab13
.Lab12:
.LN13:
	.stabn  68,0,348,.LN13-MathLib_realL		# line 348, column 7
	movl	8(%ebp),%eax
	negl	%eax
	pushl	%eax
	call	MathLib_Float
	addl	$4, %esp
	fchs 
	leave
	ret
	jmp	.Lab11
.Lab13:
.LN14:
	.stabn  68,0,350,.LN14-MathLib_realL		# line 350, column 7
	pushl	8(%ebp)
	call	MathLib_Float
	addl	$4, %esp
	leave
	ret
.Lab11:
.LN15:
	.stabn  68,0,351,.LN15-MathLib_realL		# line 351, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab10 = 4
	.stabs "arg:p7",160,0,4,8
	.stabn 192,0,0,.LBB3-MathLib_realL
	.stabn 224,0,0,.LBE3-MathLib_realL
	.stabs "MathLib_real:F9",36,0,0,MathLib_real
	.align 4
MathLib_real:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab14, %esp
.LN16:
	.stabn  68,0,341,.LN16-MathLib_real		# line 341, column 3
.LBB4:
.LN17:
	.stabn  68,0,342,.LN17-MathLib_real		# line 342, column 5
	fildl	8(%ebp)
	.data
	.align 4
.Lab15:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab16:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab15
	fstsw	%ax
	sahf
	jb	.Lab18
	fcoml	.Lab16
	fstsw	%ax
	sahf
	jbe	.Lab17
.Lab18:
   	call	BoundErr_		
.Lab17:
	leave
	ret
.LN18:
	.stabn  68,0,343,.LN18-MathLib_real		# line 343, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab14 = 4
	.stabs "arg:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-MathLib_real
	.stabn 224,0,0,.LBE4-MathLib_real
	.stabs "MathLib_arctanL:F10",36,0,0,MathLib_arctanL
	.align 4
MathLib_arctanL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab19, %esp
.LN19:
	.stabn  68,0,332,.LN19-MathLib_arctanL		# line 332, column 3
.LBB5:
.LN20:
	.stabn  68,0,333,.LN20-MathLib_arctanL		# line 333, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab23:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab23
	fstsw	%ax
	sahf
	jbe	.Lab22
.Lab21:
.LN21:
	.stabn  68,0,334,.LN21-MathLib_arctanL		# line 334, column 7
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_sarctan
	addl	$8, %esp
	leave
	ret
	jmp	.Lab20
.Lab22:
.LN22:
	.stabn  68,0,336,.LN22-MathLib_arctanL		# line 336, column 7
	fldl	8(%ebp)
	fchs 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_sarctan
	addl	$8, %esp
	fchs 
	leave
	ret
.Lab20:
.LN23:
	.stabn  68,0,337,.LN23-MathLib_arctanL		# line 337, column 0
	call	ReturnErr_
.LBE5:
	leave
	ret
	.Lab19 = 4
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB5-MathLib_arctanL
	.stabn 224,0,0,.LBE5-MathLib_arctanL
	.stabs "MathLib_arctan:F9",36,0,0,MathLib_arctan
	.align 4
MathLib_arctan:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab24, %esp
.LN24:
	.stabn  68,0,325,.LN24-MathLib_arctan		# line 325, column 3
.LBB6:
.LN25:
	.stabn  68,0,326,.LN25-MathLib_arctan		# line 326, column 5
	flds	8(%ebp)
	flds	RealOne_
	fpatan
	.data
	.align 4
.Lab25:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab26:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab25
	fstsw	%ax
	sahf
	jb	.Lab28
	fcoml	.Lab26
	fstsw	%ax
	sahf
	jbe	.Lab27
.Lab28:
   	call	BoundErr_		
.Lab27:
	leave
	ret
.LN26:
	.stabn  68,0,327,.LN26-MathLib_arctan		# line 327, column 0
	call	ReturnErr_
.LBE6:
	leave
	ret
	.Lab24 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB6-MathLib_arctan
	.stabn 224,0,0,.LBE6-MathLib_arctan
	.stabs "MathLib_cosL:F10",36,0,0,MathLib_cosL
	.align 4
MathLib_cosL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab29, %esp
.LN27:
	.stabn  68,0,319,.LN27-MathLib_cosL		# line 319, column 3
.LBB7:
.LN28:
	.stabn  68,0,320,.LN28-MathLib_cosL		# line 320, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab32:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab32
	fstsw	%ax
	sahf
	jae	.Lab30
.Lab31:
.LN29:
	.stabn  68,0,320,.LN29-MathLib_cosL		# line 320, column 27
	fldl	8(%ebp)
	fchs 
	fstpl	8(%ebp)
.Lab30:
.LN30:
	.stabn  68,0,321,.LN30-MathLib_cosL		# line 321, column 5
	pushl	$1
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_sinus
	addl	$12, %esp
	leave
	ret
.LN31:
	.stabn  68,0,322,.LN31-MathLib_cosL		# line 322, column 0
	call	ReturnErr_
.LBE7:
	leave
	ret
	.Lab29 = 4
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB7-MathLib_cosL
	.stabn 224,0,0,.LBE7-MathLib_cosL
	.stabs "MathLib_cos:F9",36,0,0,MathLib_cos
	.align 4
MathLib_cos:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab33, %esp
.LN32:
	.stabn  68,0,314,.LN32-MathLib_cos		# line 314, column 3
.LBB8:
.LN33:
	.stabn  68,0,315,.LN33-MathLib_cos		# line 315, column 5
	flds	8(%ebp)
	fcos
	.data
	.align 4
.Lab34:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab35:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab34
	fstsw	%ax
	sahf
	jb	.Lab37
	fcoml	.Lab35
	fstsw	%ax
	sahf
	jbe	.Lab36
.Lab37:
   	call	BoundErr_		
.Lab36:
	leave
	ret
.LN34:
	.stabn  68,0,316,.LN34-MathLib_cos		# line 316, column 0
	call	ReturnErr_
.LBE8:
	leave
	ret
	.Lab33 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB8-MathLib_cos
	.stabn 224,0,0,.LBE8-MathLib_cos
	.stabs "MathLib_sinL:F10",36,0,0,MathLib_sinL
	.align 4
MathLib_sinL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab38, %esp
.LN35:
	.stabn  68,0,309,.LN35-MathLib_sinL		# line 309, column 3
.LBB9:
.LN36:
	.stabn  68,0,310,.LN36-MathLib_sinL		# line 310, column 5
	pushl	$0
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_sinus
	addl	$12, %esp
	leave
	ret
.LN37:
	.stabn  68,0,311,.LN37-MathLib_sinL		# line 311, column 0
	call	ReturnErr_
.LBE9:
	leave
	ret
	.Lab38 = 4
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB9-MathLib_sinL
	.stabn 224,0,0,.LBE9-MathLib_sinL
	.stabs "MathLib_sin:F9",36,0,0,MathLib_sin
	.align 4
MathLib_sin:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab39, %esp
.LN38:
	.stabn  68,0,304,.LN38-MathLib_sin		# line 304, column 3
.LBB10:
.LN39:
	.stabn  68,0,305,.LN39-MathLib_sin		# line 305, column 5
	flds	8(%ebp)
	fsin
	.data
	.align 4
.Lab40:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab41:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab40
	fstsw	%ax
	sahf
	jb	.Lab43
	fcoml	.Lab41
	fstsw	%ax
	sahf
	jbe	.Lab42
.Lab43:
   	call	BoundErr_		
.Lab42:
	leave
	ret
.LN40:
	.stabn  68,0,306,.LN40-MathLib_sin		# line 306, column 0
	call	ReturnErr_
.LBE10:
	leave
	ret
	.Lab39 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB10-MathLib_sin
	.stabn 224,0,0,.LBE10-MathLib_sin
	.stabs "MathLib_lnL:F10",36,0,0,MathLib_lnL
	.align 4
MathLib_lnL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab44, %esp
.LN41:
	.stabn  68,0,289,.LN41-MathLib_lnL		# line 289, column 3
.LBB11:
.LN42:
	.stabn  68,0,290,.LN42-MathLib_lnL		# line 290, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab47:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab47
	fstsw	%ax
	sahf
	ja	.Lab45
.Lab46:
.LN43:
	.stabn  68,0,290,.LN43-MathLib_lnL		# line 290, column 39
	.data
	.align 4
.Lab48:
	.long	0,0		# +0.0E0
	.text
	fldl	.Lab48
	leave
	ret
.Lab45:
.LN44:
	.stabn  68,0,291,.LN44-MathLib_lnL		# line 291, column 9
	leal	-20(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_frexp
	addl	$12, %esp
	fstpl	8(%ebp)
	jmp	.Lab49
.Lab50:
.LN45:
	.stabn  68,0,293,.LN45-MathLib_lnL		# line 293, column 11
	.data
	.align 4
.Lab52:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab52
	fmull	8(%ebp) 
	fstpl	8(%ebp)
.LN46:
	.stabn  68,0,294,.LN46-MathLib_lnL		# line 294, column 7
	decl	-20(%ebp) 
.Lab49:
.LN47:
	.stabn  68,0,292,.LN47-MathLib_lnL		# line 292, column 15
	fldl	8(%ebp)
	.data
	.align 4
.Lab53:
	.long	1719614415,1072079006		# +0.70710678118654772E0
	.text
	fcompl	.Lab53
	fstsw	%ax
	sahf
	jb	.Lab50
.Lab51:
.LN48:
	.stabn  68,0,296,.LN48-MathLib_lnL		# line 296, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab54:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fsubl	.Lab54 
	.data
	.align 4
.Lab55:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	.Lab55
	faddl	8(%ebp) 
	fdivrp	%st,%st(1)
	fstpl	8(%ebp)
.LN49:
	.stabn  68,0,297,.LN49-MathLib_lnL		# line 297, column 9
	fldl	8(%ebp)
	fmull	8(%ebp) 
	fstpl	-16(%ebp)
.LN50:
	.stabn  68,0,298,.LN50-MathLib_lnL		# line 298, column 5
	.data
	.align 4
.Lab56:
	.long	1913189123,1071313688		# +0.42108737121797910E0
	.text
	fldl	-16(%ebp)
	fmull	.Lab56 
	.data
	.align 4
.Lab57:
	.long	1829914639,-1071430017		# -0.96376909336868532E1
	.text
	faddl	.Lab57 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab58:
	.long	611398421,1077867793		# +0.30957292821537589E2
	.text
	faddl	.Lab58 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab59:
	.long	546144779,-1070070896		# -0.24013917955921026E2
	.text
	faddl	.Lab59 
	.data
	.align 4
.Lab60:
	.long	-504590784,-1071525252		# -0.89111090279831142E1
	.text
	fldl	.Lab60
	faddl	-16(%ebp) 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab61:
	.long	-1750760312,1077115680		# +0.19480966070088948E2
	.text
	faddl	.Lab61 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab62:
	.long	546144779,-1071119472		# -0.12006958977960513E2
	.text
	faddl	.Lab62 
	fdivrp	%st,%st(1)
	fmull	8(%ebp) 
	fildl	-20(%ebp)
	.data
	.align 4
.Lab63:
	.long	-17155609,1072049730		# +0.69314718055994433E0
	.text
	fmull	.Lab63 
	faddp	%st,%st(1)
	leave
	ret
.LN51:
	.stabn  68,0,299,.LN51-MathLib_lnL		# line 299, column 0
	call	ReturnErr_
.LBE11:
	leave
	ret
	.Lab44 = 20
	.stabs "q2:c=r-8.91110902798311599326E0",128,0,0,0
	.stabs "q1:c=r1.94809660700889519802E1",128,0,0,0
	.stabs "q0:c=r-1.20069589779605134793E1",128,0,0,0
	.stabs "p3:c=r4.21087371217979100634E-1",128,0,0,0
	.stabs "p2:c=r-9.63769093368685325629E0",128,0,0,0
	.stabs "p1:c=r3.09572928215375942073E1",128,0,0,0
	.stabs "p0:c=r-2.40139179559210269587E1",128,0,0,0
	.stabs "sqrto2:c=r7.07106781186547728168E-1",128,0,0,0
	.stabs "exp:7",128,0,4,-20
	.stabs "asq:10",128,0,8,-16
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB11-MathLib_lnL
	.stabn 224,0,0,.LBE11-MathLib_lnL
	.stabs "MathLib_ln:F9",36,0,0,MathLib_ln
	.align 4
MathLib_ln:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab64, %esp
.LN52:
	.stabn  68,0,273,.LN52-MathLib_ln		# line 273, column 3
.LBB12:
.LN53:
	.stabn  68,0,274,.LN53-MathLib_ln		# line 274, column 5
	fldl	RealLn2_
	flds	8(%ebp)
	fyl2x
	.data
	.align 4
.Lab65:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab66:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab65
	fstsw	%ax
	sahf
	jb	.Lab68
	fcoml	.Lab66
	fstsw	%ax
	sahf
	jbe	.Lab67
.Lab68:
   	call	BoundErr_		
.Lab67:
	leave
	ret
.LN54:
	.stabn  68,0,275,.LN54-MathLib_ln		# line 275, column 0
	call	ReturnErr_
.LBE12:
	leave
	ret
	.Lab64 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB12-MathLib_ln
	.stabn 224,0,0,.LBE12-MathLib_ln
	.stabs "MathLib_expL:F10",36,0,0,MathLib_expL
	.align 4
MathLib_expL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab69, %esp
.LN55:
	.stabn  68,0,259,.LN55-MathLib_expL		# line 259, column 3
.LBB13:
.LN56:
	.stabn  68,0,260,.LN56-MathLib_expL		# line 260, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab72:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab72
	fstsw	%ax
	sahf
	jne	.Lab70
.Lab71:
.LN57:
	.stabn  68,0,260,.LN57-MathLib_expL		# line 260, column 23
	.data
	.align 4
.Lab73:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	.Lab73
	leave
	ret
.Lab70:
.LN58:
	.stabn  68,0,261,.LN58-MathLib_expL		# line 261, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab76:
	.long	0,-1060927488		# -0.09999999999999998E5
	.text
	fcompl	.Lab76
	fstsw	%ax
	sahf
	jae	.Lab74
.Lab75:
.LN59:
	.stabn  68,0,261,.LN59-MathLib_expL		# line 261, column 25
	.data
	.align 4
.Lab77:
	.long	0,0		# +0.0E0
	.text
	fldl	.Lab77
	leave
	ret
.Lab74:
.LN60:
	.stabn  68,0,262,.LN60-MathLib_expL		# line 262, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab80:
	.long	0,1086556160		# +0.09999999999999998E5
	.text
	fcompl	.Lab80
	fstsw	%ax
	sahf
	jbe	.Lab78
.Lab79:
.LN61:
	.stabn  68,0,262,.LN61-MathLib_expL		# line 262, column 40
	.data
	.align 4
.Lab81:
	.long	0,0		# +0.0E0
	.text
	fldl	.Lab81
	leave
	ret
.Lab78:
.LN62:
	.stabn  68,0,263,.LN62-MathLib_expL		# line 263, column 9
	.data
	.align 4
.Lab82:
	.long	1697350406,1073157447		# +0.14426950408889648E1
	.text
	fldl	.Lab82
	fmull	8(%ebp) 
	fstpl	8(%ebp)
.LN63:
	.stabn  68,0,264,.LN63-MathLib_expL		# line 264, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab83:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab84:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab83
	fstsw	%ax
	sahf
	jb	.Lab86
	fcoml	.Lab84
	fstsw	%ax
	sahf
	jbe	.Lab85
.Lab86:
   	call	BoundErr_		
.Lab85:
	fldcw	fpucw_round_to_neginf
	fistpl	-8(%ebp)
.LN64:
	.stabn  68,0,265,.LN64-MathLib_expL		# line 265, column 11
	fildl	-8(%ebp)
	fsubrl	8(%ebp) 
	.data
	.align 4
.Lab87:
	.long	-1,1071644671		# +0.49999999999999991E0
	.text
	fsubl	.Lab87 
	fstpl	-16(%ebp)
.LN65:
	.stabn  68,0,266,.LN65-MathLib_expL		# line 266, column 9
	fldl	-16(%ebp)
	fmull	-16(%ebp) 
	fstpl	-24(%ebp)
.LN66:
	.stabn  68,0,267,.LN66-MathLib_expL		# line 267, column 11
	.data
	.align 4
.Lab88:
	.long	-2091844872,1078873779		# +0.60614853300610702E2
	.text
	fldl	-24(%ebp)
	fmull	.Lab88 
	.data
	.align 4
.Lab89:
	.long	810186221,1088263102		# +0.30286971697440292E5
	.text
	faddl	.Lab89 
	fmull	-24(%ebp) 
	.data
	.align 4
.Lab90:
	.long	1489042226,1094696576		# +0.20803843466946592E7
	.text
	faddl	.Lab90 
	fmull	-16(%ebp) 
	fstpl	-32(%ebp)
.LN67:
	.stabn  68,0,268,.LN67-MathLib_expL		# line 268, column 11
	.data
	.align 4
.Lab91:
	.long	-1745340244,1083921702		# +0.17492876890930730E4
	.text
	fldl	.Lab91
	faddl	-24(%ebp) 
	fmull	-24(%ebp) 
	.data
	.align 4
.Lab92:
	.long	-1686920719,1091829940		# +0.32772515180829064E6
	.text
	faddl	.Lab92 
	fmull	-24(%ebp) 
	.data
	.align 4
.Lab93:
	.long	386803490,1096214024		# +0.60027203602388201E7
	.text
	faddl	.Lab93 
	fstpl	-40(%ebp)
.LN68:
	.stabn  68,0,269,.LN68-MathLib_expL		# line 269, column 5
	pushl	-8(%ebp)
	.data
	.align 4
.Lab94:
	.long	1719614410,1073127582		# +0.14142135623730944E1
	.text
	fldl	-32(%ebp)
	faddl	-40(%ebp) 
	fmull	.Lab94 
	fldl	-40(%ebp)
	fsubl	-32(%ebp) 
	fdivrp	%st,%st(1)
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_ldexp
	addl	$12, %esp
	leave
	ret
.LN69:
	.stabn  68,0,270,.LN69-MathLib_expL		# line 270, column 0
	call	ReturnErr_
.LBE13:
	leave
	ret
	.Lab69 = 40
	.stabs "log2e:c=r1.44269504088896516336E0",128,0,0,0
	.stabs "q2:c=r1.74928768909307326140E3",128,0,0,0
	.stabs "q1:c=r3.27725151808290648958E5",128,0,0,0
	.stabs "q0:c=r6.00272036023882105126E6",128,0,0,0
	.stabs "p2:c=r6.06148533006107115284E1",128,0,0,0
	.stabs "p1:c=r3.02869716974402969356E4",128,0,0,0
	.stabs "p0:c=r2.08038434669465921444E6",128,0,0,0
	.stabs "maxf:c=r1.00000000000000000000E4",128,0,0,0
	.stabs "temp2:10",128,0,8,-40
	.stabs "temp1:10",128,0,8,-32
	.stabs "xsq:10",128,0,8,-24
	.stabs "fract:10",128,0,8,-16
	.stabs "ent:7",128,0,4,-8
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB13-MathLib_expL
	.stabn 224,0,0,.LBE13-MathLib_expL
	.stabs "MathLib_exp:F9",36,0,0,MathLib_exp
	.align 4
MathLib_exp:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab95, %esp
.LN70:
	.stabn  68,0,242,.LN70-MathLib_exp		# line 242, column 3
.LBB14:
.LN71:
	.stabn  68,0,243,.LN71-MathLib_exp		# line 243, column 5
	flds	8(%ebp)
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
	.data
	.align 4
.Lab96:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab97:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab96
	fstsw	%ax
	sahf
	jb	.Lab99
	fcoml	.Lab97
	fstsw	%ax
	sahf
	jbe	.Lab98
.Lab99:
   	call	BoundErr_		
.Lab98:
	leave
	ret
.LN72:
	.stabn  68,0,244,.LN72-MathLib_exp		# line 244, column 0
	call	ReturnErr_
.LBE14:
	leave
	ret
	.Lab95 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB14-MathLib_exp
	.stabn 224,0,0,.LBE14-MathLib_exp
	.stabs "MathLib_sqrtL_TwoPower:F10",36,0,0,MathLib_sqrtL_TwoPower
	.align 4
MathLib_sqrtL_TwoPower:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab100, %esp
.LN73:
	.stabn  68,0,205,.LN73-MathLib_sqrtL_TwoPower		# line 205, column 5
.LBB15:
.LN74:
	.stabn  68,0,206,.LN74-MathLib_sqrtL_TwoPower		# line 206, column 14
	movl	$0,-16(%ebp)
	movl	$1072693248,-12(%ebp)	
.LN75:
	.stabn  68,0,207,.LN75-MathLib_sqrtL_TwoPower		# line 207, column 7
	movl	8(%ebp),%eax
	movl	%eax,-20(%ebp) 
	cmpl	$1,-20(%ebp)
	jb	.Lab101
	movl	$1,-8(%ebp) 
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
.Lab102:
.LN76:
	.stabn  68,0,207,.LN76-MathLib_sqrtL_TwoPower		# line 207, column 33
	.data
	.align 4
.Lab103:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab103
	fmull	-16(%ebp) 
	fstpl	-16(%ebp)
.LN77:
	.stabn  68,0,207,.LN77-MathLib_sqrtL_TwoPower		# line 207, column 7
	movl	-8(%ebp),%eax
	cmpl	-24(%ebp),%eax
	jae	.Lab101
	incl	-8(%ebp) 
	jmp	.Lab102
.Lab101:
.LN78:
	.stabn  68,0,208,.LN78-MathLib_sqrtL_TwoPower		# line 208, column 7
	fldl	-16(%ebp)
	leave
	ret
.LN79:
	.stabn  68,0,209,.LN79-MathLib_sqrtL_TwoPower		# line 209, column 0
	call	ReturnErr_
.LBE15:
	leave
	ret
	.Lab100 = 24
	.stabs "result:10",128,0,8,-16
	.stabs "i:4",128,0,4,-8
	.stabs "b:p4",160,0,4,8
	.stabn 192,0,0,.LBB15-MathLib_sqrtL_TwoPower
	.stabn 224,0,0,.LBE15-MathLib_sqrtL_TwoPower
	.stabs "MathLib_sqrtL:F10",36,0,0,MathLib_sqrtL
	.align 4
MathLib_sqrtL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab104, %esp
.LN80:
	.stabn  68,0,211,.LN80-MathLib_sqrtL		# line 211, column 3
.LBB16:
.LN81:
	.stabn  68,0,212,.LN81-MathLib_sqrtL		# line 212, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab107:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab107
	fstsw	%ax
	sahf
	jae	.Lab105
.Lab106:
.LN82:
	.stabn  68,0,212,.LN82-MathLib_sqrtL		# line 212, column 38
	.data
	.align 4
.Lab108:
	.long	0,0		# +0.0E0
	.text
	fldl	.Lab108
	leave
	ret
.Lab105:
.LN83:
	.stabn  68,0,213,.LN83-MathLib_sqrtL		# line 213, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab111:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab111
	fstsw	%ax
	sahf
	jne	.Lab109
.Lab110:
.LN84:
	.stabn  68,0,213,.LN84-MathLib_sqrtL		# line 213, column 23
	.data
	.align 4
.Lab112:
	.long	0,0		# +0.0E0
	.text
	fldl	.Lab112
	leave
	ret
.Lab109:
.LN85:
	.stabn  68,0,214,.LN85-MathLib_sqrtL		# line 214, column 7
	leal	-28(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_frexp
	addl	$12, %esp
	fstpl	-16(%ebp)
	jmp	.Lab113
.Lab114:
.LN86:
	.stabn  68,0,216,.LN86-MathLib_sqrtL		# line 216, column 9
	.data
	.align 4
.Lab116:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab116
	fmull	-16(%ebp) 
	fstpl	-16(%ebp)
.LN87:
	.stabn  68,0,217,.LN87-MathLib_sqrtL		# line 217, column 7
	decl	-28(%ebp) 
.Lab113:
.LN88:
	.stabn  68,0,215,.LN88-MathLib_sqrtL		# line 215, column 13
	fldl	-16(%ebp)
	.data
	.align 4
.Lab117:
	.long	-1,1071644671		# +0.49999999999999991E0
	.text
	fcompl	.Lab117
	fstsw	%ax
	sahf
	jb	.Lab114
.Lab115:
.LN89:
	.stabn  68,0,219,.LN89-MathLib_sqrtL		# line 219, column 5
	movl	-28(%ebp),%eax
	andl	$1,%eax
	xorl	$1,%eax
	jnz	.Lab118
.Lab119:
.LN90:
	.stabn  68,0,220,.LN90-MathLib_sqrtL		# line 220, column 9
	.data
	.align 4
.Lab120:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab120
	fmull	-16(%ebp) 
	fstpl	-16(%ebp)
.LN91:
	.stabn  68,0,221,.LN91-MathLib_sqrtL		# line 221, column 7
	decl	-28(%ebp) 
.Lab118:
.LN92:
	.stabn  68,0,223,.LN92-MathLib_sqrtL		# line 223, column 10
	.data
	.align 4
.Lab121:
	.long	-1,1071644671		# +0.49999999999999991E0
	.text
	.data
	.align 4
.Lab122:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	-16(%ebp)
	faddl	.Lab122 
	fmull	.Lab121 
	fstpl	-24(%ebp)
	jmp	.Lab123
.Lab124:
.LN93:
	.stabn  68,0,225,.LN93-MathLib_sqrtL		# line 225, column 12
	.data
	.align 4
.Lab126:
	.long	-5,1104150527		# +0.10737418239999985E10
	.text
	fldl	.Lab126
	fmull	-24(%ebp) 
	fstpl	-24(%ebp)
.LN94:
	.stabn  68,0,226,.LN94-MathLib_sqrtL		# line 226, column 7
	subl	$60,-28(%ebp) 
.Lab123:
.LN95:
	.stabn  68,0,224,.LN95-MathLib_sqrtL		# line 224, column 15
	cmpl	$60,-28(%ebp)
	jg	.Lab124
.Lab125:
	jmp	.Lab127
.Lab128:
.LN96:
	.stabn  68,0,229,.LN96-MathLib_sqrtL		# line 229, column 12
	fldl	-24(%ebp)
	.data
	.align 4
.Lab130:
	.long	-5,1104150527		# +0.10737418239999985E10
	.text
	fdivl	.Lab130 
	fstpl	-24(%ebp)
.LN97:
	.stabn  68,0,230,.LN97-MathLib_sqrtL		# line 230, column 7
	addl	$60,-28(%ebp) 
.Lab127:
.LN98:
	.stabn  68,0,228,.LN98-MathLib_sqrtL		# line 228, column 15
	cmpl	$-60,-28(%ebp)
	jl	.Lab128
.Lab129:
.LN99:
	.stabn  68,0,232,.LN99-MathLib_sqrtL		# line 232, column 5
	cmpl	$0,-28(%ebp)
	jl	.Lab133
.Lab132:
.LN100:
	.stabn  68,0,233,.LN100-MathLib_sqrtL		# line 233, column 12
	movl	-28(%ebp),%eax
	sarl	$1, %eax 
	.data
	.align 4
.Lab134:
	.long	0,2147483647
	.text
	boundl	%eax,.Lab134
	pushl	%eax
	call	MathLib_sqrtL_TwoPower
	addl	$4, %esp
	fmull	-24(%ebp) 
	fstpl	-24(%ebp)
	jmp	.Lab131
.Lab133:
.LN101:
	.stabn  68,0,235,.LN101-MathLib_sqrtL		# line 235, column 12
	movl	-28(%ebp),%eax
	sarl	$1, %eax 
	negl	%eax
	.data
	.align 4
.Lab135:
	.long	0,2147483647
	.text
	boundl	%eax,.Lab135
	pushl	%eax
	call	MathLib_sqrtL_TwoPower
	addl	$4, %esp
	fdivrl	-24(%ebp) 
	fstpl	-24(%ebp)
.Lab131:
.LN102:
	.stabn  68,0,237,.LN102-MathLib_sqrtL		# line 237, column 5
	movl	$0,-32(%ebp) 
.Lab136:
.LN103:
	.stabn  68,0,237,.LN103-MathLib_sqrtL		# line 237, column 29
	.data
	.align 4
.Lab138:
	.long	-1,1071644671		# +0.49999999999999991E0
	.text
	fldl	8(%ebp)
	fdivl	-24(%ebp) 
	faddl	-24(%ebp) 
	fmull	.Lab138 
	fstpl	-24(%ebp)
.LN104:
	.stabn  68,0,237,.LN104-MathLib_sqrtL		# line 237, column 5
	cmpl	$4,-32(%ebp)
	jae	.Lab137
	incl	-32(%ebp) 
	jmp	.Lab136
.Lab137:
.LN105:
	.stabn  68,0,238,.LN105-MathLib_sqrtL		# line 238, column 5
	fldl	-24(%ebp)
	leave
	ret
.LN106:
	.stabn  68,0,239,.LN106-MathLib_sqrtL		# line 239, column 0
	call	ReturnErr_
.LBE16:
	leave
	ret
	.Lab104 = 32
	.stabs "i:17=4",128,0,4,-32
	.stabs "exp:7",128,0,4,-28
	.stabs "temp:10",128,0,8,-24
	.stabs "x:10",128,0,8,-16
	.stabs "L30:c=r1.07374182399999873460E9",128,0,0,0
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB16-MathLib_sqrtL
	.stabn 224,0,0,.LBE16-MathLib_sqrtL
	.stabs "MathLib_sqrt:F9",36,0,0,MathLib_sqrt
	.align 4
MathLib_sqrt:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab139, %esp
.LN107:
	.stabn  68,0,192,.LN107-MathLib_sqrt		# line 192, column 3
.LBB17:
.LN108:
	.stabn  68,0,193,.LN108-MathLib_sqrt		# line 193, column 5
	flds	8(%ebp)
	fsqrt
	.data
	.align 4
.Lab140:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab141:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab140
	fstsw	%ax
	sahf
	jb	.Lab143
	fcoml	.Lab141
	fstsw	%ax
	sahf
	jbe	.Lab142
.Lab143:
   	call	BoundErr_		
.Lab142:
	leave
	ret
.LN109:
	.stabn  68,0,194,.LN109-MathLib_sqrt		# line 194, column 0
	call	ReturnErr_
.LBE17:
	leave
	ret
	.Lab139 = 4
	.stabs "arg:p9",160,0,4,8
	.stabn 192,0,0,.LBB17-MathLib_sqrt
	.stabn 224,0,0,.LBE17-MathLib_sqrt
	.stabs "MathLib_sinus:F10",36,0,0,MathLib_sinus
	.align 4
MathLib_sinus:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab144, %esp
.LN110:
	.stabn  68,0,168,.LN110-MathLib_sinus		# line 168, column 3
.LBB18:
.LN111:
	.stabn  68,0,169,.LN111-MathLib_sinus		# line 169, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab147:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab147
	fstsw	%ax
	sahf
	jae	.Lab145
.Lab146:
.LN112:
	.stabn  68,0,170,.LN112-MathLib_sinus		# line 170, column 8
	fldl	8(%ebp)
	fchs 
	fstpl	8(%ebp)
.LN113:
	.stabn  68,0,171,.LN113-MathLib_sinus		# line 171, column 6
	addl	$2,16(%ebp) 
.Lab145:
.LN114:
	.stabn  68,0,173,.LN114-MathLib_sinus		# line 173, column 7
	.data
	.align 4
.Lab148:
	.long	1841940611,1071931184		# +0.63661977236758131E0
	.text
	fldl	.Lab148
	fmull	8(%ebp) 
	fstpl	8(%ebp)
.LN115:
	.stabn  68,0,174,.LN115-MathLib_sinus		# line 174, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab152:
	.long	0,1088421632		# +0.32763999999999984E5
	.text
	fcompl	.Lab152
	fstsw	%ax
	sahf
	jbe	.Lab151
.Lab150:
.LN116:
	.stabn  68,0,175,.LN116-MathLib_sinus		# line 175, column 9
	leal	-36(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_modf
	addl	$12, %esp
	fstpl	-16(%ebp)
.LN117:
	.stabn  68,0,176,.LN117-MathLib_sinus		# line 176, column 7
	movl	16(%ebp),%eax
	addl	%eax,-36(%ebp) 
.LN118:
	.stabn  68,0,177,.LN118-MathLib_sinus		# line 177, column 13
	leal	-40(%ebp),%eax
	pushl	%eax
	.data
	.align 4
.Lab153:
	.long	1048575999		# +0.24999998509883880E0
	.text
	fildl	-36(%ebp)
	fmuls	.Lab153 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_modf
	addl	$12, %esp
	fstpl	-24(%ebp)
.LN119:
	.stabn  68,0,178,.LN119-MathLib_sinus		# line 178, column 12
	movl	-36(%ebp),%ebx
	movl	-40(%ebp),%eax
	addl	%eax, %eax
	addl	%eax, %eax
 	subl	%eax,%ebx 
	movl	%ebx,16(%ebp) 
	jmp	.Lab149
.Lab151:
.LN120:
	.stabn  68,0,180,.LN120-MathLib_sinus		# line 180, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab154:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab155:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab154
	fstsw	%ax
	sahf
	jb	.Lab157
	fcoml	.Lab155
	fstsw	%ax
	sahf
	jbe	.Lab156
.Lab157:
   	call	BoundErr_		
.Lab156:
	fldcw	fpucw_round_to_neginf
	fistpl	-44(%ebp)
.LN121:
	.stabn  68,0,181,.LN121-MathLib_sinus		# line 181, column 9
	fildl	-44(%ebp)
	fsubrl	8(%ebp) 
	fstpl	-16(%ebp)
.LN122:
	.stabn  68,0,182,.LN122-MathLib_sinus		# line 182, column 12
	movl	-44(%ebp),%eax
 	addl	16(%ebp),%eax 
	movl	$4,%ebx
	cdq
	idivl	%ebx
	movl	%edx,16(%ebp) 
.Lab149:
.LN123:
	.stabn  68,0,184,.LN123-MathLib_sinus		# line 184, column 5
	movl	16(%ebp),%eax
	andl	$1,%eax
	xorl	$1,%eax
	jnz	.Lab158
.Lab159:
.LN124:
	.stabn  68,0,184,.LN124-MathLib_sinus		# line 184, column 26
	.data
	.align 4
.Lab160:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	.Lab160
	fsubl	-16(%ebp) 
	fstpl	-16(%ebp)
.Lab158:
.LN125:
	.stabn  68,0,185,.LN125-MathLib_sinus		# line 185, column 5
	cmpl	$1,16(%ebp)
	jle	.Lab161
.Lab162:
.LN126:
	.stabn  68,0,185,.LN126-MathLib_sinus		# line 185, column 24
	fldl	-16(%ebp)
	fchs 
	fstpl	-16(%ebp)
.Lab161:
.LN127:
	.stabn  68,0,186,.LN127-MathLib_sinus		# line 186, column 9
	fldl	-16(%ebp)
	fmull	-16(%ebp) 
	fstpl	-32(%ebp)
.LN128:
	.stabn  68,0,187,.LN128-MathLib_sinus		# line 187, column 5
	.data
	.align 4
.Lab163:
	.long	-1104920729,1080180480		# +0.14596884066657655E3
	.text
	fldl	-32(%ebp)
	fmull	.Lab163 
	.data
	.align 4
.Lab164:
	.long	-515492556,-1060435038		# -0.13847272499824496E5
	.text
	faddl	.Lab164 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab165:
	.long	919767694,1092279452		# +0.44010305353752574E6
	.text
	faddl	.Lab165 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab166:
	.long	108343599,-1051534577		# -0.49429081009028363E7
	.text
	faddl	.Lab166 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab167:
	.long	525475142,1097459275		# +0.13578840978773714E8
	.text
	faddl	.Lab167 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab168:
	.long	1706294303,1080071401		# +0.13265349087861335E3
	.text
	fldl	.Lab168
	faddl	-32(%ebp) 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab169:
	.long	1292771795,1086487436		# +0.94630961015381931E4
	.text
	faddl	.Lab169 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab170:
	.long	-425470981,1092151756		# +0.40817922523432921E6
	.text
	faddl	.Lab170 
	fmull	-32(%ebp) 
	.data
	.align 4
.Lab171:
	.long	-723206714,1096842489		# +0.86445586529225160E7
	.text
	faddl	.Lab171 
	fdivrp	%st,%st(1)
	leave
	ret
.LN129:
	.stabn  68,0,188,.LN129-MathLib_sinus		# line 188, column 0
	call	ReturnErr_
.LBE18:
	leave
	ret
	.Lab144 = 44
	.stabs "q3:c=r1.32653490878613378178E2",128,0,0,0
	.stabs "q2:c=r9.46309610153819491529E3",128,0,0,0
	.stabs "q1:c=r4.08179225234329301486E5",128,0,0,0
	.stabs "q0:c=r8.64455865292251779408E6",128,0,0,0
	.stabs "p4:c=r1.45968840666576582520E2",128,0,0,0
	.stabs "p3:c=r-1.38472724998244988370E4",128,0,0,0
	.stabs "p2:c=r4.40103053537525834570E5",128,0,0,0
	.stabs "p1:c=r-4.94290810090283727618E6",128,0,0,0
	.stabs "p0:c=r1.35788409787737163192E7",128,0,0,0
	.stabs "k:7",128,0,4,-44
	.stabs "f:7",128,0,4,-40
	.stabs "e:7",128,0,4,-36
	.stabs "ysq:10",128,0,8,-32
	.stabs "dummy:10",128,0,8,-24
	.stabs "y:10",128,0,8,-16
	.stabs "quad:p7",160,0,4,16
	.stabs "x:p10",160,0,8,8
	.stabn 192,0,0,.LBB18-MathLib_sinus
	.stabn 224,0,0,.LBE18-MathLib_sinus
	.stabs "MathLib_sarctan_xatan:F10",36,0,0,MathLib_sarctan_xatan
	.align 4
MathLib_sarctan_xatan:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab172, %esp
.LN130:
	.stabn  68,0,134,.LN130-MathLib_sarctan_xatan		# line 134, column 5
.LBB19:
.LN131:
	.stabn  68,0,135,.LN131-MathLib_sarctan_xatan		# line 135, column 13
	fldl	8(%ebp)
	fmull	8(%ebp) 
	fstpl	-16(%ebp)
.LN132:
	.stabn  68,0,136,.LN132-MathLib_sarctan_xatan		# line 136, column 7
	.data
	.align 4
.Lab173:
	.long	155135687,1076897621		# +0.16153641298222987E2
	.text
	fldl	-16(%ebp)
	fmull	.Lab173 
	.data
	.align 4
.Lab174:
	.long	-970285338,1081132750		# +0.26842548195503903E3
	.text
	faddl	.Lab174 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab175:
	.long	240421341,1083311134		# +0.11530293515404834E4
	.text
	faddl	.Lab175 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab176:
	.long	292176279,1083953568		# +0.17804063164331940E4
	.text
	faddl	.Lab176 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab177:
	.long	-1396607256,1082918473		# +0.89678597403663715E3
	.text
	faddl	.Lab177 
	.data
	.align 4
.Lab178:
	.long	41320635,1078819454		# +0.58956970508444506E2
	.text
	fldl	.Lab178
	faddl	-16(%ebp) 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab179:
	.long	2087422512,1082180127		# +0.53626537403121421E3
	.text
	faddl	.Lab179 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab180:
	.long	-1604433182,1083837218		# +0.16667838148816298E4
	.text
	faddl	.Lab180 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab181:
	.long	-2117779447,1084243627		# +0.20793349744454059E4
	.text
	faddl	.Lab181 
	fmull	-16(%ebp) 
	.data
	.align 4
.Lab182:
	.long	-1396607256,1082918473		# +0.89678597403663715E3
	.text
	faddl	.Lab182 
	fdivrp	%st,%st(1)
	fmull	8(%ebp) 
	leave
	ret
.LN133:
	.stabn  68,0,137,.LN133-MathLib_sarctan_xatan		# line 137, column 0
	call	ReturnErr_
.LBE19:
	leave
	ret
	.Lab172 = 16
	.stabs "argsq:10",128,0,8,-16
	.stabs "q0:c=r8.96785974036637334450E2",128,0,0,0
	.stabs "q1:c=r2.07933497444540593690E3",128,0,0,0
	.stabs "q2:c=r1.66678381488163003254E3",128,0,0,0
	.stabs "q3:c=r5.36265374031214303585E2",128,0,0,0
	.stabs "q4:c=r5.89569705084445150333E1",128,0,0,0
	.stabs "p0:c=r8.96785974036637334450E2",128,0,0,0
	.stabs "p1:c=r1.78040631643319420263E3",128,0,0,0
	.stabs "p2:c=r1.15302935154048369348E3",128,0,0,0
	.stabs "p3:c=r2.68425481955039080261E2",128,0,0,0
	.stabs "p4:c=r1.61536412982229888868E1",128,0,0,0
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB19-MathLib_sarctan_xatan
	.stabn 224,0,0,.LBE19-MathLib_sarctan_xatan
	.stabs "MathLib_sarctan:F10",36,0,0,MathLib_sarctan
	.align 4
MathLib_sarctan:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab183, %esp
.LN134:
	.stabn  68,0,145,.LN134-MathLib_sarctan		# line 145, column 3
.LBB20:
.LN135:
	.stabn  68,0,146,.LN135-MathLib_sarctan		# line 146, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab187:
	.long	-1711476952,1071284857		# +0.41421356237309447E0
	.text
	fcompl	.Lab187
	fstsw	%ax
	sahf
	jae	.Lab186
.Lab185:
.LN136:
	.stabn  68,0,147,.LN136-MathLib_sarctan		# line 147, column 7
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_sarctan_xatan
	addl	$8, %esp
	leave
	ret
	jmp	.Lab184
.Lab186:
.LN137:
	.stabn  68,0,148,.LN137-MathLib_sarctan		# line 148, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab191:
	.long	859807205,1073958991		# +0.24142135623730940E1
	.text
	fcompl	.Lab191
	fstsw	%ax
	sahf
	jbe	.Lab190
.Lab189:
.LN138:
	.stabn  68,0,149,.LN138-MathLib_sarctan		# line 149, column 7
	.data
	.align 4
.Lab192:
	.long	1413754135,1073291771		# +0.15707963267948961E1
	.text
	.data
	.align 4
.Lab193:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	.Lab193
	fdivl	8(%ebp) 
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_sarctan_xatan
	addl	$8, %esp
	fsubrl	.Lab192 
	leave
	ret
	jmp	.Lab188
.Lab190:
.LN139:
	.stabn  68,0,151,.LN139-MathLib_sarctan		# line 151, column 7
	.data
	.align 4
.Lab194:
	.long	1413754135,1072243195		# +0.78539816339744810E0
	.text
	fldl	8(%ebp)
	.data
	.align 4
.Lab195:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fsubl	.Lab195 
	.data
	.align 4
.Lab196:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fldl	.Lab196
	faddl	8(%ebp) 
	fdivrp	%st,%st(1)
	subl	$8,%esp
	fstpl	(%esp)
	call	MathLib_sarctan_xatan
	addl	$8, %esp
	faddl	.Lab194 
	leave
	ret
.Lab188:
.Lab184:
.LN140:
	.stabn  68,0,152,.LN140-MathLib_sarctan		# line 152, column 0
	call	ReturnErr_
.LBE20:
	leave
	ret
	.Lab183 = 4
	.stabs "sq2p1:c=r2.41421356237309447934E0",128,0,0,0
	.stabs "sq2m1:c=r4.14213562373094479340E-1",128,0,0,0
	.stabs "arg:p10",160,0,8,8
	.stabn 192,0,0,.LBB20-MathLib_sarctan
	.stabn 224,0,0,.LBE20-MathLib_sarctan
	.stabs "MathLib_modf:F10",36,0,0,MathLib_modf
	.align 4
MathLib_modf:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab197, %esp
.LN141:
	.stabn  68,0,109,.LN141-MathLib_modf		# line 109, column 3
.LBB21:
.LN142:
	.stabn  68,0,110,.LN142-MathLib_modf		# line 110, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab198:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab198
	fstsw	%ax
	sahf
	setb	%bl
	movb	%bl,-5(%ebp) 
.LN143:
	.stabn  68,0,111,.LN143-MathLib_modf		# line 111, column 5
	cmpb	$0,-5(%ebp)
	je	.Lab199
.Lab200:
.LN144:
	.stabn  68,0,111,.LN144-MathLib_modf		# line 111, column 23
	fldl	8(%ebp)
	fchs 
	fstpl	8(%ebp)
.Lab199:
.LN145:
	.stabn  68,0,112,.LN145-MathLib_modf		# line 112, column 9
	movl	16(%ebp),%eax
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	MathLib_Trunc
	addl	$8, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN146:
	.stabn  68,0,113,.LN146-MathLib_modf		# line 113, column 11
	movl	16(%ebp),%eax
	pushl	(%eax)
	call	MathLib_Float
	addl	$4, %esp
	fsubrl	8(%ebp) 
	fstpl	8(%ebp)
.LN147:
	.stabn  68,0,114,.LN147-MathLib_modf		# line 114, column 5
	cmpb	$0,-5(%ebp)
	je	.Lab201
.Lab202:
.LN148:
	.stabn  68,0,114,.LN148-MathLib_modf		# line 114, column 21
	movl	16(%ebp),%ebx
	movl	16(%ebp),%eax
	movl	(%eax),%eax
	negl	%eax
	movl	%eax,(%ebx) 
.Lab201:
.LN149:
	.stabn  68,0,115,.LN149-MathLib_modf		# line 115, column 5
	fldl	8(%ebp)
	leave
	ret
.LN150:
	.stabn  68,0,116,.LN150-MathLib_modf		# line 116, column 0
	call	ReturnErr_
.LBE21:
	leave
	ret
	.Lab197 = 8
	.stabs "neg:1",128,0,1,-5
	.stabs "int:v7",160,0,4,16
	.stabs "value:p10",160,0,8,8
	.stabn 192,0,0,.LBB21-MathLib_modf
	.stabn 224,0,0,.LBE21-MathLib_modf
	.stabs "MathLib_ldexp:F10",36,0,0,MathLib_ldexp
	.align 4
MathLib_ldexp:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab203, %esp
.LN151:
	.stabn  68,0,96,.LN151-MathLib_ldexp		# line 96, column 3
.LBB22:
.LN152:
	.stabn  68,0,97,.LN152-MathLib_ldexp		# line 97, column 5
	cmpl	$0,16(%ebp)
	jle	.Lab206
.Lab205:
.LN153:
	.stabn  68,0,98,.LN153-MathLib_ldexp		# line 98, column 7
	movl	16(%ebp),%eax
	movl	%eax,-12(%ebp) 
	cmpl	$1,-12(%ebp)
	jl	.Lab207
	movl	$1,-8(%ebp) 
	movl	-12(%ebp),%eax
	movl	%eax,-16(%ebp) 
.Lab208:
.LN154:
	.stabn  68,0,98,.LN154-MathLib_ldexp		# line 98, column 35
	.data
	.align 4
.Lab209:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab209
	fmull	8(%ebp) 
	fstpl	8(%ebp)
.LN155:
	.stabn  68,0,98,.LN155-MathLib_ldexp		# line 98, column 7
	movl	-8(%ebp),%eax
	cmpl	-16(%ebp),%eax
	jge	.Lab207
	incl	-8(%ebp) 
	jmp	.Lab208
.Lab207:
	jmp	.Lab204
.Lab206:
.LN156:
	.stabn  68,0,99,.LN156-MathLib_ldexp		# line 99, column 5
	cmpl	$0,16(%ebp)
	jge	.Lab210
.Lab211:
.LN157:
	.stabn  68,0,100,.LN157-MathLib_ldexp		# line 100, column 7
	movl	16(%ebp),%eax
	negl	%eax
	movl	%eax,-20(%ebp) 
	cmpl	$1,-20(%ebp)
	jl	.Lab212
	movl	$1,-8(%ebp) 
	movl	-20(%ebp),%eax
	movl	%eax,-24(%ebp) 
.Lab213:
.LN158:
	.stabn  68,0,100,.LN158-MathLib_ldexp		# line 100, column 35
	fldl	8(%ebp)
	.data
	.align 4
.Lab214:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fdivl	.Lab214 
	fstpl	8(%ebp)
.LN159:
	.stabn  68,0,100,.LN159-MathLib_ldexp		# line 100, column 7
	movl	-8(%ebp),%eax
	cmpl	-24(%ebp),%eax
	jge	.Lab212
	incl	-8(%ebp) 
	jmp	.Lab213
.Lab212:
.Lab210:
.Lab204:
.LN160:
	.stabn  68,0,102,.LN160-MathLib_ldexp		# line 102, column 5
	fldl	8(%ebp)
	leave
	ret
.LN161:
	.stabn  68,0,103,.LN161-MathLib_ldexp		# line 103, column 0
	call	ReturnErr_
.LBE22:
	leave
	ret
	.Lab203 = 24
	.stabs "i:7",128,0,4,-8
	.stabs "exp:p7",160,0,4,16
	.stabs "value:p10",160,0,8,8
	.stabn 192,0,0,.LBB22-MathLib_ldexp
	.stabn 224,0,0,.LBE22-MathLib_ldexp
	.stabs "MathLib_frexp:F10",36,0,0,MathLib_frexp
	.align 4
MathLib_frexp:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab215, %esp
.LN162:
	.stabn  68,0,76,.LN162-MathLib_frexp		# line 76, column 3
.LBB23:
.LN163:
	.stabn  68,0,77,.LN163-MathLib_frexp		# line 77, column 9
	movl	16(%ebp),%eax
	movl	$0,(%eax) 
.LN164:
	.stabn  68,0,78,.LN164-MathLib_frexp		# line 78, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab216:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab216
	fstsw	%ax
	sahf
	setb	%bl
	movb	%bl,-5(%ebp) 
.LN165:
	.stabn  68,0,79,.LN165-MathLib_frexp		# line 79, column 5
	cmpb	$0,-5(%ebp)
	je	.Lab217
.Lab218:
.LN166:
	.stabn  68,0,79,.LN166-MathLib_frexp		# line 79, column 19
	fldl	8(%ebp)
	fchs 
	fstpl	8(%ebp)
.Lab217:
.LN167:
	.stabn  68,0,80,.LN167-MathLib_frexp		# line 80, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab222:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fcompl	.Lab222
	fstsw	%ax
	sahf
	jb	.Lab221
.Lab220:
.Lab223:
.LN168:
	.stabn  68,0,82,.LN168-MathLib_frexp		# line 82, column 9
	movl	16(%ebp),%eax
	incl	(%eax) 
.LN169:
	.stabn  68,0,82,.LN169-MathLib_frexp		# line 82, column 22
	fldl	8(%ebp)
	.data
	.align 4
.Lab225:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fdivl	.Lab225 
	fstpl	8(%ebp)
.LN170:
	.stabn  68,0,83,.LN170-MathLib_frexp		# line 83, column 15
	fldl	8(%ebp)
	.data
	.align 4
.Lab226:
	.long	0,1072693248		# +0.09999999999999998E1
	.text
	fcompl	.Lab226
	fstsw	%ax
	sahf
	jae	.Lab223
.Lab224:
	jmp	.Lab219
.Lab221:
.LN171:
	.stabn  68,0,84,.LN171-MathLib_frexp		# line 84, column 5
	fldl	8(%ebp)
	.data
	.align 4
.Lab230:
	.long	-1717986919,1069128089		# +0.09999999999999998E0
	.text
	fcompl	.Lab230
	fstsw	%ax
	sahf
	jae	.Lab227
.Lab229:
	fldl	8(%ebp)
	.data
	.align 4
.Lab231:
	.long	0,0		# +0.0E0
	.text
	fcompl	.Lab231
	fstsw	%ax
	sahf
	je	.Lab227
.Lab228:
.Lab232:
.LN172:
	.stabn  68,0,86,.LN172-MathLib_frexp		# line 86, column 9
	movl	16(%ebp),%eax
	decl	(%eax) 
.LN173:
	.stabn  68,0,86,.LN173-MathLib_frexp		# line 86, column 22
	.data
	.align 4
.Lab234:
	.long	0,1073741824		# +0.19999999999999996E1
	.text
	fldl	.Lab234
	fmull	8(%ebp) 
	fstpl	8(%ebp)
.LN174:
	.stabn  68,0,87,.LN174-MathLib_frexp		# line 87, column 15
	fldl	8(%ebp)
	.data
	.align 4
.Lab235:
	.long	-1717986919,1069128089		# +0.09999999999999998E0
	.text
	fcompl	.Lab235
	fstsw	%ax
	sahf
	jb	.Lab232
.Lab233:
.Lab227:
.Lab219:
.LN175:
	.stabn  68,0,89,.LN175-MathLib_frexp		# line 89, column 5
	cmpb	$0,-5(%ebp)
	je	.Lab236
.Lab237:
.LN176:
	.stabn  68,0,89,.LN176-MathLib_frexp		# line 89, column 19
	fldl	8(%ebp)
	fchs 
	fstpl	8(%ebp)
.Lab236:
.LN177:
	.stabn  68,0,90,.LN177-MathLib_frexp		# line 90, column 5
	fldl	8(%ebp)
	leave
	ret
.LN178:
	.stabn  68,0,91,.LN178-MathLib_frexp		# line 91, column 0
	call	ReturnErr_
.LBE23:
	leave
	ret
	.Lab215 = 8
	.stabs "neg:1",128,0,1,-5
	.stabs "exp:v7",160,0,4,16
	.stabs "x:p10",160,0,8,8
	.stabn 192,0,0,.LBB23-MathLib_frexp
	.stabn 224,0,0,.LBE23-MathLib_frexp
	.stabs "MathLib_Float:F10",36,0,0,MathLib_Float
	.align 4
MathLib_Float:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab238, %esp
.LN179:
	.stabn  68,0,66,.LN179-MathLib_Float		# line 66, column 3
.LBB24:
.LN180:
	.stabn  68,0,67,.LN180-MathLib_Float		# line 67, column 10
	movl	8(%ebp),%eax
	movl	$65535,%ebx
	cdq
	idivl	%ebx
	.data
	.align 4
.Lab239:
	.long	0,2147483647
	.text
	boundl	%eax,.Lab239
	movl	%eax,-8(%ebp) 
.LN181:
	.stabn  68,0,67,.LN181-MathLib_Float		# line 67, column 34
	fildl	-8(%ebp)
	cmpl	$0x7fffffff,-8(%ebp)
	jbe	.Lab240
	faddl	TwoExp32_
.Lab240:
	fstpl	-24(%ebp)
.LN182:
	.stabn  68,0,68,.LN182-MathLib_Float		# line 68, column 10
	movl	8(%ebp),%eax
	movl	$65535,%ebx
	cdq
	idivl	%ebx
	.data
	.align 4
.Lab241:
	.long	0,2147483647
	.text
	boundl	%edx,.Lab241
	movl	%edx,-12(%ebp) 
.LN183:
	.stabn  68,0,68,.LN183-MathLib_Float		# line 68, column 34
	fildl	-12(%ebp)
	cmpl	$0x7fffffff,-12(%ebp)
	jbe	.Lab242
	faddl	TwoExp32_
.Lab242:
	fstpl	-32(%ebp)
.LN184:
	.stabn  68,0,69,.LN184-MathLib_Float		# line 69, column 5
	.data
	.align 4
.Lab243:
	.long	0,1089470432		# +0.65534999999999969E5
	.text
	fldl	.Lab243
	fmull	-24(%ebp) 
	faddl	-32(%ebp) 
	leave
	ret
.LN185:
	.stabn  68,0,70,.LN185-MathLib_Float		# line 70, column 0
	call	ReturnErr_
.LBE24:
	leave
	ret
	.Lab238 = 32
	.stabs "modR:10",128,0,8,-32
	.stabs "divR:10",128,0,8,-24
	.stabs "modC:4",128,0,4,-12
	.stabs "divC:4",128,0,4,-8
	.stabs "x:p7",160,0,4,8
	.stabn 192,0,0,.LBB24-MathLib_Float
	.stabn 224,0,0,.LBE24-MathLib_Float
	.stabs "MathLib_Trunc:F7",36,0,0,MathLib_Trunc
	.align 4
MathLib_Trunc:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab244, %esp
.LN186:
	.stabn  68,0,44,.LN186-MathLib_Trunc		# line 44, column 3
.LBB25:
.LN187:
	.stabn  68,0,45,.LN187-MathLib_Trunc		# line 45, column 9
	movl	$0,-12(%ebp) 
	jmp	.Lab245
.Lab246:
.LN188:
	.stabn  68,0,47,.LN188-MathLib_Trunc		# line 47, column 9
	fldl	8(%ebp)
	.data
	.align 4
.Lab248:
	.long	0,1089470432		# +0.65534999999999969E5
	.text
	fdivl	.Lab248 
	fstpl	8(%ebp)
.LN189:
	.stabn  68,0,47,.LN189-MathLib_Trunc		# line 47, column 26
	incl	-12(%ebp) 
.Lab245:
.LN190:
	.stabn  68,0,46,.LN190-MathLib_Trunc		# line 46, column 13
	fldl	8(%ebp)
	.data
	.align 4
.Lab249:
	.long	0,1089470432		# +0.65534999999999969E5
	.text
	fcompl	.Lab249
	fstsw	%ax
	sahf
	jae	.Lab246
.Lab247:
.LN191:
	.stabn  68,0,49,.LN191-MathLib_Trunc		# line 49, column 8
	fldl	8(%ebp)
	.data
	.align 4
.Lab250:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab251:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab250
	fstsw	%ax
	sahf
	jb	.Lab253
	fcoml	.Lab251
	fstsw	%ax
	sahf
	jbe	.Lab252
.Lab253:
   	call	BoundErr_		
.Lab252:
	fstps	-24(%ebp)
.LN192:
	.stabn  68,0,50,.LN192-MathLib_Trunc		# line 50, column 9
	flds	-24(%ebp)
	fcoml	TwoExp31_
	fstsw	%ax
	sahf
	jb	.Lab254
	fsubl	TwoExp32_
.Lab254:
	subl	$4,%esp
	fldcw	fpucw_round_to_zero
	fistpl	(%esp)
	popl	%eax
	cmpl	$2147483647,%eax
	jbe	.Lab255
.Lab256:
   	call	BoundErr_		
.Lab255:
	movl	%eax,-8(%ebp) 
.LN193:
	.stabn  68,0,51,.LN193-MathLib_Trunc		# line 51, column 5
	movl	-12(%ebp),%eax
	movl	%eax,-40(%ebp) 
	cmpl	$1,-40(%ebp)
	jl	.Lab257
	movl	$1,-16(%ebp) 
	movl	-40(%ebp),%eax
	movl	%eax,-44(%ebp) 
.Lab258:
.LN194:
	.stabn  68,0,52,.LN194-MathLib_Trunc		# line 52, column 10
	fldl	8(%ebp)
	.data
	.align 4
.Lab259:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab260:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab259
	fstsw	%ax
	sahf
	jb	.Lab262
	fcoml	.Lab260
	fstsw	%ax
	sahf
	jbe	.Lab261
.Lab262:
   	call	BoundErr_		
.Lab261:
	fstps	-24(%ebp)
.LN195:
	.stabn  68,0,53,.LN195-MathLib_Trunc		# line 53, column 10
	flds	-24(%ebp)
	fcoml	TwoExp31_
	fstsw	%ax
	sahf
	jb	.Lab263
	fsubl	TwoExp32_
.Lab263:
	subl	$4,%esp
	fldcw	fpucw_round_to_zero
	fistpl	(%esp)
	popl	%eax
	pushl	%eax
	fildl	(%esp)
	addl	$4,%esp
	cmpl	$0x7fffffff,%eax
	jbe	.Lab264
	faddl	TwoExp32_
.Lab264:
	fstpl	-32(%ebp)
.LN196:
	.stabn  68,0,54,.LN196-MathLib_Trunc		# line 54, column 9
	fldl	8(%ebp)
	fsubl	-32(%ebp) 
	.data
	.align 4
.Lab265:
	.long	0,1089470432		# +0.65534999999999969E5
	.text
	fmull	.Lab265 
	fstpl	8(%ebp)
.LN197:
	.stabn  68,0,55,.LN197-MathLib_Trunc		# line 55, column 10
	fldl	8(%ebp)
	.data
	.align 4
.Lab266:
	.long	-536870912,-940572673		# -0.34028234663852794E39
	.text
	.data
	.align 4
.Lab267:
	.long	-536870912,1206910975		# +0.34028234663852794E39
	.text
	fcoml	.Lab266
	fstsw	%ax
	sahf
	jb	.Lab269
	fcoml	.Lab267
	fstsw	%ax
	sahf
	jbe	.Lab268
.Lab269:
   	call	BoundErr_		
.Lab268:
	fstps	-24(%ebp)
.LN198:
	.stabn  68,0,56,.LN198-MathLib_Trunc		# line 56, column 9
	flds	-24(%ebp)
	fcoml	TwoExp31_
	fstsw	%ax
	sahf
	jb	.Lab270
	fsubl	TwoExp32_
.Lab270:
	subl	$4,%esp
	fistpl	(%esp)
	popl	%eax
	cmpl	$2147483647,%eax
	jbe	.Lab271
.Lab272:
   	call	BoundErr_		
.Lab271:
	movl	%eax,-20(%ebp) 
.LN199:
	.stabn  68,0,57,.LN199-MathLib_Trunc		# line 57, column 11
	imull	$65535,-8(%ebp),%eax 
 	addl	-20(%ebp),%eax 
	movl	%eax,-8(%ebp) 
.LN200:
	.stabn  68,0,51,.LN200-MathLib_Trunc		# line 51, column 5
	movl	-16(%ebp),%eax
	cmpl	-44(%ebp),%eax
	jge	.Lab257
	incl	-16(%ebp) 
	jmp	.Lab258
.Lab257:
.LN201:
	.stabn  68,0,59,.LN201-MathLib_Trunc		# line 59, column 5
	movl	-8(%ebp),%eax
	leave
	ret
.LN202:
	.stabn  68,0,60,.LN202-MathLib_Trunc		# line 60, column 0
	call	ReturnErr_
.LBE25:
	leave
	ret
	.Lab244 = 44
	.stabs "c:4",128,0,4,-36
	.stabs "xL:10",128,0,8,-32
	.stabs "xS:9",128,0,4,-24
	.stabs "j:7",128,0,4,-20
	.stabs "i:7",128,0,4,-16
	.stabs "exp:7",128,0,4,-12
	.stabs "res:7",128,0,4,-8
	.stabs "x:p10",160,0,8,8
	.stabn 192,0,0,.LBB25-MathLib_Trunc
	.stabn 224,0,0,.LBE25-MathLib_Trunc
	.stabs "MathLib:F16",36,0,0,MathLib
	.align 4
MathLib:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab273, %esp
.LN203:
	.stabn  68,0,372,.LN203-MathLib		# line 372, column 1
.LBB26:
.LN204:
	.stabn  68,0,373,.LN204-MathLib		# line 373, column 0
.LBE26:
	leave
	ret
	.Lab273 = 4
	.stabs "MaxCardR:c=r6.55349999999999788258E4",128,0,0,0
	.stabs "MaxCardI:c=i65535",128,0,0,0
	.stabs "sqrt2:c=r1.41421356237309447934E0",128,0,0,0
	.stabs "pio4:c=r7.85398163397448101363E-1",128,0,0,0
	.stabs "pio2:c=r1.57079632679489629154E0",128,0,0,0
	.stabs "twoopi:c=r6.36619772367581315819E-1",128,0,0,0
	.stabs "pi:c=r3.14159265358979267190E0",128,0,0,0
	.stabs "log2:c=r6.93147180559944331434E-1",128,0,0,0
	.stabn 192,0,0,.LBB26-MathLib
	.stabn 224,0,0,.LBE26-MathLib
