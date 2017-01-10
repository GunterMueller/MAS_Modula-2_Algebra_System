(* ----------------------------------------------------------------------------
 * $Id: setjmp.md,v 1.4 1993/05/11 10:46:24 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: setjmp.md,v $
 * Revision 1.4  1993/05/11  10:46:24  kredel
 * Increased jmp buffer
 *
 * Revision 1.3  1992/09/29  09:39:48  kredel
 * Added procedure comments.
 *
 * Revision 1.2  1992/02/12  17:32:04  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:24  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

FOREIGN MODULE setjmp;

(* Setjmp Foreign Module. *)


TYPE jmp_buf = ARRAY [0..255] OF INTEGER;

CONST rcsid = "$Id: setjmp.md,v 1.4 1993/05/11 10:46:24 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE setjmp(VAR env: jmp_buf): INTEGER;
(* Set jump environment. *)


PROCEDURE longjmp(VAR env: jmp_buf; rc: INTEGER);
(* Long jump to old environment. *) 


END setjmp.
(* -EOF- *)
