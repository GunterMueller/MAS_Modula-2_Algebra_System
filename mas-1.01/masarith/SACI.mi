(* ----------------------------------------------------------------------------
 * $Id: SACI.mi,v 1.4 1995/11/05 08:44:29 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACI.mi,v $
 * Revision 1.4  1995/11/05 08:44:29  kredel
 * Preparation for 64 bit integers.
 *
 * Revision 1.3  1992/10/15  16:28:18  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:12  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:40  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACI;

(* SAC Integer Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT MASEVEN, MASQREM, MASSIGN, MASABS, MASODD, MASEXP;


FROM MASBIOS IMPORT CREAD, CREADB, CWRITE,
                    SWRITE, BLINES, MASORD, DIGIT, BKSP, 
                    DIBUFF;


FROM MASSTOR IMPORT BETA, SIL, LIST, 
                    COMP, ADV, FIRST, RED, SFIRST, SRED,
                    LENGTH, INV, LIST1;


FROM SACLIST IMPORT LAST, CONC, CINV, 
                    ADV2, FIRST2, LIST2, LIST3, LIST10,
                    OWRITE, AWRITE;


FROM SACD IMPORT TABP2, ZETA, THETA, ETA,
                 DPR, DQR, DGCD, DPCC, DEGCD, DRAN, DSQRTF,
                 DLOG2;

CONST rcsidi = "$Id: SACI.mi,v 1.4 1995/11/05 08:44:29 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


    
PROCEDURE AADV(L: LIST; VAR AL,LP: LIST);
(*Arithmetic advance.  L is a list.  If L ne () then a=FIRST(L) and
LP=RED(L).  Otherwise a=0 and LP=().*)
BEGIN
(*1*) IF L <> SIL THEN ADV(L,AL,LP); ELSE AL:=0; LP:=BETA; END;
      RETURN;
(*4*) END AADV;


PROCEDURE IABSF(A: LIST): LIST;
(*Integer absolute value function.  A is an integer.  B=ABS(A).*)
VAR  B, SL: LIST;
BEGIN
(*1*) SL:=ISIGNF(A);
      IF SL >= 0 THEN B:=A; ELSE B:=INEG(A); END;
      RETURN(B);
(*4*) END IABSF;


PROCEDURE ICOMP(A,B: LIST): LIST;
(*Integer comparison.  A and B are integers.  s=SIGN(A-B).*)
VAR  AL, AP, BL, BP, DL, J1Y, SL, UL, VL: LIST;
BEGIN
(*1*) (*a and b single-precision.*)
      IF (A < BETA) AND (B < BETA) THEN J1Y:=A-B; SL:=MASSIGN(J1Y);
         RETURN(SL); END;
(*2*) (*a single-precision.*)
      IF A < BETA THEN J1Y:=ISIGNF(B); SL:=-J1Y; RETURN(SL); END;
(*3*) (*b single-precision.*)
      IF B < BETA THEN SL:=ISIGNF(A); RETURN(SL); END;
(*4*) (*compare corresponding digits.*) SL:=0; AP:=A; BP:=B;
      REPEAT ADV(AP,AL,AP); ADV(BP,BL,BP); UL:=MASSIGN(AL); VL:=MASSIGN(BL);
             IF UL*VL = -1 THEN SL:=UL; RETURN(SL); END;
             DL:=AL-BL;
             IF DL <> 0 THEN SL:=MASSIGN(DL); END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*5*) (*same length$*)
      IF (AP = SIL) AND (BP = SIL) THEN RETURN(SL); END;
(*6*) (*use sign of longer input.*)
      IF AP = SIL THEN J1Y:=ISIGNF(BP); SL:=-J1Y; ELSE
         SL:=ISIGNF(AP); END;
      RETURN(SL);
(*9*) END ICOMP;


PROCEDURE IDEGCD(AL,BL: LIST; VAR CL,UL1,VL1,UL2,VL2: LIST);
(*Integer doubly extended greatest common divisor algorithm.  a and b
are integers.  c=GCD(a,b).  a*u1+b*v1=c and a*u2+b*v2=0.
If a ne 0 and b ne 0 then ABS(u1) le ABS(b)/(2*c), ABS(v1) le
ABS(a)/(2*c), u2=-b/c and v2=a/c.  Otherwise u1=v2=SIGN(a),
v1=SIGN(b) and u2=-SIGN(b).*)
VAR  J1Y: LIST;
BEGIN
(*1*) IEGCD(AL,BL,CL,UL1,VL1);
      IF CL = 0 THEN UL2:=0; VL2:=0; ELSE J1Y:=IQ(BL,CL);
         UL2:=INEG(J1Y); VL2:=IQ(AL,CL); END;
      RETURN;
(*4*) END IDEGCD;


PROCEDURE IDIF(A,B: LIST): LIST;
(*Integer difference.  A and B are integers.  C=A-B.*)
VAR  BP, C: LIST;
BEGIN
(*1*) BP:=INEG(B); C:=ISUM(A,BP); RETURN(C);
(*4*) END IDIF;


PROCEDURE IDIPR2(A,B,AL,BL: LIST): LIST;
(*Integer digit inner product, length 2.  A and B are integers.
a and b are beta-integers.  C=A*a+B*b.*)
VAR  C, J1Y, J2Y: LIST;
BEGIN
(*1*) J1Y:=IDPR(A,AL); J2Y:=IDPR(B,BL); C:=ISUM(J1Y,J2Y); RETURN(C);
(*4*) END IDIPR2;


PROCEDURE IDPR(A,BL: LIST): LIST;
(*Integer-digit product.  A is an integer.  b is a beta-digit.
C=A*b.*)
VAR  AL, AP, C, CL, CLP, EL, FL: LIST;
BEGIN
(*1*) (*a or bl zero$*)
      IF (A = 0) OR (BL = 0) THEN C:=0; RETURN(C); END;
(*2*) (*a single-precision$*)
      IF A < BETA THEN DPR(A,BL,EL,FL);
         IF EL = 0 THEN C:=FL; ELSE C:=LIST2(FL,EL); END;
         RETURN(C); END;
(*3*) (*a multiple-precision.*) AP:=A; C:=BETA; CLP:=0;
      REPEAT ADV(AP,AL,AP); DPR(AL,BL,EL,FL); CL:=FL+CLP; CLP:=EL;
             IF CL >= BETA THEN CL:=CL-BETA; CLP:=CLP+1; ELSE
                IF CL <= -BETA THEN CL:=CL+BETA; CLP:=CLP-1; END;
                END;
             C:=COMP(CL,C);
             UNTIL AP = SIL;
      IF CLP <> 0 THEN C:=COMP(CLP,C); END;
      C:=INV(C); RETURN(C);
(*6*) END IDPR;


PROCEDURE IDP2(A,KL: LIST): LIST;
(*Integer division by power of 2.  A is an integer.  k is a
non-negative beta-digit.  B is the integral part of A/2**k.*)
VAR  B, J1Y, QL, RL: LIST;
BEGIN
(*1*) (*a=0 or kl=0.*)
      IF (A = 0) OR (KL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) QL:=KL DIV ZETA; J1Y:=QL*ZETA; RL:=KL-J1Y; B:=A;
      IF B < BETA THEN B:=LIST1(B); END;
      WHILE (QL > 0) AND (B <> SIL) DO B:=RED(B); QL:=QL-1; END;
      IF B = SIL THEN B:=0; RETURN(B); END;
      IF RED(B) = SIL THEN B:=FIRST(B); END;
      B:=IDQ(B,TABP2[INTEGER(RL+1)]); RETURN(B);
(*5*) END IDP2;


PROCEDURE IDQ(A,BL: LIST): LIST;
(*Integer-digit quotient.  A is an integer.  b is a non-zero
beta-digit.  C=INTEGER(A/b).*)
VAR  C, RL: LIST;
BEGIN
(*1*) IDQR(A,BL,C,RL); RETURN(C);
(*4*) END IDQ;


PROCEDURE IDQR(A,BL: LIST; VAR Q,RL: LIST);
(*Integer-digit quotient and remainder.  A is an integer.  b is a
non-zero beta-digit.  Q is the integral part of A/b and r=A-b*Q.*)
VAR  AL0, AP, J1Y, QL: LIST;
BEGIN
(*1*) (*a single-precision.*)
      IF A < BETA THEN Q:=A DIV BL; J1Y:=BL*Q; RL:=A-J1Y; RETURN; END;
(*2*) (*a multiple-precision.*) AP:=CINV(A); Q:=SIL; RL:=0;
      REPEAT ADV(AP,AL0,AP); DQR(RL,AL0,BL,QL,RL);
             IF (QL <> 0) OR (Q <> SIL) THEN Q:=COMP(QL,Q); END;
             UNTIL AP = SIL;
      IF RED(Q) = SIL THEN Q:=FIRST(Q); END;
      RETURN;
(*5*) END IDQR;


PROCEDURE IDREM(A,BL: LIST): LIST;
(*Integer-digit remainder.  A is an integer.  b is a non-zero
beta-digit.  r=A-b*INTEGER(A/b).*)
VAR  Q, RL: LIST;
BEGIN
(*1*) IDQR(A,BL,Q,RL); RETURN(RL);
(*4*) END IDREM;


PROCEDURE IEGCD(AL,BL: LIST; VAR CL,UL1,VL1: LIST);
(*Integer extended greatest common divisor algorithm.  a and b are
integers.  c=GCD(a,b).  a*u1+b*v1=c.  If a ne 0 and b ne 0
then ABS(u1) le ABS(b)/(2*c) and ABS(v1) le ABS(a)/(2*c).
Otherwise u1=SIGN(a) and v1=SIGN(b).*)
VAR  J1Y: LIST;
BEGIN
(*1*) IHEGCD(AL,BL,CL,VL1);
      IF AL = 0 THEN UL1:=0; ELSE J1Y:=IPROD(BL,VL1);
         J1Y:=IDIF(CL,J1Y); UL1:=IQ(J1Y,AL); END;
      RETURN;
(*4*) END IEGCD;


PROCEDURE IEVEN(A: LIST): BOOLEAN;
(*Integer even.  A is an integer.  If A is even then true is returned 
and otherwise false. *)
VAR  J1Y: LIST;
     TL: BOOLEAN;
BEGIN
(*1*) IF A < BETA THEN TL:=MASEVEN(A); ELSE J1Y:=FIRST(A);
         TL:=MASEVEN(J1Y); END;
      RETURN(TL);
(*4*) END IEVEN;


PROCEDURE IEXP(A,NL: LIST): LIST;
(*Integer exponentiation.  A is an integer.  n is a non-negative
beta-integer.  B=A**n.*)
VAR  B, KL: LIST;
BEGIN
(*1*) (*nl less than or equal to 1.*)
      IF NL = 0 THEN B:=1; RETURN(B); END;
      IF NL = 1 THEN B:=A; RETURN(B); END;
(*2*) (*recursion.*) KL:=NL DIV 2; B:=IEXP(A,KL); B:=IPROD(B,B);
      IF NL > 2*KL THEN B:=IPROD(B,A); END;
      RETURN(B);
(*5*) END IEXP;



PROCEDURE IFCL2(AL: LIST; VAR ML,NL: LIST);
(*Integer, floor and ceiling, logarithm, base 2.  a is a non-zero
integer.  m and n, gamma-integers, are the floor and ceiling of
LOG2(ABS(a)) respectively.*)
VAR  AL1, ALP, RL, TL: LIST;
BEGIN
(*1*) (*process beta-digits.*) TL:=0;
      IF AL < BETA THEN AL1:=AL; ML:=0; ELSE ALP:=AL; ML:=-ZETA;
         REPEAT ADV(ALP,AL1,ALP); ML:=ML+ZETA;
                IF (ALP <> SIL) AND (AL1 <> 0) THEN TL:=1; END;
                UNTIL ALP = SIL;
         END;
(*2*) (*process leading digits.*)
      IF AL1 < 0 THEN AL1:=-AL1; END;
      WHILE AL1 <> 1 DO MASQREM(AL1,2,AL1,RL);
            IF RL <> 0 THEN TL:=1; END;
            ML:=ML+1; END;
(*3*) (*finish.*) NL:=ML+TL; RETURN;
(*6*) END IFCL2;


PROCEDURE IGCD(A,B: LIST): LIST;
(*Integer greatest common divisor.  A and B are integers.  C=GCD(A,B).*)
VAR  A1, A2, A3, A4, AL, BL, C, HL, ML1, ML2, UL1, UL2, VL1,
     VL2: LIST;
BEGIN
(*1*) (*compute absolute values and compare.*) A1:=IABSF(A);
      A2:=IABSF(B);
      IF ICOMP(A1,A2) < 0 THEN A3:=A1; A1:=A2; A2:=A3; END;
(*2*) (*compute remainders.*)
      WHILE A2 <> 0 DO
            IF A1 < BETA THEN C:=DGCD(A1,A2); RETURN(C); END;
            ML1:=ILOG2(A1); ML2:=ILOG2(A2);
            IF (ML1-ML2) >= (ZETA DIV 2) THEN A4:=IREM(A1,A2); A3:=A2; ELSE
               HL:=ML1-ZETA; AL:=ITRUNC(A1,HL); BL:=ITRUNC(A2,HL);
               DPCC(AL,BL,UL1,UL2,VL1,VL2);
               IF VL1 = 0 THEN A4:=IREM(A1,A2); A3:=A2; ELSE
                  A3:=ILCOMB(A1,A2,UL1,VL1); A4:=ILCOMB(A1,A2,UL2,VL2);
                  END;
               END;
            A1:=A3; A2:=A4; END;
      C:=A1; RETURN(C);
(*5*) END IGCD;


PROCEDURE IGCDCF(A,B: LIST; VAR C,AB,BB: LIST);
(*Integer greatest common divisor and cofactors.  A and B are integers.
C eq GCD(A,B).  If C eq 0 then AB eq BB eq 0 and otherwise
AB eq A/C,BB eq B/C.*)
BEGIN
(*1*) C:=IGCD(A,B);
      IF (C = 0) OR (C = 1) THEN AB:=A; BB:=B; ELSE AB:=IQ(A,C);
         BB:=IQ(B,C); END;
      RETURN;
(*4*) END IGCDCF;


PROCEDURE IHEGCD(A,B: LIST; VAR C,V: LIST);
(*Integer half-extended greatest common divisor.  A and B are integers.
C=GCD(A,B).  If A ne 0, B*V=C(mod A), with ABS(V) le ABS(A)/2C.  If
A=0,V=SIGN(B).*)
VAR  A1, A2, A3, A4, AL, BL, HL, J1Y, ML1, ML2, Q, SL, UL1, UL2,
     V1, V2, V3, V4, VL1, VL2: LIST;
BEGIN
(*1*) (*compute absolute values and compare, and prepare v1, v2.*)
      A1:=IABSF(A); SL:=ISIGNF(B);
      IF SL < 0 THEN A2:=INEG(B); ELSE A2:=B; END;
      IF ICOMP(A1,A2) < 0 THEN A3:=A1; A1:=A2; A2:=A3; V1:=SL; V2:=0;
         ELSE V1:=0; V2:=SL; END;
(*2*) (*compute r emainder and cosequence.*)
      WHILE A2 <> 0 DO
            IF A1 <= BETA THEN DEGCD(A1,A2,C,UL1,VL1);
               V:=IDIPR2(V1,V2,UL1,VL1); RETURN; END;
            ML1:=ILOG2(A1); ML2:=ILOG2(A2);
            IF (ML1-ML2) >= (ZETA DIV 2) THEN IQR(A1,A2,Q,A4); A3:=A2;
               V3:=V2;
               J1Y:=IPROD(V2,Q); V4:=IDIF(V1,J1Y); ELSE HL:=ML1-ZETA;
               AL:=ITRUNC(A1,HL); BL:=ITRUNC(A2,HL);
               DPCC(AL,BL,UL1,UL2,VL1,VL2);
               IF VL1 = 0 THEN IQR(A1,A2,Q,A4); A3:=A2; V3:=V2;
                  J1Y:=IPROD(V2,Q); V4:=IDIF(V1,J1Y); ELSE
                  A3:=ILCOMB(A1,A2,UL1,VL1); A4:=ILCOMB(A1,A2,UL2,VL2);
                  V3:=IDIPR2(V1,V2,UL1,VL1); V4:=IDIPR2(V1,V2,UL2,VL2);
                  END;
               END;
            A1:=A3; A2:=A4; V1:=V3; V2:=V4; END;
      C:=A1; V:=V1; RETURN;
(*5*) END IHEGCD;


PROCEDURE ILCM(A,B: LIST): LIST;
(*Integer least common multiple.  A and B are integers.
C=LCM(A,B), a nonnegative integer.*)
VAR  AP, APP, BP, C, CP: LIST;
BEGIN
(*1*) (*a or b eq 0.*) AP:=IABSF(A); BP:=IABSF(B);
      IF AP = 0 THEN C:=BP; RETURN(C); ELSE
         IF BP = 0 THEN C:=AP; RETURN(C); END;
         END;
(*2*) (*a and b nonzero.*) CP:=IGCD(AP,BP); APP:=IQ(AP,CP);
      C:=IPROD(APP,BP); RETURN(C);
(*5*) END ILCM;


PROCEDURE ILCOMB(A,B,UL,VL: LIST): LIST;
(*Integer linear combination.  A and B are non-negative integers.
u and v are beta-integers such that A*u+B*v ge 0.  C=A*u+B*v.*)
VAR  AB, AL, AL0, AL1, BB, BL, BL0, BL1, C, CL0, CL1: LIST;
BEGIN
(*1*) (*convert to lists.*)
      IF A > BETA THEN AB:=A; ELSE AB:=LIST1(A); END;
      IF B > BETA THEN BB:=B; ELSE BB:=LIST1(B); END;
(*2*) (*multiply and add.*) C:=BETA; CL1:=0;
      REPEAT AADV(AB,AL,AB); AADV(BB,BL,BB); DPR(AL,UL,AL1,AL0);
             DPR(BL,VL,BL1,BL0); CL0:=AL0+BL0; CL0:=CL0+CL1;
             CL1:=AL1+BL1;
             WHILE CL0 < 0 DO CL0:=CL0+BETA; CL1:=CL1-1; END;
             IF CL0 >= BETA THEN CL0:=CL0-BETA; CL1:=CL1+1; END;
             C:=COMP(CL0,C);
             UNTIL (AB = SIL) AND (BB = SIL);
      IF CL1 <> 0 THEN C:=COMP(CL1,C); END;
(*3*) (*normalize.*)
      WHILE (C <> SIL) AND (FIRST(C) = 0) DO C:=RED(C); END;
      IF C = SIL THEN C:=0; ELSE
         IF RED(C) = SIL THEN C:=FIRST(C); ELSE C:=INV(C); END;
         END;
      RETURN(C);
(*6*) END ILCOMB;


PROCEDURE ILOG2(A: LIST): LIST;
(*Integer logarithm, base 2.  A is an integer.  If A=0 then n=0.
Otherwise n=FLOOR(LOG2(ABS(A)))+1, a beta-integer.*)
VAR  AP, J1Y, NL: LIST;
BEGIN
(*1*) (*a single-precision.*)
      IF A < BETA THEN NL:=DLOG2(A); RETURN(NL); END;
(*2*) (*a multiple-precision.*) AP:=A; NL:=0;
      WHILE RED(AP) <> SIL DO AP:=RED(AP); NL:=NL+ZETA; END;
      J1Y:=FIRST(AP); J1Y:=DLOG2(J1Y); NL:=NL+J1Y; RETURN(NL);
(*5*) END ILOG2;


PROCEDURE ILWRIT(L: LIST);
(*Integer list write.  L is a list of integers.  The list L is written
in the output stream.*)
VAR  AL, LP: LIST;
BEGIN
(*1*) LP:=L; SWRITE("(");
      WHILE LP <> SIL DO ADV(LP,AL,LP); IWRITE(AL);
            IF LP <> SIL THEN SWRITE(","); END;
            END;
      SWRITE(")"); RETURN;
(*4*) END ILWRIT;


PROCEDURE IMAX(AL,BL: LIST): LIST;
(*Integer maximum.  a and b are integers.  c is the maximum of a
and b.*)
VAR  CL, SL: LIST;
BEGIN
(*1*) SL:=ICOMP(AL,BL);
      IF SL >= 0 THEN CL:=AL; ELSE CL:=BL; END;
      RETURN(CL);
(*4*) END IMAX;


PROCEDURE IMIN(AL,BL: LIST): LIST;
(*Integer minimum.  a and b are integers.  c is the minimum of a
and b.*)
VAR  CL, SL: LIST;
BEGIN
(*1*) SL:=ICOMP(AL,BL);
      IF SL <= 0 THEN CL:=AL; ELSE CL:=BL; END;
      RETURN(CL);
(*4*) END IMIN;


PROCEDURE IMP2(A,HL: LIST): LIST;
(*Integer multiplication by power of 2.  A is an integer.  h is a
non-negative beta-integer.  B=A*(2**h).*)
VAR  B, IL, J1Y, QL, RL: LIST;
BEGIN
(*1*) (*a=0 or hl=0.*)
      IF (A = 0) OR (HL = 0) THEN B:=A; RETURN(B); END;
(*2*) (*general case.*) QL:=HL DIV ZETA; J1Y:=QL*ZETA; RL:=HL-J1Y;
      B:=IDPR(A,TABP2[INTEGER(RL+1)]);
      IF QL <> 0 THEN
         IF B < BETA THEN B:=LIST1(B); END;
         FOR IL:=1 TO QL DO B:=COMP(0,B); END;
         END;
      RETURN(B);
(*5*) END IMP2;


PROCEDURE INEG(A: LIST): LIST;
(*Integer negation.  A is an integer.  B=-A.*)
VAR  AL, AP, B, BL: LIST;
BEGIN
(*1*) (*a single-precision.*)
      IF A < BETA THEN B:=-A; RETURN(B); END;
(*2*) (*a multiple-precision.*) B:=BETA; AP:=A;
      REPEAT ADV(AP,AL,AP); BL:=-AL; B:=COMP(BL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END INEG;


PROCEDURE IODD(A: LIST): BOOLEAN;
(*Integer odd.  A is an integer.  If a is odd then true is returned
and otherwise false. *)
VAR  J1Y: LIST;
     TL: BOOLEAN;
BEGIN
(*1*) IF A < BETA THEN TL:=MASODD(A); ELSE J1Y:=FIRST(A); TL:=MASODD(J1Y);
         END;
      RETURN(TL);
(*4*) END IODD;


PROCEDURE IORD2(AL: LIST): LIST;
(*Integer, order of 2.  a is a non-zero integer.  n is the largest
integer such that 2**n divides a.*)
VAR  AL1, ALP, J1Y, NL, QL, RL: LIST;
BEGIN
(*1*) (*count low-order beta-digits.*)
      IF AL < BETA THEN NL:=-1; AL1:=AL; ELSE J1Y:=-ZETA; NL:=J1Y-1;
         ALP:=AL;
         REPEAT ADV(ALP,AL1,ALP); NL:=NL+ZETA;
                UNTIL AL1 <> 0;
         END;
(*2*) (*count low-order bits.*)
      REPEAT MASQREM(AL1,2,QL,RL); AL1:=QL; NL:=NL+1;
             UNTIL RL <> 0;
      RETURN(NL);
(*5*) END IORD2;


PROCEDURE IPOWER(A,L: LIST; VAR B,NL: LIST);
(*Integer power.  A, greater than or equal to 3, is an odd positive
integer.  L is a list (p(1),p(2), ...,p(k)) of the first k prime
numbers, with p(k) greater than or equal to the base 3 logarithm of A.
If A=B**m for some m greater than or equal to 2 then n is the least
such m and B=A**(1/n).  Otherwise B=0 and n=0.*)
VAR  J1Y, LP, N, TL: LIST;
BEGIN
(*1*) (*compute bound on nl.*) N:=ILOG2(A); J1Y:=7*N; N:=J1Y DIV 11;
(*2*) (*apply iroot.*) LP:=L;
      WHILE LP <> SIL DO ADV(LP,NL,LP);
            IF NL > N THEN (*go to 3;*)
               B:=0; NL:=0; RETURN;
               END;
            IROOT(A,NL,B,TL);
            IF TL = 0 THEN RETURN; END;
            END;
(*3*) (*non-power.*) B:=0; NL:=0; RETURN;
(*6*) END IPOWER;


PROCEDURE IPROD(A,B: LIST): LIST;
(*Integer product.  A and B are integers.  C=A*B.*)
VAR  AL, AP, APP, BL, BP, C, C2, CL, CLP, CP, CPP, EL, FL, I, ML, NL,
     TL: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*a and b single-precision.*)
      IF (A < BETA) AND (B < BETA) THEN DPR(A,B,CLP,CL);
         IF CLP = 0 THEN C:=CL; ELSE C:=LIST2(CL,CLP); END;
         RETURN(C); END;
(*3*) (*a or b single-precision.*)
      IF A < BETA THEN C:=IDPR(B,A); RETURN(C); END;
      IF B < BETA THEN C:=IDPR(A,B); RETURN(C); END;
(*4*) (*interchange if b is longer.*) ML:=LENGTH(A); NL:=LENGTH(B);
      IF ML >= NL THEN AP:=A; BP:=B; ELSE AP:=B; BP:=A; END;
(*5*) (*set product to zero.*) C2:=LIST2(0,0); C:=C2;
      FOR I:=1 TO ML+NL-2 DO C:=COMP(0,C); END;
(*6*) (*multiply digits and add products.*) CP:=C;
      REPEAT APP:=AP; ADV(BP,BL,BP);
             IF BL <> 0 THEN CPP:=CP; CLP:=0;
                REPEAT ADV(APP,AL,APP); DPR(AL,BL,EL,FL);
                       CL:=FIRST(CPP); CL:=CL+FL; CL:=CL+CLP;
                       CLP:=CL DIV BETA; TL:=CLP*BETA; CL:=CL-TL;
                       SFIRST(CPP,CL); CLP:=EL+CLP; CPP:=RED(CPP);
                       UNTIL APP = SIL;
                SFIRST(CPP,CLP); END;
             CP:=RED(CP);
             UNTIL BP = SIL;
(*7*) (*leading digit zero$*)
      IF CLP = 0 THEN SRED(C2,SIL); END;
      RETURN(C);
(*10*) END IPROD;


PROCEDURE IPRODK(A,B: LIST): LIST;
(*Integer product, Karatsuba algorithm.  A and B are integers.  C=A*B.*)
VAR  A0, A1, AP, AS, B0, B1, BP, BS, C, C0, C1, C2, CH, CS, KL, L, ML,
     NL, TL: LIST;
BEGIN
(*1*) (*a or b single-precision.*)
      IF (A < BETA) OR (B < BETA) THEN C:=IPROD(A,B); RETURN(C);
      END;
(*2*) (*compute lengths, ml and nl, ml ge nl.*) ML:=LENGTH(A);
      NL:=LENGTH(B);
      IF ML >= NL THEN AP:=A; BP:=B; ELSE AP:=B; BP:=A; TL:=ML;
         ML:=NL; NL:=TL; END;
(*3*) (*use classical algorithm if nl is small.*)
      IF NL < 16 THEN C:=IPROD(AP,BP); RETURN(C); END;
(*4*) (*ml ge 2*nl.*)
      IF ML >= 2*NL THEN L:=BETA;
         REPEAT ISEG(AP,NL,AP,A0); C0:=IPRODK(A0,BP); L:=COMP(C0,L);
                UNTIL AP = 0;
         L:=INV(L); C:=ISSUM(NL,L); RETURN(C); END;
(*5*) (*nl le ml lt 2*nl.*) KL:=ML DIV 2;
      IF ML > KL+KL THEN KL:=KL+1; END;
      ISEG(AP,KL,A1,A0); ISEG(BP,KL,B1,B0); AS:=ISUM(A1,A0);
      BS:=ISUM(B1,B0); C2:=IPRODK(A1,B1); C0:=IPRODK(A0,B0);
      CS:=IPRODK(AS,BS); CH:=ISUM(C0,C2); C1:=IDIF(CS,CH);
      L:=LIST3(C0,C1,C2); C:=ISSUM(KL,L); RETURN(C);
(*8*) END IPRODK;


PROCEDURE IQ(A,B: LIST): LIST;
(*Integer quotient.  A and B are integers, B ne 0.  C is the integral
part of A/B.*)
VAR  C, R: LIST;
BEGIN
(*1*) IQR(A,B,C,R); RETURN(C);
(*4*) END IQ;


PROCEDURE IQR(A,B: LIST; VAR Q,R: LIST);
(*Integer quotient and remainder.  A and B are integers, B ne 0.  Q is
the quotient, integral part of A/B, and R is the remainder A-B*Q.*)
VAR  AH, AL, AL0, AL1, AL2, AP, APP, APPP, AS, BL, BL0, BL1, BP, BPP,
     BS, CL, CL0, CL1, CL2, CLP1, DL, IL, J1Y, ML, NL, QL, RL, SL, T,
     TL, UL: LIST;
BEGIN
(*1*) (*b single-precision.*)
      IF B < BETA THEN IDQR(A,B,Q,R); RETURN; END;
(*2*) (*a single-precision.*)
      IF A < BETA THEN Q:=0; R:=A; RETURN; END;
(*3*) (*compare lengths.*) ML:=LENGTH(A); NL:=LENGTH(B);
      IF ML < NL THEN Q:=0; R:=A; RETURN; END;
(*4*) (*compute signs and normalize.*) SL:=ISIGNF(A); T:=LAST(B);
      BL:=FIRST(T); TL:=MASSIGN(BL); BL:=MASABS(BL); J1Y:=BL+1; 
      DL:=BETA DIV J1Y;
      J1Y:=SL*DL; AP:=IDPR(A,J1Y); J1Y:=TL*DL; BP:=IDPR(B,J1Y);
(*5*) (*compute app and appp.*) APP:=AP; APPP:=BETA;
      FOR IL:=1 TO ML-NL DO ADV(APP,AL,APP); APPP:=COMP(AL,APPP); END;
(*6*) (*obtain leading digits of divisor.*) BPP:=BP;
      FOR IL:=1 TO NL-2 DO BPP:=RED(BPP); END;
      ADV2(BPP,BL0,BL1,BPP);
(*7*) (*initialize quotient.*) Q:=BETA;
(*begining of loop executed for each quotient digit.*)
LOOP
(*8*) (*obtain high-order digits of dividend.*) AS:=APP;
      FOR IL:=1 TO NL-2 DO AS:=RED(AS); END;
      ADV2(AS,AL0,AL1,AS);
      IF AS = SIL THEN AL2:=0; ELSE AL2:=FIRST(AS); END;
(*9*) (*compute quotient digit approximation ql.*)
      IF AL2 = BL1 THEN QL:=BETA-1; ELSE DQR(AL2,AL1,BL1,QL,RL); END;
      REPEAT DPR(BL0,QL,CL1,CL0); DPR(BL1,QL,CL2,CLP1); CL1:=CL1+CLP1;
             IF CL1 >= BETA THEN CL1:=CL1-BETA; CL2:=CL2+1; END;
             UL:=AL2-CL2;
             IF UL = 0 THEN UL:=AL1-CL1; END;
             IF UL = 0 THEN UL:=AL0-CL0; END;
             QL:=QL-1;
             UNTIL UL >= 0;
      QL:=QL+1;
LOOP
(*10*) (*subtract ql*bp from app.*) AS:=APP; BS:=BP; AH:=BETA; CL:=0;
       FOR IL:=1 TO NL DO ADV(BS,BL,BS); DPR(BL,QL,CL2,CL1);
           ADV(AS,AL,AS); AL:=AL-CL; AL:=AL-CL1; CL:=CL2;
           WHILE AL < 0 DO AL:=AL+BETA; CL:=CL+1; END;
           AH:=COMP(AL,AH); END;
       IF AS = SIL THEN AL:=0; ELSE AL:=FIRST(AS); END;
       AL:=AL-CL;
(*11*) (*adjust ql if necessary.*)
       IF AL < 0 THEN QL:=QL-1; (*go to 10;*) 
                 ELSE APP:=INV(AH); EXIT; END;
END; 
(*12*) (*put ql in list.*)
       IF (Q <> SIL) OR (QL <> 0) THEN Q:=COMP(QL,Q); END;
(*13*) (*return for next quotient digit, if any.*)
       IF APPP <> SIL 
          THEN ADV(APPP,AL,APPP); APP:=COMP(AL,APP); (*go to 8;*)
          ELSE EXIT; END;
END;
(*14*) (*normalize quotient and remainder.*)
       IF Q = SIL THEN Q:=0; ELSE
          IF RED(Q) = SIL THEN Q:=FIRST(Q); END;
          END;
       T:=0; AS:=APP;
       REPEAT AL:=FIRST(AS);
              IF AL <> 0 THEN T:=AS; END;
              AS:=RED(AS);
              UNTIL AS = SIL;
       IF T = 0 THEN R:=0; ELSE SRED(T,SIL); R:=APP;
          IF RED(R) = SIL THEN R:=FIRST(R); END;
          END;
(*15*) (*modify quotient and remainder.*)
       IF SL*TL = -1 THEN Q:=INEG(Q); END;
       IDQR(R,SL*DL,R,T); RETURN;
(*18*) END IQR;


PROCEDURE IRAND(NL: LIST): LIST;
(*Integer, random.  n is a positive beta-integer.  A is an integer
with random sign and random absolute value less than 2**n.*)
VAR  A, AL, IDUM, IL, J1Y, QL, RL, SL: LIST;
BEGIN
(*1*) (*compute sign and high-order beta-digit.*) MASQREM(NL,ZETA,QL,RL);
      IF RL = 0 THEN QL:=QL-1; RL:=ZETA; END;
      AL:=DRAN(); SL:=MASSIGN(AL); J1Y:=ZETA-RL; J1Y:=J1Y+1;
      AL:=AL DIV TABP2[INTEGER(J1Y)];
      IF QL = 0 THEN A:=AL; RETURN(A); END;
      A:=BETA;
      IF AL <> 0 THEN A:=COMP(AL,A); END;
(*2*) (*compute remaining digits.*)
      FOR IL:=1 TO QL DO J1Y:=DRAN(); AL:=MASABS(J1Y);
          IF SL < 0 THEN AL:=-AL; END;
          IF (AL <> 0) OR (A <> SIL) THEN A:=COMP(AL,A); END;
          END;
      IF A = SIL THEN A:=0; ELSE
         IF RED(A) = SIL THEN A:=FIRST(A); END;
         END;
      RETURN(A);
(*5*) END IRAND;


PROCEDURE IREAD(): LIST;
(*Integer read.  The integer A is read from the input stream.  Any
preceding blanks are skipped.*)
VAR  A, B, BL, BLP, C, IDUM, IL, J1Y, SL: LIST;
BEGIN
(*1*) (*read sign.*) SL:=1; C:=CREADB();
      IF C = MASORD("-") THEN SL:=-1; END;
      IF (C = MASORD("+")) OR (C = MASORD("-")) THEN C:=CREAD(); END;
      IF NOT DIGIT(C) THEN (*go to 6;*)
         (*6*) (*error.*) SWRITE("ERROR FOUND BY IREAD."); DIBUFF;        
         A:=0; RETURN(A);
         END;
(*2*) (*skip leading zeros.*)
      WHILE C = 0 DO C:=CREAD(); END;
(*3*) (*is a=0.*) A:=0;
      IF NOT DIGIT(C) THEN BKSP; RETURN(A); END;
(*4*) (*compute theta-digits.*) B:=SIL; BL:=0; IL:=0;
      REPEAT BL:=10*BL+C; IL:=IL+1;
             IF IL = ETA THEN B:=COMP(BL,B); BL:=0; IL:=0; END;
             C:=CREAD();
             UNTIL NOT DIGIT(C);
(*5*) (*convert to base beta.*) B:=INV(B);
      WHILE B <> SIL DO A:=IDPR(A,THETA); ADV(B,BLP,B);
            A:=ISUM(A,BLP); END;
      IF A <> 0 THEN A:=IDPR(A,MASEXP(10,IL)); END;
      A:=ISUM(A,BL);
      IF SL < 0 THEN A:=INEG(A); END;
      BKSP; RETURN(A);
(*6*) (*error.*) SWRITE("ERROR FOUND BY IREAD."); DIBUFF;
(*9*) END IREAD;


PROCEDURE IREM(A,B: LIST): LIST;
(*Integer remainder.  A and B are integers, B non-zero.  C is the
remainder of A and B.*)
VAR  C, Q: LIST;
BEGIN
(*1*) IQR(A,B,Q,C); RETURN(C);
(*4*) END IREM;


PROCEDURE IROOT(A,NL: LIST; VAR B,TL: LIST);
(*Integer root.  A is a positive integer.  n, greater than or equal
to 2, is a beta-integer.  B=FLOOR(A**(1/n)) and t=SIGN(A-B**n).*)
VAR  AP, BP, C, D, E, F, HL, J1Y, J2Y, KL, NLP, R, RL, SL, UL:
     LIST;
BEGIN
(*1*) (*compute first approximation.*) KL:=ILOG2(A); NLP:=NL-1;
      HL:=KL DIV NL; J1Y:=HL*NL; RL:=KL-J1Y; J1Y:=4*RL; UL:=J1Y DIV NL;
      IF HL >= 2 THEN J1Y:=UL+5; J2Y:=HL-2; B:=IMP2(J1Y,J2Y); ELSE
         B:=4; END;
(*2*) (*iterate modified newton method.*)
      LOOP   C:=IEXP(B,NLP); IQR(A,C,D,R); SL:=ICOMP(B,D);
             IF SL <= 0 THEN EXIT; (*go to 3;*) ELSE E:=IDPR(B,NLP);
                F:=ISUM(E,D); B:=IDQ(F,NL); END;
             END;
(*3*) (*test whether result is too small.*)
      IF SL = 0 THEN TL:=ISIGNF(R); ELSE BP:=ISUM(B,1);
         AP:=IEXP(BP,NL); TL:=ICOMP(A,AP);
         IF TL >= 0 THEN B:=BP; ELSE TL:=1; END;
         END;
      RETURN;
(*6*) END IROOT;


PROCEDURE ISEG(A,NL: LIST; VAR A1,A0: LIST);
(*Integer segmentation.  A is an integer.  n is a positive beta-
integer.  A1 is the integral part of A/beta**n.  A0=A-A1*beta**n.*)
VAR  AL, IL: LIST;
BEGIN
(*1*) (*a a beta digit.*)
      IF A < BETA THEN A1:=0; A0:=A; RETURN; END;
(*2*) (*create lists.*) A1:=A; A0:=BETA; IL:=0;
      REPEAT IL:=IL+1; ADV(A1,AL,A1); A0:=COMP(AL,A0);
             UNTIL (IL = NL) OR (A1 = SIL);
(*3*) (*normalize a1.*)
      IF A1 = SIL THEN A1:=0; ELSE
         IF RED(A1) = SIL THEN A1:=FIRST(A1); END;
         END;
(*4*) (*normalize a0.*)
      WHILE (A0 <> SIL) AND (FIRST(A0) = 0) DO A0:=RED(A0); END;
      A0:=INV(A0);
      IF A0 = SIL THEN A0:=0; ELSE
         IF RED(A0) = SIL THEN A0:=FIRST(A0); END;
         END;
      RETURN;
(*7*) END ISEG;


PROCEDURE ISIGNF(A: LIST): LIST;
(*Integer sign function.  A is an integer.  s=SIGN(A).*)
VAR  AL, AP, SL: LIST;
BEGIN
(*1*) (*a single-precision.*)
      IF A < BETA THEN SL:=MASSIGN(A); RETURN(SL); END;
(*2*) (*a multiple-precision.*) AP:=A;
      REPEAT ADV(AP,AL,AP);
             UNTIL AL <> 0;
      SL:=MASSIGN(AL); RETURN(SL);
(*5*) END ISIGNF;


PROCEDURE ISQRT(A: LIST; VAR B,TL: LIST);
(*Integer square root.  A is a non-negative integer.  B is the floor
function of the square root of A and t is the sign of A-B*B.*)
VAR  AL, BL, C, D, HL, J1Y, KL, R, SL: LIST;
BEGIN
(*1*) (*a single-precision.*)
      IF A < BETA THEN DSQRTF(A,B,TL); RETURN; END;
(*2*) (*compute single-precision approximation.*) KL:=ILOG2(A);
      HL:=KL-ZETA; IF MASODD(HL) THEN HL:=HL+1 END; AL:=IDP2(A,HL);
      DSQRTF(AL,BL,TL); BL:=BL+1; J1Y:=HL DIV 2; B:=IMP2(BL,J1Y);
(*3*) (*iterate modified newton method.*)
      LOOP IQR(A,B,C,R); SL:=ICOMP(B,C);
           IF SL <= 0 THEN EXIT; (*go to 4;*) END;
           D:=ISUM(B,C); B:=IDQ(D,2);
           END; 
(*4*) (*compute tl.*) J1Y:=IPROD(B,B); TL:=ICOMP(A,J1Y); RETURN;
(*7*) END ISQRT;


PROCEDURE ISSUM(NL,L: LIST): LIST;
(*Integer shifted sum.  n is a positive integer.  L is a list
(c(0),c(1), ...,c(k)), k non-negative, of integers c(i) with
ABS(c(i)) less than beta**(2*n+1).  Either each c(i) is
non-negative or each c(i) is non-positive.  C is the sum on i,
from 0 to k, of c(i)*(beta**(i*n)).*)
VAR  AL, AL0, AL1, C, C0, C1, CL, CLP, IL, J1Y, LP: LIST;
BEGIN
(*1*) (*initialize.*) C:=BETA; CL:=0; ADV(L,C0,LP);
      IF C0 < BETA THEN C0:=LIST1(C0); END;
      FOR IL:=1 TO NL DO AADV(C0,AL0,C0); C:=COMP(AL0,C); END;
(*2*) (*add.*)
      WHILE LP <> SIL DO ADV(LP,C1,LP);
            IF C1 < BETA THEN C1:=LIST1(C1); END;
            FOR IL:=1 TO NL DO AADV(C0,AL0,C0); AADV(C1,AL1,C1);
                AL:=AL0+AL1; AL:=AL+CL; CL:=AL DIV BETA; CLP:=CL*BETA;
                AL:=AL-CLP; C:=COMP(AL,C); END;
            IF C0 <> SIL THEN J1Y:=FIRST(C0); CL:=CL+J1Y; END;
            C0:=C1; END;
(*3*) (*finish.*)
      WHILE (C0 <> SIL) OR (CL <> 0) DO AADV(C0,AL0,C0); AL:=AL0+CL;
            CL:=0;
            IF AL >= BETA THEN AL:=AL-BETA; CL:=1; ELSE
               IF AL <= -BETA THEN AL:=AL+BETA; CL:=-1; END;
               END;
            C:=COMP(AL,C); END;
(*4*) (*normalize.*)
      WHILE (C <> SIL) AND (FIRST(C) = 0) DO C:=RED(C); END;
      C:=INV(C);
      IF C = SIL THEN C:=0; ELSE
         IF RED(C) = SIL THEN C:=FIRST(C); END;
         END;
      RETURN(C);
(*7*) END ISSUM;


PROCEDURE ISUM(A,B: LIST): LIST;
(*Integer sum.  A and B are integers.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, CLP, CP, CPP, CS, J1Y, J2Y, SL, TL, UL:
     LIST;
BEGIN
(*1*) (*a or b zero$*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*a and b single-precision$*)
      IF (A < BETA) AND (B < BETA) THEN CL:=A+B;
         IF CL >= BETA THEN J1Y:=CL-BETA; C:=LIST2(J1Y,1); ELSE
            IF CL <= -BETA THEN J1Y:=CL+BETA; J2Y:=-1;
               C:=LIST2(J1Y,J2Y); ELSE C:=CL; END;
            END;
         RETURN(C); END;
(*3*) (*determine signs of inputs.*) SL:=ISIGNF(A); TL:=ISIGNF(B);
      C:=BETA;
(*4*) (*a or b single-precision$*)
      IF A < BETA THEN AP:=LIST1(A); ELSE AP:=A; END;
      IF B < BETA THEN BP:=LIST1(B); ELSE BP:=B; END;
(*5*) (*branch on signs.*)
      IF SL = TL THEN (*if <> then go to 8;*)
(*6*) (*same signs, add with carry.*) CLP:=0;
      REPEAT IF AP <> SIL THEN ADV(AP,AL,AP); ELSE AL:=0; END;
             IF BP <> SIL THEN ADV(BP,BL,BP); ELSE BL:=0; END;
             CL:=AL+BL; CL:=CL+CLP; CLP:=0;
             IF CL >= BETA THEN CL:=CL-BETA; CLP:=1; ELSE
                IF CL <= -BETA THEN CL:=CL+BETA; CLP:=-1; END;
                END;
             C:=COMP(CL,C);
             UNTIL (CLP = 0) AND ((AP = SIL) OR (BP = SIL));
      IF AP = SIL THEN AP:=BP; END;
(*7*) (*invert and concatenate.*) CP:=INV(C); SRED(C,AP); C:=CP;
      RETURN(C); END; (*from 5, goto 8*)
(*8*) (*opposite signs, add without carry.*) UL:=0;
      REPEAT ADV(AP,AL,AP); ADV(BP,BL,BP); CL:=AL+BL;
             IF CL <> 0 THEN UL:=CL; END;
             C:=COMP(CL,C);
             UNTIL (AP = SIL) OR (BP = SIL);
      IF AP = SIL THEN AP:=BP; SL:=TL; END;
(*9*) (*sum zero$*)
      IF (UL = 0) AND (AP = SIL) THEN C:=0; RETURN(C); END;
(*10*) (*continue with longer input$*)
       IF (UL = 0) OR (AP <> SIL) AND (SL <> MASSIGN(UL)) THEN
          REPEAT ADV(AP,AL,AP); C:=COMP(AL,C); UL:=AL;
                 UNTIL AL <> 0;
          END;
(*11*) (*invert and normalize.*) CP:=INV(C); CPP:=CP; CLP:=0;
       REPEAT CL:=FIRST(CPP); CL:=CL+CLP; CLP:=0;
              IF (UL > 0) AND (CL < 0) THEN CL:=CL+BETA; CLP:=-1;
                 ELSE
                 IF (UL < 0) AND (CL > 0) THEN CL:=CL-BETA; CLP:=1;
                    END;
                 END;
              IF CL <> 0 THEN CS:=CPP; END;
              SFIRST(CPP,CL); CPP:=RED(CPP);
              UNTIL CPP = SIL;
(*12*) (*concatenate or delete leading zeros.*)
       IF AP = SIL THEN SRED(CS,SIL); ELSE SRED(C,AP); END;
       C:=CP;
       IF RED(C) = SIL THEN C:=FIRST(C); END;
       RETURN(C);
(*15*) END ISUM;


PROCEDURE ITRUNC(A,NL: LIST): LIST;
(*Integer truncation.  A is an integer.  n is a beta-integer.
B=INTEGER(A/2**n).*)
VAR  AL, B, IL, J1Y, ML, QL, RL: LIST;
BEGIN
(*1*) (*a=0 or nl=0.*) B:=A;
      IF (A = 0) OR (NL = 0) THEN RETURN(B); END;
(*2*) (*let abs(nl)=ql*zeta+rl, al=2**rl.*) ML:=MASABS(NL); QL:=ML DIV ZETA;
      J1Y:=QL*ZETA; RL:=ML-J1Y; AL:=TABP2[INTEGER(RL+1)];
(*3*) (*nl gt 0.*)
      IF NL > 0 THEN IL:=0;
         IF B < BETA THEN B:=LIST1(B); END;
         WHILE (B <> SIL) AND (IL <> QL) DO B:=RED(B); IL:=IL+1; END;
         IF B = SIL THEN B:=0; RETURN(B); END;
         IF RED(B) = SIL THEN B:=FIRST(B); END;
         IF RL <> 0 THEN IDQR(B,AL,B,RL); END;
         RETURN(B); END;
(*4*) (*nl lt 0.*)
      IF RL <> 0 THEN B:=IDPR(B,AL); END;
      IF QL = 0 THEN RETURN(B); END;
      IF B < BETA THEN B:=LIST1(B); END;
      FOR IL:=1 TO QL DO B:=COMP(0,B); END;
      RETURN(B);
(*7*) END ITRUNC;


PROCEDURE IWRITE(A: LIST);
(*Integer write.  The input integer A is converted to decimal and
written in the output stream.*)
VAR  B: ARRAY[1..30] OF LIST;
     IL: INTEGER;
     HL, J1Y, H, AP, QL: LIST;
BEGIN
(*6*) (*a single-precision.*)
      IF A < BETA THEN AWRITE(A); RETURN; END;
(*2*) (*compute list of theta-digits.*) AP:=A; H:=BETA;
      REPEAT IDQR(AP,THETA,AP,HL); H:=COMP(HL,H);
             UNTIL AP = 0;
(*3*) (*write first theta-digit.*) ADV(H,HL,H); AWRITE(HL);
(*4*) (*write remaining digits.*)
      WHILE H <> SIL DO ADV(H,HL,H); HL:=MASABS(HL);
            FOR IL:=1 TO INTEGER(ETA) DO QL:=HL DIV 10; J1Y:=10*QL; 
                B[IL]:=HL-J1Y;
                HL:=QL; END;
            FOR IL:=INTEGER(ETA) TO 1 BY -1 DO CWRITE(B[IL]); END;
            END;
      RETURN;
(*7*) END IWRITE;


END SACI.


(* -EOF- *)
