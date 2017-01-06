(* ----------------------------------------------------------------------------
 * $Id: ADTOOLS.mi,v 1.2 1994/11/28 20:43:11 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ADTOOLS.mi,v $
 * Revision 1.2  1994/11/28  20:43:11  dolzmann
 * Constructors and destructors for some domain descriptors introduced.
 *
 * Revision 1.1  1994/04/14  18:01:57  dolzmann
 * Introduced new modules ADTOOLS and DIPTOOLS.
 *
 * ----------------------------------------------------------------------------
 *)
  
IMPLEMENTATION MODULE ADTOOLS;
(* Arbitrary Domain Tools Implementation Module *)


FROM DOMIP	IMPORT	DOMIPD;
FROM DOMRF	IMPORT	DOMRFD;
FROM DIPRF	IMPORT	RFFIP;
FROM DOMI	IMPORT	DOMINT;
FROM MASADOM	IMPORT	ADCONV, ADDDREAD, ADDDWRIT, ADFI, SetConvFunc;
FROM MASBIOS	IMPORT	LISTS;
FROM MASBIOSU	IMPORT	CLTIS;
FROM MASSTOR	IMPORT	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, LISTVAR,
			RED, SFIRST, SIL, SRED;
FROM SACLIST	IMPORT	ADV2, ADV3, ADV4, AWRITE, CCONC, CINV, CLOUT, COMP2,
			CONC, EQUAL, FIRST3, FIRST4, FOURTH, LIST10, LIST2,
			LIST3, LIST4, LIST5, MEMBER, RED2, SECOND, THIRD;


PROCEDURE ADRFFADIP(adip:LIST):LIST;
(* arbitrary domain rational function from arbitrary domain intgeral
polynomial. adip is an arbitrary domain integral polynomial. adip is 
converted to an arbitrary domain rational function. *)
	VAR ip,r,vlist: LIST;
BEGIN
	FIRST3(adip,ip,r,vlist);
	RETURN LIST2(RFFIP(r,ip),vlist);
END ADRFFADIP;

PROCEDURE ADDDFSTR(s:ARRAY OF CHAR):LIST;
(* arbitrary domain domain descriptor from string. s is an string. 
The string must finish with a blank character. *)
BEGIN
	CLTIS(LISTS(s));
	RETURN ADDDREAD();
END ADDDFSTR;

PROCEDURE ADCAST(e,dd:LIST):LIST;
(* arbitraray domain cast. e is an element, dd is an 
arbitrary domain descriptor. The domain informations of the domain dd
is added to e. No conversion is done. *)
	VAR result,red,add:LIST;	
BEGIN
(*1*)	(* take the domain id from dd *)
	result:=LIST1(FIRST(dd));
(*2*)	(* take the data from e *)
	result:=COMP(e,result);
(*3*)	(* add all additionally descriptor informations of dd to the result *)
	add:=RED2(dd);
	WHILE add<>SIL DO
		ADV(add,red,add);
		result:=COMP(red,result);
	END;
(*9*)	(* reorder the result and return it *)
	RETURN INV(result);
END ADCAST;

PROCEDURE ADRMDD(e: LIST):LIST;
(* arbitrary domain remove domain descriptor informations. 
e is an arbitrary domain element. The domain descriptor informations 
are removed from the element e, the result is returned. *)
BEGIN
	RETURN SECOND(e);
END ADRMDD;

PROCEDURE AdLoadConvFunc();
(* arbitrary domain load conversion functions. This procedure is called from 
the module MASLOADE after all domains are loaded. *)
BEGIN
	SetConvFunc(DOMRFD,DOMIPD,ADRFFADIP);
END AdLoadConvFunc;

(******************************************************************************
*                      D O M A I N   D E S C R I P T O R                      *
******************************************************************************)

PROCEDURE RFDDFIPDD(ipdd:LIST):LIST;
(* rational function domain descriptor from integral polynomial domain
descriptor. *)
	VAR ipid,p,r,vlist:LIST;
BEGIN
	FIRST4(ipdd,ipid,p,r,vlist);
	RETURN LIST3(DOMRFD,LIST2(r,0),vlist);
END RFDDFIPDD;

PROCEDURE IPDDCMP(vlist:LIST):LIST;
(* integral polynomial domain descriptor composition. *)
BEGIN
	RETURN LIST4(DOMIPD,0,LENGTH(vlist),vlist);
END IPDDCMP;

PROCEDURE IPDECMP(e,vlist:LIST):LIST;
(* integral polynomial domain element composition. *)
BEGIN
	RETURN LIST4(DOMIPD,e,LENGTH(vlist),vlist);
END IPDECMP;

PROCEDURE INTDDCMP():LIST;
(* integer domain descriptor composition. *)
BEGIN
	RETURN LIST2(DOMINT,0);
END INTDDCMP;

PROCEDURE IPDDADV(p: LIST;  VAR q,r,vl:LIST);
(* integral polynomial domain descriptor advance *)
	VAR dnr: LIST;
BEGIN
	FIRST4(p, dnr,q,r,vl);
END IPDDADV;

PROCEDURE RFDDADV(e: LIST; VAR rat, vl: LIST);
(* rational function domain descriptor advance. *)
	VAR dnr: LIST;
BEGIN
	FIRST3(e,dnr,rat,vl);
	RETURN;
END RFDDADV;			   

END ADTOOLS.

(* -EOF- *)
