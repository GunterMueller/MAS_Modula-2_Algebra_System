(* ----------------------------------------------------------------------------
 * $Id: ALDPARSE.md,v 1.2 1992/02/12 17:32:18 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ALDPARSE.md,v $
 * Revision 1.2  1992/02/12  17:32:18  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:55  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE ALDPARSE;

(* Aldes Parser Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: ALDPARSE.md,v 1.2 1992/02/12 17:32:18 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE Aparse(): LIST;
(* Parse a set of ALDES-2 declarations and algorithms. *) 


END ALDPARSE.
(* -EOF- *)
