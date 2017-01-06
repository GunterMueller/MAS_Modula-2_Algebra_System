(* ----------------------------------------------------------------------------
 * $Id: SACMPOL.mi,v 1.3 1992/10/15 16:28:42 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACMPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:42  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:01  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:16  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACMPOL;

(* SAC Modular Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX;

FROM MASSTOR IMPORT LIST, SIL, BETA, SRED,
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT LIST2, COMP2, ADV2, FIRST2, 
                    CLOUT, CINV, RED2, SECOND, EQUAL;

FROM SACD IMPORT DQR, DRANN;

FROM SACM IMPORT SMFMI, MDRAN, MDQ, MDINV, MDHOM, 
                 MDSUM, MDPROD, MDDIF, MDNEG, MIPROD, 
                 MIINV, MISUM, MINEG, MIDIF, MIHOM, MIRAN;

FROM SACI IMPORT ISIGNF, ISUM, IPROD;

FROM SACPOL IMPORT PINV, PDEG, PLDCF, PRED, PLBCF; 

FROM SACIPOL IMPORT IPIPR, IPPROD;

CONST rcsidi = "$Id: SACMPOL.mi,v 1.3 1992/10/15 16:28:42 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE MIPDIF(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial difference.  M is a positive integer.
A and B are polynomials in r variables over Z sub M, r ge 0.  C=A-B.*)
VAR  AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=MIPNEG(RL,M,B); RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=MIDIF(M,A,B); RETURN(C); END;
(*3*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MINEG(M,BL); ELSE
                      CL:=MIPNEG(RLP,M,BL); END;
                   CP:=COMP2(CL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MIDIF(M,AL,BL); ELSE
                      CL:=MIPDIF(RLP,M,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF (AP = SIL) AND (BP = SIL) THEN CPP:=BETA; ELSE
         IF AP = SIL THEN CPP:=MIPNEG(RL,M,BP); ELSE CPP:=AP; END;
         END;
      C:=INV(CP);
      IF C = SIL THEN C:=CPP; ELSE SRED(CP,CPP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END MIPDIF;


PROCEDURE MIPFSM(RL,M,A: LIST): LIST;
(*Modular integral polynomial from symmetric modular.  M is a positive
integer.  A is a polynomial in r variables over Z prime sub M, r ge 0.
B belongs to Z sub M (x, ...,x sub r) with B=A (modulo M).*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN
         IF ISIGNF(A) < 0 THEN B:=ISUM(M,A); ELSE B:=A; END;
         RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP); BL:=MIPFSM(RLP,M,AL);
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END MIPFSM;


PROCEDURE MIPHOM(RL,M,A: LIST): LIST;
(*Modular integral polynomial homomorphism.  A is an integral
polynomial in r variables, r ge 0.  M is a positive integer.
B=H sub M (A), a polynomial in r variables over Z sub M.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=MIHOM(M,A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=MIHOM(M,AL); ELSE
                BL:=MIPHOM(RLP,M,AL); END;
             IF BL <> 0 THEN B:=COMP2(BL,EL,B); END;
             UNTIL AP = SIL;
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END;
      RETURN(B);
(*6*) END MIPHOM;


PROCEDURE MIPIPR(RL,M,D,A,B: LIST): LIST;
(*Modular integral polynomial mod ideal product.  D is a list (d sub
1, ...,d sub r-1) of non-negative beta-integers, r ge 1.  M is a
positive integer.  A and B belong to Z sub M (x sub 1, ...,x sub
r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1).  C=A*B.*)
VAR  C, CP: LIST;
BEGIN
(*1*) CP:=IPIPR(RL,D,A,B); C:=MIPHOM(RL,M,CP); RETURN(C);
(*4*) END MIPIPR;


PROCEDURE MIPNEG(RL,M,A: LIST): LIST;
(*Modular integral polynomial negation.  M is a positive integer.  A is
a polynomial in r variables over Z sub M, r ge 0.  B=-A.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=MINEG(M,A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=MINEG(M,AL); ELSE
                BL:=MIPNEG(RLP,M,AL); END;
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END MIPNEG;


PROCEDURE MIPPR(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial product.  M is a positive integer.  A and
B are polynomials in r variables over Z sub M, r ge 0.  C=A*B.*)
VAR  C, J1Y: LIST;
BEGIN
(*1*) J1Y:=IPPROD(RL,A,B); C:=MIPHOM(RL,M,J1Y); RETURN(C);
(*4*) END MIPPR;


PROCEDURE MIPRAN(RL,M,QL,N: LIST): LIST;
(*Modular integral polynomial, random.  M is a positive integer.  q is
a rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list
(n sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random polynomial in r variables over Z sub M with deg sub i of A le
n sub i for 1 le i le r.  q is the probability that any particular
term of A has a non-zero coefficient.*)
VAR  A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL: LIST;
BEGIN
(*1*) (*compute qls=int(ql*beta).*) FIRST2(QL, QL1,QL2);
      DQR(QL1,0,QL2, QLS,TL);
(*2*) (*rl=0.*)
      IF RL = 0 THEN DL:=DRANN();
         IF DL < QLS THEN A:=MIRAN(M); ELSE A:=0; END;
         RETURN(A); END;
(*3*) (*rl gt 0.*) RLP:=RL-1; ADV(N, NL,NP); A:=BETA;
      FOR EL:=0 TO NL DO
          IF RLP = 0 THEN DL:=DRANN();
             IF DL < QLS THEN AL:=MIRAN(M); ELSE AL:=0; END;
             ELSE AL:=MIPRAN(RLP,M,QL,NP); END;
          IF AL <> 0 THEN A:=COMP2(EL,AL,A); END;
          END;
      IF A = SIL THEN A:=0; END;
      RETURN(A);
(*6*) END MIPRAN;


PROCEDURE MIPSUM(RL,M,A,B: LIST): LIST;
(*Modular integral polynomial sum.  M is a positive integer.  A and B
are polynomials in r variables over Z sub M, r ge 0.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, CP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=MISUM(M,A,B); RETURN(C); END;
(*3*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   CP:=COMP2(BL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MISUM(M,AL,BL); ELSE
                      CL:=MIPSUM(RLP,M,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF AP = SIL THEN AP:=BP; END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END MIPSUM;


PROCEDURE MIUPQR(M,A,B: LIST;    VAR Q,R: LIST);
(*Modular integral univariate polynomial quotient and remainder.  M is
a positive integer.  A and B belong to Z sub M (x) with LDCF(B) a unit.
Q and R are the unique elements of Z sub M (x) such that A=B*Q+R with
either R=0 or DEG(R) lt DEG(B).*)
VAR  AL, BL, BLP, BP, DL, ML, NL, Q1, QL, QP, RP: LIST;
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BL:=PLDCF(B); BP:=PRED(B); Q:=BETA;
      R:=A; BLP:=MIINV(M,BL);
(*2*) (*compute quotient terms.*)
      WHILE R <> 0 DO ML:=PDEG(R); DL:=ML-NL;
            IF DL < 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            AL:=PLDCF(R); QL:=MIPROD(M,AL,BLP); Q:=COMP2(QL,DL,Q);
            Q1:=LIST2(DL,QL); RP:=PRED(R); QP:=MIPPR(1,M,BP,Q1);
            R:=MIPDIF(1,M,RP,QP); END;
(*3*) (*finish.*)
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
      RETURN;
(*6*) END MIUPQR;


PROCEDURE MMPIQR(RL,M,D,A,B: LIST;    VAR Q,R: LIST);
(*Modular monic polynomial mod ideal quotient and remainder.  M is a
positive integer.  D is a list (d sub 1, ...,d sub r-1) of non-nega-
tive beta-integers, r ge 1.  A and B belong to Z sub M(x sub 1, ...,x
sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1), with B
monic.  A=B*Q+R, deg sub y of R lt deg sub y of B unless B divides A,
in which case R=0, with Q,R belonging to Z sub M (x sub 1, ...,x sub
r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1).*)
VAR  AL, BP, DL, ML, NL, Q1, QP, RP: LIST;
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BP:=PRED(B); Q:=BETA; R:=A;
(*2*) (*compute quotient terms.*)
      WHILE R <> 0 DO ML:=PDEG(R); DL:=ML-NL;
            IF DL < 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            AL:=PLDCF(R); Q:=COMP2(AL,DL,Q); Q1:=LIST2(DL,AL);
            RP:=PRED(R); QP:=MIPIPR(RL,M,D,BP,Q1);
            R:=MIPDIF(RL,M,RP,QP); END;
(*3*) (*finish.*)
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
      RETURN;
(*6*) END MMPIQR;


PROCEDURE MPDIF(RL,ML,A,B: LIST): LIST;
(*Modular polynomial difference.  A and B are polynomials in r
variables over Z sub m, m a beta-integer.  C=A-B.*)
VAR  AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=MPNEG(RL,ML,B); RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MDNEG(ML,BL); ELSE
                      CL:=MPNEG(RLP,ML,BL); END;
                   CP:=COMP2(CL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MDDIF(ML,AL,BL); ELSE
                      CL:=MPDIF(RLP,ML,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*3*) (*finish.*)
      IF (AP = SIL) AND (BP = SIL) THEN CPP:=BETA; ELSE
         IF AP = SIL THEN CPP:=MPNEG(RL,ML,BP); ELSE CPP:=AP; END;
         END;
      C:=INV(CP);
      IF C = SIL THEN C:=CPP; ELSE SRED(CP,CPP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*6*) END MPDIF;


PROCEDURE MPEMV(RL,ML,A,AL: LIST): LIST;
(*Modular polynomial evaluation of main variable.  A is a polynomial in
r variables over Z sub m, m a beta-integer.  a is an element of
Z sub m.  B(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),a).*)
VAR  AL1, AP, B, EL1, EL2, IL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*apply horners method.*) ADV(A, EL1,AP); B:=0; RLP:=RL-1;
      REPEAT ADV(AP, AL1,AP);
             IF RLP = 0 THEN B:=MDSUM(ML,B,AL1); ELSE
                B:=MPSUM(RLP,ML,B,AL1); END;
             IF AP <> SIL THEN ADV(AP, EL2,AP); ELSE EL2:=0; END;
             FOR IL:=1 TO EL1-EL2 DO
                 IF RLP = 0 THEN B:=MDPROD(ML,AL,B); ELSE
                    B:=MPMDP(RLP,ML,AL,B); END;
                 END;
             EL1:=EL2;
             UNTIL AP = SIL;
      RETURN(B);
(*5*) END MPEMV;


PROCEDURE MPEVAL(RL,ML,A,IL,AL: LIST): LIST;
(*Modular polynomial evaluation.  A is a polynomial in r variables
over Z sub m, m a beta-integer.  1 le i le r.  a is an element of
Z sub m.  B(x(1), ...,x(i-1),x(i+1), ...,x(r))=
A(x(1), ...,x(i-1),a,x(i+1), ...,x(r)).*)
VAR  A1, AP, B, B1, EL1, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*il=rl.*)
      IF IL = RL THEN B:=MPEMV(RL,ML,A,AL); RETURN(B); END;
(*3*) (*il lt rl.*) RLP:=RL-1; AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL1,A1,AP); B1:=MPEVAL(RLP,ML,A1,IL,AL);
             IF B1 <> 0 THEN B:=COMP2(B1,EL1,B); END;
             UNTIL AP = SIL;
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END;
      RETURN(B);
(*6*) END MPEVAL;


PROCEDURE MPEXP(RL,ML,A,NL: LIST): LIST;
(*Modular polynomial exponentiation.  A is a polynomial in r variables
over Z sub m, m a beta-integer.  n is a non-negative integer.
B=A**n.*)
VAR  B, IL: LIST;
BEGIN
(*1*) (*nl=0.*)
      IF NL = 0 THEN B:=PINV(0,1,RL); RETURN(B); END;
(*2*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*3*) (*general case.*) B:=A;
      FOR IL:=1 TO NL-1 DO B:=MPPROD(RL,ML,B,A); END;
      RETURN(B);
(*6*) END MPEXP;


PROCEDURE MPHOM(RL,ML,A: LIST): LIST;
(*Modular polynomial homomorphism.  A is an integral polynomial in r
variables, r ge 0.  m is a positive beta-integer.  B is the image of
A under the homomorphism H sub m, a polynomial in r variables over
Z sub m.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=MDHOM(ML,A); RETURN(B); END;
(*3*) (*general case.*) RLP:=RL-1; AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=MDHOM(ML,AL); ELSE
                BL:=MPHOM(RLP,ML,AL); END;
             IF BL <> 0 THEN B:=COMP2(BL,EL,B); END;
             UNTIL AP = SIL;
      B:=INV(B);
      IF B = SIL THEN B:=0; END;
      RETURN(B);
(*6*) END MPHOM;


PROCEDURE MPINT(PL,B,BL,BLP,RL,A,A1: LIST): LIST;
(*Modular polynomial interpolation.  p is a prime beta-integer.  B is
a univariate polynomial over Z sub p.  b is an element of Z sub p
such that B(b) ne 0 and bp=B(b)**-1.  A is a polynomial over Z sub
p in r variables, r ge 1, with A=0 or the degree of A in x(1) less
than the degree of B.  A1 is a polynomial over Z sub p in r-1
variables.  AS(x(1), ...,x(r)) is the unique polynomial over Z sub
p such that AS(x(1), ...,x(r)) is congruent to A(x(1), ...,x(r))
modulo B(x(1)), AS(b,x(2), ...,x(r))=A1(x(2), ...,x(r)) and
the degree of AS in x(1) is less than or equal to the degree of B.*)
VAR  AL, AL1, ALS, AP, AP1, AS, CL, DL, EL, EL1, ELS, J1Y, NL, RLP:
     LIST;
BEGIN
(*1*) (*deg(b)=0.*) NL:=PDEG(B);
      IF NL = 0 THEN J1Y:=RL-1; AS:=PINV(J1Y,A1,1); RETURN(AS); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN AL:=MPEMV(1,PL,A,BL); DL:=MDDIF(PL,A1,AL);
         IF DL = 0 THEN AS:=A; ELSE CL:=MDPROD(PL,DL,BLP);
            J1Y:=MPMDP(1,PL,CL,B); AS:=MPSUM(1,PL,J1Y,A); END;
         RETURN(AS); END;
(*3*) (*rl gt 1.*) AS:=BETA; RLP:=RL-1;
      IF A = 0 THEN AP:=BETA; ELSE AP:=A; END;
      IF A1 = 0 THEN AP1:=BETA; ELSE AP1:=A1; END;
      WHILE (AP <> SIL) OR (AP1 <> SIL) DO
            IF AP = SIL THEN AL:=0; ADV2(AP1, ELS,AL1,AP1); ELSE
               IF AP1 = SIL THEN AL1:=0; ADV2(AP, ELS,AL,AP); ELSE
                  EL:=FIRST(AP); EL1:=FIRST(AP1); ELS:=MASMAX(EL,EL1);
                  AL:=0; AL1:=0;
                  IF EL = ELS THEN ADV2(AP, EL,AL,AP); END;
                  IF EL1 = ELS THEN ADV2(AP1, EL1,AL1,AP1); END;
                  END;
               END;
            ALS:=MPINT(PL,B,BL,BLP,RLP,AL,AL1); AS:=COMP2(ALS,ELS,AS);
            END;
      IF AS = SIL THEN AS:=0; ELSE AS:=INV(AS); END;
      RETURN(AS);
(*6*) END MPINT;


PROCEDURE MPMDP(RL,PL,AL,B: LIST): LIST;
(*Modular polynomial modular digit product.  a is an element of
Z sub p, p a prime beta-integer.  B is a polynomial in r variables
over Z sub p.  C=a*B.*)
VAR  BL, BP, C, CL, EL, RLP: LIST;
BEGIN
(*1*) (*c=0.*)
      IF (AL = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*general case.*) BP:=B; C:=BETA; RLP:=RL-1;
      REPEAT ADV2(BP, EL,BL,BP);
             IF RLP = 0 THEN CL:=MDPROD(PL,AL,BL); ELSE
                CL:=MPMDP(RLP,PL,AL,BL); END;
             C:=COMP2(CL,EL,C);
             UNTIL BP = SIL;
      C:=INV(C); RETURN(C);
(*5*) END MPMDP;


PROCEDURE MPMON(RL,PL,A: LIST): LIST;
(*Modular polynomial monic.  A is a polynomial in r variables over
Z sub p, p a prime beta-integer.  If A is non-zero then AP is
the polynomial similar to A with LBCF(AP)=1.  If A=0 then AP=0.*)
VAR  AL, ALP, AP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN AP:=0; RETURN(AP); END;
(*2*) (*a non-zero.*) AL:=PLBCF(RL,A); ALP:=MDINV(PL,AL);
      AP:=MPMDP(RL,PL,ALP,A); RETURN(AP);
(*5*) END MPMON;


PROCEDURE MPNEG(RL,ML,A: LIST): LIST;
(*Modular polynomial negative.  A is a polynomial in r variables over
Z sub m, m a beta-integer.  B=-A.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*a non-zero.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=MDNEG(ML,AL); ELSE
                BL:=MPNEG(RLP,ML,AL); END;
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END MPNEG;


PROCEDURE MPPROD(RL,ML,A,B: LIST): LIST;
(*Modular polynomial product.  A and B are polynomials in r variables
over Z sub m, m a beta-integer, r ge 0.  C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=MDPROD(ML,A,B); RETURN(C); END;
(*3*) (*general case.*) AS:=CINV(A); BS:=CINV(B); C:=0; RLP:=RL-1;
      REPEAT ADV2(BS, BL,FL,BS); AP:=AS; C1:=BETA;
             REPEAT ADV2(AP, AL,EL,AP);
                    IF RLP = 0 THEN CL:=MDPROD(ML,AL,BL); ELSE
                       CL:=MPPROD(RLP,ML,AL,BL); END;
                    IF CL <> 0 THEN J1Y:=EL+FL; C1:=COMP2(J1Y,CL,C1);
                       END;
                    UNTIL AP = SIL;
             IF C1 <> SIL THEN C:=MPSUM(RL,ML,C,C1); END;
             UNTIL BS = SIL;
      RETURN(C);
(*6*) END MPPROD;


PROCEDURE MPPSR(RL,PL,A,B: LIST): LIST;
(*Modular polynomial pseudo-remainder.  A and B are polynomials
in r variables over Z sub p, p a prime beta-integer,
with B non-zero.  C is the pseudo-remainder of A and B.*)
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
             C:=MPPROD(RL,PL,C,B1); J1Y:=LL-NL; C1:=LIST2(J1Y,CL);
             BS:=MPPROD(RL,PL,BB,C1); C:=MPDIF(RL,PL,C,BS); ELSE
             C:=MPPROD(RL,PL,C,B1); END;
          END;
      RETURN(C);
(*5*) END MPPSR;


PROCEDURE MPQ(RL,PL,A,B: LIST): LIST;
(*Modular polynomial quotient.  A and B are polynomials in r
variables over Z sub p, p a prime beta-integer, r ge 0.  B is a
non-zero divisor of A.  C=A/B.*)
VAR  C, R: LIST;
BEGIN
(*1*) IF RL = 0 THEN C:=MDQ(PL,A,B); ELSE MPQR(RL,PL,A,B, C,R); END;
      RETURN(C);
(*4*) END MPQ;


PROCEDURE MPQR(RL,PL,A,B: LIST;    VAR Q,R: LIST);
(*Modular polynomial quotient and remainder.  A and B are polynomials
un r variables over Z sub p, p a prime beta-integer, with B non-zero.
Q and R are the unique polynomials such that either B divides A, Q=A/B
and R=0 or else B does not divide A and A=BQ+R with DEG(R) minimal.*)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL: LIST;
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BL:=PLDCF(B); BP:=PRED(B); Q:=BETA;
      R:=A; RLP:=RL-1;
(*2*) (*compute quotient terms.*)
      WHILE R <> 0 DO ML:=PDEG(R); DL:=ML-NL;
            IF DL < 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            AL:=PLDCF(R);
            IF RLP = 0 THEN QL:=MDQ(PL,AL,BL); SL:=0; ELSE
               MPQR(RLP,PL,AL,BL, QL,SL); END;
            IF SL <> 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            Q:=COMP2(QL,DL,Q); Q1:=LIST2(DL,QL); RP:=PRED(R);
            QP:=MPPROD(RL,PL,BP,Q1); R:=MPDIF(RL,PL,RP,QP); END;
(*3*) (*finish.*)
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
      RETURN;
(*6*) END MPQR;


PROCEDURE MPRAN(RL,ML,QL,N: LIST): LIST;
(*Modular polynomial, random.  m is a positive beta-integer.  q is a
rational number q1/q2 with 0 lt q1 le q2 lt beta.  N is a list (n
sub r, ...,n sub 1) of non-negative beta-digits, r ge 0.  A is a
random polynomial in r variables over Z sub m with deg sub i of A le
n sub i for 1 le i le r.  q is the probability that any particular
term of A has a non-zero coefficient.*)
VAR  A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL: LIST;
BEGIN
(*1*) (*compute qls=int(ql*beta).*) FIRST2(QL, QL1,QL2);
      DQR(QL1,0,QL2, QLS,TL);
(*2*) (*rl=0.*)
      IF RL = 0 THEN DL:=DRANN();
         IF DL < QLS THEN A:=MDRAN(ML); ELSE A:=0; END;
         RETURN(A); END;
(*3*) (*rl gt 0.*) RLP:=RL-1; ADV(N, NL,NP); A:=BETA;
      FOR EL:=0 TO NL DO
          IF RLP = 0 THEN DL:=DRANN();
             IF DL < QLS THEN AL:=MDRAN(ML); ELSE AL:=0; END;
             ELSE AL:=MPRAN(RLP,ML,QL,NP); END;
          IF AL <> 0 THEN A:=COMP2(EL,AL,A); END;
          END;
      IF A = SIL THEN A:=0; END;
      RETURN(A);
(*6*) END MPRAN;


PROCEDURE MPSUM(RL,ML,A,B: LIST): LIST;
(*Modular polynomial sum.  A and B are polynomials in r variables over
Z sub m, m a beta-integer.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, CP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   CP:=COMP2(BL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=MDSUM(ML,AL,BL); ELSE
                      CL:=MPSUM(RLP,ML,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*3*) (*finish.*)
      IF AP = SIL THEN AP:=BP; END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*6*) END MPSUM;


PROCEDURE MPUP(RL,ML,CL,A: LIST): LIST;
(*Modular polynomial univariate product.  A is a polynomial in r
variables, r ge 1, over Z sub m, m a positive beta-integer.  c is a
univariate polynomial over Z sub m.  B(x(1), ...,x(r)) =
c(x(1))*A(x(1), ...,x(r)).*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*cl=0 or a=0.*)
      IF (CL = 0) OR (A = 0) THEN B:=0; RETURN(B); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN B:=MPPROD(RL,ML,CL,A); RETURN(B); END;
(*3*) (*general case.*) RLP:=RL-1; AP:=A; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); BL:=MPUP(RLP,ML,CL,AL);
             IF BL <> 0 THEN B:=COMP2(BL,EL,B); END;
             UNTIL AP = SIL;
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END;
      RETURN(B);
(*6*) END MPUP;


PROCEDURE MPUQ(RL,PL,A,BL: LIST): LIST;
(*Modular polynomial univariate quotient.  A is a polynomial in r
variables, r ge 2, over Z sub p, p a prime beta-integer.  b is a
non-zero univariate polynomial over Z sub p which divides A.
C(x(1), ...,x(r))=A(x(1), ...,x(r))/b(x(1)).*)
VAR  AL, AP, C, CL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*a non-zero.*) AP:=A; RLP:=RL-1; C:=BETA;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 1 THEN CL:=MPQ(RLP,PL,AL,BL); ELSE
                CL:=MPUQ(RLP,PL,AL,BL); END;
             C:=COMP2(CL,EL,C);
             UNTIL AP = SIL;
      C:=INV(C); RETURN(C);
(*5*) END MPUQ;


PROCEDURE MUPDER(ML,A: LIST): LIST;
(*Modular univariate polynomial derivative.  m is a beta-integer.  A
is a univariate polynomial over Z sub m.  B is the derivative of A, a
univariate polynomial over Z sub m.*)
VAR  AL, AP, B, EL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*a ne 0.*) B:=BETA; AP:=A;
      REPEAT ADV2(AP, EL,AL,AP); AL:=MDPROD(ML,EL,AL);
             IF AL <> 0 THEN EL:=EL-1; B:=COMP2(AL,EL,B); END;
             UNTIL AP = SIL;
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END;
      RETURN(B);
(*5*) END MUPDER;


PROCEDURE MUPRAN(PL,NL: LIST): LIST;
(*Modular univariate polynomial, random.  A is a random univariate
polynomial of degree n over Z(p).*)
VAR  A, AL, IL, J1Y: LIST;
BEGIN
(*1*) A:=BETA;
      FOR IL:=0 TO NL-1 DO AL:=MDRAN(PL);
          IF AL <> 0 THEN A:=COMP2(IL,AL,A); END;
          END;
      J1Y:=PL-1; J1Y:=MDRAN(J1Y); AL:=J1Y+1; A:=COMP2(NL,AL,A);
      RETURN(A);
(*4*) END MUPRAN;


PROCEDURE SMFMIP(RL,M,A: LIST): LIST;
(*Symmetric modular from modular integral polynomial.  M is a positive
integer.  A is a polynomial in r variables over Z sub M, r ge 0.  B
belongs to Z prime sub M (x1, ...,x sub r) with B=A (modulo M).*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=SMFMI(M,A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=SMFMI(M,AL); ELSE
                BL:=SMFMIP(RLP,M,AL); END;
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END SMFMIP;


PROCEDURE VMPIP(RL,ML,A,B: LIST): LIST;
(*Vector of modular polynomial inner product.  A and B are vectors of
modular polynomials in r variables over Z sub m, r non-negative, m
a beta-integer.  C is the inner product of A and B.*)
VAR  AL, AP, BL, BP, CL, J1Y: LIST;
BEGIN
(*1*) (*a=0 or b=0.*) CL:=0;
      IF (A = 0) OR (B = 0) THEN RETURN(CL); END;
(*2*) (*general case.*) AP:=A; BP:=B;
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP);
             IF RL = 0 THEN J1Y:=MDPROD(ML,AL,BL);
                CL:=MDSUM(ML,CL,J1Y); ELSE J1Y:=MPPROD(RL,ML,AL,BL);
                CL:=MPSUM(RL,ML,CL,J1Y); END;
             UNTIL AP = SIL;
      RETURN(CL);
(*5*) END VMPIP;


END SACMPOL.


(* -EOF- *)
