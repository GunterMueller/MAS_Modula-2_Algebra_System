(* ----------------------------------------------------------------------------
 * $Id: DIPIGB.mi,v 1.3 1992/10/15 16:29:37 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIGB.mi,v $
 * Revision 1.3  1992/10/15  16:29:37  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:20  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:56  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIGB;

(* DIP Integral Groebner Bases Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, SFIRST, SRED,
                    CELLS, TIME, 
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT FIRST3, LIST3, LIST2, COMP2, ADV2, OWRITE, 
                    CCONC, CONC, LAST, AWRITE, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACI IMPORT IPROD, ISUM, IABSF, INEG, IGCDCF;

FROM SACRN IMPORT RNRED, RNDWR;

FROM DIPC IMPORT DIPFMO, DIPMCP, DIPMAD, DIPEVL, DIPNOV, 
                 VALIS, DIPLPM, 
                 EVCOMP, EVDIF, EVSIGN, EVLCM, EVMT, EVSUM;

FROM DIPI IMPORT DIIPIP, DIIPDF, DIIPWR, DIIPON, DIIPCP, DIIPPR, DIIPSM;

FROM DIPRNGB IMPORT DIGBC4, DIGBC3, DILCPL, DILUPL; 

CONST rcsidi = "$Id: DIPIGB.mi,v 1.3 1992/10/15 16:29:37 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIIGBA(PL,P,TF: LIST): LIST; 
(*Distributive integral polynomial groebner basis augmentation.
P is a groebner basis of polynomials in distributive
representation in r variables. p is a polynomial. PP is the
groebner basis of (P,p). tf is the trace flag.*)
VAR   B, C, CL, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, J1Y, K,
      PLI, PLJ, PLS, PP, PSS, Q, QL, QLS, QP, RL, S, SL, T, X3,
      X4, XC, XD, XH, XS, XT, YD: LIST; 
BEGIN
(*1*) (*prepare input. *) T:=TIME(); XH:=0; DIIPCP(PL, CL,PLS); 
      IF P = SIL THEN PP:=LIST1(PLS); RETURN(PP); END; 
      PLS:=DIIPNF(P,0,PLS); J1Y:=CINV(P); PP:=INV(J1Y); 
      IF PLS = 0 THEN RETURN(PP); END; 
      DIIPCP(PLS, CL,PLS); 
(*2*) (*construct b and d. *) D:=BETA; B:=BETA; PSS:=PP; 
      WHILE PSS <> SIL DO ADV(PSS, QL,PSS); QLS:=LIST1(QL); 
            B:=COMP2(QLS,QLS,B); END; 
      B:=INV(B); D:=DILUPL(PLS,PP,D,B); XD:=LENGTH(D); YD:=XD; X3:=0; 
      X4:=0; XS:=0; XH:=0; XT:=TIME(); XC:=CELLS(); 
(*3*) (*loop. *) 
LOOP 
      IF D = SIL THEN EXIT (*GO TO 6;*) END; 
      YD:=YD-1; ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
(*4*) (*use criterions to chek if the reduction is necessary. *) 
LOOP 
      X3:=X3+1; SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT (*GO TO 3;*) END; 
      X4:=X4+1; SL:=DIGBC4(PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT (*GO TO 3;*) END; 
(*5*) (*reduction step. *) XS:=XS+1; S:=DIIPSP(PLI,PLJ); 
      IF S = 0 THEN EXIT (*GO TO 3;*) END; 
      XH:=XH+1; H:=DIIPNF(PP,0,S); 
      IF H = 0 THEN EXIT (*GO TO 3;*) END; 
      DIIPCP(H, CL,H); 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); 
         SWRITE("H="); OWRITE(H); BLINES(1); END; 
      D:=DILUPL(H,PP,D,B); YD:=LENGTH(D); XD:=YD; X4:=0; X3:=0; XS:=0; 
      XH:=0; XT:=TIME(); XC:=CELLS(); 
EXIT END; 
END; 
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); END; 
      PP:=DIIGMI(PP); 
(*9*) RETURN(PP); END DIIGBA; 


PROCEDURE DIIGMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero integral polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)
VAR   AL, CL, EI, EJ, EL, PB, PI, PIP, PJ, PL, PP, PS, QP, TL: LIST; 
BEGIN
(*1*) (*length p le 1. *) PP:=P; 
      IF (P = SIL) OR (RED(P) = SIL) THEN RETURN(PP); END; 
(*2*) (*remove extreanous polynomials.*) PS:=PP; QP:=BETA; 
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
(*3*) (*normal form of monomial reductas. *) PS:=PP; QP:=PP; PP:=BETA; 
      REPEAT ADV(PS, PI,PS); DIPMAD(PI, AL,EL,PIP); 
             IF PIP <> SIL THEN PL:=DIPFMO(AL,EL); 
                PI:=DIIPNF(QP,PL,PIP); DIIPCP(PI, CL,PI); END; 
             PP:=COMP(PI,PP); 
             UNTIL PS = SIL; 
      PP:=INV(PP); 
(*4*) (*sort. *) PP:=DIPLPM(PP); 
(*7*) RETURN(PP); END DIIGMI; 


PROCEDURE DIILIS(P: LIST): LIST; 
(*Distributive integral polynomial list irreducible set.
P is a list of distributive integral polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)
VAR   CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; PS:=BETA; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); DIIPCP(PL, CL,PL); 
            IF PL <> 0 THEN PS:=COMP(PL,PS); END; 
            END; 
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END; 
      BLINES(1); SWRITE("***nf irr= "); 
