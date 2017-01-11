(* ----------------------------------------------------------------------------
 * $Id: MASSTOR.mip,v 1.6 1996/06/08 18:26:52 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSTOR.mip,v $
 * Revision 1.6  1996/06/08 18:26:52  pesch
 * Removed unused code, minor corrections.
 *
 * Revision 1.5  1995/11/04 20:40:03  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.4  1995/10/13 16:02:13  pesch
 * Fixed error: sigsetmask() at wrong places caused SIGUSR1 to be blocked
 *              permanently.
 *
 * Revision 1.3  1995/09/12  17:51:53  pesch
 * Changed mpsignal to massignal.
 *
 * Revision 1.2  1995/03/24  15:36:13  pesch
 * Changed inital message.
 *
 * Revision 1.1  1995/03/06  16:23:42  pesch
 * Replaced MASSTOR.mi by MASSTOR.mip.
 * Modified to work with new reuse library, too.
 * Modified procedure CLOCK.
 * Modified procedure GC to be more portable. Constant stackoff
 * is no longer needed (but local variables of GC are still not considered
 * during garbage collection). GC will now probably work independent of
 * direction of stack growth.
 *
 * Revision 1.9  1994/04/14  16:47:56  dolzmann
 * Syntactical errors (founded by Mocka) corrected.
 *
 * Revision 1.8  1994/04/12  13:23:14  pesch
 * Added comment to earlier revision (CLOCK has been modified).
 *
 * Revision 1.7  1994/03/30  11:34:59  pesch
 * Renamed SIGMASK to SigMask. SIGMASK was already defined in AIX signal.h.
 *
 * Revision 1.6  1994/03/11  16:04:23  pesch
 * Added support for SIGUSR1 as a method to get information about
 * the status of a running program.
 * Modified CLOCK to return only user-time (not user+system) in ms (not cs).
 *
 * Revision 1.5  1993/07/21  12:32:11  kredel
 * Fix for HP port
 *
 * Revision 1.4  1992/10/16  13:47:55  kredel
 * Errors found by Mocka
 *
 * Revision 1.3  1992/10/15  16:24:59  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:57  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:40  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSTOR;

(* MAS Storage Implementation Module. *)


(* Import lists and Definitions *) 

FROM clock	IMPORT	ClocK;

FROM MASCONF	IMPORT	KBCell; 

FROM MASELEM	IMPORT	GAMMAINT, MASEXP, MASMAX, MASODD;

FROM MASERR	IMPORT	DebugProcessor, ERROR, ErrorHandler, confusion,
			fatal, harmless, severe, spotless;

FROM MASmtc	IMPORT	getstck, gettoc;

FROM massig	IMPORT	SIGUSR1, SigMask, sigblock, signal, sigsetmask;

FROM StdIO	IMPORT	ReadC, ReadI, WriteC, WriteFlush, WriteI, WriteN,
			WriteNl, WriteS;

FROM Strings	IMPORT	ArrayToString, Concatenate, IntToString,
			StringToArray, tString;

FROM SYSTEM	IMPORT	ADDRESS, ADR, BYTE, TSIZE;

FROM Times	IMPORT	CpuTime;

#ifdef OLD_MTC
FROM SysCalls	IMPORT	Alloc;
#else
FROM System	IMPORT	SysAlloc;
#endif


CONST maxerr   = 20;        (* maximal number of errors allowed *)

      blocklen = 12*1024;   (* not to small, but less than 64 K *)
  
      proclen  = 12*1024;   (* stack size, do not know how much is necessary *)

      sysres   = 160*1024;  (* reserved for system > 16K + editor *)

      tomax    = 10;        (* allow 10 GC retries before halt *)
 
      rhomin   = 500;       (* some free space must be provided *) 

      stackOK  = 1024;      (* stack must have some rest to continue *) 

CONST rcsidi = "$Id: MASSTOR.mip,v 1.6 1996/06/08 18:26:52 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1995 Universitaet Passau";


TYPE ADDRLW = POINTER TO LONGCARD;

     P1 = PROCEDURE(GAMMAINT);
     PS = PROCEDURE(ARRAY OF CHAR);


VAR
    (*The cell fields FIRST and RED are implemented as follows

    FIRST(I) = LIST((SPACE-BETA1)+I)$^$)
    RED(I)   = LIST((SPACE-BETA)+I)$^$)
    *)

    Csize, Lsize: GAMMAINT; (* sizes of cells and lists *)

    BETA2, NUP: GAMMAINT;

    AVAIL, Globalvars: LIST;

    SPACEB, SPACEB1: GAMMAINT;

    toview, eh, marks: GAMMAINT;

    SPACE, SPACEEND,

    STACK, STACKEND, Tstack: ADDRESS;


