(* ----------------------------------------------------------------------------
 * $Id: SACIPOL.mi,v 1.3 1992/10/15 16:28:40 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACIPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:40  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:58  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACIPOL;

(* SAC Integer Polynomial System Implementation Module. *)



(* Import list and declarations. *)

FROM MASELEM IMPORT MASODD;

FROM MASSTOR IMPORT LIST, SIL, BETA, SRED, SFIRST,
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT AREAD, LIST2, COMP2, ADV2, FIRST2, 
                    OWRITE, SUFFIX, CLOUT, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT CREAD, CREADB,  
                    DIBUFF, LETTER, DIGIT, 
                    MASORD, BKSP, BLINES, SWRITE;

FROM SACD IMPORT DRANN, DQR, ZETA; 

FROM SACM IMPORT MIDCRA; 

FROM SACI IMPORT IORD2, IMAX, IABSF, IQ, IQR, ILOG2, ISIGNF, ITRUNC, 
                 IMP2, IWRITE, IREAD, IRAND, ISUM, IDIF, INEG, IPROD;

FROM SACPOL IMPORT PCL, PRT, PMPMV, VREAD, PINV, PDEG, PLDCF, PLBCF, PRED;

CONST rcsidi = "$Id: SACIPOL.mi,v 1.3 1992/10/15 16:28:40 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPABS(RL,A: LIST): LIST;
(*Integral polynomial absolute value.  A is an integral polynomial in
r variables.  B is the absolute value of A.*)
VAR  B, SL: LIST;
BEGIN
(*1*) SL:=IPSIGN(RL,A);
      IF SL >= 0 THEN B:=A; ELSE B:=IPNEG(RL,A); END;
      RETURN(B);
(*4*) END IPABS;


PROCEDURE IPCRA(M,ML,MLP,RL,A,AL: LIST): LIST;
(*Integral polynomial chinese remainder algorithm.  M is a positive
integer.  m is a positive beta-integer.  gcd(M,m)=1.  mp is the
inverse of H sub m of M.  A is an integral polynomial in r variables
whose coefficients belong to Z prime sub M, r non-negative.  a is a
polynomial in r variables over Z sub m.  AS is the unique integral
polynomial in r variables with coefficients in Z prime sub MS, where
MS=M*m, which is congruent to A modulo M and to a modulo m.*)
VAR  A1, AL1, ALP, AP, AS, AS1, E, EL, ES, RLP: LIST;
BEGIN
(*1*) (*rl=0.*)
      IF RL = 0 THEN AS:=MIDCRA(M,ML,MLP,A,AL); RETURN(AS); END;
(*2*) (*general case.*)
      IF A = 0 THEN AP:=BETA; ELSE AP:=A; END;
      IF AL = 0 THEN ALP:=BETA; ELSE ALP:=AL; END;
      RLP:=RL-1; AS:=BETA;
      WHILE (AP <> SIL) OR (ALP <> SIL) DO
            IF AP = SIL THEN A1:=0; ADV2(ALP, ES,AL1,ALP); ELSE
               IF ALP = SIL THEN AL1:=0; ADV2(AP, ES,A1,AP); ELSE
                  E:=FIRST(AP); EL:=FIRST(ALP);
                  IF E > EL THEN ADV2(AP, ES,A1,AP); AL1:=0; ELSE
                     IF E < EL THEN ADV2(ALP, ES,AL1,ALP); A1:=0;
                        ELSE ADV2(AP, ES,A1,AP); ADV2(ALP, ES,AL1,ALP);
                        END;
                     END;
                  END;
               END;
            IF RLP = 0 THEN AS1:=MIDCRA(M,ML,MLP,A1,AL1); ELSE
               AS1:=IPCRA(M,ML,MLP,RLP,A1,AL1); END;
            AS:=COMP2(AS1,ES,AS); END;
      IF AS = SIL THEN AS:=0; ELSE AS:=INV(AS); END;
      RETURN(AS);
(*5*) END IPCRA;


PROCEDURE IPDER(RL,A,IL: LIST): LIST;
(*Integral polynomial derivative.  A is an integral polynomial in r
variables.  1 le i le r.  B is the derivative of A with respect to
its i-th variable.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*il=rl.*)
      IF IL = RL THEN B:=IPDMV(RL,A); RETURN(B); END;
(*3*) (*il lt rl.*) AP:=A; RLP:=RL-1; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); BL:=IPDER(RLP,AL,IL);
             IF BL <> 0 THEN B:=COMP2(BL,EL,B); END;
             UNTIL AP = SIL;
      B:=INV(B);
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*6*) END IPDER;


