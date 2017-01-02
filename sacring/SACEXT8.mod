(* ----------------------------------------------------------------------------
 * $Id: SACEXT8.mi,v 1.4 1993/05/11 10:51:42 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT8.mi,v $
 * Revision 1.4  1993/05/11  10:51:42  kredel
 * Spelling errors corr.
 *
 * Revision 1.3  1992/10/15  16:29:00  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:56  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:07  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT8;

(* SAC Extensions 8 Implementation Module. *)


(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA, INV, LIST1,
                    COMP, SRED, ADV, FIRST, RED, SFIRST;

FROM MASELEM IMPORT MASMAX, MASQREM; 

FROM SACLIST IMPORT COMP4, FIRST4, COMP2, LIST2, SECOND, CINV, 
                    OWRITE, CONC, MEMBER, EQUAL, ADV2, FIRST2, LAST;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM SACI IMPORT IDIF, IEXP, IPROD, INEG;

FROM SACM IMPORT MDHOM, MDINV;

FROM SACRN IMPORT RNINT, RNRED, RNFCL2, RNCOMP, RNDIF, 
                  RNSUM, RNNEG, RNQ, RNSIGN, RNP2, RIRNP;

FROM SACPOL IMPORT PBIN, PTBCF, PDEG, PLDCF, PMON, PLBCF, PINV, PRED, PCL;

FROM SACIPOL IMPORT IPEXP, IPNEG, IPPROD, IPDMV, IPQ, IPPSR,
                    IPIP, IUPBES, IUPBRE, IPCRA, IPMAXN, IPGSUB;

FROM SACRPOL IMPORT RPFIP;

FROM SACMPOL IMPORT MPDIF, MPMDP, MPPROD, MPHOM, MPQR;

FROM SACRPOL IMPORT RPQR, RPRNP;

FROM SACEXT2 IMPORT RNBCR;

FROM SACEXT4 IMPORT IPINT, RPMAIP;

FROM SACEXT5 IMPORT IUPRC, MUPRC, IPPSC, IPLCPP, IPDSCR;

FROM SACEXT7 IMPORT IUPVOI, ISFPIR;

FROM MASRN IMPORT RNDWRS;

FROM DIPC IMPORT PPERMV;

FROM SACPGCD IMPORT IPPP, IPSRP, IPCPP, IPGCDC, IPSPRS, 
                    IPSCPP, IPRES, IPPGSD;

FROM SACROOT IMPORT IPRIM, RIB, IUPRB, IUPRLP;

FROM SACPFAC IMPORT IPFAC;

FROM SACANF IMPORT AFDIF, AFSIGN, AFPROD, AFQ, AFNEG, AFSUM, AFINV;

FROM SACUPFAC IMPORT IUSFPF;

CONST rcsidi = "$Id: SACEXT8.mi,v 1.4 1993/05/11 10:51:42 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE AFCOMP(MB,I,AL,BL: LIST): LIST; 
(*Algebraic number field comparison.  MB is the integral minimal
polynomial of a real algebraic number alpha.  I is an acceptable
isolating interval for alpha.  a and b are elements of
Q( alpha ).  t eq SIGN(a-b).*)
VAR   CL, TL: LIST; 
BEGIN
(*1*) CL:=AFDIF(AL,BL); TL:=AFSIGN(MB,I,CL); RETURN(TL); 
(*4*) END AFCOMP; 


PROCEDURE AFFINT(M: LIST): LIST; 
(*Algebraic number field element from integer.  M is an
integer.  A is M represented as an element of an algebraic
number field.*)
VAR   AL, R: LIST; 
BEGIN
(*1*) R:=RNINT(M); AL:=PMON(R,0); RETURN(AL); 
(*4*) END AFFINT; 


PROCEDURE AFFRN(R: LIST): LIST; 
(*Algebraic number field element from rational number.  R is a
rational number.  A is R represented as an element of an algebraic
number field.*)
VAR   AL: LIST; 
BEGIN
(*1*) AL:=PMON(R,0); RETURN(AL); 
(*4*) END AFFRN; 


PROCEDURE AFPAFP(RL,M,AL,B: LIST): LIST; 
(*Algebraic number field polynomial algebraic number field element product.  
M is the rational minimal polynomial of an algebraic number alpha.  
a is an element of Q( alpha ).  B is a polynomial
over Q( alpha ) in r variables, r ge 1.  C eq a cdot B.*)
VAR   BL, BP, C, CL, EL, RLP: LIST; 
BEGIN
(*1*) (*c=0.*) 
      IF (AL = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*general case.*) BP:=B; C:=BETA; RLP:=RL-1; 
      REPEAT ADV2(BP, EL,BL,BP); 
             IF RLP = 0 THEN CL:=AFPROD(M,AL,BL); ELSE
                CL:=AFPAFP(RLP,M,AL,BL); END; 
             C:=COMP2(CL,EL,C); 
             UNTIL BP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END AFPAFP; 


PROCEDURE AFPAFQ(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field polynomial algebraic number field element quotient.  
M is the rational minimal polynomial of an algebraic
number alpha.  A is a polynomial over Q( alpha ) in r variables,
r ge 1.  b is an element of Q( alpha ).  C eq A/b.*)
VAR   AL, AP, C, CL, EL, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
(*2*) (*a ne 0.*) AP:=A; RLP:=RL-1; C:=BETA; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 0 THEN CL:=AFQ(M,AL,BL); ELSE
                CL:=AFPAFQ(RLP,M,AL,BL); END; 
             C:=COMP2(CL,EL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END AFPAFQ; 


(* -- depends indirectly on AFPRII :-(
PROCEDURE AFPBRI(M,MB,I,L: LIST): LIST; 
(*Algebraic number field polynomial basis real root isolation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  L is a
nonempty squarefree basis (A sub 1 ,... , A sub n ) of univariate
polynomials over Q( alpha ).  N is a list (i sub 1 ,b sub 1
,... , i sub m ,b sub m ), m ge 0, where i sub 1 lt i sub 2 lt  ...   lt
i sub m are strongly disjoint isolating intervals for all
the real roots of a eq prod from (j eq 1) to n (a sub j).
each i sub i has binary rational endpoints and is left open
and right closed.  b sub i is the unique a sub j which has
a root in i sub i.*)
VAR   A1, A2, B1, I1, I11, I21, J1Y, J2Y, LP, LPP, ML, N, S, S1, S2, SL,
     SP, SPP, SS1, SS2, T, T1, T2: LIST; 
BEGIN
(*1*) (*isolate roots of each a sub i.*) LP:=L; S:=BETA; 
      REPEAT ADV(LP, A1,LP); S1:=AFPRCL(M,MB,I,A1); S:=COMP(S1,S); 
             UNTIL LP = SIL; 
      S:=INV(S); 
(*2*) (*refine to disjoint isolating intervals.*) LP:=L; SP:=S; 
      WHILE RED(LP) <> SIL DO A1:=FIRST(LP); S1:=FIRST(SP); 
            LPP:=RED(LP); SPP:=RED(SP); 
            REPEAT A2:=FIRST(LPP); S2:=FIRST(SPP); 
                   AFPRLS(M,MB,I,A1,A2,S1,S2, SS1,SS2); S1:=SS1; 
                   SFIRST(SPP,SS2); LPP:=RED(LPP); SPP:=RED(SPP); 
                   UNTIL LPP = SIL; 
            SFIRST(SP,S1); LP:=RED(LP); SP:=RED(SP); END; 
(*3*) (*prepare to merge intervals.*) LP:=L; SP:=S; T:=BETA; 
      REPEAT ADV(LP, A1,LP); ADV(SP, S1,SP); T1:=BETA; 
             WHILE S1 <> SIL DO ADV2(S1, I11,ML,S1); 
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
      N:=FIRST(T); RETURN(N); 
(*7*) END AFPBRI; 
*)


(* -- depends on AFPRII :-(
PROCEDURE AFPCLL(M,MB,I,A: LIST): LIST; 
(*Algebraic number field polynomial real root isolation, Collins-Loos algorithm, list output version.  
M is the rational minimal polynomial of a real algebraic number alpha.
MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial of degree n ge 0 over Q( alpha ).
If n eq 0 then L eq ().
If n gt 0, then L eq (L sub 0 ,... , L sub n-1 ),
where L sub i is a strong isolation list for the real roots
of der sup i (A).*)
VAR   AP, AS, BL, C, DL, L, L1, LP1: LIST; 
BEGIN
(*1*) (*degree zero.*) L:=BETA; 
      IF PDEG(A) = 0 THEN RETURN(L); END; 
(*2*) (*initialize.*) AS:=A; AP:=AFPDMV(1,M,A); C:=BETA; 
(*3*) (*compute derivatives.*) 
      WHILE PDEG(AS) > 1 DO BL:=PTBCF(1,AS); C:=COMP(BL,C); AS:=AP; 
            AP:=AFPDMV(1,M,AS); END; 
(*4*) (*isolate roots.*) LP1:=BETA; DL:=AFUPRB(MB,I,A); 
      REPEAT L1:=AFPRII(M,MB,I,AS,AP,DL,LP1); L:=COMP(L1,L); 
             IF C = SIL THEN RETURN(L); END; 
             ADV(C, BL,C); AP:=AS; AS:=AFPINT(1,M,AP,BL); LP1:=L1; 
             UNTIL FALSE; 
(*7*) RETURN(L); END AFPCLL; 
*)

PROCEDURE AFPDIF(RL,A,B: LIST): LIST; 
(*Algebraic number field polynomial difference.  A and B are
polynomials in r variables, r ge 0, over Q( alpha ), for some
algebraic number alpha.  C=A-B.*)
VAR   AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF A = 0 THEN C:=AFPNEG(RL,B); RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN C:=AFDIF(A,B); RETURN(C); END; 
(*3*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1; 
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP); 
             IF EL > FL THEN ADV2(AP, EL,AL,AP); 
                CP:=COMP2(AL,EL,CP); ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP); 
                   IF RLP = 0 THEN CL:=AFNEG(BL); ELSE
                      CL:=AFPNEG(RLP,BL); END; 
                   CP:=COMP2(CL,FL,CP); ELSE ADV2(AP, EL,AL,AP); 
                   ADV2(BP, FL,BL,BP); 
                   IF RLP = 0 THEN CL:=AFDIF(AL,BL); ELSE
                      CL:=AFPDIF(RLP,AL,BL); END; 
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*4*) (*finish.*) 
      IF (AP = SIL) AND (BP = SIL) THEN CPP:=BETA; ELSE
         IF AP = SIL THEN CPP:=AFPNEG(RL,BP); ELSE CPP:=AP; END; 
         END; 
      C:=INV(CP); 
      IF C = SIL THEN C:=CPP; ELSE SRED(CP,CPP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*7*) END AFPDIF; 


PROCEDURE AFPDMV(RL,M,A: LIST): LIST; 
(*Algebraic number field polynomial derivative, main variable.
M is the rational minimal polynomial of an algebraic number alpha.
A is a polynomial over Q( alpha ) in r variables, r ge 1.  B is
the derivative of a with respect to its main variable.*)
VAR   AL, AP, B, BL, EL, ELP, J1Y, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AP:=A; RLP:=RL-1; B:=BETA; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 0 THEN J1Y:=AFFINT(EL); BL:=AFPROD(M,J1Y,AL); 
                ELSE J1Y:=AFFINT(EL); BL:=AFPAFP(RLP,M,J1Y,AL); END; 
             ELP:=EL-1; 
             IF EL <> 0 THEN B:=COMP2(BL,ELP,B); END; 
             UNTIL AP = SIL; 
      B:=INV(B); 
      IF B = SIL THEN B:=0; END; 
      RETURN(B); 
(*5*) END AFPDMV; 


PROCEDURE AFPEMV(RL,M,A,AL: LIST): LIST; 
(*Algebraic number field polynomial evaluation of main variable.
M is the rational minimal polynomial of an algebraic number alpha.
A is a polynomial over Q( alpha ) in r variables, r ge 1.  a is an
element of Q( alpha ).  B( x sub 1 ,... , x sub r-1 ) eq
A(x sub 1 ,... , x sub r-1 ,a).*)
VAR   A2, AP, B, EL1, EL2, IL, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*apply horners method.*) ADV2(A, EL1,B,AP); RLP:=RL-1; 
      WHILE AP <> SIL DO ADV2(AP, EL2,A2,AP); 
            FOR IL:=1 TO EL1-EL2 DO
                IF RLP = 0 THEN B:=AFPROD(M,AL,B); ELSE
                   B:=AFPAFP(RLP,M,AL,B); END; 
                END; 
            IF RLP = 0 THEN B:=AFSUM(B,A2); ELSE
               B:=AFPSUM(RLP,B,A2); END; 
            EL1:=EL2; END; 
      FOR IL:=1 TO EL1 DO
          IF RLP = 0 THEN B:=AFPROD(M,AL,B); ELSE
             B:=AFPAFP(RLP,M,AL,B); END; 
          END; 
      RETURN(B); 
(*5*) END AFPEMV; 


PROCEDURE AFPEV(RL,M,A,IL,AL: LIST): LIST; 
(*Algebraic number field polynomial evaluation.  M is the rational
minimal polynomial of an algebraic number alpha.  A is a
polynomial in r ge 1 variables over Q( alpha ).  i satisfies
1 le i le r, and a is an element of Q( alpha ).
B(x sub 1 ,... , x sub i-1 , x sub i+1 ,... , x sub r) eq
A(x sub 1 ,... , x sub i-1 , a , x sub i+1 ,... , x sub r ).*)
VAR   A1, AP, B, B1, EL1, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*il=rl.*) 
      IF IL = RL THEN B:=AFPEMV(RL,M,A,AL); RETURN(B); END; 
(*3*) (*il lt rl.*) RLP:=RL-1; AP:=A; B:=BETA; 
      REPEAT ADV2(AP, EL1,A1,AP); B1:=AFPEV(RLP,M,A1,IL,AL); 
             IF B1 <> 0 THEN B:=COMP2(B1,EL1,B); END; 
             UNTIL AP = SIL; 
      B:=INV(B); 
      IF B = SIL THEN B:=0; END; 
      RETURN(B); 
(*6*) END AFPEV; 


PROCEDURE AFPFIP(RL,A: LIST): LIST; 
(*Algebraic number field polynomial from integral polynomial.  A is
an integral polynomial in r variables, r ge 1.  B is a represented as
a polynomial over an algebraic number field.*)
VAR   AL, AP, B, BL, EL, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN B:=AFFINT(A); RETURN(B); END; 
(*3*) (*recursion on rl.*) B:=BETA; AP:=A; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); BL:=AFPFIP(RLP,AL); B:=COMP2(BL,EL,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*6*) END AFPFIP; 


