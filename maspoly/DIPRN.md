(* ----------------------------------------------------------------------------
 * $Id: DIPRN.md,v 1.2 1992/02/12 17:33:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRN.md,v $
 * Revision 1.2  1992/02/12  17:33:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:42  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPRN;

(* DIP Rational Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPRN.md,v 1.2 1992/02/12 17:33:51 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRFIP(A: LIST): LIST; 
(*Distributive rational polynomial from integral polynomial.
A is a distributive integral polynomial, B is the monic associate
rational polynomial of A. *)


PROCEDURE DIRLRD(V: LIST): LIST; 
(*Distributive rational polynomial list read. V is a
variable list. A list of distributive rational polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding A are skipped. *)


PROCEDURE DIRLWR(A,V,S: LIST); 
(*Distributive rational polynomial list write. V is a
variable list. A list of distributive rational polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)


PROCEDURE DIRPAB(A: LIST): LIST; 
(*Distributive rational polynomial absolute value. A is a
distributive rational polynomial. B is the absolute value of A.*)


PROCEDURE DIRPDF(A,B: LIST): LIST; 
(*Distributive rational polynomial difference. A and B are
distributive rational polynomials. C=A-B.*)


PROCEDURE DIRPDM(A: LIST): LIST; 
(*Distributive rational polynomial derivation main variable.
A is a distributive polynomial. B is the derivation of A
with respect to its main variable.*)


PROCEDURE DIRPDR(A,IL: LIST): LIST; 
(*Distributive rational polynomial derivation. A is a distributive
polynomial. B is the derivation of A with respect to its i-th
variable, 0 le i le DIPNOV(A).*)


PROCEDURE DIRPEM(A,AL: LIST): LIST; 
(*Distributive rational polynomial evaluation of main variable.
A is a distributive rational polynomial. a is a rational number.
B(x1, ...,x(r-1))=A(x1, ...,x(r-1),a). *)


PROCEDURE DIRPEV(A,IL,AL: LIST): LIST; 
(*Distributive rational polynomial evaluation of the i-th variable.
A is a distributive rational polynomial, 1 le i le DIPNOV(A),
a is a rational number. B(x1, ...,x(i-1),x(i+1), ...,xr)=
A(x1, ...,x(i-1),a,x(i+1), ...,xr). *)


PROCEDURE DIRPEX(A,NL: LIST): LIST; 
(*Distributive rational polynomial exponentiation. A is a
distributive rational polynomial, n is a non-negative beta-
integer. B=A**n. 0**0 is by definition a polynomial in
zero variables. *)


PROCEDURE DIRPHD(A,IL,NL: LIST): LIST; 
(*Distributive rational polynomial higher derivation. A is a
distributive rational polynomial. B is the n-th derivation
of A with respect to its i-th variable, 0 le i le DIPNOV(A). *)


PROCEDURE DIRPLS(A: LIST): LIST; 
(*Distributive rational polynomial list sum. A is a circular
list of distributive rational polynomials. B is the sum of all
polynomials in A. *)


PROCEDURE DIRPMC(A: LIST): LIST; 
(*Distributive rational polynomial monic. A and C are
distributive rational polynomials, C=A/LBC(A) if A ne 0
C=0 if A eq 0. *)


PROCEDURE DIRPMN(A: LIST): LIST; 
(*Distributive rational polynomial maximum norm. A is a
distributive rational polynomial. b is the maximum norm of A.*)


PROCEDURE DIRPNG(A: LIST): LIST; 
(*Distributive rational polynomial negative. B= -A.*)


PROCEDURE DIRPON(A: LIST): LIST; 
(*Distributive rational polynomial one. A is a distributive
rational polynomial. If A=1 then t=1, otherwise t=0.*)


PROCEDURE DIRPPR(A,B: LIST): LIST; 
(*Distributive rational polynomial product. A and B are
distributive rational polynomials. C=A*B.*)


PROCEDURE DIRPQ(A,B: LIST): LIST; 
(*Distributive rational polynomial quotient. A and B are
distributive rational polynomials. B is a non zero divisor
of A. C=B/A.*)


PROCEDURE DIRPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive rational polynomial quotient and remainder.
A and B are distributive rational polynomials with B ne 0.
Q and R are unique distributive rational polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with deg(R) lt deg(B). *)


PROCEDURE DIRPRA(RL,KL,LL,EL: LIST): LIST; 
(*Distributive rational polynomial random.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive rational polynomial in r variables
max norm of A lt 2**k and maximal l base coefficients. *)


PROCEDURE DIRPRD(V: LIST): LIST; 
(*Distributive rational polynomial read. V is a variable list.
A distributive rational polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. modified version, orginal
version by G. E. Collins. *)


PROCEDURE DIRPRP(A,BL: LIST): LIST; 
(*Distributive rational polynomial rational number product.
Is a distributive rational polynomial, b is a rational number.
C=A*b.*)


PROCEDURE DIRPRQ(A,BL: LIST): LIST; 
(*Distributive rational polynomial rational number quotient. A
is a distributive rational polynomial, b is a nonzero rational
number. C=A/b.*)


PROCEDURE DIRPSG(A: LIST): LIST; 
(*Distributive rational polynomial sign. A is a distributive
rational polynomial. s is the sign of the leading base
coefficient of A.*)


PROCEDURE DIRPSM(A,B: LIST): LIST; 
(*Distributive rational polynomial sum. A and B are
distributive rational polynomials. C=A+B. *)


PROCEDURE DIRPSN(A: LIST): LIST; 
(*Distributive rational polynomial sum norm. A is a distributive
rational polynomial. b is the sum norm of A.*)


PROCEDURE DIRPSO(A: LIST): LIST; 
(*Distributive rational polynomial sort. A is a
list of rational coefficients and exponent vectors,
A is sorted into inverse lexicographical order,
two terms with equal exponent vectors are added. *)


PROCEDURE DIRPSU(A,IL,B: LIST): LIST; 
(*Distributive rational polynomial substitution. A and B are
distributive rational polynomials, 1 le i le r=DIPNOV(A).
E(x1, ...,x(i-1),x(i+1), ...,xr)=A(x1, ...,x(i-1),
B(x1, ...,x(i-1),x(i+1), ...,xr),x(i+1), ...,xr). *)


PROCEDURE DIRPSV(A,B: LIST): LIST; 
(*Distributive rational polynomial substitution for main variable.
A and B are distributive rational polynomials. t=DIPNOV(A)-1.
C(x1, ...,xt)=A(x1, ...,xt,B(x1, ...,xt)). *)


PROCEDURE DIRPTM(A,HL: LIST): LIST; 
(*Distributive rational polynomial translation main variable.
A is a distributive rational polynomial, h is a rational number.
B(x1, ...xr)=A(x1, ...,x(r-1),x(r)+h). r=DIPNOV(A). *)


PROCEDURE DIRPTR(A,HL,IL: LIST): LIST; 
(*Distributive rational polynomial translation. A is a
distributive rational polynomial, h is a rational number,
the i-th variable is translated. 1 le i le r=DIPNOV(A).
B(x1, ...,xr)=A(x1, ...,x(i)+h, ...,xr).*)


PROCEDURE DIRPWR(A,V,S: LIST); 
(*Distributive rational polynomial write. A is a distributive
rational poynomial in r variables, r ge 0. V is a variable list
for A. If S ge 0 then the coefficients are written by RNDWR
else by RNWRIT. A is written in the output stream.
Modified version, original version by G. E. Collins. *)


PROCEDURE DIRPWV(A: LIST); 
(*Distributive rational polynomial write with standard variable
list. A is a distributive rational poynomial. The standard
variable list is used. A is written in the output stream.*)


PROCEDURE DIRRAS(RL,KL,LL,EL,QL: LIST): LIST; 
(*Distributive rational polynomial, random sparse exponent vector.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive rational polynomial in r variables
max norm of A lt 2**k and maximal l base coefficients. *)


END DIPRN.


(* -EOF- *)
