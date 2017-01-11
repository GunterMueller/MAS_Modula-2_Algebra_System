(* ----------------------------------------------------------------------------
 * $Id: DIPTOO.mi,v 1.7 1996/06/09 12:11:54 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPTOO.mi,v $
 * Revision 1.7  1996/06/09 12:11:54  pesch
 * Fixed typo.
 *
 * Revision 1.6  1994/03/30  13:05:17  dolzmann
 * New procedures DIPVOPP and INVPERM.
 *
 * Revision 1.5  1993/03/23  13:08:22  kredel
 * Cosmetic
 *
 * Revision 1.4  1993/03/23  13:01:37  kredel
 * Added LFCHECK
 *
 * Revision 1.3  1992/10/15  16:28:39  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:09  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPTOO;

(* DIP Termorder Optimization Implementation Module. *)



(* Import lists and declaration. *)

FROM MASELEM IMPORT MASMAX, GAMMAINT;

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, SRED, SFIRST,
                    COMP, BETA, INV, LENGTH, LIST1;

FROM SACLIST IMPORT ADV2, COMP2, LIST2, LAST, EQUAL,
                    SECOND, SLELT, CINV, RED2, OWRITE;

FROM MASBIOS IMPORT CREAD, CREADB, BLINES, SWRITE,
                    DIBUFF, BKSP, MASORD;

FROM SACD IMPORT DRANN;

FROM SACI IMPORT IPROD, ISUM;

FROM SACRN IMPORT RNRED;

FROM SACPOL IMPORT VLWRIT, VLREAD, PMON, PDEG;

FROM SACIPOL IMPORT IPSUM;

FROM SACCOMB IMPORT LPERM;

FROM DIPC IMPORT EVTDEG, EVSUM, EVLCM, EVORD, DILPERM,
                 DIPMCP, DIPTDG, DIPERM, DIPFP, 
                 DIPADM, DIPDEG, DIPMAD, DIPNOV;

FROM DIPI IMPORT DIIPWR;

FROM SACDPOL IMPORT DPFP;

FROM LINALGRN IMPORT RNMGELUD, RNMFIM;


CONST rcsidi = "$Id: DIPTOO.mi,v 1.7 1996/06/09 12:11:54 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPDEM(A: LIST): LIST;
(*Distributive polynomial degree matrix. A is a distributive
polynomial. B is the degree matrix of A. *)
VAR  AL, AP, B, EL, I, RL: LIST;
BEGIN
(*1*) (*init. *) B:=BETA; RL:=DIPNOV(A);
      IF RL = 0 THEN RETURN(B); END;
      FOR I:=1 TO RL DO B:=COMP(0,B); END;
      AP:=A;
(*2*) (*add exponent vectors. *)
      WHILE AP <> SIL DO DIPMAD(AP, AL,EL,AP); B:=DMEVAD(B,EL); END;
(*5*) RETURN(B); END DIPDEM;


PROCEDURE DIPDEV(A: LIST): LIST;
(*Distributive polynomial degree vector. A is a distributive
polynomial. N is the degree vector of A.*)
VAR  AL, AS, EL, N, NL: LIST;
BEGIN
(*1*) (*a=0.*) N:=BETA;
      IF A = 0 THEN RETURN(N); END;
(*2*) (*rl=0 or rl=1.*)
      IF DIPNOV(A) <= 1 THEN NL:=DIPDEG(A); N:=LIST1(NL); RETURN(N);
         END;
(*3*) (*find maximal degree vector.*) DIPMAD(A, AL,N,AS);
      WHILE AS <> SIL DO DIPMAD(AS, AL,EL,AS); N:=EVLCM(N,EL); END;
      RETURN(N);
(*6*) END DIPDEV;


PROCEDURE DIPLDM(A: LIST): LIST;
(*Distributive polynomial list degree matrix. A is a list of
distributive polynomials. B is the sum of all degree matrices
of each element of A. *)
VAR  AL, AP, B, BL, BP, C, CL: LIST;
BEGIN
(*1*) (*init. *) B:=BETA;
      IF A = SIL THEN RETURN(B); END;
      AP:=A;
      REPEAT ADV(AP, AL,AP);
             UNTIL (AL <> 0) OR (AP = SIL);
      IF AL = 0 THEN RETURN(B); END;
      B:=DIPDEM(AL);
(*2*) (*add degree matrices. *)
      WHILE AP <> SIL DO ADV(AP, AL,AP);
            IF AL <> 0 THEN BP:=DIPDEM(AL); C:=BETA;
               WHILE BP <> SIL DO ADV(BP, BL,BP); ADV(B, CL,B);
                     CL:=IPSUM(1,BL,CL); C:=COMP(CL,C); END;
               B:=INV(C); END;
            END;
(*5*) RETURN(B); END DIPLDM;


PROCEDURE DIPTRM(A: LIST): LIST;
(*Distributive polynomial terms. A is a distributive polynomial
in r variables. T is a list of beta-integers each counting
the terms in the respective variable.*)
VAR  AL, AS, EL, FL, L, RL, SL, T, TL: LIST;
BEGIN
(*1*) (*a=0 or rl=0.*) RL:=DIPNOV(A);
      IF RL = 0 THEN T:=BETA; RETURN(T); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN L:=LENGTH(A); L:=L DIV 2; T:=LIST1(L);
         RETURN(T); END;
(*3*) (*recursion.*) DIPADM(A, EL,FL,AL,AS); L:=1; TL:=DIPTRM(AL);
      WHILE AS <> 0 DO DIPADM(AS, EL,FL,AL,AS); SL:=DIPTRM(AL);
            L:=L+1; TL:=EVSUM(TL,SL); END;
(*4*) (*finish.*) T:=COMP(L,TL); RETURN(T);
(*7*) END DIPTRM;


PROCEDURE DIPTYP(A: LIST): LIST;
(*Distributive polynomial typ. A is a distributive polynomial
in r variables. t is a rational number, t is the typ of A,
0 lt t le 1. *)
VAR  B, P, PL, RL, SL, TL: LIST;
BEGIN
(*1*) (*a=0 or rl=0 or rl=1.*) RL:=DIPNOV(A);
      IF RL <= 1 THEN TL:=RNRED(1,1); RETURN(TL); END;
(*2*) (*rl gt 1.*) SL:=DIPTRM(A); P:=0;
      REPEAT ADV(SL, PL,SL); P:=ISUM(P,PL);
             UNTIL SL = SIL;
(*3*) (*normalise.*) B:=IPROD(PL,RL); TL:=RNRED(P,B); RETURN(TL);
(*6*) END DIPTYP;


PROCEDURE DIPVOP(P,V: LIST; VAR PP,VP: LIST);
(*Distributive polynomial variable ordering optimisation.
P and PP are lists of distributive polynomials.
V and VP are variable lists. The optimal variable ordering
for the polynomials in P is determined. The variables
of the polynomials in P are permuted to produce PP.
VP is the new variable list.*)
VAR  M, ML, MP, PL, PS, PV, VB, VL, VS: LIST;
BEGIN
(*1*) (*compute the degree matrix and the permutation vector. *)
      M:=DIPLDM(P); PV:=PVDEMA(M);
(*2*) (*write the reduced polynomials and permutation vector. *)
      VS:=CINV(V); VP:=LPERM(V,PV); MP:=M;
      SWRITE("THE REDUCED POLYNOMIALS"); BLINES(2);
      WHILE MP <> SIL DO ADV(MP, ML,MP); ADV(VS, VL,VS);
            VB:=LIST1(VL); ML:=DIPFP(1,ML); DIIPWR(ML,VB); BLINES(2);
            END;
      SWRITE("THE PERMUTATION VECTOR "); OWRITE(PV); BLINES(2);
      SWRITE("THE NEW VARIABLE LIST   "); VLWRIT(VP); BLINES(4);
(*3*) (*permute the polynomials. *) PP:=BETA; PS:=P;
      WHILE PS <> SIL DO ADV(PS, PL,PS); PL:=DIPERM(PL,PV);
            PP:=COMP(PL,PP); END;
      PP:=INV(PP);
(*6*) RETURN; END DIPVOP;


PROCEDURE DIPVOPP(P,V: LIST; VAR PP,VP,PV: LIST);
(*Distributive polynomial variable ordering optimization and permutation 
vector. P and PP are lists of distributive polynomials.
V and VP are variable lists. The optimal variable ordering
for the polynomials in P is determined. The variables
of the polynomials in P are permuted to produce PP.
VP is the new variable list, PV is the permutation to compute VP from V. *)
BEGIN
(*1*)	(*compute the degree matrix and the permutation vector. *)
	PV:=PVDEMA(DIPLDM(P));
	(* permute the variable list *)
	VP:=LPERM(V,PV);
(*3*)	(*permute the polynomials. *) 
	PP:=DILPERM(P,PV);
(*6*)	RETURN; 
END DIPVOPP;


PROCEDURE DMEVAD(A,E: LIST): LIST;
(*Degree matrix exponent vector add. A is a degree matrix.
E is an exponent vector. B=A + E. *)
VAR  AL, AP, B, BL, EL, EP, FL: LIST;
BEGIN
(*1*) (*init. *) AP:=A; EP:=E; B:=BETA;
(*2*) (*add. *)
      WHILE AP <> SIL DO ADV(AP, AL,AP); ADV(EP, EL,EP);
            FL:=PMON(1,EL); BL:=IPSUM(1,AL,FL); B:=COMP(BL,B); END;
      B:=INV(B);
(*5*) RETURN(B); END DMEVAD;
 

PROCEDURE HDIFDI(A: LIST;    VAR B,FL: LIST);
(*Homogeneous distributive polynomial from distributive polynomial.
A is a distributive polynomial in r variables. s=r+1.
If A is allready homogeneous then f=0 else f=1.
B(xs,x1, ...,xr)=(xs)**(tdeg(A)) * A(x1/xs, ...,xr/xs). *)
VAR  AL, AP, C, DL, E, EL, G, GL: LIST;
BEGIN
(*1*) (*a=0.*) B:=0; FL:=0;
      IF A = 0 THEN RETURN; END;
(*2*) (*insert new variable.*) AP:=A; DL:=DIPTDG(A); C:=BETA;
      REPEAT DIPMAD(AP, AL,E,AP); EL:=EVTDEG(E); GL:=DL-EL;
             IF GL > 0 THEN FL:=1; END;
             G:=CINV(E); G:=COMP(GL,G); G:=INV(G); C:=DIPMCP(G,AL,C);
             UNTIL AP = SIL;
      B:=INV(C);
(*5*) RETURN; END HDIFDI;
 

PROCEDURE INVPERM(perm: LIST):LIST;
(* inverse permutation. perm is a permutation. The inverse permutation
is returned, i.e. LPERM(LPERM(x,p),INVPERM(p))=x. *)
	VAR L, pos: LIST;
	VAR i, n: INTEGER;
BEGIN
(*1*)	(* initialization *)
	n:=LENGTH(perm);	
	L:=SIL;
(*2*)	(* construct a list L=(1,...,n) *)
	FOR i:=1 TO n DO L:=COMP(0,L); END;
(*3*)	(* construct the inverse permutation *)
	FOR i:=1 TO n DO
		ADV(perm,pos,perm);
		SLELT(L,pos,i);
	END;
(*9*)	RETURN L;
END INVPERM; 


PROCEDURE LBLXCO(U,V: LIST): LIST;
(*List of beta integers lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vs) are lists of beta integers.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the lexicographical ordering of the
beta integers. *)
VAR  TL, UL, US, VL, VS: LIST;
BEGIN
(*1*) (*initialise and compare.*) TL:=0; US:=U; VS:=V;
      WHILE (US <> SIL) AND (VS <> SIL) DO ADV(US, UL,US); ADV(VS,
            VL,VS);
            IF UL > VL THEN TL:=-1; RETURN(TL); END;
            IF UL < VL THEN TL:=1; RETURN(TL); END;
            END;
