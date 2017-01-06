(* ----------------------------------------------------------------------------
 * $Id: SYZGB.mi,v 1.4 1994/03/11 15:45:19 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZGB.mi,v $
 * Revision 1.4  1994/03/11  15:45:19  pesch
 * Minor changes.
 *
 * Revision 1.3  1992/10/15  16:29:21  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:17  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:59  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYZGB;

(* Syzygy Groebner Base Implementation Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM DIPC    IMPORT DIPEVL, DIPLPM, EVLCM, VALIS, STVL, DIPNOV;

FROM DIPRN   IMPORT DIRPMC, DIRPON, DIRPWR;

FROM DIPRNGB IMPORT DILCPL, DILUPL, DIRLIS, DIRPNF, DIRPSP, 
                    DIGBMI, DIGBC3, DIGBC4;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM MASNC   IMPORT DINPPR;

FROM MASNCGB IMPORT DINLIS, DINLNF, DINLSP;

FROM MASSTOR IMPORT ADV, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL, 
                    SFIRST, SRED, COMP, TIME;

FROM SACLIST IMPORT AWRITE, CCONC, LWRITE, OWRITE, FIRST3, LAST;

FROM SYZFUNC IMPORT BGFUP, NLBGFUP, NLSPC, NLRCSPR, RCSPR, SPC;

FROM SYZHLP  IMPORT ALFA, ALFRA, EVT, NEXTPAIR,
                    MTPLV, NORMF, PLVTM, TA, TR, WRS1, WRS2;

CONST rcsidi = "$Id: SYZGB.mi,v 1.4 1994/03/11 15:45:19 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE MGB(PM, SANZ : LIST): LIST;
(* Modul Groebner Base. Berechnet wird die Modul Groebner Basis fuer die
Polynommatrix PM. Das Bit SANZ steuert die Anzeigeart. *)
VAR   L, PL, GB : LIST;
BEGIN
    IF LENGTH(PM) = 1 THEN RETURN(PM); END;
    L := LENGTH(FIRST(PM));
    PL := MTPLV(PM, L);
    IF LENGTH(PL) = 1 THEN
      PM := PLVTM(PL, L);
      RETURN(PM);
    END;
    ALFA(L);
    GB := GBE(PL, SANZ, L);
    ALFRA(L);
    PM := PLVTM(GB, L);
    RETURN(PM);
END MGB;


PROCEDURE NLMGB(PM, SANZ : LIST; VAR T : LIST): LIST;
(* Non-Commutative Modul Groebner Base. Berechnet wird die Modul Groebner 
Basis fuer die Polynommatrix PM. Das Bit SANZ steuert die Anzeigeart. *)
VAR   L, PL, GB : LIST;
BEGIN
    IF LENGTH(PM) = 1 THEN RETURN(PM); END;
    L := LENGTH(FIRST(PM));
    PL := MTPLV(PM, L);
    IF LENGTH(PL) = 1 THEN
      PM := PLVTM(PL, L);
      RETURN(PM);
    END;
    ALFA(L);
    T := TA(L, T);
    GB := NLGBE(PL, SANZ, L, T);
    T := TR(L, T);
    ALFRA(L);
    PM := PLVTM(GB, L);
    RETURN(PM);
END NLMGB;


PROCEDURE GBE(P, TF, L : LIST): LIST;
(* Groebner Base with Exponent Vector Check. Berechnung der Groebner Basis 
von P unter Beruecksichtigung des Exponentenvektors der Hoechsten Terme.
S-Polynome werden nur bei solchen Polynomen gebildet, deren HT-Exponen-
tenvektor in den ersten L Stellen uebereinstimmt. *)
VAR  B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL,
     J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S,
     VL, RL1, SL, T, TR, X3, X4, XC, XH, XS, XT, YD, ZD: LIST; 
BEGIN
(*1*) (*prepare input. *)  
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=SIL; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP); 
               IF SL = 1 THEN PP:=LIST1(PLIP); RETURN(PP); END; 
               PPR:=COMP(PLIP,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
      VL:=VALIS; 
      IF VL = SIL THEN TF:=0; 
         ELSE RL:=DIPNOV(FIRST(PP)); RL1:=LENGTH(VL); 
              IF RL1 < RL THEN VL:=INV(STVL(RL-RL1)); 
                 VL:=CCONC(VALIS,VL); END;
              END;
      T:=TIME(); XH:=0; XS:=0; X3:=0; X4:=0;
(*2*) (*construct b and d. *) 
      PPR:=DIPLPM(PP); PP:=INV(PPR); 
      DILCPL(PP, D,B); YD:=LENGTH(D); 
(*3*) (*loop until no more pairs left. *) 
LOOP
      IF D = SIL THEN EXIT END; 
      YD:=YD-1; ADV(D, DL,D); 
      FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
(*4*) (*use criterions to chek if the reduction is necessary. *) 
      LOOP
      IF EVT(PLI, PLJ, L) <> 1 THEN EXIT END;
      X3:=X3+1; SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT END; 
      X4:=X4+1; SL:=DIGBC4(PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT END; 
(*5*) (*reduction step. *) 
      XS:=XS+1; S:=DIRPSP(PLI,PLJ); 
      IF S = 0 THEN EXIT END; 
      XH:=XH+1; H:=DIRPNF(PP,S); 
      IF H = 0 THEN EXIT END; 
      H:=DIRPMC(H); SL:=DIRPON(H);
      IF SL = 1 THEN PP:=LIST1(H); RETURN(PP); END;
      IF TF >= 1 THEN 
         AWRITE(TIME()-T); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); 
         AWRITE(YD); SWRITE(" PAIRS LEFT."); BLINES(0); 
         SWRITE("H="); DIRPWR(H,VL,-1); BLINES(0); END; 
      IF TF >= 2 THEN 
         AWRITE(X3); SWRITE(" CRIT3,  "); 
         AWRITE(X4); SWRITE(" CRIT4,  "); 
         AWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1);  
         END; 
      D:=DILUPL(H,PP,D,B); YD:=LENGTH(D);
      EXIT END;
END; 
(*6*) (*finish. *) 
      IF TF >= 1 THEN 
         AWRITE(TIME()-T); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); 
         AWRITE(YD); SWRITE(" PAIRS LEFT."); BLINES(0); 
         END; 
      IF TF >= 2 THEN 
         AWRITE(X3); SWRITE(" CRIT3,  "); 
         AWRITE(X4); SWRITE(" CRIT4,  "); 
         AWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1); 
         END; 
      PP:=DIGBMI(PP); 
