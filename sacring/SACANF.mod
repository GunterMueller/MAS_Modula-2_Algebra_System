(* ----------------------------------------------------------------------------
 * $Id: SACANF.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACANF.mi,v $
 * Revision 1.3  1992/10/15  16:28:54  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:44  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:50  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACANF;

(* SAC Algebraic Number Field Implementation Module. *)



(* import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    EQUAL, RED2, SECOND, LIST2;

FROM SACRN IMPORT RNSIGN, RNINT, RNINV, RNNEG;

FROM SACPOL IMPORT PLDCF, PDEG, PBIN;

FROM SACIPOL IMPORT IUPBES;

FROM SACPGCD IMPORT IPPGSD, IPSRP;

FROM SACRPOL IMPORT RPSUM, RPRNP, RPNEG, RPDIF, RPQR, RPPROD;

FROM SACROOT IMPORT IUPVSI, RIB;

CONST rcsidi = "$Id: SACANF.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE AFDIF(AL,BL: LIST): LIST; 
(*Algebraic number field element difference.  AL and BL are elements
of Q(alpha) for some algebraic number alpha.  CL=AL-BL.*)
VAR  CL: LIST; 
BEGIN
(*1*) CL:=RPDIF(1,AL,BL); RETURN(CL); 
(*4*) END AFDIF; 


PROCEDURE AFINV(M,AL: LIST): LIST; 
(*Algebraic number field inverse.  AL is a nonzero
element of Q(alpha) for some algebraic number alpha.  M is the
rational minimal polynomial for alpha.  BL=1/AL.*)
VAR  AL1, AL2, AL3, BL, CL, J1Y, QL, RL, VL1, VL2, VL3: LIST; 
BEGIN
(*1*) AL1:=M; AL2:=AL; VL1:=0; RL:=RNINT(1); VL2:=LIST2(0,RL); 
      LOOP J1Y:=PLDCF(AL2); CL:=RNINV(J1Y); VL2:=RPRNP(1,CL,VL2); 
           IF PDEG(AL2) = 0 THEN BL:=VL2; RETURN(BL); END; 
           AL2:=RPRNP(1,CL,AL2); RPQR(1,AL1,AL2, QL,AL3); 
           J1Y:=RPPROD(1,QL,VL2); VL3:=RPDIF(1,VL1,J1Y); AL1:=AL2; 
           AL2:=AL3; VL1:=VL2; VL2:=VL3; 
           END; 
(*4*) RETURN(BL); END AFINV; 


PROCEDURE AFNEG(AL: LIST): LIST; 
(*Algebraic number field element negation.  AL is an element of
Q(alpha) for some algebraic number alpha.  BL= -AL.*)
VAR  BL: LIST; 
BEGIN
(*1*) BL:=RPNEG(1,AL); RETURN(BL); 
(*4*) END AFNEG; 


PROCEDURE AFPROD(M,AL,BL: LIST): LIST; 
(*Algebraic number field element product.  AL and BL are elements of
Q(alpha) for some algebraic number alpha.  M is the minimal polynomial
of alpha.  CL=AL+BL.*)
VAR  CL, CLP, QL: LIST; 
BEGIN
(*1*) CLP:=RPPROD(1,AL,BL); RPQR(1,CLP,M, QL,CL); 
(*4*) RETURN(CL); END AFPROD; 


PROCEDURE AFQ(M,AL,BL: LIST): LIST; 
(*Algebraic number field quotient.  AL and BL are
elements of Q(alpha) for some algebraic number alpha with BL
nonzero.  M is the minimal polynomial for alpha.  CL=AL/BL.*)
VAR  CL, J1Y: LIST; 
BEGIN
(*1*) IF AL = 0 THEN CL:=0; ELSE J1Y:=AFINV(M,BL); 
         CL:=AFPROD(M,AL,J1Y); END; 
      RETURN(CL); 
(*4*) END AFQ; 


PROCEDURE AFSIGN(M,I,AL: LIST): LIST; 
(*Algebraic number field sign.  M is the integral minimal polynomial
of a real algebraic number alpha.  I is an acceptable isolating
interval for alpha.  AL is an element of Q(alpha).  SL=SIGN(AL).*)
VAR  ALP, ALS, IS, J1Y, NL, RL, SL, SLH, SLP, SLS, UL, VL, WL:
     LIST; 
BEGIN
(*1*) (*AL rational.*) 
      IF AL = 0 THEN SL:=0; RETURN(SL); END; 
      IF PDEG(AL) = 0 THEN J1Y:=SECOND(AL); SL:=RNSIGN(J1Y); 
         RETURN(SL); END; 
(*2*) (*Obtain the greatest squarefree divisor of an integral
      polynomial similiar to AL.*) IPSRP(1,AL, RL,ALP); 
      SLS:=RNSIGN(RL); ALS:=IPPGSD(1,ALP); IS:=I; FIRST2(IS, UL,VL); 
      SLP:=0; 
(*3*) (*Obtain an isolating interval for alpha containing no roots of
      ALS.  Return SIGN(AL(alpha)). *) 
      LOOP NL:=IUPVSI(ALS,IS); WL:=RIB(UL,VL); 
           IF NL = 0 THEN SL:=IUPBES(ALP,WL); SL:=SLS*SL; 
              RETURN(SL); END; 
           IF SLP = 0 THEN SLP:=IUPBES(M,VL); END; 
           SLH:=IUPBES(M,WL); 
           IF SLH <> SLP THEN UL:=WL; ELSE VL:=WL; SLP:=SLH; END; 
           IS:=LIST2(UL,VL); 
           END; 
(*6*) RETURN(SL); END AFSIGN; 


PROCEDURE AFSUM(AL,BL: LIST): LIST; 
(*Algebraic number field element sum.  AL and BL are elements of
Q(alpha) for some algebraic number alpha.  CL=AL+BL.*)
VAR  CL: LIST; 
BEGIN
(*1*) CL:=RPSUM(1,AL,BL); RETURN(CL); 
(*4*) END AFSUM; 


PROCEDURE RUPMRN(R: LIST): LIST; 
(*Rational univariate polynomial minimal polynomial of a rational number.  
R is a rational number.  M is the rational minimal polynomial of R.*)
VAR  J1Y, J2Y, M: LIST; 
BEGIN
(*1*) J1Y:=RNINT(1); J2Y:=RNNEG(R); M:=PBIN(J1Y,1,J2Y,0); RETURN(M); 
(*4*) END RUPMRN; 


END SACANF.
(* -EOF- *)
