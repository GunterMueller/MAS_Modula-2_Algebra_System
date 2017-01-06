(* ----------------------------------------------------------------------------
 * $Id: SYZFUNC.mi,v 1.4 1995/11/04 18:00:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZFUNC.mi,v $
 * Revision 1.4  1995/11/04 18:00:51  pesch
 * Changed comments violating documentation rules.
 *
 * Revision 1.3  1992/10/15  16:29:20  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:16  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:57  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYZFUNC;

(* Syzygy Functions Implementation Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM DIPC    IMPORT DIPEVL, DIPFMO, DIPMAD, EVDEL, EVDIF, EVLCM, EVMT, 
                    DIPINV, DIPLBC, DIPMPV, DIPLPM, VALIS;

FROM DIPRN   IMPORT DIRPDF, DIRPNG, DIRPPR, DIRPQ, DIRPRP, DIRPSM;

FROM DIPRNGB IMPORT DIRPNF;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM MASNC   IMPORT DINPPR, EVZERO;

FROM MASNCGB IMPORT DINLNF;

FROM MASSTOR IMPORT ADV, FIRST, LIST, LIST1, RED, SIL, LENGTH;

FROM SACLIST IMPORT ADV2, AWRITE, LWRITE, CCONC;

FROM SACRN   IMPORT RNINT, RNQ;

FROM SYZHLP  IMPORT ADDLAST, APP0, EVT, EXPPL, PLWR, POS, POL, EVL, 
                    ADDPPOS, GBTMRED, GENPOSV;

CONST rcsidi = "$Id: SYZFUNC.mi,v 1.4 1995/11/04 18:00:51 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE SPC(P1, P2 : LIST; VAR SPFL, SP : LIST);
(* S-Polynomial with Coefficients. Berechnet das S-Pol SP von P1 und P2,
und speichert die zugehoerigen Faktoren Uij und Vij in dieser Reihenfolge
unter SPFL ab. *)
VAR   SP1, SP2, KO1, KO2, EV1, EV2, H, EV3, EV31, EV32, SPF1, SPF2 : LIST;
BEGIN
    DIPMAD(P1, KO1, EV1, H);
    DIPMAD(P2, KO2, EV2, H);
    EV3 := EVLCM(EV1,EV2);
    EV31 := EVDIF(EV3, EV1);
    EV32 := EVDIF(EV3, EV2);
    SPF1 := DIPFMO(KO2, EV31);
    SPF2 := DIPFMO(KO1, EV32);
    SPFL := CCONC(LIST1(SPF1), LIST1(SPF2));
    SP1 := DIRPPR(SPF1, P1);
    SP2 := DIRPPR(SPF2, P2);
    SP := DIRPDF(SP1,SP2);
    RETURN;
END SPC;


PROCEDURE NLSPC(P1, P2 : LIST; VAR SPFL, SP, T : LIST);
(* Non-Commutative S-Polynomial with Coefficients. Berechnet nicht-
kommutative das S-Pol SP von P1 und P2, und speichert die zugehoerigen
Faktoren Uij und Vij in dieser Reihenfolge unter SPFL ab. *)
VAR   SP1, SP2, KO1, KO2, EV1, EV2, EV3, EV31, EV32, RZ,
      SPF1, SPF2 : LIST;
BEGIN
    EV1 := DIPEVL(P1);
    EV2 := DIPEVL(P2);
    EV3 := EVLCM(EV1, EV2);
    EV31 := EVDIF(EV3, EV1);
    EV32 := EVDIF(EV3, EV2);
    RZ := RNINT(1);
    SPF1 := DIPFMO(RZ, EV31);
    SPF2 := DIPFMO(RZ, EV32);
    SP1 := DINPPR(T, SPF1, P1);
    SP2 := DINPPR(T, SPF2, P2);
    KO1 := DIPLBC(SP1);
    KO2 := DIPLBC(SP2);
    SP1 := DIRPRP(SP1, KO2);
    SP2 := DIRPRP(SP2, KO1);
    SPF1 := DIRPRP(SPF1, KO2);
    SPF2 := DIRPRP(SPF2, KO1);
    SPFL := CCONC(LIST1(SPF1), LIST1(SPF2));
    SP := DIRPDF(SP1, SP2);
    RETURN;
END NLSPC;


PROCEDURE SPCGB(GB : LIST; VAR SPFL, SPL : LIST);
(* S-Polynomials with Coefficients for Groebner Base. Berechnet die 
S-Polynome aller Polynome in GB und speichert diese in SPL ab. Die 
zugehoerigen Faktoren Uij und Vij aller S-Polynome werden in dieser 
Reihenfolge unter SPFL abgelegt. *)
VAR   GB1, P1, P2, SPFL1, SP : LIST;
BEGIN
    SPFL := SIL;
    SPL := SIL;
    WHILE RED(GB) <> SIL DO
      GB1 := RED(GB);
      ADV(GB, P1, GB);
      WHILE GB1 <> SIL DO
        ADV(GB1, P2, GB1);
        SPC(P1, P2, SPFL1, SP);
        SPFL := CCONC(SPFL, SPFL1);
        SPL := CCONC(SPL, LIST1(SP));
      END;
    END;
    RETURN;
END SPCGB;


PROCEDURE NLSPCGB(GB : LIST; VAR SPFL, SPL, T : LIST);
(* Non-Commutative S-Polynomials with Coefficients for Groebner Base. 
Berechnet die nicht-kommutativen S-Polynome aller Polynome in GB und 
speichert diese in SPL ab. Die zugehoerigen Faktoren Uij und Vij aller 
S-Polynome werden in dieser Reihenfolge unter SPFL abgelegt. *)
VAR   GB1, P1, P2, SPFL1, SP : LIST;
BEGIN
    SPFL := SIL;
    SPL := SIL;
    WHILE RED(GB) <> SIL DO
      GB1 := RED(GB);
      ADV(GB, P1, GB);
      WHILE GB1 <> SIL DO
        ADV(GB1, P2, GB1);
        NLSPC(P1, P2, SPFL1, SP, T);
        SPFL := CCONC(SPFL, SPFL1);
        SPL := CCONC(SPL, LIST1(SP));
      END;
    END;
    RETURN;
END NLSPCGB;


PROCEDURE SPCEGB(GB, L : LIST; VAR SPFL, SPL : LIST);
(* S-Polynomials with Coefficients and Exponenetvector-Check for Groebner Base.
Berechnet die S-Polynome aller Polynome in GB unter Beruecksichtigung der
Gleichheit der fuehrenden L Stellen des Exponenetenvektors der HT, und
speichert diese in SPL ab. Die zugehoerigen Faktoren Uij und Vij aller
S-Polynome werden in dieser Reihenfolge unter SPFL abgelegt. Konnte ein
S-Polynom nicht gebildet werden, dann wird an die Liste SPFL als
Steuerbit eine Null angehaengt. *)
VAR   GB1, P1, P2, SPFL1, SP : LIST;
BEGIN
    SPFL := SIL;
    SPL := SIL;
    WHILE RED(GB) <> SIL DO
      GB1 := RED(GB);
      ADV(GB, P1, GB);
      WHILE GB1 <> SIL DO
        ADV(GB1, P2, GB1);
        IF EVT(P1, P2, L) = 1 THEN
          SPC(P1, P2, SPFL1, SP);
          SPFL := CCONC(SPFL, SPFL1);
          SPL := CCONC(SPL, LIST1(SP));
        ELSE
          SPFL := CCONC(SPFL, LIST1(0));
        END;
      END;
    END;
    RETURN;
END SPCEGB;


PROCEDURE NLSPCEGB(GB, L : LIST; VAR SPFL, SPL, T : LIST);
(* Non-Commutative S-Polynomials with Coefficients and Exponenetvector-Check
for Groebner Base. Berechnet die nicht-kommutativen S-Polynome aller 
Polynome in GB unter Beruecksichtigung der Gleichheit der fuehrenden 
L Stellen des Exponenetenvektors der HT, und speichert diese in SPL ab. 
Die zugehoerigen Faktoren Uij und Vij aller S-Polynome werden in dieser 
Reihenfolge unter SPFL abgelegt. Konnte ein S-Polynom nicht gebildet 
werden, dann wird an die Liste SPFL als Steuerbit eine Null angehaengt. *)
VAR   GB1, P1, P2, SPFL1, SP : LIST;
BEGIN
    SPFL := SIL;
    SPL := SIL;
    WHILE RED(GB) <> SIL DO
      GB1 := RED(GB);
      ADV(GB, P1, GB);
      WHILE GB1 <> SIL DO
        ADV(GB1, P2, GB1);
        IF EVT(P1, P2, L) = 1 THEN
          NLSPC(P1, P2, SPFL1, SP, T);
          SPFL := CCONC(SPFL, SPFL1);
          SPL := CCONC(SPL, LIST1(SP));
        ELSE
          SPFL := CCONC(SPFL, LIST1(0));
        END;
      END;
    END;
    RETURN;
END NLSPCEGB;


PROCEDURE RCSP(GB, SPL : LIST): LIST;
(* Reduction Chain of S-Polynomials. Fuer alle S-Polynome in SPL werden
diejenigen Faktoren gespeichert, die noetig sind, um ein S-Polynom
bzgl. der Groebner Basis GB zu Null zu reduzieren.
Bsp.: Sei GB = (G1, G2, G3) und gelte SPi - P1 G1 - P2 G2 - P3 G1 = 0.
Dann hat die i-te Zeile der Ergebnismatrix die Gestalt: (P1+P3, P2, 0). *)
VAR   EV1, EV2, GB1, P1, P2, P3, NF, KO1, KO2, PL, NV, P, PR,
      H, POS, TW, SPAK : LIST;
BEGIN
    SPAK := SIL;
    NV := EVZERO(LENGTH(GB));
    WHILE SPL <> SIL DO
      ADV(SPL, PR, SPL);
      IF PR = 0 THEN
        SPAK := CCONC(SPAK, LIST1(NV));
      ELSE
        PL := NV;
        WHILE (PR <> 0) DO
          GB1 := GB;
          POS := 0;
          WHILE (GB1 <> SIL) AND (PR <> 0) DO
            ADV(GB1, P, GB1);
            POS := POS + 1;
            DIPMAD(PR, KO1, EV1, H);
            DIPMAD(P, KO2, EV2, H);
            TW := EVMT(EV1, EV2);
            IF TW = 1 THEN
              P1 := DIPFMO(KO1, EV1);
              P2 := DIPFMO(KO2, EV2);
              NF := DIRPQ(P1, P2);
              P3 := DIRPPR(NF, P);
              PR := DIRPDF(PR, P3);
              PL := ADDPPOS(PL, NF, POS);
            END;
          END;
        END;
        SPAK := CCONC(SPAK, LIST1(PL));
      END;
    END;
    RETURN(SPAK);
END RCSP;


PROCEDURE RCSPR(PL : LIST; VAR SP : LIST): LIST;
(* Reduction Chain of S-Polynomials with Remainder. Fuer das S-Polynome 
SP werden diejenigen Faktoren gespeichert, die noetig sind, um dieses 
S-Polynom bzgl. der Polynome in PL zu Null zu reduzieren. Konnte bei 
einem Durchlauf nicht mehr reduziert werden, dann bricht das Verfahren 
mit den bereits errechneten Werten ab.
Bsp.: Sei PL = (P1, P2, P3) und gelte SP - F1 P1 - F2 P2 - F3 P1 = 0.
Dann hat die Ergebniszeile die Gestalt: (F1+F3, F2, 0). *)
VAR   C, EV1, EV2, P1, P2, P3, NF, KO1, KO2, NV, P, PL1, H, POS,
      TW, SPAK : LIST;
BEGIN
    SPAK := EVZERO(LENGTH(PL));
    C := 1;
    WHILE (SP <> 0) AND (C = 1) DO
      PL1 := PL;
      POS := 0;
      C := 0;
      WHILE (PL1 <> SIL) AND (SP <> 0) DO
        ADV(PL1, P, PL1);
        POS := POS + 1;
        DIPMAD(SP, KO1, EV1, H);
        DIPMAD(P, KO2, EV2, H);
        TW := EVMT(EV1, EV2);
        IF TW = 1 THEN
          C := 1;
          P1 := DIPFMO(KO1, EV1);
          P2 := DIPFMO(KO2, EV2);
          NF := DIRPQ(P1, P2);
          P3 := DIRPPR(NF, P);
          SP := DIRPDF(SP, P3);
          SPAK := ADDPPOS(SPAK, NF, POS);
        END;
      END;
    END;
    RETURN(SPAK);
END RCSPR;


PROCEDURE NLRCSPR(PL : LIST; VAR SP, T : LIST): LIST;
(* Reduction Chain of S-Polynomials with Remainder. Fuer das S-Polynome 
SP werden diejenigen Faktoren gespeichert, die noetig sind, um dieses 
S-Polynom bzgl. der Polynome in PL zu Null zu reduzieren. Konnte bei 
einem Durchlauf nicht mehr reduziert werden, dann bricht das Verfahren 
mit den bereits errechneten Werten ab.
Bsp.: Sei PL = (P1, P2, P3) und gelte SP - F1 P1 - F2 P2 - F3 P1 = 0.
Dann hat die Ergebniszeile die Gestalt: (F1+F3, F2, 0). *)
VAR   C, EV1, EV2, P1, P2, P3, NF, KO, KO1, KO2, NV, P, PL1, H, POS,
      TW, SPAK : LIST;
BEGIN
    SPAK := EVZERO(LENGTH(PL));
    C := 1;
    WHILE (SP <> 0) AND (C = 1) DO
      PL1 := PL;
      POS := 0;
      C := 0;
      WHILE (PL1 <> SIL) AND (SP <> 0) DO
        ADV(PL1, P, PL1);
        POS := POS + 1;
        DIPMAD(SP, KO1, EV1, H);
        DIPMAD(P, KO2, EV2, H);
        TW := EVMT(EV1, EV2);
        IF TW = 1 THEN
          C := 1;
          NF := EVDIF(EV1, EV2);
          P1 := DIPFMO(RNINT(1), NF);
          P2 := DINPPR(T, P1, P);
          KO := RNQ(KO1, DIPLBC(P2));
          P2 := DIRPRP(P2, KO);
          SP := DIRPDF(SP, P2);
          P1 := DIRPRP(P1, KO);
          SPAK := ADDPPOS(SPAK, P1, POS);
        END;
      END;
    END;
    RETURN(SPAK);
END NLRCSPR;


PROCEDURE NLRCSP(GB, SPL : LIST; VAR T : LIST): LIST;
(* Non-Commutative Reduction Chain of S-Polynomials. Fuer alle S-Polynome 
in SPL werden diejenigen Faktoren gespeichert, die noetig sind, um 
eine S-Polynom bzgl. der Groebner Basis GB und der Kommutatorrelationen 
T zu Null zu reduzieren.
Bsp.: Sei GB = (G1, G2, G3) und gelte SPi - P1 G1 - P2 G2 - P3 G1 = 0.
Dann hat die i-te Zeile der Ergebnismatrix die Gestalt: (P1+P3, P2, 0). *)
VAR   EV1, EV2, GB1, P1, P2, P3, NF, KO, KO1, KO2, PL, NV, P, PR,
      H, POS, TW, SPAK : LIST;
BEGIN
    SPAK := SIL;
    NV := EVZERO(LENGTH(GB));
    WHILE SPL <> SIL DO
      ADV(SPL, PR, SPL);
      IF PR = 0 THEN
        SPAK := CCONC(SPAK, LIST1(NV));
      ELSE
        PL := NV;
        WHILE (PR <> 0) DO
          GB1 := GB;
          POS := 0;
          WHILE (GB1 <> SIL) AND (PR <> 0) DO
            ADV(GB1, P, GB1);
            POS := POS + 1;
            DIPMAD(PR, KO1, EV1, H);
            DIPMAD(P, KO2, EV2, H);
            TW := EVMT(EV1, EV2);
            IF TW = 1 THEN
              NF := EVDIF(EV1, EV2);
              P1 := DIPFMO(RNINT(1), NF);
              P2 := DINPPR(T, P1, P);
              KO := RNQ(KO1, DIPLBC(P2));
              P2 := DIRPRP(P2, KO);
              P1 := DIRPRP(P1, KO);
              PR := DIRPDF(PR, P2);
              PL := ADDPPOS(PL, P1, POS);
            END;
          END;
        END;
        SPAK := CCONC(SPAK, LIST1(PL));
      END;
    END;
    RETURN(SPAK);
END NLRCSP;


PROCEDURE SYGB(SPFL, SPAK : LIST): LIST;
(* Syzygy for Groebner Base. Berechnet wird aufgrund bereits erzeugter
Faktorenliste SPFL und den S-Polynom Ableitungsketten SPAK ein
Loesungsmodulgenerator fuer eine homogene Gleichung, wobei die Polynome
dieser Gleichung eine Groebner Basis bilden. *)
VAR   C1, C2, C3, C4, PL, PL1, P, P1, SPF1, SPF2, SY1 : LIST;
BEGIN
    SY1 := SIL;
    C3 := LENGTH(FIRST(SPAK));
    FOR C1 := 1 TO C3 - 1 DO
      FOR C2 := C1 + 1 TO C3 DO
        ADV2(SPFL, SPF1, SPF2, SPFL);
        ADV(SPAK, PL1, SPAK);
        PL := SIL;
        FOR C4 := 1 TO C3 DO
          ADV(PL1, P, PL1);
          IF (C4 <> C1) AND (C4 <> C2) THEN
            P1 := P;
          ELSIF (C4 = C1) THEN
            P1 := DIRPDF(P, SPF1);
          ELSIF (C4 = C2) THEN
            P1 := DIRPSM(P, SPF2);
          END;
          PL := CCONC(PL, LIST1(P1));
        END;
        SY1 := CCONC(SY1, LIST1(PL));
      END;
    END;
    RETURN(SY1);
END SYGB;


PROCEDURE SYGBE(SPFL, SPAK : LIST): LIST;
(* Syzygy for Groebner Base with Exponent Vector. Berechnet wird aufgrund
bereits erzeugter Faktorenliste SPFL und den S-Polynom Ableitungsketten 
SPAK ein Loesungsmodulgenerator fuer eine homogene Gleichung, wobei die 
Polynome dieser Gleichung eine Groebner Basis bilden. Hier wird das bei 
SPCEGB in die Faktorliste SPFL eingetragene Steuerbit 0 verwertet, das 
besagt, dass sofort ein neuer Schleifendurchlauf beginnen soll. *)
VAR   C1, C2, C3, C4, PL, PL1, P, P1, SPF1, SPF2, SY1 : LIST;
BEGIN
    SY1 := SIL;
    C3 := LENGTH(FIRST(SPAK));
    FOR C1 := 1 TO C3 - 1 DO
      FOR C2 := C1 + 1 TO C3 DO
        ADV(SPFL, SPF1, SPFL);
        IF SPF1 <> 0 THEN
          ADV(SPFL, SPF2, SPFL);
          ADV(SPAK, PL1, SPAK);
          PL := SIL;
          FOR C4 := 1 TO C3 DO
            ADV(PL1, P, PL1);
            IF (C4 <> C1) AND (C4 <> C2) THEN
              P1 := P;
            ELSIF (C4 = C1) THEN
              P1 := DIRPDF(P, SPF1);
            ELSIF (C4 = C2) THEN
              P1 := DIRPSM(P, SPF2);
            END;
            PL := CCONC(PL, LIST1(P1));
          END;
          SY1 := CCONC(SY1, LIST1(PL));
        END;
      END;
    END;
    RETURN(SY1);
END SYGBE;


PROCEDURE MMULT(SY1, GBTM : LIST): LIST;
(* Matrix Multiplication. Das Produkt der Matrizen SY1 * GBTM ergibt 
die Loesungsmatrix. *)
VAR   PL, PL1, PL2, PL3, P1, P2, P3, P4, GBTM1, SY2 : LIST;
BEGIN
    SY2 := SIL;
    WHILE SY1 <> SIL DO
      ADV(SY1, PL, SY1);
      PL2 := SIL;
      GBTM1 := GBTM;
      WHILE GBTM1 <> SIL DO
        ADV(GBTM1, PL3, GBTM1);
        PL1 := PL;
        P2 := 0;
        WHILE PL1 <> SIL DO
          ADV(PL1, P3, PL1);
          ADV(PL3, P4, PL3);
          P1 := DIRPPR(P3, P4);
          P2 := DIRPSM(P2, P1);
        END;
        PL2 := CCONC(PL2, LIST1(P2));
      END;
      SY2 := CCONC(SY2, LIST1(PL2));
    END;
    RETURN(SY2);
END MMULT;


PROCEDURE NLMMULT(SY1, GBTM : LIST; VAR T : LIST): LIST;
(* Non-Commutative Matrix Multiplication. Das nicht-kommutative Produkt
der Matrizen SY1 * GBTM ergibt die Loesungsmatrix. *)
VAR   PL, PL1, PL2, PL3, P1, P2, P3, P4, GBTM1, SY2 : LIST;
BEGIN
    SY2 := SIL;
    WHILE SY1 <> SIL DO
      ADV(SY1, PL, SY1);
      PL2 := SIL;
      GBTM1 := GBTM;
      WHILE GBTM1 <> SIL DO
        ADV(GBTM1, PL3, GBTM1);
        PL1 := PL;
        P2 := 0;
        WHILE PL1 <> SIL DO
          ADV(PL1, P3, PL1);
          ADV(PL3, P4, PL3);
          P1 := DINPPR(T, P3, P4);
          P2 := DIRPSM(P2, P1);
        END;
        PL2 := CCONC(PL2, LIST1(P2));
      END;
      SY2 := CCONC(SY2, LIST1(PL2));
    END;
    RETURN(SY2);
END NLMMULT;


PROCEDURE BGFUP(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM : LIST): LIST;
(* Base Generators Factor Update. Fuer das zu einer Groebner Basis GB 
neu hinzugenommene normierte Polynom SPN werden dessen Abhaengigkeiten 
zu den Grundpolynomen berechnet. Dazu werden die Polynome P1 und P2, 
aus denen SP gebildet wurde, die zwei Faktoren des S-Polynoms in SPFL, 
die Ableitungskette des urspruenglichen S-Polynoms SPAK und die bereits 
bestehende Faktormatrix GBTM verwendet. *)
VAR   NF, P, P3, P4, P5, PL, PL1, H, GBTM1, SPF1, SPF2, POS1, POS2, POS3,
      SPAK1 : LIST;
BEGIN
    GBTM := APP0(GBTM);
    NF := DIRPQ(SPN, SP);
    POS1 := POS(P1, GB);
    POS2 := POS(P2, GB);
    ADV2(SPFL, SPF1, SPF2, H);
    GBTM1 := GBTM;
    GBTM := SIL;
    WHILE GBTM1 <> SIL DO
      POS3 := 0;
      SPAK1 := SPAK;
      ADV(GBTM1, PL, GBTM1);
      PL1 := PL;
      WHILE RED(PL1) <> SIL DO
        ADV(PL1, P, PL1);
        ADV(SPAK1, P3, SPAK1);
        POS3 := POS3 + 1;
        IF POS3 = POS1 THEN
          P4 := DIRPPR(DIRPDF(SPF1, P3), NF);
          P4 := DIRPPR(P4, P);
        ELSIF POS3 = POS2 THEN
          P4 := DIRPDF(DIRPNG(SPF2), P3);
          P4 := DIRPPR(P4, NF);
          P4 := DIRPPR(P4, P);
        ELSE
          P4 := DIRPPR(DIRPNG(P3), NF);
          P4 := DIRPPR(P4, P);
        END;
        PL := ADDLAST(P4, PL);
      END;
      GBTM := CCONC(GBTM, LIST1(PL));
    END;
    RETURN(GBTM);
END BGFUP;


PROCEDURE NLBGFUP(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM : LIST; 
                  VAR T : LIST): LIST;
(* Non-Commutative Base Generators Factor Update. Fuer das zu einer 
Groebner Basis GB neu hinzugenommene normierte Polynom SPN werden 
dessen Abhaengigkeiten zu den Grundpolynomen berechnet. Dazu werden 
die Polynome P1 und P2, aus denen SP mit nicht-kommutativer 
Multiplikation gebildet wurde, die zwei Faktoren des S-Polynoms in 
SPFL und die bereits bestehende Faktormatrix GBTM verwendet. *)
VAR   NF, P, P3, P4, P5, PL, PL1, H, GBTM1, SPF1, SPF2, POS1, POS2, POS3,
      SPAK1 : LIST;
BEGIN
    GBTM := APP0(GBTM);
    NF := DIRPQ(SPN, SP);
    POS1 := POS(P1, GB);
    POS2 := POS(P2, GB);
    ADV2(SPFL, SPF1, SPF2, H);
    GBTM1 := GBTM;
    GBTM := SIL;
    WHILE GBTM1 <> SIL DO
      POS3 := 0;
      SPAK1 := SPAK;
      ADV(GBTM1, PL, GBTM1);
      PL1 := PL;
      WHILE RED(PL1) <> SIL DO
        ADV(PL1, P, PL1);
        ADV(SPAK1, P3, SPAK1);
        POS3 := POS3 + 1;
        IF POS3 = POS1 THEN
          P4 := DINPPR(T, NF, DIRPDF(SPF1, P3));
          P4 := DINPPR(T, P4, P);
        ELSIF POS3 = POS2 THEN
          P4 := DIRPDF(DIRPNG(SPF2), P3);
          P4 := DINPPR(T, NF, P4);
          P4 := DINPPR(T, P4, P);
        ELSE
          P4 := DINPPR(T, NF, DIRPNG(P3));
          P4 := DINPPR(T, P4, P);
        END;
        PL := ADDLAST(P4, PL);
      END;
      GBTM := CCONC(GBTM, LIST1(PL));
    END;
    RETURN(GBTM);
END NLBGFUP;


PROCEDURE DGBRED(GB, GBTM : LIST; VAR SY : LIST): LIST;
(* Discrete Groebner Base Reduction. Konnte ein Polynom P aus GB 
bzgl. GB ohne P nicht zu Null reduziert werden, dann verbleibt es im 
Ursprungszustand in der Groebner Basis GB. Hat die so reduzierte 
GB nur noch ein Polynom, dann wird die Syzygie abhaengig von der 
Faktormatrix GBTM berechnet. *)
VAR   GB1, GB2, GB3, L1, L2, P, PL, P1, KO1, EV1, KO2, EV2, H, TW : LIST;
BEGIN
    GB1 := GB;
    GB2 := GB;
    GB := SIL;
    WHILE GB1 <> SIL DO
      ADV(GB1, P, GB1);
      GB3 := EXPPL(P, GB2);
      TW := DIRPNF(GB3, P);
      IF TW <> 0 THEN GB := CCONC(GB, LIST1(P)); END;
    END;
    SY := SYONP(GB2, GB, GBTM);
    RETURN (GB);
END DGBRED;


PROCEDURE NLDGBRED(GB, GBTM : LIST; VAR SY, T : LIST): LIST;
(* Non-Commutative Discrete Groebner Base Reduction. Konnte ein Polynom 
P aus GB bzgl. GB ohne P nicht zu Null reduziert werden, dann verbleibt 
es im Ursprungszustand in der Groebner Basis GB. Verwendung findet 
hier die Bildung der Linksnormalform mit DINLNF. Hat die so 
reduzierte GB nur noch ein Polynom, dann wird die Syzygie abhaengig 
von der Faktormatrix GBTM berechnet. *)
VAR   GB1, GB2, GB3, L1, L2, P, TW : LIST;
BEGIN
    GB1 := GB;
    GB2 := GB;
    GB := SIL;
    WHILE GB1 <> SIL DO
      ADV(GB1, P, GB1);
      GB3 := EXPPL(P, GB2);
      TW := DINLNF(T, GB3, P);
      IF TW <> 0 THEN GB := CCONC(GB, LIST1(P)); END;
    END;
    SY := NLSYONP(GB2, GB, GBTM, T);
    RETURN(GB);
END NLDGBRED;


PROCEDURE SYONP(GB1, GB2, GBTM : LIST): LIST;
(* Syzygy for old Polynomials by new Polynomials. Berechnet einen
Loesungsmodulgenerator ausgehend von der Groebner Basis GB1 unter
Zuhilfenahme der alten Polynome und der Faktormatrix GBTM. GB2 ist 
die eventuell reduzierte Groebner Basis. *)
VAR   POS1, POS2, PALT, PL, PL1, PL2, P, P1, P2, P3, P4, L, SY,
      GBTM1, GBTM2, POSV, GB3 : LIST;
BEGIN
    POS1 := LENGTH(GBTM);
    POS2 := 1;
    GBTM1 := GBTM;
    PALT := SIL;
    GB3 := GB1;
    WHILE POS2 <= POS1 DO
      ADV(GB3, P, GB3);
      ADV(GBTM1, PL, GBTM1);
      P1 := POL(PL, POS2);
      PALT := CCONC(PALT, LIST1(DIRPQ(P, P1)));
      POS2 := POS2 + 1;
    END;
    POSV := GENPOSV(GB1, GB2);
    GBTM1 := GBTMRED(GBTM, POSV);
    GBTM2 := RCSP(GB2, PALT);
    SY := SIL;
    L := EVL(GBTM1);
    P3 := DIPFMO(RNINT(-1), EVZERO(L));
    POS2 := 1;
    WHILE GBTM2 <> SIL DO
      GBTM := GBTM1;
      PL := SIL;
      ADV(GBTM2, PL2, GBTM2);
      WHILE GBTM <> SIL DO
        ADV(GBTM, PL1, GBTM);
        P := PLMULT(PL2, PL1);
        PL := CCONC(PL, LIST1(P));
      END;
      PL2 := ADDPPOS(PL, P3, POS2);
      SY := CCONC(SY, LIST1(PL2));
      POS2 := POS2 + 1;
    END;
    RETURN(SY);
END SYONP;


PROCEDURE NLSYONP(GB1, GB2, GBTM : LIST; VAR T : LIST): LIST;
(* Syzygy for one Polynomial. Berechnet einen Loesungsmodulgenerator 
fuer das Polynom P unter Zuhilfenahme der Faktormatrix GBTM. *)
VAR   POS1, POS2, PALT, PL, PL1, PL2, P, P1, P2, P3, P4, L, SY,
      GBTM1, GBTM2, POSV, GB3 : LIST;
BEGIN
    POS1 := LENGTH(GBTM);
    POS2 := 1;
    GBTM1 := GBTM;
    PALT := SIL;
    GB3 := GB1;
    WHILE POS2 <= POS1 DO
      ADV(GB3, P, GB3);
      ADV(GBTM1, PL, GBTM1);
      P1 := POL(PL, POS2);
      PALT := CCONC(PALT, LIST1(DINPQ(P, P1, T)));
      POS2 := POS2 + 1;
    END;
    POSV := GENPOSV(GB1, GB2);
    GBTM1 := GBTMRED(GBTM, POSV);
    GBTM2 := NLRCSP(GB2, PALT, T);
    SY := SIL;
    L := EVL(GBTM1);
    P3 := DIPFMO(RNINT(-1), EVZERO(L));
    POS2 := 1;
    WHILE GBTM2 <> SIL DO
      GBTM := GBTM1;
      PL := SIL;
      ADV(GBTM2, PL2, GBTM2);
      WHILE GBTM <> SIL DO
        ADV(GBTM, PL1, GBTM);
        P := NLPLMULT(PL2, PL1, T);
        PL := CCONC(PL, LIST1(P));
      END;
      PL2 := ADDPPOS(PL, P3, POS2);
      SY := CCONC(SY, LIST1(PL2));
      POS2 := POS2 + 1;
    END;
    RETURN(SY);
  RETURN(SY);
END NLSYONP;


PROCEDURE DINPQ(P1, P2 : LIST; VAR T : LIST): LIST;
(* Distributive non-commutative Polynomial Quotient. Berechnet wird 
der nicht-kommutaive Quotient P1/P2=P3; *)
VAR   P : LIST;
BEGIN
    P := NLRCSPR(LIST1(P2), P1, T);
    P := FIRST(P);
    IF P1 = 0 THEN
      RETURN(P)
    ELSE
      RETURN(SIL);
    END;
END DINPQ;


PROCEDURE PLMULT(SY, PL : LIST): LIST;
(* Polynomial List Multiplication. Multipliziert die Polynome der 
Listen SY und PL komponentenweise, und addiert die erhaltenen 
Ergebnisse. *)
VAR   P, P1, P2 : LIST;
BEGIN
    P := 0;
    WHILE (SY <> SIL) DO
      ADV(SY, P1, SY);
      ADV(PL, P2, PL);
      P2 := DIRPPR(P1, P2);
      P := DIRPSM(P, P2);
    END;
    RETURN (P);
END PLMULT;


PROCEDURE NLPLMULT(SY, PL : LIST; VAR T : LIST): LIST;
(* Non-Commutative Polynomial List Multiplication. Multipliziert die 
Polynome der Listen SY und PL komponentenweise, und addiert die 
erhaltenen Ergebnisse. *)
VAR   P, P1, P2 : LIST;
BEGIN
    P := 0;
    WHILE (SY <> SIL) DO
      ADV(SY, P1, SY);
      ADV(PL, P2, PL);
      P2 := DINPPR(T, P1, P2);
      P := DIRPSM(P, P2);
    END;
    RETURN (P);
END NLPLMULT;


END SYZFUNC.

(* -EOF- *)
