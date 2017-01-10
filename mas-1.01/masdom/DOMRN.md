(* ----------------------------------------------------------------------------
 * $Id: DOMRN.md,v 1.3 1994/11/03 14:42:16 pfeil Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMRN.md,v $
 * Revision 1.3  1994/11/03  14:42:16  pfeil
 * modified comment
 *
 * Revision 1.2  1992/02/12  17:31:35  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:20  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMRN;

(* MAS Domain Rational Number Definition Module. *)


FROM MASADOM IMPORT Domain;


VAR DOMRND: Domain;

CONST rcsid = "$Id: DOMRN.md,v 1.3 1994/11/03 14:42:16 pfeil Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadRN();
(*Domain load rational number. *)


END DOMRN.

(* -EOF- *)
