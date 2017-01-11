(* ----------------------------------------------------------------------------
 * $Id: DOMIP.md,v 1.2 1992/02/12 17:31:29 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMIP.md,v $
 * Revision 1.2  1992/02/12  17:31:29  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:12  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMIP;

(* MAS Domain Integral Polynomial Definition Module. *)



FROM MASADOM IMPORT Domain;


VAR DOMIPD: Domain;

CONST rcsid = "$Id: DOMIP.md,v 1.2 1992/02/12 17:31:29 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadIP();
(*Domain load integral polynomials . *)


END DOMIP.

(* -EOF- *)