(*$S-  No stack check *)
PROCEDURE FIRST(L: LIST): LIST;
(*First.  L is a non-null list.  a is the first element of L. *)
VAR   s: ADDRLW;
BEGIN
(*1*) (*DEBUG*)  
#ifndef NO_FIRST_ADDRESS_CHECK
      IF (L < BETA) OR (BETA2 <= L) THEN WL; WI(L); 
         ERROR(severe,"FIRST address out of range, value = ");
         RETURN(0);
         END;
#endif 
      (*GUBED*)
(*2*) s:=ADDRESS(SPACEB1+L); RETURN(LIST(s^));
(*4*) END FIRST;


PROCEDURE RED(L: LIST): LIST;
(*Reductum.  L is a non-null list.  Returns the reductum of L. *)
VAR   s: ADDRLW;
BEGIN
(*1*) (*DEBUG*)   
#ifndef NO_RED_ADDRESS_CHECK
      IF (L < BETA) OR (BETA2 <= L) THEN WL; WI(L);
         ERROR(severe,"RED address out of range, value = ");
         RETURN(SIL);
         END;
      (*GUBED*)
#endif
(*2*) s:=ADDRESS(SPACEB+L); RETURN(LIST(s^));
(*4*) END RED;


PROCEDURE SFIRST(L,a: LIST);
(*Set first.  L is a non-null list.  a is an object.  The first
element of L is changed to a. *)
VAR   s: ADDRLW;
BEGIN
(*1*) (*DEBUG*)   
#ifndef NO_SFIRST_ADDRESS_CHECK
      IF (L < BETA) OR (BETA2 <= L) THEN WL; WI(L);
         ERROR(severe,"SFIRST address out of range, value = ");
         RETURN;
         END;
      (*GUBED*)   
#endif
(*2*) (*DEBUG     *)
#ifdef SFIRST_CONTENTS_ADDRESS_CHECK
      IF (a < -BETA) OR (BETA2 <= a) THEN WL; WI(a);  
	 ERROR(severe,"SFIRST contents out of range, value = ");
         RETURN;
         END;
      (*GUBED*)
#endif
(*3*) s:=ADDRESS(SPACEB1+L); 
      s^:=LONGCARD(a); RETURN;
(*4*) END SFIRST;


PROCEDURE SRED(L,LP: LIST);
(*Set reductum.  L is a non-null list.  LP is a list.  The reductum
of L is changed to LP. *)
VAR   s: ADDRLW;
BEGIN
#ifdef SRED_ADDRESS_CHECK
(*1*) (*DEBUG*)   
      IF (L < BETA) OR (BETA2 <= L) THEN WL; WI(L);
         ERROR(severe,"SRED address out of range, value = ");
         RETURN;
         END;
      (*GUBED*)   
#endif
(*3*) s:=ADDRESS(SPACEB+L);
      s^:=LONGCARD(LP); RETURN;
(*4*) END SRED;

(*$S+  Stack check on *)

PROCEDURE ADV(L: LIST; VAR a,LP: LIST);
(*Advance.  L is a non-null list.  a=FIRST(L) and LP=RED(L). *)
BEGIN
(*1*) a:=FIRST(L); LP:=RED(L); RETURN;
(*4*) END ADV;


