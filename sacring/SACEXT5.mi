(* ----------------------------------------------------------------------------
 * $Id: SACEXT5.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT5.mi,v $
 * Revision 1.3  1992/10/15  16:28:57  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:51  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:00  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT5;

(* SAC Extensions 5 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASELEM IMPORT MASEVEN, MASREM, MASODD;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    INV, COMP, SRED, ADV, FIRST, RED;

FROM MASERR IMPORT ERROR, fatal;

FROM SACLIST IMPORT CONC, MEMBER, EQUAL, 
                    LIST2, SECOND, ADV2, FIRST2, LAST;

FROM SACI IMPORT IEXP, ICOMP, IPROD, IDP2, IMP2, IORD2;

FROM SACM IMPORT MDPROD, MDHOM, MDINV;

FROM SACCOMB IMPORT IFACTL;

FROM SACPOL IMPORT PRIME, PMON, PLDCF, PDEG;

FROM SACIPOL IMPORT IPPSR, IPDMV, IPCRA, IPMAXN, IPPROD, 
                    IPQ, IPNEG, IPEXP;

FROM SACMPOL IMPORT MPMDP, MPDIF, MPHOM, MPQR, MPPROD;

FROM SACPGCD IMPORT IPRES, IPSF, IPSCPP, IPGCDC;

FROM SACEXT4 IMPORT PCONST;

CONST rcsidi = "$Id: SACEXT5.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPCSFB(RL,A: LIST): LIST; 
(*Integral polynomial coarsest squarefree basis.  A eq (A sub 1
, ..., A sub n ), n ge 0, is a list of positive primitive integral
polynomials in r variables, r ge 1, each of which is of positive
degree in its main variable.  B is a coarsest squarefree basis
for A.*)
VAR  A1, AP, AP1, AS, B, L, L1: LIST; 
BEGIN
(*1*) AS:=BETA; AP:=A; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); L:=IPSF(RL,A1); 
            REPEAT ADV(L, L1,L); AP1:=SECOND(L1); AS:=COMP(AP1,AS); 
                   UNTIL L = SIL; 
            END; 
      B:=ISPSFB(RL,AS); RETURN(B); 
(*4*) END IPCSFB; 


PROCEDURE IPDSCR(RL,A: LIST): LIST; 
(*Integral polynomial discriminant.  A is an integral polynomial
in r variables, r ge 1, of degree greater than or equal to two in
its main variable.  B is the discriminant of A.*)
VAR  AL, AP, B, NL, RLP: LIST; 
BEGIN
(*1*) AP:=IPDMV(RL,A); B:=IPRES(RL,A,AP); AL:=PLDCF(A); RLP:=RL-1; 
      B:=IPQ(RLP,B,AL); NL:=PDEG(A); 
      IF MASREM(NL,4) >= 2 THEN B:=IPNEG(RLP,B); END; 
      RETURN(B); 
(*4*) END IPDSCR; 


PROCEDURE IPLCPP(RL,A: LIST;  VAR C,P: LIST); 
(*Integral polynomial list of contents and primitive parts.
A eq (A sub 1 , ..., A sub n ), n ge 0, is a list of integral
polynomials in r variables, r ge 1.  C eq (C sub 1 , ..., C sub s ),
0 le s le n, is a list such that for 1 le i le n, content(a sub i ) eq
c sub j for some j, 1 le j le s, if and only if content(a sub i )
has positive degree in some variable.
P eq (P sub 1 , ..., P sub m ), 0 le m le n, is a list such that
for 1 le i le n, PP(A sub i ) eq P sub j for some j, 1 le j le m,
if and only if PP(a sub i ) has positive degree in its main
variable.*)
VAR  A1, AP, C1, P1, RLP, SL: LIST; 
BEGIN
(*1*) C:=BETA; P:=BETA; AP:=A; RLP:=RL-1; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); IPSCPP(RL,A1, SL,C1,P1); 
            IF  NOT (PCONST(RLP,C1) = 1) THEN C:=COMP(C1,C); END; 
            IF PDEG(P1) > 0 THEN P:=COMP(P1,P); END; 
            END; 
      C:=INV(C); P:=INV(P); RETURN; 
(*4*) END IPLCPP; 


