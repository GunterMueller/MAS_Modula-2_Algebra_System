(* ----------------------------------------------------------------------------
 * $Id: TIPRNGB.mi,v 1.1 1995/11/05 15:57:39 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: TIPRNGB.mi,v $
 * Revision 1.1  1995/11/05 15:57:39  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE TIPRNGB;

(* DIP Rational Extended Groebner Bases Implementation Module. *)

FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED,
			SFIRST, SIL, SRED, TIME;

FROM SACLIST	IMPORT	ADV2, EQUAL, FIRST2, FIRST3, LAST, LIST2, LIST3,
			OWRITE;

FROM MASBIOS	IMPORT	BLINES, SWRITE;

FROM SACRN	IMPORT	RNABS, RNINV, RNNEG, RNPROD, RNQ, RNRED, RNSUM;

FROM DIPC	IMPORT	DIPEVL, DIPFMO, DIPLBC, DIPMAD, DIPMCP, EVCOMP,
			EVDIF, EVLCM, EVMT, EVSIGN, EVSUM, VALIS;

FROM DIPRN	IMPORT	DIRPDF, DIRPEX, DIRPON, DIRPPR, DIRPRP, DIRPSM,
			DIRPWR;

FROM DIPRNGB	IMPORT	EVPLM, EVPLSO;

CONST rcsidi = "$Id: TIPRNGB.mi,v 1.1 1995/11/05 15:57:39 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE EGBPMC(AM: LIST): LIST;
VAR A, AX, BL, CM, C, CX, Y: LIST;
BEGIN
CM := SIL;
IF AM = SIL THEN RETURN(CM); END;
FIRST2(AM, A, AX);
IF A = 0 THEN RETURN(CM); END;
BL := RNINV(DIPLBC(A)); C := DIRPRP(A, BL);
CX := SIL;
WHILE AX # SIL DO ADV(AX, Y, AX); Y := DIRPRP(Y, BL); CX := COMP(Y, CX); END; 
CM := COMP(C, COMP(INV(CX), CM));
RETURN(CM);
END EGBPMC;

PROCEDURE EGBPON(AM: LIST): LIST;
VAR A, AX: LIST;
BEGIN
IF AM = SIL THEN RETURN(0); END;
FIRST2(AM, A, AX);
RETURN(DIRPON(A));
END EGBPON;

PROCEDURE EGBC3(B, PMI, PMJ, EL: LIST): LIST;
VAR BP, EP, PM, PL, PX, PP, PLI, PLJ, PXI, PXJ, PPI, PPJ,
    PS, Q, QM, SL, TL: LIST;
BEGIN
BP := B;
REPEAT ADV2(BP, PS, Q, BP);
    ADV(PS, PM, PS); FIRST2(PM, PL, PX);
    IF PM <> PMI THEN EP := DIPEVL(PL);
         TL := EVMT(EL, EP);
         IF TL = 1 THEN SL := 0; 
              PP := PS;
              WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QM, PP);
                   IF (QM = PMI) OR (QM = PMJ) THEN SL := 1; END;
                   END;
              IF SL = 0 THEN RETURN(SL); END;
              END;
         END;
    UNTIL PM = PMI;

PPI := PS;
REPEAT ADV2(BP, PS, Q, BP);
    ADV(PS, PM, PS); FIRST2(PM, PL, PX);
    IF PM <> PMJ THEN EP := DIPEVL(PL);
         TL := EVMT(EL,EP);
         IF TL = 1 THEN SL := 0; 
              PP := PPI;
              WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QM, PP);
                   IF QM = PM THEN SL := 1; END;
                   END;
              PP := PS;
              WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QM, PP);
                   IF QM = PMJ THEN SL := 1; END;
                   END;
              IF SL = 0 THEN RETURN(SL); END;
              END;
         END;
    UNTIL PM = PMJ;

PPJ := PS;
WHILE BP <> SIL DO ADV2(BP, PS, Q, BP);
    ADV(PS, PM, PS); FIRST2(PM, PL, PX);
    EP := DIPEVL(PL); TL := EVMT(EL, EP);
    IF TL = 1 THEN SL := 0; PP := PPI;
         WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QM, PP);
              IF QM = PM THEN SL := 1; END;
              END;
         PP := PPJ;
         WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QM, PP);
              IF QM = PM THEN SL := 1; END;
              END;
         IF SL = 0 THEN RETURN(SL); END;
         END;
    END;
