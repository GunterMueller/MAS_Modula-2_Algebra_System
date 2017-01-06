(* ----------------------------------------------------------------------------
 * $Id: DIPRNPOL.md,v 1.3 1992/06/12 13:36:28 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNPOL.md,v $
 * Revision 1.3  1992/06/12  13:36:28  kredel
 * Added GCD and LCM for rational univariate polynomials and some others.
 *
 * Revision 1.2  1992/02/12  17:33:53  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:45  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPRNPOL;


(* DIP Rational Number Polynomial Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPRNPOL.md,v 1.3 1992/06/12 13:36:28 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RPABS(RL,A: LIST): LIST;
(*Rational polynomial absolute value.  A is a rational polynomial in
r variables.  B is the absolute value of A.*)


PROCEDURE RPCONST(RL,A: LIST): LIST; 
(*Rational polynomial constant.  A is a rational polynomial in r
variables.  If A is a non-zero rational number then t=1, 
otherwise t=0. *) 


PROCEDURE RPEXP(RL,A,NL: LIST): LIST;
(*Rational polynomial exponentiation.  A is a rational polynomial in
r variables, r ge 0.  n is a non-negative integer.  B=A**n.*)
 

PROCEDURE RPMON(RL,A: LIST): LIST;
(*Rational polynomial monic.  A is a rational polynomial in r variables.
If A is non-zero then AP is the polynomial similar to A with LBCF(AP)=1.  
If A=0 then AP=0.*)


PROCEDURE RPONE(RL,A: LIST): LIST; 
(*Rational polynomial one.  A is a rational polynomial in r
variables.  If A=1 then t=1, otherwise t=0. *) 


PROCEDURE RPSIGN(RL,A: LIST): LIST;
(*Rational polynomial sign.  A is a rational polynomial in r
variables.  s is the sign of A.*)


PROCEDURE RPLWRS(RL,A,V,S: LIST); 
(*Rational polynomial list write.  A is a list of rational
polynomial in r variables, r ge 0.  V is a variable list for
the polynomials in A. S is a decimal flag. A is written in the
output stream in external canonical form.*)


PROCEDURE RPWRTS(RL,A,V,S: LIST); 
(*Rational polynomial write.  A is a rational polynomial in r
variables, r ge 0.  V is a variable list for A. S is a decimal
flag. A is written in the output stream in external canonical form.*)


PROCEDURE RUPEGC(A,B: LIST;  VAR C,U,V: LIST); 
(*Rational univariate polynomial extended greatest common divisor.  
A and B are rational univariate polynomials. C=gcd(A,B).  
A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt
deg(A/C), else deg(V)=0.  Similarly, if deg(B/C) gt 0, then deg(U) lt
deg(B/C), else deg(U)=0.  If A=0, U=0.  If B=0, V=0.*)


PROCEDURE RUPGCD(A,B: LIST): LIST; 
(*Rational univariate polynomial greatest common divisor.  A and B are
rational univariate polynomials. C=gcd(A,B).*)


PROCEDURE RUPHEG(A,B: LIST;  VAR C,V: LIST); 
(*Rational univariate polynomial half-extended greatest common divisor.
A and B are rational univariate polynomials.  C=gcd(A,B).  
There exists a polynomial U such that A*U+B*V=C, and, if deg(A/C) gt 0, 
then deg(V) lt deg(A/C).  If deg(A/C)=0, deg(V) is also 0.  If B=0, V=0.*)


PROCEDURE RUPLCM(A,B: LIST): LIST; 
(*Rational univariate polynomial least common multiple. A and B are 
rational univariate polynomials. C=LCM(A,B), a nonnegative 
rational univariate polynomial.*)


END DIPRNPOL.


(* -EOF- *)