PROCEDURE AFPFRP(RL,A: LIST): LIST; 
(*Algebraic number field polynomial from rational polynomial.  A is
a rational polynomial in r variables, r ge 1.  B is a represented as
a polynomial over an algebraic number field.*)
VAR   AL, AP, B, BL, EL, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN B:=AFFRN(A); RETURN(B); END; 
(*3*) (*recursion on rl.*) B:=BETA; AP:=A; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); BL:=AFPFRP(RLP,AL); B:=COMP2(BL,EL,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*6*) END AFPFRP; 


PROCEDURE AFPINT(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field polynomial integration.  M is the rational
minimal polynomial of an algebraic number alpha. A is a nonzero
polynomial over Q( alpha ) in r variables, r ge 1.  b is a polynomial
over Q( alpha ) in r-1 variables.  B eq B(x sub 1 ,... , x sub r )
is the integral of a with respect to its main variable, such that
B(x sub 1 ,... , x sub r-1 ,0) eq b.*)
VAR   AL, AP, B, CL, EL, J1Y, RLP: LIST; 
BEGIN
(*1*) AP:=A; B:=BETA; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); EL:=EL+1; 
             IF RL = 1 THEN J1Y:=AFFINT(EL); CL:=AFQ(M,AL,J1Y); 
                ELSE J1Y:=AFFINT(EL); CL:=AFPAFQ(RLP,M,AL,J1Y); END; 
             B:=COMP2(CL,EL,B); 
             UNTIL AP = SIL; 
      IF BL <> 0 THEN B:=COMP2(BL,0,B); END; 
      B:=INV(B); RETURN(B); 
(*4*) END AFPINT; 


