(* ----------------------------------------------------------------------------
 * $Id: DIPRN.mi,v 1.4 1995/11/05 09:18:39 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRN.mi,v $
 * Revision 1.4  1995/11/05 09:18:39  kredel
 * Improved polynomial parsing and corrections.
 *
 * Revision 1.3  1992/10/15  16:28:36  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:52  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:05  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPRN;

(* DIP Rational Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, FIRST, ADV, RED, COMP,
                    LENGTH, LIST1, SRED, SFIRST, INV;

FROM MASERR IMPORT harmless, ERROR;

FROM MASBIOS IMPORT BLINES, SWRITE, CWRITE, CREAD, CREADB,
                    SOLINE, BKSP, MASORD, LETTER, DIGIT;

FROM SACLIST IMPORT FIRST2, CINV, CLOUT, AWRITE;

FROM SACD IMPORT DQR; 

FROM SACI IMPORT IRAND;

FROM SACRN IMPORT RNWRIT, RNABS, RNINV, RNDIF, RNNEG, RNINT, RNRED, 
                  RNCOMP, RNSIGN, RNRAND, RNQ, RNPROD, RNSUM;

FROM SACPOL IMPORT VREAD, VLSRCH, VLWRIT;

FROM MASRN IMPORT RNDWR, RNDRD, RNONE, RNEXP, RNMAX;
 
FROM DIPC    IMPORT DIPNBC, DIPADS, DIPADV, DIPEVL, DIPMAD, 
                    DIPMPM, DIPFMO, 
                    DIPMCP, DIPMRD, DIPCMP, DIPTCF, DIPTCS, 
                    DIPMPV, DIPLBC, DIPINV, DIPADM, DIPNOV,
                    STVL,
                    EVRASP, EVRAND, EVDFSI, EVSUM, 
                    EPREAD, EVSIGN, EVDER, EVCOMP;

CONST rcsidi = "$Id: DIPRN.mi,v 1.4 1995/11/05 09:18:39 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRFIP(A: LIST): LIST; 
(*Distributive rational polynomial from integral polynomial.
A is a distributive integral polynomial, B is the monic associate
rational polynomial of A. *)
VAR  AL, AL1, AP, B, BL, EL: LIST; 
BEGIN
(*1*) (*a=0. *) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*divide base coefficients. *) DIPMAD(A, AL1,EL,AP); 
      BL:=RNINT(1); B:=DIPFMO(EL,BL); 
      WHILE AP <> SIL DO DIPMAD(AP, AL,EL,AP); BL:=RNRED(AL,AL1); 
            B:=DIPMCP(EL,BL,B); END; 
      B:=INV(B); 
(*5*) RETURN(B); END DIRFIP; 


PROCEDURE DIRLRD(V: LIST): LIST; 
(*Distributive rational polynomial list read. V is a
variable list. A list of distributive rational polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding A are skipped. *)
VAR  A, AL, C: LIST; 
BEGIN
(*1*) (*no list. *) A:=BETA; C:=CREADB(); 
      IF C <> MASORD("(") THEN ERROR(harmless,"DIRLRD, ( expected."); 
         RETURN(A); END; 
(*2*) (*read polynomials. *) 
      REPEAT C:=CREADB(); 
             IF C = MASORD(",") THEN C:=CREADB(); END; 
             IF C <> MASORD(")") THEN BKSP; AL:=DIRPRD(V); A:=COMP(AL,A); 
                END; 
             UNTIL C = MASORD(")"); 
      A:=INV(A); 
(*5*) RETURN(A); END DIRLRD; 


PROCEDURE DIRLWR(A,V,S: LIST); 
(*Distributive rational polynomial list write. V is a
variable list. A list of distributive rational polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)
VAR  AL, AP, OS, LS, RS: LIST; 
BEGIN
(*1*) (*format. *) BLINES(0); OS:=-1; LS:=10; RS:=60;  
      SOLINE(OS,LS,RS);  
(*2*) (*write polynomials. *) AP:=A; 
      WHILE AP <> SIL DO ADV(AP, AL,AP); DIRPWR(AL,V,S); BLINES(1); 
            END; 
      SOLINE(OS,LS,RS); BLINES(0);
(*5*) RETURN; END DIRLWR; 


PROCEDURE DIRPAB(A: LIST): LIST; 
(*Distributive rational polynomial absolute value. A is a
distributive rational polynomial. B is the absolute value of A.*)
VAR  B, SL: LIST; 
BEGIN
(*1*) (* b=a*(sign of a). *) SL:=DIRPSG(A); 
      IF SL >= 0 THEN B:=A; ELSE B:=DIRPNG(A); END; 
      RETURN(B); 
(*4*) END DIRPAB; 


PROCEDURE DIRPDF(A,B: LIST): LIST; 
(*Distributive rational polynomial difference. A and B are
distributive rational polynomials. C=A-B.*)
VAR  AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=DIRPNG(B); RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); SL:=EVCOMP(EL,FL); 
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CL:=RNNEG(BL); CP:=DIPMCP(FL,CL,CP); 
                   ELSE DIPMAD(AP,AL,EL,AP); DIPMAD(BP, BL,FL,BP); 
                   CL:=RNDIF(AL,BL); 
                   IF CL <> 0 THEN CP:=DIPMCP(EL,CL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) APP:=AP; 
      IF AP = SIL THEN
         IF BP <> SIL THEN APP:=DIRPNG(BP); END; 
         END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*6*) END DIRPDF; 


