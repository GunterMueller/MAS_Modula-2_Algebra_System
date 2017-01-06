(* ----------------------------------------------------------------------------
 * $Id: MASSYM2.md,v 1.2 1992/02/12 17:32:33 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSYM2.md,v $
 * Revision 1.2  1992/02/12  17:32:33  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:09  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASSYM2;

(* MAS/SAC Symbol System Definition Module 2. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT GAMMAINT;

FROM MASSTOR IMPORT LIST;

VAR COUNT, TRMAX: GAMMAINT;

    SYMTB: LIST;

    NOSHOW: LIST;

CONST rcsid = "$Id: MASSYM2.md,v 1.2 1992/02/12 17:32:33 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ACOMP(A,B: LIST): LIST;
(*Alphabetic comparison. A and B are symbols. t=+1,0,-1 according
to whether A preceds, is equal, or follows B alphabetically.*)


PROCEDURE ACOMP1(A,B: LIST): LIST;
(*Alphabetic comparison, 1. subalgorithm. A and B are packed strings.
s=-1,0,1 according to whether a preceds, is equal, or succeeds B
alphabetically.*)


PROCEDURE ASSOC(AL,L: LIST): LIST;
(*Associate. L=(a1 b1, a2 b2, ...,a sub n b sub n), n ge 0,
a is an object. If there is an i such that a=a sub i then
P=(b sub i, ...,a sub n b sub n), otherwise P=().*)


PROCEDURE ASSOCQ(AL,L: LIST): LIST;
(*Associate equal. L=(a1 b1, a2 b2, ...,a sub n b sub n), n ge 0,
a is an object. If there is an i such that a is equal to a sub i then
P=(b sub i, ...,a sub n b sub n), otherwise P=().*)


PROCEDURE ATTRIB(L: LIST): LIST;
(*Attribute. L is a symbol. Returns the attributes of L.*)


PROCEDURE EXPLOD(S: LIST): LIST;
(*Explode symbol. S is a symbol, L its character list.*)


PROCEDURE ENTER(L: LIST): LIST;
(*Enter into symbol table. L is a character list, S the pointer
to the corresponding symbol. If the symbol is not yet in the
symbol table SYMTB, then a new node is created.*)


PROCEDURE GENSYM(): LIST;
(*Generate symbol. S is a newly generated symbol. NAM is advanced.*)


PROCEDURE GET(S,AL: LIST): LIST;
(*Get property. The property list of the symbol S is searched
under indicator a. A is the property under a, if any, otherwise
A is set to beta.*)


PROCEDURE NAME(L: LIST): LIST;
(*Name. L is a symbol. Returns the name of L.*)


PROCEDURE PACK(L: LIST): LIST;
(*Pack character list. L is a non-empty character list. B is the
packed list.*)


PROCEDURE PUT(S,AL,A: LIST);
(*Put. The property A is stored on the property list of
the symbol S under the indicator a.*)


PROCEDURE REMPRP(S,AL: LIST);
(*Remove property. Under indicator a on the property list of
symbol S the property is removed.*)


PROCEDURE SMEMB(S,L: LIST): LIST;
(*Symbol membership. S is a symbol, L a list containing possibly
also symbols. b=1 if S or a copy of S occurs in L, b=0 otherwise.*)


PROCEDURE SREAD(): LIST;
(*Symbol read. The next symbol is read from input. S is the symbol in
the symbol table SYMTB.*)


PROCEDURE SREAD1(): LIST;
(*Symbol read, 1. The first non-alphanumeric character of the
input stream terminates the symbol.  L is the character list of 
the symbol, which is not entered in the symbol table.*)


PROCEDURE STCNT(T: LIST;    VAR S,P: LIST);
(*Symbol table tree count. T is a symbol tree, S is the number
of symbols in T, P the number of properties of all symbols of the tree.
Since every symbol has a name property, P ge S.*)


PROCEDURE STINS(B: LIST): LIST;
(*Symbol tree insertion. B is a packed list of characters. S is a
pointer to the corresponding symbol in the symbol table. If
it is not yet in, a new node is created.*)


PROCEDURE STLST(T: LIST): LIST;
(*Symbol tree list. T is a symbol tree, L is the list of its symbols
in alphabetic order.*)


PROCEDURE STLSTI(T: LIST): LIST;
(*Symbol tree list, in-order. T is a binary tree of symbols, L is a
list of its symbols, with the root symbol appearing first.*)


PROCEDURE STSRCH(T,AP: LIST): LIST;
(*Symbol tree search. T is a binary tree of symbols, AP is a packed
list of characters. If the symbol with the name AP occurs already
in the symbol table T then S=() and otherwise S points to the entry.*)


PROCEDURE STWRT(T: LIST);
(*Symbol tree write. T is a binary tree of symbols. The symbols
followed by their properties are printed in alphabetic order.*)


PROCEDURE SYMBOL(AP: LIST): BOOLEAN;
(*Symbol. AP is an object. Returns true if it is a symbol and 
false else.*)


PROCEDURE SymSummary();
(*Summary of symbol system. The number of symbols in SYMTB and
the number of their properties is written.*)


PROCEDURE SYWRIT(S: LIST);
(*Symbol write. The symbol S is written in the output stream.*)


PROCEDURE SUBLIS(L,A: LIST): LIST;
(*Substitution with list. L=(x1 e1, ...,x sub n e sub n),
a and e sub i are objects. The x sub i are beta-digits
or pointers to uniquely stored lists like symbols. B is A
with the x sub i substituted by the e sub i.*)


PROCEDURE UREAD(): LIST;
(*Universal read. The next atom, symbol or list over atoms
and symbols is read and stored under L. Blanks may occur anywhere,
elements of a list may or may not be separated by a comma.*)


PROCEDURE UWRITE(L: LIST);
(*Universal write. L is an atom, symbol or a list over
atoms and symbols. L is written in the output stream,
followed by BLINES(0). *)


PROCEDURE UWRIT1(L: LIST);
(*Universal write, 1. subalgorithm. L is an atom, a symbol
or a list over atoms or symbols. L is written in the output
stream followed by a blank character, but not by BLINES. *)


END MASSYM2.


(* -EOF- *)
