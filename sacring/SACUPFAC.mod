(* ----------------------------------------------------------------------------
 * $Id: SACUPFAC.mi,v 1.3 1992/10/15 16:29:08 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACUPFAC.mi,v $
 * Revision 1.3  1992/10/15  16:29:08  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:35:07  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:17  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACUPFAC;

(* SAC Univariate Polynomial Factorization Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM MASERR IMPORT ERROR, fatal; 

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

FROM SACMUFAC IMPORT MCPMV, MIUPSE, MUPBQP, MUPDDF, MUPFBL, MUPFS;


VAR NPFDS: LIST;

CONST rcsidi = "$Id: SACUPFAC.mi,v 1.3 1992/10/15 16:29:08 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE BEGIN4(); 
(*Begin 4.  Begin4 calls Begin3, then initializes the global
variable NPFDS.*)
BEGIN
(*1*) (*begin3;*) NPFDS:=10; RETURN; 
(*4*) END BEGIN4; 


PROCEDURE IPFLC(RL,M,I,A,L,D: LIST): LIST; 
(*Integral polynomial factor list combine.  A is a non-constant
primitive r-variate integral polynomial.  M is a positive integer.
I is a list (d sub 1, ...,d sub r - 1) of non-negative beta-digits.
L is a list of monic factors of A modulo M, ((x sub 1)**(d sub 1), ...
,(x sub rl- 1)**(d sub r - 1)) such that if B is an integral factor
of A, then H sub M,I (B) is an associate of some product of elements
of L.  D is either 0, or a characteristic set for the possible degrees
of integral factors of A.  LP is a list of the primitive irreducible
integral factors of A. *)
VAR  ALS, AS, BS, C, CL, CLB, CLS, CS, DL, DLS, IL, 
     J1Y, KL, LB, LP, LS, P, PL, RLP, RS, S, SL, SS, XL: LIST; 
BEGIN
(*1*) (*initialize.*) DL:=1; C:=A; KL:=LENGTH(L); P:=PERMR(KL); 
      LB:=LPERM(L,P); LP:=BETA; RLP:=RL-1; 
LOOP
(*2*) (*prepare polynomial.*) CL:=PLDCF(C); CLS:=PTBCF(RLP,CL); 
      CL:=LIST2(0,CL); CS:=IPPROD(RL,CL,C); CLB:=PTBCF(RL,CS); 
      CLS:=MIHOM(M,CLS); 

LOOP
(*3*) (*done.*) 
      IF DL > KL DIV 2 THEN LP:=COMP(C,LP); RETURN(LP); END; 
      LS:=LB; S:=BETA; 
      FOR IL:=1 TO DL DO S:=COMP(LS,S); LS:=RED(LS); END; 

REPEAT
(*4*) (*see if s is a factor.*) SS:=S; ALS:=CLS; DLS:=0; 
      WHILE SS <> SIL DO ADV(SS, SL,SS); PL:=FIRST(SL); 
            J1Y:=PDEG(PL); DLS:=DLS+J1Y; J1Y:=PTBCF(RL,PL); 
            ALS:=MIPROD(M,ALS,J1Y); END; 
      ALS:=SMFMI(M,ALS); 
      IF NOT ((ALS = 0) AND (CLB <> 0)) THEN (*go to 5;*) 
         IF ((D = 0) OR (IODD(IDP2(D,DLS)) (*= 1*) )) 
                    AND ((CLB = 0) OR (IREM(CLB,ALS) = 0)) 
            THEN SS:=S; AS:=CL; 
            WHILE SS <> SIL DO ADV(SS, SL,SS); PL:=FIRST(SL); 
                  AS:=MIPIPR(RL,M,I,AS,PL); END; 
            AS:=SMFMIP(RL,M,AS); IPQR(RL,CS,AS, BS,RS); 
            IF RS = 0 THEN (*go to 6;*) EXIT END; 
            END; 
         END; (*goto*)
(*5*) (*advance to next set.*) S:=LEXNEX(S); 
      UNTIL S = SIL; (*then go to 4; end;*) 
      DL:=DL+1; 
      END; (*go to 3;*) 

(*6*) (*remove a factor.*) AS:=IPPP(RL,AS); LP:=COMP(AS,LP); 
      J1Y:=PLDCF(AS); J1Y:=LIST2(0,J1Y); C:=IPQ(RL,BS,J1Y); KL:=KL-DL; 
      REPEAT ADV(S, SL,S); 
             IF SL = LB THEN LB:=RED(LB); ELSE XL:=RED(SL); 
                LB:=INV(LB); SL:=RED(SL); LB:=INV(LB); SRED(SL,XL); END; 
             UNTIL S = SIL; 
      END; (*go to 2;*) 
(*9*) RETURN(LP); END IPFLC; 


PROCEDURE IUPFAC(A: LIST;  VAR SL,CL,L: LIST); 
(*Integral univariate polynomial factorization.  A is a non-zero
integral univariate polynomial.  s=sign(A), c=cont(A).  L is
a list ((e1,A1), ...,(ek,Ak)), k ge 0, where each ei is a
positive integer, e1 le e2 le  ... le ek, each A i is an ir-
reducible positive integral univariate polynomial, and A = s * c *
the product of A i ** ei, 1 le i le k.*)
VAR  A1, AB, EL1, J1Y, L1, P, S: LIST; 
BEGIN
(*1*) (*compute sign, content and primitive part.*) 
      IPSCPP(1,A,SL,CL,AB); 
(*2*) (*degree zero.*) 
      IF PDEG(A) = 0 THEN L:=BETA; RETURN; END; 
(*3*) (*compute squarefree factorization.*) S:=IPSF(1,AB); 
(*4*) (*factor squarefree factors*) S:=INV(S); L:=BETA; 
      REPEAT ADV(S, P,S); FIRST2(P, EL1,A1); L1:=IUSFPF(A1); 
             REPEAT ADV(L1, A1,L1); J1Y:=LIST2(EL1,A1); L:=COMP(J1Y,L); 
                    UNTIL L1 = SIL; 
             UNTIL S = SIL; 
      RETURN; 
(*7*) END IUPFAC; 


PROCEDURE IUPFDS(A: LIST;  VAR PL,F,C: LIST); 
(*Integral univariate polynomial factor degree set.  A is a non-zero
square-free integral polynomial.  C is the intersection of
the degree sets of factorizations over Z sub p for as many as NPFDS
primes p (fewer only if SMPRM is exhausted or A is proved irredu-
cible). C is represented as a characteristic set.  p is
the least examined prime in P which gave the smallest number of
factors, and F is the distinct degree factorization of A over Z sub p,
unless A is shown to be irreducible, in which case p=0, F=().*)
VAR  AL, B, BL, BP, CL, D, FL, G, H, HL, I, IL, J, J1Y,
     JL, KL, L, NL, P, RL, SL: LIST; 
BEGIN
(*1*) (*initialize.*) PL:=0; P:=SMPRM; NL:=PDEG(A); 
      AL:=PLDCF(A); IL:=0; J:=LIST2(0,1); J1Y:=IMP2(1,NL); 
      I:=CSUN(J1Y,1); NL:=NL+1; J1Y:=IMP2(1,NL); C:=IDIF(J1Y,1); 
(*2*) (*try primes.*) 
      WHILE (EQUAL(C,I) = 0) AND (IL < NPFDS) DO
            IF P = SIL THEN
               IF PL <> 0 THEN RETURN; END; 
               ERROR(fatal,"prime list exhausted in IUPFDS."); 
               RETURN; END; 
            ADV(P, RL,P); 
            IF IDREM(AL,RL) <> 0 THEN B:=MPHOM(1,RL,A); 
               BP:=MUPDER(RL,B); 
               IF EQUAL(MUPGCD(RL,B,BP),J) = 1 THEN
                  BP:=MPMON(1,RL,B); G:=MUPDDF(RL,BP); H:=G; L:=BETA; 
                  KL:=0; 
                  REPEAT ADV(H, HL,H); FIRST2(HL, FL,BL); CL:=PDEG(BL); 
                         JL:=CL DIV FL; KL:=KL+JL; 
                         FOR SL:=1 TO JL DO L:=COMP(FL,L); END; 
                         UNTIL H = SIL; 
                  IF KL < NL THEN PL:=RL; NL:=KL; F:=G; END; 
                  D:=CSFPAR(L); C:=CSINT(C,D); IL:=IL+1; END; 
               END; 
            END; 
(*3*) (*clean up.*) 
      IF EQUAL(C,I) = 1 THEN PL:=0; F:=BETA; END; 
      RETURN; 
(*6*) END IUPFDS; 


PROCEDURE IUPQH(PL,AB,BB,SB,TB,M,C: LIST;  VAR A,B: LIST); 
(*Integral univariate polynomial quadratic Hensel lemma.  AB, BB, SB, TB
are univariate polynomials over Z sub p, p a prime beta-integer, with
AB*SB+BB*TB=1, and deg(TB) lt deg(AB).  C is a univariate integral
polynomial with H sub p of C=AB*BB.  M, a positive integer, is equal
to p**j for some positive integer j.  A and B are univariate
polynomials over Z sub M, with H sub p of A=AB, H sub p of B=BB,
ldcf(A)=ldcf(AB),deg(A)=deg(AB), and H sub M of C=A*B.*)
VAR  AS, AT, BS, BT, CL, I, QL, QLS, QLT, R, RP, S, SS, ST, T, TS, TT,
     U, U1, Y, Y1, Z, Z1: LIST; 
BEGIN
(*1*) (*initialize.*) QL:=PL; A:=AB; B:=BB; S:=SB; T:=TB; 
      I:=LIST2(0,1); 
      IF QL = M THEN RETURN; END; 
LOOP
(*2*) (*compute y,z.*) R:=IPPROD(1,A,B); R:=IPDIF(1,C,R); 
      U:=IPIQ(1,R,QL); QLS:=IPROD(QL,QL); CL:=ICOMP(QLS,M); 
      IF CL > 0 THEN QLT:=IQ(M,QL); AT:=MIPHOM(1,QLT,A); 
         BT:=MIPHOM(1,QLT,B); ST:=MIPHOM(1,QLT,S); TT:=MIPHOM(1,QLT,T); 
         ELSE QLT:=QL; AT:=A; BT:=B; ST:=S; TT:=T; END; 
      MIUPSE(QLT,AT,BT,ST,TT,U, Y,Z); 
(*3*) (*compute as,bs and check for end.*) R:=IPIP(1,QL,Z); 
      AS:=IPSUM(1,A,R); R:=IPIP(1,QL,Y); BS:=IPSUM(1,B,R); 
      IF CL >= 0 THEN A:=AS; B:=BS; RETURN; END; 
(*4*) (*compute y1,z1.*) R:=IPPROD(1,AS,S); RP:=IPPROD(1,BS,T); 
      R:=IPSUM(1,R,RP); R:=IPDIF(1,R,I); U1:=IPIQ(1,R,QL); 
      MIUPSE(QL,A,B,S,T,U1, Y1,Z1); 
(*5*) (*compute ss,ts.*) R:=IPIP(1,QL,Y1); SS:=MIPDIF(1,QLS,S,R); 
      R:=IPIP(1,QL,Z1); TS:=MIPDIF(1,QLS,T,R); 
(*6*) (*advance.*) QL:=QLS; A:=AS; B:=BS; S:=SS; T:=TS; 
      END; (*go to 2;*) 
(*9*) RETURN; END IUPQH; 


PROCEDURE IUPQHL(PL,F,M,C: LIST): LIST; 
(*Integral univariate polynomial quadratic Hensel lemma, list.  C is an
integral univariate polynomial.  F is a list (f sub 1, ...,f sub r)
of monic polynomials in Z sub p (x) with H sub p of C similar to the
product of the f sub i, and gcd(f sub i,f sub j)=1 for 1 le i
lt j le r, p a beta-prime not dividing ldcf(C).  M is a positive
power of p.  FP is a list (fp sub 1, ...,fp sub r) of monic
polynomials in Z sub M (x) with H sub M of C similar to the product of
the fp sub i, H sub p of fp sub i=f sub i and deg(fp sub
i)=deg(f sub i), for 1 le i le r.*)
VAR  A, AB, B, BB, CB, CP, FP, FS, Q, R, SB, TB:
     LIST; 
BEGIN
(*1*) (*initialize.*) FP:=BETA; FS:=F; CP:=MIPHOM(1,M,C); B:=CP; 
(*2*) (*lift factors.*) 
      WHILE RED(FS) <> SIL DO ADV(FS, AB,FS); CB:=MIPHOM(1,PL,CP); 
            BB:=MPQ(1,PL,CB,AB); MUPEGC(PL,AB,BB, R,SB,TB); 
            IUPQH(PL,AB,BB,SB,TB,M,CP, A,B); FP:=COMP(A,FP); 
            IF RED(FS) <> SIL THEN MIUPQR(M,CP,A, CP,R); END; 
            END; 
      MIUPQR(M,B,LIST2(0,PLDCF(B)), Q,R); FP:=COMP(Q,FP); FP:=INV(FP); 
      RETURN(FP); 
(*5*) END IUPQHL; 


PROCEDURE IUSFPF(A: LIST): LIST; 
(*Integral univariate squarefree polynomial factorization.  A is
an integral univariate squarefree polynomial which is positive,
primitive and of positive degree.  L is a list (A1, ...,Ak) of the
positive irreducible factors of A.*)
VAR  A1, AL, BL, C, F, G, G1, GS, HL, L, M, ML1, NL, NL1, P,
     PL: LIST; 
BEGIN
(*1*) (*compute distinct degree factorization f for suitable prime
            pl, and a factor degree set c.*) IUPFDS(A, PL,F,C); 
      IF PL = 0 THEN L:=LIST1(A); RETURN(L); END; 
(*2*) (*factor distinct degree factors.*) G:=BETA; 
      REPEAT ADV(F, P,F); FIRST2(P, NL1,A1); ML1:=PDEG(A1); 
             IF NL1 = ML1 THEN G:=COMP(A1,G); ELSE
                G1:=MUPFBL(PL,A1); G:=CONC(G1,G); END; 
             UNTIL F = SIL; 
(*3*) (*compute coefficient bound.*) AL:=PLDCF(A); HL:=IPSUMN(1,A); 
      NL:=PDEG(A); BL:=IPROD(AL,HL); BL:=IMP2(BL,NL); M:=PL; 
      WHILE ICOMP(M,BL) <= 0 DO M:=IDPR(M,PL); END; 
(*4*) (*apply Hensel construction.*) GS:=IUPQHL(PL,G,M,A); 
(*5*) (*combine lifted factors.*) L:=IPFLC(1,M,BETA,A,GS,C); RETURN(L); 
(*8*) END IUSFPF; 


BEGIN

BEGIN4;

END SACUPFAC.
(* -EOF- *)
