(* ----------------------------------------------------------------------------
 * $Id: DIPI.mi,v 1.5 1995/11/05 09:17:21 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPI.mi,v $
 * Revision 1.5  1995/11/05 09:17:21  kredel
 * Improved polynomial parsing.
 *
 * Revision 1.4  1993/03/23  12:58:56  kredel
 * Added DIILFRCD
 *
 * Revision 1.3  1992/10/15  16:28:34  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:49  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:01  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPI;

(* DIP Integral Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMIN, MASMAX;


FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, SRED, SFIRST,
                    FIRST, RED, COMP, INV, ADV, LIST1;


FROM MASERR IMPORT severe, ERROR;


FROM SACLIST IMPORT LIST2, COMP2, ADV2, FIRST2, 
                    LIST3, AWRITE, CLOUT, CINV, RED2, SECOND, EQUAL;


FROM MASBIOS IMPORT CREAD, CREADB, CWRITE, 
                    SOLINE, LETTER, DIGIT, DIBUFF, 
                    MASORD, BKSP, BLINES, SWRITE;


FROM SACD IMPORT DPR, DQR, DRANN;


FROM SACI IMPORT IDPR, IWRITE, IREAD, IRAND, IMAX, IABSF, 
                 IEXP, IDIF, IGCD, ISIGNF, ILCM, 
                 ISUM, INEG, IQ, IQR;


FROM SACRN IMPORT RNDEN, RNNUM, RNSIGN;


FROM SACPOL IMPORT VREAD, VLSRCH;


FROM DIPC IMPORT DIPNBC, DIPADS, DIPMPM, DIPTCS, DIPMPV, 
                    DIPMRD, DIPCMP, DIPDEG, DIPINV, DIPFMO, 
                    DIPADV, DIPADM, DIPLBC, DIPMCP, DIPMAD, 
                    DIPTCF, DIPEVL, DIPNOV,
                    STVL, BACKUB, 
                    EVRASP, EPREAD, EVRAND, EVDFSI, EVDER, 
                    EVSUM, EVSIGN, EVCOMP;

FROM MASI IMPORT IPROD;
 
CONST rcsidi = "$Id: DIPI.mi,v 1.5 1995/11/05 09:17:21 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIIFRP(A: LIST): LIST; 
(*Distributive integral polynomial from rational polynomial.
A is a distributive rational polynomial, B is the primitive
positive associate integral polynomial of A. *)
VAR  AL, AL1, ALP, AP, B, BL, CL, EL, SL: LIST; 
BEGIN
(*1*) (*a=0. *) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*lcm of denominators of base coefficients. *) DIPMAD(A,
      AL1,EL,AP); SL:=RNSIGN(AL1); BL:=RNDEN(AL1); 
      WHILE AP <> SIL DO DIPMAD(AP, AL1,EL,AP); AL:=RNDEN(AL1); 
            BL:=ILCM(BL,AL); END; 
(*3*) (*multiply with lcm and remove denominators. *) 
      IF SL < 0 THEN BL:=INEG(BL); END; 
      B:=BETA; AP:=A; 
      WHILE AP <> SIL DO DIPMAD(AP, AL1,EL,AP); FIRST2(AL1, CL,AL); 
            ALP:=IQ(BL,AL); CL:=IPROD(CL,ALP); B:=DIPMCP(EL,CL,B); END; 
      B:=INV(B); DIIPCP(B, CL,B); 
(*6*) RETURN(B); END DIIFRP; 


PROCEDURE DIILFR(A: LIST): LIST; 
(*Distributive integral polynomial list from rational polynomial list.
A is a list of distributive rational polynomial, B is a list of primitive
positive associate integral polynomials of the polynomials of A. *)
VAR  AP, AL, B, BL: LIST; 
BEGIN
(*1*) (*convert polynomials. *) AP:=A; B:=SIL; 
      WHILE AP <> SIL DO ADV(AP, AL,AP); BL:=DIIFRP(AL);  
            B:=COMP(BL,B) END;
      B:=INV(B); 
(*5*) RETURN(B); END DIILFR; 


PROCEDURE DIILFRCD(A: LIST): LIST; 
(*DIP integral list from DIP rational list using common denominator.
A is a list of distributive rational polynomial, B is a list of 
associate integral polynomials of the polynomials of A. 
All polynomials in B are multiplied by a least common multiple 
of all denominators of all polynomials in A. *)
VAR   AL, AL1, ALP, AP, B, BP, BL, CL, EL, SL, C, CP: LIST; 
BEGIN
(*1*) (*lcm of denominators of base coefficients of all polynomials. *) 
      C:=A; CP:=C; BL:=1; 
      WHILE CP <> SIL DO ADV(CP, AP,CP); 
            IF AP = 0 THEN AP:=SIL END;
            WHILE AP <> SIL DO DIPMAD(AP, AL1,EL,AP); AL:=RNDEN(AL1); 
                  BL:=ILCM(BL,AL); END; 
            END; 
(*2*) (*multiply with lcm and remove denominators. *) 
      CP:=C; BP:=SIL; 
      WHILE CP <> SIL DO ADV(CP, AP,CP); 
            IF AP = 0 THEN AP:=SIL END; B:=SIL;  
            WHILE AP <> SIL DO DIPMAD(AP, AL1,EL,AP); FIRST2(AL1, CL,AL); 
                  ALP:=IQ(BL,AL); CL:=IPROD(CL,ALP); 
                  B:=DIPMCP(EL,CL,B); END; 
            B:=INV(B); IF B = SIL THEN B:=0 END; 
            BP:=COMP(B,BP); END; 
      BP:=INV(BP); RETURN(BP); 
(*6*) END DIILFRCD; 


PROCEDURE DIILRD(V: LIST): LIST; 
(*Distributive integral polynomial list read. V is a
variable list. A list of distributive integral polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. any blanks preceding A are skipped. *)
VAR  A, AL, C: LIST; 
BEGIN
(*1*) (*no list. *) A:=BETA; C:=CREADB(); 
      IF C <> MASORD("(") THEN ERROR(severe,"DIILRD ( expected."); 
         RETURN(A); END; 
(*2*) (*read polynomials. *) 
      REPEAT C:=CREADB(); 
             IF C = MASORD(",") THEN C:=CREADB(); END; 
             IF C <> MASORD(")") THEN BKSP; AL:=DIIPRD(V); A:=COMP(AL,A); 
                END; 
             UNTIL C = MASORD(")"); 
      A:=INV(A); 
(*5*) RETURN(A); END DIILRD; 


PROCEDURE DIILWR(A,V: LIST); 
(*Distributive integral polynomial list write. V is a
variable list. A list of distributive integral polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)
VAR  AL, AP, OS, LS, RS: LIST; 
BEGIN
(*1*) (*format. *) BLINES(0); OS:=-1; LS:=10; RS:=60; SOLINE(OS,LS,RS);  
(*2*) (*write polynomials. *) AP:=A; 
      WHILE AP <> SIL DO ADV(AP, AL,AP); DIIPWR(AL,V); BLINES(0); 
            END; 
      SOLINE(OS,LS,RS);
(*5*) RETURN; END DIILWR; 


PROCEDURE DIIPAB(A: LIST): LIST; 
(*Distributive integral polynomial absolute value. A is a
distributive integral polynomial. B is the absolute value of A.*)
VAR  B, SL: LIST; 
BEGIN
(*1*) (* b=a*(sign of a). *) SL:=DIIPSG(A); 
      IF SL >= 0 THEN B:=A; ELSE B:=DIIPNG(A); END; 
      RETURN(B); 
(*4*) END DIIPAB; 


PROCEDURE DIIPCP(A: LIST;  VAR CL,AP: LIST); 
(*Distributive integral polynomial content and primitive part.
A is an distributive integral polynomial, c is the integer
content and AP is the positive primitive part of A. *)
VAR  AL, DL, EL, SL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN CL:=0; AP:=A; RETURN; END; 
(*2*) (*obtain gcd.*) DIPMAD(A, DL,EL,AP); SL:=ISIGNF(DL); 
      IF SL < 0 THEN DL:=INEG(DL); END; 
      WHILE (AP <> SIL) AND (DL <> 1) DO DIPMAD(AP, AL,EL,AP); 
            DL:=IGCD(DL,AL); END; 
(*3*) (*divide. *) CL:=DL; AP:=A; 
      IF DL = 1 THEN
         IF SL < 0 THEN CL:=-DL; AP:=DIIPNG(A); END; 
         ELSE
         IF SL < 0 THEN CL:=INEG(DL); END; 
         AP:=DIIPIQ(A,CL); END; 
(*6*) RETURN; END DIIPCP; 


PROCEDURE DIIPDF(A,B: LIST): LIST; 
(*Distributive integral polynomial difference. A and B are
distributive integral polynomials. C=A-B.*)
VAR  AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=DIIPNG(B); RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); SL:=EVCOMP(EL,FL); 
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); CL:=INEG(BL); 
                   CP:=DIPMCP(FL,CL,CP); ELSE DIPMAD(AP, AL,EL,AP); 
                   DIPMAD(BP, BL,FL,BP); CL:=IDIF(AL,BL); 
                   IF CL <> 0 THEN CP:=DIPMCP(EL,CL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) APP:=AP; 
      IF AP = SIL THEN
         IF BP <> SIL THEN APP:=DIIPNG(BP); END; 
         END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*6*) END DIIPDF; 