(*2*) (*same length. *)
      IF (US = SIL) AND (VS = SIL) THEN RETURN(TL); END;
      IF US = SIL THEN TL:=1; ELSE TL:=-1; END;
(*5*) RETURN(TL); END LBLXCO;


PROCEDURE LFCHECK(L, f: LIST): BOOLEAN;
(*Linear form check. L is a linear form for term comparison, 
if L is empty EVORD is checked. f is a print flag, 
if f >0 then a message is written to the output stream. *)
VAR   LP, LS, LL, LU, p, ps, d, dp: LIST;
BEGIN
(*1*) (*initialize.*) IF L = SIL THEN L:=EVORD END; 
      IF L <= SIL THEN
         IF f > 0 THEN SWRITE("Nothing to check."); BLINES(0) END; 
         RETURN(TRUE) END;
(*2*) (*convert and degree.*) d:=0; LS:=SIL; LP:=L; 
      WHILE LP <> SIL DO ADV(LP, p,LP); ps:=DPFP(1,p); 
            dp:=PDEG(p); IF dp > d THEN d:=dp END;  
            LS:=COMP(ps,LS); END;
      LS:=INV(LS); 
      LP:=LS; LS:=SIL; 
      WHILE LP <> SIL DO ADV(LP, p,LP); ADV(p, dp, ps);  
            WHILE dp < d DO ps:=COMP(0,ps); dp:=dp+1 END; 
            LS:=COMP(ps,LS); END;
      LS:=INV(LS); 
