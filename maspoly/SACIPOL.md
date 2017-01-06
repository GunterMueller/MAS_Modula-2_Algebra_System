(* ----------------------------------------------------------------------------
 * $Id: SACIPOL.md,v 1.2 1992/02/12 17:33:57 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACIPOL.md,v $
 * Revision 1.2  1992/02/12  17:33:57  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:50  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACIPOL;

(* SAC Integer Polynomial System Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACIPOL.md,v 1.2 1992/02/12 17:33:57 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPABS(RL,A: LIST): LIST;
(*Integral polynomial absolute value.  A is an integral polynomial in
r variables.  B is the absolute value of A.*)


PROCEDURE IPCRA(M,ML,MLP,RL,A,AL: LIST): LIST;
(*Integral polynomial chinese remainder algorithm.  M is a positive
integer.  m is a positive beta-integer.  gcd(M,m)=1.  mp is the
inverse of H sub m of M.  A is an integral polynomial in r variables
whose coefficients belong to Z prime sub M, r non-negative.  a is a
polynomial in r variables over Z sub m.  AS is the unique integral
polynomial in r variables with coefficients in Z prime sub MS, where
MS=M*m, which is congruent to A modulo M and to a modulo m.*)


PROCEDURE IPDER(RL,A,IL: LIST): LIST;
(*Integral polynomial derivative.  A is an integral polynomial in r
variables.  1 le i le r.  B is the derivative of A with respect to
its i-th variable.*)


PROCEDURE IPDIF(RL,A,B: LIST): LIST;
(*Integral polynomial difference.  A and B are integral polynomials in
r variables, r ge 0.  C=A-B.*)


PROCEDURE IPDMV(RL,A: LIST): LIST;
(*Integral polynomial derivative, main variable.  A is an integral
polynomial in r variables.  B is the derivative of A with respect to
its main variable.*)


PROCEDURE IPEMV(RL,A,AL: LIST): LIST;
(*Integral polynomial evaluation of main variable.  A is an integral
polynomial in r variables.  a is an integer.
B(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),a).*)


PROCEDURE IPEVAL(RL,A,IL,AL: LIST): LIST;
(*Integral polynomial evaluation.  A is an integral polynomial
in r variables.  1 le i le r.  a is an integer.  B(x(1), ...,
x(i-1),x(i+1), ...,x(r))=A(x(1), ...,x(i-1),a,x(i+1), ...,x(r)).*)


PROCEDURE IPEXP(RL,A,NL: LIST): LIST;
(*Integral polynomial exponentiation.  A is an integral polynomial in
r variables, r ge 0.  n is a non-negative integer.  B=A**n.*)


PROCEDURE IPFCB(V: LIST): LIST;
(*Integral polynomial factor coefficient bound.  V is the degree vector
of a non-zero integral polynomial A.  b is a non-negative integer such
that if b(1)* ...*b(k) divides A then the product of the infinity norms
of the b(i) is less than or equal to 2**b times the infinity norm of A.
Gelfonds bound is used.*)


PROCEDURE IPFRP(RL,A: LIST): LIST;
(*Integral polynomial from rational polynomial.  A is a rational
polynomial in r variables, r ge 0, each of whose base coefficients is
an integer.  B is a converted to integral polynomial representation.*)


PROCEDURE IPGSUB(RL,A,SL,L: LIST): LIST;
(*Integral polynomial general substitution.  A is an integral
polynomial in r variables, r ge 1.  L is a list (b(1), ...,b(r)) of
integral polynomials in s variables, s ge 1.  C(y(1), ...,y(s))=
A(b(1)(y(1), ...,y(s)), ...,b(r)(y(1), ...,y(s))).*)


PROCEDURE IPHDMV(RL,A,KL: LIST): LIST;
(*Integral polynomial higher derivative, main variable.  A is an
integral polynomial in r variables.  k is a non-negative
gamma-integer B is the k-th derivative of A with respect to its main
variable.*)


PROCEDURE IPIHOM(RL,D,A: LIST): LIST;
(*Integral polynomial mod ideal homomorphism.  D is a list (d sub 1, ...,
d sub r-1) of non-negative beta-integers, r ge 0.  A is an r-variate 
integral polynomial.  B=A mod (x sub 1 ** d sub 1, ...,x sub
r-1 ** d sub r-1).*)


PROCEDURE IPIP(RL,AL,B: LIST): LIST;
(*Integral polynomial integer product.  a is an integer.  B is an
integral polynomial in r variables.  C=a*B.*)


PROCEDURE IPIPR(RL,D,A,B: LIST): LIST;
(*Integral polynomial mod ideal product.  D is a list (d sub 1, ...,
d sub r-1) of non-negative beta-integers, r ge 1.  A and B belong to
Z(x sub 1, ...,x sub r-1,y)/(x sub 1 **d sub 1, ...,x sub r-1 ** d
sub r-1).  C=A*B.*)


PROCEDURE IPIQ(RL,A,BL: LIST): LIST;
(*Integral polynomial integer quotient.  A is an integral polynomial
in r variables.  b is a non-zero integer which divides A.  C=A/b.*)


PROCEDURE IPMAXN(RL,A: LIST): LIST;
(*Integral polynomial maximum norm.  A is an integral polynomial
in r variables.  b is the maximum norm of A.*)


PROCEDURE IPNEG(RL,A: LIST): LIST;
(*Integral polynomial negative.  A is an integral polynomial in r
variables, r ge 0.  B=-A.*)


PROCEDURE IPONE(RL,A: LIST): LIST;
(*Integral polynomial one.  A is an integral polynomial in r
variables.  If A=1 then t=1, otherwise t=0.*)


PROCEDURE IPPROD(RL,A,B: LIST): LIST;
(*Integral polynomial product.  A and B are integral polynomials in r
variables, r ge 0.  C=A*B.*)


PROCEDURE IPPSR(RL,A,B: LIST): LIST;
(*Integral polynomial pseudo-remainder.  A and B are integral
polynomials in r variables, B non-zero.  C is the pseudo-remainder
of A and B.*)


PROCEDURE IPQ(RL,A,B: LIST): LIST;
(*Integral polynomial quotient.  A and B are integral polynomials in
r variables, r ge 0.  B is a non-zero divisor of A.  C=A/B.*)


PROCEDURE IPQR(RL,A,B: LIST; VAR Q,R: LIST);
(*Integral polynomial quotient and remainder.  A and B are integral
polynomials in r variables with B non-zero.  Q and R are the unique
integral polynomials such that either B divides A, Q=A/B and R=0 or
else B does not divide A and A=BQ+R with deg(R) minimal.*)


PROCEDURE IPRAN(RL,KL,QL,N: LIST): LIST;
(*Integral polynomial, random.  k is a positive beta-digit.  q is a
rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list
(n sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random integral polynonial in r variables with deg sub i of a le n
sub i for 1 le i le r.  Max norm of A lt 2**k and q is the
probability that any particular term of a has a non-zero coefficient.*)


PROCEDURE IPREAD( VAR RL,A,V: LIST);
(*Integral polynomial read.  The integral polynomial A is read from the
input stream.  r, non-negative, is the number of variables of A and V
is the variable list of A.  Any number of preceding blanks are skipped.*)


PROCEDURE IPSIGN(RL,A: LIST): LIST;
(*Integral polynomial sign.  A is an integral polynomial in r
variables.  s is the sign of A.*)


PROCEDURE IPSMV(RL,A,B: LIST): LIST;
(*Integral polynomial substitution for main variable.  A is an
integral polynomial in r variables, x(1), ...,x(r).  B is an
integral polynomial in x(1), ...,x(r-1).  C(x(1), ...,x(r-1))=
A(x(1), ...,x(r-1),B(x(1), ...,x(r-1))).*)


PROCEDURE IPSUB(RL,A,IL,B: LIST): LIST;
(*Integral polynomial substitution.  A is an integral polynomial in
r variables, x(1), ...,x(r).  1 le i le r.  B is an integral
polynomial in x(1), ...,x(i-1).  C(x(1), ...,x(i-1),x(i+1), ...,
x(r))=A(x(1), ...,x(i-1),B(x(1), ...,x(i-1)),x(i+1), ..., x(r)).*)


PROCEDURE IPSUM(RL,A,B: LIST): LIST;
(*Integral polynomial sum.  A and B are integral polynomials in r
variables, r ge 0.  C=A+B.*)


PROCEDURE IPSUMN(RL,A: LIST): LIST;
(*Integral polynomial sum norm.  A is an integral polynomial in r
variables, r non-negative.  b is the sum norm of A.*)


PROCEDURE IPTPR(RL,D,A,B: LIST): LIST;
(*Integral polynomial truncated product.  D is a list (d sub 1, ...,d sub r)
of non-negative beta-integers, r ge 1.  A and B belong to
Z(x sub 1, ...,x sub r)/(x sub 1 **d sub 1, ...,x sub r ** d sub r).
C=A*B.*)


PROCEDURE IPTRAN(RL,A,T: LIST): LIST;
(*Integral polynomial translation.  A is an integral polynomial in r
variables, r ge 1.  T is a list (tr, ...,t1) of integers.
B(x1, ...,xr)=A(x1+t1, ...,xr+tr).*)


PROCEDURE IPTRMV(RL,A,HL: LIST): LIST;
(*Integral polynomial translation, main variable.  A is an integral
polynomial in r variables, r ge 1.  h is an integer.
B(x1, ...,xr)=A(x1, ...,x(r-1),xr+h).*)


PROCEDURE IPTRUN(RL,D,A: LIST): LIST;
(*Integral polynomial truncation.  D is a list (d sub 1, ...,d sub r)
of non-negative beta-integers, r ge 0.  A is an r-variate integral
polynomial.  B=A mod (x sub 1 ** d sub 1, ..., x sub r ** d sub r).*)


PROCEDURE IPWRIT(RL,A,V: LIST);
(*Integral polynomial write.  A is an integral polynomial in r
variables, r ge 0.  V is a variable list for A.  A is written
in the output stream in external canonical form.*)


PROCEDURE IUPBEI(A,CL,ML: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation, integer output.  
A is a univariate integral polynomial.  c is an integer.  m is a 
non-negative beta-integer.  b=2**(n*m)*A(c/2**m) where n=deg(A).
b is an integer.*)


PROCEDURE IUPBES(A,AL: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation of sign.
A is a univariate polynomial.  a is a binary rational number.  
s=sign(A(a)).*)


PROCEDURE IUPBHT(A,KL: LIST): LIST;
(*Integral univariate polynomial binary homothetic transformation.  A
is a non-zero univariate integral polynomial.  k is a gamma-integer.
B(x)=2**(-h)*A(2**k*x) where h is uniquely determined so that B is
an integral polynomial not divisible by 2.*)


PROCEDURE IUPBRE(A,AL: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation.  A is a
univariate integral polynomial.  a is a binary rational number.  
B=A(a), a binary rational number.*)


PROCEDURE IUPCHT(A: LIST): LIST;
(*Integral univariate polynomial circle to half-plane transformation.
A is a non-zero univariate integral polynomial.  Let n=deg(A).  Then
B(x)=(x+1)**n*A(1/(x+1)), a univariate integral polynomial.*)


PROCEDURE IUPNT(A: LIST): LIST;
(*Integral univariate polynomial negative transformation.  A is a 
univariate integral polynomial.  B(x)=A(-x).*)


PROCEDURE IUPTPR(NL,A,B: LIST): LIST;
(*Integral univariate polynomial truncated product.  n is a non-
negative integer.  A and B are integral univariate polynomials.  
C(x)=A(x)*B(x) (modulo x**n) and C=0 or deg(C) lt n.*)


PROCEDURE IUPTR(A,HL: LIST): LIST;
(*Integral univariate polynomial translation.  A is a univariate
integral polynomial.  h is an integer.  B(x)=A(x+h).*)


PROCEDURE IUPTR1(A: LIST): LIST;
(*Integral univariate polynomial translation by 1.  A is a univariate
integral polynomial.  B(x)=A(x+1).*)


END SACIPOL.


(* -EOF- *)
