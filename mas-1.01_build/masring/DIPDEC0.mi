(* ----------------------------------------------------------------------------
 * $Id: DIPDEC0.mi,v 1.3 1992/10/15 16:29:31 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDEC0.mi,v $
 * Revision 1.3  1992/10/15  16:29:31  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:15  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPDEC0;

(* DIP Ideal Decomposition 0 System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, BETA, SIL, LENGTH,
                    LIST1, ADV, FIRST, RED, SFIRST, SRED, COMP, INV;

FROM MASERR IMPORT ERROR, fatal, severe;

FROM MASBIOS IMPORT MASORD, SWRITE, BLINES, SOLINE;

FROM SACLIST IMPORT COMP2, COMP3, COMP4, LIST2, LIST3, LIST4, FIRST3, 
                    FIRST4, FIRST2, 
                    SECOND, RED2, RED3, CCONC, CINV, LELT, OWRITE, 
                    MEMBER, CLOUT, CONC, AWRITE, ADV2, ADV3, ADV4;

FROM SACSET IMPORT USDIFF, USUN;

FROM SACCOMB IMPORT LPERM; 

FROM SACPOL IMPORT VLSRCH, VLWRIT;

FROM SACRN IMPORT RNINT;

FROM DIPC IMPORT DIPMRD, DIPEVL, DIPEXC, DIPLBC, DIPNOV, DIPADM, 
                 VALIS, DIPUV, EVDOV, EVTDEG,
                 DIPLDC, DIPFMO, DIPMPV, DIPINV, 
                 DIPERM, PFDIP, DIPADV, DIPFP;

FROM DIPTOO IMPORT DIPDEV;

FROM DIPI IMPORT DIIFRP;

FROM DIPRN IMPORT DIRFIP, DIRLWR, DIRPWR, DIRPEV, 
                  DIRPPR, DIRPDF, DIRPRP, DIRPSM;

FROM DIPRNGB IMPORT DIRPGB, DIRGBA;

FROM DIPIDEAL IMPORT DIPLDV, DIRLPI;

FROM DIPZ IMPORT DIRMPG;

FROM DIPDIM IMPORT DIGBZT;

FROM SACUPFAC IMPORT IUPFAC;

CONST rcsidi = "$Id: DIPDEC0.mi,v 1.3 1992/10/15 16:29:31 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGFET(P,IL,JL: LIST): LIST; 
(*DIP G base successful extension test. P is a Groebner base of 
an ideal of dimension 0 in inverse lexicographical term ordering. 
i and j are indexes of variables where an field extension is required. 
t=1 if the extension was successful t=0 else. *)
VAR  DL, EL, IP, IS1, IS2, J1Y, PL, PP, RL, TL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; J1Y:=FIRST(PP); J1Y:=DIPNOV(J1Y); 
      RL:=J1Y+1; IS1:=RL-IL; IS2:=RL-JL; TL:=0; 
(*2*) (*test linearity of the head terms in the variable il. *) 
      LOOP IF PP = SIL THEN EXIT END;
           ADV(PP, PL,PP); EL:=DIPEVL(PL); 
           IP:=EVDOV(EL); 
           IF FIRST(IP) = IS1 THEN DL:=EVTDEG(EL); 
              IF DL = 1 THEN EXIT (*go to 3;*) ELSE RETURN(TL); END; 
              END; 
           END; 
(*3*) (*test linearity of the head terms in the variable jl. *) PP:=P; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); EL:=DIPEVL(PL); 
            IP:=EVDOV(EL); 
            IF FIRST(IP) = IS2 THEN DL:=EVTDEG(EL); 
               IF DL = 1 THEN TL:=1; END; 
               RETURN(TL); END; 
            END; 
(*6*) RETURN(TL); END DIGFET; 


PROCEDURE DIGISM(P: LIST): LIST; 
(*DIP G base index search for extension multiple univariats. 
P is a Groebner base of dimension 0 in inverse lexicographical term 
ordering. I is a list of indexes of variables where an field extension
is required or I=() if no field extension is neccessary. *)
VAR  DL, EL, I, IP, IS, IS1, IS2, J1Y, PL, PP, RL, TL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; IP:=SIL; 
LOOP 
(*2*) (*search multiple nonlinear univariat polynomials. *) 
      WHILE PP <> SIL DO ADV(PP, PL,PP); EL:=DIPDEV(PL); 
           TL:=EVTDEG(EL); IS:=EVDOV(EL); 
           IF (LENGTH(IS) = 1) AND (TL >= 2) THEN
              IF IP = SIL THEN IP:=IS; 
                 ELSE IP:=CONC(IS,IP); EXIT (*go to 4;*) END; 
              END; 
           END; 
(*3*) (*search univariat polynomials with non linear headterms. *) 
      PP:=P; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); EL:=DIPEVL(PL); 
            DL:=EVTDEG(EL); 
            IF DL >= 2 THEN EL:=DIPDEV(PL); IP:=EVDOV(EL); 
               IF LENGTH(IP) >= 2 THEN EXIT (*go to 4;*) END; 
               END; 
            END; 
      I:=SIL; RETURN(I);
      END; 
