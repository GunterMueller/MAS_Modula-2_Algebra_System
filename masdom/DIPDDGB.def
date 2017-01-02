(* ----------------------------------------------------------------------------
 * $Id: DIPDDGB.md,v 1.1 1993/05/11 10:13:41 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDDGB.md,v $
 * Revision 1.1  1993/05/11  10:13:41  kredel
 * Initial Revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPDDGB;

(* DIP Domain D-Groebner Bases Definition Module. *)


(* Author: W. Mark, Uni Passau, 1992. *)


FROM MASSTOR IMPORT LIST;



PROCEDURE DIDPELIMDGB(P : LIST) : LIST;
(*Distributive domain polynomial eliminate D-groebner base.
P is a list of non zero polynomials in distributive
integral representation in r variables.
ELIMDGB eliminates the polynominials with respect
to the divisibility of the highest monominials. *)


PROCEDURE DIDPTDR(P, lcmHT, pair : LIST): LIST;
(*Distributive domain polynomial top-D-reduzibel. P is a list
of non zero polynomials in distributive integral
representation in r variables.
pair is a pair two integral polynomials in
distributive representation.
lcmHT is the lcm of the highest terms of the two
polynomials.
TDR is a boolean value which equals 1, if g is top-D-
reduzibel modulo P and 0 if not. *)


PROCEDURE DIDPCPLMS1(P : LIST) : LIST;
(*Distributive domain polynomial list construct pairs list merge sort.
P is a list of non zero polynomials in distributive
integral representation in r variables.
CPLMS1 sorts a constructed pairs list in the
following ascending order:
1. lcm of the highest terms
2. lcm of the highest coefficients
P will be changed. *)


PROCEDURE DIDPLM1(onestep, twostep : LIST) : LIST;
(*Distributive domain polynomial list merge sort.
P is a list of non zero polynomials in distributive
integral representation in r variables.
LM1 merges two (onestep, twostep) constructed
pairs lists in the same manner as DIDPLCPLMS1.
The lists onestep and twostep will be changed. *)


PROCEDURE DIDPUCPL1(P, g, Old : LIST) : LIST;
(*Distributive domain polynomial update constructed pairs list.
P is a list of integral polynomials in distributive
representation. g ist a polynomial in distributive
representation. Both are polynomials in r variables.
Old is the constructed and sorted pairs
list to be updated. *)


PROCEDURE DIDPGPOL(g1,g2: LIST): LIST;
(*Distributive domain polynomial g polynomial. g1 and g2 are
integral polynomials in distributive representation. GPOL is
the G-polynomial of g1 and g2. *)


PROCEDURE DIDPSPOL2(g1, g2, lcmHT, lcmHK: LIST): LIST;
(*Distributive domain polynomial s polynomial. g1 and g2 are
integral polynomials in distributive representation.
lcmHT is the lcm of the highest terms of g1 and g2.
lcmHK is the lcm of the highest coefficients of g1 and g2.
polynomials in pair.
SPol is the S-polynomial of g1 and g2. *)


PROCEDURE DIDPLEXTAL(AL, g : LIST) : LIST;
(*Distributive domain polynomial list extend array list.
AL is an array list.
g is a polynomial in distributive representation
in r variables.
Ag is the extended array list of AL.
The list AL is modified. *)


PROCEDURE DIDPLCPL4(P : LIST; VAR CPL, AL : LIST);
(*Distributive domain polynomial list construct pair list.
P is a list of polynomials in distributive
representation in r variables.
CPL is the constructed pairs list, AL is the
Array list. *)


PROCEDURE DIDPALCMPC(AL, g1, g2, flag : LIST) : LIST;
(*Distributive domain polynomial array list check and mark polynomials.
AL is an array list. g1, g2 are polynomials in
distributive representation in r variables.
flag determines whether the pair will be
marked as computed or only checked. 1 means to
mark 0 only to check.
The value 1 is returned if the pair (g1,g2) is
already computed otherwise 0 is returned. *)


PROCEDURE DIDPENF(P,varl,g: LIST): LIST;
(*Distributive domain polynomial E-normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. g is a distributive
integral polynomial. ENF is a polynomial such that
g is e-reducible to ENF modulo P and ENF is in
E-normalform modulo P. *)


PROCEDURE DIDPREDDGB(P : LIST) : LIST;
(*Distributive domain polynomial reduce D-groebner base.
P is a list of non zero polynomials in distributive
integral representation in r variables.
REDDGB reduces the polynominials.
It is nescessary that the highest monomials are
pairwise disjoint. *)


PROCEDURE DIDPSPOL(g1,g2: LIST): LIST;
(*Distributive domain polynomial s polynomial. g1 and g2 are
integral polynomials in distributive representation.
SPol is the S-polynomial of g1 and g2. *)


PROCEDURE DIDPDNF(P,varl,g: LIST): LIST;
(*Distributive domain polynomial D-normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. g is a distributive
integral polynomial. NF is a polynomial such that
g is reducible to NF modulo P and NF is in
D-normalform modulo P. *)


PROCEDURE DIDPDGB(F, TF : LIST): LIST;
(*Distributive domain polynomial D-groebner basis. F is a
list of integral polynomials in distributive representation
in r variables. G is the groebner basis of F. TF the trace flag. *)


PROCEDURE DIDPEGB(F, DP, TF : LIST): LIST;
(*Distributive domain polynomial E-groebner basis. F is a
list of integral polynomials in distributive representation
in r variables.
DP is a domain element with descriptor.
G is the groebner basis of F. TF the trace flag. *)


END DIPDDGB.

