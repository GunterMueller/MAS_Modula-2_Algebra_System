(* ----------------------------------------------------------------------------
 * $Id: DIPRNGB.mi,v 1.3 1992/10/15 16:29:39 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNGB.mi,v $
 * Revision 1.3  1992/10/15  16:29:39  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:23  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:00  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPRNGB;

(* DIP Rational Groebner Bases Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, SFIRST, SRED,
                    CELLS, TIME, 
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT FIRST3, LIST3, LIST2, COMP2, ADV2, OWRITE, 
                    CONC, LAST, AWRITE, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACRN IMPORT RNQ, RNPROD, RNINV, RNRED, RNSUM, RNABS, RNNEG;

FROM DIPC IMPORT DIPFMO, DIPMCP, DIPMAD, DIPEVL, DIPNOV, 
                 VALIS, DIPLPM, 
                 EVCOMP, EVDIF, EVSIGN, EVLCM, EVMT, EVSUM;

FROM DIPRN IMPORT DIRPDF, DIRPWR, DIRPON, DIRPMC, DIRPPR, DIRPSM;

CONST rcsidi = "$Id: DIPRNGB.mi,v 1.3 1992/10/15 16:29:39 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBC3(B,PLI,PLJ,EL: LIST): LIST; 
(*Distributive polynomial groebner basis criterion 3.
B is a non empty list of reduction sets. pi and pj are
distributive polynomials. e is the least common multiple
of the leading exponent vectors of pi and pj. s=1 if the
reduction of pi and pj is necessary s=0 else. *)
VAR  BP, EP, PL, PP, PPI, PPJ, PS, Q, QL, SL, TL: LIST; 
BEGIN
(*1*) (*check polynomials before pli. *) BP:=B; 
      REPEAT ADV2(BP, PS,Q,BP); ADV(PS, PL,PS); 
             IF PL <> PLI THEN EP:=DIPEVL(PL); TL:=EVMT(EL,EP); 
                IF TL = 1 THEN SL:=0; PP:=PS; 
                   WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QL,PP); 
                         IF (QL = PLI) OR (QL = PLJ) THEN
                            SL:=1; END; 
                         END; 
                   IF SL = 0 THEN RETURN(SL); END; 
                   END; 
                END; 
             UNTIL PL = PLI; 
(*2*) (*check polynomials between pli and plj. *) PPI:=PS; 
      REPEAT ADV2(BP, PS,Q,BP); ADV(PS, PL,PS); 
             IF PL <> PLJ THEN EP:=DIPEVL(PL); TL:=EVMT(EL,EP); 
                IF TL = 1 THEN SL:=0; PP:=PPI; 
                   WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QL,PP); 
                         IF QL = PL THEN SL:=1; END; 
                         END; 
                   PP:=PS; 
                   WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QL,PP); 
                         IF QL = PLJ THEN SL:=1; END; 
                         END; 
                   IF SL = 0 THEN RETURN(SL); END; 
                   END; 
                END; 
             UNTIL PL = PLJ; 
(*3*) (*check polynomials after plj. *) PPJ:=PS; 
      WHILE BP <> SIL DO ADV2(BP, PS,Q,BP); ADV(PS, PL,PS); 
            EP:=DIPEVL(PL); TL:=EVMT(EL,EP); 
            IF TL = 1 THEN SL:=0; PP:=PPI; 
               WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QL,PP); 
                     IF QL = PL THEN SL:=1; END; 
                     END; 
               PP:=PPJ; 
               WHILE (PP <> SIL) AND (SL = 0) DO ADV(PP, QL,PP); 
                     IF QL = PL THEN SL:=1; END; 
                     END; 
               IF SL = 0 THEN RETURN(SL); END; 
               END; 
            END; 
      SL:=1; 
(*6*) RETURN(SL); END DIGBC3; 


PROCEDURE DIGBC4(PLI,PLJ,EL: LIST): LIST; 
(*Distributive polynomial groebner basis criterion 4.
pi and pj are polynomials in distributive representation.
e is the least common multiple of the leading exponent vectors
of pi and pj. s=1 if the reduction of pi and pj is necessary
s=0 else. *)
VAR  EI, EJ, EP, SL: LIST; 
BEGIN
(*1*) (*compare least common multiple with product. *) EI:=DIPEVL(PLI); 
      EJ:=DIPEVL(PLJ); EP:=EVSUM(EI,EJ); SL:=EQUAL(EL,EP); SL:=1-SL; 