(*9*) RETURN(PP); END GBE;

(* 
PROCEDURE GBE(PL, SANZ, L : LIST): LIST;
(* Groebner Base with Exponent Vector Check. Berechnung der Groebner Basis 
von PL unter Beruecksichtigung des Exponentenvektors der Hoechsten Terme.
S-Polynome werden nur bei solchen Polynomen gebildet, deren HT-Exponen-
tenvektor in den ersten L Stellen uebereinstimmt. *)
VAR   SL, EL, P1, P2, PPL, B, SP, SPN, TW1, TW2, TW3, SZ, C1, C2, C3 : LIST;
BEGIN
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        IF EVT(P1, P2, L) <> 1 THEN EXIT; END;

        (* versuchsweise *) 
      EL:=EVLCM(DIPEVL(P1),DIPEVL(P2));
      SL:=DIGBC3(B,P1,P2,EL); 
      IF SL = 0 THEN EXIT END; 
      SL:=DIGBC4(P1,P2,EL); 
      IF SL = 0 THEN EXIT END; 
        (* versuchs ende *) 

        C2 := C2 + 1;
        SP := DIRPSP(P1, P2);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                           SWRITE(' sec.  0-MGB '); BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        TW1 := DIRPNF(PL, SP);
        IF TW1 = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                           SWRITE(' sec.  0-RedMGB ');
                           BLINES(0); END;
          EXIT;
        END;
        (* SPN := DIRPMC(SP); fehler ??????????????? *)
        SPN := DIRPMC(TW1);
        IF SANZ = 2 THEN SWRITE("GBE, NF: "); OWRITE(SPN); BLINES(1); END;
        TW2 := DIRPON(SPN);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN)); (* ??????????? *)
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); SWRITE(' sec.  Neu-MGB ');
                         BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        PPL := DILUPL(SPN, PL, PPL, B ); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    (* PL := DIRLIS(PL); *)
    PL:=DIGBMI(PL);
    RETURN(PL);
