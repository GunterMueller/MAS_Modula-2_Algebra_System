(* ----------------------------------------------------------------------------
 * $Id: DIPIIB.mi,v 1.1 1995/10/12 14:44:57 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIIB.mi,v $
 * Revision 1.1  1995/10/12 14:44:57  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIIB;
(* DIP Integral Involutive Base Implementation Module. *)

(* Import lists and declarations. *)

FROM DIPC 	IMPORT 	DIPEVL, DIPFMO, DIPMAD, EVDIF, EVSIGN, EVSUM, EVTDEG;

FROM DIPI 	IMPORT 	DIIPCP, DIIPDF, DIIPIP, DIIPPR; 

FROM DIPCJ 	IMPORT 	ADDTDG, ADVTDG, DIILPP, DILATDG, DILBBS, DILEP2P, 
			DILTDG, DIPNML, DIRPMV, DIPPGL, DIPPGL2, DIPPGL3,
			DIPSSM, DIPVL, EVMTJ2, EVDIF2, EVMTJ;
  
FROM MASBIOS 	IMPORT 	BLINES, SWRITE;

FROM MASERR 	IMPORT 	harmless, ERROR;

FROM MASLISPU 	IMPORT 	PROCP2V2;

FROM MASSTOR 	IMPORT 	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL,
			SRED, TIME;

FROM SACI 	IMPORT 	IGCDCF, IPROD;

FROM SACLIST 	IMPORT 	AWRITE, CCONC, CINV, COMP2, CONC, EQUAL, LAST, LWRITE,
			OWRITE;

VAR DIPIIBOpt: RECORD
                   Select: PROCP2V2;
                           (* Strategy for selection of polynoms from
                              polynomlist. *)
               END;
   Select: PROCP2V2;


CONST rcsidi = "$Id: DIPIIB.mi,v 1.1 1995/10/12 14:44:57 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";      

(** Version from: Zharkov, Blinkov: 
                  Involutive Bases of zero-dimensional Ideals ****************)

PROCEDURE DIIPNFJ(P,RPP,S: LIST): LIST; 
(*Distributive integral polynomial normal form in the sense of Janet. 
  P is a list of non zero polynomials in distributive integral
  representation in r variables. RPP and S are distributive integral
  polynomials. The result is a polynomial such that S is reducible to R
  modulo P and R is in normalform with respect to P. *)
VAR   AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, R, RP, RS, SL, SP, TA,
      TE, r: LIST; 
BEGIN
      IF S = 0 THEN R:=RPP; RETURN(R); END; 
      IF P = SIL THEN
         IF RPP = 0 THEN R:=S; ELSE R:=CCONC(RPP,S); END; 
         RETURN(R); 
      END; 
      SP:=S; R:=RPP; 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMTJ(TE,QE); 
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN RP:=DIPFMO(TA,TE); 
                IF R = 0 THEN R:=RP; ELSE RS:=LAST(R); SRED(RS,RP); 
                   END; 
                ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); IGCDCF(TA,QA,
                   CL,AL,BL); AP:=DIPFMO(AL,FL); APP:=DIIPPR(QP,AP); 
                   SP:=DIIPIP(SP,BL); R:=DIIPIP(R,BL);
                   SP:=DIIPDF(SP,APP); END; 
             END; 
      UNTIL SP = 0; 
      RETURN(R); 
END DIIPNFJ; 

       
PROCEDURE DIILISJ(P: LIST): LIST; 
(*Distributive integral polynomial list irreducible set.
  P is a list of distributive integral polynomials,
  PP is the result of reducing each p element of P modulo P-(p)
  in the sense of Janet until no further reductions are possible. *)
VAR   CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL: LIST; 
BEGIN
      PP:=P; PS:=SIL; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); DIIPCP(PL, CL,PL); 
            IF PL <> 0 THEN PS:=COMP(PL,PS); END; 
            END; 
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END; 
      (*reduce until all polynomials are irreducible. *) 
      LOOP ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIIPNFJ(PP,0,PL); 
           IF PL = 0 THEN LL:=LL-1; 
              IF LL <= 1 THEN EXIT END; 
              ELSE FL:=DIPEVL(PL); SL:=EVSIGN(FL); 
              IF SL = 0 THEN PP:=LIST1(PL); EXIT; END; 
              SL:=EQUAL(EL,FL); 
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; DIIPCP(PL,CL,PL); END; 
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
           IF IRR = LL THEN EXIT END; 
      END; (*loop*)
      BLINES(1); AWRITE(LL); 
      SWRITE("  irreducible polynomials."); BLINES(1); 
      RETURN(PP); 
