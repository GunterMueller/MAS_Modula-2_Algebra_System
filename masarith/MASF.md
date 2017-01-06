(* ----------------------------------------------------------------------------
 * $Id: MASF.md,v 1.3 1992/10/16 13:52:04 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASF.md,v $
 * Revision 1.3  1992/10/16  13:52:04  kredel
 * Errors found by Mocka corrected
 *
 * Revision 1.2  1992/02/12  13:19:01  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:02  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASF;

(* MAS Floating Point Definition Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT;


FROM MASSTOR IMPORT LIST;
 

TYPE MFLOAT = REAL;


VAR FBETA:  MFLOAT;
    FBETAH: MFLOAT;
    BETAH:  GAMMAINT;
    IBETA:  LIST;

CONST rcsid = "$Id: MASF.md,v 1.3 1992/10/16 13:52:04 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE FFGI(N: GAMMAINT): MFLOAT;
(*Floating point from gamma integer.
The gamma integer N is converted to the floating point number A. *)
 

PROCEDURE IFF(F: MFLOAT): LIST;
(*Integer from floating point.
The floating point number F is converted to the integer A. *)

 
PROCEDURE FEXP(F: MFLOAT; N: GAMMAINT): MFLOAT;
(*Floating point exponentiation.
The floating point number F raised to the n-th power. *)

 
PROCEDURE FLOG10(F: MFLOAT): MFLOAT;
(*Floating point logarithm base 10.
The logarithm of the floating point number F with base 10 is returned. *)


PROCEDURE FFINT(N: LIST): MFLOAT;
(*Floating point from integer.
The integer N is converted to the floating point number f. *)


PROCEDURE FFRN(A: LIST): MFLOAT;
(*Floating point from rational number.
The rational number A is converted to the floating point number f. *)


PROCEDURE RNFF(F: MFLOAT): LIST;
(*Rational number from floating point.
The floating point number F is converted to the rational number R. *)


PROCEDURE SIN(A: LIST): LIST;
(*Sinus. A is a rational number, the sinus of A is returned. *)  


PROCEDURE COS(A: LIST): LIST;
(*Cosinus. A is a rational number, the cosinus of A is returned. *)  


PROCEDURE TAN(A: LIST): LIST;
(*Tangens. A is a rational number, the tangens of A is returned. *)  


PROCEDURE ARCTAN(A: LIST): LIST;
(*Arcus tangens. A is a rational number, the arctangens of A is returned. *)  


PROCEDURE EXPF(A: LIST): LIST;
(*Exponential. A is a rational number, the exponential of A is returned. *)  


PROCEDURE LN(A: LIST): LIST;
(*Ln. A is a rational number, the natural logarithm of A is returned. *)  


PROCEDURE LOG(A: LIST): LIST;
(*Log. A is a rational number, the logarithm base 10 of A is returned. *)  


PROCEDURE SQRT(A: LIST): LIST;
(*Sqrt. A is a rational number, the square root of A is returned. *)  


END MASF.


(* -EOF- *)