(*4*) (*adjust index. *) J1Y:=LENGTH(EL); RL:=J1Y+1; IP:=INV(IP); 
      FIRST2(IP, IS1,IS2); IS1:=RL-IS1; IS2:=RL-IS2; I:=LIST2(IS1,IS2); 
      RETURN(I);
(*7*) END DIGISM; 


PROCEDURE DIGISR(P: LIST): LIST; 
(*DIP G base index search for extension reductas. P is a Groebner 
base of an ideal of dimension 0 in inverse lexicographical term 
ordering. I is a list of indexes of variables where an field 
extension is required or I=() if no field extension is neccessary. *)
VAR  EL, I, IP, IS, IS1, IS2, J1Y, PL, PP, QL, RL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; I:=SIL; 
LOOP
(*2*) (*test dependency of variables for each polynomial. *) 
      WHILE PP <> SIL DO ADV(PP, PL,PP); EL:=DIPEVL(PL); 
            IP:=EVDOV(EL); 
            IF LENGTH(IP) >= 2 THEN EXIT (*go to 3;*) END; 
            QL:=DIPMRD(PL); EL:=DIPDEV(QL); IS:=EVDOV(EL); 
            IP:=USDIFF(IS,IP); 
            IF LENGTH(IP) >= 2 THEN EXIT (*go to 3;*) END; 
            END; 
      I:=SIL; RETURN(I); 
      END;
(*3*) (*adjust index. *) J1Y:=LENGTH(EL); RL:=J1Y+1; IP:=INV(IP); 
      FIRST2(IP, IS1,IS2); IS1:=RL-IS1; IS2:=RL-IS2; I:=LIST2(IS1,IS2); 
      RETURN(I);
(*6*) END DIGISR; 


PROCEDURE DINTFE(T,IL,JL: LIST): LIST; 
(*DIP normalized tupel field extension. T is a normalized tupel 
of a zero set with a final Groebner base of dimension 0.
i and j determine the variable indexes for the field extension.
TP is a list of normalized tupels for the field extension for T. 
Trial values are used for the transcendent parameter. *)
VAR  AI, AIP, AJ, AP, AS, EINS, EL, ELS, FL, ILP, JLP, KL, N, PL, PP,
     PS, RL, T0, T0P, TB, TL, TP, VL, VL1, VL2, VP: LIST; 
BEGIN
(*1*) (*initialise. *) TP:=SIL; ADV3(T, FL,VP,PP,TB); RL:=LENGTH(VP); 
      VL1:=LELT(VP,IL); VL2:=LELT(VP,JL); VL:=CCONC(VL1,VL2); 
      VL:=COMP(MASORD("e"),VL); 
      SWRITE("Introduction of the new variable "); CLOUT(VL); 
      BLINES(2); VP:=COMP(VL,VP); VALIS:=VP; 