PROCEDURE ALLOCATESPACE(VAR S: ADDRESS; VAR AMNT: LONGINT); 
(*Allocate Space for list processing.
S is the address, where the allocated space starts.
AMNT is the desired number of bytes to be allocated, on return this
parameter shows, how much space was actually allocated. 
The intention of this procedure is to reflect the allocation 
algorithms of the different Modula-2 run time packages. *)
VAR   p2, d, amnt: LONGCARD;
      a,i: CARDINAL;
      SP: ADDRESS;
      t: BOOLEAN;
BEGIN
(*1*) (*Initialize. *) amnt:=0; 
      IF AMNT > 0 THEN amnt:=LONGCARD(AMNT) END; 
      p2:=blocklen;   
      d:=(amnt DIV p2)+1; (*ceiling*) 
      amnt:=d*p2; (*d = number of blocks*) 
(*
(*2*) (*Find maximal available Heap. *)
      WHILE (amnt >= p2) AND (NOT CreateHeap(amnt,TRUE)) DO
            amnt:=amnt-p2; (*may be slow ?*)
            END;  
      (*leave some space for system!!!!!*)
      amnt:=amnt-sysres;
      t:=CreateHeap(amnt,TRUE);
*)
(*3*) (*Allocate maximal chunk. *)
      (* WS("Alloc, amnt "); WI(GAMMAINT(amnt)); WL; *)
#ifdef OLD_MTC
      S:=Alloc(amnt); (*base address and length*)
#else
      S:=SysAlloc(amnt); (*base address and length*)
#endif
      (* WS("Alloc, S    "); WI(GAMMAINT(S)); WL; *)
      AMNT:=LONGINT(amnt);
(*4*) END ALLOCATESPACE;


PROCEDURE CELLS(): GAMMAINT;
(*Cells. Returns the used cells since storage initialization. *)
VAR   a,c: GAMMAINT;
BEGIN
(*1*) (*Add currently used cells to previously used cells. *)
      a:=NU-LENGTH(AVAIL);  
      c:=GCCC+a; RETURN(c);
(*2*) END CELLS;


PROCEDURE CLOCK(): GAMMAINT;
(*Clock. Returns the current CPU clock reading in milliseconds. 
Intervalls are system dependent. *)
BEGIN
     RETURN(GAMMAINT(ClocK()));
END CLOCK;


PROCEDURE COMP(a,L: LIST): LIST;
(*Composition.  a is an object.  L is a list.  Returns the 
composition of a and L. *)
VAR   M: LIST;
      m: INTEGER;
BEGIN
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1 *)
(*1*) (*Is AVAIL empty? *) IF AVAIL = SIL THEN GC() END;
(*2*) (*Get new cell. *) M:=AVAIL; AVAIL:=RED(M);
(*3*) (*Store a and L. *) SFIRST(M,a); SRED(M,L);
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN(M);
(*6*) END COMP;


PROCEDURE DEQUE(L: LIST): LIST;
(*Dequeue.  L is a non empty queue representing list.  Returns a, the 
first object from the queue. L is updated. *)
VAR   a, M, MP: LIST;
BEGIN
(*1*) (*Get a. *) M:=RED(L); ADV(M,a,MP);
(*2*) (*Update L. *) IF MP = SIL THEN SFIRST(L,L) END;
      SRED(L,MP); 
      RETURN(a);
(*3*) END DEQUE;


PROCEDURE ENQUE(a,L: LIST);
(*Enqueue.  a is an object.  L is a queue representing list. Appends a
to the quque L. *)
VAR   M, MP: LIST;
BEGIN
(*1*) (*Compose tail. *) M:=COMP(a,SIL); 
(*3*) (*Update queue. *) MP:=FIRST(L); 
      SRED(MP,M); SFIRST(L,M);
(*4*) END ENQUE;


