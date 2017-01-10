(* ----------------------------------------------------------------------------
 * $Id: DIPGB.mi,v 1.5 1994/07/29 12:01:22 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPGB.mi,v $
 * Revision 1.5  1994/07/29  12:01:22  rose
 * Corrected comment
 *
 * Revision 1.4  1994/05/19  10:42:35  rose
 * Modified trace flag handling
 *
 * Revision 1.3  1992/10/15  16:30:11  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:23  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:37  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPGB;

(* DIP Groebner Bases Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, SFIRST, SRED,
                    CELLS, TIME, 
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT FIRST3, LIST3, LIST2, COMP2, ADV2, OWRITE, 
                    CCONC, CONC, LAST, AWRITE, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACI IMPORT IPROD, ISUM, IABSF, INEG, IGCDCF;

FROM SACRN IMPORT RNRED, RNDWR;

FROM DIPC IMPORT DIPFMO, DIPMCP, DIPMAD, DIPEVL, DIPNOV, DIPTDG,  
                 VALIS, DIPLPM, 
                 EVCOMP, EVDIF, EVSIGN, EVLCM, EVMT, EVSUM;

FROM DIPRNGB IMPORT DIGBC4, DIGBC3, DILCPL, DILUPL; 

FROM DIPADOM IMPORT DIPMOC, DILRD, DILWR, DIFIP, (*DIREAD,*) DIWRIT, 
                    DIPBCP, DIPEXP, DIPDIF, DIPNEG, DIPROD, DIPSUM; 

FROM MASADOM IMPORT ADDIF, ADNEG, ADONE, ADPROD, ADQUOT, 
                    ADSIGN, ADSUM, ADGCDC;

CONST rcsidi = "$Id: DIPGB.mi,v 1.5 1994/07/29 12:01:22 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGMIN(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)
VAR   AL, EI, EJ, EL, PB, PI, PIP, PJ, PP, PS, QP, TL: LIST; 
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
(*3*) (*call dipnor. *) PS:=PP; QP:=PP; PP:=BETA; 
      REPEAT ADV(PS, PI,PS); DIPMAD(PI, AL,EL,PIP); 
             IF PIP <> SIL THEN PIP:=DIPNOR(QP,PIP); 
                IF PIP <> 0 THEN PI:=DIPMCP(AL,EL,PIP); ELSE
                   PI:=DIPFMO(AL,EL); END; 
                END; 
             PP:=COMP(PI,PP); 
             UNTIL PS = SIL; 
      PP:=INV(PP); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
(*4*) (*sort. *) PP:=DIPLPM(PP); 
(*7*) RETURN(PP); END DIGMIN; 


PROCEDURE DILIS(P: LIST): LIST; 
(*Distributive polynomial list irreducible set.
P is a list of distributive polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)
VAR   EL, FL, IRR, LL, PL, PP, PS, RP, SL: LIST; 
BEGIN
(*1*) (*initialise. *) PP:=P; PS:=BETA; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIPMOC(PL); 
            IF PL <> 0 THEN PS:=COMP(PL,PS); END; 
            END; 
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END; 
      BLINES(1); SWRITE("***nf irr= "); 
(*2*) (*reduce until all polynomials are irreducible. *) 
      REPEAT ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIPNOR(PP,PL); 
             AWRITE(IRR); SWRITE(", "); 
             IF PL = 0 THEN LL:=LL-1; 
                IF LL <= 1 THEN RETURN(PP); END; 
                ELSE FL:=DIPEVL(PL); SL:=EQUAL(EL,FL); 
                IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; 
                   PL:=DIPMOC(PL); END; 
                PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
             UNTIL IRR = LL; 
(*3*) (*finish. *) BLINES(1); AWRITE(LL); 
      SWRITE(" irreducible polynomials"); BLINES(1); 
(*6*) RETURN(PP); END DILIS; 


PROCEDURE DIPGB(P,TF: LIST): LIST; 
(*Distributive polynomial groebner basis. P is a
list of polynomials in distributive representation
in r variables. PP is the groebner basis of P. tf is the
trace flag.*)
VAR   B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL,
      J1Y, K, PL, PLI, PLJ, PP, PPR, PS, PSS, Q, QP, RL, S, SL,
      T, TR, X3, X4, XC, XD, XH, XS, XT, YD: LIST; 
BEGIN
(*1*) (*prepare input. *) 
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); PL:=DIPMOC(PLI); 
            IF PLI <> 0 THEN PPR:=COMP(PL,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
      X3:=0; X4:=0; XS:=0; XH:=0; XT:=TIME(); XC:=CELLS(); 
(*2*) (*construct b and d. *) PPR:=DIPLPM(PP); PP:=INV(PPR); PSS:=PP; 
      DILCPL(PP, D,B); XD:=LENGTH(D); YD:=XD; 
(*3*) (*loop. *) 
LOOP 
      IF D = SIL THEN EXIT; (*GO TO 6;*) END; 
      YD:=YD-1; ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
(*4*) (*use criterions to chek if the reduction is necessary. *) 
LOOP
      X3:=X3+1; SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT; (*GO TO 3;*) END; 
      X4:=X4+1; SL:=DIGBC4(PLI,PLJ,EL); 
      IF SL = 0 THEN EXIT (*GO TO 3;*) END; 
(*5*) (*reduction step. *) XS:=XS+1; S:=DIPSP(PLI,PLJ); 
      IF S = 0 THEN EXIT (*GO TO 3;*) END; 
      XH:=XH+1; H:=DIPNOR(PP,S); 
      IF H = 0 THEN EXIT; (*GO TO 3;*) END; 
      H:=DIPMOC(H); 
      IF TF >= 3 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); 
         SWRITE("H="); DIWRIT(H,VALIS); BLINES(1); END; 
      D:=DILUPL(H,PP,D,B); XD:=LENGTH(D); YD:=XD; X3:=0; X4:=0; XH:=0; 
      XS:=0; (*GO TO 3;*) 
EXIT; END;
END; 
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); AWRITE(CELLS()-XC);
         SWRITE(" cells;  "); END;
      IF TF >= 2 THEN BLINES(0); AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); END;
      BLINES(1);
      PP:=DIGMIN(PP); 