PROCEDURE AFPME(RL,M,A,BL: LIST): LIST; 
(*Algebraic number field, polynomial multiple evaluation.
M is the rational minimal polynomial of an algebraic number
alpha.  A eq A(x sub 1 ,... , x sub r ) is a polynomial in
r ge 1 variables over Q( alpha ).  b eq (b sub 1 ,... , b sub k )
is a list of k elements of Q( alpha ) for some k, 1 le k le r.
B eq A(b sub 1 ,... , b sub k ,x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)
VAR   B, BL1, BLP, IL, J1Y: LIST; 
BEGIN
(*1*) IL:=0; BLP:=BL; B:=A; 
      REPEAT IL:=IL+1; ADV(BLP, BL1,BLP); J1Y:=RL-IL; J1Y:=J1Y+1; 
             B:=AFPEV(J1Y,M,B,1,BL1); 
             UNTIL BLP = SIL; 
      RETURN(B); 
(*4*) END AFPME; 


PROCEDURE AFPMON(RL,M,A: LIST): LIST; 
(*Algebraic number field polynomial monic.  A is a polynomial in
r variables, r ge 1, over Q( alpha ) for some algebraic number
alpha.  M is the rational minimal polynomial of alpha.
If A is nonzero then AP is the monic polynomial over Q( alpha )
similar to A.  If A eq 0 then AP eq 0.*)
VAR   AL, ALP, AP: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN AP:=0; RETURN(AP); END; 
(*2*) (*a ne 0.*) AL:=PLBCF(RL,A); ALP:=AFINV(M,AL); 
      AP:=AFPAFP(RL,M,ALP,A); RETURN(AP); 
(*5*) END AFPMON; 


PROCEDURE AFPMPR(M,MB,I,B,J,L: LIST;  VAR JS,JL: LIST); 
(*Algebraic number field polynomial minimal polynomial of a real root.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  I
is an acceptable isolating interval for alpha.  J is an interval
with binary rational number endpoints which is either left-open and
right-closed, or a one-point interval.  B is a univariate polynomial
over Q( alpha ) having a unique root beta of odd multiplicity
in j.  L is a nonempty list of positive irreducible univariate
integral polynomials exactly one of which has beta as a root.
j is the index in L of the unique element n of L having beta
as a root, and js is a subinterval of j with binary rational
endpoints which is an isolating interval for beta as a root of n.
js is either left-open and right-closed or a one-point interval.*)
VAR   AL, BL, CL, JLP, L1, LP, SL, TL, VL, VLP: LIST; 
BEGIN
(*1*) (*initialize.*) FIRST2(J, AL,BL); TL:=AFUPSR(M,MB,I,B,BL); 
LOOP 
      IF TL = 0 THEN EXIT; (*GO TO 4;*) END; 
LOOP LOOP
(*2*) (*test for real roots of each l sub i in current interval.*) 
      VL:=0; JLP:=0; LP:=L; JS:=LIST2(AL,BL); 
      REPEAT ADV(LP, L1,LP); JLP:=JLP+1; VLP:=IUPVOI(L1,JS); 
             IF VLP > 1 THEN EXIT; (*GO TO 3;*) END; 
             IF VLP = 1 THEN
                IF VL = 1 THEN EXIT; (*GO TO 3;*) 
                          ELSE VL:=1; JL:=JLP; END; 
                END; 
             UNTIL LP = SIL; 
      RETURN; 
      END; (*loop*)
(*3*) (*bisect current interval.*) CL:=RIB(AL,BL); 
      SL:=AFUPSR(M,MB,I,B,CL); 
      IF SL = 0 THEN BL:=CL; EXIT; (*GO TO 4;*) ELSE
         IF SL*TL < 0 THEN AL:=CL; ELSE BL:=CL; TL:=SL; END; 
         END; 
      (*GO TO 2;*) 
      END; (*loop*)
      END; (*loop*)
(*4*) (*b has root at right end point of current interval.*) JL:=0; 
      JS:=LIST2(BL,BL); LP:=L; 
      REPEAT ADV(LP, L1,LP); JL:=JL+1; 
             IF PDEG(L1) = 1 THEN
                IF IUPBES(L1,BL) = 0 THEN RETURN; END; 
                END; 
             UNTIL FALSE; 
(*7*) END AFPMPR; 


PROCEDURE AFPNEG(RL,A: LIST): LIST; 
(*Algebraic number field polynomial negative.  A is a polynomial in
r variables, r ge 0, over Q( alpha ) for some algebraic number
alpha.  B=-A.*)
VAR   AL, AP, B, BL, EL, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN B:=AFNEG(A); RETURN(B); END; 
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 0 THEN BL:=AFNEG(AL); ELSE
                BL:=AFPNEG(RLP,AL); END; 
             B:=COMP2(BL,EL,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*6*) END AFPNEG; 


PROCEDURE AFPNIP(MB,A: LIST): LIST; 
(*Algebraic number field polynomial normalize to integral polynomial.
MB is the integral minimal polynomial of an algebraic number alpha.
A is a univariate polynomial over Q( alpha ) of positive degree.
l is a list (l sub 1 ,... , l sub n ), n ge 1, of the positive
irreducible factors of positive degree of a univariate integral
polynomial which has among its roots the roots of A.*)
VAR   AP, C, CL, DL, J1Y, L, L1, LP, MP, SL: LIST; 
BEGIN
(*1*) (*check for a having only rational coefficients.*) IPSRP(2,A,
      DL,AP); J1Y:=LIST2(2,1); AP:=PPERMV(2,AP,J1Y); 
LOOP 
      IF PDEG(AP) = 0 THEN C:=PLDCF(AP); EXIT; (*GO TO 3;*) END; 
(*2*) (*compute resultant of a and mb.*) MP:=PINV(1,MB,1); 
      C:=IPRES(2,AP,MP); 
      EXIT; END; (*loop*) 
(*3*) (*factor resultant.*) IPFAC(1,C, SL,CL,LP); L:=BETA; 
      REPEAT ADV(LP, L1,LP); J1Y:=SECOND(L1); L:=COMP(J1Y,L); 
             UNTIL LP = SIL; 
      L:=INV(L); RETURN(L); 
(*6*) END AFPNIP; 


PROCEDURE AFPPR(RL,M,A,B: LIST): LIST; 
(*Algebraic number field polynomial product.  A and B are polynomials
in r variables, r ge 0, over Q( alpha ) for some algebraic number
alpha.  M is the rational minimal polynomial of alpha.  C=A*B.*)
VAR   AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN C:=AFPROD(M,A,B); RETURN(C); END; 
(*3*) (*general case.*) AS:=CINV(A); BS:=CINV(B); C:=0; RLP:=RL-1; 
      REPEAT ADV2(BS, BL,FL,BS); AP:=AS; C1:=BETA; 
             REPEAT ADV2(AP, AL,EL,AP); 
                    IF RLP = 0 THEN CL:=AFPROD(M,AL,BL); ELSE
                       CL:=AFPPR(RLP,M,AL,BL); END; 
                    J1Y:=EL+FL; C1:=COMP2(J1Y,CL,C1); 
                    UNTIL AP = SIL; 
             C:=AFPSUM(RL,C,C1); 
             UNTIL BS = SIL; 
      RETURN(C); 
(*6*) END AFPPR; 


PROCEDURE AFPQR(RL,M,A,B: LIST;  VAR Q,R: LIST); 
(*Algebraic number field polynomial quotient and remainder.  A and B,
B ne 0, are polynomials in r variables, r ge 1, over Q( alpha ), for
some algebraic number alpha.  M is the rational minimal polynomial
of alpha.  Q and R are the unique algebraic number field polynomials
such that either B divides A, Q eq B/A, and r eq 0 or else B does not
divide A and A eq BQ+R with degree(R) minimal.*)
VAR   AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL: LIST; 
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BL:=PLDCF(B); BP:=PRED(B); Q:=BETA; 
      R:=A; RLP:=RL-1; 
(*2*) (*compute quotient terms.*) 
LOOP
      WHILE R <> 0 DO ML:=PDEG(R); DL:=ML-NL; 
            IF DL < 0 THEN EXIT; (*GO TO 3;*) END; 
            AL:=PLDCF(R); 
            IF RLP = 0 THEN QL:=AFQ(M,AL,BL); SL:=0; ELSE
               AFPQR(RLP,M,AL,BL, QL,SL); END; 
            IF SL <> 0 THEN EXIT; (*GO TO 3;*) END; 
            Q:=COMP2(QL,DL,Q); Q1:=LIST2(DL,QL); RP:=PRED(R); 
            QP:=AFPPR(RL,M,BP,Q1); R:=AFPDIF(RL,RP,QP); END; 
      EXIT; END; (*loop*) 
(*3*) (*finish.*) 
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END; 
      RETURN; 
(*6*) END AFPQR; 


(* -- depends on AFPRII :-(
PROCEDURE AFPRCL(M,MB,I,A: LIST): LIST; 
(*Algebraic number field polynomial real root isolation, Collins-Loos algorithm.  
M is the rational minimal polynomial of a real algebraic
number alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial of degree n ge 0 over Q( alpha ).  L is a
strong isolation list for the real roots of a.*)
VAR   AP, AS, BL, C, DL, L, LP: LIST; 
BEGIN
(*1*) (*degree zero.*) 
      IF PDEG(A) = 0 THEN L:=BETA; RETURN(L); END; 
(*2*) (*initialize.*) AS:=A; AP:=AFPDMV(1,M,A); C:=BETA; 
(*3*) (*compute derivatives.*) 
      WHILE PDEG(AS) > 1 DO BL:=PTBCF(1,AS); C:=COMP(BL,C); AS:=AP; 
            AP:=AFPDMV(1,M,AS); END; 
(*4*) (*isolate roots.*) LP:=BETA; DL:=AFUPRB(MB,I,A); 
      REPEAT L:=AFPRII(M,MB,I,AS,AP,DL,LP); 
             IF C = SIL THEN RETURN(L); END; 
             ADV(C, BL,C); AP:=AS; AS:=AFPINT(1,M,AP,BL); LP:=L; 
             UNTIL FALSE; 
(*7*) RETURN(L); END AFPRCL; 
*)


(* -- zuviele goto's :-(
PROCEDURE AFPRII(M,MB,J,A,AP,DL,LP: LIST): LIST; 
(*Algebraic number field polynomial real root isolation induction.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  J is
an acceptable isolating interval for alpha.  A is a positive
univariate polynomial over Q( alpha ) of positive degree.  AP is
the derivative of A.  d is a binary rational real root bound for A.
LP is a strong isolation list for AP.  L is a strong isolation list
for A.*)
VAR   ABP, AL1, AL2, ALHS1, ALS1, B, B1, B2, BL0, BL1, BLHS1, BLS1, CL,
      CLH, DLP, I, I1, IP, IPP, J1Y, KL, L, LS, ML, ML1, NL, RL, RL0,
      RL1, SL, SL1, SL2, SLBP, SLBP1, SLP, SLS1, TL0, TL1, TLP0,
      TLP1, TLS1, UL, UL1, UL2, ULP, ULP1, ULS1, VL1, VLP1, VLS1, WLS0,
      WLS1, ZL, ZL1, ZL2: LIST; 
BEGIN
(*1*) (*ap without roots.*) DLP:=RNNEG(DL); 
      IF LP = SIL THEN I:=LIST2(DLP,DL); L:=LIST2(I,1); RETURN(L); 
         END; 
(*2*) (*initialize.*) ABP:=AFUPGS(M,AP); AFUPGC(M,A,ABP, B,B1,B2); 
      NL:=PDEG(A); KL:=PDEG(B); LS:=LP; 
      IF EVEN(NL THEN TL0:=1; ELSE TL0:=-1; END; 
      TLP0:=-TL0; BL0:=DLP; I1:=FIRST(LS); AL1:=FIRST(I1); 
      J1Y:=AFFRN(AL1); UL1:=AFPEMV(1,M,A,J1Y); SL1:=AFSIGN(MB,J,UL1); 
      L:=BETA; 
      IF TL0*SL1 > 0 THEN RL0:=0; ELSE RL0:=1; I:=LIST2(BL0,AL1); 
         L:=COMP2(1,I,L); END; 
      IF EVEN(KL THEN WLS0:=1; ELSE WLS0:=-1; END; 
      ML:=PDEG(ABP); 
      IF EVEN(ML THEN SLBP1:=1; ELSE SLBP1:=-1; END; 
(*3*) (*root of a in (b sub i ,a sub i+1 ).*) ADV2(LS, I1,ML1,LS); 
      BL1:=SECOND(I1); J1Y:=AFFRN(BL1); VL1:=AFPEMV(1,M,A,J1Y); 
      TL1:=AFSIGN(MB,J,VL1); 
      IF EVEN(ML1 THEN TLP1:=TLP0; ELSE TLP1:=-TLP0; END; 
      TLS1:=TL1; 
      IF TL1 = 0 THEN TLS1:=TLP1; END; 
      IF LS = SIL THEN AL2:=DL; ELSE J1Y:=FIRST(LS); 
         AL2:=FIRST(J1Y); END; 
      IF RNCOMP(BL1,AL2) < 0 THEN J1Y:=AFFRN(AL2); 
         UL2:=AFPEMV(1,M,A,J1Y); SL2:=AFSIGN(MB,J,UL2); 
         IF TLS1*SL2 <= 0 THEN RL1:=1; ELSE RL1:=0; END; 
         ELSE UL2:=VL1; SL2:=TL1; RL1:=0; END; 
(*4*) (*alpha sub i a root of a.*) 
      IF KL = 0 THEN WLS1:=WLS0; ELSE WLS1:=AFUPSR(M,MB,J,B,BL1); 
         IF WLS1 = 0 THEN WLS1:=-WLS0; END; 
         END; 
      IF WLS0*WLS1 < 0 THEN J1Y:=ML1+1; L:=COMP2(J1Y,I1,L); GO TO
         9; END; 
(*5*) (*other roots of a in (a sub i ,b sub i ).*) RL:=RL0+RL1; 
      IF RL = 2 THEN GO TO 9; END; 
      IF SL1 <> 0 THEN SLS1:=SL1; ELSE SLS1:=TLP0; END; 
      IF (RL = 1) OR EVEN(ML1) THEN
         IF SLS1*TL1 <= 0 THEN GO TO 6; ELSE GO TO 9; END; 
         END; 
      IF TL1 = 0 THEN
         IF SLS1*TLP0 > 0 THEN GO TO 6; END; 
         ALS1:=AL1; BLS1:=BL1; GO TO 8; END; 
      IF SLS1*TL1 < 0 THEN GO TO 6; END; 
      IF SLS1*TLP0 > 0 THEN GO TO 9; ELSE GO TO 7; END; 
(*6*) (*one root in (a sub i ,b sub i ).*) 
      I:=AFPRRI(M,MB,J,A,ABP,I1,SLS1,SLBP1); L:=COMP2(1,I,L); GO TO 9; 
(*7*) (*zero or two roots of a in (a sub i ,b sub i ).*) ALS1:=AL1; 
      BLS1:=BL1; ULS1:=UL1; VLS1:=VL1; ALHS1:=AFFRN(ALS1); 
      BLHS1:=AFFRN(BLS1); ULP1:=AFPEMV(1,M,AP,ALHS1); 
      VLP1:=AFPEMV(1,M,AP,BLHS1); 
      IF VLP1 = 0 THEN GO TO 9; END; 
      REPEAT ZL:=AFQ(M,ULS1,ULP1); ZL1:=AFDIF(ALHS1,ZL); 
             ZL:=AFQ(M,VLS1,VLP1); ZL2:=AFDIF(BLHS1,ZL); 
             ZL:=AFCOMP(MB,J,ZL1,ZL2); 
             IF ZL >= 0 THEN GO TO 9; END; 
             CL:=RIB(ALS1,BLS1); CLH:=AFFRN(CL); UL:=AFPEMV(1,M,A,CLH); 
             SL:=AFSIGN(MB,J,UL); ULP:=AFPEMV(1,M,AP,CLH); 
             SLP:=AFSIGN(MB,J,ULP); 
             IF (SLS1*SL > 0) AND (SLP = 0) THEN GO TO 9; END; 
             IF (SL = 0) AND (TLP0*SLP < 0) THEN BLS1:=CL; GO
                TO 8; END; 
             IF SLS1*SL <= 0 THEN IP:=LIST2(ALS1,CL); 
                IPP:=LIST2(CL,BLS1); 
                IF TLP0*SLP <= 0 THEN
                   I:=AFPRRI(M,MB,J,A,ABP,IP,SLS1,SLBP1); 
                   L:=COMP4(1,IPP,1,I,L); ELSE J1Y:=-SLS1; 
                   I:=AFPRRI(M,MB,J,A,ABP,IPP,J1Y,SLBP1); 
                   L:=COMP4(1,I,1,IP,L); END; 
                GO TO 9; END; 
             IF TLP0*SLP > 0 THEN ALS1:=CL; ULS1:=UL; ULP1:=ULP; 
                ELSE BLS1:=CL; VLS1:=UL; VLP1:=ULP; END; 
             UNTIL SIL; 
(*8*) (*roots at b sub i sup * and in (a sub i sup * ,b sub i sup * )*) 
      REPEAT CL:=RIB(ALS1,BLS1); SL:=AFUPSR(M,MB,J,A,CL); 
             IF SLS1*SL <= 0 THEN SLBP:=AFUPSR(M,MB,J,ABP,CL); 
                IP:=LIST2(ALS1,CL); IPP:=LIST2(CL,BLS1); 
                IF SLBP1*SLBP <= 0 THEN
                   I:=AFPRRI(M,MB,J,A,ABP,IP,SLS1,SLBP1); 
                   L:=COMP4(1,IPP,1,I,L); ELSE J1Y:=-SLS1; 
                   I:=AFPRRI(M,MB,J,A,ABP,IPP,J1Y,SLBP1); 
                   L:=COMP4(1,I,1,IP,L); END; 
                GO TO 9; END; 
             ALS1:=CL; 
             UNTIL SIL; 
(*9*) (*update.*) 
      IF RL1 = 1 THEN I:=LIST2(BL1,AL2); L:=COMP2(1,I,L); END; 
      AL1:=AL2; RL0:=RL1; TLP0:=TLP1; SL1:=SL2; WLS0:=WLS1; 
      SLBP1:=-SLBP1; UL1:=UL2; 
      IF LS <> SIL THEN GO TO 3; END; 
(*10*) (*finish.*) L:=INV(L); RETURN(L); 
(*13*) END AFPRII; 
*)

PROCEDURE AFPRLS(M,MB,I,A1,A2,L1,L2: LIST;  VAR LS1,LS2: LIST); 
(*Algebraic number field polynomial real root list separation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A1 and A2
are univariate polynomials over Q( alpha ) with no common roots
and real roots of only odd multiplicity.  L1 and L2 are strong
isolation lists for the real roots of A1 and A2 respectively.  Let
L1 eq (i sub 1,1 ,m sub 1,1 ,... , i sub (1,r sub 1),m sub (1,r sub 1)),
L2 eq (i sub 2,1 ,m sub 2,1 ,... , i sub (2,r sub 2),m sub (2,r sub 2)).
Then i sub 1,1  lt  i sub 1,2  lt  ...   lt  i sub (1,r sub 1)
and  i sub 2,1  lt  i sub 2,2  lt  ...   lt  i sub (2,r sub 2) .
l sub 1 sup *  eq (i sub 1,1 sup * ,m sub 1,1 ,... ,
i sub (1,r sub 1) sup * ,m sub (1,r sub 1))
and l sub 2 sup *  eq (i sub 2,1 sup * ,m sub 2,1 ,... ,
i sub (2,r sub 2) sup * ,m sub (2,r sub 2)),
where i sub i,j sup * is a binary rational subinterval of
i sub i,j containing the root of a sub i in i sub i,j.
each i sub 1,j sup * is strongly disjoint from each
i sub 2,j sup *.*)
VAR   I1, I2, LP1, LP2, ML1, ML2, SL: LIST; 
BEGIN
(*1*) (*initialize.*) 
      IF (L1 = SIL) OR (L2 = SIL) THEN LS1:=L1; LS2:=L2; 
         RETURN; END; 
      ADV2(L1, I1,ML1,LP1); LS1:=BETA; ADV2(L2, I2,ML2,LP2); LS2:=BETA; 
(*2*) (*refine and merge.*) 
      REPEAT AFPRRS(M,MB,I,A1,A2,I1,I2, I1,I2,SL); 
             IF SL < 0 THEN LS1:=COMP2(ML1,I1,LS1); 
                IF LP1 <> SIL THEN ADV2(LP1, I1,ML1,LP1); ELSE
                   I1:=0; END; 
                ELSE LS2:=COMP2(ML2,I2,LS2); 
                IF LP2 <> SIL THEN ADV2(LP2, I2,ML2,LP2); ELSE
                   I2:=0; END; 
                END; 
             UNTIL (I1 = 0) OR (I2 = 0); 
(*3*) (*finish.*) 
      IF I1 = 0 THEN LS2:=COMP2(ML2,I2,LS2); 
         WHILE LP2 <> SIL DO ADV2(LP2, I2,ML2,LP2); 
               LS2:=COMP2(ML2,I2,LS2); END; 
         ELSE LS1:=COMP2(ML1,I1,LS1); 
         WHILE LP1 <> SIL DO ADV2(LP1, I1,ML1,LP1); 
               LS1:=COMP2(ML1,I1,LS1); END; 
         END; 
      LS1:=INV(LS1); LS2:=INV(LS2); RETURN; 
(*6*) END AFPRLS; 


PROCEDURE AFPRRI(M,MB,I,A,B,J,SL1,TL1: LIST): LIST; 
(*Algebraic number field polynomial relative real root isolation.
M is the rational minimal polynomial of a real algebraic number
alpha.  MB is the integral minimal polynomial of alpha.  I is an
acceptable isolating interval for alpha.  A and B are univariate
polynomials over Q( alpha ).  J is a left open, right closed
interval (a sub 1 ,a sub 2 ) where al sub 1 and al sub 2 are
binary rational numbers with al sub 1 lt al sub 2.  A and B have
unique roots, alpha and beta respectively, in J, each of odd
multiplicity and with alpha ne beta.  sl sub 1 eq
sign(a(al sub 1 +)) and tl sub 1 eq sign(b(al sub 1 +)).
js eq (al sub 1 sup * ,al sub 2 sup * ) is al left-open, right-closed
subinterval of j with al sub 1 sup * and al sub 2 sup *
binary rational numbers and al sub 1 sup * lt al sub 2 sup *,
such that js contains alpha but not beta.*)
VAR   AL, ALS1, ALS2, JS, SL, TL, UL, VL: LIST; 
BEGIN
(*1*) (*initialize.*) FIRST2(J, ALS1,ALS2); 
LOOP
(*2*) (*bisect.*) AL:=RIB(ALS1,ALS2); SL:=AFUPSR(M,MB,I,A,AL); 
      IF SL = 0 THEN SL:=-SL1; END; 
      TL:=AFUPSR(M,MB,I,B,AL); 
      IF TL = 0 THEN TL:=-TL1; END; 
      UL:=SL1*SL; VL:=TL1*TL; 
      IF UL > 0 THEN ALS1:=AL; ELSE ALS2:=AL; END; 
      IF UL <> VL THEN EXIT; (* if = then GO TO 2;*) END; 
      END; (*loop*) 
(*3*) (*construct js.*) JS:=LIST2(ALS1,ALS2); RETURN(JS); 
(*6*) END AFPRRI; 


PROCEDURE AFPRRS(M,MB,I,A1,A2,I1,I2: LIST; VAR IS1,IS2,SL: LIST); 
(*Algebraic number field polynomial real root separation.  M is
the rational minimal polynomial of a real algebraic number alpha.
MB is the integral minimal polynomial of alpha.  I is an
acceptable isolating interval for alpha.  A1 and A2 are
univariate integral polynomials of positive degrees over Q( alpha ).
I1 and I2 are intervals with binary rational number endpoints, each of
which is either left-open and right-closed, or a one-point interval.
I1 contains a unique root alpha sub 1 of A1 of odd multiplicity,
and I2 contains a unique root alpha sub 2 ne alpha sub 1
of A2 of odd multiplicity.  I sub 1 sup * and
I sub 2 sup * are binary rational subintervals of I1 and I2
containing alpha sub 1 and alpha sub 2 respectively, with
I sub 1 sup * and I sub 2 sup * strongly disjoint.  If I1 is
left-open and right-closed then so is I sub 1 sup *, and
similarly for I2 and I sub 2 sup *.  s eq -1
if I sub 1 sup *  lt  I sub 2 sup *, and s eq 1
if I sub 1 sup *  gt  I sub 2 sup *.*)
VAR   AL1, AL2, BL1, BL2, CL, DL1, DL2, SL1, SL2, TL, UL, VL: LIST; 
BEGIN
(*1*) (*i1 and i2 disjoint.*) FIRST2(I1, AL1,BL1); FIRST2(I2, AL2,BL2); 
      IF RNCOMP(BL1,AL2) < 0 THEN IS1:=I1; IS2:=I2; SL:=-1; RETURN; 
         END; 
      IF RNCOMP(BL2,AL1) < 0 THEN IS1:=I1; IS2:=I2; SL:=1; RETURN; 
         END; 
(*2*) (*initialize.*) DL1:=RNDIF(BL1,AL1); DL2:=RNDIF(BL2,AL2); SL1:=2; 
      SL2:=2; 
LOOP
(*3*) (*bisect i1.*) TL:=RNCOMP(DL1,DL2); 
      IF TL >= 0 THEN
         IF SL1 > 1 THEN SL1:=AFUPSR(M,MB,I,A1,BL1); END; 
         CL:=RIB(AL1,BL1); UL:=AFUPSR(M,MB,I,A1,CL); 
         IF (SL1 = 0) OR (SL1*UL < 0) THEN AL1:=CL; VL:=1; 
            ELSE BL1:=CL; SL1:=UL; VL:=-1; END; 
         DL1:=RNDIF(BL1,AL1); END; 
(*4*) (*bisect i2.*) 
      IF TL < 0 THEN
         IF SL2 > 1 THEN SL2:=AFUPSR(M,MB,I,A2,BL2); END; 
         CL:=RIB(AL2,BL2); UL:=AFUPSR(M,MB,I,A2,CL); 
         IF (SL2 = 0) OR (SL2*UL < 0) THEN AL2:=CL; VL:=-1; 
            ELSE BL2:=CL; SL2:=UL; VL:=1; END; 
         DL2:=RNDIF(BL2,AL2); END; 
(*5*) (*i1 and i2 disjoint.*) 
      IF (VL < 0) AND (RNCOMP(BL1,AL2) < 0) THEN SL:=-1; EXIT; (*loop*)
         ELSE
         IF (VL > 0) AND (RNCOMP(BL2,AL1) < 0) 
            THEN SL:=1; EXIT; (*loop*) 
            ELSE (*GO TO 3;*) END; 
         END; 
      END; (*loop*)
      IS1:=LIST2(AL1,BL1); IS2:=LIST2(AL2,BL2); RETURN; 
(*8*) END AFPRRS; 


PROCEDURE AFPSUM(RL,A,B: LIST): LIST; 
(*Algebraic number field polynomial sum. A and B are polynomials over
Q( alpha ) in r variables, r ge 1, for some algebraic number
alpha.  C=A+B.*)
VAR   AL, AP, BL, BP, C, CL, CP, EL, FL, RLP: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF A = 0 THEN C:=B; RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN C:=AFSUM(A,B); RETURN(C); END; 
(*3*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1; 
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP); 
             IF EL > FL THEN ADV2(AP, EL,AL,AP); 
                CP:=COMP2(AL,EL,CP); ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP); 
                   CP:=COMP2(BL,FL,CP); ELSE ADV2(AP, EL,AL,AP); 
                   ADV2(BP, FL,BL,BP); 
                   IF RLP = 0 THEN CL:=AFSUM(AL,BL); ELSE
                      CL:=AFPSUM(RLP,AL,BL); END; 
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*4*) (*finish.*) 
      IF AP = SIL THEN AP:=BP; END; 
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*7*) END AFPSUM; 


PROCEDURE AFSUPB(M,A: LIST): LIST; 
(*Algebraic number field squarefree univariate polynomial squarefree
basis.  M is the rational minimal polynomial of an algebraic number
alpha.  A eq (a sub 1 ,... , a sub n ), n ge 0, is a list of monic
squarefree univariate polynomials over Q( alpha ), each of which
is of positive degree.  B is a coarsest squarefree basis for A.*)
VAR   A1, AP, B: LIST; 
BEGIN
(*1*) B:=BETA; AP:=A; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); B:=AFUPBA(M,A1,B); END; 
      RETURN(B); 
(*4*) END AFSUPB; 


PROCEDURE AFUPBA(M,A,B: LIST): LIST; 
(*Algebraic number field univariate polynomial squarefree basis
augmentation.  M is the rational minimal polynomial of an algebraic
number alpha.  A is a monic squarefree univariate polynomial over
Q( alpha ), of positive degree.  B eq (b sub 1 ,... , b sub s ),
s ge 0, is a squarefree basis of univariate polynomials over
Q( alpha ).  BS is a coarsest squarefree basis for
(a,b sub 1 ,... , b sub s ).*)
VAR   ABP, AP, B1, BB1, BP, BS, C: LIST; 
BEGIN
(*1*) AP:=A; BP:=B; BS:=BETA; 
      WHILE (BP <> SIL) AND (PDEG(AP) > 0) DO ADV(BP, B1,BP); 
            AFUPGC(M,AP,B1, C,ABP,BB1); 
            IF PDEG(C) > 0 THEN BS:=COMP(C,BS); END; 
            IF PDEG(BB1) > 0 THEN BS:=COMP(BB1,BS); END; 
            AP:=ABP; END; 
      IF PDEG(AP) > 0 THEN BS:=COMP(AP,BS); END; 
      WHILE BP <> SIL DO ADV(BP, B1,BP); BS:=COMP(B1,BS); END; 
      RETURN(BS); 
(*4*) END AFUPBA; 


PROCEDURE AFUPCB(M,A: LIST): LIST; 
(*Algebraic number field univariate polynomial coarsest squarefree basis. 
M is the rational minimal polynomial of an algebraic number alpha. 
A eq (a sub 1 ,... , a sub n ), n ge 0, is a
list of monic univariate polynomials over Q( alpha ), each of
which is of positive degree.  B is a coarsest squarefree basis for A.*)
VAR   A1, AP, AP1, AS, B, L, L1: LIST; 
BEGIN
(*1*) AS:=BETA; AP:=A; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); L:=AFUPSF(M,A1); 
            REPEAT ADV(L, L1,L); AP1:=SECOND(L1); AS:=COMP(AP1,AS); 
                   UNTIL L = SIL; 
            END; 
      B:=AFSUPB(M,AS); RETURN(B); 
(*4*) END AFUPCB; 


PROCEDURE AFUPGC(M,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Algebraic number field univariate polynomial greatest common divisor
and cofactors.  A and B are univariate polynomials over
Q( alpha ) for some algebraic number alpha.  M is the rational
minimal polynomial of alpha.  C eq gcd(A,B), a monic polynomial.
If C ne 0, then AB eq A/C and BB eq B/C, otherwise AB eq 0 and BB eq 0.
*)
VAR   AP, J1Y, ML, NL, Q, R: LIST; 
BEGIN
(*1*) (*a eq b eq 0.*) 
      IF (A = 0) AND (B = 0) THEN C:=0; AB:=0; BB:=0; RETURN; 
         END; 
(*2*) (*a eq 0 or b eq 0.*) 
      IF A = 0 THEN C:=AFPMON(1,M,B); AB:=0; J1Y:=PLDCF(B); 
         BB:=PINV(0,J1Y,1); RETURN; END; 
      IF B = 0 THEN C:=AFPMON(1,M,A); BB:=0; J1Y:=PLDCF(A); 
         AB:=PINV(0,J1Y,1); RETURN; END; 
(*3*) (*general case.*) ML:=PDEG(A); NL:=PDEG(B); 
      IF ML >= NL THEN AP:=A; C:=AFPMON(1,M,B); ELSE AP:=B; 
         C:=AFPMON(1,M,A); END; 
LOOP
      (*REPEAT*) AFPQR(1,M,AP,C, Q,R); 
                 IF R = 0 THEN EXIT; (*GO TO 4;*) 
                          ELSE AP:=C; C:=AFPMON(1,M,R); END; 
                 (*UNTIL SIL;*) 
      (*EXIT;*) END; (*loop*)
(*4*) (*make up cofactors.*) AFPQR(1,M,A,C, AB,R); AFPQR(1,M,B,C,
      BB,R); RETURN; 
(*7*) END AFUPGC; 


PROCEDURE AFUPGS(M,A: LIST): LIST; 
(*Algebraic number field polynomial greatest squarefree divisor.
M is the rational minimal polynomial of an algebraic number alpha.
A is a univariate polynomial over Q( alpha ).  If A eq 0 then
B eq 0.  Otherwise B is the monic associate of the greatest
squarefree divisor of A.*)
VAR   B, BP, C, D: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*a ne 0.*) B:=AFPMON(1,M,A); 
      IF PDEG(B) > 0 THEN BP:=AFPDMV(1,M,B); AFUPGC(M,B,BP, C,B,D); 
         END; 
      RETURN(B); 