PROCEDURE NEWQUE(): LIST;
(*New Queue.  Returns a new empty queue. *)
VAR   M: LIST;
BEGIN
(*1*) (*Compose anchor. *) M:=COMP(0,SIL); 
(*2*) (*Set pointer to last. *) SFIRST(M,M);
      RETURN(M);
(*4*) END NEWQUE;


PROCEDURE EMPTYQUE(M: LIST): BOOLEAN;
(*Empty Queue.  Tests if a queue is empty. *)
VAR   t: BOOLEAN;
BEGIN
(*1*) (*Test reductum of anchor. *) t:=( RED(M) = SIL ); 
      RETURN(t);
(*4*) END EMPTYQUE;


PROCEDURE GETLONGINT(A: LONGINT): LONGINT;
(*GET A LONG INTEGER FROM SPECIFIED ADDRESS. REGARDELESS
IF ADDRESS IS ON A WORD BOUNDARY. *) 
VAR    AL: LONGINT;
       XP, YP: POINTER TO BYTE;
       EINZ: ADDRESS;
BEGIN
(*1*) (*Initialize*)  
      XP:=ADR(AL); YP:=ADDRESS(A); EINZ:=ADDRESS(1); 
(*2*) (*Copy bytes*)
      (*OVERLAY WITH VARIABLE ALLIGNED ON CORRECT BOUNDARY*) 
      XP^:=YP^; (*1. BYTE*) 
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*2. BYTE*)
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*3. BYTE*)
      XP:=ADDRESS(XP)+EINZ; YP:=ADDRESS(YP)+EINZ;
      XP^:=YP^; (*4. BYTE*)
(*3*) (*Finish.*) RETURN(AL);
(*4*)  END GETLONGINT;


PROCEDURE GC();
(*Garbage collection.  All list cells accessible from stack are marked.
Then a new available cell list is formed from the unmarked cells and
the marks are removed.  If gcm=1 a report is written on ounit.  If the
number of reclaimed cells is no more than nu/rho then a message is
written on munit and a stop occurs. *)
VAR   CSTACK, BS, ES: GAMMAINT;
      a, I, J, K, L, LP, T, N, T1, I1, I2, I3: LIST;
      m: INTEGER; 
      (* CSTACK must be first, m last variable in declaration,
         to get correct stack position *)
BEGIN
(*1*) (*Initialize and information. *) T1:=CLOCK();
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1 during gc *)
      IF GCM = 1 THEN 
         ERROR(spotless,"Garbage collection ...");  
	 (*TEST   SysInfo;  Consistence;   TEST*)
         END;
(*      CSTACK:=GAMMAINT(getstck())+stackoff;  *)
      BS:=SIL; ES:=SIL; AVAIL:=SIL; marks:=0;
(*2*) (*Mark cells accessible from Globalvars list. *)
      LP:=Globalvars;
      WHILE LP <> SIL DO ADV(LP,I,LP);
	    a:=GETLONGINT(I); MARK(a); END;
      LP:=Globalvars;
      IF LP <> SIL THEN MARK(LP) END; (* Mark itself. *)
(*4*) (*Mark cells accessible from global variables. *)
(*      I1:=GAMMAINT(BasePageAddress^.BssBase);
      I3:=I1+GAMMAINT(BasePageAddress^.BssLen);
      MARKRANGE(I1,I3); 
*)
(*5*) (*Mark cells accessible from current stack, last mark ! *)
      IF ADR(CSTACK) < STACKEND
        THEN (* Stack grows to smaller adresses *)
            IF ADR(CSTACK) > ADR(m) THEN CSTACK := GAMMAINT(ADR(CSTACK))+4;
	                            ELSE CSTACK := GAMMAINT(ADR(m))+4;
     	    END;
      	    MARKRANGE(CSTACK,GAMMAINT(STACKEND));
        ELSE (* Stack grows to greater adresses *)
            IF ADR(CSTACK) < ADR(m) THEN CSTACK := GAMMAINT(ADR(CSTACK))-4;
	                            ELSE CSTACK := GAMMAINT(ADR(m))-4;
            END;
      	    MARKRANGE(GAMMAINT(STACKEND),CSTACK);
      END;
