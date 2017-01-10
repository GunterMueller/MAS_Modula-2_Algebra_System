(* ----------------------------------------------------------------------------
 * $Id: MASLOADS.md,v 1.2 1992/02/12 17:32:53 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLOADS.md,v $
 * Revision 1.2  1992/02/12  17:32:53  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:56  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASLOADS;

(* MAS Load Syzygy Definition Module. *)


CONST rcsid = "$Id: MASLOADS.md,v 1.2 1992/02/12 17:32:53 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsS;
(*Tell Modula and LISP about external compiled procedures. *)

END MASLOADS.
(* -EOF- *)
