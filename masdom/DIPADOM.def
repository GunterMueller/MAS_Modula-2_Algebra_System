(* ----------------------------------------------------------------------------
 * $Id: DIPADOM.md,v 1.7 1994/10/21 12:33:46 pfeil Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPADOM.md,v $
 * Revision 1.7  1994/10/21  12:33:46  pfeil
 * added procedure DIPLIR.
 *
 * Revision 1.6  1994/09/01  13:21:41  pfeil
 * modified comment
 *
 * Revision 1.5  1994/06/16  12:53:59  pfeil
 * changed number of parameters in procedure DIPSFF.
 * changed parameter type of procedures SetPFactFunc, SetPSqfrFunc.
 *
 * Revision 1.4  1994/06/10  12:06:57  pfeil
 * Minor changes.
 *
 * Revision 1.3  1994/06/09  14:48:22  pfeil
 * Added DIPFAC, DIPIRL, DIPNF, DIPRLF, DIPS, DIPSFF for DIPDCGB.
 *
 * Revision 1.2  1992/02/12  17:31:20  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:00  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
  
DEFINITION MODULE DIPADOM;

(* DIP Arbitrary Domain Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPADOM.md,v 1.7 1994/10/21 12:33:46 pfeil Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPEXP(A,NL: LIST): LIST; 
(*Distributive polynomial exponentiation.  D is a non zero
distributive polynomial. n is a non-negative beta-integer.
B=A**n. If n=0 then a polynomial in zero variables is returned. *)


PROCEDURE DIFIP(A,D: LIST): LIST; 
(*Distributive polynomial from distributive integral polynomial.
A is a distributive integral polynomial with inverse
lexicographical term ordering. D is the domain
descriptor for the distributive polynomial B. *)


PROCEDURE DILRD(V,D: LIST): LIST; 
(*Distributive polynomial list read. V is a variable list. 
A list of distributive polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding a are skipped. *)


PROCEDURE DILSUM(A: LIST): LIST; 
(*Distributive polynomial list sum. D is a circular
list of distributive polynomials. B is the sum of all
polynomials in A. *)


PROCEDURE DILWR(A,V: LIST); 
(*Distributive polynomial list write. V is a
variable list. A list of distributive polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)


PROCEDURE DIPBCP(A,BL: LIST): LIST; 
(*Distributive polynomial base coefficient product. A is a
distributive polynomial, b is a base coefficient. C=A*b.*)


PROCEDURE DIPDIF(A,B: LIST): LIST; 
(*Distributive polynomial difference. A and B are
distributive polynomials. C=A-B.*)


PROCEDURE DIPFAC(A,VOO: LIST): LIST;
(* distributive polynomial factorization.
   A is a polynomial in distributive representation,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where A = u * f1**e1 * ... * fk**ek and u unit.
   The ordering of the factors is non-deterministic !! *)


PROCEDURE DIPIRL(VAR P: LIST; VAR CS: BOOLEAN);
(* distributive polynomials interreduced list of polynomials.
   P is a list of polynomials in distributive representation
   over an arbitrary domain,
   CS is a flag, CS = TRUE iff P is changed,
   returns a interreduced list of polynomials R=(p1,...,pk),
   R is the result of reducing each pi modulo R-(pi)
   until no further reductions are possible. *)


PROCEDURE DIPLIR(P: LIST): LIST;
(* distributive polynomial list interreduce.
   P is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a interreduced list of polynomials R=(p1,...,pk),
   R is the result of reducing each pi modulo R-(pi)
   until no further reductions are possible. *)


PROCEDURE DIPRLF(P,p: LIST): LIST;
(* distributive polynomials reduce list of polynomials with factor.
   P is a list of polynomials in distributive representation
   over an arbitrary domain, p is a polynomial of same kind,
   returns a list of reduced polynomials R=(p1,...,pk),
   R is the result of reducing each polynomial of P  modulo (p) *)


PROCEDURE DIPMOC(A: LIST): LIST; 
(*Distributive polynomial monic. A and A are
distributive polynomials, C=A/lbc(A) if A ne 0
C=0 if A eq 0. *)


PROCEDURE DIPNEG(A: LIST): LIST; 
(*Distributive polynomial negative. B= -A.*)


PROCEDURE DIPNF(A,B: LIST): LIST;
(* distributive polynomial normalform.
   A is a list of polynomials in distributive representation,
   B is a polynomial as above,
   returns a polynomial h such that B is reducible to h
   modulo A and h is in normalform with respect to A *)


PROCEDURE DIPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive polynomial quotient and remainder.
A and B are distributive polynomials with B ne 0.
Q and R are unique distributive rational polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with deg(R) lt deg(B). *)


PROCEDURE DIPROD(A,B: LIST): LIST; 
(*Distributive polynomial product. A and B are
distributive polynomials. C=A*B.*)


PROCEDURE DIPS(A,B: LIST): LIST;
(* distributive polynomial S-polynomial.
   A and B are polynomials in distributive representation,
   returns the S-polynomial of A and B *)


PROCEDURE DIPSFF(A,VOO: LIST): LIST;
(* distributive polynomial squarefree factorization.
   A is a polynomial in distributive representation,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,p1),...,(ek,pk)), ei positive integers,
   pi squarefree polynomials in distributive representation,
   where A = u * p1**e1 * ... * pk**ek and u unit. *)


PROCEDURE DIPSUM(A,B: LIST): LIST; 
(*Distributive polynomial sum. A and B are
distributive polynomials. C=A+B. *)


PROCEDURE DIREAD(V,D: LIST): LIST; 
(*Distributive polynomial read. V is a variable list.
a distributive polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. any
blanks preceding A are skipped. *)


PROCEDURE DIWRIT(A,V: LIST); 
(*Distributive polynomial write. A is a distributive
polynomial in r variables, r ge 0. V is a variable list
for A. A is written in the output stream. *)


END DIPADOM.

(* -EOF- *)
