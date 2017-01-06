(* ----------------------------------------------------------------------------
 * $Id: DOMRN.mi,v 1.5 1994/06/10 12:04:33 pfeil Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMRN.mi,v $
 * Revision 1.5  1994/06/10  12:04:33  pfeil
 * Added Procedures DPSFF, DPFAC for DIPDCGB
 *
 * Revision 1.4  1994/05/19  10:43:10  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1992/10/15  16:30:21  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:36  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:53  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMRN;

(* MAS Domain Rational Number Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, BETA, INV;

FROM MASERR IMPORT harmless, severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetGcdFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetWritFunc, 
                    (*SetVlddFunc,*) SetDdrdFunc, SetDdwrFunc,
		    SetPFactFunc, SetPSqfrFunc, SetPNormFunc,
		    SetPSpolFunc, SetPSugNormFunc, SetPSugSpolFunc;

FROM MASBIOS IMPORT BLINES, SWRITE, CREADB, DIGIT, MASORD, BKSP; 

FROM SACLIST IMPORT AREAD, AWRITE, OWRITE, FIRST2, LIST2, SECOND;

FROM SACRN IMPORT RNSIGN, RNREAD, RNWRIT, RNSUM, RNINT,  
                  RNNEG, RNINV, RNQ, RNDIF, RNPROD;

FROM MASRN IMPORT RNDRD, RNDWR, RNONE, RNEXP;

FROM DIPI IMPORT DIIFRP;

FROM DIPC IMPORT PFDIP, DIPFP;

FROM DIPRN IMPORT DIRFIP;

FROM SACPFAC IMPORT IPFAC;

FROM MASPGCD IMPORT IPSFF;

FROM DIPGB IMPORT DIPNOR, DIPSP;

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;


(* Domain:            (dom, val, prec) 
   Domain descriptor:           (prec) 

   where: val   = rational number  
          prec  = write precision, -1 = write as rational number 
*)

CONST rcsidi = "$Id: DOMRN.mi,v 1.5 1994/06/10 12:04:33 pfeil Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RNDIF(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=RNEXP(AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); 
(*2*) (*compute. *) CL:=RNINT(A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain eleement with descriptor, 
A is an integral polynomial in 0 variables, so it is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); 
(*2*) (*compute. *) CL:=RNINT(A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=RNINV(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) TL:=1; 
      IF AL = 0 THEN TL:=0 END; 
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) CL:=RNNEG(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=RNONE(AL); 
(*5*) RETURN(SL); END DONE; 


PROCEDURE DPNF(G,P: LIST): LIST;
(* domain polynomial normalform.
   G is a list of polynomials in distributive
   representation with coefficients from the domain,
   P is a polynomial as above,
   h is a polynomial such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(DIPNOR(G,P));
END DPNF;


PROCEDURE DPROD(A,B: LIST): LIST; 
(*Domain product. c=a*b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RNPROD(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DPROD; 


PROCEDURE DPSP(A,B: LIST): LIST;
(* domain polynomial S-polynomial.
   A and B are polynomials in distributive representation
   with coefficients from the domain,
   S is the S-polynomial of A and B *)

BEGIN
   RETURN(DIPSP(A,B));
END DPSP;


PROCEDURE DPSUGNF(G,P: LIST): LIST;
(* domain polynomial normal with sugar strategy normalform.
   G is a list of extended polynomials in distributive
   representation with coefficients from the domain,
   P is an extended polynomial as above,
   h is an extended polynomial such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(EDIPSUGNOR(G,P));
END DPSUGNF;


PROCEDURE DPSUGSP(A,B: LIST): LIST;
(* domain polynomial normal with sugar strategy S-polynomial.
   A and B are extended polynomials in distributive representation
   with coefficients from the domain,
   S is the extended S-polynomial of A and B *)

BEGIN
   RETURN(EDIPSUGSP(A,B));
END DPSUGSP;


PROCEDURE DQUOT(A,B: LIST): LIST; 
(*Domain quotient. c=a/b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RNQ(AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*read. *) CL:=RNDRD(); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*compute. *) SL:=RNSIGN(AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RNSUM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) FIRST2(A,AL,SL); 
(*2*) (*write. *) IF SL < 0 THEN RNWRIT(AL) ELSE RNDWR(AL,SL) END;
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   D, C, SL: LIST;  
BEGIN
(*1*) (*read. *) SL:=-1; C:=CREADB(); BKSP; 
(*2*) (*check for number. *) 
      IF (C = MASORD("-")) OR (C = MASORD("-")) OR DIGIT(C) THEN  
         SL:=AREAD(); END;
      D:=LIST2(0,SL); 
(*5*) RETURN(D); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   SL: LIST;
BEGIN
(*1*) (*select. *) D:=RED(D); SL:=FIRST(D); 
(*2*) (*write. *) SWRITE(" "); AWRITE(SL); SWRITE(" "); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DPFAC(P: LIST): LIST;
(* domain polynomial factorization.
   P is a polynomial in distributive representation
   with coefficients from the domain,
   returns a list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where P = u * f1**e1 * ... * fk**ek and u unit. *)
VAR r,S,C,F,F1,ExpPol,exp,pol: LIST;
BEGIN
   P:=DIIFRP(P);	(* rational coeff. to integer coeff. *)
   PFDIP(P,r,P);	(* distributive to recursive *)
   IPFAC(r,P,S,C,F);	(* factorization *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);
      FIRST2(ExpPol,exp,pol);
      pol:=DIPFP(r,pol);	(* recursive to distributive *)
      pol:=DIRFIP(pol);	(* integer coeff. to rational coeff. *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END DPFAC;


PROCEDURE DPSFF(A: LIST): LIST;
(* domain polynomial factorization.
   P is a polynomial in distributive representation
   with coefficients from the domain,
   returns a list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where P = u * f1**e1 * ... * fk**ek and u unit. *)
VAR r,F,F1,ExpPol,exp,pol: LIST;
BEGIN
   A:=DIIFRP(A);	(* rational coeff. to integer coeff. *)
   PFDIP(A,r,A);	(* distributive to recursive *)
   F:=IPSFF(r,A);	(* factorization *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);
      FIRST2(ExpPol,exp,pol);
      pol:=DIPFP(r,pol);	(* recursive to distributive *)
      pol:=DIRFIP(pol);	(* integer coeff. to rational coeff. *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END DPSFF;


PROCEDURE DomLoadRN();
(*Domain load rational number. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("RN","Rational Number"); DOMRND:=d;
(*2*) SetDifFunc(d,DDIF); 
      SetExpFunc(d,DEXP); 
      SetFIntFunc(d,DFI); 
      SetFIPolFunc(d,DFIP); 
      SetInvFunc(d,DINV); 
      SetInvTFunc(d,DINVT); 
      SetNegFunc(d,DNEG); 
      SetOneFunc(d,DONE); 
      SetProdFunc(d,DPROD); 
      SetQuotFunc(d,DQUOT); 
      SetReadFunc(d,DREAD); 
      SetSignFunc(d,DSIGN); 
      SetSumFunc(d,DSUM); 
      SetWritFunc(d,DWRIT); 
      SetDdrdFunc(d,DDDRD); 
      SetDdwrFunc(d,DDDWR); 
(*3*) SetPFactFunc(d,DPFAC);
      SetPNormFunc(d,DPNF);
      SetPSqfrFunc(d,DPSFF);
      SetPSpolFunc(d,DPSP);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
(*9*) END DomLoadRN;


END DOMRN.
(* -EOF- *)