END DIILISJ; 


PROCEDURE DIIPCOM(F: LIST): LIST;
(* Distributive integral polynom complete system.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,FLAG,EL: LIST;
BEGIN
  IF F=SIL THEN RETURN(SIL); END;
  EL:=SIL; G:=DIILISJ(F); 
  REPEAT
        H:=G;
        TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) <= TDG THEN
                       f:=DIIPNFJ(G,0,p);
                       IF f<>0 THEN G:=DIILISJ(COMP(f,G));
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
   UNTIL (H = SIL) AND FLAG; 
   RETURN(G);        
END DIIPCOM; 


PROCEDURE DIIPIB2(F: LIST): LIST;
(* Distributive integral polynom involutive basis.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,EL: LIST;
    FLAG                  : BOOLEAN;
BEGIN
  IF F=SIL THEN RETURN(SIL) END;
  EL:=SIL; G:=DIIPCOM(F); 
  REPEAT
        H:=G;
        TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) > TDG THEN
                       f:=DIIPNFJ(G,0,p);
                       IF f<>0 THEN G:=DIIPCOM(COMP(f,G));
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
      UNTIL (H = SIL) AND FLAG; 
   RETURN(G);        
END DIIPIB2; 

(** Version from: Zharkov, Blinkov:
               Involution Approach to Solving Systems of Algebraic Equations **)