PROCEDURE IPPSC(RL,A,B: LIST): LIST; 
(*Integral polynomial principal subresultant coefficients.  A and B
are integral polynomials in r variables, r ge 1, of positive degree
in the main variable.  P is a list of the principal subresultant
coefficients of the second kind of A and B.*)
VAR  DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y,
     NL1, NL2, NL3, P, RLP, TL: LIST; 
BEGIN
(*1*) (*Initialize.*) NL1:=PDEG(A); NL2:=PDEG(B); 
      IF NL1 > NL2 THEN G1:=A; G2:=B; ELSE G1:=B; G2:=A; TL:=NL1; 
         NL1:=NL2; NL2:=TL; END; 
      DL0:=0; DL1:=NL1-NL2; RLP:=RL-1; IL:=1; P:=BETA; 
LOOP
(*2*) (*Compute g hat sub i+2.*) 
      IF G2 <> 0 THEN (*GO TO 3;*) 
         GH3:=IPPSR(RL,G1,G2); 
         IF GH3 <> 0 THEN (*GO TO 3;*) 
            IF MASEVEN(DL1) THEN GH3:=IPNEG(RL,GH3); END; 
            NL3:=PDEG(GH3); 
            END;
         END;
(*3*) (*Compute h sub i.*) 
      IF IL > 1 THEN GL1:=PLDCF(G1); HL1:=IPEXP(RLP,GL1,DL0); 
         IF IL > 2 THEN J1Y:=DL0-1; HLS0:=IPEXP(RLP,HL0,J1Y); 
            HL1:=IPQ(RLP,HL1,HLS0); P:=COMP(HL1,P); 
            IF G2 = 0 THEN RETURN(P); END; 
            END; 
         END; 
(*4*) (*Compute g sub i+2.*) 
      IF (IL = 1) OR (GH3 = 0) THEN G3:=GH3; ELSE
         HLS1:=IPEXP(RLP,HL1,DL1); HLS1:=IPPROD(RLP,GL1,HLS1); 
         HLS1:=LIST2(0,HLS1); G3:=IPQ(RL,GH3,HLS1); END; 
(*5*) (*Update.*) NL1:=NL2; NL2:=NL3; DL0:=DL1; DL1:=NL1-NL2; G1:=G2; 
      G2:=G3; 
      IF IL > 1 THEN HL0:=HL1; END; 
      IL:=IL+1; 
      END; (*GO TO 2;*) 
(*8*) RETURN(P); END IPPSC; 


PROCEDURE IPSFBA(RL,A,B: LIST): LIST; 
(*Integral polynomial squarefree basis augmentation.  A is a
primitive positive squarefree integral polynomial in r variables,
r ge 1, of positive degree in its main variable.
B eq (B sub 1 , ..., B sub s ), s ge 0, is a squarefree integral
polynomial basis in r variables.  BS is a coarsest squarefree
basis for (A,B sub 1 , ..., B sub s ).*)
VAR  ABP, AP, B1, BB1, BP, BS, C: LIST; 
BEGIN
(*1*) AP:=A; BP:=B; BS:=BETA; 
      WHILE (BP <> SIL) AND (PDEG(AP) > 0) DO ADV(BP, B1,BP); 
            IPGCDC(RL,AP,B1, C,ABP,BB1); 
            IF PDEG(C) > 0 THEN BS:=COMP(C,BS); END; 
            IF PDEG(BB1) > 0 THEN BS:=COMP(BB1,BS); END; 
            AP:=ABP; END; 
      IF PDEG(AP) > 0 THEN BS:=COMP(AP,BS); END; 
      WHILE BP <> SIL DO ADV(BP, B1,BP); BS:=COMP(B1,BS); END; 
      RETURN(BS); 
(*4*) END IPSFBA; 


PROCEDURE ISPSFB(RL,A: LIST): LIST; 
(*Integral squarefree polynomial squarefree basis.  A eq (A sub 1
, ..., A sub n ), n ge 0, is a list of positive primitive squarefree
integral polynomials in r variables,r ge 1, each of which is of
positive degree in its main variable.  B is a coarsest squarefree
basis for A.*)
VAR  A1, AP, B: LIST; 
BEGIN
(*1*) B:=BETA; AP:=A; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); B:=IPSFBA(RL,A1,B); END; 
      RETURN(B); 
