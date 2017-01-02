(* ----------------------------------------------------------------------------
 * $Id: DOMFF.mi,v 1.5 1995/11/05 09:29:05 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMFF.mi,v $
 * Revision 1.5  1995/11/05 09:29:05  kredel
 * Fixed DDDRD, DDDWR and other corrections.
 *
 * Revision 1.4  1994/09/06  11:48:54  rose
 * modified comment
 *
 * Revision 1.3  1994/05/19  10:42:47  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.2  1992/10/15  16:30:15  kredel
 * Changed rcsid variable
 *
 * Revision 1.1  1992/09/28  17:47:10  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMFF;

(* MAS Domain Finite Field Implementation Module. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, LIST1; 

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

FROM MASBIOS IMPORT BLINES, SWRITE, DIGIT, LETTER, MASORD, CREAD, CREADB, BKSP;

FROM SACLIST IMPORT OWRITE, CLOUT, ADV2, THIRD, FIRST2, FIRST4, 
                    AWRITE, LIST4, SECOND, FOURTH;

FROM SACI IMPORT IREAD, IWRITE;

FROM SACPOL IMPORT VREAD;

FROM MASFF IMPORT FFWRITE, FFREAD, FFFINT, FFHOM, FFRAND, 
                  FFCOMP, FFONE, FFNEG,   
                  FFSUM, FFDIF, FFINV, FFPROD, FFQ, FFEXP;

FROM DIPC IMPORT PFDIP, DIPFP; 

FROM DIPI IMPORT DIIPWR, DIIPRD;

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;

FROM DIPGB IMPORT DIPNOR, DIPSP;

FROM SACMUFAC IMPORT MUPFBL; 

FROM SACPGCD IMPORT MUPSFF; 

FROM SACPRIM IMPORT IFACT; 

CONST rcsidi = "$Id: DOMFF.mi,v 1.5 1995/11/05 09:29:05 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Domain:            (dom, val, mod, modpol, prime, V) 
   Domain descriptor:           (mod, modpol, prime, V) 

   where: val    = finite field element   
          mod    = modulus integer
          modpol = modulus polynomial 
          prime  = 1 if mod is prime, 2 if mod is squarefree, 0 else  
          V      = variable list
*)


PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=FFDIF(p,M,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); 
(*2*) (*compute. *) CL:=FFEXP(p,M,AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL, p, M: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); FIRST2(D,p,M);
(*2*) (*compute. *) CL:=FFFINT(p,M,A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain element with descriptor, 
A is an integral polynomial in 1 variables. *)
VAR   C, CL, M, p, BL, DL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); FIRST2(D,p,M); 
(*2*) (*compute. *) CL:=FFHOM(p,M,A);  
(*3*) (*create. *) C:=COMP(DL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); 
(*2*) (*compute. *) CL:=FFINV(p,M,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) TL:=0; 
      IF AL <> 0 THEN TL:=THIRD(AP);
         IF TL <> 1 THEN TL:=0 END; 
         END; 
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M);
(*2*) (*compute. *) CL:=FFNEG(p,M,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) SL:=FFONE(AL); 
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
VAR   AL, AP, BL, BP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=FFPROD(p,M,AL,BL);
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
VAR   AL, AP, BL, BP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=FFQ(p,M,AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL, M, p, RL, V, BL, DL, X: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); ADV2(D,p,M,X);  V:=SECOND(X);  
(*2*) (*read and convert. *) CL:=FFREAD(V); 
      DL:=FFHOM(p,M,CL);   
(*3*) (*create. *) C:=COMP(DL,D); 
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
VAR   AL, AP, BL, BP, C, CL, M, p: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); FIRST2(AP,p,M); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=FFSUM(p,M,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, AP, SL, M, p, I, PL, CL, N, J, V: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A,AL,AP); V:=FOURTH(AP); 
(*2*) (*write. *) FFWRITE(AL,V); 
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   c, D, PL, pl, M, p, V, RL, L: LIST;  
BEGIN
(*1*) (*initialization. *) p:=0; PL:=0; M:=0; V:=SIL;  
      D:=LIST4(p,M,PL,V); D:=COMP(0,D); 
(*2*) (*read, syntax = (mod, var, pol). *) 
      c:=CREADB(); 
      IF c <> MASORD("(") THEN BKSP; 
         ERROR(severe,"FF domain read: '(' expected."); RETURN(D) END; 
      c:=CREADB(); BKSP; 
      IF NOT DIGIT(c) THEN 
         ERROR(severe,"FF domain read: 'modulus' expected."); RETURN(D) END;
      p:=IREAD(); 
      c:=CREADB(); 
      IF c <> MASORD(",") THEN BKSP; 
         ERROR(severe,"FF domain read: ',' expected."); RETURN(D) END;
      c:=CREADB(); BKSP;  
      IF NOT LETTER(c) THEN 
         ERROR(severe,"FF domain read: 'variable' expected."); RETURN(D) END;
      V:=VREAD(); V:=LIST1(V); 
      c:=CREADB(); 
      IF c <> MASORD(",") THEN BKSP; 
         ERROR(severe,"FF domain read: ',' expected."); RETURN(D) END;
      M:=DIIPRD(V); PFDIP(M, RL,M);   
      c:=CREADB(); 
      IF c <> MASORD(")") THEN BKSP; 
         ERROR(severe,"FF domain read: ')' expected."); RETURN(D) END;
(*3*) (*check for prime or squarefree. *) PL:=1; pl:=1;  
      L:=IFACT(p); 
      IF RED(L) <> SIL THEN OWRITE(L); BLINES(0); 
         ERROR(harmless,"Warning: .. not prime number. "); 
         pl:=0; 
         END; 
      L:=MUPSFF(p,M); 
      IF RED(L) <> SIL 
         THEN OWRITE(L); BLINES(0); 
              ERROR(harmless,"Warning: .. not squarefree. "); 
              PL:=0; 
         ELSE L:=MUPFBL(p,M); 
              IF RED(L) <> SIL 
                 THEN OWRITE(L); BLINES(0); 
                      ERROR(harmless,"Warning: .. not prime. "); 
                      PL:=2; 
                 ELSE PL:=1; END;
              END; 
      PL:=PL*pl; 
      D:=LIST4(p,M,PL,V); D:=COMP(0,D); 
(*5*) RETURN(D); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   AL, AP, M, p, PL, CL, V: LIST;
BEGIN
(*1*) (*select. *) ADV(D,AL,AP); FIRST4(AP,p,M,PL,V); 
(*2*) (*write. *) 
      SWRITE("( "); IWRITE(p);  
      SWRITE(", "); CLOUT(FIRST(V)); SWRITE(", "); 
      CL:=DIPFP(1,M); DIIPWR(CL,V); SWRITE(" )"); 
      SWRITE(" (* "); 
      IF PL <> 1 THEN SWRITE("not ") END;
      SWRITE(" prime. *) "); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DomLoadFF();
(*Domain load finite field. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("FF","Finite Field"); DOMFFD:=d;
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
(*9*) END DomLoadFF;


END DOMFF.

(* -EOF- *)