(*6*) (*Reclaim unmarked cells.*) N:=0; 
      I:=NUP-Csize; K:=Csize; 
      WHILE I >= K DO
            J:=BETA+I; LP:=RED(J); 
            IF LP > 0 THEN SRED(J,AVAIL); AVAIL:=J; 
			   (*DEBUG*) SFIRST(J,0); (*GUBED*)
                           N:=N+1; 
                      ELSE SRED(J,-LP) END;
            I:=I-Csize;
            END;
(*7*) (*Increment counters.*)  
      T:=CLOCK()-T1; TAU:=TAU+T;
      GCC:=GCC+1; GCCC:=GCCC+N;
(*8*) (*Optional report.*)
      (*TEST
        WS("end of Reclaim."); WL; Consistence;
        TEST*) 
      IF GCM = 1 THEN 
         WS(" "); WI(N); WS(" cells, ");
         WI(T); WS(" milliseconds.");   
         (*Escape;*)
         ERROR(spotless,"... GC completed.");
         END;
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) (*Stop ? *)
      IF N > (NU DIV RHO) THEN 
         toview:=0; RETURN END;
      toview:=toview+1;
      IF (toview > tomax) OR (N < rhomin) 
         THEN ERROR(confusion,"Garbage Collection: No free cells reclaimed.");
         ELSE ERROR(fatal,"Garbage Collection: Too few cells reclaimed.");
              END;
(*0*) END GC;


PROCEDURE InitSTOR(n: GAMMAINT);
(*Initialize storage system. n is the number of requested kilo bytes. *)
VAR  i, j, k: GAMMAINT;
     s, s1: tString;
     sa: ARRAY[0..50] OF CHAR;
BEGIN
(*2*) (*Set parameters and message. *)
      RHO:=10; TAU:=0; GCC:=0; GCCC:=0; GCM:=1;
      (* WS("InitSTOR, n= "); WI(n); WL; *)
      IF GCM = 1 THEN 
     	 IntToString(n,s);
     	 ArrayToString("Storage initalization (",s1);
     	 Concatenate(s1,s);
     	 ArrayToString(" kB) ...",s);
     	 Concatenate(s1,s);
     	 StringToArray(s1,sa);
         ERROR(spotless,sa);  
         END;
      Lsize:=TSIZE(LIST); Csize:=2*Lsize;
      BETA:=MASEXP(2,29); BETA1:=BETA-Lsize; SIL:=BETA;
      TAU0:=CLOCK(); 
      toview:=0;
(*3*) (*Allocate space for cells and processes. *) 
      n:=n*1024; NU:=n DIV Csize; NUP:=NU*Csize; 
      ALLOCATESPACE(SPACE,NUP);
      IF SPACE = NIL THEN AVAIL:=BETA;
	 ERROR(confusion,"No Storage Available.");
	 RETURN END;
(*5*) (*Initialize range pointers. *)
      SPACEEND:=SPACE+ADDRESS(NUP);
      NU:=NUP DIV Csize;
      IF NU <= 0 THEN AVAIL:=BETA; 
         ERROR(confusion,"No Storage Available.");  
         RETURN END;
      BETA2:=BETA+NUP; 
      SPACEB:=GAMMAINT(SPACE)-BETA;
      SPACEB1:=GAMMAINT(SPACE)-BETA1;
(*6*) (*Create available cell list. *)  
      AVAIL:=BETA+Csize;
      i:=Csize; k:=NUP-Csize; 
      WHILE i <= k DO
            j:=BETA+i; 
            SRED(j,j+Csize); 
	    (*DEBUG*)  SFIRST(j,0);  (*GUBED*)
            i:=i+Csize; END;
      SRED(j,SIL);
(*7*) (*Initialize process work list to current stack. *)  
      Globalvars:=SIL; 
      Tstack:=STACKEND-proclen;
      Tstack:=Tstack+stackOK;