(*2*) (*reduce until all polynomials are irreducible. *) 
      LOOP ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIIPNF(PP,0,PL); 
           OWRITE(IRR); SWRITE(", "); 
           IF PL = 0 THEN LL:=LL-1; 
              IF LL <= 1 THEN EXIT END; 
              ELSE FL:=DIPEVL(PL); SL:=EVSIGN(FL); 
              IF SL = 0 THEN PP:=LIST1(PL); EXIT; END; 
              SL:=EQUAL(EL,FL); 
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; DIIPCP(PL,
                 CL,PL); END; 
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
           IF IRR = LL THEN EXIT END; 
           END; (*loop*)
(*3*) (*finish. *) BLINES(1); AWRITE(LL); 
      SWRITE("  irreducible polynomials."); BLINES(1); 
(*6*) RETURN(PP); END DIILIS; 


PROCEDURE DIIPGB(P,TF: LIST): LIST; 
(*Distributive integral polynomial groebner basis. P is a
list of integral polynomials in distributive representation
in r variables. PP is the groebner basis of P. tf is the
trace flag.*)
VAR   B, C, CL, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, 
      IL, J1Y, PL, PLI, PLJ, PP, PPR, PS, Q, QP, RL, S, SL, T,
      TR, X3, X4, XC, XD, XH, XS, XT, YD, ZD: LIST; 
BEGIN
(*1*) (*prepare input. *) 
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN DIIPCP(PLI, CL,PL); PPR:=COMP(PL,PPR); 
               END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
      PPR:=DIPLPM(PP); PP:=INV(PPR); XT:=TIME(); XC:=CELLS(); X3:=0; 
      X4:=0; XS:=0; XH:=0; 
(*2*) (*get irreducible basis, construct b and d. *) 
      IF XH > 0 THEN TR:=TIME(); CR:=CELLS(); PP:=DIILIS(PP); 
         SWRITE("***irr time="); AWRITE(TIME()-TR); 
         SWRITE(", cells="); AWRITE(CELLS()-CR); BLINES(1); END; 
      PPR:=DIPLPM(PP); PP:=INV(PPR); DILCPL(PP, D,B); XD:=LENGTH(D); 
      YD:=XD; 
(*3*) (*loop until no more pairs left. *) 
LOOP 
      IF D = SIL THEN EXIT; (*GO TO 6;*) END; 
      YD:=YD-1; ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
      IF TF >= 3 THEN OWRITE(EL); BLINES(0); SWRITE("pli="); 
         OWRITE(PLI); BLINES(1); SWRITE("plj="); OWRITE(PLJ); 
         BLINES(1); END; 
(*4*) (*use criterions to check if the reduction is necessary.*) 
LOOP
      X3:=X3+1; SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT; (*GO TO 3;*) END; 
      X4:=X4+1; SL:=DIGBC4(PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT (*GO TO 3;*) END; 
(*5*) (*reduction step. *) XS:=XS+1; S:=DIIPSP(PLI,PLJ); 
      IF S = 0 THEN EXIT (*GO TO 3;*) END; 
      DIIPCP(S, CL,S); XH:=XH+1; H:=DIIPNF(PP,0,S); 
      IF H = 0 THEN EXIT (*GO TO 3;*) END; 
      DIIPCP(H, CL,H); SL:=DIIPON(H); 
      IF SL = 1 THEN PP:=LIST1(H); RETURN(PP); END; 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); 
         SWRITE("H="); DIIPWR(H,VALIS); BLINES(1); END; 
      D:=DILUPL(H,PP,D,B); XD:=LENGTH(D); YD:=XD; X3:=0; X4:=0; XS:=0; 
      XH:=0; (*GO TO 3;*) 
EXIT; END; 
END;
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); END; 
      PP:=DIIGMI(PP); 
(*9*) RETURN(PP); END DIIPGB; 


PROCEDURE DIIPNF(P,RPP,S: LIST): LIST; 
(*Distributive integral polynomial normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. S is a distributive integral
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to p. *)
VAR   AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, R, RP, RS, SL, SP, TA,
      TE: LIST; 
BEGIN
(*1*) (*s=0. *) 
      IF S = 0 THEN R:=RPP; RETURN(R); END; 
      IF P = SIL THEN
         IF RPP = 0 THEN R:=S; ELSE R:=CCONC(RPP,S); END; 
         RETURN(R); END; 
(*2*) (*reduction step.*) SP:=S; R:=RPP; 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMT(TE,QE); 
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
(*3*) (*finish.*) RETURN(R); 
(*6*) END DIIPNF; 


PROCEDURE DIIPSP(A,B: LIST): LIST; 
(*Distributive integral polynomial s polynomial. A and B are
integral polynomials in distributive representation. C is
the S-polynomial of A and B. *)
VAR   AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL: LIST; 
BEGIN
(*1*) (*a=0 or b=0. *) C:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      DIPMAD(A, AL,EL,AP); DIPMAD(B, BL,FL,BP); 
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(C); END; 
(*2*) (*reduction. *) GL:=EVLCM(EL,FL); IGCDCF(AL,BL, CL,AL,BL); 
      IF AP = SIL THEN FL1:=EVDIF(GL,FL); AL:=INEG(AL); 
         BPP:=DIPFMO(AL,FL1); C:=DIIPPR(BP,BPP); RETURN(C); END; 
      IF BP = SIL THEN EL1:=EVDIF(GL,EL); APP:=DIPFMO(BL,EL1); 
         C:=DIIPPR(AP,APP); RETURN(C); END; 
(*3*) (*general case. *) EL1:=EVDIF(GL,EL); FL1:=EVDIF(GL,FL); 
      APP:=DIPFMO(BL,EL1); BPP:=DIPFMO(AL,FL1); APP:=DIIPPR(AP,APP); 
      BPP:=DIIPPR(BP,BPP); C:=DIIPDF(APP,BPP); 
(*6*) RETURN(C); END DIIPSP; 


END DIPIGB.

(* -EOF- *)
