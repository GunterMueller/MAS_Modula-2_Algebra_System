(* ----------------------------------------------------------------------------
 * $Id: NOETHER.mi,v 1.1 1995/11/05 15:57:33 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: NOETHER.mi,v $
 * Revision 1.1  1995/11/05 15:57:33  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE NOETHER;
(* Noether Polynomial System Implementation Module. *)

FROM MASELEM	IMPORT	GAMMAINT;

FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL;

FROM MASBIOS	IMPORT	BLINES, SWRITE;

FROM SACLIST	IMPORT	CINV, EQUAL, LEINST, LELT, OWRITE, SLELT;

FROM SACSET	IMPORT	LBIBS;

FROM SACRN	IMPORT	RNINT, RNNEG, RNPROD;

FROM DIPRN	IMPORT	DIRPDF, DIRPEX, DIRPPR, DIRPRP, DIRPRQ, DIRPSM;

FROM DIPC	IMPORT	DIPFMO, DIPMAD, EVDIF, EVSIGN, EVSUM, EVTDEG;

FROM GSYMFUIN	IMPORT	GSYORD, GSYSPG, GSYTWG;

FROM GSYMFURN	IMPORT	GRNCHK, GRNCHKBAS, GRNORP;

CONST rcsidi = "$Id: NOETHER.mi,v 1.1 1995/11/05 15:57:33 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE NOEINF();
BEGIN
BLINES(1);
SWRITE("Noether Polynomial System Package:");
BLINES(0);
SWRITE("----------------------------------");
BLINES(1);
SWRITE("    SK_Polynom := NOEL32(Number_of_Variables, Degree).");
BLINES(0);
SWRITE("  SK_Power_Sum := NOEPOW(PG, Degree).");
BLINES(0);
SWRITE("NOENSP(PG).");
BLINES(0);
SWRITE("NOEINF().");
BLINES(1);
SWRITE("NOERED(PG, Polynom, Base, Base_Polynom, Remainder_Polynom).");
BLINES(1);
SWRITE("       Sum_Pol := NOEPSM(Polynom_1, Polynom_2).");
BLINES(0);
SWRITE("      Mult_Pol := NOEPPR(Polynom_1, Polynom_2, Term).");
BLINES(0);
SWRITE("    Factor_Pol := NOEPIP(Polynom, Factor).");
BLINES(0);
SWRITE("    Remove_Pol := NOEPRM(Polynom, Term).");
BLINES(1);
END NOEINF;

PROCEDURE NOENSP(PG: LIST);
VAR SPG, ORBIT_SPG, ORBIT_PG, TERM: LIST;
    I, N, EL, POS, ORDER, NR1, NR2: GAMMAINT;
    FLAG: BOOLEAN;
BEGIN
NR1 := 0;
NR2 := 0;
IF PG = SIL THEN RETURN; END;
ORDER := GSYORD(PG);
N := LENGTH(FIRST(PG));
SPG := GSYSPG(N);
TERM := SIL;
FOR I := 1 TO N DO TERM := COMP(0, TERM); END;
LOOP
    LOOP POS := 1;
         EL := LELT(TERM, POS);
         FOR I := 2 TO N DO
              IF EL > LELT(TERM, I) THEN
                   POS := I;
                   EL := LELT(TERM, POS);
                   END; (* of if *)
              END; (* of for *)
         SLELT(TERM, POS, EL+1);
         IF POS < N THEN FOR I := POS+1 TO N DO SLELT(TERM, I, 0); END; END;
         IF (EVTDEG(TERM) <= ORDER) OR (FIRST(TERM) > ORDER) THEN EXIT; END;
         END; (* of loop *)
    IF FIRST(TERM) > ORDER THEN EXIT; END; (* of if *)
    I := 1;
    LOOP IF I+1 > N THEN EXIT; END;
         IF (LELT(TERM, I) - LELT(TERM, I+1)) > 1 THEN EXIT; END;
         I := I + 1;
         END; (* of loop *)
    FLAG := ((I = N) AND (LELT(TERM, N) = 0)) OR (LELT(TERM, 1) = 1);
    ORBIT_SPG := GRNORP(SPG, DIPFMO(RNINT(1), TERM));
    WHILE ORBIT_SPG # 0 DO
         NR1 := NR1 + 1;
         IF FLAG THEN NR2 := NR2 + 1; END;
         ORBIT_PG := GRNORP(PG, DIPFMO(RNINT(1), FIRST(ORBIT_SPG)));
         ORBIT_SPG := DIRPDF(ORBIT_SPG, ORBIT_PG);
         END; (* of while *);
    END; (* of loop *)
BLINES(0); SWRITE("There are "); OWRITE(NR2);
           SWRITE(" special and altogether "); OWRITE(NR1);
           SWRITE(" polynomial(s) with total degree <= ");
           OWRITE(ORDER); SWRITE(".");
END NOENSP;

PROCEDURE NOEL32(M, K: GAMMAINT): LIST;
VAR SPO, SL, SLEL, XSL, SR, SREL, XSR, POL, PP1, PP2, HK, HT, SHT, SPG,
    XLS, SIGN, DUMMY: LIST;
    I, J, EL: GAMMAINT;
BEGIN
SPO := 0;
IF (M = 0) OR (K = 0) THEN RETURN(SPO); END;
SPG := GSYSPG(M);

SL := SIL;
FOR I := 1 TO M DO
    HT := SIL;
    FOR J := 1 TO M DO
         IF I = J THEN HT := COMP(1, HT); ELSE HT := COMP(0, HT); END;
         END; (* of for *);
    SL := COMP(DIPFMO(RNINT(1), HT), SL);
    END; (* of for *)
SL := INV(SL);

SR := SIL;
FOR I := 1 TO M DO
    POL := LELT(SL, I);
    SIGN := RNINT(1);
    FOR J := I-1 TO 1 BY -1 DO
         SIGN := RNNEG(SIGN);
         POL := DIRPSM(POL, DIRPRQ( DIRPPR(LELT(SR, J), LELT(SL, J)), SIGN));
         END; (* of for *);
    SR := COMP(DIRPRQ(POL, RNPROD(SIGN, RNINT(I))), SR);
    END; (* of for *)

HT := LIST1(K);
FOR I := 1 TO M-1 DO HT := COMP(0, HT); END;
POL := GRNORP(SPG, DIPFMO(RNINT(1), HT));

SL := SIL;
FOR I := 1 TO M DO
     HT := SIL;
     FOR J := 1 TO I DO HT := COMP(1, HT); END;
     FOR J := I+1 TO M DO HT := COMP(0, HT); END;
     SL := COMP(GRNORP(SPG, DIPFMO(RNINT(1), HT)), SL);
     END; (* of for *)

WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, DUMMY);
    SHT := CINV(HT);
    LBIBS(SHT);
    SHT := COMP(0, SHT);
    XLS := SIL;
    FOR I := 1 TO M DO XLS := COMP(LELT(SHT,I+1) - LELT(SHT,I), XLS); END;
    XLS := INV(XLS);
    PP1 := SIL;
    FOR I := 1 TO M DO PP1 := COMP(0, PP1); END;
    PP1 := DIPFMO(RNINT(1), PP1);
    PP2 := SIL;
    FOR I := 1 TO M DO PP2 := COMP(0, PP2); END;
    PP2 := DIPFMO(RNINT(1), PP2);
    XSR := SR;
    XSL := SL;
    WHILE XLS # SIL DO
         ADV(XLS, EL, XLS);
         ADV(XSL, SLEL, XSL);
         ADV(XSR, SREL, XSR);
         PP1 := DIRPPR(PP1, DIRPEX(SLEL, EL));
         PP2 := DIRPPR(PP2, DIRPEX(SREL, EL));
         END; (* of while *)
    POL := DIRPDF(POL, DIRPRP(PP1, HK));
    SPO := DIRPSM(SPO, DIRPRP(PP2, HK));
    END; (* of while *)
