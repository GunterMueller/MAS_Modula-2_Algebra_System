(* ----------------------------------------------------------------------------
 * $Id: MASmtc.md,v 1.2 1992/02/12 17:31:58 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASmtc.md,v $
 * Revision 1.2  1992/02/12  17:31:58  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:16  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASmtc;

(* MAS mtc [Modula-2 to C] Definition Module. *)



FROM SYSTEM IMPORT ADDRESS;

VAR EditPrg, EditPrm: ARRAY [0..80] OF CHAR;

CONST rcsid = "$Id: MASmtc.md,v 1.2 1992/02/12 17:31:58 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";


 
PROCEDURE getstck(): ADDRESS;
(*Get contents of stack register. *)
 

PROCEDURE gettoc(): ADDRESS;
(*Get contents of toc register. *)


PROCEDURE NextParm(VAR s: ARRAY OF CHAR): BOOLEAN;
(*Next Parameter. The next parameter from the GEM environement is
placed in string s. If no parameter was found, FALSE is returned
and s is undefined, else TRUE is returned. The separator for the 
parameters is the blank character. *)


PROCEDURE DOS(s: ARRAY OF CHAR): INTEGER;
(*Call DOS program. *)


PROCEDURE EDIT(s: ARRAY OF CHAR): INTEGER;
(*Edit file with name s. *)


END MASmtc.


(* -EOF- *)
