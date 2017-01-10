(* ----------------------------------------------------------------------------
 * $Id: Portab.md,v 1.2 1992/02/12 17:31:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: Portab.md,v $
 * Revision 1.2  1992/02/12  17:31:59  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:18  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE Portab;

(* Portability Definition Module. *)

CONST rcsid = "$Id: Portab.md,v 1.2 1992/02/12 17:31:59 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

TYPE STRING = ARRAY[0..80] OF CHAR;

VAR esc, cr, ff, ef, lf, del, bs, nul, sp: CHAR;

END Portab.
(* -EOF- *)
