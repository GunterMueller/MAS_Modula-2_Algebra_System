(* ----------------------------------------------------------------------------
 * $Id: MASERR.mi,v 1.9 1995/11/05 08:50:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASERR.mi,v $
 * Revision 1.9  1995/11/05 08:50:56  kredel
 * Added return value for runtime.
 *
 * Revision 1.8  1995/11/04  20:40:00  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.7  1995/09/12  17:22:49  pesch
 * Signal handling function are now declared in massignal.
 * Action has been changed according to ANSI C.
 * signal.* and massignal.* have been removed, the former because of
 * name clash with signal.h.
 *
 * Revision 1.6  1995/03/23  17:43:57  pesch
 * Added new options -E (exit on error) and -c (command).
 *
 * Revision 1.5  1993/03/22  10:22:33  kredel
 * Make CONTROL-C, SIGINT work
 *
 * Revision 1.4  1992/10/16  13:47:54  kredel
 * Errors found by Mocka
 *
 * Revision 1.3  1992/10/15  16:24:58  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:38  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASERR;

(* MAS Error Implementation Module. *)


(* Import lists and Definitions *) 

FROM SYSTEM	IMPORT	ADDRESS, ADR, BYTE;

FROM MASmtc	IMPORT	getstck, gettoc;

FROM setjmp	IMPORT	jmp_buf, jmp_buf, longjmp, setjmp;

FROM massig	IMPORT	Action, SIGBUS, SIGFPE, SIGILL, SIGINT, SIGSEGV,
			SIGTERM, SIG_ACK, SIG_ACK, SIG_ACK, SIG_ACK, SIG_DFL,
			SIG_DFL, SIG_DFL, SIG_DFL, SIG_ERR, SIG_ERR, SIG_ERR,
			SIG_ERR, SIG_IGN, SIG_IGN, SIG_IGN, SIG_IGN, raise,
			signal;  

FROM StdIO	IMPORT	ReadC, ReadI, WriteC, WriteFlush, WriteI, WriteN,
			WriteNl, WriteS;

FROM MASELEM	IMPORT	GAMMAINT, MASEXP, MASMAX, MASODD;

FROM MASCONF	IMPORT	ExitOnError;

(*
(* error indicators *)
CONST spotless  = 0;
      harmless  = 1;
      severe    = 2;
      fatal     = 3;
      confusion = 9;
TYPE P0 = PROCEDURE;
VAR DebugProcessor: P0; (* procedure called by ERROR if debug requested *)
    history: GAMMAINT; (* highest error level encountered so far. *)
*)

CONST rcsidi = "$Id: MASERR.mi,v 1.9 1995/11/05 08:50:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

CONST maxerr   = 20;        (* maximal number of errors allowed *)

TYPE
     P1 = PROCEDURE(GAMMAINT);
     PS = PROCEDURE(ARRAY OF CHAR);

VAR elevel:  GAMMAINT;
    fehler:  GAMMAINT;
    schluss, errhup: BOOLEAN;

    errenv: jmp_buf;

    eh: GAMMAINT; 

    STACK, STACKEND: ADDRESS;

    lasterr: INTEGER;


PROCEDURE InitERR;
(*Initialize error handler. *)
BEGIN
(*1*) (*Set variables. *)
      elevel:=0; lasterr:=0; 
      STACKEND:=ADDRESS(0);
(*2*) (*procedures. *)
      schluss:=FALSE; errhup:=FALSE;
      DebugProcessor:=P0(NIL);
(*7*) END InitERR;


PROCEDURE DumpStack;
(*Dump Stack.  Dump objects on current stack. *)
VAR   I, E, a: GAMMAINT;
      c: CHAR;
BEGIN
(*1*) (*initialize. *) 
      I:=GAMMAINT(getstck()); E:=I+1000;
      WL; WS("Stack Dump: "); WL;
(*2*) (*dump objects. *) 
      WHILE I <= E DO a:=GETLONGINT(I);
	    WI(I); WS(" = "); WH(a); 
            WL; WS("(e)nd, <ENTER> ? ");
            c:=InChar();
            IF (c = 'e') OR (c = 'E') THEN RETURN END; 
            (* Must step by 1 because of CHARs and BYTes. *)
            I:=I+1; END;
(*4*) END DumpStack;


PROCEDURE GETLONGINT(A: LONGINT): LONGINT;
(*GET A LONG INTEGER FROM SPECIFIED ADDRESS. REGARDELESS
IF ADDRESS IS ON A WORD BOUNDARY. *) 
VAR   AL: LONGINT;
      XP, YP: POINTER TO BYTE;
      EINZ: ADDRESS;
BEGIN
(*1*) (*INITIALIZE*)  
      XP:=ADR(AL); YP:=ADDRESS(A); EINZ:=ADDRESS(1); 
(*2*) (*COPY BYTES*)
      (*OVERLAY WITH VARIABLE ALLIGNED ON CORRECT BOUNDARY*) 
      XP^:=YP^; (*1. BYTE*) 
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*2. BYTE*)
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*3. BYTE*)
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*4. BYTE*)
(*3*) (*FINISH.*) RETURN(AL);
END GETLONGINT;


