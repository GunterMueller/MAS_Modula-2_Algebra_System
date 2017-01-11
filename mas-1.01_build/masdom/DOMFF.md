(* ----------------------------------------------------------------------------
 * $Id: DOMFF.md,v 1.1 1992/09/28 17:47:04 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMFF.md,v $
 * Revision 1.1  1992/09/28  17:47:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMFF;

(* MAS Domain Finite Field Definition Module. *)


FROM MASADOM IMPORT Domain;

CONST rcsid = "$Id: DOMFF.md,v 1.1 1992/09/28 17:47:04 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


VAR DOMFFD: Domain;


PROCEDURE DomLoadFF();
(*Domain load finite field. *)


END DOMFF.

(* -EOF- *)
