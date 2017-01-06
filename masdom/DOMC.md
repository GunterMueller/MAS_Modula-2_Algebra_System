(* ----------------------------------------------------------------------------
 * $Id: DOMC.md,v 1.1 1992/09/28 17:47:02 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMC.md,v $
 * Revision 1.1  1992/09/28  17:47:02  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMC;

(* MAS Domain Complex Number Definition Module. *)


FROM MASADOM IMPORT Domain;

CONST rcsid = "$Id: DOMC.md,v 1.1 1992/09/28 17:47:02 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


VAR DOMCD: Domain;


PROCEDURE DomLoadC();
(*Domain load complex number. *)


END DOMC.

(* -EOF- *)
