(* ----------------------------------------------------------------------------
 * $Id: GSYMFUIN.mi,v 1.1 1995/11/05 15:57:27 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: GSYMFUIN.mi,v $
 * Revision 1.1  1995/11/05 15:57:27  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE GSYMFUIN;
(* G-Symmetric Integral Polynomial System Implementation Module. *)

FROM MASELEM	IMPORT	GAMMAINT;

FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL;

FROM MASBIOS	IMPORT	BLINES, SWRITE;

FROM SACLIST	IMPORT	CINV, EQUAL, LEINST, LELT, LREAD, MEMBER, OWRITE,
			SLELT;

FROM SACSET	IMPORT	LBIBS;

FROM SACLDIO	IMPORT	LDSMKB;

FROM DIPI	IMPORT	DIIPDF, DIIPEX, DIIPIP, DIIPPR, DIIPSM;

FROM DIPC	IMPORT	DIPFMO, DIPMAD, EVCOMP, EVDEL, EVDIF, EVILCI, EVSIGN;

CONST rcsidi = "$Id: GSYMFUIN.mi,v 1.1 1995/11/05 15:57:27 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE GSYINF();
BEGIN
BLINES(1);
SWRITE("G-Symmetric Polynomial System Package:");
BLINES(0);
SWRITE("--------------------------------------");
BLINES(1);
SWRITE("              PG := GSYPGR(Number_of_Variables).");
BLINES(0);
SWRITE("    Symmetric_PG := GSYSPG(Number_of_Variables).");
BLINES(0);
SWRITE("           Order := GSYORD(PG).");
BLINES(0);
SWRITE("GSYNSP(PG).");
BLINES(0);
SWRITE("GSYPGW(PG).");
BLINES(0);
SWRITE("GSYINF().");
BLINES(1);
SWRITE("           Orbit := GINORP(PG, Monom).");
BLINES(0);
SWRITE("      Orbit_List := GINOPL(PG, Monom_List).");
BLINES(0);
SWRITE("         Polynom := GINCHK(PG, Base, Base_Polynom).");
BLINES(0);
SWRITE("        Base_HTL := GINBAS(PG).");
BLINES(0);
SWRITE("GINCUT(PG, Polynom, PG_Symmetric_Polynom, Remainder_Polynom).");
BLINES(0);
SWRITE("GINRED(PG, Polynom, Base, Base_Polynom, Remainder_Polynom).");
BLINES(1);
SWRITE("           Orbit := GRNORP(PG, Monom).");
BLINES(0);
SWRITE("      Orbit_List := GRNOPL(PG, Monom_List).");
BLINES(0);
SWRITE("         Polynom := GRNCHK(PG, Base, Base_Polynom).");
BLINES(0);
SWRITE("        Base_HTL := GRNBAS(PG).");
BLINES(0);
SWRITE("        Base_HTL := GRNGGB(PG).");
BLINES(0);
SWRITE("GRNCUT(PG, Polynom, PG_Symmetric_Polynom, Remainder_Polynom).");
BLINES(0);
SWRITE("GRNRED(PG, Polynom, Base, Base_Polynom, Remainder_Polynom).");
BLINES(1);
END GSYINF;

PROCEDURE GSYPGR(N: GAMMAINT): LIST;
VAR PG, X: LIST;
    I: GAMMAINT;
BEGIN
PG := SIL;
IF N < 1 THEN RETURN(PG); END;
X := LREAD();
WHILE X # SIL DO
    IF LENGTH(X) # N THEN SWRITE("Length error, try again! ");
    ELSE I := 1;
         LOOP IF I > N THEN EXIT; END;
              IF MEMBER(I, X) = 0 THEN EXIT; END;
              I := I + 1;
              END; (* of loop *)
         IF I > N THEN PG := COMP(X, PG);
         ELSE SWRITE("No permutation, try again! "); END;
         END; (* of if *)
    X:= LREAD();
    END; (* of while *)
RETURN(PG);
END GSYPGR;

PROCEDURE GSYPGW(PG: LIST);
VAR F1, F2: LIST;
    N, I: GAMMAINT;
BEGIN
IF PG = SIL THEN BLINES(0); SWRITE("()"); RETURN; END;
N := LENGTH(FIRST(PG));
IF N < 1 THEN RETURN; END;
F1 := SIL;
FOR I := N TO 1 BY -1 DO F1 := COMP(I, F1); END;
WHILE PG # SIL DO
    ADV(PG, F2, PG);
    BLINES(0);
    OWRITE(F1); SWRITE(" --> "); OWRITE(F2);
    END; (* of while *)
END GSYPGW;

PROCEDURE GINORP(PG, MO: LIST): LIST;
VAR HK, HT, HTL, TERM, RES, NRES, NPG, XX, DUMMY: LIST;
    I, N, L, NL: GAMMAINT;
BEGIN
RES := 0;
L := 0;
IF PG = SIL THEN RETURN(RES); END;
N := LENGTH(FIRST(PG));
IF MO = 0 THEN RETURN(RES); END;
IF LENGTH(MO) # 2 THEN RETURN(-1); END;
IF LENGTH(FIRST(MO)) # N THEN RETURN(-1); END;
DIPMAD(MO, HK, HT, DUMMY);
HTL := SIL;
HTL := COMP(HT, HTL);
WHILE HTL # SIL DO
    ADV(HTL, HT, HTL);
    NPG := PG;
    WHILE NPG # SIL DO
         ADV(NPG, XX, NPG);
         TERM := INV(CINV(HT));
         FOR I := 1 TO N DO
              SLELT(TERM, N+1-LELT(XX, I), LELT(HT, N+1-I));
              END; (* of for *)
         NRES := DIIPSM(RES, DIPFMO(HK, TERM));
         IF NRES # 0 THEN NL := LENGTH(NRES); ELSE NL := 0; END;
         IF NL > L THEN
              RES := NRES;
              L := NL;
              HTL := COMP(TERM, HTL);
              END; (* of if *)
         END; (* of while *)
    END; (* of while *)
RETURN(RES);
END GINORP;

PROCEDURE GSYORD(PG: LIST): GAMMAINT;
VAR HK, HT, POL: LIST;
    ORDER, I, N: GAMMAINT;
BEGIN
ORDER := 0;
IF PG = SIL THEN RETURN(ORDER); END;
N := LENGTH(FIRST(PG));
HT := SIL;
FOR I := 0 TO N-1 DO HT := COMP(I, HT); END;
POL := GINORP(PG, DIPFMO(1, HT));
IF POL = 0 THEN POL := SIL; END;
WHILE POL # SIL DO
    DIPMAD(POL, HK, HT, POL);
    ORDER := ORDER + 1;
    END; (* of while *)
RETURN(ORDER);
END GSYORD;

PROCEDURE GSYNSP(PG: LIST);
VAR SPG, ORBIT_SPG, ORBIT_PG, TERM: LIST;
    I, N, MAX, NR: GAMMAINT;
BEGIN
NR := 0;
IF PG = SIL THEN RETURN; END;
N := LENGTH(FIRST(PG));
SPG := GSYSPG(N);
IF N <= 2 THEN MAX := 1; END;
IF N > 2 THEN  MAX := N - 1; END;
TERM := SIL;
FOR I := 1 TO N DO TERM := COMP(0, TERM); END;

LOOP TERM := GSYADD(TERM);
    IF FIRST(TERM) > MAX THEN EXIT; END; (* of if *)
    ORBIT_SPG := GINORP(SPG, DIPFMO(1, TERM));
    WHILE ORBIT_SPG # 0 DO
         NR := NR + 1;
         ORBIT_PG := GINORP(PG, DIPFMO(1, FIRST(ORBIT_SPG)));
         ORBIT_SPG := DIIPDF(ORBIT_SPG, ORBIT_PG);
         END; (* of while *);
    END; (* of loop *)
BLINES(0); SWRITE("There are "); OWRITE(NR); SWRITE(" special polynomial(s).");
END GSYNSP;

PROCEDURE GSYSPG(N: GAMMAINT): LIST;
VAR PG, PERM: LIST;
    I, K: GAMMAINT;
BEGIN
PG := SIL;
IF N < 1 THEN RETURN(SIL); END;
FOR I := 1 TO N DO
    PERM := SIL;
    FOR K := 1 TO N DO PERM := LEINST(PERM, K-1, K); END;
    K := I + 1;
    IF K > N THEN K := 1; END;
    SLELT(PERM, K, I);
    SLELT(PERM, I, K);
    PG := LEINST(PG, I-1, PERM);
    END; (* of for *)
RETURN(PG);
END GSYSPG;

PROCEDURE GINOPL(PG, ML: LIST): LIST;
VAR HM, RES: LIST;
BEGIN
RES := SIL;
WHILE ML # SIL DO
    ADV(ML, HM, ML);
    RES := COMP(GINORP(PG, HM), RES);
    END; (* of while *)
RETURN(INV(RES));
END GINOPL;

PROCEDURE GINCUT(PG, POL: LIST; VAR POL1, POL2: LIST);
VAR ORBIT, HM, HT, HK, DUMMY: LIST;
BEGIN
POL1 := 0;
POL2 := 0;
WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, DUMMY);
    HM := DIPFMO(HK, HT);
    ORBIT := GINORP(PG, HM);
    IF EQUAL(HT, FIRST(ORBIT)) = 1 THEN
         POL1 := DIIPSM(POL1, ORBIT);
         POL := DIIPDF(POL, ORBIT);
    ELSE POL2 := DIIPSM(POL2, HM);
         POL := DIIPDF(POL, HM);
         END; (* of if *)
    END; (* of while *)
