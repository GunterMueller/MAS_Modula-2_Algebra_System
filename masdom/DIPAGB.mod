(* ----------------------------------------------------------------------------
 * $Id: DIPAGB.mi,v 1.5 1995/11/04 20:39:35 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPAGB.mi,v $
 * Revision 1.5  1995/11/04 20:39:35  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.4  1995/09/12  17:35:59  pesch
 * Use massignal instead of mpsignal.
 *
 * Revision 1.3  1994/10/16  13:18:35  rose
 * Minor additions.
 *
 * Revision 1.2  1994/06/06  17:36:19  rose
 * Syntactical errors (found by Mocka) corrected.
 *
 * Revision 1.1  1994/05/19  10:42:31  rose
 * New module DIPAGB. Computes a Groebner basis with the second Buchberger
 * criterion (Gebauer/Moeller).
 * Implemented critical pair selection strategies: normal, normal with sugar.
 *
 * ----------------------------------------------------------------------------
 *)


IMPLEMENTATION MODULE DIPAGB;

(* DIP Arbitrary Domain Groebner Basis Implementation Module. *)



FROM DIPADOM	IMPORT	DIPBCP, DIPDIF, DIPROD, DIWRIT;

FROM DIPC	IMPORT	DIPEVL, DIPFMO, DIPMAD, DIPMCP, EVCOMP, EVDIF, EVDOV,
			EVLCM, EVMT, EVNNZE, EVSUM, VALIS;

FROM DIPGB	IMPORT	DIIFSP, DIPSP;

FROM DIPTOOLS	IMPORT	ADDDFDIP, ADDNFDIP, DIPCNST, DIPIMO, DIPONE;

FROM MASADOM	IMPORT	ADFI, ADGCDC, ADPNF, ADPSP, ADPSUGNF, ADPSUGSP,
			ADQUOT;

FROM MASBIOS	IMPORT	BLINES, CUNIT, SOUNIT, SWRITE;

FROM MASELEM	IMPORT	GAMMAINT;

FROM MASERR	IMPORT	ERROR, fatal, severe;

FROM MASLISPU	IMPORT	PROCF1, PROCF2, PROCF3, PROCF4, PROCP0, PROCP1,
			PROCP1V2;

FROM MASNCC	IMPORT	EVGCD;

FROM MASRN	IMPORT	RNMAX;

FROM MASSTOR	IMPORT	ADV, BETA, CELLS, COMP, FIRST, INV, LENGTH, LIST,
			LIST1, LISTVAR, RED, SIL, SRED, TIME;

FROM massig	IMPORT	Action, SIGUSR1, SIG_IGN, signal;

FROM SACLIST	IMPORT	AWRITE, CINV, COMP2, CONC, FIRST2, FOURTH, LELT,
			LIST2, LIST3, LIST4, LWRITE, RED4, SECOND, THIRD;

FROM SACPOL	IMPORT	VLWRIT;

FROM SACRN	IMPORT	RNCOMP, RNDIF, RNINT, RNPROD, RNSUM, RNWRIT;

FROM SYSTEM	IMPORT	ADR;


VAR DIPAGBOpt: RECORD
                  TraceFlag: CARDINAL;
                            (* A non-negative integer level for interactive
                               documentation. *)
                  Strategy: CARDINAL;
                            (* The strategy for the extended critical pair
                               selection. The following strategies are
                               supported in this module:
                                  0 (= normal)
                                  1 (= normal with sugar)
                               *)
                  VariableWeight: LIST;
                            (* A list of r non-negative rational numbers
                               where the i-th component is the weight of
                               the (r-i+1)-th variable in the variable list
                               VALIS. *)
                  UpdateVariableWeight: PROCP0;
                            (* The procedure to update the DIPAGB variable
                               weight list. *)
                  Update: PROCP1V2;
                            (* The procedure to update the extended ideal basis
                               and the extended critical pair list as required
                               by DIPAGB. *)
                  InitUpdate: PROCP1V2;
                            (* The initialization procedure. *)
                  CPExtend: PROCF2;
                            (* The function to extend a critical pair by
                               further components. *)
                  DIPExtend: PROCF1;
                            (* The function to extend a distributive polynomial
                               by further components. *)
                  ECPInsert: PROCF2;
                            (* The function to insert an extended critical pair
                               into the extended critical pair list. *)
                  ECPSelect: PROCP1V2;
                            (* The procedure to select an extended critical
                               pair from the extended critical pair list. The
                               extended critical pair list is modified. *)
                  ECPWrite: PROCP1;
                            (* The procedure to write an extended critical
                               pair in the output stream. *)
                  EDIPNormalform: PROCF2;
                            (* The function to reduce an extended distributive
                               polynomial to normalform w.r.t. a list of
                               extended distributive polynomials. *)
                  EDIPSPolynomial: PROCF2;
                            (* The function to compute the extended
                               S-polynomial of two extended distributive
                               polynomials. *)
                  EDIPUnExtend: PROCF1;
                            (* The function to get the distributive polynomial
                               from an extended distributive polynomial. *)
                  EDIPWrite: PROCP1;
                            (* The procedure to write an extended distributive
                               polynomial in the output stream. *)
               END;

VAR pG,pB, pcell, ptime, predsum, prednum: POINTER TO LIST;


CONST rcsidi = "$Id: DIPAGB.mi,v 1.5 1995/11/04 20:39:35 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1994 Universitaet Passau";



(****************************************************************************
 * 1. General Procedures                                                    *
 ****************************************************************************)


(* ------------------------------------------------------------------------ *
 * 1.1 The main function DIPAGB                                             *
 *     Given a finite subset F of a multivariate polynomial ring            *
 *     K[X1,...,Xn] over a computable field K DIPAGB finds a Groebner basis *
 *     G of the ideal in K[X1,...,Xn] generated by F. A call of DIPAGB with *
 *     parameter F performs the computation of G as given by GROEBNERNEW2   *
 *     in                                                                   *
 *        Becker, T. and Weispfenning, V., In Cooperation with Heinz Kredel,*
 *        Groebner Bases, A Computational Approach to Commutative Algebra,  *
 *        Springer 1993,                                                    *
 *     with the exception that the algorithm stops with the ideal basis     *
 *     G={1} if a constant non-zero polynomial would be added to the com-   *
 *     puted ideal basis.                                                   *
 * ------------------------------------------------------------------------ *)


PROCEDURE DIPAGB(F: LIST): LIST;
(* Distributive polynomial arbitrary domain Groebner basis.
   F is a list of polynomials in distributive representation.
   G=DIPAGB(F) is a (not reduced) Groebner basis with Id(G)=Id(F). *)

VAR G,B, g1g2, f,g1,g2,h, g, W, V,v, cell,time, redtime,redsum,rednum: LIST;
    ProperId: BOOLEAN;
    sighandleold: Action;

