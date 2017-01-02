(* ----------------------------------------------------------------------------
 * $Id: DIPAGB.md,v 1.3 1994/10/13 15:58:20 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPAGB.md,v $
 * Revision 1.3  1994/10/13  15:58:20  rose
 * Some more procedures exported.
 *
 * Revision 1.2  1994/06/06  17:15:52  rose
 * Syntactical errors (found by Mocka) corrected.
 *
 * Revision 1.1  1994/05/19  10:42:27  rose
 * New module DIPAGB. Computes a Groebner basis with the second Buchberger
 * criterion (Gebauer/Moeller).
 * Implemented critical pair selection strategies: normal, normal with sugar.
 *
 * ----------------------------------------------------------------------------
 *)


DEFINITION MODULE DIPAGB;

(* DIP Arbitrary Domain Groebner Basis Definition Module. *)


FROM MASSTOR  IMPORT LIST;

FROM MASLISPU IMPORT PROCF1, PROCF2, PROCP0, PROCP1, PROCP1V2;

CONST Normal          = 0;
CONST NormalWithSugar = 1;


CONST rcsid = "$Id: DIPAGB.md,v 1.3 1994/10/13 15:58:20 rose Exp $";
CONST copyright = "Copyright (c) 1989 - 1994 Universitaet Passau";



PROCEDURE ADDNFEDIP(f: LIST): LIST;
(* Arbitrary domain domain number from extended distributive polynomial.
   f is an extended distributive polynomial over an arbitrary domain polynomial
   ring. The domain number of the arbitrary domain is returned. If the
   unextended distributive polynomial appropriate to f is the zero polynomial
   then 0 is returned. *)


PROCEDURE CPEXTEND(f,g: LIST): LIST;
(* Critical pair extend.
   f and g are distributive polynomials such that (f,g) is a critical pair.
   CPEXTEND(f,g) is the appropriate extended critical pair, i.e. the list of
   f, g and further components which depend on the chosen extended critical
   pair selection strategy. *)


PROCEDURE DIPAGB(F: LIST): LIST;
(* Distributive polynomial arbitrary domain Groebner basis.
   F is a list of polynomials in distributive representation.
   G=DIPAGB(F) is a (not reduced) Groebner basis with Id(G)=Id(F). *)


PROCEDURE DIPEXTEND(f: LIST): LIST;
(* Distributive polynomial extension.
   f is a polynomial in distributive representation.
   DIPEXTEND(f) is the extended distributive polynomial appropriate to f. *)


PROCEDURE DIPRWTDG(f,W: LIST): LIST;
(* Distributive polynomial rational-weighted total degree.
   f is a polynomial in distributive representation in r variables.
   W=(W1,...,Wr) is a list of rational numbers, where Wi, 1 le i le r, is the
   weight of the (r-i+1)-th variable in the variable list VALIS, i.e. of the
   variable w.r.t. the i-th component in each exponent vector of f.
   DIPRWTDG(f,W) is the rational-weighted total degree of f, defined by the
   maximal rational-weighted total degree of the exponent vectors of the terms
   of f. *)


PROCEDURE ECPINSERT(CP,P: LIST): LIST;
(* Extended critical pair insertion.
   The extended critical pair CP is to be inserted into the extended critical
   pair list P.
   ECPINSERT(CP,P) is the list P with the additional pair CP. *)


PROCEDURE ECPLCMHT(CP: LIST): LIST;
(* Extended critical pair select the least common multiple of head terms.
   ECPLCMHT(CP) is the extended least common multiple of the leadings terms
   of the two extended polynomials in the extended critical pair CP. *)


PROCEDURE ECPPOLY1(CP: LIST): LIST;
(* Extended critical pair select the first extended distributive polynomial. *)


PROCEDURE ECPPOLY2(CP: LIST): LIST;
(* Extended critical pair select the second extended distributive
   polynomial. *)


PROCEDURE ECPSELECT(P: LIST; VAR CP,Q: LIST);
(* Select an extended critical pair from the extended critical pair list.
   The extended critical pair list is modified. *)


PROCEDURE ECPSUGAR(CP: LIST): LIST;
(* Extended critical pair select sugar.
   ECPSUGAR(CP) is the sugar of the S-polynomial of the polynomials in the
   extended critical pair CP. *)


