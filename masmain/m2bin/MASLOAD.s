	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/masmain/",100,0,0,.LBB0
	.stabs "MASLOAD.mod",100,0,0,.LBB0
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
	.globl	MLPQSMPL_InitExternalsPQSMPL
	.globl	MLMLDEMO_InitExternalsMLDEMO
	.globl	MLMASLOG_InitExternalsML
	.globl	MASLOADQ_InitExternalsQ
	.globl	MASLOADS_InitExternalsS
	.globl	MASLOADM_InitExternalsM
	.globl	MASLOADL_InitExternalsL
	.globl	MASLOADJ_InitExternalsJ
	.globl	MASLOADG_InitExternalsG
	.globl	MASLOADE_InitExternalsE
	.globl	MASLOADD_InitExternalsD
	.globl	MASLOADC_InitExternalsC
	.globl	MASLOADB_InitExternalsB
	.globl	MASLOADA_InitExternalsA
	.globl	MASLOAD
	.globl	MASLOAD_InitExternals
	.stabs "MASLOAD_InitExternals:F16",36,0,0,MASLOAD_InitExternals
	.align 4
MASLOAD_InitExternals:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,84,.LN1-MASLOAD_InitExternals		# line 84, column 1
.LBB1:
.LN2:
	.stabn  68,0,86,.LN2-MASLOAD_InitExternals		# line 86, column 45
	call	MASLOADA_InitExternalsA
.LN3:
	.stabn  68,0,87,.LN3-MASLOAD_InitExternals		# line 87, column 45
	call	MASLOADB_InitExternalsB
.LN4:
	.stabn  68,0,88,.LN4-MASLOAD_InitExternals		# line 88, column 45
	call	MASLOADC_InitExternalsC
.LN5:
	.stabn  68,0,89,.LN5-MASLOAD_InitExternals		# line 89, column 45
	call	MASLOADD_InitExternalsD
.LN6:
	.stabn  68,0,90,.LN6-MASLOAD_InitExternals		# line 90, column 45
	call	MASLOADG_InitExternalsG
.LN7:
	.stabn  68,0,91,.LN7-MASLOAD_InitExternals		# line 91, column 45
	call	MASLOADE_InitExternalsE
.LN8:
	.stabn  68,0,92,.LN8-MASLOAD_InitExternals		# line 92, column 45
	call	MASLOADJ_InitExternalsJ
.LN9:
	.stabn  68,0,93,.LN9-MASLOAD_InitExternals		# line 93, column 45
	call	MASLOADQ_InitExternalsQ
.LN10:
	.stabn  68,0,94,.LN10-MASLOAD_InitExternals		# line 94, column 45
	call	MASLOADL_InitExternalsL
.LN11:
	.stabn  68,0,95,.LN11-MASLOAD_InitExternals		# line 95, column 45
	call	MASLOADM_InitExternalsM
.LN12:
	.stabn  68,0,96,.LN12-MASLOAD_InitExternals		# line 96, column 45
	call	MASLOADS_InitExternalsS
.LN13:
	.stabn  68,0,97,.LN13-MASLOAD_InitExternals		# line 97, column 45
	call	MLMASLOG_InitExternalsML
.LN14:
	.stabn  68,0,98,.LN14-MASLOAD_InitExternals		# line 98, column 45
	call	MLMLDEMO_InitExternalsMLDEMO
.LN15:
	.stabn  68,0,99,.LN15-MASLOAD_InitExternals		# line 99, column 45
	call	MLPQSMPL_InitExternalsPQSMPL
.LN16:
	.stabn  68,0,100,.LN16-MASLOAD_InitExternals		# line 100, column 0
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabn 192,0,0,.LBB1-MASLOAD_InitExternals
	.stabn 224,0,0,.LBE1-MASLOAD_InitExternals
	.stabs "MASLOAD:F16",36,0,0,MASLOAD
	.align 4
MASLOAD:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab2, %esp
.LN17:
	.stabn  68,0,103,.LN17-MASLOAD		# line 103, column 1
.LBB2:
.LN18:
	.stabn  68,0,104,.LN18-MASLOAD		# line 104, column 0
.LBE2:
	leave
	ret
	.Lab2 = 4
	.stabn 192,0,0,.LBB2-MASLOAD
	.stabn 224,0,0,.LBE2-MASLOAD