PROCEDURE DIRPDM(A: LIST): LIST; 
(*Distributive rational polynomial derivation main variable.
A is a distributive polynomial. B is the derivation of A
with respect to its main variable.*)
VAR  AL, ALP, AS, B, EL, EL1, EL2, ELR, ELS, FL: LIST; 
BEGIN
(*1*) (*a eq 0 or rational.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      IF DIPEVL(A) = SIL THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); ADV(EL, EL1,ELS); 
             IF EL1 > 0 THEN ELR:=RNINT(EL1); ALP:=RNPROD(AL,ELR); 
                EL2:=EL1-1; FL:=COMP(EL2,ELS); B:=DIPMCP(FL,ALP,B); END; 
             UNTIL (AS = SIL) OR (EL1 = 0); 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIRPDM; 


PROCEDURE DIRPDR(A,IL: LIST): LIST; 
(*Distributive rational polynomial derivation. A is a distributive
polynomial. B is the derivation of A with respect to its i-th
variable, 0 le i le DIPNOV(A).*)
VAR  AL, ALP, AS, B, EL, ELP, FL, FLR, J1Y, JL, KL, RL: LIST; 
BEGIN
(*1*) (*a=0 or il=rl.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      RL:=DIPNOV(A); KL:=1; J1Y:=RL-IL; JL:=J1Y+1; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); EVDER(EL,JL,KL, ELP,FL); 
             IF FL <> 0 THEN FLR:=RNINT(FL); ALP:=RNPROD(AL,FLR); 
                B:=DIPMCP(ELP,ALP,B); END; 
             UNTIL AS = SIL; 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIRPDR; 


PROCEDURE DIRPEM(A,AL: LIST): LIST; 
(*Distributive rational polynomial evaluation of main variable.
A is a distributive rational polynomial. a is a rational number.
B(x1, ...,x(r-1))=A(x1, ...,x(r-1),a). *)
VAR  ALP, AP, B, C, EL1, EL2, J1Y: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*apply horner s method.*) DIPADM(A, EL1,EL2,B,AP); 
      WHILE AP <> 0 DO J1Y:=EL1-EL2; ALP:=RNEXP(AL,J1Y); 
            B:=DIRPRP(B,ALP); DIPADM(AP, EL1,EL2,C,AP); B:=DIRPSM(B,C); 
            END; 
      ALP:=RNEXP(AL,EL1); B:=DIRPRP(B,ALP); RETURN(B); 
(*5*) END DIRPEM; 


PROCEDURE DIRPEV(A,IL,AL: LIST): LIST; 
(*Distributive rational polynomial evaluation of the i-th variable.
A is a distributive rational polynomial, 1 le i le DIPNOV(A),
a is a rational number. B(x1, ...,x(i-1),x(i+1), ...,xr)=
A(x1, ...,x(i-1),a,x(i+1), ...,xr). *)
VAR  ALP, AP, B, BS, C, D, EL1, EL2, J1Y, RL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*apply horner s method.*) B:=LIST1(0); BS:=B; AP:=A; 
      REPEAT DIPADV(AP,IL, EL1,EL2,D,AP); 
             WHILE (AP <> 0) AND (EL1 > EL2) DO J1Y:=EL1-EL2; 
                   ALP:=RNEXP(AL,J1Y); D:=DIRPRP(D,ALP); DIPADV(AP,IL,
                   EL1,EL2,C,AP); D:=DIRPSM(D,C); END; 
             ALP:=RNEXP(AL,EL1); D:=DIRPRP(D,ALP); B:=COMP(D,B); 
             UNTIL AP = 0; 
      ADV(B, D,B); SFIRST(BS,D); SRED(BS,B); B:=DIRPLS(B); 