BEGIN
   cell:=CELLS(); pcell:=ADR(cell); time:=TIME(); ptime:=ADR(time); redtime:=0;
   redsum:=0; predsum:=ADR(redsum); rednum:=0; prednum:=ADR(rednum);
   ProperId:=TRUE;
   UpdateVariableWeight;
   G:=SIL; B:=SIL;
   WHILE F<>SIL DO
      ADV(F, f,F);
      INITUPDATE(DIPEXTEND(f), G,B);
   END;
   pG:=ADR(G); pB:=ADR(B);
   sighandleold:=signal(SIGUSR1,SigUsr1HandleDIPAGB);
   WHILE B<>SIL DO
      ECPSELECT(B, g1g2,B);
      g1:=ECPPOLY1(g1g2); g2:=ECPPOLY2(g1g2);
      f:=EDIPSP(g1,g2);
      rednum:=rednum+1;
      IF DIPAGBOpt.TraceFlag >= 4 THEN
         AWRITE(rednum);
         CASE rednum OF
              1: SWRITE("st polynomial to reduce to normalform: ") |
              2: SWRITE("nd polynomial to reduce to normalform: ") |
              3: SWRITE("rd polynomial to reduce to normalform: ")
            ELSE SWRITE("th polynomial to reduce to normalform: ");
         END;
         BLINES(0); SWRITE("  "); DIWRIT(EDIPUNEXTEND(f),VALIS); BLINES(1);
      END;
      redtime:=TIME();
      h:=EDIPNOR(G,f);
      redsum:=redsum+TIME()-redtime;
      g:=EDIPUNEXTEND(h);
      IF g<>0 THEN
         IF NOT(DIPCNST(g))
            THEN (* g ist not constant *)
                 DIPAGBOpt.Update(h, G,B);
            ELSE ProperId:=FALSE;
                 (* G should contain the single constant polynomial 1 *)
                    G:=LIST1(DIPONE(ADDDFDIP(g)));
                 (* Leave the while loop *)
                    B:=SIL;
         END;
      END;
   END;
   IF DIPAGBOpt.TraceFlag >= 2 THEN
      AWRITE(rednum); SWRITE(" normalform computations in ");
      AWRITE(redsum); SWRITE(" milliseconds. "); BLINES(1);
   END;
   IF ProperId THEN G:=LEDIPUNEXTEND(G); END;
   IF DIPAGBOpt.TraceFlag >= 1 THEN
      BLINES(0);
      SWRITE("Total time: "); AWRITE(TIME()-time); SWRITE(" milliseconds.");
      BLINES(0);
      SWRITE("     Cells: "); AWRITE(CELLS()-cell); SWRITE("."); BLINES(1);
   END;
   sighandleold:=signal(SIGUSR1,sighandleold);
   RETURN(G);
END DIPAGB;



(* ------------------------------------------------------------------------ *
 * 1.2 The procedure UPDATE                                                 *
 *     The extended ideal basis G and the extended critical pair list B are *
 *     updated as required by DIPAGB (see 1.3 and 1.4 for information about *
 *     extended polynomials and extended critical pairs). The subalgorithm  *
 *     UPDATE of DIPAGB eliminates superfluous critical pairs according to  *
 *     Buchberger's criteria as implemented by Gebauer and Moeller, see     *
 *        - Becker, T. and Weispfenning, V., In Cooperation with Heinz      *
 *          Kredel, Groebner Bases, A Computational Approach to Commutative *
 *          Algebra, Springer 1993,                                         *
 *        - Gebauer, R. and Moeller, H.M., On an installation of Buch-      *
 *          berger's algorithm, J. Symb. Comp 6/2/3, pp. 275-286.           *
 * ------------------------------------------------------------------------ *)


PROCEDURE UPDATE(h: LIST; VAR G,B: LIST);
(* Update of extended ideal basis and extended critical pair list as required
   by DIPAGB.
   h is an extended distributive polynomial, G is a list of extended
   distributive polynomials. B is a list of extended critical pairs. *)

VAR Bnew,Gnew, C,D,E,CC,DD, CP, hg,hg1,hg2,g1g2, g,g1,g2,
    HTg,HTg1,HTg2,HTh, FL: LIST;

BEGIN
   C:=SIL; D:=G;
   WHILE D<>SIL DO
      ADV(D,g1,D);
      C:=ECPINSERT(CPEXTEND(h,g1),C);
   END;
   HTh:=EDIPEVL(h);
   WHILE C<>SIL DO
      ADV(C,hg1,C); g1:=ECPPOLY2(hg1); HTg1:=EDIPEVL(g1);
      IF EVNNZE(EVGCD(HTh,HTg1))=0
         THEN D:=COMP(hg1,D);
         ELSE CC:=C; FL:=0;
              WHILE (CC<>SIL) AND (FL=0) DO
                 ADV(CC,hg2,CC);
                 FL:=EVMT(ECPLCMHT(hg1),ECPLCMHT(hg2));
              END;
              IF FL=0 THEN
                 DD:=D;
                 WHILE (DD<>SIL) AND (FL=0) DO
                    ADV(DD,hg2,DD);
                    FL:=EVMT(ECPLCMHT(hg1),ECPLCMHT(hg2));
                 END;
              END;
              IF FL=0 THEN D:=COMP(hg1,D); END;
      END;
   END;
   E:=SIL;
   WHILE D<>SIL DO
      ADV(D,hg,D); g:=ECPPOLY2(hg); HTg:=EDIPEVL(g);
      IF EVNNZE(EVGCD(HTh,HTg))>0 THEN E:=COMP(hg,E); END;
   END;
   WHILE B<>SIL DO
      ADV(B,g1g2,B);
      g1:=ECPPOLY1(g1g2); g2:=ECPPOLY2(g1g2);
      HTg1:=EDIPEVL(g1); HTg2:=EDIPEVL(g2);
      IF (EVMT(ECPLCMHT(g1g2),HTh)=0)
            OR (EVCOMP(EVLCM(HTg1,HTh),ECPLCMHT(g1g2))=0)
            OR (EVCOMP(EVLCM(HTh,HTg2),ECPLCMHT(g1g2))=0)
         THEN E:=ECPINSERT(g1g2,E);
      END;
   END;
   Bnew:=E; Gnew:=SIL;
   WHILE G<>SIL DO
      ADV(G,g,G); HTg:=EDIPEVL(g);
      IF EVMT(HTg,HTh)=0 THEN Gnew:=COMP(g,Gnew); END;
   END;
   Gnew:=COMP(h,Gnew);
   G:=Gnew; B:=Bnew;
END UPDATE;



(* ------------------------------------------------------------------------ *
 * 1.3 Procedures for extended distributive polynomials                     *
 *     In this module there are different strategies implemented to choose  *
 *     one of the critical pairs in the DIPAGB function for the process of  *
 *     reduction ("selection strategies"). Certain selection strategies     *
 *     make it necessary to carry along some information with each poly-    *
 *     nomial. This fact leads to a new data structure called "extended     *
 *     distributive polynomial". It's a tuple (f,i1,...,ik) where f is a    *
 *     distributive polynomial and i1,...,ik are informations on f. The     *
 *     informations depend on the current selection strategy.               *
 * ------------------------------------------------------------------------ *)


PROCEDURE DIPEXTEND(f: LIST): LIST;
(* Distributive polynomial extension.
   f is a polynomial in distributive representation.
   DIPEXTEND(f) is the extended distributive polynomial appropriate to f. *)

VAR Ef: LIST;
    i: CARDINAL;

BEGIN
   Ef:=DIPAGBOpt.DIPExtend(f);
   IF DIPAGBOpt.TraceFlag >= 8
      THEN SWRITE("Extending the polynomial"); BLINES(0);
           SWRITE("    "); EDIPWRITE(Ef);
           FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   END;
   RETURN(Ef);
END DIPEXTEND;



PROCEDURE LDIPEXTEND(P: LIST): LIST;
(* List of distributive polynomials extend.
   P is a list of distributive polynomials.
   LDIPEXTEND(P) is the list of the appropriate extended distributive
   polynomials. *)

VAR p,Q: LIST;

BEGIN
   Q:=SIL;
   WHILE P<>SIL DO
      ADV(P, p,P);
      Q:=COMP(DIPEXTEND(p),Q);
   END;
   RETURN(Q);
END LDIPEXTEND;



PROCEDURE EDIPEVL(f: LIST): LIST;
(* Extended distributive polynomial exponent vector of the leading monomial.
   f is an extended distributive polynomial.
   EDIPEVL(f) is the exponent vector of the leading monomial of f. *)

BEGIN
   RETURN(DIPEVL(EDIPUNEXTEND(f)));
