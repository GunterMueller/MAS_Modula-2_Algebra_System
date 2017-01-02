(* ----------------------------------------------------------------------------
 * $Id: TFORM.md,v 1.2 1995/11/04 18:00:33 pesch Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: TFORM.md,v $
 * Revision 1.2  1995/11/04 18:00:33  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.1  1994/11/28  21:10:07  dolzmann
 * New modules PQBASE.md and PQBASE.mi:
 *   Procedures for the manipulating first oder formulas over the language of
 *   ordered rings.
 * New modules RQEPRRC.md and RQEPRRC.mi:
 *   Procedures for the real quantifier elimination.
 * New modules TFORM.md and TFORM.mi:
 *   Procedures for the computation of type formulas.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE TFORM;
(* Type Formula Definition Module. *)

FROM MASLISPU	IMPORT	PROCF2; 
FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: TFORM.md,v 1.2 1995/11/04 18:00:33 pesch Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

TYPE TfClass=(Tfgood, Tfbad, Tfdontcare, Tfimpossible);


(******************************************************************************
*                        A T O M I C _ F O R M U L A S                        *
******************************************************************************)

PROCEDURE tfmkaf(rel:LIST;idl:LIST):LIST;
(* type formula make atomic formula.
rel is a relation, idl is a list of atoms, 
the atomic formula (rel,idl) is returned. *)

PROCEDURE tfpaf(af:LIST; VAR rel,idl:LIST);
(* type formula parse atomic formula. 
af is an atomic formula; 
the relation symbol of af is in rel returned; 
the list of identifiers is in id returned. *)

PROCEDURE tfgrel(af:LIST):LIST;
(* type formula get relation symbol. af 
is an atomic formula. 
The relation symbol of af is returned. *)


(******************************************************************************
*                       M A S L O G   I N T E R F A C E                       *
******************************************************************************)

PROCEDURE TFPPRT(phi:LIST);
(* type formula pretty print. 
phi is a tf-formula; 
this procedure writes the formula phi formatted in the output stream. *)

PROCEDURE TFIREAD():LIST;
(* type formula infix read. 
A type formula is read from the input stream. *)


(******************************************************************************
*                     E X T E R N A L   I N T E R F A C E                     *
******************************************************************************)

PROCEDURE TfUseDb();
(* type formula use data base. 
The global variable TypeFormulaProc is set.
Type formulas are computed only if they are not stored in the data base. *)

PROCEDURE TfComputeTf();
(* type formula compute type formulas. 
The global variable TypeFormulaProc is set.
The data base of type formulas is not used. *)

PROCEDURE TfTypeFormula(deg: LIST):LIST;
(* type formula type formula.
A type formula for polynomials of degree deg > 0 is returned. 
This is the interface for other modules. *)


(******************************************************************************
* E F F I C I E N T   C O M P U T A T I O N   O F   T Y P E   F O R M U L A S *
******************************************************************************)

PROCEDURE ComputeTypeFormula(deg: LIST):LIST;
(* compute type formula. 
deg is an atom > 0.
A type formula for polynomials of degree deg is returned. *)

PROCEDURE UseDb(deg: LIST): LIST;
(* Use data base. 
A type formula for polynomials of degree deg > 0 is returned. 
If the type formula is already stored in the data base, this formula
is returned. Otherwise the type formula is computed, stored in the 
data base and returned. 
Type formulas are stored in files with the name TF.d.db, where 
d is the degree of the type formula.  *)

PROCEDURE TFGENJ(deg: LIST):LIST;
(* type formula generate with joker argument. 
deg is an even atom greater than 1.
computed. The computed formula is returned. 
A strict type formula for polynomials of degree deg is computed.
The joker argument is used in order to reduce the size of the type formula. *)

PROCEDURE TfRecBasis(deg:LIST):LIST;
(* type formula recursion basis. 
deg is an atom < 6. 
A type formula for polynomials with degree deg is returned. *)
	
PROCEDURE TfCtj(deg: LIST):LIST;
(* type formula coefficient tuples with joker argument.
deg is an even atom.
All good coefficients tuples with of polynomials of degree deg are computed.
*)
		
(******************************************************************************
*                            M I S C E L L A N E A                            *
******************************************************************************)


PROCEDURE TfShiftVars(phi,offset: LIST):LIST;
(* type formula shift variables. 
phi is a type formula,
offset is an atom. 
All identifiers are shifted at offset positions to the right. *)

PROCEDURE tfshiftaf(phi,offset:LIST):LIST;
(* type formula shift atomic formula. phi
is an atomic formula, offset is an atom. all identifiers in phi are shifted. *)

PROCEDURE TFFTUPLE(tup:LIST):LIST;
(* type formula from coefficient tuple with joker entries.
tup is a coefficient tuple.
A formula in tf-format is returned. The formula is true, iff
the instantiation of the variables suffice the relation conditions of
the characteristic coefficients of tup. *)
				
(******************************************************************************
*                         C L A S S I F I C A T I O N                         *
******************************************************************************)

PROCEDURE Class2Sym(class: TfClass):LIST;
(* classification to symbol. class is a constant of type class.
The corresponding mas symbol is returned. *)

PROCEDURE Sym2Class(class: LIST):TfClass;
(* symbol to classification. 
class is a mas-symbol the corresponding classification is returned. *)

PROCEDURE InitClassSyms();
(* Initialize classification symbols. 
The mas symbols representing classification constants are initialized. *)

PROCEDURE TfClassify(tup:LIST):TfClass;
(* type formula classify coefficient tuple.
tup is a coefficient tuple. The classification of tup is returned.
Let f the polynomial which is represented by tup.
If tau(f)=0, then Tfgood is returned,
if tau(f)<0, then Tfdontcare is returned,
if tau(f)>0, then Tfbad is returned.
Is the sum of the upper bounds of the real zeroes do not equal the
degree of f, then TfImpossible is returned. *)

PROCEDURE TfClassifyI(tup:LIST):LIST;
(* type formula classify coefficient tuple interpreter version.
tup is a coefficient tuple. The classification of tup is returned.
Let f the polynomial which is represented by tup.
If tau(f)=0, then TfGood is returned,
if tau(f)<0, then TfDontCare is returned,
if tau(f)>0, then TfBad is returned.
Is the sum of the upper bounds of the real zeroes not equal to the
degree of f, them TfImpossible is returned. 
The classification is returned as an symbol, representing the classification.*)


(******************************************************************************
*                    T H E   N A I V E   A L G O R I T H M                    *
******************************************************************************)

PROCEDURE TFGENI(deg: LIST; class: LIST): LIST;
(* TFGEN interpreter version. Like TFGEN but the classification
parameter is a MAS symbol. *)

PROCEDURE TFGEN(deg: LIST; class: TfClass): LIST;
(* type formula generate. 
deg is an atom > 1.
A tf-formula is returned. This formula is true, iff 
a tuple t with t_0<>0 has the classification class. *)

PROCEDURE PatternAStart(deg:LIST; VAR start, pattern:LIST);
(* pattern and start. A pattern and a start value for the computation of
characteristic coefficient tuples is computed. Let (c_0,...,c_deg)
the start value and (p_0,...,p_deg) the pattern. Then the following holds.
If d MOD 4 = 0, then c_0=1 p_0=0. 
If d MOD 4 = 1, then c_0=0 and c_1=1 and p_0=p_1=0.
If d MOD 4 = 2, then c_0=-1 and p_0=0.
If d MOD 4 = 3, then c_0=0 and c_1 = -1 and p_0=p_1=0.
c_deg=1.
*)

PROCEDURE TfNextTuple(last,pattern:LIST):LIST;
(* type formula next tuple. 
last is a list with n elements of the set \{0,-1,1\}. 
pattern is a list with n elements of the set \{0,1\}.
The lexicographic tuple which differs only an those positions that are
1 in list pattern is returned. The constant SIL is returned, if no
lexicographic tuple greater last exists. The result is generated
non-constructive from last. *)

PROCEDURE NextRel(e: LIST):LIST;
(* next relation. 
e is an code for a relation. 
The code of the next relation (in order <, =, > ) is returned. *)

PROCEDURE TfCount(deg: LIST):LIST;
(* type formula count. 
deg is an atom.
Some characteristic coefficient tuples (c_0,...,c_d) in $\{-1,0,1\}^(d+1) $
are generated. The following holds.
If d MOD 4 = 0, then c_0=1.
If d MOD 4 = 1, then c_0=0 and c_1=1.
If d MOD 4 = 2, then c_0=-1 
If d MOD 4 = 3, then c_0=0 and c_1 = -1.
c_deg=1.
A list (Good,Bad,DontCare,Impossible) is returned. 
Each element is the number  of coefficient tuples with the corresponding
classification.
*)

PROCEDURE TfCount1(start, pattern: LIST):LIST;
(* type formula count 1. 
start is a list (s_0,...s_d) with elements of the set \{-1,0,1\}, 
pattern is a list (p_0,...,p_d) with elements of \{0,1\}.
The set T := { t in {-1,0,1}**{d+1} | t >= s , t_i=s_i, if p_i=0 }
is computed. 
A list (Good,Bad,DontCare,Impossible) is returned. 
Each element is the number of coefficient tuples with the corresponding
classification. *)


(******************************************************************************
*                D E S C A R T E S   R U L E   O F   S I G N S                *
******************************************************************************)

PROCEDURE TfZeroes0(tup: LIST):LIST;
(* type formula zeroes 0. 
The numbers of the leading zeroes is returned. 
This is the number of zeroes at the origin of the polynomial SUM tup_i X**i.
For the tuple tup containing only zeroes and for the empty tuple 
the constant SIL is returned. *)

PROCEDURE TfZeroes(tup: LIST; VAR CZeroes, ZeroesM, Zeroes0, ZeroesP: LIST);
(* type formula zeroes. tup is a coefficient tuple of a univariate 
polynomial f. A upper bound of the real zeroes of f, which are
greater than zero (less than zero) is returned in ZeroesP (ZeroeseM).
The number of zeroes at the origin are returned in Zeroes0. If f has only
real zeroes then the numbers of zeroes are exactly. The computation
of the numbers are done using Descartes rule of signs. The number of
all complex zeroes (=deg(f)=length(tup)-1) is returned in CZeroes.
If tup is a list containing only zeroes, then CZeroes is SIL, and all other
variables are undefined. *)

PROCEDURE TfZeroesI(tup: LIST):LIST;
(* TfZeroes interpreter version.
This procedure returns the 4 variable parameters of the procedure
TfZeroes as a list containing 4 elements. *)

PROCEDURE TfSignChs(tup: LIST): LIST;
(* type formula sign changes. 
tup is a list with elements of the set \{-1,0,1\}. 
The number of sign changes of tup is returned. *)


END TFORM.
(* -EOF- *)
 