(*4*) RETURN(SL); END DIGBC4; 


PROCEDURE DIGBMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero rational polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)
VAR  AL, EI, EJ, EL, PB, PI, PIP, PJ, PP, PS, QP, TL: LIST; 
BEGIN
(*1*) (*length p le 1. *) PP:=P; 
      IF (P = SIL) OR (RED(P) = SIL) THEN RETURN(PP); END; 
(*2*) (*search for exponent vector .*) PS:=PP; QP:=BETA; 
      REPEAT ADV(PS, PI,PS); PB:=PS; EI:=DIPEVL(PI); TL:=0; 
             WHILE (PB <> SIL) AND (TL = 0) DO ADV(PB, PJ,PB); 
                   EJ:=DIPEVL(PJ); TL:=EVMT(EI,EJ); END; 
             PB:=QP; 
             WHILE (PB <> SIL) AND (TL = 0) DO ADV(PB, PJ,PB); 
                   EJ:=DIPEVL(PJ); TL:=EVMT(EI,EJ); END; 
             IF TL = 0 THEN QP:=COMP(PI,QP); END; 
             UNTIL PS = SIL; 
      PP:=INV(QP); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
(*3*) (*call dirpnf. *) PS:=PP; QP:=PP; PP:=BETA; 
      REPEAT ADV(PS, PI,PS); DIPMAD(PI, AL,EL,PIP); 
             IF PIP <> SIL THEN PIP:=DIRPNF(QP,PIP); 
                IF PIP <> 0 THEN PI:=DIPMCP(AL,EL,PIP); ELSE
                   PI:=DIPFMO(AL,EL); END; 
                END; 
             PP:=COMP(PI,PP); 
             UNTIL PS = SIL; 
      PP:=INV(PP); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
(*4*) (*sort. *) PP:=DIPLPM(PP); 
(*7*) RETURN(PP); END DIGBMI; 


PROCEDURE DILCPL(P: LIST;  VAR D,B: LIST); 
(*Distributive polynomial list construct pair list.
P is list of polynomials in distributive representation
in r variables. B is the polynomials pairs list and
D is the pairs list. *)
VAR  BP, BR, DL, EL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, V: LIST; 
BEGIN
(*1*) (*prepare input. *) D:=BETA; B:=BETA; 
      IF P = SIL THEN RETURN; END; 
      PP:=P; 
(*2*) (*construct b and d. *) BR:=BETA; PSS:=PP; 
      REPEAT ADV(PSS, PI,QP); Q:=LIST1(PI); BP:=COMP(0,BR); 
             ELI:=DIPEVL(PI); 
             WHILE QP <> SIL DO ADV(QP, PJ,QP); ELJ:=DIPEVL(PJ); 
                   EL:=EVLCM(ELI,ELJ); DL:=LIST3(EL,BP,Q); 
                   D:=COMP(DL,D); Q:=COMP(PJ,Q); END; 
             QP:=INV(Q); SFIRST(BP,QP); BR:=COMP(Q,BP); PSS:=RED(PSS); 
             UNTIL PSS = SIL; 
      D:=EVPLSO(D); B:=INV(BR); 
(*6*) END DILCPL; 


PROCEDURE DILUPL(PL,P,D,B: LIST): LIST; 
(*Distributive polynomial list update pair list.
P is list of polynomials in distributive representation
in r variables. B is the polynomials pairs list and
D is the pairs list. p is a non zero polynomial in
distributive representation. D, P and B are modified.
DP is the updated pairs list. *)
VAR  BP, BPP, BPPP, BR, DL, DP, EL, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP,
     PPR, PS, Q, QS, SL, T, TF, V: LIST; 
BEGIN
(*1*) (*prepare input, update p. *) BP:=B; DP:=BETA; PP:=P; H:=PL; 
      PS:=LIST1(H); PPR:=LAST(PP); SRED(PPR,PS); 
