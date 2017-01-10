(* ----------------------------------------------------------------------------
 * $Id: ADTOOLS.md,v 1.2 1994/11/28 20:43:07 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ADTOOLS.md,v $
 * Revision 1.2  1994/11/28  20:43:07  dolzmann
 * Constructors and destructors for some domain descriptors introduced.
 *
 * Revision 1.1  1994/04/14  18:01:55  dolzmann
 * Introduced new modules ADTOOLS and DIPTOOLS.
 *
 * ----------------------------------------------------------------------------
 *)
  
DEFINITION MODULE ADTOOLS;
(* Arbitrary Domain Tools Definition Module *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: ADTOOLS.md,v 1.2 1994/11/28 20:43:07 dolzmann Exp $";
CONST copyright = "Copyright (c) 1989 - 1994 Universitaet Passau";

PROCEDURE ADRFFADIP(adip:LIST):LIST;
(* arbitrary domain rational function from arbitrary domain intgeral
polynomial. adip is an arbitrary domain integral polynomial. adip is 
converted to an arbitrary domain rational function. *)

PROCEDURE ADDDFSTR(s:ARRAY OF CHAR):LIST;
(* arbitrary domain domain descriptor from string. s is an string. 
The string must finish with a blank character. *)

PROCEDURE ADCAST(e,dd:LIST):LIST;
(* arbitraray domain cast. e is an element, dd is an 
arbitrary domain descriptor. The domain information of the elemnt e is 
changed to the domain informations of dd. No conversion is done. *)

PROCEDURE ADRMDD(e: LIST):LIST;
(* arbitrary domain remove domain descriptor informations. 
e is an arbitrary domain element. The domain descriptor informations 
are removed from the element e, the result is returned. *)

PROCEDURE AdLoadConvFunc();
(* arbitrary domain load conversion functions. This procedure is called from 
the module MASLOADE after all domains are loaded. *)

(******************************************************************************
*                      D O M A I N   D E S C R I P T O R                      *
******************************************************************************)

PROCEDURE RFDDFIPDD(ipdd:LIST):LIST;
(* rational function domain descriptor from integral polynomial domain
descriptor. *)

PROCEDURE IPDDCMP(vlist:LIST):LIST;
(* integral polynomial domain descriptor composition. *)

PROCEDURE IPDECMP(e,vlist:LIST):LIST;
(* integral polynomial domain element composition. *)

PROCEDURE INTDDCMP():LIST;
(* integer domain descriptor composition. *)

PROCEDURE IPDDADV(p: LIST;  VAR q,r,vl:LIST);
(* integral polynomial domain descriptor advance *)

PROCEDURE RFDDADV(e: LIST; VAR rat, vl: LIST);
(* rational function domain descriptor advance. *)

END ADTOOLS.

(* -EOF- *)