(*5*) END AFUPGS; 


PROCEDURE AFUPRB(MB,I,A: LIST): LIST; 
(*Algebraic number field univariate polynomial root bound.  MB is
the integral minimal polynomial of a real algebraic number alpha.
I is an acceptable isolating interval for alpha.  A is a monic
univariate polynomial over Q( alpha ) of positive degree.
B is a binary rational number which is a root bound for A.
If A(x) eq x sup n + sum from (i eq 0) to n-1 (a sub i x sup i),
then B is the smallest power of 2 such that 2 cdot (abs(a sub n-k ))
sup 1/k le B for 1 le k le n.  If a sub n-k eq 0 for 1 le k le n
then B eq 1.*)
VAR   AL, AL1, AP, BL, EL, HL, HL1, HL2, HLP, IL, J, J1Y, N, NL, NL1,
      QL, RL, TL, UL, VL: LIST; 
BEGIN
(*1*) (*initialize.*) ADV2(A, NL,AL,AP); 
LOOP 
      IF AP = SIL THEN EL:=-1; EXIT; (* GO TO 3;*) END; 
      TL:=0; 
(*2*) (*process terms.*) 
      REPEAT ADV2(AP, NL1,AL1,AP); IL:=NL-NL1; ANFAF(MB,I,AL1, N,J); 
             J:=ISFPIR(N,J,0); FIRST2(J, UL,VL); 
             IF UL = 0 THEN RNFCL2(VL, HLP,HL); ELSE
                IF VL = 0 THEN RNFCL2(UL, HLP,HL); ELSE RNFCL2(UL,
                   HLP,HL1); RNFCL2(VL, HLP,HL2); HL:=MASMAX(HL1,HL2); END; 
                END; 
             MASQREM(HL,IL, QL,RL); 
             IF RL > 0 THEN QL:=QL+1; END; 
             IF (TL = 0) OR (QL > EL) THEN EL:=QL; END; 
             TL:=1; 
             UNTIL AP = SIL; 
      EXIT; END; (*loop*) 