(*3*) (*LU decomposition.*) LS:=RNMFIM(LS); RNMGELUD(LS, LL,LU);  
      IF LENGTH(LS) > LENGTH(LU) THEN 
         IF f > 0 THEN 
            SWRITE("LFCHECK: LF linearly dependent."); BLINES(0) END; 
         RETURN(FALSE) END; 
      IF f > 0 THEN 
         SWRITE("LFCHECK: LF linearly independent."); BLINES(0) END; 
      RETURN(TRUE); 
(*9*) END LFCHECK
;


PROCEDURE PTERM(RL,A: LIST): LIST;
(*Polynomial terms. A is a recursive polynomial in r
variables. T is a list of beta-integers each counting the
terms in the respective variable.*)
VAR  AL, AS, EL, L, RLS, SL, T, TL: LIST;
BEGIN
(*1*) (*a=0 or rl=0.*)
      IF (A = 0) OR (RL = 0) THEN T:=BETA; RETURN(T); END;
(*2*) (*rl=1.*)
      IF RL = 1 THEN L:=LENGTH(A); L:=L DIV 2; T:=LIST1(L);
         RETURN(T); END;
(*3*) (*recursion.*) RLS:=RL-1; ADV2(A, EL,AL,AS); L:=1;
      TL:=PTERM(RLS,AL);
      WHILE AS <> SIL DO ADV2(AS, EL,AL,AS); SL:=PTERM(RLS,AL);
            L:=L+1; TL:=EVSUM(TL,SL); END;