PROCEDURE DIIPDM(A: LIST): LIST; 
(*Distributive integral polynomial derivation main variable.
A is a distributive polynomial. B is the derivation of A
with respect to its main variable.*)
VAR  AL, ALP, AS, B, EL, EL1, EL2, ELS, FL: LIST; 
BEGIN
(*1*) (*a eq 0 or integer.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      IF DIPEVL(A) = SIL THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); ADV(EL, EL1,ELS); 
             IF EL1 > 0 THEN ALP:=IPROD(AL,EL1); EL2:=EL1-1; 
                FL:=COMP(EL2,ELS); B:=DIPMCP(FL,ALP,B); END; 
             UNTIL (AS = SIL) OR (EL1 = 0); 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIIPDM; 


PROCEDURE DIIPDR(A,IL: LIST): LIST; 
(*Distributive integral polynomial derivation. A is a distributive
polynomial. B is the derivation of A with respect to its i-th
variable, 0 le i le DIPNOV(A).*)
VAR  AL, ALP, AS, B, EL, ELP, FL, J1Y, JL, KL, RL: LIST; 
BEGIN
(*1*) (*a=0 or il=rl.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      RL:=DIPNOV(A); KL:=1; J1Y:=RL-IL; JL:=J1Y+1; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); EVDER(EL,JL,KL, ELP,FL); 
             IF FL <> 0 THEN ALP:=IPROD(AL,FL); 
                B:=DIPMCP(ELP,ALP,B); END; 
             UNTIL AS = SIL; 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIIPDR; 