RETURN(SPO);
END NOEL32;

PROCEDURE MERGE(FLAG: BOOLEAN; BASE1, POL1: LIST; VAR BASE2, POL2: LIST);
VAR XBASE, NPOL1, NPOL2, HK1, HT1, HM1, HK2, HT2, HM2, XX,
    POS1, POS2, DUMMY: LIST;
    I, J, L1, L2, N, SIGN: GAMMAINT;
BEGIN
L1 := LENGTH(BASE1);
L2 := LENGTH(BASE2);
XBASE := SIL;
POS1 := SIL;
POS2 := SIL;
I := 0;
J := 0;
WHILE BASE2 # SIL DO
    ADV(BASE2, HM2, BASE2);
    HT2 := FIRST(HM2);
    LOOP IF BASE1 # SIL THEN
              ADV(BASE1, HM1, DUMMY);
              HT1 := FIRST(HM1);
              SIGN := GSYTWG(HT2, HT1);
         ELSE SIGN := 1; END; (* of if *)
         IF SIGN = 1 THEN
              IF J < L2 THEN J := J + 1; END;
              POS1 := COMP(I, POS1);
              XBASE := COMP(HM2, XBASE);
              EXIT;
              END; (* of if *)
         IF SIGN = 0 THEN
              IF I < L1 THEN I := I + 1; END;
              IF J < L2 THEN J := J + 1; END;
              XBASE := COMP(HM2, XBASE);
              BASE1 := RED(BASE1);
              EXIT;
              END; (* of if *)
         IF SIGN = -1 THEN
              IF I < L1 THEN I := I + 1; END;
              POS2 := COMP(J, POS2);
              XBASE := COMP(HM1, XBASE);
              BASE1 := RED(BASE1);
              END; (* of if *)
         END; (* of loop *)
    END; (* of while *)

