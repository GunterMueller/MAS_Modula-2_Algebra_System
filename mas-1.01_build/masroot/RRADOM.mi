(* ----------------------------------------------------------------------------
 * $Id: RRADOM.mi,v 1.1 1994/03/11 15:21:49 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRADOM.mi,v $
 * Revision 1.1  1994/03/11  15:21:49  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE RRADOM;
(* Real Root Arbitrary Domain Implementation Module *)

(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, ADV, RED, COMP, INV, FIRST, LIST1, LENGTH;

FROM SACLIST IMPORT ADV2, COMP2, LIST2, SECOND, FIRST3, LIST3, EQUAL, 
                    CONC, CINV, SUFFIX, REDUCT, MEMBER, OWRITE;

FROM DIPC IMPORT DIPEVL, DIPFMO, DIPMAD, DIPMRD,
                 EVDOV, EVDFSI, EVCOMP, EVCADD, EVSUM, EVDIF, EVSIGN, EVTDEG;

FROM DIPADOM IMPORT DIPNEG, DIPBCP, DIPSUM;

FROM MASADOM IMPORT ADFI;

FROM MASELEM IMPORT MASEVEN;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACI IMPORT IWRITE;

FROM SACRN IMPORT RNNUM;

FROM LINALG IMPORT ADUM, ADVVSUM, ADVSVPROD, ADSMPROD, ADMSUM, ADMPROD,
                   ADMPTRACE, ADVSPROD, ADSIG, IMRTPROD;

FROM LINALGI IMPORT IMGELUD, IMSDS, IVWRITE;

FROM LINALGRN IMPORT VEL, MSET, MTRANS;

CONST rcsidi = "$Id: RRADOM.mi,v 1.1 1994/03/11 15:21:49 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE EVUMSORT(L: LIST): LIST;
(* Exponent vector unique merge sort. 
   The list of exponent vectors L ist sorted with respect to the actual 
   termorder. Multiple entries are deleted. *)
VAR L1,L2,s,x: LIST;
BEGIN
  IF (L <> SIL) AND (RED(L) <> SIL) THEN
    L1 := SIL;
    L2 := SIL;
    s := 1;
    WHILE L <> SIL DO
      ADV(L,x,L);
      IF s = 1 THEN L1 := COMP(x,L1) ELSE L2 := COMP(x,L2) END;
      s := -s;
    END;
    L1 := EVUMSORT(L1);
    L2 := EVUMSORT(L2);
    WHILE (L1 <> SIL) AND (L2 <> SIL) DO
      s := EVCOMP(FIRST(L1),FIRST(L2));
      IF s <>  1 THEN ADV(L1,x,L1) END;
      IF s <> -1 THEN ADV(L2,x,L2) END;
      L := COMP(x,L);
    END;
    WHILE L1 <> SIL DO ADV(L1,x,L1); L := COMP(x,L) END;
    WHILE L2 <> SIL DO ADV(L2,x,L2); L := COMP(x,L) END;
    L := INV(L);
  END;
  RETURN(L);
END EVUMSORT;

PROCEDURE EVSSPROD(T: LIST): LIST;
(* Exponent vektor set sorted product. 
   T is a list of terms. U = {a*b: a,b from T} is sorted with respect to 
   the actual termorder. *)
VAR U,V,v,t: LIST;
BEGIN
  U := SIL;
  WHILE T <> SIL DO
    V := T;
    ADV(T,t,T);
    WHILE V <> SIL DO
      ADV(V,v,V);
      U := COMP(EVSUM(t,v),U);
    END;
  END;
  RETURN(EVUMSORT(U));
END EVSSPROD;

PROCEDURE RRVTEXT(A,L: LIST): LIST;
(* Real root vector of tupels extension. 
   A is a set of s-tupels, L is a set of objects. B is a set of (s+1)-tupels 
   constructed by appending each object of L to the tupels of A. The ordering
   of B is increasing lexicographical wrt the ordering of L and A. *)
VAR B,As,as,e: LIST; 
BEGIN
  B := SIL;
  WHILE L <> SIL DO
    ADV(L,e,L);
    As := A;
    WHILE As <> SIL DO
      ADV(As,as,As);
      B := COMP(COMP(e,as),B);
  END; END;
  B := INV(B);
  RETURN(B);
END RRVTEXT;

PROCEDURE RRZDIM(G: LIST): LIST;
(* Real root zero-dimensional test.
   G non-trivial reduced groebner basis. 
   s = 1 iff Id(G) is zero-dimensional, s = 0 otherwise. *)
VAR n,g: LIST;
BEGIN
  n := LENGTH(DIPEVL(FIRST(G)));
  WHILE G <> SIL DO
    ADV(G,g,G);  
    IF LENGTH(EVDOV(DIPEVL(g))) = 1 THEN n := n - 1 END;
  END;
  IF n = 0 THEN RETURN(1) ELSE RETURN(0) END;
END RRZDIM;

PROCEDURE RRREDTEST(G,t: LIST; VAR g,s: LIST);
(* Real root reducibility test. 
   G reduced groebner basis, t term.
   s =  0, if t is reducible with an Element g of G with HT(g) = t,
   s = -1, if t is not reducible and s = 1 otherwise *)
VAR w: LIST;
BEGIN
  s := -1;
  WHILE (G <> SIL) AND (s = -1) DO
    ADV(G,g,G);
    EVDFSI(t,DIPEVL(g),w,s);
  END;
END RRREDTEST;

PROCEDURE RRREDTERMS(G: LIST): LIST;      
(* Real root reduced terms. 
   G reduced groebner basis of a nontrival zerodimensional ideal. R ist the 
   set of reduced terms sorted with respect to the actual termorder. *)
VAR R,L,i,j,g,t,n,s: LIST;
BEGIN
  n := LENGTH(DIPEVL(FIRST(G)));
  R := LIST1(VEL(0,n));
  FOR i := 1 TO n DO
    L := R;
    WHILE L <> SIL DO
      ADV(L,t,L);
      EVCADD(t,i,1,t,j);
      RRREDTEST(G,t,g,s);
      WHILE s = -1 DO
        R := COMP(t,R);
        EVCADD(t,i,1,t,j);
        RRREDTEST(G,t,g,s); 
      END;
    END;
  END; 
  RETURN(EVUMSORT(R));
END RRREDTERMS;  

PROCEDURE RRADNFORM(D,G,R: LIST): LIST;
(* Real root arbitrary domain normal form. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal of 
   domain D, R is the set of reduced terms. NF is a list of entries (u,ut,up)
   with: u is an element of R * R, RRREDTEST(G,u,_,ut) and up is the normal 
   form of u wrt G. The elements of NF are sorted with respect to the actual 
   termorder in decreasing order of the first entry. *)
VAR NF,N,L,U,u,ut,up,v,vt,vp,w,wt,wp,a,t,x,tx,g: LIST;
BEGIN
  NF := SIL;
  U := EVSSPROD(R);
  WHILE U <> SIL DO
    ADV(U,u,U);
    RRREDTEST(G,u,g,ut);
    IF ut = -1 THEN up := DIPFMO(ADFI(D,1),u)
    ELSIF ut = 0 THEN up := DIPNEG(DIPMRD(g)) ELSE
(* u is not in R and not in HM(G) *)
      up := 0; N := NF;
(* find element v in R x R with v*x = u and v not in R *) 
      REPEAT
        REPEAT                                 
          ADV(N,L,N);                    
          FIRST3(L,v,vt,vp);              
        UNTIL vt <> -1; 
        x := EVDIF(u,v);
      UNTIL (EVSIGN(x) = 1) AND (EVTDEG(x) = 1);
(* for all monomials a*t in vp: up=up+a*"normal-form of t*x" *) 
      N := NF;
      WHILE vp <> 0 DO
        DIPMAD(vp,a,t,vp);
        IF vp = SIL THEN vp := 0 END;
        tx := EVSUM(t,x);     
        REPEAT
          ADV(N,L,N);
          FIRST3(L,w,wt,wp);
        UNTIL EQUAL(w,tx) = 1; 
        up := DIPSUM(up, DIPBCP(wp,a));
      END;
    END;
    NF := COMP(LIST3(u,ut,up),NF);
  END;
  RETURN(NF);
END RRADNFORM;

PROCEDURE RRADSTRCONST(D,G,R: LIST; VAR U, beta: LIST);
(* Real root arbitrary domain structure constants. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal of 
   domain D, R is the set of reduced terms. beta is a matrix of structure-
   constants beta[u,v] wrt the basis R with u from U = R * R and v from R. 
   U and the rows of the matrix beta are sorted with respect to the actual 
   termorder in increasing order. *)
VAR NF,L,u,ut,up,uv,a,t,V,v: LIST;
BEGIN
  U := SIL; beta := SIL;
  NF := RRADNFORM(D,G,R);
  WHILE NF <> SIL DO
    ADV(NF,L,NF);
    FIRST3(L,u,ut,up);
    uv := SIL; V := CINV(R);
    WHILE up <> 0 DO
      DIPMAD(up,a,t,up);
      IF up = SIL THEN up := 0 END;
      ADV(V,v,V);
      WHILE EQUAL(v,t) = 0 DO ADV(V,v,V); uv := COMP(ADFI(D,0),uv) END;
      uv := COMP(a,uv);
    END; 
    WHILE V <> SIL DO ADV(V,v,V); uv := COMP(ADFI(D,0),uv) END;
    U := COMP(u,U);
    beta := COMP(uv,beta);
  END;
END RRADSTRCONST;

PROCEDURE RRMMULT(w,R,U,beta: LIST): LIST;
(* Real root matrix of multiplication. 
   R is the set of reduced terms in increasing order, w from R, U = R * R 
   and beta is the set of combined structure constants wrt R. The columnwise 
   represented matrix of multiplication with w is returned. *)
VAR M,u,v,t,l: LIST;
BEGIN
  M := SIL; 
  WHILE R <> SIL DO
    ADV(R,v,R);
    t := EVSUM(w,v);
    REPEAT 
      ADV(U,u,U);
      ADV(beta,l,beta)
    UNTIL EQUAL(t,u) = 1;
    M := COMP(l,M);
  END;
  RETURN(INV(M));
END RRMMULT;

PROCEDURE RRADVARMATRICES(G,R,U,beta: LIST): LIST;
(* Real root arbitrary domain multiplication matrices of variables. 
   G monic reduced groebner basis of a nontrivial zerodimensional ideal. R is
   the set of reduced terms in increasing order, U = R * R and beta is the
   set of combined structure constants wrt R. L is a list of entries of the 
   form (1,M(i)) and M(i) is the matrix of multiplication with X(i) wrt R. *)
VAR L,MXi,i,j,n,s,a,t,f,g: LIST;
BEGIN
  L := SIL;
  n := LENGTH(DIPEVL(FIRST(G)));
  FOR i := n TO 1 BY -1 DO
    EVCADD(VEL(0,n),i,1,t,j);
    RRREDTEST(G,t,g,s);
    IF s = -1 THEN MXi := RRMMULT(t,R,U,beta) ELSE
      MXi := SIL; f := DIPNEG(DIPMRD(g));
      WHILE f <> 0 DO
        DIPMAD(f,a,t,f);
        IF f = SIL THEN f := 0 END;
        MXi := ADMSUM(MXi,ADSMPROD(RRMMULT(t,R,U,beta),a));
    END; END;
    L := COMP(LIST2(1,MXi),L);
  END;
  RETURN(L);
END RRADVARMATRICES;

PROCEDURE RRADUPDATE(D,i,M1,M2: LIST; VAR l,ls: LIST);
(* Real root arbitrary domain update. Subroutine of RRADPOLMATRIX. *)
VAR j,M: LIST;
BEGIN
  WHILE (l <> SIL) AND (FIRST(l) < i) DO
    ADV2(l,j,M,l);
    ls := COMP2(M,j,ls);
  END;
  IF (l = SIL) OR (FIRST(l) > i) THEN
    M := ADMPROD(D,M1,M2);
    l := COMP2(i,M,l);
  END; 
END RRADUPDATE;

PROCEDURE RRADPOLMATRIX(D,R,h: LIST; VAR Mh,L: LIST);
(* Real root arbitrary domain polynomial matrix. 
   R is the set of reduced terms in increasing order, 
   h is a polynomial of domain D, L contains nonempty lists L(i) of the form 
   j(1),M(1),j(2),M(2),...,j(k),M(k) with 1=j(1)<j(2)<...<j(k) and M(l) ist 
   the matrix of multiplikation with X(i)**j(l) for the variable X(i). L is 
   extended with new calculated matrices. Mh is the matrix of multiplication 
   with h. *)
VAR Mt,Ls,l,ls,A,a,B,b,k,p,c,t: LIST;
BEGIN
  p := LENGTH(R);
  Mh := SIL;
  WHILE h <> 0 DO
    DIPMAD(h,c,t,h);
    IF h = SIL THEN h := 0 END;
    Mt := ADUM(D,p); 
    Ls := SIL;
    WHILE L <> SIL DO
      ADV(L,l,L);
      ADV(t,k,t);
      IF k <> 0 THEN
        ls := SIL;
        a := 0; A := ADUM(D,p);
        b := FIRST(l); B := SECOND(l);
        WHILE k <> 0 DO
          WHILE MASEVEN(k) DO
            b := 2*b; k := k DIV 2;
            RRADUPDATE(D,b,B,B,l,ls);
            B := SECOND(l);
          END;
          a := a+b; k:= k-1;
          RRADUPDATE(D,a,A,B,l,ls);
          A := SECOND(l);
        END;
        Mt := ADMPROD(D,Mt,A);
        l := CONC(INV(ls),l);
      END;
      Ls := COMP(l,Ls);
    END;
    Mh := ADMSUM(Mh,ADSMPROD(Mt,c));
    L := INV(Ls);
  END;
END RRADPOLMATRIX;

PROCEDURE RRADQUADFORM(D,R,U,beta,Mh: LIST): LIST;
(* Real root arbitrary domain quadratic form. 
   D is a domain, R is the set of reduced terms in increasing order, U = R * R
   and beta is the set of combined structure constants wrt R. Mh is the matrix
   of multiplication with h represented columnwise. The matrix Q=(q(i,j)) with
   q(i,j) = tr(M(h)*M(v(i))*M(v(j)) and v(i),v(j) from R is computed. *)
VAR Q,V,v,W,w,tab,t,p,betah,Mhv,i,j,e,q,s,u: LIST;
BEGIN
  tab := SIL;
  p := LENGTH(R);
  Q := VEL(VEL(0,p),p);
  betah := ADMPROD(D,beta,Mh);
  V := R; 
  FOR i := 1 TO p DO
    W := V;
    ADV(V,v,V);
    Mhv := RRMMULT(v,R,U,betah);
    FOR j := i TO p DO
      ADV(W,w,W); 
      u := EVSUM(v,w);
      s := 0; t := tab;
      WHILE (t <> SIL) AND (s = 0) DO
        ADV2(t,e,q,t);
        s := EQUAL(u,e);
      END;
      IF s = 0 THEN
        q := ADMPTRACE(D,Mhv,RRMMULT(w,R,U,beta));
        tab := COMP2(u,q,tab);
      END;
      Q := MSET(Q,i,j,q);
      IF j <> i THEN Q := MSET(Q,j,i,q) END; 
    END;
  END;
  RETURN(Q);
END RRADQUADFORM;

PROCEDURE RRCSR(i,v,tf: LIST; VAR A,N,S,L: LIST): LIST;
(* Real root count solve and reduce. Subroutine of the RR*COUNT procedures.
   i is an integer, v is a sign vector, tf is the trace-flag. 
   A is an integral k x k- matrix, N is a subset of {-1,0,+1}**i of length k 
   sorted in increasing lexicographical order, S is an integral vector of 
   length k and L is a list of length k.
   The system A*Z=S is solved and reduced by deleting the zero entries of Z
   and the corresponding columns of A. Then the system is reduced to a regular
   one by deleting linear dependend rows of A and the corresponding elements
   of S and L. ZNL is a list of pairs (z,n) with z > 0 is an element of Z and 
   n is the corresponding element of N. If there does not exist an element n
   in N satisfiing the sign condition v then the empty list is returned. *)
VAR ZNL,Z,z,zi,AL,AU,As,a,au,Ns,n,ni,Ss,s,Ls,l,k: LIST;
BEGIN
(* solve linear system *) 
  IMGELUD(A,AL,AU);
  Z := IMSDS(AL,AU,S);
(* delete zero entries of Z and corresponding columns of A and elements of N *)
  A := MTRANS(A); Ns := SIL; As := SIL; ZNL := SIL;
  WHILE Z <> SIL DO
    ADV(Z,z,Z); ADV(N,n,N); ADV(A,a,A);
    IF z <> 0 THEN
      zi := RNNUM(z); ni := CINV(n);
      IF tf = 1 THEN SWRITE("Sign-Condition: "); OWRITE(ni);
                     SWRITE("  Real Zeroes: "); OWRITE(zi); BLINES(0) END;
      ZNL := COMP(LIST2(zi,ni),ZNL);
      Ns := COMP(n,Ns); As:= COMP(a,As);
    END;
  END;
  N := INV(Ns); A := INV(As); ZNL := INV(ZNL);
(* test sign criterion *)
  IF (LENGTH(v) >= i) AND 
     (MEMBER(REDUCT(CINV(v),LENGTH(v)-i),N) = 0) THEN RETURN(SIL) END;
(* getting a regular system by deleting linear dependend rows of A *)
  k := LENGTH(FIRST(A));
  IMGELUD(A,AL,AU);
  A := MTRANS(A); As := SIL; Ss := SIL; Ls := SIL;
  WHILE AU <> SIL DO
    ADV(AU,au,AU); i := LENGTH(au);
    ADV(A,a,A); ADV(S,s,S); ADV(L,l,L);
    WHILE i < k DO
      ADV(A,a,A); ADV(S,s,S); ADV(L,l,L);
      k := k - 1;
    END;
    As := COMP(a,As); Ss:= COMP(s,Ss); Ls := COMP(l,Ls);
    k := k - 1;
  END;
  A := INV(As); S := INV(Ss); L := INV(Ls);
  RETURN(ZNL);
END RRCSR;

PROCEDURE RRADCOUNT(D,G,H,v,tf: LIST): LIST;
(* Real root arbirary domain count. 
   G is a monic reduced groebner basis of a zerodimensional ideal of domain D,
   H is a list of polynomials of length s. v is a vektor of signs with length 
   not greater than s. tf is the trace-flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of G wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v, 
   then the empty list is returned. *)
VAR ZNL,R,E,U,beta,s,S,m,N,A,W,L,i,h,S1,S2,m0,m1,m2,md,mh: LIST;
BEGIN
  R := RRREDTERMS(G);
  E := ADUM(D,LENGTH(R));
  RRADSTRCONST(D,G,R,U,beta);
  s := ADSIG(D,RRADQUADFORM(D,R,U,beta,E));
  IF s = 0 THEN RETURN(SIL) END;
  IF H = SIL THEN ZNL := LIST1(LIST2(s,SIL)); RETURN(ZNL) END;
  S := LIST1(s); m := LIST1(E); N := LIST1(SIL);
  A := LIST1(LIST1(1)); W := LIST3(LIST3(1,1,1),LIST3(-1,0,1),LIST3(1,0,1));
  L := RRADVARMATRICES(G,R,U,beta);
  i := 0;
  REPEAT
    ADV(H,h,H); i := i+1;
    IF tf = 1 THEN BLINES(1); 
              SWRITE("Condition No. "); OWRITE(i); BLINES(0) END;
    RRADPOLMATRIX(D,R,h,mh,L);
(* expanding the system *)
    N := RRVTEXT(N,LIST3(-1,0,1));
    A := IMRTPROD(W,A);
    S1 := SIL; S2 := SIL; m1 := SIL; m2 := SIL; m0 := m;
    WHILE m0 <> SIL DO
      ADV(m0,md,m0);
      md := ADMPROD(D,md,mh); m1 := COMP(md,m1);
      s := ADSIG(D,RRADQUADFORM(D,R,U,beta,md)); S1 := COMP(s,S1);
      md := ADMPROD(D,md,mh); m2 := COMP(md,m2);
      s := ADSIG(D,RRADQUADFORM(D,R,U,beta,md)); S2 := COMP(s,S2);
    END;
    S := CONC(S,CONC(INV(S1),INV(S2)));
    m := CONC(m,CONC(INV(m1),INV(m2)));
(* solving the linear equation A*Z=S and reduce the system *)
    ZNL := RRCSR(i,v,tf,A,N,S,m);
  UNTIL (ZNL = SIL) OR (H = SIL);
  RETURN(ZNL);
END RRADCOUNT;

END RRADOM.

(* -EOF- *)


