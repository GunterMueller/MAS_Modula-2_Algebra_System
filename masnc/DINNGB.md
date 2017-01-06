(* ----------------------------------------------------------------------------
 * $Id: DINNGB.md,v 1.1 1995/12/16 13:23:13 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: DINNGB.md,v $
 * Revision 1.1  1995/12/16 13:23:13  kredel
 * Moved from the masdom directory.
 *
 * Revision 1.1  1994/03/11  15:35:17  pesch
 * Groebner bases for non noetherian polynomial rings.
 * Diplomarbeit I. Bader.
 * Modified.
 * Does not give correct results. Do not use.
 * Should be rewritten.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DINNGB;
(* DIP Groebner bases for non noetherian polynomial rings.*)

  (* Import lists and declarations. *)
   
  FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DINNGB.md,v 1.1 1995/12/16 13:23:13 kredel Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";


  PROCEDURE DINNCP(EL,A,B: LIST): LIST;
  (* distributive polynomial non-commutative product. e is a non-negative
     integer. A and B are distributive polynomials in 2 variables. C is the
      non-commutative product of A and B with respect to  Y * X = X**e Y. *)
  

  PROCEDURE EVNNCP(EL,S,T: LIST): LIST;
  (* exponent vector non-commutative product. S and T are exponent vectors.
     of length 2. C is the non-commutative product S * T with respect
     to the relation Y * X = X**e Y. *)
   


  PROCEDURE EVNRDT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right division test. s and t are
     exponent vectors. C=1 if s rdiv t otherwise, C=0. *)
  

  PROCEDURE EVNCRD(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right division. s and t a are
     exponent vectors, if s rdiv t then the output is t//s. *)
 
  PROCEDURE EVNLDT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative left division test. s and t are
     exponent vectors. C=1 if s ldiv t otherwise, C=0. *)

 
  PROCEDURE EVNCLD(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative left division. s and t a are
     exponent vectors. The output is s\\t if s ldiv t . *)
  
  PROCEDURE EVLLCM(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative least left common multiple. s and t are
     exponent vectors. C is the least left common multiple of s and t. *)
 


  PROCEDURE EVLRCM(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative least right common multiple.
     s and t exponent vectors. C is the least right common multiple
     of s and t if it exists! *)
 
  PROCEDURE EVRCMT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right multiple test.
     S and T are exponent vectors. C=1 if S and T have some right common
     multiple otherweise, C=0. *)
  


  PROCEDURE DNNLNF(EL,P,S:LIST):LIST;
  (* distributive polynomials non-noetherian left normal form.
   P is a list of non zero polynomials in distributive rational representation.
   S is a distributive rational polynomial. R is a polynomial such that S is
   left reducible to R modulo P and R is in normal form with respect to P. *)

  
  PROCEDURE DNNLIS(EL,P: LIST): LIST;
  (* distributive polynomials non-noetherian left irreducible set.
     P is a list of distributive rational polynomials, PP is the
     result of left reducing each p element of P modulo P-(p)
     until no further reductions are possible. *)
  
  PROCEDURE DNNLSP(EL,A,B:LIST):LIST;
  (* distributive polynomials non-noetherian left S-polynomial.
     A and B are polynomials in distributive rational representation
     in 2 variables. C is the left S-polynomial of A and B. *)
 
PROCEDURE DNNLGB(EL,P,TF: LIST): LIST;
(* distributive non-noetherian polynomials left Groebner base.
P is a list of rational polynomials in distributive representation
in 2 variables. PP is the left Groebner base of P. t is the
trace flag. *)
   