(*2*) (*prepare Groebner base. *) ELS:=SIL; 
      FOR KL:=1 TO RL+1 DO ELS:=COMP(0,ELS); END; 
      ILP:=IL+1; JLP:=JL+1; EINS:=RNINT(1); AP:=DIPFMO(EINS,ELS); 
      AI:=DIPMPV(AP,ILP,1); AJ:=DIPMPV(AP,JLP,1); AP:=DIPMPV(AP,1,1); 
      PS:=SIL; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIPINV(PL,0,1); 
            PS:=COMP(PL,PS); END; 
      PP:=INV(PS); 
(*3*) (*compute new Groebner base over q(xj + t0 xi). *) T0:=0; 
      REPEAT T0:=T0-1; T0P:=RNINT(T0); AIP:=DIRPRP(AI,T0P); 
             AS:=DIRPSM(AIP,AJ); AS:=DIRPDF(AP,AS); PS:=DIRGBA(AS,PP,1); 
             TL:=DIGFET(PS,ILP,JLP); 
             UNTIL TL = 1; 
(*4*) (*create new normalized tupel set. *) N:=DIRGZS(VP,PS,VP); 
      TP:=DINTZS(N); 
(*7*) RETURN(TP); END DINTFE; 


PROCEDURE DINTSR(T: LIST): LIST; 
(*DIP normalized tupel separation refinement. T is a list of 
normalized tupels with final Groebner base of dimension 0.
TP is a list of normalized tupels for some field extensions for T. *)
VAR  FL, I, IL, JL, PP, TB, TL, TP, TS, VP: LIST; 
BEGIN
(*1*) (*initialise. *) TP:=SIL; TB:=T; 
(*2*) (*refine each tupel. *) 
      REPEAT ADV(TB, TL,TB); FIRST3(TL, FL,VP,PP); I:=DIGISR(PP); 
             IF I = SIL THEN TP:=COMP(TL,TP); ELSE FIRST2(I,
                IL,JL); TS:=DINTFE(TL,IL,JL); TB:=CONC(TS,TB); END; 
             UNTIL TB = SIL; 
(*3*) (*finish. *) TP:=INV(TP); 
(*6*) RETURN(TP); END DINTSR; 


PROCEDURE DINTSS(T: LIST): LIST; 
(*DIP normalized tupel strong separation. T is a list of normalized 
tupels with final Groebner base of dimension 0. TP is a list of 
normalized tupels for some field extensions for T. *)
VAR  EL1, EL2, FL, FL1, I, IL, J1Y, JL, KL, PL, PL1, PP, PP1, PS, QL,
     RL, RLP, RLS, TB, TL, TLS, TP, VL1, VP, VP1: LIST; 
BEGIN
(*1*) (*initialise. *) TP:=SIL; TB:=T; 
      IF TB = SIL THEN RETURN(TP); END; 
      J1Y:=FIRST(TB); J1Y:=SECOND(J1Y); RL:=LENGTH(J1Y); 
(*2*) (*refinements of each tupel. *) 
      REPEAT ADV(TB, TL,TB); FIRST3(TL, FL,VP,PP); I:=DIGISR(PP); 
             IF I = SIL THEN I:=DIGISM(PP); END; 
             IF I = SIL THEN TP:=COMP(TL,TP); ELSE FIRST2(I,
                IL,JL); TLS:=DINTFE(TL,IL,JL); TB:=CONC(TLS,TB); END; 
             UNTIL TB = SIL; 
      TB:=INV(TP); TP:=SIL; 
(*3*) (*extraction of unneccessary variables. *) 
      REPEAT ADV(TB, TLS,TB); ADV3(TLS, FL,VP,PP,TLS); RLS:=LENGTH(VP); 
             J1Y:=RLS-RL; RLP:=J1Y-1; 
             IF RLP >= 1 THEN ADV3(TLS, FL1,VP1,PP1,TLS); ADV(VP,
                VL1,VP); ADV(PP, PL1,PP); 
                FOR KL:=1 TO RLP DO TLS:=RED3(TLS); PP:=RED(PP); 
                    VP:=RED(VP); END; 
                TLS:=COMP3(FL1,VP1,PP1,TLS); VP:=COMP(VL1,VP); 
                PP:=COMP(PL1,PP); PS:=SIL; 
                WHILE PP <> SIL DO ADV(PP, PL,PP); 
                      FOR KL:=1 TO RLP DO DIPADV(PL,2, EL1,EL2,PL,QL); 
                          END; 
                      PS:=COMP(PL,PS); END; 
                PP:=INV(PS); END; 
             TLS:=COMP3(FL,VP,PP,TLS); TP:=COMP(TLS,TP); 
             UNTIL TB = SIL; 