PROCEDURE DIIPEM(A,AL: LIST): LIST; 
(*Distributive integral polynomial evaluation of main variable.
A is a distributive integral polynomial. a is an integer.
B(x1, ...,x(r-1))=A(x1, ...,x(r-1),a). *)
VAR   B, EL1, EL2, C, AP, J1Y, ALP: LIST;
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*apply horner s method.*) DIPADM(A, EL1,EL2,B,AP); 
      WHILE AP <> 0 DO J1Y:=EL1-EL2; ALP:=IEXP(AL,J1Y); 
            B:=DIIPIP(B,ALP); DIPADM(AP, EL1,EL2,C,AP); B:=DIIPSM(B,C); 
            END; 
      ALP:=IEXP(AL,EL1); B:=DIIPIP(B,ALP); RETURN(B); 
(*5*) END DIIPEM; 


PROCEDURE DIIPEV(A,IL,AL: LIST): LIST; 
(*Distributive integral polynomial evaluation of the i-th variable.
A is a distributive integral polynomial, 1 le i le DIPNOV(A),
a is an integer. B(x1, ...,x(i-1),x(i+1), ...,xr)=
A(x1, ...,x(i-1),a,x(i+1), ...,xr). *)
VAR  ALP, AP, B, BS, C, D, EL1, EL2, J1Y, RL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*apply horner s method.*) B:=LIST1(0); BS:=B; B:=0; AP:=A; 
      REPEAT DIPADV(AP,IL, EL1,EL2,D,AP); 
             WHILE (AP <> 0) AND (EL1 > EL2) DO J1Y:=EL1-EL2; 
                   ALP:=IEXP(AL,J1Y); D:=DIIPIP(D,ALP); DIPADV(AP,IL,
                   EL1,EL2,C,AP); D:=DIIPSM(D,C); END; 
             ALP:=IEXP(AL,EL1); D:=DIIPIP(D,ALP); B:=COMP(D,B); 
             UNTIL AP = 0; 
      ADV(B, D,B); SFIRST(BS,D); SRED(BS,B); B:=DIIPLS(B); 
(*5*) RETURN(B); END DIIPEV; 


PROCEDURE DIIPEX(A,NL: LIST): LIST; 
(*Distributive integral polynomial exponentiation. A is a
distributive integral polynomial, n is a non-negative beta-
integer. B=A**n. 0**0 is by definition a polynomial in
zero variables. *)
VAR  B, BL, I, RL: LIST; 
BEGIN
(*1*) (*nl=0.*) 
      IF NL = 0 THEN RL:=DIPNOV(A); BL:=DIPFMO(1,BETA); 
         B:=DIPINV(BL,0,RL); RETURN(B); END; 