(*2*) (*update b and d. *) ELJ:=DIPEVL(H); 
      WHILE BP <> SIL DO ADV(BP, QS,BPP); ADV(BPP, Q,BPPP); 
            PLI:=FIRST(QS); ELI:=DIPEVL(PLI); EL:=EVLCM(ELI,ELJ); 
            DL:=LIST3(EL,BP,Q); DP:=COMP(DL,DP); PS:=LIST1(H); 
            SRED(Q,PS); SFIRST(BPP,PS); BP:=BPPP; END; 
      DP:=EVPLSO(DP); DP:=EVPLM(D,DP); PS:=LIST1(H); PB:=LIST2(PS,PS); 
      BR:=LAST(B); SRED(BR,PB); 
(*6*) RETURN(DP); END DILUPL; 


PROCEDURE DIRGBA(PL,P,TF: LIST): LIST; 
(*Distributive rational polynomial groebner basis augmentation.
P is a groebner basis of polynomials in distributive
representation in r variables. p is a polynomial. PP is the
groebner basis of (P,p). t is the trace flag.*)
VAR  B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, J1Y, K, PLI,
     PLJ, PLS, PP, PSS, Q, QL, QLS, QP, RL, S, SL, T, X3, X4,
     XC, XD, XH, XS, XT, YD: LIST; 
BEGIN
(*1*) (*prepare input. *) T:=TIME(); XH:=0; PLS:=DIRPMC(PL); 
      IF P = SIL THEN PP:=LIST1(PLS); RETURN(PP); END; 
      PLS:=DIRPNF(P,PLS); J1Y:=CINV(P); PP:=INV(J1Y); 
      IF PLS = 0 THEN RETURN(PP); END; 
      PLS:=DIRPMC(PLS); 
      IF VALIS = SIL THEN TF:=0 END;
(*2*) (*construct b and d. *) D:=BETA; B:=BETA; PSS:=PP; 
      WHILE PSS <> SIL DO ADV(PSS, QL,PSS); QLS:=LIST1(QL); 
            B:=COMP2(QLS,QLS,B); END; 
      B:=INV(B); D:=DILUPL(PLS,PP,D,B); XD:=LENGTH(D); YD:=XD; X3:=0; 
      X4:=0; XS:=0; XH:=0; XT:=TIME(); XC:=CELLS(); 
(*3*) (*loop. *) 
LOOP
      IF D = SIL THEN EXIT END; 
      YD:=YD-1; ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
(*4*) (*use criterions to chek if the reduction is necessary. *) 
LOOP
      X3:=X3+1; SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT END; 
      X4:=X4+1; SL:=DIGBC4(PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT END; 
(*5*) (*reduction step. *) XS:=XS+1; S:=DIRPSP(PLI,PLJ); 
      IF S = 0 THEN EXIT END; 
      XH:=XH+1; H:=DIRPNF(PP,S); 
      IF H = 0 THEN EXIT END; 
      H:=DIRPMC(H); 
      IF TF >= 1 THEN 
         AWRITE(TIME()-T); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); 
         AWRITE(LENGTH(D)); SWRITE(" PAIRS LEFT."); BLINES(0); 
         SWRITE("H="); DIRPWR(H,VALIS,-1); BLINES(0); END; 
      IF TF >= 2 THEN 
         AWRITE(X3); SWRITE(" CRIT3,  "); 
         AWRITE(X4); SWRITE(" CRIT4,  "); 
         AWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1); 
         END; 
      D:=DILUPL(H,PP,D,B); XD:=LENGTH(D);  
EXIT; END;
END; 
(*6*) (*finish. *) 
      IF TF >= 1 THEN 
         AWRITE(TIME()-T); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); 
         AWRITE(LENGTH(D)); SWRITE(" PAIRS LEFT."); BLINES(0);
         END; 
      IF TF >= 2 THEN 
         AWRITE(X3); SWRITE(" CRIT3,  "); 
         AWRITE(X4); SWRITE(" CRIT4,  "); 
         AWRITE(XS); SWRITE(" SPOLY,  "); BLINES(1); 
         END; 
      PP:=DIGBMI(PP); 
(*9*) RETURN(PP); END DIRGBA; 


PROCEDURE DIRGBR(P,TF: LIST): LIST; 
(*Distributive rational polynomial groebner basis recursion.
P is a list of rational polynomials in distributive representation
in r variables. PP is the groebner basis of P. t is the
trace flag.*)
VAR  PL, PP, PS: LIST; 
BEGIN
(*1*) (*call dirgba. *) PP:=BETA; PS:=P; 
      WHILE PS <> SIL DO ADV(PS, PL,PS); 
            PP:=DIRGBA(PL,PP,TF); END; 