(*3*) (*compute b.*) J1Y:=EL+1; BL:=RNP2(J1Y); RETURN(BL); 
(*6*) END AFUPRB; 


PROCEDURE AFUPRL(M,A: LIST): LIST; 
(*Algebraic number field polynomial, root of a linear polynomial.  A
is an element of Q( alpha )(x) of degree one, for some algebraic
number alpha.  M is the rational minimal polynomial of alpha.
a is the unique element of Q( alpha ) such that A(a) eq 0.*)
VAR   AL, CL, DL, J1Y, L: LIST; 
BEGIN
(*1*) IF PRED(A) = 0 THEN AL:=0; ELSE L:=PCL(A); FIRST2(L, CL,DL); 
         J1Y:=AFNEG(DL); AL:=AFQ(M,J1Y,CL); RETURN(AL); END; 
(*4*) RETURN(AL); END AFUPRL; 


PROCEDURE AFUPSF(M,A: LIST): LIST; 
(*Algebraic number field univariate polynomial squarefree factorization.
M is the rational minimal polynomial of an algebraic number alpha.
A is a monic univariate polynomial over Q( alpha ) of positive degree.
L is the list ((e sub 1 ,a sub 1 ) ,... , (e sub k ,a sub k )),
where A eq prod from (i eq 1) to k (a sub i sup (e sub i)) is the
squarefree factorization of A, with 1 le e sub 1 lt e sub 2
le ...   lt e sub k and each a sub i a monic squarefree polynomial
of positive degree.*)
VAR   AP, B, BP, C, CP, D, J1Y, JL, L: LIST; 
BEGIN
(*1*) (*initialize.*) L:=BETA; AP:=AFPDMV(1,M,A); AFUPGC(M,A,AP,
      B,C,CP); JL:=1; 