END EDIPEVL;



PROCEDURE EDIPNOR(P,f: LIST): LIST;
(* Extended distributive polynomial normal form.
   P is a list of non-zero extended distributive polynomials.
   f is an extended distributive polynomial.
   EDIPNOR(P,f) is an extended distributive polynomial such that f is reducible
   to EDIPNOR(P,f) modulo P and EDIPNOR(P,f) is in normalform w.r.t. P. *)

VAR g: LIST;
    i: CARDINAL;

BEGIN
   g:=DIPAGBOpt.EDIPNormalform(P,f);
   IF DIPAGBOpt.TraceFlag >= 5
      THEN SWRITE("The normalform is"); BLINES(0);
           SWRITE("  "); EDIPWRITE(g);
           FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   END;
   RETURN(g);
END EDIPNOR;



PROCEDURE EDIPSP(f,g: LIST): LIST;
(* Extended distributive polynomial S-polynomial.
   f and g are extended distributive polynomials.
   EDIPSP(f,g) is the extended S-polynomial of f and g. *)

VAR SP: LIST;
     i: CARDINAL;

BEGIN
   SP:=DIPAGBOpt.EDIPSPolynomial(f,g);
   IF DIPAGBOpt.TraceFlag >= 9
      THEN SWRITE("Computing the S-polynomial of the following two ");
           SWRITE("distributive polynomials:"); BLINES(0);
           SWRITE("f = "); EDIPWRITE(f);
           SWRITE("g = "); EDIPWRITE(g);
           SWRITE("==> Spol(f,g) = "); EDIPWRITE(SP);
           FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   END;
   RETURN(SP);
END EDIPSP;



PROCEDURE EDIPUNEXTEND(f: LIST): LIST;
(* Extended distributive polynomial un-extend.
   f is an extended distributive polynomial.
   EDIPUNEXTEND(f) is the distributive polynomial appropriate to f. *)

BEGIN
   RETURN(DIPAGBOpt.EDIPUnExtend(f));
END EDIPUNEXTEND;



PROCEDURE LEDIPUNEXTEND(P: LIST): LIST;
(* List of extended distributive polynomials un-extend.
   P is a list of extended distributive polynomials.
   LEDIPUNEXTEND(P) is the list of the appropriate distributive polynomials. *)

VAR p,Q: LIST;

BEGIN
   Q:=SIL;
   WHILE P<>SIL DO
      ADV(P, p,P);
      Q:=COMP(EDIPUNEXTEND(p),Q);
   END;
   RETURN(Q);
END LEDIPUNEXTEND;



PROCEDURE EDIPWRITE(f: LIST);
(* Extended distributive polynomial write.
   The extended distributive polynomial f is written in the output stream. *)

BEGIN
   DIPAGBOpt.EDIPWrite(f);
END EDIPWRITE;



PROCEDURE LEDIPWRITE(P: LIST);
(* List of extended distributive polynomials write.
   The list P of extended distributive polynomials is written in the output
   stream. *)

VAR p,i: LIST;

BEGIN
   i:=0;
   WHILE P<>SIL DO
      ADV(P, p,P);
      i:=i+1; AWRITE(i);
      CASE i OF
           1: SWRITE("st polynomial: ") |
           2: SWRITE("nd polynomial: ") |
           3: SWRITE("rd polynomial: ");
         ELSE SWRITE("th polynomial: ");
      END;
      EDIPWRITE(p);
   END; 
END LEDIPWRITE;



(* ------------------------------------------------------------------------ *
 * 1.4 Procedures for extended critical pairs                               *
 *     An extended critical pair is a pair of extended distributive poly-   *
 *     nomials together with some information which depends on the chosen   *
 *     selection strategy.                                                  *
 * ------------------------------------------------------------------------ *)


PROCEDURE CPEXTEND(f,g: LIST): LIST;
(* Critical pair extend.
   f and g are distributive polynomials such that (f,g) is a critical pair.
   CPEXTEND(f,g) is the appropriate extended critical pair, i.e. the list of
   f, g and further components which depend on the chosen extended critical
   pair selection strategy. *)

VAR ECP: LIST;
    i: CARDINAL;

BEGIN
   ECP:=DIPAGBOpt.CPExtend(f,g);
   IF DIPAGBOpt.TraceFlag >= 8
      THEN SWRITE("Extending the following critical pair:"); BLINES(0);
           ECPWRITE(ECP); BLINES(1);
           FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   END;
   RETURN(ECP);
END CPEXTEND;



PROCEDURE ECPINSERT(CP,P: LIST): LIST;
(* Extended critical pair insertion.
   The extended critical pair CP is to be inserted into the extended critical
   pair list P.
   ECPINSERT(CP,P) is the list P with the additional pair CP. *)

VAR i: CARDINAL;

BEGIN
   P:=DIPAGBOpt.ECPInsert(CP,P);
   IF DIPAGBOpt.TraceFlag >= 7
      THEN SWRITE("Inserting the following extended critical pair:");
           BLINES(0); ECPWRITE(CP); BLINES(1);
           SWRITE("==> New extended critical pair list:"); BLINES(0);
           LECPWRITE(P);
           FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   END;
   RETURN(P);
END ECPINSERT;



PROCEDURE ECPLCMHT(CP: LIST): LIST;
(* Extended critical pair select the least common multiple of head terms.
   ECPLCMHT(CP) is the extended least common multiple of the leadings terms
   of the two extended polynomials in the extended critical pair CP. *)

(* This selector function has to be modified if a new extended critical pair
   data structure is chosen in this implementation module. In the current
   revision the extended critical pair is implemented as a list where the third
   component is the extended least common multiple of the leading terms. *)

BEGIN
   RETURN(THIRD(CP));
END ECPLCMHT;



PROCEDURE ECPPOLY1(CP: LIST): LIST;
(* Extended critical pair select the first extended distributive polynomial. *)

(* This selector function has to be modified if a new extended critical pair
   data structure is chosen in this implementation module. In the current
   revision the extended critical pair is implemented as a list where the first
   component is the first extended distributive polynomial. *)

BEGIN
   RETURN(FIRST(CP));
END ECPPOLY1;



PROCEDURE ECPPOLY2(CP: LIST): LIST;
(* Extended critical pair select the second extended distributive
   polynomial. *)

(* This selector function has to be modified if a new extended critical pair
   data structure is chosen in this implementation module. In the current
   revision the extended critical pair is implemented as a list where the
   second component is the second extended distributive polynomial. *)

BEGIN
   RETURN(SECOND(CP));
END ECPPOLY2;



PROCEDURE ECPSELECT(P: LIST; VAR CP,Q: LIST);
(* Select an extended critical pair from the extended critical pair list.
   The extended critical pair list is modified. *)

BEGIN
   DIPAGBOpt.ECPSelect(P, CP,Q);
END ECPSELECT;



PROCEDURE ECPUNEXTEND(CP: LIST): LIST;
(* Extended critical pair un-extend.
   CP is an extended critical pair.
   ECPUNEXTEND(CP) is the appropriate critical pair, i.e. CP without the
   extensions which depend on the chosen extended critical pair selection
   strategy. *)

VAR f,g: LIST;

BEGIN
   f:=ECPPOLY1(CP); g:=ECPPOLY2(CP);
   RETURN(CPCON(EDIPUNEXTEND(f),EDIPUNEXTEND(g)));
END ECPUNEXTEND;



PROCEDURE LECPUNEXTEND(P: LIST): LIST;
(* List of extended critical pairs un-extend.
   P is a list of extended critical pairs.
   LECPUNEXTEND(P) is the list of the appropriate critical pairs. *)

VAR CP,Q: LIST;