SL := 1; RETURN(SL);
END EGBC3;

PROCEDURE EGBC4(PMI, PMJ, EL: LIST): LIST;
VAR  PI, PJ, EI, EJ, EP, SL, DUMMY: LIST;
BEGIN
FIRST2(PMI, PI, DUMMY); FIRST2(PMJ, PJ, DUMMY);
EI := DIPEVL(PI); EJ := DIPEVL(PJ);
EP := EVSUM(EI, EJ); SL := EQUAL(EL, EP);
RETURN(1 - SL);
END EGBC4;

PROCEDURE EGBPSP(AM, BM: LIST): LIST;
VAR A, AL, AP, AX, B, BL, BP, BX, C, CL, CX, CM, 
    EL, FL, GL, Y1, Y2, DUMMY: LIST;
BEGIN
CM := SIL;
IF (AM = SIL) OR (BM = SIL) THEN RETURN(CM); END;
FIRST2(AM, A, AX); FIRST2(BM, B, BX);
IF (A = 0) OR (B = 0) THEN RETURN(CM); END;

DIPMAD(A, AL, EL, DUMMY); DIPMAD(B, BL, FL, DUMMY);
GL := EVLCM(EL, FL);
AP := DIPFMO(BL, EVDIF(GL, EL)); BP := DIPFMO(AL, EVDIF(GL, FL));
C := DIRPDF(DIRPPR(A, AP), DIRPPR(B, BP));
IF C = 0 THEN RETURN(CM); END;

CX := SIL;
WHILE AX # SIL DO
    ADV(AX, Y1, AX); Y1 := DIRPPR(Y1, AP);
    ADV(BX, Y2, BX); Y2 := DIRPPR(Y2, BP);
    CX := COMP(DIRPDF(Y1, Y2), CX);
    END; (* of while *)
CM := COMP(C, COMP(INV(CX), CM));
RETURN(CM);
END EGBPSP;

PROCEDURE EGBPNF(P, SM: LIST): LIST;
VAR AP, APP, PP, QM, Q, QX, QA, QE, R, RX, RM,
    SL, S, SX, TA, TE, XX, Y1, Y2, DUMMY: LIST;
BEGIN
RM := SIL;
IF (SM = SIL) OR (P = SIL) THEN RM := SM; RETURN(RM); END;
R := 0;
FIRST2(SM, S, SX);
REPEAT DIPMAD(S, TA, TE, DUMMY);
    PP := P;
    REPEAT ADV(PP, QM, PP); FIRST2(QM, Q, QX);
         DIPMAD(Q, QA, QE, DUMMY); SL := EVMT(TE, QE);
         UNTIL (PP = SIL) OR (SL = 1);
    IF SL = 0 THEN XX := DIPFMO(TA, TE);
         S := DIRPDF(S, XX); 
         R := DIRPSM(R, XX);
    ELSE XX := DIPFMO(RNQ(TA, QA), EVDIF(TE, QE));
         AP := DIRPPR(Q, XX);
         S := DIRPDF(S, AP);
         RX := SIL;
         WHILE SX # SIL DO ADV(SX, Y1, SX);
              ADV(QX, Y2, QX);
              RX := COMP(DIRPDF(Y1, DIRPPR(Y2, XX)), RX);
              END; (* of while *)
         SX := INV(RX);
         END;
    UNTIL S = 0;
RX := SX;
IF R = 0 THEN RETURN(RM); ELSE RM := COMP(R, COMP(RX, RM)); END;
RETURN(RM);
END EGBPNF;

PROCEDURE LISTMERGE(L1, L2: LIST): LIST;
VAR AM1, AM2, AL1, AL2, AX1, AX2, EL1, EL2, L, LP, LP1, LP2, TL: LIST;
    eoz: BOOLEAN;
BEGIN
IF L1 = SIL THEN L := L2; RETURN(L); END;
IF L2 = SIL THEN L := L1; RETURN(L); END;