PROCEDURE IPDIF(RL,A,B: LIST): LIST;
(*Integral polynomial difference.  A and B are integral polynomials in
r variables, r ge 0.  C=A-B.*)
VAR  AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=IPNEG(RL,B); RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=IDIF(A,B); RETURN(C); END;
(*3*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=INEG(BL); ELSE
                      CL:=IPNEG(RLP,BL); END;
                   CP:=COMP2(CL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=IDIF(AL,BL); ELSE
                      CL:=IPDIF(RLP,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF (AP = SIL) AND (BP = SIL) THEN CPP:=BETA; ELSE
         IF AP = SIL THEN CPP:=IPNEG(RL,BP); ELSE CPP:=AP; END;
         END;
      C:=INV(CP);
      IF C = SIL THEN C:=CPP; ELSE SRED(CP,CPP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END IPDIF;


PROCEDURE IPDMV(RL,A: LIST): LIST;
(*Integral polynomial derivative, main variable.  A is an integral
polynomial in r variables.  B is the derivative of A with respect to
its main variable.*)
VAR  AL, AP, B, BL, EL, ELP, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*general case.*) AP:=A; RLP:=RL-1; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=IPROD(EL,AL); ELSE
                BL:=IPIP(RLP,EL,AL); END;
             ELP:=EL-1;
             IF EL <> 0 THEN B:=COMP2(BL,ELP,B); END;
             UNTIL AP = SIL;
      B:=INV(B);
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*5*) END IPDMV;


PROCEDURE IPEMV(RL,A,AL: LIST): LIST;
(*Integral polynomial evaluation of main variable.  A is an integral
polynomial in r variables.  a is an integer.
B(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),a).*)
VAR  A2, AP, B, EL1, EL2, IL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*apply horners method.*) ADV2(A, EL1,B,AP); RLP:=RL-1;
      WHILE AP <> SIL DO ADV2(AP, EL2,A2,AP);
            FOR IL:=1 TO EL1-EL2 DO
                IF RLP = 0 THEN B:=IPROD(AL,B); ELSE
                   B:=IPIP(RLP,AL,B); END;
                END;
            IF RLP = 0 THEN B:=ISUM(B,A2); ELSE B:=IPSUM(RLP,B,A2);
               END;
            EL1:=EL2; END;
      FOR IL:=1 TO EL1 DO
          IF RLP = 0 THEN B:=IPROD(AL,B); ELSE B:=IPIP(RLP,AL,B);
          END;
          END;
      RETURN(B);
(*5*) END IPEMV;


PROCEDURE IPEVAL(RL,A,IL,AL: LIST): LIST;
(*Integral polynomial evaluation.  A is an integral polynomial
in r variables.  1 le i le r.  a is an integer.  B(x(1), ...,
x(i-1),x(i+1), ...,x(r))=A(x(1), ...,x(i-1),a,x(i+1), ...,x(r)).*)
VAR  A1, AP, B, B1, EL1, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*il=rl.*)
      IF IL = RL THEN B:=IPEMV(RL,A,AL); RETURN(B); END;
(*3*) (*il lt rl.*) RLP:=RL-1; AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL1,A1,AP); B1:=IPEVAL(RLP,A1,IL,AL);
             IF B1 <> 0 THEN B:=COMP2(B1,EL1,B); END;
             UNTIL AP = SIL;
      B:=INV(B);
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*6*) END IPEVAL;


PROCEDURE IPEXP(RL,A,NL: LIST): LIST;
(*Integral polynomial exponentiation.  A is an integral polynomial in
r variables, r ge 0.  n is a non-negative integer.  B=A**n.*)
VAR  B, IL: LIST;
BEGIN
(*1*) (*nl=0.*)
      IF NL = 0 THEN B:=PINV(0,1,RL); RETURN(B); END;
(*2*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*3*) (*general case.*) B:=A;
      FOR IL:=1 TO NL-1 DO B:=IPPROD(RL,B,A); END;
      RETURN(B);
(*6*) END IPEXP;


PROCEDURE IPFCB(V: LIST): LIST;
(*Integral polynomial factor coefficient bound.  V is the degree vector
of a non-zero integral polynomial A.  b is a non-negative integer such
that if b(1)* ...*b(k) divides A then the product of the infinity norms
of the b(i) is less than or equal to 2**b times the infinity norm of A.
Gelfonds bound is used.*)
VAR  BL, J1Y, NL, NL1, PL, VP: LIST;
BEGIN
(*1*) NL:=0; PL:=1; VP:=V;
      REPEAT ADV(VP, NL1,VP);
             IF NL1 > 0 THEN J1Y:=NL+NL1; J1Y:=J1Y+NL1; NL:=J1Y-1;
                J1Y:=NL1+1; PL:=IPROD(PL,J1Y); END;
             UNTIL VP = SIL;
      J1Y:=ILOG2(PL); NL:=NL+J1Y; J1Y:=NL+1; BL:=J1Y DIV 2; RETURN(BL);
(*4*) END IPFCB;


PROCEDURE IPFRP(RL,A: LIST): LIST;
(*Integral polynomial from rational polynomial.  A is a rational
polynomial in r variables, r ge 0, each of whose base coefficients is
an integer.  B is a converted to integral polynomial representation.*)
VAR  AL, AS, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a eq 0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl eq 0.*)
      IF RL = 0 THEN B:=FIRST(A); RETURN(B); END;
(*3*) (*rl gt 0.*) AS:=A; RLP:=RL-1; B:=BETA;
      REPEAT ADV2(AS, EL,AL,AS);
             IF RLP = 0 THEN BL:=FIRST(AL); ELSE BL:=IPFRP(RLP,AL);
                END;
             B:=COMP2(BL,EL,B);
             UNTIL AS = SIL;
      B:=INV(B); RETURN(B);
(*6*) END IPFRP;


PROCEDURE IPGSUB(RL,A,SL,L: LIST): LIST;
(*Integral polynomial general substitution.  A is an integral
polynomial in r variables, r ge 1.  L is a list (b(1), ...,b(r)) of
integral polynomials in s variables, s ge 1.  C(y(1), ...,y(s))=
A(b(1)(y(1), ...,y(s)), ...,b(r)(y(1), ...,y(s))).*)
VAR  B, C, J1Y, LP, TL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*a ne 0.*) C:=PINV(RL,A,SL); LP:=L; TL:=RL+SL;
      REPEAT ADV(LP, B,LP); J1Y:=SL+1; C:=IPSUB(TL,C,J1Y,B); TL:=TL-1;
             UNTIL LP = SIL;
      RETURN(C);