PROCEDURE ERROR(a: GAMMAINT; s: ARRAY OF CHAR);
(*Error. An error of severity a and indication s is reported. *)
VAR   i: INTEGER;
      c: CHAR;
BEGIN
(*1*) (*initialize *) 
      IF a > history THEN history:=a END; 
      (*stack check
      IF getstck() < Tstack THEN a:=fatal;
	 WL; WS("** Stack underflow."); END; *)
      IF (a = spotless) AND (HIGH(s) < 5) THEN RETURN END;
      elevel:=elevel+1;
(*2*) (*report *) WL; WS("** "); 
      i:=INTEGER(a);
      CASE         i OF 
           spotless: |
           harmless: WS("error: ") |
           severe  : WS("severe error: ") |
           fatal   : WS("fatal error: ") 
                ELSE WS("("); WI(a); WS(") ") END; 
      WS(s); WS(" ");
      IF lasterr = SIGTERM THEN history:=confusion; longjmp(errenv,1) END; 
(*3*) (*interact *) 
      IF i > harmless THEN
     	 IF ExitOnError THEN a:=confusion;
	 ELSE
	     LOOP WL; WS("(a)bort, (b)reak, (c)ontinue, (d)ebug, <ENTER> ? ");
                  c:=InChar(); 
                     IF (c = 's') OR (c = 'S') THEN DumpStack
                  ELSIF (c = 'i') OR (c = 'I') THEN SysInfo
                  ELSIF (c = 'd') OR (c = 'D') THEN Debug
                   ELSE EXIT END;
                  END;
             CASE        c OF 
                  'a','A': WS("abort"); a:=confusion |
                  'b','B': WS("break"); a:=fatal |
                  'c','C': WS("continue"); a:=severe |
                      ELSE WS("system") (*use system decision*) END; 
             WS(". "); 
             END; 
      END;
      IF a > history THEN history:=a END; 
(*4*) (*history and error count *) 
      elevel:=elevel-1;
      (*avoid recursive errors*)
      IF elevel > 0 THEN history:=history+1 END;  
      IF history > spotless THEN fehler:=fehler+1 END;
      (*avoid to much errors*)
      IF fehler > maxerr THEN history:=history+1 END;
(*5*) (*continue ? *) 
      IF (spotless <= history) AND (history < fatal) THEN RETURN END;
      IF (spotless <= a) AND (a < fatal) THEN RETURN END;
      IF NOT errhup THEN HALT END;
      IF history > confusion THEN HALT END;
      longjmp(errenv,2);
(*6*) END ERROR;


PROCEDURE Debug;
(*call DebugProcessor if available. *)
BEGIN
(*1*) IF ADDRESS(DebugProcessor) = NIL THEN 
         WL; WS("No Debug Processor available."); WL;
         RETURN END;
(*2*) WL; WS("Entering Debug Processor ..."); WL;
      DebugProcessor;  
      WL; WS("... Debug Processor exited."); WL;
(*4*) END Debug;


PROCEDURE ErrorHandler(a: P0): GAMMAINT;
(*Error handler. Any error reported by the ERROR procedure is catched. *)
VAR   f, t: INTEGER;
      oldsig: Action;
BEGIN
(*1*) f:=0; 
      oldsig:=signal(SIGINT, runtime); 
      IF oldsig = SIG_ERR THEN 
         WL; WS("Cannot install runtime signal handler."); WL; 
         END;
   (* oldsig:=signal(SIGILL, runtime); 
      oldsig:=signal(SIGFPE, runtime); 
      oldsig:=signal(SIGBUS, runtime); 
      oldsig:=signal(SIGSEGV, runtime); 
      oldsig:=signal(SIGTERM, runtime); *)
(*2*) REPEAT f:=f+1;
             fehler:=0; history:=spotless;
	     t:=setjmp(errenv); errhup:=TRUE;
	     IF t = 0 THEN a(); schluss:=TRUE;
		      ELSE IF history >= confusion THEN schluss:=TRUE END 
                           END;
             IF NOT schluss AND (history > harmless) THEN 
                WL; WS("Trying to restart program ... "); WL;
                END;
             UNTIL schluss OR (f > maxerr);
(*3*) (*WL; WS("... done."); WL;*)
      oldsig:=signal(SIGINT, SIG_DFL); 
      errhup:=FALSE; 
      RETURN(history);
