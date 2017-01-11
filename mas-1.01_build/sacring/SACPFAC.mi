(* ----------------------------------------------------------------------------
 * $Id: SACPFAC.mi,v 1.3 1992/10/15 16:29:03 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPFAC.mi,v $
 * Revision 1.3  1992/10/15  16:29:03  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:35:00  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:16:11  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACPFAC;

(* SAC Polynomial Factorization Implementation Module. *)



(* import lists and declarations. *)

FROM MASELEM IMPORT MASMAX;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM MASBIOS IMPORT SWRITE;

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    EQUAL, RED2, SECOND, LIST2;

FROM SACI IMPORT IODD, IREM, IDP2, ICOMP, IPROD, IQ, 
                 IDREM, IDPR, IDIF, IMP2, INEG;

FROM SACM IMPORT MIHOM, MIPROD, SMFMI;

FROM SACPRIM IMPORT SMPRM;

FROM SACCOMB IMPORT CSFPAR, CSINT, CSUN, LEXNEX, LPERM, PERMR;

FROM SACPOL IMPORT PUFP, PRIME, PDPV, PDEG, PLDCF, PTBCF, PDEGV, PINV;

FROM SACIPOL IMPORT IPIHOM, IPSIGN, IPABS, IPDMV, IPEMV, 
                    IPSUM, IPDIF, IPIP, IPIQ, IPTRAN, 
                    IUPTPR, IPSUMN, IPQR, IPPROD, IPQ, IPEVAL;

FROM SACMPOL IMPORT VMPIP, MIPPR, MPQ, MPHOM, MPMON, MUPDER,
                    MMPIQR, SMFMIP, MIPDIF, MIPHOM, MIPIPR, MIPSUM;

FROM SACDPOL IMPORT DPFP, DMPPRD, DMUPNR;

FROM SACPGCD IMPORT MUPEGC, IPSF, IPPP, IPCPP, IPGCDC, MUPGCD;

FROM SACUPFAC IMPORT IPFLC, IUSFPF, IUPFAC;

CONST rcsidi = "$Id: SACPFAC.mi,v 1.3 1992/10/15 16:29:03 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IPCEVP(RL,A: LIST;  VAR B,L: LIST); 
(*Integral polynomial, choice of evaluation points.  A is an r-variate
integral polynomial, square-free in its main variable x, r ge 1.  L is
a list (l sub 1, ...,l sub r-1) of beta-integers, with L as small as
possible in reverse lexicographic order with 0 lt 1 lt -1 lt 2 lt -2 lt
 ... such that deg sub x of A(x1, ...,x sub r-1,x)=deg sub x of A(l sub
1, ...,l sub r-1,x), and A(l sub 1, ...,l sub r-1,x) is the square-
free univariate integral polynomial B.*)
VAR  AB, AL, ALT, AT, C, CP, D, E, EL, F, J1Y, LL, RLP: LIST; 
     fin: BOOLEAN;
BEGIN
(*1*) (*initialize.*) RLP:=RL-1; AT:=A; L:=BETA; 
LOOP
(*2*) (*univariate.*) 
      IF RLP = 0 THEN B:=AT; RETURN; END; 
(*3*) (*prepare to choose ll sub rlp.*) LL:=0; ADV2(AT, EL,ALT,AB); 
REPEAT fin:=TRUE;
(*4*) (*evaluate alt and at for x sub rlp=ll.*) AL:=IPEMV(RLP,ALT,LL); 
      IF AL = 0 THEN 
         IF LL > 0 THEN LL:=-LL; ELSE LL:=1-LL; END; 
         fin:=FALSE; (*go to 6; *) 
         ELSE
         IF AB <> SIL THEN J1Y:=RLP+1; C:=IPEVAL(J1Y,AB,RLP,LL); ELSE
            C:=0; END; 
         IF C = 0 THEN C:=BETA; END; 
         C:=COMP2(EL,AL,C); CP:=IPDMV(RLP,C); IPGCDC(RLP,C,CP, D,E,F); 
         IF PDEG(D) > 0 THEN (*go to 6;*) fin:=FALSE;
            IF LL > 0 THEN LL:=-LL; ELSE LL:=1-LL; END; 
            END; 
         END;
      UNTIL fin;
(*5*) (*success.*) L:=COMP(LL,L); RLP:=RLP-1; AT:=C; 
      END; (*go to 2;*) 
(*6*) (*try again. 
      if ll > 0 then ll:=-ll; else ll:=1-ll; end; 
      go to 4; *)
(*9*) RETURN; END IPCEVP; 


PROCEDURE IPFAC(RL,A: LIST;  VAR SL,CL,L: LIST); 
(*Integral polynomial factorization.  A is a non-zero integral
polynomial in r variables, r ge 1.  s=sign(A).  c is the integer
content of A.  L is a list ((e1,A1), ...,(ek,Ak)), k ge 0, where
each ei is a positive integer, the Aips are the distinct positive
irreducible integral factors of A, and A=s*c*(the product from i
equal 1 to k of Ai**ei).*)
VAR  A1, A1S, AB, AS, CLS, EL1, J1Y, L1, LB, LS, P, RLP, SLS:
     LIST; 
BEGIN
(*1*) (*rl=1.*) 
      IF RL = 1 THEN IUPFAC(A, SL,CL,L); RETURN; END; 
(*2*) (*compute sign, absolute value, content and primitive part.*) 
      SL:=IPSIGN(RL,A); AS:=IPABS(RL,A); IPCPP(RL,AS, CLS,AB); 
(*3*) (*factor content.*) RLP:=RL-1; IPFAC(RLP,CLS, SLS,CL,LS); 
(*4*) (*compute squarefree factorization of primitive part.*) 
      IF PDEG(AB) = 0 THEN LB:=BETA; ELSE LB:=IPSF(RL,AB); END; 
(*5*) (*factor squarefree factors and combine.*) LB:=INV(LB); L:=BETA; 
      WHILE LB <> SIL DO ADV(LB, P,LB); FIRST2(P, EL1,A1); 
            L1:=ISFPF(RL,A1); 
            REPEAT ADV(L1, A1,L1); J1Y:=LIST2(EL1,A1); L:=COMP(J1Y,L); 
                   UNTIL L1 = SIL; 
            END; 
(*6*) (*adjoin factors of content.*) LS:=INV(LS); 
      WHILE LS <> SIL DO ADV(LS, P,LS); FIRST2(P, EL1,A1S); 
            A1:=LIST2(0,A1S); J1Y:=LIST2(EL1,A1); L:=COMP(J1Y,L); END; 
      RETURN; 
(*9*) END IPFAC; 


PROCEDURE IPGFCB(RL,A: LIST): LIST; 
(*Integral polynomial Gelfond factor coefficient bound.  A is an
integral polynomial in r variables, r gt 0.  a=2**h*(the degree of
A in xr) where h=the least integer greater than the sum from i=1 to
r of the maximum of 0 and ((2*the i-th partial derivative of A)-1)/2.
a is an integer.*)
VAR  AL, HL, J1Y, NL, V: LIST; 
BEGIN
(*1*) AL:=IPSUMN(RL,A); V:=PDEGV(RL,A); HL:=0; 
      REPEAT ADV(V, NL,V); J1Y:=2*NL; J1Y:=J1Y-1; J1Y:=MASMAX(0,J1Y); 
             HL:=HL+J1Y; 
             UNTIL V = SIL; 
      J1Y:=HL+1; HL:=J1Y DIV 2; AL:=IMP2(AL,HL); RETURN(AL); 
(*4*) END IPGFCB; 


PROCEDURE IPIQH(RL,PL,D,AB,BB,SB,TB,M,C: LIST;  VAR A,B: LIST); 
(*Integral polynomial mod ideal quadratic Hensel lemma.  D is a list of
non-negative beta-integers (d sub 1, ...,d sub r-1), r ge 1.  AB, BB,
SB and TB belong to Z sub p (x sub 1, ...,x sub r-1,y)/(x sub 1 ** d
sub 1, ...,x sub r-1 ** d sub r-1), with AB monic, AB*SB+BB*TB=1,
deg sub y of AB gt 0 and p a prime beta-integer.  C is an r-variate
integral polynomial with AB*BB congruent to C.  M, a positive integer,
is equal to p**j for some positive integer j.  A, B belong to Z sub M
(x sub 1, ...,x sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d
sub r-1), with A monic, A congruent to AB, B congruent to BB, deg sub y
of A=deg sub y of AB, and A*B congruent to C.*)
VAR  AS, AT, BS, BT, CL, I, QL, QLS, QLT, R, RP, S, SS, ST, T, TS, TT,
     U, U1, UT, Y, Y1, Z, Z1: LIST; 
BEGIN
(*1*) (*initialize.*) QL:=PL; A:=AB; B:=BB; S:=SB; T:=TB; 
      I:=PINV(0,1,RL); 
      IF QL = M THEN RETURN; END; 
LOOP
(*2*) (*compute y,z.*) R:=MIPIPR(RL,M,D,A,B); R:=IPDIF(RL,C,R); 
      U:=IPIQ(RL,R,QL); QLS:=IPROD(QL,QL); CL:=ICOMP(QLS,M); 
      IF CL > 0 THEN QLT:=IQ(M,QL); AT:=MIPHOM(RL,QLT,A); 
         BT:=MIPHOM(RL,QLT,B); ST:=MIPHOM(RL,QLT,S); 
         TT:=MIPHOM(RL,QLT,T); ELSE QLT:=QL; AT:=A; BT:=B; ST:=S; TT:=T; 
         END; 
      UT:=MIPHOM(RL,QLT,U); MIPISE(RL,QLT,D,AT,BT,ST,TT,UT, Y,Z); 
(*3*) (*compute as,bs and check for end.*) R:=IPIP(RL,QL,Z); 
      AS:=IPSUM(RL,A,R); R:=IPIP(RL,QL,Y); BS:=IPSUM(RL,B,R); 
      IF CL >= 0 THEN A:=AS; B:=BS; RETURN; END; 
(*4*) (*compute y1,z1.*) R:=MIPIPR(RL,QLS,D,AS,S); 
      RP:=MIPIPR(RL,QLS,D,BS,T); R:=MIPSUM(RL,QLS,R,RP); 
      R:=MIPDIF(RL,QLS,R,I); U1:=IPIQ(RL,R,QL); 
      MIPISE(RL,QL,D,A,B,S,T,U1, Y1,Z1); 
(*5*) (*compute ss,ts.*) R:=IPIP(RL,QL,Y1); SS:=MIPDIF(RL,QLS,S,R); 
      R:=IPIP(RL,QL,Z1); TS:=MIPDIF(RL,QLS,T,R); 
(*6*) (*advance.*) QL:=QLS; A:=AS; B:=BS; S:=SS; T:=TS; 
      END; (*go to 2;*) 
(*9*) RETURN; END IPIQH; 


PROCEDURE ISFPF(RL,A: LIST): LIST; 
(*Integral squarefree polynomial factorization.  A is a positive
integral polynomial in r variables, r ge 1, which with respect to its
main variable is of positive degree, primitive, and squarefree.  L is a
list (A1, ...,Ak) of the distinct positive irreducible factors of A.*)
VAR  A1P, A1S, ABP, ALP, AP, AS, B, BL, BP, C, D, DL, J1Y, KL,
     L, LP, LS, M, ML, NL, P, PL, T, TL, TP, V, VL: LIST; 
BEGIN
(*1*) (*rl=1.*) 
      IF RL = 1 THEN L:=IUSFPF(A); RETURN(L); END; 
(*2*) (*evaluate to univariate polynomial, as, and factor as.*) 
      IPCEVP(RL,A, AS,T); AS:=IPABS(1,AS); AS:=IPPP(1,AS); 
      LS:=IUSFPF(AS); 
(*3*) (*as irreducible.*) 
      IF RED(LS) = SIL THEN L:=LIST1(A); RETURN(L); END; 
(*4*) (*translate a to ap and find prime pl not dividing discr(as).*) 
      J1Y:=INV(T); T:=COMP(0,J1Y); AP:=IPTRAN(RL,A,T); P:=PRIME; 
      NL:=PDEG(AS); 
      REPEAT IF P = SIL THEN
                SWRITE("PRIME LIST EXHAUSTED IN ISFPF"); END; 
             ADV(P, PL,P); B:=MPHOM(1,PL,AS); ML:=PDEG(B); 
             IF ML = NL THEN BP:=MUPDER(PL,B); C:=MUPGCD(PL,B,BP); 
                KL:=PDEG(C); END; 
             UNTIL (ML = NL) AND (KL = 0); 
(*5*) (*convert as factors to monic factors modulo p.*) LP:=BETA; 
      REPEAT ADV(LS, A1S,LS); A1P:=MPHOM(1,PL,A1S); 
             A1P:=MPMON(1,PL,A1P); LP:=COMP(A1P,LP); 
             UNTIL LS = SIL; 
(*6*) (*compute a factor coefficient bound for abp=ap*ldcf(ap).*) 
      ALP:=PLDCF(AP); J1Y:=LIST2(0,ALP); ABP:=IPPROD(RL,AP,J1Y); 
      BL:=IPGFCB(RL,ABP); BL:=IMP2(BL,1); M:=PL; 
      WHILE ICOMP(M,BL) <= 0 DO M:=IDPR(M,PL); END; 
(*7*) (*compute factor degree bounds.*) V:=PDEGV(RL,ABP); D:=BETA; 
      V:=RED(V); 
      REPEAT ADV(V, VL,V); DL:=VL+1; D:=COMP(DL,D); 
             UNTIL V = SIL; 
(*8*) (*lift modular factors.*) L:=MPIQHL(RL,PL,LP,M,D,AP); 
(*9*) (*combine lifted factors.*) LP:=IPFLC(RL,M,D,AP,L,0); 
(*10*) (*translate ap factors to a factors.*) TP:=BETA; 
       REPEAT ADV(T, TL,T); J1Y:=INEG(TL); TP:=COMP(J1Y,TP); 
              UNTIL T = SIL; 
       TP:=INV(TP); L:=BETA; 
       REPEAT ADV(LP, A1P,LP); J1Y:=IPTRAN(RL,A1P,TP); L:=COMP(J1Y,L); 
              UNTIL LP = SIL; 
       RETURN(L); 
(*13*) END ISFPF; 


PROCEDURE MIPISE(RL,M,D,A,B,S,T,C: LIST;  VAR U,V: LIST); 
(*Modular integral polynomial mod ideal, solution of equation.  D is a
list (d sub 1, ...,d sub r-1) of non-negative beta-integers, r ge 1.
A, B, S, T and C belong to Z sub M (x sub 1, ...,x sub r-1,y)/(x sub 1 **
d sub 1, ...,x sub r-1 ** d sub r-1), with A monic and of positive
degree in y, and A*S+B*T=1.  U and V belong to Z sub M(x sub 1, ...,x
sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1) such
that A*U+B*V=C, and deg sub y of V lt deg sub y of A.*)
VAR  Q, W, Y, Z: LIST; 
BEGIN
(*1*) W:=MIPIPR(RL,M,D,T,C); MMPIQR(RL,M,D,W,A, Q,V); 
      Y:=MIPIPR(RL,M,D,S,C); Z:=MIPIPR(RL,M,D,B,Q); U:=MIPSUM(RL,M,Y,Z); 
      RETURN; 
(*4*) END MIPISE; 


PROCEDURE MPIQH(RL,PL,D,AB,BB,SB,TB,M,DP,C: LIST;  VAR A,B: LIST); 
(*Modular polynomial mod ideal, quadratic Hensel lemma.  p is a beta-
prime.  D and DP are lists of positive beta-integers of length r-1, r
ge 1.  AB, BB, SB, TB belong to Z sub p (x sub 1, ...,x sub r-1,y)/(x sub
1 ** d(1), ...,x sub r-1 ** d(r-1)), with AB monic, AB*SB+BB*TB=1, and
deg sub y of AB gt 0.  C is an r-variate integral polynomial, with AB*
BB congruent to C.  M, a positive integer, is equal to p**j for some
positive integer j.  A, b belong to Z sub M(x sub 1, ...,x sub r-1,y)/
(x sub 1 ** DP(1), ...,x sub rl-1 ** DP(r-1)), with A monic, A
congruent to AB, B congruent to BB, deg sub y of A=deg sub y of AB, and
A*B congruent to C.*)
VAR  AS, BS, CB, DH, DL, DPP, DS, IL, S, SS, T, TS: LIST; 
BEGIN
(*1*) (*initialize.*) DH:=D; A:=AB; B:=BB; S:=SB; T:=TB; DPP:=CINV(DP); 
      IL:=RL-1; CB:=MPHOM(RL,PL,C); 
(*2*) (*lift in x sub il.*) 
      WHILE IL > 0 DO ADV(DPP, DL,DPP); 
            MPIQHS(RL,PL,DH,A,B,S,T,IL,DL,CB, AS,BS,SS,TS,DS); A:=AS; 
            B:=BS; S:=SS; T:=TS; DH:=DS; IL:=IL-1; END; 
(*3*) (*lift to m.*) IPIQH(RL,PL,DP,AS,BS,S,T,M,C, A,B); RETURN; 
(*6*) END MPIQH; 


PROCEDURE MPIQHL(RL,PL,F,M,D,C: LIST): LIST; 
(*Modular polynomial mod ideal quadratic Hensel lemma, list.  C is an
r-variate integral polynomial.  F is a list (f sub 1, ...,f sub m)
of monic univariate polynomials of positive degree over Z sub p, with
the product of the f sub i (x) similar to C(0, ...,0,x), and gcd(f
sub i, f sub j)=1 for 1 le i lt j le m, p a beta-prime not
dividing ldcf(C).  M is a positive power of p.  D is a list (d
sub 1, ...,d sub r-1) of non-negative beta-integers.  FP is a list (fp
sub 1, ...,fp sub m) of monic polynomials in Z sub M (x sub 1, ...,x
sub r-1,x)/(x sub 1 ** d sub 1, ...,x sub r-1 ** d sub r-1), with
C similar to the product of the fp sub i, fp sub i congruent to f
sub i, and deg sub x of fp sub i=deg sub x of f sub i, for 1 le
i le m.*)
VAR  A, AB, B, BB, CB, CP, DP, FP, FS, IL, R, RLP, SB, TB: LIST; 
BEGIN
(*1*) (*initialize.*) FP:=BETA; FS:=F; CP:=IPIHOM(RL,D,C); 
      CP:=MIPHOM(RL,M,CP); B:=CP; RLP:=RL-1; DP:=BETA; 
      FOR IL:=1 TO RLP DO DP:=COMP(1,DP); END; 
(*2*) (*lift factors.*) 
      WHILE FS <> SIL DO ADV(FS, AB,FS); CB:=PUFP(RL,CP); 
            CB:=MIPHOM(1,PL,CB); BB:=MPQ(1,PL,CB,AB); MUPEGC(PL,AB,BB,
            R,SB,TB); AB:=PINV(1,AB,RLP); BB:=PINV(1,BB,RLP); 
            SB:=PINV(1,SB,RLP); TB:=PINV(1,TB,RLP); 
            MPIQH(RL,PL,DP,AB,BB,SB,TB,M,D,CP, A,B); FP:=COMP(A,FP); 
            IF FS <> SIL THEN MMPIQR(RL,M,D,CP,A, CP,R); END; 
            END; 
      FP:=INV(FP); RETURN(FP); 
(*5*) END MPIQHL; 


PROCEDURE MPIQHS(RL,M,D,AB,BB,SB,TB,SL,NL,C: LIST; VAR A,B,S,T,DP: LIST); 
(*Modular polynomial mod ideal, quadratic Hensel lemma on a single variable. 
M is a positive integer.  D is a list of positive beta-integers 
(d sub 1, ...,d sub r-1), r ge 2.  AB, BB, SB, TB belong to
Z sub M(x sub 1, ...,x sub r-1,y)/(x sub 1 ** d sub 1, ...,x sub r-1
**d sub r-1).  s is a positive integer lt r, and N is a
non-negative  beta-integer.  C is an element of Z sub M ( x sub 1, ...,
x sub r-1,yl).  AB is monic. AB*SB+BB*TB=1, AB*BB is congruent to C, 
and deg sub y of AB gt 0. 
A, B, S, T belong to Z sub M(x sub 1, ...,x sub r-1,y)/(x
sub 1 ** d sub 1, ...,S sub s-1 ** d sub s-1,x sub s ** n,x sub
s+1 ** d sub s+1, ...,x sub r-1 ** d sub r-1), with A*S+B*T=1, deg
sub y of A=deg sub y of AB, A monic, A*B congruent to C, and A congruent
to AB, B congruent to BB, S congruent to SB, T congruent to TB.  DP is
a list of non-negative beta-integers (d sub 1, ...,d sub
s-1,n,d sub s+1, ...,d  sub r-1).*)
VAR  AS, BS, DB, DH, DL, DS, DT, I, IL, J1Y, SS, TS, U, U1, V, VP, VPP,
     Y, Y1, YB, Z, Z1, ZB: LIST; 
BEGIN
(*1*) (*initialize.*) A:=AB; B:=BB; S:=SB; T:=TB; I:=LIST2(0,1); 
      J1Y:=RL-1; I:=PINV(1,I,J1Y); DB:=D; DS:=D; DH:=BETA; 
      FOR IL:=1 TO SL-1 DO ADV(DS, DL,DS); DH:=COMP(DL,DH); END; 
      ADV(DS, DL,DS); DT:=COMP(NL,DS); DP:=CINV(DH); DP:=CONC(DP,DT); 
LOOP
(*2*) IF DL > NL THEN A:=IPIHOM(RL,DP,A); B:=IPIHOM(RL,DP,B); 
         S:=IPIHOM(RL,DP,S); T:=IPIHOM(RL,DP,T); END; 
      IF DL >= NL THEN RETURN; END; 
(*3*) (*compute y,z.*) V:=MIPIPR(RL,M,DP,A,B); VP:=MIPDIF(RL,M,C,V); 
      U:=PDPV(RL,VP,SL,DL); MIPISE(RL,M,DB,A,B,S,T,U, Y,Z); 
(*4*) (*compute as,bs the liftings of a and b.*) J1Y:=-DL; 
      YB:=PDPV(RL,Y,SL,J1Y); J1Y:=-DL; ZB:=PDPV(RL,Z,SL,J1Y); 
      AS:=MIPSUM(RL,M,A,ZB); BS:=MIPSUM(RL,M,B,YB); 
(*5*) (*compute y1,z1.*) V:=MIPIPR(RL,M,DP,AS,S); 
      VP:=MIPIPR(RL,M,DP,BS,T); VPP:=MIPSUM(RL,M,V,VP); 
      V:=MIPDIF(RL,M,VPP,I); U1:=PDPV(RL,V,SL,DL); 
      MIPISE(RL,M,DB,A,B,S,T,U1, Y1,Z1); 
(*6*) (*compute ss,ts.*) J1Y:=-DL; YB:=PDPV(RL,Y1,SL,J1Y); J1Y:=-DL; 
      ZB:=PDPV(RL,Z1,SL,J1Y); SS:=MIPDIF(RL,M,S,YB); 
      TS:=MIPDIF(RL,M,T,ZB); 
(*7*) (*update.*) DL:=DL+DL; DT:=COMP(DL,DS); DB:=CINV(DH); 
      DB:=CONC(DB,DT); A:=AS; B:=BS; S:=SS; T:=TS; 
      END; (*go to 2;*) 
(*10*) RETURN; END MPIQHS; 


END SACPFAC.
(* -EOF- *)
