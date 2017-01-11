(* ----------------------------------------------------------------------------
 * $Id: LINALGRN.mi,v 1.5 1995/11/05 09:24:14 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: LINALGRN.mi,v $
 * Revision 1.5  1995/11/05 09:24:14  kredel
 * Fixed comments and code.
 *
 * Revision 1.4  1992/10/15  16:29:16  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/08/21  13:52:13  kredel
 * Corrected error in RNMDET: wrong check for square matrix.
 *
 * Revision 1.2  1992/02/12  17:33:11  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:51  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE LINALGRN;

(* MAS Linear Algebra Rational Number Implementation Module. *)


(*-------------------------------------------------------------------------

Implementation Module: Linear Algebra Rational Number 

Programmierpraktikum SS 1990: JUERGEN MUELLER, Heinz Kredel 

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

  FROM MASBIOS IMPORT SWRITE, BLINES, CREADB, BKSP, MASORD, DIGIT;

  FROM MASSTOR IMPORT LIST, SIL, BETA, 
                      ADV, FIRST, RED, INV, LIST1, COMP, LENGTH;

  FROM MASERR IMPORT ERROR, severe;

  FROM SACLIST IMPORT LIST2, CCONC, CINV, CONC;

  FROM SACRN IMPORT RNINV, RNABS, RNCOMP, RNWRIT, RNNEG, RNDIF, RNQ, 
                    RNDEN, RNNUM, RNRED, RNINT, RNPROD, RNSUM;

  FROM MASRN IMPORT RNMAX, RNDWR;

  FROM MASAPF IMPORT RNDRD, APFRN, APWRIT;

CONST rcsidi = "$Id: LINALGRN.mi,v 1.5 1995/11/05 09:24:14 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

TYPE F2 = PROCEDURE(LIST,LIST): LIST;

(*The TDI compiler accepts only global functions in expressions. *)   

PROCEDURE rnhi(i,j: LIST): LIST; (*Hilbert*)
BEGIN RETURN(RNRED(1,i+j-1)) END rnhi;

PROCEDURE rnum(i,j: LIST): LIST; (*unit matrix*)
BEGIN IF i = j THEN RETURN(RNINT(1)) ELSE RETURN(0) END;
(*9*) END rnum;

(*---------------- arbitrary matices --------------------*)

PROCEDURE MDIM(M : LIST): LIST;
(*Matrix dimension. M is a matrix. MDIM returns
max( row, column) of M. *)
VAR   zeile, spalte : LIST;
BEGIN
(*1*) zeile := LENGTH(FIRST(M));
      spalte := LENGTH(M);
      IF spalte < zeile THEN RETURN(zeile) 
                        ELSE RETURN(spalte) END;
(*9*) END MDIM;


PROCEDURE MGET(M, k, l : LIST): LIST;
(*Matrix get. M is a matrix. k, l are integers, 0 le k le  rows(M),
0 le l le  columns(M). MGET returns the element M(k,l) of matrix M. *)
VAR   i, j, h1, rest : LIST;
BEGIN
(*1*) rest := M; h1 := SIL;
      i := 0; j := 0;
(*2*) (*Suche nach Eintrag in der gewuenschter Zeile*)
      WHILE i < k DO
            i := i+1;
            ADV(rest, h1, rest);
            END;
      rest := h1;
(*3*) (*Suche nach Eintrag in der gewuenschten Spalte*)
      WHILE j < l DO
            j := j+1;
            ADV(rest, h1, rest);
            END;
      RETURN(h1);
(*9*) END MGET;


PROCEDURE MSET(M, k, l, x : LIST): LIST;
(*Matrix set. M is a matrix. k, l are integers, 0 le k le  rows(M),
0 le l le  columns(M). MSET sets the element M(k,l) to x. 
The new matrix is returned. *)
VAR    i, j, h1, rest1, rest2, neuk, neul, neuhilf, 
       egal, neu : LIST;
BEGIN
(*1*) rest1 := M; neuk := SIL;
      i := 0;
      j := 0;
(*2*) (*Suche k-te Zeile*)
      WHILE i < k DO
            i := i+1;
            ADV(rest1, h1, rest1);
            neuk := COMP(h1,neuk);
            END;
      rest2 := h1;
      neul := SIL;
(*3*) (*Suche l-te Spalte*)
      WHILE j < l DO
            j := j+1;
            ADV(rest2, h1, rest2);
            neul := COMP(h1,neul);
            END;
      neu := COMP(x,rest2); (*tausche x aus*)
(*4*) (*und fuege neu zusammen*)
      ADV(neul, egal, neul);
      WHILE neul <> SIL DO
            ADV(neul, neuhilf, neul);
            neu := COMP(neuhilf,neu);
            END;
      neu := LIST1(neu);
(*5*) (*restauriere Matrix*) 
      ADV(neuk, egal, neuk);
      WHILE neuk<>SIL DO
            ADV(neuk, neuhilf, neuk);
            neu := COMP(neuhilf,neu);
            END;
      neu := INV(neu);
(*6*) WHILE rest1 <> SIL DO
            ADV(rest1, neuhilf, rest1);
            neu := COMP(neuhilf,neu);
            END;
      neu := INV(neu);
      RETURN(neu);
(*9*) END MSET;


PROCEDURE VDELEL(V, i : LIST): LIST;
(*Vector delete element. V is a vector. The i-th element of V 
is deleted. 0 le i le length(V). *)
VAR   U, VP, v, j : LIST;
BEGIN
(*1*) IF i <= 0 THEN RETURN(V) END;
      IF V = SIL THEN RETURN(V) END;
      VP := V; j := 0; U := SIL;
(*2*) REPEAT
             j := j+1;
             IF VP = SIL THEN RETURN(V); END;
             ADV(VP, v, VP);
             U := COMP(v,U);
             UNTIL j=i;
(*3*) U := RED(U); U := INV(U); U := CONC(U,VP);
      RETURN(U);
(*9*) END VDELEL;


PROCEDURE MDELCOL(M, i : LIST): LIST;
(*Matrix delete column. M is a vector of row vectors. In each 
row the i-th element is deleted, 0 le i le  columns(M). The new 
matrix is returned. *)
VAR   N, MP, V : LIST;
BEGIN
(*1*) IF i <= 0 THEN RETURN(M) END;
      IF M = SIL THEN RETURN(M) END;
      MP := M; N := SIL;
(*2*) WHILE MP # SIL DO
            ADV(MP, V, MP);
            V := VDELEL(V,i);
            N := COMP(V,N);
            END;
(*3*) N := INV(N);
      RETURN(N);
(*9*) END MDELCOL;


PROCEDURE MMINOR(M, i, j : LIST): LIST;
(*Matrix minor. M is a vector of row vectors. The i-th column, 
0 le i le  rows(M), and in each remaining row the j-th element,
0 le j le  columns(M), is deleted. *)
VAR   MP: LIST;
BEGIN
(*1*) MP:=VDELEL(M,j); MP:=MDELCOL(MP,i); 
      RETURN(MP);
(*9*) END MMINOR;


PROCEDURE MTRANS(M : LIST): LIST;
(*Matrix transpose. M is a matrix. The transposed matrix is returned. *)
VAR   A, B, C, MT, a, b : LIST;
BEGIN
(*1*) B:=M; MT:=SIL;
      WHILE B # SIL DO 
            A:=B; B:=SIL; C:=SIL; 
            WHILE A # SIL DO ADV(A,a,A); 
                  IF a # SIL THEN ADV(a,b,a); 
                     B:=COMP(a,B); C:=COMP(b,C) END;
                  END;
            C:=INV(C); 
            IF C # SIL THEN MT:=COMP(C,MT) END;
            B:=INV(B);
            END;
      MT:=INV(MT); RETURN(MT);
(*9*) END MTRANS;


PROCEDURE VEL(a, n : LIST): LIST;
(*Vector elements. A vector of length n with elements a is returned. *)
VAR   A, k : LIST;
BEGIN
(*1*) A := SIL; k := 1;
(*2*) WHILE k<=n DO k := k+1;
            A := COMP(a,A); END;
(*3*) RETURN(A);
(*9*) END VEL;


PROCEDURE MFILL(M, m, n: LIST): LIST;
(*Matrix fill. M is an upper triangular matrix. A (m x n) matrix 
with zeros in the lower triangular part is returned. *)
VAR   i, j, V, MP, np: LIST;
BEGIN
(*1*) MP:=SIL; i:=0;
(*2*) WHILE i < m DO i:=i+1; j:=0; 
            IF M # SIL THEN ADV(M,V,M); np:=n-LENGTH(V);  
                       ELSE V:=SIL; np:=n END;
            WHILE j < np DO j:=j+1; V:=COMP(0,V) END;
            MP:=COMP(V,MP);
            END;
(*4*) MP:=INV(MP); RETURN(MP);
(*9*) END MFILL;


PROCEDURE MRANG(U: LIST): LIST;
(*Matrix rang. U is an upper triangular matrix from a
LU-decomposition. The rang of U is returned. *)
VAR   r: LIST; 
BEGIN
(*1*) r:=LENGTH(U); 
      RETURN(r);
(*9*) END MRANG;


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


(*---------------- rational number matices --------------------*)

PROCEDURE RNMHILBERT(m, n : LIST): LIST;
(*Rational number matrix Hilbert. m, n integer. A (m x n) rational 
number Hilbert matrix is returned. *)
BEGIN
(*1*) RETURN(MAT(rnhi,m,n));
(*9*) END RNMHILBERT;


PROCEDURE RNUM(m, n : LIST): LIST;
(*Rational number unit matrix. m, n integer. A (m x n) rational 
number unit matrix is returned. *)
BEGIN
(*1*) RETURN(MAT(rnum,m,n));
(*9*) END RNUM;


PROCEDURE RNVWRITE(A, s : LIST);
(*Rational number vector write. A is a rational number vector. 
A is written to the output stream. The rational numbers are written 
as rational numbers if s = -1, as decimal approximations, with s decimal 
digits if s >= 0 or in floating point format if s < -1. *)
VAR   a : LIST;
BEGIN
(*1*) SWRITE("(");
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            IF s < 0 THEN 
               IF s = -1 THEN RNWRIT(a) 
                  ELSE a:=APFRN(a); APWRIT(a); END; 
               ELSE RNDWR(a,s); END;
            IF A # SIL THEN SWRITE(", ") END;
            END;
(*3*) SWRITE(")");
(*9*) END RNVWRITE;


PROCEDURE RNVREAD(): LIST;
(*Rational number vector read. A rational number vector is 
read from the input stream, and returned. *)
VAR   c, a, A: LIST;
BEGIN
(*1*) c:=CREADB(); A:=SIL;
      IF c # MASORD("(") THEN ERROR(severe,"RNVREAD ( expected."); 
         BKSP; RETURN(A) END;
(*2*) LOOP c:=CREADB(); 
           IF c = MASORD(")") THEN EXIT END; BKSP; 
           a:=RNDRD(); A:=COMP(a,A);
           c:=CREADB();               
           IF c # MASORD(",") THEN BKSP END;
           END;
(*3*) A:=INV(A); RETURN(A); 
(*9*) END RNVREAD;


PROCEDURE RNMWRITE(A, s : LIST);
(*Rational number matrix write. A is a rational number matrix. 
A is written to the output stream. The rational numbers are written 
as rational numbers if s = -1, as decimal approximations, with s decimal 
digits if s >= 0 or in floating point format if s < -1. *)
VAR   a : LIST;
BEGIN
(*1*) BLINES(0); SWRITE("(");
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            RNVWRITE(a,s);
            IF A # SIL THEN SWRITE(", "); BLINES(0) END;
            END;
(*3*) SWRITE(")"); BLINES(0);
(*9*) END RNMWRITE;


PROCEDURE RNMREAD(): LIST;
(*Rational number matrix read. A rational number matrix is 
read from the input stream, and returned. *)
VAR   c, a, A: LIST;
BEGIN
(*1*) c:=CREADB(); A:=SIL;
      IF c # MASORD("(") THEN ERROR(severe,"RNMREAD ( expected."); 
         BKSP; RETURN(A) END;
(*2*) LOOP c:=CREADB(); 
           IF c = MASORD(")") THEN EXIT END;
           IF c = MASORD("(") THEN BKSP; a:=RNVREAD(); 
              A:=COMP(a,A);
              c:=CREADB();               
              IF c # MASORD(",") THEN BKSP END;
              END;
           END;
(*3*) A:=INV(A); RETURN(A); 
(*9*) END RNMREAD;


PROCEDURE RNVFIV(A : LIST): LIST;
(*Rational number vector from integer vector. A is an integer 
vector. A rational number vector with denominators 1 
and nominators equal to the elements of A is returned. *)
VAR   a, c, C : LIST;
BEGIN
(*1*) C := SIL; a := SIL; c := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := RNINT(a);
            C := COMP(c,C);
            END;
(*2*) C := INV(C);
      RETURN(C);
(*2*) END RNVFIV;


PROCEDURE RNMFIM(M : LIST): LIST;
(*Rational number matrix from integer matrix. A is an integer 
matrix. A rational number matrix with denominators 1 
and nominators equal to the elements of A is returned. *)
VAR   hilf, neu : LIST;
BEGIN
(*1*) hilf := SIL;
(*2*) WHILE M # SIL DO
            ADV(M, neu, M);
            neu := RNVFIV(neu);
            hilf := COMP(neu,hilf);
            END;
(*3*) hilf := INV(hilf);
      RETURN(hilf);
(*9*) END RNMFIM;


PROCEDURE RNVDIF(A, B : LIST): LIST;
(*Rational number vector difference. A and B are rational number 
vectors. The rational number vector C = A - B is returned. *)
VAR   a, b, c, C, test : LIST;
BEGIN
(*1*) C := SIL;
      WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNDIF(a,b);
            C := COMP(c,C);
            END;
      C := INV(C); RETURN(C);
(*9*) END RNVDIF;


PROCEDURE RNVQ(A, B : LIST): LIST;
(*Rational number vector quotient. A and B are rational number vectors.
The rational number vector C = A / FIRST(B) is returned. *)
    VAR   a, b, c, C : LIST;
    BEGIN
      C := SIL;
      IF B#SIL THEN
        WHILE A#SIL DO
          ADV(A, a, A);
          c := RNQ(a,FIRST(B));
          C := COMP(c,C);
        END;
        C := INV(C);
        RETURN(C);
      ELSE
        RETURN(A);
      END;
    END RNVQ;


PROCEDURE RNVQF(A : LIST): LIST;
(*Rational number vector quotient. A is a rational number vector.  
The rational number vector C = A / FIRST(A) is returned. *)
    VAR   b : LIST;
    BEGIN
      IF b#LIST(0) THEN
        A := RNVQ(A,A);
      END;
      RETURN(A);
    END RNVQF;


PROCEDURE RNVVSUM(A, B : LIST): LIST;
(*Rational number vector vector sum. A and B are rational number vectors. 
A rational number vector C = A + B is returned. *)
VAR   a, b, c, C, test : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNSUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNVVSUM;


PROCEDURE RNVSVSUM(A, B : LIST): LIST;
(*Rational number vector scalar sum. A and B are rational number vectors.
A rational number vector C = A + FIRST(B) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL; b:=FIRST(B); 
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := RNSUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNVSVSUM;


PROCEDURE RNVSSUM(A : LIST): LIST;
(*Rational number vector scalar sum. A is a rational number vector.
A rational number C = a1 + a2 + ... + an is returned. *)
VAR   a, c : LIST;
BEGIN
(*1*) a := SIL; c := 0;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := RNSUM(a,c);
            END;
      RETURN(c);
(*2*) END RNVSSUM;


PROCEDURE RNVSVPROD(A, B : LIST): LIST;
(*Rational number vector scalar vector product. A and B are 
rational number vectors. A rational number vector 
C = (a1*FIRST(B), ..., an*FIRST(B)) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL; b:=FIRST(B);
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := RNPROD(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNVSVPROD;


PROCEDURE RNVVPROD(A, B : LIST): LIST;
(*Rational number vector vector product. A and B are 
rational number vectors. A rational number vector 
C = (a1*b1, ..., an*bn) is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNPROD(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNVVPROD;


PROCEDURE RNVSPROD(A, B : LIST): LIST;
(*Rational number vector scalar product. A and B are rational 
number vectors. A rational number C = a1*b1 + ... + an*bn is
returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) C := 0;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNPROD(a,b);
            C := RNSUM(c,C);
            END;
(*3*) RETURN(C);
(*9*) END RNVSPROD;


PROCEDURE RNVMAX(M : LIST): LIST;
(*Rational number vector maximum norm. M is a rational number 
vector. A rational number a = maximum absolute value M(i) 
is returned. *)
VAR   g, zeile, element, max : LIST;
BEGIN
(*1*) max := 0;
(*2*) WHILE M # SIL DO
            ADV(M, element, M);
            element := RNABS(element);
            max:=RNMAX(max,element);  
            END;
(*3*) RETURN(max);
(*9*) END RNVMAX;


PROCEDURE RNMSUM(A, B : LIST): LIST;
(*Rational number matrix sum. A and B are rational number
matrices. A rational number matrix C = A + B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN RETURN(B) END;
      IF B=SIL THEN RETURN(A) END;
      C := SIL;
(*2*) WHILE A#SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNVVSUM(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNMSUM;


PROCEDURE RNMDIF(A, B : LIST): LIST;
(*Rational number matrix difference. A and B are rational number
matrices. A rational number matrix C = A - B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN
         B := RNSMPROD(B,RNINT(-1));
         RETURN(B);
         END;
      IF B=SIL THEN RETURN(A); END;
      C := SIL;
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            ADV(B, b, B);
            c := RNVDIF(a,b);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNMDIF;


PROCEDURE RNSMPROD(A, B : LIST): LIST;
(*Rational number scalar and matrix product. A is a rational 
number matrix. B is a rational number. A rational number matrix 
C = A * B is returned. *)
VAR   a, b, c, C : LIST;
BEGIN
(*1*) IF A=SIL THEN RETURN(A) END;
      C := SIL; b:=LIST1(B);
(*2*) WHILE A # SIL DO
            ADV(A, a, A);
            c := RNVSVPROD(a,b); (* geaendert *)
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNSMPROD;


PROCEDURE RNMMAX(M : LIST): LIST;
(*Rational number matrix maximum norm. M is a rational number 
matrix. A rational number a = maximum absolute value M(i,j) 
is returned. *)
VAR   g, zeile, element, max : LIST;
BEGIN
(*1*) max := 0;
(*2*) WHILE M # SIL DO
            ADV(M, zeile, M);
            element := RNVMAX(zeile);
            max:=RNMAX(max,element);  
            END;
(*3*) RETURN(max);
(*9*) END RNMMAX;


PROCEDURE RNMGE(M : LIST): LIST;
(*Rational number matrix Gaussian elimination. M is a (n x m) 
rational number matrix. A (n x m) rational number matrix
resulting from Gaussian elimination is returned.  
RNMGELUD is called. *)
VAR   l, u, i, j, MP : LIST;
BEGIN
(*1*) i:=LENGTH(M);
      IF M # SIL THEN j:=LENGTH(FIRST(M))
                 ELSE j:=0 END;
(*2*) RNMGELUD(M,l,u);
(*3*) MP:=MFILL(u,i,j);
      RETURN(MP);
(*9*) END RNMGE;


PROCEDURE RNMDETL(M : LIST): LIST;
(*Rational number matrix determinant, using Laplace expansion. 
M is a rational number matrix. The determinant of M is returned. *)
VAR   i, d, dp, s, N, MP, V, VP, v : LIST;
BEGIN
(*1*) d := 0;
      IF M = SIL THEN RETURN(d); END;
      ADV(M, V, MP);
      IF MP = SIL THEN (*not square matrix ? *)
         IF RED(V) # SIL THEN d:=0 ELSE d:=FIRST(V) END;
         RETURN(d); END;
      s := 1;
      i := 0;
(*2*) WHILE V # SIL DO
            ADV(V, v, V);
            i := i+1;
            IF v # 0 THEN
               N := MDELCOL(MP,i);
               dp := RNMDETL(N);
               dp := RNPROD(v,dp);
               IF s < 0 THEN dp := RNNEG(dp) END;
               d := RNSUM(d,dp);
               END;
            s := -s; END;
      RETURN(d);
(*9*) END RNMDETL;


(*-------------------*)


PROCEDURE RNVLC(a, A, b, B : LIST): LIST;
(*Rational number vector linear combination. A and B are rational 
number vectors. a and b are rational numbers. A rational number vector 
C = a*A + b*B is returned. *)
VAR    c, cp, C, ap, bp : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A#SIL DO
            ADV(A, ap, A);  ADV(B, bp, B);
            c := RNPROD(a,ap); cp := RNPROD(b,bp);
            c := RNSUM(c,cp); C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNVLC;


PROCEDURE RNSVPROD(a, A : LIST): LIST;
(*Rational number vector product with scalar. A is a rational 
number vector. a is a rational number. A rational number vector
C = a*A is returned. *)
VAR   c, cp, C, ap : LIST;
BEGIN
(*1*) C := SIL;
(*2*) WHILE A#SIL DO
            ADV(A, ap, A);
            c := RNPROD(a,ap);
            C := COMP(c,C);
            END;
(*3*) C := INV(C); RETURN(C);
(*9*) END RNSVPROD;


PROCEDURE RNMPROD(A, B : LIST): LIST;
(*Rational number matrix product. A and B are rational number
matrices. A rational number matrix C = A * B is returned, if 
the number of coloums of A is equal to the number of rows of B, 
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
                  c:=RNVSPROD(a,b);   
                  C1:=COMP(c,C1);
                  END;
            C1 := INV(C1);
            C := COMP(C1,C);
            END;
(*4*) C := INV(C); RETURN(C);
(*9*) END RNMPROD;


(*--------------------------*)


PROCEDURE RNMDET(M : LIST): LIST;
(*Rational number matrix determinant, using Gaussian elimination. 
M is a rational number matrix. The determinant of M is returned. *)
VAR   d, s, i, C, M1, MP, a, b, c, MP1, V, e: LIST;
BEGIN
(*1*) M1 := M; d := 0; s := 1;
      IF M1 = SIL THEN RETURN(d) END;
      V:=FIRST(M1); 
      IF V = SIL THEN RETURN(d) END;
      IF LENGTH(M1) # LENGTH(V) THEN RETURN(d) END; (* not square *) 
      e:=RNINT(1); d := e;
(*2*) WHILE M1 # SIL DO
            MP1 := M1; M1 := SIL;
            a := 0; i:=0;
            (*search pivot row and count sign changes. *)
            WHILE (MP1 # SIL) AND (a = 0) DO
                  ADV(MP1, C, MP1); i:=i+1;
                  ADV(C, a, C);
                  IF a = 0 THEN M1 := COMP(C,M1) END;
                  END;
            IF MASEVEN(i) THEN s:=-s END;
            IF a = 0 THEN d:=0; RETURN(d); END;
            (*rest matrix. *)
            d:=RNPROD(d,a);
            WHILE MP1 # SIL DO
                  ADV(MP1, V, MP1);
                  ADV(V, b, V);
                  IF b # 0 THEN b:=RNNEG(RNQ(b,a));
                     V := RNVLC(e,V,b,C) END;
                  M1 := COMP(V,M1);
                  END;
            M1 := INV(M1); 
            IF M1 # SIL THEN (*not square matrix ? *)
               IF FIRST(M1) = SIL THEN d := 0; RETURN(d) END;
               END;
            END;
(*3*) IF s < 0 THEN d:=RNNEG(d) END;
      RETURN(d);
(*9*) END RNMDET;


PROCEDURE RNMGELUD(M : LIST; VAR L, U: LIST);
(*Rational number matrix Gaussian elimination LU-decomposition. 
M is a rational number matrix represented rowwise. L is a lower 
triangular rational number matrix represented columnwise.
U is an upper triangular rational number matrix represented rowwise.
M = L * U for appropriate modifications of L and U. 
The pivot operations are also recorded in L. *)
VAR   C, M1, MP, L1, a, b, c, MP1, V, e, n, Z : LIST;
BEGIN
(*1*) M1 := M; MP := SIL; L := SIL; U := SIL;
      IF M1 = SIL THEN RETURN END;
      IF FIRST(M1) = SIL THEN RETURN END;
      e := RNINT(1);
      n := RNINT(0);
(*2*) WHILE M1 # SIL DO
            L1 := SIL; MP1 := M1; M1 := SIL;
            a := 0;
            (*search pivot row. *)
            WHILE (MP1 # SIL) AND (a = 0) DO
                  ADV(MP1, C, MP1);
                  ADV(C, a, C);
                  IF a = 0 THEN M1 := COMP(C,M1); L1 := COMP(a,L1); END;
                  END;
            IF a = 0 THEN (*C:=COMP(a,C); M1:=RED(M1); *)
               ELSE  
               a := RNQ(e,a);
               L1 := COMP(a,L1);
               C := RNSVPROD(a,C);
               WHILE MP1 # SIL DO
                     ADV(MP1, V, MP1);
                     ADV(V, b, V);
                     IF b # 0 THEN V := RNVLC(e,V,RNNEG(b),C) END;
                     M1 := COMP(V,M1);
                     L1 := COMP(b,L1);
                     END;
               C := COMP(e,C);
               MP := COMP(C,MP); 
               END;
            M1 := INV(M1); 
            L1 := INV(L1); L := COMP(L1,L);
            IF M1 # SIL THEN (*if not square matrix *)
               IF FIRST(M1) = SIL THEN M1 := SIL END;
               END;
            END;
(*3*) U := INV(MP); L := INV(L);
(*9*) END RNMGELUD;


PROCEDURE RNMLT(L, b : LIST): LIST;
(*Rational matrix lower triangular matrix transformation. 
L is a lower triangular rational number matrix represented 
columnwise as generated by RNMGELUD. b is a rational number 
vector. A rational number vector u = L * b is returned, 
such that if M * x = b and M = L * U, then U * x = u. *)
VAR   u, L1, b1, c, l, d, a : LIST;
BEGIN
(*1*) u := SIL;
(*2*) WHILE L # SIL DO
            ADV(L, L1, L);
            b1 := b; b := SIL;
            l := 0;
            WHILE (L1 # SIL) AND (l = 0) DO
                  ADV(L1, l, L1);
                  ADV(b1, c, b1);
                  IF l = 0 THEN b := COMP(c,b) END;
                  END;
            IF l = 0 
               THEN (*u := COMP(c,u);*) 
               ELSE (* l # 0 *)
                    c := RNPROD(c,l);
                    u := COMP(c,u);
                    WHILE L1 # SIL DO
                          ADV(L1, l, L1);
                          ADV(b1, d, b1);
                          a := RNPROD(l,c);
                          a := RNDIF(d,a);
                          b := COMP(a,b);
                          END;
                    END;
            b := INV(b);
            END;
(*3*) WHILE b <> SIL DO ADV(b,c,b); (*unsolvable ? *)
            IF c # 0 THEN RETURN(SIL) END;
            END;
(*4*) u := INV(u); RETURN(u);
(*9*) END RNMLT;


PROCEDURE RNMUT(U, b : LIST): LIST;
(*Rational matrix upper triangular matrix transformation. 
U is an upper triangular rational number matrix represented rowwise
as generated by RNMGELUD. b is a rational number vector 
b = L * b' as generated by RNMLT. A rational number vector x, 
such that U * x = b is returned. If no such x exists, then an 
empty vector is returned. If more than one such x exists, then 
for free x(i), x(i) = 0 is taken. *)
VAR   UP, x, U1, a, c, y, u, xp, b1: LIST;
BEGIN
(*1*) x:=SIL; 
      IF U = SIL THEN RETURN(x) END;
      UP := CINV(U); b1 := CINV(b);
(*2*) WHILE UP # SIL DO
            ADV(UP, U1, UP);
            U1 := CINV(U1);
            y := 0;
            xp := x;
            WHILE xp # SIL DO
                  ADV(xp, c, xp);
                  ADV(U1, u, U1);
                  u := RNPROD(u,c);
                  y := RNSUM(y,u);
                  END;
            xp:=SIL; 
            WHILE RED(U1) # SIL DO
                  U1:=RED(U1);
                  xp:=COMP(0,xp); (* arbitrary solution. *)
                  END;
            ADV(U1, u, U1); 
            ADV(b1, c, b1);
            c := RNDIF(c,y);
            (* u = 0, should not occur. *) 
            a := RNQ(c,u); 
            xp := COMP(a,xp); xp:=INV(xp);
            x := CONC(x,xp);
            END;
(*3*) x := INV(x); RETURN(x);
(*9*) END RNMUT;


PROCEDURE RNMSDS(L, U, b : LIST): LIST;
(*Rational number matrix solve decomposed system. 
L is a lower triangular rational number matrix represented 
columnwise, U is an upper triangular rational number matrix 
represented rowwise. L and U as generated by RNMGELUD.
If M = L * U, then a rational number vector x, such that 
M * x = b is returned. If no such x exists, then an empty 
vector is returned. If more than one such x exists, then 
for free x(i), x(i) = 0 is taken. *)
VAR   u, x : LIST;
BEGIN
(*1*) u := RNMLT(L,b);
      IF u # SIL THEN x := RNMUT(U,u);
                 ELSE x := SIL; (*unsolvable*) END;
(*3*) RETURN(x);
(*9*) END RNMSDS;


PROCEDURE RNMINV(A : LIST): LIST;
(*Rational number matrix inversion. A is a rational number matrix 
represented rowwise. If it exists, the inverse matrix of A is 
returned, otherwise an empty matrix is returned. *)
VAR   B, l, u, n, E, e, x : LIST;
BEGIN
(*1*) n := LENGTH(A); B := SIL;
      IF n <= 0 THEN RETURN(B) END;
      IF n # LENGTH(FIRST(A)) THEN RETURN(B) END;
(*2*) (*LU-decomposition. *)
      RNMGELUD(A,l,u); 
(*3*) (*solve A Ainv = E. *)
      E := RNUM(n,n);
      WHILE E # SIL DO
            ADV(E, e, E);
            x := RNMSDS(l,u,e);
            IF x = SIL THEN RETURN(SIL) END; (*singular *)
            B := COMP(x,B);
            END;
(*4*) B := INV(B); RETURN(B);
(*9*) END RNMINV;


PROCEDURE RNMUNS(U : LIST): LIST;
(*Rational number matrix upper triangular matrix solution null space. 
U is an upper triangular rational number matrix represented rowwise
as generated by RNMGELUD. A matrix X of linear independent rational 
number vectors x is returned, such that for each x in X, U * x = 0 holds. 
If only x = 0 satisfies the condition U * x = 0, then the 
matrix X is empty. *)
VAR   UP, V, N, Z, ZP, e, a, c, u, up, b, i, n, m, j: LIST; 
BEGIN
(*1*) UP:=CINV(U); N:=SIL; Z:=SIL; i:=0; e:=RNINT(1);
(*2*) WHILE UP # SIL DO ADV(UP,u,UP); 
            n:=LENGTH(u)-1;
            IF i < n THEN ADV(u,b,u); 
               WHILE i < n DO i:=i+1; j:=i; 
                     ZP:=COMP(e,Z); Z:=COMP(0,Z); 
                     WHILE j < n DO j:=j+1; ZP:=COMP(0,ZP) END;
                     a:=RNVSPROD(u,ZP); 
                     c:=RNNEG(a); a:=RNQ(c,b); 
                     j:=j+1; ZP:=COMP(a,ZP);
                     V:=UP; 
                     WHILE V # SIL DO ADV(V,up,V);
                           m:=LENGTH(up)-1; 
                           WHILE j < m DO j:=j+1; ZP:=COMP(0,ZP) END;
                           ADV(up,c,up); 
                           a:=RNVSPROD(up,ZP); 
                           a:=RNNEG(a); a:=RNQ(a,c); 
                           j:=j+1; ZP:=COMP(a,ZP);
                           END;
                     N:=COMP(ZP,N); 
                     END;
               END; 
            i:=n+1;    
            END;
      N:=INV(N); RETURN(N);
(*9*) END RNMUNS;


END LINALGRN.

(* -EOF- *)