(*4*) RETURN(PP); END DIRGBR; 


PROCEDURE DIRLIS(P: LIST): LIST; 
(*Distributive rational polynomial list irreducible set.
P is a list of distributive rational polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)
VAR  EL, FL, IRR, LL, PL, PP, PS, RL, RP, SL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; PS:=BETA; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIRPMC(PL); 
            IF PL <> 0 THEN PS:=COMP(PL,PS); END; 
            END; 
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END; 
      SWRITE("***NF IRR= "); 
(*2*) (*reduce until all polynomials are irreducible. *) 
      LOOP ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIRPNF(PP,PL); 
           AWRITE(IRR); SWRITE(", "); 
           IF PL = 0 THEN LL:=LL-1; 
              IF LL <= 1 THEN EXIT END; 
              ELSE FL:=DIPEVL(PL); SL:=EVSIGN(FL); 
              IF SL = 0 THEN PP:=LIST1(PL); EXIT END; 
              SL:=EQUAL(EL,FL); 
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; 
                 PL:=DIRPMC(PL); END; 
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
           IF IRR = LL THEN EXIT END;
           END; 
(*3*) (*finish. *) BLINES(0); 
(*6*) RETURN(PP); END DIRLIS; 


PROCEDURE DIRPGB(P,TF: LIST): LIST; 
(*Distributive rational polynomials groebner basis.
P is a list of rational polynomials in distributive representation
in r variables. PP is the groebner basis of P. t is the
trace flag.*)
VAR  B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL,
     J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S,
     SL, T, TR, X3, X4, XC, XH, XS, XT, YD, ZD: LIST; 
BEGIN
(*1*) (*prepare input. *)  
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP); 
               IF SL = 1 THEN PP:=LIST1(PLIP); RETURN(PP); END; 
               PPR:=COMP(PLIP,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
      IF VALIS = SIL THEN TF:=0 END;
      T:=TIME(); XH:=0; XS:=0; X3:=0; X4:=0;
(*2*) (*get irreducible basis. construct b and d. *) 
      IF TF < 0 THEN TF:=-TF; TR:=TIME(); CR:=CELLS(); 
         PP:=DIRLIS(PP); 
         SWRITE("***IRR TIME="); AWRITE(TIME()-TR); 
         SWRITE(", CELLS="); AWRITE(CELLS()-CR); BLINES(1); END; 
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
         SWRITE("H="); DIRPWR(H,VALIS,-1); BLINES(0); END; 
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
(*9*) RETURN(PP); END DIRPGB; 


PROCEDURE DIRPNF(P,S: LIST): LIST; 
(*Distributive rational polynomial normal form. P is a list
of non zero polynomials in distributive rational
representation in r variables. S is a distributive rational
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)
VAR  AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE: LIST; 
BEGIN
(*1*) (*s=0. *) 
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN(R); END; 
(*2*) (*reduction step.*) R:=SIL; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMT(TE,QE); 
                    UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); BL:=RNQ(TA,QA); 
                   AP:=DIPFMO(BL,FL); APP:=DIRPPR(QP,AP); 
                   SP:=DIRPDF(SP,APP); END; 
                END; 
             UNTIL SP = 0; 
(*3*) (*finish.*) 
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END; 
(*6*) RETURN(R); END DIRPNF; 


PROCEDURE DIRPSP(A,B: LIST): LIST; 
(*Distributive rational polynomial S polynomial. A and B are
rational polynomials in distributive representation. C is
the S polynomial of A and B. *)
VAR  AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL: LIST; 
BEGIN
(*1*) (*a=0 or b=0. *) C:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      DIPMAD(A, AL,EL,AP); DIPMAD(B, BL,FL,BP); 
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(C); END; 
(*2*) (*reduction. *) GL:=EVLCM(EL,FL); 
      IF AP = SIL THEN FL1:=EVDIF(GL,FL); CL:=RNNEG(AL); 
         BPP:=DIPFMO(CL,FL1); C:=DIRPPR(BP,BPP); RETURN(C); END; 
      IF BP = SIL THEN EL1:=EVDIF(GL,EL); APP:=DIPFMO(BL,EL1); 
         C:=DIRPPR(AP,APP); RETURN(C); END; 
