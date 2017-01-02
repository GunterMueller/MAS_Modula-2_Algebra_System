	.comm Portab_s, 12
	.text
	.stabs "/home/gunter/GM_MATH/MAS_Modula-2_Algebra_System/maskern/",100,0,0,.LBB0
	.stabs "Portab.mod",100,0,0,.LBB0
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
	.globl	Portab
	.stabs "Portab:F16",36,0,0,Portab
	.align 4
Portab:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,29,.LN1-Portab		# line 29, column 1
.LBB1:
.LN2:
	.stabn  68,0,31,.LN2-Portab		# line 31, column 10
	movb	$27,Portab_s 
.LN3:
	.stabn  68,0,32,.LN3-Portab		# line 32, column 10
	movb	$13,Portab_s + 1 
.LN4:
	.stabn  68,0,33,.LN4-Portab		# line 33, column 10
	movb	$12,Portab_s + 2 
.LN5:
	.stabn  68,0,34,.LN5-Portab		# line 34, column 10
	movb	$4,Portab_s + 3 
.LN6:
	.stabn  68,0,35,.LN6-Portab		# line 35, column 10
	movb	$11,Portab_s + 4 
.LN7:
	.stabn  68,0,36,.LN7-Portab		# line 36, column 10
	movb	$127,Portab_s + 5 
.LN8:
	.stabn  68,0,37,.LN8-Portab		# line 37, column 10
	movb	$8,Portab_s + 6 
.LN9:
	.stabn  68,0,38,.LN9-Portab		# line 38, column 10
	movb	$0,Portab_s + 7 
.LN10:
	.stabn  68,0,39,.LN10-Portab		# line 39, column 10
	movb	$32,Portab_s + 8 
.LN11:
	.stabn  68,0,40,.LN11-Portab		# line 40, column 0
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabs "STRING:t17=ar4;0;80;2",128,0,0,0
	.stabn 192,0,0,.LBB1-Portab
	.stabn 224,0,0,.LBE1-Portab
	.stabs "Portab_s:Gs9esc:2,0,8;cr:2,8,8;ff:2,16,8;ef:2,24,8;lf:2,32,8;del:2,40,8;bs:2,48,8;nul:2,56,8;sp:2,64,8;;",32,0,0,0
