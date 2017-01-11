(* ----------------------------------------------------------------------------
 * $Id: SYZHLP.mi,v 1.3 1992/10/15 16:29:22 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYZHLP.mi,v $
 * Revision 1.3  1992/10/15  16:29:22  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:19  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:02  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYZHLP;

(* Syzygy Utility Programs Implementation Module. *)


(* Author: J. Philipp, Uni Passau, 1991. *)


FROM DIPC    IMPORT DIPEVL, DIPFMO, DIPINV, DIPMAD, DIPMPV, EVDEL, 
                    EVORD, VALIS;

FROM DIPRN   IMPORT DIRLRD, DIRPQ, DIRPMC, DIRPSM, DIRPWR;

FROM MASBIOS IMPORT BLINES, BKSP, CREADB, MASORD, SOLINE, SWRITE;

FROM MASNC   IMPORT DINLRD, EVZERO;

FROM MASSTOR IMPORT ADV, BETA, FIRST, LENGTH, LIST, LIST1, RED, SIL, 
                    SFIRST, SRED, TIME;

FROM SACLIST IMPORT ADV2, AWRITE, CCONC, COMP2, EQUAL, FIRST3, LAST, 
                    LIST4, LWRITE;

FROM SACPOL  IMPORT PDEG;

CONST rcsidi = "$Id: SYZHLP.mi,v 1.3 1992/10/15 16:29:22 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ALFA(L : LIST);
(* Automatic Linear Form Adaption. Fuehrt bei einer gegebenen Linearform
von EVORD L neue Variablen mit Graden groesser als der hoechste Grad
der EVORD-Polynome ein. *)
VAR   LF, G, P, G1, P1, C : LIST;
BEGIN
   IF EVORD < BETA THEN RETURN; END;
   SWRITE('ALFA');
   LF := EVORD;
   G := 0;
   WHILE LF <> SIL DO
     ADV(LF, P, LF);
     G1 := PDEG(P);
     IF G1 > G THEN G := G1; END;
   END;
   C := 1;
   WHILE C <= L DO
     P1 := CCONC(LIST1(G + C), LIST1(1));
     EVORD := CCONC(LIST1(P1), EVORD);
     C := C + 1;
   END;
   RETURN;
END ALFA;


PROCEDURE ALFRA(L : LIST);
(* Automatic Linear Form Readaption. Gegenstueck zu ALFA. Reduziert bei
gegebener Linearform von EVORD die fuehrenden L Polynome. *)
BEGIN
    IF EVORD < BETA THEN RETURN; END;
    WHILE L >= 1 DO
      EVORD := RED(EVORD);
      L := L - 1;
    END;
    RETURN;
END ALFRA;


PROCEDURE ADDPPOS(PL, P, POS : LIST): LIST;
(* Add Polynomial P at Position. Gegeben ist eine Polynomliste PL. Dann 
wird P an der POS-ten Position dieser Liste zu dem dort vorhandenen Polynom
addiert. *)
VAR   PL1, C, P1, P2 : LIST;
BEGIN
    PL1 := PL;
    PL := SIL;
    FOR C := 1 TO POS - 1 DO
      ADV(PL1, P1, PL1);
      PL := CCONC(PL, LIST1(P1));
    END;
    ADV(PL1, P1, PL1);
    P2 := DIRPSM(P1, P);
    PL := CCONC(PL, LIST1(P2));
    WHILE PL1 <> SIL DO
      ADV(PL1, P1, PL1);
      PL := CCONC(PL, LIST1(P1));
    END;
    RETURN (PL);
END ADDPPOS;


PROCEDURE PLWR(PL, VL : LIST);
(* Polynomial List Write. Am Bildschirm wird die Polynomliste PL bzgl.
der Variablenliste VL ausgegeben. *)
VAR   OS, LS, RS, P, P1 : LIST;
BEGIN
    OS := -1; LS := 0; RS := 80;
    SOLINE(OS, LS, RS);
    IF PL = SIL THEN
      SWRITE(' () ');
      RETURN;
    END;
    SWRITE('(');
    WHILE RED(PL) <> SIL DO
      ADV(PL, P, PL);
      IF P = 0 THEN
        SWRITE(' 0, ');
      ELSE
        DIRPWR(P, VL, -1);
        SWRITE(', ');
      END;
    END;
    DIRPWR(FIRST(PL), VL, -1);
    SWRITE(')');
    RETURN;
END PLWR;


PROCEDURE PMWR(PM, VL : LIST);
(* Polynomial Matrix Write. Am Bildschirm wird die Polynommatrix PM 
(Liste ueber Listen) bzgl. der Variablenliste VL ausgegeben. *)
VAR   PL : LIST;
BEGIN
    IF PM = SIL THEN
      SWRITE('()');
      RETURN;
    END;
    SWRITE('(');
    BLINES(0);
    WHILE RED(PM) <> SIL DO
      ADV(PM, PL, PM);
      PLWR(PL, VL);
      SWRITE(', ');
      BLINES(0);
    END;
    ADV(PM, PL, PM);
    PLWR(PL, VL);
    BLINES(0);
    SWRITE(')');
    RETURN;
END PMWR;


PROCEDURE APP0(PM : LIST): LIST;
(* Append 0. Haengt an jede Polynomliste von PM das Nullpolynom an. *)
VAR   PM1, PL : LIST;
BEGIN
    PM1 := SIL;
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      PL := CCONC(PL, LIST1(0));
      PM1 := CCONC(PM1, LIST1(PL));
    END;
    RETURN (PM1);
END APP0;


PROCEDURE ADDLAST(P, PL : LIST): LIST;
(* Add last Polynomial. Addiert das Polynom P zum letzten Polynom der
Polynomliste PL. *)
VAR   PL1, P1, P2 : LIST;
BEGIN
    PL1 := SIL;
    WHILE RED(PL) <> SIL DO
      ADV(PL, P1, PL);
      PL1 := CCONC(PL1, LIST1(P1));
    END;
    ADV(PL, P1, PL);
    P2 := DIRPSM(P, P1);
    PL1 := CCONC(PL1, LIST1(P2));
    RETURN (PL1);
END ADDLAST;


PROCEDURE POS(P, PL : LIST): LIST;
(* Position of Polynomial. Bestimmt die Position des Polynoms P in der
Polynomliste PL. *)
VAR   POS, P1 : LIST;
BEGIN
    POS := 1;
    WHILE PL <> SIL DO
      ADV(PL, P1, PL);
      IF EQUAL(P1, P) = 1 THEN
        RETURN(POS);
      END;
      POS := POS + 1;
    END;
END POS;


PROCEDURE POL(PL, POS : LIST): LIST;
(* Polynomial at Position. Bestimmt das Polynom an der POS-ten Stelle in 
der Polynomliste PL. *)
VAR   C, P : LIST;
BEGIN
    FOR C := 1 TO POS DO
      ADV(PL, P, PL);
    END;
    RETURN (P);
END POL;


PROCEDURE GENPOSV(GB, GBR : LIST): LIST;
(* Generate Postion Vector. Gegeben ist eine Groebner Basis GB und die dazu-
gehoerige diskret reduzierte Groebner Basis GBR. Bestimmt wird nun ein
Vektor mit Nullen und Einsen, bei dem die Einsen an der Position stehen,
an der ein Polynom aus GB nicht ganz zu Null reduziert werden konnte.
Zusaetzlich bleiben immer mindestens zwei Polynome aus GB uebrig.
Bsp.: GB = (P1, P2, P3), GBR = (P2, P3), dann ist POSV = (0, 1, 1). *)
VAR   GB1, POS, P1, P2, POSV : LIST;
BEGIN
    POSV := EVZERO(LENGTH(GB));
    WHILE GBR <> SIL DO
      POS := 1;
      ADV(GBR, P1, GBR);
      GB1 := GB;
      LOOP
        ADV(GB1, P2, GB1);
        IF EQUAL(P1, P2) = 1 THEN
          POSV := ADDPPOS(POSV, 1, POS);
          EXIT;
        END;
        POS := POS + 1;
      END;
    END;
    RETURN(POSV);
END GENPOSV;


PROCEDURE INSPOSV(PM, POSV : LIST): LIST;
(* Insert Position Vector. Fuegt bei der Polynommatrix PM in jede Polynomliste
PL Nullen an den Stellen ein, an denen bei POSV auch Nullen stehen.
Bsp.: Sei eine Polynomliste PLi = (P1, P2, P3), und sei
POSV = (0, 1, 0, 1, 1, 0, 0). Dann wird als neue Polynomliste
(0, P1, 0, P2, P3, 0, 0) an die Matrix zurueckgegeben. *)
VAR   PL, PL1, P, POSV1, TW, PM1 : LIST;
BEGIN
    PM1 := SIL;
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      PL1 := SIL;
      POSV1 := POSV;
      WHILE POSV1 <> SIL DO
        ADV(POSV1, TW, POSV1);
        IF TW = 0 THEN
          PL1 := CCONC(PL1, LIST1(0));
        ELSE
          ADV(PL, P, PL);
          PL1 := CCONC(PL1, LIST1(P));
        END;
      END;
      PM1 := CCONC(PM1, LIST1(PL1));
    END;
    RETURN(PM1);
END INSPOSV;


PROCEDURE EXPPL(P, GB : LIST): LIST;
(* Exclude P from GB. Loescht das Polynom P aus der Polynomliste GB. *)
VAR   GB1, P1 : LIST;
BEGIN
    GB1 := SIL;
    WHILE GB <> SIL DO
      ADV(GB, P1, GB);
      IF EQUAL(P, P1) <> 1 THEN
        GB1 := CCONC(GB1, LIST1(P1));
      END;
    END;
    RETURN (GB1);
END EXPPL;


PROCEDURE EX0PL(PL : LIST): LIST;
(* Exclude 0 from PL. Loescht alle Nullen aus der Polynomliste PL. *)
VAR   PL1, P : LIST;
BEGIN
    PL1 := SIL;
    WHILE PL <> SIL DO
      ADV(PL, P, PL);
      IF P <> 0 THEN
        PL1 := CCONC(PL1, LIST1(P));
      END;
    END;
    RETURN (PL1);
END EX0PL;


PROCEDURE EVF(EV, L : LIST): LIST;
(* Exponent Vector First. Liefert die ersten L Stellen des Exponentenvektors
EV zurueck. Bsp.: Sei EV = (4, 3, 0, 1, 9), und sei L = 3, dann wird 
(4, 3, 0) zurueckgegeben. *)
VAR   EV1, EV11, C : LIST;
BEGIN
    EV1 := SIL;
    C := 1;
    WHILE C <= L DO
      ADV(EV, EV11, EV);
      EV1 := CCONC(EV1, LIST1(EV11));
      C := C + 1;
    END;
    RETURN (EV1);
END EVF;


PROCEDURE EVR(PM, L : LIST): LIST;
(* Exponent Vector Reduction. Bei der Polynommatrix PM wird jeder
Exponentenvektor jeden Polynoms um die ersten L Stellen gekuerzt. *)
VAR   PM1, PL, PL1, P, P1, P2, KO, EV, C, H : LIST;
BEGIN
    PM1 := SIL;
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      PL1 := SIL;
      WHILE PL <> SIL DO
        ADV(PL, P, PL);
        IF P = 0 THEN
          PL1 := CCONC(PL1, LIST1(P));
        ELSE
          P1 := 0;
          WHILE P <> SIL DO
            DIPMAD(P, KO, EV, P);
            C := L;
            WHILE C <> 0 DO
              EVDEL(EV, 1, EV, H);
              C := C - 1;
            END;
            P2 := DIPFMO(KO, EV);
            P1 := DIRPSM(P1, P2);
          END;
          PL1 := CCONC(PL1, LIST1(P1));
        END;
      END;
      PM1 := CCONC(PM1, LIST1(PL1));
    END;
    RETURN(PM1);
END EVR;


PROCEDURE MREAD(VL : LIST): LIST;
(* Matrix Read. Liest eine Polynommatrix entsprechend der Variablenliste 
VL und der gegebenen Einheit (Textdatei, "Bildschirm") ein. *)
VAR   PM, PL, CH : LIST;
BEGIN
    PM := SIL;
    CH := CREADB();
    IF CH <> MASORD("(") THEN
      RETURN (PM);
    END;
    REPEAT
      CH := CREADB();
      IF CH = MASORD(",") THEN
        CH := CREADB();
      END;
      IF CH <> MASORD(")") THEN
        BKSP();
        PL := DIRLRD(VL);
        PM := CCONC(PM, LIST1(PL));
      END;
    UNTIL CH = MASORD(")");
    RETURN (PM);
END MREAD;


PROCEDURE NMREAD(VL, T : LIST): LIST;
(* Non-Commutative Matrix Read. Liest eine Polynommatrix mit nicht-
kommutativen Polynomen entsprechend der Variablenliste VL, der Relations-
matrix T und der gegebenen Einheit (Textdatei, "Bildschirm") ein. *)
VAR   PM, PL, CH : LIST;
BEGIN
    PM := SIL;
    CH := CREADB();
    IF CH <> MASORD("(") THEN
      RETURN (PM);
    END;
    REPEAT
      CH := CREADB();
      IF CH = MASORD(",") THEN
        CH := CREADB();
      END;
      IF CH <> MASORD(")") THEN
        BKSP();
        PL := DINLRD(VL, T);
        PM := CCONC(PM, LIST1(PL));
      END;
    UNTIL CH = MASORD(")");
    RETURN (PM);
END NMREAD;


PROCEDURE TA(L : LIST; T : LIST): LIST;
(* T Adaption. Die Exponentenvektoren jeden Polynoms in der Polynomliste T
werden um L Stellen erweitert. Bsp.: Sei EV = (2, 1, 3) und L = 2, 
dann wird EV zu (0, 0, 2, 1, 3). *)
VAR   EV, L1, T1, P : LIST;
BEGIN
    EV := DIPEVL(FIRST(T));
    L1 := LENGTH(EV) + L + 1;
    T1 := SIL;
    WHILE T <> SIL DO
      ADV(T, P, T);
      P := DIPINV(P, L1, L);
      T1 := CCONC(T1, LIST1(P));
    END;
    RETURN(T1);
END TA;


PROCEDURE TR(L : LIST; T : LIST): LIST;
(* T Readaption. Die Exponentenvektoren jeden Polynoms in der Polynomliste 
T werden um L Stellen gekuerzt. Bsp.: Sei EV = (0, 0, 2, 1, 3) und 
L = 2, dann wird EV zu (2, 1, 3). *)
VAR   T1, P, P1, P2, KO, EV, C, H : LIST;
BEGIN
    T1 := SIL;
    WHILE T <> SIL DO
      ADV(T, P, T);
      P1 := 0;
      WHILE P <> SIL DO
        DIPMAD(P, KO, EV, P);
        C := 1;
        WHILE C <= L DO
          EVDEL(EV, 1, EV, H);
          C := C + 1;
        END;
        P2 := DIPFMO(KO, EV);
        P1 := DIRPSM(P1, P2);
      END;
      T1 := CCONC(T1, LIST1(P1));
    END;
    RETURN(T1);
END TR;


PROCEDURE NEXTPAIR(VAR P1, P2, PPL : LIST);
(* Next Pair of Polynomials. Bestimmt aus der Polynompaarliste PPL das
naechste Paar P1, P2 von Polynomen. Gleichzeitig wird dieses Paar aus
der Liste entfernt. Siehe Groebner Basis Algorithmen! *)
VAR PP, PL1, PL2, PM1, PM2, PL, PM21, PM22, P : LIST;
BEGIN
    ADV(PPL, PP, PPL);
    FIRST3(PP, PL2, PM1, PM2);
    ADV(PM1, PL, PL1);
    P1 := FIRST(PL);
    PM21 := RED(PM2);
    P2 := FIRST(PM21);
    PM21 := RED(PM2);
    PM22 := RED(PM21);
    SRED(PM2, PM22);
    IF PM22 = SIL THEN
      P := LAST(PL);
      SFIRST(PL1, P);
    END;
END NEXTPAIR;


PROCEDURE EVT(P1, P2, L : LIST): LIST;
(* Exponent Vector Test. Ueberprueft, ob die Exponentenvektoren der HT der
Polynome P1 und P2 in den fuehrenden L Stellen uebereinstimmen. Ist dies
der Fall, dann wird die 1, ansonsten die 0 zurueckgegeben. *)
VAR   EV1, EV2, EV11, EV21, LL, e1, e2 : LIST;
BEGIN
    EV1 := DIPEVL(P1);
    EV2 := DIPEVL(P2);
    LL:=0; 
    WHILE (LL < L) AND (EV1 <> SIL) (* AND (EV2 <> SIL) *) DO
          LL:=LL+1; ADV(EV1, e1, EV1); ADV(EV2, e2, EV2); 
          IF e1 <> e2 THEN RETURN(0) END;
          END;
    RETURN(1); 
    (* EV11 := EVF(EV1, L);
       EV21 := EVF(EV2, L);
       RETURN(EQUAL(EV11, EV21)); *)
END EVT;


PROCEDURE WRS1(SZ, C1, C2, C3 : LIST);
(* Write Situation. Ausgegben wird die CPU-Zeit minus eine Startzeit SZ,
die Anzahl der H-Polynome C1, die Anzahl der S-Polynome C2 und die
Anzahl der uebrigen Paare von Polynomen C3. *)
BEGIN
    AWRITE(TIME() - SZ); SWRITE(' sec., '); BLINES(0);
    IF C1 = 1 THEN AWRITE(C1); SWRITE(' H-Polynom, '); BLINES(0);
    ELSE           AWRITE(C1); SWRITE(' H-Polynome, '); BLINES(0); END;
    IF C2 = 1 THEN AWRITE(C2); SWRITE(' S-Polynom, '); BLINES(0);
    ELSE           AWRITE(C2); SWRITE(' S-Polynome, '); BLINES(0); END;
    IF C3 = 1 THEN  AWRITE(C3); SWRITE(' uebriges Paar. '); BLINES(0);
    ELSE            AWRITE(C3); SWRITE(' uebrige Paare. '); BLINES(0); END;
    BLINES(1);
    RETURN;
END WRS1;


PROCEDURE WRS2(SZ, C1, TW1, C2, SPN, C3 : LIST);
(* Write Situation. Ausgegben wird die CPU-Zeit minus eine Startzeit SZ,
die Anzahl der H-Polynome C1 und das letzte H-Polynom, die Anzahl der
S-Polynome C2 und das letzte S-Polynom, sowie die Anzahl der uebrigen
Paare von Polynomen C3. *)
BEGIN
    AWRITE(TIME() - SZ); SWRITE(' sec., '); BLINES(0);
    IF C1 = 1 THEN AWRITE(C1); SWRITE(' H-Polynom, '); 
                   PLWR(LIST1(TW1), VALIS); BLINES(0);
    ELSE           AWRITE(C1); SWRITE(' H-Polynome, '); 
                   PLWR(LIST1(TW1), VALIS); BLINES(0); END;
    IF C2 = 1 THEN AWRITE(C2); SWRITE(' S-Polynom, '); 
                   PLWR(LIST1(SPN), VALIS); BLINES(0);
    ELSE           AWRITE(C2); SWRITE(' S-Polynome, '); 
                   PLWR(LIST1(SPN), VALIS); BLINES(0); END;
    IF C3 = 1 THEN AWRITE(C3); SWRITE(' uebriges Paar. '); BLINES(0);
    ELSE           AWRITE(C3); SWRITE(' uebrige Paare. '); BLINES(0); END;
    BLINES(1);
    RETURN;
END WRS2;


PROCEDURE EVL(PM : LIST) : LIST;
(* Exponent Vector Length. Bestimmt in einer Polynommatrix PM die Laenge des
Exponentenvektors des ersten Polynoms ungleich dem Nullpolynom. *)
VAR   L, PL, P : LIST;
BEGIN
    L := 0;
    WHILE PM <> SIL DO
      ADV(PM, PL, PM);
      WHILE PL <> SIL DO
        ADV(PL, P, PL);
        IF P <> 0 THEN
          L := LENGTH(DIPEVL(P));
          RETURN(L);
        END;
      END;
    END;
    RETURN(L);
END EVL;


PROCEDURE NORMF(VAR PL, GBTM : LIST);
(* Normative Factors. Berechnet eine Matrix GBTM, auf deren Hauptdiagonalen
die Normfaktoren der Polynome der Polynomliste PL stehen. *)
VAR   PL1, PL2, POS, L, NV, P, PN, NF : LIST;
BEGIN
    PL1 := PL;
    PL := SIL;
    GBTM := SIL;
    POS := 1;
    L := LENGTH(PL1);
    NV := EVZERO(L);
    WHILE PL1 <> SIL DO
      ADV(PL1, P, PL1);
      PN := DIRPMC(P);
      NF := DIRPQ(PN, P);
      PL2 := ADDPPOS(NV, NF, POS);
      PL := CCONC(PL, LIST1(PN));
      GBTM := CCONC(GBTM, LIST1(PL2));
      POS := POS + 1;
    END;
    RETURN;
END NORMF;


PROCEDURE GBTMRED(GBTM, POSV : LIST) : LIST;
(* GBTM Reduction. Reduziert die Spalten von GBTM entsprechend der
auftretenden Nullen in POSV. *)
VAR   GBTM1, PL, PL1, P, TW, POSV1 : LIST;
BEGIN
    GBTM1 := SIL;
    WHILE GBTM <> SIL DO
      ADV(GBTM, PL, GBTM);
      POSV1 := POSV;
      PL1 := SIL;
      WHILE PL <> SIL DO
        ADV(PL, P, PL);
        ADV(POSV1, TW, POSV1);
        IF TW = 1 THEN
          PL1 := CCONC(PL1, LIST1(P));
        END;
      END;
      GBTM1 := CCONC(GBTM1, LIST1(PL1));
    END;
    RETURN(GBTM1);
END GBTMRED;


PROCEDURE MTPLV(PM : LIST; VAR L : LIST): LIST;
(* Matrix to Polynomial List Vertical. Erzeugt eine Polynomliste PL derart,
dass L (gleich Zeilenzahl) neue verschiedene Variablen mit der Matrix
multipliziert werden (1. Variable mit der 1. Zeile, ...), und anschlieaend
die so erhaltene Matrix spaltenweise aufaddiert wird. *)
VAR   L1, L2, PL1, P, P1, PL, POS : LIST;
BEGIN
    L := LENGTH(FIRST(PM));
    L1 := EVL(PM);
    IF L1 = 0 THEN PL := LIST1(0); RETURN(PL); END;
    L1 := L1 + 1;
    L2 := L1 + L;
    PL := SIL;
    WHILE PM <> SIL DO
      ADV(PM, PL1, PM);
      POS := 1;
      P := 0;
      WHILE PL1 <> SIL DO
        ADV(PL1, P1, PL1);
        IF P1 <> 0 THEN
          P1 := DIPINV(P1, L1, L);
          P1 := DIPMPV(P1, L2 - POS, 1);
          P := DIRPSM(P1, P);
        END;
        POS := POS + 1;
      END;
      IF P <> 0 THEN
        PL := CCONC(PL, LIST1(P));
      END;
    END;
    RETURN(PL);
END MTPLV;


PROCEDURE PLVTM(PL, L : LIST): LIST;
(* Polynomial List Vertical To Matrix. Das Gegenstueck zu MTPLV. Beachtet
werden mua hierbei nur, dass Anteile der Polynome aus der Polynomliste PL
enstprechend der L neu eingefuehrten Variablen wieder in eine Matrix
zerlegt werden, d.h. das erste Polynom der Polynomliste PL verteilt sich
in der ersten Spalte, ... . *)
VAR   NV, PL1, P, POS, KO, EV, P1, P2, P3, EV1, EV2, C, H, PM : LIST;
BEGIN
    PM := SIL;
    NV := EVZERO(L);
    WHILE PL <> SIL DO
      ADV(PL, P, PL);
      PL1 := SIL;
      POS := 1;
      WHILE POS <= L DO
        P1 := P;
        EV2 := ADDPPOS(NV, 1, POS);
        POS  := POS + 1;
        P2 := 0;
        WHILE P1 <> SIL DO
          DIPMAD(P1, KO, EV, P1);
          EV1 := EVF(EV, L);
          IF EQUAL(EV2, EV1) = 1 THEN
            C := 1;
            WHILE C <= L DO
              EVDEL(EV, 1, EV, H);
              C := C + 1;
            END;
            P3 := DIPFMO(KO, EV);
            P2 := DIRPSM(P3, P2);
          END;
        END;
        PL1 := CCONC(PL1, LIST1(P2));
      END;
      PM := CCONC(PM, LIST1(PL1));
    END;
    RETURN(PM);
END PLVTM;


PROCEDURE MTPLH(PM : LIST; VAR L : LIST): LIST;
(* Matrix to Polynomial List Horizontal. Erzeugt eine Polynomliste PL derart,
dass L (gleich Spaltenzahl) neue verschiedene Variablen mit der Matrix
multipliziert werden (1. Variable mit der 1. Spalte, ...), und anschlieaend
die so erhaltene Matrix zeilenweise aufaddiert wird. *)
VAR   L1, L2, POS1, POS2, PL, PL1, P : LIST;
BEGIN
    L := LENGTH(PM);
    L1 := EVL(PM);
    PL := EVZERO(LENGTH(FIRST(PM)));
    L2 := L1 + L + 1;
    POS1 := 0;
    WHILE PM <> SIL DO
      ADV(PM, PL1, PM);
      POS1 := POS1 + 1;
      POS2 := 1;
      WHILE PL1 <> SIL DO
        ADV(PL1, P, PL1);
        IF P <> 0 THEN
          P := DIPINV(P, L2, L);
          P := DIPMPV(P, L2 - POS1, 1);
          PL := ADDPPOS(PL, P, POS2);
        END;
        POS2 := POS2 + 1;
      END;
    END;
    RETURN(PL);
END MTPLH;



PROCEDURE PLHTP(PL : LIST): LIST;
(* Polynomial List Horizontal To Polynomial. Jedes Polynom aus PL wird mit
einer neuen , zu den anderen verschiedenen, Variablen multipliziert und
zu einem Polynom aufaddiert. *)
VAR   L1, L2, L3, POS, P, P1 : LIST;
BEGIN
    P := 0;
    L1 := LENGTH(PL);
    L2 := EVL(LIST1(PL));
    L3 := L2 + L1 + 1;
    POS := 0;
    WHILE PL <> SIL DO
      ADV(PL, P1, PL);
      POS := POS + 1;
      IF P1 <> 0 THEN
        P1 := DIPINV(P1, L3, L1);
        P1 := DIPMPV(P1, L3 - POS, 1);
        P := DIRPSM(P, P1);
      END;
    END;
    RETURN(P);
END PLHTP;



PROCEDURE VMADD(PM : LIST): LIST;
(* Vertical Matrix Addition. Erzeugt wird eine Polynomliste, deren Elemente
aus den aufaddierten Spalten der Matrix PM gebildet wurden. *)
VAR   PL, PL1, POS, P : LIST;
BEGIN
    PL := EVZERO(LENGTH(FIRST(PM)));
    WHILE (PM <> SIL) DO
      POS := 0;
      ADV(PM, PL1, PM);
       WHILE (PL1 <> SIL) DO
        ADV(PL1, P, PL1);
        POS := POS + 1;
        PL := ADDPPOS(PL, P, POS);
      END;
    END;
    RETURN(PL);
END VMADD;


END SYZHLP.

(* -EOF- *)
