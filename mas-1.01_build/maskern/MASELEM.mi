(* ----------------------------------------------------------------------------
 * $Id: MASELEM.mi,v 1.3 1992/10/15 16:24:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASELEM.mi,v $
 * Revision 1.3  1992/10/15  16:24:57  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:34  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASELEM;

(* MAS Elementary Function Implementation Module. *)



CONST rcsidi = "$Id: MASELEM.mi,v 1.3 1992/10/15 16:24:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE MASABS(a: GAMMAINT): GAMMAINT;
(*Absolute value.  a is a gamma-integer.  Returns the absolute value
of a. *)
VAR  b: GAMMAINT;
BEGIN 
(*1*) IF a >= 0 THEN b:=a; ELSE b:=-a; END;
      RETURN(b);
(*4*) END MASABS;


PROCEDURE MASEVEN(a: GAMMAINT): BOOLEAN;
(*Even.  a is a gamma-integer.  Returns TRUE if a is even and 
FALSE otherwise. *)
VAR  t: BOOLEAN;
BEGIN
(*1*) t:=TRUE;
      IF (a MOD 2) <> 0 THEN t:=FALSE END;
      RETURN(t);
(*4*) END MASEVEN;


PROCEDURE MASEXP(a,b: GAMMAINT): GAMMAINT;
(*Exponential function.  a and b are gamma-integers, b non-negative.
Returns $a^b$, with $0^0=1$. *)
VAR  CL, IL: GAMMAINT;
BEGIN
(*1*) CL:=1;
      FOR IL:=1 TO b DO CL:=a*CL; END;
      RETURN(CL);
(*4*) END MASEXP;


PROCEDURE MASMAX(a,b: GAMMAINT): GAMMAINT;
(*Maximum.  a and b are gamma-integers.  Returns the maximum of
a and b. *)
VAR  c: GAMMAINT;
BEGIN
(*1*) IF a >= b THEN c:=a; ELSE c:=b; END;
      RETURN(c);
(*4*) END MASMAX;


PROCEDURE MASMIN(a,b: GAMMAINT): GAMMAINT;
(*Minimum.  a and b are gamma-integers.  Returns the minimum
of a and b. *)
VAR  c: GAMMAINT;
BEGIN
(*1*) IF a <= b THEN c:=a; ELSE c:=b; END;
      RETURN(c);
(*4*) END MASMIN;


PROCEDURE MASODD(a: GAMMAINT): BOOLEAN;
(*Odd.  a is a gamma-integer.  Returns TRUE if a is odd and 
FALSE otherwise. *)
VAR  t: BOOLEAN;
BEGIN
(*1*) t:=FALSE;
      IF (a MOD 2) <> 0 THEN t:=TRUE END;
      RETURN(t);
(*4*) END MASODD;


PROCEDURE MASQREM(a,b: GAMMAINT; VAR q,r: GAMMAINT);
(*Quotient and remainder.  a and b are gamma-integers, b non-zero.
$q=integer(a/b)$ and $r=a-b*q$. *)
BEGIN
(*1*) q:=a DIV b; r:=a-b*q; RETURN;
(*4*) END MASQREM;


PROCEDURE MASREM(a,b: GAMMAINT): GAMMAINT;
(*Remainder.  a and b are gamma-integers, b non-zero.
Returns $a-b*integer(a/b)$. *)
VAR  q, r: GAMMAINT;
BEGIN
(*1*) q:=a DIV b; r:=a-b*q; RETURN(r);
(*4*) END MASREM;


PROCEDURE MASSIGN(a: GAMMAINT): GAMMAINT;
(*Sign.  a is a gamma-integer.  Returns the sign of a. *)
VAR  s: GAMMAINT;
BEGIN
(*1*) IF a > 0 THEN s:=1; ELSE
         IF a < 0 THEN s:=-1; ELSE s:=0; END;
         END;
      RETURN(s);
(*4*) END MASSIGN;


END MASELEM.


(* -EOF- *)