END GINCUT;

PROCEDURE GINCHK(PG, BASE, POL: LIST): LIST;
VAR RES, HK, HT, BASE_ORBIT, PROD: LIST;
    I, N: GAMMAINT;
BEGIN
RES := 0;
IF POL = 0 THEN RETURN(RES); END;
N := LENGTH(BASE);
IF N = 0 THEN RETURN(RES); END;
BASE_ORBIT := GINOPL(PG, BASE);
WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, POL);
    IF POL = SIL THEN POL := 0; END;
    PROD := DIIPEX(LELT(BASE_ORBIT, 1), 0);
    FOR I := 1 TO N DO
         PROD := DIIPPR(PROD, DIIPEX(LELT(BASE_ORBIT, I), LELT(HT, I)));
         END; (* of for *)
    RES := DIIPSM(RES, DIIPIP(PROD, HK));
    END; (* of while *)
RETURN(RES);
END GINCHK;

PROCEDURE GINCHKBAS(VAR BASE, POL: LIST);
VAR NBASE, NPOL, HT, HK, POS, DUMMY: LIST;
    I, J, N1, N2: GAMMAINT;
BEGIN
IF POL = 0 THEN BASE := SIL; END;
IF BASE = SIL THEN RETURN; END;
N1 := LENGTH(BASE);
NBASE := BASE;
BASE := SIL;
FOR I := 1 TO N1 DO
    NPOL := POL;
    LOOP IF NPOL = SIL THEN EXIT; END;
         DIPMAD(NPOL, HK, HT, NPOL);
         IF LELT(HT, I) # 0 THEN
              BASE := COMP(LELT(NBASE, I), BASE);
              EXIT; END; (* of if *)
         END; (* of loop *)
    END; (* of for *)
