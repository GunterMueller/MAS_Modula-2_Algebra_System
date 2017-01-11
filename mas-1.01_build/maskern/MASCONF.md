(* ----------------------------------------------------------------------------
 * $Id: MASCONF.md,v 1.6 1995/03/23 17:43:56 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASCONF.md,v $
 * Revision 1.6  1995/03/23  17:43:56  pesch
 * Added new options -E (exit on error) and -c (command).
 *
 * Revision 1.5  1995/03/23  16:01:26  pesch
 * New options -e (exit after loading files) and -o (output file).
 *
 * Revision 1.4  1995/03/06  16:09:29  pesch
 * Modified for masconf.c instead of removed MASCONF.mi.
 *
 * Revision 1.3  1992/10/16  13:47:52  kredel
 * Errors found by Mocka
 *
 * Revision 1.2  1992/02/12  17:31:52  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:08  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

FOREIGN MODULE MASCONF;

(* MAS Configuration Definition Module. *)

(* Import lists and Definitions *) 

FROM MASELEM	IMPORT	GAMMAINT;

CONST rcsid = "$Id: MASCONF.md,v 1.6 1995/03/23 17:43:56 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1995 Universitaet Passau";

VAR KBCell: GAMMAINT; (* Requested cell storage in kilo byte. *)

    InitName: ARRAY [0..255] OF CHAR; (* Name of initialization file. *)

    FileName: ARRAY [0..255] OF CHAR; (* Name of input file. *)

    OutFileName: ARRAY [0..255] OF CHAR; (* Name of output file. *)

    InitialCommand: ARRAY [0..1002] OF CHAR; (* Initial command string. *)

    ExitAfterFiles: BOOLEAN;

    ExitOnError: BOOLEAN;

END MASCONF.


(* -EOF- *)