END GBE;
*) 

PROCEDURE GBF(PL, SANZ: LIST; VAR GBTM : LIST): LIST;
(* Groebner Base with Factors. Groebner Basis Berechnung mit Faktoren.
Waehrend des Programmdurchlaufs wird die ''Entstehungsgeschichte'' der
Groebner Basis von PL dokumentiert, d.h. jedes neu hinzugenommene
Basispolynom wird dargestellt durch Faktoren GBTM bezogen auf die
Ausgangspolynome. *)
VAR   P1, P2, PPL, B, SP, SP1, SPAK, SPN, SPFL, SZ, C1, C2, C3, TW2 : LIST;
BEGIN
    NORMF(PL, GBTM);
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        C2 := C2 + 1;
        SPC(P1, P2, SPFL, SP);
        SP1 := SP;
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
             SWRITE(' sec.  0 '); BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        SPAK := RCSPR(PL, SP);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
             SWRITE(' sec.  0-Red '); BLINES(0); END;
          EXIT;
        END;
        SPN := DIRPMC(SP);
        TW2 := DIRPON(SPN);
        GBTM := BGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, GBTM);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN));
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); SWRITE(' sec.  Neu '); 
                         BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
        PPL := DILUPL(SPN, PL, PPL, B ); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
    RETURN(PL);
END GBF;


PROCEDURE GBEF(PL, SANZ, L : LIST; VAR GBTM : LIST): LIST;
(* Groebner Base with Exponent Vector Check and Factors. Kombination der
Eigenschaften der Funktionen GBE und GBF. *)
VAR   P1, P2, PPL, B, SPFL, SP, SP1, SZ, C1, C2, C3, SPN, SPAK, 
      TW2 : LIST;
BEGIN
    NORMF(PL, GBTM);
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        IF EVT(P1, P2, L) <> 1 THEN EXIT; END;
        C2 := C2 + 1;
        SPC(P1, P2, SPFL, SP);
        SP1 := SP;
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); SWRITE(' sec.  0 '); 
                           BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        SPAK := RCSPR(PL, SP);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); SWRITE(' sec.  0-Red ');
                           BLINES(0); END;
          EXIT;
        END;
        SPN := DIRPMC(SP);
        TW2 := DIRPON(SPN);
        GBTM := BGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, GBTM);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN));
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); SWRITE(' sec.  Neu '); 
                         BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
        PPL := DILUPL(SPN, PL, PPL, B ); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
    RETURN(PL);
END GBEF;


PROCEDURE NLGBE(PL, SANZ, L : LIST; VAR T : LIST): LIST;
(* Non-Commutative Groebner Base with Exponent Vector Check. Berechnung der
Groebner Basis von PL unter Beruecksichtigung des Exponentenvektors der
Hoechsten Terme. S-Polynome werden nur bei solchen Polynomen gebildet, deren
HT-Exponentenvektor in den ersten L Stellen uebereinstimmt. *)
VAR   P1, P2, PPL, B, SP, SPN, SZ, C1, C2, C3, TW1, TW2 : LIST;
BEGIN
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        IF EVT(P1, P2, L) <> 1 THEN EXIT; END;
        C2 := C2 + 1;
        SP := DINLSP(T, P1, P2);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                           SWRITE(' sec.  0-MGB '); BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        SPN := DINLNF(T, PL, SP);
        IF SPN = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                           SWRITE(' sec.  0-RedMGB ');
                           BLINES(0); END;
          EXIT;
        END;
        SPN := DIRPMC(SPN);
        TW2 := DIRPON(SPN);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN));
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                         SWRITE(' sec.  Neu-MGB ');
                         BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        PPL := DILUPL(SPN,PL,PPL,B); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    PL := DINLIS(T, PL);
    RETURN(PL);