WHILE BASE1 # SIL DO
    ADV(BASE1, HM1, BASE1);
    XBASE := COMP(HM1, XBASE);
    POS2 := COMP(J, POS2);
    END; (* of while *)

BASE2 := INV(XBASE);
N := LENGTH(BASE2);

NPOL1 := 0;
IF POL1 = 0 THEN POL1 := SIL; END;
WHILE POL1 # SIL DO
    DIPMAD(POL1, HK1, HT1, POL1);
    XX := INV(CINV(HT1));
    FOR I := 1 TO LENGTH(POS1) DO
         XX := LEINST(XX, LELT(POS1, I), 0);
         END; (* of for *)
    NPOL1 := DIRPSM(DIPFMO(HK1, XX), NPOL1);
    END; (* of while *)

NPOL2 := 0;
IF POL2 = 0 THEN POL2 := SIL; END;
WHILE POL2 # SIL DO
    DIPMAD(POL2, HK2, HT2, POL2);
    XX := INV(CINV(HT2));
    FOR I := 1 TO LENGTH(POS2) DO
         XX := LEINST(XX, LELT(POS2, I), 0);
         END; (* of for *)
    NPOL2 := DIRPSM(DIPFMO(HK2, XX), NPOL2);
    END; (* of while *)

IF FLAG THEN POL2 := DIRPSM(NPOL1, NPOL2); RETURN; END; (* add *)
IF NPOL1 = 0 THEN POL2 := NPOL2; RETURN; END; (* multiplicate *)
IF NPOL2 = 0 THEN POL2 := NPOL1; RETURN; END;
POL2 := DIRPPR(NPOL1, NPOL2);
END MERGE;

PROCEDURE NOESRT(POL: LIST): LIST;
VAR RES, NPOL, HK, HK1, HT, HT1, DUMMY: LIST;
BEGIN
RES := SIL;
IF POL = SIL THEN RETURN(RES); END;
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    NPOL := RES; RES := SIL;
    LOOP IF NPOL = SIL THEN EXIT; END;
         DIPMAD(NPOL, HK1, HT1, DUMMY);
         IF GSYTWG(HT1, HT) = 1 THEN
              RES := COMP(HT1, COMP(HK1, RES));
              DIPMAD(NPOL, HK1, HT1, NPOL);
         ELSE EXIT; END; (* of if *)
         END; (* of loop *)
    RES := COMP(HT, COMP(HK, RES));
    WHILE NPOL # SIL DO
         DIPMAD(NPOL, HK1, HT1, NPOL);
         RES := COMP(HT1, COMP(HK1, RES));
         END; (* of while *)
    NPOL := RES; RES := SIL; (* reverse list *)
    WHILE NPOL # SIL DO
         DIPMAD(NPOL, HK, HT, NPOL);
         RES := COMP(HT, COMP(HK, RES));
         END; (* of while *)
    END; (* of while *)
