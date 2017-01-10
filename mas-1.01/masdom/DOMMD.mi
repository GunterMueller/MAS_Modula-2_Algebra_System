(* ----------------------------------------------------------------------------
 * $Id: DOMMD.mi,v 1.5 1994/09/06 11:49:00 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMMD.mi,v $
 * Revision 1.5  1994/09/06  11:49:00  rose
 * modified comment
 *
 * Revision 1.4  1994/05/19  10:42:56  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1992/10/15  16:30:17  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:31  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:47  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMMD;

(* MAS Domain Modular Digit Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP;

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

FROM MASBIOS IMPORT BLINES, SWRITE; 

FROM SACLIST IMPORT OWRITE, FIRST2, LIST3, SECOND;

FROM SACI IMPORT ISIGNF, IREAD, IWRITE;

FROM SACM IMPORT MDSUM, MDHOM, MDNEG, MDINV,  
                 MDQ, MDEXP, MDDIF, MDPROD;

FROM SACPRIM IMPORT IFACT;

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;

FROM DIPGB IMPORT DIPNOR, DIPSP;

(* Domain:            (dom, val, mod, prime) 
   Domain descriptor:           (mod, prime) 

   where: val   = modular digit 
          mod   = modulus 
          prime = 1 if mod is prime, 0 else  
*)

CONST rcsidi = "$Id: DOMMD.mi,v 1.5 1994/09/06 11:49:00 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=MDDIF(M,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP);  
(*2*) (*compute. *) CL:=MDEXP(M,AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL, M: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); M:=FIRST(D); 
(*2*) (*compute. *) CL:=MDHOM(M,A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain eleement with descriptor, 
A is an integral polynomial in 0 variables, so it is an integer. *)
VAR   C, CL, M: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); M:=FIRST(D); 
(*2*) (*compute. *) CL:=MDHOM(M,A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); 
(*2*) (*compute. *) CL:=MDINV(M,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) TL:=0; 
      IF AL <> 0 THEN TL:=FIRST(AP) END; 
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP);
(*2*) (*compute. *) CL:=MDNEG(M,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=AL; IF SL <> 1 THEN SL:=0  END;
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
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=MDPROD(M,AL,BL);
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
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=MDQ(M,AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL, M: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); M:=FIRST(D);
(*2*) (*read. *) CL:=IREAD(); CL:=MDHOM(M,CL);  
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*compute. *) SL:=ISIGNF(AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=MDSUM(M,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*write. *) IWRITE(AL);
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   M, D, PL, MP: LIST;  
BEGIN
(*1*) (*read. *) M:=IREAD(); 
(*2*) (*check for prime number. *) MP:=IFACT(M); PL:=1;  
      IF RED(MP) <> SIL THEN OWRITE(MP); BLINES(0); 
         ERROR(harmless,"Warning: Modular digit not prime. "); 
         PL:=0; END;
      D:=LIST3(0,M,PL); 
(*5*) RETURN(D); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   M, PL: LIST;
BEGIN
(*1*) (*select. *) FIRST2(RED(D), M,PL); 
(*2*) (*write. *) SWRITE(" "); IWRITE(M); SWRITE(" (*"); 
      IF PL <> 1 THEN SWRITE(" not") END;
      SWRITE(" prime. *)"); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DomLoadMD();
(*Domain load modular digit. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("MD","Modular Digit"); DOMMDD:=d;
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
(*9*) END DomLoadMD;


END DOMMD.
(* -EOF- *)