(*2*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*3*) (*general case.*) B:=A; 
      FOR I:=1 TO NL-1 DO B:=DIIPPR(B,A); END; 
      RETURN(B); 
(*6*) END DIIPEX; 


PROCEDURE DIIPHD(A,IL,NL: LIST): LIST; 
(*Distributive integral polynomial higher derivation. A is a
distributive integral polynomial. B is the n-th derivation
of A with respect to its i-th variable, 0 le i le DIPNOV(A). *)
VAR  AL, ALP, AS, B, EL, ELP, FL, J1Y, JL, RL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      RL:=DIPNOV(A); J1Y:=RL-IL; JL:=J1Y+1; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); EVDER(EL,JL,NL, ELP,FL); 
             IF FL <> 0 THEN ALP:=IPROD(AL,FL); 
                B:=DIPMCP(ELP,ALP,B); END; 
             UNTIL AS = SIL; 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIIPHD; 


PROCEDURE DIIPIP(A,BL: LIST): LIST; 
(*Distributive integral polynomial integer product. A is a
distributive integral polynomial, b is an integer. C=A*b.*)
VAR  AL, AP, C, EL, PL: LIST; 
BEGIN
(*1*) (*a=0 or bl=0.*) 
      IF (A = 0) OR (BL = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*multiply.*) C:=BETA; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); PL:=IPROD(AL,BL); C:=DIPMCP(EL,PL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END DIIPIP; 


PROCEDURE DIIPIQ(A,BL: LIST): LIST; 
(*Distributive integral polynomial integer quotient. A is a
distributive integral polynomial, b is a nonzero integer,
and b divides any coefficient of A. C=A/b.*)
VAR  AL, AP, C, EL, QL, RL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
(*2*) (*divide.*) C:=BETA; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); IQR(AL,BL, QL,RL); 
             C:=DIPMCP(EL,QL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END DIIPIQ; 


PROCEDURE DIIPLS(A: LIST): LIST; 
(*Distributive integral polynomial list sum. A is a circular
list of distributive integral polynomials. B is the sum of all
polynomials in A. *)
VAR  B, BP, BPP, C, CP, CPP: LIST; 
BEGIN
(*1*) (*nothing to do. *) 
      IF A = SIL THEN B:=0; RETURN(B); END; 
(*2*) (*merge. *) C:=A; ADV(C, B,CP); 
      WHILE C <> CP DO ADV(CP, BP,CPP); BPP:=DIIPSM(B,BP); 
            SFIRST(C,BPP); SRED(C,CPP); C:=CPP; ADV(C, B,CP); END; 
(*5*) RETURN(B); END DIIPLS; 


PROCEDURE DIIPMN(A: LIST): LIST; 
(*Distributive integral polynomial maximum norm. A is a
distributive integral polynomial. b is the maximum norm of A.*)
VAR  AL, AS, BL, CL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) BL:=0; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*find maximum.*) AS:=A; 
      REPEAT DIPMAD(AS, AL,EL,AS); CL:=IABSF(AL); BL:=IMAX(CL,BL); 
             UNTIL AS = SIL; 
      RETURN(BL); 
(*5*) END DIIPMN; 


PROCEDURE DIIPNG(A: LIST): LIST; 
(*Distributive integral polynomial negative. B= -A.*)
VAR  AL, AS, B, BL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); BL:=INEG(AL); B:=DIPMCP(EL,BL,B); 
             UNTIL AS = SIL; 
      B:=INV(B); RETURN(B); 
(*5*) END DIIPNG; 


PROCEDURE DIIPON(A: LIST): LIST; 
(*Distributive integral polynomial one. A is a distributive
integral polynomial. If A=1 then t=1, otherwise t=0.*)
VAR  AL, AS, EL, FL, TL: LIST; 
BEGIN
(*1*) (*a eq 0.*) TL:=0; 
      IF A = 0 THEN RETURN(TL); END; 
(*2*) (*a=integer.*) DIPMAD(A, AL,EL,AS); 
      IF (AL <> 1) OR (AS <> SIL) THEN RETURN(TL); END; 
      FL:=EVSIGN(EL); 
      IF FL = 0 THEN TL:=1; END; 
      RETURN(TL); 
(*5*) END DIIPON; 


