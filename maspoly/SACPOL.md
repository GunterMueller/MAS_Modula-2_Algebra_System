(* ----------------------------------------------------------------------------
 * $Id: SACPOL.md,v 1.2 1992/02/12 17:34:02 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPOL.md,v $
 * Revision 1.2  1992/02/12  17:34:02  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:54  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACPOL;

(* SAC Polynomial System Definition Module. *)



FROM MASSTOR IMPORT LIST;


VAR PRIME: LIST;

CONST rcsid = "$Id: SACPOL.md,v 1.2 1992/02/12 17:34:02 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE PBIN(AL1,EL1,AL2,EL2: LIST): LIST;
(*Polynomial binomial.  a1 and a2 are elements of a coefficient ring
R.  e1 and e2 are non-negative beta-integers e1 gt e2.  A is the
polynomial A(x)=a1*x**e1+a2*x**e2, a univariate polynomial
over R.*)


PROCEDURE PCL(A: LIST): LIST;
(*Polynomial coefficient list.  A is a non-zero polynomial.  L is the
list (a(n),a(n-1), ...,a(0)) where n=DEG(A) and A(x)=a(n)*x**n+
a(n-1)*x**(n-1)+ ...+a(0).*)


PROCEDURE PDBORD(A: LIST): LIST;
(*Polynomial divided by order.  A is a non-zero polynomial.  B(x)=
A(x)/x**k where k is the order of A.*)


PROCEDURE PDEG(A: LIST): LIST;
(*Polynomial degree.  A is a polynomial.  n is the degree of A.*)


PROCEDURE PDEGSV(RL,A,IL: LIST): LIST;
(*Polynomial degree, specified variable.  A is a polynomial in r
variables, r ge 1.  1 le i le r.  n is the degree of A in the i-th
variable.*)


PROCEDURE PDEGV(RL,A: LIST): LIST;
(*Polynomial degree vector.  A is a polynomial A(x(1), ...,x(r)) in
r variables.  V is the list (v(r), ...,v(1)) where v(i) is the
degree of a in x(i).*)


PROCEDURE PDPV(RL,A,IL,NL: LIST): LIST;
(*Polynomial division by power of variable.  A is a polynomial in
r variables.  1 le i le r and n is a beta-integer such that
x sub i sup n divides A.  B eq A/x sub i sup n.*)


PROCEDURE PFDP(RL,A: LIST): LIST;
(*Polynomial from dense polynomial.  A is a dense polynomial in
r variables, r ge 0.  B is the result of converting A to recursive
polynomial representation.*)


PROCEDURE PINV(RL,A,KL: LIST): LIST;
(*Polynomial introduction of new variables.  A is a polynomial in r
variables, r ge 0.  k ge 0.  B(y(1), ...,y(k),x(1), ...,x(r))
=A(x(1), ...,x(r)).*)


PROCEDURE PLBCF(RL,A: LIST): LIST;
(*Polynomial leading base coefficient.  A is a polynomial in r
variables.  a is the leading base coefficient of A.*)


PROCEDURE PLDCF(A: LIST): LIST;
(*Polynomial leading coefficient.  A is a polynomial.  a is the
leading coefficient of A.*)


PROCEDURE PMDEG(A: LIST): LIST;
(*Polynomial modified degree.  A is a polynomial.  If A=0 then n=-1
and otherwise n=DEG(A).*)


PROCEDURE PMON(AL,EL: LIST): LIST;
(*Polynomial monomial.  a is an element of a coefficient ring R.
e is a non-negative beta-integer.  A is the polynomial
A(x)=a*x**e, a univariate polynomial over R.*)


PROCEDURE PMPMV(A,KL: LIST): LIST;
(*Polynomial multiplication by power of main variable.  A is a
polynomial in r variables, r ge 1.  k is a non-negative integer.
B(x sub 1 , ..., x sub r ) eq A(x sub 1 , ..., x sub r ) *
x sub r sup k .*)


PROCEDURE PORD(A: LIST): LIST;
(*Polynomial order.  A is a non-zero polynomial.  k is the order of A.
that is, if A(x)=a(n)*x**n+ ...+a(0), then k is the smallest
integer such that a(k) ne 0.*)


PROCEDURE PRED(A: LIST): LIST;
(*Polynomial reductum.  A is a polynomial.  B is the reductum of A.*)


PROCEDURE PRT(A: LIST): LIST;
(*Polynomial reciprocal transformation.  A is a non-zero polynomial.
let n=DEG(A).  Then B(x)=x**n*A(1/x), where x is the main
variable of A.*)


PROCEDURE PTBCF(RL,A: LIST): LIST;
(*Polynomial trailing base coefficient.  A is an r-variate polynomial,
r ge 0.  a=trailing base coefficient of A.*)


PROCEDURE PUFP(RL,A: LIST): LIST;
(*Polynomial, univariate, from polynomial.  A is an r-variate
polynomial, r ge 0.  B, a univariate polynomial, equals A(0, ...,0,x).*)


PROCEDURE VCOMP(U,V: LIST): LIST;
(*Vector comparison.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r))
are lists of beta-integers with common length r ge 1.  If U=V
then t=0.  If U is not equal to V then t=1 if u(i) le v(i) for
all i and t=2 if v(i) le u(i) for all i.  Otherwise t=3.*)


PROCEDURE VLREAD(): LIST;
(*Variable list read.  V, a list of variables, is read from the input
stream.  Any preceding blanks are skipped.*)


PROCEDURE VLSRCH(VL,V: LIST): LIST;
(*Variable list search.  v is a variable.  V is a list of variables
(v(1), ...,v(n)), n non-negative.  If v=v(j) for some j then
i=j.  Otherwise i=0.*)


PROCEDURE VLWRIT(V: LIST);
(*Variable list write.  V, a list of variables, is written in the
output stream.*)


PROCEDURE VMAX(U,V: LIST): LIST;
(*Vector maximum.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r)) are
lists of beta-integers with common length r ge 1.  W=(w(1), ...,
w(r)) where w(i)=MAX(u(i),v(i)).*)


PROCEDURE VMIN(U,V: LIST): LIST;
(*Vector maximum.  U=(u(1), ...,u(r)) and V=(v(1), ...,v(r)) are
lists of beta-integers with common length r ge 1.  W=(w(1), ...,
w(r)) where w(i)=MIN(u(i),v(i)).*)


PROCEDURE VREAD(): LIST;
(*Variable read.  The variable v is read from the input stream.  Any
number of preceding blanks are skipped.*)


END SACPOL.


(* -EOF- *)