(*5*) RETURN(B); END DIRPEV; 


PROCEDURE DIRPEX(A,NL: LIST): LIST; 
(*Distributive rational polynomial exponentiation. A is a
distributive rational polynomial, n is a non-negative beta-
integer. B=A**n. 0**0 is by definition a polynomial in
zero variables. *)
VAR  B, BL, BLP, I, RL: LIST; 
BEGIN
(*1*) (*nl=0.*) 
      IF NL = 0 THEN RL:=DIPNOV(A); BLP:=RNINT(1); 
         BL:=DIPFMO(BLP,BETA); B:=DIPINV(BL,0,RL); RETURN(B); END; 
(*2*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*3*) (*general case.*) B:=A; 
      FOR I:=1 TO NL-1 DO B:=DIRPPR(B,A); END; 
      RETURN(B); 
(*6*) END DIRPEX; 


PROCEDURE DIRPHD(A,IL,NL: LIST): LIST; 
(*Distributive rational polynomial higher derivation. A is a
distributive rational polynomial. B is the n-th derivation
of A with respect to its i-th variable, 0 le i le DIPNOV(A). *)
VAR  AL, ALP, AS, B, EL, ELP, FL, FLR, J1Y, JL, RL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
      RL:=DIPNOV(A); J1Y:=RL-IL; JL:=J1Y+1; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); EVDER(EL,JL,NL, ELP,FL); 
             IF FL <> 0 THEN FLR:=RNINT(FL); ALP:=RNPROD(AL,FLR); 
                B:=DIPMCP(ELP,ALP,B); END; 
             UNTIL AS = SIL; 
(*3*) (*finish.*) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
      RETURN(B); 
(*6*) END DIRPHD; 


PROCEDURE DIRPLS(A: LIST): LIST; 
(*Distributive rational polynomial list sum. A is a circular
list of distributive rational polynomials. B is the sum of all
polynomials in A. *)
VAR  B, BP, BPP, C, CP, CPP: LIST; 
BEGIN
(*1*) (*nothing to do. *) 
      IF A = SIL THEN B:=0; RETURN(B); END; 
(*2*) (*merge. *) C:=A; ADV(C, B,CP); 
      WHILE C <> CP DO ADV(CP, BP,CPP); BPP:=DIRPSM(B,BP); 
            SFIRST(C,BPP); SRED(C,CPP); C:=CPP; ADV(C, B,CP); END; 
(*5*) RETURN(B); END DIRPLS; 


PROCEDURE DIRPMC(A: LIST): LIST; 
(*Distributive rational polynomial monic. A and C are
distributive rational polynomials, C=A/LBC(A) if A ne 0
C=0 if A eq 0. *)
VAR  BL, C, CL, SL: LIST; 
BEGIN
(*1*) (*a=0.*) C:=A; 
      IF A = 0 THEN RETURN(C); END; 
(*2*) (*multiply.*) BL:=DIPLBC(A); SL:=RNONE(BL); 
      IF SL <> 1 THEN CL:=RNINV(BL); C:=DIRPRP(A,CL); END; 
(*5*) RETURN(C); END DIRPMC; 


PROCEDURE DIRPMN(A: LIST): LIST; 
(*Distributive rational polynomial maximum norm. A is a
distributive rational polynomial. b is the maximum norm of A.*)
VAR  AL, AS, BL, CL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) BL:=0; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*find maximum.*) AS:=A; 
      REPEAT DIPMAD(AS, AL,EL,AS); CL:=RNABS(AL); BL:=RNMAX(CL,BL); 
             UNTIL AS = SIL; 
      RETURN(BL); 
(*5*) END DIRPMN; 


PROCEDURE DIRPNG(A: LIST): LIST; 
(*Distributive rational polynomial negative. B= -A.*)
VAR  AL, AS, B, BL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); BL:=RNNEG(AL); B:=DIPMCP(EL,BL,B); 
             UNTIL AS = SIL; 
      B:=INV(B); RETURN(B); 
(*5*) END DIRPNG; 