(*9*) RETURN(PP); END DIPGB; 


PROCEDURE DIPNOR(P,S: LIST): LIST; 
(*Distributive polynomial normal form. P is a list
of non zero polynomials in distributive
representation in r variables. S is a distributive
polynomial. R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE: LIST; 
BEGIN
(*1*) (*s=0. *) 
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN(R); END; 
(*2*) (*reduction step.*) R:=BETA; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMT(TE,QE); 
                    UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   BL:=ADQUOT(TA,QA); AP:=DIPFMO(BL,FL); 
                   APP:=DIPROD(QP,AP); SP:=DIPDIF(SP,APP); END; 
                END; 
             UNTIL SP = 0; 
(*3*) (*finish.*) 
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END; 
(*6*) RETURN(R); END DIPNOR; 


PROCEDURE DIPSP(A,B: LIST): LIST; 
(*Distributive polynomial S-polynomial. A and B are
polynomials in distributive representation. C is
the S-polynomial of A and B. *)
VAR   AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL: LIST; 
BEGIN
(*1*) (*a=0 or b=0. *) C:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      DIPMAD(A, AL,EL,AP); DIPMAD(B, BL,FL,BP); 
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(C); END; 
(*2*) (*reduction. *) GL:=EVLCM(EL,FL); 
      IF AP = SIL THEN FL1:=EVDIF(GL,FL); CL:=ADNEG(AL); 
         BPP:=DIPFMO(CL,FL1); C:=DIPROD(BP,BPP); RETURN(C); END; 
      IF BP = SIL THEN EL1:=EVDIF(GL,EL); APP:=DIPFMO(BL,EL1); 
         C:=DIPROD(AP,APP); RETURN(C); END; 
(*3*) (*general case. *) EL1:=EVDIF(GL,EL); FL1:=EVDIF(GL,FL); 
      APP:=DIPFMO(BL,EL1); BPP:=DIPFMO(AL,FL1); APP:=DIPROD(AP,APP); 
      BPP:=DIPROD(BP,BPP); C:=DIPDIF(APP,BPP); 
(*6*) RETURN(C); END DIPSP; 



(* DIP Integral Function Groebner Bases Implementation Module. ----- *)

PROCEDURE DIIFGB(P,TF: LIST): LIST; 
(*Distributive integral function polynomial groebner basis.
P is a list of integral function polynomials in
distributive representation in r variables.
PP is the groebner basis of P. tf is the trace flag.*)
VAR   B, C, CL, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, 
      IL, J1Y, PLI, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S, SL, T,
      TR, X3, X4, XC, XD, XDP, XH, XS, XT, YD, ZD: LIST; 
BEGIN
(*1*) (*prepare input. *) 
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN PPR:=COMP(PLI,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
      PPR:=DIPLPM(PP); PP:=INV(PPR); XT:=TIME(); XC:=CELLS(); 
(*2*) (*get irreducible basis, construct b and d. *) 
      IF XH > 0 THEN TR:=TIME(); CR:=CELLS(); PPP:=PP; PP:=BETA; 
         PP:=DIIFLS(PPP);
         IF TF>=3 THEN SWRITE("***irr time="); AWRITE(TIME()-TR); 
            SWRITE(", cells="); AWRITE(CELLS()-CR); BLINES(1); END; END;
      PPR:=DIPLPM(PP); PP:=INV(PPR); DILCPL(PP, D,B); XD:=LENGTH(D); 
      YD:=XD; X3:=0; X4:=0; XS:=0; XH:=0; 
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
      IF SL = 0 THEN EXIT; (*GO TO 3;*) END; 
(*5*) (*reduction step. *) XS:=XS+1; S:=DIIFSP(PLI,PLJ); 
      IF S = 0 THEN EXIT; (*GO TO 3;*) END; 
      IF TF >= 3 THEN SWRITE("S="); OWRITE(S); BLINES(1); END; 
      XH:=XH+1; H:=DIIFNF(PP,0,S); 
      IF H = 0 THEN EXIT; (*GO TO 3;*) END; 
      SL:=DIPTDG(H); 
      IF SL = 0 THEN SWRITE("total degree = 0"); BLINES(1); END; 
      IF TF >= 2 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); 
         AWRITE(CELLS()-XC); SWRITE(" cells,  "); BLINES(0); 
         AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); 
         AWRITE(XH); SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); 
         SWRITE(" pairs,  "); AWRITE(YD); SWRITE(" restp,  "); 
         RNDWR(RNRED(YD,XD),3); SWRITE(" quot."); BLINES(1); 
         SWRITE("H="); DIWRIT(H,VALIS); BLINES(1); END; 
      SL:=DIPTDG(H); 
      IF SL = 0 THEN EXIT; (*GO TO 3;*) END; 
      D:=DILUPL(H,PP,D,B); J1Y:=LENGTH(PP); XDP:=J1Y-1; XD:=XD+XDP; 
      YD:=YD+XDP; X3:=0; X4:=0; XS:=0; XH:=0; (*GO TO 3;*) 
