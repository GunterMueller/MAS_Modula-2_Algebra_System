(* ----------------------------------------------------------------------------
 * $Id: DIPZ.mi,v 1.3 1992/10/15 16:29:41 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPZ.mi,v $
 * Revision 1.3  1992/10/15  16:29:41  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:27  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPZ;

(* DIP Zero Dimensional Ideal Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, 
                    LIST1, FIRST, RED, ADV, COMP, INV, LENGTH;

FROM MASBIOS IMPORT SWRITE, BLINES, TAB, SOLINE;

FROM SACLIST IMPORT LELT, CCONC, EQUAL, MEMBER, LIST2,  
                    ADV2, ADV4, ADV3, FIRST4, FIRST2;

FROM SACRN IMPORT RNINT, RNNEG, RNSUM;

FROM SACPOL IMPORT PINV, PMON;

FROM SACRPOL IMPORT RPSUM;

FROM DIPC IMPORT DIPEVL, DIPNOV, EVDOV, DILFPL, DIPFMO, DIPFP,
                 VALIS, EVORD, INVLEX, 
                 DIPMPV, DIPTBC, DIPBSO, PFDIP, PMPV, PBCLI;

FROM DIPRN IMPORT DIRPEM;

FROM DIPRNGB IMPORT DIRPNF, DIRLIS;

FROM DIPDIM IMPORT DIGBZT;

CONST rcsidi = "$Id: DIPZ.mi,v 1.3 1992/10/15 16:29:41 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRMPG(IL,F: LIST): LIST; 
(*Distributive rational minimal polynomial for a groebner basis.
F is a groebner basis. PP is the minimal polynomial for the
i-th variable for F. *)
VAR   C, CL, CLP, CP, CS, EINS, EL, J1Y, JL, EVOREM, EVOCOR,
      LL, NL, P, PL, PP, RL, RLS, TL, X, XP, YP: LIST; 
      ec: BOOLEAN;
BEGIN
(*1*) (*initialise. *) 
      IF F = SIL THEN PP:=0; RETURN(PP); END; 
      J1Y:=FIRST(F); RL:=DIPNOV(J1Y); EINS:=RNINT(1); 
      EVOREM:=EVORD; EVOCOR:=INVLEX; ec:=(EVOREM = EVOCOR); 
      EL:=BETA; 
      FOR JL:=1 TO RL DO EL:=COMP(0,EL); END; 
      X:=DIPFMO(EINS,EL); LL:=1; NL:=RL+LL; PFDIP(X, RLS,P); 
      P:=PINV(RL,P,1); P:=PMPV(NL,P,LL,1); 
(*2*) (*solve linear systems of equations to get the coefficients. *) 
      REPEAT XP:=DIPMPV(X,IL,LL); LL:=LL+1; XP:=DIRPNF(F,XP); 
             IF NOT ec THEN EVORD:=EVOCOR; DIPBSO(XP); END; 
             PFDIP(XP, RLS,YP); YP:=PINV(RL,YP,LL); NL:=RL+LL; 
             YP:=PMPV(NL,YP,LL,1); P:=PINV(RL,P,1); P:=RPSUM(NL,P,YP); 
             CP:=PBCLI(RL,P); C:=DILFPL(LL,CP); CS:=BETA; 
             WHILE C <> SIL DO ADV(C, CL,C); CL:=DIRPEM(CL,EINS); 
                   CS:=COMP(CL,CS); END; 
             C:=INV(CS); C:=DIRLIS(C); TL:=DIGBZT(C); 
             IF  NOT ec THEN EVORD:=EVOREM; END; 
             UNTIL TL = 0; 
      LL:=LL-1; 
(*3*) (*constuct minimal polynomial. *) PP:=PMON(EINS,LL); 
      WHILE C <> SIL DO ADV(C, CL,C); EL:=DIPEVL(CL); 
            J1Y:=EVDOV(EL); J1Y:=FIRST(J1Y); NL:=LL-J1Y; 
            J1Y:=DIPTBC(CL); CLP:=RNNEG(J1Y); PL:=PMON(CLP,NL); 
            PP:=RPSUM(1,PP,PL); END; 
      PP:=DIPFP(1,PP); 
(*6*) RETURN(PP); END DIRMPG; 


END DIPZ.

(* -EOF- *)
