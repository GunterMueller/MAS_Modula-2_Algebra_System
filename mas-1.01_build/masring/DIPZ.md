(* ----------------------------------------------------------------------------
 * $Id: DIPZ.md,v 1.2 1992/02/12 17:34:26 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPZ.md,v $
 * Revision 1.2  1992/02/12  17:34:26  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPZ;

(* DIP Zero Dimensional Ideal Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPZ.md,v 1.2 1992/02/12 17:34:26 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRMPG(IL,F: LIST): LIST; 
(*Distributive rational minimal polynomial for a groebner basis.
F is a groebner basis. PP is the minimal polynomial for the
i-th variable for F. *)


END DIPZ.

(* -EOF- *)
