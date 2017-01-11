(* ----------------------------------------------------------------------------
 * $Id: DIPI.md,v 1.3 1993/03/23 12:58:55 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPI.md,v $
 * Revision 1.3  1993/03/23  12:58:55  kredel
 * Added DIILFRCD
 *
 * Revision 1.2  1992/02/12  17:33:48  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:38  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPI;

(* DIP Integral Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPI.md,v 1.3 1993/03/23 12:58:55 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIIFRP(A: LIST): LIST; 
(*Distributive integral polynomial from rational polynomial.
A is a distributive rational polynomial, B is the primitive
positive associate integral polynomial of A. *)


PROCEDURE DIILFR(A: LIST): LIST; 
(*Distributive integral polynomial list from rational polynomial list.
A is a list of distributive rational polynomial, B is a list of primitive
positive associate integral polynomials of the polynomials of A. *)


PROCEDURE DIILFRCD(A: LIST): LIST; 
(*DIP integral list from DIP rational list using common denominator.
A is a list of distributive rational polynomial, B is a list of 
associate integral polynomials of the polynomials of A. 
All polynomials in B are multiplied by a least common multiple 
of all denominators of all polynomials in A. *)


PROCEDURE DIILRD(V: LIST): LIST; 
(*Distributive integral polynomial list read. V is a
variable list. A list of distributive integral polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. any blanks preceding A are skipped. *)


PROCEDURE DIILWR(A,V: LIST); 
(*Distributive integral polynomial list write. V is a
variable list. A list of distributive integral polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)


PROCEDURE DIIPAB(A: LIST): LIST; 
(*Distributive integral polynomial absolute value. A is a
distributive integral polynomial. B is the absolute value of A.*)


PROCEDURE DIIPCP(A: LIST;  VAR CL,AP: LIST); 
(*Distributive integral polynomial content and primitive part.
A is an distributive integral polynomial, c is the integer
content and AP is the positive primitive part of A. *)


PROCEDURE DIIPDF(A,B: LIST): LIST; 
(*Distributive integral polynomial difference. A and B are
distributive integral polynomials. C=A-B.*)


PROCEDURE DIIPDM(A: LIST): LIST; 
(*Distributive integral polynomial derivation main variable.
A is a distributive polynomial. B is the derivation of A
with respect to its main variable.*)


PROCEDURE DIIPDR(A,IL: LIST): LIST; 
(*Distributive integral polynomial derivation. A is a distributive
polynomial. B is the derivation of A with respect to its i-th
variable, 0 le i le DIPNOV(A).*)


PROCEDURE DIIPEM(A,AL: LIST): LIST; 
(*Distributive integral polynomial evaluation of main variable.
A is a distributive integral polynomial. a is an integer.
B(x1, ...,x(r-1))=A(x1, ...,x(r-1),a). *)


PROCEDURE DIIPEV(A,IL,AL: LIST): LIST; 
(*Distributive integral polynomial evaluation of the i-th variable.
A is a distributive integral polynomial, 1 le i le DIPNOV(A),
a is an integer. B(x1, ...,x(i-1),x(i+1), ...,xr)=
A(x1, ...,x(i-1),a,x(i+1), ...,xr). *)


PROCEDURE DIIPEX(A,NL: LIST): LIST; 
(*Distributive integral polynomial exponentiation. A is a
distributive integral polynomial, n is a non-negative beta-
integer. B=A**n. 0**0 is by definition a polynomial in
zero variables. *)


PROCEDURE DIIPHD(A,IL,NL: LIST): LIST; 
(*Distributive integral polynomial higher derivation. A is a
distributive integral polynomial. B is the n-th derivation
of A with respect to its i-th variable, 0 le i le DIPNOV(A). *)


PROCEDURE DIIPIP(A,BL: LIST): LIST; 
(*Distributive integral polynomial integer product. A is a
distributive integral polynomial, b is an integer. C=A*b.*)


PROCEDURE DIIPIQ(A,BL: LIST): LIST; 
(*Distributive integral polynomial integer quotient. A is a
distributive integral polynomial, b is a nonzero integer,
and b divides any coefficient of A. C=A/b.*)


PROCEDURE DIIPLS(A: LIST): LIST; 
(*Distributive integral polynomial list sum. A is a circular
list of distributive integral polynomials. B is the sum of all
polynomials in A. *)


PROCEDURE DIIPMN(A: LIST): LIST; 
(*Distributive integral polynomial maximum norm. A is a
distributive integral polynomial. b is the maximum norm of A.*)


PROCEDURE DIIPNG(A: LIST): LIST; 
(*Distributive integral polynomial negative. B= -A.*)


PROCEDURE DIIPON(A: LIST): LIST; 
(*Distributive integral polynomial one. A is a distributive
integral polynomial. If A=1 then t=1, otherwise t=0.*)


PROCEDURE DIIPPR(A,B: LIST): LIST; 
(*Distributive integral polynomial product. A and B are
distributive integral polynomials. C=A*B.*)


PROCEDURE DIIPPS(A,B: LIST): LIST; 
(*Distributive integral polynomial pseudo-remainder. A and B are
distributive integral polynomials, B ne 0. C is the
pseudo-remainder of A and B. *)


PROCEDURE DIIPQ(A,B: LIST): LIST; 
(*Distributive integral polynomial quotient. A and B are
distributive integral polynomials. B is a non zero divisor
of A. C=B/A.*)


PROCEDURE DIIPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive integral polynomial quotient and remainder.
A and B are distributive integral polynomials with B ne 0.
Q and R are unique distributive integral polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with DEG(R) minimal.*)


PROCEDURE DIIPRA(RL,KL,LL,EL: LIST): LIST; 
(*Distributive integral polynomial random.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive integral polynomial in r variables
max norm of a lt 2**k and maximal l base coefficients. *)


PROCEDURE DIIPRD(V: LIST): LIST; 
(*Distributive integral polynomial read. V is a variable list.
A distributive integral polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. Modified version, orginal
version by G. E. Collins. *)


PROCEDURE DIIPSG(A: LIST): LIST; 
(*Distributive integral polynomial sign. A is a distributive
integral polynomial. s is the sign of the leading base
coefficient of A.*)


PROCEDURE DIIPSM(A,B: LIST): LIST; 
(*Distributive integral polynomial sum. A and B are
distributive integral polynomials. C=A+B. *)


PROCEDURE DIIPSN(A: LIST): LIST; 
(*Distributive integral polynomial sum norm. A is a distributive
integral polynomial. b is the sum norm of A.*)


PROCEDURE DIIPSO(A: LIST): LIST; 
(*Distributive integral polynomial sort. A is a
list of integer base coefficients and exponent vectors,
A is sorted with respect to the actual term order,
two terms with equal exponent vectors are added. *)


PROCEDURE DIIPSU(A,IL,B: LIST): LIST; 
(*Distributive integral polynomial substitution. A and B are
distributive integral polynomials, 1 le i le r=DIPNOV(A).
E(x1, ...,x(i-1),x(i+1), ...,xr)=A(x1, ...,x(i-1),
B(x1, ...,x(i-1),x(i+1), ...,xr),x(i+1), ...,xr). *)


PROCEDURE DIIPSV(A,B: LIST): LIST; 
(*Distributive integral polynomial substitution for main variable.
A and B are distributive integral polynomials. t=DIPNOV(A)-1.
C(x1, ...,xt)=A(x1, ...,xt,B(x1, ...,xt)). *)


PROCEDURE DIIPTM(A,HL: LIST): LIST; 
(*Distributive integral polynomial translation main variable.
A is a distributive integral polynomial, h is an integer.
B(x1, ...xr)=A(x1, ...,x(r-1),xr+h). r=DIPNOV(A). *)


PROCEDURE DIIPTR(A,HL,IL: LIST): LIST; 
(*Distributive integral polynomial translation. A is a
distributive integral polynomial, h is an integer,
the i-th variable is translated. 1 le i le r=DIPNOV(A).
B(x1, ...,xr)=A(x1, ...,xi+h, ...,xr).*)


PROCEDURE DIIPWR(A,V: LIST); 
(*Distributive integral polynomial write. A is a distributive
integral poynomial in r variables, r ge 0. V is a variable list
for A. A is written in the output stream. Modified version,
original version by G. E. Collins. *)


PROCEDURE DIIPWV(A: LIST); 
(*Distributive integral polynomial write with standard variable list.
A is a distributive integral poynomial. The standard
variable list is used. A is written in the output stream.*)


PROCEDURE DIIRAS(RL,KL,LL,EL,QL: LIST): LIST; 
(*Distributive integral polynomial random sparse exponent vector.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive integral polynomial in r variables
max norm of a lt 2**k and maximal l base coefficients. *)


END DIPI.


(* -EOF- *)