BASE := INV(BASE);
N2 := LENGTH(BASE);
IF N1 = N2 THEN RETURN; END; (* nothing has changed *)

NPOL := POL;
POL := 0;
J := 1;
POS := SIL;
FOR I := 1 TO N1 DO
    IF (J<=N2) AND (EQUAL(LELT(NBASE, I), LELT(BASE, J)) = 1) THEN J := J + 1;
    ELSE POS := COMP(I, POS); END; (* of if *)
    END; (* of for *)
WHILE NPOL # SIL DO
    DIPMAD(NPOL, HK, HT, NPOL);
    FOR I := 1 TO LENGTH(POS) DO
         EVDEL(HT, LELT(POS, I), HT, DUMMY);
         END; (* of for *)
    POL := DIIPSM(POL, DIPFMO(HK, HT));
    END; (* of while *)
END GINCHKBAS;

PROCEDURE GSYMLT(N: GAMMAINT): LIST;
VAR TL, SIGMA, SPG, ORBIT, HK, HT: LIST;
    I, J: GAMMAINT;
BEGIN
TL := SIL;
IF N = 0 THEN RETURN(SIL); END;
SPG := GSYSPG(N);
FOR I := 1 TO N DO
    SIGMA := SIL;
    FOR J := 1 TO I DO SIGMA := COMP(1, SIGMA); END;
    FOR J := I+1 TO N DO SIGMA := COMP(0, SIGMA); END;
    ORBIT := GINORP(SPG, DIPFMO(1, SIGMA));
    WHILE ORBIT # SIL DO
         DIPMAD(ORBIT, HK, HT, ORBIT);
         TL := COMP(HT, TL);
         END; (* of while *)
    END; (* of for *)
RETURN(INV(TL));
END GSYMLT;

PROCEDURE GSYTWG(TERM1, TERM2: LIST): GAMMAINT;
VAR S_TERM1, S_TERM2: LIST;
    SIGN: GAMMAINT;
BEGIN (*  1, if wg(TERM1)>wg(TERM2) or (wg(TERM1)=wg(TERM2) and TERM1>TERM2) *)
      (*  0, if wg(TERM1) = wg(TERM2) and TERM1 = TERM2                      *)
      (* -1, otherwise                                                       *)
S_TERM1 := CINV(TERM1);
S_TERM2 := CINV(TERM2);
LBIBS(S_TERM1);
LBIBS(S_TERM2);
SIGN := EVILCI(S_TERM1, S_TERM2);
IF SIGN = 1 THEN RETURN(1); END;
IF SIGN = 0 THEN RETURN(EVCOMP(TERM1, TERM2)); END;
RETURN(-1);
END GSYTWG;

PROCEDURE EXTRACT(PG, POL_1, POL_2, POL_3: LIST; VAR BASE, POL: LIST);
VAR NPOL, TERM, TERM1, HT, HK, HM, ORBIT, DUMMY: LIST;
    POS, I, N, SIGN: GAMMAINT;