LP1 := L1; LP2 := L2;
AM1 := FIRST(L1); AM2 := FIRST(L2);
FIRST2(AM1, AL1, AX1); FIRST2(AM2, AL2, AX2);
EL1 := DIPEVL(AL1); EL2 := DIPEVL(AL2);
TL := EVCOMP(EL1, EL2);
IF TL > 0 THEN L := L2; LP := L2; LP2 := RED(L2); eoz := FALSE;
ELSE L := L1; LP := L1; LP1 := RED(L1); eoz := TRUE; END;

LOOP IF eoz THEN
         IF LP1 = SIL THEN EXIT; END;
         AM1 := FIRST(LP1); FIRST2(AM1, AL1, AX1);
         EL1 := DIPEVL(AL1); TL := EVCOMP(EL1, EL2);
         IF TL <= 0 THEN LP := LP1; LP1 := RED(LP1); eoz := TRUE;
         ELSE SRED(LP, LP2); LP := LP2; LP2 := RED(LP2); eoz:=FALSE; END;
    ELSE IF LP2 = SIL THEN EXIT; END;
         AM2 := FIRST(LP2); FIRST2(AM2, AL2, AX2);
         EL2 := DIPEVL(AL2); TL := EVCOMP(EL1, EL2);
         IF TL <= 0 THEN SRED(LP, LP1); LP := LP1; LP1 := RED(LP1); eoz := TRUE;
         ELSE LP := LP2; LP2 := RED(LP2); eoz := FALSE END;
         END;
    END;
IF LP1 = SIL THEN SRED(LP, LP2); ELSE SRED(LP, LP1); END;
RETURN(L);
END LISTMERGE;

PROCEDURE EGBLPM(A: LIST): LIST;
VAR AM1, AM2, AL1, AL2, AX1, AX2, AP, APP, APPP, B, BP, BPP,
    C, CP, CPP, CS, EL1, EL2, TL: LIST;
BEGIN
IF (A = SIL) OR (RED(A) = SIL) THEN B := A; RETURN(B); END;
C := LIST1(0); CS := C; AP := A;
REPEAT ADV(AP, AM1, APP); FIRST2(AM1, AL1, AX1);
    IF APP = SIL THEN BP := AP;
    ELSE ADV(APP, AM2, APPP); FIRST2(AM2, AL2, AX2);
         EL1 := DIPEVL(AL1); EL2 := DIPEVL(AL2);
         TL := EVCOMP(EL1, EL2);
         IF TL <= 0 THEN BP := AP; SRED(APP, SIL);
         ELSE BP := APP; SRED(APP, AP); SRED(AP, SIL); END;
         END;
    C := COMP(BP, C); AP := APPP;
    UNTIL (APP = SIL) OR (AP = SIL);

ADV(C, BP, C); SFIRST(CS, BP); SRED(CS, C); ADV(C, B, CP);
WHILE C <> CP DO ADV(CP, BP, CPP); BPP := LISTMERGE(B, BP);
    SFIRST(C, BPP); SRED(C, CPP); C := CPP; ADV(C, B, CP); END;
RETURN(B);
END EGBLPM;

PROCEDURE EGBMI(GB: LIST): LIST;
VAR AL, EI, EJ, EL, PB, PI, PIP, PJ, PP, PS, QP, TL, PM1, PM2, PX1, PX2: LIST;
BEGIN
PP := GB;
IF (GB = SIL) OR (RED(GB) = SIL) THEN RETURN(PP); END;

PS := PP; QP := SIL;
REPEAT ADV(PS, PM1, PS); FIRST2(PM1, PI, PX1);
    PB := PS; EI := DIPEVL(PI); TL := 0;
    WHILE (PB <> SIL) AND (TL = 0) DO ADV(PB, PM2, PB);
         FIRST2(PM2, PJ, PX2); EJ := DIPEVL(PJ);
         TL := EVMT(EI, EJ);
         END;
    PB := QP;
    WHILE (PB <> SIL) AND (TL = 0) DO ADV(PB, PM2 ,PB);
         FIRST2(PM2, PJ, PX2); EJ := DIPEVL(PJ);
         TL := EVMT(EI,EJ);
         END;
    IF TL = 0 THEN QP := COMP(PM1, QP); END;
    UNTIL PS = SIL;

