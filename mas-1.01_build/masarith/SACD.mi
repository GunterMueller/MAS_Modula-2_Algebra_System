(* ----------------------------------------------------------------------------
 * $Id: SACD.mi,v 1.3 1992/10/15 16:28:17 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACD.mi,v $
 * Revision 1.3  1992/10/15  16:28:17  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:10  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:38  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACD;

(* SAC Digit Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT MASABS, MASEVEN, MASQREM, MASREM, MASSIGN;

FROM MASSTOR IMPORT BETA, SIL, LIST,
                    COMP, ADV; 

FROM SACLIST IMPORT CONC, LIST10;


VAR RINC, RMULT, RTERM: LIST;
    
CONST rcsidi = "$Id: SACD.mi,v 1.3 1992/10/15 16:28:17 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE BEGIN2;
(*BEGIN2 calls BEGIN1 and then initializes the system globals for the
arithmetic system.*)
VAR  IL, J1Y, J2Y, L, ML, TL: LIST;
BEGIN
(*1*) (*call begin1.*) (*BEGIN1; not required with modula-2*)
(*2*) (*compute zeta, eta, theta, delta, epsil and tabp2 elements.*)
      IL:=1; TL:=1;
      WHILE TL < BETA DO TABP2[INTEGER(IL)]:=TL; 
            IL:=IL+1; TL:=TL+TL; END;
      ZETA:=IL-1; ETA:=0; TL:=BETA;
      REPEAT TL:=TL DIV 10; ETA:=ETA+1;
             UNTIL TL < 10;
      THETA:=1;
      FOR IL:=1 TO ETA DO THETA:=10*THETA; END;
      J1Y:=ZETA DIV 2; J1Y:=J1Y+1; DELTA:=TABP2[INTEGER(J1Y)]; 
      EPSIL:=BETA DIV DELTA;
(*3*) (*compute rmult, rinc and rterm.*)
      J1Y:=LIST10(3,1,4,1,5,9,2,6,5,3);
      J2Y:=LIST10(5,8,9,7,9,3,2,3,8,4); L:=CONC(J1Y,J2Y); ML:=0;
      WHILE ML < (BETA DIV 10) DO ADV(L,TL,L); J1Y:=10*ML; ML:=J1Y+TL; END;
      ML:=ML DIV 8; J1Y:=8*ML; RMULT:=J1Y+5;
      J1Y:=LIST10(2,1,1,3,2,4,8,6,5,4);
      J2Y:=LIST10(0,5,1,8,7,1,0,0,0,0); L:=CONC(J1Y,J2Y); ML:=0;
      FOR IL:=1 TO ETA DO ADV(L,TL,L); J1Y:=10*ML; ML:=J1Y+TL; END;
      DQR(ML,0,THETA,RINC,TL);
      IF MASEVEN(RINC) THEN RINC:=RINC+1; END;
      J1Y:=LIST10(5,7,7,2,1,5,6,6,4,9);
      J2Y:=LIST10(0,1,5,3,2,8,6,0,6,0); L:=CONC(J1Y,J2Y); ML:=0;
      FOR IL:=1 TO ETA DO ADV(L,TL,L); J1Y:=10*ML; ML:=J1Y+TL; END;
      RTERM:=ML;
(*8*) RETURN; END BEGIN2;


PROCEDURE BITRAN(): LIST;
(*Bit, random.  b is a random bit, 0 or 1.*)
VAR  AL, BL, IDUM: LIST;
BEGIN
(*1*) AL:=DRANN(); AL:=AL+AL;
      IF AL >= BETA THEN BL:=1; ELSE BL:=0; END;
      RETURN(BL);
(*4*) END BITRAN;


PROCEDURE DEGCD(AL,BL: LIST; VAR CL,UL,VL: LIST);
(*Digit extended greatest common divisor.  a and b are beta-integers,
a ge b ge 0.  c=GCD(a,b), a beta-integer.  a*u+b*v=c, with
ABS(u) le b/2c, ABS(v) le a/2c.*)
VAR  AL1, AL2, AL3, J1Y, QL, UL1, UL2, UL3, VL1, VL2, VL3: LIST;
BEGIN
(*1*) AL1:=AL; AL2:=BL; UL1:=1; UL2:=0; VL1:=0; VL2:=1;
      WHILE AL2 <> 0 DO MASQREM(AL1,AL2,QL,AL3); AL1:=AL2; AL2:=AL3;
            J1Y:=QL*UL2; UL3:=UL1-J1Y; UL1:=UL2; UL2:=UL3; J1Y:=QL*VL2;
            VL3:=VL1-J1Y; VL1:=VL2; VL2:=VL3; END;
      CL:=AL1; UL:=UL1; VL:=VL1; RETURN;
(*4*) END DEGCD;


PROCEDURE DGCD(AL,BL: LIST): LIST;
(*Digit greatest common divisor.  a and b are beta-integers,
a ge b ge 0.  c=GCD(a,b).*)
VAR  AL1, AL2, AL3, CL: LIST;
BEGIN
(*1*) AL1:=AL; AL2:=BL;
      WHILE AL2 <> 0 DO AL3:=MASREM(AL1,AL2); AL1:=AL2; AL2:=AL3; END;
      CL:=AL1; RETURN(CL);
(*4*) END DGCD;


PROCEDURE DLOG2(AL: LIST): LIST;
(*Digit logarithm, base 2.  a is a beta-digit.  If a=0 then n=0.
otherwise n=FLOOR(LOG2(ABS(a)))+1.*)
VAR  ALB, IL, J1Y, JL, NL: LIST;
BEGIN
(*1*) (*al le 0.*)
      IF AL = 0 THEN NL:=0; RETURN(NL); END;
      ALB:=MASABS(AL);
(*2*) (*binary search.*) IL:=1; JL:=ZETA+1;
      REPEAT J1Y:=IL+JL; NL:=J1Y DIV 2;
             IF ALB >= TABP2[INTEGER(NL)] THEN IL:=NL; ELSE JL:=NL; END;
             UNTIL JL-IL = 1;
      NL:=IL; RETURN(NL);
(*5*) END DLOG2;


PROCEDURE DPCC(AL1,AL2: LIST; VAR UL,ULP,VL,VLP: LIST);
(*Digit partial cosequence calculation.  a1 and a2 are beta-integers,
a1 ge a2 gt 0.  u, up, v and vp are the last cosequence elements
of a1 and a2 which can be guaranteed to correspond to correct
quotient digits.*)
VAR  AL, ALP, ALPP, J1Y, QL, ULPP, VLPP: LIST;
BEGIN
(*1*) AL:=AL1; ALP:=AL2; UL:=1; ULP:=0; VL:=0; VLP:=1;
      LOOP   QL:=AL DIV ALP; J1Y:=QL*ALP; ALPP:=AL-J1Y; J1Y:=QL*ULP;
             ULPP:=UL-J1Y; J1Y:=QL*VLP; VLPP:=VL-J1Y;
             IF (ALPP < MASABS(VLPP)) OR (ALP-ALPP < MASABS(VLP-VLPP))
                THEN RETURN; END;
             AL:=ALP; ALP:=ALPP; UL:=ULP; ULP:=ULPP; VL:=VLP; VLP:=VLPP;
             END;
(*4*) RETURN; END DPCC;


PROCEDURE DPR(AL,BL: LIST; VAR CL,DL: LIST);
(*Digit product.  a and b are beta-digits.  c and d are the unique
beta-digits such that a*b=c*beta+d and c*d ge 0.*)
VAR  AL0, AL1, BL0, BL1, CL0, CL00, CL01, CL1, CL10, CL11, CL2, CLP,
     DLP, J1Y, J2Y: LIST;
BEGIN
(*1*) AL1:=AL DIV EPSIL; J1Y:=AL1*EPSIL; AL0:=AL-J1Y; BL1:=BL DIV EPSIL;
      J1Y:=BL1*EPSIL; BL0:=BL-J1Y;
(*2*) CL0:=AL0*BL0; J1Y:=AL1*BL0; J2Y:=AL0*BL1; CL1:=J1Y+J2Y;
      CL2:=AL1*BL1;
(*3*) IF CL0 >= BETA THEN CL01:=1; CL00:=CL0-BETA; ELSE
         IF CL0 <= -BETA THEN CL01:=-1; CL00:=CL0+BETA; ELSE CL01:=0;
            CL00:=CL0; END;
         END;
      CL11:=CL1 DIV DELTA; J1Y:=CL11*DELTA; CL10:=CL1-J1Y;
(*4*) J1Y:=CL2+CL01; CLP:=J1Y+CL11;
      IF DELTA <> EPSIL THEN CLP:=CLP+CL2; END;
      J1Y:=CL10*EPSIL; DLP:=J1Y+CL00;
(*5*) IF DLP >= BETA THEN CL:=CLP+1; DL:=DLP-BETA; ELSE
         IF DLP <= -BETA THEN CL:=CLP-1; DL:=DLP+BETA; ELSE CL:=CLP;
            DL:=DLP; END;
         END;
      RETURN;
(*8*) END DPR;


PROCEDURE DQR(AL1,AL0,BL: LIST; VAR QL,RL: LIST);
(*Digit quotient and remainder.  a1, a0 and b are beta-integers with
a1*a0 ge 0 and ABS(b) gt ABS(a1).  q is the integral part of
(a1*beta+a0)/b and r is (a1*beta+a0)-b*q.  q and r are
beta-integers.*)
VAR  ALP0, ALP1, BLP, QLP: LIST;
     IL: INTEGER;
BEGIN
(*1*) (*al1 eq 0.*)
      IF AL1 = 0 THEN MASQREM(AL0,BL,QL,RL); RETURN; END;
(*2*) (*compute absolute values.*) ALP1:=MASABS(AL1); ALP0:=MASABS(AL0);
      BLP:=MASABS(BL);
(*3*) (*shift and subtract.*) QLP:=0;
      FOR IL:=1 TO INTEGER(ZETA) DO ALP1:=ALP1+ALP1; ALP0:=ALP0+ALP0;
          IF ALP0 >= BETA THEN ALP0:=ALP0-BETA; ALP1:=ALP1+1; END;
          QLP:=QLP+QLP;
          IF ALP1 >= BLP THEN ALP1:=ALP1-BLP; QLP:=QLP+1; END;
          END;
(*4*) (*compute signs.*)
      IF AL1 < 0 THEN QLP:=-QLP; ALP1:=-ALP1; END;
      IF BL < 0 THEN QLP:=-QLP; END;
      QL:=QLP; RL:=ALP1; 
      RETURN;
(*7*) END DQR;


PROCEDURE DRAN(): LIST;
(*Digit, random.  a is a random beta-digit.*)
VAR  AL, AL1, AL2, IDUM, J1Y, SL: LIST;
BEGIN
(*1*) AL1:=DRANN(); SL:=0; AL1:=AL1+AL1;
      IF AL1 >= BETA THEN SL:=1; AL1:=AL1-BETA; END;
      AL1:=AL1 DIV DELTA; AL2:=DRANN(); AL2:=AL2 DIV EPSIL; J1Y:=AL1*DELTA;
      AL:=J1Y+AL2;
      IF SL = 1 THEN AL:=-AL; END;
      RETURN(AL);
(*4*) END DRAN;


PROCEDURE DRANN(): LIST;
(*Digit, random non-negative.  a is a random non-negative beta-digit.
Caution, the low-order bits of a are not very random.*)
VAR  AL, TL: LIST;
BEGIN
(*1*) DPR(RTERM,RMULT,TL,AL); AL:=AL+RINC;
      IF AL >= BETA THEN AL:=AL-BETA; END;
      RTERM:=AL; RETURN(AL);
(*4*) END DRANN;


PROCEDURE DSQRTF(AL: LIST; VAR BL,TL: LIST);
(*Digit square root function.  a is a non-negative beta-integer.
b is the floor function of the square root of a and t is the sign
of a-b*b.*)
VAR  CL, HL, J1Y, KL, RL: LIST;
BEGIN
(*1*) (*al=0.*)
      IF AL = 0 THEN BL:=0; TL:=0; RETURN; END;
(*2*) (*compute first approximation.*) KL:=DLOG2(AL); J1Y:=KL+1;
      HL:=J1Y DIV 2; BL:=TABP2[INTEGER(HL)+1];
(*3*) (*iterate modified newton method.*)
      LOOP MASQREM(AL,BL,CL,RL);
           IF BL <= CL THEN J1Y:=BL*BL; J1Y:=AL-J1Y; TL:=MASSIGN(J1Y);
              RETURN; END;
           J1Y:=BL+CL; BL:=J1Y DIV 2;
           END; (*loop*)
      RETURN;
(*6*) END DSQRTF;


BEGIN
(* Initialization. *)

BEGIN2;

END SACD.


(* -EOF- *)