(*2*) (*compute factors.*) 
      WHILE PDEG(B) > 0 DO AFUPGC(M,B,C, D,BP,CP); 
            IF PDEG(CP) > 0 THEN J1Y:=LIST2(JL,CP); L:=COMP(J1Y,L); 
               END; 
            B:=BP; C:=D; JL:=JL+1; END; 
(*3*) (*finish.*) J1Y:=LIST2(JL,C); L:=COMP(J1Y,L); L:=INV(L); 
      RETURN(L); 
(*6*) END AFUPSF; 


PROCEDURE AFUPSR(M,MB,I,A,CL: LIST): LIST; 
(*Algebraic number field univariate polynomial, sign at a rational
point.  M is the rational minimal polynomial of a real algebraic
number alpha.  MB is the integral minimal polynomial of alpha.
I is an acceptable isolating interval for alpha.  A is a
univariate polynomial over Q( alpha ).  c is a rational number.
s eq sign(A(c)).*)
VAR   AL, BL, SL: LIST; 
BEGIN
(*1*) AL:=AFFRN(CL); BL:=AFPEMV(1,M,A,AL); SL:=AFSIGN(MB,I,BL); 
      RETURN(SL); 
(*4*) END AFUPSR; 


PROCEDURE ANDWR(M,I,NL: LIST); 
(*Algebraic number decimal write.  M is the integral minimal polynomial
of a real algebraic number alpha.  I is an acceptable isolating
interval for alpha.  n is a nonnegative integer.  alpha is
approximated by a rational number r with inaccuracy of approximation
at most 10 sup -(n+1).  Then r is approximated by a decimal
fraction d with n decimal digits following the decimal point and
d is written in the output stream.  The inaccuracy of the approximation
of d to r is at most (1/2) 10 sup -n.  If abs(d) gt abs(r) then
the last digit is followed by $=-. If abs(d) lt abs(r) then by $=+.*)
VAR   J, J1Y, R: LIST; 
BEGIN
(*1*) IF PDEG(M) = 1 THEN R:=IUPRLP(M); ELSE J1Y:=NL+1; 
         J:=ISFPIR(M,I,J1Y); R:=FIRST(J); END; 
      RNDWRS(R,NL); RETURN; 