PROCEDURE DIIPPR(A,B: LIST): LIST; 
(*Distributive integral polynomial product. A and B are
distributive integral polynomials. C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*general case.*) AS:=CINV(A); BS:=B; C:=LIST1(0); CS:=C; 
      REPEAT DIPMAD(BS, BL,FL,BS); AP:=AS; C1:=BETA; 
             REPEAT DIPMAD(AP, EL,AL,AP); CL:=IPROD(AL,BL); 
                    GL:=EVSUM(EL,FL); C1:=DIPMCP(CL,GL,C1); 
                    UNTIL AP = SIL; 
             C:=COMP(C1,C); 
             UNTIL BS = SIL; 
      ADV(C, C1,C); SFIRST(CS,C1); SRED(CS,C); C:=DIIPLS(C); 
(*5*) RETURN(C); END DIIPPR; 


PROCEDURE DIIPPS(A,B: LIST): LIST; 
(*Distributive integral polynomial pseudo-remainder. A and B are
distributive integral polynomials, B ne 0. C is the
pseudo-remainder of A and B. *)
VAR  B1, BP, BS, C, C1, CL, FL, IL, J1Y, LL, LLP, ML, NL: LIST; 
BEGIN
(*1*) (*deg(b)=0.*) NL:=DIPDEG(B); 
      IF NL = 0 THEN C:=0; RETURN(C); END; 
(*2*) (*deg(b) gt 0.*) ML:=DIPDEG(A); C:=A; DIPADM(B, NL,FL,BS,BP); 
      B1:=DIPCMP(0,BS); 
      FOR IL:=ML TO NL BY -1 DO
          IF C = 0 THEN RETURN(C); END; 
          LL:=DIPDEG(C); 
          IF LL = IL THEN DIPADM(C, LLP,FL,CL,C); C:=DIIPPR(C,B1); 
             J1Y:=LL-NL; C1:=DIPCMP(J1Y,CL); BS:=DIIPPR(BP,C1); 
             C:=DIIPDF(C,BS); ELSE C:=DIIPPR(C,B1); END; 
          END; 
      RETURN(C); 
(*5*) END DIIPPS; 


PROCEDURE DIIPQ(A,B: LIST): LIST; 
(*Distributive integral polynomial quotient. A and B are
distributive integral polynomials. B is a non zero divisor
of A. C=B/A.*)
VAR  C, R: LIST; 
BEGIN
(*1*) (*call diipqr.*) DIIPQR(A,B, C,R); RETURN(C); 
(*4*) END DIIPQ; 


PROCEDURE DIIPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive integral polynomial quotient and remainder.
A and B are distributive integral polynomials with B ne 0.
Q and R are unique distributive integral polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with DEG(R) minimal.*)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RP, SL, TL: LIST; 
BEGIN
(*1*) (*initialise.*) DIPMAD(B, BL,NL,BP); 
      IF BP = SIL THEN BP:=0; END; 
      Q:=BETA; R:=A; 
(*2*) (*compute quotient terms.*) 
      LOOP IF R = 0 THEN EXIT END; 
           ML:=DIPEVL(R); EVDFSI(ML,NL, DL,TL); 
           IF TL < 0 THEN EXIT END; 
           AL:=DIPLBC(R); IQR(AL,BL, QL,SL); 
           IF SL <> 0 THEN EXIT END; 
           Q:=DIPMCP(DL,QL,Q); Q1:=DIPFMO(QL,DL); RP:=DIPMRD(R); 
           QP:=DIIPPR(BP,Q1); R:=DIIPDF(RP,QP); 
           END; 
(*3*) (*finish.*) 
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END; 
      RETURN; 
(*6*) END DIIPQR; 


PROCEDURE DIIPRA(RL,KL,LL,EL: LIST): LIST; 
(*Distributive integral polynomial random.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive integral polynomial in r variables
max norm of a lt 2**k and maximal l base coefficients. *)
VAR  A, AL, AP, FL, IL: LIST; 
BEGIN
(*1*) (*rl=0.*) A:=0; 
      IF RL = 0 THEN AL:=IRAND(KL); A:=DIPFMO(AL,BETA); RETURN(A); 
         END; 
(*2*) (*call evrand.*) 
      FOR IL:=1 TO LL DO AL:=IRAND(KL); 
          IF AL <> 0 THEN FL:=EVRAND(RL,EL); AP:=DIPFMO(AL,FL); 
             A:=DIIPSM(A,AP); END; 
          END; 