END NLGBE;


PROCEDURE NLGBF(PL, SANZ: LIST; VAR GBTM, T: LIST): LIST;
(* Non-Commutative Groebner Base with Factors. Groebner Basis Berechnung mit
Faktoren. W"ahrend des Programmdurchlaufs wird die ''Entstehungsgeschichte''
der Groebner Basis von PL dokumentiert, d.h. jedes neu hinzugenommene
Basispolynom wird dargestellt durch Faktoren GBTM bezogen auf die
Ausgangspolynome. *)
VAR   P1, P2, PPL, B, SPFL, SP, SP1, SPN, SZ, C1, C2, C3, TW1, 
      TW2, SPAK : LIST;
BEGIN
    NORMF(PL, GBTM);
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        C2 := C2 + 1;
        NLSPC(P1, P2, SPFL, SP, T);
        SP1 := SP;
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
             SWRITE(' sec.  0 '); BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        SPAK := NLRCSPR(PL, SP, T);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                           SWRITE(' sec.  0-Red ');
                           BLINES(0); END;
          EXIT;
        END;
        SPN := DIRPMC(SP);
        TW2 := DIRPON(SPN);
        GBTM := NLBGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, GBTM, T);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN));
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
                         SWRITE(' sec.  Neu '); BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
        PPL := DILUPL(SPN,PL,PPL,B); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
    RETURN(PL);
END NLGBF;


PROCEDURE NLGBEF(PL, SANZ, L : LIST; VAR GBTM, T : LIST): LIST;
(* Non-Commutative Groebner Base with Exponent Vector Check and Factors.
Kombination der Eigenschaften der Funktionen NGBE und NGBF. *)
VAR   P1, P2, PPL, B, SPFL, SP, SP1, SPN,SZ, C1, C2, C3, TW2, SPAK : LIST;
BEGIN
    NORMF(PL, GBTM);
    DILCPL(PL, PPL, B);
    C3 := LENGTH(PPL); SZ := TIME(); C2 := 0; C1 := 0;
    LOOP
      IF PPL = SIL THEN EXIT; END;
      C3 := C3 - 1;
      NEXTPAIR(P1, P2, PPL);
      LOOP
        IF EVT(P1, P2, L) <> 1 THEN EXIT; END;
        C2 := C2 + 1;
        NLSPC(P1, P2, SPFL, SP, T);
        SP1 := SP;
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
             SWRITE(' sec.  0 '); BLINES(0); END;
          EXIT;
        END;
        C1 := C1 + 1;
        SPAK := NLRCSPR(PL, SP, T);
        IF SP = 0 THEN
          IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
             SWRITE(' sec.  0-Red '); BLINES(0); END;
          EXIT;
        END;
        SPN := DIRPMC(SP);
        TW2 := DIRPON(SPN);
        GBTM := NLBGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, GBTM, T);
        IF TW2 = 1 THEN
          PL := CCONC(PL, LIST1(SPN));
          RETURN(PL);
        END;
        IF SANZ = 1 THEN AWRITE(TIME() - SZ); 
           SWRITE(' sec.  Neu '); BLINES(0); END;
        IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
        IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
        PPL := DILUPL(SPN,PL,PPL,B); C3 := LENGTH(PPL);
        EXIT;
      END;
    END;
    IF SANZ = 2 THEN WRS1(SZ, C1, C2, C3); END;
    IF SANZ = 3 THEN WRS2(SZ, C1, SPN, C2, SP1, C3); END;
    RETURN(PL);
END NLGBEF;


END SYZGB.

(* -EOF- *)