(*4*) (*finish.*) T:=COMP(L,TL); RETURN(T);
(*7*) END PTERM;


PROCEDURE PTYP(RL,A: LIST): LIST;
(*Polynomial typ. A is a recursive polynomial in r variables.
t is a rational number, t is the PTYP of A, 0 lt t lt 1. *)
VAR  B, P, PL, SL, TL: LIST;
BEGIN
(*1*) (*a=0 or rl=0 or rl=1.*)
      IF (A = 0) OR (RL <= 1) THEN TL:=LIST2(1,1); RETURN(TL); END;
(*2*) (*rl gt 1.*) SL:=PTERM(RL,A); P:=0;
      REPEAT ADV(SL, PL,SL); P:=ISUM(P,PL);
             UNTIL SL = SIL;
(*3*) (*normalise.*) B:=IPROD(PL,RL); TL:=RNRED(P,B); RETURN(TL);
(*6*) END PTYP;


PROCEDURE PVDEMA(A: LIST): LIST;
(*Permutation vector for degree matrix. A is a degree matrix.
P is a permutation vector. *)
VAR  AP, B, BL, BP, BPP, F, G, I, J, K, P, RL, TL: LIST;
BEGIN
(*1*) (*init. *) RL:=LENGTH(A); P:=BETA;
      IF RL = 0 THEN RETURN(P); END;
      G:=LIST1(BETA); AP:=CINV(A);
(*2*) (*search smallest element. *)
      FOR I:=1 TO RL DO K:=0; B:=BETA; F:=G; BP:=AP;
          FOR J:=1 TO RL DO ADV(BP, BL,BPP); TL:=LBLXCO(F,BL);
              IF TL < 0 THEN K:=J; B:=BP; F:=BL; END;
              BP:=BPP; END;
          P:=COMP(K,P); SFIRST(B,G); END;
(*5*) RETURN(P); END PVDEMA;


END DIPTOO.


(* -EOF- *)
