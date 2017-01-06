(* ----------------------------------------------------------------------------
 * $Id: CGBMAIN.md,v 1.8 1996/04/24 12:09:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1996 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: CGBMAIN.md,v $
 * Revision 1.8  1996/04/24 12:09:59  pesch
 * Used EVOWRITE instead of WRORD for writing term orders.
 * Removed WRORD.
 * Reformatted import lists.
 *
 * Revision 1.7  1995/03/06  15:49:39  pesch
 * Added new procedure GSYSF, Groebner system with factorization. This uses
 * the new procedures GBSYSF and CONSGBF (also added).
 *
 * Added new procedures DIP2AD, AD2DIP and DIPPFACTAV.
 *
 * Fixed error in CHECK.
 *
 * New option for factorization of conditions: factorize with optimization
 * of variable ordering.
 *
 * Revision 1.6  1994/04/09  18:05:57  pesch
 * Reformatted parts of the CGB sources. Updated comments in CGB*.md.
 *
 * Revision 1.5  1994/03/30  14:41:11  pesch
 * Added new function GSYSRED.
 * Replaced some FIRST's,... by contructors.
 *
 * Revision 1.4  1994/03/14  16:42:56  pesch
 * Minor changes requested by A. Dolzmann
 *
 * Revision 1.3  1994/03/11  15:58:12  pesch
 * Major changes to CGB.
 * C-Preprocessor now used for .mip files. The corresponding .mi files have
 * been removed.
 * Many new CGB-Functions and fixes of old ones.
 *
 * Revision 1.2  1992/02/12  17:31:16  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:08:56  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE CGBMAIN;

(* Comprehensive-Groebner-Bases Main Programms Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: CGBMAIN.md,v 1.8 1996/04/24 12:09:59 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1996 Universitaet Passau";

PROCEDURE CDINIT(CD: LIST): LIST;
(* Case distinction init. 
CD is a case distinction.
Returns a case distinction with conditions as required by PAR.Cond*. *)

PROCEDURE GSYS(CDP: LIST): LIST;
(* Groebner system.
CDP is case distinction and polynomial set.
Returns a Groebner system for CDP. *)

PROCEDURE GSYSF(CDP: LIST): LIST;
(* Groebner system with factorization.
CDP is case distinction and polynomial set.
Returns a Groebner system for CDP. *)

PROCEDURE GSYSDIM(GS: LIST): LIST;
(* Groebner system dimension.
GS is a Groebner system.
Returns the parametric dimension for GS.
*)

PROCEDURE DIMIS(PL,VL: LIST; VAR MAXVL: LIST): LIST; 
(* Dimension and maximal independent set.
PL is a list of polynomials.
VL is the variable list.
MAXVL need not be initialized.
Returns the dimension of PP and a maximal independent set in MAXVL. *)

PROCEDURE GSYSRED(GS: LIST): LIST;
(* Reduce Groebner system.
GS is a Groebner system.
Returns a reduced Groeber system for GS.
*)

PROCEDURE CGBFGSYS(S: LIST): LIST;
(* Comprehensive Groebner basis from Groebner system.
S is a Groebner system.
Returns a comprehensive Groebner basis.
*)

PROCEDURE CGBGLOBRED(CGB: LIST): LIST;
(* Comprehensive Groebner basis global reduce.
CGB is a comprehensive Groebner basis.
Returns a global reduced comprehensive Groebner basis.
*)

(* obsolete *) PROCEDURE CGBQFWRITE(CGB: LIST);

PROCEDURE CGBQFF(CGB: LIST): LIST;
(* Comprehensive Groebner basis quantifier free formula.
CGB is a comprehensive Groebner basis.
Returns a formula containing a condition for the existence of common zeroes
of the polynomials in CGB.
*)


(***********************************************)
(* The following is mostly obsolete -- mp      *)
(***********************************************)

PROCEDURE CGBIN(); 
(*Comprehensive-Groebner-Basis input. The input is read from the
stream. Start computation by call of CGBOUT. *)


PROCEDURE CGBOUT(AC: LIST); 
(*Comprehensive-Groebner-Basis execute and output.
AC contains the input data set ( case distinction, 2 polynomial
systems, polynomial descriptor, list of options ). *)


PROCEDURE DVREAD(): LIST; 
(*Polynom descriptor read. *)




PROCEDURE CONINI(VD: LIST): LIST; 
(*Initialize case distinction. VD is the domain descriptor. CONS is
the case distinction read from the input stream. *)


PROCEDURE CONDRD(V,D,B,DALT: LIST; VAR DNEU: LIST); 
(* Conditions read.  V is the variables list, D is the domain
descriptor, DALT is a case distinction.
DNEU contains DALT and new coefficients, which
are zero, if B=0. If B=1 they are not zero. *)


PROCEDURE UPDCAS(ALIST,DALT,B: LIST): LIST; 
(*Update case distinction. ALIST is a list of coefficients (a1,... ,an).
DALT is a case distinction. If B=0 then DNEU is a case distinction
including DALT and ( a1=0,... , an=0 ). If B=1 then DNEU is a
case distinction including DALT and (a1<>0,... , an<>0).
ADDCON computes a complete case distinction including DALT and
(a1,... ,an). Then the well formed conditions are composed. *)


PROCEDURE CCOVER(CONS: LIST): LIST; 
(*Cover condition. CONS is a case distinction. C is a condition, so
that CONS covers C. *)


PROCEDURE SCOV(CONDA,CONS,B: LIST): LIST; 
(* Search condition. CONDA is a list of coefficients. 
CONS is a list of conditions. If B=0 then SCOV returns all 
coefficients, that are in CONDA and in the zero list of each 
condition in CONS. If B=1 then SCOV returns all coefficients, 
that are in CONDA and in the not-zero list of each condition in 
CONS. *)


PROCEDURE CHDOM(CONDS,PPS: LIST; VAR CONS,PP: LIST); 
(*Change domain. CONDS is a case distinction. PPS is a list of
polynomials with coefficient from an arbitrary domain. This list is
converted to a list PP of integral polynomials. Each polynomial
containing fractions, is mutliplied with the lcm of the coefficient-
denominators. CONS contains CONDS and conditions to assure that 
the prime-factors of each lcm are not zero. This procedure makes 
sense for rational-polynomials only. For integral-polynomials it 
will work, but create overhead by copying PPS to PP *)


PROCEDURE EXECRD(): LIST; 
(*Exec read. The list nrlist of options is read from the input
stream. *)


PROCEDURE SEENR(AC: LIST; VAR NR: LIST); 
(*Find key for option. AC is an option. NR is the key for AC. *)


PROCEDURE WRTITL(NR: LIST); 
(*Write title. *)


PROCEDURE WRGBS(PLS: LIST); 
(*Write groebner-system. PLS is a list of
pairs, each pair containing a condition and a polynomials list,
where each polynomial is coloured wrt the condition. The conditions
and the polynomials are written on the output stream, sorted by
polynomial systems. *)


PROCEDURE WRCGB(CGB,I: LIST); 
(*Write comprehensive-groebner-basis. CGB is a list of coloured
polynomials forming a comprehensive-groebner-basis. I is the number of
conditions of the groebner-system. CGB and I are written on the
output stream. *)


PROCEDURE WRRCGB(CGB,I: LIST); 
(*Write reduced comprehensive-groebner-basis. CGB is a list of coloured
polynomials forming a reduced comprehensive-groebner-basis. I is the
number of conditions of the groebner-system. CGB and I are
written on the output stream. *)


PROCEDURE GGREEN(GS: LIST); 
(*Write groebner-system without green monomials. GS is a list of
pairs, each pair containing a condition and a polynomials list,
where each polynomial is coloured wrt the condition. The conditions
and the polynomials are written on the output stream without green
coloured monomials. *)


PROCEDURE NWRIT0(N: LIST); 
(*Normalforms write. N is a set of tripels each containing a condition,
a polynomial coloured green wrt the condition and a factor c. The
polynomials form a set of normalforms. The conditions and the factors
are written on the output stream. *)


PROCEDURE NWRIT1(N: LIST); 
(*Normalforms write. N is a set of tripels each containing a condition,
a polynomial not coloured green wrt the condition and a factor c. The
polynomials form a set of normalforms. The conditions, the polynomials
and the factors are written on the output stream. *)


PROCEDURE WPAIRS(PS: LIST); 
(*Write pairs of polynomials. PS is a list of tripels, each tripel
containing two coloured polynomials and the product of their highest
terms wrt their colour. The polynomials are written on the output
stream. *)


PROCEDURE WPLIST(PL: LIST); 
(*Write polynomials and pairs. PL is a list of tripels, each tripel
containing a condition, a set of polynomials coloured wrt the
condition and a set of pairs of polynomials, constructed from
the set of polynomials. The condition, the polynomials and the
pairs are written on the output stream. *)


PROCEDURE NFWRIT(NOUT: LIST); 
(*Normalforms write. The polynomials for which the test for parametric
ideal membership has been executed are written on the output stream
their normalforms. For each polynomial the quantifier free formula
is written on the output stream. *)

END CGBMAIN.
(* -EOF- *)