RETURN(RES);
END NOESRT;

PROCEDURE NOEPOW(PG: LIST; K: GAMMAINT): LIST;
VAR POL, XPOL, NPOL, HKPOL, HKBASE, XHK, XHT, HT1, HT2,
    HK, HT, NHT, MO, POS, EL, XX, DUMMY: LIST;
    I, J, N: GAMMAINT;
BEGIN
POL := 0;
XPOL := 0;
NPOL := 0;
IF PG = SIL THEN RETURN(POL); END;

N := LENGTH(FIRST(PG));
HT := SIL;
FOR I := N TO 1 BY -1 DO HT := COMP(I, HT); END;
POL := GRNORP(PG, DIPFMO(RNINT(1), HT));

IF POL = 0 THEN POL := SIL; END;
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    I := 0;
    XX := 0;
    WHILE HT # SIL DO
         ADV(HT, POS, HT);
         I := I + 1;
         NHT := SIL;
         FOR J:= 1 TO N DO
              IF I = J THEN NHT := COMP(1, NHT);
              ELSE NHT := COMP(0, NHT); END; (* of if *)
              END; (* of for *)
         FOR J := 1 TO N DO
              IF POS = J THEN NHT := COMP(1, NHT);
              ELSE NHT := COMP(0, NHT); END; (* of if *)
              END; (* of for *)
         XX := DIRPSM(XX, DIPFMO(RNINT(1), NHT));
         END; (* of while *)
    NPOL := DIRPSM(NPOL, DIRPEX(XX, K));
    END; (* of while *)

POL := SIL;
IF NPOL = 0 THEN NPOL := SIL; END;
WHILE NPOL # SIL DO
    DIPMAD(NPOL, HK, HT, NPOL);
    HT := INV(HT);
    HT1 := SIL; HT2 := SIL;
    FOR I := 1 TO N DO ADV(HT, EL, HT); HT1 := COMP(EL, HT1); END;
    FOR I := 1 TO N DO ADV(HT, EL, HT); HT2 := COMP(EL, HT2); END;
    MO := DIPFMO(HK, HT2);
    XPOL := POL; POL := SIL;
    WHILE XPOL # SIL DO
         DIPMAD(XPOL, XHK, XHT, XPOL);
         IF EQUAL(XHT, HT1) = 1 THEN XHK := DIRPSM(XHK, MO); MO := SIL; END;
         POL := COMP(XHT, COMP(XHK, POL));
         END; (* of while *)
    IF MO # SIL THEN
         XPOL := POL; POL := SIL;
         LOOP IF XPOL = SIL THEN EXIT; END;
              DIPMAD(XPOL, XHK, XHT, DUMMY);
              IF GSYTWG(XHT, HT1) = 1 THEN
                   POL := COMP(XHT, COMP(XHK, POL));
                   DIPMAD(XPOL, XHK, XHT, XPOL);
              ELSE EXIT; END; (* of if *)
              END; (* of loop *)
        POL := COMP(HT1, COMP(MO, POL));
        WHILE XPOL # SIL DO
              DIPMAD(XPOL, XHK, XHT, XPOL);
              POL := COMP(XHT, COMP(XHK, POL));
              END; (* of while *)
         END;  (* of if *)
    END; (* of while *)

NPOL := POL; POL := SIL;
WHILE NPOL # SIL DO
    DIPMAD(NPOL, XHK, XHT, NPOL);
    DIPMAD(XHK, HK, HT, DUMMY);
    HKPOL := DIPFMO(HK, LIST1(1));
    HKBASE := LIST1(DIPFMO(RNINT(1), HT));
    XHK := SIL;
    XHK := COMP(HKPOL, COMP(HKBASE, XHK));
    POL := COMP(XHT, COMP(XHK, POL));
    END; (* of while *)
POL := NOESRT(POL);
RETURN(POL);
END NOEPOW;

PROCEDURE NOEPSM(POL1, POL2: LIST): LIST;
VAR RES, HK1, HT1, HK1POL, HK1BASE,
    HK2, HT2, HK2POL, HK2BASE, SIGN, DUMMY: LIST;