PROCEDURE DIRPON(A: LIST): LIST; 
(*Distributive rational polynomial one. A is a distributive
rational polynomial. If A=1 then t=1, otherwise t=0.*)
VAR  AL, AS, EL, FL, TL: LIST; 
BEGIN
(*1*) (*a eq 0.*) TL:=0; 
      IF A = 0 THEN RETURN(TL); END; 
(*2*) (*a=rational number.*) DIPMAD(A, AL,EL,AS); 
      IF AS <> SIL THEN RETURN(TL); END; 
      FL:=EVSIGN(EL); 
      IF FL <> 0 THEN RETURN(TL); END; 
      TL:=RNONE(AL); 
(*5*) RETURN(TL); END DIRPON; 


PROCEDURE DIRPPR(A,B: LIST): LIST; 
(*Distributive rational polynomial product. A and B are
distributive rational polynomials. C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*general case.*) AS:=CINV(A); BS:=B; C:=LIST1(0); CS:=C; 
      REPEAT DIPMAD(BS, BL,FL,BS); AP:=AS; C1:=BETA; 
             REPEAT DIPMAD(AP, EL,AL,AP); CL:=RNPROD(AL,BL); 
                    GL:=EVSUM(EL,FL); C1:=DIPMCP(CL,GL,C1); 
                    UNTIL AP = SIL; 
             C:=COMP(C1,C); 
             UNTIL BS = SIL; 
      ADV(C, C1,C); SFIRST(CS,C1); SRED(CS,C); C:=DIRPLS(C); 
(*5*) RETURN(C); END DIRPPR; 


PROCEDURE DIRPQ(A,B: LIST): LIST; 
(*Distributive rational polynomial quotient. A and B are
distributive rational polynomials. B is a non zero divisor
of A. C=B/A.*)
VAR  C, R: LIST; 
BEGIN
(*1*) (*call dirpqr.*) DIRPQR(A,B, C,R); RETURN(C); 
(*4*) END DIRPQ; 


PROCEDURE DIRPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive rational polynomial quotient and remainder.
A and B are distributive rational polynomials with B ne 0.
Q and R are unique distributive rational polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with deg(R) lt deg(B). *)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RP, SL, TL: LIST; 
BEGIN
(*1*) (*initialise.*) DIPMAD(B, BL,NL,BP); 
      IF BP = SIL THEN BP:=0; END; 
      Q:=BETA; R:=A; 
(*2*) (*compute quotient terms.*) 
      LOOP IF R = 0 THEN EXIT END; 
           ML:=DIPEVL(R); EVDFSI(ML,NL, DL,TL); 
           IF TL < 0 THEN EXIT END; 
           AL:=DIPLBC(R); QL:=RNQ(AL,BL); Q:=DIPMCP(DL,QL,Q); 
           Q1:=DIPFMO(QL,DL); RP:=DIPMRD(R); QP:=DIRPPR(BP,Q1); 
           R:=DIRPDF(RP,QP); END; 
(*3*) (*finish.*) 
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END; 
      RETURN; 
(*6*) END DIRPQR; 


PROCEDURE DIRPRA(RL,KL,LL,EL: LIST): LIST; 
(*Distributive rational polynomial random.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive rational polynomial in r variables
max norm of A lt 2**k and maximal l base coefficients. *)
VAR  A, AL, AP, FL, IL: LIST; 
BEGIN
(*1*) (*rl=0.*) A:=0; 
      IF RL = 0 THEN AL:=RNRAND(KL); A:=DIPFMO(AL,BETA); RETURN(A); 
         END; 
(*2*) (*call evrand.*) 
      FOR IL:=1 TO LL DO AL:=RNRAND(KL); 
          IF AL <> 0 THEN FL:=EVRAND(RL,EL); AP:=DIPFMO(AL,FL); 
             A:=DIRPSM(A,AP); END; 
          END; 
(*5*) RETURN(A); END DIRPRA; 


PROCEDURE DIRPRD(V: LIST): LIST; 
(*Distributive rational polynomial read. V is a variable list.
A distributive rational polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. modified version, orginal
version by G. E. Collins. *)
VAR  A, A1, AL, AP, C, EL, ES, FL, IDUM, IL, J1Y, JL, RL, VL: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) A:=0; C:=CREADB(); 
      IF C = 0 THEN RETURN(A); END; 
      BKSP; 