PROCEDURE DIIPIB3(F: LIST): LIST;
(* Distributive integral polynom involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, H, h, NM, nm, f, VL, le: LIST;
BEGIN
  G:=SIL;
  IF F=SIL THEN RETURN(G) END;
  VL:=DIPVL(FIRST(F)); le:=LENGTH(VL)+1;
  WHILE F<>SIL DO  
        G:=DIILISJ(CONC(F,G)); 
        F:=SIL; H:=G;
        WHILE H<>SIL DO 
              ADV(H,h,H);
              NM:=DIPPGL3(h,VL,le); 
              WHILE NM<>SIL DO
                       ADV(NM,nm,NM);
                       f:=DIIPNFJ(G,0,nm);
                       IF f<>0 THEN F:=COMP(f,F); END; 
              END;
        END;
  END;     
  RETURN(G);
END DIIPIB3;

(** Optimized Version and some subalgorithms **********************************)

PROCEDURE DIIPPR2(A,B: LIST): LIST;
(*Distributive integral polynomial product. 
  A and B are distributive integral polynomials.
  Unlike procedure DIIPPR (in modul DIPI) B consists of one monomial. 
  C=A*B.*)
VAR  AL, AS, BL, BS, C, CL, EL, FL, GL: LIST;
BEGIN (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
      (*general case.*) AS:=CINV(A); BS:=B; C:=SIL; 
      DIPMAD(BS, BL,FL,BS); 
      REPEAT DIPMAD(AS, EL,AL,AS); 
             CL:=IPROD(AL,BL); GL:=EVSUM(EL,FL);
             C:=COMP2(GL,CL,C); 
      UNTIL AS = SIL;
      RETURN(C); 
END DIIPPR2;


PROCEDURE DIIPNFJ2(P,S: LIST; VAR R, c: LIST); 
(*Distributive integral polynomial normal form in the sense of Janet. 
  P is a list of non zero polynomials in distributive integral  
  representation in r variables. S is a distributive integral
  polynomial. R is a polynomial such that S is reducible to R
  modulo P and R is in normalform with respect to p.
  c returns 1 if a reduction took place and zero else.
  This procedure is should be used only from procedure DIIPISJ2 *)
VAR   AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, RP, RS, SL, SP, TA,
      TE, r, deg, tdg: LIST; 
BEGIN
      R:=0; c:=0;
      IF (S<>0) AND (P<>SIL) THEN  
      (*reduction step.*) ADVTDG(S, deg, SP); 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); ADVTDG(Q, tdg, Q); 
                    DIPMAD(Q, QA,QE,QP); SL:=EVMTJ(TE,QE); 
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN RP:=DIPFMO(TA,TE); 
                IF R = 0 THEN R:=RP; ELSE RS:=LAST(R); SRED(RS,RP); END;                     ELSE
                IF QP <> SIL THEN FL:=EVDIF2(TE,QE); IGCDCF(TA,QA,CL,AL,BL); 
                IF FL<>0 THEN  AP:=DIPFMO(AL,FL); APP:=DIIPPR2(QP,AP); 
                         ELSE APP:=DIIPIP(QP,AL) END;
                   SP:=DIIPIP(SP,BL); R:=DIIPIP(R,BL); 
                   SP:=DIIPDF(SP,APP); c:=1; 
                END; 
             END; 
      UNTIL SP = 0 END;
      IF (R<>0) THEN 
         IF c = 1 THEN R:=ADDTDG(EVTDEG(FIRST(R)),R); 
                  ELSE R:=ADDTDG(deg,R); END;
      END;       
END DIIPNFJ2; 


PROCEDURE DIILISJ2(P: LIST): LIST; 
(* Distributive integral polynomial list irreducible set.
   P is a list of distributive integral polynomials,
   PP is the result of reducing each p element of P modulo P-(p)
   in the sense of Janet until no further reductions are possible
   This should only be used from procedure DIIPIB. 
   For computation of the irreducible set use DIILISJ*)
VAR   CL, IRR, LL, PL, pl,  PP, PS, RP, SL, H: LIST; 
BEGIN
       PS:=CINV(P); RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0;     
       (*reduce until all polynomials are irreducible. *) 
       LOOP ADV(PP, PL,PP); DIIPNFJ2(PP,PL,PL,SL);
            IF PL = 0 THEN LL:=LL-1; 
              IF LL <= 1 THEN EXIT END; 
            ELSE IF SL=0 THEN IRR:=IRR+1; ELSE IRR:=0; 
                   ADVTDG(PL,pl,PL); DIIPCP(PL,CL,PL); PL:=ADDTDG(pl,PL); END; 
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS;  
           END;
           IF IRR = LL THEN EXIT END; 
      END; (*loop*) RETURN(PP);
END DIILISJ2; 


PROCEDURE DIIPIB(F: LIST): LIST;
(* Distributive integral polynomial involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, g, NM, nm, f, T, LL, VL, le, PL, CL, PS, r, tdg: LIST;
BEGIN
  G:=SIL;
  VL:=DIPVL(FIRST(F)); le:=LENGTH(VL)+1;
  PS:=DIILPP(F); PS:=DILATDG(PS); 
  F:=PS;
  IF F=SIL THEN RETURN(G) END;
  G:=DIILISJ2(F); 
  LOOP 
       Select(G,TRUE,g,G); 
       IF FIRST(g)=0 THEN EXIT END;
       NM:=DIPPGL2(g,VL,le); 
       ADVTDG(g,tdg,g); g:=COMP(0,g); 
       G:=COMP(g,G); 
       IF NM<>SIL THEN G:=CONC(NM,G); G:=DIILISJ2(G); END; 
  END;
  G:=COMP(g,G); 
  PS:=DILEP2P(G);
  RETURN(PS);
END DIIPIB;


(*** Initialization and setting of options ************************************)

PROCEDURE InitDIPIIB;
(* Init distributive integral involutive base.
   Initialization of the DIPIIB options *)
BEGIN
  SetDIPIIBSelect(1);
  Select:=DIPSSM;
END InitDIPIIB;

PROCEDURE SetDIPIIBSelect(SEL: INTEGER);
(* Set distributive integral polynomial Select.
   Set polynom selection strategy *)
BEGIN
  CASE SEL OF
       1: DIPIIBOpt.Select:=DIPSSM;
       ELSE ERROR(harmless,"DIPIIB.SetSelect: Unknown option number");
  END;
END SetSelect;

BEGIN
  InitDIPIIB;
END DIPIIB.


(* -EOF- *)
