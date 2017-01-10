(* ----------------------------------------------------------------------------
 * $Id: DIPRF.md,v 1.2 1992/02/12 17:34:21 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRF.md,v $
 * Revision 1.2  1992/02/12  17:34:21  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:39  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPRF;

(* DIP Rational Function Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPRF.md,v 1.2 1992/02/12 17:34:21 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IFWRIT(R,V: LIST); 
(*Integral function write. R is an integral function.  
R is the variable list. R is written in the output stream. *)


PROCEDURE RFDEN(R: LIST): LIST; 
(*Rational function denominator.  R is a rational function.
BL is the denominator of R, a positive integral polynomial
in RL variables. *)


PROCEDURE RFDIF(R,S: LIST): LIST; 
(*Rational function difference.  R and S are rational functions.
T=R-S. *)


PROCEDURE RFEXP(A,NL: LIST): LIST; 
(*Rational function exponentiation.  A is a rational function,
n is a non-negative beta-integer.  B=A**n. *)


PROCEDURE RFFIP(RL,A: LIST): LIST; 
(*Rational function from integral polynomial. A is an integral
polynomial in RL variables. R is the rational function A/1. *)


PROCEDURE RFINV(R: LIST): LIST; 
(*Rational function inverse. R is a non-zero rational
function. S=1/R. *)


PROCEDURE RFNEG(R: LIST): LIST; 
(*Rational function negative. R is a rational function. S=-R. *)


PROCEDURE RFNOV(R: LIST): LIST; 
(*Rational function number of variables. R is a rational
function. RL is the number of variables of the numerator
and denumerator of R. *)


PROCEDURE RFNUM(R: LIST): LIST; 
(*Rational function numerator.  R is a rational function.
AL is the numerator of R, an integral polynomial. *)


PROCEDURE RFONE(R: LIST): LIST; 
(*Rational function one.  R is a rational function.  s=1 if R=1,
s=0 else. *)


PROCEDURE RFPROD(R,S: LIST): LIST; 
(*Rational function product.  R and S are rational functions.
T=R*S. *)


PROCEDURE RFQ(R,S: LIST): LIST; 
(*Rational function quotient. R and S are rational functions,
S non-zero. T=R/S. *)


PROCEDURE RFREAD(V: LIST): LIST; 
(*Rational function read. The rational function R is read
from the input stream. V is the variable list. any preceding
blanks are skipped. *)


PROCEDURE RFRED(RL,A,B: LIST): LIST; 
(*Rational function reduction to lowest terms.  A and B are
integral polynomials in RL variables, B non-zero. R is the
rational function A/B in canonical form. *)


PROCEDURE RFSIGN(R: LIST): LIST; 
(*Rational function sign.  R is a rational function.  s=sign(R). *)


PROCEDURE RFSUM(R,S: LIST): LIST; 
(*Rational function sum.  R and S are rational functions.  T=R+S. *)


PROCEDURE RFWRIT(R,V: LIST); 
(*Rational function write. R is a rational function.  V is the 
variable list. R is written in the output stream. *)


END DIPRF.

(* -EOF- *)
