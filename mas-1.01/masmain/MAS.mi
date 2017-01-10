(* ----------------------------------------------------------------------------
 * $Id: MAS.mi,v 1.11 1995/11/05 09:01:14 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MAS.mi,v $
 * Revision 1.11  1995/11/05 09:01:14  kredel
 * Support for small letter exit.
 *
 * Revision 1.10  1995/10/13  16:03:00  pesch
 * *** empty log message ***
 *
 * Revision 1.9  1995/03/24  15:36:32  pesch
 * Changed inital message.
 *
 * Revision 1.8  1995/03/23  17:44:22  pesch
 * Added new options -E (exit on error) and -c (command).
 *
 * Revision 1.7  1995/03/23  16:09:52  pesch
 * Added support for -e and -o option.
 *
 * Revision 1.6  1995/03/06  16:44:36  pesch
 * Modified to load two files at startup: InitName (which is ~/.masrc
 * (MAS.INI without kpathsea) or set by the -f option)
 * and FileName (given as argument to mas).
 *
 * Revision 1.5  1993/03/22  10:23:51  kredel
 * Copyright for 1993
 *
 * Revision 1.4  1992/10/15  16:30:31  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/02/12  17:32:47  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.2  1992/01/30  13:52:12  kredel
 * Resolved name clash: copyright -> copyrightc
 *
 * Revision 1.1  1992/01/22  15:12:03  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

MODULE MAS;

(* MAS Implementation Module. *)

(* Import lists and declarations. *)

FROM MASCONF	IMPORT	ExitAfterFiles, FileName, InitName, InitialCommand,
			OutFileName;

FROM MASSTOR	IMPORT	ADV, COMP, LIST, LIST1, SIL, TAU, TIME;

FROM MASERR	IMPORT	DebugProcessor, ErrorHandler;

FROM MASBIOS	IMPORT	BLINES, CUNIT, CWRITE, CWRITE, CloseBIOS, GWRITE,
			LISTS, SIUNIT, SOUNIT, SWRITE;

FROM MASSYM	IMPORT	UREAD, UWRITE;

FROM MASLISP	IMPORT	ENV, SCHLUSS, schluss;

FROM MASSPEC	IMPORT	EVALUATE;

FROM MASLOAD	IMPORT	InitExternals;

FROM MASU	IMPORT	Debug, DoParse, DoWrite, InitExternalsU, Time;

(*
CONST banner     = "Modula-2 Algebra System, Version 0.7";
      copyrightc = "(c)";
      copyright0 = "Copyrights: ";
      copyright1 = " 1989 - 1993, MAS: H. Kredel, Uni Passau.";
      copyright2 = " 1982, SAC-2:      G. E. Collins, Uni Ohio,";
      copyright3 =                   " R. Loos, Uni Tuebingen.";
      public     = "(non-profit redistribution is permitted)";
*)

CONST rcsidi = "$Id: MAS.mi,v 1.11 1995/11/05 09:01:14 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

PROCEDURE CLTIS1(A: LIST);
(*Character list to input stream. A is an SAC-2 character list. *)
VAR   AP, k, b: LIST;
BEGIN
(*1*) k:=CUNIT("RAM:internal1");  
      k:=SOUNIT("RAM:internal1");
(*2*) (*write out characters. *) AP:=A;
      WHILE AP <> SIL DO ADV(AP,b,AP); CWRITE(b) END;
(*3*) k:=CUNIT("RAM:internal1");  
      k:=SIUNIT("RAM:internal1"); 
(*3*) END CLTIS1;

PROCEDURE CLTIS2(A: LIST);
(*Character list to input stream. A is an SAC-2 character list. *)
VAR   AP, k, b: LIST;
BEGIN
(*1*) k:=CUNIT("RAM:internal2");  
      k:=SOUNIT("RAM:internal2");
(*2*) (*write out characters. *) AP:=A;
      WHILE AP <> SIL DO ADV(AP,b,AP); CWRITE(b) END;
(*3*) k:=CUNIT("RAM:internal2");  
      k:=SIUNIT("RAM:internal2"); 
(*3*) END CLTIS2;

PROCEDURE INTERPRETE;
(*Lisp interpreter. *)
VAR   f: LIST;
BEGIN
(*1*) (*initialize*)
      InitExternals;
      InitExternalsU; 
      (*write to outfile*)
      IF OutFileName[0] <> CHR(0) THEN f:=SOUNIT(OutFileName); END;
(*2*) (*read startup file*) 
      IF ExitAfterFiles THEN CLTIS1(LISTS(".EXIT.")); END;
      IF FileName[0] <> CHR(0) THEN f:=SIUNIT(FileName); END; 
      IF InitialCommand[0] <> CHR(0) THEN CLTIS2(LISTS(InitialCommand)); END;
      IF InitName[0] <> CHR(0) THEN f:=SIUNIT(InitName); END;
(*3*) (*read, eval, print - loop*)
      f:=ErrorHandler(REP); 
(*4*) END INTERPRETE;


PROCEDURE REP;
(*Read, Eval, Print - loop*)
VAR   S, Y, Z, T, r, e, p, t, c: LIST;
      time: BOOLEAN;
BEGIN 
(*1*) (*reset some flags*)  
      T:=TIME(); r:=T; e:=T; p:=T; c:=0;
(*2*) (*actual loop*) 
      REPEAT time:=Time;
             IF time THEN r:=TIME(); c:=TAU END;
             Y:=DoParse(); 
             IF time THEN e:=TIME(); r:=e-r; END;
             Z:=EVALUATE(Y,ENV); BLINES(0);
             IF time THEN p:=TIME(); e:=p-e; END;
             DoWrite(Z);
             IF time THEN T:=TIME(); p:=T-p; c:=TAU-c;  
                SWRITE("Time: read = "); GWRITE(r); 
                SWRITE(", eval = "); GWRITE(e); 
                SWRITE(", print = "); GWRITE(p); 
                SWRITE(", gc = "); GWRITE(c); 
                SWRITE("."); BLINES(0) END;
             UNTIL (Z = SCHLUSS) OR (Z = schluss);
(*3*) END REP;


PROCEDURE REPdebug;
(*Read, Eval, Print - loop for debuging only *)
VAR   Y, Z, f: LIST;
BEGIN 
(*1*) (*communicate via terminal*) 
      f:=SOUNIT("CON:debugO"); 
      f:=SIUNIT("CON:debugI"); 
(*2*) (*actual loop*) 
      LOOP SWRITE("DEBUG: "); 
           Y:=UREAD(); 
           Z:=EVALUATE(Y,ENV); BLINES(0);  
           SWRITE("**ANS: "); 
           UWRITE(Z); BLINES(1); 
           IF (Z = SCHLUSS) OR (Z = schluss) THEN EXIT END;
           END;
(*3*) (*resume communication*) 
      f:=CUNIT("CON:debugO"); 
      f:=CUNIT("CON:debugI"); 
(*4*) END REPdebug;


(* Execution part. *)
BEGIN

BLINES(1);
(*
BLINES(1);    SWRITE(banner); BLINES(1); 
SWRITE(copyright0); BLINES(0); 
SWRITE(copyrightc); SWRITE(copyright1); BLINES(0); 
SWRITE(copyrightc); SWRITE(copyright2);  
                    SWRITE(copyright3); BLINES(1); 
                    SWRITE(public); BLINES(1); 
*)

DebugProcessor:=REPdebug; (* install debug aid *)

INTERPRETE;
 
CloseBIOS;

(*StorSummary;*)

END MAS.



(* -EOF- *)
