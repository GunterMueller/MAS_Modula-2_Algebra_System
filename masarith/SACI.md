(* ----------------------------------------------------------------------------
 * $Id: SACI.md,v 1.2 1992/02/12 13:19:11 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACI.md,v $
 * Revision 1.2  1992/02/12  13:19:11  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:14  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACI;

(* SAC Integer Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACI.md,v 1.2 1992/02/12 13:19:11 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


    
PROCEDURE AADV(L: LIST; VAR AL,LP: LIST);
(*Arithmetic advance.  L is a list.  If L ne () then a=FIRST(L) and
LP=RED(L).  Otherwise a=0 and LP=().*)


PROCEDURE IABSF(A: LIST): LIST;
(*Integer absolute value function.  A is an integer.  B=ABS(A).*)


PROCEDURE ICOMP(A,B: LIST): LIST;
(*Integer comparison.  A and B are integers.  s=SIGN(A-B).*)


PROCEDURE IDEGCD(AL,BL: LIST; VAR CL,UL1,VL1,UL2,VL2: LIST);
(*Integer doubly extended greatest common divisor algorithm.  a and b
are integers.  c=GCD(a,b).  a*u1+b*v1=c and a*u2+b*v2=0.
If a ne 0 and b ne 0 then ABS(u1) le ABS(b)/(2*c), ABS(v1) le
ABS(a)/(2*c), u2=-b/c and v2=a/c.  Otherwise u1=v2=SIGN(a),
v1=SIGN(b) and u2=-SIGN(b).*)


PROCEDURE IDIF(A,B: LIST): LIST;
(*Integer difference.  A and B are integers.  C=A-B.*)


PROCEDURE IDIPR2(A,B,AL,BL: LIST): LIST;
(*Integer digit inner product, length 2.  A and B are integers.
a and b are beta-integers.  C=A*a+B*b.*)


PROCEDURE IDPR(A,BL: LIST): LIST;
(*Integer-digit product.  A is an integer.  b is a beta-digit.
C=A*b.*)


PROCEDURE IDP2(A,KL: LIST): LIST;
(*Integer division by power of 2.  A is an integer.  k is a
non-negative beta-digit.  B is the integral part of A/2**k.*)


PROCEDURE IDQ(A,BL: LIST): LIST;
(*Integer-digit quotient.  A is an integer.  b is a non-zero
beta-digit.  C=INTEGER(A/b).*)


PROCEDURE IDQR(A,BL: LIST; VAR Q,RL: LIST);
(*Integer-digit quotient and remainder.  A is an integer.  b is a
non-zero beta-digit.  Q is the integral part of A/b and r=A-b*Q.*)


PROCEDURE IDREM(A,BL: LIST): LIST;
(*Integer-digit remainder.  A is an integer.  b is a non-zero
beta-digit.  r=A-b*INTEGER(A/b).*)


PROCEDURE IEGCD(AL,BL: LIST; VAR CL,UL1,VL1: LIST);
(*Integer extended greatest common divisor algorithm.  a and b are
integers.  c=GCD(a,b).  a*u1+b*v1=c.  If a ne 0 and b ne 0
then ABS(u1) le ABS(b)/(2*c) and ABS(v1) le ABS(a)/(2*c).
Otherwise u1=SIGN(a) and v1=SIGN(b).*)


PROCEDURE IEVEN(A: LIST): BOOLEAN;
(*Integer even.  A is an integer.  If A is even then true is returned 
and otherwise false. *)


PROCEDURE IEXP(A,NL: LIST): LIST;
(*Integer exponentiation.  A is an integer.  n is a non-negative
beta-integer.  B=A**n.*)


PROCEDURE IFCL2(AL: LIST; VAR ML,NL: LIST);
(*Integer, floor and ceiling, logarithm, base 2.  a is a non-zero
integer.  m and n, gamma-integers, are the floor and ceiling of
LOG2(ABS(a)) respectively.*)


PROCEDURE IGCD(A,B: LIST): LIST;
(*Integer greatest common divisor.  A and B are integers.  C=GCD(A,B).*)


PROCEDURE IGCDCF(A,B: LIST; VAR C,AB,BB: LIST);
(*Integer greatest common divisor and cofactors.  A and B are integers.
C eq GCD(A,B).  If C eq 0 then AB eq BB eq 0 and otherwise
AB eq A/C,BB eq B/C.*)


PROCEDURE IHEGCD(A,B: LIST; VAR C,V: LIST);
(*Integer half-extended greatest common divisor.  A and B are integers.
C=GCD(A,B).  If A ne 0, B*V=C(mod A), with ABS(V) le ABS(A)/2C.  If
A=0,V=SIGN(B).*)


PROCEDURE ILCM(A,B: LIST): LIST;
(*Integer least common multiple.  A and B are integers.
C=LCM(A,B), a nonnegative integer.*)


PROCEDURE ILCOMB(A,B,UL,VL: LIST): LIST;
(*Integer linear combination.  A and B are non-negative integers.
u and v are beta-integers such that A*u+B*v ge 0.  C=A*u+B*v.*)


PROCEDURE ILOG2(A: LIST): LIST;
(*Integer logarithm, base 2.  A is an integer.  If A=0 then n=0.
Otherwise n=FLOOR(LOG2(ABS(A)))+1, a beta-integer.*)


PROCEDURE ILWRIT(L: LIST);
(*Integer list write.  L is a list of integers.  The list L is written
in the output stream.*)


PROCEDURE IMAX(AL,BL: LIST): LIST;
(*Integer maximum.  a and b are integers.  c is the maximum of a
and b.*)


PROCEDURE IMIN(AL,BL: LIST): LIST;
(*Integer minimum.  a and b are integers.  c is the minimum of a
and b.*)


PROCEDURE IMP2(A,HL: LIST): LIST;
(*Integer multiplication by power of 2.  A is an integer.  h is a
non-negative beta-integer.  B=A*(2**h).*)


PROCEDURE INEG(A: LIST): LIST;
(*Integer negation.  A is an integer.  B=-A.*)


PROCEDURE IODD(A: LIST): BOOLEAN;
(*Integer odd.  A is an integer.  If a is odd then true is returned
and otherwise false. *)


PROCEDURE IORD2(AL: LIST): LIST;
(*Integer, order of 2.  a is a non-zero integer.  n is the largest
integer such that 2**n divides a.*)


PROCEDURE IPOWER(A,L: LIST; VAR B,NL: LIST);
(*Integer power.  A, greater than or equal to 3, is an odd positive
integer.  L is a list (p(1),p(2), ...,p(k)) of the first k prime
numbers, with p(k) greater than or equal to the base 3 logarithm of A.
If A=B**m for some m greater than or equal to 2 then n is the least
such m and B=A**(1/n).  Otherwise B=0 and n=0.*)


PROCEDURE IPROD(A,B: LIST): LIST;
(*Integer product.  A and B are integers.  C=A*B.*)


PROCEDURE IPRODK(A,B: LIST): LIST;
(*Integer product, Karatsuba algorithm.  A and B are integers.  C=A*B.*)


PROCEDURE IQ(A,B: LIST): LIST;
(*Integer quotient.  A and B are integers, B ne 0.  C is the integral
part of A/B.*)


PROCEDURE IQR(A,B: LIST; VAR Q,R: LIST);
(*Integer quotient and remainder.  A and B are integers, B ne 0.  Q is
the quotient, integral part of A/B, and R is the remainder A-B*Q.*)


PROCEDURE IRAND(NL: LIST): LIST;
(*Integer, random.  n is a positive beta-integer.  A is an integer
with random sign and random absolute value less than 2**n.*)


PROCEDURE IREAD(): LIST;
(*Integer read.  The integer A is read from the input stream.  Any
preceding blanks are skipped.*)


PROCEDURE IREM(A,B: LIST): LIST;
(*Integer remainder.  A and B are integers, B non-zero.  C is the
remainder of A and B.*)


PROCEDURE IROOT(A,NL: LIST; VAR B,TL: LIST);
(*Integer root.  A is a positive integer.  n, greater than or equal
to 2, is a beta-integer.  B=FLOOR(A**(1/n)) and t=SIGN(A-B**n).*)


PROCEDURE ISEG(A,NL: LIST; VAR A1,A0: LIST);
(*Integer segmentation.  A is an integer.  n is a positive beta-
integer.  A1 is the integral part of A/beta**n.  A0=A-A1*beta**n.*)


PROCEDURE ISIGNF(A: LIST): LIST;
(*Integer sign function.  A is an integer.  s=SIGN(A).*)


PROCEDURE ISQRT(A: LIST; VAR B,TL: LIST);
(*Integer square root.  A is a non-negative integer.  B is the floor
function of the square root of A and t is the sign of A-B*B.*)


PROCEDURE ISSUM(NL,L: LIST): LIST;
(*Integer shifted sum.  n is a positive integer.  L is a list
(c(0),c(1), ...,c(k)), k non-negative, of integers c(i) with
ABS(c(i)) less than beta**(2*n+1).  Either each c(i) is
non-negative or each c(i) is non-positive.  C is the sum on i,
from 0 to k, of c(i)*(beta**(i*n)).*)


PROCEDURE ISUM(A,B: LIST): LIST;
(*Integer sum.  A and B are integers.  C=A+B.*)


PROCEDURE ITRUNC(A,NL: LIST): LIST;
(*Integer truncation.  A is an integer.  n is a beta-integer.
B=INTEGER(A/2**n).*)


PROCEDURE IWRITE(A: LIST);
(*Integer write.  The input integer A is converted to decimal and
written in the output stream.*)


END SACI.


(* -EOF- *)
