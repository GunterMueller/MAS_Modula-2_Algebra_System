(* ----------------------------------------------------------------------------
 * $Id: LINALG.mi,v 1.1 1994/03/11 15:21:46 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: LINALG.mi,v $
 * Revision 1.1  1994/03/11  15:21:46  pesch
 * Counting real roots of multivariate polynomials, Diplomarbeit F. Lippold
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE LINALG;
(* Linear algebra implementation module *)

(* Import lists and declarations *)

FROM MASSTOR IMPORT LIST, SIL, COMP, INV, ADV, LENGTH, FIRST, LIST1, RED;

FROM SACLIST IMPORT LELT, SUFFIX;

FROM MASADOM IMPORT ADFI, ADPROD, ADSUM, ADSIGN, ADNEG, ADQUOT, ADWRIT;

FROM SACI IMPORT ISUM, IQ, ISIGNF, INEG;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM LINALGI IMPORT IVSPROD, IMPROD;

FROM LINALGRN IMPORT MTRANS;

FROM MASI IMPORT IPROD;

CONST rcsidi = "$Id: LINALG.mi,v 1.1 1994/03/11 15:21:46 pesch Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";

(* ---------------------------------------------------------------------- *)
(* Arbitrary domain linear algebra *)

PROCEDURE ADUM(D,n: LIST): LIST;
(* Arbitrary domain unit matrix. 
   n is an integer. The (n x n) unit matrix of domain D is returned. *)
VAR C,c,i,j,e: LIST;
BEGIN
  C := SIL; i := 0;
  WHILE i < n DO
    c := SIL; i := i + 1; j := 0;
    WHILE j < n DO
      j := j + 1;
      IF i = j THEN e := ADFI(D,1) ELSE e := ADFI(D,0) END;
      c := COMP(e,c);
    END;
    c := INV(c); C := COMP(c,C);
  END;
  C := INV(C); RETURN(C);
END ADUM;

PROCEDURE ADVSPROD(D,A,B: LIST): LIST;
(* Arbitrary domain vector scalar product. 
   A and B are vectors of the domain D. The arbitrary domain value 
   C = a1*b1 + ... + an*bn is returned. *)
VAR a,b,c,C: LIST;
BEGIN
  C := ADFI(D,0);
  WHILE A <> SIL DO
    ADV(A, a, A);
    ADV(B, b, B);
    c := ADPROD(a,b);
    C := ADSUM(c,C);
  END;
  RETURN(C);
END ADVSPROD;

PROCEDURE ADVSVPROD(A,b: LIST): LIST;
(* Arbitrary domain vector scalar vector product. 
   A is an arbitrary domain vector and b is a number of the same domain. 
   The arbitrary domain vector C = (a1*b, ..., an*b) is returned. *)
VAR a,c,C: LIST;
BEGIN
  C := SIL;
  WHILE A <> SIL DO
    ADV(A, a, A);
    c := ADPROD(a,b);
    C := COMP(c,C);
  END;
  C := INV(C); RETURN(C);
END ADVSVPROD;

PROCEDURE ADVVSUM(A,B: LIST): LIST;
(* Arbitrary domain vector vector sum. 
   A and B are arbitrary domain vectors. The arbitrary domain vector 
   C = (a1+b1, ..., an+bn) is returned. *)
VAR a,b,c,C: LIST;
BEGIN
  C := SIL;
  WHILE A <> SIL DO
    ADV(A, a, A);
    ADV(B, b, B);
    c := ADSUM(a,b);
    C := COMP(c,C);
  END;
  C := INV(C); RETURN(C);
END ADVVSUM;

PROCEDURE ADSMPROD(A,b: LIST): LIST;
(* Arbitrary domain scalar and matrix product.
   A is a arbitrary domain matrix. b is a arbitrary domain number. 
   The arbitrary domain matrix C = A * b is returned. *)
VAR a,c,C: LIST;
BEGIN
  IF A = SIL THEN RETURN(A) END;
  C := SIL;
  WHILE A <> SIL DO
    ADV(A, a, A);
    c := ADVSVPROD(a,b);
    C := COMP(c,C);
  END;
  C := INV(C); RETURN(C);
END ADSMPROD;

PROCEDURE ADMSUM(A,B: LIST): LIST;
(* Arbitrary domain matrix sum. 
   A and B are arbitrary domain matrices. The arbitrary domain matrix 
   C = A + B is returned. *)
VAR a,b,c,C: LIST;
BEGIN
  IF A = SIL THEN RETURN(B) END;
  IF B = SIL THEN RETURN(A) END;
  C := SIL;
  WHILE A <> SIL DO
    ADV(A, a, A);
    ADV(B, b, B);
    c := ADVVSUM(a,b);
    C := COMP(c,C);
  END;
  C := INV(C); RETURN(C);
END ADMSUM;

PROCEDURE ADMPROD(D,A,B: LIST): LIST;
(* Arbitrary domain matrix product. 
   A and B are matrices of domain D. The matrix C = A * B of domain D is 
   returned, if the number of columns of A is equal to the number of rows 
   of B, otherwise the empty matrix is returned. *)
VAR H1,H2,C,C1,a,c,BP,BT,b: LIST;
BEGIN
  C := SIL;
  IF A = SIL THEN RETURN(C) END;
  IF B = SIL THEN RETURN(C) END;
  H1 := LENGTH(FIRST(A));
  H2 := LENGTH(B);
  IF H1 <> H2 THEN RETURN(C) END;
  BT:=MTRANS(B);
  WHILE A <> SIL DO ADV(A, a, A);
    C1:=SIL; BP:=BT;
    WHILE BP <> SIL DO ADV(BP,b,BP);
      c:=ADVSPROD(D,a,b);   
      C1:=COMP(c,C1);
    END;
    C1 := INV(C1); C := COMP(C1,C);
  END;
  C := INV(C); RETURN(C);
END ADMPROD;

PROCEDURE ADVWRITE(A: LIST);
(* Arbitrary domain vector write. 
   A is an arbitrary domain vector. A is written to the output stream. *)
VAR a : LIST;
BEGIN
  SWRITE("(");
  WHILE A <> SIL DO
    ADV(A, a, A);
    ADWRIT(a);
    IF A <> SIL THEN SWRITE(",") END;
  END; 
  SWRITE(")");
END ADVWRITE;

PROCEDURE ADMWRITE(A: LIST);
(*Arbitrary domain matrix write. 
  A is an arbitrary domain  matrix. A is written to the output stream. *)
VAR a : LIST;
BEGIN
  BLINES(0); SWRITE("(");
  WHILE A <> SIL DO
    ADV(A, a, A);
    ADVWRITE(a);
    IF A <> SIL THEN SWRITE(", "); BLINES(0) END;
  END;
  SWRITE(")"); BLINES(0);
END ADMWRITE;

PROCEDURE ADMTRACE(D,A: LIST): LIST;
(* Arbitrary domain matrix trace. 
   A is a matrix of domain D. The trace of A is returned. *)
VAR tr,i,a: LIST;
BEGIN
  tr := ADFI(D,0); i := 0;
  WHILE A <> SIL DO
    ADV(A,a,A); i := i + 1;
    tr := ADSUM(tr,LELT(a,i));
  END;
  RETURN(tr);
END ADMTRACE;

PROCEDURE ADMPTRACE(D,A,B: LIST): LIST;
(* Arbitrary domain matrix product trace. 
   A and B are matrices of domain D. The trace of A*B is returned. *)
VAR tr,a,b,H1,H2,BT: LIST;
BEGIN
  tr := ADFI(D,0);
  IF (A = SIL) OR (B = SIL) THEN RETURN(tr) END;
  H1 := LENGTH(FIRST(A));
  H2 := LENGTH(B);
  IF H1 <> H2 THEN RETURN(tr) END;
  BT:=MTRANS(B);
  WHILE A <> SIL DO 
    ADV(A, a, A);
    ADV(BT,b,BT);
    tr := ADSUM(tr,ADVSPROD(D,a,b));   
  END;
  RETURN(tr);
END ADMPTRACE;

PROCEDURE ADCHARPOL(D,Q: LIST): LIST;
(* Arbitrary domain characteristic polynomial. 
   Q is a p x p Matrix of domain D. The list al=(a(0),...,a(p)) is created 
   such that a(i) from D is the coefficient of X^(p-i) in det(XE-Q). *)
VAR L,l,A,B,sl,s,al,a,k,p: LIST;
BEGIN
  al := LIST1(ADFI(D,1));
  IF Q = SIL THEN RETURN(al) END;
  p := LENGTH(Q);
  L := SIL; A := Q;
  k := 1;
  s := ADMTRACE(D,A);
  sl := LIST1(s); 
  a := ADNEG(s);
  al := SUFFIX(al,a);
  WHILE k*k < p DO
    k := k+1;
    L := COMP(A,L);
    A := ADMPROD(D,A,Q);
    s := ADMTRACE(D,A);
    sl := COMP(s,sl);
    a := ADQUOT(ADVSPROD(D,sl,al), ADFI(D,-k));
    al := SUFFIX(al,a);
  END;
  B := A;
  L := INV(L);
  l := L;
  WHILE k < p DO
    k := k+1;
    IF l = SIL THEN
      B := ADMPROD(D,B,A);
      s := ADMTRACE(D,B);
      l := L;
    ELSE
      s := ADMPTRACE(D,B,FIRST(l));
      l := RED(l);
    END;
    sl := COMP(s,sl);
    a := ADQUOT(ADVSPROD(D,sl,al), ADFI(D,-k));
    al := SUFFIX(al,a);
  END; 
  RETURN(al); 
END ADCHARPOL;

PROCEDURE ADSIG(D,Q: LIST): LIST;
(* Arbitrary domain signature. 
   Q is a symmetric p x p Matrix of domain D. The signature of Q ist returned.
   ADCHARPOL is used. *)
VAR al,p,n,a,s,sp,sn,t: LIST;
BEGIN
  p := 0; n := 0;
  al := ADCHARPOL(D,Q);
  ADV(al,a,al);
  sp := ADSIGN(a); sn := sp; t := 1;
  WHILE al <> SIL DO
    ADV(al,a,al); t := -t; s := ADSIGN(a);
    IF s <> 0 THEN
      IF sp <> s   THEN p := p + 1; sp := s   END;
      IF sn <> s*t THEN n := n + 1; sn := s*t END; 
    END; 
  END;
  RETURN(p-n);
END ADSIG;

(* ---------------------------------------------------------------------- *)
(* Integer linear algebra *)

PROCEDURE IMTRACE(A: LIST): LIST;
(* Integral matrix trace. 
   A is an integral matrix. The trace of A is returned. *)
VAR tr,i,a: LIST;
BEGIN
  tr := 0; i := 0;
  WHILE A <> SIL DO
    ADV(A,a,A); i := i + 1;
    tr := ISUM(tr,LELT(a,i));
  END;
  RETURN(tr);
END IMTRACE;

PROCEDURE IMPTRACE(A,B: LIST): LIST;
(* Integral matrix product trace. 
   A and B are integral matrices. The trace of the matrix A*B is returned. *)
VAR tr,a,b,H1,H2,BT: LIST;
BEGIN
  tr := 0;
  IF (A = SIL) OR (B = SIL) THEN RETURN(tr) END;
  H1 := LENGTH(FIRST(A));
  H2 := LENGTH(B);
  IF H1 <> H2 THEN RETURN(tr) END;
  BT:=MTRANS(B);
  WHILE A <> SIL DO 
    ADV(A, a, A);
    ADV(BT,b,BT);
    tr := ISUM(tr,IVSPROD(a,b));   
  END;
  RETURN(tr);
END IMPTRACE;

PROCEDURE ICHARPOL(Q: LIST): LIST;
(* Integral matrix characteristic polynomial. 
   Q is an integral p x p Matrix. The list al = (a(0),...,a(p)) of integers 
   is created with a(i) is the coefficient of X^(p-i) in det(XE-Q). *)
VAR L,l,A,B,sl,s,al,a,k,p: LIST;
BEGIN
  al := LIST1(1);
  IF Q = SIL THEN RETURN(al) END;
  p := LENGTH(Q);
  L := SIL; A := Q;
  k := 1;
  s := IMTRACE(A);
  sl := LIST1(s); 
  a := INEG(s);
  al := SUFFIX(al,a);
  WHILE k*k < p DO
    k := k+1;
    L := COMP(A,L);
    A := IMPROD(A,Q);
    s := IMTRACE(A);
    sl := COMP(s,sl);
    a := IQ(IVSPROD(sl,al),-k);
    al := SUFFIX(al,a);
  END;
  B := A;
  L := INV(L);
  l := L;
  WHILE k < p DO
    k := k+1;
    IF l = SIL THEN
      B := IMPROD(B,A);
      s := IMTRACE(B);
      l := L;
    ELSE
      s := IMPTRACE(B,FIRST(l));
      l := RED(l);
    END;
    sl := COMP(s,sl);
    a := IQ(IVSPROD(sl,al),-k);
    al := SUFFIX(al,a);
  END; 
  RETURN(al); 
END ICHARPOL;

PROCEDURE ISIG(Q: LIST): LIST;
(* Integral matrix signature. 
   Q is a symmetric integral p x p Matrix. The signature of Q ist returned.
   ICHARPOL is used *)
VAR al,p,n,a,s,sp,sn,t: LIST;
BEGIN
  p := 0; n := 0;
  al := ICHARPOL(Q);
  ADV(al,a,al);
  sp := ISIGNF(a); sn := sp; t := 1;
  WHILE al <> SIL DO
    ADV(al,a,al); t := -t; s := ISIGNF(a);
    IF s <> 0 THEN
      IF sp <> s   THEN p := p + 1; sp := s   END;
      IF sn <> s*t THEN n := n + 1; sn := s*t END; 
    END; 
  END;
  RETURN(p-n);
END ISIG;

PROCEDURE IMRTPROD(A,B: LIST): LIST;
(* Integral matrix right tensor product. 
   A and B are integral matrices. The matrix C is constructed by 
   replacing every entry a(i,j) of A by the matrix a(i,j)*B. *) 
VAR C,c,a,ar,ars,Bs,b,br,brs: LIST;
BEGIN
  C := SIL;
  IF (A = SIL) OR (B = SIL) THEN RETURN(C) END;
  WHILE A <> SIL DO
    ADV(A,ar,A);
    Bs := B;
    WHILE Bs <> SIL DO
      ADV(Bs,br,Bs);
      c := SIL;
      ars := ar;
      WHILE ars <> SIL DO
        ADV(ars,a,ars);
        brs := br;
        WHILE brs <> SIL DO
          ADV(brs,b,brs);
          c := COMP(IPROD(a,b),c);
      END; END;
      c := INV(c); C := COMP(c,C);
  END; END;
  C := INV(C);
  RETURN(C);
END IMRTPROD;

END LINALG.

(* -EOF- *)