EXIT; END; 
END;
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-XT); SWRITE(" ms,  "); AWRITE(CELLS()-XC);
         SWRITE(" cells;  "); END;
      IF TF >= 2 THEN BLINES(0); AWRITE(X3); SWRITE(" crit3,  "); AWRITE(X4); 
         SWRITE(" crit4,  "); AWRITE(XS); SWRITE(" spoly,  "); AWRITE(XH);
         SWRITE(" hpoly,  "); BLINES(0); AWRITE(XD); SWRITE(" pairs,  ");
         AWRITE(YD); SWRITE(" restp,  "); RNDWR(RNRED(YD,XD),3);
         SWRITE(" quot."); END; 
      BLINES(1);
      PP:=DIIFMI(PP); 
(*9*) RETURN(PP); END DIIFGB; 


PROCEDURE DIIFLS(P: LIST): LIST; 
(*Distributive integral function polynomial list irreducible set.
P is a list of distributive integral function polynomials,
PP is the result of reducing each p element of P modulo P-(p)
until no further reductions are possible. *)
VAR   CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL: LIST; 
BEGIN
(*1*) (*initialise. *) RP:=CINV(P); PP:=INV(RP); LL:=LENGTH(P); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END; 
      BLINES(1); SWRITE("***nf irr= "); 