(*2*) (*initialise.*) C:=CREADB(); BKSP; 
      IF C = MASORD(",") THEN ERROR(harmless,"DIRPRD, no , expected.");  
         RETURN(A); END; 
      FL:=0; 
      IF C = MASORD("(") THEN C:=CREADB(); FL:=1; END; 
      IF C = MASORD(")") THEN
         IF FL = 1 THEN RETURN(A); 
            ELSE ERROR(harmless,"DIRPRD, no ) expected."); RETURN(A); END; 
         END; 
      RL:=LENGTH(V); ES:=BETA; 
      FOR IL:=1 TO RL DO ES:=COMP(0,ES); END; 
      J1Y:=RNINT(1); A1:=DIPFMO(J1Y,ES); AP:=A1;
LOOP 
(*3*) (*next input. determine next action. *) C:=CREADB(); 
      IF C = MASORD(")") THEN
         IF FL = 0 THEN BKSP; END; 
         RETURN(A); END; 
      IF C = MASORD(",") THEN BKSP; RETURN(A); END; 
      IF C = MASORD("-") THEN AP:=DIRPNG(AP); END; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) THEN C:=CREADB(); END; 
      IF C = MASORD("*") THEN C:=CREADB(); END; 
      BKSP; 
(*4*) (*read coefficient.*) 
      IF DIGIT(C) THEN AL:=RNDRD(); EL:=EPREAD(); 
         AL:=RNEXP(AL,EL); AP:=DIRPRP(AP,AL);  
(*5*) (*read polynomial.*) 
      ELSIF C = MASORD("(") THEN AL:=DIRPRD(V); EL:=EPREAD(); 
         AL:=DIRPEX(AL,EL); AP:=DIRPPR(AP,AL);  
(*6*) (*read monic monomial.*) 
      ELSIF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); 
         IF JL = 0 THEN ERROR(harmless,"DIRPRD, unknown variable.");  
            RETURN(A); END; 
         EL:=EPREAD(); AP:=DIPMPV(AP,JL,EL); END; 
(*8*) (*complete polynomial.*) C:=CREADB(); BKSP; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) OR (C = MASORD(")"))
      OR (C = MASORD(",")) THEN A:=DIRPSM(A,AP); AP:=A1; END; 
END; 
(*11*) END DIRPRD; 


PROCEDURE DIRPRP(A,BL: LIST): LIST; 
(*Distributive rational polynomial rational number product.
Is a distributive rational polynomial, b is a rational number.
C=A*b.*)
VAR  AL, AP, C, EL, PL: LIST; 
BEGIN
(*1*) (*a=0 or bl=0.*) 
      IF (A = 0) OR (BL = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*multiply.*) C:=BETA; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); PL:=RNPROD(AL,BL); 
             C:=DIPMCP(EL,PL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END DIRPRP; 


PROCEDURE DIRPRQ(A,BL: LIST): LIST; 
(*Distributive rational polynomial rational number quotient. A
is a distributive rational polynomial, b is a nonzero rational
number. C=A/b.*)
VAR  AL, AP, C, CL, EL, QL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
(*2*) (*divide.*) C:=BETA; AP:=A; CL:=RNINV(BL); 
      REPEAT DIPMAD(AP, AL,EL,AP); QL:=RNPROD(AL,CL); 
             C:=DIPMCP(EL,QL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); 
(*5*) RETURN(C); END DIRPRQ; 


PROCEDURE DIRPSG(A: LIST): LIST; 
(*Distributive rational polynomial sign. A is a distributive
rational polynomial. s is the sign of the leading base
coefficient of A.*)
VAR  J1Y, SL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN SL:=0; ELSE J1Y:=DIPLBC(A); SL:=RNSIGN(J1Y); 
         END; 
      RETURN(SL); 
(*4*) END DIRPSG; 


PROCEDURE DIRPSM(A,B: LIST): LIST; 
(*Distributive rational polynomial sum. A and B are
distributive rational polynomials. C=A+B. *)
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
                   DIPMAD(BP, BL,FL,BP); CL:=RNSUM(AL,BL); 
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
(*6*) END DIRPSM; 


PROCEDURE DIRPSN(A: LIST): LIST; 
(*Distributive rational polynomial sum norm. A is a distributive
rational polynomial. b is the sum norm of A.*)
VAR  AL, AS, BL, CL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) BL:=0; 
      IF A = 0 THEN RETURN(BL); END; 
