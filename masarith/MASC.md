(* ----------------------------------------------------------------------------
 * $Id: MASC.md,v 1.2 1992/09/28 18:34:51 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASC.md,v $
 * Revision 1.2  1992/09/28  18:34:51  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:29:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASC;

(* MAS Complex Number Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASC.md,v 1.2 1992/09/28 18:34:51 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE CABS(R: LIST): LIST;
(*Complex number absolute value.  R is a complex number.  S is the
absolute value of R, a rational number. *)


PROCEDURE CCON(R: LIST): LIST;
(*Complex number conjugate.  R is a complex number. S is the
complex conjugate of R. *)


PROCEDURE CCOMP(R,S: LIST): LIST;
(*Complex number comparison.  R and S are complex numbers.
t=0 if R=S, t=1 else. *)


PROCEDURE CDIF(R,S: LIST): LIST;
(*Complex number difference.  R and S are complex numbers.  T=R-S. *)


PROCEDURE CDREAD(): LIST; 
(*Complex number decimal read.  The complex number R is read
from the input stream.  Any preceding blanks are skipped. *)


PROCEDURE CDWRITE(R,NL: LIST); 
(*Complex number decimal write.  R is a complex number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)


PROCEDURE CEXP(A,NL: LIST): LIST; 
(*Complex number exponentiation.  A is a complex number,
n is a non-negative beta-integer.  B=A**n. *)


PROCEDURE CIM(R: LIST): LIST;
(*Complex number imaginary part.  R is a complex number.  b is the
imaginary part of R, a rational number. *)


PROCEDURE CINT(A: LIST): LIST;
(*Complex number from integer.  A is an integer.  R is the complex
number with real part A/1 and imaginary part 0. *)


PROCEDURE CRE(R: LIST): LIST;
(*Complex number real part.  R is a complex number.  b is the
real part of R, a rational number. *)


PROCEDURE CRN(A: LIST): LIST;
(*Complex number from rational number.  A is a rational number.  
R is the complex number with real part A and imaginary part 0. *)


PROCEDURE CRNP(A, B: LIST): LIST;
(*Complex number from pair of rational numbers.  A and B are 
rational numbers.  R is the complex number with real part A 
and imaginary part B. *)


PROCEDURE CNINV(R: LIST): LIST;
(*Complex number inverse.  R is a non-zero complex number.  S R=1. *)


PROCEDURE CNEG(R: LIST): LIST;
(*Complex number negative.  R is a complex number.  S=-R. *)


PROCEDURE CONE(R: LIST): LIST; 
(*Complex number one.  R is a complex number.  s=1 if R=1,
s=0 else. *)


PROCEDURE CPROD(R,S: LIST): LIST;
(*Complex number product.  R and S are complex numbers.  T=R*S. *)


PROCEDURE CQ(R,S: LIST): LIST;
(*Complex number quotient.  R and S are complex numbers, S non-zero.
T=R/S. *)


PROCEDURE CRAND(NL: LIST): LIST;
(*Complex number, random.  n is a positive beta-integer.  Random 
rational numbers A and B are generated using RNRAND(n). Then 
R is the complex number with real part A and imaginary part B. *)


PROCEDURE CNREAD(): LIST;
(*Complex number read.  The complex number R is read from the input
stream.  Any preceding blanks are skipped. *)


PROCEDURE CSUM(R,S: LIST): LIST;
(*Complex number sum.  R and S are complex numbers.  T=R+S. *)


PROCEDURE CNWRITE(R: LIST);
(*Complex number write. R is a complex number.  R is converted 
to decimal and written in the output stream. *)


END MASC. 


(* -EOF- *)
