(* ----------------------------------------------------------------------------
 * $Id: SACD.md,v 1.2 1992/02/12 13:19:10 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACD.md,v $
 * Revision 1.2  1992/02/12  13:19:10  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:12  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACD;

(* SAC Digit Definition Module. *)



(* Import lists and Definitions *) 

FROM MASSTOR IMPORT LIST;


VAR THETA, ZETA, DELTA, ETA, EPSIL: LIST;

    
    TABP2: ARRAY[1..64] OF LIST;

CONST rcsid = "$Id: SACD.md,v 1.2 1992/02/12 13:19:10 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


    
PROCEDURE BITRAN(): LIST;
(*Bit, random.  b is a random bit, 0 or 1.*)


PROCEDURE DEGCD(AL,BL: LIST; VAR CL,UL,VL: LIST);
(*Digit extended greatest common divisor.  a and b are beta-integers,
a ge b ge 0.  c=GCD(a,b), a beta-integer.  a*u+b*v=c, with
ABS(u) le b/2c, ABS(v) le a/2c.*)


PROCEDURE DGCD(AL,BL: LIST): LIST;
(*Digit greatest common divisor.  a and b are beta-integers,
a ge b ge 0.  c=GCD(a,b).*)


PROCEDURE DLOG2(AL: LIST): LIST;
(*Digit logarithm, base 2.  a is a beta-digit.  If a=0 then n=0.
otherwise n=FLOOR(LOG2(ABS(a)))+1.*)


PROCEDURE DPCC(AL1,AL2: LIST; VAR UL,ULP,VL,VLP: LIST);
(*Digit partial cosequence calculation.  a1 and a2 are beta-integers,
a1 ge a2 gt 0.  u, up, v and vp are the last cosequence elements
of a1 and a2 which can be guaranteed to correspond to correct
quotient digits.*)


PROCEDURE DPR(AL,BL: LIST; VAR CL,DL: LIST);
(*Digit product.  a and b are beta-digits.  c and d are the unique
beta-digits such that a*b=c*beta+d and c*d ge 0.*)


PROCEDURE DQR(AL1,AL0,BL: LIST; VAR QL,RL: LIST);
(*Digit quotient and remainder.  a1, a0 and b are beta-integers with
a1*a0 ge 0 and ABS(b) gt ABS(a1).  q is the integral part of
(a1*beta+a0)/b and r is (a1*beta+a0)-b*q.  q and r are
beta-integers.*)


PROCEDURE DRAN(): LIST;
(*Digit, random.  a is a random beta-digit.*)


PROCEDURE DRANN(): LIST;
(*Digit, random non-negative.  a is a random non-negative beta-digit.
Caution, the low-order bits of a are not very random.*)


PROCEDURE DSQRTF(AL: LIST; VAR BL,TL: LIST);
(*Digit square root function.  a is a non-negative beta-integer.
b is the floor function of the square root of a and t is the sign
of a-b*b.*)


END SACD.


(* -EOF- *)