(*2*) (*sum.*) AS:=A; 
      REPEAT DIPMAD(AS, AL,EL,AS); CL:=RNABS(AL); BL:=RNSUM(CL,BL); 
             UNTIL AS = SIL; 
      RETURN(BL); 
(*5*) END DIRPSN; 


PROCEDURE DIRPSO(A: LIST): LIST; 
(*Distributive rational polynomial sort. A is a
list of rational coefficients and exponent vectors,
A is sorted into inverse lexicographical order,
two terms with equal exponent vectors are added. *)
VAR  AL, AP, B, BP, BS, EL, TL: LIST; 
BEGIN
(*1*) (*trivial case.*) 
      IF A = 0 THEN RETURN(A); END; 
(*2*) (*construct monomials.*) B:=LIST1(0); BS:=B; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); BP:=DIPFMO(AL,EL); B:=COMP(BP,B); 
             UNTIL AP = SIL; 
(*3*) (*add monomials.*) ADV(B, BP,B); SFIRST(BS,BP); SRED(BS,B); 
      B:=DIRPLS(B); 
(*6*) RETURN(B); END DIRPSO; 


PROCEDURE DIRPSU(A,IL,B: LIST): LIST; 
(*Distributive rational polynomial substitution. A and B are
distributive rational polynomials, 1 le i le r=DIPNOV(A).
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
                   BP:=DIRPEX(BS,J1Y); D:=DIRPPR(D,BP); DIPADV(AP,IL,
                   EL1,EL2,C,AP); D:=DIRPSM(D,C); END; 
             BP:=DIRPEX(BS,EL1); D:=DIRPPR(D,BP); E:=COMP(D,E); 
             UNTIL AP = 0; 
      ADV(E, D,E); SFIRST(ES,D); SRED(ES,E); E:=DIRPLS(E); 
(*5*) RETURN(E); END DIRPSU; 


PROCEDURE DIRPSV(A,B: LIST): LIST; 
(*Distributive rational polynomial substitution for main variable.
A and B are distributive rational polynomials. t=DIPNOV(A)-1.
C(x1, ...,xt)=A(x1, ...,xt,B(x1, ...,xt)). *)
VAR  AP, BP, C, D, EL1, EL2, J1Y: LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
      IF B = 0 THEN C:=DIPTCF(A); RETURN(C); END; 
(*2*) (*apply horner s method.*) DIPADM(A, EL1,EL2,C,AP); 
      WHILE AP <> 0 DO J1Y:=EL1-EL2; BP:=DIRPEX(B,J1Y); 
            C:=DIRPPR(C,BP); DIPADM(AP, EL1,EL2,D,AP); C:=DIRPSM(C,D); 
            END; 
      BP:=DIRPEX(B,EL1); C:=DIRPPR(C,BP); RETURN(C); 
(*5*) END DIRPSV; 


PROCEDURE DIRPTM(A,HL: LIST): LIST; 
(*Distributive rational polynomial translation main variable.
A is a distributive rational polynomial, h is a rational number.
B(x1, ...xr)=A(x1, ...,x(r-1),x(r)+h). r=DIPNOV(A). *)
VAR  AL, ALQ, AS, B, B1, B2, EL, ELS, IL: LIST; 
BEGIN
(*1*) (*a=0 or hl=0.*) 
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END; 
(*2*) (*general case.*) DIPADM(A, EL,ELS,AL,AS); B:=DIPCMP(0,AL); 
      LOOP FOR IL:=1 TO EL-ELS DO B1:=DIPMPM(B,1); B2:=DIRPRP(B,HL); 
                B:=DIRPSM(B1,B2); END; 
           IF AS = 0 THEN RETURN(B); END; 
           DIPADM(AS, EL,ELS,AL,AS); ALQ:=DIPCMP(0,AL); 
           B:=DIRPSM(B,ALQ); 
           END; 
(*5*) RETURN(B); END DIRPTM; 


PROCEDURE DIRPTR(A,HL,IL: LIST): LIST; 
(*Distributive rational polynomial translation. A is a
distributive rational polynomial, h is a rational number,
the i-th variable is translated. 1 le i le r=DIPNOV(A).
B(x1, ...,xr)=A(x1, ...,x(i)+h, ...,xr).*)
VAR  AL, AS, B, BS, C, C1, C2, EL1, EL2, KL, RL: LIST; 
BEGIN
(*1*) (*a=0 or hl=0.*) 
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END; 
(*2*) (*apply horner s method.*) AS:=A; B:=LIST1(0); BS:=B; 
      REPEAT DIPADS(AS,IL,0, EL1,EL2,C,AS); 
             WHILE (AS <> 0) AND (EL1 > EL2) DO
                   FOR KL:=1 TO EL1-EL2 DO C1:=DIPMPV(C,IL,1); 
                       C2:=DIRPRP(C,HL); C:=DIRPSM(C1,C2); END; 
                   DIPADS(AS,IL,0, EL1,EL2,AL,AS); C:=DIRPSM(C,AL); END; 
             FOR KL:=1 TO EL1 DO C1:=DIPMPV(C,IL,1); C2:=DIRPRP(C,HL); 
                 C:=DIRPSM(C1,C2); END; 
             B:=COMP(C,B); 
             UNTIL AS = 0; 
      ADV(B, C,B); SFIRST(BS,C); SRED(BS,B); B:=DIRPLS(B); 
(*5*) RETURN(B); END DIRPTR; 


PROCEDURE DIRPWR(A,V,S: LIST); 
(*Distributive rational polynomial write. A is a distributive
rational poynomial in r variables, r ge 0. V is a variable list
for A. If S ge 0 then the coefficients are written by RNDWR
else by RNWRIT. A is written in the output stream.
Modified version, original version by G. E. Collins. *)
VAR  AL, AS, E, EL, ES, FL, J1Y, LL, R1, RL, SL, TL, VL, VS:
     LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) 
      IF A = 0 THEN
         IF S < 0 THEN RNWRIT(A); ELSE RNDWR(A,S); END; 
         RETURN; END; 
      RL:=DIPNOV(A); 
      IF RL = 0 THEN AL:=DIPLBC(A); 
         IF S < 0 THEN RNWRIT(AL); ELSE RNDWR(AL,S); END; 
         RETURN; END; 
