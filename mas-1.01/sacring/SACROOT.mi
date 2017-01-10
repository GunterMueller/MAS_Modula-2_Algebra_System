(* ----------------------------------------------------------------------------
 * $Id: SACROOT.mi,v 1.4 1993/05/11 10:51:46 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACROOT.mi,v $
 * Revision 1.4  1993/05/11  10:51:46  kredel
 * Spelling errors corr.
 *
 * Revision 1.3  1992/10/15  16:29:07  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:35:05  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:15  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACROOT;

(* SAC Polynomial Real Root Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX, MASQREM;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM MASBIOS IMPORT SWRITE, BLINES; 

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    ADV4, COMP4, ADV3, COMP3, EQUAL, RED2, 
                    OWRITE, SECOND, LIST2;

FROM SACI IMPORT INEG, ISUM, IABSF, ISIGNF, ICOMP, ILOG2, ITRUNC;

FROM SACRN IMPORT RNFLOR, RNCEIL, RNRED, RNP2, RNNEG, RNFCL2, RNINT, 
                  RIRNP, RNQ, RNSIGN, RNCOMP, RNDIF, RNPROD, RNSUM;

FROM SACPOL IMPORT PCL, PRED, PRT, PORD, PDBORD, PDEG, PLDCF, 
                   PTBCF, PDEGV, PINV;

FROM SACIPOL IMPORT IUPTR1, IUPBRE, IUPBES, IPABS, IPDMV, IPHDMV, 
                    IPONE, IUPBHT, IUPNT, IUPTR;

FROM SACPGCD IMPORT IPPGSD, IPSF, IPPP, IPGCDC;

CONST rcsidi = "$Id: SACROOT.mi,v 1.4 1993/05/11 10:51:46 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IIC(A,AP,I,L: LIST): LIST; 
(*Isolating interval conversion.  A is a squarefree univariate integral
polynomial.  AP is the derivative of A.  I is an left open right closed
interval (a,b) with binary rational endpoints represented by the list
(a,b).  L is a list of isolating intervals with binary rational end-
points for the real roots of A in I.  L=((a(1),b(1)), ...,(a(k),b(k))) 
with a(1) le b(1) le  ... le a(k) le b(k) and (a(i), b(i)) 
represents the open interval (a(i),b(i)) if a(i) lt
b(i), the closed interval (a(i),b(i)) if a(i)=b(i).  LS is a
list ((as(1),bs(1)), ...,(as(k),bs(k))) of isolating intervals for
the same roots and satisfying the same conditions except that each pair
(as(i),bs(i)) represents the left open right closed interval
(as(i),bs(i)).*)
VAR  AL1, AL2, BL1, BL2, CL, I1, I2, J1Y, LP, LS, SL, SL1: LIST; 
BEGIN
(*1*) (*initialize.*) LP:=CINV(L); LS:=BETA; 

LOOP
LOOP
LOOP
(*2*) (*finish.*) 
      IF LP = SIL THEN RETURN(LS); END; 

(*3*) (*i2 open.*) ADV(LP, I2,LP); FIRST2(I2, AL2,BL2); 
      SL:=RNCOMP(AL2,BL2); 
      IF SL = 0 THEN (*<>*) EXIT END;
      LS:=COMP(I2,LS); (*go to 2;*) 
      END;

(*4*) (*lp empty.*) 
      IF LP = SIL THEN AL2:=FIRST(I); J1Y:=LIST2(AL2,BL2); 
         LS:=COMP(J1Y,LS); RETURN(LS); END; 
(*5*) (*i1 not adjacent.*) I1:=FIRST(LP); FIRST2(I1, AL1,BL1); 
      SL:=RNCOMP(BL1,AL2); 
      IF SL = 0 THEN (*<>*) EXIT END;
      AL2:=BL1; J1Y:=LIST2(AL2,BL2); LS:=COMP(J1Y,LS); 
END; (*go to 3;*) (*changed in goto 2. because of crossing loops. *)

(*6*) (*bisect i1.*) LP:=RED(LP); SL1:=IUPBES(A,AL1); 
      IF SL1 = 0 THEN SL1:=IUPBES(AP,AL1); END; 
      CL:=AL1; 
      REPEAT CL:=RIB(CL,BL1); SL:=IUPBES(A,CL); 
             UNTIL SL1*SL <= 0; 
(*7*) (*adjoint two intervals.*) J1Y:=LIST2(CL,BL1); LS:=COMP(J1Y,LS); 
      J1Y:=LIST2(AL1,CL); LS:=COMP(J1Y,LS); 
END; (*go to 2;*) 

(*10*) RETURN(LS); END IIC; 


PROCEDURE IPFSD(RL,A: LIST): LIST; 
(*Integral polynomial factorization, second derivative.  A is a
positive primitive integral polynomial in r variables of positive
degree.  L is a list (a(1), ...,a(k)) where k ge 1, A equal to sum of
a(i) for i=1, ...,k and, for each i, a(i) is a positive primitive
integral polynomial of positive degree with deg(a(i)) le 2 or
gcd(a(i),app(i))=1  where app(i) is the second derivative of a(i).*)
VAR  B, B1, B2, BPP, C, L, NL, S: LIST; 
BEGIN
(*1*) L:=BETA; S:=LIST1(A); 
      REPEAT ADV(S, B,S); NL:=FIRST(B); 
             IF NL <= 2 THEN L:=COMP(B,L); ELSE BPP:=IPHDMV(RL,B,2); 
                IPGCDC(RL,B,BPP, C,B1,B2); 
                IF IPONE(RL,C) = 1 THEN L:=COMP(B,L); ELSE
                   S:=COMP2(B1,C,S); END; 
                END; 
             UNTIL S = SIL; 
      RETURN(L); 
(*4*) END IPFSD; 


PROCEDURE IPLRRI(L: LIST): LIST; 
(*Integral polynomial list real root isolation.  L is a non-empty list
(A sub 1 ,  ..., A sub n ) of distinct univariate integral polynomials
which are positive, of positive degree, squarefree, and pairwise
relatively prime.  M is a list (I sub 1 , B sub 1 , ..., I sub m ,
B sub m ), where I sub 1  lt  I sub 2  lt   ...  lt  I sub m are
strongly disjoint isolating intervals for all of the real roots of A eq
prod from (j eq 1) to n (A sub j).  Each I sub i has binary
rational number endpoints, and is either left-open and
right-closed or is a one-point interval.  B sub i is the unique A
sub j which has a root in I sub i.*)
VAR  A1, A2, B1, I1, I11, I21, J1Y, J2Y, LP, LPP, M, S, S1, S2, SL, SP,
     SPP, SS1, SS2, T, T1, T2: LIST; 
BEGIN
(*1*) (*isolate roots of each a sub i.*) LP:=L; S:=BETA; 
      REPEAT ADV(LP, A1,LP); S1:=IPRIM(A1); S:=COMP(S1,S); 
             UNTIL LP = SIL; 
      S:=INV(S); 
(*2*) (*refine to disjoint isolating intervals.*) LP:=L; SP:=S; 
      WHILE RED(LP) <> SIL DO A1:=FIRST(LP); S1:=FIRST(SP); 
            LPP:=RED(LP); SPP:=RED(SP); 
            REPEAT A2:=FIRST(LPP); S2:=FIRST(SPP); IPRRLS(A1,A2,S1,S2,
                   SS1,SS2); S1:=SS1; SFIRST(SPP,SS2); LPP:=RED(LPP); 
                   SPP:=RED(SPP); 
                   UNTIL LPP = SIL; 
            SFIRST(SP,S1); LP:=RED(LP); SP:=RED(SP); END; 
(*3*) (*prepare to merge intervals.*) LP:=L; SP:=S; T:=BETA; 
      REPEAT ADV(LP, A1,LP); ADV(SP, S1,SP); T1:=BETA; 
             WHILE S1 <> SIL DO ADV(S1, I11,S1); 
                   T1:=COMP2(A1,I11,T1); END; 
             J1Y:=INV(T1); T:=COMP(J1Y,T); 
             UNTIL LP = SIL; 
      T:=INV(T); 
(*4*) (*merge-sort isolating intervals.*) 
      WHILE RED(T) <> SIL DO S:=BETA; 
            WHILE (T <> SIL) AND (RED(T) <> SIL) DO ADV2(T,
                  T1,T2,T); S1:=BETA; 
                  WHILE (T1 <> SIL) AND (T2 <> SIL) DO
                        I11:=FIRST(T1); I21:=FIRST(T2); J1Y:=FIRST(I11); 
                        J2Y:=FIRST(I21); SL:=RNCOMP(J1Y,J2Y); 
                        IF SL < 0 THEN ADV2(T1, I1,B1,T1); ELSE
                           ADV2(T2, I1,B1,T2); END; 
                        S1:=COMP2(B1,I1,S1); END; 
                  IF T1 = SIL THEN T1:=T2; END; 
                  J1Y:=INV(S1); S1:=CONC(J1Y,T1); S:=COMP(S1,S); END; 
            IF T <> SIL THEN J1Y:=FIRST(T); S:=COMP(J1Y,S); END; 
            T:=INV(S); END; 
      M:=FIRST(T); RETURN(M); 
(*7*) END IPLRRI; 


PROCEDURE IPRCH(A,I,KL: LIST): LIST; 
(*Integral polynomial real root calculation, high precision.  A is a
univariate integral polynomial of positive degree.  I is either the
nulllist () or a standard interval or an interval whose positive and
non-positive parts are standard.  k is a gamma-integer.  L is a
list ((e(1),I(1)), ...,(e(r),I(r))) where the e(j) are
beta-integers,  1 le e(1) le  ... le e(r), and the I(j) are binary
rational isolating intervals, I(j)=(a(j),b(j)), for the r distinct
real roots of A if I=(), or for the r distinct real roots of A in I if
I ne ().  e(j) is the multiplicity of the root alpha(j) in I(j) and
abs(b(j)-a(j))  le 2**k.  I(j) is a left-open and right-closed
interval if a(j) lt b(j), a one-point interval if a(j)=b(j).*)
VAR  A1, AB, EL, J, L, L1, L2, P: LIST; 
BEGIN
(*1*) (*squarefree factorization.*) AB:=IPABS(1,A); L1:=IPSFSD(1,AB); 
(*2*) (*compute roots of factors.*) L:=BETA; 
      REPEAT ADV(L1, P,L1); FIRST2(P, EL,A1); L2:=IPRCHS(A1,I,KL); 
             WHILE L2 <> SIL DO ADV(L2, J,L2); P:=LIST2(EL,J); 
                   L:=COMP(P,L); END; 
             UNTIL L1 = SIL; 
      L:=INV(L); RETURN(L); 
(*5*) END IPRCH; 


PROCEDURE IPRCHS(A,I,KL: LIST): LIST; 
(*Integral polynomial real root calculation, high-precision special.
A is a positive, primitive, squarefree, univariate, integral polynomial
of positive degrre with GCD(A,APP)=1.  I is either the null list () or
a standard interval or an interval whose positive and non-positive parts
are standard.  k is a gamma-integer.  L is a list (I(1), ...,I(r)) of
binary rational isolating intervals I(j)=(a(j),b(j)) for the r
distinct real roots of A if I=(), for the r distinct real roots of A
of I if I ne (), with b(j)-a(j) le 2**kl.  I(j) is a left-open and
right-closed interval if a(j) ne b(j), a one-point interval if
a(j)=b(j).*)
VAR  BL, J, L, L1, SL, SLP, SLPP, TL: LIST; 
BEGIN
(*1*) (*find strong isolation list for a.*) L:=BETA; L1:=IPSRM(A,I); 
      IF L1 = SIL THEN RETURN(L); END; 
(*2*) (*refine isolation list.*) 
      REPEAT ADV(L1, J,L1); BL:=SECOND(J); 
             IF IUPBRE(A,BL) = 0 THEN J:=LIST2(BL,BL); 
                ELSE IPRCNP(A,J, SLP,SLPP,J); TL:=RILC(J,KL); 
                IF TL = 0 THEN SL:=SLP*SLPP; J:=IPRCN1(A,J,SL,KL) END; 
                END; 
             L:=COMP(J,L); 
             UNTIL L1 = SIL; 
      L:=INV(L); RETURN(L); 
(*5*) END IPRCHS; 


PROCEDURE IPRCNP(A,I: LIST;  VAR SLP,SLPP,J: LIST); 
(*Integral polynomial real root calculation, newton method preparation.
A is a positive, primitive, squarefree, univariate integral polynomial
of positive degree.  I is an open interval (a1,a2) with binary
rational endpoints containing no roots of AP and APP.  sp and spp,
beta-integers, are the signs of AP and APP on I.  J is a subinterval
(b1,b2) of I with binary rational endpoints, containing alpha and
such that spp*SIGN(AP(b1)+f*AP(b2)) ge 0, where
f=(-3/4)**(sp*spp).  J is a left-open and right-closed interval if
b1 lt b2, the one-point interval if b1=b2.*)
VAR  AP, BL, BL1, BL2, DL, DL1, DL2, FL, HL, J1Y, SL, TL: LIST; 
BEGIN
(*1*) (*initialize.*) FIRST2(I, BL1,BL2); HL:=LIST2(1,2); 
(*2*) (*compute slp.*) SLP:=IUPBES(A,BL2); 
(*3*) (*compute slpp.*) AP:=IPDMV(1,A); DL1:=IUPBRE(AP,BL1); 
      DL2:=IUPBRE(AP,BL2); DL:=RNDIF(DL2,DL1); SLPP:=RNSIGN(DL); 
(*4*) (*compute fl.*) 
      IF SLP*SLPP > 0 THEN J1Y:=-3; FL:=LIST2(J1Y,4); ELSE J1Y:=-4; 
         FL:=LIST2(J1Y,3); END; 
LOOP
(*5*) (*test for completion.*) DL:=RNPROD(FL,DL2); DL:=RNSUM(DL1,DL); 
      TL:=RNSIGN(DL); 
      IF SLPP*TL >= 0 THEN EXIT (*go to 7;*) END; 
(*6*) (*bisect interval.*) BL:=RNSUM(BL1,BL2); BL:=RNPROD(BL,HL); 
      SL:=IUPBES(A,BL); 
      IF SL = 0 THEN BL1:=BL; BL2:=BL; EXIT (*go to 7;*) END; 
      DL:=IUPBRE(AP,BL); 
      IF SL = SLP THEN BL2:=BL; DL2:=DL; ELSE BL1:=BL; DL1:=DL END; 
      END; (*go to 5;*) 

(*7*) (*finish.*) J:=LIST2(BL1,BL2); RETURN; 
(*9*) END IPRCNP; 


PROCEDURE IPRCN1(A,I,SL,KL: LIST): LIST; 
(*Integral polynomial real root calculation, 1 root.  A is a positive
primitive univariate integral polynomial of positive degree. I is an
open interval (a1,a2) with binary rational endpoints containing a
unique root alpha of A and containing no roots of AP or APP.  s, a
beta-integer, is the sign of AP*APP on I.
min(abs(AP(a1)),abs(AP(a2))) le (3/4)*max(abs(AP(a1)),abs(AP(a2))).
k is a beta-integer.  J is a subinterval of I of length 2**k or less
containing alpha and with binary rational endpoints.*)
VAR  AP, BL, BL1, BL2, DL1, DL2, DLP, J, QL1, QL2:
     LIST; 
BEGIN
(*1*) (*initialize.*) AP:=IPDMV(1,A); J:=I; 
(*2*) (*refine interval.*) 
      WHILE RILC(J,KL) = 0 DO FIRST2(J, BL1,BL2); 
            DL1:=IUPBRE(A,BL1); DL2:=IUPBRE(A,BL2); 
            IF SL < 0 THEN BL:=BL1; ELSE BL:=BL2; END; 
            DLP:=IUPBRE(AP,BL); QL1:=RNQ(DL1,DLP); QL2:=RNQ(DL2,DLP); 
            BL1:=RNDIF(BL1,QL1); BL2:=RNDIF(BL2,QL2); J:=LIST2(BL1,BL2); 
            IF RNCOMP(BL1,BL2) = 0 THEN RETURN(J); END; 
            J:=RINT(J); END; 
      RETURN(J); 
(*5*) END IPRCN1; 


PROCEDURE IPRIM(A: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method.
A is a non-zero squarefree univariate integral polynomial.  L is
a list (I sub 1 , ..., I sub r ) of strongly disjoint isolating
intervals for all of the real roots of A with I sub 1  lt  I
sub 2  lt   ...  lt  I sub r.  Each I sub j has binary rational
endpoints and is either left-open and right-closed or a one-point
interval.*)
VAR  AB, AS, BL, BLS, HL, I, I1, I2, J1Y, KL, L, LP, LS, NL, SL:
     LIST; 
BEGIN
(*1*) (*degree zero.*) NL:=PDEG(A); L:=BETA; 
      IF NL = 0 THEN RETURN(L); END; 
(*2*) (*compute positive roots.*) AB:=PDBORD(A); BL:=IUPRB(AB); 
      RNFCL2(BL, HL,KL); AS:=IUPBHT(AB,KL); LS:=IPRIMU(AS); 
      WHILE LS <> SIL DO ADV(LS, I,LS); I:=RIRNP(I,BL); 
            L:=COMP(I,L); END; 
      L:=INV(L); 
(*3*) (*zero a root.*) 
      IF FIRST(AB) < NL THEN J1Y:=LIST2(0,0); L:=COMP(J1Y,L); END; 
(*4*) (*compute negative roots.*) AS:=IUPNT(AS); LS:=IPRIMU(AS); 
      BLS:=RNNEG(BL); 
      WHILE LS <> SIL DO ADV(LS, I,LS); I:=RIRNP(I,BLS); 
            L:=COMP(I,L); END; 
(*5*) (*make intervals strongly disjoint.*) LP:=L; 
      WHILE (L <> SIL) AND (RED(LP) <> SIL) DO I1:=FIRST(LP); 
            I2:=SECOND(LP); IPRRS(A,A,I1,I2, I1,I2,SL); 
            SFIRST(LP,I1); LP:=RED(LP); SFIRST(LP,I2); END; 
      RETURN(L); 
(*8*) END IPRIM; 


PROCEDURE IPRIMO(A,AP,I: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, open interval.  
A is a univariate integral polynomial without multiple roots.  
AP is the derivative of A.  I is an open interval (a,b) with
binary rational endpoints, represented by the list (a,b), such that
there are integers h and k for which a=h*2**k and b=(h+1)*2**k.
L is a list (I(1), ...,I(r)) of isolating intervals for the real roots
of A in I.  Each I(j) is a left open right closed interval with binary
rational endpoints and I(1) lt I(2) lt  ... lt I(r).*)
VAR  BL, CL, J, L: LIST; 
BEGIN
(*1*) L:=IPRIMS(A,AP,I); 
      IF L <> SIL THEN L:=INV(L); J:=FIRST(L); BL:=SECOND(I); 
         CL:=SECOND(J); 
         IF (RNCOMP(BL,CL) = 0) AND (IUPBES(A,BL) = 0) THEN
            L:=RED(L); END; 
         L:=INV(L); END; 
      RETURN(L); 
(*4*) END IPRIMO; 


PROCEDURE IPRIMS(A,AP,I: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, standard interval.  
A is a univariate integral polynomial without multiple roots.  
AP is the derivative of A.  I is a standard interval.
L is a list (I(1), ...,I(r)) of isolating intervals for the real roots
of A in I.  Each interval I(j) is a left open right closed interval
(a(j),b(j)) with binary rational endpoints and I(1) lt I(2) lt  ...
lt I(r).*)
VAR  A1, AL, AL1, ALP1, BL, BL1, BLP1, CL, HLP, HLS, I1, IP1, KL, KLP,
     L, L1, LP: LIST; 
BEGIN
(*1*) (*degree zero.*) 
      IF PDEG(A) = 0 THEN L:=BETA; RETURN(L); END; 
(*2*) (*transform a.*) FIRST2(I, AL,BL); CL:=RNDIF(BL,AL); RNFCL2(CL,
      KL,KLP); 
      IF BL = 0 THEN HLP:=0; ELSE HLS:=RNQ(BL,CL); HLP:=FIRST(HLS); 
         END; 
      A1:=IUPBHT(A,KL); A1:=IUPTR(A1,HLP); A1:=IUPNT(A1); 
(*3*) (*compute roots.*) L1:=IPRIMU(A1); 
(*4*) (*transform isolation intervals.*) LP:=BETA; 
      WHILE L1 <> SIL DO ADV(L1, I1,L1); FIRST2(I1, AL1,BL1); 
            ALP1:=RNPROD(AL1,CL); ALP1:=RNDIF(BL,ALP1); 
            BLP1:=RNPROD(BL1,CL); BLP1:=RNDIF(BL,BLP1); 
            IP1:=LIST2(BLP1,ALP1); LP:=COMP(IP1,LP); END; 
(*5*) (*convert isolating intervals.*) L:=IIC(A,AP,I,LP); RETURN(L); 
(*8*) END IPRIMS; 


PROCEDURE IPRIMU(A: LIST): LIST; 
(*Integral polynomial real root isolation, modified Uspensky method, unit interval.  
A is a squarefree univariate integral polynomial.  L is
a list (I(1), ...,I(r)) of isolating intervals for all the roots of A
in the left closed right open interval (0,1).  Each I(j) is a pair
(a(j),b(j)) of binary rational numbers, with 0 le a(1) le b(1) le
 ... le a(r) le b(r).  If a(j)=b(j) then (a(j),b(j))
represents the one-point interval (a(j),b(j)).  If a(j) lt b(j)
then the pair  (a(j),b(j)) represents the open interval
(a(j),b(j)).*)
VAR  AL, B, B1, BL, CL, EL, EL1, I, J1Y, L, S, TL, VL, VL1: LIST; 
BEGIN
(*1*) (*initialize.*) L:=BETA; S:=BETA; B:=A; AL:=0; BL:=LIST2(1,1); 
      EL:=PORD(A); VL:=IPVCHT(B); TL:=LIST2(1,2); 
LOOP
LOOP
(*2*) (*one variation or less.*) 
      IF VL <= 1 THEN
         IF VL = 1 THEN I:=LIST2(AL,BL); L:=COMP(I,L); END; 
         IF EL > 0 THEN I:=LIST2(AL,AL); L:=COMP(I,L); END; 
         EXIT (*go to 5;*) END; 
(*3*) (*bisect.*) J1Y:=-1; B1:=IUPBHT(B,J1Y); B:=IUPTR1(B1); 
      CL:=RNSUM(AL,BL); CL:=RNPROD(CL,TL); EL1:=EL; VL1:=IPVCHT(B1); 
      EL:=PORD(B); VL:=IPVCHT(B); 
(*4*) (*stack left half.*) 
      IF (EL1 > 0) OR (VL1 > 0) THEN S:=COMP2(AL,CL,S); 
         S:=COMP3(VL1,EL1,B1,S); END; 
      AL:=CL; 
      END; (*go to 2;*) 

(*5*) (*finished.*) 
      IF S = SIL THEN RETURN(L); END; 
      ADV3(S, VL,EL,B,S); ADV2(S, AL,BL,S); 
      END; (*go to 2;*) 
(*8*) RETURN(L); END IPRIMU; 


PROCEDURE IPRIU(A: LIST): LIST; 
(*Integral polynomial real root isolation, Uspensky method.  A is a
non-zero squarefree univariate integral polynomial.  L is a list of
pairs  ((a(1),b(1)), ...,(a(k),b(k))) representing isolating
intervals forall of the real roots of A, with a(1) le b(1) le  ... le
a(k) le b(k).  If a(i) lt b(i) then the pair
(a(i),b(i)) represents the open interval (a(i),b(i)), while
if a(i)=b(i) then it represents the closed one-point interval
(a(i),b(i)).  The a(i) and b(i) are rational numbers except
that one may have a(1) equal to negative infinity, represented by
-1/0, that is the pair (-1,0), and one may have b(k) equal to
infinity, represented by 1/0.*)
VAR  AB, AS, I, L, LS, ML, NL, RL1, RL2, RLP1, RLP2: LIST; 
BEGIN
(*1*) (*initialize.*) NL:=FIRST(A); AB:=PDBORD(A); ML:=FIRST(AB); 
(*2*) (*compute positive roots.*) L:=IPRIUP(AB); 
(*3*) (*adjoint zero.*) 
      IF ML < NL THEN I:=LIST2(0,0); L:=COMP(I,L); END; 
(*4*) (*compute negative roots.*) AS:=IUPNT(AB); LS:=IPRIUP(AS); 
(*5*) (*adjoint negative roots.*) 
      WHILE LS <> SIL DO ADV(LS, I,LS); ADV2(I, RL1,RL2,I); 
            RLP1:=RNNEG(RL1); RLP2:=RNNEG(RL2); I:=LIST2(RLP2,RLP1); 
            L:=COMP(I,L); END; 
      RETURN(L); 
(*8*) END IPRIU; 


PROCEDURE IPRIUP(A: LIST): LIST; 
(*Integral polynomial real root isolation, Uspensky method, positive roots.  
A is a non-zero squarefree univariate integral polynomial.  L
is a list of pairs ((a(1),b(1)), ...,(a(k),b(k))) representing iso-
lating intervals for the positive real roots of A, with a(1) le
b(1) le  ... le a(k) le b(k).  If a(i) lt e(i) then the pair
(a(i), b(i)) represents the open interval (a(i),b(i)) while if
a(i)=b(i) then (a(i),b(i)) represents the closed one-point
interval (a(i),b(i)).  The a(i) and b(i) are rational
numbers except thatone may have b(k) equal to infinity, represented
by 1/0, that is, the pair (1,0).*)
VAR  AL, B, B1, B2, BL, CL, DL, EL, FL, HL, J1Y, L, RL, S, SL,
     TL, UL, VL, VL1, VL2: LIST; 
BEGIN
(*1*) (*initialize.*) L:=BETA; S:=BETA; B:=A; RL:=LIST2(0,1); 
      SL:=LIST2(1,0); TL:=2; VL:=IUPVAR(B); 
(*2*) (*vl=0.*) 
      IF VL = 0 THEN RETURN(L); END; 

LOOP
(*3*) (*vl le 1.*) 
      IF VL <= 1 THEN
         IF FIRST(RL) = 0 THEN RL:=0; END; 
         J1Y:=LIST2(RL,SL); L:=COMP(J1Y,L); (*go to 9;*)
         ELSE 

LOOP
(*4*) (*bisect.*) B1:=IUPTR1(B); J1Y:=PRT(B); B2:=IUPTR1(J1Y); 
      FIRST2(RL, AL,CL); FIRST2(SL, BL,DL); EL:=ISUM(AL,BL); 
      FL:=ISUM(CL,DL); HL:=LIST2(EL,FL); 
      IF TL = 2 THEN UL:=B1; B1:=B2; B2:=UL; END; 
      VL1:=IUPVAR(B1); VL2:=IUPVAR(B2); 
(*5*) (*vl1 ne 0.*) 
      IF VL1 <> 0 THEN S:=COMP4(B1,RL,HL,VL1,S); END; 
(*6*) (*hl a root.*) 
      IF PORD(B2) > 0 THEN J1Y:=-1; S:=COMP4(0,HL,HL,J1Y,S); END; 
(*7*) (*vl2 gt 1.*) 
      IF VL2 <= 1 THEN (*>*) EXIT END;
      B:=B2; RL:=HL; VL:=VL2; TL:=2; 
      END; (* go to 4;*) 

(*8*) (*vl2=1.*) 
      IF VL2 = 1 THEN J1Y:=LIST2(HL,SL); L:=COMP(J1Y,L); END; 

      END; 
(*9*) (*finished.*) 
      IF S = SIL THEN (*<>*) EXIT END;
      ADV4(S, B,RL,SL,VL,S); TL:=1; 
      END; (*go to 3;*) 

      RETURN(L); 
(*12*) END IPRIUP; 


PROCEDURE IPRRLS(A1,A2,L1,L2: LIST;  VAR LS1,LS2: LIST); 
(*Integral polynomial real root list separation.  A1 and A2 are
univariate integral polynomials with no multiple real roots and with
no common real roots.  L1 and L2 are lists of isolating intervals for
some or all of the real roots of A1 and A2, respectively.  The
intervals in L1 and L2 have binary rational endpoints, and are either
left-open and right-closed or one-point intervals. Let
L1 eq (I sub 1,1 , ..., I sub (1,r sub 1) ),
L2 eq (I sub 2,1 , ..., I sub (2,r sub 2) ).
Then I sub 1,1  lt  I sub 1,2  lt   ...  lt  I sub (1,r sub 1)
and  I sub 2,1  lt  I sub 2,2  lt   ...  lt  I sub (2,r sub 2) .
L sub 1 sup *  eq (I sub 1,1 sup * , ..., I sub (1,r sub 1) sup * )
and L sub 2 sup *  eq (I sub 2,1 sup * , ..., I sub (2,r sub 2) sup * ),
where I sub i,j sup * is a binary rational subinterval of
I sub i,j containing the root of A sub i in I sub i,j.
Each I sub 1,j sup * is strongly disjoint from each
I sub 2,j sup *.*)
VAR  I1, I2, LP1, LP2, SL: LIST; 
BEGIN
(*1*) (*initialize.*) 
      IF (L1 = SIL) OR (L2 = SIL) THEN LS1:=L1; LS2:=L2; 
         RETURN; END; 
      ADV(L1, I1,LP1); LS1:=BETA; ADV(L2, I2,LP2); LS2:=BETA; 
(*2*) (*refine and merge.*) 
      REPEAT IPRRS(A1,A2,I1,I2, I1,I2,SL); 
             IF SL < 0 THEN LS1:=COMP(I1,LS1); 
                IF LP1 <> SIL THEN ADV(LP1, I1,LP1); ELSE I1:=0; 
                END; 
                ELSE LS2:=COMP(I2,LS2); 
                IF LP2 <> SIL THEN ADV(LP2, I2,LP2); ELSE I2:=0; 
                END; 
                END; 
             UNTIL (I1 = 0) OR (I2 = 0); 
(*3*) (*finish.*) 
      IF I1 = 0 THEN LS2:=COMP(I2,LS2); 
         WHILE LP2 <> SIL DO ADV(LP2, I2,LP2); LS2:=COMP(I2,LS2); 
               END; 
         ELSE LS1:=COMP(I1,LS1); 
         WHILE LP1 <> SIL DO ADV(LP1, I1,LP1); LS1:=COMP(I1,LS1); 
               END; 
         END; 
      LS1:=INV(LS1); LS2:=INV(LS2); RETURN; 
(*6*) END IPRRLS; 


PROCEDURE IPRRS(A1,A2,I1,I2: LIST;  VAR IS1,IS2,SL: LIST); 
(*Integral polynomial real root separation.  A1 and A2 are squarefree
univariate integral polynomials of positive degrees.  I1 and I2
are intervals with binary rational number endpoints, each of
which is either left-open and right-closed, or a one-point interval.
I1 contains a unique root alpha sub 1 of A1, and I2 contains a
unique root alpha sub 2 ne alpha sub 1 of A2.  I sub 1 sup *
and I sub 2 sup * are binary rational subintervals of I1 and I2
containing alpha sub 1 and alpha sub 2 respectively, with
I sub 1 sup * and I sub 2 sup * strongly disjoint.  If I1 is
left-open and right-closed then so is I sub 1 sup *, and
similarly for I2 and I sub 2 sup *.  s eq -1
if I sub 1 sup *  lt  I sub 2 sup *, and s eq 1
if I sub 1 sup *  gt  I sub 2 sup *.*)
VAR   AL1, AL2, BL1, BL2, CL, DL1, DL2, SL1l, SL1r, SL2l, SL2r, 
      TL, UL, VL: LIST; 
BEGIN
(*1*) (*i1 and i2 disjoint.*) FIRST2(I1, AL1,BL1); FIRST2(I2, AL2,BL2); 
      IF RNCOMP(BL1,AL2) < 0 THEN IS1:=I1; IS2:=I2; SL:=-1; RETURN; 
         END; 
      IF RNCOMP(BL2,AL1) < 0 THEN IS1:=I1; IS2:=I2; SL:=1; RETURN; 
         END; 
(*2*) (*initialize.*) DL1:=RNDIF(BL1,AL1); DL2:=RNDIF(BL2,AL2); 
      SL1l:=IUPBES(A1,AL1); SL2l:=IUPBES(A2,AL2); 
      SL1r:=IUPBES(A1,BL1); SL2r:=IUPBES(A2,BL2); 
LOOP
(*3*) (*bisect i1.*) TL:=RNCOMP(DL1,DL2); 
      IF TL >= 0 THEN
         CL:=RIB(AL1,BL1); UL:=IUPBES(A1,CL);
         IF (SL1r = 0) OR (SL1r*UL < 0) THEN 
            IF (UL = 0) OR (SL1l*UL < 0)   
               THEN (* looks like roots in both intervalls. *)
                    BL1:=CL; SL1r:=UL; VL:=-1;
               ELSE AL1:=CL; SL1l:=UL; VL:=1; END;
            ELSE BL1:=CL; SL1r:=UL; VL:=-1; END; 
         DL1:=RNDIF(BL1,AL1); END; 
(*4*) (*bisect i2.*) 
      IF TL < 0 THEN
         CL:=RIB(AL2,BL2); UL:=IUPBES(A2,CL); 
         IF (SL2r = 0) OR (SL2r*UL < 0) THEN 
            IF (UL = 0) OR (SL2l*UL < 0) 
               THEN (* looks like roots in both intervalls. *)
                    BL2:=CL; SL2r:=UL; VL:=-1; 
               ELSE AL2:=CL; SL2l:=UL; VL:=-1; END;
            ELSE BL2:=CL; SL2r:=UL; VL:=1; END; 
         DL2:=RNDIF(BL2,AL2); END; 
(*5*) (*i1 and i2 disjoint.*) 
      IF (VL < 0) AND (RNCOMP(BL1,AL2) < 0) 
         THEN SL:=-1; EXIT;
         ELSE
         IF (VL > 0) AND (RNCOMP(BL2,AL1) < 0) 
            THEN SL:=1; EXIT; 
            (*else go to 3;*) END; 
         END; 
      END; (*loop*)
      IS1:=LIST2(AL1,BL1); IS2:=LIST2(AL2,BL2); RETURN; 
(*8*) END IPRRS; 


PROCEDURE IPSFSD(RL,A: LIST): LIST; 
(*Integral squarefree factorization, second derivative.  A is a
positive integral polynomial in r variables of positive degree L is a
list ((e(1),A(1)), ...,(e(k),A(k))) where primitive part of A
is equal to the sum of A(i)**e(i) for i=1, ...,k.  The a(i) are
pairwise relatively prime squarefree positive polynomials of
positive degrees, with deg(A(i))=1 or GCD(A(i),APP(i))=1 for all
i where APP(i) is the second derivative of A(i) and the e(i) are
positive beta-integers e(1) le e(2) le  ... le e(k).*)
VAR  A1, AB, EL, L, L1, LB, P: LIST; 
BEGIN
(*1*) (*compute primitive part.*) AB:=IPPP(RL,A); 
(*2*) (*squarefree factorization.*) LB:=IPSF(RL,AB); 
(*3*) (*apply ipfsd.*) L:=BETA; LB:=INV(LB); 
      REPEAT ADV(LB, P,LB); FIRST2(P, EL,A1); L1:=IPFSD(RL,A1); 
             WHILE L1 <> SIL DO ADV(L1, A1,L1); P:=LIST2(EL,A1); 
                   L:=COMP(P,L); END; 
             UNTIL LB = SIL; 
      RETURN(L); 
(*6*) END IPSFSD; 


PROCEDURE IPSRM(A,I: LIST): LIST; 
(*Integral polynomial strong real root isolation, modified Uspensky method. 
A is a univariate integral polynomial with multiple roots and
with no real roots in common with APP.  I is either the null list () or
a standard interval or an interval whose positive and non-negative
parts are standard.  L is a list (I(1), ...,I(r)) of isolating intervals
for  all the real roots of A if I=(), or for all the real roots of A in
I if I ne ().  The intervals I(j) contain no roots of AP or APP, are
left-open and right-closed, have binary rational endpoints, and
satisfy I(1) lt I(2) lt  ... lt I(r).*)
VAR  AL, BL, I1, I2, L, L1, L2, NL: LIST; 
BEGIN
(*1*) (*degree zero.*) NL:=PDEG(A); 
      IF NL = 0 THEN L:=BETA; RETURN(L); END; 
(*2*) (*compute intervals.*) 
      IF I = SIL THEN BL:=IUPRB(A); AL:=RNNEG(BL); I1:=LIST2(AL,0); 
         I2:=LIST2(0,BL); ELSE FIRST2(I, AL,BL); 
         IF RNSIGN(AL) >= 0 THEN I1:=BETA; I2:=I; ELSE
            IF RNSIGN(BL) <= 0 THEN I1:=I; I2:=BETA; ELSE
               I1:=LIST2(AL,0); I2:=LIST2(0,BL); END; 
            END; 
         END; 
(*3*) (*compute non-positive roots.*) 
      IF I1 <> SIL THEN L1:=IPSRMS(A,I1); ELSE L1:=BETA; END; 
(*4*) (*compute positive roots.*) 
      IF I2 <> SIL THEN L2:=IPSRMS(A,I2); ELSE L2:=BETA; END; 
(*5*) (*concatenate.*) L:=CONC(L1,L2); RETURN(L); 
(*8*) END IPSRM; 


PROCEDURE IPSRMS(A,I: LIST): LIST; 
(*Integral polynomial strong real root isolation, modified Uspensky method, standard interval. 
A is a univariate integral polynomial with no multiple real roots 
and with no real roots in common with APP.  I is
a standard interval.  L is a list (I(1), ...,I(r)) of isolating
intervals for the roots of A in I.  The intervals I(j) contain no
roots of AP or APP, are left-open and right-closed, have binary rational
endpoints, are subintervals of I, and satisfy I(1) lt I(2) lt  ...
lt I(r).*)
VAR  AP, APP, APPS, APPSP, APS, APSP, L, LP, LPP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN L:=BETA; RETURN(L); END; 
(*2*) (*isolate roots of a.*) AP:=IPDMV(1,A); L:=IPRIMS(A,AP,I); 
(*3*) (*remove roots of ap.*) APS:=IPPGSD(1,AP); APSP:=IPDMV(1,APS); 
      LP:=IPRIMS(APS,APSP,I); 
      IPRRLS(A,APS,L,LP, L,LP); 
(*4*) (*remove roots of app.*) APP:=IPDMV(1,AP); APPS:=IPPGSD(1,APP); 
      LPP:=IPRIMS(APPS,APPSP,I); 
      IPRRLS(A,APPS,L,LPP, L,LPP); 
      RETURN(L); 
(*7*) END IPSRMS; 


PROCEDURE IPVCHT(A: LIST): LIST; 
(*Integral polynomial variations after circle to half-plane transformation.  
A is a non-zero univariate integral polynomial.  Let
n=deg(A), AP(x)=(x**n)*A(1/x), B(x)=AP(x+1).  k is the number of
sign variations in the coefficients of B.*)
VAR  AP, B, KL: LIST; 
BEGIN
(*1*) AP:=PRT(A); B:=IUPTR1(AP); KL:=IUPVAR(B); RETURN(KL); 
(*4*) END IPVCHT; 


PROCEDURE IUPRB(A: LIST): LIST; 
(*Integral univariate polynomial root bound.  A is an integral poly-
nomial of positive degree.  b is a binary rational number which is a
root bound for A.  If A(x) is equal to the sum of a(i)*x(i)**i for
i=0, ...,n, a(n) ne 0, then b is the smallest power of 2 such that
2*abs(a(n-k)/a(n))**(1/k) le b for 1 le k le n.  If
a(n-k)=0 for 1 le k le n then b=1.*)
VAR  AL, AL1, ALB, ALB1, ALBP, AP, BL, DL, HL, HL1, J1Y, KL, ML, ML1,
     NL, NL1, QL, RL, SL, TL: LIST; 
BEGIN
(*1*) (*initialize.*) ADV2(A, NL,AL,AP); 
      IF AP = SIL THEN HL:=-1; (*go to 3;*)
         ELSE 

      ALB:=IABSF(AL); ML:=ILOG2(ALB); TL:=0; 
(*2*) (*process terms.*) 
      REPEAT ADV2(AP, NL1,AL1,AP); KL:=NL-NL1; ML1:=ILOG2(AL1); 
             J1Y:=ML1-ML; DL:=J1Y-1; MASQREM(DL,KL, QL,RL); 
             IF RL < 0 THEN RL:=RL+KL; QL:=QL-1; END; 
             HL1:=QL+1; 
             IF RL = KL-1 THEN ALB1:=IABSF(AL1); J1Y:=HL1*KL; 
                J1Y:=-J1Y; ALBP:=ITRUNC(ALB,J1Y); SL:=ICOMP(ALB1,ALBP); 
                IF SL > 0 THEN HL1:=HL1+1; END; 
                END; 
             IF (TL = 0) OR (HL1 > HL) THEN HL:=HL1; END; 
             TL:=1; 
             UNTIL AP = SIL; 
END; (*go to 3*)

(*3*) (*compute bl.*) J1Y:=HL+1; BL:=RNP2(J1Y); RETURN(BL); 
(*6*) END IUPRB; 


PROCEDURE IUPRLP(A: LIST): LIST; 
(*Integral univariate polynomial, root of a linear polynomial.
A is an integral univariate polynomial of degree one.  r is
the unique rational number such that A(r)=0.*)
VAR  AL, BL, J1Y, L, RL: LIST; 
BEGIN
(*1*) IF PRED(A) = 0 THEN RL:=0; ELSE L:=PCL(A); FIRST2(L, AL,BL); 
         J1Y:=INEG(BL); RL:=RNRED(J1Y,AL); RETURN(RL); END; 
(*4*) RETURN(RL); END IUPRLP; 


PROCEDURE IUPVAR(A: LIST): LIST; 
(*Integral univariate polynomial variations.  A is a non-zero uni-
variate integral polynomial.  n is the number of sign variations in
the coefficients of A.*)
VAR  AL, AP, EL, NL, SL, TL: LIST; 
BEGIN
(*1*) NL:=0; AP:=A; ADV2(AP, EL,AL,AP); SL:=ISIGNF(AL); 
      WHILE AP <> SIL DO ADV2(AP, EL,AL,AP); TL:=ISIGNF(AL); 
            IF SL <> TL THEN NL:=NL+1; SL:=TL; END; 
            END; 
      RETURN(NL); 
(*4*) END IUPVAR; 


PROCEDURE IUPVSI(A,I: LIST): LIST; 
(*Integral univariate polynomial, variations for standard interval.  
A is a non-zero integral univariate polynomial.  I is
a standard open interval.  Let T(z) be the transformation mapping the
right half-plane onto the circle having I as a diameter.
Let B(x)=A(T(x)).  Then v is the number of sign variations in the
coefficients of B.*)
VAR  AL, B, BL, C, DL, HL, KL, KLP, VL: LIST; 
BEGIN
(*1*) (*compute hl and kl such that i=(al,bl), al=hl*2**kl and
            bl=(hl+1)*2**kl.*) FIRST2(I, AL,BL); DL:=RNDIF(BL,AL); 
      RNFCL2(DL, KL,KLP); 
      IF AL <> 0 THEN HL:=RNQ(AL,DL); HL:=FIRST(HL); ELSE HL:=0; 
      END; 
(*2*) (*transform and count variations.*) 
      IF KL <> 0 THEN B:=IUPBHT(A,KL); ELSE B:=A; END; 
      IF HL <> 0 THEN C:=IUPTR(B,HL); ELSE C:=B; END; 
      VL:=IPVCHT(C); RETURN(VL); 
(*5*) END IUPVSI; 


PROCEDURE RIB(RL,SL: LIST): LIST; 
(*Rational interval bisection.  r and s are binary rational numbers,
r lt s.  t is a binary rational number with r lt t lt s, defined
as follows.  Let h=floor(log2(s-r)) and let c be the least integer
such that c*2**h gt r.  Then t=c*2**h if c*2**h lt s and
t=(2*c-1)*2**(h-1) otherwise.*)
VAR  CL, DL, EL, H, HL, HLP, NL, QL, TL: LIST; 
BEGIN
(*1*) (*compute hlp=2**hl.*) DL:=RNDIF(RL,SL); RNFCL2(DL, HL,NL); 
      HLP:=RNP2(HL); 
(*2*) (*compute tl.*) QL:=RNQ(RL,HLP); CL:=RNCEIL(QL); CL:=RNINT(CL); 
      TL:=RNPROD(CL,HLP); EL:=RNCOMP(TL,RL); 
      IF EL = 0 THEN TL:=RNSUM(TL,HLP); END; 
      EL:=RNCOMP(TL,SL); 
      IF EL >= 0 THEN H:=LIST2(1,2); HLP:=RNPROD(HLP,H); 
         TL:=RNDIF(TL,HLP); END; 
      RETURN(TL); 
(*5*) END RIB; 


PROCEDURE RILC(I,KL: LIST): LIST; 
(*Rational interval length comparison.  I is an interval (a,b) with
rational endpoints, a le b.  k is a gamma-integer.  t=1 if b-a le
2**k and t=0 otherwise.*)
VAR  AL, BL, DL, ML, NL, TL: LIST; 
BEGIN
(*1*) FIRST2(I, AL,BL); DL:=RNDIF(BL,AL); TL:=1; 
      IF DL <> 0 THEN RNFCL2(DL, ML,NL); 
         IF NL > KL THEN TL:=0; END; 
         END; 
      RETURN(TL); 
(*4*) END RILC; 


PROCEDURE RINT(I: LIST): LIST; 
(*Rational interval normalizing transformation.  I is a list (r,s)
with rational endpoints and r lt s.  IS is the list (rs,ss)=
psi(r,s).*)
VAR  DL, HL, IS, J1Y, KL, KLP, RL, RLS, SL, SLS, TL: LIST; 
BEGIN
(*1*) (*compute hl=floor(log2(sl-rl))-1 and tl=2**hl.*) FIRST2(I,
      RL,SL); DL:=RNDIF(SL,RL); RNFCL2(DL, KL,KLP); HL:=KL-1; 
      TL:=RNP2(HL); 
(*2*) (*compute rls.*) J1Y:=RNQ(RL,TL); RLS:=RNFLOR(J1Y); 
      IF RLS <> 0 THEN RLS:=LIST2(RLS,1); RLS:=RNPROD(RLS,TL); END; 
(*3*) (*compute sls.*) J1Y:=RNQ(SL,TL); SLS:=RNCEIL(J1Y); 
      IF SLS <> 0 THEN SLS:=LIST2(SLS,1); SLS:=RNPROD(SLS,TL); END; 
(*4*) (*finish.*) IS:=LIST2(RLS,SLS); RETURN(IS); 
(*7*) END RINT; 


END SACROOT.
(* -EOF- *)