(*5*) END IPGSUB;


PROCEDURE IPHDMV(RL,A,KL: LIST): LIST;
(*Integral polynomial higher derivative, main variable.  A is an
integral polynomial in r variables.  k is a non-negative
gamma-integer B is the k-th derivative of A with respect to its main
variable.*)
VAR  B, IL: LIST;
BEGIN
(*1*) B:=A; IL:=KL;
      WHILE (IL > 0) AND (B <> 0) DO B:=IPDMV(RL,B); IL:=IL-1; END;
      RETURN(B);
(*4*) END IPHDMV;


PROCEDURE IPIHOM(RL,D,A: LIST): LIST;
(*Integral polynomial mod ideal homomorphism.  D is a list (d sub 1, ...,
d sub r-1) of non-negative beta-integers, r ge 0.  A is an r-variate 
integral polynomial.  B=A mod (x sub 1 ** d sub 1, ...,x sub
r-1 ** d sub r-1).*)
VAR  AL, AS, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) RLP:=RL-1; B:=BETA; AS:=CINV(A);
      WHILE AS <> SIL DO ADV2(AS, AL,EL,AS); BL:=IPTRUN(RLP,D,AL);
            IF BL <> 0 THEN B:=COMP2(EL,BL,B); END;
            END;
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*5*) END IPIHOM;


PROCEDURE IPIP(RL,AL,B: LIST): LIST;
(*Integral polynomial integer product.  a is an integer.  B is an
integral polynomial in r variables.  C=a*B.*)
VAR  BL, BP, C, CL, EL, RLP: LIST;
BEGIN
(*1*) (*c=0.*)
      IF (AL = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*general case.*) BP:=B; C:=BETA; RLP:=RL-1;
      REPEAT ADV2(BP, EL,BL,BP);
             IF RLP = 0 THEN CL:=IPROD(AL,BL); ELSE
                CL:=IPIP(RLP,AL,BL); END;
             C:=COMP2(CL,EL,C);
             UNTIL BP = SIL;
      C:=INV(C); RETURN(C);
(*5*) END IPIP;


PROCEDURE IPIPR(RL,D,A,B: LIST): LIST;
(*Integral polynomial mod ideal product.  D is a list (d sub 1, ...,
d sub r-1) of non-negative beta-integers, r ge 1.  A and B belong to
Z(x sub 1, ...,x sub r-1,y)/(x sub 1 **d sub 1, ...,x sub r-1 ** d
sub r-1).  C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*general case.*) AS:=CINV(A); BS:=CINV(B); C:=0; RLP:=RL-1;
      REPEAT ADV2(BS, BL,FL,BS); AP:=AS; C1:=BETA;
             REPEAT ADV2(AP, AL,EL,AP);
                    IF RLP = 0 THEN CL:=IPROD(AL,BL); ELSE
                       CL:=IPTPR(RLP,D,AL,BL); END;
                    IF CL <> 0 THEN J1Y:=EL+FL; C1:=COMP2(J1Y,CL,C1);
                       END;
                    UNTIL AP = SIL;
             IF C1 <> SIL THEN C:=IPSUM(RL,C,C1); END;
             UNTIL BS = SIL;
      RETURN(C);
(*5*) END IPIPR;


PROCEDURE IPIQ(RL,A,BL: LIST): LIST;
(*Integral polynomial integer quotient.  A is an integral polynomial
in r variables.  b is a non-zero integer which divides A.  C=A/b.*)
VAR  AL, AP, C, CL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*a ne 0.*) AP:=A; RLP:=RL-1; C:=BETA;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN CL:=IQ(AL,BL); ELSE CL:=IPIQ(RLP,AL,BL);
                END;
             C:=COMP2(CL,EL,C);
             UNTIL AP = SIL;
      C:=INV(C); RETURN(C);
(*5*) END IPIQ;


PROCEDURE IPMAXN(RL,A: LIST): LIST;
(*Integral polynomial maximum norm.  A is an integral polynomial
in r variables.  b is the maximum norm of A.*)
VAR  AL1, AP, BL, BL1, EL1, RLP: LIST;
BEGIN
(*1*) BL:=0;
      IF A = 0 THEN RETURN(BL); END;
      AP:=A; RLP:=RL-1;
      REPEAT ADV2(AP, EL1,AL1,AP);
             IF RLP = 0 THEN BL1:=IABSF(AL1); ELSE
                BL1:=IPMAXN(RLP,AL1); END;
             BL:=IMAX(BL,BL1);
             UNTIL AP = SIL;
      RETURN(BL);
(*4*) END IPMAXN;