(*4*) END ANDWR; 


PROCEDURE ANFAF(M,I,AL: LIST;  VAR N,J: LIST); 
(*Algebraic number from algebraic number field element.  M is the
integral minimal polynomial of a real algebraic number alpha.
I is an acceptable isolating interval for alpha.  a is an
element of Q( alpha ).  N is the integral minimal polynomial of a,
and J is an acceptable isolating interval for a.*)
VAR   A, B, BL1, BL2, C, DL, J1Y, J2Y, L, SL1, SL2, UL1, UL2, VL1,
     VL2: LIST; 
BEGIN
(*1*) (*a rational.*) 
      IF AL = 0 THEN N:=PMON(1,1); J:=LIST2(0,0); RETURN; END; 
      IF PDEG(AL) = 0 THEN J1Y:=-1; J1Y:=RNINT(J1Y); 
         J2Y:=SECOND(AL); N:=PBIN(J1Y,1,J2Y,0); IPSRP(1,N, DL,N); 
         L:=IPRIM(N); J:=FIRST(L); RETURN; END; 
(*2*) (*find minimal polynomial.*) J1Y:=-1; J1Y:=RNINT(J1Y); 
      J1Y:=PMON(J1Y,0); A:=PBIN(J1Y,1,AL,0); IPSRP(2,A, DL,A); 
      J1Y:=LIST2(2,1); A:=PPERMV(2,A,J1Y); B:=PINV(1,M,1); 
      C:=IPRES(2,A,B); N:=IPPGSD(1,C); 
(*3*) (*find acceptable isolating interval.*) L:=IPRIM(N); 
      REPEAT ADV(L, J,L); FIRST2(J, UL1,UL2); VL1:=PMON(UL1,0); 
             VL2:=PMON(UL2,0); BL1:=AFDIF(AL,VL1); BL2:=AFDIF(AL,VL2); 
             SL1:=AFSIGN(M,I,BL1); SL2:=AFSIGN(M,I,BL2); 
             IF SL1*SL2 = -1 THEN RETURN; END; 
             UNTIL FALSE; 
(*6*) RETURN; END ANFAF; 


PROCEDURE ANIIPE(MB,I,NB,J,TL,L: LIST;  VAR S,KL,K: LIST); 
(*Algebraic number isolating interval for a primitive element.
MB is the integral minimal polynomial of a real algebraic number
alpha.  I is a binary rational isolating interval for alpha
which is either left-open and right-closed or a one-point interval.
NB is the integral minimal polynomial of a real algebraic number
beta.  J is a binary rational isolating interval for beta which
is either left-open and right-closed or a one-point interval.
t is an integer such that Q( alpha +t beta ) eq
Q( alpha , beta ).  If degree(MB) eq 1 and degree(NB) eq 1,
then L is a list containing a primitive positive integral polynomial
p of degree 1, s eq p, k eq 1, and k is a binary rational isolating
interval for the real root of p which is either left-open and
right-closed or a one-point interval.  If degree(mb) eq 1,
degree(NB) gt 1, then l eq (NB), S eq NB, k eq 1, and k eq j.
If degree(MB) gt 1, degree(NB) eq 1, then L eq (MB), S eq MB, k eq 1,
and k eq i.  If degree(MB) gt 1, degree(NB) gt 1, then L is a nonempty
list of positive irreducible univariate integral polynomials exactly
one of which has alpha +t beta as a root.  S is the element of L
having alpha +t beta as a root, k is the index of S in L, and
k is a left-open, right-closed binary rational isolating interval
for alpha +t beta as a root of S.*)
VAR   AL, BL, CL, CLS, DL, DLS, EL, J1Y, J2Y, JP, JS, KLP, L1, LP, ML,
      NL, SL1, SL2, SLP, TLP, VL, VLP: LIST; 
BEGIN
(*1*) (*mb or nb has degree 1.*) KL:=1; ML:=PDEG(MB); NL:=PDEG(NB); 
      IF (ML = 1) AND (NL = 1) THEN S:=FIRST(L); K:=IPRIM(S); 
         K:=FIRST(K); RETURN; END; 
      IF ML = 1 THEN S:=NB; K:=J; RETURN; END; 
      IF NL = 1 THEN S:=MB; K:=I; RETURN; END; 
(*2*) (*initialization.*) FIRST2(I, AL,BL); SL1:=IUPBES(MB,BL); JP:=J; 
      FIRST2(J, CL,DL); SL2:=IUPBES(NB,DL); TLP:=RNINT(TL); 
LOOP
(*3*) (*make new interval.*) JS:=RIRNP(JP,TLP); FIRST2(JS, CLS,DLS); 
      J1Y:=RNSUM(AL,CLS); J2Y:=RNSUM(BL,DLS); K:=LIST2(J1Y,J2Y); 
(*4*) (*test for real roots of each l sub i in current interval.*) 
LOOP
      VL:=0; KLP:=0; LP:=L; 
      REPEAT ADV(LP, L1,LP); KLP:=KLP+1; VLP:=IUPVOI(L1,K); 
             IF VLP > 1 THEN EXIT; (*GO TO 5;*) END; 
             IF VLP = 1 THEN
                IF VL = 1 THEN EXIT; (*GO TO 5;*) 
                          ELSE VL:=1; S:=L1; KL:=KLP; 
                   END; 
                END; 
             UNTIL LP = SIL; 
      RETURN; 
      END; (*loop*) 
(*5*) (*bisect isolating intervals for alpha and beta.*) 
      EL:=RIB(AL,BL); SLP:=IUPBES(MB,EL); 
      IF SLP*SL1 < 0 THEN AL:=EL; ELSE BL:=EL; SL1:=SLP; END; 
      EL:=RIB(CL,DL); SLP:=IUPBES(NB,EL); 
      IF SLP*SL2 < 0 THEN CL:=EL; ELSE DL:=EL; SL2:=SLP; END; 
      JP:=LIST2(CL,DL); 
      (*GO TO 3;*) 
      END; (*loop*)
(*8*) END ANIIPE; 


