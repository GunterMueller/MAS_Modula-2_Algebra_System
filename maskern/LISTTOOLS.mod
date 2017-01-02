(* ----------------------------------------------------------------------------
 * $Id: LISTTOOLS.mi,v 1.1 1994/11/28 20:32:51 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: LISTTOOLS.mi,v $
 * Revision 1.1  1994/11/28  20:32:51  dolzmann
 * New modules SYSINFO.md, SYSINFO.mi, LISTTOOLS.md, and LISTTOOLS.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE LISTTOOLS;
(* List Tools Implementation Module. *)

FROM MASBIOS	IMPORT	LETTER, MASORD;
FROM MASELEM	IMPORT	GAMMAINT, MASEVEN;
FROM MASSTOR	IMPORT	ADV, COMP, INV, LIST, SIL; 
FROM SACLIST	IMPORT	EQUAL, LIST2, LIST5, SLELT; 

CONST rcsidi = "$Id: LISTTOOLS.mi,v 1.1 1994/11/28 20:32:51 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";


PROCEDURE CLISTFA(atom:LIST):LIST;
(* character list from atom. 
The decimal printable representation of atom is returned as a character 
list. *)
	VAR result:LIST;
	VAR minus:BOOLEAN;
BEGIN
	result:=SIL;
	IF atom<0 THEN
		minus:=TRUE;
		atom:=-atom;
	ELSE
		minus:=FALSE;
	END;
	REPEAT
		result:=COMP((atom MOD 10),result);
		atom:=atom DIV 10;
	UNTIL atom=0;
	IF minus THEN result:=COMP(MASORD("-"),result); END;
	RETURN result;
END CLISTFA; 


PROCEDURE LIST6(a1,a2,a3,a4,a5,a6:LIST):LIST;
(* list of 6 elements. The list (a1,a2,...a6) is returned. *)
BEGIN
	RETURN COMP(a1,LIST5(a2,a3,a4,a5,a6));
END LIST6;


PROCEDURE LPAIRS(L:LIST):LIST;
(* list pairs. L=(l1,...ln) is a list. A list containing all lists (li,lj),
where li and lj are elements of L and i <> j is returned. *)
	VAR result, pointer, first, second: LIST;
BEGIN
	result:=SIL;
	WHILE L<>SIL DO
		ADV(L,  first,L);
		pointer:=L;
		WHILE pointer<>SIL DO
			ADV(pointer,  second,pointer);
			result:=COMP(LIST2(first,second),result);
		END;
	END;
	RETURN result;
END LPAIRS;


PROCEDURE LSRCHQ(a,L:LIST):LIST;
(* List search equal. 
a is an element, 
L is a list.
The first position of a in L is returned if a is member of L, 
otherwise 0 is returned. *)
	VAR b,i: LIST;
BEGIN
	i:=0;
	WHILE L<>SIL DO
		i:=i+1;
		ADV(L,  b,L);
		IF EQUAL(a,b)=1 THEN RETURN i; END;
	END;
	RETURN 0;
END LSRCHQ;


PROCEDURE UPCASE(clist:LIST):LIST;
(* upcase character list. 
clist is a character list. All letters in clist are converted to upper case. 
The result is returned. *)
	VAR c:GAMMAINT;
	VAR result:LIST;
BEGIN
	result:=SIL;
	WHILE clist<>SIL DO
		ADV(clist,c,clist);
		IF LETTER(c) AND MASEVEN(c) THEN
			result:=COMP(c+1,result);
		ELSE
			result:=COMP(c,result);
		END;
	END;
	RETURN INV(result);
END UPCASE;


END LISTTOOLS.

(* -EOF- *)
