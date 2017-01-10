(* ----------------------------------------------------------------------------
 * $Id: DOMI.md,v 1.2 1992/02/12 17:31:27 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMI.md,v $
 * Revision 1.2  1992/02/12  17:31:27  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:10  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMI;

(* MAS Domain Integer Definition Module. *)



FROM MASADOM IMPORT Domain;


VAR DOMINT: Domain;

CONST rcsid = "$Id: DOMI.md,v 1.2 1992/02/12 17:31:27 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadI();
(*Domain load integer. *)


END DOMI.

(* -EOF- *)