(*8*) (*TEST  
      WS("Module MASSTOR initialized."); WL;
      SysInfo; 
        TEST*)
      IF GCM = 1 THEN  
         ERROR(spotless,"... completed.");
         END;
(*8*) END InitSTOR;


PROCEDURE Consistence;
(*Check consistency of cell space. *)
VAR   n, I, J, K, L, LP: LIST;
BEGIN 
(*1*) (* initialize *) n:=0;
      WL; WS("Cell consistence check ..."); WL;
      I:=NUP-Csize; K:=Csize; 
(*2*) (* consistency check *)
      WHILE I >= K DO
            J:=BETA+I; LP:=RED(J); L:=FIRST(J); 
            IF (LP < BETA) OR (BETA2 <= LP) THEN n:=n+1;
               WS("invalid reductum at "); WI(J); 
               WS(" contents "); WI(L); WS(" "); WI(LP); WL; 
               END;
            IF (L < -BETA) OR (BETA2 <= L) THEN n:=n+1;
               WS("invalid first at "); WI(J); 
               WS(" contents "); WI(L); WS(" "); WI(LP); WL; 
               END;
            I:=I-Csize;
            END;
(*3*) (* message *) WI(n); WS(" invalid value(s)."); WL;
(*7*) END Consistence;


PROCEDURE INV(L: LIST): LIST;
(*Inverse.  L is a list.  The inverse of L is returned.  The list L is
modified. *)
VAR   M, MP, MPP: LIST;
BEGIN
(*1*) M:=BETA; MP:=L;
      WHILE MP <> SIL DO MPP:=RED(MP); SRED(MP,M); M:=MP; MP:=MPP;
            END;
      RETURN(M);
(*4*) END INV;


PROCEDURE LENGTH(L: LIST): GAMMAINT;
(*Length.  L is a list.  Returns length(L). *)
VAR   LP: LIST;
      n: GAMMAINT;
BEGIN
(*1*) n:=0; LP:=L;
      WHILE LP > SIL DO LP:=RED(LP); n:=n+1; END;
      RETURN(n);
(*4*) END LENGTH;


PROCEDURE LIST1(a: LIST): LIST;
(*List, 1 element.  a is an object.  L is the list (a). *)
VAR   L: LIST;
BEGIN
(*1*) L:=COMP(a,SIL); RETURN(L);
(*4*) END LIST1;


PROCEDURE LISTVAR(VAR L: LIST);
(*List variable.  L is a list.  The address of L is made accessible
to the garbage collector. *)
VAR   s: GAMMAINT;
BEGIN
(*1*) s:=GAMMAINT(ADR(L)); Globalvars:=COMP(s,Globalvars); 
(*2*) END LISTVAR;


PROCEDURE MARK(L: LIST);
(*Mark.  L is a non-null list such that every cell of L which is
accessible from an already marked cell of L is itself already marked.
Mark marks every unmarked cell of L. *)
VAR   AL, LP, LS: LIST;
BEGIN
(*1*) (*check if in range. *) 
      IF (L <= BETA) OR (BETA2 <= L) 
         OR ((L MOD Csize) <> 0) THEN RETURN END;   
(*2*) (*probably a list pointer. *) LP:=L;
      (*TEST
      WS("MARK = "); WH(L); WS(". ");
	TEST*)
      WHILE LP <> SIL DO LS:=RED(LP); 
            IF (LS < BETA) OR (BETA2 <= LS) THEN RETURN; END;
            (*IF LS < 0 THEN RETURN; END;*)
	    SRED(LP,-LS); AL:=FIRST(LP);
	    (*TEST   marks:=marks+1;   TEST*)
            MARK(AL); LP:=LS; END;
(*4*) END MARK;


PROCEDURE MARKRANGE(B, E: LIST);
(*Mark range.  Mark all lists in range from B to E. *)
VAR   I, E1, a: LIST;
BEGIN
(*1*) (*initialize. *) I:=B; E1:=E-Lsize;
      (*TEST  
      WS("marking in range "); WI(I);
      WS(" to "); WI(E1); WL;
        TEST*)
