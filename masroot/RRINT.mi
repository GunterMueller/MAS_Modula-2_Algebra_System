(* ----------------------------------------------------------------------------
 * $Id: RRINT.mi,v 1.1 1994/03/11 15:21:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRINT.mi,v $
 * Revision 1.1  1994/03/11  15:21:51  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE RRINT;
(* Real Root Integral Implementation Module *)

(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, ADV, COMP, INV, FIRST, LENGTH, LIST1;

FROM SACLIST IMPORT CINV, EQUAL, LIST2, ADV2, COMP2, FIRST4, LIST3, 
                    LIST4, SECOND, CONC, MEMBER, REDUCT, OWRITE;

FROM MASELEM IMPORT MASEVEN;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM MASI IMPORT IPROD;

FROM SACI IMPORT IGCDCF, ILCM, IQ, IEXP, IMAX;

FROM DIPI IMPORT DIIPIP, DIIPSM, DIIPIQ, DIIPCP, DIIPNG;

FROM DIPC IMPORT DIPEVL, DIPFMO, DIPMAD, DIPMRD, DIPLBC,
                 EVCADD, EVCOMP, EVSUM, EVDIF, EVSIGN, EVTDEG, EVLCM;

FROM LINALGI IMPORT IUM, IMSUM, ISMPROD, IMPROD;

FROM LINALGRN IMPORT VEL, MSET;

FROM LINALG IMPORT IMPTRACE, ISIG, IMRTPROD;

FROM RRADOM IMPORT RRREDTEST, RRREDTERMS, EVSSPROD, RRMMULT, RRVTEXT, RRCSR;

CONST rcsidi = "$Id: RRINT.mi,v 1.1 1994/03/11 15:21:51 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE RRIPIQ(c: LIST; VAR A,a: LIST);
(* Real root integral polynomial integral quotient.
   A is an integral polynomial. a and c are nonzero integers. New values for 
   A and a are computed such that the equation A/a := (1/c)*(A/a) holds. If a 
   and the content of A have gcd 1 then this is also true for the result. *)
VAR b,ct,pp,cts,cs: LIST;
BEGIN
  IF c <> 1 THEN
    DIIPCP(A,ct,pp);
    IGCDCF(ct,c,b,cts,cs);
    A := DIIPIP(pp,cts);
    a := IPROD(a,cs);
  END;
END RRIPIQ;   

PROCEDURE RRIPQSUM(B,b,c: LIST; VAR A,a: LIST);
(* Real root integral polynomial quotient sum. 
   A and B are integral polynomials. a,b and c are non zero integers. 
   New values for A and a are computed such that the equation 
   A/a := A/a + c*(B/b) holds. If b and the content of B have gcd 1 
   and a and the content of A have gcd 1 then the new integral polynomial 
   A has gcd 1 with the new value of a. *)
VAR as,bs,bss,cs,d,e,es,f,ct,cts,pp: LIST;
BEGIN
  IF B <> 0 THEN
  IF A = 0 THEN
    IF b = 1 THEN A := DIIPIP(B,c); a := 1;
    ELSE IGCDCF(b,c,d,a,cs); A := DIIPIP(B,cs); END;
  ELSIF (a = 1) AND (b = 1) THEN
    A := DIIPSM(A,DIIPIP(B,c));
  ELSIF b = 1 THEN
    A := DIIPSM(A,DIIPIP(B,IPROD(a,c)));
  ELSIF a = 1 THEN
    IGCDCF(b,c,d,a,cs);
    A := DIIPSM(DIIPIP(A,a),DIIPIP(B,cs));
  ELSE 
    IGCDCF(b,c,d,bs,cs);
    IGCDCF(a,bs,e,as,bss);
    A := DIIPSM(DIIPIP(A,bss),DIIPIP(B,IPROD(cs,as)));
    DIIPCP(A,ct,pp);
    IGCDCF(ct,e,f,cts,es);
    A := DIIPIP(pp,cts);
    a := IPROD(IPROD(as,es),bss);
  END; END;
END RRIPQSUM;

PROCEDURE RRINFORM(G,R: LIST; VAR a,NF: LIST);
(* Real root integral normal form. 
   G reduced integral groebner basis of a nontrivial zerodimensional ideal, 
   R is the set of reduced terms. NF is a list of entries (u,ut,ua,up) with: 
   u is an element of R * R, RRREDTEST(G,u,_,ut), up is an integral polynomial
   and ua is an integer such that up/ua is the normal form of u wrt G. 
   a is the lcm of all integers ua in NF. The elements of NF are sorted with 
   respect to the actual termorder in decreasing order of the first entry. *)
VAR N,L,U,u,ut,ua,up,ups,v,vt,va,vas,vp,w,wt,wa,wp,c,t,x,tx,g,i,is: LIST;
BEGIN
  a := 1; NF := SIL;
  U := EVSSPROD(R);
  WHILE U <> SIL DO
    ADV(U,u,U);
    RRREDTEST(G,u,g,ut);
    IF ut = -1 THEN ua := 1; up := DIPFMO(1,u)
    ELSIF ut = 0 THEN ua := DIPLBC(g); up := DIIPNG(DIPMRD(g)) ELSE
(* u is not in R and not in HM(G) *)
      ua := 1; up := 0; 
      N := NF;
(* find element v in R x R with v*x = u and v not in R *)
      REPEAT
        REPEAT
          ADV(N,L,N);
          FIRST4(L,v,vt,va,vp);
        UNTIL vt <> -1; 
        x := EVDIF(u,v);
      UNTIL (EVSIGN(x) = 1) AND (EVTDEG(x) = 1);
(* for all monomials c*t in vp: up=up+c*("normal-form of t*x") *) 
      N := NF;
      WHILE vp <> 0 DO
        DIPMAD(vp,c,t,vp);
        IF vp = SIL THEN vp := 0 END;
        tx := EVSUM(t,x);
        REPEAT
          ADV(N,L,N);
          FIRST4(L,w,wt,wa,wp);
        UNTIL EQUAL(w,tx) = 1;
        RRIPQSUM(wp,wa,c,up,ua);
      END;
(* up := (1/va) * up *)
      RRIPIQ(va,up,ua);
    END;
    a := ILCM(a,ua);
    NF := COMP(LIST4(u,ut,ua,up),NF);
  END;
END RRINFORM;

PROCEDURE RRISTRCONST(G,R: LIST; VAR U,a,beta: LIST);
(* Real root integral structure constants. 
   G reduced integral groebner basis of a nontrivial zerodimensional ideal, 
   R the set of reduced terms. beta is the integral matrix of combined 
   structure constants beta[u,v] wrt the basis a*R with u from U = R * R and
   v from R. U and the rows of the matrix beta are sorted with respect to the
   actual termorder in increasing order. *)
VAR NF,L,u,ut,ua,up,uv,c,k,t,V,v: LIST;
BEGIN
  U := SIL; beta := SIL;
  RRINFORM(G,R,a,NF);
  WHILE NF <> SIL DO
    ADV(NF,L,NF);
    FIRST4(L,u,ut,ua,up);
    k := IQ(a,ua);
(* convert polynomial to integer vector *)
    uv := SIL; V := CINV(R);
    WHILE up <> 0 DO
      DIPMAD(up,c,t,up);
      IF up = SIL THEN up := 0 END;
      ADV(V,v,V);
      WHILE EQUAL(v,t) = 0 DO ADV(V,v,V); uv := COMP(0,uv) END;
      uv := COMP(IPROD(k,c),uv);
    END; 
    WHILE V <> SIL DO ADV(V,v,V); uv := COMP(0,uv) END;
    U := COMP(u,U);
    beta := COMP(uv,beta);
  END;
END RRISTRCONST;

PROCEDURE RRIVARMATRICES(G,R,U,beta: LIST; VAR al,L: LIST);
(* Real root integral multiplication matrices of variables.
   G reduced integral groebner basis  of a nontrivial zerodimensional ideal. 
   R is the set of reduced terms in increasing order, U= R * R and beta is the
   set of combined structure constants wrt c*R for some nonzero integer c.
   al=(a(1),...,a(n)) is a list of integers and L is a list of entries of the 
   form (1,M(i)) and M(i) is the matrix of multiplication with a(i)*X(i) wrt 
   c*R. *)
VAR MXi,ai,i,j,n,s,c,t,f,g: LIST;
BEGIN
  L := SIL; al := SIL;
  n := LENGTH(DIPEVL(FIRST(G)));
  FOR i := n TO 1 BY -1 DO
    EVCADD(VEL(0,n),i,1,t,j);
    RRREDTEST(G,t,g,s);
    IF s = -1 THEN MXi := RRMMULT(t,R,U,beta); ai := 1 ELSE
      MXi := SIL; ai := DIPLBC(g); f := DIIPNG(DIPMRD(g));
      WHILE f <> 0 DO
        DIPMAD(f,c,t,f);
        IF f = SIL THEN f := 0 END;
        MXi := IMSUM(MXi,ISMPROD(RRMMULT(t,R,U,beta),c));
    END; END;
    al := COMP(ai,al);
    L := COMP(LIST2(1,MXi),L);
  END;
END RRIVARMATRICES;

PROCEDURE RRIUPDATE(i,M1,M2: LIST; VAR l,ls: LIST);
(* Real root integral update. Subroutine of RRIPOLMATRIX. *)
VAR j,M: LIST;
BEGIN
  WHILE (l <> SIL) AND (FIRST(l) < i) DO
    ADV2(l,j,M,l);
    ls := COMP2(M,j,ls);
  END;
  IF (l = SIL) OR (FIRST(l) > i) THEN
    M := IMPROD(M1,M2);
    l := COMP2(i,M,l);
  END; 
END RRIUPDATE;

PROCEDURE RRIPOLMATRIX(R,h,f,fl: LIST; VAR Mh,L: LIST);
(* Real root integral polynomial matrix. 
   R is the set of reduced terms in increasing order, 
   h is a polynomial of domain D, f is a positive integer, fl=(f(1),...,f(n))
   is a list of positive integers, L contains nonempty lists L(i) of the form
   j(1),M(1),j(2),M(2),...,j(k),M(k) with 1=j(1)<j(2)<...<j(k) and M(l) is the
   integral matrix of multiplikation with (f*f(i)*X(i))**j(l) for the variable
   X(i). L is extended with new calculated matrices. 
   If d(i) is the maximal degree in the variable X(i) and d is the maximal 
   total degree of the terms of the polynomial h, then Mh is the integral 
   matrix of multiplication with (f**d)*(f(1)**d(1))*...*(f(1)**d(1)) * h. *)
VAR Mt,Ls,l,ls,A,a,B,b,i,k,p,c,t,hs,d,dl,di,dls,fi,fls: LIST;
BEGIN
  Mh := SIL;
  IF h = 0 THEN RETURN END;
  p := LENGTH(R);
(* compute the maximal total-degree d of h and the *)
(* list dl of maximal degrees in the variable X(i) *)
  hs := h;
  DIPMAD(hs,c,dl,hs);
  IF hs = SIL THEN hs := 0 END;
  d := EVTDEG(dl);
  WHILE hs <> 0 DO
    DIPMAD(hs,c,t,hs);
    IF hs = SIL THEN hs := 0 END;
    dl := EVLCM(dl,t);
    d := IMAX(d,EVTDEG(t));
  END;
(* compute the integer matrix for multiplication with h *)
  WHILE h <> 0 DO
    DIPMAD(h,c,t,h);
    IF h = SIL THEN h := 0 END;
    IF f <> 1 THEN c := IPROD(c,IEXP(f,d-EVTDEG(t))) END;
    Mt := IUM(p,p); 
    Ls := SIL;
    dls := dl; fls := fl;
    WHILE L <> SIL DO
      ADV(L,l,L); ADV(t,k,t); ADV(dls,di,dls); ADV(fls,fi,fls);
      IF fi <> 1 THEN c := IPROD(c,IEXP(fi,di-k)) END;
      IF k <> 0 THEN
        ls := SIL;
        a := 0; A := IUM(p,p);
        b := FIRST(l); B := SECOND(l);
        WHILE k <> 0 DO
          WHILE MASEVEN(k) DO
            b := 2*b; k := k DIV 2;
            RRIUPDATE(b,B,B,l,ls);
            B := SECOND(l);
          END;
          a := a+b; k:= k-1;
          RRIUPDATE(a,A,B,l,ls);
          A := SECOND(l);
        END;
        Mt := IMPROD(Mt,A);
        l := CONC(INV(ls),l);
      END;
      Ls := COMP(l,Ls);
    END;
    Mh := IMSUM(Mh,ISMPROD(Mt,c));
    L := INV(Ls);
  END;
END RRIPOLMATRIX;

PROCEDURE RRIQUADFORM(R,U,beta,Mh: LIST): LIST;
(* Real root integral quadratic form. 
   R is the set of reduced terms in increasing order, U = R * R and beta is 
   the set of integral combined structure constants wrt a*R for some nonzero
   integer a. Mh is the integral matrix of multiplication with c*h for some
   positive constant c represented columnwise. The matrix Q = (q(i,j)) with 
   q(i,j) = tr(M(h)*M(v(i))*M(v(j)) and v(i),v(j) from a*R is computed. *)
VAR Q,V,v,W,w,tab,t,p,betah,Mhv,i,j,e,q,s,u: LIST;
BEGIN
  tab := SIL;
  p := LENGTH(R);
  Q := VEL(VEL(0,p),p);
  betah := IMPROD(beta,Mh);
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
        q := IMPTRACE(Mhv,RRMMULT(w,R,U,beta));
        tab := COMP2(u,q,tab);
      END;
      Q := MSET(Q,i,j,q);
      IF j <> i THEN Q := MSET(Q,j,i,q) END; 
    END;
  END;
  RETURN(Q);
END RRIQUADFORM;

PROCEDURE RRICOUNT(G,H,v,tf: LIST): LIST;
(* Real root integral count. 
   G is an integral reduced groebner basis of a zerodimensional ideal I, 
   H is a list of polynomials of length s. v is a vector of signs with length 
   not greater than s. tf is the trace-flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of I wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v,
   then the empty list is returned. *)
VAR ZNL,R,E,U,beta,s,S,S1,S2,m,m0,m1,m2,md,mh,h,N,A,W,L,a,al,p,i: LIST;
BEGIN
  R := RRREDTERMS(G); p := LENGTH(R); E := IUM(p,p);
  RRISTRCONST(G,R,U,a,beta);
  s := ISIG(RRIQUADFORM(R,U,beta,E));
  IF s = 0 THEN RETURN(SIL) END;
  IF H = SIL THEN ZNL := LIST1(LIST2(s,SIL)); RETURN(ZNL) END;
  S := LIST1(s); m := LIST1(E); N := LIST1(SIL);
  A := LIST1(LIST1(1)); W := LIST3(LIST3(1,1,1),LIST3(-1,0,1),LIST3(1,0,1));
  RRIVARMATRICES(G,R,U,beta,al,L);
  i := 0;
  REPEAT
    ADV(H,h,H); i := i+1;
    IF tf = 1 THEN BLINES(1); 
                   SWRITE("Condition No. "); OWRITE(i); BLINES(0) END;
    RRIPOLMATRIX(R,h,a,al,mh,L);
(* expanding the system *)
    N := RRVTEXT(N,LIST3(-1,0,1));
    A := IMRTPROD(W,A);
    S1 := SIL; S2 := SIL; m1 := SIL; m2 := SIL; m0 := m;
    WHILE m0 <> SIL DO
      ADV(m0,md,m0);
      md := IMPROD(md,mh); m1 := COMP(md,m1);
      s := ISIG(RRIQUADFORM(R,U,beta,md)); S1 := COMP(s,S1);
      md := IMPROD(md,mh); m2 := COMP(md,m2);
      s := ISIG(RRIQUADFORM(R,U,beta,md)); S2 := COMP(s,S2);
    END;
    S := CONC(S,CONC(INV(S1),INV(S2)));
    m := CONC(m,CONC(INV(m1),INV(m2)));
(* solving the linear equation A*Z=S and reduce the system *)
    ZNL := RRCSR(i,v,tf,A,N,S,m);
  UNTIL (ZNL = SIL) OR (H = SIL);
  RETURN(ZNL);
END RRICOUNT;

END RRINT.

(* -EOF- *)