(*2*) (*general case.*) AS:=A; FL:=0; J1Y:=-1; R1:=RNINT(J1Y); 
      LL:=DIPNBC(A); 
      IF LL > 1 THEN SWRITE("("); END; 
      REPEAT DIPMAD(AS, AL,E,AS); SWRITE(" "); SL:=RNSIGN(AL); 
             IF (SL > 0) AND (FL <> 0) THEN SWRITE("+"); END; 
             FL:=1; TL:=EVSIGN(E); 
             IF TL = 0 THEN
                IF S >= 0 THEN RNDWR(AL,S); ELSE RNWRIT(AL); END; 
                ELSE TL:=RNONE(AL); 
                IF RNCOMP(R1,AL) = 0 THEN SWRITE("-"); TL:=1; END; 
                IF TL <> 1 THEN
                   IF S >= 0 THEN RNDWR(AL,S); ELSE RNWRIT(AL); END; 
                   END; 
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
(*5*) RETURN; END DIRPWR; 


PROCEDURE DIRPWV(A: LIST); 
(*Distributive rational polynomial write with standard variable
list. A is a distributive rational poynomial. The standard
variable list is used. A is written in the output stream.*)
VAR  RL, VL: LIST; 
BEGIN
(*1*) (*create variable list.*) RL:=DIPNOV(A); VL:=STVL(RL); 
(*2*) (*write polynomial.*) DIRPWR(A,VL,-1); RETURN; 
(*5*) END DIRPWV; 


PROCEDURE DIRRAS(RL,KL,LL,EL,QL: LIST): LIST; 
(*Distributive rational polynomial, random sparse exponent vector.
k, l and e are positive beta-digits. e is the
maximal permitted exponent of A in any variable. A is a
random distributive rational polynomial in r variables
max norm of A lt 2**k and maximal l base coefficients. *)
VAR  A, AL, AP, FL, IL, QL1, QL2, QLP, TL: LIST; 
BEGIN
(*1*) (*rl=0.*) A:=0; 
      IF RL = 0 THEN AL:=IRAND(KL); A:=DIPFMO(AL,BETA); RETURN(A); 
         END; 
(*2*) (*call evrand.*) FIRST2(QL, QL1,QL2); DQR(QL1,0,QL2, QLP,TL); 
      FOR IL:=1 TO LL DO AL:=RNRAND(KL); 
          IF AL <> 0 THEN FL:=EVRASP(RL,EL,QLP); AP:=DIPFMO(AL,FL); 
             A:=DIRPSM(A,AP); END; 
          END; 
(*5*) RETURN(A); END DIRRAS; 


END DIPRN.


(* -EOF- *)
