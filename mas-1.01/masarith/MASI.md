(* ----------------------------------------------------------------------------
 * $Id: MASI.md,v 1.2 1992/02/12 13:19:03 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASI.md,v $
 * Revision 1.2  1992/02/12  13:19:03  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASI;

(* MAS Integer Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASI.md,v 1.2 1992/02/12 13:19:03 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPROD(A,B: LIST): LIST; 
(*Integer product.  A and B are integers.  C=A*B. For long
integers Karatsubas method is used. *)


END MASI.


(* -EOF- *)