(*4*) (*finish. *) TP:=INV(TP); 
(*7*) RETURN(TP); END DINTSS; 


PROCEDURE DINTZS(N: LIST): LIST; 
(*DIP nomalized tupels from system zero. N is a zero set. 
T is the list of nomalized tupels of N. *)
VAR  TUP: ARRAY[1..200] OF LIST; 
VAR  FL, J, NP, PL, RL, T, T1, T2, TL, TP, TS, U, V, 
     VL, VP, VS: LIST; 
     I: INTEGER;
BEGIN
(*1*) (*empty or initialise. *) NP:=N; 
      IF NP = SIL THEN T:=SIL; RETURN(T); END; 
      T:=DITFZS(N); VS:=VALIS; RL:=LENGTH(VS); 
      IF RL > 200 THEN ERROR(fatal,"tup overflow in DINTZS"); 
         RETURN(T); END; 
LOOP
(*2*) (*nomalize tupels. *) TP:=SIL; 
      WHILE T <> SIL DO ADV(T, TL,T); T1:=SIL; TS:=SIL; 
            FOR I:=1 TO INTEGER(RL) DO TUP[I]:=SIL; END; 
            WHILE TL <> SIL DO ADV3(TL, FL,V,PL,TL); 
                  CASE INTEGER(FL) OF
                       1 : VL:=FIRST(V); I:=INTEGER(VLSRCH(VL,VS)); 
                           IF TUP[I] <> SIL THEN EXIT (*go to 4;*) END; 
                           TS:=COMP(VL,TS); TUP[I]:=LIST3(FL,V,PL); |
                       4 : T1:=T1; |
                       5 : IF TL = SIL THEN TS:=SIL; END; |
                       6 : T1:=COMP3(FL,V,PL,T1); |
                       3 : WHILE V <> SIL DO ADV(V, VL,V); 
                                 VP:=LIST1(VL); I:=INTEGER(VLSRCH(VL,VS)); 
                                 IF TUP[I] <> SIL THEN EXIT (*go to 4;*) END; 
                                 TS:=COMP(VL,TS); 
                                 TUP[I]:=LIST3(FL,VP,PL); END; 
                           |
                       2 : T1:=COMP3(FL,V,PL,T1); U:=DIPLDV(PL,VS); 
                           TS:=USUN(TS,U); 
                      ELSE EXIT END; 
                  END; 
            IF TS <> SIL THEN V:=USDIFF(VS,TS); 
               WHILE V <> SIL DO ADV(V, VL,V); VP:=LIST1(VL); 
                     I:=INTEGER(VLSRCH(VL,VS)); 
                     IF TUP[I] = SIL THEN TUP[I]:=LIST3(3,VP,0); 
                        END; 
                     END; 
               T2:=SIL; 
               FOR I:=INTEGER(RL) TO 1 BY -1 DO T2:=CONC(TUP[I],T2); END; 
               IF FIRST(T1) = 6 THEN T1:=CONC(T1,T2); ELSE
                  T1:=CONC(T2,T1); END; 
               IF  MEMBER(T1,TP) <> 1 THEN TP:=COMP(T1,TP); END; 
               END; 
            END; 
      T:=INV(TP); 
(*3*) (*finish. *) RETURN(T); 
      END;