PP := INV(QP);
IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END;
PS := PP; QP := PP; PP := SIL;
REPEAT ADV(PS, PM1, PS);
    FIRST2(PM1, PI, PX1);
    DIPMAD(PI, AL, EL, PIP);
    IF PIP <> SIL THEN
         PM1 := SIL; PM1 := COMP(PIP, COMP(PX1, PM1));
         PM1 := EGBPNF(QP, PM1);
         IF PM1 <> SIL THEN
              FIRST2(PM1, PIP, PX1);
              PI := DIPMCP(AL, EL, PIP);
         ELSE PI := DIPFMO(AL, EL); END;
         PM1 := SIL; PM1 := COMP(PI, COMP(PX1, PM1));
         END;
    PP := COMP(PM1, PP);
    UNTIL PS = SIL;
PP := INV(PP);
IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END;
RETURN(EGBLPM(PP));
END EGBMI;

PROCEDURE EGBLCPL(P: LIST;  VAR D, B: LIST);
VAR BP, BR, EL, ELI, ELJ, PI, PJ, PP, PM1, PM2, PX1, PX2,
    PSS, Q, QP, V: LIST;
BEGIN
D := SIL; B := SIL;
IF P = SIL THEN RETURN; END;
PP := P; PSS := PP; BR := SIL;
REPEAT ADV(PSS, PM1, QP);
    FIRST2(PM1, PI, PX1);
    Q := LIST1(PM1); BP := COMP(0, BR); ELI := DIPEVL(PI);
    WHILE QP <> SIL DO ADV(QP, PM2, QP); FIRST2(PM2, PJ, PX2);
         ELJ := DIPEVL(PJ); EL := EVLCM(ELI, ELJ);
         D := COMP(LIST3(EL, BP, Q), D); Q := COMP(PM2, Q);
         END;
    QP := INV(Q); SFIRST(BP, QP);
    BR := COMP(Q, BP); PSS := RED(PSS);
    UNTIL PSS = SIL;
D := EVPLSO(D); B := INV(BR);
END EGBLCPL;

PROCEDURE EGBLUPL(PM, P, D, B: LIST): LIST;
VAR BP, BPP, BPPP, BR, DL, DP, EL, ELI, ELJ, PB, PMI, PLI, PXI, PP, PPP,
    PPR, PS, Q, QS, SL, T, TF, V, HM, HI, HX: LIST;
BEGIN
BP := B; DP := SIL; PP := P; HM := PM;
PS := LIST1(HM); PPR := LAST(PP); SRED(PPR, PS);
FIRST2(HM, HI, HX); ELJ := DIPEVL(HI);

WHILE BP <> SIL DO ADV(BP, QS, BPP); ADV(BPP, Q, BPPP);
            PMI := FIRST(QS); FIRST2(PMI, PLI, PXI);
            ELI := DIPEVL(PLI); EL := EVLCM(ELI, ELJ);
            DL := LIST3(EL, BP, Q); DP := COMP(DL, DP);
            PS := LIST1(HM); SRED(Q, PS); SFIRST(BPP, PS); BP := BPPP;
            END;
DP := EVPLSO(DP); DP := EVPLM(D, DP);
PS := LIST1(HM); PB := LIST2(PS, PS);
BR := LAST(B); SRED(BR, PB);
RETURN(DP);
END EGBLUPL;

PROCEDURE DIREGB(P, TF: LIST; VAR GB, GBM: LIST);
VAR B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, J1Y, K, PMI, PMIP, PMJ, 
    PM, PL, PX, PP, PPP, PPR, PS, Q, QP, SM, HM, H, HX, SL, T, 
    X3, X4, XC, XH, XS, YD, I, XX: LIST;
BEGIN
GB := SIL; GBM := SIL; PP := SIL;
IF P = SIL THEN RETURN; END;
PS := P; K := 0; YD := LENGTH(P);
WHILE PS <> SIL DO ADV(PS, PMI, PS);
    IF PMI # 0 THEN 
         K := K + 1;
         XX := SIL;
         FOR I := K + 1 TO YD DO XX := COMP(0, XX); END;
         XX := COMP(DIRPEX(PMI, 0), XX);
         FOR I := 1 TO K - 1 DO XX := COMP(0, XX); END;
         PP := COMP(LIST2(PMI, XX), PP);
         END; 
    END; (* of while *)
