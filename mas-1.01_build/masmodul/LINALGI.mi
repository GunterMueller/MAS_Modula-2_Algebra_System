(* ----------------------------------------------------------------------------
 * $Id: LINALGI.mi,v 1.6 1995/11/05 09:23:13 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: LINALGI.mi,v $
 * Revision 1.6  1995/11/05 09:23:13  kredel
 * Fixed comments and code of: IVSVSUM, ISMPROD, IMDETL, IMDET, IMGELUD, IMLT.
 *
 * Revision 1.5  1994/03/11  15:43:31  pesch
 * Corrections by Lippold.
 *
 * Revision 1.4  1992/10/15  16:29:15  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/08/24  10:05:42  kredel
 * Corrected error in IMDET: wrong check for square matrix.
 *
 * Revision 1.2  1992/02/12  17:33:09  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE LINALGI;

(* MAS Linear Algebra Integer Implementation Module. *)


(*-------------------------------------------------------------------------

Implementation Module: Linear Algebra Integer 

Programmierpraktikum SS 1990 JUERGEN MUELLER, Heinz Kredel 

Contents: Standartoperations for matrix and vector manipulations,  
          Gaussian elimination, LU-Decomposition, Solve,    
          Inversion, Nullspace, Determinant. 

Stand : 27.09.90, Juergen Mueller                         
        from then date of the file, Heinz Kredel             

Remarks: A vector is represented as a list of elements.
         The elements may be integers or rational numbers.
         A matix is represented as a list of vectors.
         In most circumstances these vectors are interpreted row 
         vectors, but they can also be interpreted as column vectors.

--------------------------------------------------------------------------*)


  FROM MASELEM IMPORT GAMMAINT, MASMIN, MASEVEN;

  FROM MASBIOS IMPORT SWRITE, BLINES;

  FROM MASSTOR IMPORT LIST, SIL, BETA,
                      ADV, FIRST, RED, INV, LIST1, COMP, LENGTH;

  FROM MASERR IMPORT ERROR, severe;

  FROM SACLIST IMPORT OWRITE, LIST2, FIRST2, CCONC, CINV, CONC;

  FROM SACI IMPORT IWRITE, IABSF, ISUM, 
                   IPROD, INEG, ICOMP, ISIGNF, 
                   ILCM, IQ, IQR, IMIN, IDIF, IMAX;

  FROM SACRN IMPORT RNDEN, RNNUM, RNRED, RNINT,
                    RNPROD, RNQ, RNSUM, RNDIF;

  FROM LINALGRN IMPORT MTRANS, MFILL, MDELCOL, 
                       RNMUT, RNUM, RNMUNS, RNMFIM, RNVFIV;

CONST rcsidi = "$Id: LINALGI.mi,v 1.6 1995/11/05 09:23:13 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



TYPE F2 = PROCEDURE(LIST,LIST): LIST;

(*The TDI compiler accepts only global functions in expressions. *)   

PROCEDURE ium(i,j: LIST): LIST; (*unit matrix*)
BEGIN IF i = j THEN RETURN(1) ELSE RETURN(0) END;
(*9*) END ium;


(*---------------- arbitrary matices --------------------*)

PROCEDURE MAT(f: F2; m, n: LIST): LIST;
(*Matrix. An (m x n) matrix with elements given by f(i,j) is returned. *)
VAR   i, j, V, M, v: LIST;
BEGIN
(*1*) M:=SIL;
      IF (m <= 0) OR (n <= 0) THEN RETURN(M) END;
(*2*) i:=0;
      WHILE i < m DO i:=i+1; j:=0; V:=SIL; 
            WHILE j < n DO j:=j+1;
                  v:=f(i,j); V:=COMP(v,V) END;
            V:=INV(V); M:=COMP(V,M);
            END;
(*4*) M:=INV(M); RETURN(M);
(*9*) END MAT;


(*---------------- integer matices --------------------*)


PROCEDURE IUM(m, n: LIST): LIST;
(*Integer unit matrix. m, n integer. An (m x n) integer unit 
matrix is returned. *)
BEGIN
(*1*) RETURN(MAT(ium,m,n));
(*9*) END IUM;


PROCEDURE IVWRITE(A : LIST);
(*Integer vector write. A is an integer vector. A is written 
to the output stream. *)
VAR   a : LIST;
BEGIN
(*1*) SWRITE("(");
(*2*) WHILE A#SIL DO
            ADV(A, a, A);
            IWRITE(a);
            IF A#SIL THEN SWRITE(", ") END;
            END;
(*3*) SWRITE(")");
(*9*) END IVWRITE;


PROCEDURE IMWRITE(A : LIST);
(*Integer matrix write. A is an integer matrix. A is written 
to the output stream. *)
VAR   a : LIST;
BEGIN
(*1*) BLINES(0); SWRITE("(");
(*2*) WHILE A#SIL DO
            ADV(A, a, A);
            IVWRITE(a);
            IF A#SIL THEN SWRITE(", "); BLINES(0) END;
            END;
(*3*) SWRITE(")"); BLINES(0);
(*9*) END IMWRITE;


PROCEDURE IKM(A, B : LIST): LIST;
(*Integer vector component product. IKM returns the difference of 
the product of the integer vector A with FIRST(B) and the product of 
the integer vector B with FIRST(A). C = A * FIRST(B) - B * FIRST(A).
C is an integer vector. *)
VAR   a, b, c, d, C, D : LIST;
BEGIN
(*1*) C := SIL; D := SIL;
      a := FIRST(A); b := FIRST(B);
(*2*) IF a # LIST(0) THEN
         IF b # LIST(0) THEN
            WHILE A # SIL  DO
                  ADV(A, c, A);
                  c := IPROD(c,b);
                  C := COMP(c,C);
                  ADV(B, d, B);
                  d := IPROD(d,a);
                  D := COMP(d,D);
                  END;
            A := INV(C); B := INV(D);
            B := IVVDIF(B,A);
            END;
         END;
(*3*) RETURN(B);
(*9*) END IKM;


PROCEDURE IVVDIF(A, B : LIST): LIST;
(*Integer vector difference. A and B are integer vectors. 
The integer vector C = A - B is returned. *)
VAR   a, b, c, C, test : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := IDIF(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVVDIF;


PROCEDURE IVVSUM(A, B : LIST): LIST;
(*Integer vector vector sum. A and B are integer vectors. 
An integer vector C = A + B is returned. *)
VAR   a, b, c, C, test : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := ISUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVVSUM;


PROCEDURE IVSVSUM(A, B : LIST): LIST;
(*Integer vector scalar and vector sum. A and B are integer vectors.
An integer vector C = A + FIRST(B) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL; b:=FIRST(B); 
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := ISUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVSVSUM;


PROCEDURE IVSSUM(A : LIST): LIST;
(*Integer vector scalar sum. A is an integer vector. An integer 
C = a1 + a2 + ... + an is returned. *)
VAR   a, c : LIST;
BEGIN
(*1*) c := 0;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := ISUM(a,c);
            END;
(*3*) RETURN(c);
(*9*) END IVSSUM;


PROCEDURE IVSVPROD(A, B : LIST): LIST;
(*Integer vector scalar and vector product. A and B are integer vectors.
An integer vector C = (a1*FIRST(B), ..., an*FIRST(B) ) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL; b:=FIRST(B);
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := IPROD(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVSVPROD;


PROCEDURE IVVPROD(A, B : LIST): LIST;
(*Integer vector vectors product. A and B are integer vectors.
An integer vector C = (a1*b1, ..., an*bn) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := IPROD(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVVPROD;


PROCEDURE IVSPROD(A, B : LIST): LIST;
(*Integer vector scalar product. A and B are integer vectors.
An integer C = a1*b1 + ... + an*bn is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := 0;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := IPROD(a,b);
            C := ISUM(c,C);
            END;
(*3*) RETURN(C);
(*9*) END IVSPROD;


PROCEDURE IVMAX(M : LIST): LIST;
(*Integer vector maximum norm. M is an integer vector. 
An integer a = maximum absolute value M(i) is returned. *)
VAR   g, zeile, element, max : LIST;
BEGIN
(*1*) max := 0;
(*2*) WHILE M # SIL DO
            ADV(M, element, M);
            element := IABSF(element);
            max:=IMAX(max,element);  
            END;
(*3*) RETURN(max);
(*9*) END IVMAX;


PROCEDURE IMPROD(A, B : LIST): LIST;
(*Integer matrix product. A and B are integer matrices. 
An integer matrix C = A * B is returned, if the number of 
coloums of A is equal to the number of rows of B, 
otherwise the empty matrix is returned. *)
VAR   H1, H2, C, C1, a, c, BP, BT, b : LIST;
BEGIN
(*1*) C := SIL;
      IF A = SIL THEN RETURN(C) END;
      IF B = SIL THEN RETURN(C) END;
      H1 := LENGTH(FIRST(A));
      H2 := LENGTH(B);
      IF H1 # H2 THEN RETURN(C) END;
(*2*) BT:=MTRANS(B); (*transpose B. *)
      WHILE A # SIL DO ADV(A, a, A);
            C1:=SIL; BP:=BT;
            WHILE BP # SIL DO ADV(BP,b,BP);
                  c:=IVSPROD(a,b);   
                  C1:=COMP(c,C1);
                  END;
            C1 := INV(C1);
            C := COMP(C1,C);
            END;
(*4*) C := INV(C); RETURN(C);
(*9*) END IMPROD;


PROCEDURE ISMPROD(A, B : LIST): LIST;
(*Integer scalar and matrix product. A is an integer matrix. 
B is an integer. An integer matrix C = A * B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN RETURN(A) END;
      C := SIL; b:=LIST1(B);
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := IVSVPROD(a,b); (* geaendert *)
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END ISMPROD;


PROCEDURE IMDIF(A, B : LIST): LIST;
(*Integer matrix difference. A and B are integer matrices. 
An integer matrix C = A - B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN
         B := ISMPROD(B,-1); (*geaendert*)
         RETURN(B);
         END;
      IF B=SIL THEN RETURN(A); END;
      C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := IVVDIF(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IMDIF;


PROCEDURE IMSUM(A, B : LIST): LIST;
(*Integer matrix sum. A and B are integer matrices. 
An integer matrix C = A + B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN RETURN(B) END;
      IF B=SIL THEN RETURN(A) END;
      C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := IVVSUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IMSUM;


PROCEDURE IMMAX(M : LIST): LIST;
(*Integer matrix maximum norm. M is an integer matrix. 
An integer a = maximum absolute value M(i,j) is returned. *)
VAR   g, zeile, element, max : LIST;
BEGIN
(*1*) max := 0;
(*2*) WHILE M # SIL DO
            ADV(M, zeile, M);
            element := IVMAX(zeile);
            max:=IMAX(max,element);  
            END;
(*3*) RETURN(max);
(*9*) END IMMAX;


PROCEDURE IVFRNV(A: LIST): LIST;
(*Integer vector from rational number vector. A is a rational 
number vector. A is muliplied by a common multiple of its 
denominators, then the denominators are removed. An integer 
vector C = lcm(denom(A)) * A is returned.  *)
VAR   AP, BP: LIST;
BEGIN
(*1*) IVFRNV1(A,SIL, AP,BP); RETURN(AP);
(*9*) END IVFRNV;


PROCEDURE IVFRNV1(A, B : LIST; VAR C, D: LIST);
(*Integer vector from rational number vector. A and B are 
rational number vectors. A and B are muliplied by a common 
multiple of their denominators, then the denominators are 
removed. C and D are integer vectors, such that 
C = lcm(denom(A),denom(B))*A and D = lcm(denom(A),denom(B))*B. *)
VAR   ap, bp, d, a, c, b: LIST;
BEGIN
(*1*) C := SIL; D:=SIL;
(*2*) (*determine lcm. *) ap:=A; bp:=B; d:=1;
      WHILE ap # SIL DO ADV(ap, a, ap);
            c := RNDEN(a); d:=ILCM(d,c);
            END;
      WHILE bp # SIL DO ADV(bp, a, bp);
            c := RNDEN(a); d:=ILCM(d,c);
            END;
(*3*) (*clear denominators. *) ap:=A; bp:=B; 
      WHILE ap # SIL DO ADV(ap, a, ap);
            c := RNDEN(a); b:=IQ(d,c); 
            c:=RNNUM(a); c:=IPROD(c,b); 
            C:=COMP(c,C);
            END;
      WHILE bp # SIL DO ADV(bp, a, bp);
            c := RNDEN(a); b:=IQ(d,c); 
            c:=RNNUM(a); c:=IPROD(c,b); 
            D:=COMP(c,D);
            END;
(*4*) C := INV(C); D:=INV(D);
(*9*) END IVFRNV1;


PROCEDURE IMFRNM(A : LIST): LIST;
(*Integer matrix from rational number matrix. A is a rational 
number row matix. The rows of A are muliplied by a common 
multiple of its denominators, then the denominators are 
removed. An integer matix C is returned, such that for 
all rows C(i) = lcm(denom(A(i))) * A(i). *)
VAR   AP, BP: LIST;
BEGIN
(*1*) IMFRNM1(A,SIL, AP,BP); RETURN(AP);
(*9*) END IMFRNM;


PROCEDURE IMFRNM1(A, B : LIST; VAR C, D: LIST);
(*Integer matrix from rational number matrix. A is a rational 
number row matix. B is a rational number column matix. 
The rows of A and the rows of B are muliplied by
a common multiple of their denominators, then the 
denominators are removed. C and D are integer matices,
such that C(i) = lcm(denom(A(i)),B(i)) * A(i) and
D(i) = lcm(denom(A(i)),B(i)) * B(i). *)
VAR   a, b, c, d: LIST;
BEGIN
(*1*) C:= SIL; D:=SIL; B:=MTRANS(B); 
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            IF B # SIL THEN ADV(B, b, B) ELSE b:=SIL END; 
            IVFRNV1(a,b,c,d);
            C:=COMP(c,C);
            IF d # SIL THEN D:=COMP(d,D) END;
            END;
(*3*) C:=INV(C); D:=INV(D); D:=MTRANS(D);
(*9*) END IMFRNM1;


(* ------------ *)

PROCEDURE IVLC(a, A, b, B : LIST): LIST;
(*Integer vector linear combination. A and B are integer vectors. 
a and b are integers. An integer vector C = a*A + b*B is returned. *)
VAR    c, cp, C, ap, bp : LIST;
BEGIN
(*1*) (*initialization*) C := SIL;
      IF a = 0 THEN a:=b; A:=B; b:=0; END; 
(*2*) (*a or b zero*)
      IF b = 0 THEN 
         WHILE A # SIL DO
               ADV(A, ap, A);  
               c := IPROD(a,ap); 
               C := COMP(c,C);
               END;
         C:=INV(C); RETURN(C); END;  
(*3*) (*general case*)
      WHILE A # SIL DO
            ADV(A, ap, A);  ADV(B, bp, B);
            c := IPROD(a,ap); cp := IPROD(b,bp);
            c := ISUM(c,cp); C := COMP(c,C);
            END;
(*4*) (*finish*) C := INV(C); RETURN(C);
(*9*) END IVLC;


PROCEDURE IVSQ(a, A: LIST): LIST;
(*Integer vector scalar quotient. A is an integer vector. 
a is an integer. An integer vector C = A/a is returned. 
a must divide each element of A exactly.  *)
VAR    c, C, ap, r: LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, ap, A);  
            IQR(ap,a,c,r);
            IF r # 0 THEN ERROR(severe,"IVSQ: non zero remainder.") END;
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END IVSQ;

(*
PROCEDURE IMGELUD0(M : LIST; VAR L, U: LIST);
(* Integer matrix Gaussian elimination. LU-decomposition. *)
VAR   C, M1, MP, L1, a, b, c, MP1, V, n, Z : LIST;
BEGIN
(*1*) M1 := M; MP := SIL; L := SIL; U := SIL;
      IF M1 = SIL THEN RETURN END;
      IF FIRST(M1) = SIL THEN RETURN END;
      n := 0;
(*2*) WHILE M1 # SIL DO
            L1 := SIL; MP1 := M1; M1 := SIL;
            a := 0;
            (*search pivot row. *)
            WHILE (MP1 # SIL) AND (a = 0) DO
                  ADV(MP1, C, MP1);
                  ADV(C, a, C);
                  IF a = 0 THEN M1 := COMP(C,M1); L1 := COMP(a,L1); END;
                  END;
            IF a = 0 THEN C:=COMP(a,C); M1:=RED(M1); 
               ELSE  
               L1 := COMP(a,L1);
               WHILE MP1 # SIL DO
                     ADV(MP1, V, MP1);
                     ADV(V, b, V);
                     IF b # 0 THEN V := IVLC(a,V,INEG(b),C) END;
                     M1 := COMP(V,M1);
                     L1 := COMP(b,L1);
                     END;
               C := COMP(a,C);
               END;
            MP := COMP(C,MP); 
            L1 := INV(L1); L := COMP(L1,L);
            M1 := INV(M1); 
            IF M1 # SIL THEN (*if not square matrix *)
               IF FIRST(M1) = SIL THEN M1 := SIL END;
               END;
            END;
(*3*) U := INV(MP); L := INV(L);
      RETURN;
(*9*) END IMGELUD0;
*)

PROCEDURE IMGELUD(M : LIST; VAR L, U: LIST);
(*Integer matrix Gaussian elimination LU-decomposition. 
M is an integer matrix represented rowwise. L is a lower 
triangular integer matrix represented columnwise.
U is an upper triangular integer matrix represented rowwise.
M = L * U for appropriate modifications of L and U. The pivot 
operations and exact division factors are also recorded in L. *)
VAR   F, C, CP, M1, MP, L1, a, b, c, MP1, MP2, V, n, Z : LIST;
BEGIN
(*1*) M1 := M; MP := SIL; L := SIL; U := SIL;
      IF M1 = SIL THEN RETURN END;
      IF FIRST(M1) = SIL THEN RETURN END;
      n := 0; F:=1; 
(*2*) WHILE M1 # SIL DO
            L1 := SIL; MP1 := M1; M1 := SIL;
            a := 0; 
            (*search pivot row. *)
            WHILE (MP1 # SIL) AND (a = 0) DO
                  ADV(MP1, C, MP1);
                  ADV(C, a, CP);
                  IF a = 0 THEN M1 := COMP(CP,M1); L1 := COMP(a,L1); END;
                  END;
            IF a = 0 THEN (*M1:=RED(M1);*) F:=1  
               ELSE L1 := COMP(a,L1); L1 := COMP(F,L1); 
               (*transform rest matrix. *)
               MP2:=INV(M1); M1:=SIL;
               WHILE MP2 # SIL DO ADV(MP2, V, MP2);
                     V:=IVLC(a,V,0,CP);
                     IF F # 1 THEN V:=IVSQ(F,V) END; (*Bareiss factor *)
                     M1 := COMP(V,M1);
                     END;
               WHILE MP1 # SIL DO ADV(MP1, V, MP1);
                     ADV(V, b, V);
                     V:=IVLC(a,V,INEG(b),CP);
                     IF F # 1 THEN V:=IVSQ(F,V) END; (*Bareiss factor *)
                     M1 := COMP(V,M1);
                     L1 := COMP(b,L1);
                     END;
               F:=a;
               MP := COMP(C,MP); 
               END;
            M1 := INV(M1); 
            L1 := INV(L1); L := COMP(L1,L);
            IF M1 # SIL THEN (*if not square matrix *)
               IF FIRST(M1) = SIL THEN M1 := SIL END;
               END;
            END;
(*3*) U := INV(MP); L := INV(L);
      RETURN;
(*9*) END IMGELUD;


PROCEDURE IMLT(L, b : LIST): LIST;
(*Integer lower triangular matrix transformation. 
L is a lower triangular integer matrix represented 
columnwise as generated by IMGELUD. b is an integer vector. 
An integer vector u = L * b is returned, such that 
if M * x = b and M = L * U, then U * x = u. *)
VAR   F, u, L1, b1, b2, c, l, d, a, e: LIST;
BEGIN
(*1*) u := SIL;
(*2*) WHILE L # SIL DO
            ADV(L, L1, L);
            b1 := b; b := SIL; b2:=SIL; 
            l := 0;
            WHILE (L1 # SIL) AND (l = 0) DO
                  ADV(L1, l, L1);
                  ADV(b1, c, b1);
                  IF l = 0 THEN b2 := COMP(c,b2) END;
                  END;
            IF l = 0 
               THEN (*u := COMP(c,u);*) b:=b2; 
               ELSE (* l # 0 *)
                    u := COMP(c,u); e:=l; ADV(L1,F,L1);
                    b2:=INV(b2); 
                    WHILE b2 # SIL DO
                          ADV(b2, d, b2);
                          a := IPROD(e,d);
                          IF F # 1 THEN a:=IQ(a,F) END;
                          b := COMP(a,b);
                          END;
                    WHILE L1 # SIL DO
                          ADV(L1, l, L1);
                          ADV(b1, d, b1);
                          d := IPROD(e,d);
                          a := IPROD(l,c);
                          a := IDIF(d,a); 
                          IF F # 1 THEN a:=IQ(a,F) END;
                          b := COMP(a,b);
                          END;
                    END;
            b := INV(b);
            END;
(*3*) WHILE b <> SIL DO ADV(b,c,b); (*unsolvable ? *)
            IF c # 0 THEN RETURN(SIL) END;
            END;
(*4*) u := INV(u); RETURN(u);
(*9*) END IMLT;


PROCEDURE IMUT(U, b : LIST): LIST;
(*Integer upper triangular matrix transformation. 
U is an upper triangular integer matrix represented rowwise
as generated by IMGELUD. b is an integer vector 
b = L * b' as generated by IMLT. A rational number (!) vector x, 
such that U * x = b is returned. If no such x exists, then an 
empty vector is returned. If more than one such x exists, then 
for free x(i), x(i) = 0 is taken. *)
VAR   UP, x, bp : LIST;
BEGIN
(*1*) UP:=RNMFIM(U); bp:=RNVFIV(b); x:=RNMUT(UP,bp);
(*3*) RETURN(x);
(*9*) END IMUT;


PROCEDURE IMGE(M : LIST): LIST;
(*Integer matrix Gaussian elimination. M is a (n x m) integer 
matrix. A (n x m) integer matrix resulting from Gaussian 
elimination is returned. IMGELUD is called. *)
VAR   i, j, u, MP, l: LIST;
BEGIN  
(*1*) i:=LENGTH(M);
      IF M # SIL THEN j:=LENGTH(FIRST(M))
                 ELSE j:=0 END;
(*2*) IMGELUD(M, l, u);
(*3*) MP:=MFILL(u,i,j);
      RETURN(MP);
(*9*) END IMGE;


PROCEDURE IMSDS(L, U, b : LIST): LIST;
(*Integer matrix solve decomposed system. L is a lower 
triangular integer matrix represented columnwise, U is an upper 
triangular integer matrix represented rowwise. L and U as 
generated by IMGELUD. If M = L * U, then a rational number (!) 
vector x, such that M * x = b is returned. If no such x exists, 
then an empty vector is returned. If more than one such x exists, 
then for free x(i), x(i) = 0 is taken. *)
VAR   u, x : LIST;
BEGIN
(*1*) u := IMLT(L,b);
      IF u # SIL THEN x := IMUT(U,u);
                 ELSE x := SIL; (*unsolvable*) END;
(*3*) RETURN(x);
(*9*) END IMSDS;


PROCEDURE RNMINVI(A : LIST): LIST;
(*Rational number matrix inversion, integer algorithm. A is a 
rational number matrix represented rowwise. If it exists, 
the inverse matrix of A is returned, otherwise an empty matrix 
is returned. The integer Gaussian elimination IMGELUD is used. *)
VAR   B, C, n, E, e, x, AP, EP, u, UP, L, U: LIST;
BEGIN
(*1*) n := LENGTH(A); B := SIL;
      IF n <= 0 THEN RETURN(B) END;
      IF n # LENGTH(FIRST(A)) THEN RETURN(B) END;
      E := RNUM(n,n);
      IMFRNM1(A,E,AP,EP);
(*2*) (*LU-decomposition. *)
      IMGELUD(AP, L, U);
(*3*) (*solve A Ainv = E. *)
      UP:=RNMFIM(U);
      WHILE EP # SIL DO
            ADV(EP, e, EP);
            u := IMLT(L,e);
            IF u = SIL THEN RETURN(SIL) END; (*singular *)
            u:=RNVFIV(u); x:=RNMUT(UP,u);
            IF x = SIL THEN RETURN(SIL) END; (*singular *)
            B := COMP(x,B);
            END;
(*4*) B := INV(B); RETURN(B);
(*9*) END RNMINVI;


PROCEDURE IMUNS(U : LIST): LIST;
(*Integer matrix upper triangular matrix solution null space. 
U is an upper triangular integer matrix represented rowwise
as generated by IMGELUD. A matrix X of linear independent rational 
number vectors x is returned, such that for each x in X, U * x = 0 holds. 
If only x = 0 satisfies the condition U * x = 0, then the 
matrix X is empty. *)
VAR   UP, N: LIST; 
BEGIN
(*1*) UP:=RNMFIM(U); N:=RNMUNS(UP); RETURN(N);
(*9*) END IMUNS;


PROCEDURE IMDETL(M : LIST): LIST;
(*Integer matrix determinant, using Laplace expansion. 
M is an integer matrix. The determinant of M is returned. *)
VAR   i, d, dp, s, N, MP, V, VP, v : LIST;
BEGIN
(*1*) d := 0;
      IF M = SIL THEN RETURN(d); END;
      ADV(M, V, MP);
      IF MP = SIL THEN 
         IF V = SIL THEN RETURN(d); END;
         ADV(V,d,V); 
         IF V # SIL THEN d:=0 END;
         RETURN(d); END;
      s := 1; i := 0;   
(*2*) WHILE V # SIL DO
            ADV(V, v, V);
            i := i+1;
            IF v # 0 THEN
               N := MDELCOL(MP,i);
               dp := IMDETL(N);
               dp := IPROD(v,dp);
               IF s < 0 THEN dp := INEG(dp); END;
               d := ISUM(d,dp);
               END;
            s := -s;
            END;
      RETURN(d);
(*9*) END IMDETL;


PROCEDURE IMDET(M : LIST): LIST;
(*Integer matrix determinant, using Gaussian elimination. 
M is an integer matrix. The determinant of M is returned. *)
VAR   F, d, s, i, C, CP, M1, MP, a, b, c, MP1, MP2, V, e: LIST;
BEGIN
(*1*) M1 := M; d := 0; s := 1;
      IF M1 = SIL THEN RETURN(d) END;
      V:=FIRST(M1); 
      IF V = SIL THEN RETURN(d) END;
      IF LENGTH(M1) # LENGTH(V) THEN RETURN(d) END; (* not square *) 
      e:=1; d:=e; F:=1;
(*2*) WHILE M1 # SIL DO
            MP1 := M1; M1 := SIL;
            a := 0; i:=0;
            (*search pivot row and count sign changes. *)
            WHILE (MP1 # SIL) AND (a = 0) DO
                  ADV(MP1, C, MP1); i:=i+1;
                  ADV(C, a, CP);
                  IF a = 0 THEN M1 := COMP(CP,M1) END;
                  END;
            IF a = 0 THEN d:=0; RETURN(d); END;
            IF MASEVEN(i) THEN s:=-s END;
            (*rest matrix. *)
            d:=a; (* d:=IPROD(d,a); *) 
            MP2:=INV(M1); M1:=SIL;
            WHILE MP2 # SIL DO ADV(MP2, V, MP2);
                  V:=IVLC(a,V,0,CP);
                  IF F # 1 THEN V:=IVSQ(F,V) END; (*Bareiss factor *)
                  M1 := COMP(V,M1);
                  END;
            WHILE MP1 # SIL DO
                  ADV(MP1, V, MP1);
                  ADV(V, b, V);
                  V := IVLC(a,V,INEG(b),CP);
                  IF F # 1 THEN V:=IVSQ(F,V) END; (*Bareiss factor *)
                  M1 := COMP(V,M1);
                  END;
            M1 := INV(M1); F:=a;
            IF M1 # SIL THEN (*not square matrix ? *)
               IF FIRST(M1) = SIL THEN d := 0; RETURN(d) END;
               END;
            END;
(*3*) IF s < 0 THEN d:=INEG(d) END;
      RETURN(d);
(*9*) END IMDET;


END LINALGI.

(* -EOF- *)