(*4*) (*error. *) SWRITE("Tup non empty"); SWRITE("I="); OWRITE(LIST(I)); 
      BLINES(2); SWRITE("TUP[I]="); OWRITE(TUP[I]); BLINES(2); 
      SWRITE("T1="); OWRITE(T1); BLINES(2); SWRITE("T2="); OWRITE(T2); 
      BLINES(2); SWRITE("FL="); OWRITE(FL); BLINES(2); SWRITE("V ="); 
      OWRITE(V); BLINES(2); SWRITE("PL="); OWRITE(PL); BLINES(2); 
      FOR J:=1 TO RL DO SWRITE("TUP(J)="); OWRITE(TUP[INTEGER(J)]); 
          BLINES(2); END; 
      RETURN(SIL);
(*7*) END DINTZS; 


PROCEDURE DIRGZS(VB,PB,W: LIST): LIST; 
(*Distributive rational Groebner base zero set. VB is a rest of a 
variable list. PB is a Groebner base. W is the total variable 
list. N is the zero set of P. *)
VAR  CL, EL, IL, J1Y, J2Y, KL, LEN, LL, N, NP, P, PL, PLS, PP,
     PS, QL, QLP, QLS, QP, QPP, QS, RL, RLS, SL, TL, V, VL, VP,
     VS, WL: LIST; 
BEGIN
(*1*) (*dimension of p. *) P:=PB; V:=VB; 
      IF P = SIL THEN N:=LIST4(3,V,0,SIL); RETURN(N) END; 
      TL:=DIGBZT(P); N:=SIL; J1Y:=FIRST(P); RL:=DIPNOV(J1Y); 
      J1Y:=RL+1; J2Y:=LENGTH(V); IL:=J1Y-J2Y; 
      IF TL = -1 THEN N:=LIST4(2,W,PB,SIL); RETURN(N) END; 
      IF TL = 1 THEN N:=LIST4(4,W,PB,SIL); RETURN(N) END; 
(*2*) (*rl = 1. *) 
      IF RL = 1 THEN 
         PL:=FIRST(P); PL:=DIIFRP(PL); PFDIP(PL, RLS,QL); 
         IUPFAC(QL,SL,CL,QP); 
         WHILE QP <> SIL DO ADV(QP, QS,QP); 
               N:=COMP4(1,V,QS,SIL,N); END; 
         RETURN(N) END; 
(*3*) (*il = rl. *) 
      IF IL = RL THEN  
         PL:=DIRMPG(IL,P); PL:=DIIFRP(PL); PFDIP(PL, RLS,QL); 
         IUPFAC(QL, SL,CL,QP); LEN:=LENGTH(QL); 
         WHILE QP <> SIL DO ADV(QP, QLS,QP); FIRST2(QLS, SL,QL); 
               IF (LEN = 1) AND (SL = 1) 
                  THEN PP:=P; 
                  ELSE QL:=DIPFP(1,QL); QL:=DIRFIP(QL); J1Y:=IL-1; 
                  SL:=DIPINV(QL,0,J1Y); J1Y:=RL-IL; SL:=DIPINV(SL,IL,J1Y); 
                  PP:=DIRGBA(SL,P,1); END; 
               NP:=LIST4(6,W,PP,SIL); N:=COMP4(1,V,QLS,NP,N); END; 
         RETURN(N) END; 
(*4*) (*il lt rl. *) PL:=DIRMPG(IL,P); PL:=DIIFRP(PL); 
      PFDIP(PL,RLS,QL); IUPFAC(QL, SL,CL,QP); LEN:=LENGTH(QP); 
      ADV(V, VL,VP); VL:=LIST1(VL); 
      WHILE QP <> SIL DO ADV(QP, QLS,QP); FIRST2(QLS, SL,QL); 
            IF (LEN = 1) AND (SL = 1) THEN PP:=P; ELSE
               QL:=DIPFP(1,QL); QL:=DIRFIP(QL); J1Y:=IL-1; 
               SL:=DIPINV(QL,0,J1Y); J1Y:=RL-IL; SL:=DIPINV(SL,IL,J1Y); 
               PP:=DIRGBA(SL,P,1); END; 
            NP:=DIRGZS(VP,PP,W); N:=COMP4(1,VL,QLS,NP,N); END; 
      RETURN(N);
(*9*) END DIRGZS; 


