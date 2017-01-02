	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maslisp/",100,0,0,.LBB0
	.stabs "SACSYM2.mod",100,0,0,.LBB0
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
	.globl	SACSYM_UWRIT1
	.globl	SACSYM_UWRITE
	.globl	SACSYM_UREAD
	.globl	SACSYM_SUBLIS
	.globl	SACSYM_SYWRIT
	.globl	SACSYM_SymSummary
	.globl	SACSYM_SYMBOL
	.globl	SACSYM_STWRT
	.globl	SACSYM_STSRCH
	.globl	SACSYM_STLSTI
	.globl	SACSYM_STLST
	.globl	SACSYM_STINS
	.globl	SACSYM_STCNT
	.globl	SACSYM_SREAD1
	.globl	SACSYM_SREAD
	.globl	SACSYM_SMEMB
	.globl	SACSYM_REMPRP
	.globl	SACSYM_PUT
	.globl	SACSYM_PACK
	.globl	SACSYM_NAME
	.globl	SACSYM_GET
	.globl	SACSYM_GENSYM
	.globl	SACSYM_ENTER
	.globl	SACSYM_EXPLOD
	.globl	SACSYM_ATTRIB
	.globl	SACSYM_ASSOCQ
	.globl	SACSYM_ASSOC
	.globl	SACSYM_ACOMP1
	.globl	SACSYM_ACOMP
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
	.globl	MASERR_ErrorHandler
	.globl	MASERR_ERROR
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
	.globl	SACSYM2
	.globl	SACSYM2_SSYTBAL
	.globl	SACSYM2_STNLST
	.globl	SACSYM2_STBALS
	.globl	SACSYM2_STBAL
	.stabs "SACSYM2_SSYTBAL:F16",36,0,0,SACSYM2_SSYTBAL
	.align 4
SACSYM2_SSYTBAL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,103,.LN1-SACSYM2_SSYTBAL		# line 103, column 1
.LBB1:
.LN2:
	.stabn  68,0,104,.LN2-SACSYM2_SSYTBAL		# line 104, column 27
	movl	SACSYM_s + 8,%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab2
.Lab3:
.LN3:
	.stabn  68,0,104,.LN3-SACSYM2_SSYTBAL		# line 104, column 47
	leave
	ret
.Lab2:
.LN4:
	.stabn  68,0,105,.LN4-SACSYM2_SSYTBAL		# line 105, column 26
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	SACSYM_s + 8
	call	SACSYM2_STNLST
	addl	$12, %esp
.LN5:
	.stabn  68,0,106,.LN5-SACSYM2_SSYTBAL		# line 106, column 27
	pushl	-12(%ebp)
	pushl	-8(%ebp)
	call	SACSYM2_STBAL
	addl	$8, %esp
	movl	%eax,-8(%ebp) 
.LN6:
	.stabn  68,0,107,.LN6-SACSYM2_SSYTBAL		# line 107, column 7
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab4
.Lab5:
.LN7:
	.stabn  68,0,107,.LN7-SACSYM2_SSYTBAL		# line 107, column 29
	movl	-8(%ebp),%eax
	movl	%eax,SACSYM_s + 8 
.Lab4:
.LN8:
	.stabn  68,0,108,.LN8-SACSYM2_SSYTBAL		# line 108, column 7
	leave
	ret
.LN9:
	.stabn  68,0,109,.LN9-SACSYM2_SSYTBAL		# line 109, column 0
.LBE1:
	leave
	ret
	.Lab1 = 12
	.stabs "n:7",128,0,4,-12
	.stabs "L:7",128,0,4,-8
	.stabn 192,0,0,.LBB1-SACSYM2_SSYTBAL
	.stabn 224,0,0,.LBE1-SACSYM2_SSYTBAL
	.stabs "SACSYM2_STNLST:F16",36,0,0,SACSYM2_STNLST
	.align 4
SACSYM2_STNLST:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab6, %esp
.LN10:
	.stabn  68,0,88,.LN10-SACSYM2_STNLST		# line 88, column 1
.LBB2:
.LN11:
	.stabn  68,0,89,.LN11-SACSYM2_STNLST		# line 89, column 23
	leal	-12(%ebp),%eax
	pushl	%eax
	leal	-24(%ebp),%eax
	pushl	%eax
	leal	-8(%ebp),%eax
	pushl	%eax
	pushl	8(%ebp)
	call	SACLIST_ADV2
	addl	$16, %esp
.LN12:
	.stabn  68,0,89,.LN12-SACSYM2_STNLST		# line 89, column 41
	movl	$0,-28(%ebp) 
