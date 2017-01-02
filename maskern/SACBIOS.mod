(* ----------------------------------------------------------------------------
 * $Id: SACBIOS.mi,v 1.3 1992/10/15 16:25:03 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACBIOS.mi,v $
 * Revision 1.3  1992/10/15  16:25:03  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:01  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACBIOS;

(* SAC Basic I/O System Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT;

FROM MASBIOS IMPORT CWRITE;

CONST rcsidi = "$Id: SACBIOS.mi,v 1.3 1992/10/15 16:25:03 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE CWRIT2(C1,C2: GAMMAINT);
(*Character write, 2 characters.  C1 and C2 are sequentially
transmitted to the output stream using CWRITE.*)
BEGIN
(*1*) CWRITE(C1); CWRITE(C2); RETURN;
(*4*) END CWRIT2;


PROCEDURE CWRIT3(C1,C2,C3: GAMMAINT);
(*Character write, 3 characters.  C1, C2 and C3 are sequentially
transmitted to the output stream using CWRITE.*)
BEGIN
(*1*) CWRITE(C1); CWRITE(C2); CWRITE(C3); RETURN;
(*4*) END CWRIT3;


PROCEDURE CWRIT4(C1,C2,C3,C4: GAMMAINT);
(*Character write, 4 characters.  C1, C2, C3, and C4 are sequentially
transmitted to the output stream using CWRITE.*)
BEGIN
(*1*) CWRITE(C1); CWRITE(C2); CWRITE(C3); CWRITE(C4); RETURN;
(*4*) END CWRIT4;


PROCEDURE CWRIT5(C1,C2,C3,C4,C5: GAMMAINT);
(*Character write, 5 characters.  C1, C2, C3, C4 and C5 are
sequentially transmitted to the output stream using CWRITE.*)
BEGIN
(*1*) CWRITE(C1); CWRITE(C2); CWRITE(C3); CWRITE(C4); CWRITE(C5);
      RETURN;
(*4*) END CWRIT5;


PROCEDURE CWRIT6(C1,C2,C3,C4,C5,C6: GAMMAINT);
(*Character write, 6 characters.  C1, C2, C3, C4, C5 and C6 are
sequentially transmitted to the output stream using CWRITE.*)
BEGIN
(*1*) CWRITE(C1); CWRITE(C2); CWRITE(C3); CWRITE(C4); CWRITE(C5);
      CWRITE(C6); RETURN;
(*4*) END CWRIT6;


END SACBIOS.


(* -EOF- *)