BEGIN
   Q:=SIL;
   WHILE P<>SIL DO
      ADV(P, CP,P);
      Q:=COMP(ECPUNEXTEND(CP),Q);
   END;
   RETURN(Q);
END LECPUNEXTEND;



PROCEDURE ECPWRITE(CP: LIST);
(* Extended critical pair write.
   The extended critical pair CP is written in the output stream. *)

BEGIN
   DIPAGBOpt.ECPWrite(CP);
END ECPWRITE;



PROCEDURE LECPWRITE(P: LIST);
(* List of extended critical pairs write.
   The list P of extended critical pairs is written in the output stream. *)

VAR CP,i: LIST;

BEGIN
   i:=0;
   WHILE P<>SIL DO
      ADV(P, CP,P);
      i:=i+1; AWRITE(i);
      CASE i OF
           1: SWRITE("st critical pair: ") |
           2: SWRITE("nd critical pair: ") |
           3: SWRITE("rd critical pair: ");
         ELSE SWRITE("th critical pair: ");
      END;
      BLINES(0); ECPWRITE(CP); BLINES(1);
   END;
END LECPWRITE;



(* ------------------------------------------------------------------------ *
 * 1.5 Further general procedures                                           *
 * ------------------------------------------------------------------------ *)


PROCEDURE ADDNFEDIP(f: LIST): LIST;
(* Arbitrary domain domain number from extended distributive polynomial.
   f is an extended distributive polynomial over an arbitrary domain polynomial
   ring. The domain number of the arbitrary domain is returned. If the
   unextended distributive polynomial appropriate to f is the zero polynomial
   then 0 is returned. *)

BEGIN
   RETURN(ADDNFDIP(EDIPUNEXTEND(f)));
END ADDNFEDIP;



PROCEDURE CPCON(f,g: LIST): LIST;
(* Critical pair constructor.
   f and g are distributive polynomials.
   CPCON(f,g) is the critical pair (f,g). *)

(* This constructor function has to be modified if a new critical pair
   data structure is chosen in this implementation module. In the current
   revision the critical pair is implemented as a list of length two. *)

BEGIN
   RETURN(LIST2(f,g));
END CPCON;



PROCEDURE DIPRWTDG(f,W: LIST): LIST;
(* Distributive polynomial rational-weighted total degree.
   f is a polynomial in distributive representation in r variables.
   W=(W1,...,Wr) is a list of rational numbers, where Wi, 1 le i le r, is the
   weight of the (r-i+1)-th variable in the variable list VALIS, i.e. of the
   variable w.r.t. the i-th component in each exponent vector of f.
   DIPRWTDG(f,W) is the rational-weighted total degree of f, defined by the
   maximal rational-weighted total degree of the exponent vectors of the terms
   of f. *)

VAR TD, g, A,EV: LIST;

BEGIN
   IF f=0 THEN RETURN(0); END;
   g:=f; TD:=0;
   WHILE g<>SIL DO
      DIPMAD(g, A,EV,g);
      TD:=RNMAX(TD,EVRWTDEG(EV,W));
   END;
   IF DIPAGBOpt.TraceFlag >= 6
      THEN SWRITE("The rational-weighted total degree of the polynomial");
           BLINES(0);
           SWRITE("  "); DIWRIT(f,VALIS); BLINES(0);
           SWRITE("w.r.t. the variable list"); BLINES(0);
           SWRITE("  "); VLWRIT(VALIS); BLINES(0);
           SWRITE("and the variable weight list"); BLINES(0);
           SWRITE("  "); LRNWRIT(CINV(W)); BLINES(0);
           SWRITE("is "); RNWRIT(TD); SWRITE("."); BLINES(1);
   END;
   RETURN(TD);
END DIPRWTDG;



PROCEDURE EVRWTDEG(U,W: LIST): LIST;
(* Exponent vector rational-weighted total degree.
   U=(U1,...,Ur) is an exponent vector.
   W=(W1,...,Wr) is a list of rational numbers, where Wi, 1 le i le r, is the
   weight of the (r-i+1)-th variable in the variable list VALIS, i.e. of the
   variable w.r.t. the i-th component of U.
   TD=EVRWTDEG(U,W) is the rational-weighted total degree of U, defined by
   TD = W1U1+...+WrUr. *)

VAR TD, Ui,Wi: LIST;

BEGIN
   TD:=0;
   WHILE U<>SIL DO
      ADV(U, Ui,U); ADV(W, Wi,W);
      IF Ui >= BETA THEN
         ERROR(severe,"EVRWTDEG: exponent out of range");
         RETURN(SIL);
      END;
      TD:=RNSUM(TD,RNPROD(Wi,RNINT(Ui)));
   END;
   RETURN(TD);
END EVRWTDEG;



PROCEDURE IDF1(L: LIST): LIST;
(* Identity. IDF1(L)=L. *)

BEGIN
   RETURN(L)
END IDF1;



PROCEDURE INITUPDATE(f: LIST; VAR G,B: LIST);
(* The initialization function as a first call of UPDATE. *)

BEGIN
   DIPAGBOpt.InitUpdate(f, G,B);
END INITUPDATE;



PROCEDURE LRNWRIT(LRN: LIST);
(* List of rational numbers write.
   The list LRN of rational numbers is written in the output stream. *)

VAR RN: LIST;

BEGIN
   SWRITE("(");
   IF LRN<>SIL THEN ADV(LRN, RN,LRN); RNWRIT(RN); END;
   WHILE LRN<>SIL DO
      ADV(LRN, RN,LRN);
      SWRITE(","); RNWRIT(RN);
   END;
   SWRITE(")");
END LRNWRIT;


PROCEDURE NOP;
(* No operation. *)

BEGIN
END NOP;



PROCEDURE UpdateVariableWeight;
(* Update of the DIPAGB variable weight list. *)

BEGIN
   DIPAGBOpt.UpdateVariableWeight;
END UpdateVariableWeight;



PROCEDURE SigUsr1HandleDIPAGB(signo: INTEGER);
(* Handler for sigusr1 in DIPAGB. *)

VAR dummy: Action;
    Dummy: LIST;
    i: CARDINAL;

BEGIN
   dummy:=signal(SIGUSR1,SIG_IGN);
   Dummy:=SOUNIT("CON:x");
   BLINES(0); FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   SWRITE("SIGUSR1 received in DIPAGB:"); BLINES(1);
   AWRITE(prednum^); SWRITE(" normalform computations in ");
   AWRITE(predsum^); SWRITE(" milliseconds up to now. "); BLINES(1);
   SWRITE("Total time up to now:      ");
   AWRITE(TIME()-ptime^); SWRITE(" milliseconds."); BLINES(0);
   SWRITE("Number of cells up to now: ");
   AWRITE(CELLS()-pcell^); SWRITE("."); BLINES(1);
   SWRITE("Already computed polynomials of the Groebner Basis:"); BLINES(1);
   LEDIPWRITE(pG^); BLINES(1);
   SWRITE("Actual extended critical pair list:"); BLINES(1);
   LECPWRITE(pB^); BLINES(1);
   FOR i:=1 TO 79 DO SWRITE("-"); END; BLINES(1);
   Dummy:= CUNIT("CON:x");
   dummy:=signal(SIGUSR1,SigUsr1HandleDIPAGB);
END SigUsr1HandleDIPAGB;



(*****************************************************************************
 * 2. Procedures w.r.t. the normal strategy                                  *
 *    In case of the normal strategy a critical pair of polynomials is       *
 *    chosen if the least common multiple of their leading terms is minimal  *
 *    in the current term order.                                             *
 *****************************************************************************)


(* ------------------------------------------------------------------------ *
 * 2.1 Procedures for extended distributive polynomials                     *
 *     In case of the normal strategy an extended distributive polynomial   *
 *     simply is the same as a distributive polynomial.                     *
 * ------------------------------------------------------------------------ *)


