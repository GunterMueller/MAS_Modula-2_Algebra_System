(* ----------------------------------------------------------------------------
 * $Id: SACPGCD.md,v 1.2 1992/02/12 17:35:01 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPGCD.md,v $
 * Revision 1.2  1992/02/12  17:35:01  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:43  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACPGCD;

(* SAC Polynomial GCD and RES System Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACPGCD.md,v 1.2 1992/02/12 17:35:01 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPC(RL,A: LIST): LIST; 
(*Integral polynomial content.  A is an integral polynomial in r
variables.  C is the content of A.*)


PROCEDURE IPCPP(RL,A: LIST;  VAR C,AB: LIST); 
(*Integral polynomial content and primitive part.  A is an integral
polynomial in r variables.  C is the content of A and AB is the
primitive part of A.*)


PROCEDURE IPGCDC(RL,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Integral polynomial greatest common divisor and cofactors.  A and B
are integral polynomials in r variables, r ge 0.  C=GCD(A,B).
If C is non-zero then AB=A/C and BB=B/C.  Otherwise AB=0 and BB=0.*)


PROCEDURE IPIC(RL,A: LIST): LIST; 
(*Integral polynomial integer content.  A is an integral polynomial in
r variables.  c is the integer content of A.*)


PROCEDURE IPICPP(RL,A: LIST;  VAR AL,AB: LIST); 
(*Integral polynomial integer content and primitive part.  A is an
integral polynomial in r variables.  a is the integer content of A.
AB=A/a if A is non-zero and AB=0 if A=0.*)


PROCEDURE IPICS(RL,A,CL: LIST): LIST; 
(*Integral polynomial integer content subroutine.  A is a non-zero
integral polynomial in r variables.  c is an integer.  d is the
greatest common divisor of c and the integer content of A.*)


PROCEDURE IPIPP(RL,A: LIST): LIST; 
(*Integral polynomial integer primitive part.  A is an integral
polynomial in r variables.  If A ne 0 then AB=A/a where a is the
integer content of A.  If A=0 then AB=0.*)


PROCEDURE IPPGSD(RL,A: LIST): LIST; 
(*Integral polynomial primitive greatest squarefree divisor.  A is an
integral polynomial in r variables.  If A=0 then B=0.  Otherwise B is
the greatest squarefree divisor of the primitive part of A.*)


PROCEDURE IPPP(RL,A: LIST): LIST; 
(*Integral polynomial primitive part.  A is an integral polynomial in
r variables.  AB is the primitive part of A.*)


PROCEDURE IPRES(RL,A,B: LIST): LIST; 
(*Integral polynomial resultant.  A and B are integral polynomials in
r variables, r ge 1, of positive degrees.  C is the resultant of A and
B with respect to the main variable, an integral polynomial in r-1
variables.*)


PROCEDURE IPRPRS(RL,A,B: LIST): LIST; 
(*Integral polynomial reduced polynomial remainder sequence.  A and B
are non-zero integral polynomials in r variables with deg(A) ge deg(B).
S is the reduced polynomial remainder sequence of A and B.*)


PROCEDURE IPSCPP(RL,A: LIST;  VAR SL,C,AB: LIST); 
(*Integral polynomial sign, content, and primitive part.  A is
an integral polynomial in R ge 1 variables.  s is
the sign of A, C is the content of A, and AB is the primitive
part of A.*)


PROCEDURE IPSF(RL,A: LIST): LIST; 
(*Integral polynomial squarefree factorization.  A is a positive pri-
mitive integral polynomial in r variables of positive degree.  L is
the list ((e sub 1,A sub 1), ...,(e sub l,A sub l)) where A equal to
the product of (A sub i)**(e sub i) for i = 1, ...,k is the
squarefree factorization of A in which 1 le e sub 1 lt e sub 2 lt  ...
lt e sub k and each A sub i is a positive squarefree polynomial of
positive degree.*)


PROCEDURE IPSPRS(RL,A,B: LIST): LIST; 
(*Integral polynomial subresultant polynomial remainder sequence.
A and B are non-zero integral polynomials in r variables with
deg(A) ge deg(B).  S is the subresultant p.r.s. of the first kind
of A and B.*)

 
PROCEDURE IPSRP(RL,A: LIST;  VAR AL,AB: LIST); 
(*Integral polynomial similiar to rational polynomial.  A is a
rational polynomial in r variables, r ge 0.  a is a
rational number, and AB is an integral polynomial such that A=a*AB. If
A eq 0 then a=AB=0. Otherwise AB is integer primitive and positive.*)


PROCEDURE MPGCDC(RL,PL,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Modular polynomial greatest common divisor and cofactors.  p is a
prime beta-integer.  A and B are polynomials in r variables over
Z sub p.  C=gcd(A,B).  If C is non-zero then AB=A/C and BB=B/C.
Otherwise AB=0 and BB=0.*)


PROCEDURE MPRES(RL,PL,A,B: LIST): LIST; 
(*Modular polynomial resultant.  p is a prime beta-digit.  A and B are
polynomials over Z sub p in r variables, r ge 1, of positive degree.
C is the resultant of A and B, a polynomial over Z sub p in r-1
variables.*)


PROCEDURE MPSPRS(RL,PL,A,B: LIST): LIST; 
(*Modular polynomial subresultant polynomial remainder sequence.
A and B are non-zero polynomials in r variables over Z sub p,
p a prime beta-integer, with deg(A) ge deg(B).
S is the subresultant p.r.s. of the first kind of A and B.*)


PROCEDURE MPUC(RL,PL,A: LIST): LIST; 
(*Modular polynomial univariate content.  A is a polynomial in r
variables, r ge 2, over Z sub p, p a prime beta-integer.  c is the
univariate content of A.*)


PROCEDURE MPUCPP(RL,PL,A: LIST;  VAR AL,AB: LIST); 
(*Modular polynomial univariate content and primitive part.  A is a
polynomial in r variables, r ge 2, over Z sub p, p a prime
beta-integer.  a is the univariate content of A.  AB=A/a if A is
non-zero and AB=0 if A=0.*)


PROCEDURE MPUCS(RL,PL,A,CL: LIST): LIST; 
(*Modular polynomial univariate content subroutine.  A is a non-zero
polynomial in r variables, r ge 2, over Z sub p, p a prime
beta-integer.  c is a univariate polynomial over Z sub p.  d is the
greatest common divisor of c and the univariate content of A.*)


PROCEDURE MPUPP(RL,PL,A: LIST): LIST; 
(*Modular polynomial univariate primitive part.  A is a polynomial in
r variables, r ge 2, over Z sub p, p a prime beta-integer.  If A is
non-zero then AB=A/a where a is the univariate content of A.  If A=0
then AB=0.*)


PROCEDURE MUPEGC(PL,A,B: LIST;  VAR C,U,V: LIST); 
(*Modular univariate polynomial extended greatest common divisor.  p
is a prime beta-integer.  A and B are univariate polynomials over Z sub
p. C=gcd(A,B).  A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt
deg(A/C), else deg(V)=0.  Similarly, if deg(B/C) gt 0, then deg(U) lt
deg(B/C), else deg(U)=0.  If A=0, U=0.  If B=0, V=0.*)


PROCEDURE MUPGCD(PL,A,B: LIST): LIST; 
(*Modular univariate polynomial greatest common divisor.  A and B are
univariate polynomials over Z sub p, p a prime beta-integer.
C=gcd(A,B).*)


PROCEDURE MUPHEG(PL,A,B: LIST;  VAR C,V: LIST); 
(*Modular univariate polynomial half-extended greatest common divisor.
p is a prime beta-integer.  A and B are univariate polynomials over
Z sub p.  C=gcd(A,B).  There exists a polynomial U such that
A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt deg(A/C).  If
deg(A/C)=0, deg(V) is also 0.  If B=0, V=0.*)


PROCEDURE MUPRES(PL,A,B: LIST): LIST; 
(*Modular univariate polynomial resultant.  p is a prime beta-digit.
A and B are univariate polynomials over Z sub p of positive degrees.
C is the resultant of A and B, an element of Z sub p.*)


PROCEDURE MUPSFF(PL,A: LIST): LIST; 
(*Modular univariate polynomial squarefree factorization.  p is a
prime beta-integer.  A is a monic univariate polynomial over Z sub p
of positive degree.  L is a list ((i(1),A(1)), ...,(i(r),A(r))) with
i(1) lt i(2) lt  ... lt i(r), A(j) a monic squarefree factor of a
of positive degree for 1 le j le r and A the product of A(j)**i(j)
for j=1, ...,r.*)


PROCEDURE RPBLGS(RL,A: LIST;  VAR AL,BL,SL: LIST); 
(*Rational polynomial base coefficients least common multiple, greatest common divisor, and sign.  
A is a rational polynomial in r variables, r ge 0.  If A=0 then 
a=b=s=0.  Otherwise, a is the lcm of the denominators of the 
base coefficients of A, b is the gcd of the numerators of 
the base coefficients of A, and s is the sign of the leading base 
coefficient of A.*)


END SACPGCD.

(* -EOF- *)