BEGIN
RES := SIL;
IF POL2 = SIL THEN RETURN(POL1); END;
WHILE POL2 # SIL DO
    DIPMAD(POL2, HK2, HT2, POL2);
    LOOP IF POL1 # SIL THEN
              DIPMAD(POL1, HK1, HT1, DUMMY);
              SIGN := GSYTWG(HT2, HT1);
         ELSE SIGN := 1; END; (* of if *)
         IF SIGN = 1 THEN
              RES := COMP(HT2, COMP(HK2, RES));
              EXIT;
              END; (* of if *)
         IF SIGN = 0 THEN
              DIPMAD(HK1, HK1BASE, HK1POL, DUMMY);
              DIPMAD(HK2, HK2BASE, HK2POL, DUMMY);
              MERGE(TRUE, HK1BASE, HK1POL, HK2BASE, HK2POL);
              HK2 := SIL;
              HK2 := COMP(HK2POL, COMP(HK2BASE, HK2));
              RES := COMP(HT2, COMP(HK2, RES));
              DIPMAD(POL1, HK1, HT1, POL1);
              EXIT;
              END; (* of if *)
         IF SIGN = -1 THEN
              RES := COMP(HT1, COMP(HK1, RES));
              DIPMAD(POL1, HK1, HT1, POL1);
              END; (* of if *)
         END; (* of loop *)
    END; (* of while *)

WHILE POL1 # SIL DO
    DIPMAD(POL1, HK1, HT1, POL1);
    RES := COMP(HT1, COMP(HK1, RES));
    END; (* of while *)
RES := NOESRT(RES);
RETURN(RES);
END NOEPSM;

PROCEDURE NOEMLT(POL, HK, HT, TERM: LIST): LIST;
VAR RES, HKPOL, HKBASE, HK1, HT1, HK1POL, HK1BASE, XHT, DUMMY: LIST;
BEGIN
RES := SIL;
IF POL = SIL THEN RETURN(RES); END;
DIPMAD(HK, HKBASE, HKPOL, DUMMY);
WHILE POL # SIL DO
    DIPMAD(POL, HK1, HT1, POL);
    XHT := EVSUM(HT, HT1);
    IF EVSIGN(EVDIF(TERM, XHT)) >= 0 THEN
         DIPMAD(HK1, HK1BASE, HK1POL, DUMMY);
         MERGE(FALSE, HKBASE, HKPOL, HK1BASE, HK1POL);
         HK1 := SIL;
         HK1 := COMP(HK1POL, COMP(HK1BASE, HK1));
         RES := COMP(XHT, COMP(HK1, RES));
         END; (* of if *)
    END; (* of while *)
RES := NOESRT(RES);
RETURN(RES);
END NOEMLT;

PROCEDURE NOEPPR(POL1, POL2, TERM: LIST): LIST;
VAR POL, HK2, HT2, RES: LIST;
BEGIN
RES := SIL;
IF POL1 = SIL THEN RETURN(POL2); END;
IF POL2 = SIL THEN RETURN(POL1); END;
WHILE POL2 # SIL DO
    DIPMAD(POL2, HK2, HT2, POL2);
    RES := NOEPSM(RES, NOEMLT(POL1, HK2, HT2, TERM));
    END; (* of while *)
RETURN(RES);
END NOEPPR;

PROCEDURE NOEPIP(POL, FACT: LIST): LIST;
VAR RES, HK, HT, HKBASE, HKPOL, DUMMY: LIST;
BEGIN
RES := SIL;
IF FACT = 0 THEN RETURN(RES); END;
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    DIPMAD(HK, HKBASE, HKPOL, DUMMY);
    HKPOL := DIRPRP(HKPOL, FACT);
    HK := SIL;
    HK := COMP(HKPOL, COMP(HKBASE, HK));
    RES := COMP(HT, COMP(HK, RES));
    END; (* of while *)
RES := NOESRT(RES);
RETURN(RES);
END NOEPIP;