(*3*) (*general case. *) EL1:=EVDIF(GL,EL); FL1:=EVDIF(GL,FL); 
      APP:=DIPFMO(BL,EL1); BPP:=DIPFMO(AL,FL1); 
      APP:=DIRPPR(AP,APP); BPP:=DIRPPR(BP,BPP); 
      C:=DIRPDF(APP,BPP); 
(*6*) RETURN(C); END DIRPSP; 


PROCEDURE EVPLM(L1,L2: LIST): LIST; 
(*Exponent vector pair-list merge.  L1 and L2 are pair-lists
of exponent vectors in non decreasing order.  L is the merge 
of L1 and L2. L1 and L2 are modified to produce L. *)
VAR  AL1, AL2, EL1, EL2, L, LP, LP1, LP2, TL: LIST; 
     eoz: BOOLEAN;
BEGIN
(*1*) (*l1 or l2 null.*) 
      IF L1 = SIL THEN L:=L2; RETURN(L); END; 
      IF L2 = SIL THEN L:=L1; RETURN(L); END; 
(*2*) (*initialize.*) LP1:=L1; LP2:=L2; AL1:=FIRST(L1); AL2:=FIRST(L2); 
      EL1:=FIRST(AL1); EL2:=FIRST(AL2); TL:=EVCOMP(EL1,EL2); 
      IF TL > 0 THEN L:=L2; LP:=L2; LP2:=RED(L2); eoz:=FALSE
         ELSE L:=L1; LP:=L1; LP1:=RED(L1); eoz:=TRUE END; 
LOOP
(*3*) (*last element from l1.*) 
IF eoz THEN 
      IF LP1 = SIL THEN EXIT END; 
      AL1:=FIRST(LP1); EL1:=FIRST(AL1); TL:=EVCOMP(EL1,EL2); 
      IF TL <= 0 THEN LP:=LP1; LP1:=RED(LP1); eoz:=TRUE 
         ELSE SRED(LP,LP2); LP:=LP2; LP2:=RED(LP2); eoz:=FALSE END; 
(*4*) (*last element from l2.*) 
ELSE
      IF LP2 = SIL THEN EXIT END; 
      AL2:=FIRST(LP2); EL2:=FIRST(AL2); TL:=EVCOMP(EL1,EL2); 
      IF TL <= 0 THEN SRED(LP,LP1); LP:=LP1; LP1:=RED(LP1); eoz:=TRUE 
         ELSE LP:=LP2; LP2:=RED(LP2); eoz:=FALSE END; 
      END;
END;
(*5*) (*left over.*) 
      IF LP1 = SIL THEN SRED(LP,LP2); ELSE SRED(LP,LP1); END; 
      RETURN(L); 
(*8*) END EVPLM; 


PROCEDURE EVPLSO(A: LIST): LIST; 
(*Exponent vector pair-list sort. A is a list of pair-lists. B is 
the result of sorting A into non-decreasing order. Pairs of
elements of A are merged. The list A is modified to produce B. *)
VAR  AL1, AL2, AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2,
     TL: LIST; 
BEGIN
(*1*) (*nothing to do. *) 
      IF (A = SIL) OR (RED(A) = SIL) THEN B:=A; RETURN(B); 
      END; 
(*2*) (*construct pairs. *) C:=LIST1(0); CS:=C; AP:=A; 
      REPEAT ADV(AP, AL1,APP); 
             IF APP = SIL THEN BP:=AP; ELSE ADV(APP, AL2,APPP); 
                EL1:=FIRST(AL1); EL2:=FIRST(AL2); TL:=EVCOMP(EL1,EL2); 
                IF TL <= 0 THEN BP:=AP; SRED(APP,SIL); ELSE BP:=APP; 
                   SRED(APP,AP); SRED(AP,SIL); END; 
                END; 
             C:=COMP(BP,C); AP:=APPP; 
             UNTIL (APP = SIL) OR (AP = SIL); 
(*3*) (*circle and merge. *) ADV(C, BP,C); SFIRST(CS,BP); SRED(CS,C); 
      ADV(C, B,CP); 
      WHILE C <> CP DO ADV(CP, BP,CPP); BPP:=EVPLM(B,BP); 
            SFIRST(C,BPP); SRED(C,CPP); C:=CPP; ADV(C, B,CP); END; 
(*6*) RETURN(B); END EVPLSO; 


END DIPRNGB.


(* -EOF- *)