(*5*) RETURN(A); END DIIPRA; 


PROCEDURE DIIPRD(V: LIST): LIST; 
(*Distributive integral polynomial read. V is a variable list.
A distributive integral polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. Modified version, orginal
version by G. E. Collins. *)
VAR  A, A1, AL, AP, C, EL, ES, FL, IL, JL, RL, VL: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) A:=0; C:=CREADB(); 
      IF C = 0 THEN RETURN(A); END; 
      BKSP; 
(*2*) (*initialise.*) C:=CREADB(); BKSP; 
      IF C = MASORD(",") THEN ERROR(severe,"DIIPRD no , expected.");  
         RETURN(A); END; 
      FL:=0; 
      IF C = MASORD("(") THEN C:=CREADB(); FL:=1; END; 
      IF C = MASORD(")") THEN
         IF FL = 1 THEN RETURN(A); ELSE ERROR(severe,"DIIPRD no ) expected.");  
            RETURN(A); END; 
         END; 
      RL:=LENGTH(V); ES:=BETA; 
      FOR IL:=1 TO RL DO ES:=COMP(0,ES); END; 
      A1:=DIPFMO(1,ES); AP:=A1; 
LOOP
(*3*) (*next input. determine next action. *) C:=CREADB(); 
      IF C = MASORD(")") THEN
         IF FL = 0 THEN BKSP; END; 
         RETURN(A); END; 
      IF C = MASORD(",") THEN BKSP; RETURN(A); END; 
      IF C = MASORD("-") THEN AP:=DIIPNG(AP); END; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) THEN C:=CREADB(); END; 
      IF C = MASORD("*") THEN C:=CREADB(); END; 
      BKSP; 
(*4*) (*read coefficient.*) 
      IF DIGIT(C) THEN AL:=IREAD(); EL:=EPREAD(); 
         AL:=IEXP(AL,EL); AP:=DIIPIP(AP,AL);  
(*5*) (*read polynomial.*) 
   ELSIF C = MASORD("(") THEN AL:=DIIPRD(V); EL:=EPREAD(); 
         AL:=DIIPEX(AL,EL); AP:=DIIPPR(AP,AL);  
(*6*) (*read monic monomial.*) 
   ELSIF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); 
         IF JL = 0 THEN BACKUB; A:=DIIPSM(A,AP); RETURN(A); END; 
         EL:=EPREAD(); AP:=DIPMPV(AP,JL,EL); 
         END; 
(*8*) (*complete polynomial.*) C:=CREADB(); BKSP; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) OR (C = MASORD(")"))
      OR (C = MASORD(",")) THEN A:=DIIPSM(A,AP); AP:=A1; END; 
      END; 
(*9*) END DIIPRD; 


PROCEDURE DIIPSG(A: LIST): LIST; 
(*Distributive integral polynomial sign. A is a distributive
integral polynomial. s is the sign of the leading base
coefficient of A.*)
VAR  J1Y, SL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN SL:=0; ELSE J1Y:=DIPLBC(A); SL:=ISIGNF(J1Y); 
         END; 
      RETURN(SL); 
(*4*) END DIIPSG; 


PROCEDURE DIIPSM(A,B: LIST): LIST; 
(*Distributive integral polynomial sum. A and B are
distributive integral polynomials. C=A+B. *)
VAR  AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=B; RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); SL:=EVCOMP(EL,FL); 
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CP:=DIPMCP(FL,BL,CP); ELSE DIPMAD(AP, AL,EL,AP); 
                   DIPMAD(BP, BL,FL,BP); CL:=ISUM(AL,BL); 
                   IF CL <> 0 THEN CP:=DIPMCP(EL,CL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) 
      IF AP = SIL THEN APP:=BP; ELSE APP:=AP; END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*6*) END DIIPSM; 


PROCEDURE DIIPSN(A: LIST): LIST; 
(*Distributive integral polynomial sum norm. A is a distributive
integral polynomial. b is the sum norm of A.*)
VAR  AL, AS, BL, CL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) BL:=0; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*sum.*) AS:=A; 
      REPEAT DIPMAD(AS, AL,EL,AS); CL:=IABSF(AL); BL:=ISUM(CL,BL); 
             UNTIL AS = SIL; 
      RETURN(BL); 
(*5*) END DIIPSN; 


PROCEDURE DIIPSO(A: LIST): LIST; 
(*Distributive integral polynomial sort. A is a
list of integer base coefficients and exponent vectors,
A is sorted with respect to the actual term order,
two terms with equal exponent vectors are added. *)
VAR  AL, AP, B, BP, BS, EL, TL: LIST; 
BEGIN
(*1*) (*trivial case.*) 
      IF A = 0 THEN RETURN(B); END; 