PROCEDURE ECPUNEXTEND(CP: LIST): LIST;
(* Extended critical pair un-extend.
   CP is an extended critical pair.
   ECPUNEXTEND(CP) is the appropriate critical pair, i.e. CP without the
   extensions which depend on the chosen extended critical pair selection
   strategy. *)


PROCEDURE ECPWRITE(CP: LIST);
(* Extended critical pair write.
   The extended critical pair CP is written in the output stream. *)


PROCEDURE EDIIFSUGNF(P,f: LIST): LIST;
(* Extended distributive integral function polynomial normal with sugar
   strategy normal form.
   P is a list of non-zero extended distributive integral function polynomials.
   f is an extended distributive integral function polynomial.
   EDIIFSUGNF(P,f) is an extended distributive integral function polynomial
   such that f is reducible to EDIIFSUGNF(P,f) modulo P and EDIIFSUGNF(P,f) is
   in normalform w.r.t. P. *)


PROCEDURE EDIIFSUGSP(f,g: LIST): LIST;
(* Extended distributive integral function polynomial normal with sugar
   strategy S-polynomial.
   f and g are extended distributive integral function polynomials.
   EDIIFSUGSP(f,g) is the extended S-polynomial of f and g w.r.t. the normal
   with sugar strategy. *)


PROCEDURE EDIPEVL(f: LIST): LIST;
(* Extended distributive polynomial exponent vector of the leading monomial.
   f is an extended distributive polynomial.
   EDIPEVL(f) is the exponent vector of the leading monomial of f. *)


PROCEDURE EDIPNOR(P,f: LIST): LIST;
(* Extended distributive polynomial normal form.
   P is a list of non-zero extended distributive polynomials.
   f is an extended distributive polynomial.
   EDIPNOR(P,f) is an extended distributive polynomial such that f is reducible
   to EDIPNOR(P,f) modulo P and EDIPNOR(P,f) is in normalform w.r.t. P. *)


PROCEDURE EDIPSP(f,g: LIST): LIST;
(* Extended distributive polynomial S-polynomial.
   f and g are extended distributive polynomials.
   EDIPSP(f,g) is the extended S-polynomial of f and g. *)


PROCEDURE EDIPSUGAR(f: LIST): LIST;
(* Extended distributive polynomial sugar.
   EDIPSUGAR(f) is the sugar of the extended distributive polynomial f. *)


PROCEDURE EDIPSUGCON(f,S: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy constructor.
   f is a distributive polynomial.
   S is the sugar of f.
   EDIPSUGCON(f,S) is the extended distributive polynomial appropriate to f
   with sugar S. *)


PROCEDURE EDIPSUGNOR(P,f: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy normal form.
   P is a list of non-zero extended distributive polynomials.
   f is an extended distributive polynomial.
   EDIPSUGNOR(P,f) is an extended distributive polynomial such that f is
   reducible to EDIPSUGNOR(P,f) modulo P and EDIPSUGNOR(P,f) is in normalform
   w.r.t. P. *)


PROCEDURE EDIPSUGSP(f,g: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy S-polynomial.
   f and g are extended distributive polynomials.
   EDIPSUGSP(f,g) is the extended S-polynomial of f and g w.r.t. the normal
   with sugar strategy. *)


PROCEDURE EDIPUNEXTEND(f: LIST): LIST;
(* Extended distributive polynomial un-extend.
   f is an extended distributive polynomial.
   EDIPUNEXTEND(f) is the distributive polynomial appropriate to f. *)


PROCEDURE EDIPWRITE(f: LIST);
(* Extended distributive polynomial write.
   The extended distributive polynomial f is written in the output stream. *)


PROCEDURE EVRWTDEG(U,W: LIST): LIST;
(* Exponent vector rational-weighted total degree.
   U=(U1,...,Ur) is an exponent vector.
   W=(W1,...,Wr) is a list of rational numbers, where Wi, 1 le i le r, is the
   weight of the (r-i+1)-th variable in the variable list VALIS, i.e. of the
   variable w.r.t. the i-th component of U.
   TD=EVRWTDEG(U,W) is the rational-weighted total degree of U, defined by
   TD = W1U1+...+WrUr. *)


PROCEDURE INITUPDATE(f: LIST; VAR G,B: LIST);
(* The initialization function as a first call of UPDATE. *)


PROCEDURE LDIPEXTEND(P: LIST): LIST;
(* List of distributive polynomials extend.
   P is a list of distributive polynomials.
   LDIPEXTEND(P) is the list of the appropriate extended distributive
   polynomials. *)