IF PP = SIL THEN RETURN; END;

PS := PP; PPR := SIL;
WHILE PS <> SIL DO ADV(PS, PMI, PS);
    IF PMI <> SIL THEN PMIP := EGBPMC(PMI);
         SL := EGBPON(PMIP);
         IF SL = 1 THEN FIRST2(PMIP, GB, GBM);
              GB := LIST1(GB); GBM := LIST1(GBM); RETURN;
              END;
         PPR := COMP(PMIP, PPR);
         END;
    END; (* of while *)
PP := INV(PPR);

IF (PP = SIL) OR (RED(PP) = SIL) THEN
    WHILE PP # SIL DO ADV(PP, PM, PP);
         FIRST2(PM, PL, PX);
         GB := COMP(PL, GB); GBM := COMP(PX, GBM);
         END;
    GB := INV(GB);  GBM := INV(GBM); RETURN;
    END;

IF VALIS = SIL THEN TF := 0 END;
T := TIME(); XH := 0; XS := 0; X3 := 0; X4 := 0;

PPR := EGBLPM(PP); PP := INV(PPR);
EGBLCPL(PP, D, B); YD := LENGTH(D);

LOOP IF D = SIL THEN EXIT END;
    YD := YD - 1; ADV(D, DL, D);
    FIRST3(DL, EL, CPI, CPJ); ADV(CPI, QP, C);
    PMI := FIRST(QP); J1Y := RED(CPJ);
    PMJ := FIRST(J1Y); J1Y := RED(CPJ);
    CPP := RED(J1Y); SRED(CPJ, CPP);
    IF CPP = SIL THEN Q := LAST(QP); SFIRST(C, Q); END;
    LOOP X3 := X3 + 1; IF EGBC3(B, PMI, PMJ, EL) = 0 THEN EXIT; END;
         X4 := X4 + 1; IF EGBC4(PMI, PMJ, EL) = 0 THEN EXIT; END;
         XS := XS + 1; SM := EGBPSP(PMI, PMJ);
         IF SM = SIL THEN EXIT END;
         XH := XH + 1; HM := EGBPNF(PP, SM);
         IF HM = SIL THEN EXIT; END;
         HM := EGBPMC(HM); FIRST2(HM, H, HX); SL := EGBPON(HM);
         IF SL = 1 THEN FIRST2(PMIP, GB, GBM);
              GB := LIST1(GB); GBM := LIST1(GBM); RETURN;
              END;
         IF TF >= 1 THEN OWRITE(TIME()-T); SWRITE(" S, "); OWRITE(XH);
              SWRITE(" H-POLYNOMIALS, "); OWRITE(YD); SWRITE(" PAIRS LEFT.");
              BLINES(0); SWRITE("H="); DIRPWR(H,VALIS,-1); BLINES(0);
              END;
         IF TF >= 2 THEN OWRITE(X3); SWRITE(" CRIT3,  "); OWRITE(X4);
              SWRITE(" CRIT4,  "); OWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1);
              END;
         D := EGBLUPL(HM, PP, D, B); YD := LENGTH(D);
         EXIT;
         END; (* of loop *)
    END; (* of loop *)

IF TF >= 1 THEN OWRITE(TIME()-T); SWRITE(" S, "); OWRITE(XH);
    SWRITE(" H-POLYNOMIALS, "); OWRITE(YD); SWRITE(" PAIRS LEFT.");
    BLINES(0); SWRITE("H="); DIRPWR(H,VALIS,-1); BLINES(0);
    END;
IF TF >= 2 THEN OWRITE(X3); SWRITE(" CRIT3,  "); OWRITE(X4);
    SWRITE(" CRIT4,  "); OWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1);
    END;
PP := EGBMI(PP);
WHILE PP # SIL DO
    ADV(PP, PM, PP);
    FIRST2(PM, PL, PX);
    GB := COMP(PL, GB); GBM := COMP(PX, GBM);
    END;
GB := INV(GB);  GBM := INV(GBM);
END DIREGB;

END TIPRNGB.
(* -EOF- *)