(*2*) (*construct monomials.*) B:=LIST1(0); BS:=B; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); BP:=DIPFMO(AL,EL); B:=COMP(BP,B); 
             UNTIL AP = SIL; 
(*3*) (*add monomials.*) ADV(B, BP,B); SFIRST(BS,BP); SRED(BS,B); 
      B:=DIIPLS(B); 
(*6*) RETURN(B); END DIIPSO; 


PROCEDURE DIIPSU(A,IL,B: LIST): LIST; 
(*Distributive integral polynomial substitution. A and B are
distributive integral polynomials, 1 le i le r=DIPNOV(A).
E(x1, ...,x(i-1),x(i+1), ...,xr)=A(x1, ...,x(i-1),
B(x1, ...,x(i-1),x(i+1), ...,xr),x(i+1), ...,xr). *)
VAR  AP, BP, BS, C, D, E, EL1, EL2, ES, J1Y, RL: LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) 
      IF A = 0 THEN E:=0; RETURN(E); END; 
      IF B = 0 THEN E:=DIPTCS(A,IL); RETURN(E); END; 
(*2*) (*apply horner s method.*) BS:=B; E:=LIST1(0); ES:=E; AP:=A; 
      REPEAT DIPADV(AP,IL, EL1,EL2,D,AP); 
             WHILE (AP <> 0) AND (EL1 > EL2) DO J1Y:=EL1-EL2; 
                   BP:=DIIPEX(BS,J1Y); D:=DIIPPR(D,BP); 
                   DIPADV(AP,IL,EL1,EL2,C,AP); D:=DIIPSM(D,C); END; 
             BP:=DIIPEX(BS,EL1); D:=DIIPPR(D,BP); E:=COMP(D,E); 
             UNTIL AP = 0; 
      ADV(E, D,E); SFIRST(ES,D); SRED(ES,E); E:=DIIPLS(E); 
(*5*) RETURN(E); END DIIPSU; 


PROCEDURE DIIPSV(A,B: LIST): LIST; 
(*Distributive integral polynomial substitution for main variable.
A and B are distributive integral polynomials. t=DIPNOV(A)-1.
C(x1, ...,xt)=A(x1, ...,xt,B(x1, ...,xt)). *)
VAR  AP, BP, C, D, EL1, EL2, J1Y: LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
      IF B = 0 THEN C:=DIPTCF(A); RETURN(C); END; 
(*2*) (*apply horner s method.*) DIPADM(A, EL1,EL2,C,AP); 
      WHILE AP <> 0 DO J1Y:=EL1-EL2; BP:=DIIPEX(B,J1Y); 
            C:=DIIPPR(C,BP); DIPADM(AP, EL1,EL2,D,AP); C:=DIIPSM(C,D); 
            END; 
      BP:=DIIPEX(B,EL1); C:=DIIPPR(C,BP); RETURN(C); 
(*5*) END DIIPSV; 


PROCEDURE DIIPTM(A,HL: LIST): LIST; 
(*Distributive integral polynomial translation main variable.
A is a distributive integral polynomial, h is an integer.
B(x1, ...xr)=A(x1, ...,x(r-1),xr+h). r=DIPNOV(A). *)
VAR  AL, ALQ, AS, B, B1, B2, EL, ELS, IL: LIST; 
BEGIN
(*1*) (*a=0 or hl=0.*) 
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END; 
(*2*) (*general case.*) DIPADM(A, EL,ELS,AL,AS); B:=DIPCMP(0,AL); 
      LOOP FOR IL:=1 TO EL-ELS DO B1:=DIPMPM(B,1); B2:=DIIPIP(B,HL); 
               B:=DIIPSM(B1,B2); END; 
           IF AS = 0 THEN RETURN(B); END; 
           DIPADM(AS, EL,ELS,AL,AS); ALQ:=DIPCMP(0,AL); 
           B:=DIIPSM(B,ALQ); 
           END; 
(*5*) RETURN(B); END DIIPTM; 