BEGIN
BASE := SIL;
POL := SIL;
IF (POL_1 # 0) AND (POL_2 # 0) THEN
    TERM := FIRST(POL_1);
    TERM1 := FIRST(POL_2);
    SIGN := GSYTWG(TERM, TERM1);
    IF SIGN = 0 THEN
         POL := DIPFMO(1, LIST1(2));
         BASE := LIST1(DIPFMO(1, TERM));
    ELSE
         SIGN := SIGN + 1;
         IF SIGN = 2 THEN SIGN := 1; END;
         POL := DIPFMO(1, COMP(1, LIST1(1)));
         BASE := LEINST(LIST1(DIPFMO(1, TERM)),SIGN,DIPFMO(1,TERM1));
         END; (* of if *)
    END; (* of if *)

WHILE POL_3 # 0 DO
    DIPMAD(POL_3, HK, HT, DUMMY);
    HM := DIPFMO(HK, HT);
    ORBIT := GINORP(PG, HM);
    POL_3 := DIIPDF(POL_3, ORBIT);
    IF BASE = SIL THEN
         POL := DIPFMO(HK, LIST1(1));
         BASE := LIST1(DIPFMO(1, HT));
    ELSE
         N := LENGTH(BASE);
         POS := 0;
         LOOP POS := POS + 1;
              IF POS > N THEN EXIT; END;
              HM := LELT(BASE, POS);
              IF GSYTWG(FIRST(HM), HT) <= 0 THEN EXIT; END;
              END; (* of loop *)
         POS := POS - 1;
         BASE := LEINST(BASE, POS, DIPFMO(1, HT));
         NPOL := POL;
         HT := SIL;
         FOR I := 1 TO N DO HT := COMP(0, HT); END; (* of for *)
         HT := LEINST(HT, POS, 1);
         POL := DIPFMO(HK, HT);
         WHILE NPOL # SIL DO
              DIPMAD(NPOL, HK, HT, NPOL);
              HT := LEINST(HT, POS, 0);
              POL := DIIPSM(DIPFMO(HK, HT), POL);
              END; (* of while *)
         END; (* of if *)
    END; (* of while *)
END EXTRACT;

PROCEDURE MERGE(K: GAMMAINT; BASE_1, POL_1: LIST; VAR BASE_2, POL_2: LIST);
VAR XBASE, NPOL1, NPOL2, HK1, HT1, HM1, HK2, HT2, HM2, POS1, POS2, DUMMY: LIST;
    I, J, L1, L2, N, EL, SIGN: GAMMAINT;
BEGIN
L1 := LENGTH(BASE_1);
L2 := LENGTH(BASE_2);
XBASE := SIL;
POS1 := SIL;
POS2 := SIL;
I := 0;
J := 0;
WHILE BASE_2 # SIL DO
    ADV(BASE_2, HM2, BASE_2);
    HT2 := FIRST(HM2);
    LOOP IF BASE_1 # SIL THEN
              ADV(BASE_1, HM1, DUMMY);
              HT1 := FIRST(HM1);
              SIGN := GSYTWG(HT2, HT1);
         ELSE SIGN := 1; END; (* of if *)
         IF SIGN = 1 THEN
              IF J < L2 THEN J := J + 1; END;
              POS1 := COMP(I, POS1);
              IF J # K THEN XBASE := COMP(HM2, XBASE); END;
              EXIT;
              END; (* of if *)
         IF SIGN = 0 THEN
              IF I < L1 THEN I := I + 1; END;
              IF J < L2 THEN J := J + 1; END;
              XBASE := COMP(HM2, XBASE);
              BASE_1 := RED(BASE_1);
              EXIT;
              END; (* of if *)
         IF SIGN = -1 THEN
              IF I < L1 THEN I := I + 1; END;
              POS2 := COMP(J, POS2);
              XBASE := COMP(HM1, XBASE);
              BASE_1 := RED(BASE_1);
              END; (* of if *)
         END; (* of loop *)
    END; (* of while *)

WHILE BASE_1 # SIL DO
    ADV(BASE_1, HM1, BASE_1);
    XBASE := COMP(HM1, XBASE);
    POS2 := COMP(J, POS2);
    END; (* of while *)

BASE_2 := INV(XBASE);
N := LENGTH(BASE_2);

NPOL1 := 0;
IF POL_1 = 0 THEN POL_1 := SIL; END;
WHILE POL_1 # SIL DO
    DIPMAD(POL_1, HK1, HT1, POL_1);
    FOR I := 1 TO LENGTH(POS1) DO
         HT1 := LEINST(HT1, LELT(POS1, I), 0);
         END; (* of for *)
    NPOL1 := DIIPSM(DIPFMO(HK1, HT1), NPOL1);
    END; (* of while *)

NPOL2 := 0;
IF POL_2 = 0 THEN POL_2 := SIL; END;
WHILE POL_2 # SIL DO
    DIPMAD(POL_2, HK2, HT2, POL_2);
    FOR I := 1 TO LENGTH(POS2) DO
         HT2 := LEINST(HT2, LELT(POS2, I), 0);
         END; (* of for *)
    NPOL2 := DIIPSM(DIPFMO(HK2, HT2), NPOL2);
    END; (* of while *)

IF K = 0 THEN POL_2 := DIIPSM(NPOL1, NPOL2); RETURN; END;
POL_1 := 0;
IF NPOL1 = 0 THEN NPOL1 := SIL; END;
WHILE NPOL1 # SIL DO
    DIPMAD(NPOL1, HK1, HT1, NPOL1);
    EVDEL(HT1, K, HT1, DUMMY);
    POL_1 := DIIPSM(POL_1, DIPFMO(HK1, HT1));
    END; (* of while *)

POL_2 := 0;
IF NPOL2 = 0 THEN NPOL2 := SIL; END;
WHILE NPOL2 # SIL DO
    DIPMAD(NPOL2, HK2, HT2, NPOL2);
    EVDEL(HT2, K, HT2, EL);
    POL_2 := DIIPSM(POL_2, DIIPPR(DIIPEX(POL_1, EL), DIPFMO(HK2, HT2)));
    END; (* of while *)
END MERGE;

PROCEDURE REDUCE(PG, ORBIT: LIST; VAR BASE, POL: LIST);
VAR HK, HT, HM, RED_HT, BHM, BHT, PHM, PHK, PHT, TERM, XX, XHT, XHK, SIGMA,
    SIGMA_TL, BTL, NBTL, ORBIT_S, ORBIT_RED, OMEGA, PBASE, PPOL, SPG, PAIRS,
    MAT, NMAT, RS, ROW, NROW, SIGN, XLS, KOEFF, POS, DUMMY: LIST;
    ACT, LOW, MINI, MAXI, I, J, L, N: GAMMAINT;
    FLAG: BOOLEAN;
BEGIN
BASE := SIL;
POL := 0;
IF ORBIT = 0 THEN RETURN; END;
DIPMAD(ORBIT, HK, HT, DUMMY);
N := LENGTH(HT);
HM := DIPFMO(HK, HT);

SIGMA := SIL;
RED_HT := SIL;
(*-------------------------------------------------------------------------*)
(* ORBIT is a constant polynomial                                          *)
(*-------------------------------------------------------------------------*)
IF EVSIGN(HT) = 0 THEN EXTRACT(PG, 0, 0, ORBIT, BASE, POL); RETURN; END;

MAXI := 0;
MINI := 999999;
FOR I := 1 TO N DO
    ACT := LELT(HT, I);
    IF ACT > MAXI THEN MAXI := ACT; END;
    IF ACT < MINI THEN MINI := ACT; END;
    END; (* of for *)

LOW := MAXI;
I := MAXI - 1;
WHILE I >= MINI DO
    J := 1;
    WHILE (J <= N) AND (LELT(HT, J) # I) DO J:=J+1; END; (* of while *)
    IF J = (N+1) THEN I := -1;
    ELSE LOW := I; END; (* of if *)
    I := I - 1;
    END; (* of while *)

(*-------------------------------------------------------------------------*)
(* ORBIT is not max. n-linked or max. n-linked with no zero exponents      *)
(*-------------------------------------------------------------------------*)
IF (LOW # MINI) OR ((LOW # 0) AND (MAXI > 1)) THEN
    FOR I := N TO 1 BY -1 DO
         ACT := LELT(HT, I);
         IF ACT >= LOW THEN RED_HT := COMP(ACT-1, RED_HT);
         ELSE RED_HT := COMP(ACT, RED_HT); END; (* of if *)
         END; (* of for *)
    SIGMA := EVDIF(HT, RED_HT);
    ORBIT_S := GINORP(PG, DIPFMO(1, SIGMA));
    ORBIT_RED := GINORP(PG, DIPFMO(1, RED_HT));
    OMEGA := DIIPDF(ORBIT, DIIPPR(ORBIT_RED, ORBIT_S));
    EXTRACT(PG, ORBIT_RED, ORBIT_S, OMEGA, BASE, POL);
    RETURN; END; (* of if *)

(*-------------------------------------------------------------------------*)
(* ORBIT is max. n-linked and not multilinear --> try simple reduction     *)
(*-------------------------------------------------------------------------*)
IF MAXI > 1 THEN
    FOR LOW := 1 TO MAXI DO
         RED_HT := SIL;
         FOR I := N TO 1 BY -1 DO
              ACT := LELT(HT, I);
              IF ACT >= LOW THEN RED_HT := COMP(ACT-1, RED_HT);
              ELSE RED_HT := COMP(ACT, RED_HT); END; (* of if *)
              END; (* of for *)
         SIGMA := EVDIF(HT, RED_HT);
         ORBIT_S := GINORP(PG, DIPFMO(1, SIGMA));
         ORBIT_RED := GINORP(PG, DIPFMO(1, RED_HT));
         OMEGA := DIIPDF(ORBIT, DIIPPR(ORBIT_RED, ORBIT_S));
         EXTRACT(PG, ORBIT_RED, ORBIT_S, OMEGA, BASE, POL);
         IF GSYTWG(HT, FIRST(FIRST(BASE))) = 1 THEN RETURN; END;
         END; (* of for *)
    END; (* of if *)

(*-------------------------------------------------------------------------*)
(* ORBIT is max. n-linked and not multilinear --> try extended reduction 1 *)
(*-------------------------------------------------------------------------*)
BLINES(0); SWRITE("HT = "); OWRITE(HT);
BASE := SIL;
POL := SIL;
SPG := GSYSPG(N);
BTL := SIL;
PAIRS := SIL;
MAT := SIL;
RS := SIL;
SIGMA_TL := GSYMLT(N);

WHILE SIGMA_TL # SIL DO
    ADV(SIGMA_TL, SIGMA, SIGMA_TL);
    RED_HT := EVDIF(HT, SIGMA);
    IF EVSIGN(RED_HT) > 0 THEN
         ORBIT_RED := GINORP(PG, DIPFMO(1, RED_HT));
         XX := GINORP(SPG, DIPFMO(1, SIGMA));
    ELSE XX := 0; END; (* of if *)

    WHILE XX # 0 DO
         DIPMAD(XX, XHK, XHT, DUMMY);
         XX := DIIPDF(XX, GINORP(PG, DIPFMO(1, XHT)));
         ORBIT_S := GINORP(PG, DIPFMO(1, XHT));
         EXTRACT(PG, ORBIT_RED, ORBIT_S, 0, PBASE, DUMMY);
         FLAG := FALSE;
         IF MEMBER(PBASE, PAIRS) # 1 THEN
              PAIRS := COMP(PBASE, PAIRS);
              PPOL := DIIPPR(ORBIT_RED, ORBIT_S);
              FLAG := TRUE;
         ELSE PPOL := 0; END; (* of if *)

         KOEFF := SIL;
         PBASE := SIL;
         WHILE PPOL # 0 DO
              DIPMAD(PPOL, PHK, PHT, DUMMY);
              PPOL := DIIPDF(PPOL, GINORP(PG, DIPFMO(PHK, PHT)));
              L := LENGTH(PBASE);
              I := 0;
              LOOP I := I + 1;
                   IF I > L THEN EXIT; END;
                   PHM := LELT(PBASE, I);
                   IF GSYTWG(FIRST(PHM), PHT) <= 0 THEN EXIT; END;
                   END; (* of loop *)
              I := I - 1;
              PBASE := LEINST(PBASE, I, DIPFMO(1, PHT));
              KOEFF := LEINST(KOEFF, I, PHK);
              END; (* of while *)

         ROW := SIL;
         POS := SIL;
         L := LENGTH(BTL);
         NBTL := INV(BTL);
         BTL := SIL;
         LOOP IF PBASE = SIL THEN EXIT; END;
              ADV(PBASE, BHM, PBASE);
              BHT := FIRST(BHM);
              ADV(KOEFF, PHK, KOEFF);
              IF GSYTWG(BHT, HT) < 0 THEN EXIT; END;
              LOOP IF NBTL # SIL THEN
                        ADV(NBTL, TERM, DUMMY);
                        SIGN := GSYTWG(TERM, BHT);
                   ELSE SIGN := -1; END;
                   IF SIGN = 1 THEN
                        L := L - 1;
                        BTL := COMP(TERM, BTL);
                        ROW := COMP(0, ROW);
                        NBTL := RED(NBTL);
                        END; (* of if *)
                   IF SIGN = 0 THEN
                        L := L - 1;
                        BTL := COMP(TERM, BTL);
                        ROW := COMP(PHK, ROW);
                        NBTL := RED(NBTL);
                        EXIT; END; (* of if *)
                   IF SIGN = -1 THEN
                        POS := COMP(L, POS);
                        BTL := COMP(BHT, BTL);
                        ROW := COMP(PHK, ROW);
                        EXIT; END; (* of if *)
                   END; (* of loop *)
              END; (* of loop *)

         WHILE NBTL # SIL DO
              ADV(NBTL, TERM, NBTL);
              BTL := COMP(TERM, BTL);
              ROW := COMP(0, ROW);
              END; (* of while *)

         POS := INV(POS);
         NMAT := INV(MAT);
         MAT := SIL;
         WHILE NMAT # SIL DO
              ADV(NMAT, NROW, NMAT);
              FOR I := 1 TO LENGTH(POS) DO
                   NROW := LEINST(NROW, LELT(POS,I), 0);
                   END; (* of for *)
              MAT := COMP(NROW, MAT);
              END; (* of while *)

         IF EVSIGN(ROW) # 0 THEN  MAT := COMP(ROW, MAT);
         ELSE IF FLAG THEN PAIRS := RED(PAIRS); END; END; (* of if *)
         END; (* of while *)
    END; (* of while *)

XLS := SIL;
IF MAT # SIL THEN
BLINES(0); SWRITE("C/R = "); OWRITE(LENGTH(MAT));
           SWRITE("/"); OWRITE(LENGTH(FIRST(MAT)));
    FOR I := 1 TO LENGTH(FIRST(MAT))-1 DO RS := COMP(0, RS); END;
    RS := COMP(1, RS);
    LDSMKB(MAT, RS, XLS, DUMMY);
    SWRITE(" XLS = "); OWRITE(XLS);
    END; (* of if *)
IF XLS # SIL THEN 
    OMEGA := ORBIT;
    WHILE XLS # SIL DO
         ADV(XLS, XHK, XLS);
         ADV(PAIRS, PBASE, PAIRS);
         IF XHK # 0 THEN
              IF LENGTH(PBASE) = 1 THEN PPOL := DIPFMO(1, LIST1(2));
              ELSE PPOL := DIPFMO(1, COMP(1, LIST1(1))); END;
              PPOL := DIIPIP(PPOL, XHK);
              OMEGA := DIIPDF(OMEGA, GINCHK(PG, PBASE, PPOL));
              MERGE(0, PBASE, PPOL, BASE, POL);
              END; (* of if *)
         END; (* of while *)
     EXTRACT(PG, 0, 0, OMEGA, PBASE, PPOL);
     MERGE(0, PBASE, PPOL, BASE, POL);
     GINCHKBAS(BASE, POL);
     RETURN; END; (* of if *)

(*-------------------------------------------------------------------------*)
(* ORBIT is max. n-linked and not multilinear --> try extended reduction 2 *)
(*-------------------------------------------------------------------------*)
BASE := SIL;
POL := SIL;
SPG := GSYSPG(N);
BTL := SIL;
PAIRS := SIL;
MAT := SIL;
RS := SIL;
SIGMA_TL := GSYMLT(N);

WHILE SIGMA_TL # SIL DO
    ADV(SIGMA_TL, SIGMA, SIGMA_TL);
    RED_HT := EVDIF(HT, SIGMA);
    IF EVSIGN(RED_HT) > 0 THEN
         ORBIT_S := GINORP(PG, DIPFMO(1, SIGMA));
         XX := GINORP(SPG, DIPFMO(1, RED_HT));
    ELSE XX := 0; END; (* of if *)

    WHILE XX # 0 DO
         DIPMAD(XX, XHK, XHT, DUMMY);
         XX := DIIPDF(XX, GINORP(PG, DIPFMO(1, XHT)));
         ORBIT_RED := GINORP(PG, DIPFMO(1, XHT));
         EXTRACT(PG, ORBIT_RED, ORBIT_S, 0, PBASE, DUMMY);
         FLAG := FALSE;
         IF MEMBER(PBASE, PAIRS) # 1 THEN
              PAIRS := COMP(PBASE, PAIRS);
              PPOL := DIIPPR(ORBIT_RED, ORBIT_S);
              FLAG := TRUE;
         ELSE PPOL := 0; END; (* of if *)

         KOEFF := SIL;
         PBASE := SIL;
         WHILE PPOL # 0 DO
              DIPMAD(PPOL, PHK, PHT, DUMMY);
              PPOL := DIIPDF(PPOL, GINORP(PG, DIPFMO(PHK, PHT)));
              L := LENGTH(PBASE);
              I := 0;
              LOOP I := I + 1;
                   IF I > L THEN EXIT; END;
                   PHM := LELT(PBASE, I);
                   IF GSYTWG(FIRST(PHM), PHT) <= 0 THEN EXIT; END;
                   END; (* of loop *)
              I := I - 1;
              PBASE := LEINST(PBASE, I, DIPFMO(1, PHT));
              KOEFF := LEINST(KOEFF, I, PHK);
              END; (* of while *)

         ROW := SIL;
         POS := SIL;
         L := LENGTH(BTL);
         NBTL := INV(BTL);
         BTL := SIL;
         LOOP IF PBASE = SIL THEN EXIT; END;
              ADV(PBASE, BHM, PBASE);
              BHT := FIRST(BHM);
              ADV(KOEFF, PHK, KOEFF);
              IF GSYTWG(BHT, HT) < 0 THEN EXIT; END;
              LOOP IF NBTL # SIL THEN
                        ADV(NBTL, TERM, DUMMY);
                        SIGN := GSYTWG(TERM, BHT);
                   ELSE SIGN := -1; END;
                   IF SIGN = 1 THEN
                        L := L - 1;
                        BTL := COMP(TERM, BTL);
                        ROW := COMP(0, ROW);
                        NBTL := RED(NBTL);
                        END; (* of if *)
                   IF SIGN = 0 THEN
                        L := L - 1;
                        BTL := COMP(TERM, BTL);
                        ROW := COMP(PHK, ROW);
                        NBTL := RED(NBTL);
                        EXIT; END; (* of if *)
                   IF SIGN = -1 THEN
                        POS := COMP(L, POS);
                        BTL := COMP(BHT, BTL);
                        ROW := COMP(PHK, ROW);
                        EXIT; END; (* of if *)
                   END; (* of loop *)
              END; (* of loop *)

         WHILE NBTL # SIL DO
              ADV(NBTL, TERM, NBTL);
              BTL := COMP(TERM, BTL);
              ROW := COMP(0, ROW);
              END; (* of while *)

         POS := INV(POS);
         NMAT := INV(MAT);
         MAT := SIL;
         WHILE NMAT # SIL DO
              ADV(NMAT, NROW, NMAT);
              FOR I := 1 TO LENGTH(POS) DO
                   NROW := LEINST(NROW, LELT(POS,I), 0);
                   END; (* of for *)
              MAT := COMP(NROW, MAT);
              END; (* of while *)

         IF EVSIGN(ROW) # 0 THEN  MAT := COMP(ROW, MAT);
         ELSE IF FLAG THEN PAIRS := RED(PAIRS); END; END; (* of if *)
         END; (* of while *)
    END; (* of while *)

XLS := SIL;
IF MAT # SIL THEN
BLINES(0); SWRITE("C/R = "); OWRITE(LENGTH(MAT));
           SWRITE("/"); OWRITE(LENGTH(FIRST(MAT)));
    FOR I := 1 TO LENGTH(FIRST(MAT))-1 DO RS := COMP(0, RS); END;
    RS := COMP(1, RS);
    LDSMKB(MAT, RS, XLS, DUMMY);
    SWRITE(" XLS = "); OWRITE(XLS);
    END; (* of if *)
(*-------------------------------------------------------------------------*)
(* return ORBIT without reduction                                          *)
(*-------------------------------------------------------------------------*)
IF XLS = SIL THEN EXTRACT(PG, 0, 0, ORBIT, BASE, POL); RETURN; END;

OMEGA := ORBIT;
WHILE XLS # SIL DO
    ADV(XLS, XHK, XLS);
    ADV(PAIRS, PBASE, PAIRS);
    IF XHK # 0 THEN
         IF LENGTH(PBASE) = 1 THEN PPOL := DIPFMO(1, LIST1(2));
         ELSE PPOL := DIPFMO(1, COMP(1, LIST1(1))); END;
         PPOL := DIIPIP(PPOL, XHK);
         OMEGA := DIIPDF(OMEGA, GINCHK(PG, PBASE, PPOL));
         MERGE(0, PBASE, PPOL, BASE, POL);
         END; (* of if *)
    END; (* of while *)
EXTRACT(PG, 0, 0, OMEGA, PBASE, PPOL);
MERGE(0, PBASE, PPOL, BASE, POL);
GINCHKBAS(BASE, POL);
END REDUCE;

PROCEDURE GINRED(PG, POL: LIST; VAR BASE, BASE_POL, REM_POL: LIST);
VAR HK, HT, HM, ORBIT, BASE_1, BASE_POL_1, DUMMY: LIST;
    I: GAMMAINT;
BEGIN
BASE := SIL;
BASE_POL := SIL;
REM_POL := 0;
IF POL = 0 THEN RETURN; END;
WHILE POL # 0 DO
    DIPMAD(POL, HK, HT, DUMMY);
    HM := DIPFMO(HK, HT);
    ORBIT := GINORP(PG, HM);
    IF EQUAL(HT, FIRST(ORBIT)) = 1 THEN
         POL := DIIPDF(POL, ORBIT);
         EXTRACT(PG, 0, 0, ORBIT, BASE_1, BASE_POL_1);
         MERGE(0, BASE_1, BASE_POL_1, BASE, BASE_POL);
    ELSE POL := DIIPDF(POL, HM);
         REM_POL := DIIPSM(REM_POL, HM);
         END; (* of if *)
    END; (* of while *)

I := 1;
WHILE I <= LENGTH(BASE) DO
    BLINES(0); SWRITE("GINRED working... (BASE) "); OWRITE(BASE);
    HM := LELT(BASE,I);
    ORBIT := GINORP(PG, HM);
    REDUCE(PG, ORBIT, BASE_1, BASE_POL_1);
    HT := FIRST(HM);
    IF EQUAL(HT, FIRST(FIRST(BASE_1))) = 1 THEN I := I + 1;
    ELSE MERGE(I, BASE_1, BASE_POL_1, BASE, BASE_POL); END; (* of if *)
    END; (* of while *)

GINCHKBAS(BASE, BASE_POL);
BLINES(1); SWRITE("GINRED exit (BASE): "); OWRITE(BASE);
BLINES(0); SWRITE("GINRED exit (BASE_POL): "); OWRITE(BASE_POL);
BLINES(0); SWRITE("GINRED exit (REM_POL): "); OWRITE(REM_POL);
END GINRED;

PROCEDURE GSYADD(TERM: LIST): LIST;
VAR ADDTERM, EL: LIST;
    I, N, POS: GAMMAINT;
BEGIN
ADDTERM := TERM;
N := LENGTH(TERM);
IF (N <= 2) AND (LELT(TERM,1) = 2) THEN RETURN(ADDTERM); END;
IF (N > 2) AND (LELT(TERM,1) = N) THEN RETURN(ADDTERM); END;
POS := 1;
EL := LELT(TERM, POS);
FOR I := 2 TO N DO
    IF EL > LELT(TERM, I) THEN
         POS := I;
         EL := LELT(TERM, POS);
         END; (* of if *)
    END; (* of for *)
SLELT(ADDTERM, POS, EL+1);
IF POS < N THEN
    FOR I := POS+1 TO N DO SLELT(ADDTERM, I, 0); END;
    END; (* of if *)

I := 1;
LOOP IF I+1 > N THEN EXIT; END;
     IF (LELT(ADDTERM, I) - LELT(ADDTERM, I+1)) > 1 THEN EXIT; END;
     I := I + 1;
     END; (* of loop *)

IF (I = N) AND (LELT(ADDTERM, N) = 0) THEN RETURN(ADDTERM); END;
IF (LELT(ADDTERM,1) = 1) THEN RETURN(ADDTERM); END;
RETURN(GSYADD(ADDTERM));
END GSYADD;

PROCEDURE GINBAS(PG: LIST): LIST;
VAR BASE, XBASE, SPG, ORBIT_SPG, ORBIT_PG, POL, TERM, HK, HT: LIST;
    I, N, MAX, NR1, NR2: GAMMAINT;
BEGIN
NR1 := 0;
NR2 := 0;
XBASE := 0;
BASE := SIL;
IF PG = SIL THEN RETURN(BASE); END;
N := LENGTH(FIRST(PG));
SPG := GSYSPG(N);
IF N <= 2 THEN MAX := 1; END;
IF N > 2 THEN  MAX := N - 1; END;
TERM := SIL;
FOR I := 1 TO N DO TERM := COMP(0, TERM); END;

LOOP TERM := GSYADD(TERM);
    IF FIRST(TERM) > MAX THEN EXIT; END; (* of if *)
    ORBIT_SPG := GINORP(SPG, DIPFMO(1, TERM));
    WHILE ORBIT_SPG # 0 DO
         NR1 := NR1 + 1;
         HT := FIRST(ORBIT_SPG);
         ORBIT_PG := GINORP(PG, DIPFMO(1, HT));
         ORBIT_SPG := DIIPDF(ORBIT_SPG, ORBIT_PG);
         REDUCE(PG, ORBIT_PG, BASE, POL);
         IF EQUAL(HT, FIRST(FIRST(BASE))) = 1 THEN
              NR2 := NR2 + 1;
              BLINES(0); SWRITE("GINBAS working... (Term ");
              OWRITE(NR1); SWRITE("/"); OWRITE(NR2); SWRITE("): "); OWRITE(HT);
              XBASE := DIIPSM(XBASE, DIPFMO(1, HT));
              END; (* of if *)
         END; (* of while *);
    END; (* of loop *)

BASE := SIL;
IF XBASE = 0 THEN XBASE := SIL; END;
WHILE XBASE # SIL DO
    DIPMAD(XBASE, HK, HT, XBASE);
    BASE := COMP(DIPFMO(1, HT), BASE);
    END; (* of while *)
BLINES(1); SWRITE("GINBAS exit (BASE): "); OWRITE(BASE);
BLINES(0); SWRITE("Number of special polynomials: ");OWRITE(NR1);
BLINES(0); SWRITE("Number of base polynomials:    ");OWRITE(NR2);
RETURN(BASE);
END GINBAS;

END GSYMFUIN.
(* -EOF- *)
