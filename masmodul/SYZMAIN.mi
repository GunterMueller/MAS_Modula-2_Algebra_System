(* ----------------------------------------------------------------------------
 * $Id: SYZMAIN.mi,v 1.3 1992/10/15 16:29:23 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZMAIN.mi,v $
 * Revision 1.3  1992/10/15  16:29:23  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:21  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYZMAIN;

(* Syzygy Main Programs Implementation Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM DIPRN   IMPORT DIRPDF, DIRPNG, DIRPPR, DIRPQ, DIRPSM;

FROM DIPRNGB IMPORT DIRPNF, DIRLIS;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM MASNC   IMPORT DINPPR, EVZERO;

FROM MASNCGB IMPORT DINLNF;

FROM MASSTOR IMPORT ADV, FIRST, LENGTH, LIST, LIST1, RED, SIL, TIME;

FROM SACLIST IMPORT AWRITE, CCONC, LWRITE;

FROM SYZFUNC IMPORT RCSP, NLRCSP, NLDGBRED, NLPLMULT, NLSPCEGB, NLSPCGB,
             NLMMULT, DGBRED, PLMULT, SPCEGB, SPCGB, SYGB, SYGBE, MMULT,
             SYONP, NLSYONP;

FROM SYZGB   IMPORT GBEF, GBF, MGB, NLGBEF, NLGBF, NLMGB;

FROM SYZHLP  IMPORT ALFA, ALFRA, EVR, EX0PL, GENPOSV, INSPOSV,
                    MTPLH, PLHTP, PLWR, TA, TR, VMADD;

CONST rcsidi = "$Id: SYZMAIN.mi,v 1.3 1992/10/15 16:29:23 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE SYHC(PM, SANZ, SRD : LIST): LIST;
(* Syzygy for homogenous commutative system of equation. Berechnet die
Syzygien fuer ein kommutatives Gleichungssystem. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen. *)
VAR   SY, PL, L : LIST;
BEGIN
    L := LENGTH(PM);
    IF L = 1 THEN
      PL := FIRST(PM);
      SY := HEQ(PL, SANZ, SRD);
    ELSE
      SY := HSEQ(PM, SANZ, SRD);
    END;
    RETURN(SY);
END SYHC;


PROCEDURE HEQ(PL, SANZ, SRD : LIST): LIST;
(* Homogenous Equation. Berechnet den Syzygienmodul fuer eine Gleichung mit 
den Polynomen aus PL. Das Bit SRD steuert eine moegliche Reduktion waehrend 
des Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)
VAR   SY, SY1, SY2, GBTM, GB, GBR, POSV, SPFL, SPL, SPAK : LIST;
BEGIN
    GB := GBF(PL, SANZ, GBTM);
    SY1 := SIL;
    IF (SRD = 1) THEN
      GBR := DGBRED(GB, GBTM, SY1);
      IF LENGTH(GBR) = 1 THEN
        RETURN(SY1);
      END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR
    END;
    SPCGB(GB, SPFL, SPL);
    SPAK := RCSP(GB, SPL);
    SY2 := SYGB(SPFL, SPAK);
    IF (SRD = 1) THEN
      SY2 := INSPOSV(SY2, POSV);
    END;
    SY2 := MMULT(SY2, GBTM);
    SY2 := CCONC(SY1, SY2);
    IF (SRD = 1) THEN
      SY2 := MGB(SY2, SANZ);
    END;
    RETURN(SY2);
END HEQ;


PROCEDURE HSEQ(PM, SANZ, SRD : LIST): LIST;
(* Homogenous System of Equation. Berechnet den Syzygienmodul fuer das
Gleichungssystem mit den Polynomen aus der Matrix PM. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)
VAR   NV, L, GB, SPFL, SPAK, GBTM, SY, SY1, SY2, PL, SPL, POSV,
      PL1, TW1, TW2, GBR, POSV1 : LIST;
BEGIN
    SY:=SIL; (*hk*)
    PL := MTPLH(PM, L);
    PL1 := EX0PL(PL);
    POSV := GENPOSV(PL, PL1);
    PL := PL1;
    ALFA(L);
    GB := GBEF(PL, SANZ, L, GBTM);
    IF (SRD = 1) THEN
      GBR := DGBRED(GB, GBTM, SY);
      SY := EVR(SY, L);
      IF LENGTH(GBR) = 1 THEN
        ALFRA(L);
        RETURN(SY);
      END;
      POSV1 := GENPOSV(GB, GBR);
      GB := GBR
    END;
    SPCEGB(GB, L, SPFL, SPL);
    SPAK := RCSP(GB, SPL);
    SY1 := SYGBE(SPFL, SPAK);
    IF (SRD = 1) THEN
      SY1 := INSPOSV(SY1, POSV1);
    END;
    SY2 := MMULT(SY1, GBTM);
    SY2 := EVR(SY2, L);
    SY2 := INSPOSV(SY2, POSV);
    ALFRA(L);
    SY2 := CCONC(SY, SY2);
    IF (SRD = 1) THEN
      SY2 := MGB(SY2, SANZ);
    END;
    RETURN(SY2);
END HSEQ;


PROCEDURE SYTHC(SY, PM, VL : LIST);
(* Syzygy Test for homogenous commutative Case. Testet, ob der berechnete
Loesungsgenerator SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten der Gleichungen werden ausgegeben. *)
VAR   P, PL : LIST;
BEGIN
    SY := VMADD(SY);
    BLINES(0);
    SWRITE('VMADD:');
    BLINES(0);
    PLWR(SY,VL);
    BLINES(1);
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      P := PLMULT(SY, PL);
      SWRITE(' SYZYGIEN-TEST:  ');
      PLWR(LIST1(P), VL);
      BLINES(0);
    END;
END SYTHC;


PROCEDURE SIC(PM, PL, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative system of equation.
Berechnet eine spezielle Loesung fuer ein kommutatives Gleichungssystem PM.
Die Polynome der rechten Seite stehen in der Liste PL. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)
VAR   SY, P, PL1, L : LIST;
BEGIN
    L := LENGTH(PM);
    IF L = 1 THEN
      PL1 := FIRST(PM);
      P := FIRST(PL);
      SY := IEQ(PL1, P, SANZ, SRD);
    ELSE
      SY := ISEQ(PM, PL, SANZ, SRD);
    END;
    RETURN(SY);
END SIC;


PROCEDURE IEQ(PL, P, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative equation. Berechnet eine
spezielle Loesung fuer eine lineare Gleichung PL. Das Polynom der rechten
Seite ist P. Das Bit SRD steuert eine moegliche Reduktion waehrend des
Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)
VAR   SY, TW1, H, L, TW2, GBTM, GB, GBR, POSV, SPAK : LIST;
BEGIN
    GB := GBF(PL, SANZ, GBTM);
    TW2 := DIRPNF(GB, P);
    IF TW2 <> 0 THEN
      BLINES(1); SWRITE('IEQ: Gleichung nicht loesbar! '); RETURN(SIL);
    END;
    IF (SRD = 1) THEN
      GBR := DGBRED(GB, GBTM, H);
      IF LENGTH(GBR) = 1 THEN RETURN(SIL); END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    SPAK := RCSP(GB, LIST1(P));
    IF (SRD = 1) THEN
      SPAK := INSPOSV(SPAK, POSV);
    END;
    SY := MMULT(SPAK, GBTM);
    SY := FIRST(SY);
    RETURN(SY);
END IEQ;


PROCEDURE ISEQ(PM, PL, SANZ, SRD : LIST): LIST;
(* Special Solution for inhomogenous commutative system of equation.
Berechnet eine spezielle Loesung fuer ein kommutatives Gleichungssystem PM.
Die Polynome der rechten Seite stehen in der Liste PL. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen.*)
VAR   L, GB, GBR, SPAK, GBTM, SY, H, POSV, POSV1, P, PL1, PL2,
      TW1, TW2, TW3, TW4 : LIST;
BEGIN
    PL1 := MTPLH(PM, L);
    P := PLHTP(PL);
    PL2 := EX0PL(PL1);
    POSV1 := GENPOSV(PL1, PL2);
    PL1 := PL2;
    ALFA(L);
    GB := GBEF(PL1, SANZ, L, GBTM);
    TW4 := DIRPNF(GB, P);
    IF TW4 <> 0 THEN
      BLINES(1); SWRITE('ISEQ: Gleichungssystem nicht loesbar! ');
      ALFRA(L); RETURN(SIL);
    END;
    IF (SRD = 1) THEN
      GBR := DGBRED(GB, GBTM, H);
      IF LENGTH(GBR) = 1 THEN
        ALFRA(L);
        RETURN(SIL);
      END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    SPAK := RCSP(GB, LIST1(P));
    IF (SRD = 1) THEN
      SPAK := INSPOSV(SPAK, POSV);
    END;
    SY := MMULT(SPAK, GBTM);
    SY := INSPOSV(SY, POSV1);
    SY := FIRST(EVR(SY, L));
    ALFRA(L);
    RETURN(SY);
END ISEQ;


PROCEDURE STIC(SY, PM, PL, VL : LIST);
(* Solution Test for inhomogenous commutative Case. Testet, ob der berechnete
Loesungsvektor SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten werden von denen der rechten Seite abgezogen,
und das Ergebnis dieser Differenz wird ausgegeben. *)
VAR   P1, P2, PL1 : LIST;
BEGIN
    IF (SY = SIL) THEN RETURN; END;
    BLINES(1);
    WHILE PM <> SIL DO
      ADV(PM, PL1, PM);
      ADV(PL, P1, PL);
      P2 := PLMULT(SY, PL1);
      P2 := DIRPDF(P2, P1);
      SWRITE(' GLEICHUNGS-TEST:  ');
      PLWR(LIST1(P2), VL);
      BLINES(0);
    END;
END STIC;


PROCEDURE SYHNL(PM, SANZ, SRD, T : LIST): LIST;
(* Syzygy for homogenous non-commutative system of equation. Berechnet die
Syzygien fuer ein nicht-kommutatives Gleichungssystem. Das Bit SRD steuert
eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die
Anzeigeart von Zwischenergebnissen. *)
VAR   SY, L, PL : LIST;
BEGIN
    L := LENGTH(PM);
    IF L = 1 THEN
      PL := FIRST(PM);
      SY := NLHEQ(PL, SANZ, SRD, T);
    ELSE
      SY := NLHSEQ(PM, SANZ, SRD, T);
    END;
    RETURN(SY);
END SYHNL;


PROCEDURE NLHEQ(PL, SANZ, SRD, T : LIST): LIST;
(* Non-Commutative Homogenous Equation. Berechnet den Syzygienmodul fuer eine
Gleichung mit den Polynomen aus PL. Das Bit SRD steuert eine moegliche
Reduktion waehrend des Verfahrens. Das Bit SANZ regelt die Anzeigeart von
Zwischenergebnissen.*)
VAR   NV, SY, SY1, SY2, L, TW, GBTM, GB, GBR, POSV, SPFL, SPL, SPAK : LIST;
BEGIN
    SY1:=SIL; (*hk*)
    GB := NLGBF(PL, SANZ, GBTM, T);
    IF (SRD = 1) THEN
      GBR := NLDGBRED(GB, GBTM, SY1, T);
      IF LENGTH(GBR) = 1 THEN
        RETURN(SY1);
      END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    NLSPCGB(GB, SPFL, SPL, T);
    SPAK := NLRCSP(GB, SPL, T);
    SY2 := SYGB(SPFL, SPAK);
    IF (SRD = 1) THEN
      SY2 := INSPOSV(SY2, POSV);
    END;
    SY2 := NLMMULT(SY2, GBTM, T);
    SY2 := CCONC(SY1, SY2);
    IF (SRD = 1) THEN
      SY2 := NLMGB(SY2, SANZ, T);
    END;
    RETURN(SY2);
END NLHEQ;


PROCEDURE NLHSEQ(PM, SANZ, SRD, T : LIST): LIST;
(* Non-Commutative Homogenous System of Equation. Berechnet den Syzygienmodul
fuer das Gleichungssystem mit den Polynomen aus der Matrix PM. Das Bit SRD
steuert eine moegliche Reduktion waehrend des Verfahrens. Das Bit SANZ regelt
die Anzeigeart von Zwischenergebnissen.*)
VAR   L1, L2, GB, GBR, SPFL, SPAK, GBTM, SY, SY1, SY2,  PL, PL1, POSV,
      POSV1, SPL, TW1, TW2 : LIST;
BEGIN
    SY1:=SIL; (*hk*) 
    PL := MTPLH(PM, L1);
    PL1 := EX0PL(PL);
    POSV := GENPOSV(PL, PL1);
    PL := PL1;
    ALFA(L1);
    T := TA(L1, T);
    GB := NLGBEF(PL, SANZ, L1, GBTM, T);
    IF (SRD = 1) THEN
      GBR := NLDGBRED(GB, GBTM, SY1, T);
      SY1 := EVR(SY1, L1);
      IF LENGTH(GBR) = 1 THEN
        T := TR(L1, T);
        ALFRA(L1);
        RETURN(SY1);
      END;
      POSV1 := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    NLSPCEGB(GB, L1, SPFL, SPL, T);
    SPAK := NLRCSP(GB, SPL, T);
    SY2 := SYGBE(SPFL, SPAK);
    IF (SRD = 1) THEN
      SY2 := INSPOSV(SY2, POSV1);
    END;
    SY2 := NLMMULT(SY2, GBTM, T);
    SY2 := EVR(SY2, L1);
    SY2 := INSPOSV(SY2, POSV);
    ALFRA(L1);
    T := TR(L1, T);
    SY2 := CCONC(SY1, SY2);
    IF (SRD = 1) THEN
      SY2 := NLMGB(SY2, SANZ, T);
    END;
    RETURN(SY2);
END NLHSEQ;


PROCEDURE SYTHNL(SY, PM, VL, T : LIST);
(* Syzygy Test for homogenous non-commutative Case. Testet, ob der berechnete
Loesungsgenerator SY jede einzelne Gleichung von PM loest. Die Polynome
der errechnten linken Seiten der Gleichungen werden ausgegeben. *)
VAR   P, PL : LIST;
BEGIN
    SY := VMADD(SY);
    BLINES(1);
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      P := NLPLMULT(SY, PL, T);
      SWRITE(' N-SYZYGIEN-TEST:  ');
      PLWR(LIST1(P), VL);
      BLINES(0);
    END;
END SYTHNL;


PROCEDURE SINL(PM, PL, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative system of equation.
Berechnet eine spezielle Loesung fuer ein nicht-kommutatives Gleichungs-
system PM. Die Polynome der rechten Seite stehen in der Liste PL. Das
Bit SRD steuert eine moegliche Reduktion waehrend des Verfahrens. Das
Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)
VAR   SY, PL1, P, L : LIST;
BEGIN
    L := LENGTH(PM);
    IF L = 1 THEN
      PL1 := FIRST(PM);
      P := FIRST(PL);
      SY := NLIEQ(PL1, P, SANZ, SRD, T);
    ELSE
      SY := NLISEQ(PM, PL, SANZ, SRD, T);
    END;
    RETURN(SY);
END SINL;


PROCEDURE NLIEQ(PL, P, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative equation. Berechnet eine
spezielle Loesung fuer eine lineare Gleichung PL. Das Polynom der rechten
Seite ist P. Das Bit SRD steuert eine moegliche Reduktion waehrend des
Verfahrens. Das Bit SANZ regelt die Anzeigeart von Zwischenergebnissen.*)
VAR   SY, L, H, TW1, TW2, GBTM, GB, GBR,  POSV, SPAK : LIST;
BEGIN
    GB := NLGBF(PL, SANZ, GBTM, T);
    TW2 := DINLNF(T, GB, P);
    IF TW2 <> 0 THEN
      BLINES(1); SWRITE('INLEQ: Gleichung nicht loesbar! '); RETURN(SIL);
    END;
    IF (SRD = 1) THEN
      GBR := NLDGBRED(GB, GBTM, H, T);
      IF LENGTH(GBR) = 1 THEN RETURN(SIL); END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    SPAK := NLRCSP(GB, LIST1(P), T);
    IF (SRD = 1) THEN
      SPAK := INSPOSV(SPAK, POSV);
    END;
    SY := NLMMULT(SPAK, GBTM, T);
    RETURN(FIRST(SY));
END NLIEQ;


PROCEDURE NLISEQ(PM, PL, SANZ, SRD, T : LIST): LIST;
(* Special Solution for inhomogenous non-commutative system of equation.
Berechnet eine spezielle Loesung fuer ein nicht-kommutatives Gleichungs-
system PM. Die Polynome der rechten Seite stehen in der Liste PL. Das
Bit SRD steuert eine moegliche Reduktion waehrend des Verfahrens. Das Bit
SANZ regelt die Anzeigeart von Zwischenergebnissen.*)
VAR   L, H, GB, GBR, SPAK, GBTM, SY,  PL1, PL2, TW1, TW2, TW3, TW4,
      POSV, POSV1, P : LIST;
BEGIN
    PL1 := MTPLH(PM, L);
    P := PLHTP(PL);
    PL2 := EX0PL(PL1);
    POSV1 := GENPOSV(PL1, PL2);
    PL1 := PL2;
    ALFA(L);
    T := TA(L, T);
    GB := NLGBEF(PL1, SANZ, L, GBTM, T);
    TW4 := DINLNF(T, GB, P);
    IF TW4 <> 0 THEN
      BLINES(1); SWRITE('INLSEQ: Gleichungssystem nicht loesbar! ');
      ALFRA(L); T := TR(L, T); RETURN(SIL);
    END;
    IF (SRD = 1) THEN
      GBR := NLDGBRED(GB, GBTM, H, T);
      IF LENGTH(GBR) = 1 THEN
        ALFRA(L);
        T := TR(L, T);
        RETURN(SIL);
      END;
      POSV := GENPOSV(GB, GBR);
      GB := GBR;
    END;
    SPAK := NLRCSP(GB, LIST1(P), T);
    IF (SRD = 1) THEN
      SPAK := INSPOSV(SPAK, POSV);
    END;
    SY := NLMMULT(SPAK, GBTM, T);
    SY := INSPOSV(SY, POSV1);
    SY := FIRST(EVR(SY, L));
    ALFRA(L);
    T := TR(L, T);
    RETURN(SY);
END NLISEQ;


PROCEDURE STINL(SY, PM, PL, VL, T : LIST);
(* Solution Test for inhomogenous non-commutative Case. Testet, ob der
berechnete Loesungsvektor SY jede einzelne Gleichung von PM loest. Die
Polynome der errechnten linken Seiten werden von denen der rechten Seite
abgezogen, und das Ergebnis dieser Differenz wird ausgegeben. *)
VAR   P1, PL1, P  : LIST;
BEGIN
    IF (SY = SIL) THEN RETURN; END;
    BLINES(1);
    WHILE PM <> SIL DO
      ADV(PM, PL1, PM);
      ADV(PL, P, PL);
      P1 := NLPLMULT(SY, PL1, T);
      P1 := DIRPDF(P1, P);
      SWRITE(' N-GLEICHUNGS-TEST:  ');
      PLWR(LIST1(P1), VL);
      BLINES(0);
    END;
END STINL;


PROCEDURE OREC(P1, P2 : LIST; VAR P3, P4, T : LIST);
(* Ore Condition. Fuer gegebene Polynome P1 und P2 werden Polynome P3 und P4
berechnet, sodass P3*P1 = P4*P2. Die Multiplikation * ist die nicht-
kommutative Multiplikation. *)
VAR   PL1, PL2, SY : LIST;
BEGIN
    P2 := DIRPNG(P2);
    PL1 := CCONC(LIST1(P1), LIST1(P2));
    SY := NLHEQ(PL1, 1, 0, T);
    PL2 := VMADD(SY);
    P3 := FIRST(PL2);
    P4 := DIRPNG(FIRST(RED(PL2)));
    RETURN;
END OREC;


END SYZMAIN.

(* -EOF- *)
