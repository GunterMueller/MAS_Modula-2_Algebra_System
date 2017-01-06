(* ----------------------------------------------------------------------------
 * $Id: DIPROOT.mi,v 1.5 1996/06/08 14:13:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPROOT.mi,v $
 * Revision 1.5  1996/06/08 14:13:56  kredel
 * Correction to interval.
 *
 * Revision 1.4  1992/10/15  16:29:40  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/07/09  13:13:44  kredel
 * Corrected spelling error.
 *
 * Revision 1.2  1992/02/12  17:34:25  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:02  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPROOT;

(* DIP Ideal Real Root System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, BETA, SIL, LENGTH,
                    LIST1, ADV, FIRST, RED, SFIRST, SRED, COMP, INV;

FROM MASERR IMPORT ERROR, fatal, severe; 

FROM MASBIOS IMPORT SWRITE, BLINES, SOLINE;

FROM SACLIST IMPORT COMP2, COMP3, LIST4, LIST3, LIST2, FIRST3, FIRST2, 
                    RED2, RED3, CONC, CCONC, CINV, LELT, OWRITE, 
                    CLOUT, EQUAL, AWRITE, ADV2, ADV3, ADV4;

FROM SACSET IMPORT USDIFF, USUN;

FROM SACI IMPORT ICOMP, IEXP, ILOG2, IMAX, IMIN, IPROD;

FROM SACRN IMPORT RNWRIT, RNRED, RNSIGN, RNINT, RNDEN, RNPROD, RNSUM;

FROM MASRN IMPORT RNDWR;

FROM SACPOL IMPORT VLWRIT;

FROM DIPC IMPORT DIPMRD, DIPEVL, DIPEXC, DIPLBC, DIPNOV, DIPADM, 
                 DIPLDC, DIPFMO, DIPMPV, DIPINV, 
                 VALIS, DIPERM, PFDIP, DIPADV, DIPFP;

FROM DIPRN IMPORT DIRFIP, DIRLWR, DIRPWR, DIRPEV, 
                  DIRPPR, DIRPDF, DIRPRP, DIRPSM;

FROM DIPRNGB IMPORT DIRPNF, DIRPGB, DIRGBA;

FROM SACROOT IMPORT IPRIM, IPRCHS;

FROM SACANF IMPORT AFSIGN;

FROM DIPIDEAL IMPORT DIPLDV;

FROM DIPDEC0 IMPORT DINTSR, DIRGZS, DINTZS, DITSPL;

CONST TRAFL = 2;

CONST rcsidi = "$Id: DIPROOT.mi,v 1.5 1996/06/08 14:13:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBSI(P,T,A: LIST): LIST; 
(*Distributive polynomial system algebraic number G basis sign.
P is a goebner basis in inverse lexicographical term order
in r variables (non empty), with all neccessary refinements.
T=(t1,... ,ti) i le r, where tj=(vj,ij,pj) j=1, ...,i and v is 
the character list for the j-th variable, ij is an isolating 
interval for a real root of the univariate polynomial pjl.
A is a distributive rational polynomial depending maximal on one 
variable. s is the sign of A as element of an algebraic extension
of Q determined by P. *)
VAR  AL, B, BP, EL, FL1, FL2, I, IL, J, J1Y, PL, RL, RLP, SL, TL, VL:
     LIST; 
BEGIN
(*1*) (*determine the variable on which a depend. *) J1Y:=FIRST(P); 
      RL:=DIPNOV(J1Y); EL:=DIPEVL(A); 
      WHILE (EL <> SIL) AND (FIRST(EL) = 0) DO EL:=RED(EL); 
      END; 
      IL:=LENGTH(EL); 
      IF IL = 0 THEN AL:=DIPLBC(A); SL:=RNSIGN(AL); RETURN(SL); 
      END; 
(*2*) (*get corresponding univariate polynomial. *) B:=A; 
      FOR J:=RL TO IL+1 BY -1 DO DIPADM(B, FL1,FL2,B,BP); END; 
      B:=DIPEXC(B,1,IL); 
      FOR J:=IL TO 2 BY -1 DO DIPADM(B, FL1,FL2,B,BP); END; 
(*3*) (*determine sign. *) PFDIP(B, RLP,B); TL:=LELT(T,IL); FIRST3(TL,
      VL,I,PL); SL:=AFSIGN(PL,I,B); 
(*6*) RETURN(SL); END DIGBSI; 


PROCEDURE DIITNT(T: LIST): LIST; 
(*Distributive polynomial system interval tupel from norm tupel.
T is a refined normalized tupel of a zero set with a final Goebner 
base of dimension 0. TP is a list of interval tupels for T. *)
VAR  A, A1, A2, EL, FL, I, I1, I2, IL, ILP, J1Y, L, P, PB, PL, PP, R,
     RL, S1, S2, TB, TL, TP, TPP, TS, V, VL, VP: LIST; 
BEGIN
(*1*) (*initialise. *) TP:=BETA; TL:=BETA; 
      IF T = SIL THEN RETURN(TP); END; 
      ADV3(T, FL,VP,PP,TB); RL:=LENGTH(VP); 
(*2*) (*calculate isolating intervals for the roots for il=1. *) 
      IL:=1; PB:=RED(PP); ADV3(TB, FL,V,P,TB); FIRST2(P, EL,PL); 
      VL:=FIRST(V); L:=IPRIM(PL); 
      WHILE L <> SIL DO ADV(L, I,L); J1Y:=LIST3(VL,I,PL); 
            R:=LIST1(J1Y); TP:=COMP(R,TP); END; 
      TP:=INV(TP); 
(*3*) (*calculate isolating intervals for the roots for il ge 2. *) 
      WHILE TB <> SIL DO ILP:=IL; IL:=IL+1; TS:=BETA; ADV3(TB,
            FL,V,P,TB); ADV(PB, A,PB); FIRST2(P, EL,PL); VL:=FIRST(V); 
            L:=IPRIM(PL); 
            WHILE L <> SIL DO ADV(L, I,L); FIRST2(I, I1,I2); 
                  A1:=DIRPEV(A,IL,I1); A1:=DIPINV(A1,ILP,1); 
                  A1:=DIRPNF(PP,A1); A2:=DIRPEV(A,IL,I2); 
                  A2:=DIPINV(A2,ILP,1); A2:=DIRPNF(PP,A2); TPP:=TP; 
                  WHILE TPP <> SIL DO ADV(TPP, TL,TPP); 
                        S1:=DIGBSI(PP,TL,A1); S2:=DIGBSI(PP,TL,A2); 
                        IF S1*S2 <= 0 THEN R:=LIST3(VL,I,PL); 
                           TL:=CINV(TL); TL:=COMP(R,TL); TL:=INV(TL); 
                           TS:=COMP(TL,TS); END; 
                        END; 
                  END; 
            TP:=INV(TS); END; 
(*4*) (*finish. *) RETURN(TP); 
(*7*) END DIITNT; 


PROCEDURE DIITWR(TP,EPS: LIST); 
(*Distributive polynomial system interval tupels write. TP is a list 
of interval tupels of a zero set. EPS is LOG10 of the desired 
precision. *)
VAR  E, I, J, J1Y, R, RL, T, TL, VS: LIST; 
BEGIN
(*1*) (*empty or initialise. *) T:=TP; 
      IF T = SIL THEN RETURN; END; 
      J1Y:=IEXP(10,EPS); E:=RNRED(1,J1Y); VS:=VALIS; RL:=LENGTH(VS); 
(*2*) (*roots for single tupels. *) J:=0; 
      WHILE T <> SIL DO ADV(T, TL,T); J:=J+1; 
            BLINES(1); SWRITE("Zero set tupel no "); AWRITE(J); 
            BLINES(1); 
            WHILE TL <> SIL DO ADV(TL, R,TL); RIRWRT(R,E); END; 
            BLINES(1); END; 
(*3*) (*finish. *) RETURN; 
(*6*) END DIITWR; 


PROCEDURE DINTWR(TP,EPS: LIST); 
(*Distributive polynomial system normalized tupels write.
TP is a list of normalized tupels of a zero set. EPS is log10 of 
the desired precision. *)
VAR  E, FL, I, J, J1Y, PL, RL, T, TL, U, UP, V, VS: LIST; 
BEGIN
(*1*) (*empty or initialise. *) T:=TP; 
      IF T = SIL THEN RETURN; END; 
      J1Y:=IEXP(10,EPS); E:=RNRED(1,J1Y); VS:=VALIS; RL:=LENGTH(VS); 
(*2*) (*roots, groebner basis for single tupels. *) J:=0; 
      WHILE T <> SIL DO ADV(T, TL,T); J:=J+1; 
            SWRITE("Zero set tupel no "); AWRITE(J); BLINES(1); 
            WHILE TL <> SIL DO ADV3(TL, FL,V,PL,TL); 
                  CASE INTEGER(FL) OF
                       1 : DIROWR(V,PL,E); |
                       2 : SWRITE("The groebner basis in the variables "); 
                           U:=DIPLDV(PL,VS); UP:=USDIFF(VS,U); 
                           VLWRIT(U); DIRLWR(PL,V,-1); 
                           IF U = SIL THEN
                              SWRITE("There are no roots at all"); 
                              ELSE SWRITE("Exponent zero variables "); 
                              VLWRIT(UP); END; 
                           BLINES(2); |
                       3 : SWRITE("The total ring D"); VLWRIT(V); 
                           BLINES(2); |
                       4 : SWRITE("The generating polynomial for tree "); 
                           DIRLWR(PL,V,-1); BLINES(2); |
                       5 : SWRITE("Groebner basis for tree"); 
                           DIRLWR(PL,V,-1); BLINES(2); |
                       6 : SWRITE("Characterising groebner basis"); 
                           DIRLWR(PL,V,-1); BLINES(2); 
                      ELSE SWRITE("Invalid flag in DINTWR "); 
                           OWRITE(FL); BLINES(1) END; 
                  END; 
            END; 
(*3*) (*finish. *) 
      BLINES(1); 
(*6*) END DINTWR; 


PROCEDURE DIROWR(V,P,EPS: LIST); 
(*Distributive polynomial system real root write. V is a variable 
list. P is a list (e,p). EPS is the desired precision. e is the 
multiplicity of the root, and p is an irreducible polynomial. *)
VAR   AL, BL, CL, EL, I, IL, J1Y, J2Y, KL, L,
      ILEN, LM, LS, PL, QL, S, VL, W, Z: LIST; 
BEGIN
(*1*) (*write polynomial and multipicity of the root. *) 
      IF LENGTH(V) <> 1 THEN RETURN; END; 
      FIRST2(P, EL,PL); VL:=FIRST(V); 
      SWRITE("Characterising polynomial for the real roots is"); 
      BLINES(1); QL:=DIPFP(1,PL); QL:=DIRFIP(QL); SWRITE("p"); 
      VLWRIT(V); SWRITE(" = "); DIRPWR(QL,V,-1); 
      IF EL <> 1 THEN SWRITE("**"); AWRITE(EL); END; 
      BLINES(1); 
      IF TRAFL < 100 THEN RETURN END;
(*2*) (*calculate the real roots. *) 
      L:=IPRIM(PL); 
      IF L = SIL THEN SWRITE("There are no real roots"); 
         ELSE SWRITE("The isolating interval"); 
         IF RED(L) = SIL 
            THEN SWRITE(" for the the real root is"); 
            ELSE SWRITE("s for the the real roots are"); END; 
         END; 
      BLINES(1); 
(*3*) (*write isolating intervals and approximation. *) 
      WHILE L <> SIL DO ADV(L, IL,L); FIRST2(IL, AL,BL); 
            CLOUT(VL); SWRITE(" = "); 
            SWRITE("("); RNWRIT(AL); SWRITE(", "); RNWRIT(BL); SWRITE(")"); 
            BLINES(1); 
            IF TRAFL >= 2 THEN
               IF EQUAL(AL,BL) <> 1 THEN J1Y:=RNDEN(EPS); 
                  J1Y:=ILOG2(J1Y); KL:=J1Y+1; KL:=-KL; 
                  I:=IPRCHS(PL,IL,KL); 
                  IL:=FIRST(I); FIRST2(IL, AL,BL); 
                  END; 
               J1Y:=RNDEN(AL); J2Y:=RNDEN(BL); ILEN:=IMAX(J1Y,J2Y); 
               J1Y:=RNDEN(EPS); ILEN:=IMIN(ILEN,J1Y); Z:=10; LS:=1; 
               S:=0; 
               WHILE ICOMP(ILEN,LS) >= 0 DO S:=S+1; 
                     LS:=IPROD(LS,Z); END; 
               W:=RNRED(1,2); CL:=RNSUM(AL,BL); CL:=RNPROD(CL,W); 
               CLOUT(VL); SWRITE(" = "); RNDWR(CL,S); 
               BLINES(1); END; 
            END; 
(*6*) END DIROWR; 


PROCEDURE GBZSET(V,PP,EPS: LIST); 
(*Groebner base real zero set of zero dimensional ideal. 
V is a variable list. PP is a list of distributive rational polynomials,
PP is a Groebner base. EPS is is LOG10 of the desired precision. *)
VAR   N, T, T0, T1, TL, TP: LIST; 
BEGIN
(*1*) (*zero set. *) N:=DIRGZS(V,PP,V); 
(*2*) (*zero set tupels. *) T:=DINTZS(N);  
      SWRITE("The normalized tupels"); BLINES(1); 
      DINTWR(T,EPS); 
      DITSPL(T, T0,T1); IF T0 = SIL THEN RETURN; END; 
      T0:=DINTSR(T0); 
      SWRITE("The refined tupels"); BLINES(1); 
      DINTWR(T0,EPS); 
(*3*) (*write zero set as interval tupels. *) TP:=SIL; 
      WHILE T0 <> SIL DO ADV(T0, TL,T0); TL:=DIITNT(TL); 
            TP:=CONC(TP,TL); END; 
      SWRITE("The zero set for dim 0 tupels"); BLINES(1); 
      DIITWR(TP,EPS); 
(*6*) END GBZSET; 


PROCEDURE RIRWRT(R,EPS: LIST); 
(*Rational interval refinement write. R=(v,i,p) where v is the 
variable character string, i is a rational interval containing only
one real root of the polynomial p. EPS is the presicion epsilon. *)
VAR   AL, BL, CL, I, IL, ILEN, J1Y, J2Y, KL, LM, LS,
      PL, QL, S, V, VL, W, Z: LIST; 
BEGIN
(*1*) (*write polynomial.*) FIRST3(R, VL,IL,PL); 
      IF TRAFL >= 2 THEN
         SWRITE("Characterising polynomial for the real root is"); 
         BLINES(1); 
         QL:=DIPFP(1,PL); QL:=DIRFIP(QL); V:=LIST1(VL); 
         SWRITE("p"); VLWRIT(V); SWRITE(" = "); 
         DIRPWR(QL,V,-1); BLINES(1) END; 
      IF IL = SIL THEN RETURN; END; 
(*3*) (*write isolating interval on output stream. *) 
      FIRST2(IL, AL,BL); 
      IF TRAFL >= 2 THEN
         SWRITE("The isolating interval for the real root is"); 
         BLINES(1); CLOUT(VL); SWRITE(" = (");  
         RNWRIT(AL); SWRITE(", "); RNWRIT(BL); SWRITE(")"); 
         BLINES(1); END; 
(*4*) (*refine root isolating interval. *) 
      IF EQUAL(AL,BL) <> 1 THEN 
         J1Y:=RNDEN(EPS); J1Y:=ILOG2(J1Y); KL:=J1Y+1; KL:=-KL; 
         I:=IPRCHS(PL,IL,KL); IL:=FIRST(I); END; 
(*5*) (*compute number of exact decimal digits determined and wanted.*) 
      FIRST2(IL, AL,BL); J1Y:=RNDEN(AL); J2Y:=RNDEN(BL); 
      ILEN:=IMAX(J1Y,J2Y); J1Y:=RNDEN(EPS); ILEN:=IMIN(ILEN,J1Y); 
      Z:=10; LS:=1; S:=0; 
      WHILE ICOMP(ILEN,LS) >= 0 DO S:=S+1; LS:=IPROD(LS,Z); END; 
(*6*) (*write refined interval in decimal aproximation. *) 
      IF TRAFL >= 2 THEN
         SWRITE("The decimal approximation for the real root is"); 
         BLINES(1); END; 
      CLOUT(VL); SWRITE(" = "); W:=RNRED(1,2); CL:=RNSUM(AL,BL); 
      CL:=RNPROD(CL,W); RNDWR(CL,S); 
(*7*) (*finish. *) BLINES(1); 
(*9*) END RIRWRT; 


END DIPROOT.
(* -EOF- *)
