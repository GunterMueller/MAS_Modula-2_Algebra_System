(* ----------------------------------------------------------------------------
 * $Id: MASERR.md,v 1.2 1992/02/12 17:31:55 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASERR.md,v $
 * Revision 1.2  1992/02/12  17:31:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:12  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASERR;

(* MAS Error Definition Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT;

FROM SYSTEM IMPORT ADDRESS;


(* error indicators *)
CONST spotless  = 0;
      harmless  = 1;
      severe    = 2;
      fatal     = 3;
      confusion = 9;

CONST rcsid = "$Id: MASERR.md,v 1.2 1992/02/12 17:31:55 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



TYPE P0 = PROCEDURE;


VAR DebugProcessor: P0; (* procedure called by ERROR if debug requested *)

    history: GAMMAINT; (* highest error level encountered so far. *)


PROCEDURE ERROR(a: GAMMAINT; s: ARRAY OF CHAR);
(*Error. An error of severity a and indication s is reported. *)


PROCEDURE ErrorHandler(a: P0): GAMMAINT;
(*Error handler. Any error reported by the ERROR procedure is catched. *)


END MASERR.


(* -EOF- *)