PROCEDURE LECPUNEXTEND(P: LIST): LIST;
(* List of extended critical pairs un-extend.
   P is a list of extended critical pairs.
   LECPUNEXTEND(P) is the list of the appropriate critical pairs. *)


PROCEDURE LECPWRITE(P: LIST);
(* List of extended critical pairs write.
   The list P of extended critical pairs is written in the output stream. *)


PROCEDURE LEDIPUNEXTEND(P: LIST): LIST;
(* List of extended distributive polynomials un-extend.
   P is a list of extended distributive polynomials.
   LEDIPUNEXTEND(P) is the list of the appropriate distributive polynomials. *)


PROCEDURE LEDIPWRITE(P: LIST);
(* List of extended distributive polynomials write.
   The list P of extended distributive polynomials is written in the output
   stream. *)


PROCEDURE LRNWRIT(LRN: LIST);
(* List of rational numbers write.
   The list LRN of rational numbers is written in the output stream. *)


PROCEDURE UPDATE(h: LIST; VAR G,B: LIST);
(* Update of extended ideal basis and extended critical pair list as required
   by DIPAGB.
   h is an extended distributive polynomial, G is a list of extended
   distributive polynomials. B is a list of extended critical pairs. *)


PROCEDURE UpdateVariableWeight;
(* Update of the DIPAGB variable weight list. *)


(* ------------------------------------------------------------------------- *)


PROCEDURE SetDIPAGBOptions(OPT: LIST);
(* Set the trace flag, the strategy and the variable weight list of the
   DIPAGB option record. *)


PROCEDURE SetDIPAGBStrategy(st: LIST);
(* Set the DIPAGB strategy option for the extended critical pair selection.
   st=0 (= normal) and st=1 (= normal with sugar) are supported. *)


PROCEDURE SetDIPAGBTraceFlag(tf: LIST);
(* Set the DIPAGB trace flag.
   tf is a non-negative integer level for interactive documentations. *)


PROCEDURE SetDIPAGBVariableWeight(VW: LIST);
(* Set the DIPAGB variable weight list for the normal with sugar strategy.
   VW is a list of r non-negative rational components where r is the number of
   variables in the distributive polynomials handled with. The i-th component
   is the weight of the i-th variable in the variable list VALIS. *)


PROCEDURE SetCPExtend(EXT: PROCF2);
(* Set the critical pair extension function. *)


PROCEDURE SetDIPExtend(EXT: PROCF1);
(* Set the distributive polynomial extension function. *)


PROCEDURE SetECPInsert(INS: PROCF2);
(* Set the extended critical pair insertion function. *)


PROCEDURE SetECPSelect(SEL: PROCP1V2);
(* Set the extended critical pair selection procedure. *)


PROCEDURE SetECPWrite(WR: PROCP1);
(* Set the extended critical pair write procedure. *)


PROCEDURE SetEDIPNormalform(NF: PROCF2);
(* Set the extended distributive polynomial normalform function. *)


PROCEDURE SetEDIPSPolynomial(SP: PROCF2);
(* Set the extended distributive S-polynomial function. *)

 
PROCEDURE SetEDIPUnExtend(UEXT: PROCF1);
(* Set the extended distributive polynomial un-extension function. *)


PROCEDURE SetEDIPWrite(WR: PROCP1);
(* Set the extended distributive polynomial write procedure. *)


PROCEDURE SetInit(INIT: PROCP1V2);
(* Set the initialization procedure. *)


PROCEDURE SetUpdate(UPD: PROCP1V2);
(* Set the update procedure. *)


PROCEDURE SetUpdateVariableWeight(UPD: PROCP0);
(* Set the DIPAGB variable weight update procedure. *)


PROCEDURE WriteDIPAGBOptions;
(* Write the current trace flag, strategy and variable weight list of the
   DIPAGB option record in the output stream. *)


PROCEDURE WriteDIPAGBStrategy;
(* Write the DIPAGB strategy option for the extended critical pair selection
   in the output stream. *)


PROCEDURE WriteDIPAGBTraceFlag;
(* Write the DIPAGB trace flag in the output stream. *)


PROCEDURE WriteDIPAGBVariableWeight;
(* Write the DIPAGB variable weight list in the output stream. *)


END DIPAGB.

(* -EOF- *)
