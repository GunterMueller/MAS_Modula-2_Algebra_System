(* ----------------------------------------------------------------------------
 * $Id: MASNCC.mi,v 1.3 1992/10/15 16:29:47 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNCC.mi,v $
 * Revision 1.3  1992/10/15  16:29:47  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:32  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:23  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASNCC;

(* MAS Non-commutative Center Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, 
                    LIST1, FIRST, SRED, RED, ADV, COMP, INV, LENGTH;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM SACLIST IMPORT CONC, LELT, CCONC, EQUAL, MEMBER, LIST2,  
                    THIRD, SECOND, 
                    OWRITE, ADV2, ADV4, ADV3, FIRST4, FIRST2;

FROM SACSET IMPORT USDIFF;

FROM SACRN IMPORT RNINT, RNNEG, RNSUM;

FROM MASRN IMPORT RNONE;

FROM SACPOL IMPORT PINV, PMON, VLWRIT;

FROM SACRPOL IMPORT RPSUM;

FROM DIPC IMPORT DIPNBC, DIPEVL, DIPNOV, EVSUM, EVDOV, DILFPL, DIPFMO, DIPFP,
                 DIPMCP, DIPMAD, EVCADD, VALIS, EVORD, INVLEX, DIPLPM,
                 DIPLBC, EVLCM, DIPMRD,
                 STVL, DIPMPV, DIPTBC, DIPBSO, PFDIP, PMPV, PBCLI;

FROM DIPTOO IMPORT DIPDEV;

FROM DIPRN IMPORT DIRPSM, DIRPPR, DIRPEM, DIRPEV, DIRPDF, DIRPWR, DIRLWR;

FROM DIPRNGB IMPORT DIRLIS;

FROM DIPDIM IMPORT DIGBZT;

FROM MASNC IMPORT DINPPR;

FROM MASNCGB IMPORT DINLNF;

CONST rcsidi = "$Id: MASNCC.mi,v 1.3 1992/10/15 16:29:47 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINCCO(T, A, B: LIST): LIST;
(*Distributive rational non-commutative polynomial commutator. 
A and B are distributive rational non-commutative polynomials.
The commutator of A and B is returned. T is the relation table. *)
VAR   C, C1, C2: LIST;
BEGIN
(*1*) (*Products*) C1:=DINPPR(T, A,B); C2:=DINPPR(T, B,A); 
(*2*) (*Difference*) C:=DIRPDF(C1,C2); 
      RETURN(C);
(*3*) END DINCCO;


PROCEDURE DINCCP(T, E: LIST): LIST; 
(*Distributive rational non-commutative polynomial center polynomial. 
E is a list of exponent vectors. T is the relation table. 
A polynomial in the center of the polynomial ring is returned. *)
VAR   C, CL, CP, EINS, V,  
      EVOREM, EVOCOR, ES, EP, EH, EB, 
      e, ep, f, l, n, m, a, 
      P, PP, PE, p, pp, r, r1, r2, rp,  
      X, Y, Z: LIST; 
      ec: BOOLEAN;
BEGIN
(*1*) (*initialise. *) PP:=0;
      IF E = SIL THEN RETURN(PP); END; 
      (*remember actual termorder.*)
      EVOREM:=EVORD; EVOCOR:=INVLEX; ec:=(EVOREM = EVOCOR); 

(*2*) (*build polynomials from variables. *)
      e:=FIRST(E); r:=LENGTH(e); EINS:=RNINT(1); 
      IF r = 0 THEN PP:=DIPFMO(EINS,COMP(1,e)); RETURN(PP) END;
      EP:=EVLGTD(r,1,SIL); EP:=SECOND(EP); 
      PE:=DILFEL(EINS,EP); PE:=INV(PE); 
      EH:=DILFEL(EINS,E); EH:=DIPLPM(EH);

(*3*) (*generate linear systems of equations for the coefficients. *) 
      EP:=PE; C:=SIL;
      WHILE EP <> SIL DO ADV(EP,Z,EP); 
            P:=0; l:=0; n:=r; ES:=EH; 

            SWRITE("commutators with: "); DIRPWR(Z,VALIS,-1); BLINES(0);
      
            REPEAT ADV(ES,X,ES);  
                   P:=PINV(r,P,1); l:=l+1; n:=r+l;  
                   Y:=DINCCO(T,X,Z); 
                   IF Y <> 0 THEN 
                      IF NOT ec THEN 
                         EVORD:=EVOCOR; DIPBSO(Y); EVORD:=EVOREM END; 
                      PFDIP(Y, rp,Y); Y:=PINV(r,Y,l); 
                      Y:=PMPV(n,Y,l,1); P:=RPSUM(n,P,Y); 
                      END;
                   UNTIL ES = SIL; 

            CP:=PBCLI(r,P); CP:=DILFPL(l,CP);
              SWRITE("added coefficient system: "); BLINES(0);
              V:=STVL(l); DIRLWR(CP,V,-1); BLINES(1); 
            C:=CCONC(CP,C); 
            C:=DIRLIS(C); (* evord ! *)
            END; 

      IF NOT ec THEN EVORD:=EVOCOR END; 
      C:=DIPLPM(C); (*must be sorted*)
      IF NOT ec THEN EVORD:=EVOREM END; 

      SWRITE("Coefficient system: "); BLINES(0);
      V:=STVL(l); DIRLWR(C,V,-1); BLINES(1);

(*5*) (*construct center polynomial. *)  
      PP:=0; r1:=LENGTH(EH); r2:=LENGTH(C); rp:=r1-r2;  
 
      IF rp > 0 THEN EB:=EVLGTD(rp,1,SIL); EB:=SECOND(EB); 
                ELSE EB:=SIL END;
      ES:=EVLINV(EB,0,r); ES:=INV(ES); (*parameters*)

      m:=0; EP:=SIL;
      WHILE C <> SIL DO ADV(C, CL,C); (* CL <> 0 ! *) 
            m:=m+1;
      
            (*head term, left hand side*)
            DIPMAD(CL,a,f,CL); (*a = 1 !*)
            e:=EVDOV(f); n:=l-FIRST(e)+1; (*e <> () !*) 
            e:=LELT(EH,n); e:=DIPEVL(e); (*wg. sorted *)
            e:=EVINV(e,r,rp); p:=DIPFMO(a,e);

            (*check for new parameters. *)
            EP:=INV(EP);
            WHILE m < n DO ADV(ES,ep,ES);
                  EP:=COMP(ep,EP);
                  e:=LELT(EH,m); e:=DIPEVL(e); (*wg. sorted *) 
                  e:=EVINV(e,r,rp); e:=EVSUM(e,ep);
                  pp:=DIPFMO(EINS,e); 
                  PP:=DIRPSM(PP,pp); 
                  m:=m+1; END;
            EP:=COMP(4711,EP); EP:=INV(EP);

            (*get right hand side. *) pp:=SIL;
            WHILE CL <> SIL DO DIPMAD(CL,a,f,CL);
                  a:=RNNEG(a);
                  e:=EVDOV(f); n:=l-FIRST(e)+1; (*e <> () !*) 
                  e:=LELT(EP,n); (*parameters*) 
                  pp:=DIPMCP(e,a,pp);
                  END; 
            pp:=INV(pp);
            IF pp <> SIL THEN 
               pp:=DIRPPR(p,pp);
               PP:=DIRPSM(PP,pp) END;
            END; 

      (*check for new parameters. *)
      EP:=INV(EP); 
      WHILE ES <> SIL DO ADV(ES,ep,ES);
            EP:=COMP(ep,EP);
            e:=LELT(EH,m); e:=DIPEVL(e); (*wg. sorted *) 
            e:=EVINV(e,r,rp); e:=EVSUM(e,ep);
            pp:=DIPFMO(EINS,e); 
            PP:=DIRPSM(PP,pp); 
            m:=m+1; END;
      EP:=INV(EP);
(*7*) RETURN(PP); END DINCCP; 


PROCEDURE DINCCPpre(T, E: LIST): LIST; 
(*Distributive non-commutative polynomial center polynomial preparation. 
E is a list of exponent vectors. T is the relation table. 
A polynomial in the center of the polynomial ring is returned. *)
VAR   TP, pl, pr, pp, e, N, NP, 
      C, Z, V, F, FP, FS,
      ES, EP, P, PP, PE, Q, QP, n, r, rp, one: LIST;
BEGIN
(*1*) (*initialise. *) PP:=0;
      IF E = SIL THEN RETURN(PP) END; 
      r:=LENGTH(FIRST(E));

(*2*) (*prepare. *) EP:=E; PE:=EVLGTD(r,2,SIL);
      TP:=T; FP:=SIL;
      WHILE TP <> SIL DO ADV3(TP,pl,pr,pp, TP);  
            IF DIPMRD(pp) <> 0 THEN
               N:=EVLCM(DIPEVL(pl),DIPEVL(pr)); 
	       FP:=COMP(N,FP);
               END;
            END;
      SWRITE("FP: "); OWRITE(FP); BLINES(0);
      FS:=SECOND(PE);
      WHILE FS <> SIL DO ADV(FS,N,FS);
            N:=EVSUM(N,N); 
            FP:=COMP(N,FP);
            END;
      F:=THIRD(PE); 
      F:=USDIFF(F,FP);
      SWRITE("F: "); OWRITE(F); BLINES(0);

      EP:=E;
(*3*) (*call DINCCP and report. *) PP:=DINCCP(T,EP);
      IF PP = 0 THEN RETURN(PP) END;
      rp:=DIPNOV(PP)-r;
      V:=STVL(rp); (*rp parameters*)
      SWRITE("Parameters: "); VLWRIT(V); BLINES(1);
      V:=CONC(V,VALIS); 
      SWRITE("Center polynomial: "); BLINES(0);
      DIRPWR(PP,V,-1); BLINES(1);

(*6*) (*specialization. *) one:=RNINT(1);
      EP:=EVLGTD(rp,1,SIL); (*miss use. *)
      EP:=SECOND(EP);
      QP:=SIL;

      WHILE EP <> SIL DO ADV(EP,ES,EP);
            P:=PP; n:=rp;
            WHILE ES <> SIL DO ADV(ES,e,ES); 
                  IF e = 1 THEN P:=DIRPEV(P,n,one); 
                           ELSE P:=DIRPEV(P,n,0) END; 
                  n:=n-1;
                  END; 
            QP:=COMP(P,QP);
            END;
      QP:=INV(QP); 

      P:=QP;
      SWRITE("Specialized center polynomials: "); BLINES(0);
      DIRLWR(P,VALIS,-1); BLINES(1);

(*7*) (*test. *) 
      EP:=EVLGTD(r,1,SIL); EP:=SECOND(EP); 
      EP:=INV(EP); EP:=DILFEL(one,EP); (*list of vars as polys. *)
      WHILE EP <> SIL DO ADV(EP,Z,EP); 
            WHILE QP <> SIL DO ADV(QP,Q,QP);
                  C:=DINCCO(T,Q,Z); 
                  IF C <> 0 THEN 
                     SWRITE("Commutator with: "); 
                     DIRPWR(Q,VALIS,-1); BLINES(0);
                     DIRPWR(Z,VALIS,-1); BLINES(0);
                     DIRPWR(C,VALIS,-1); BLINES(1);
                     END;
                  END;
            END;
(*7*) RETURN(P); END DINCCPpre; 


PROCEDURE DILFEL(a, E: LIST): LIST;
(*Distributive polynomial list from exponent vector list. 
E is a list of exponent vectors. A list of distributive polynomials 
with exponent vectors from E and coefficients equal to a is returned. *)
VAR   EP, P, p, ep: LIST;
BEGIN
(*1*) (*trivial cases. *) P:=SIL;
      IF (a = 0) OR (E = SIL) THEN RETURN(P) END;
(*2*) (*loop over exponent vectors. *) EP:=E; 
      WHILE EP <> SIL DO ADV(EP,ep,EP);
            p:=DIPFMO(a,ep); P:=COMP(p,P) END;
      P:=INV(P);
(*7*) RETURN(P); END DILFEL; 


PROCEDURE DINPTslT(T: LIST): BOOLEAN; 
(*Distributive polynomial non-commutative product table strict lex test.
T is a table of distributive polynomials specifying the non-commutative
relations. It is tested if T is strict lexicographical, i.e. if 
Xj*Xi = cij Xi Xj + pij is a strict lexicographical commutator relation,
then cij = 1 and pij <(inv lex) Xi Xj. *)
VAR   g, g1, g2, e1, e2, C, P, Q1, Q2: LIST;
      t: BOOLEAN; 
BEGIN
(*1*) (*initialize.*) P:=T; 
      IF P = SIL THEN RETURN(TRUE) END;
(*2*) (*check polynomials in P. *) 
      REPEAT ADV3(P, Q1,Q2,C,P); 
             g:=DIPLBC(C);
             IF RNONE(g) <> 1 THEN RETURN(FALSE) END;
             C:=DIPMRD(C); g1:=DIPDEV(C); e1:=EVDOV(g1);
             IF e1 = SIL THEN e1:=0 ELSE e1:=FIRST(e1) END;
             g2:=DIPEVL(Q1); e2:=EVDOV(g2); 
             (*e2 <> SIL*) e2:=FIRST(e2);
             IF e1 <= e2 THEN RETURN(FALSE) END;
             UNTIL P = SIL; 
      RETURN(TRUE)
(*6*) END DINPTslT; 


PROCEDURE DINLMPG(T,i,F: LIST): LIST; 
(*Distributive non-commutative left rational minimal polynomial for a G basis. 
F is a non-commutative left groebner basis. 
PP is the left minimal polynomial for the i-th variable for F. *)
VAR   C, c, CLP, CP, CS, EINS, e, J1Y, j, EVOREM, EVOCOR,
      l, n, P, p, PP, r, rs, t, X, XP, YP: LIST; 
      ec: BOOLEAN;
BEGIN
(*1*) (*initialise. *) 
      IF F = SIL THEN PP:=0; RETURN(PP); END; 
      J1Y:=FIRST(F); r:=DIPNOV(J1Y); EINS:=RNINT(1); 
      EVOREM:=EVORD; EVOCOR:=INVLEX; ec:=(EVOREM = EVOCOR); 
      e:=SIL; 
      FOR j:=1 TO r DO e:=COMP(0,e); END; 
      X:=DIPFMO(EINS,e); l:=1; n:=r+l; PFDIP(X, rs,P); 
      P:=PINV(r,P,1); P:=PMPV(n,P,l,1); 
(*2*) (*solve linear systems of equations to get the coefficients. *) 
      REPEAT XP:=DIPMPV(X,i,l); (*commut.*) l:=l+1; 
             XP:=DINLNF(T,F,XP); (*non-commutative*)
             IF NOT ec THEN EVORD:=EVOCOR; DIPBSO(XP); END; 
             PFDIP(XP, rs,YP); YP:=PINV(r,YP,l); n:=r+l; 
             YP:=PMPV(n,YP,l,1); (*commut.*) 
             P:=PINV(r,P,1); P:=RPSUM(n,P,YP); 
             CP:=PBCLI(r,P); C:=DILFPL(l,CP); CS:=SIL; 
             WHILE C <> SIL DO ADV(C, c,C); c:=DIRPEM(c,EINS); (*commut.*)
                   CS:=COMP(c,CS); END; 
             C:=INV(CS); C:=DIRLIS(C); (*commut.*) t:=DIGBZT(C); 
             IF  NOT ec THEN EVORD:=EVOREM; END; 
             UNTIL t = 0; 
      l:=l-1; 
      SWRITE("C="); OWRITE(C); BLINES(0);
(*3*) (*constuct minimal polynomial. *) PP:=PMON(EINS,l); 
      WHILE C <> SIL DO ADV(C, c,C); e:=DIPEVL(c); 
            n:=l-FIRST(EVDOV(e));  
            CLP:=RNNEG(DIPTBC(c)); p:=PMON(CLP,n); 
            PP:=RPSUM(1,PP,p); END; 
      PP:=DIPFP(1,PP); 
(*6*) RETURN(PP); END DINLMPG; 


PROCEDURE DINLMPL(T,F: LIST): LIST; 
(*Distributive non-commutative left rational minimal polynomial list for a G basis. 
F is a non-commutative left groebner basis. 
P is the list of left minimal polynomial for each variable for F. *)
VAR   P, p, r, i, t: LIST; 
BEGIN
(*1*) (*initialise. *) P:=SIL;
      IF F = SIL THEN RETURN(P) END;
      r:=DIPNOV(FIRST(F)); 
(*2*) (*check dimension and commutator relations. *) 
      t:=DIGBZT(F);
      IF t > 0 THEN RETURN(P) END;
      IF NOT DINPTslT(T) THEN RETURN(P) END;
(*3*) (*construct minimal polynomials. *) i:=0;
      WHILE i < r DO i:=i+1;
            p:=DINLMPG(T,i,F); P:=COMP(p,P);
            END;
      P:=INV(P);
(*6*) RETURN(P); END DINLMPL; 


PROCEDURE EVGCD(U,V: LIST): LIST;
(*Exponent vector greatest common divisor. U=(UL1, ...,ULRL),
V=(VL1, ...,VLRL) are exponent vectors of length r.
W=(WL1, ...,WLRL) is the greatest common divisor of U and V. *)
VAR  UL, US, VL, VS, W, WL: LIST;
BEGIN
(*1*) (*U=() and V=().*) W:=BETA;
      IF U = SIL THEN RETURN(W); END;
      US:=U; VS:=V;
(*2*) (*minimum of components.*)
      REPEAT ADV(US, UL,US); ADV(VS, VL,VS);
             IF UL < VL THEN WL:=UL; ELSE WL:=VL; END;
             W:=COMP(WL,W);
             UNTIL US = SIL;
(*3*) (*FINISH.*) W:=INV(W); RETURN(W);
(*6*) END EVGCD;


PROCEDURE EVLGTD(r,d,L: LIST): LIST;
(*Exponent vector list generate for total degree. 
r is the number of variables. L is a list of already generated 
exponent vectors. A list of exponent vectors up to total degree 
d (>= 0) is returned. *)
VAR   LS, LP, D, DP, DPP, DPPP, DH, e, f, n, ep, m, l: LIST;
BEGIN
(*1*) (*d = 0. *) LP:=L; 
      IF LP = SIL THEN e:=SIL;
         FOR n:=1 TO r DO e:=COMP(0,e) END;
         D:=LIST1(e); LP:=COMP(D,LP);
         END;
      IF d = 0 THEN RETURN(LP) END;
(*2*) (*d = 1. *) LS:=RED(LP);
      IF LS = SIL THEN e:=FIRST(FIRST(LP)); D:=SIL;
         FOR n:=1 TO r DO EVCADD(e,n,1,ep,f); D:=COMP(ep,D) END;
         D:=INV(D); LS:=LIST1(D); LP:=CCONC(LP,LS); 
         END;
      IF d = 1 THEN RETURN(LP) END; 
(*3*) (*d >= 1, skip already computed exponent vectors. *)
      ADV(LS,D,LS); DP:=D; m:=2;
      WHILE (m <= d) AND (LS <> SIL) DO
            m:=m+1; ADV(LS,DP,LS);
            END;
(*4*) (*generate new exponent vectors. *) LS:=SIL;
      WHILE m <= d DO m:=m+1; DH:=SIL; 
            FOR n:=1 TO r DO DPP:=DP; l:=n-1; 
                (*skip by commutativity already done stuff. *) 
                REPEAT DPPP:=DPP; ADV(DPP,e,DPP);
                       UNTIL EVTSZ(l,e); 
                DPP:=DPPP; DP:=DPP;
                WHILE DPP <> SIL DO  ADV(DPP,e,DPP);
                      EVCADD(e,n,1,ep,f); DH:=COMP(ep,DH);
                      END;
                END;
            DH:=INV(DH); DP:=DH; LS:=COMP(DH,LS);
            END; 
(*5*) (*combine old and new exponent vectors. *)
      IF LS <> SIL THEN LS:=INV(LS); LP:=CCONC(LP,LS) END; 
      RETURN(LP); 
(*9*) END EVLGTD;


PROCEDURE EVLGIL(D: LIST): LIST;
(*Exponent vector list generate for inverse lexicographical sequence. 
D is a list of maximal degrees in the respective variable. 
A list of exponent vectors up to the maximal degrees is returned. *)
VAR   U, LP, LPP, LS, DP, e, n: LIST;
BEGIN
(*1*) (*recursion base, zero variables. *) LP:=SIL;
      IF D = SIL THEN LP:=COMP(SIL,LP); RETURN(LP) END;
(*2*) (*recursion base, one variable. *) ADV(D,e,DP); 
      IF DP = SIL THEN 
         FOR n:=0 TO e DO U:=LIST1(n); LP:=COMP(U,LP) END;
         RETURN(LP);
         END; 
(*3*) (*recursion.*) LS:=EVLGIL(DP); LS:=INV(LS); 
      FOR n:=0 TO e DO LPP:=LS;
          WHILE LPP <> SIL DO ADV(LPP,U,LPP);
                U:=COMP(n,U); LP:=COMP(U,LP) END;
          END;
      RETURN(LP); 
(*9*) END EVLGIL;


PROCEDURE EVLINV(L,i,k: LIST): LIST;
(*Exponent vector list introduction of new variables. 
L is a list of exponent vectors. In each element of L k new variables
are introduced after position i. The new list is returned. *) 
VAR   M, LP, E, e: LIST;
BEGIN
(*1*) (*trivial cases. *) LP:=L;
      IF (L = SIL) OR (k = 0) THEN RETURN(LP) END;
(*2*) (*introduce variables. *) M:=L; LP:=SIL;
      WHILE M <> SIL DO ADV(M,e,M); 
            e:=EVINV(e,i,k); LP:=COMP(e,LP) END; 
      LP:=INV(LP); RETURN(LP); 
(*9*) END EVLINV;


PROCEDURE EVTSZ(i,U: LIST): BOOLEAN;
(*Exponent vector test if starting with i zero exponents. *) 
VAR   e, n: LIST;
BEGIN
(*1*) (*search non-zero exponents. *)  
      FOR n:=1 TO i DO ADV(U,e,U); 
          IF e <> 0 THEN RETURN(FALSE) END;
          END;
(*2*) (*no non-zero exponents found. *) RETURN(TRUE); 
(*9*) END EVTSZ;


PROCEDURE EVINV(U,i,k: LIST): LIST;
(*Exponent vector introduction of new variables. At position
i in U k new variables are introduced. *) 
VAR   j, V, W, WS, e: LIST;
BEGIN
(*1*) (*copy exponents. *) V:=SIL;
      FOR j:=1 TO i DO ADV(U, e,U); V:=COMP(e,V); END;
(*2*) (*add new exponents. *) W:=U;
      FOR j:=1 TO k DO W:=COMP(0,W); END;
(*3*) (*combine exponents. *) 
      IF V <> SIL THEN WS:=INV(V); SRED(V,W); W:=WS END;
      RETURN(W);
(*9*) END EVINV;


END MASNCC.

(* -EOF- *)