PROCEDURE EDIPNORWRITE(f: LIST);
(* Extended distributive polynomial write in case of the normal strategy.
   The (extended) distributive polynomial f is written in the output stream. *)

BEGIN
   DIWRIT(EDIPUNEXTEND(f),VALIS); BLINES(1);
END EDIPNORWRITE;



(* ------------------------------------------------------------------------ *
 * 2.2 Procedures for extended critical pairs                               *
 *     In case of the normal strategy an extended critical pair is a triple *
 *     (f,g,lcm) of two (extended) distributive polynomials f,g and the     *
 *     least common multiple lcm of the leading terms of f and g, whenever  *
 *     (f,g) defines a critical pair of polynomials.                        *
 * ------------------------------------------------------------------------ *)


PROCEDURE ECPNORCON(f,g: LIST): LIST;
(* Critical pair normal strategy extension constructor.
   f and g are (extended) distributive polynomials such that (f,g) is a
   critical pair.
   The extended critical pair ECPNORCON(f,g) is the extension of (f,g) by a
   third component, namely the exponent vector of the least common multiple of
   the leading term of f and the leading term of g. *)

(* This constructor function has to be modified if a new extended critical pair
   data structure w.r.t. the normal strategy is chosen in this implementation
   module. In the current revision the extended critical pair is implemented
   as a list of length three. *)

VAR HTf,HTg: LIST;

BEGIN
   HTf:=EDIPEVL(f); HTg:=EDIPEVL(g);
   RETURN(LIST3(f,g,EVLCM(HTf,HTg)));
END ECPNORCON;



PROCEDURE ECPNORINS(CP,P: LIST): LIST;
(* Extended critical pair normal strategy insertion.
   The extended critical pair CP is to be inserted into the extended critical
   pair list P w.r.t. the normal strategy.
   P and ECPNORINS(CP,P) are ordered lists with increasing least common
   multiple of the leading terms w.r.t. the given term order. *)

VAR PP,PPR, LCMCP: LIST;