PROCEDURE DIRLPD(A,VP: LIST): LIST; 
(*DIP rational polynomial ideal primary ideal decomposition.
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in A have r variables.
L=(l1, ...,ln) with li=(pi,ei,vpi,qi) i=1, ...,n where 
qi = ideal(pi**e,A) with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list vor pi. *)
VAR  DL, EL1, EL2, FL, FLP, IL, J1Y, L, N, P, PB, PL, PP, QL, QLS,
     RL, RLS, SL, T, T0, T0P, T1, TL, TLS, VL, VLP,
     VS: LIST; 
BEGIN
(*1*) (*zero set. *) DL:=DIGBZT(A); L:=SIL; 
      IF DL = -1 THEN RETURN(L); END; 
      N:=DIRGZS(VP,A,VP);  
(*2*) (*zero set refined tupels. *) T:=DINTZS(N); DITSPL(T, T0,T1); 
      IF T0 = SIL THEN RETURN(L); END; 
      T0:=DINTSS(T0);  
(*3*) (*invert variable odering. *) T0P:=SIL; RL:=LENGTH(VP); 
      RLS:=RL+1; VS:=LIST1(1); 
      FOR IL:=RL+1 TO 2 BY -1 DO VS:=COMP(IL,VS); END; 
      WHILE T0 <> SIL DO ADV(T0, TL,T0); FIRST3(TL, FL,VL,P); 
            IF LENGTH(VL) > RL THEN TLS:=RED3(TL); 
               VL:=LPERM(VL,VS); VALIS:=VL; PP:=SIL; IL:=0; 
               IF TLS <> SIL THEN TLS:=RED3(TLS); END; 
               WHILE TLS <> SIL DO ADV3(TLS, FLP,VLP,QLS,TLS); 
                     IL:=IL+1; FIRST2(QLS, SL,QL); QL:=DIPFP(1,QL); 
                     QL:=DIRFIP(QL); J1Y:=IL-1; PL:=DIPINV(QL,0,J1Y); 
                     J1Y:=RLS-IL; PL:=DIPINV(PL,IL,J1Y); 
                     PP:=COMP(PL,PP); END; 
               IF P <> SIL THEN P:=RED(P); END; 
               WHILE P <> SIL DO ADV(P, PL,P); PL:=DIPERM(PL,VS); 
                     PP:=COMP(PL,PP); END; 
               PP:=DIRPGB(PP,1); VL:=CINV(VL); VL:=RED(VL); VL:=INV(VL); 
               VALIS:=VL; PP:=CINV(PP); PP:=RED(PP); PP:=INV(PP); P:=PP; 
               PP:=SIL; 
               WHILE P <> SIL DO ADV(P, PL,P); 
                     DIPADM(PL,EL1,EL2,PL,PB); PP:=COMP(PL,PP); END; 
               P:=INV(PP); END; 
            J1Y:=LIST3(FL,VL,P); T0P:=COMP(J1Y,T0P); END; 
      T0:=INV(T0P); 
(*4*) (*get primary ideals. *) L:=SIL; 
      WHILE T0 <> SIL DO ADV(T0, TL,T0); FIRST3(TL, FL,VL,P); 
            QL:=DIRLPI(A,P,VL); 
            L:=COMP(QL,L); END; 
(*5*) (*finish. *) L:=INV(L); RETURN(L); 
(*8*) END DIRLPD; 


PROCEDURE DIRLPW(A,V,L: LIST); 
(*DIP rational polynomial ideal primary ideal decomposition write.
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in a have r variables.
L=(l1, ...,ln) with li=(pi,eli,vpi,qi) i=1, ...,n where 
qi = ideal(pi)**e with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list for pi. *)
VAR  EL, LP, LS, P, Q, VL: LIST; 
BEGIN
(*1*) (*write a. *) SWRITE("The given ideal"); DIRLWR(A,V,-1); 
      BLINES(1); 
