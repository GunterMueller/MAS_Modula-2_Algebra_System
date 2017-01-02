(* ----------------------------------------------------------------------------
 * $Id: RRUADOM.mi,v 1.1 1994/03/11 15:21:52 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: RRUADOM.mi,v $
 * Revision 1.1  1994/03/11  15:21:52  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE RRUADOM;
(* Real Root Univariate Arbitrary Domain Implementation Module *)

(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, ADV, COMP, INV, FIRST, LIST1, LENGTH;

FROM SACLIST IMPORT CINV, SUFFIX, REDUCT, CONC, LIST2, LIST3, MEMBER, OWRITE;

FROM DIPC IMPORT DIPDEG, DIPMAD, DIPMRD, DIPFMO;

FROM DIPADOM IMPORT DIPNEG, DIPQR, DIPROD;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM MASADOM IMPORT ADFI, ADSIGN, ADSUM;

FROM LINALG IMPORT ADVVSUM, ADVSVPROD, ADSIG, IMRTPROD;

FROM RRADOM IMPORT RRVTEXT, RRCSR;

CONST rcsidi = "$Id: RRUADOM.mi,v 1.1 1994/03/11 15:21:52 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

PROCEDURE RRUADPOLTOVEC(D,g,d: LIST): LIST;
(* Real root univariate arbitrary domain polynomial to vector. 
   g is an univariate polynomial of domain D with degree less than d. 
   If a(i) is the coefficient of X**i in g then the list (a(p-1),...,a(0)) 
   is returned. *)
VAR v,a,t: LIST;
BEGIN
  v := SIL; d:= d-1;
  WHILE g <> 0 DO
    DIPMAD(g,a,t,g);
    IF g = SIL THEN g := 0 END;
    WHILE d > FIRST(t) DO v := COMP(ADFI(D,0),v); d:= d-1 END;
    v := COMP(a,v); d := d-1;
  END; 
  WHILE d >= 0 DO v := COMP(ADFI(D,0),v); d:= d-1 END;
  RETURN(INV(v));
END RRUADPOLTOVEC;

PROCEDURE RRUADSTRCONST(D,f,h: LIST): LIST;
(* Real root univariate arbitrary domain structure constants. 
   f and h are univariate polynomials of domain D. 
   f is monic with degree p > 0. A matrix beta with entries beta[i,j] 
   from D for 0 le i le p-1 and 0 le j le 3*p-3 is created, such that 
   h * X**j = beta[0,j]+beta[1,j]*X+...+beta[p-1,j]X**(p-1) modulo f. 
   beta is represented columnwise. *)
VAR beta,p,i,v,w,b,q,r: LIST;
BEGIN
  beta := SIL; 
  p := DIPDEG(f);
  IF p <= 0 THEN RETURN(beta) END;
(* r = h modulo f *)
  DIPQR(h,f,q,r);
(* create vector representation of -red(f) and r *)
  v := RRUADPOLTOVEC(D,DIPNEG(DIPMRD(f)),p);
  w := RRUADPOLTOVEC(D,r,p);
(* compute structure constants *)
  beta := LIST1(CINV(w));
  FOR i := 1 TO 3*p-3 DO
    ADV(w,b,w);
    w := SUFFIX(w,ADFI(D,0));
    IF ADSIGN(b) <> 0 THEN
      w := ADVVSUM(w,ADVSVPROD(v,b));
    END;
    beta := COMP(CINV(w),beta);
  END;
  beta := INV(beta);
  RETURN(beta);
END RRUADSTRCONST;

PROCEDURE RRUADQUADFORM(beta: LIST): LIST;
(* Real root univariate arbitrary domain quadratic form. 
   beta is the set of structure constants as computed by RRUADSTRCONST.
   Let s(k) = tr(M(h)*M(X**k))=beta[0,k]+beta[1,k+1]+...+beta[p-1,k+p-1].
   The matrix Q=(q(i,j)) with q(i,j) = s(i+j-2) is computed. *)
VAR Q,s,v,vs,w,x,y,i,p: LIST;
BEGIN
  Q := SIL; s := SIL;
  IF beta = SIL THEN RETURN(Q) END;
  p := LENGTH(FIRST(beta)); i := 0; vs := SIL;
(* create the list s containing the sums of the diagonal elements of beta *)
  WHILE beta <> SIL DO
    ADV(beta,w,beta); i := i+1; v := INV(vs);
    IF i >= 2*p THEN w := REDUCT(w,i+1-2*p); vs := SIL;
                ELSE ADV(w,y,w); vs := LIST1(y) END;
    WHILE v <> SIL DO
      ADV(v,x,v); ADV(w,y,w);
      vs := COMP(ADSUM(x,y),vs);
    END;
    IF i >= p THEN ADV(vs,x,vs); s := COMP(x,s); END;
  END;
(* creating the matrix Q *)
  v := SIL; i := 0;
  WHILE s <> SIL DO
    ADV(s,x,s); i := i+1; vs := SIL;
    WHILE v <> SIL DO
      ADV(v,y,v); y := COMP(x,y);
      vs := COMP(y,vs);
    END;
    IF i <= p THEN vs := COMP(LIST1(x),vs) END;
    v := INV(vs);
    IF i >= p THEN ADV(v,y,v); Q := COMP(y,Q) END;
  END;
  RETURN(Q);
END RRUADQUADFORM;

PROCEDURE RRUADCOUNT(D,f,H,v,tf: LIST): LIST;
(* Real root univariate arbirary domain count. 
   f is a monic univariate polynomial of domain D with degree p > 0. 
   H is a list of univariate polynomials of length s. v is a vector of signs 
   with length not greater than s. tf is the trace flag.
   ZNL is a list of pairs (z,n) with n is an element of {-1,0,+1}**s and z > 0
   is the number of real zeroes of f wrt the sign condition n for the elements
   of H. ZNL is sorted wrt the invers lexicographical order of the n. If there
   does not exist any real zero or a zero satisfiing the sign condition v,
   then the empty list is returned. *)
VAR ZNL,e,S,S1,S2,g,g0,g1,g2,gd,q,h,N,A,W,s,i: LIST;
BEGIN
  e := DIPFMO(ADFI(D,1),LIST1(0));  (* e = polynomial(1) *)
  s := ADSIG(D,RRUADQUADFORM(RRUADSTRCONST(D,f,e)));
  IF s = 0 THEN RETURN(SIL) END;
  IF H = SIL THEN ZNL := LIST1(LIST2(s,SIL)); RETURN(ZNL) END;
  S := LIST1(s); g := LIST1(e); N := LIST1(SIL);
  A := LIST1(LIST1(1)); W := LIST3(LIST3(1,1,1),LIST3(-1,0,1),LIST3(1,0,1));
  i := 0;
  REPEAT
    ADV(H,h,H); i := i+1;
    IF tf = 1 THEN BLINES(1); 
                   SWRITE("Condition No. "); OWRITE(i); BLINES(0) END;
(* expanding the system *)
    N := RRVTEXT(N,LIST3(-1,0,1));
    A := IMRTPROD(W,A);
    S1 := SIL; S2 := SIL; g1 := SIL; g2 := SIL; g0 := g;
    WHILE g0 <> SIL DO
      ADV(g0,gd,g0);
      DIPQR(DIPROD(gd,h),f,q,gd); g1 := COMP(gd,g1);
      s := ADSIG(D,RRUADQUADFORM(RRUADSTRCONST(D,f,gd))); S1 := COMP(s,S1);
      DIPQR(DIPROD(gd,h),f,q,gd); g2 := COMP(gd,g2);
      s := ADSIG(D,RRUADQUADFORM(RRUADSTRCONST(D,f,gd))); S2 := COMP(s,S2);
    END;
    S := CONC(S,CONC(INV(S1),INV(S2)));
    g := CONC(g,CONC(INV(g1),INV(g2)));
(* solving the linear equation A*Z=S and reduce the system *)
    ZNL := RRCSR(i,v,tf,A,N,S,g);
  UNTIL (ZNL = SIL) OR (H = SIL);
  RETURN(ZNL);
END RRUADCOUNT;

END RRUADOM.

(* -EOF- *)