(*2*) (*mark any lists. *) 
      WHILE I <= E1 DO a:=GETLONGINT(I);
	    (* IF (a > BETA) AND (BETA2 > a)
	       AND ((a MOD Csize) = 0) THEN
	       WS("I, a = "); WH(I); WS(",  "); WH(a);
	       (*WS(", len "); WI(LENGTH(a));*) WL; END; *)
	    MARK(a);
            (* Must step by 1 because of CHARs and BYTes. *)
            I:=I+1; END;
      (*TEST  
      WS("marks = "); WI(marks); WS(" end of mark range."); WL;
        TEST*)
(*4*) END MARKRANGE;


PROCEDURE DumpStack;
(*Dump Stack.  Dump objects on current stack. *)
VAR   I, E, a: LIST;
      c: CHAR;
BEGIN
(*1*) (*initialize. *) 
      I:=GAMMAINT(getstck()); E:=I+1000;
      WL; WS("Stack Dump: "); WL;
(*2*) (*dump objects. *) 
      WHILE I <= E DO a:=GETLONGINT(I); 
            WI(I); WS(" = "); DumpObj(a); 
            WL; WS("(e)nd, <ENTER> ? ");
            c:=InChar();
            IF (c = 'e') OR (c = 'E') THEN RETURN END; 
            (* Must step by 1 because of CHARs and BYTes. *)
            I:=I+1; END;
(*4*) END DumpStack;


PROCEDURE DumpObj(L: LIST);
(*Dump Object.  The object L is dumped. *)
VAR   AL, LP, LS, i: LIST;
BEGIN
(*1*) (*check if atom or in range to be list. *) 
      IF (L <= BETA) OR (BETA2 <= L) 
         THEN WI(L); RETURN END;   
      IF ((L MOD Csize) <> 0) THEN WI(L); RETURN END;   
(*2*) (*probably a list pointer. *) LP:=L; i:=0;
      WS("(");
      WHILE LP <> SIL DO LS:=RED(LP); 
            IF (LS < BETA) OR (BETA2 <= LS) THEN 
               RETURN; END;
            (*IF LS < 0 THEN RETURN; END;*)
            AL:=FIRST(LP);
            i:=i+1; IF i >= 5 THEN i:=0; WL END; 
            DumpObj(AL);
            IF LS <> SIL THEN WS(", ") END;
            LP:=LS; END;
      WS(")"); 
(*4*) END DumpObj;


PROCEDURE SUBLIST(A,B: LIST): BOOLEAN;
(*Sub-list, check if A is equal to some reductum of B.
Returns TRUE, if the test is true, else FALSE. *)
VAR   BP: LIST;
      t: BOOLEAN;
BEGIN
(*1*) (*Initialize*) BP:=B; t:=FALSE;
      WHILE BP <> SIL DO
            IF A = BP THEN t:=TRUE; RETURN(t); END;
            BP:=RED(BP);
            END;
(*2*) (*Finish.*) RETURN(t);
(*3*) END SUBLIST;


PROCEDURE TIME(): GAMMAINT;
(*Time. Returns the CLOCK minus the garbage collection time TAU.  
Intervalls are system dependent. *)
VAR   T: GAMMAINT;
BEGIN
(*1*) T:=CLOCK(); T:=T-TAU;
      RETURN(T); 
(*2*) END TIME;


(* Test procedures *)

PROCEDURE SysInfo;
(*System Information. *)
VAR   a, b, bp, i, c: GAMMAINT;
BEGIN
(*1*) (*general info. *)
      WI(NU); WS(" CELLS IN SPACE."); WL;
      WS("NUMBER OF BYTES ALLOCATED = "); WH(NUP); WL;
      WS("ADDRESS OF ALLOCATED AREA = "); 
      WH(GAMMAINT(SPACE)); WL;
      WS("BETA         = "); WH(BETA); WL;
      WS("BETA2        = "); WH(BETA2); WL;
