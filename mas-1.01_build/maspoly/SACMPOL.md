(* ----------------------------------------------------------------------------
 * $Id: SACMPOL.md,v 1.2 1992/02/12 17:33:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACMPOL.md,v $
 * Revision 1.2  1992/02/12  17:33:59  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:52  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACMPOL;

(* SAC Modular Polynomial Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACMPOL.md,v 1.2 1992/02/12 17:33:59 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE MIPDIF(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial difference.  M is a positive integer.
A and B are polynomials in r variables over Z sub M, r ge 0.  C=A-B.*)


PROCEDURE MIPFSM(RL,M,A: LIST): LIST;
(*Modular integral polynomial from symmetric modular.  M is a positive
integer.  A is a polynomial in r variables over Z prime sub M, r ge 0.
B belongs to Z sub M (x, ...,x sub r) with B=A (modulo M).*)


PROCEDURE MIPHOM(RL,M,A: LIST): LIST;
(*Modular integral polynomial homomorphism.  A is an integral
polynomial in r variables, r ge 0.  M is a positive integer.
B=H sub M (A), a polynomial in r variables over Z sub M.*)


PROCEDURE MIPIPR(RL,M,D,A,B: LIST): LIST;
(*Modular integral polynomial mod ideal product.  D is a list (d sub
1, ...,d sub r-1) of non-negative beta-integers, r ge 1.  M is a
positive integer.  A and B belong to Z sub M (x sub 1, ...,x sub
r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1).  C=A*B.*)


PROCEDURE MIPNEG(RL,M,A: LIST): LIST;
(*Modular integral polynomial negation.  M is a positive integer.  A is
a polynomial in r variables over Z sub M, r ge 0.  B=-A.*)


PROCEDURE MIPPR(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial product.  M is a positive integer.  A and
B are polynomials in r variables over Z sub M, r ge 0.  C=A*B.*)


PROCEDURE MIPRAN(RL,M,QL,N: LIST): LIST;
(*Modular integral polynomial, random.  M is a positive integer.  q is
a rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list
(n sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random polynomial in r variables over Z sub M with deg sub i of A le
n sub i for 1 le i le r.  q is the probability that any particular
term of A has a non-zero coefficient.*)


PROCEDURE MIPSUM(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial sum.  M is a positive integer.  A and B
are polynomials in r variables over Z sub M, r ge 0.  C=A+B.*)


PROCEDURE MIUPQR(M,A,B: LIST;    VAR Q,R: LIST);
(*Modular integral univariate polynomial quotient and remainder.  M is
a positive integer.  A and B belong to Z sub M (x) with LDCF(B) a unit.
Q and R are the unique elements of Z sub M (x) such that A=B*Q+R with
either R=0 or DEG(R) lt DEG(B).*)


PROCEDURE MMPIQR(RL,M,D,A,B: LIST;    VAR Q,R: LIST);
(*Modular monic polynomial mod ideal quotient and remainder.  M is a
positive integer.  D is a list (d sub 1, ...,d sub r-1) of non-nega-
tive beta-integers, r ge 1.  A and B belong to Z sub M(x sub 1, ...,x
sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1), with B
monic.  A=B*Q+R, deg sub y of R lt deg sub y of B unless B divides A,
in which case R=0, with Q,R belonging to Z sub M (x sub 1, ...,x sub
r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1).*)


PROCEDURE MPDIF(RL,ML,A,B: LIST): LIST;
(*Modular polynomial difference.  A and B are polynomials in r
variables over Z sub m, m a beta-integer.  C=A-B.*)


PROCEDURE MPEMV(RL,ML,A,AL: LIST): LIST;
(*Modular polynomial evaluation of main variable.  A is a polynomial in
r variables over Z sub m, m a beta-integer.  a is an element of
Z sub m.  B(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),a).*)


PROCEDURE MPEVAL(RL,ML,A,IL,AL: LIST): LIST;
(*Modular polynomial evaluation.  A is a polynomial in r variables
over Z sub m, m a beta-integer.  1 le i le r.  a is an element of
Z sub m.  B(x(1), ...,x(i-1),x(i+1), ...,x(r))=
A(x(1), ...,x(i-1),a,x(i+1), ...,x(r)).*)


PROCEDURE MPEXP(RL,ML,A,NL: LIST): LIST;
(*Modular polynomial exponentiation.  A is a polynomial in r variables
over Z sub m, m a beta-integer.  n is a non-negative integer.
B=A**n.*)


PROCEDURE MPHOM(RL,ML,A: LIST): LIST;
(*Modular polynomial homomorphism.  A is an integral polynomial in r
variables, r ge 0.  m is a positive beta-integer.  B is the image of
A under the homomorphism H sub m, a polynomial in r variables over
Z sub m.*)


PROCEDURE MPINT(PL,B,BL,BLP,RL,A,A1: LIST): LIST;
(*Modular polynomial interpolation.  p is a prime beta-integer.  B is
a univariate polynomial over Z sub p.  b is an element of Z sub p
such that B(b) ne 0 and bp=B(b)**-1.  A is a polynomial over Z sub
p in r variables, r ge 1, with A=0 or the degree of A in x(1) less
than the degree of B.  A1 is a polynomial over Z sub p in r-1
variables.  AS(x(1), ...,x(r)) is the unique polynomial over Z sub
p such that AS(x(1), ...,x(r)) is congruent to A(x(1), ...,x(r))
modulo B(x(1)), AS(b,x(2), ...,x(r))=A1(x(2), ...,x(r)) and
the degree of AS in x(1) is less than or equal to the degree of B.*)


PROCEDURE MPMDP(RL,PL,AL,B: LIST): LIST;
(*Modular polynomial modular digit product.  a is an element of
Z sub p, p a prime beta-integer.  B is a polynomial in r variables
over Z sub p.  C=a*B.*)


PROCEDURE MPMON(RL,PL,A: LIST): LIST;
(*Modular polynomial monic.  A is a polynomial in r variables over
Z sub p, p a prime beta-integer.  If A is non-zero then AP is
the polynomial similar to A with LBCF(AP)=1.  If A=0 then AP=0.*)


PROCEDURE MPNEG(RL,ML,A: LIST): LIST;
(*Modular polynomial negative.  A is a polynomial in r variables over
Z sub m, m a beta-integer.  B=-A.*)


PROCEDURE MPPROD(RL,ML,A,B: LIST): LIST;
(*Modular polynomial product.  A and B are polynomials in r variables
over Z sub m, m a beta-integer, r ge 0.  C=A*B.*)


PROCEDURE MPPSR(RL,PL,A,B: LIST): LIST;
(*Modular polynomial pseudo-remainder.  A and B are polynomials
in r variables over Z sub p, p a prime beta-integer,
with B non-zero.  C is the pseudo-remainder of A and B.*)


PROCEDURE MPQ(RL,PL,A,B: LIST): LIST;
(*Modular polynomial quotient.  A and B are polynomials in r
variables over Z sub p, p a prime beta-integer, r ge 0.  B is a
non-zero divisor of A.  C=A/B.*)


PROCEDURE MPQR(RL,PL,A,B: LIST;    VAR Q,R: LIST);
(*Modular polynomial quotient and remainder.  A and B are polynomials
un r variables over Z sub p, p a prime beta-integer, with B non-zero.
Q and R are the unique polynomials such that either B divides A, Q=A/B
and R=0 or else B does not divide A and A=BQ+R with DEG(R) minimal.*)


PROCEDURE MPRAN(RL,ML,QL,N: LIST): LIST;
(*Modular polynomial, random.  m is a positive beta-integer.  q is a
rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list (n
sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random polynomial in r variables over Z sub m with deg sub i of A le
n sub i for 1 le i le r.  q is the probability that any particular
term of A has a non-zero coefficient.*)


PROCEDURE MPSUM(RL,ML,A,B: LIST): LIST;
(*Modular polynomial sum.  A and B are polynomials in r variables over
Z sub m, m a beta-integer.  C=A+B.*)


PROCEDURE MPUP(RL,ML,CL,A: LIST): LIST;
(*Modular polynomial univariate product.  A is a polynomial in r
variables, r ge 1, over Z sub m, m a positive beta-integer.  c is a
univariate polynomial over Z sub m.  B(x(1), ...,x(r)) =
c(x(1))*A(x(1), ...,x(r)).*)


PROCEDURE MPUQ(RL,PL,A,BL: LIST): LIST;
(*Modular polynomial univariate quotient.  A is a polynomial in r
variables, r ge 2, over Z sub p, p a prime beta-integer.  b is a
non-zero univariate polynomial over Z sub p which divides A.
C(x(1), ...,x(r))=A(x(1), ...,x(r))/b(x(1)).*)


PROCEDURE MUPDER(ML,A: LIST): LIST;
(*Modular univariate polynomial derivative.  m is a beta-integer.  A
is a univariate polynomial over Z sub m.  B is the derivative of A, a
univariate polynomial over Z sub m.*)


PROCEDURE MUPRAN(PL,NL: LIST): LIST;
(*Modular univariate polynomial, random.  A is a random univariate
polynomial of degree n over Z(p).*)


PROCEDURE SMFMIP(RL,M,A: LIST): LIST;
(*Symmetric modular from modular integral polynomial.  M is a positive
integer.  A is a polynomial in r variables over Z sub M, r ge 0.  B
belongs to Z prime sub M (x1, ...,x sub r) with B=A (modulo M).*)


PROCEDURE VMPIP(RL,ML,A,B: LIST): LIST;
(*Vector of modular polynomial inner product.  A and B are vectors of
modular polynomials in r variables over Z sub m, r non-negative, m
a beta-integer.  C is the inner product of A and B.*)


END SACMPOL.



(* -EOF- *)