.LN13:
	.stabn  68,0,89,.LN13-SACSYM2_STNLST		# line 89, column 48
	movl	$0,-32(%ebp) 
.LN14:
	.stabn  68,0,90,.LN14-SACSYM2_STNLST		# line 90, column 9
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-16(%ebp) 
.LN15:
	.stabn  68,0,90,.LN15-SACSYM2_STNLST		# line 90, column 18
	movl	MASSTOR_s + 8,%eax
	movl	%eax,-20(%ebp) 
.LN16:
	.stabn  68,0,92,.LN16-SACSYM2_STNLST		# line 92, column 7
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab7
.Lab8:
.LN17:
	.stabn  68,0,92,.LN17-SACSYM2_STNLST		# line 92, column 24
	leal	-28(%ebp),%eax
	pushl	%eax
	leal	-16(%ebp),%eax
	pushl	%eax
	pushl	-8(%ebp)
	call	SACSYM2_STNLST
	addl	$12, %esp
.Lab7:
.LN18:
	.stabn  68,0,93,.LN18-SACSYM2_STNLST		# line 93, column 7
	movl	-12(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	je	.Lab9
.Lab10:
.LN19:
	.stabn  68,0,93,.LN19-SACSYM2_STNLST		# line 93, column 24
	leal	-32(%ebp),%eax
	pushl	%eax
	leal	-20(%ebp),%eax
	pushl	%eax
	pushl	-12(%ebp)
	call	SACSYM2_STNLST
	addl	$12, %esp
.Lab9:
.LN20:
	.stabn  68,0,95,.LN20-SACSYM2_STNLST		# line 95, column 8
	movl	12(%ebp),%eax
	pushl	%eax
	pushl	-20(%ebp)
	pushl	8(%ebp)
	call	MASSTOR_COMP
	addl	$8, %esp
	pushl	%eax
	pushl	-16(%ebp)
	call	SACLIST_CONC
	addl	$8, %esp
	popl	%ebx
	movl	%eax,(%ebx) 
.LN21:
	.stabn  68,0,95,.LN21-SACSYM2_STNLST		# line 95, column 32
	movl	16(%ebp),%ebx
	movl	$1,%eax
 	addl	-28(%ebp),%eax 
 	addl	-32(%ebp),%eax 
	movl	%eax,(%ebx) 
.LN22:
	.stabn  68,0,96,.LN22-SACSYM2_STNLST		# line 96, column 7
	leave
	ret
.LN23:
	.stabn  68,0,97,.LN23-SACSYM2_STNLST		# line 97, column 0
.LBE2:
	leave
	ret
	.Lab6 = 32
	.stabs "n2:7",128,0,4,-32
	.stabs "n1:7",128,0,4,-28
	.stabs "S:7",128,0,4,-24
	.stabs "rp:7",128,0,4,-20
	.stabs "lp:7",128,0,4,-16
	.stabs "r:7",128,0,4,-12
	.stabs "l:7",128,0,4,-8
	.stabs "n:v7",160,0,4,16
	.stabs "L:v7",160,0,4,12
	.stabs "T:p7",160,0,4,8
	.stabn 192,0,0,.LBB2-SACSYM2_STNLST
	.stabn 224,0,0,.LBE2-SACSYM2_STNLST
	.stabs "SACSYM2_STBALS:F7",36,0,0,SACSYM2_STBALS
	.align 4
SACSYM2_STBALS:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab11, %esp
.LN24:
	.stabn  68,0,70,.LN24-SACSYM2_STBALS		# line 70, column 1
.LBB3:
.LN25:
	.stabn  68,0,72,.LN25-SACSYM2_STBALS		# line 72, column 7
	movl	16(%ebp),%eax
	cmpl	20(%ebp),%eax
	jne	.Lab12
.Lab13:
.LN26:
	.stabn  68,0,72,.LN26-SACSYM2_STBALS		# line 72, column 22
	movl	16(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN27:
	.stabn  68,0,72,.LN27-SACSYM2_STBALS		# line 72, column 27
	pushl	MASSTOR_s + 8
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab15
	cmpl	12(%ebp),%eax
	jbe	.Lab14
.Lab15:
   	call	BoundErr_		
.Lab14:
	pushl	(%ebx,%eax,4)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.LN28:
	.stabn  68,0,73,.LN28-SACSYM2_STBALS		# line 73, column 21
	pushl	MASSTOR_s + 8
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab17
	cmpl	12(%ebp),%eax
	jbe	.Lab16
.Lab17:
   	call	BoundErr_		
.Lab16:
	pushl	(%ebx,%eax,4)
	call	MASSTOR_RED
	addl	$4, %esp
	pushl	%eax
	call	MASSTOR_SRED
	addl	$8, %esp
.LN29:
	.stabn  68,0,73,.LN29-SACSYM2_STBALS		# line 73, column 42
	movl	-8(%ebp),%eax
	leave
	ret
.Lab12:
.LN30:
	.stabn  68,0,74,.LN30-SACSYM2_STBALS		# line 74, column 23
	movl	20(%ebp),%eax
 	addl	16(%ebp),%eax 
	sarl	$1, %eax 
	movl	%eax,-8(%ebp) 
.LN31:
	.stabn  68,0,75,.LN31-SACSYM2_STBALS		# line 75, column 7
	movl	16(%ebp),%eax
	cmpl	-8(%ebp),%eax
	jne	.Lab20
.Lab19:
.LN32:
	.stabn  68,0,75,.LN32-SACSYM2_STBALS		# line 75, column 21
	pushl	MASSTOR_s + 8
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab22
	cmpl	12(%ebp),%eax
	jbe	.Lab21
.Lab22:
   	call	BoundErr_		
.Lab21:
	pushl	(%ebx,%eax,4)
	call	MASSTOR_SFIRST
	addl	$8, %esp
	jmp	.Lab18
.Lab20:
.LN33:
	.stabn  68,0,76,.LN33-SACSYM2_STBALS		# line 76, column 23
	movl	-8(%ebp),%eax
 	subl	$1,%eax 
	pushl	%eax
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACSYM2_STBALS
	addl	$16, %esp
	movl	%eax,-12(%ebp) 
.LN34:
	.stabn  68,0,76,.LN34-SACSYM2_STBALS		# line 76, column 42
	movl	8(%ebp),%ebx
	movl	-12(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab24
	cmpl	12(%ebp),%eax
	jbe	.Lab23
.Lab24:
   	call	BoundErr_		
.Lab23:
	pushl	(%ebx,%eax,4)
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab26
	cmpl	12(%ebp),%eax
	jbe	.Lab25
.Lab26:
   	call	BoundErr_		
.Lab25:
	pushl	(%ebx,%eax,4)
	call	MASSTOR_SFIRST
	addl	$8, %esp
.Lab18:
.LN35:
	.stabn  68,0,77,.LN35-SACSYM2_STBALS		# line 77, column 9
	pushl	20(%ebp)
	movl	$1,%eax
 	addl	-8(%ebp),%eax 
	pushl	%eax
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	SACSYM2_STBALS
	addl	$16, %esp
	movl	%eax,-16(%ebp) 
.LN36:
	.stabn  68,0,77,.LN36-SACSYM2_STBALS		# line 77, column 28
	movl	8(%ebp),%ebx
	movl	-16(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab28
	cmpl	12(%ebp),%eax
	jbe	.Lab27
.Lab28:
   	call	BoundErr_		
.Lab27:
	pushl	(%ebx,%eax,4)
	movl	8(%ebp),%ebx
	movl	-8(%ebp),%eax
	cmpl	$0,%eax
	jb	.Lab30
	cmpl	12(%ebp),%eax
	jbe	.Lab29
.Lab30:
   	call	BoundErr_		
.Lab29:
	pushl	(%ebx,%eax,4)
	call	MASSTOR_RED
	addl	$4, %esp
	pushl	%eax
	call	MASSTOR_SRED
	addl	$8, %esp
.LN37:
	.stabn  68,0,78,.LN37-SACSYM2_STBALS		# line 78, column 7
	movl	-8(%ebp),%eax
	leave
	ret
.LN38:
	.stabn  68,0,79,.LN38-SACSYM2_STBALS		# line 79, column 0
	call	ReturnErr_
.LBE3:
	leave
	ret
	.Lab11 = 20
	.stabs "L:7",128,0,4,-20
	.stabs "m2:7",128,0,4,-16
	.stabs "m1:7",128,0,4,-12
	.stabs "m:7",128,0,4,-8
	.stabs "r:p7",160,0,4,20
	.stabs "l:p7",160,0,4,16
	.stabs "A:p17=s8start:*7,0,32;high:5,32,32;;",160,0,8,8
	.stabn 192,0,0,.LBB3-SACSYM2_STBALS
	.stabn 224,0,0,.LBE3-SACSYM2_STBALS
	.stabs "SACSYM2_STBAL:F7",36,0,0,SACSYM2_STBAL
	.align 4
SACSYM2_STBAL:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab31, %esp
.LN39:
	.stabn  68,0,51,.LN39-SACSYM2_STBAL		# line 51, column 1
.LBB4:
.LN40:
	.stabn  68,0,53,.LN40-SACSYM2_STBAL		# line 53, column 7
	cmpl	$500,12(%ebp)
	jle	.Lab32
.Lab33:
.LN41:
	.stabn  68,0,53,.LN41-SACSYM2_STBAL		# line 53, column 23
	.data
.Lab34:
 	.ascii	"STBAL: array to small.\000"
	.text
	pushl	$22
	leal	.Lab34,%eax
	pushl	%eax
	pushl	$2
	call	MASERR_ERROR
	addl	$12, %esp
.LN42:
	.stabn  68,0,54,.LN42-SACSYM2_STBAL		# line 54, column 18
	movl	MASSTOR_s + 8,%eax
	leave
	ret
.Lab32:
.LN43:
	.stabn  68,0,55,.LN43-SACSYM2_STBAL		# line 55, column 25
	movl	8(%ebp),%eax
	movl	%eax,-8(%ebp) 
.LN44:
	.stabn  68,0,55,.LN44-SACSYM2_STBAL		# line 55, column 31
	movl	$-1,-12(%ebp) 
	jmp	.Lab35
.Lab36:
.LN45:
	.stabn  68,0,56,.LN45-SACSYM2_STBAL		# line 56, column 27
	incl	-12(%ebp)
.LN46:
	.stabn  68,0,56,.LN46-SACSYM2_STBAL		# line 56, column 38
	movl	-12(%ebp),%eax
	.data
	.align 4
.Lab38:
	.long	0,500
	.text
	boundl	%eax,.Lab38
	pushl	%eax
	pushl	-8(%ebp)
	call	MASSTOR_FIRST
	addl	$4, %esp
	popl	%ebx
	movl	%eax,-2020(%ebp,%ebx,4) 
.LN47:
	.stabn  68,0,57,.LN47-SACSYM2_STBAL		# line 57, column 25
	pushl	-8(%ebp)
	call	MASSTOR_RED
	addl	$4, %esp
	movl	%eax,-8(%ebp) 
.Lab35:
.LN48:
	.stabn  68,0,56,.LN48-SACSYM2_STBAL		# line 56, column 16
	movl	-8(%ebp),%eax
	cmpl	MASSTOR_s + 8,%eax
	jne	.Lab36
.Lab37:
.LN49:
	.stabn  68,0,59,.LN49-SACSYM2_STBAL		# line 59, column 8
	movl	12(%ebp),%eax
 	subl	$1,%eax 
	pushl	%eax
	pushl	$0
	pushl	$500
	leal	-2020(%ebp),%eax
	pushl	%eax
	call	SACSYM2_STBALS
	addl	$16, %esp
	movl	%eax,-16(%ebp) 
.LN50:
	.stabn  68,0,60,.LN50-SACSYM2_STBAL		# line 60, column 7
	movl	-16(%ebp),%eax
	.data
	.align 4
.Lab39:
	.long	0,500
	.text
	boundl	%eax,.Lab39
	movl	-2020(%ebp,%eax,4),%eax
	leave
	ret
.LN51:
	.stabn  68,0,61,.LN51-SACSYM2_STBAL		# line 61, column 0
	call	ReturnErr_
.LBE4:
	leave
	ret
	.Lab31 = 2020
	.stabs "A:18=ar4;0;500;7",128,0,2004,-2020
	.stabs "m:7",128,0,4,-16
	.stabs "i:7",128,0,4,-12
	.stabs "LP:7",128,0,4,-8
	.stabs "n:p7",160,0,4,12
	.stabs "L:p7",160,0,4,8
	.stabn 192,0,0,.LBB4-SACSYM2_STBAL
	.stabn 224,0,0,.LBE4-SACSYM2_STBAL
	.stabs "SACSYM2:F16",36,0,0,SACSYM2
	.align 4
SACSYM2:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab40, %esp
.LN52:
	.stabn  68,0,112,.LN52-SACSYM2		# line 112, column 1
.LBB5:
.LN53:
	.stabn  68,0,113,.LN53-SACSYM2		# line 113, column 0
.LBE5:
	leave
	ret
	.Lab40 = 4
	.stabn 192,0,0,.LBB5-SACSYM2
	.stabn 224,0,0,.LBE5-SACSYM2
