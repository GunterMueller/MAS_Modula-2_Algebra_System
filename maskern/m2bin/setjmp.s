	.text
	.stabs "/home/gunter/GM_MATH/MAS_CAS/gm_mas-1.01/maskern/",100,0,0,.LBB0
	.stabs "setjmp.mod",100,0,0,.LBB0
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
	.globl	setjmp
	.globl	setjmp
	.globl	longjmp
	.stabs "setjmp:F16",36,0,0,setjmp
	.align 4
setjmp:
	pushl	%ebp
	movl	%esp,%ebp
	subl	$.Lab1, %esp
.LN1:
	.stabn  68,0,19,.LN1-setjmp		# line 19, column 1
.LBB1:
.LN2:
	.stabn  68,0,20,.LN2-setjmp		# line 20, column 0
.LBE1:
	leave
	ret
	.Lab1 = 4
	.stabs "jmp_buf:t17=ar4;0;255;7",128,0,0,0
	.stabn 192,0,0,.LBB1-setjmp
	.stabn 224,0,0,.LBE1-setjmp
