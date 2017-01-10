(* ----------------------------------------------------------------------------
 * $Id: DOMO.md,v 1.1 1992/09/28 17:47:06 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMO.md,v $
 * Revision 1.1  1992/09/28  17:47:06  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMO;

(* MAS Domain Octonion Number Definition Module. *)


FROM MASADOM IMPORT Domain;

CONST rcsid = "$Id: DOMO.md,v 1.1 1992/09/28 17:47:06 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



VAR DOMOD: Domain;


PROCEDURE DomLoadO();
(*Domain load octonion number. *)


END DOMO.

(* -EOF- *)
