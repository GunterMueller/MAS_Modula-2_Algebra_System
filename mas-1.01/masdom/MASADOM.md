(* ----------------------------------------------------------------------------
 * $Id: MASADOM.md,v 1.12 1995/03/06 15:53:26 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASADOM.md,v $
 * Revision 1.12  1995/03/06  15:53:26  pesch
 * Added new domain function (FACTO): factorization with variable order
 * optimization.
 *
 * Revision 1.11  1994/11/28  20:56:30  dolzmann
 * New function for the computation of the content and the primitive part of a
 * polynomial.
 *
 * Revision 1.10  1994/11/03  14:42:17  pfeil
 * modified comment
 *
 * Revision 1.9  1994/10/27  13:53:50  rose
 * Some comments corrected.
 *
 * Revision 1.8  1994/06/16  12:54:04  pfeil
 * changed number of parameters in procedure DIPSFF.
 * changed parameter type of procedures SetPFactFunc, SetPSqfrFunc.
 *
 * Revision 1.7  1994/06/10  12:06:49  pfeil
 * Minor changes.
 *
 * Revision 1.6  1994/06/09  14:51:38  pfeil
 * Added ADPFACT, ADPSFF, SetPFactFunc, SetPSqfrFunc for DIPDCGB.
 *
 * Revision 1.5  1994/05/19  10:43:16  rose
 * Added ADPNF, ADPSP, ADPSUGNF, ADPSUGSP, SetPNormFunc, SetPSpolFunc,
 * SetPSugNormFunc, SetPSugSpolFunc in connection with the new module DIPAGB
 *
 * Revision 1.4  1993/05/11  10:35:59  kredel
 * Added QR, REM, ... support
 *
 * Revision 1.3  1992/06/12  13:51:08  kredel
 * Added extended GCD support
 *
 * Revision 1.2  1992/02/12  17:31:36  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:22  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASADOM;

(* MAS Arbitrary Domain Definition Module. *)



FROM MASSTOR IMPORT LIST;


TYPE Domain = LIST; 

CONST rcsid = "$Id: MASADOM.md,v 1.12 1995/03/06 15:53:26 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



TYPE PROCP1 = PROCEDURE(LIST);

     PROCF0 = PROCEDURE(): LIST;
     PROCF1 = PROCEDURE(LIST): LIST;
     PROCF2 = PROCEDURE(LIST,LIST): LIST;

     PROCF1B = PROCEDURE(LIST): BOOLEAN;

     PROCF1V1 = PROCEDURE(LIST, VAR LIST):LIST;

     PROCP1V2 = PROCEDURE(LIST, VAR LIST, VAR LIST );
     PROCP2V2 = PROCEDURE(LIST,LIST,VAR LIST,VAR LIST);

     PROCP2V3 = PROCEDURE(LIST,LIST,VAR LIST,VAR LIST,VAR LIST);



PROCEDURE ADABSF(A:LIST):LIST;
(*Arbitrary domain absolute value. *)


PROCEDURE ADCNST(A: LIST): BOOLEAN; 
(*Arbitrary domain constant test. Returns true iff A is a constant. *)


PROCEDURE ADCOMP(A,B:LIST):LIST;
(*Arbitrary domain comparison. c=sign(a-b). *)


PROCEDURE ADCONV(A,B: LIST): LIST; 
(*Arbitrary domain conversion. c=b:domain(a). *)


PROCEDURE ADDIF(A,B: LIST): LIST; 
(*Arbitrary domain difference. c=a-b. *)


PROCEDURE ADEXP(A,NL: LIST): LIST; 
(*Arbitrary domain exponentiation. c=a**nl. *)


PROCEDURE ADFACT(A: LIST): LIST; 
(*Arbitrary domain factorization. Returns a list containing
all prime factors of A.*)


PROCEDURE ADFACTO(A: LIST): LIST; 
(*Arbitrary domain factorization with variable order optimization.
A is an arbitrary domain polynomial.
Returns a list containing all prime factors of A.*)


PROCEDURE ADFI(D,A: LIST): LIST; 
(*Arbitrary domain from integer. D is a domain element and A is an 
integer. *)


PROCEDURE ADFIP(D,A: LIST): LIST; 
(*Arbitrary domain from integral polynomial. D is a domain element and 
A is an integral polynomial in #vldd(D) variables. *)


PROCEDURE ADGCD(A,B: LIST): LIST;
(*Arbitrary domain greatest common divisor. c=gcd(a,b). *)


PROCEDURE ADGCDC(A,B: LIST; VAR C,AA,BB: LIST);
(*Arbitrary domain greatest common divisor and cofactors.
C=gcd(A,B), A=C*AA, B=C*BB, if C=0 then AA=BB=0.
If gcd is undefined for the current domain then C:=1, AA:=A, BB:=B. *)


PROCEDURE ADGCDE(A,B: LIST; VAR C,AA,BB: LIST);
(*Arbitrary domain greatest common divisor and linear combination.
C=gcd(A,B), C=A*AA+B*BB.
If gcd is undefined for the current domain then C:=1, AA:=0, BB:=0. *)


PROCEDURE ADINV(A: LIST): LIST; 
(*Arbitrary domain inverse. c=1/a. *)


PROCEDURE ADINVT(A: LIST): LIST; 
(*Arbitrary domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)


PROCEDURE ADLCM(A,B: LIST): LIST; 
(*Arbitrary domain least common multiple. c=lcm(a,b). *)


PROCEDURE ADNEG(A: LIST): LIST; 
(*Arbitrary domain negative. c=-a. *)


PROCEDURE ADONE(A: LIST): LIST; 
(*Arbitrary domain one. sl=1 if a=1, sl ne 1 else. *)

PROCEDURE ADPCPP(P: LIST; VAR c, pp: LIST);
(* Arbitrary domain polynomial content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The content of c and its primitive part is returned. 
It holds P=c * pp.
If the domain is a field then HC(pp)=1. 
If ADSIGN is defined in the domain, then ADSIGN(HC(p))>=0. *)


PROCEDURE ADPROD(A,B: LIST): LIST; 
(*Arbitrary domain product. c=a*b. *)


PROCEDURE ADQR(A,B:LIST; VAR Q,R:LIST);
(*Arbitrary domain quotient and remainder. q=a/b, r=a-(a/b)*b. *)


PROCEDURE ADQUOT(A,B: LIST): LIST; 
(*Arbitrary domain quotient. c=a/b. *)


PROCEDURE ADREAD(D: LIST): LIST; 
(*Arbitrary domain read. d is the domain descriptor. *)


PROCEDURE ADREM(A,B:LIST):LIST;
(*Arbitrary domain remainder. r=a-(a/b)*b. *)


PROCEDURE ADSIGN(A: LIST): LIST; 
(*Arbitrary domain sign. cl=sign(a). *)


PROCEDURE ADSUM(A,B: LIST): LIST; 
(*Arbitrary domain sum. c=a+b. *)


PROCEDURE ADTOIP(A: LIST; VAR LCM: LIST): LIST;
(*Arbitrary domain to integral polynomial conversion.
LCM is the lcm of coefficient-denominators *)


PROCEDURE ADWRIT(A: LIST); 
(*Arbitrary domain write. *)


PROCEDURE ADDDREAD(): LIST; 
(*Arbitrary domain, domain descriptor read. A domain element with 
descriptor D is read from the input stream. *)


PROCEDURE ADDDWRIT(D: LIST); 
(*Arbitrary domain, domain descriptor write. d is a domain element with
descriptor. d is written to the output stream. *)


PROCEDURE ADVLDD(D: LIST): LIST; 
(*variable list from domain descriptor. d is a domain element with 
descriptor. if the domain depends on some variables, then
the related variable list is returned, otherwise the empty
list is returned. *)


(* -------------- *)


PROCEDURE SetAbsFunc(d: Domain; f1: PROCF1);
(*Set absolute value function in domain. d is a domain 
and f1 is a function of one LIST argument. *)


PROCEDURE SetCnstFunc(d: Domain; f1: PROCF1B);
(*Set constant test function in domain. d is a domain 
and f1 is a boolean-function of one LIST argument. *)


PROCEDURE SetCompFunc(d: Domain; f2: PROCF2);
(*Set comparison function in domain. d is a domain 
and f2 is a function of two LIST arguments. *)


PROCEDURE SetConvFunc(d1, d2: Domain; f1: PROCF1);
(*Set conversion function in domain. d1 and d2 are domains and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetDifFunc(d: Domain; f2: PROCF2);
(*Set difference function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetExpFunc(d: Domain; f2: PROCF2);
(*Set exponential function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetFactFunc(d: Domain; f1: PROCF1);
(*Set factorization function in domain. d is a domain
and f1 is a function of one LIST argument. *)


PROCEDURE SetFIntFunc(d: Domain; f2: PROCF2);
(*Set from integer function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetFIPolFunc(d: Domain; f2: PROCF2);
(*Set from integral polynomial function in domain. d is a domain 
and f2 is a function of two LIST arguments. *)


PROCEDURE SetGcdFunc(d: Domain; f2: PROCF2);
(*Set gcd function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetGcdcFunc(d: Domain; p2v3: PROCP2V3);
(*Set gcd-and-cofactors function in domain. d is a domain
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)


PROCEDURE SetGcdeFunc(d: Domain; p2v3: PROCP2V3);
(*Set gcd-and-lin-combination function in domain. d is a domain
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)


PROCEDURE SetInvFunc(d: Domain; f1: PROCF1);
(*Set inversion function in domain. d is a domain and 
f is a function of one LIST argument. *)


PROCEDURE SetInvTFunc(d: Domain; f1: PROCF1);
(*Set inversion test function in domain. d is a domain and 
f is a function of one LIST argument. *)


PROCEDURE SetLcmFunc(d: Domain; f2: PROCF2);
(*Set lcm function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetNegFunc(d: Domain; f1: PROCF1);
(*Set negation function in domain. d is a domain and 
f is a function of one LIST argument. *)


PROCEDURE SetOneFunc(d: Domain; f1: PROCF1);
(*Set one test function in domain. d is a domain and 
f is a function of one LIST argument. *)

PROCEDURE SetPCppFunc(d:Domain; p1v2: PROCP1V2);
(* Set Content and primitive part function. d is a domain and
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)


PROCEDURE SetProdFunc(d: Domain; f2: PROCF2);
(*Set product function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetQrFunc(d: Domain; p2v2: PROCP2V2);
(*Set quotient and remainder function in domain. d is a domain 
and p2v2 is a procedure of 2 LIST and 2 var LIST arguments. *)


PROCEDURE SetQuotFunc(d: Domain; f2: PROCF2);
(*Set quotient function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetReadFunc(d: Domain; f1: PROCF1);
(*Set read function in domain. d is a domain and 
f1 is a function of one LIST argument. *)


PROCEDURE SetRemFunc(d: Domain; f2: PROCF2);
(*Set remainder function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)


PROCEDURE SetSignFunc(d: Domain; f1: PROCF1);
(*Set sign function in domain. d is a domain and 
f1 is a function of one LIST argument. *)


PROCEDURE SetSumFunc(d: Domain; f2: PROCF2);
(*Set sum function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
 

PROCEDURE SetToipFunc(d: Domain; f1v1: PROCF1V1);
(*Set conversion-to-integer-polynomial function in domain. d is a domain 
and f1v1 is a function of one LIST and one VAR LIST argument. *)


PROCEDURE SetWritFunc(d: Domain; p1: PROCP1);
(*Set write function in domain. d is a domain and 
p1 is a procedure of one LIST argument. *)


PROCEDURE SetVlddFunc(d: Domain; f1: PROCF1);
(*Set variable list from domain descriptor function in domain. 
d is a domain and f is a function of one LIST argument. *)


PROCEDURE SetDdrdFunc(d: Domain; f0: PROCF0);
(*Set domain descriptor read function in domain. d is a domain 
and f0 is a function with no arguments. *)


PROCEDURE SetDdwrFunc(d: Domain; p1: PROCP1);
(*Set domain descriptor write function in domain. d is a domain 
and p1 is a procedure of one LIST argument. *)



PROCEDURE NewDom(S, s: ARRAY OF CHAR): Domain;
(*New domain. S is a domain identificator and s is a domain name. 
A new domain is returned. *)


PROCEDURE DomSummary(); 
(*Arbitrary domain summary. A summary of all defined domains 
is written to the output stream. *)


(* -------------- *)


PROCEDURE ADPFACT(P,VOO: LIST): LIST; 
(* Arbitrary domain polynomial factorization.
   P is a polynomial in distributive representation
   over an arbitrary domain,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns the list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where P = u * f1**e1 * ... * fk**ek and u unit. *)
(* the ordering of the factors is non-deterministic !! *)


PROCEDURE ADPNF(G,P: LIST): LIST;
(* Arbitrary domain polynomial normalform.
   G is a list of polynomials in distributive
   representation over an arbitrary domain,
   P is a polynomial as above,
   returns a polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)


PROCEDURE ADPSFF(A,VOO: LIST): LIST;
(* Arbitrary domain polynomial squarefree factorization.
   A is a polynomial in distributive representation
   over an arbitrary domain,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,p1),...,(ek,pk)), ei positive integers,
   pi squarefree polynomials in distributive representation,
   where A = u * p1**e1 * ... * pk**ek and u unit. *)


PROCEDURE ADPSP(A,B: LIST): LIST;
(* Arbitrary domain polynomial S-polynomial.
   A and B are polynomials in distributive
   representation over an arbitrary domain,
   returns the S-polynomial of A and B *)


PROCEDURE ADPSUGNF(G,P: LIST): LIST;
(* Arbitrary domain polynomial normal with sugar strategy normalform.
   G is a list of extended polynomials in distributive representation over an
   arbitrary domain,
   P is an extended polynomial as above,
   returns an extended polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)


PROCEDURE ADPSUGSP(A,B: LIST): LIST;
(* Arbitrary domain polynomial normal with sugar strategy S-polynomial.
   A and B are extended polynomials in distributive
   representation over an arbitrary domain,
   returns the extended S-polynomial of A and B *)


(* -------------- *)


PROCEDURE SetPFactFunc(d: Domain; f1: PROCF1);
(* Set factorization function in domain.
   d is a domain and f1 is a function of one LIST argument. *)


PROCEDURE SetFactoFunc(d: Domain; f1: PROCF1);
(*Set factorization with variable order optimization function in domain. 
d is a domain and f1 is a function of one LIST argument. *)


PROCEDURE SetPNormFunc(d: Domain; f2: PROCF2);
(* Set polynomial normalform function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)


PROCEDURE SetPSqfrFunc(d: Domain; f1: PROCF1);
(* Set polynomial squarefree factorization function in domain.
   d is a domain and f1 is a function of one LIST argument. *)


PROCEDURE SetPSpolFunc(d: Domain; f2: PROCF2);
(* Set polynomial S-polynomial function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
 

PROCEDURE SetPSugNormFunc(d: Domain; f2: PROCF2);
(* Set polynomial normal with sugar strategy normalform function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)


PROCEDURE SetPSugSpolFunc(d: Domain; f2: PROCF2);
(* Set polynomial normal with sugar strategy S-polynomial function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
 

END MASADOM.

(* -EOF- *)