BEGIN
   (* P is the empty list. *)  
      IF P=SIL THEN RETURN(LIST1(CP)); END;
   LCMCP:=ECPLCMHT(CP);
   (* LCMCP is minimal among all the lcm's. *)
      IF EVCOMP(ECPLCMHT(FIRST(P)),LCMCP)>=0 THEN RETURN(COMP(CP,P)); END;
   (* Else look for the first element of P with lcm >= LCMCP. *)
      PP:=P; PPR:=RED(PP);
      WHILE (PPR<>SIL) AND (EVCOMP(ECPLCMHT(FIRST(PPR)),LCMCP)=-1) DO
         PP:=PPR; PPR:=RED(PP);
      END;
   (* Insert CP. *)
      SRED(PP,COMP(CP,PPR)); RETURN(P);
END ECPNORINS;



PROCEDURE ECPNORWRITE(CP: LIST);
(* Extended critical pair write in case of the normal strategy.
   The extended critical pair CP is written in the output stream. *)

VAR f,g, Cf,Ef,Rf: LIST;

BEGIN
   f:=EDIPUNEXTEND(ECPPOLY1(CP)); g:=EDIPUNEXTEND(ECPPOLY2(CP));
   SWRITE("1st polynomial: "); DIWRIT(f,VALIS); BLINES(0);
   SWRITE("2nd polynomial: "); DIWRIT(g,VALIS); BLINES(0);
   DIPMAD(f, Cf,Ef,Rf);
   SWRITE("LCM of their leading terms:");
   DIWRIT(DIPFMO(ADFI(Cf,1),ECPLCMHT(CP)),VALIS); BLINES(0);
END ECPNORWRITE;



(*****************************************************************************
 * 3. Procedures w.r.t. the normal with sugar strategy                       *
 *    In case of the normal with sugar strategy a critical pair of poly-     *
 *    nomials is chosen if the the sugar of their S-polynomial is minimal    *
 *    and, in order to break ties, if the least common multiple of their     *
 *    S-polynomial is minimal in the current term order among all critical   *
 *    pairs with the same sugar of their S-polynomial, see                   *
 *       Giovini, A., Mora, T., Niesi, G., Robbiano, L. and Traverso, C.,    *
 *       "One sugar cube, please" or Selection strategies in the Buchberger  *
 *       algorithm, J. of the ACM 1991, pp. 49-54.                           *
 *****************************************************************************)



(* ------------------------------------------------------------------------ *
 * 3.1 Procedures for extended distributive polynomials                     *
 *     In case of the normal with sugar strategy an extended distributive   *
 *     polynomial is a pair (f,Sf) of a polynomial f in distributive        * 
 *     representation and its sugar Sf.                                     *
 * ------------------------------------------------------------------------ *)


PROCEDURE DIPSUGEXT(f: LIST): LIST;
(* Distributive polynomial normal with sugar strategy extension.
   f is a distributive polynomial.
   The extended distributive polynomial DIPSUGEXT(f) is the extension of f
   by a second component, namely the sugar of f. *)

VAR W: LIST;

BEGIN
   W:=DIPAGBOpt.VariableWeight;
   RETURN(EDIPSUGCON(f,DIPRWTDG(f,W)));
END DIPSUGEXT;



PROCEDURE EDIIFSUGNF(P,f: LIST): LIST;
(* Extended distributive integral function polynomial normal with sugar
   strategy normal form.
   P is a list of non-zero extended distributive integral function polynomials.
   f is an extended distributive integral function polynomial.
   EDIIFSUGNF(P,f) is an extended distributive integral function polynomial
   such that f is reducible to EDIIFSUGNF(P,f) modulo P and EDIIFSUGNF(P,f) is
   in normalform w.r.t. P. *)

VAR PP, g,h,p,q, Ag,Eg,Ap,Ep, gcd,CoAg,CoAp, Sh,Sp, W,Mult: LIST;

BEGIN
   g:=EDIPUNEXTEND(f);
   (* trivial cases *)
      IF (g=0) OR (P=SIL) THEN RETURN(f); END;
   (* Initialization *)
      h:=0;
      Sh:=EDIPSUGAR(f);
      W:=DIPAGBOpt.VariableWeight;
   REPEAT
      (* Look at the leading monomial of g *)
         DIPMAD(g, Ag,Eg,g);
         IF g=SIL THEN g:=0; END;
      (* Look for a polynomial p in P such that the leading monomial above
         is a multiple of the leading monomial of p *) 
         PP:=P;
         REPEAT
            ADV(PP, p,PP);
            Sp:=EDIPSUGAR(p);
            p:=EDIPUNEXTEND(p);
            DIPMAD(p, Ap,Ep,q);
            Mult:=EVMT(Eg,Ep);
         UNTIL (PP=SIL) OR (Mult=1);
      IF Mult=0
         THEN (* No polynomial p as above was found *)
              IF h=0 THEN h:=DIPFMO(Ag,Eg);
                     ELSE h:=DIPMCP(Ag,Eg,h);
              END;
         ELSE IF q<>SIL THEN
                 ADGCDC(Ag,Ap, gcd,CoAg,CoAp);
                 g:=DIPDIF(DIPBCP(g,CoAp),DIPROD(q,DIPFMO(CoAg,EVDIF(Eg,Ep))));
                 h:=DIPBCP(h,CoAp);
              END;
              Sh:=RNMAX(Sh,RNSUM(Sp,EVRWTDEG(EVDIF(Eg,Ep),W)));
      END;
   UNTIL g=0;
   RETURN(EDIPSUGCON(DIPIMO(h),Sh));
END EDIIFSUGNF;



PROCEDURE EDIIFSUGSP(f,g: LIST): LIST;
(* Extended distributive integral function polynomial normal with sugar
   strategy S-polynomial.
   f and g are extended distributive integral function polynomials.
   EDIIFSUGSP(f,g) is the extended S-polynomial of f and g w.r.t. the normal
   with sugar strategy. *)

VAR SP,SUG, W,HTf,HTg: LIST;

BEGIN
   SP:=DIIFSP(EDIPUNEXTEND(f),EDIPUNEXTEND(g));
   W:=DIPAGBOpt.VariableWeight;
   HTf:=EDIPEVL(f); HTg:=EDIPEVL(g);
   SUG:=RNSUM(RNMAX(RNDIF(EDIPSUGAR(f),EVRWTDEG(HTf,W)),
                    RNDIF(EDIPSUGAR(g),EVRWTDEG(HTg,W))),
              EVRWTDEG(EVLCM(HTf,HTg),W));
   RETURN(EDIPSUGCON(SP,SUG));
END EDIIFSUGSP;



PROCEDURE EDIPSUGAR(f: LIST): LIST;
(* Extended distributive polynomial sugar.
   EDIPSUGAR(f) is the sugar of the extended distributive polynomial f. *)

BEGIN
   RETURN(SECOND(f));
END EDIPSUGAR;



PROCEDURE EDIPSUGCON(f,S: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy constructor.
   f is a distributive polynomial.
   S is the sugar of f.
   EDIPSUGCON(f,S) is the extended distributive polynomial appropriate to f
   with sugar S. *)

(* This constructor function has to be modified if a new extended distributive
   polynomial data structure w.r.t. the normal with sugar strategy is chosen in
   this implementation module. In the current revision the extended distribu-
   tive polynomial is implemented as a list of length 2. *)

BEGIN
   RETURN(LIST2(f,S));
END EDIPSUGCON;



PROCEDURE EDIPSUGNOR(P,f: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy normal form.
   P is a list of non-zero extended distributive polynomials.
   f is an extended distributive polynomial.
   EDIPSUGNOR(P,f) is an extended distributive polynomial such that f is
   reducible to EDIPSUGNOR(P,f) modulo P and EDIPSUGNOR(P,f) is in normalform
   w.r.t. P. *)

VAR PP, g,h,p,q, Ag,Eg,Ap,Ep, Sh,Sp, W,Mult: LIST;

BEGIN
   g:=EDIPUNEXTEND(f);
   (* trivial cases *)
      IF (g=0) OR (P=SIL) THEN RETURN(f); END;
   (* Initialization *)
      h:=0;
      Sh:=EDIPSUGAR(f);
      W:=DIPAGBOpt.VariableWeight;
   REPEAT
      (* Look at the leading monomial of g *)
         DIPMAD(g, Ag,Eg,g);
         IF g=SIL THEN g:=0; END;
      (* Look for a polynomial p in P such that the leading monomial above
         is a multiple of the leading monomial of p *) 
         PP:=P;
         REPEAT
            ADV(PP, p,PP);
            Sp:=EDIPSUGAR(p);
            p:=EDIPUNEXTEND(p);
            DIPMAD(p, Ap,Ep,q);
            Mult:=EVMT(Eg,Ep);
         UNTIL (PP=SIL) OR (Mult=1);
      IF Mult=0
         THEN (* No polynomial p as above was found *)
              IF h=0 THEN h:=DIPFMO(Ag,Eg);
                     ELSE h:=DIPMCP(Ag,Eg,h);
              END;
         ELSE IF q<>SIL THEN
                 g:=DIPDIF(g,DIPROD(q,DIPFMO(ADQUOT(Ag,Ap),EVDIF(Eg,Ep))));
              END;
              Sh:=RNMAX(Sh,RNSUM(Sp,EVRWTDEG(EVDIF(Eg,Ep),W)));
      END;
   UNTIL g=0;
   RETURN(EDIPSUGCON(DIPIMO(h),Sh));
END EDIPSUGNOR;



PROCEDURE EDIPSUGSP(f,g: LIST): LIST;
(* Extended distributive polynomial normal with sugar strategy S-polynomial.
   f and g are extended distributive polynomials.
   EDIPSUGSP(f,g) is the extended S-polynomial of f and g w.r.t. the normal
   with sugar strategy. *)

VAR SP,SUG, W,HTf,HTg: LIST;

BEGIN
   SP:=DIPSP(EDIPUNEXTEND(f),EDIPUNEXTEND(g));
   W:=DIPAGBOpt.VariableWeight;
   HTf:=EDIPEVL(f); HTg:=EDIPEVL(g);
   SUG:=RNSUM(RNMAX(RNDIF(EDIPSUGAR(f),EVRWTDEG(HTf,W)),
                    RNDIF(EDIPSUGAR(g),EVRWTDEG(HTg,W))),
              EVRWTDEG(EVLCM(HTf,HTg),W));
   RETURN(EDIPSUGCON(SP,SUG));
END EDIPSUGSP;
 


PROCEDURE EDIPSUGWRITE(f: LIST);
(* Extended distributive polynomial write in case of the normal with sugar
   strategy.
   The extended distributive polynomial f is written in the output stream. *)

BEGIN
   DIWRIT(EDIPUNEXTEND(f),VALIS); BLINES(0);
   SWRITE("with sugar "); RNWRIT(EDIPSUGAR(f));
   SWRITE("."); BLINES(1);
END EDIPSUGWRITE;



(* ------------------------------------------------------------------------ *
 * 3.2 Procedures for extended critical pairs                               *
 *     In case of the normal with sugar strategy an extended critical pair  *
 *     is a quadruple ((f,Sf),(g,Sg),lcm,S) where (f,g) is a critical pair, *
 *     lcm is the exponent vector of the least common multiple of the       *
 *     leading terms of f and g and S is the sugar of the S-polynomial of f *
 *     and g.                                                               *
 * ------------------------------------------------------------------------ *)


PROCEDURE ECPSUGCON(f,g: LIST): LIST;
(* Critical pair normal with sugar strategy extension constructor.
   f and g are extended distributive polynomials such that the distributive
   polynomial appropriate to f,g define a critical pair.
   The extended critical pair ECPSUGCON(f,g) is the extension of (f,g) by two
   further components: a third component is given by the exponent vector of the
   least common multiple of the leading term of f and the leading term of g, a
   fourth component is given by the sugar of the S-polynomial of f and g. *)

(* This constructor function has to be modified if a new extended critical pair
   data structure w.r.t. the normal with sugar strategy is chosen in this
   implementation module. In the current revision the extended critical pair
   is implemented as a list of length four. *)


VAR W, HTf,HTg, LCM,SUG: LIST;

BEGIN
   HTf:=EDIPEVL(f); HTg:=EDIPEVL(g);
   LCM:=EVLCM(HTf,HTg);
   W:=DIPAGBOpt.VariableWeight;
   SUG:=RNSUM(RNMAX(RNDIF(EDIPSUGAR(f),EVRWTDEG(HTf,W)),
                    RNDIF(EDIPSUGAR(g),EVRWTDEG(HTg,W))),
              EVRWTDEG(LCM,W));
   RETURN(LIST4(f,g,LCM,SUG));
END ECPSUGCON;



PROCEDURE ECPSUGAR(CP: LIST): LIST;
(* Extended critical pair select sugar.
   ECPSUGAR(CP) is the sugar of the S-polynomial of the polynomials in the
   extended critical pair CP. *)

(* This selector function has to be modified if a new extended critical pair
   data structure w.r.t. the normal with sugar strategy is chosen in this
   implementation module. In the current revision the extended critical pair
   is implemented as a list of length four where the fourth component is the
   sugar of the S-polynomial. *)

BEGIN
   RETURN(FOURTH(CP));
END ECPSUGAR;



PROCEDURE ECPSUGINS(CP,P: LIST): LIST;
(* Extended critical pair normal with sugar strategy insertion.
   The extended critical pair CP is to be inserted into the extended critical
   pair list P w.r.t. the normal with sugar strategy.
   P and ECPSUGINS(CP,P) are ordered lists with increasing sugar of the
   S-polynomial and then increasing least common multiple of the leading terms
   w.r.t. the given term order. *)

VAR PP,PPR, LCMCP,SUGCP, SUGCompare: LIST;

BEGIN
   (* P is the empty list. *)
      IF P=SIL THEN RETURN(LIST1(CP)); END;
   SUGCP:=ECPSUGAR(CP);
   LCMCP:=ECPLCMHT(CP);
   (* SUGCP is minimal among all sugar. *)
      SUGCompare:=RNCOMP(ECPSUGAR(FIRST(P)),SUGCP);
      IF SUGCompare=1 THEN RETURN(COMP(CP,P)); END;
      IF (SUGCompare=0) AND (EVCOMP(ECPLCMHT(FIRST(P)),LCMCP)>=0)
         THEN RETURN(COMP(CP,P));
      END;
   (* Look for the first element of P with sugar >= SUGCP. *)
      PP:=P; PPR:=RED(PP);
      WHILE (PPR<>SIL) AND (RNCOMP(ECPSUGAR(FIRST(PPR)),SUGCP)=-1) DO
         PP:=PPR; PPR:=RED(PP);
      END;
   (* The end of PP is reached or sugar(FIRST(PPR)) > SUGCP. *)
      IF (PPR=SIL) OR (RNCOMP(ECPSUGAR(FIRST(PPR)),SUGCP)=1) THEN
         SRED(PP,COMP(CP,PPR)); RETURN(P);
      END;
   (* sugar(FIRST(PPR)) = SUGCP holds. *)
      (* Look for the first element of PPR with sugar > SUGCP or
         (sugar = SUGCP and lcm >= LCMCP). *)
         WHILE (PPR<>SIL)
               AND (RNCOMP(ECPSUGAR(FIRST(PPR)),SUGCP)=0)
               AND (EVCOMP(ECPLCMHT(FIRST(PPR)),LCMCP)=-1) DO
            PP:=PPR; PPR:=RED(PP);
         END;
      (* Insert CP. *)
      SRED(PP,COMP(CP,PPR)); RETURN(P);
END ECPSUGINS;



PROCEDURE ECPSUGWRITE(CP: LIST);
(* Extended critical pair write in case of the normal with sugar strategy.
   The extended critical pair CP is written in the output stream. *)

VAR f,g, Cf,Ef,Rf, F,G: LIST;

BEGIN
   F:=ECPPOLY1(CP); G:=ECPPOLY2(CP);
   f:=EDIPUNEXTEND(F); g:=EDIPUNEXTEND(G);
   SWRITE("1st polynomial: "); DIWRIT(f,VALIS); BLINES(0);
   SWRITE("    with sugar "); RNWRIT(EDIPSUGAR(F)); BLINES(0);
   SWRITE("2nd polynomial: "); DIWRIT(g,VALIS); BLINES(0);
   SWRITE("    with sugar "); RNWRIT(EDIPSUGAR(G)); BLINES(0);
   DIPMAD(f, Cf,Ef,Rf);
   SWRITE("LCM of their leading terms:");
   DIWRIT(DIPFMO(ADFI(Cf,1),ECPLCMHT(CP)),VALIS); BLINES(0);
   SWRITE("Sugar of their S-polynomial: "); RNWRIT(ECPSUGAR(CP)); BLINES(0);
END ECPSUGWRITE;



(* ------------------------------------------------------------------------ *
 * 3.3 Further procedures w.r.t. the normal with sugar strategy             *
 * ------------------------------------------------------------------------ *)


PROCEDURE SugarUpdateVariableWeight;
(* Update of the DIPAGB variable weight list in case of the normal with
   sugar strategy.
   If the actual DIPAGB variable weight list W is of the form W=(1,...,1)
   or W=SIL then W is replaced by the list W'=(1,...,1) such that W' and the
   variable list VALIS are of the same length. If W, however, has components
   different to 1 then it is tested whether W and VALIS are of the same length
   and in case this test is false an error message will occur. *)

VAR V,W, v,w: LIST;
    OnlyOneSeen: BOOLEAN;

BEGIN
   V:=VALIS;
   W:=DIPAGBOpt.VariableWeight;
   OnlyOneSeen:=TRUE;
   WHILE (V<>SIL) AND (W<>SIL) DO
      ADV(V, v,V); ADV(W, w,W);
      IF RNCOMP(RNINT(1),w)<>0 THEN OnlyOneSeen:=FALSE; END;
   END;
   IF OnlyOneSeen
      THEN (* All components of W up to now were 1. *)
              IF (V<>SIL) AND (W=SIL)
              THEN (* Add (1,...,1) to the DIPAGB variable weight list until
                      it is of the same length as VALIS. *)
                   W:=DIPAGBOpt.VariableWeight;
                   WHILE V<>SIL DO
                      ADV(V, v,V);
                      W:=COMP(RNINT(1),W);
                   END;
                   SetDIPAGBVariableWeight(W); BLINES(1);
              ELSE IF (* V=SIL AND *) W<>SIL
                      THEN (* Test whether the rest of the DIPAGB variable
                              weight list is of the form (1,...,1) *)
                           WHILE OnlyOneSeen AND (W<>SIL) DO
                              ADV(W, w,W);
                              IF RNCOMP(RNINT(1),w)<>0
                                 THEN OnlyOneSeen:=FALSE;
                              END;
                           END;
                           IF OnlyOneSeen
                              THEN (* The test above is true. So the new DIPAGB
                                      variable weight list should be the list
                                      (1,...,1) of the length |VALIS|. *)
                                   V:=VALIS; W:=SIL;
                                   WHILE V<>SIL DO
                                      ADV(V, v,V);
                                      W:=COMP(RNINT(1),W);
                                   END;
                                   SetDIPAGBVariableWeight(W); BLINES(1);
                              ELSE (* The test above is false. *)
                                   WriteDIPAGBVariableWeight;
                                   ERROR(fatal,
                                      "DIPAGB: no valid variable weight list");
                           END;
                   END;
           END;
      ELSE (* At least one component of W was different to 1. *)
           IF ((V=SIL) AND (W<>SIL)) OR ((V<>SIL) AND (W=SIL))
              THEN WriteDIPAGBVariableWeight;
                   ERROR(fatal,"DIPAGB: no valid variable weight list");
           END;
   END;
END SugarUpdateVariableWeight;



(*****************************************************************************
 * 4. Option Handling                                                        *
 *****************************************************************************)


PROCEDURE InitDIPAGB;
(* Initialization of the DIPAGB options. *)

BEGIN
   DIPAGBOpt.TraceFlag            := 0;
   DIPAGBOpt.Strategy             := Normal;
   DIPAGBOpt.VariableWeight       := SIL;
   DIPAGBOpt.UpdateVariableWeight := NOP;
   DIPAGBOpt.Update               := UPDATE;
   DIPAGBOpt.InitUpdate           := UPDATE;
   DIPAGBOpt.CPExtend             := ECPNORCON;
   DIPAGBOpt.DIPExtend            := IDF1;
   DIPAGBOpt.ECPInsert            := ECPNORINS;
   DIPAGBOpt.ECPSelect            := ADV;
   DIPAGBOpt.ECPWrite             := ECPNORWRITE;
   DIPAGBOpt.EDIPNormalform       := ADPNF;
   DIPAGBOpt.EDIPSPolynomial      := ADPSP;
   DIPAGBOpt.EDIPUnExtend         := IDF1;
   DIPAGBOpt.EDIPWrite            := EDIPNORWRITE;
END InitDIPAGB;



PROCEDURE SetCPExtend(EXT: PROCF2);
(* Set the critical pair extension function. *)

BEGIN
   DIPAGBOpt.CPExtend:=EXT;
END SetCPExtend;



PROCEDURE SetDIPAGBOptions(OPT: LIST);
(* Set the trace flag, the strategy and the variable weight list in the
   DIPAGB option record. *)

VAR L: GAMMAINT;

BEGIN
   L:=LENGTH(OPT);
   IF L>=1  THEN SetDIPAGBTraceFlag(FIRST(OPT)); BLINES(1); END;
   IF L>=2  THEN SetDIPAGBStrategy(SECOND(OPT)); BLINES(1); END;
   IF L>=3  THEN SetDIPAGBVariableWeight(THIRD(OPT)); BLINES(1); END;
END SetDIPAGBOptions;



PROCEDURE SetDIPAGBStrategy(st: LIST);
(* Set the DIPAGB strategy option for the extended critical pair selection.
   st=0 (= normal) and st=1 (= normal with sugar) are supported. *)

BEGIN
   DIPAGBOpt.Strategy := st;
   IF DIPAGBOpt.TraceFlag >= 3 THEN
      SWRITE("New strategy: "); AWRITE(st);
      CASE st OF
         0: SWRITE("  (= normal)           ") |
         1: SWRITE("  (= normal with sugar)")
         ELSE ERROR(fatal, "SetDIPAGBStrategy: No valid strategy.");
      END;
   END;
   CASE st OF
      0: SetUpdateVariableWeight(NOP);
         SetCPExtend(ECPNORCON);
         SetDIPExtend(IDF1);
         SetECPInsert(ECPNORINS);
         SetECPWrite(ECPNORWRITE);
         SetEDIPNormalform(ADPNF);
         SetEDIPSPolynomial(ADPSP);
         SetEDIPUnExtend(IDF1);
         SetEDIPWrite(EDIPNORWRITE)
         |
      1: SetUpdateVariableWeight(SugarUpdateVariableWeight);
         SetCPExtend(ECPSUGCON);
         SetDIPExtend(DIPSUGEXT);
         SetECPInsert(ECPSUGINS);
         SetECPWrite(ECPSUGWRITE);
         SetEDIPNormalform(ADPSUGNF);
         SetEDIPSPolynomial(ADPSUGSP);
         SetEDIPUnExtend(FIRST);
         SetEDIPWrite(EDIPSUGWRITE)	
   END;
END SetDIPAGBStrategy;



PROCEDURE SetDIPAGBTraceFlag(tf: LIST);
(* Set the DIPAGB trace flag.
   tf is a non-negative integer level for interactive documentations. *)

BEGIN
   DIPAGBOpt.TraceFlag := tf;
   IF DIPAGBOpt.TraceFlag >= 3 THEN
      SWRITE("New documentation level: "); AWRITE(tf);
   END;
END SetDIPAGBTraceFlag;



PROCEDURE SetDIPAGBVariableWeight(VW: LIST);
(* Set the DIPAGB variable weight list for the normal with sugar strategy.
   VW is a list of r non-negative rational components where r is the number of
   variables in the distributive polynomials handled with. The i-th component
   is the weight of the i-th variable in the variable list VALIS. *)

BEGIN
   IF DIPAGBOpt.TraceFlag >= 3 THEN
      SWRITE("New variable weight list: "); LRNWRIT(VW);
   END;
   DIPAGBOpt.VariableWeight := INV(VW);
END SetDIPAGBVariableWeight;



PROCEDURE SetDIPExtend(EXT: PROCF1);
(* Set the distributive polynomial extension function. *) 

BEGIN
   DIPAGBOpt.DIPExtend:=EXT;
END SetDIPExtend;



PROCEDURE SetECPInsert(INS: PROCF2);
(* Set the extended critical pair insertion function. *)

BEGIN
   DIPAGBOpt.ECPInsert:=INS;
END SetECPInsert;



PROCEDURE SetECPSelect(SEL: PROCP1V2);
(* Set the extended critical pair selection procedure. *)

BEGIN
   DIPAGBOpt.ECPSelect:=SEL;
END SetECPSelect;



PROCEDURE SetECPWrite(WR: PROCP1);
(* Set the extended critical pair write procedure. *)

BEGIN
   DIPAGBOpt.ECPWrite:=WR;
END SetECPWrite;



PROCEDURE SetEDIPNormalform(NF: PROCF2);
(* Set the extended distributive polynomial normalform function. *)

BEGIN
   DIPAGBOpt.EDIPNormalform:=NF;
END SetEDIPNormalform;



PROCEDURE SetEDIPSPolynomial(SP: PROCF2);
(* Set the extended distributive S-polynomial function. *)

BEGIN
   DIPAGBOpt.EDIPSPolynomial:=SP;
END SetEDIPSPolynomial;


 
PROCEDURE SetEDIPUnExtend(UEXT: PROCF1);
(* Set the extended distributive polynomial un-extension function. *)

BEGIN
   DIPAGBOpt.EDIPUnExtend:=UEXT;
END SetEDIPUnExtend;



PROCEDURE SetEDIPWrite(WR: PROCP1);
(* Set the extended distributive polynomial write procedure. *)

BEGIN
   DIPAGBOpt.EDIPWrite:=WR;
END SetEDIPWrite;



PROCEDURE SetInit(INIT: PROCP1V2);
(* Set the initialization procedure. *)

BEGIN
   DIPAGBOpt.InitUpdate:=INIT;
END SetInit;



PROCEDURE SetUpdate(UPD: PROCP1V2);
(* Set the update procedure. *)

BEGIN
   DIPAGBOpt.Update:=UPD;
END SetUpdate;



PROCEDURE SetUpdateVariableWeight(UPD: PROCP0);
(* Set the DIPAGB variable weight update procedure. *)

BEGIN
   DIPAGBOpt.UpdateVariableWeight:=UPD;
END SetUpdateVariableWeight;



PROCEDURE WriteDIPAGBOptions;
(* Write the current trace flag, strategy and variable weight list of the
   DIPAGB option record in the output stream. *)

BEGIN
   WriteDIPAGBTraceFlag;      BLINES(0);
   WriteDIPAGBStrategy;       BLINES(0);
   WriteDIPAGBVariableWeight; BLINES(0);
END WriteDIPAGBOptions;



PROCEDURE WriteDIPAGBStrategy;
(* Write the DIPAGB strategy option for the extended critical pair selection
   in the output stream. *)

BEGIN
   SWRITE("Actual strategy: "); AWRITE(DIPAGBOpt.Strategy);
   CASE DIPAGBOpt.Strategy OF
      0: SWRITE("  (= normal)           ") |
      1: SWRITE("  (= normal with sugar)")
   END;
   BLINES(0);
END WriteDIPAGBStrategy;



PROCEDURE WriteDIPAGBTraceFlag;
(* Write the DIPAGB trace flag in the output stream. *)

BEGIN
   SWRITE("Actual documentation level: "); AWRITE(DIPAGBOpt.TraceFlag);
   BLINES(0);
END WriteDIPAGBTraceFlag;



PROCEDURE WriteDIPAGBVariableWeight;
(* Write the DIPAGB variable weight list in the output stream. *)

VAR WL, RN: LIST;

BEGIN
   SWRITE("Actual variable weight list: ");
   LRNWRIT(CINV(DIPAGBOpt.VariableWeight));
   BLINES(0);
END WriteDIPAGBVariableWeight;



(*****************************************************************************
 * 5. Main Program                                                           *
 *****************************************************************************)


BEGIN
   LISTVAR(DIPAGBOpt.VariableWeight);
   InitDIPAGB;
END DIPAGB.

(* -EOF- *)