PROCEDURE DIIPTR(A,HL,IL: LIST): LIST; 
(*Distributive integral polynomial translation. A is a
distributive integral polynomial, h is an integer,
the i-th variable is translated. 1 le i le r=DIPNOV(A).
B(x1, ...,xr)=A(x1, ...,xi+h, ...,xr).*)
VAR  AL, AS, B, BS, C, C1, C2, EL1, EL2, KL, RL: LIST; 
BEGIN
(*1*) (*a=0 or hl=0.*) 
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END; 
(*2*) (*apply horner s method.*) AS:=A; B:=LIST1(0); BS:=B; 
      REPEAT DIPADS(AS,IL,0, EL1,EL2,C,AS); 
             WHILE (AS <> 0) AND (EL1 > EL2) DO
                   FOR KL:=1 TO EL1-EL2 DO C1:=DIPMPV(C,IL,1); 
                       C2:=DIIPIP(C,HL); C:=DIIPSM(C1,C2); END; 
                   DIPADS(AS,IL,0, EL1,EL2,AL,AS); C:=DIIPSM(C,AL); END; 
             FOR KL:=1 TO EL1 DO C1:=DIPMPV(C,IL,1); C2:=DIIPIP(C,HL); 
                 C:=DIIPSM(C1,C2); END; 
             B:=COMP(C,B); 
             UNTIL AS = 0; 
      ADV(B, C,B); SFIRST(BS,C); SRED(BS,B); B:=DIIPLS(B); 
(*5*) RETURN(B); END DIIPTR; 


PROCEDURE DIIPWR(A,V: LIST); 
(*Distributive integral polynomial write. A is a distributive
integral poynomial in r variables, r ge 0. V is a variable list
for A. A is written in the output stream. Modified version,
original version by G. E. Collins. *)
VAR  AL, AS, E, EL, ES, FL, LL, RL, SL, VL, VS: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) 
      IF A = 0 THEN AWRITE(A); RETURN; END; 
      RL:=DIPNOV(A); 
      IF RL = 0 THEN IWRITE(DIPLBC(A)); RETURN; END; 
(*2*) (*general case.*) AS:=A; FL:=0; LL:=DIPNBC(A); 
      IF LL > 1 THEN SWRITE("("); END; 
      REPEAT DIPMAD(AS, AL,E,AS); SWRITE(" "); SL:=ISIGNF(AL); 
             IF (SL > 0) AND (FL <> 0) THEN SWRITE("+"); END; 
             FL:=1; SL:=EVSIGN(E); 
             IF SL = 0 THEN IWRITE(AL); ELSE
                IF AL = -1 THEN SWRITE("-"); AL:=1; END; 
                IF AL <> 1 THEN IWRITE(AL); END; 
                ES:=CINV(E); VS:=V; 
                REPEAT ADV(ES, EL,ES); ADV(VS, VL,VS); 
                       IF EL > 0 THEN SWRITE(" "); CLOUT(VL); 
                          IF EL > 1 THEN SWRITE("**"); 
                             AWRITE(EL); END; 
                          END; 
                       UNTIL ES = SIL; 
                END; 
             UNTIL AS = SIL; 
      SWRITE(" "); 
      IF LL > 1 THEN SWRITE(")"); END; 
(*5*) RETURN; END DIIPWR; 


PROCEDURE DIIPWV(A: LIST); 
(*Distributive integral polynomial write with standard variable list.
A is a distributive integral poynomial. The standard
variable list is used. A is written in the output stream.*)
VAR  RL, VL: LIST; 
BEGIN
(*1*) (*create variable list.*) RL:=DIPNOV(A); VL:=STVL(RL); 
(*2*) (*write polynomial.*) DIIPWR(A,VL); RETURN; 
(*5*) END DIIPWV; 


PROCEDURE DIIRAS(RL,KL,LL,EL,QL: LIST): LIST; 
(*Distributive integral polynomial random sparse exponent vector.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive integral polynomial in r variables
max norm of a lt 2**k and maximal l base coefficients. *)
VAR  A, AL, AP, FL, IL, QL1, QL2, QLP, TL: LIST; 
BEGIN
(*1*) (*rl=0.*) A:=0; 
      IF RL = 0 THEN AL:=IRAND(KL); A:=DIPFMO(AL,BETA); RETURN(A); 
         END; 
(*2*) (*call evrand.*) FIRST2(QL, QL1,QL2); DQR(QL1,0,QL2, QLP,TL); 
      FOR IL:=1 TO LL DO AL:=IRAND(KL); 
          IF AL <> 0 THEN FL:=EVRASP(RL,EL,QLP); AP:=DIPFMO(AL,FL); 
             A:=DIIPSM(A,AP); END; 
          END; 
(*5*) RETURN(A); END DIIRAS; 


END DIPI.


(* -EOF- *)
