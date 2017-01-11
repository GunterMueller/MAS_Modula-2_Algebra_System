(* ----------------------------------------------------------------------------
 * $Id: MASELEM.md,v 1.2 1992/02/12 17:31:54 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASELEM.md,v $
 * Revision 1.2  1992/02/12  17:31:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:10  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASELEM;

(* MAS Elementary Functions Definition Module. *)



TYPE GAMMAINT = LONGINT;

     LIST = GAMMAINT;

CONST rcsid = "$Id: MASELEM.md,v 1.2 1992/02/12 17:31:54 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE MASABS(a: GAMMAINT): GAMMAINT;
(*Absolute value.  a is a gamma-integer.  Returns the absolute value
of a. *)


PROCEDURE MASEVEN(a: GAMMAINT): BOOLEAN;
(*Even.  a is a gamma-integer.  Returns TRUE if a is even and 
FALSE otherwise. *)


PROCEDURE MASEXP(a,b: GAMMAINT): GAMMAINT;
(*Exponential function.  a and b are gamma-integers, b non-negative.
Returns $a^b$, with $0^0=1$. *)


PROCEDURE MASMAX(a,b: GAMMAINT): GAMMAINT;
(*Maximum.  a and b are gamma-integers.  Returns the maximum of
a and b. *)


PROCEDURE MASMIN(a,b: GAMMAINT): GAMMAINT;
(*Minimum.  a and b are gamma-integers.  Returns the minimum
of a and b. *)


PROCEDURE MASODD(a: GAMMAINT): BOOLEAN;
(*Odd.  a is a gamma-integer.  Returns TRUE if a is odd and 
FALSE otherwise. *)


PROCEDURE MASQREM(a,b: GAMMAINT; VAR q,r: GAMMAINT);
(*Quotient and remainder.  a and b are gamma-integers, b non-zero.
$q=integer(a/b)$ and $r=a-b*q$. *)


PROCEDURE MASREM(a,b: GAMMAINT): GAMMAINT;
(*Remainder.  a and b are gamma-integers, b non-zero.
Returns $a-b*integer(a/b)$. *)


PROCEDURE MASSIGN(a: GAMMAINT): GAMMAINT;
(*Sign.  a is a gamma-integer.  Returns the sign of a. *)


END MASELEM.


(* -EOF- *)