(*2*) (*write decomposition of a. *) LP:=L; 
      SWRITE("The decomposition of the ideal"); BLINES(2); 
      WHILE LP <> SIL DO ADV(LP, LS,LP); FIRST4(LS, P,EL,VL,Q); 
            SWRITE("The prime ideal"); DIRLWR(P,VL,-1); BLINES(1); 
            SWRITE("The primary ideal"); DIRLWR(Q,VL,-1); BLINES(1); 
            SWRITE("The exponent is "); AWRITE(EL); BLINES(2); END; 
(*3*) (*finish. *) RETURN; 
(*6*) END DIRLPW; 


PROCEDURE DIRPDA(A,VP: LIST): LIST; 
(*DIP rational polynomial ideal primary ideal decomposition over Q(alpha).
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in A have r variables.
L=(l1, ...,ln) with li=(pi,ei,vpi,qi) i=1, ...,n where 
qi = ideal(pi**e,A) with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list vor pi. *)
VAR  DL, FL, L, N, P, QL, T, T0, T1, TL, TP, VL: LIST; 
BEGIN
(*1*) (*zero set. *) DL:=DIGBZT(A); L:=SIL; 
      IF DL = -1 THEN RETURN(L); END; 
      N:=DIRGZS(VP,A,VP);  
(*2*) (*zero set refined tupels. *) T:=DINTZS(N); DITSPL(T, T0,T1); 
      IF T0 = SIL THEN RETURN(L); END; 
      T0:=DINTSS(T0); 
(*3*) (*get primary ideals. *) L:=SIL; 
      WHILE T0 <> SIL DO ADV(T0, TL,T0); FIRST3(TL, FL,VL,P); 
            QL:=DIRLPI(A,P,VL); L:=COMP(QL,L); END; 
(*4*) (*finish. *) L:=INV(L); 
(*7*) RETURN(L); END DIRPDA; 


PROCEDURE DITFZS(N: LIST): LIST; 
(*DIP tupel from zero set. N is a zero set. T is a list of 
tupels of the zero set. *)
VAR  EPS, FL, M, NP, PL, T, TL, TP, V: LIST; 
BEGIN
(*1*) (*empty or initialise. *) T:=SIL; NP:=N; 
      IF NP = SIL THEN T:=COMP(SIL,T); RETURN(T); END; 
(*2*) (*roots, Groebner base and recursion. *) 
      WHILE NP <> SIL DO ADV4(NP, FL,V,PL,M,NP); TP:=DITFZS(M); 
            WHILE TP <> SIL DO ADV(TP, TL,TP); 
                  TL:=COMP3(FL,V,PL,TL); T:=COMP(TL,T); END; 
            END; 
(*5*) RETURN(T); END DITFZS; 


PROCEDURE DITSPL(T: LIST;  VAR T0,T1: LIST); 
(*DIP zero set tupel split. T is a list of normalized tupels 
of a zero set. T0 is a list of normalized tupels of a zero set 
with a final Groebner base of a ideal of dimension 0. T1=T-T0. *)
VAR  FL, IL, J1Y, PL, RL, TL, TLP, TP, V: LIST; 
BEGIN
(*1*) (*initialise. *) T0:=SIL; T1:=SIL; TP:=T; 
      IF T = SIL THEN RETURN; END; 
(*2*) (*split. *) 
      REPEAT ADV(TP, TL,TP); TLP:=TL; IL:=0; RL:=-1; 
             WHILE TL <> SIL DO ADV3(TL, FL,V,PL,TL); 
                   CASE INTEGER(FL) OF
                        1 : IL:=IL+1; |
                        2 : IL:=IL; |
                        3 : IL:=IL; |
                        4 : IL:=IL; |
                        5 : IL:=IL; |
                        6 : J1Y:=FIRST(PL); RL:=DIPNOV(J1Y); END; 
                   END; 
             IF IL = RL THEN T0:=COMP(TLP,T0); 
                        ELSE T1:=COMP(TLP,T1); END; 
             UNTIL TP = SIL; 
(*3*) (*finish. *) T0:=INV(T0); T1:=INV(T1); 
(*6*) END DITSPL; 


END DIPDEC0.

(* -EOF- *)
