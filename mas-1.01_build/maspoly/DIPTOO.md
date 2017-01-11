(* ----------------------------------------------------------------------------
 * $Id: DIPTOO.md,v 1.4 1994/03/30 13:05:15 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPTOO.md,v $
 * Revision 1.4  1994/03/30  13:05:15  dolzmann
 * New procedures DIPVOPP and INVPERM.
 *
 * Revision 1.3  1993/03/23  13:01:36  kredel
 * Added LFCHECK
 *
 * Revision 1.2  1992/02/12  17:33:54  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPTOO;

(* DIP Termorder Optimization Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPTOO.md,v 1.4 1994/03/30 13:05:15 dolzmann Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPDEM(A: LIST): LIST;
(*Distributive polynomial degree matrix. A is a distributive
polynomial. B is the degree matrix of A. *)


PROCEDURE DIPDEV(A: LIST): LIST;
(*Distributive polynomial degree vector. A is a distributive
polynomial. N is the degree vector of A.*)


PROCEDURE DIPLDM(A: LIST): LIST;
(*Distributive polynomial list degree matrix. A is a list of
distributive polynomials. B is the sum of all degree matrices
of each element of A. *)


PROCEDURE DIPTRM(A: LIST): LIST;
(*Distributive polynomial terms. A is a distributive polynomial
in r variables. T is a list of beta-integers each counting
the terms in the respective variable.*)


PROCEDURE DIPTYP(A: LIST): LIST;
(*Distributive polynomial typ. A is a distributive polynomial
in r variables. t is a rational number, t is the typ of A,
0 lt t le 1. *)


PROCEDURE DIPVOP(P,V: LIST; VAR PP,VP: LIST);
(*Distributive polynomial variable ordering optimisation.
P and PP are lists of distributive polynomials.
V and VP are variable lists. The optimal variable ordering
for the polynomials in P is determined. The variables
of the polynomials in P are permuted to produce PP.
VP is the new variable list.*)


PROCEDURE DIPVOPP(P,V: LIST; VAR PP,VP,PV: LIST);
(*Distributive polynomial variable ordering optimization and permutation 
vector. P and PP are lists of distributive polynomials.
V and VP are variable lists. The optimal variable ordering
for the polynomials in P is determined. The variables
of the polynomials in P are permuted to produce PP.
VP is the new variable list, PV is the permutation to compute VP from V. *)


PROCEDURE DMEVAD(A,E: LIST): LIST;
(*Degree matrix exponent vector add. A is a degree matrix.
E is an exponent vector. B=A + E. *)
 

PROCEDURE HDIFDI(A: LIST; VAR B,FL: LIST);
(*Homogeneous distributive polynomial from distributive polynomial.
A is a distributive polynomial in r variables. s=r+1.
If A is allready homogeneous then f=0 else f=1.
B(xs,x1, ...,xr)=(xs)**(tdeg(A)) * A(x1/xs, ...,xr/xs). *)
 

PROCEDURE INVPERM(perm: LIST):LIST;
(* inverse permutation. perm is a permutation. The inverse permutation
is returned, i.e. LPERM(LPERM(x,p),INVPERM(p))=x. *)


PROCEDURE LBLXCO(U,V: LIST): LIST;
(*List of beta integers lexicographical compare.
U=(u1, ...,ur), V=(v1, ...vs) are lists of beta integers.
t=0 if U eq V. t=1 if U gt V. t=-1 if U lt V. eq, gt,
lt with respect to the lexicographical ordering of the
beta integers. *)


PROCEDURE LFCHECK(L, f: LIST): BOOLEAN;
(*Linear form check. L is a linear form for term comparison, 
if L is empty EVORD is checked. f is a print flag, 
if f >0 then a message is written to the output stream. *)


PROCEDURE PTERM(RL,A: LIST): LIST;
(*Polynomial terms. A is a recursive polynomial in r
variables. T is a list of beta-integers each counting the
terms in the respective variable.*)


PROCEDURE PTYP(RL,A: LIST): LIST;
(*Polynomial typ. A is a recursive polynomial in r variables.
t is a rational number, t is the PTYP of A, 0 lt t lt 1. *)


PROCEDURE PVDEMA(A: LIST): LIST;
(*Permutation vector for degree matrix. A is a degree matrix.
P is a permutation vector. *)


END DIPTOO.


(* -EOF- *)
