(* ----------------------------------------------------------------------------
 * $Id: DIPDEC0.md,v 1.2 1992/02/12 17:34:14 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDEC0.md,v $
 * Revision 1.2  1992/02/12  17:34:14  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:30  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPDEC0;

(* DIP Ideal Decomposition 0 System Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPDEC0.md,v 1.2 1992/02/12 17:34:14 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGFET(P,IL,JL: LIST): LIST; 
(*DIP G base successful extension test. P is a Groebner base of 
an ideal of dimension 0 in inverse lexicographical term ordering. 
i and j are indexes of variables where an field extension is required. 
t=1 if the extension was successful t=0 else. *)


PROCEDURE DIGISM(P: LIST): LIST; 
(*DIP G base index search for extension multiple univariats. 
P is a Groebner base of dimension 0 in inverse lexicographical term 
ordering. I is a list of indexes of variables where an field extension
is required or I=() if no field extension is neccessary. *)


PROCEDURE DIGISR(P: LIST): LIST; 
(*DIP G base index search for extension reductas. P is a Groebner 
base of an ideal of dimension 0 in inverse lexicographical term 
ordering. I is a list of indexes of variables where an field 
extension is required or I=() if no field extension is neccessary. *)


PROCEDURE DINTFE(T,IL,JL: LIST): LIST; 
(*DIP normalized tupel field extension. T is a normalized tupel 
of a zero set with a final Groebner base of dimension 0.
i and j determine the variable indexes for the field extension.
TP is a list of normalized tupels for the field extension for T. 
Trial values are used for the transcendent parameter. *)


PROCEDURE DINTSR(T: LIST): LIST; 
(*DIP normalized tupel separation refinement. T is a list of 
normalized tupels with final Groebner base of dimension 0.
TP is a list of normalized tupels for some field extensions for T. *)


PROCEDURE DINTSS(T: LIST): LIST; 
(*DIP normalized tupel strong separation. T is a list of normalized 
tupels with final Groebner base of dimension 0. TP is a list of 
normalized tupels for some field extensions for T. *)


PROCEDURE DINTZS(N: LIST): LIST; 
(*DIP nomalized tupels from system zero. N is a zero set. 
T is the list of nomalized tupels of N. *)


PROCEDURE DIRGZS(VB,PB,W: LIST): LIST; 
(*Distributive rational Groebner base zero set. VB is a rest of a 
variable list. PB is a Groebner base. W is the total variable 
list. N is the zero set of P. *)


PROCEDURE DIRLPD(A,VP: LIST): LIST; 
(*DIP rational polynomial ideal primary ideal decomposition.
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in A have r variables.
L=(l1, ...,ln) with li=(pi,ei,vpi,qi) i=1, ...,n where 
qi = ideal(pi**e,A) with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list vor pi. *)


PROCEDURE DIRLPW(A,V,L: LIST); 
(*DIP rational polynomial ideal primary ideal decomposition write.
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in a have r variables.
L=(l1, ...,ln) with li=(pi,eli,vpi,qi) i=1, ...,n where 
qi = ideal(pi)**e with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list for pi. *)


PROCEDURE DIRPDA(A,VP: LIST): LIST; 
(*DIP rational polynomial ideal primary ideal decomposition over Q(alpha).
A is a non empty list of distributive rational polynomials 
representing a Groebner base. The polynomials in A have r variables.
L=(l1, ...,ln) with li=(pi,ei,vpi,qi) i=1, ...,n where 
qi = ideal(pi**e,A) with A contained in qi and e maximal.
Ideal(pi) is a prime ideal in at most r+1 variables. VPI is the 
variable list vor pi. *)


PROCEDURE DITFZS(N: LIST): LIST; 
(*DIP tupel from zero set. N is a zero set. T is a list of 
tupels of the zero set. *)


PROCEDURE DITSPL(T: LIST;  VAR T0,T1: LIST); 
(*DIP zero set tupel split. T is a list of normalized tupels 
of a zero set. T0 is a list of normalized tupels of a zero set 
with a final Groebner base of a ideal of dimension 0. T1=T-T0. *)


END DIPDEC0.


(* -EOF- *)
