(* ----------------------------------------------------------------------------
 * $Id: DOMQ.mi,v 1.5 1994/09/06 11:49:09 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMQ.mi,v $
 * Revision 1.5  1994/09/06  11:49:09  rose
 * modified comment
 *
 * Revision 1.4  1994/05/19  10:43:05  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1994/03/11  15:54:10  pesch
 * Minor corrections.
 *
 * Revision 1.2  1992/10/15  16:30:19  kredel
 * Changed rcsid variable
 *
 * Revision 1.1  1992/09/28  17:47:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMQ;

(* MAS Domain Quaternion Number Implementation Module. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP;

FROM MASERR IMPORT  harmless, severe, fatal, ERROR;

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

FROM MASQ  IMPORT QNREAD, QNWRITE, QSUM, QINT,  
                  QNEG, QINV, QQ, QDIF, QPROD,
                  QDREAD, QDWRITE, QONE, QEXP;

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;

FROM DIPGB IMPORT DIPNOR, DIPSP;

CONST rcsidi = "$Id: DOMQ.mi,v 1.5 1994/09/06 11:49:09 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Domain:            (dom, val, prec) 
   Domain descriptor:           (prec) 

   where: val   = complex number  
          prec  = write precision, -1 = write as rational number 
*)


PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=QDIF(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=QEXP(AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); 
(*2*) (*compute. *) CL:=QINT(A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain eleement with descriptor, 
A is an integral polynomial in 0 variables, so it is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); 
(*2*) (*compute. *) CL:=QINT(A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=QINV(AL);
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
(*2*) (*compute. *) CL:=QNEG(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=QONE(AL); 
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
(*2*) (*compute. *) CL:=QPROD(AL,BL);
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
(*2*) (*compute. *) CL:=QQ(AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*read. *) CL:=QDREAD(); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*compute. *) IF AL = 0 THEN SL:=0 ELSE SL:=1 END;
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=QSUM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) FIRST2(A,AL,SL); 
(*2*) (*write. *) IF SL < 0 THEN QNWRITE(AL) ELSE QDWRITE(AL,SL) END;
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


PROCEDURE DomLoadQ();
(*Domain load Quaternion number. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("Q","Quaternion Number"); DOMQD:=d;
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
(*9*) END DomLoadQ;


END DOMQ.
(* -EOF- *)
