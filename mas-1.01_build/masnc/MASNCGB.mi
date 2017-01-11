(* ----------------------------------------------------------------------------
 * $Id: MASNCGB.mi,v 1.3 1992/10/15 16:29:48 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNCGB.mi,v $
 * Revision 1.3  1992/10/15  16:29:48  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:33  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:25  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASNCGB;

(* MAS Non-commutative Groebner Bases Implementation Module. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, TIME,
                    SRED, SFIRST, FIRST, RED, COMP, INV, ADV, LIST1;

FROM MASERR IMPORT harmless, ERROR;

FROM SACLIST IMPORT AWRITE, ADV3, COMP3, LIST2, COMP2, ADV2, FIRST3, 
                    OWRITE, LAST, CONC, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACRN IMPORT RNINT, RNPROD, RNQ;

FROM DIPC IMPORT DIPMPV, DIPINV, DIPMAD, DIPNOV, DIPFMO, DIPEVL,
                 DIPLPM, DIPLBC, DIPMCP, 
                 VALIS, EVLCM, EVSIGN, EPREAD,
                 EVMT, EVDIF, EVDOV, EVSUM, (*EVZERO,*) EVCADD, EVSU; 

FROM DIPRN IMPORT DIRLWR, DIRPMC, DIRPON, DIRPDF, 
                  DIRPNG, DIRPPR, DIRPRP, DIRPSM, DIRPWR; 

FROM DIPRNGB IMPORT DIGBC3, DILUPL, DILCPL; 

FROM MASNC IMPORT EVZERO, DINPPR;

CONST rcsidi = "$Id: MASNCGB.mi,v 1.3 1992/10/15 16:29:48 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINLNF(T,P,S: LIST): LIST; 
(*Distributive non-commutative polynomial left normal form.
P is a list of non zero polynomials in distributive rational
representation in r variables. S is a distributive rational
polynomial. R is a polynomial such that S is left reducible to R
modulo P and R is in normalform with respect to P.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  AP, APP, BL, FL, OL, PP, Q, QA, QE, QP, R, SL, SP, SPP, TA, TE:
     LIST; 
BEGIN
(*1*) (*s=0. *) 
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN(R); END; 
(*2*) (*reduction step.*) R:=BETA; SP:=S; OL:=RNINT(1); 
      REPEAT DIPMAD(SP, TA,TE,SPP); PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMT(TE,QE); 
                    UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); 
                IF SPP = SIL THEN SP:=0; ELSE SP:=SPP; END; 
                ELSE FL:=EVDIF(TE,QE); AP:=DIPFMO(OL,FL); 
                APP:=DINPPR(T,AP,Q); BL:=DIPLBC(APP); BL:=RNQ(TA,BL); 
                APP:=DIRPRP(APP,BL); SP:=DIRPDF(SP,APP); END; 
             UNTIL SP = 0; 
(*3*) (*finish.*) 
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END; 
(*6*) RETURN(R); END DINLNF; 


PROCEDURE DINLIS(T,P: LIST): LIST; 
(*Distributive non-commutative polynomial list left irreducible set.
P is a list of distributive rational polynomials, PP is the
result of left reducing each p element of P modulo P-(p)
until no further reductions are possible.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
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
      LOOP ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DINLNF(T,PP,PL); 
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
(*6*) RETURN(PP); END DINLIS; 


PROCEDURE DINLSP(T,A,B: LIST): LIST; 
(*Distributive non-commutative polynomial left S-polynomial.
A and B are rational polynomials in distributive representation.
C is the left S-polynomial of A and B.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  AL, AP, APP, BL, BP, BPP, C, EL, EL1, FL, FL1, GL, OL: LIST; 
BEGIN
(*1*) (*a=0 or b=0. *) C:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(C); END; 
      EL:=DIPEVL(A); FL:=DIPEVL(B); OL:=RNINT(1); 
(*2*) (*least common multiple. *) GL:=EVLCM(EL,FL); EL1:=EVDIF(GL,EL); 
      FL1:=EVDIF(GL,FL); 
(*3*) (*non-commutative products. *) APP:=DIPFMO(OL,EL1); 
      BPP:=DIPFMO(OL,FL1); APP:=DINPPR(T,APP,A); BPP:=DINPPR(T,BPP,B); 
(*4*) (*adjust coefficients. *) AL:=DIPLBC(APP); BL:=DIPLBC(BPP); 
      APP:=DIRPRP(APP,BL); BPP:=DIRPRP(BPP,AL); 
(*5*) (*difference. *) C:=DIRPDF(APP,BPP); 
(*8*) RETURN(C); END DINLSP; 


PROCEDURE DINLGB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials left Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the left Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  B, C, CPI, CPJ, CPP, D, DL, EL, ELI, ELJ, H, IL,
     J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S,
     SL, SL3, TL, TR, X3, X4, XC, XD, XH, XS, XT, YD, ZD:
     LIST; 
BEGIN
(*1*) (*prepare input. *) TL:=TIME(); XH:=0; 
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP); 
               IF SL = 1 THEN PP:=LIST1(PLIP); RETURN(PP); END; 
               PPR:=COMP(PLIP,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF (PP = SIL) OR (RED(PP) = SIL) THEN RETURN(PP); END; 
(*2*) (*get irreducible base. construct b and d. *) 
      IF TF < 0 THEN TF:=-TF; TR:=TIME(); PP:=DINLIS(T,PP); 
         SWRITE("***IRR TIME="); AWRITE(TIME()-TR); BLINES(0); END; 
      PPR:=DIPLPM(PP); PP:=INV(PPR); DILCPL(PP, D,B); 
(*3*) (*loop until no more pairs left. *) 
LOOP
      IF D = SIL THEN EXIT END; 
      ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
      IF TF >= 3 THEN SWRITE("EL="); OWRITE(EL); BLINES(0); END; 
LOOP
(*4*) (*compute criterion 3. *) SL3:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL3 = 0 THEN (* SWRITE("** CRITERION 3 **"); BLINES(0); *)
         EXIT END;
(*5*) (*s-pol and reduction step. *) S:=DINLSP(T,PLI,PLJ); 
      IF S = 0 THEN EXIT END; 
      XH:=XH+1; 
      IF TF >= 2 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         SWRITE("S="); DIRPWR(S,VALIS,-1); BLINES(1); END; 
      H:=DINLNF(T,PP,S); 
      IF H = 0 THEN EXIT END; 
      H:=DIRPMC(H); SL:=DIRPON(H); 
      IF SL = 1 THEN PP:=LIST1(H); RETURN(PP); END; 
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); AWRITE(LENGTH(D)); 
         SWRITE(" PAIRS LEFT."); BLINES(0); SWRITE("H="); 
         DIRPWR(H,VALIS,-1); BLINES(1); END; 
      D:=DILUPL(H,PP,D,B); 
EXIT END;
END; 
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS."); BLINES(0); END; 
      PP:=DINLGM(T,PP); 
(*9*) RETURN(PP); END DINLGB; 


PROCEDURE DINLGM(T,P: LIST): LIST; 
(*Distributive non-commutative minimal ordered left Groebner base.
P is a list of non zero rational polynomials in distributive
representation in r variables, P is a left Groebner base.
PP is the minimal normed and ordered left Groebner base.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  AL, EI, EJ, EL, PB, PI, PJ, PP, PS, QP, TL: LIST; 
BEGIN
(*1*) (*length p le 1. *) PP:=P; 
      IF (P = SIL) OR (RED(P) = SIL) THEN RETURN(PP); END; 
      SWRITE("LEN="); OWRITE(LENGTH(PP)); BLINES(0); 
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
(*3*) (*get irreducible set. *) PP:=DINLIS(T,PP); 
(*4*) (*sort. *) PP:=DIPLPM(PP); 
(*7*) RETURN(PP); END DINLGM; 


PROCEDURE DIN1GB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  EL, F, G, IL, J1Y, N, O, PL, PP, QL, RL, TL, V, X, XL, XP,
     XS: LIST; 
BEGIN
(*1*) (*initialization. *) PP:=P; 
      IF P = SIL THEN RETURN(PP); END; 
      J1Y:=FIRST(P); RL:=DIPNOV(J1Y); 
      IF RL = 0 THEN RETURN(PP); END; 
      N:=EVZERO(RL); O:=RNINT(1); X:=BETA; 
      FOR IL:=1 TO RL DO EVSU(N,IL,1, EL,XL); XP:=DIPFMO(O,EL); 
          X:=COMP(XP,X); END; 
      V:=VALIS; 
(*2*) (*compute left Groebner bases. *) 
      REPEAT G:=DINLGB(T,PP,TF); SWRITE("Left Groebner base "); 
             DIRLWR(G,V,-1); BLINES(1); PP:=G; F:=G; 
             REPEAT ADV(F, PL,F); XS:=X; 
                    REPEAT ADV(XS, XP,XS); QL:=DINPPR(T,PL,XP); 
                           QL:=DINLNF(T,PP,QL); 
                           IF QL <> 0 THEN SWRITE("QL="); 
                              DIRPWR(QL,V,-1); BLINES(1); 
                              PP:=COMP(QL,PP); END; 
                           UNTIL XS = SIL; 
                    UNTIL F = SIL; 
             UNTIL G = PP; 
(*3*) (*finish. *) RETURN(PP); 
(*6*) END DIN1GB; 


PROCEDURE DINCGB(T,P,TF: LIST): LIST; 
(*Distributive non-commutative polynomials Groebner base.
P is a list of rational polynomials in distributive representation
in r variables. PP is the Groebner base of P. t is the
trace flag.
T is a table of distributive polynomials specifying the
non-commutative relations. *)
VAR  B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, F, H, 
     IL, J1Y, K, N, O, PL, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q,
     QL, QP, RL, S, SL, TL, TR, V, X, X3, X4, XC, XD, XH, XL,
     XP, XS, XT, YD, ZD: LIST; 
BEGIN
(*1*) (*prepare input. *) TL:=TIME(); XH:=0; 
      IF P = SIL THEN PP:=P; RETURN(PP); END; 
      PS:=P; PPR:=BETA; 
      WHILE PS <> SIL DO ADV(PS, PLI,PS); 
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP); 
               IF SL = 1 THEN PP:=LIST1(PLIP); RETURN(PP); END; 
               PPR:=COMP(PLIP,PPR); END; 
            END; 
      PP:=INV(PPR); 
      IF PP = SIL THEN RETURN(PP); END; 
      J1Y:=FIRST(PP); RL:=DIPNOV(J1Y); 
      IF RL = 0 THEN RETURN(PP); END; 
      N:=EVZERO(RL); O:=RNINT(1); X:=BETA; 
      FOR IL:=1 TO RL DO EVSU(N,IL,1, EL,XL); XP:=DIPFMO(O,EL); 
          X:=COMP(XP,X); END; 
      V:=VALIS; 
(*2*) (*add right multiples of polynomials and single variables. *) 
      F:=PP; 
      REPEAT ADV(F, PL,F); XS:=X; 
             REPEAT ADV(XS, XP,XS); QL:=DINPPR(T,PL,XP); 
                    QL:=DINLNF(T,PP,QL); QL:=DIRPMC(QL); SL:=DIRPON(QL); 
                    IF SL = 1 THEN PP:=LIST1(QL); RETURN(PP); END; 
                    IF QL <> 0 THEN SWRITE("QL="); DIRPWR(QL,V,-1); 
                       BLINES(1); PP:=COMP(QL,PP); END; 
                    UNTIL XS = SIL; 
             UNTIL F = SIL; 
      IF TF < 0 THEN TF:=-TF; TR:=TIME(); PP:=DINLIS(T,PP); 
         SWRITE("***IRR TIME="); AWRITE(TIME()-TR); BLINES(0); END; 
      PPR:=DIPLPM(PP); PP:=INV(PPR); DILCPL(PP, D,B); 
(*3*) (*loop until no more pairs left. *) 
LOOP
      IF D = SIL THEN EXIT END; 
      ADV(D, DL,D); FIRST3(DL, EL,CPI,CPJ); ADV(CPI, QP,C); 
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ); 
      CPP:=RED(J1Y); SRED(CPJ,CPP); 
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END; 
      IF TF >= 3 THEN SWRITE("EL="); OWRITE(EL); BLINES(0); END; 
LOOP
(*4*) (*compute criterion 3. *) SL:=DIGBC3(B,PLI,PLJ,EL); 
      IF SL = 0 THEN (* SWRITE("** CRITERION 3 **"); BLINES(0); *) 
         EXIT END; 
(*5*) (*reduction step. *) S:=DINLSP(T,PLI,PLJ); 
      IF S = 0 THEN EXIT END; 
      XH:=XH+1; 
      IF TF >= 2 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         BLINES(0); SWRITE("S="); DIRPWR(S,V,-1); BLINES(1); END; 
      H:=DINLNF(T,PP,S); 
      IF H = 0 THEN EXIT END; 
      H:=DIRPMC(H); SL:=DIRPON(H); 
      IF SL = 1 THEN PP:=LIST1(H); RETURN(PP); END; 
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); AWRITE(LENGTH(D)); 
         SWRITE(" PAIRS LEFT."); BLINES(0); SWRITE("H="); 
         DIRPWR(H,V,-1); BLINES(1); END; 
      D:=DILUPL(H,PP,D,B); XS:=X; 
      REPEAT ADV(XS, XP,XS); QL:=DINPPR(T,H,XP); QL:=DINLNF(T,PP,QL); 
             QL:=DIRPMC(QL); SL:=DIRPON(QL); 
             IF SL = 1 THEN PP:=LIST1(QL); RETURN(PP); END; 
             IF QL <> 0 THEN SWRITE("QL="); DIRPWR(QL,V,-1); 
                BLINES(1); D:=DILUPL(QL,PP,D,B); END; 
             UNTIL XS = SIL;
EXIT END; 
END;
(*6*) (*finish. *) 
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, "); 
         AWRITE(XH); SWRITE(" H-POLYNOMIALS."); BLINES(0); END; 
      PP:=DINLGM(T,PP); 
(*9*) RETURN(PP); END DINCGB; 


END MASNCGB.


(* -EOF- *)
