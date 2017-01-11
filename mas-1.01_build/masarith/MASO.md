(* ----------------------------------------------------------------------------
 * $Id: MASO.md,v 1.2 1992/09/28 18:34:52 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASO.md,v $
 * Revision 1.2  1992/09/28  18:34:52  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:29:07  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASO;

(* MAS Octonion Number Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASO.md,v 1.2 1992/09/28 18:34:52 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE OABS(R: LIST): LIST;
(*Octonion number absolute value.  R is a octonion number.  S is the
absolute value of R, a rational number. *)


PROCEDURE OCON(R: LIST): LIST;
(*Octonion number conjugate.  R is a octonion number. S is the
octonion conjugate of R. *)


PROCEDURE OCOMP(R,S: LIST): LIST;
(*Octonion number comparison.  R and S are octonion numbers.
t=0 if R=S, t=1 else. *)


PROCEDURE ODIF(R,S: LIST): LIST;
(*Octonion number difference.  R and S are octonion numbers.  T=R-S. *)


PROCEDURE ODREAD(): LIST; 
(*Octonion number decimal read.  The octonion number R is read
from the input stream.  Any preceding blanks are skipped. *)


PROCEDURE ODWRITE(R,NL: LIST); 
(*Octonion number decimal write.  R is a octonion number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)


PROCEDURE OEXP(A,NL: LIST): LIST; 
(*Octonion number exponentiation.  A is a octonion number,
n is a non-negative beta-integer.  B=A**n. *)


PROCEDURE OIM(R: LIST): LIST;
(*Octonion number imaginary part.  R is a octonion number.  b is the
imaginary part of R, a rational number. *)


PROCEDURE OINT(A: LIST): LIST;
(*Octonion number from integer.  A is an integer.  R is the octonion
number with real part A/1 and imaginary part 0. *)


PROCEDURE ORE(R: LIST): LIST;
(*Octonion number real part.  R is a octonion number.  b is the
real part of R, a rational number. *)


PROCEDURE ORN(A: LIST): LIST;
(*Octonion number from rational number.  A is a rational number.  
R is the octonion number with real part A and imaginary part 0. *)


PROCEDURE ORNP(A, B: LIST): LIST;
(*Octonion number from pair of rational numbers.  A and B are 
rational numbers.  R is the octonion number with real part A 
and imaginary part B. *)


PROCEDURE ONINV(R: LIST): LIST;
(*Octonion number inverse.  R is a non-zero octonion number.  S R=1. *)


PROCEDURE ONEG(R: LIST): LIST;
(*Octonion number negative.  R is a octonion number.  S=-R. *)


PROCEDURE OONE(R: LIST): LIST; 
(*Octonion number one.  R is a octonion number.  s=1 if R=1,
s=0 else. *)


PROCEDURE OPROD(R,S: LIST): LIST;
(*Octonion number product.  R and S are octonion numbers.  T=R*S. *)


PROCEDURE OQ(R,S: LIST): LIST;
(*Octonion number quotient.  R and S are octonion numbers, S non-zero.
T=R/S. *)


PROCEDURE ORAND(NL: LIST): LIST;
(*Octonion number, random.  n is a positive beta-integer.  Random 
rational numbers A and B are generated using RNRAND(n). Then 
R is the octonion number with real part A and imaginary part B. *)


PROCEDURE ONREAD(): LIST;
(*Octonion number read.  The octonion number R is read from the input
stream.  Any preceding blanks are skipped. *)


PROCEDURE OSUM(R,S: LIST): LIST;
(*Octonion number sum.  R and S are octonion numbers.  T=R+S. *)


PROCEDURE ONWRITE(R: LIST);
(*Octonion number write. R is a octonion number.  R is converted 
to decimal and written in the output stream. *)


END MASO. 


(* -EOF- *)