PROCEDURE ANPEDE(MB,NB: LIST;  VAR TL,S,T: LIST); 
(*Algebraic number primitive element for a double extension.
MB eq MB(x) is the integral minimal polynomial of a real algebraic
number alpha.  NB eq NB(x) is the integral minimal polynomial
of a real algebraic number beta.  t is an integer such that
Q( alpha +t beta ) eq Q( alpha , beta ).  If degree(MB) eq 1
and degree(NB) eq 1, then S eq (x), a list of length of length 1
containing the polynomial x.  If degree(MB) eq 1 and degree(NB) gt 1,
then S eq (NB).  If degree(MB) gt 1 and degree(NB) eq 1, then S eq (MB).
If degree(MB) gt 1 and degree(NB1) gt 1, then S is a list of the
integral minimal polynomials of all algebraic numbers of the
form alpha sub i + t beta sub j, where alpha sub i is some
conjugate of alpha and beta sub j is some conjugate of
beta.  Where n ge 1 is the length of S, t is a list
(m sub 1 sup * ,n sub 1 sup * ,... , m sub n sup * , n sub n sup * ).
For 1 le k le n, where gamma sub k is a root of s sub k,
m sub k sup * is the representation of alpha as an element
of Q( gamma sub k ) and n sub k sup * is the representation
of beta as an element of Q( gamma sub k ).*)
VAR   C, CL, J1Y, J2Y, ML, MP, MS, NL, NP, NS, P, R, RB, RBP, RP, S1,
      SL, SP, SP1: LIST; 
BEGIN
(*1*) (*mb and nb have degree 1.*) TL:=1; ML:=PDEG(MB); NL:=PDEG(NB); 
      IF (ML = 1) AND (NL = 1) THEN J1Y:=PMON(1,1); 
         S:=LIST1(J1Y); MS:=IUPRLP(MB); MS:=AFFRN(MS); NS:=IUPRLP(NB); 
         NS:=AFFRN(NS); T:=LIST2(MS,NS); RETURN; END; 
(*2*) (*mb or nb has degree 1.*) 
      IF ML = 1 THEN S:=LIST1(NB); MS:=IUPRLP(MB); MS:=AFFRN(MS); 
         J1Y:=RNINT(1); NS:=PMON(J1Y,1); T:=LIST2(MS,NS); RETURN; END; 
      IF NL = 1 THEN S:=LIST1(MB); J1Y:=RNINT(1); MS:=PMON(J1Y,1); 
         NS:=IUPRLP(NB); NS:=AFFRN(NS); T:=LIST2(MS,NS); RETURN; END; 
      NP:=PINV(1,NB,1); 
LOOP 
(*3*) (*find t such that alpha +t beta is primitive.*) J1Y:=-TL; 
      J1Y:=PMON(J1Y,0); J2Y:=PMON(1,1); P:=PBIN(J1Y,1,J2Y,0); 
      J1Y:=LIST1(P); MP:=IPGSUB(1,MB,2,J1Y); R:=IPRES(2,MP,NP); 
      RP:=IPDMV(1,R); IPGCDC(1,R,RP, C,RB,RBP); 
      IF PDEG(C) > 0 THEN
         IF TL > 0 THEN TL:=-TL; ELSE J1Y:=-TL; TL:=J1Y+1; END; 
         (*GO TO 3;*)
         ELSE EXIT; END; 
      END; (*loop*)
(*4*) (*get minimal polynomials for conjugates 
      alpha sub i + t beta sub j . construct representations for 
      alpha and beta as elements of Q( alpha sub i + t beta sub j ). *) 
      IPSCPP(1,R, SL,CL,R); S:=IUSFPF(R); SP:=S; T:=BETA; 
      REPEAT ADV(SP, S1,SP); SP1:=RPMAIP(1,S1); 
             NS:=ANREPE(SP1,S1,MP,NP); J1Y:=AFFINT(TL); 
             MS:=AFPROD(SP1,J1Y,NS); J1Y:=RNINT(1); J1Y:=PMON(J1Y,1); 
             MS:=AFDIF(J1Y,MS); T:=COMP2(NS,MS,T); 
             UNTIL SP = SIL; 
      T:=INV(T); RETURN; 
(*7*) END ANPEDE; 


PROCEDURE ANREPE(M,MB,A,B: LIST): LIST; 
(*Algebraic number represent element of a primitive extension.
M is the rational minimal polynomial of an algebraic number
gamma.  MB is the integral minimal polynomial of gamma.
A and B are elements of Q( gamma ) (y) which can be and are
represented as bivariate integral polynomials, i.e. as elements
of Z(x,y).  A eq AP(x-ty) for a minimal polynomial AP of an
algebraic number alpha, and B eq B(y) is the minimal polynomial
of an algebraic number beta.  gamma is a primitive element
for alpha and beta.  B is a univariate rational polynomial
which is the representation for beta as an element of Q( gamma ).*)
VAR   AL, BL, C0, C1, D, EL0, EL1, QL, R, RL, S, S1, T: LIST; 
BEGIN
(*1*) (*get subresultant of degree one of a and b.*) 
      IF PDEG(A) > PDEG(B) THEN S:=IPSPRS(2,A,B); ELSE
         S:=IPSPRS(2,B,A); END; 
      S:=INV(S); S1:=SECOND(S); 
(*2*) (*reduce coefficients mod m.*) FIRST4(S1, EL1,C1,EL0,C0); 
      C1:=RPFIP(1,C1); C0:=RPFIP(1,C0); RPQR(1,C1,M, QL,C1); 
      RPQR(1,C0,M, QL,C0); 
(*3*) (*find similar integral polynomial for leading coefficient.*) 
      IPSRP(1,C1, AL,C1); C0:=RPRNP(1,AL,C0); 
(*4*) (*multiply c sub 0 by negated inverse of c sub 1.*) IUPRC(MB,C1,
      T,RL); R:=RNRED(1,RL); R:=RNNEG(R); T:=RPFIP(1,T); 
      D:=AFPROD(M,T,C0); BL:=RPRNP(1,R,D); RETURN(BL); 
(*7*) END ANREPE; 


PROCEDURE APDWR(M,I,BL,NL: LIST); 
(*Algebraic point, decimal write.  M,I, and b constitute the
representation of an algebraic point in r-dimensional euclidean
space for some r ge 1.  n is a nonnegative integer.  For each
coordinate b sub i of b, b sub i is represented by a rational
number r sub i with inaccuracy of approximation at most
10 sup -(n+1).  Then r sub i is approximated by a decimal
fraction d sub i with n decimal digits following the decimal
point, and d sub i is written in the output stream.  The
inaccuracy of the approximation of d sub i to r sub i is
at most (1/2) 10 sup -n.*)
VAR   BL1, BLP, J, N: LIST; 
BEGIN
(*1*) BLP:=BL; SWRITE("( "); 
      WHILE BLP <> SIL DO ADV(BLP, BL1,BLP); ANFAF(M,I,BL1, N,J); 
            ANDWR(N,J,NL); 
            IF BLP <> SIL THEN SWRITE(", "); END; 
            END; 
      SWRITE(" )"); RETURN; 
(*4*) END APDWR; 


PROCEDURE IPAFME(RL,M,A,BL: LIST): LIST; 
(*Integral polynomial, algebraic number field multiple evaluation.
A is an integral polynomial in r
variables, r ge 1.  M is the rational minimal polynomial of an
algebraic number alpha.   b eq (b sub 1 ,... , b sub k ) is
a list of k elements of Q( alpha ), for some k, 1 le k le r.
b eq a(b sub 1 ,... , b sub k , x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)
VAR   AP, B: LIST; 
BEGIN
(*1*) (*convert a to a polynomial over Q( alpha ).*) AP:=AFPFIP(RL,A); 
(*2*) (*evaluate at b.*) B:=AFPME(RL,M,AP,BL); RETURN(B); 
(*5*) END IPAFME; 


PROCEDURE IUPMRN(R: LIST): LIST; 
(*Integral univariate polynomial minimal polynomial of a rational number. 
R is a rational number.  M is the integral minimal polynomial of R.*)
VAR   J1Y, M, R1, R2: LIST; 
BEGIN
(*1*) IF R = 0 THEN M:=PMON(1,1); ELSE FIRST2(R, R1,R2); 
         J1Y:=INEG(R1); M:=PBIN(R2,1,J1Y,0); END; 
      RETURN(M); 
(*4*) END IUPMRN; 


PROCEDURE RPAFME(RL,M,A,BL: LIST): LIST; 
(*Rational polynomial, algebraic number field multiple evaluation.
A is a rational polynomial in r
variables, r ge 1.  M is the rational minimal polynomial of an
algebraic number alpha.   b eq (b sub 1 ,... , b sub k ) is
a list of k elements of Q( alpha ), for some k, 1 le k le r.
B eq A(b sub 1 ,... , b sub k , x sub k+1 ,... , x sub r ),
an element of Q( alpha )(x sub k+1 ,... , x sub r ).*)
VAR   AP, B: LIST; 
BEGIN
(*1*) (*convert a to a polynomial over Q( alpha ).*) AP:=AFPFRP(RL,A); 
(*2*) (*evaluate at b.*) B:=AFPME(RL,M,AP,BL); RETURN(B); 
(*5*) END RPAFME; 


END SACEXT8.

(* -EOF- *)