PROCEDURE IPNEG(RL,A: LIST): LIST;
(*Integral polynomial negative.  A is an integral polynomial in r
variables, r ge 0.  B=-A.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=INEG(A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=INEG(AL); ELSE BL:=IPNEG(RLP,AL);
                END;
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END IPNEG;


PROCEDURE IPONE(RL,A: LIST): LIST;
(*Integral polynomial one.  A is an integral polynomial in r
variables.  If A=1 then t=1, otherwise t=0.*)
VAR  AL, IL, TL: LIST;
BEGIN
(*1*) TL:=0;
      IF A = 0 THEN RETURN(TL); END;
      AL:=A;
      FOR IL:=1 TO RL DO
          IF PDEG(AL) <> 0 THEN RETURN(TL); END;
          AL:=PLDCF(AL); END;
      IF AL = 1 THEN TL:=1; END;
      RETURN(TL);
(*4*) END IPONE;


PROCEDURE IPPROD(RL,A,B: LIST): LIST;
(*Integral polynomial product.  A and B are integral polynomials in r
variables, r ge 0.  C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=IPROD(A,B); RETURN(C); END;
(*3*) (*general case.*) AS:=CINV(A); BS:=CINV(B); C:=0; RLP:=RL-1;
      REPEAT ADV2(BS, BL,FL,BS); AP:=AS; C1:=BETA;
             REPEAT ADV2(AP, AL,EL,AP);
                    IF RLP = 0 THEN CL:=IPROD(AL,BL); ELSE
                       CL:=IPPROD(RLP,AL,BL); END;
                    J1Y:=EL+FL; C1:=COMP2(J1Y,CL,C1);
                    UNTIL AP = SIL;
             C:=IPSUM(RL,C,C1);
             UNTIL BS = SIL;
      RETURN(C);
(*6*) END IPPROD;


PROCEDURE IPPSR(RL,A,B: LIST): LIST;
(*Integral polynomial pseudo-remainder.  A and B are integral
polynomials in r variables, B non-zero.  C is the pseudo-remainder
of A and B.*)
VAR  B1, BB, BS, C, C1, CL, IL, J1Y, LL, ML, NL: LIST;
BEGIN
(*1*) (*deg(b)=0.*) NL:=PDEG(B);
      IF NL = 0 THEN C:=0; RETURN(C); END;
(*2*) (*deg(b) gt 0.*) ML:=PDEG(A); C:=A; BB:=PRED(B); J1Y:=PLDCF(B);
      B1:=LIST2(0,J1Y);
      FOR IL:=ML TO NL BY -1 DO
          IF C = 0 THEN RETURN(C); END;
          LL:=PDEG(C);
          IF LL = IL THEN CL:=PLDCF(C); C:=PRED(C);
             C:=IPPROD(RL,C,B1); J1Y:=LL-NL; C1:=LIST2(J1Y,CL);
             BS:=IPPROD(RL,BB,C1); C:=IPDIF(RL,C,BS); ELSE
             C:=IPPROD(RL,C,B1); END;
          END;
      RETURN(C);
(*5*) END IPPSR;


PROCEDURE IPQ(RL,A,B: LIST): LIST;
(*Integral polynomial quotient.  A and B are integral polynomials in
r variables, r ge 0.  B is a non-zero divisor of A.  C=A/B.*)
VAR  C, R: LIST;
BEGIN
(*1*) IF RL = 0 THEN C:=IQ(A,B); ELSE IPQR(RL,A,B, C,R); END;
      RETURN(C);
(*4*) END IPQ;


PROCEDURE IPQR(RL,A,B: LIST; VAR Q,R: LIST);
(*Integral polynomial quotient and remainder.  A and B are integral
polynomials in r variables with B non-zero.  Q and R are the unique
integral polynomials such that either B divides A, Q=A/B and R=0 or
else B does not divide A and A=BQ+R with deg(R) minimal.*)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL: LIST;
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BL:=PLDCF(B); BP:=PRED(B); Q:=BETA;
      R:=A; RLP:=RL-1;
(*2*) (*compute quotient terms.*)
      LOOP IF R = 0 THEN EXIT END; 
           ML:=PDEG(R); DL:=ML-NL;
           IF DL < 0 THEN EXIT END;
           AL:=PLDCF(R);
           IF RLP = 0 THEN IQR(AL,BL, QL,SL); 
                      ELSE IPQR(RLP,AL,BL,QL,SL); END;
           IF SL <> 0 THEN EXIT END;
           Q:=COMP2(QL,DL,Q); Q1:=LIST2(DL,QL); RP:=PRED(R);
           QP:=IPPROD(RL,BP,Q1); R:=IPDIF(RL,RP,QP); END;
(*3*) (*finish.*)
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
      RETURN;
(*6*) END IPQR;


PROCEDURE IPRAN(RL,KL,QL,N: LIST): LIST;
(*Integral polynomial, random.  k is a positive beta-digit.  q is a
rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list
(n sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random integral polynonial in r variables with deg sub i of a le n
sub i for 1 le i le r.  Max norm of A lt 2**k and q is the
probability that any particular term of a has a non-zero coefficient.*)
VAR  A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL: LIST;
BEGIN
(*1*) (*compute qls=int(ql*beta).*) FIRST2(QL, QL1,QL2);
      DQR(QL1,0,QL2, QLS,TL);
(*2*) (*rl=0.*)
      IF RL = 0 THEN DL:=DRANN();
         IF DL < QLS THEN A:=IRAND(KL); ELSE A:=0; END;
         RETURN(A); END;
(*3*) (*rl gt 0.*) RLP:=RL-1; ADV(N, NL,NP); A:=BETA;
      FOR EL:=0 TO NL DO
          IF RLP = 0 THEN DL:=DRANN();
             IF DL < QLS THEN AL:=IRAND(KL); ELSE AL:=0; END;
             ELSE AL:=IPRAN(RLP,KL,QL,NP); END;
          IF AL <> 0 THEN A:=COMP2(EL,AL,A); END;
          END;
      IF A = SIL THEN A:=0; END;
      RETURN(A);
(*6*) END IPRAN;


PROCEDURE IPREAD( VAR RL,A,V: LIST);
(*Integral polynomial read.  The integral polynomial A is read from the
input stream.  r, non-negative, is the number of variables of A and V
is the variable list of A.  Any number of preceding blanks are skipped.*)
VAR  AL, C, EL, IDUM, RLP, VL: LIST;
BEGIN
(*1*) (*rl=0.*) C:=CREADB();
      IF C <> MASORD("(") THEN BKSP; A:=IREAD(); RL:=0; V:=BETA; RETURN;
      END;
(*2*) (*rl positive.*) A:=BETA;
      LOOP C:=CREADB();
           IF C = MASORD(")") THEN EXIT END;
           BKSP; IPREAD(RLP,AL,V); C:=CREADB();
           IF C <> MASORD("*") THEN EXIT END;
           VL:=VREAD(); C:=CREADB();
           IF C <> MASORD("*") THEN EXIT END;
           C:=CREAD();
           IF C <> MASORD("*") THEN EXIT END;
           EL:=AREAD(); A:=COMP2(AL,EL,A); C:=CREADB();
           IF C = MASORD(")") THEN EXIT ELSE
              IF C = MASORD("-") THEN BKSP; ELSE
                 IF C <> MASORD("+") THEN EXIT END;
                 END;
              END;
           END;
(*3*) (*error.*) 
      IF C <> MASORD(")") THEN
         SWRITE("error found by IPREAD."); DIBUFF; END;
(*4*) (*finish.*) A:=INV(A); RL:=RLP+1; V:=SUFFIX(V,VL); RETURN;
(*7*) END IPREAD;


PROCEDURE IPSIGN(RL,A: LIST): LIST;
(*Integral polynomial sign.  A is an integral polynomial in r
variables.  s is the sign of A.*)
VAR  J1Y, SL: LIST;
BEGIN
(*1*) J1Y:=PLBCF(RL,A); SL:=ISIGNF(J1Y); RETURN(SL);
(*4*) END IPSIGN;


PROCEDURE IPSMV(RL,A,B: LIST): LIST;
(*Integral polynomial substitution for main variable.  A is an
integral polynomial in r variables, x(1), ...,x(r).  B is an
integral polynomial in x(1), ...,x(r-1).  C(x(1), ...,x(r-1))=
A(x(1), ...,x(r-1),B(x(1), ...,x(r-1))).*)
VAR  A2, AP, C, EL1, EL2, IL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN C:=IPEMV(RL,A,B); RETURN(C); END;
(*3*) (*apply horners method.*) RLP:=RL-1; ADV2(A, EL1,C,AP);
      WHILE AP <> SIL DO ADV2(AP, EL2,A2,AP);
            FOR IL:=1 TO EL1-EL2 DO C:=IPPROD(RLP,C,B); END;
            C:=IPSUM(RLP,C,A2); EL1:=EL2; END;
      FOR IL:=1 TO EL1 DO C:=IPPROD(RLP,C,B); END;
      RETURN(C);
(*6*) END IPSMV;


PROCEDURE IPSUB(RL,A,IL,B: LIST): LIST;
(*Integral polynomial substitution.  A is an integral polynomial in
r variables, x(1), ...,x(r).  1 le i le r.  B is an integral
polynomial in x(1), ...,x(i-1).  C(x(1), ...,x(i-1),x(i+1), ...,
x(r))=A(x(1), ...,x(i-1),B(x(1), ...,x(i-1)),x(i+1), ..., x(r)).*)
VAR  A1, AP, C, C1, EL1, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*il=rl.*)
      IF IL = RL THEN C:=IPSMV(RL,A,B); RETURN(C); END;
(*3*) (*il lt rl.*) RLP:=RL-1; AP:=A; C:=BETA;
      REPEAT ADV2(AP, EL1,A1,AP); C1:=IPSUB(RLP,A1,IL,B);
             IF C1 <> 0 THEN C:=COMP2(C1,EL1,C); END;
             UNTIL AP = SIL;
      C:=INV(C);
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*6*) END IPSUB;


PROCEDURE IPSUM(RL,A,B: LIST): LIST;
(*Integral polynomial sum.  A and B are integral polynomials in r
variables, r ge 0.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, CP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=ISUM(A,B); RETURN(C); END;
(*3*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   CP:=COMP2(BL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=ISUM(AL,BL); ELSE
                      CL:=IPSUM(RLP,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF AP = SIL THEN AP:=BP; END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END IPSUM;


PROCEDURE IPSUMN(RL,A: LIST): LIST;
(*Integral polynomial sum norm.  A is an integral polynomial in r
variables, r non-negative.  b is the sum norm of A.*)
VAR  AL1, AP, BL, BL1, EL1, RLP: LIST;
BEGIN
(*1*) (*rl=0.*)
      IF RL = 0 THEN BL:=IABSF(A); RETURN(BL); END;
(*2*) (*rl gt 0.*) BL:=0;
      IF A = 0 THEN RETURN(BL); END;
      AP:=A; RLP:=RL-1;
      REPEAT ADV2(AP, EL1,AL1,AP);
             IF RLP = 0 THEN BL1:=IABSF(AL1); ELSE
                BL1:=IPSUMN(RLP,AL1); END;
             BL:=ISUM(BL,BL1);
             UNTIL AP = SIL;
      RETURN(BL);
(*5*) END IPSUMN;


PROCEDURE IPTPR(RL,D,A,B: LIST): LIST;
(*Integral polynomial truncated product.  D is a list (d sub 1, ...,d sub r)
of non-negative beta-integers, r ge 1.  A and B belong to
Z(x sub 1, ...,x sub r)/(x sub 1 **d sub 1, ...,x sub r ** d sub r).
C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, CL, CP, DP, EL, FL, J1Y, NL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*prepare general case.*) DP:=CINV(D); ADV(DP, NL,DP);
      DP:=INV(DP); C:=0;
      IF NL = 0 THEN RETURN(C); END;
      AS:=CINV(A); BS:=CINV(B); RLP:=RL-1;
(*3*) (*multiply.*)
      WHILE (BS <> SIL) AND (SECOND(BS) < NL) DO ADV2(BS, BL,FL,BS);
            AP:=AS; CP:=BETA;
            WHILE (AP <> SIL) AND (SECOND(AP) < NL-FL) DO ADV2(AP,
                  AL,EL,AP);
                  IF RLP = 0 THEN CL:=IPROD(AL,BL); ELSE
                     CL:=IPTPR(RLP,DP,AL,BL); END;
                  IF CL <> 0 THEN J1Y:=EL+FL; CP:=COMP2(J1Y,CL,CP);
                     END;
                  END;
            IF CP <> SIL THEN C:=IPSUM(RL,C,CP); END;
            END;
      RETURN(C);
(*6*) END IPTPR;


PROCEDURE IPTRAN(RL,A,T: LIST): LIST;
(*Integral polynomial translation.  A is an integral polynomial in r
variables, r ge 1.  T is a list (tr, ...,t1) of integers.
B(x1, ...,xr)=A(x1+t1, ...,xr+tr).*)
VAR  B, BL, BLP, BP, EL, RLP, TL, TP: LIST;
BEGIN
(*1*) (*translate main variable.*) ADV(T, TL,TP); B:=IPTRMV(RL,A,TL);
(*2*) (*translate coefficients.*) RLP:=RL-1;
      IF (RLP = 0) OR (B = 0) THEN RETURN(B); END;
      BP:=B; B:=BETA;
      REPEAT ADV2(BP, EL,BLP,BP); BL:=IPTRAN(RLP,BLP,TP);
             B:=COMP2(BL,EL,B);
             UNTIL BP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END IPTRAN;


PROCEDURE IPTRMV(RL,A,HL: LIST): LIST;
(*Integral polynomial translation, main variable.  A is an integral
polynomial in r variables, r ge 1.  h is an integer.
B(x1, ...,xr)=A(x1, ...,x(r-1),xr+h).*)
VAR  AL, ALB, AP, B, B1, B2, EL, ELP, IL: LIST;
BEGIN
(*1*) (*a=0 or hl=0.*)
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) ADV2(A, EL,AL,AP); B:=LIST2(0,AL);
      LOOP IF AP = SIL THEN ELP:=0; ELSE ELP:=FIRST(AP); END;
           FOR IL:=1 TO EL-ELP DO B1:=PMPMV(B,1); B2:=IPIP(RL,HL,B);
               B:=IPSUM(RL,B1,B2); END;
           IF AP = SIL THEN RETURN(B); END;
           ADV2(AP, EL,AL,AP); ALB:=LIST2(0,AL); B:=IPSUM(RL,B,ALB);
           END;
(*5*) END IPTRMV;


PROCEDURE IPTRUN(RL,D,A: LIST): LIST;
(*Integral polynomial truncation.  D is a list (d sub 1, ...,d sub r)
of non-negative beta-integers, r ge 0.  A is an r-variate integral
polynomial.  B=A mod (x sub 1 ** d sub 1, ..., x sub r ** d sub r).*)
VAR  AL, AS, B, BL, DL, DP, EL, RLP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN B:=A; RETURN(B); END;
(*2*) (*initialize.*) RLP:=RL-1; AS:=CINV(A); B:=BETA; DP:=CINV(D);
      ADV(DP, DL,DP); DP:=INV(DP);
(*3*) (*generate terms.*)
      WHILE (AS <> SIL) AND (SECOND(AS) < DL) DO ADV2(AS, AL,EL,AS);
            IF RLP = 0 THEN BL:=AL; ELSE BL:=IPTRUN(RLP,DP,AL); END;
            IF BL <> 0 THEN B:=COMP2(EL,BL,B); END;
            END;
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*6*) END IPTRUN;


PROCEDURE IPWRIT(RL,A,V: LIST);
(*Integral polynomial write.  A is an integral polynomial in r
variables, r ge 0.  V is a variable list for A.  A is written
in the output stream in external canonical form.*)
VAR  AL, AP, EL, IL, RLP, V1, VB, VP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN IWRITE(A); RETURN; END;
(*2*) (*a non-zero.*) SWRITE("("); AP:=A; RLP:=RL-1; VB:=CINV(V);
      ADV(VB, V1,VP); VP:=INV(VP); IL:=0;
      REPEAT ADV2(AP, EL,AL,AP);
             IF (IL <> 0) AND ((RL > 1) OR (ISIGNF(AL) > 0)) THEN
                SWRITE("+"); END;
             IF RLP = 0 THEN IWRITE(AL); ELSE IPWRIT(RLP,AL,VP); END;
             SWRITE("*"); CLOUT(V1); SWRITE("*"); SWRITE("*");
             IWRITE(EL); IL:=1;
             UNTIL AP = SIL;
      SWRITE(")"); RETURN;
(*5*) END IPWRIT;


PROCEDURE IUPBEI(A,CL,ML: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation, integer output.  
A is a univariate integral polynomial.  c is an integer.  m is a 
non-negative beta-integer.  b=2**(n*m)*A(c/2**m) where n=deg(A).
b is an integer.*)
VAR  AL, ALP, AP, BL, EL, J1Y, KL, NL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN BL:=0; RETURN(BL); END;
(*2*) (*apply horner method.*) ADV2(A, NL,BL,AP); KL:=1;
      WHILE KL <= NL DO BL:=IPROD(BL,CL);
            IF (AP <> SIL) AND (FIRST(AP) = NL-KL) THEN ADV2(AP,
               EL,AL,AP); J1Y:=ML*KL; J1Y:=-J1Y; ALP:=ITRUNC(AL,J1Y);
               BL:=ISUM(BL,ALP); END;
            KL:=KL+1; END;
      RETURN(BL);
(*5*) END IUPBEI;


PROCEDURE IUPBES(A,AL: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation of sign.
A is a univariate polynomial.  a is a binary rational number.  
s=sign(A(a)).*)
VAR  BL, CL, DL, ML, SL: LIST;
BEGIN
(*1*) IF A = 0 THEN SL:=0; ELSE
         IF AL = 0 THEN CL:=0; ML:=0; ELSE FIRST2(AL, CL,DL);
            ML:=IORD2(DL); END;
         BL:=IUPBEI(A,CL,ML); SL:=ISIGNF(BL); END;
      RETURN(SL);
(*4*) END IUPBES;


PROCEDURE IUPBHT(A,KL: LIST): LIST;
(*Integral univariate polynomial binary homothetic transformation.  A
is a non-zero univariate integral polynomial.  k is a gamma-integer.
B(x)=2**(-h)*A(2**k*x) where h is uniquely determined so that B is
an integral polynomial not divisible by 2.*)
VAR  AL, AP, B, BL, EL, HL, J1Y, ML, NL: LIST;
BEGIN
(*1*) (*compute hl.*) AP:=A; HL:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); ML:=IORD2(AL); J1Y:=KL*EL; NL:=J1Y+ML;
             IF NL < HL THEN HL:=NL; END;
             UNTIL AP = SIL;
(*2*) (*compute b.*) AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); J1Y:=KL*EL; J1Y:=HL-J1Y;
             BL:=ITRUNC(AL,J1Y); B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END IUPBHT;


PROCEDURE IUPBRE(A,AL: LIST): LIST;
(*Integral univariate polynomial binary rational evaluation.  A is a
univariate integral polynomial.  a is a binary rational number.  
B=A(a), a binary rational number.*)
VAR  BL, BL1, BL2, CL, DL, HL, KL, ML, NL: LIST;
BEGIN
(*1*) (*a=0.*) BL:=0;
      IF A = 0 THEN RETURN(BL); END;
(*2*) (*a ne 0.*)
      IF AL = 0 THEN CL:=0; ML:=0; ELSE FIRST2(AL, CL,DL);
         ML:=IORD2(DL); END;
      BL1:=IUPBEI(A,CL,ML);
      IF BL1 = 0 THEN RETURN(BL); END;
      KL:=IORD2(BL1); NL:=FIRST(A); HL:=ML*NL;
      IF KL >= HL THEN BL1:=ITRUNC(BL1,HL); BL2:=1; ELSE
         BL1:=ITRUNC(BL1,KL); HL:=HL-KL; BL2:=IMP2(1,HL); END;
      BL:=LIST2(BL1,BL2); RETURN(BL);
(*5*) END IUPBRE;


PROCEDURE IUPCHT(A: LIST): LIST;
(*Integral univariate polynomial circle to half-plane transformation.
A is a non-zero univariate integral polynomial.  Let n=deg(A).  Then
B(x)=(x+1)**n*A(1/(x+1)), a univariate integral polynomial.*)
VAR  AP, B: LIST;
BEGIN
(*1*) AP:=PRT(A); B:=IUPTR1(AP); RETURN(B);
(*4*) END IUPCHT;


PROCEDURE IUPNT(A: LIST): LIST;
(*Integral univariate polynomial negative transformation.  A is a 
univariate integral polynomial.  B(x)=A(-x).*)
VAR  AL, AP, B, EL: LIST;
BEGIN
(*1*) IF A = 0 THEN B:=0; RETURN(B); END;
      B:=BETA; AP:=A;
      REPEAT ADV2(AP, EL,AL,AP);
             IF MASODD(EL) THEN AL:=INEG(AL); END;
             B:=COMP2(AL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*4*) END IUPNT;


PROCEDURE IUPTPR(NL,A,B: LIST): LIST;
(*Integral univariate polynomial truncated product.  n is a non-
negative integer.  A and B are integral univariate polynomials.  
C(x)=A(x)*B(x) (modulo x**n) and C=0 or deg(C) lt n.*)
VAR  AL, AP, AS, BL, BS, C, CL, CP, EL, FL, J1Y: LIST;
BEGIN
(*1*) (*nl=0 or a=0 or b=0.*) C:=0;
      IF (NL = 0) OR (A = 0) OR (B = 0) THEN RETURN(C); END;
(*2*) (*general case.*) AS:=CINV(A); BS:=CINV(B);
      WHILE (BS <> SIL) AND (SECOND(BS) < NL) DO ADV2(BS, BL,FL,BS);
            AP:=AS; CP:=BETA;
            WHILE (AP <> SIL) AND (SECOND(AP) < NL-FL) DO ADV2(AP,
                  AL,EL,AP); CL:=IPROD(AL,BL); J1Y:=EL+FL;
                  CP:=COMP2(J1Y,CL,CP); END;
            IF CP <> SIL THEN C:=IPSUM(1,C,CP); END;
            END;
      RETURN(C);
(*5*) END IUPTPR;


PROCEDURE IUPTR(A,HL: LIST): LIST;
(*Integral univariate polynomial translation.  A is a univariate
integral polynomial.  h is an integer.  B(x)=A(x+h).*)
VAR  AL, B, BL, IL, JL, L, LP, NL: LIST;
BEGIN
(*1*) (*degree zero.*) NL:=PDEG(A);
      IF NL = 0 THEN B:=A; RETURN(B); END;
(*2*) (*compute coefficient list.*) L:=PCL(A);
(*3*) (*apply synthetic division.*)
      FOR IL:=NL TO 1 BY -1 DO ADV(L, AL,LP);
          FOR JL:=1 TO IL DO BL:=FIRST(LP); AL:=IPROD(AL,HL);
              AL:=ISUM(AL,BL); SFIRST(LP,AL); LP:=RED(LP); END;
          END;
(*4*) (*convert coefficient list to polynomial.*) B:=BETA; L:=INV(L);
      FOR IL:=0 TO NL DO ADV(L, AL,L);
          IF AL <> 0 THEN B:=COMP2(IL,AL,B); END;
          END;
      RETURN(B);
(*7*) END IUPTR;


PROCEDURE IUPTR1(A: LIST): LIST;
(*Integral univariate polynomial translation by 1.  A is a univariate
integral polynomial.  B(x)=A(x+1).*)
VAR   PAD: ARRAY[1..500] OF LIST;
VAR   AL, AL1, ALP, AP, B, CL, EL, FL, FLB, J1Y, J2Y, 
      NL, SL: LIST;
      ML, JL, HL, IL, KL, TL: INTEGER;
BEGIN
(*1*) (*degree zero.*) NL:=PDEG(A);
      IF NL = 0 THEN B:=A; RETURN(B); END;
(*2*) (*compute maximum coefficient length.*) FLB:=0; AP:=A;
      REPEAT AP:=RED(AP); ADV(AP, AL,AP); FL:=ILOG2(AL);
             IF FL > FLB THEN FLB:=FL; END;
             UNTIL AP = SIL;
(*3*) (*store coefficients in array.*) 
      KL:=INTEGER((FLB+NL+ZETA-1) DIV ZETA); ML:=KL*(INTEGER(NL)+1);
      IF ML > 500 THEN SWRITE("array PAD too small for IUPTR1");
         RETURN(0) END;
      AP:=A; IL:=1;
      FOR HL:=INTEGER(NL) TO 0 BY -1 DO
          IF AP = SIL THEN EL:=-1; ELSE EL:=FIRST(AP); END;
          IF INTEGER(EL) = HL THEN ADV2(AP, EL,AL,AP); ELSE AL:=0; END;
          ALP:=AL;
          IF ALP < BETA THEN ALP:=LIST1(ALP); END;
          FOR JL:=1 TO KL DO
              IF ALP <> SIL THEN ADV(ALP, AL1,ALP); ELSE AL1:=0; END;
              PAD[IL]:=AL1; IL:=IL+1; END;
          END;
(*4*) (*apply synthetic division.*)
      FOR HL:=INTEGER(NL) TO 1 BY -1 DO CL:=0; ML:=ML-KL;
          FOR IL:=1 TO ML DO 
              SL:=PAD[IL]+PAD[IL+KL]+CL; CL:=0;
              IF SL >= BETA THEN SL:=SL-BETA; CL:=1; ELSE
                 IF SL <= -BETA THEN SL:=SL+BETA; CL:=-1; END;
                 END;
              PAD[IL+KL]:=SL; END;
          END;
(*5*) (*convert b to normal form.*) B:=SIL; EL:=0; IL:=KL*INTEGER(NL);
      REPEAT AL:=BETA; JL:=KL;
             REPEAT SL:=PAD[IL+JL]; JL:=JL-1;
                    UNTIL (SL <> 0) OR (JL = 0);
             IF SL <> 0 THEN CL:=0; HL:=IL+1; JL:=JL+1;
                FOR TL:=1 TO JL DO AL1:=PAD[HL]+CL; CL:=0;
                    IF (SL > 0) AND (AL1 < 0) THEN AL1:=AL1+BETA;
                       CL:=-1; END;
                    IF (SL < 0) AND (AL1 > 0) THEN AL1:=AL1-BETA;
                       CL:=1; END;
                    AL:=COMP(AL1,AL); HL:=HL+1; END;
                WHILE FIRST(AL) = 0 DO AL:=RED(AL); END;
                IF RED(AL) = SIL THEN AL:=FIRST(AL); 
                   ELSE AL:=INV(AL); END;
                B:=COMP2(EL,AL,B); END;
             EL:=EL+1; IL:=IL-KL;
             UNTIL EL > NL;
      RETURN(B);
(*8*) END IUPTR1;


END SACIPOL.


(* -EOF- *)
