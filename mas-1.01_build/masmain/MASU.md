(* ----------------------------------------------------------------------------
 * $Id: MASU.md,v 1.4 1995/09/12 17:24:39 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASU.md,v $
 * Revision 1.4  1995/09/12  17:24:39  pesch
 * Corrected to handle prompts other then "MAS:".
 *
 * Revision 1.3  1995/03/06  16:45:42  pesch
 * Modified to make use of GNU readline possible.
 *
 * Revision 1.2  1992/02/12  17:32:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:58  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASU;

(* MAS Utility Definition Module. *)


FROM MASSTOR IMPORT LIST;


VAR  Time, Debug, PromptFirst: BOOLEAN;
     WroteChars, PromptType: INTEGER;

CONST rcsid = "$Id: MASU.md,v 1.4 1995/09/12 17:24:39 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE InitExternalsU();
(*Initialize external compiled utility procedures. *)


PROCEDURE DoParse(): LIST;
(*Do parse. Call specific Parser. *)


PROCEDURE DoWrite(Y: LIST);
(*Do Write. Write according to Parser. *)


PROCEDURE MWRITE(Y: LIST);
(*Output in modula like syntax. *)
                       

PROCEDURE MWRIT1(Y: LIST; top: BOOLEAN);
(*Output in modula like syntax. *)


END MASU.
(* -EOF- *)