(*
(*2*) (*global data info. *)
      b:=GAMMAINT(BasePageAddress^.BssBase); 
      bp:=GAMMAINT(ADDRESS(b)+ADDRESS(BasePageAddress^.BssLen));
      WS("BSS START    = "); WI(b); WL;
      WS("BSS END      = "); WI(bp); WL; 
*)
(*3*) (*storage info. *)
      WS("SPACE BEGIN  = "); WH(GAMMAINT(SPACE)); WL;
      WS("SPACE END    = "); WH(GAMMAINT(SPACEEND)); WL;
(*4*) (*stack info. *)
      STACK:=ADDRESS(getstck());
      WS("STACK END    = "); WH(GAMMAINT(STACKEND)); WL;
      WS("STACK A1     = "); WH(GAMMAINT(STACK)); WL;
(*5*) (*register info. *)
      a:=GAMMAINT(gettoc());
      WS("TOC   A2     = "); WH(a); WL;
(*7*) END SysInfo;


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


(*TEST  

PROCEDURE Summary();
(*MASSTOR Summary. *) 
VAR   L, ML, NL, TL: LIST;
      c: INTEGER;
BEGIN
(*1*) WL;
(*2*) ML:=GCC; NL:=GCCC; TL:=TAU;  
      WI(ML); WS(" garbage collections, ");
      WI(NL); WS(" cells reclaimed, in ");
      WI(TL); WS(" milliseconds.");
      WL; 
(*3*) NL:=CELLS(); TL:=TIME()-TAU0;
      WI(NL); WS(" cells used, in ");
      WI(TL); WS(" milliseconds.");
      WL; 
(*4*) TL:=CLOCK()-TAU0;
      WI(NU); WS(" cells allocated. ");
      WS("Total time ");
      WI(TL); WS(" milliseconds.");
      WL;
(*5*) END Summary;


PROCEDURE TestSTOR();
(*Test Storage. *) 
VAR   L: LIST;
      i, a, b: GAMMAINT;
BEGIN
(*1*) L:=SIL; b:=NU-1000;
      FOR i:=1 TO b DO L:=COMP(i,L); END; 
      IF LENGTH(L) <> b THEN
         WS("Error in MASSTOR."); WL;
         END;
      i:=b; 
      WHILE L <> SIL DO ADV(L,a,L);
            IF i <> a THEN
               WS("Error in MASSTOR."); WL;
	       WI(i); WS(" "); WI(a); WS(" "); WI(L); WL;
               END;
            i:=i-1; END;
      WS("Test 1 in MASSTOR ended."); WL;         
(*2*) L:=SIL; 
      FOR i:=1 TO b DO L:=COMP(i,L); END; 
      i:=b; 
      WHILE L <> SIL DO ADV(L,a,L);
            IF i <> a THEN
               WS("Error in MASSTOR."); WL;
	       WI(i); WS(" "); WI(a); WS(" "); WI(L); WL;
               END;
            i:=i-1; END;
      WS("Test 2 in MASSTOR ended."); WL;         
(*4*) END TestSTOR;

  TEST*)



(* MASSTOR module initialization.  *)

PROCEDURE SetSTACKEND();
(* Set STACKEND. The global variable STACKEND is set.*)
VAR s: ADDRESS;
BEGIN
     s:=ADR(s); STACKEND:=s
END SetSTACKEND;

BEGIN
(*1*)(* STACKEND:=getstck();*) (*remember stack address*)
      SetSTACKEND;
(*2*) InitSTOR(KBCell);
(*4*) (*TEST  
      eh:=ErrorHandler(TestSTOR);
      WS("nach error handler 1"); WL;
      SysInfo;
      eh:=ErrorHandler(TestSTOR);
      WS("nach error handler 2"); WL;
      SysInfo; Summary;
        TEST*)
END MASSTOR.

(* -EOF- *)
