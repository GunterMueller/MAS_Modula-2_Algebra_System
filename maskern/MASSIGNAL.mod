(* ----------------------------------------------------------------------------
 * $Id: MASSIGNAL.mi,v 1.6 1995/11/04 20:40:01 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994, 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASSIGNAL.mi,v $
 * Revision 1.6  1995/11/04 20:40:01  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.5  1995/10/13 16:02:10  pesch
 * Fixed error: sigsetmask() at wrong places caused SIGUSR1 to be blocked
 *              permanently.
 *
 * Revision 1.4  1995/09/12  17:22:49  pesch
 * Signal handling function are now declared in massignal.
 * Action has been changed according to ANSI C.
 * signal.* and massignal.* have been removed, the former because of
 * name clash with signal.h.
 *
 * Revision 1.3  1994/04/14  12:42:03  pesch
 * Defined Action according to POSIX.
 *
 * Revision 1.2  1994/04/12  13:55:51  pesch
 * Added line feed after signal handler output.
 *
 * Revision 1.1  1994/04/12  13:25:26  pesch
 * Default handling for SIGUSR1 is now done in MASSIGNAL.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSIGNAL;

(* MAS Signal Handling Implementation Module. *)

FROM MASBIOS	IMPORT	BLINES, CUNIT, SOUNIT, SWRITE;

FROM MASSTOR	IMPORT	LIST;

FROM massig	IMPORT	Action, SIGUSR1, SIG_IGN, SIG_IGN, raise, signal;

CONST rcsidi = "$Id: MASSIGNAL.mi,v 1.6 1995/11/04 20:40:01 pesch Exp $";
CONST copyrighti = "Copyright (c) 1994, 1995 Universitaet Passau";

VAR s: Action;

PROCEDURE SigUsr1HandleDefault(signo: INTEGER);
VAR dummy: Action;
    Dummy: LIST;
BEGIN
     dummy:=signal(SIGUSR1,SIG_IGN);
     Dummy:=SOUNIT("CON:x");
     BLINES(0);
     SWRITE("______________________________________________________________________________"); BLINES(0);
     SWRITE("SIGUSR1 received. This is the default signal handler.");
        BLINES(0);
     SWRITE("Sorry, whatever is executing at the moment has"); BLINES(0);
     SWRITE("no special signal-handler installed."); BLINES(0);
     SWRITE("______________________________________________________________________________"); BLINES(1);
     Dummy:=CUNIT("CON:x");
     dummy:=signal(SIGUSR1,SigUsr1HandleDefault);
END SigUsr1HandleDefault;

BEGIN 
     (* Install a default handler for SIGUSR1. *)
     s:=signal(SIGUSR1,SigUsr1HandleDefault);
END MASSIGNAL.
(* -EOF- *)
