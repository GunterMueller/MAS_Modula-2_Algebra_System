(* ----------------------------------------------------------------------------
 * $Id: SACMUFAC.mi,v 1.3 1992/10/15 16:29:02 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACMUFAC.mi,v $
 * Revision 1.3  1992/10/15  16:29:02  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:58  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:09  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACMUFAC;

(* SAC Modular Univariate Polynomial Factorization Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM MASBIOS IMPORT SWRITE;

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    EQUAL, RED2, SECOND, LIST2;

FROM SACI IMPORT IODD, IREM, IDP2, ICOMP, IPROD, IQ, 
                 IDREM, IDPR, IDIF, IMP2, INEG;

FROM SACM IMPORT MDDIF, MIHOM, MIPROD, SMFMI;

FROM SACPRIM IMPORT SMPRM;

FROM SACCOMB IMPORT CSFPAR, CSINT, CSUN, LEXNEX, LPERM, PERMR;

FROM SACPOL IMPORT PRIME, PFDP, PDPV, PDEG, PLDCF, PTBCF, PDEGV, PINV;

FROM SACIPOL IMPORT IPSIGN, IPABS, IPDMV, IPEMV, 
                    IPSUM, IPDIF, IPIP, IPIQ, IPTRAN, 
                    IUPTPR, IPSUMN, IPQR, IPPROD, IPQ, IPEVAL;

FROM SACMPOL IMPORT VMPIP, MIPPR, MPQ, MPHOM, MPMON, MUPDER,
                    MPSUM, MPDIF, MIUPQR, SMFMIP, MIPDIF, 
                    MIPHOM, MIPIPR, MIPSUM;

FROM SACDPOL IMPORT DPFP, DMPPRD, DMUPNR;

FROM SACPGCD IMPORT IPSF, IPSCPP, IPPP, IPCPP, IPGCDC, 
                    MUPEGC, MUPGCD;

FROM SACLDIO IMPORT MMDNSB;

CONST rcsidi = "$Id: SACMUFAC.mi,v 1.3 1992/10/15 16:29:02 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE MCPMV(NL,L: LIST): LIST; 
(*Matrix of coefficients of polynomials, with respect to main variable.
L is a list (L(1), ...,L(k)) of k, ge 1, non-zero polynomials with
degrees less than n.  n is a positive beta-integer.  M is the matrix
with m(1,il)+m(2,i)*x+ ...+m(n,i)*x**(n-1)=L(i) for 1 le i le
k.*)
VAR  IL, KL, LP, LP1, LS, M, MP, MS: LIST; 
BEGIN
(*1*) LP:=L; MP:=BETA; 
      REPEAT ADV(LP, LS,LP); LP1:=DPFP(1,LS); ADV(LP1, KL,LP1); 
             FOR IL:=1 TO NL-KL-1 DO LP1:=COMP(0,LP1); END; 
             MP:=COMP(LP1,MP); 
             UNTIL LP = SIL; 
      M:=BETA; 
      REPEAT MS:=MP; LP:=BETA; 
             REPEAT LS:=FIRST(MS); SFIRST(MS,RED(LS)); SRED(LS,LP); 
                    LP:=LS; MS:=RED(MS); 
                    UNTIL MS = SIL; 
             M:=COMP(LP,M); 
             UNTIL FIRST(MP) = SIL; 
      RETURN(M); 
(*4*) END MCPMV; 


PROCEDURE MIUPSE(M,A,B,S,T,C: LIST;  VAR U,V: LIST); 
(*Modular integral univariate polynomial, solution of equation.  M is a
positive integer.  A,B,S,T and C belong to Z sub M (x) with ldcf(A) a
unit, deg(T) lt deg(A) and A*S+B*T=1.  U and V are the unique elements
of Z sub M (x) such that A*U+B*V=C, with deg(V) lt deg(A).*)
VAR  HL, J, J1Y, K, KL, L, ML, NL, Q, Y: LIST; 
BEGIN
(*1*) NL:=PDEG(C); HL:=PDEG(A); KL:=PDEG(B); J1Y:=NL-HL; J1Y:=J1Y+1; 
      ML:=MASMAX(J1Y,KL); Y:=MIPPR(1,M,T,C); MIUPQR(M,Y,A, Q,V); 
      J:=IUPTPR(ML,S,C); K:=IUPTPR(ML,B,Q); L:=IPSUM(1,J,K); 
      U:=MIPHOM(1,M,L); RETURN; 
(*4*) END MIUPSE; 


PROCEDURE MUPBQP(PL,A: LIST): LIST; 
(*Modular univariate polynomial Berlekamp q polynomials construction.
p is a prime beta-integer.  A is a univariate polynomial over Z sub p
with deg(A) ge 2.  Q is the list (Q(0), ...,Q(n-1)), where Q(i)(x)=
rem(x**(p*i),A(x)) and n=deg(A).*)
VAR  AP, B, C, IL, J1Y, KL, ML, NL, Q, X: LIST; 
BEGIN
(*1*) (*initialize.*) KL:=2; 
      WHILE KL <= PL DO KL:=KL+KL; END; 
      KL:=KL DIV 2; NL:=FIRST(A); AP:=DPFP(1,A); C:=LIST2(0,1); 
      Q:=LIST1(C); 
(*2*) (*compute q1.*) X:=LIST3(1,1,0); B:=X; ML:=PL-KL; 
      REPEAT B:=DMPPRD(1,PL,B,B); 
             IF FIRST(B) >= NL THEN B:=DMUPNR(PL,B,AP); END; 
             KL:=KL DIV 2; 
             IF ML >= KL THEN B:=DMPPRD(1,PL,X,B); 
                IF FIRST(B) >= NL THEN B:=DMUPNR(PL,B,AP); END; 
                ML:=ML-KL; END; 
             UNTIL KL = 1; 
      J1Y:=PFDP(1,B); Q:=COMP(J1Y,Q); 
(*3*) (*compute q(il).*) C:=B; 
      FOR IL:=2 TO NL-1 DO C:=DMPPRD(1,PL,B,C); 
          IF FIRST(C) >= NL THEN C:=DMUPNR(PL,C,AP); END; 
          J1Y:=PFDP(1,C); Q:=COMP(J1Y,Q); END; 
      Q:=INV(Q); RETURN(Q); 
(*6*) END MUPBQP; 


PROCEDURE MUPDDF(PL,A: LIST): LIST; 
(*Modular univariate polynomial distinct degree factorization.  p is
a prime beta-integer.  A is a monic squarefree univariate polynomial
over Z sub p, with deg(A) ge 2.  L is a list ((n(1),A(1)), ...
,(n(k),A(k))) where each n(i) is a positive integer, n(1) lt
n(2) lt ...lt n(k), and A(i) is the product of all irreducible monic
factors of A  of degree n(i).*)
VAR  B, BL, BP, C, D, EL, IL, J1Y, KL, L, L1, NL, Q, Q1, QP, W, X:
     LIST; 
BEGIN
(*1*) (*initialize.*) Q:=MUPBQP(PL,A); J1Y:=RED(Q); B:=FIRST(J1Y); 
      C:=A; L:=BETA; KL:=1; X:=LIST2(1,1); NL:=FIRST(A); 
(*2*) (*compute a(kl).*) 
      LOOP   W:=MPDIF(1,PL,B,X); D:=MUPGCD(PL,W,C); 
             IF FIRST(D) > 0 THEN L1:=LIST2(KL,D); L:=COMP(L1,L); 
                C:=MPQ(1,PL,C,D); END; 
             KL:=KL+1; EL:=FIRST(C); 
             IF EL >= 2*KL THEN
                IF KL = 2 THEN Q:=MCPMV(NL,Q); END; 
                B:=DPFP(1,B); ADV(B, EL,B); 
                FOR IL:=1 TO NL-EL-1 DO B:=COMP(0,B); END; 
                BP:=INV(B); B:=BETA; QP:=Q; 
                REPEAT ADV(QP, Q1,QP); BL:=VMPIP(0,PL,BP,Q1); 
                       B:=COMP(BL,B); 
                       UNTIL QP = SIL; 
                EL:=NL-1; 
                WHILE FIRST(B) = 0 DO EL:=EL-1; B:=RED(B); END; 
                B:=COMP(EL,B); B:=PFDP(1,B); ELSE
                IF EL > 0 THEN L1:=LIST2(EL,C); L:=COMP(L1,L); END; 
                L:=INV(L); RETURN(L); END; 
             END; (*until sil*) 
(*5*) RETURN(L); END MUPDDF; 


PROCEDURE MUPFBL(PL,A: LIST): LIST; 
(*Modular univariate polynomial factorization-Berlekamp algorithm.
p is a prime beta-integer.  A is a monic squarefree univariate poly-
nomial, with deg(A) ge 2.  L is a list of all the monic irreducible
factors of A of positive degree.*)
VAR  AL, B, B1, BS, IL, JL, L, NL, Q, Q1, QP: LIST; 
BEGIN
(*1*) (*construct the matrix q-i.*) NL:=FIRST(A); Q:=MUPBQP(PL,A); 
      Q:=MCPMV(NL,Q); QP:=Q; 
      FOR IL:=0 TO NL-1 DO Q1:=FIRST(QP); 
          FOR JL:=1 TO IL DO Q1:=RED(Q1); END; 
          AL:=FIRST(Q1); AL:=MDDIF(PL,AL,1); SFIRST(Q1,AL); QP:=RED(QP); 
          END; 
(*2*) (*generate null space basis and convert to polynomials.*) 
      BS:=MMDNSB(PL,Q); B:=BETA; 
      REPEAT ADV(BS, B1,BS); B1:=INV(B1); IL:=NL-1; 
             WHILE FIRST(B1) = 0 DO IL:=IL-1; B1:=RED(B1); END; 
             B1:=COMP(IL,B1); B1:=PFDP(1,B1); B:=COMP(B1,B); 
             UNTIL BS = SIL; 
(*3*) (*factorize.*) L:=MUPFS(PL,A,B,1); RETURN(L); 
(*6*) END MUPFBL; 


PROCEDURE MUPFS(PL,A,B,DL: LIST): LIST; 
(*Modular univariate polynomial factorization, special.  p is a prime
beta-integer. A is a monic squarefree polynomial in Z sub p(x),deg(A)
ge 2.  B is a list (B(1), ...,B(r)) of monic univariate polynomials
over Z sub p, which constitute a basis for the space of all polynomials
C of degree less than deg(A) such that A is a divisor of C**p-C.
Further-more, B(1)=1.  d is a positive beta-integer such that A has
no irreducible factor of degree less than d.  L is a list
consisting of all the monic irreducible factors of A of positive
degree.*)
VAR  A1, B1, BP, C, CL, EL, FL, IL, KL, L, LP, RL, SL: LIST; 
BEGIN
(*1*) (*a irreducible.*) L:=LIST1(A); RL:=LENGTH(B); 
      IF RL = 1 THEN RETURN(L); END; 
(*2*) (*factorize.*) BP:=RED(B); KL:=1; CL:=LIST2(0,1); 
      LOOP   LP:=BETA; ADV(BP, B1,BP); 
             REPEAT ADV(L, A1,L); EL:=FIRST(A1); 
                    IF EL > DL THEN SL:=0; IL:=0; 
                       REPEAT C:=MUPGCD(PL,A1,B1); FL:=FIRST(C); 
                              IF FL > 0 THEN
                                 IF FL = EL THEN SL:=1; ELSE
                                    LP:=COMP(C,LP); A1:=MPQ(1,PL,A1,C); 
                                    KL:=KL+1; 
                                    IF KL = RL THEN
                                       LP:=COMP(A1,LP); L:=CONC(LP,L); 
                                       RETURN(L); END; 
                                    EL:=FIRST(A1); 
                                    IF EL = DL THEN SL:=1; END; 
                                    END; 
                                 END; 
                              B1:=MPSUM(1,PL,CL,B1); IL:=IL+1; 
                              UNTIL (IL = PL) OR (SL = 1); 
                       END; 
                    LP:=COMP(A1,LP); 
                    UNTIL L = SIL; 
             L:=LP; 
             END; (*until sil;*) 
(*5*) RETURN(L); END MUPFS; 


END SACMUFAC.

(* -EOF- *)
