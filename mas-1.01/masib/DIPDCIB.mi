(* ----------------------------------------------------------------------------
 * $Id: DIPDCIB.mi,v 1.1 1995/10/12 14:44:50 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDCIB.mi,v $
 * Revision 1.1  1995/10/12 14:44:50  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPDCIB;

(* DIP Decompositional Involutive Bases Implementation Module. *)


(* Import lists and declarations. *)
FROM ADEXTRA	IMPORT 	ADLGinH;

FROM DIPADOM 	IMPORT 	DILWR, DIPFAC, DIPSFF, DIWRIT;

FROM DIPC 	IMPORT	DIPTDG, DIPEVL, VALIS, DIPLPM;

FROM DIPCJ      IMPORT 	DIPPGL3, DILBBS, DIPSSM, DIPVL, DILBBS;

FROM DIPIB      IMPORT 	ADPNFJ, DILISJ, DIPIRLJ2;

FROM MASBIOS 	IMPORT 	SWRITE, BLINES;

FROM MASERR	IMPORT 	harmless, severe, ERROR;

FROM MASLISPU   IMPORT 	PROCF2;

FROM MASSTOR 	IMPORT 	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL,
			SFIRST, TIME;

FROM SACI	IMPORT 	IWRITE;

FROM SACLIST 	IMPORT 	EQUAL, SECOND, FIRST2, AWRITE, CINV,
			LIST2, LIST4,  LIST5, LWRITE, OWRITE, CONC, CCONC;

CONST rcsidi = "$Id: DIPDCIB.mi,v 1.1 1995/10/12 14:44:50 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";


VAR DCIBopt: RECORD
               TraceLevel: INTEGER;
               DecompProc: PROCF2;
               VarOrdOpt : INTEGER;
               depth    : INTEGER;
             END; 


PROCEDURE SetDCIBopt(options: LIST);
(* Set decompositional involutive base options.
   Input: a list of max. 4 options in the order: TraceLevel, DecomProc,
   VarOrd, Depth of tree. *)
VAR opt: INTEGER;
BEGIN
  IF options<>SIL THEN ADV(options, opt, options);
                        SetDCIBTraceLevel(opt);
     IF options<>SIL THEN ADV(options, opt, options);
                          SetDCIBDecomp(opt);
        IF options<> SIL THEN ADV(options, opt, options);
                              SetDCIBVarOrdOpt(opt);
           IF options<> SIL THEN ADV(options, opt, options);
                                 SetDCIBdepth(opt);
           END;
        END;
     END;
  END;
END SetDCIBopt;


PROCEDURE SetDCIBTraceLevel(TL: INTEGER);
(* Set decompositional involutive base Trace Level.
   TL is an integer with meaning:
   0: default, no output, 
  >0: output of time,
  >1: output of messages about tree of computation,
  >2: detailed messages about tree of computation. *)
BEGIN
  DCIBopt.TraceLevel:=TL;
END SetDCIBTraceLevel;


PROCEDURE SetDCIBDecomp(DCP: INTEGER);
(* Set decompositional involutive base decomposition.
   Set the procedure which is used for decomposition.
   1: complete factorisation
   2: squarefree decomposition  *)
BEGIN
  CASE DCP OF 
       1: DCIBopt.DecompProc:=DIPFAC; |
       2: DCIBopt.DecompProc:=DIPSFF;
       ELSE ERROR(harmless, "SetDecompProc: unknown Decomp option");
  END;
END SetDecomp;


PROCEDURE SetDCIBVarOrdOpt(VOO: INTEGER);
(* Set decompositional involutive base variable order option.
  VOO is an integer with meaning:
  0: do not optimize,
  1: optimize at factorization *)
BEGIN
  IF (VOO<0) OR (VOO>1) THEN 
             ERROR(harmless, "SetVarOrdOpt: unknown VarOrdOpt option"); ELSE
             DCIBopt.VarOrdOpt:=VOO; 
  END;
END SetDCIBVarOrdOpt;


PROCEDURE SetDCIBdepth(d: INTEGER);
(* Set decompositional involutive base depth of tree.
   Input: an integer with
   <0: unrestricted growth of tree
    0: no computation possible,
   >0: depth of tree is restricted through d *)
BEGIN
  IF d<0 THEN DCIBopt.depth:=-1;
         ELSE DCIBopt.depth:=d; END;
END SetDCIBdepth;


PROCEDURE InvolutiveBases(G, V: LIST): LIST; 
(* Distributive polynomials decompositional involutive bases.
   G is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a list (IB1,...,IBk) of involutive bases,
   where Z(G) = Z(IB1) v ... v Z(IBk). *)
VAR IBList,T,t,Fcmp,counter,VL,le,FNodes: LIST;
    nocb, depth, lc, eqn	: INTEGER;
    dummy, Factorisation	: BOOLEAN;

PROCEDURE RECIB1(G,Fcmp: LIST): LIST;
VAR H,g,HTg,HTf,G1,F,IBList,IBL,IBLFirst,f,B: LIST;
    c: INTEGER;
BEGIN
   H:=SIL; 
   WHILE G<>SIL DO 
      ADV(G,g,G);  
      IF DIPTDG(g)=0 THEN 
         IF DCIBopt.TraceLevel>1 THEN
            BLINES(0); SWRITE("** branch w.o. zeros "); nocb:=nocb+1; 
         END;
         RETURN(SIL); 
      END;
      G1:=CCONC(G,H); 
      F:=newFactors(G1,g,Fcmp,V);
      IF F=SIL THEN 
         IF DCIBopt.TraceLevel>1 THEN
            BLINES(0); SWRITE("** cancel branch"); nocb:=nocb+1;
         END;
         RETURN(SIL); 
      END;
      ADV(F,f,F);
      IF F=SIL THEN
         HTg:=DIPEVL(g); HTf:=DIPEVL(f);
         IF EQUAL(HTg,HTf)=1 THEN H:=COMP(f,H);	
                             ELSE DILISJ(COMP(f,G1),G,dummy); H:=SIL; END;
         ELSE
         IBList:=SIL; IBLFirst:=SIL; IncCounter(counter,lc,0); 
         LOOP (* 1 *)
            DILISJ(COMP(f,G1),G,dummy);
            IF DCIBopt.TraceLevel>2 THEN 
               IncCounter(counter,lc,1);
               BLINES(0); CounterWR(counter); 
               SWRITE(" Factor: "); DIWRIT(f,V); 
               BLINES(0); DILWR(G,V);
            END;
            IF depth<>lc THEN  
               IBList:=CONC(IBList,RECIB1(G,Fcmp));
            ELSE IF DCIBopt.TraceLevel>1 THEN BLINES(0);
                    SWRITE("** depth maximum reached; cancel branch"); 
                 END;
            END;
            IF F=SIL THEN EXIT; END;
            Fcmp:=COMP(f,Fcmp); 
            ADV(F,f,F);
         END; (* LOOP 1 *)
         DecCounter(counter, lc); RETURN(IBList);
      END; (* IF F... *) 
   END; (* WHILE G... *)
   RETURN(RECIB2(H,Fcmp));
END RECIB1;


PROCEDURE RECIB2(G, Fcmp: LIST): LIST;
VAR S,h,F,f,H,B,K,g,GG: LIST;
    red, reduced  : BOOLEAN;
BEGIN
   K:=SIL; red:=FALSE;
   (* if no factorisation occured then remove last inserted node from FNodes *)
   IF (FNodes<>SIL) AND NOT(Factorisation) THEN FNodes:=RED(FNodes); END;
   LOOP 
       IF G=SIL THEN EXIT END;
       DIPSSM(G,FALSE,g,G); K:=COMP(g,K); B:=DIPPGL3(g,VL,le); H:=SIL;
       WHILE B<>SIL DO
             ADV(B,S,B); ADPNFJ(CCONC(G,K),S,h,reduced); 
             IF h<>0 THEN red:=red OR reduced;
                          IF DIPTDG(h)=0 THEN RETURN(SIL); END;
                          H:=COMP(h,H); 
             END; 
       END; 
       IF H<>SIL THEN G:=CONC(H,G);
                      DIPIRLJ2(G,K,reduced); red:=red OR reduced;
                      IF DCIBopt.TraceLevel>2 THEN BLINES(0);CounterWR(counter);
                                          SWRITE(" Prolongation & Reduction"); 
                                          DILWR(CCONC(G,K),V); 
                      END;
                      IF depth<>lc THEN  
                               IF red THEN GG:=CCONC(G,K);
                                     IF NOT(ADLGinH(FNodes, GG)) THEN
                                        FNodes:=COMP(GG,FNodes);
                                        Factorisation:=FALSE;
                                        RETURN(RECIB1(GG,Fcmp));
                                        FNodes:=RED(FNodes);
                                        EXIT;
                                     ELSE IF DCIBopt.TraceLevel > 1 THEN
                                        BLINES(0);
                                        SWRITE("** equal nodes found");
                                        eqn:=eqn+1; END;
                                     END;
                               END;
                      ELSE nocb:=nocb+1; BLINES(0); 
                           SWRITE("** depth maximum reached; cancel branch"); 
                           RETURN(SIL);
                      END;
       END; (* IF H... *)
   END; (* LOOP *)
   IF DCIBopt.TraceLevel>1 THEN BLINES(0);
      SWRITE("= involutive base ="); BLINES(0);
      IF DCIBopt.TraceLevel>2 THEN t:=TIME()-T; SWRITE("Time: "); IWRITE(t);
         DILWR(K,V); BLINES(0);
      END;
   END; 
   RETURN(LIST1(K));
END RECIB2;


PROCEDURE newFactors(G,h,Fcmp,V: LIST): LIST;
VAR Fnew,F,hi,FL,g,h,G1: LIST;
    reduced          : BOOLEAN;
BEGIN
   Fnew:=SIL; 
   F:=DCIBopt.DecompProc(h, DCIBopt.VarOrdOpt);	(* factorization *)
   IF LENGTH(F) > 1 THEN Factorisation:=TRUE; END; 
                (* set flag if factorisation took place *)
   F:=SortF(F); (* sort factors in non-increasing order *)
   WHILE F<>SIL DO
      ADV(F,hi,F);
      G1:=COMP(hi,G);
      FL:=Fcmp;
      LOOP (* 1 *)
	 IF FL=SIL THEN Fnew:=COMP(hi,Fnew); Fcmp:=COMP(hi,Fcmp); EXIT; END;
	 ADV(FL,g,FL); ADPNFJ(G1,g,h,reduced);
	 IF h=0 THEN
            IF DCIBopt.TraceLevel>1 THEN 
               BLINES(0); SWRITE("** cancel factor "); DIWRIT(g,V);
               nocb:=nocb+1; 
            END;
            EXIT; 
         END;
      END; (* LOOP 1 *)
   END; (* WHILE F... *)
   RETURN(INV(Fnew));
END newFactors;

BEGIN
   IF G=SIL THEN ERROR(severe,"IB1: undefined ideal"); END;
   IF ZeroPoly(G) THEN ERROR(severe,"IB1: zero polynomial"); END; 
   T:=TIME(); VALIS:=V;
   Fcmp:=SIL; counter:=SIL; lc:=0; nocb:=0; eqn:=0;  
   depth:=DCIBopt.depth;
   DILISJ(G,G,dummy); VL:=DIPVL(FIRST(G)); le:=LENGTH(VL)+1;
   FNodes:=SIL; Factorisation:=FALSE; 
   IBList:=RECIB1(G,Fcmp);
   IF DCIBopt.TraceLevel>0 THEN t:=TIME()-T;
      IF DCIBopt.TraceLevel>1 THEN 
         BLINES(0); SWRITE("Number of canceled branches/factors: ");
         IWRITE(nocb);
         BLINES(0); IWRITE(eqn); SWRITE(" equal nodes found.");
      END;
      BLINES(0); SWRITE("Time: "); IWRITE(t); SWRITE("ms ");
      IF DCIBopt.TraceLevel>2 THEN IBLWR(IBList,V); END;
   END;
   RETURN(IBList);
END InvolutiveBases;


PROCEDURE SortF(F: LIST): LIST;
VAR Fnew, ExpPol: LIST;
BEGIN
   Fnew:=SIL;
   WHILE F<>SIL DO 	(* remove exponents *)
      ADV(F,ExpPol,F);
      Fnew:=COMP(SECOND(ExpPol),Fnew);
   END; (* WHILE F... *)
   RETURN(INV(DIPLPM(Fnew)));	(* sorting F into non-decreasing order *)
END SortF;


PROCEDURE ZeroPoly(G: LIST): BOOLEAN;
(* test polynomial list G for zero-polynomial *)
VAR g: LIST;
BEGIN
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF g=0 THEN RETURN(TRUE); END;
   END; (* while G... *)
   RETURN(FALSE);
END ZeroPoly;


PROCEDURE DecCounter(VAR counter: LIST; VAR length_of_counter: INTEGER);
(* Decrement counter.
   counter is a list of integers, the first element of counter is removed *)    BEGIN
  IF length_of_counter>0 THEN counter:=RED(counter);
                              length_of_counter:=length_of_counter-1;
  END;                 
END DecCounter;


PROCEDURE IncCounter(VAR counter: LIST; VAR loc: INTEGER; add: INTEGER);
(* Increment Counter.
   Increment the first entry of the counter list or append a new element
   Input: counter: a list of integers, 
          add = 0: append a new element and increment counterlength loc, or
          add>0: increment the first element by add *)
VAR c: INTEGER;
BEGIN
   IF add=0 THEN counter:=COMP(0,counter); 
                 loc:=loc+1; 
            ELSE ADV(counter,c,counter);
                 c:=c+add; 
                 counter:=COMP(c,counter);
   END;
END IncCounter;


PROCEDURE CounterWR(counter: LIST);
(* Counter Write. 
   write the given list counter as the number of a reached node *)
VAR C,c: LIST;
BEGIN
  IF counter<>SIL THEN C:=CINV(counter); ELSE C:=SIL; END;
  WHILE C<>SIL DO ADV(C,c,C);
                  IWRITE(c);
                  IF C<>SIL THEN SWRITE("."); ELSE SWRITE(" "); END;
  END;
END CounterWR;


PROCEDURE IBLWR(PP,V: LIST);
(* Involutive bases list write.
   PP is a list of involutive bases in distributive representation.
   V is a variable list 
*)
VAR ib: LIST;
    i,j : INTEGER;
BEGIN 
  i:=0;
  WHILE PP<>SIL DO ADV(PP,ib,PP);
                   i:=i+1;j:=LENGTH(ib); BLINES(0); 
                   IWRITE(i); SWRITE(". IB with "); IWRITE(j);
                   IF j>1 THEN SWRITE(" polynoms");
                          ELSE SWRITE(" polynom"); END;
                   DILWR(ib,V);
  END;
END IBLWR;


BEGIN
   (* TraceLevel = 0, DecompProc = Factorisation, VarOrdOpt = off, 
      Depth = unrestricted *)
   SetDCIBopt(LIST4(0,1,0,-1));
END DIPDCIB.

(* -EOF- *)
