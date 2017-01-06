(* ----------------------------------------------------------------------------
 * $Id: DOMAPF.md,v 1.2 1992/02/12 17:31:26 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMAPF.md,v $
 * Revision 1.2  1992/02/12  17:31:26  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:08  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMAPF;

(* MAS Domain Arbitrary Precision Floating Point Definition Module. *)



FROM MASADOM IMPORT Domain;


VAR DOMAPFD: Domain;

CONST rcsid = "$Id: DOMAPF.md,v 1.2 1992/02/12 17:31:26 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadAPF();
(*Domain load arbitrary precision floating point. *)


END DOMAPF.

(* -EOF- *)
