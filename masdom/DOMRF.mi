(* ----------------------------------------------------------------------------
 * $Id: DOMRF.mi,v 1.5 1994/09/06 11:49:11 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMRF.mi,v $
 * Revision 1.5  1994/09/06  11:49:11  rose
 * modified comment
 *
 * Revision 1.4  1994/05/19  10:43:07  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1992/10/15  16:30:20  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:34  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:51  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMRF;

(* MAS Domain Rational Function Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, LENGTH;

FROM MASERR IMPORT harmless, severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetGcdFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetWritFunc, 
                    (*SetVlddFunc,*) SetDdrdFunc, SetDdwrFunc, 
		    SetPNormFunc, SetPSpolFunc, SetPSugNormFunc,
		    SetPSugSpolFunc;

FROM MASBIOS IMPORT BLINES, SWRITE, CREADB, DIGIT, MASORD, BKSP; 

FROM SACLIST IMPORT AREAD, AWRITE, OWRITE, FIRST2, LIST2, SECOND;

FROM DIPRF IMPORT RFSIGN, RFREAD, RFWRIT, RFSUM, RFNUM, RFFIP, RFNOV,  
                  RFEXP, RFONE, RFNEG, RFINV, RFQ, RFDIF, RFPROD;
FROM SACPOL IMPORT VLREAD, VLWRIT, PINV; 

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;

FROM DIPGB IMPORT DIPNOR, DIPSP;


(* Domain:            (dom, val, V) 
   Domain descriptor:           (V) 

   where: val   = rational function  
          V     = variable list  
*)

CONST rcsidi = "$Id: DOMRF.mi,v 1.5 1994/09/06 11:49:11 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RFDIF(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=RFEXP(AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL, RL, BL: LIST; 
BEGIN
(*1*) (*select. *) ADV(D,BL,D); RL:=RFNOV(BL);
(*2*) (*compute. *) CL:=PINV(0,A,RL); CL:=RFFIP(RL,CL); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain element with descriptor, 
A is an integral polynomial in #vldd(D) variables. *)
VAR   C, CL, RL, BL: LIST; 
BEGIN
(*1*) (*select. *) ADV(D,BL,D); RL:=RFNOV(BL);  
(*2*) (*compute. *) CL:=RFFIP(RL,A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=RFINV(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) TL:=1; 
      IF RFNUM(AL) = 0 THEN TL:=0 END; 
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) CL:=RFNEG(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=RFONE(AL); 
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
(*2*) (*compute. *) CL:=RFPROD(AL,BL);
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
(*2*) (*compute. *) CL:=RFQ(AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL, V: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); V:=FIRST(D); 
(*2*) (*read. *) CL:=RFREAD(V); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*compute. *) SL:=RFSIGN(AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RFSUM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, V: LIST; 
BEGIN
(*1*) (*advance. *) FIRST2(A,AL,V); 
(*2*) (*write. *) RFWRIT(AL,V); 
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   V, D, RL, AL: LIST;  
BEGIN
(*1*) (*read. *) V:=VLREAD(); RL:=LENGTH(V); 
(*3*) (*create. *) AL:=RFFIP(RL,0); D:=LIST2(AL,V); 
(*5*) RETURN(D); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   V: LIST;
BEGIN
(*1*) (*select. *) D:=RED(D); V:=FIRST(D); 
(*2*) (*write. *) VLWRIT(V); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DomLoadRF();
(*Domain load modular digit. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("RF","Rational Function"); DOMRFD:=d;
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
(*3*) SetPNormFunc(d,DPNF);
      SetPSpolFunc(d,DPSP);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
(*9*) END DomLoadRF;


END DOMRF.
(* -EOF- *)