(*4*) END ErrorHandler;


PROCEDURE runtime(e: INTEGER): INTEGER;
(*Run time error handler for Unix. *)
VAR   s: ARRAY [0..100] OF CHAR;
      abort: BOOLEAN;
      err: GAMMAINT; 
      oldsig: Action; x:INTEGER;  
BEGIN
(*1*) abort:=TRUE; WL; lasterr:=e; err:=fatal;
      CASE e OF 
      SIGINT : s:=" Interrupt. "; abort:=FALSE; err:=severe |
(*unused*)
      SIGILL : s:=" Illegal Instruction. "; abort:=FALSE; err:=fatal |
      SIGFPE : s:=" Floating Point Error. "; abort:=FALSE; err:=fatal |
      SIGBUS : s:=" Bus Error. "; abort:=FALSE; err:=fatal |
     SIGSEGV : s:=" Segmentation Error. "; abort:=FALSE; err:=fatal |
     SIGTERM : s:=" Terminate. "; abort:=FALSE; err:=harmless |
          ELSE s:=" Unknown Error. "; abort:=TRUE; err:=fatal   
               END;
      WI(GAMMAINT(e)); WS(s); 
(*2*) IF abort THEN x:=raise(e); (*should not return*) HALT; END;
      oldsig:=signal(e, runtime); (*rs6000*)
      ERROR(err,"Signal received.");
      RETURN(0); 
(*4*) END runtime;


PROCEDURE WI(a: GAMMAINT);
(*Utility. *)
BEGIN
(*1*) WriteI(a,1); (*Dependes on MASELEM. *)
(*4*) END WI;


PROCEDURE WH(a: GAMMAINT);
(*Utility. *)
BEGIN
(*1*) WriteI(a,1); WriteS("  "); WriteN(a,1,16); (*Dependes on MASELEM. *)
(*4*) END WH;


PROCEDURE WS(s: ARRAY OF CHAR);
(*Utility. *)
BEGIN
(*1*) WriteS(s); WriteFlush;
(*9*) END WS;


PROCEDURE WL();
(*Utility. *)
BEGIN
(*1*) WriteNl; WriteFlush;
(*4*) END WL;


PROCEDURE InChar(): CHAR;
VAR   c: CHAR;
BEGIN
(*1*) c:=ReadC();
      IF ORD(c) <= 10 THEN c:=ReadC() END;
      RETURN(c); 
(*2*) END InChar;


PROCEDURE Escape;
VAR   c: CHAR;
BEGIN
(*1*) c:=ReadC();
      IF ORD(c) <= 10 THEN c:=ReadC(); END;
      IF ORD(c) = 27 THEN ERROR(severe,"ESC key pressed.") END;
(*2*) END Escape;


(* Test procedures *)

PROCEDURE SysInfo;
(*System Information. *)
VAR   a, b, bp, i, c: GAMMAINT;
BEGIN
(*4*) (*stack info. *)
      STACK:=getstck();
      WS("STACK END    = "); WH(GAMMAINT(STACKEND)); WL; 
      WS("STACK A1     = "); WH(GAMMAINT(STACK)); WL;
(*5*) (*register info. *)
      a:=GAMMAINT(gettoc());
      WS("      A2     = "); WH(a); WL;
(*7*) END SysInfo;


(*TEST  
PROCEDURE Hold;
VAR   c: CHAR;
BEGIN
(*1*) c:=ReadC();
      IF ORD(c) > 13 THEN Pause END;
(*2*) END Hold;


PROCEDURE Pause;
VAR   c: CHAR;
BEGIN
(*1*) REPEAT c:=ReadC();
       UNTIL ORD(c) > 0; 
(*2*) END Pause;


PROCEDURE TestERR;
(*Test error. *)
VAR   a,b: GAMMAINT;
BEGIN
(*1*) REPEAT WS("Eingabe 1: ");
	     b:=ReadI(); WL;
             IF b >= 0 THEN ERROR(b,"Fehler in testerr.") END;
             UNTIL b < 0;
(*2*) REPEAT WS("Eingabe 2: ");
	     b:=ReadI(); WL;
             IF b >= 0 THEN a:=1 DIV b END;
             UNTIL b < 0;
(*4*) END TestERR;
  TEST*)



(* MASSTOR module initialization.  *)

BEGIN
(*1*) STACKEND:=getstck(); (*remember stack address*)
(*2*) InitERR;
(*3*) (*TEST  
      eh:=ErrorHandler(TestERR);
      WS("nach error handler 1"); WL; 
      SysInfo;
      eh:=ErrorHandler(TestERR);
      WS("nach error handler 2"); WL; 
      SysInfo;
        TEST*)
END MASERR.

(* -EOF- *)
