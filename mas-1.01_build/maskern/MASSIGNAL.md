(* ----------------------------------------------------------------------------
 * $Id: MASSIGNAL.md,v 1.4 1995/12/16 15:11:42 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASSIGNAL.md,v $
 * Revision 1.4  1995/12/16 15:11:42  kredel
 * Provided module comment.
 *
 * Revision 1.3  1995/12/16  13:11:19  kredel
 * Comments provided.
 *
 * Revision 1.2  1994/04/14  16:47:55  dolzmann
 * Syntactical errors (founded by Mocka) corrected.
 *
 * Revision 1.1  1994/04/12  13:25:25  pesch
 * Default handling for SIGUSR1 is now done in MASSIGNAL.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSIGNAL;

(* MAS Signal Handling Definition Module. *)


CONST rcsid = "$Id: MASSIGNAL.md,v 1.4 1995/12/16 15:11:42 kredel Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE SigUsr1HandleDefault(signo: INTEGER);
(* SIGUSR1 default signal handler. *)
	
END MASSIGNAL.
(* -EOF- *)
