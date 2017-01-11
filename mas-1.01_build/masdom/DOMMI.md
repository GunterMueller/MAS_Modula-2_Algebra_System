(* ----------------------------------------------------------------------------
 * $Id: DOMMI.md,v 1.2 1992/02/12 17:31:31 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMMI.md,v $
 * Revision 1.2  1992/02/12  17:31:31  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:16  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DOMMI;

(* MAS Domain Modular Integer Definition Module. *)



FROM MASADOM IMPORT Domain;


VAR DOMMID: Domain;

CONST rcsid = "$Id: DOMMI.md,v 1.2 1992/02/12 17:31:31 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DomLoadMI();
(*Domain load modular integer. *)


END DOMMI.

(* -EOF- *)