(*4*) END ISPSFB; 


PROCEDURE IUPRC(A,B: LIST;  VAR C,R: LIST); 
(*Integral univariate polynomial resultant and cofactor.  A and B are
univariate integral polynomials of positive degree.  R is the
resultant of A and B.  C is a univariate integral polynomial such
that for some univariate integral polynomial D, AD+BC eq R.*)
VAR  AS, BS, CS, DL, EL, FL, I, J1Y, ML, NL, PL, Q, QL, RS:
     LIST; 
BEGIN
(*1*) (*Compute coefficient bound.*) DL:=IPMAXN(1,A); EL:=IPMAXN(1,B); 
      ML:=PDEG(A); NL:=PDEG(B); DL:=IEXP(DL,NL); EL:=IEXP(EL,ML); 
      J1Y:=ML+NL; FL:=IFACTL(J1Y); FL:=IPROD(EL,FL); FL:=IPROD(DL,FL); 
(*2*) (*Initialize.*) I:=PRIME; Q:=1; C:=0; R:=0; 
(*3*) (*Loop.*) 
      WHILE I <> SIL DO ADV(I, PL,I); AS:=MPHOM(1,PL,A); 
            IF PDEG(AS) = ML THEN BS:=MPHOM(1,PL,B); 
               IF PDEG(BS) = NL THEN MUPRC(PL,AS,BS, CS,RS); 
                  QL:=MDHOM(PL,Q); QL:=MDINV(PL,QL); 
                  C:=IPCRA(Q,PL,QL,1,C,CS); R:=IPCRA(Q,PL,QL,0,R,RS); 
                  Q:=IPROD(Q,PL); 
                  IF ICOMP(Q,FL) >= 0 THEN RETURN; END; 
                  END; 
               END; 
            END; 
(*4*) (*Algorithm fails.*) ERROR(fatal,"algorithm IUPRC fails");  
(*7*) RETURN; END IUPRC; 


PROCEDURE MUPRC(PL,A,B: LIST;  VAR C,RL: LIST); 
(*Modular univariate polynomial resultant and cofactor.  p is a
prime beta-digit.  A and B are univariate polynomials over
Z sub p of positive degree.  R is the resultant of A and B,
an element of Z sub p.  C is a univariate polynomial over
Z sub p such that for some univariate polynomial D over
Z sub p, AD+BC eq R.*)
VAR  A1, A2, A3, IL, J1Y, NL1, NL2, NL3, Q, RL2, SL, TL, VL1, VL2,
     VL3: LIST; 
BEGIN
(*1*) (*initialize.*) RL:=1; A1:=A; A2:=B; VL1:=0; VL2:=PMON(1,0); 
      NL1:=PDEG(A1); NL2:=PDEG(A2); SL:=0; 
      IF NL1 < NL2 THEN
         IF ODD(NL1) AND ODD(NL2) THEN SL:=1; END; 
         TL:=A1; A1:=A2; A2:=TL; VL1:=VL2; VL2:=0; END; 
(*2*) (*loop.*) 
      REPEAT MPQR(1,PL,A1,A2, Q,A3); J1Y:=MPPROD(1,PL,Q,VL2); 
             VL3:=MPDIF(1,PL,VL1,J1Y); 
             IF A3 = 0 THEN RL:=0; C:=VL3; RETURN; END; 
             NL1:=PDEG(A1); NL2:=PDEG(A2); NL3:=PDEG(A3); 
             IF MASODD(NL1) AND MASODD(NL2) THEN SL:=1-SL; END; 
             RL2:=PLDCF(A2); 
             FOR IL:=1 TO NL1-NL3 DO RL:=MDPROD(PL,RL,RL2); END; 
             A1:=A2; A2:=A3; VL1:=VL2; VL2:=VL3; 
             UNTIL NL3 = 0; 
(*3*) (*finish.*) RL2:=PLDCF(A2); 
      FOR IL:=1 TO NL2-1 DO RL:=MDPROD(PL,RL,RL2); END; 
      C:=MPMDP(1,PL,RL,VL2); RL:=MDPROD(PL,RL,RL2); 
      IF SL = 1 THEN RL:=PL-RL; END; 
      RETURN; 
(*6*) END MUPRC; 


END SACEXT5.
(* -EOF- *)