(*2*) (*reduce until all polynomials are irreducible. *) 
      REPEAT ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIIFNF(PP,0,PL); 
             OWRITE(IRR); SWRITE(" "); 
             IF PL = 0 THEN LL:=LL-1; 
                IF LL <= 1 THEN RETURN(PP); END; 
                ELSE FL:=DIPEVL(PL); SL:=EQUAL(EL,FL); 
                IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; END; 
                PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
             UNTIL IRR = LL; 
(*3*) (*finish. *) BLINES(1); AWRITE(LL); 
      SWRITE(" irreducible polynomials"); BLINES(1); 
(*6*) RETURN(PP); END DIIFLS; 


PROCEDURE DIIFMI(P: LIST): LIST; 
(*Distributive minimal ordered groebner basis. P is a list of
non zero integral function polynomials in distributive representation
in r variables. PP is the minimal normed and ordered
groebner basis. *)
VAR   AL, EI, EJ, EL, PB, PI, PIP, PJ, PL, PP, PS, QP, TL: LIST; 
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
                PI:=DIIFNF(QP,PL,PIP); END; 
             PP:=COMP(PI,PP); 
             UNTIL PS = SIL; 
      PP:=INV(PP); 
(*4*) (*sort. *) PP:=DIPLPM(PP); 
(*7*) RETURN(PP); END DIIFMI; 


PROCEDURE DIIFNF(P,RPP,S: LIST): LIST; 
(*Distributive integral function polynomial normal form.
P is a list of non zero polynomials in distributive
integral function representation in r variables.
S is a distributive integral function polynomial.
R is a polynomial such that S is reducible to R
modulo P and R is in normalform with respect to P. *)
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
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); ADGCDC(TA,QA,
                   CL,AL,BL); AP:=DIPFMO(AL,FL); APP:=DIPROD(QP,AP); 
                   SP:=DIPBCP(SP,BL); R:=DIPBCP(R,BL); 
                   SP:=DIPDIF(SP,APP); END; 
                END; 
             UNTIL SP = 0; 
(*3*) (*finish.*) RETURN(R); 
(*6*) END DIIFNF; 


PROCEDURE DIIFSP(A,B: LIST): LIST; 
(*Distributive integral function polynom S-polynomial.
A and B are integral function polynomials in distributive
representation. C is the S polynomial of A and B. *)
VAR   AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL: LIST; 
BEGIN
(*1*) (*a=0 or b=0. *) C:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      DIPMAD(A, AL,EL,AP); DIPMAD(B, BL,FL,BP); 
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(C); END; 
(*2*) (*reduction. *) GL:=EVLCM(EL,FL); ADGCDC(AL,BL, CL,AL,BL); 
      IF AP = SIL THEN FL1:=EVDIF(GL,FL); AL:=ADNEG(AL); 
         BPP:=DIPFMO(AL,FL1); C:=DIPROD(BP,BPP); RETURN(C); END; 
      IF BP = SIL THEN EL1:=EVDIF(GL,EL); APP:=DIPFMO(BL,EL1); 
         C:=DIPROD(AP,APP); RETURN(C); END; 
(*3*) (*general case. *) EL1:=EVDIF(GL,EL); FL1:=EVDIF(GL,FL); 
      APP:=DIPFMO(BL,EL1); BPP:=DIPFMO(AL,FL1); APP:=DIPROD(AP,APP); 
      BPP:=DIPROD(BP,BPP); C:=DIPDIF(APP,BPP); 
(*6*) RETURN(C); END DIIFSP; 


END DIPGB.

(* -EOF- *)
