(* ----------------------------------------------------------------------------
 * $Id: MASRN.md,v 1.2 1992/02/12 13:19:04 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASRN.md,v $
 * Revision 1.2  1992/02/12  13:19:04  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASRN;

(* MAS Rational Number Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASRN.md,v 1.2 1992/02/12 13:19:04 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RNDRD(): LIST; 
(*Rational number decimal read.  The rational number R is read
from the input stream.  Any preceding blanks are skipped.*)


PROCEDURE RNDWR(R,NL: LIST); 
(*Rational number decimal write.  R is a rational number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)


PROCEDURE RNDWRS(A,S: LIST); 
(*Rational number decimal write special.
Call RNDWR. *)


PROCEDURE RNEXP(A,NL: LIST): LIST; 
(*Rational number exponentiation.  A is a rational number,
n is a non-negative beta-integer.  B=A**n.*)


PROCEDURE RNMAX(AL,BL: LIST): LIST; 
(*Rational number maximum.  a and b are rational numbers.
c is the maximum of a and b.*)


PROCEDURE RNONE(R: LIST): LIST; 
(*Rational number one.  R is a rational number.  s=1 if R=1,
s=0 else. *)


END MASRN.


(* -EOF- *)
