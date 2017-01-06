(* ----------------------------------------------------------------------------
 * $Id: DOMAF.md,v 1.2 1992/02/12 17:31:24 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMAF.md,v $
 * Revision 1.2  1992/02/12  17:31:24  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMAF;

(* MAS Domain Algebraic Number Definition Module. *)



FROM MASADOM IMPORT Domain;


VAR DOMAFD: Domain;

CONST rcsid = "$Id: DOMAF.md,v 1.2 1992/02/12 17:31:24 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadAF();
(*Domain load algebraic number. *)


END DOMAF.

(* -EOF- *)
