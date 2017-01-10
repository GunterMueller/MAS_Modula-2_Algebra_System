(* ----------------------------------------------------------------------------
 * $Id: SACEXT6.md,v 1.2 1992/02/12 17:34:52 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT6.md,v $
 * Revision 1.2  1992/02/12  17:34:52  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:33  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT6;

(* SAC Extensions 6 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT6.md,v 1.2 1992/02/12 17:34:52 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPFSFB(RL,A: LIST): LIST; 
(*Integral polynomial finest squarefree basis.  A eq (A sub 1 , ...,
A sub n ), n ge 0, is a list of positive primitive integral
polynomials in r variables, r ge 1, each of which is of positive
degree in its main variable.  B is a finest squarefree basis for A.*)


END SACEXT6.

(* -EOF- *)
