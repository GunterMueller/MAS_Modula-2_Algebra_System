(* ----------------------------------------------------------------------------
 * $Id: MASPGCD.mi,v 1.2 1994/06/16 13:01:00 pfeil Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASPGCD.mi,v $
 * Revision 1.2  1994/06/16  13:01:00  pfeil
 * corrected errors found by mocka.
 *
 * Revision 1.1  1994/06/10  12:10:21  pfeil
 * Initial revision. Procedures for squarefree factorization of integral
 * polynomials.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASPGCD;

(* MAS Polynomial GCD and RES System Implementation Module. *)



(* Import lists and declarations. *)


FROM MASSTOR IMPORT ADV, COMP, INV, LIST, SIL;

FROM SACEXT4 IMPORT PCONST;

FROM SACIPOL IMPORT IPPROD;

FROM SACLIST IMPORT FIRST2, LIST2;

FROM SACPGCD IMPORT IPCPP, IPSF;


CONST rcsidi = "$Id: MASPGCD.mi,v 1.2 1994/06/16 13:01:00 pfeil Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1994 Universitaet Passau";


PROCEDURE IPSFF(r,f: LIST): LIST;
(* integral polynomial squarefree factorization
   f is a primitive polynomial in r variables,
   returns a list ((e1,p1),...,(ek,pk)), 
   ei positive integers, pi squarefree polynomials,
   where f = p1**e1 * ... * pk**ek *)
VAR cf,f0,CF,CF1,F0,F,EP,e,p: LIST;
BEGIN
   IF r=1 THEN RETURN(IPSF(1,f));
   ELSE 
      IPCPP(r,f,cf,f0);	(* compute content and primitive part *)
      IF PCONST(r-1,cf)=1 
	 THEN CF:=SIL;     
	 ELSE CF:=IPSFF(r-1,cf);	(* factorize content *)
      END; 
      CF1:=SIL;
      WHILE CF<>SIL DO
	 ADV(CF,EP,CF);
	 FIRST2(EP,e,p);
	 EP:=LIST2(e,LIST2(0,p));
	 CF1:=COMP(EP,CF1);
      END; (* WHILE CF... *)
      CF:=INV(CF1);
      IF PCONST(r,f0)=1
	 THEN F0:=SIL;
	 ELSE F0:=IPSF(r,f0);	(* factorize primitive part *)
      END;
      F:=IPFLMER(r,F0,CF);	(* merge factorizations *)
      RETURN(F);
   END; (* IF r... *)
END IPSFF;


PROCEDURE IPFLMER(r,F1,F2: LIST): LIST;
(* integral polynomial factorlist merge.
   F1 and F2 are factorlists ((e1,p1),...,(ek,pk)),
   ei positive integers, pi integer polynomials in r variables,
   as computed in IPSFF.
   returns the merge of F1 and F2. *)
VAR F,EP1,EP2,e1,e2,f1,f2,f: LIST;
BEGIN
   F:=SIL;
   LOOP (* 1 *)
      IF F1=SIL THEN
	 WHILE F2<>SIL DO ADV(F2,EP2,F2); F:=COMP(EP2,F); END;
	 RETURN(INV(F));
      END;
      ADV(F1,EP1,F1);
      FIRST2(EP1,e1,f1);
      IF F2=SIL THEN
	 F:=COMP(EP1,F);
	 WHILE F1<>SIL DO ADV(F1,EP1,F1); F:=COMP(EP1,F); END;
	 RETURN(INV(F));
      END;
      ADV(F2,EP2,F2);
      FIRST2(EP2,e2,f2);
      LOOP (* 2 *)
	 IF e1=e2 THEN
	    f:=IPPROD(r,f1,f2);
	    F:=COMP(LIST2(e1,f),F);
	    EXIT;
	 END;
	 IF e1<e2 THEN
	    F:=COMP(EP1,F);
	    IF F1=SIL THEN
	       F:=COMP(EP2,F);
	       WHILE F2<>SIL DO ADV(F2,EP2,F2); F:=COMP(EP2,F); END;
	       RETURN(INV(F));
	    END;
	    ADV(F1,EP1,F1);
	    FIRST2(EP1,e1,f1); 
	 ELSE (* e1>e2 *)
	    F:=COMP(EP2,F);
	    IF F2=SIL THEN
	       F:=COMP(EP1,F);
	       WHILE F1<>SIL DO ADV(F1,EP1,F1); F:=COMP(EP1,F); END;
	       RETURN(INV(F));
	    END;
	    ADV(F2,EP2,F2);
	    FIRST2(EP2,e2,f2);
	 END; (* IF e1<e2... *)
      END; (* LOOP 2 *)
   END; (* LOOP 1 *)
END IPFLMER;

END MASPGCD.
