(* ----------------------------------------------------------------------------
 * $Id: MASPARSE.md,v 1.2 1992/02/12 17:32:25 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASPARSE.md,v $
 * Revision 1.2  1992/02/12  17:32:25  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:01  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASPARSE;

(* MAS Parser Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASPARSE.md,v 1.2 1992/02/12 17:32:25 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE Parse(): LIST;
(*Parse program and generate code. *)

                       
PROCEDURE SwitchParse(g: BOOLEAN);
(*Switch parsing between generic / non-generic parse. 
If g = TRUE then the parser generates code for generic names, 
if g = FALSE then the parser generates code for the builtin LISP 
arithmetic functions. *)


END MASPARSE.



(* -EOF- *)