PROCEDURE DNNRNF(EL,P,S:LIST):LIST;
  (* distributive polynomials non-noetherian right normal form.
   P is a list of non zero polynomials in distributive rational representation.
   S is a distributive rational polynomial. R is a polynomial such that S is
   right reducible to R modulo P and R is in normal form with respect to P. *)

 
  PROCEDURE DNNRIS(EL,P: LIST): LIST;
  (* distributive polynomials non-noetherian right irreducible set.
     P is a list of distributive rational polynomials, PP is the
     result of right reducing each p element of P modulo P-(p)
     until no further reductions are possible. *)
 

  PROCEDURE DNNRSP(EL,A,B:LIST):LIST;
  (* distributive polynomials non-noetherian right S-polynomial.
     A and B are polynomials in distributive rational representation.
     C is the right S-polynomial of A and B if it exists! *)
 

 PROCEDURE DNNRGB(EL,P,TF: LIST): LIST;
 (* distributive polynomials non-noetherian right Groebner base.
  P is a list of rational polynomials in distributive representation in 
  2 variables. PP is the right Groebner base of P. t is the trace flag. *)



PROCEDURE DNLCPL(EL,P: LIST;  VAR D,B: LIST);
(* distributive polynomial non-noetherian left  construct pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and D is the pairs list. *)


PROCEDURE DNRCPL(EL,P: LIST;  VAR D,B: LIST);
(* distributive polynomial non-noetherian right construct pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and
D is the pairs list. *)

PROCEDURE DNLUPL(EL,PL,P,D,B: LIST): LIST;
(* distributive polynomial non-noetherian left update pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and D is the pairs list. p is a non zero 
polynomial in distributive representation. D, P and B are modified.
DP is the updated pairs list. *)


 PROCEDURE DNRUPL(EL,PL,P,D,B: LIST): LIST;
 (* distributive polynomial non-noetherian right update pair list.
 P is list of polynomials in distributive representation in 2 variables.
 B is the polynomials pairs list and
 D is the pairs list. p is a non zero polynomial in
distributive representation. D, P and B are modified.
DP is the updated pairs list. *)


PROCEDURE DNN2GB(EL,P,TF: LIST): LIST;
(* distributive polynomials non-noetherian 2-sided Groebner base.
P is a list of rational polynomials in distributive representation
in 2 variables. PP is the Groebner base of P. t is the trace flag.*)   



  PROCEDURE DNNTGB(EL,P,TF:LIST):LIST;
  (* distributive polynomials non-noetherian two-sided Groebner base. P is
     a list of rational polynomials in distributive representation in 2
     variables. PP is the two-sided Groebner base of P. t is the trace
     flag. The non-commutative produkt is computed w.r.t Y*X=X**eY. *)



  PROCEDURE DNNLES(EL,P:LIST):LIST;
  (* distributive polynomials non-noetherian left exponents set.
     P is a list of polinomials in distributive representation. PP is the
     the list which is result of *-multiplication of each polynomial of P
     from the left with the main variable. The non-commutative
     multiplication is computed w.r.t the relation Y * X = X**e Y. *)

  

  PROCEDURE DNNRES(EL,P,DL,DP:LIST):LIST;
  (* distributive polynomials non-noetherian right exponents set. P is a
    list of polynomials in distributive representation, d and d'are non-
    negative integers with  d' >= d. PP is the is result of *-multiplication
    of each polynomial of P from the right with exponents (e**i) of the
    first variable in the variable list, where i ranges from d to d'.
    The *-multiplication is computed w.r.t the relation Y * X = X**e Y. *)
    

  PROCEDURE DIPSPS(D,B:LIST):LIST;
  (* distibutive polynomials S-polynomials set.
     D is the pairs list and B is the polynomials pairs list.
     D and B are modified. H is the set of all non-zero S-polynomials. *)
  
PROCEDURE DIPLMD(P:LIST):LIST;
 (* distributive polynomial list maximum degree.
    P is a non-empty list of polynomials in distributive form in r variables.
    d is the maximum degree of all polynomials of P w.r.t the main variable .*)
 
  PROCEDURE IPOWER(EL,AL:LIST):LIST;
  (* integer power. e and a are  positive integers. C=e**a. *)
 

END DINNGB.

(* -EOF- *)
