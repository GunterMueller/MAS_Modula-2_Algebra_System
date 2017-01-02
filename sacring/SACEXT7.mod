(* ----------------------------------------------------------------------------
 * $Id: SACEXT7.mi,v 1.3 1992/10/15 16:28:59 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT7.mi,v $
 * Revision 1.3  1992/10/15  16:28:59  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT7;

(* SAC Extensions 7 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASELEM IMPORT MASEVEN;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    INV, COMP, SRED, ADV, FIRST, RED;

FROM SACLIST IMPORT CONC, MEMBER, EQUAL, ADV2, FIRST2, 
                    SECOND, COMP4, LIST2, COMP2, LAST;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM SACI IMPORT IEXP, IDIF;

FROM SACRN IMPORT RNQ, RNDIF, RNCOMP, RNSIGN, RNNEG;

FROM SACPOL IMPORT PDEG, PTBCF;

FROM SACIPOL IMPORT IUPBRE, IUPTR, IUPBES, IUPBHT, IPDMV, IPIP; 

FROM SACPGCD IMPORT IPPP, IPCPP, IPPGSD, IPGCDC;

FROM SACROOT IMPORT IPVCHT, RIB, IUPRB;

FROM SACEXT2 IMPORT RNBCR;

FROM SACEXT4 IMPORT IPINT, IUPIHT;


CONST rcsidi = "$Id: SACEXT7.mi,v 1.3 1992/10/15 16:28:59 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* -- depends on IPRRII :-(
PROCEDURE IPRICL(A: LIST): LIST; 
(*Integral polynomial real root isolation, Collins-Loos algorithm.
A is an integral polynomial.  L is a strong isolation list for A.*)
VAR  B, BL, BP, C, CL, DL, L, LP: LIST; 
BEGIN
(*1*) (*degree zero.*) 
      IF PDEG(A) = 0 THEN L:=BETA; RETURN(L); END; 
(*2*) (*initialize.*) B:=IPPP(1,A); BP:=IPDMV(1,B); C:=BETA; 
(*3*) (*compute derivatives.*) 
      WHILE PDEG(B) > 1 DO BL:=PTBCF(1,B); IPCPP(1,BP, CL,B); 
            BP:=IPDMV(1,B); C:=COMP2(BL,CL,C); END; 
(*4*) (*isolate roots.*) LP:=BETA; 
      LOOP DL:=IUPRB(B); L:=IPRRII(B,BP,DL,LP); 
           IF C = SIL THEN RETURN(L); END; 
           ADV2(C, BL,CL,C); BP:=IPIP(1,CL,B); B:=IPINT(1,BP,BL); 
           LP:=L; 
           END; 
(*7*) RETURN(L); END IPRICL; 
*)


(* -- zuviele gotos :-(
PROCEDURE IPRRII(A,AP,DL,LP: LIST): LIST; 
(*Integral polynomial real root isolation induction.  A is a primitive
positive univariate integral polynomial of positive degree.  AP is
the derivative of A.  D is a binary rational real root bound for A.
LP is a strong isolation list for AP.  L is a strong isolation list
for A.*)
VAR  ABP, AL1, AL2, ALS1, B, B1, B2, BL0, BL1, BLS1, CL, DLP, I, I1,
     IP, IPP, J1Y, KL, L, LS, ML, ML1, NL, RL, RL0, RL1, SL, SL1, SL2,
     SLBP, SLBP1, SLP, SLS1, TL0, TL1, TLP0, TLP1, TLS1, UL, UL1, UL2,
     ULP, ULP1, ULS1, VL1, VLP1, VLS1, WLS0, WLS1, ZL, ZL1, ZL2:
     LIST; 
BEGIN
(*1*) (*AP without roots.*) DLP:=RNNEG(DL); 
      IF LP = SIL THEN I:=LIST2(DLP,DL); L:=LIST2(I,1); RETURN(L); 
         END; 
(*2*) (*initialize.*) ABP:=IPPGSD(1,AP); IPGCDC(1,A,ABP, B,B1,B2); 
      NL:=PDEG(A); KL:=PDEG(B); LS:=LP; 
      IF MASEVEN(NL) THEN TL0:=1; ELSE TL0:=-1; END; 
      TLP0:=-TL0; BL0:=DLP; I1:=FIRST(LS); AL1:=FIRST(I1); 
      UL1:=IUPBRE(A,AL1); SL1:=RNSIGN(UL1); L:=BETA; 
      IF TL0*SL1 > 0 THEN RL0:=0; ELSE RL0:=1; I:=LIST2(BL0,AL1); 
         L:=COMP2(1,I,L); END; 
      IF MASEVEN(KL) THEN WLS0:=1; ELSE WLS0:=-1; END; 
      ML:=PDEG(ABP); 
      IF MASEVEN(ML) THEN SLBP1:=1; ELSE SLBP1:=-1; END; 
LOOP
(*3*) (*root of A in (B sub i ,A sub i+1 ).*) ADV2(LS, I1,ML1,LS); 
      BL1:=SECOND(I1); VL1:=IUPBRE(A,BL1); TL1:=RNSIGN(VL1); 
      IF MASEVEN(ML1) THEN TLP1:=TLP0; ELSE TLP1:=-TLP0; END; 
      TLS1:=TL1; 
      IF TL1 = 0 THEN TLS1:=TLP1; END; 
      IF LS = SIL THEN AL2:=DL; ELSE J1Y:=FIRST(LS); 
         AL2:=FIRST(J1Y); END; 
      IF RNCOMP(BL1,AL2) < 0 THEN UL2:=IUPBRE(A,AL2); 
         SL2:=RNSIGN(UL2); 
         IF TLS1*SL2 <= 0 THEN RL1:=1; ELSE RL1:=0; END; 
         ELSE UL2:=VL1; SL2:=TL1; RL1:=0; END; 

(*4*) (*alpha sub i a root of A.*) 
      IF KL = 0 THEN WLS1:=WLS0; ELSE WLS1:=IUPBES(B,BL1); 
         IF WLS1 = 0 THEN WLS1:=-WLS0; END; 
         END; 
      IF WLS0*WLS1 < 0 THEN J1Y:=ML1+1; L:=COMP2(J1Y,I1,L); GO TO
         9; END; 

(*5*) (*other roots of A in (a sub i ,b sub i ).*) RL:=RL0+RL1; 
      IF RL = 2 THEN GO TO 9; END; 
      IF SL1 <> 0 THEN SLS1:=SL1; ELSE SLS1:=TLP0; END; 
      IF (RL = 1) OR MASEVEN(ML1) THEN
         IF SLS1*TL1 <= 0 THEN GO TO 6; ELSE GO TO 9; END; 
         END; 
      IF TL1 = 0 THEN
         IF SLS1*TLP0 > 0 THEN GO TO 6; END; 
         ALS1:=AL1; BLS1:=BL1; GO TO 8; END; 
      IF SLS1*TL1 < 0 THEN GO TO 6; END; 
      IF SLS1*TLP0 > 0 THEN GO TO 9; ELSE GO TO 7; END; 

(*6*) (*one root in (a sub i ,b sub i ).*) 
      I:=IPRRRI(A,ABP,I1,SLS1,SLBP1); L:=COMP2(1,I,L); GO TO 9; 

(*7*) (*zero or two roots of a in (a sub i ,b sub i ).*) ALS1:=AL1; 
      BLS1:=BL1; ULS1:=UL1; VLS1:=VL1; ULP1:=IUPBRE(AP,ALS1); 
      VLP1:=IUPBRE(AP,BLS1); 
      IF VLP1 = 0 THEN GO TO 9; END; 
      LOOP ZL:=RNQ(ULS1,ULP1); ZL1:=RNDIF(ALS1,ZL); 
           ZL:=RNQ(VLS1,VLP1); ZL2:=RNDIF(BLS1,ZL); 
           ZL:=RNCOMP(ZL1,ZL2); 
           IF ZL >= 0 THEN GO TO 9; END; 
           CL:=RIB(ALS1,BLS1); UL:=IUPBRE(A,CL); SL:=RNSIGN(UL); 
           ULP:=IUPBRE(AP,CL); SLP:=RNSIGN(ULP); 
           IF (SLS1*SL > 0) AND (SLP = 0) THEN GO TO 9; END; 
           IF (SL = 0) AND (TLP0*SLP < 0) THEN BLS1:=CL; GO
              TO 8; END; 
           IF SLS1*SL <= 0 THEN IP:=LIST2(ALS1,CL); 
              IPP:=LIST2(CL,BLS1); 
              IF TLP0*SLP <= 0 THEN
                 I:=IPRRRI(A,ABP,IP,SLS1,SLBP1); 
                 L:=COMP4(1,IPP,1,I,L); ELSE J1Y:=-SLS1; 
                 I:=IPRRRI(A,ABP,IPP,J1Y,SLBP1); L:=COMP4(1,I,1,IP,L); 
                 END; 
              GO TO 9; END; 
           IF TLP0*SLP > 0 THEN ALS1:=CL; ULS1:=UL; ULP1:=ULP; 
              ELSE BLS1:=CL; VLS1:=UL; VLP1:=ULP; END; 
           END; 

(*8*) (*roots at b sub i sup * and in (a sub i sup * ,b sub i sup * )*) 
      LOOP CL:=RIB(ALS1,BLS1); SL:=IUPBES(A,CL); 
           IF SLS1*SL <= 0 THEN SLBP:=IUPBES(ABP,CL); 
              IP:=LIST2(ALS1,CL); IPP:=LIST2(CL,BLS1); 
              IF SLBP1*SLBP <= 0 THEN
                 I:=IPRRRI(A,ABP,IP,SLS1,SLBP1); 
                 L:=COMP4(1,IPP,1,I,L); ELSE J1Y:=-SLS1; 
                 I:=IPRRRI(A,ABP,IPP,J1Y,SLBP1); L:=COMP4(1,I,1,IP,L); 
                 END; 
              GO TO 9; END; 
           ALS1:=CL; 
           END; 

(*9*) (*update.*) 
      IF RL1 = 1 THEN I:=LIST2(BL1,AL2); L:=COMP2(1,I,L); END; 
      AL1:=AL2; RL0:=RL1; TLP0:=TLP1; SL1:=SL2; WLS0:=WLS1; 
      SLBP1:=-SLBP1; UL1:=UL2; 
      IF LS = SIL THEN EXIT (*GO TO 3;*) END; 
      END; 
(*10*) (*finish.*) L:=INV(L); RETURN(L); 
(*13*) END IPRRII; 
*)


PROCEDURE IPRRRI(A,B,I,SL1,TL1: LIST): LIST; 
(*Integral polynomial relative real root isolation.  A and B are
univariate integral polynomials.  I is a left-open, right-closed
interval (a sub 1 ,a sub 2 ) where al sub 1 and al sub 2 are
binary rational numbers with al sub 1 lt al sub 2.  A and B have
unique roots, alpha and beta respectively, in I, each of odd
multiplicity and with alpha ne beta.  sl sub 1 eq
sign(A(al sub 1 +)) and tl sub 1 eq sign(B(al sub 1 +)).
is eq (al sub 1 sup * ,al sub 2 sup * ) is al left-open, right-closed
subinterval of I with al sub 1 sup * and al sub 2 sup *
binary rational numbers and al sub 1 sup * lt al sub 2 sup *,
such that is contains alpha but not beta.*)
VAR  AL, ALS1, ALS2, IS, SL, TL, UL, VL: LIST; 
BEGIN
(*1*) (*initialize.*) FIRST2(I, ALS1,ALS2); 
LOOP
(*2*) (*bisect.*) AL:=RIB(ALS1,ALS2); SL:=IUPBES(A,AL); 
      IF SL = 0 THEN SL:=-SL1; END; 
      TL:=IUPBES(B,AL); 
      IF TL = 0 THEN TL:=-TL1; END; 
      UL:=SL1*SL; VL:=TL1*TL; 
      IF UL > 0 THEN ALS1:=AL; ELSE ALS2:=AL; END; 
      IF UL <> VL THEN EXIT (*GO TO 2;*) END; 
      END; 
(*3*) (*construct is.*) IS:=LIST2(ALS1,ALS2); RETURN(IS); 
(*6*) END IPRRRI; 


PROCEDURE IPSIFI(A,I: LIST): LIST; 
(*Integral polynomial standard isolating interval from isolating interval.
I is an interval with binary rational endpoints, which is either 
left-open and right-closed or a one-point interval.  A is a univariate
integral polynomial which has a unique root alpha
of odd multiplicity in I.  If I is a one-point interval, then
J=I.  If I is left-open and right-closed, then J is either a
standard left-open and right-closed subinterval of I containing
alpha, or if alpha is a binary rational number, J may
possibly instead be the one-point interval ( alpha , alpha ).*)
VAR  AL, BL, CL, J, KL, ML, NL, SL, TL: LIST; 
BEGIN
(*1*) (*initialize.*) FIRST2(I, AL,BL); TL:=IUPBES(A,BL); 
      IF TL = 0 THEN J:=LIST2(BL,BL); RETURN(J); END; 
      RNBCR(AL,BL, ML,NL,KL); 
LOOP
(*2*) (*bisect I until standard subinterval obtained.*) CL:=RIB(AL,BL); 
      SL:=IUPBES(A,CL); 
      IF SL = 0 THEN J:=LIST2(CL,CL); RETURN(J); ELSE
         IF SL*TL < 0 THEN AL:=CL; ELSE BL:=CL; TL:=SL; END; 
         END; 
      RNBCR(AL,BL, ML,NL,KL); 
      IF IDIF(NL,ML) = 1 THEN J:=LIST2(AL,BL); RETURN(J); END; 
      END; (*GO TO 2;*) 
(*5*) RETURN(J); END IPSIFI; 


PROCEDURE ISFPIR(A,I,KL: LIST): LIST; 
(*Integral squarefree polynomial isolating interval refinement.
A is a squarefree univariate integral polynomial.  I is an
isolating interval for a real root alpha of A.  k is a
nonnegative beta -integer.  J is a subinterval of I isolating alpha
with length less than 10 sup -k.*)
VAR  J, QL, RL, SLH, SLP, TL, UL, VL, WL, XL: LIST; 
BEGIN
(*1*) RL:=IEXP(10,KL); QL:=LIST2(1,RL); FIRST2(I, UL,VL); 
      SLP:=IUPBES(A,VL); XL:=RNDIF(VL,UL); TL:=RNCOMP(XL,QL); 
      WHILE TL >= 0 DO WL:=RIB(UL,VL); SLH:=IUPBES(A,WL); 
            IF (SLP = 0) OR (SLH*SLP < 0) THEN UL:=WL; ELSE
               VL:=WL; SLP:=SLH; END; 
            XL:=RNDIF(VL,UL); TL:=RNCOMP(XL,QL); END; 
      J:=LIST2(UL,VL); RETURN(J); 
(*4*) END ISFPIR; 


PROCEDURE IUPVOI(A,I: LIST): LIST; 
(*Integral univariate polynomial, variations for open interval.
A is a non-zero integral univariate polynomial.  I is an open
interval (a,b) with a and b binary rational numbers such that
a lt b.  Let t(z) be the transformation mapping the right half-plane
onto the circle having I as diameter.  Let B(X) eq A(t(X)).
then v is the number of sign variations in the coefficients of B.*)
VAR  AL, B, BL, C, D, DL, KL, ML, NL, VL: LIST; 
BEGIN
(*1*) (*compute m,n, and k such that a eq m 2 sup k,b eq n 2 sup k.*) 
      FIRST2(I, AL,BL); RNBCR(AL,BL, ML,NL,KL); 
(*2*) (*transform and count variations.*) 
      IF KL <> 0 THEN B:=IUPBHT(A,KL); ELSE B:=A; END; 
      IF ML <> 0 THEN C:=IUPTR(B,ML); ELSE C:=B; END; 
      DL:=IDIF(NL,ML); D:=IUPIHT(C,DL); VL:=IPVCHT(D); RETURN(VL); 
(*5*) END IUPVOI; 


END SACEXT7.
(* -EOF- *)