PROCEDURE NOEPRM(POL, TERM: LIST): LIST;
VAR RES, HK, HT: LIST;
BEGIN
RES := SIL;
IF TERM = SIL THEN RETURN(POL); END;
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    IF EVSIGN(EVDIF(TERM, HT)) >= 0 THEN RES := COMP(HT, COMP(HK, RES)); END;
    END; (* of while *)
RES := NOESRT(RES);
RETURN(RES);
END NOEPRM;

PROCEDURE COMPARE(PG, SKL, SKP, TERM: LIST; VAR BASE, POL: LIST);
VAR HK, HT, XHK, XHT, PROD, RES, NSKL, XX, DUMMY: LIST;
    I, J, N: GAMMAINT;
BEGIN
BASE := SIL; POL := 0;
IF SKP = 0 THEN RETURN; END;
N := LENGTH(SKL);
IF N = 0 THEN RETURN; END;
NSKL := SIL;
FOR I := N TO 1 BY -1 DO NSKL := COMP(NOEPRM(LELT(SKL, I), TERM), NSKL); END;
RES := SIL;
BLINES(0); SWRITE("SKP "); OWRITE(SKP);
WHILE SKP # SIL DO
    DIPMAD(SKP, HK, HT, SKP);
    BLINES(0); SWRITE("HT = "); OWRITE(HT);
    PROD := SIL;
    FOR I := 1 TO N DO
         FOR J := 1 TO LELT(HT, I) DO
              PROD := NOEPPR(PROD, LELT(NSKL, I), TERM); END;
         END; (* of for *)
    RES := NOEPSM(RES, NOEPIP(PROD, HK));
    END; (* of while *)
LOOP IF RES = SIL THEN RETURN; END;
    DIPMAD(RES, XHK, XHT, RES);
    IF EQUAL(XHT, TERM) = 1 THEN
         DIPMAD(XHK, BASE, POL, DUMMY);
         EXIT;
         END; (* of if *)
    END; (* of loop *)
XX := GRNCHK(PG, BASE, POL);
IF XX = 0 THEN RETURN; END;
DIPMAD(XX, HK, HT, DUMMY);
POL := DIRPRQ(POL, HK);
END COMPARE;

PROCEDURE NOERED(PG, POL: LIST; VAR BASE, BASEPOL, REMPOL: LIST);
VAR HK, HT, HM, ORBIT, SKL, SKP, PSM, BASE1, BASEPOL1, XX, DUMMY: LIST;
    ORDER, DEGREE, KK, I: GAMMAINT;
BEGIN
BASE := SIL;
BASEPOL := SIL;
REMPOL := 0;
IF (POL = 0) OR (PG = SIL) THEN RETURN; END;
ORDER := GSYORD(PG);
SKL := SIL;
FOR I := 1 TO ORDER DO SKL := COMP(NOEPOW(PG, I), SKL); END;
WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, DUMMY);
    HM := DIPFMO(HK, HT);
    ORBIT := GRNORP(PG, HM);
    IF EQUAL(HT, FIRST(ORBIT)) = 1 THEN
         POL := DIRPDF(POL, ORBIT);
         DEGREE := EVTDEG(HT);
         IF DEGREE <= ORDER THEN
              BASE1 := LIST1(DIPFMO(RNINT(1), HT));
              BASEPOL1 := DIPFMO(HK, LIST1(1));
         ELSE SKP := NOEL32(ORDER, DEGREE);
              COMPARE(PG, SKL, SKP, HT, BASE1, BASEPOL1);
              BASEPOL1 := DIRPRP(BASEPOL1, HK);
              END; (* of if *)
         MERGE(TRUE, BASE1, BASEPOL1, BASE, BASEPOL);
    ELSE POL := DIRPDF(POL, HM);
         REMPOL := DIRPSM(REMPOL, HM);
         END; (* of if *)
    END; (* of while *)
GRNCHKBAS(BASE, BASEPOL);
BLINES(1); SWRITE("NOERED exit (BASE): "); OWRITE(BASE);
BLINES(0); SWRITE("NOERED exit (BASEPOL): "); OWRITE(BASEPOL);
BLINES(0); SWRITE("NOERED exit (REMPOL): "); OWRITE(REMPOL);
END NOERED;

END NOETHER.
(* -EOF- *)
