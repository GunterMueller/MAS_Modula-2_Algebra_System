
(* ----------------------------------------------------------------------------
 * $Id: SACPGCD.mi,v 1.3 1992/10/15 16:29:05 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPGCD.mi,v $
 * Revision 1.3  1992/10/15  16:29:05  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:35:02  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACPGCD;

(* SAC Polynomial GCD and RES System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX, MASODD, MASEVEN;

FROM MASSTOR IMPORT LIST, BETA, SIL,
                    ADV, FIRST, RED, SRED, SFIRST, COMP, INV;

FROM MASERR IMPORT ERROR, fatal;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM SACLIST IMPORT CONC, SECOND, FIRST2, LIST4, COMP2, 
                    OWRITE, EQUAL, LIST2, ADV2, CLOUT;

FROM SACI IMPORT ISIGNF, IEXP, IDPR, IGCD, ILCM, ILOG2, IMAX, 
                 ICOMP, IABSF, IMP2, IPROD, IQ; 

FROM SACM IMPORT MDHOM, MDINV, MDPROD, MDNEG;

FROM SACCOMB IMPORT IFACTL;

FROM SACPOL IMPORT PRIME, PDEG, PDEGV, PDEGSV, PINV, PLDCF, PLBCF, PFDP,
                   VCOMP, VMIN;

FROM SACIPOL IMPORT IPABS, IPCRA, IPIP, IPIQ, IPMAXN, IPFCB, 
                    IPPSR, IPFRP, IPEXP, IPNEG, IPPROD, IPQ, 
                    IPONE, IPSIGN, IPSUMN, IPDMV;

FROM SACMPOL IMPORT MPHOM, MPMDP, MPEMV, MPEVAL, MPINT, MPMON, 
                    MPPROD, MPPSR, MUPDER, MPQR, MPDIF, MPEXP, 
                    MPNEG, MPQ, MPUP, MPUQ; 

FROM SACRPOL IMPORT RPRNP;

FROM SACDPOL IMPORT DMUPNR, DPFP;

CONST rcsidi = "$Id: SACPGCD.mi,v 1.3 1992/10/15 16:29:05 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPC(RL,A: LIST): LIST; 
(*Integral polynomial content.  A is an integral polynomial in r
variables.  C is the content of A.*)
VAR  AP, C, C1, CP, CP1, RLP: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN C:=0; RETURN(C); END; 
(*2*) (*a ne 0.*) AP:=RED(A); ADV(AP, C,AP); RLP:=RL-1; 
      WHILE AP <> SIL DO AP:=RED(AP); ADV(AP, C1,AP); 
            IPGCDC(RLP,C,C1, C,CP,CP1); 
            IF IPONE(RLP,C) = 1 THEN RETURN(C); END; 
            END; 
      C:=IPABS(RLP,C); RETURN(C); 
(*5*) END IPC; 


PROCEDURE IPCPP(RL,A: LIST;  VAR C,AB: LIST); 
(*Integral polynomial content and primitive part.  A is an integral
polynomial in r variables.  C is the content of A and AB is the
primitive part of A.*)
VAR  SL: LIST; 
BEGIN
(*1*) IPSCPP(RL,A, SL,C,AB); RETURN; 
(*4*) END IPCPP; 


PROCEDURE IPGCDC(RL,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Integral polynomial greatest common divisor and cofactors.  A and B
are integral polynomials in r variables, r ge 0.  C=GCD(A,B).
If C is non-zero then AB=A/C and BB=B/C.  Otherwise AB=0 and BB=0.*)
VAR  AH, AHS, AL, ALB, ALH, ALP, AP, AS, BH, BHS, BL, BLB, BLH, BLP,
     BP, BS, CHS, CL, CLH, CLHP, CLP, CLPP, CLS, CP, CS, DL, DLB, EL,
     ELB, FL, FLB, GL, GLB, GLH, J1Y, J2Y, P, PL,
     Q, QL, QLP, TL, U, US, V, VS, W, WL, WP, WS: LIST; 
BEGIN
(*1*) (*a=b=0.*) 
      IF (A = 0) AND (B = 0) THEN C:=0; AB:=0; BB:=0; RETURN; 
         END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN C:=IGCD(A,B); AB:=IQ(A,C); BB:=IQ(B,C); 
         RETURN; END; 
(*3*) (*a=0 or b=0.*) 
      IF A = 0 THEN C:=IPABS(RL,B); AB:=0; J1Y:=IPSIGN(RL,B); 
         BB:=PINV(0,J1Y,RL); RETURN; END; 
      IF B = 0 THEN C:=IPABS(RL,A); BB:=0; J1Y:=IPSIGN(RL,A); 
         AB:=PINV(0,J1Y,RL); RETURN; END; 
(*4*) (*compute integer contents and primitive parts.*) IPICPP(RL,A,
      AL,AH); IPICPP(RL,B, BL,BH); CL:=IGCD(AL,BL); 
(*5*) (*compute normalization factor.*) ALH:=PLBCF(RL,AH); 
      BLH:=PLBCF(RL,BH); CLH:=IGCD(ALH,BLH); 
(*6*) (*compute norms.*) DL:=IPMAXN(RL,AH); EL:=IPMAXN(RL,BH); 
      FL:=IMAX(DL,EL); J1Y:=IPROD(2,CLH); GL:=IPROD(J1Y,FL); 
(*7*) (*compute degree vectors.*) U:=PDEGV(RL,AH); V:=PDEGV(RL,BH); 
(*8*) (*compute factor coefficient bounds.*) J1Y:=IPFCB(U); 
      DLB:=IMP2(DL,J1Y); J1Y:=IPFCB(V); ELB:=IMP2(EL,J1Y); 
      FLB:=IMAX(DLB,ELB); J1Y:=IPROD(8,CLH); GLB:=IPROD(J1Y,FLB); 
(*9*) (*initialize prime list and degree vector.*) P:=PRIME; 
      J1Y:=FIRST(U); J1Y:=J1Y+1; J2Y:=RED(U); W:=COMP(J1Y,J2Y); 

REPEAT REPEAT REPEAT REPEAT REPEAT REPEAT
(*10*) (*obtain next prime.*) 
       IF P = SIL THEN ERROR(fatal,"PRIME LIST EXHAUSTED IN IPGCDC."); 
          RETURN END; 
       ADV(P, PL,P); 

(*11*) (*map normalization factor.*) CLS:=MDHOM(PL,CLH); 
       UNTIL CLS <> 0; (*then go to 10; end;*)

(*12*) (*map ah and bh.*) AS:=MPHOM(RL,PL,AH); US:=PDEGV(RL,AS); 
       UNTIL EQUAL(U,US) <> 0; (* then go to 10; end;*)
       BS:=MPHOM(RL,PL,BH); VS:=PDEGV(RL,BS); 
       UNTIL EQUAL(V,VS) <> 0; (*then go to 10; end;*) 
(*13*) (*compute g.c.d.*) MPGCDC(RL,PL,AS,BS, CS,AHS,BHS); 
(*14*) (*test for constant g.c.d.*) 
       IF IPONE(RL,CS) = 1 THEN C:=PINV(0,CL,RL); 
          AB:=IPIQ(RL,A,CL); BB:=IPIQ(RL,B,CL); RETURN; END; 
(*15*) (*conditional initialization of chinese remainder process.*) 
       WS:=PDEGV(RL,CS); TL:=VCOMP(W,WS); 
       IF TL >= 2 THEN Q:=1; AP:=0; BP:=0; CP:=0; W:=VMIN(W,WS); WP:=W; 
          GLH:=GLB; 
          REPEAT ADV(WP, WL,WP); J1Y:=WL+1; GLH:=IPROD(GLH,J1Y); 
                 UNTIL WP = SIL; 
          END; 
(*16*) (*test for unlucky prime.*) 
       UNTIL NOT ((TL = 1) OR (TL = 3) OR 
                  ((TL = 0) AND (ICOMP(Q,GLH) > 0))
                 ); (*then go to 10; end;*) 

(*17*) (*apply chinese remainder algorithm.*) 
       CHS:=MPMDP(RL,PL,CLS,CS); 
       J1Y:=MDHOM(PL,Q); QLP:=MDINV(PL,J1Y); 
       CP:=IPCRA(Q,PL,QLP,RL,CP,CHS); 
       AP:=IPCRA(Q,PL,QLP,RL,AP,AHS); 
       BP:=IPCRA(Q,PL,QLP,RL,BP,BHS); 
       Q:=IPROD(Q,PL); 
(*18*) (*test for completion.*) 
       UNTIL ICOMP(Q,GL) > 0; (* then go to 10; end; *)
       QL:=ILOG2(Q); J1Y:=IPSUMN(RL,CP); CLP:=ILOG2(J1Y); 
       J1Y:=IPMAXN(RL,AP); ALP:=ILOG2(J1Y); J1Y:=IPMAXN(RL,BP); 
       BLP:=ILOG2(J1Y); CLPP:=MASMAX(ALP,BLP); 
       UNTIL QL >= CLP+CLPP+2; (*then go to 10; end;*) 
(*19*) (*remove normalization.*) IPICPP(RL,CP, CLP,C); 
       CLHP:=IQ(CLH,CLP); AB:=IPIQ(RL,AP,CLHP); BB:=IPIQ(RL,BP,CLHP); 
       C:=IPIP(RL,CL,C); ALB:=IQ(AL,CL); AB:=IPIP(RL,ALB,AB); 
       BLB:=IQ(BL,CL); BB:=IPIP(RL,BLB,BB); RETURN; 
(*22*) END IPGCDC; 


PROCEDURE IPIC(RL,A: LIST): LIST; 
(*Integral polynomial integer content.  A is an integral polynomial in
r variables.  c is the integer content of A.*)
VAR  CL: LIST; 
BEGIN
(*1*) IF A = 0 THEN CL:=0; ELSE CL:=IPICS(RL,A,0); END; 
      RETURN(CL); 
(*4*) END IPIC; 


PROCEDURE IPICPP(RL,A: LIST;  VAR AL,AB: LIST); 
(*Integral polynomial integer content and primitive part.  A is an
integral polynomial in r variables.  a is the integer content of A.
AB=A/a if A is non-zero and AB=0 if A=0.*)
BEGIN
(*1*) IF A = 0 THEN AL:=0; AB:=0; ELSE AL:=IPIC(RL,A); 
         AB:=IPIQ(RL,A,AL); END; 
      RETURN; 
(*4*) END IPICPP; 


PROCEDURE IPICS(RL,A,CL: LIST): LIST; 
(*Integral polynomial integer content subroutine.  A is a non-zero
integral polynomial in r variables.  c is an integer.  d is the
greatest common divisor of c and the integer content of A.*)
VAR  AL, AP, DL, EL, RLP: LIST; 
BEGIN
(*1*) AP:=A; RLP:=RL-1; DL:=CL; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 0 THEN DL:=IGCD(AL,DL); ELSE
                DL:=IPICS(RLP,AL,DL); END; 
             IF DL = 1 THEN RETURN(DL); END; 
             UNTIL AP = SIL; 
      RETURN(DL); 
(*4*) END IPICS; 


PROCEDURE IPIPP(RL,A: LIST): LIST; 
(*Integral polynomial integer primitive part.  A is an integral
polynomial in r variables.  If A ne 0 then AB=A/a where a is the
integer content of A.  If A=0 then AB=0.*)
VAR  AB, AL: LIST; 
BEGIN
(*1*) IPICPP(RL,A, AL,AB); RETURN(AB); 
(*4*) END IPIPP; 


PROCEDURE IPPGSD(RL,A: LIST): LIST; 
(*Integral polynomial primitive greatest squarefree divisor.  A is an
integral polynomial in r variables.  If A=0 then B=0.  Otherwise B is
the greatest squarefree divisor of the primitive part of A.*)
VAR  B, BP, C, D: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*a ne 0.*) B:=IPPP(RL,A); 
      IF FIRST(B) > 0 THEN BP:=IPDMV(RL,B); IPGCDC(RL,B,BP, C,B,D); 
         END; 
      RETURN(B); 
(*5*) END IPPGSD; 


PROCEDURE IPPP(RL,A: LIST): LIST; 
(*Integral polynomial primitive part.  A is an integral polynomial in
r variables.  AB is the primitive part of A.*)
VAR  AB, C: LIST; 
BEGIN
(*1*) IPCPP(RL,A, C,AB); RETURN(AB); 
(*4*) END IPPP; 


PROCEDURE IPRES(RL,A,B: LIST): LIST; 
(*Integral polynomial resultant.  A and B are integral polynomials in
r variables, r ge 1, of positive degrees.  C is the resultant of A and
B with respect to the main variable, an integral polynomial in r-1
variables.*)
VAR  AS, BS, C, CS, DL, EL, FL, I, J1Y, ML, NL, PL, Q, QL,
     RLP: LIST; 
BEGIN
(*1*) (*compute coefficient bound.*) DL:=IPMAXN(RL,A); 
      EL:=IPMAXN(RL,B); ML:=FIRST(A); NL:=FIRST(B); DL:=IEXP(DL,NL); 
      EL:=IEXP(EL,ML); J1Y:=ML+NL; FL:=IFACTL(J1Y); FL:=IPROD(EL,FL); 
      FL:=IPROD(DL,FL); 
(*2*) (*initialize.*) I:=PRIME; Q:=1; C:=0; RLP:=RL-1; 
(*3*) (*loop.*) 
      WHILE I <> SIL DO ADV(I, PL,I); AS:=MPHOM(RL,PL,A); 
            IF PDEG(AS) = ML THEN BS:=MPHOM(RL,PL,B); 
               IF PDEG(BS) = NL THEN CS:=MPRES(RL,PL,AS,BS); 
                  QL:=MDHOM(PL,Q); QL:=MDINV(PL,QL); 
                  C:=IPCRA(Q,PL,QL,RLP,C,CS); Q:=IPROD(Q,PL); 
                  IF ICOMP(Q,FL) >= 0 THEN RETURN(C); END; 
                  END; 
               END; 
            END; 
(*4*) (*algorithm fails.*) ERROR(fatal,"ALGORITHM IPRES FAILS.");  
(*7*) RETURN(C); END IPRES; 


PROCEDURE IPRPRS(RL,A,B: LIST): LIST; 
(*Integral polynomial reduced polynomial remainder sequence.  A and B
are non-zero integral polynomials in r variables with deg(A) ge deg(B).
S is the reduced polynomial remainder sequence of A and B.*)
VAR  A1, A2, A3, AL1, ALS1, DL, IL, J1Y, NL1, NL2, S: LIST; 
BEGIN
(*1*) A1:=A; A2:=B; S:=LIST2(A2,A1); DL:=-1; 
      LOOP A3:=IPPSR(RL,A1,A2); 
           IF A3 = 0 THEN S:=INV(S); RETURN(S); END; 
           IF DL >= 0 THEN AL1:=PLDCF(A1); ALS1:=AL1; 
              FOR IL:=1 TO DL DO
                  IF RL = 1 THEN ALS1:=IPROD(ALS1,AL1); ELSE
                     J1Y:=RL-1; ALS1:=IPPROD(J1Y,ALS1,AL1); END; 
                  END; 
              ALS1:=LIST2(0,ALS1); A3:=IPQ(RL,A3,ALS1); END; 
           S:=COMP(A3,S); NL1:=PDEG(A1); NL2:=PDEG(A2); DL:=NL1-NL2; 
           A1:=A2; A2:=A3; 
           END; 
(*4*) RETURN(S); END IPRPRS; 


PROCEDURE IPSCPP(RL,A: LIST;  VAR SL,C,AB: LIST); 
(*Integral polynomial sign, content, and primitive part.  A is
an integral polynomial in R ge 1 variables.  s is
the sign of A, C is the content of A, and AB is the primitive
part of A.*)
VAR  A1, AP, C1, EL, RLP: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN SL:=0; C:=0; AB:=0; RETURN; END; 
(*2*) (*a ne 0.*) SL:=IPSIGN(RL,A); AP:=IPABS(RL,A); RLP:=RL-1; 
      C:=IPC(RL,AP); 
      IF IPONE(RLP,C) = 1 THEN AB:=AP; ELSE AB:=BETA; 
         REPEAT ADV2(AP, EL,A1,AP); C1:=IPQ(RLP,A1,C); 
                AB:=COMP2(C1,EL,AB); 
                UNTIL AP = SIL; 
         AB:=INV(AB); END; 
      RETURN; 
(*5*) END IPSCPP; 


PROCEDURE IPSF(RL,A: LIST): LIST; 
(*Integral polynomial squarefree factorization.  A is a positive pri-
mitive integral polynomial in r variables of positive degree.  L is
the list ((e sub 1,A sub 1), ...,(e sub l,A sub l)) where A equal to
the product of (A sub i)**(e sub i) for i = 1, ...,k is the
squarefree factorization of A in which 1 le e sub 1 lt e sub 2 lt  ...
lt e sub k and each A sub i is a positive squarefree polynomial of
positive degree.*)
VAR  AP, B, BP, C, CP, D, J1Y, JL, L: LIST; 
BEGIN
(*1*) (*initialize.*) L:=BETA; AP:=IPDMV(RL,A); IPGCDC(RL,A,AP,
      B,C,CP); JL:=1; 
(*2*) (*compute factors.*) 
      WHILE PDEG(B) > 0 DO IPGCDC(RL,B,C, D,BP,CP); 
            IF PDEG(CP) > 0 THEN J1Y:=LIST2(JL,CP); L:=COMP(J1Y,L); 
               END; 
            B:=BP; C:=D; JL:=JL+1; END; 
(*3*) (*finish.*) J1Y:=LIST2(JL,C); L:=COMP(J1Y,L); L:=INV(L); 
      RETURN(L); 
(*6*) END IPSF; 


PROCEDURE IPSPRS(RL,A,B: LIST): LIST; 
(*Integral polynomial subresultant polynomial remainder sequence.
A and B are non-zero integral polynomials in r variables with
deg(A) ge deg(B).  S is the subresultant p.r.s. of the first kind
of A and B.*)
VAR  DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y,
     NL1, NL2, NL3, RLP, S: LIST; 
BEGIN
(*1*) (*initialize.*) G1:=A; G2:=B; S:=LIST2(G2,G1); NL1:=PDEG(G1); 
      NL2:=PDEG(G2); DL0:=0; DL1:=NL1-NL2; RLP:=RL-1; IL:=1; 
LOOP
(*2*) (*compute gh(il+2).*) GH3:=IPPSR(RL,G1,G2); 
      IF GH3 = 0 THEN S:=INV(S); RETURN(S); END; 
      IF MASEVEN(DL1)(*=1*) THEN GH3:=IPNEG(RL,GH3); END; 
      NL3:=PDEG(GH3); 
(*3*) (*compute hl(il).*) 
      IF IL > 1 THEN GL1:=PLDCF(G1); HL1:=IPEXP(RLP,GL1,DL0); 
         IF IL > 2 THEN J1Y:=DL0-1; HLS0:=IPEXP(RLP,HL0,J1Y); 
            HL1:=IPQ(RLP,HL1,HLS0); HLS0:=0; END; 
         END; 
(*4*) (*compute g(il+2).*) 
      IF IL = 1 THEN G3:=GH3; ELSE HLS1:=IPEXP(RLP,HL1,DL1); 
         HLS1:=IPPROD(RLP,GL1,HLS1); HLS1:=LIST2(0,HLS1); 
         G3:=IPQ(RL,GH3,HLS1); HLS1:=0; GH3:=0; END; 
(*5*) (*update.*) S:=COMP(G3,S); NL1:=NL2; NL2:=NL3; DL0:=DL1; 
      DL1:=NL1-NL2; G1:=G2; G2:=G3; 
      IF IL > 1 THEN HL0:=HL1; END; 
      IL:=IL+1; 
      END; (* loop go to 2*) 
(*8*) RETURN(S); END IPSPRS;

 
PROCEDURE IPSRP(RL,A: LIST;  VAR AL,AB: LIST); 
(*Integral polynomial similiar to rational polynomial.  A is a
rational polynomial in r variables, r ge 0.  a is a
rational number, and AB is an integral polynomial such that A=a*AB. If
A eq 0 then a=AB=0. Otherwise AB is integer primitive and positive.*)
VAR  AS, SL, UL, ULP, VL: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN AL:=0; AB:=0; RETURN; END; 
(*2*) (*a ne 0.*) RPBLGS(RL,A, UL,VL,SL); ULP:=IDPR(UL,SL); 
      AL:=LIST2(ULP,VL); AS:=RPRNP(RL,AL,A); AB:=IPFRP(RL,AS); RETURN; 
(*5*) END IPSRP; 


PROCEDURE MPGCDC(RL,PL,A,B: LIST;  VAR C,AB,BB: LIST); 
(*Modular polynomial greatest common divisor and cofactors.  p is a
prime beta-integer.  A and B are polynomials in r variables over
Z sub p.  C=gcd(A,B).  If C is non-zero then AB=A/C and BB=B/C.
Otherwise AB=0 and BB=0.*)
VAR  AH, AHS, AL, ALB, ALH, ALP, AP, AS, BH, BHS, BL, BLB, BLH, BLP,
     BP, BS, CHS, CL, CLH, CLHP, CLP, CLPP, CLS, CP, CS, DL, EL, 
     FL, GL, J1Y, J2Y, Q, QLP, RLP, TL, U, US, V, VS, W, WS:
     LIST; 
BEGIN
(*1*) (*a=b=0.*) 
      IF (A = 0) AND (B = 0) THEN C:=0; AB:=0; BB:=0; RETURN; 
         END; 
(*2*) (*a=0 or b=0.*) 
      IF A = 0 THEN BL:=PLBCF(RL,B); C:=MPMON(RL,PL,B); AB:=0; 
         BB:=PINV(0,BL,RL); RETURN; END; 
      IF B = 0 THEN AL:=PLBCF(RL,A); C:=MPMON(RL,PL,A); BB:=0; 
         AB:=PINV(0,AL,RL); RETURN; END; 
(*3*) (*rl=1.*) 
      IF RL = 1 THEN C:=MUPGCD(PL,A,B); AB:=MPQ(RL,PL,A,C); 
         BB:=MPQ(RL,PL,B,C); RETURN; END; 
(*4*) (*compute univariate contents and primitive parts.*) 
      MPUCPP(RL,PL,A, AL,AH); MPUCPP(RL,PL,B, BL,BH); 
      CL:=MUPGCD(PL,AL,BL); 
(*5*) (*compute normalization factor.*) RLP:=RL-1; ALH:=PLBCF(RLP,AH); 
      BLH:=PLBCF(RLP,BH); CLH:=MUPGCD(PL,ALH,BLH); 
(*6*) (*compute degrees.*) U:=PDEGV(RLP,AH); V:=PDEGV(RLP,BH); 
      EL:=PDEGSV(RL,AH,1); FL:=PDEGSV(RL,BH,1); J1Y:=PDEG(CLH); 
      J2Y:=MASMAX(EL,FL); GL:=J1Y+J2Y; 
(*7*) (*initialize element and degree vector.*) DL:=-1; J1Y:=FIRST(U); 
      J1Y:=J1Y+1; J2Y:=RED(U); W:=COMP(J1Y,J2Y); 

REPEAT REPEAT REPEAT REPEAT REPEAT REPEAT
(*8*) (*obtain next element.*) DL:=DL+1; 
      IF DL = PL THEN
         ERROR(fatal,"ELEMENTS OF Z SUB P EXHAUSTED IN MPGCDC."); 
         RETURN END; 

(*9*) (*map normalization factor.*) CLS:=MPEMV(1,PL,CLH,DL); 
      UNTIL CLS <> 0; (*then go to 8; end;*) 

(*10*) (*map ah and bh.*) AS:=MPEVAL(RL,PL,AH,1,DL); US:=PDEGV(RLP,AS); 
       UNTIL EQUAL(U,US) <> 0; (*then go to 8; end;*) 
       BS:=MPEVAL(RL,PL,BH,1,DL); VS:=PDEGV(RLP,BS); 
       UNTIL EQUAL(V,VS) <> 0; (*then go to 8; end;*) 

(*11*) (*compute g.c.d.*) MPGCDC(RLP,PL,AS,BS, CS,AHS,BHS); 
(*12*) (*test for constant g.c.d.*) 
       IF IPONE(RLP,CS) = 1 THEN C:=PINV(0,CL,RLP); 
          AB:=MPUQ(RL,PL,A,CL); BB:=MPUQ(RL,PL,B,CL); RETURN; END; 
(*13*) (*conditional initialization of interpolation process.*) 
       WS:=PDEGV(RLP,CS); TL:=VCOMP(W,WS); 
       IF TL >= 2 THEN Q:=LIST2(0,1); AP:=0; BP:=0; CP:=0; 
          W:=VMIN(W,WS); END; 

(*14*) (*test for unlucky element.*) 
       UNTIL NOT ( (TL = 1) OR (TL = 3) OR 
                   (TL = 0) AND (PDEG(Q) > GL) ); 
             (*then go to 8; end;*) 

(*15*) (*interpolate.*) CHS:=MPMDP(RLP,PL,CLS,CS); 
       J1Y:=MPEMV(1,PL,Q,DL); QLP:=MDINV(PL,J1Y); 
       CP:=MPINT(PL,Q,DL,QLP,RL,CP,CHS); 
       AP:=MPINT(PL,Q,DL,QLP,RL,AP,AHS); 
       BP:=MPINT(PL,Q,DL,QLP,RL,BP,BHS); J1Y:=MDNEG(PL,DL); 
       J1Y:=LIST4(1,1,0,J1Y); Q:=MPPROD(1,PL,Q,J1Y); 
(*16*) (*test for completion.*) 
       UNTIL PDEG(Q) > GL; (*then go to 8; end;*) 
       CLP:=PDEGSV(RL,CP,1); ALP:=PDEGSV(RL,AP,1); BLP:=PDEGSV(RL,BP,1); 
       CLPP:=MASMAX(ALP,BLP); 
       UNTIL PDEG(Q) > CLP+CLPP; (*then go to 8; end;*) 

(*17*) (*remove normalization.*) MPUCPP(RL,PL,CP, CLP,C); 
       CLHP:=MPQ(1,PL,CLH,CLP); AB:=MPUQ(RL,PL,AP,CLHP); 
       BB:=MPUQ(RL,PL,BP,CLHP); C:=MPUP(RL,PL,CL,C); 
       ALB:=MPQ(1,PL,AL,CL); AB:=MPUP(RL,PL,ALB,AB); 
       BLB:=MPQ(1,PL,BL,CL); BB:=MPUP(RL,PL,BLB,BB); RETURN; 
(*20*) END MPGCDC; 


PROCEDURE MPRES(RL,PL,A,B: LIST): LIST; 
(*Modular polynomial resultant.  p is a prime beta-digit.  A and B are
polynomials over Z sub p in r variables, r ge 1, of positive degree.
C is the resultant of A and B, a polynomial over Z sub p in r-1
variables.*)
VAR  AS, BL, BS, C, CS, D, DP, IL, J1Y, J2Y, KL, ML, ML1, NL, NL1,
     RLP: LIST; 
BEGIN
(*1*) (*rl=1.*) 
      IF RL = 1 THEN C:=MUPRES(PL,A,B); RETURN(C); END; 
(*2*) (*initialize.*) ML:=FIRST(A); ML1:=PDEGSV(RL,A,1); NL:=FIRST(B); 
      NL1:=PDEGSV(RL,B,1); J1Y:=ML*NL1; J2Y:=ML1*NL; KL:=J1Y+J2Y; 
      RLP:=RL-1; C:=0; D:=LIST2(0,1); IL:=0; 
(*3*) (*recursion.*) 
      WHILE IL < PL DO AS:=MPEVAL(RL,PL,A,1,IL); 
            IF PDEG(AS) = ML THEN BS:=MPEVAL(RL,PL,B,1,IL); 
               IF PDEG(BS) = NL THEN CS:=MPRES(RLP,PL,AS,BS); 
                  BL:=MPEMV(1,PL,D,IL); BL:=MDINV(PL,BL); 
                  C:=MPINT(PL,D,IL,BL,RLP,C,CS); J1Y:=PL-IL; 
                  DP:=LIST4(1,1,0,J1Y); D:=MPPROD(1,PL,D,DP); 
                  IF PDEG(D) > KL THEN RETURN(C); END; 
                  END; 
               END; 
            IL:=IL+1; END; 
(*4*) (*algorithm fails.*) ERROR(fatal,"ALGORITHM MPRES FAILS.");  
(*7*) RETURN(C); END MPRES; 


PROCEDURE MPSPRS(RL,PL,A,B: LIST): LIST; 
(*Modular polynomial subresultant polynomial remainder sequence.
A and B are non-zero polynomials in r variables over Z sub p,
p a prime beta-integer, with deg(A) ge deg(B).
S is the subresultant p.r.s. of the first kind of A and B.*)
VAR  DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y,
     NL1, NL2, NL3, RLP, S: LIST; 
BEGIN
(*1*) (*initialize.*) G1:=A; G2:=B; S:=LIST2(G2,G1); NL1:=PDEG(G1); 
      NL2:=PDEG(G2); DL0:=0; DL1:=NL1-NL2; RLP:=RL-1; IL:=1; 
LOOP
(*2*) (*compute gh(il+2).*) GH3:=MPPSR(RL,PL,G1,G2); 
      IF GH3 = 0 THEN S:=INV(S); RETURN(S); END; 
      IF MASEVEN(DL1) (*= 1*) THEN GH3:=MPNEG(RL,PL,GH3); END; 
      NL3:=PDEG(GH3); 
(*3*) (*compute hl(il).*) 
      IF IL > 1 THEN GL1:=PLDCF(G1); HL1:=MPEXP(RLP,PL,GL1,DL0); 
         IF IL > 2 THEN J1Y:=DL0-1; HLS0:=MPEXP(RLP,PL,HL0,J1Y); 
            HL1:=MPQ(RLP,PL,HL1,HLS0); HLS0:=0; END; 
         END; 
(*4*) (*compute g(il+2).*) 
      IF IL = 1 THEN G3:=GH3; ELSE HLS1:=MPEXP(RLP,PL,HL1,DL1); 
         HLS1:=MPPROD(RLP,PL,GL1,HLS1); HLS1:=LIST2(0,HLS1); 
         G3:=MPQ(RL,PL,GH3,HLS1); HLS1:=0; GH3:=0; END; 
(*5*) (*update.*) S:=COMP(G3,S); NL1:=NL2; NL2:=NL3; DL0:=DL1; 
      DL1:=NL1-NL2; G1:=G2; G2:=G3; 
      IF IL > 1 THEN HL0:=HL1; END; 
      IL:=IL+1; 
      END; (*loop go to 2;*) 
(*8*) RETURN(S); END MPSPRS; 


PROCEDURE MPUC(RL,PL,A: LIST): LIST; 
(*Modular polynomial univariate content.  A is a polynomial in r
variables, r ge 2, over Z sub p, p a prime beta-integer.  c is the
univariate content of A.*)
VAR  CL: LIST; 
BEGIN
(*1*) IF A = 0 THEN CL:=0; ELSE CL:=MPUCS(RL,PL,A,0); END; 
      RETURN(CL); 
(*4*) END MPUC; 


PROCEDURE MPUCPP(RL,PL,A: LIST;  VAR AL,AB: LIST); 
(*Modular polynomial univariate content and primitive part.  A is a
polynomial in r variables, r ge 2, over Z sub p, p a prime
beta-integer.  a is the univariate content of A.  AB=A/a if A is
non-zero and AB=0 if A=0.*)
BEGIN
(*1*) IF A = 0 THEN AL:=0; AB:=0; ELSE AL:=MPUC(RL,PL,A); 
         AB:=MPUQ(RL,PL,A,AL); END; 
      RETURN; 
(*4*) END MPUCPP; 


PROCEDURE MPUCS(RL,PL,A,CL: LIST): LIST; 
(*Modular polynomial univariate content subroutine.  A is a non-zero
polynomial in r variables, r ge 2, over Z sub p, p a prime
beta-integer.  c is a univariate polynomial over Z sub p.  d is the
greatest common divisor of c and the univariate content of A.*)
VAR  AL, AP, DL, EL, RLP: LIST; 
BEGIN
(*1*) AP:=A; RLP:=RL-1; DL:=CL; 
      REPEAT ADV2(AP, EL,AL,AP); 
             IF RLP = 1 THEN DL:=MUPGCD(PL,AL,DL); ELSE
                DL:=MPUCS(RLP,PL,AL,DL); END; 
             UNTIL (AP = SIL) OR (PDEG(DL) = 0); 
      RETURN(DL); 
(*4*) END MPUCS; 


PROCEDURE MPUPP(RL,PL,A: LIST): LIST; 
(*Modular polynomial univariate primitive part.  A is a polynomial in
r variables, r ge 2, over Z sub p, p a prime beta-integer.  If A is
non-zero then AB=A/a where a is the univariate content of A.  If A=0
then AB=0.*)
VAR  AB, AL: LIST; 
BEGIN
(*1*) MPUCPP(RL,PL,A, AL,AB); RETURN(AB); 
(*4*) END MPUPP; 


PROCEDURE MUPEGC(PL,A,B: LIST;  VAR C,U,V: LIST); 
(*Modular univariate polynomial extended greatest common divisor.  p
is a prime beta-integer.  A and B are univariate polynomials over Z sub
p. C=gcd(A,B).  A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt
deg(A/C), else deg(V)=0.  Similarly, if deg(B/C) gt 0, then deg(U) lt
deg(B/C), else deg(U)=0.  If A=0, U=0.  If B=0, V=0.*)
VAR  D: LIST; 
BEGIN
(*1*) MUPHEG(PL,A,B, C,V); 
      IF A = 0 THEN U:=0; ELSE D:=MPPROD(1,PL,B,V); 
         D:=MPDIF(1,PL,C,D); U:=MPQ(1,PL,D,A); END; 
      RETURN; 
(*4*) END MUPEGC; 


PROCEDURE MUPGCD(PL,A,B: LIST): LIST; 
(*Modular univariate polynomial greatest common divisor.  A and B are
univariate polynomials over Z sub p, p a prime beta-integer.
C=gcd(A,B).*)
VAR  A1, A2, A3, C, ML, NL: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF A = 0 THEN C:=MPMON(1,PL,B); RETURN(C); END; 
      IF B = 0 THEN C:=MPMON(1,PL,A); RETURN(C); END; 
(*2*) (*general case.*) ML:=PDEG(A); NL:=PDEG(B); 
      IF ML >= NL THEN A1:=A; A2:=B; ELSE A1:=B; A2:=A; END; 
      A1:=DPFP(1,A1); A2:=DPFP(1,A2); 
      REPEAT A3:=DMUPNR(PL,A1,A2); A1:=A2; A2:=A3; 
             UNTIL A2 = 0; 
      A1:=PFDP(1,A1); C:=MPMON(1,PL,A1); RETURN(C); 
(*5*) END MUPGCD; 


PROCEDURE MUPHEG(PL,A,B: LIST;  VAR C,V: LIST); 
(*Modular univariate polynomial half-extended greatest common divisor.
p is a prime beta-integer.  A and B are univariate polynomials over
Z sub p.  C=gcd(A,B).  There exists a polynomial U such that
A*U+B*V=C, and, if deg(A/C) gt 0, then deg(V) lt deg(A/C).  If
deg(A/C)=0, deg(V) is also 0.  If B=0, V=0.*)
VAR  A1, A2, A3, AL, ALP, J1Y, Q, V1, V2, V3: LIST; 
BEGIN
(*1*) (*compute remainder sequence.*) V1:=0; V2:=LIST2(0,1); A1:=A; 
      A2:=B; 
      WHILE A2 <> 0 DO MPQR(1,PL,A1,A2, Q,A3); 
            J1Y:=MPPROD(1,PL,Q,V2); V3:=MPDIF(1,PL,V1,J1Y); A1:=A2; 
            A2:=A3; V1:=V2; V2:=V3; END; 
(*2*) (*adjust ldcf.*) 
      IF A1 = 0 THEN C:=0; V:=0; RETURN; END; 
      AL:=PLDCF(A1); ALP:=MDINV(PL,AL); C:=MPMDP(1,PL,ALP,A1); 
      V:=MPMDP(1,PL,ALP,V1); RETURN; 
(*5*) END MUPHEG; 


PROCEDURE MUPRES(PL,A,B: LIST): LIST; 
(*Modular univariate polynomial resultant.  p is a prime beta-digit.
A and B are univariate polynomials over Z sub p of positive degrees.
C is the resultant of A and B, an element of Z sub p.*)
VAR  A1, A2, A3, CL, CL2, IL, NL1, NL2, NL3, SL, TL: LIST; 
BEGIN
(*1*) (*initialize.*) CL:=1; A1:=DPFP(1,A); A2:=DPFP(1,B); 
      NL1:=FIRST(A1); NL2:=FIRST(A2); SL:=0; 
      IF NL1 < NL2 THEN
         IF (MASODD(NL1) (*= 1*)) AND (MASODD(NL2) (*= 1*)) THEN SL:=1; END; 
         TL:=A1; A1:=A2; A2:=TL; END; 
(*2*) (*loop.*) 
      REPEAT A3:=DMUPNR(PL,A1,A2); 
             IF A3 = 0 THEN CL:=0; RETURN(CL); END; 
             NL1:=FIRST(A1); NL2:=FIRST(A2); NL3:=FIRST(A3); 
             IF (MASODD(NL1) (* = 1*)) AND (MASODD(NL2) (*= 1*)) THEN
                SL:=1-SL; END; 
             CL2:=SECOND(A2); 
             FOR IL:=1 TO NL1-NL3 DO CL:=MDPROD(PL,CL,CL2); END; 
             A1:=A2; A2:=A3; 
             UNTIL NL3 = 0; 
(*3*) (*finish.*) CL2:=SECOND(A2); 
      FOR IL:=1 TO NL2 DO CL:=MDPROD(PL,CL,CL2); END; 
      IF SL = 1 THEN CL:=PL-CL; END; 
      RETURN(CL); 
(*6*) END MUPRES; 


PROCEDURE MUPSFF(PL,A: LIST): LIST; 
(*Modular univariate polynomial squarefree factorization.  p is a
prime beta-integer.  A is a monic univariate polynomial over Z sub p
of positive degree.  L is a list ((i(1),A(1)), ...,(i(r),A(r))) with
i(1) lt i(2) lt  ... lt i(r), A(j) a monic squarefree factor of a
of positive degree for 1 le j le r and A the product of A(j)**i(j)
for j=1, ...,r.*)
VAR  A1, AP, B, BP, C, D, EL, J1Y, JL, L, L1, LP, M, M1, MP: LIST; 
BEGIN
(*1*) (*initialize.*) LP:=SIL; AP:=MUPDER(PL,A); 
      IF AP = 0 THEN B:=A; (*go to 3;*) 
         ELSE 
         B:=MUPGCD(PL,A,AP); C:=MPQ(1,PL,A,B); JL:=1; 
(*2*) (*compute a(jl) with jl not divisible by pl.*) 
         REPEAT D:=MUPGCD(PL,B,C); 
                A1:=MPQ(1,PL,C,D); 
                IF FIRST(A1) > 0 THEN J1Y:=LIST2(JL,A1); 
                   LP:=COMP(J1Y,LP); END; 
                IF FIRST(D) > 0 THEN C:=D; B:=MPQ(1,PL,B,C); 
                   JL:=JL+1; (*go to 2;*) END;
                UNTIL FIRST(D) = 0; 
         END; (*goto*)
(*3*) (*compute a(jl) with jl divisible by pl.*) 
      IF FIRST(B) = 0 THEN L:=INV(LP); RETURN(L); END; 
      BP:=BETA; 
      REPEAT ADV2(B, EL,A1,B); EL:=EL DIV PL; BP:=COMP2(A1,EL,BP); 
             UNTIL B = SIL; 
      B:=INV(BP); M:=MUPSFF(PL,B); MP:=M; 
      REPEAT ADV(MP, M1,MP); J1Y:=FIRST(M1); EL:=PL*J1Y; SFIRST(M1,EL); 
             UNTIL MP = SIL; 
      M:=INV(M); 
(*4*) (*merge.*) L:=SIL; 
      WHILE (LP <> SIL) AND (M <> SIL) DO
            IF FIRST(FIRST(LP)) > FIRST(FIRST(M)) 
               THEN ADV(LP,L1,LP); 
               ELSE ADV(M, L1,M); END; 
            L:=COMP(L1,L); END; 
      IF M = SIL THEN LP:=INV(LP); ELSE LP:=INV(M); END; 
      L:=CONC(LP,L); RETURN(L); 
(*7*) END MUPSFF; 


PROCEDURE RPBLGS(RL,A: LIST;  VAR AL,BL,SL: LIST); 
(*Rational polynomial base coefficients least common multiple, greatest common divisor, and sign.  
A is a rational polynomial in r variables, r ge 0.  If A=0 then 
a=b=s=0.  Otherwise, a is the lcm of the denominators of the 
base coefficients of A, b is the gcd of the numerators of 
the base coefficients of A, and s is the sign of the leading base 
coefficient of A.*)
VAR  ALP, AS, BLP, CL, EL, RLP, SLP: LIST; 
BEGIN
(*1*) (*a eq 0.*) 
      IF A = 0 THEN AL:=0; BL:=0; SL:=0; RETURN; END; 
(*2*) (*rl eq 0.*) 
      IF RL = 0 THEN BLP:=FIRST(A); SL:=ISIGNF(BLP); 
         BL:=IABSF(BLP); AL:=SECOND(A); RETURN; END; 
(*3*) (*general case.*) RLP:=RL-1; ADV2(A, EL,CL,AS); RPBLGS(RLP,CL,
      AL,BL,SL); 
      WHILE AS <> SIL DO ADV2(AS, EL,CL,AS); 
            IF RLP = 0 THEN FIRST2(CL, BLP,ALP); ELSE
               RPBLGS(RLP,CL, ALP,BLP,SLP); END; 
            AL:=ILCM(AL,ALP); 
            IF BL <> 1 THEN BL:=IGCD(BL,BLP); END; 
            END; 
      RETURN; 
(*6*) END RPBLGS; 


END SACPGCD.
(* -EOF- *)
