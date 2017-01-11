(* ----------------------------------------------------------------------------
 * $Id: MathLib.md,v 1.2 1993/03/22 10:17:06 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) GMD 
 * ----------------------------------------------------------------------------
 * $Log: MathLib.md,v $
 * Revision 1.2  1993/03/22  10:17:06  kredel
 * This file is not part of MAS
 *
 * Revision 1.1  1992/01/22  15:08:08  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
DEFINITION MODULE MathLib;

(* GMD Mocka MathLIb. *)

CONST rcsid = "$Id: MathLib.md,v 1.2 1993/03/22 10:17:06 kredel Exp $";
CONST copyright = "Copyright (c) GMD";


  
   PROCEDURE sqrt (x : REAL) : REAL;
      (* calculates the square root of 'x' *)
   
   PROCEDURE sqrtL (x : LONGREAL) : LONGREAL;
      (* calculates the square root of 'x' *)
   
   PROCEDURE exp (x : REAL) : REAL;
      (* calculates 'e' to the power of 'x', 'e' Euler's number *)
  
   PROCEDURE expL (x : LONGREAL) : LONGREAL;
      (* calculates 'e' to the power of 'x', 'e' Euler's number *)

   PROCEDURE ln (x : REAL) : REAL;
      (* calculates natural logarithm of 'x' *)

   PROCEDURE lnL (x : LONGREAL) : LONGREAL;
      (* calculates natural logarithm of 'x' *)

   PROCEDURE sin (x : REAL) : REAL;
      (* calculates sine of 'x' *)

   PROCEDURE sinL (x : LONGREAL) : LONGREAL;
      (* calculates sine of 'x' *)

   PROCEDURE cos (x : REAL) : REAL;
      (* calculates cosine of 'x' *)

   PROCEDURE cosL (x : LONGREAL) : LONGREAL;
      (* calculates cosine of 'x' *)
  
   PROCEDURE arctan (x : REAL) : REAL;
      (* calculates arc tangent of 'x' *)
  
   PROCEDURE arctanL (x : LONGREAL) : LONGREAL;
      (* calculates arc tangent of 'x' *)

   PROCEDURE real (x : INTEGER) : REAL;
      (* converts 'x' to type 'REAL' *)

   PROCEDURE realL (x : INTEGER) : LONGREAL;
      (* converts 'x' to type 'LONGREAL' *)

   PROCEDURE entier (x : REAL) : INTEGER;
      (* calculates the largest integer <= 'x' *)

   PROCEDURE entierL (x : LONGREAL) : INTEGER;
      (* calculates the largest long integer <= 'x' *)
  
END MathLib.
(* -EOF- *)
