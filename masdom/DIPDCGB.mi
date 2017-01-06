(* ----------------------------------------------------------------------------
 * $Id: DIPDCGB.mi,v 1.3 1994/11/28 20:52:53 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDCGB.mi,v $
 * Revision 1.3  1994/11/28  20:52:53  dolzmann
 * Syntactical errors corrected.
 * Usage of predefined procedure types.
 *
 * Revision 1.2  1994/11/03  14:40:56  pfeil
 * added procedures SetTraceLevel, SetDecompProc, SetUpdateProc, SetVarOrdOpt,
 * SetFacSugar, SetReduceExp, SetBranchProc, WriteDCGBopt.
 * modified procedure GroebnerBases1 for sugar.
 * added procedure EQIEQ (Graebe/Lassner) for procedure GrobnerBases2
 *
 * Revision 1.1  1994/08/31  13:27:50  pfeil
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPDCGB;

(* DIP Decompositional Groebner Bases Implementation Module. *)



(* Import lists and declarations. *)

FROM MASBIOS 	IMPORT SWRITE, BLINES;

FROM MASSTOR 	IMPORT LIST, SIL, COMP, ADV, FIRST, RED,
		       SFIRST, LIST1, INV, TIME, LENGTH;

FROM MASERR	IMPORT severe, ERROR;

FROM MASLISPU IMPORT PROCF1, PROCF2, PROCP1V2, PROCP0V2; 

FROM SACLIST 	IMPORT EQUAL, SECOND, FIRST2, AWRITE,
		       LIST2, LIST5, LWRITE, OWRITE, CONC, CCONC;

FROM SACRN	IMPORT RNINT;

FROM DIPC 	IMPORT DIPTDG, DIPEVL, VALIS, DILPERM, DIPLPM;

FROM DIPADOM 	IMPORT DIWRIT, DIPFAC, DIPSFF, DIPNF, DIPS, DIPEXP,
		       DIPIRL;

FROM DIPTOO	IMPORT DIPVOPP, INVPERM;

FROM DIPAGB	IMPORT ECPPOLY1, ECPPOLY2, ECPSELECT, EDIPEVL, EDIPNOR,
		       EDIPSP, EDIPSUGAR, EDIPSUGCON, EDIPUNEXTEND,
		       EDIPWRITE, LDIPEXTEND, LECPWRITE, LEDIPUNEXTEND,
		       LEDIPWRITE, SetDIPAGBStrategy, UpdateVariableWeight,
		       UPDATE;


CONST rcsidi = "$Id: DIPDCGB.mi,v 1.3 1994/11/28 20:52:53 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1994 Universitaet Passau";


VAR DCGBopt: RECORD
		TraceLevel: INTEGER;
		DecompProc: PROCF2;	DPNo:       INTEGER;
		UpdateProc: PROCP1V2;	UPNo:       INTEGER;
		VarOrdOpt:  INTEGER;
		FacSugar:   INTEGER;
		ReduceExp:  INTEGER;
		BranchProc: PROCF1;	BPNo:       INTEGER;
	     END;


(* ------------------------------------------------------------------------ *
 * 0. option procedures							    *
 * ------------------------------------------------------------------------ *)


PROCEDURE SetTraceLevel(TL: INTEGER);
(* Set Trace-Level for decompositional groebner bases:
      0 = no output, except with VOOB,
     >0 = output of time and result after computation,
     >1 = output of messages about tree of computation:
	  number of canceled branches/factors, "cancel factor",
          "cancel branch", "groebner base", "branch w.o. zeros",
     >2 = output of s-polynomials and normalforms,
     >3 = output of parameters of local procedures
          and of time and groebner bases during computation. *)
BEGIN
   DCGBopt.TraceLevel:=TL;
END SetTraceLevel;

PROCEDURE SetDecompProc(DCP: INTEGER);
(* Set Decomposition-Procedure for decompositional groebner bases:
      1 = DIPFAC,
      2 = DIPSFF. *)
BEGIN
   CASE DCP OF
      1: DCGBopt.DecompProc:=DIPFAC; |
      2: DCGBopt.DecompProc:=DIPSFF; 
   ELSE
      ERROR(severe,"SetDecompProc: unknown DecompProc option");
   END; (* CASE DCP... *)
   DCGBopt.DPNo:=DCP;
END SetDecompProc;

PROCEDURE SetUpdateProc(UP: INTEGER);
(* Set Update-Procedure for decompositional groebner bases: 
      1 = UPDATE from module DIPAGB. *)
BEGIN   
   CASE UP OF
      1: DCGBopt.UpdateProc:=UPDATE; 
   ELSE
      ERROR(severe,"SetUpdateProc: unknown UpdateProc option");
   END; (* CASE UP... *)
   DCGBopt.UPNo:=UP;
END SetUpdateProc;

PROCEDURE SetVarOrdOpt(VOO: INTEGER);
(* Set Variable-Order-Optimization for decompositional groebner bases: 
      0 = don`t optimize,
      1 = optimize at begin only,
      2 = optimize factorization only,
      3 = optimize at begin and factorization *)
BEGIN
   IF (VOO<0) OR (VOO>3) THEN
      ERROR(severe,"SetVarOrdOpt: unknown VarOrdOpt option"); END;
   DCGBopt.VarOrdOpt:=VOO;   
END SetVarOrdOpt;

PROCEDURE SetFacSugar(FS: INTEGER);
(* Set Factor-Sugar for procedure GroebnerBases1: 
      0 = normal strategy (no sugar)
      1 = sugar of factor is total degree of factor,
      2 = sugar of factor is old sugar *)
BEGIN
   IF (FS<0) OR (FS>2) THEN
      ERROR(severe,"SetFacSugar: unknown FacSugar option"); END;
   DCGBopt.FacSugar:=FS;
END SetFacSugar;

PROCEDURE SetReduceExp(RE: INTEGER);
(* Set Reduce-Exponent for procedure GroebnerBases2:
      1 = reduce (no power of) polynomial
     >1 = reduce corresponding power of polynomial *)
BEGIN
   IF RE<1 THEN
      ERROR(severe,"SetReduceExp: unknown ReduceExp option"); END;
   DCGBopt.ReduceExp:=RE;
END SetReduceExp;

PROCEDURE SetBranchProc(BP: INTEGER);
(* Set Branch-Procedure for procedure GroebnerBases2:
      1 = SSCO  - new branch for each subset of factors,
      2 = EQIEQ - new branch for each factor *)
BEGIN
   CASE BP OF
      1: DCGBopt.BranchProc:=SSCO; |
      2: DCGBopt.BranchProc:=EQIEQ;
   ELSE
      ERROR(severe,"SetBranchProc: unknown BranchProc option");
   END; (* CASE BP... *)
   DCGBopt.BPNo:=BP;
END SetBranchProc;

PROCEDURE SetDCGBopt(options: LIST);
(* Set options for decompositional groebner bases.
   options is a list of 7 or less elements in following order:
   1. Trace-Level (0-4),
   2. No. of Decomposition-Procedure (1,2),
   3. No. of Update-Procedure (1),
   4. Optimization of variable order (0,1,2,3),
   5. Sugar of factors for Procedure GroebnerBases1 (0,1,2),
   6. Reduce-Exponent for procedure GroebnerBases2 (>0),
   7. No. of Branch-Procedure in GroebnerBases2 (1,2).
*)
VAR TL,DCP,UP,VOO,RE,FS,BP: INTEGER;
BEGIN
   IF options<>SIL THEN
      ADV(options,TL,options);
      SetTraceLevel(TL);
   IF options<>SIL THEN
      ADV(options,DCP,options);
      SetDecompProc(DCP);
   IF options<>SIL THEN
      ADV(options,UP,options);
      SetUpdateProc(UP);
   IF options<>SIL THEN
      ADV(options,VOO,options);
      SetVarOrdOpt(VOO);
   IF options<>SIL THEN
      ADV(options,FS,options);
      SetFacSugar(FS);
   IF options<>SIL THEN
      ADV(options,RE,options);
      SetReduceExp(RE);
   IF options<>SIL THEN
      ADV(options,BP,options);
      SetBranchProc(BP);
   END; END; END; END; END; END; END;
END SetDCGBopt;

PROCEDURE WriteDCGBopt;
(* write decompositional groebner bases options *)
BEGIN
   SWRITE("TraceLevel : "); AWRITE(DCGBopt.TraceLevel); BLINES(0);
   SWRITE("DecompProc : "); 
   CASE DCGBopt.DPNo OF
      1: SWRITE("DIPFAC"); |
      2: SWRITE("DIPSFF");
   END; (* CASE ... *) BLINES(0);
   SWRITE("UpdateProc : ");
   CASE DCGBopt.UPNo OF
      1: SWRITE("UPDATE");
   END; (* CASE ... *) BLINES(0);
   SWRITE("VarOrdOpt  : "); AWRITE(DCGBopt.VarOrdOpt);  BLINES(0);
   SWRITE("FacSugar   : "); AWRITE(DCGBopt.FacSugar);   BLINES(0);
   SWRITE("ReduceExp  : "); AWRITE(DCGBopt.ReduceExp);  BLINES(0);
   SWRITE("BranchProc : ");
   CASE DCGBopt.BPNo OF
      1: SWRITE("SSCO"); |
      2: SWRITE("EQIEQ");
   END; (* CASE ... *) BLINES(0);
END WriteDCGBopt;


(* ------------------------------------------------------------------------ *
 * 1. The main function GroebnerBases1                                      *
 * ------------------------------------------------------------------------ *)


PROCEDURE GroebnerBases1(G: LIST): LIST; 
(* Distributive polynomials decompositional groebner bases.
   G is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a list (GB1,...,GBk) of groebner bases,
   where Z(G) = Z(GB1) v ... v Z(GBk). *)

VAR GBList,T,t,OldVarL,PermV,invPV,VOOF,VOOB: LIST;
    nocb: INTEGER;
    CS: BOOLEAN; 

PROCEDURE RECGB1(G,Fcmp: LIST): LIST;
VAR H,g,HTg,HTf,G1,F,GBList,f,B: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R1"); BLINES(0); PWrite(1,G); PWrite(4,Fcmp); BLINES(1); END;
   H:=SIL;
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF DIPTDG(g)=0 THEN 
         IF DCGBopt.TraceLevel>1 THEN 
	    SWRITE("= branch w.o. zeros ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      G1:=CCONC(G,H);
      F:=newFactors(G1,g,Fcmp);
      IF DCGBopt.TraceLevel>3 THEN PWrite(2,F); END;
      IF F=SIL THEN
	 IF DCGBopt.TraceLevel>1 THEN
            SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      ADV(F,f,F);
      IF F=SIL THEN
         HTg:=DIPEVL(g);
         HTf:=DIPEVL(f);
         IF EQUAL(HTg,HTf)=1 THEN
            H:=COMP(f,H);
         ELSE
            G:=COMP(f,G1);
            DIPIRL(G,CS);
            H:=SIL;
         END; (* IF EQUAL... *)
      ELSE
         GBList:=SIL;
         LOOP (* 1 *)
            G:=COMP(f,G1);
            DIPIRL(G,CS);
            GBList:=CONC(GBList,RECGB1(G,Fcmp));
            IF F=SIL THEN EXIT; END;
            Fcmp:=COMP(f,Fcmp);
            ADV(F,f,F);
         END; (* LOOP 1 *)
         RETURN(GBList);
      END; (* IF F... *)
   END; (* WHILE G... *)
   Init(H,B);
   RETURN(RECGB2(H,B,Fcmp));
END RECGB1;

PROCEDURE RECGB2(G,B,Fcmp: LIST): LIST;
VAR CP,g1,g2,S,h,F,oldG,oldB,f,GBList: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R2"); BLINES(0); PWrite(1,G); PPWrite(B);
      PWrite(4,Fcmp); BLINES(1); END;
   WHILE B<>SIL DO
      ADV(B,CP,B);
      FIRST2(CP,g1,g2);
      S:=DIPS(g1,g2);
      IF DCGBopt.TraceLevel>2 THEN DIWRIT(S,VALIS); END;
      IF S<>0 THEN
         h:=DIPNF(G,S);
         IF DCGBopt.TraceLevel>2 THEN DIWRIT(h,VALIS); BLINES(0); END;
         IF h<>0 THEN
            IF DIPTDG(h)=0 THEN
	       IF DCGBopt.TraceLevel>1 THEN
       	          SWRITE("= branch w.o. zeros ="); nocb:=nocb+1;
		  BLINES(0); END;
	       RETURN(SIL); END;
            F:=newFactors(G,h,Fcmp);
            IF DCGBopt.TraceLevel>3 THEN PWrite(2,F); END;
            IF F=SIL THEN
	       IF DCGBopt.TraceLevel>1 THEN
                  SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
	       RETURN(SIL); END;
            ADV(F,f,F);
            IF F=SIL THEN 
               DCGBopt.UpdateProc(f,G,B);
            ELSE
               GBList:=SIL; oldG:=G; oldB:=B;
               LOOP (* 1 *)
                  G:=oldG; B:=oldB;
                  DCGBopt.UpdateProc(f,G,B);
                  GBList:=CONC(GBList,RECGB2(G,B,Fcmp));
                  IF F=SIL THEN EXIT; END;
                  Fcmp:=COMP(f,Fcmp);
                  ADV(F,f,F);
               END; (* LOOP 1 *)
               RETURN(GBList);
            END; (* IF F... *)
         END; (* IF h... *)
      ELSE 
         IF DCGBopt.TraceLevel>2 THEN BLINES(0); END;
      END; (* IF S... *)
   END; (* WHILE B... *)
   DIPIRL(G,CS);
   IF CS THEN RETURN(RECGB1(G,Fcmp));
   ELSE 
      IF DCGBopt.TraceLevel>1 THEN 
         SWRITE("= groebner base ="); BLINES(0);
         IF DCGBopt.TraceLevel>3 THEN
            t:=TIME()-T; SWRITE("Time :"); AWRITE(t); 
            PWrite(0,G); BLINES(0);
	 END; (* IF DCGBopt... *)
      END; (* IF DCGBopt... *)
      RETURN(LIST1(G));
   END; (* IF CS... *)
END RECGB2;

PROCEDURE newFactors(G,h,Fcmp: LIST): LIST;
VAR Fnew,F,ExpPol,hi,FL,g,G1: LIST;
BEGIN
   Fnew:=SIL;
   F:=DCGBopt.DecompProc(h,VOOF);	(* factorization *)
   F:=SortF(F);	(* sort factors in non-increasing order *)
   WHILE F<>SIL DO
      ADV(F,hi,F);
      G1:=COMP(hi,G);
      FL:=Fcmp;
      LOOP (* 1 *)
	 IF FL=SIL THEN Fnew:=COMP(hi,Fnew); Fcmp:=COMP(hi,Fcmp); EXIT; END;
	 ADV(FL,g,FL);
	 IF DIPNF(G1,g)=0 THEN
            IF DCGBopt.TraceLevel>1 THEN
               SWRITE("= cancel factor ="); nocb:=nocb+1; BLINES(0); END;
            EXIT; END;
      END; (* LOOP 1 *)
   END; (* WHILE F... *)
   RETURN(INV(Fnew));
END newFactors;

PROCEDURE REC1(G,Fcmp1: LIST): LIST;
VAR H,g,h,HTg,HTf,G1,F,GBList,f,B: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R1"); BLINES(0); LEDIPWRITE(G);
      PWrite(4,Fcmp1); BLINES(1); END;
   H:=SIL;
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF DIPTDG(EDIPPOLY(g))=0 THEN (* g constant *)
         IF DCGBopt.TraceLevel>1 THEN 
	    SWRITE("= branch w.o. zeros ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      G1:=CCONC(G,H);
      F:=EnewFactors(G1,g,Fcmp1);
      IF DCGBopt.TraceLevel>3 THEN
	 SWRITE("F = "); BLINES(0);
	 LEDIPWRITE(F); END;
      IF F=SIL THEN
	 IF DCGBopt.TraceLevel>1 THEN
            SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      ADV(F,f,F);
      IF F=SIL THEN
         HTg:=EDIPEVL(g);
         HTf:=EDIPEVL(f);
         IF EQUAL(HTg,HTf)=1 THEN
            H:=COMP(f,H);
         ELSE
            G:=COMP(f,G1);
            EDIPIRL(G,CS);
            H:=SIL;
         END; (* IF EQUAL... *)
      ELSE
         GBList:=SIL;
         LOOP (* 1 *)
            G:=COMP(f,G1);
            EDIPIRL(G,CS);
            GBList:=CONC(GBList,REC1(G,Fcmp1));
            IF F=SIL THEN EXIT; END;
            Fcmp1:=COMP(EDIPPOLY(f),Fcmp1);
            ADV(F,f,F);
         END; (* LOOP 1 *)
         RETURN(GBList);
      END; (* IF F... *)
   END; (* WHILE G... *)
   Init(H,B);
   RETURN(REC2(H,B,Fcmp1));
END REC1;

PROCEDURE REC2(G,B,Fcmp2: LIST): LIST;
VAR CP,g1,g2,S,h,h1,F,oldG,oldB,f,GBList: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R2"); BLINES(0); LEDIPWRITE(G);
      LECPWRITE(B); PWrite(4,Fcmp2); BLINES(1); END;
   WHILE B<>SIL DO
      ECPSELECT(B,CP,B);
      g1:=ECPPOLY1(CP); g2:=ECPPOLY2(CP);
      S:=EDIPSP(g1,g2);
      IF DCGBopt.TraceLevel>2 THEN EDIPWRITE(S); END;
      IF FIRST(S)<>0 THEN
         h:=EDIPNOR(G,S);
         IF DCGBopt.TraceLevel>2 THEN EDIPWRITE(h); BLINES(0); END;
         h1:=EDIPPOLY(h);
         IF h1<>0 THEN
            IF DIPTDG(h1)=0 THEN (* h1 constant *)
	       IF DCGBopt.TraceLevel>1 THEN
       	          SWRITE("= branch w.o. zeros ="); nocb:=nocb+1;
		  BLINES(0); END;
	       RETURN(SIL); END;
            F:=EnewFactors(G,h,Fcmp2);
            IF DCGBopt.TraceLevel>3 THEN 
		SWRITE("F = "); BLINES(0);
		LEDIPWRITE(F); END;
            IF F=SIL THEN
	       IF DCGBopt.TraceLevel>1 THEN
                  SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
	       RETURN(SIL); END;
            ADV(F,f,F);
            IF F=SIL THEN 
               DCGBopt.UpdateProc(f,G,B);
            ELSE
               GBList:=SIL; oldG:=G; oldB:=B;
               LOOP (* 1 *)
                  G:=oldG; B:=oldB;
                  DCGBopt.UpdateProc(f,G,B);
                  GBList:=CONC(GBList,REC2(G,B,Fcmp2));
                  IF F=SIL THEN EXIT; END;
                  Fcmp2:=COMP(EDIPPOLY(f),Fcmp2);
                  ADV(F,f,F);
               END; (* LOOP 1 *)
               RETURN(GBList);
            END; (* IF F... *)
         END; (* IF h... *)
      ELSE 
         IF DCGBopt.TraceLevel>2 THEN BLINES(0); END;
      END; (* IF S... *)
   END; (* WHILE B... *)
   EDIPIRL(G,CS);
   IF CS THEN RETURN(REC1(G,Fcmp2));
   ELSE 
      IF DCGBopt.TraceLevel>1 THEN 
         SWRITE("= groebner base ="); BLINES(0);
         IF DCGBopt.TraceLevel>3 THEN
            t:=TIME()-T; SWRITE("Time :"); AWRITE(t); BLINES(0);
            LEDIPWRITE(G); BLINES(0);
	 END; (* IF DCGBopt... *)
      END; (* IF DCGBopt... *)
      RETURN(LIST1(G));
   END; (* IF CS... *)
END REC2;

PROCEDURE EnewFactors(G,h,Fcmp: LIST): LIST;
(* G is a list of extended polynomials in distributive
   representation,
   Fcmp is a list of polynomials in distributive representation, 
   h is an extended polynomial in distributive representation *)
VAR Fnew,Sugar,F,ExpPol,hi,FL,g,G1,h1: LIST;
BEGIN
   Fnew:=SIL; 
   FIRST2(h,h1,Sugar);
   G:=LEDIPUNEXTEND(G); 
   F:=DCGBopt.DecompProc(h1,VOOF);	(* factorization *)
   F:=SortF(F);	(* sort factors in non-increasing order *)
   WHILE F<>SIL DO
      ADV(F,hi,F);
      G1:=COMP(hi,G);
      FL:=Fcmp;
      LOOP (* 1 *)
	 IF FL=SIL THEN 
	    Fcmp:=COMP(hi,Fcmp); 
            CASE DCGBopt.FacSugar OF
	       1: Fnew:=COMP(LIST2(hi,RNINT(DIPTDG(hi))),Fnew); |
               2: Fnew:=COMP(LIST2(hi,Sugar),Fnew);
            END; (* CASE ... *)
	    EXIT;
	 END; (* if FL... *)
	 ADV(FL,g,FL);
	 IF DIPNF(G1,g)=0 THEN
            IF DCGBopt.TraceLevel>1 THEN
               SWRITE("= cancel factor ="); BLINES(0);
	       nocb:=nocb+1; END;
            EXIT;
         END; (* IF DIPNF... *)
      END; (* LOOP 1 *)
   END; (* WHILE F... *)
   RETURN(INV(Fnew));
END EnewFactors;

BEGIN
   CASE DCGBopt.FacSugar OF
        0: SetDIPAGBStrategy(0); |	(* strategy = normal *)
      1,2: SetDIPAGBStrategy(1);	(* strategy = normal with sugar *)
   END; (* CASE ... *)
   IF G=SIL THEN ERROR(severe,"GB1: undefined ideal"); END;
   IF ZeroPoly(G) THEN ERROR(severe,"GB1: zero polynomial"); END; 
   T:=TIME();
   CASE DCGBopt.VarOrdOpt OF 
      1: VOOB:=1; VOOF:=0; |
      2: VOOB:=0; VOOF:=1; |
      3: VOOB:=1; VOOF:=1; 
   ELSE
      VOOB:=0; VOOF:=0;
   END; (* DCGBopt... *)
   IF VOOB=1 THEN 
      OldVarL:=VALIS;
      DIPVOPP(G,OldVarL,G,VALIS,PermV);
      invPV:=INVPERM(PermV);
   END; (* IF VOOB... *)
   nocb:=0;
   CASE DCGBopt.FacSugar OF
        0: DIPIRL(G,CS);
           GBList:=RECGB1(G,SIL); |
      1,2: UpdateVariableWeight;
           G:=LDIPEXTEND(G);
           EDIPIRL(G,CS);
           GBList:=LLEDIPUNEXTEND(REC1(G,SIL));
   END; (* CASE ... *)
   IF VOOB=1 THEN
      VALIS:=OldVarL;
      BLINES(1); SWRITE("= changed variable order =");
      GBList:=SGBLwrtVO1(GBList,invPV);
   END; (* IF VOOB... *) 
   IF DCGBopt.TraceLevel>0 THEN
      t:=TIME()-T;
      IF DCGBopt.TraceLevel>1 THEN
	 BLINES(0); SWRITE("Number of canceled branches/factors : ");
	 AWRITE(nocb); END;
      BLINES(1); SWRITE("Time : "); AWRITE(t); SWRITE(" ms");
      SWRITE(" with program GB1 :");
      CWrite1(GBList);
   END; (* IF DCGBopt... *)
   RETURN(GBList);
END GroebnerBases1;

(* ------------------------------------------------------------------------ *)

PROCEDURE SGBLwrtVO1(GBL,invPV: LIST): LIST;
(* sort groebner bases list w.r.t. variable order *)
VAR GBLnew,G: LIST;
BEGIN
   GBLnew:=SIL;
   WHILE GBL<>SIL DO
      ADV(GBL,G,GBL);
      G:=DILPERM(G,invPV);
      GBLnew:=COMP(G,GBLnew);
   END;
   RETURN(GBLnew);
END SGBLwrtVO1;

PROCEDURE CWrite1(gbl: LIST);
VAR i: INTEGER;
    G: LIST;
BEGIN
   BLINES(1); i:=1;
   WHILE gbl<>SIL DO
      ADV(gbl,G,gbl);
      AWRITE(i); SWRITE(". GB with ");
      AWRITE(LENGTH(G)); SWRITE(" equation(s)");
      BLINES(0); PWrite(0,G);
      BLINES(1);
      i:=i+1;
   END;
END CWrite1;

PROCEDURE LLEDIPUNEXTEND(P: LIST): LIST;
(* List of lists of extended distributive polynomials un-extend.
   P is a list of lists of extended distributive polynomials.
   LLEDIPUNEXTEND(P) is the list of lists of the appropriate
   distributive polynomials. *)
VAR Pnew,PL: LIST;
BEGIN
   Pnew:=SIL;
   WHILE P<>SIL DO
      ADV(P,PL,P);
      Pnew:=COMP(LEDIPUNEXTEND(PL),Pnew);
   END; (* while P... *)
   RETURN(Pnew);
END LLEDIPUNEXTEND;

PROCEDURE EDIPPOLY(PS: LIST): LIST;
(* Extended distributive polynomial *)
VAR p: LIST;
BEGIN
   CASE DCGBopt.FacSugar OF
        0: p:=PS; |
      1,2: p:=FIRST(PS);
   END; (* CASE ... *)
   RETURN(p);
END EDIPPOLY;

PROCEDURE EDIPIRL(VAR P: LIST; VAR CS: BOOLEAN);
(* Extended distributive polynomials interreduced list of polynomials.
   P is a list of extended polynomials in distributive representation
   over an arbitrary domain,
   CS is a flag, CS = TRUE iff P is changed,
   returns a interreduced list of polynomials R=(p1,...,pk),
   R is the result of reducing each pi modulo R-(pi)
   until no further reductions are possible. *)
VAR H,f,f1,HTf1,HTg1,g,g1: LIST;
    NewHT: BOOLEAN;
BEGIN
   CS:=FALSE;
   REPEAT
      H:=SIL; NewHT:=FALSE;
      WHILE P<>SIL DO
	 ADV(P,f,P);
	 f1:=EDIPPOLY(f);
	 HTf1:=DIPEVL(f1);
	 g:=EDIPNOR(CCONC(P,H),f);
	 g1:=EDIPPOLY(g);
	 IF g1<>0 THEN
	    HTg1:=DIPEVL(g1);
            IF EQUAL(HTf1,HTg1)=1 THEN
               IF EQUAL(f1,g1)<>1 THEN CS:=TRUE; END; 
            ELSE
	       NewHT:=TRUE; CS:=TRUE;
            END; (* IF EQUAL... *)
	    H:=COMP(g,H);
	 END; (* IF g1<>0... *)
      END; (* WHILE ... *)
      P:=H;
   UNTIL NOT(NewHT);
END EDIPIRL;


(* ------------------------------------------------------------------------ *
 * 2. The main function GroebnerBases2                                      *
 * ------------------------------------------------------------------------ *)


PROCEDURE GroebnerBases2(G,U: LIST): LIST; 
(* Distributive polynomials decompositional groebner bases 2.
   G and U are lists of polynomials in distributive representation
   over an arbitrary domain,
   returns a list ((GB1,U1),...,(GBk,Uk)) of pairs (Gi,Ui), where
   Gi is a groebner bases, Ui is a list of polynomials and
   Z(G) n D(U) = (Z(GB1) n D(U1)) v ... v (Z(GBk) n D(Uk)). *)

VAR GBList,T,t,OldVarL,PermV,invPV,VOOF,VOOB: LIST;
    nocb: INTEGER;
    CS: BOOLEAN;

PROCEDURE RECGB1(G,U: LIST): LIST;
VAR H,g,HTg,HTf,G1,F,GBList,f,B,SCL,SC,U1,G2: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN 
      SWRITE("R1"); BLINES(0); PWrite(1,G); PWrite(3,U); END;
   H:=SIL;
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF DIPTDG(g)=0 THEN 
         IF DCGBopt.TraceLevel>1 THEN 
	    SWRITE("= branch w.o. zeros ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      G1:=CCONC(G,H);
      F:=DCGBopt.DecompProc(g,VOOF);
      IF DCGBopt.TraceLevel>3 THEN PWrite(5,F); END;
      IF RED(F)=SIL THEN
         HTg:=DIPEVL(g);
         f:=SECOND(FIRST(F));
         HTf:=DIPEVL(f);
         IF EQUAL(HTg,HTf)=1 THEN
            H:=COMP(f,H);
         ELSE
            G:=COMP(f,G1);
            DIPIRL(G,CS);
            IF NOT(TEII(U,G)) THEN RETURN(SIL); END;
            H:=SIL;
         END; (* IF EQUAL... *)
      ELSE
         SCL:=DCGBopt.BranchProc(F);
         GBList:=SIL;
         WHILE SCL<>SIL DO
            ADV(SCL,SC,SCL);
            FIRST2(SC,G2,U1);
            G2:=CCONC(G2,G1);
            U1:=CCONC(U1,U);
            DIPIRL(G2,CS);
            IF TEII(U1,G2) THEN GBList:=CONC(GBList,RECGB1(G2,U1)); END;
         END; (* WHILE SCL... *)
         RETURN(GBList);
      END; (* IF RED(F)... *)
   END; (* WHILE G... *)
   Init(H,B);
   RETURN(RECGB2(H,U,B));
END RECGB1;

PROCEDURE RECGB2(G,U,B: LIST): LIST;
VAR CP,g1,g2,S,h,F,oldG,oldB,SCL,SC,G1,U1,f,GBList: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R2"); BLINES(0); PWrite(1,G); PWrite(3,U); PPWrite(B); END;
   WHILE B<>SIL DO
      ADV(B,CP,B);
      FIRST2(CP,g1,g2);
      S:=DIPS(g1,g2);
      IF DCGBopt.TraceLevel>2 THEN DIWRIT(S,VALIS); END;
      IF S<>0 THEN
         h:=DIPNF(G,S);
         IF DCGBopt.TraceLevel>2 THEN DIWRIT(h,VALIS); BLINES(0); END;
         IF h<>0 THEN
            IF DIPTDG(h)=0 THEN
	       IF DCGBopt.TraceLevel>1 THEN
       	          SWRITE("= branch w.o. zeros ="); nocb:=nocb+1;
		  BLINES(0); END;
	       RETURN(SIL); END;
            F:=DCGBopt.DecompProc(h,VOOF);
            IF DCGBopt.TraceLevel>3 THEN PWrite(5,F); END;
            IF RED(F)=SIL THEN
               f:=SECOND(FIRST(F));                  
               DCGBopt.UpdateProc(f,G,B);
               IF NOT(TEII(U,G)) THEN RETURN(SIL); END;
            ELSE
               SCL:=DCGBopt.BranchProc(F);
               oldG:=G; oldB:=B; GBList:=SIL;
               REPEAT
                  ADV(SCL,SC,SCL);
                  FIRST2(SC,G1,U1);
                  G:=oldG; B:=oldB;
                  WHILE G1<>SIL DO
                     ADV(G1,f,G1);
                     DCGBopt.UpdateProc(f,G,B);
                  END; (* WHILE G1... *)
                  U1:=CCONC(U1,U);
                  IF TEII(U1,G) THEN GBList:=CONC(GBList,RECGB2(G,U1,B)); END;
               UNTIL SCL=SIL;
               RETURN(GBList);
            END; (* IF RED... *)
         END; (* IF h... *)
      END; (* IF S... *)
   END; (* WHILE B... *)
   DIPIRL(G,CS);
   IF CS THEN
      IF TEII(U,G) THEN RETURN(RECGB1(G,U)); END;
      RETURN(SIL);
   ELSE
      IF DCGBopt.TraceLevel>1 THEN 
         SWRITE("= groebner base ="); BLINES(0);
         IF DCGBopt.TraceLevel>3 THEN
            t:=TIME()-T; SWRITE("Time :"); AWRITE(t); 
            PWrite(0,G); PWrite(0,U); BLINES(0);
	 END; (* IF DCGBopt... *)
      END; (* IF DCGBopt... *)
      RETURN(LIST1(LIST2(G,U)));
   END; (* IF CS... *)
END RECGB2;

PROCEDURE REC1(G,U: LIST): LIST;
VAR H,g,HTg,HTf,G1,F,GBList,f,B,SCL,SC,U1,G2: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN 
      SWRITE("R1"); BLINES(0); PWrite(1,G); PWrite(3,U); END;
   H:=SIL;
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF DIPTDG(g)=0 THEN 
         IF DCGBopt.TraceLevel>1 THEN 
	    SWRITE("= branch w.o. zeros ="); nocb:=nocb+1; BLINES(0); END;
	 RETURN(SIL); END;
      G1:=CCONC(G,H);
      F:=DCGBopt.DecompProc(g,VOOF);
      IF DCGBopt.TraceLevel>3 THEN PWrite(5,F); END;
      IF RED(F)=SIL THEN
         HTg:=DIPEVL(g);
         f:=SECOND(FIRST(F));
         HTf:=DIPEVL(f);
         IF EQUAL(HTg,HTf)=1 THEN
            H:=COMP(f,H);
         ELSE
            G:=COMP(f,G1);
            DIPIRL(G,CS);
            IF NOT(TEII(U,G)) THEN RETURN(SIL); END;
            H:=SIL;
         END; (* IF EQUAL... *)
      ELSE
         SCL:=DCGBopt.BranchProc(F);
         GBList:=SIL;
         WHILE SCL<>SIL DO
            ADV(SCL,SC,SCL);
            FIRST2(SC,g,U1);
            G2:=COMP(g,G1);
            U1:=CCONC(U1,U);
            DIPIRL(G2,CS);
            IF TEII(U1,G2) THEN GBList:=CONC(GBList,REC1(G2,U1)); END;
         END; (* WHILE SCL... *)
         RETURN(GBList);
      END; (* IF RED(F)... *)
   END; (* WHILE G... *)
   Init(H,B);
   RETURN(REC2(H,U,B));
END REC1;

PROCEDURE REC2(G,U,B: LIST): LIST;
VAR CP,g1,g2,S,h,F,oldG,oldB,SCL,SC,U1,f,GBList: LIST;
    CS: BOOLEAN;
BEGIN
   IF DCGBopt.TraceLevel>3 THEN
      SWRITE("R2"); BLINES(0); PWrite(1,G); PWrite(3,U); PPWrite(B); END;
   WHILE B<>SIL DO
      ADV(B,CP,B);
      FIRST2(CP,g1,g2);
      S:=DIPS(g1,g2);
      IF DCGBopt.TraceLevel>2 THEN DIWRIT(S,VALIS); END;
      IF S<>0 THEN
         h:=DIPNF(G,S);
         IF DCGBopt.TraceLevel>2 THEN DIWRIT(h,VALIS); BLINES(0); END;
         IF h<>0 THEN
            IF DIPTDG(h)=0 THEN
	       IF DCGBopt.TraceLevel>1 THEN
       	          SWRITE("= branch w.o. zeros ="); nocb:=nocb+1;
		  BLINES(0); END;
	       RETURN(SIL); END;
            F:=DCGBopt.DecompProc(h,VOOF);
            IF DCGBopt.TraceLevel>3 THEN PWrite(5,F); END;
            IF RED(F)=SIL THEN
               f:=SECOND(FIRST(F));                  
               DCGBopt.UpdateProc(f,G,B);
               IF NOT(TEII(U,G)) THEN RETURN(SIL); END;
            ELSE
               SCL:=DCGBopt.BranchProc(F);
               oldG:=G; oldB:=B; GBList:=SIL;
               REPEAT
                  ADV(SCL,SC,SCL);
                  FIRST2(SC,f,U1);
                  G:=oldG; B:=oldB;
                  DCGBopt.UpdateProc(f,G,B);
                  U1:=CCONC(U1,U);
                  IF TEII(U1,G) THEN GBList:=CONC(GBList,REC2(G,U1,B)); END;
               UNTIL SCL=SIL;
               RETURN(GBList);
            END; (* IF RED... *)
         END; (* IF h... *)
      END; (* IF S... *)
   END; (* WHILE B... *)
   DIPIRL(G,CS);
   IF CS THEN
      IF TEII(U,G) THEN RETURN(REC1(G,U)); END;
      RETURN(SIL);
   ELSE
      IF DCGBopt.TraceLevel>1 THEN 
         SWRITE("= groebner base ="); BLINES(0);
         IF DCGBopt.TraceLevel>3 THEN
            t:=TIME()-T; SWRITE("Time :"); AWRITE(t); 
            PWrite(0,G); PWrite(0,U); BLINES(0);
	 END; (* IF DCGBopt... *)
      END; (* IF DCGBopt... *)
      RETURN(LIST1(LIST2(G,U)));
   END; (* IF CS... *)
END REC2;

PROCEDURE TEII(U,G: LIST): BOOLEAN;
(* Test equations and inequations for inconsistence *)
VAR u: LIST;
BEGIN
   IF DCGBopt.ReduceExp=1 THEN
      WHILE U<>SIL DO
         ADV(U,u,U);
         IF DIPNF(G,u)=0 THEN 
	    IF DCGBopt.TraceLevel>1 THEN
	       SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
            RETURN(FALSE);
         END; (* IF DIPNF... *)
      END; (* WHILE U... *)
   ELSE
      WHILE U<>SIL DO
         ADV(U,u,U);
         u:=DIPEXP(u,DCGBopt.ReduceExp);
         IF DIPNF(G,u)=0 THEN 
	    IF DCGBopt.TraceLevel>1 THEN
	       SWRITE("= cancel branch ="); nocb:=nocb+1; BLINES(0); END;
            RETURN(FALSE);
         END; (* IF DIPNF... *)
      END; (* WHILE U... *)
   END; (* IF DCGBopt... *)
   RETURN(TRUE);
END TEII;

BEGIN
   SetDIPAGBStrategy(0);	(* strategy = normal *)
   IF G=SIL THEN ERROR(severe,"GB2: undefined ideal"); END;
   IF ZeroPoly(G) THEN ERROR(severe,"GB2: zero polynomial"); END; 
   T:=TIME();
   CASE DCGBopt.VarOrdOpt OF 
      1: VOOB:=1; VOOF:=0; |
      2: VOOB:=0; VOOF:=1; |
      3: VOOB:=1; VOOF:=1; 
   ELSE
      VOOB:=0; VOOF:=0;
   END; (* DCGBopt... *)
   IF VOOB=1 THEN 
      OldVarL:=VALIS;
      DIPVOPP(G,OldVarL,G,VALIS,PermV);
      invPV:=INVPERM(PermV);
   END; (* IF VOOB... *)
   GBList:=SIL; nocb:=0;
   DIPIRL(G,CS);
   IF TEII(U,G) THEN 
      CASE DCGBopt.BPNo OF
         1: GBList:=RECGB1(G,U); |
         2: GBList:=REC1(G,U);
      END; (* CASE ... *)
   END; (* IF TEII... *)
   IF VOOB=1 THEN
      VALIS:=OldVarL;
      BLINES(1); SWRITE("= changed variable order =");
      GBList:=SGBLwrtVO2(GBList,invPV);
   END; (* IF VOOB... *)
   IF DCGBopt.TraceLevel>0 THEN
      t:=TIME()-T;
      IF DCGBopt.TraceLevel>1 THEN
	 BLINES(0); SWRITE("Number of canceled branches : ");
	 AWRITE(nocb); END;
      BLINES(1); SWRITE("Time : "); AWRITE(t); SWRITE(" ms");
      SWRITE(" with program GB2 :");
      CWrite2(GBList);
   END; (* IF DCGBopt... *)
   RETURN(GBList);
END GroebnerBases2;

(* ------------------------------------------------------------------------ *)

PROCEDURE SSCO(M: LIST): LIST;
(* compute subsets and their complements *)
VAR ML,CS,f,SSL,A,SS,CO,S1,S2,ExpPol: LIST;
BEGIN
   ML:=SIL; CS:=SIL;
   WHILE M<>SIL DO
      ADV(M,ExpPol,M);
      f:=SECOND(ExpPol);
      SSL:=LIST1(LIST2(LIST1(f),CS));
      WHILE ML<>SIL DO
	 ADV(ML,A,ML);
	 FIRST2(A,SS,CO);
	 S1:=LIST2(COMP(f,SS),CO);
	 SSL:=COMP(S1,SSL);
	 S2:=LIST2(SS,COMP(f,CO));
	 SSL:=COMP(S2,SSL);
      END; (* WHILE ML... *)
   CS:=COMP(f,CS);
   ML:=SSL;
   END; (* WHILE M... *)
   RETURN(SSL);
END SSCO;

PROCEDURE EQIEQ(M: LIST): LIST;
(* compute equalities and inequalities *)
VAR ML,CS,f: LIST;
BEGIN
   M:=SortF(M);	(* sort factors into non-increasing order *)
   ML:=SIL; CS:=SIL;
   WHILE M<>SIL DO
      ADV(M,f,M);
      ML:=COMP(LIST2(f,CS),ML);
      CS:=COMP(f,CS);
   END; (* while M... *)
   RETURN(ML);
END EQIEQ;

PROCEDURE SGBLwrtVO2(GBL,invPV: LIST): LIST;
(* sort groebner bases list w.r.t. variable order *)
VAR GBLnew,GU,G,U: LIST;
BEGIN
   GBLnew:=SIL;
   WHILE GBL<>SIL DO
      ADV(GBL,GU,GBL);
      FIRST2(GU,G,U);
      G:=DILPERM(G,invPV);
      U:=DILPERM(U,invPV);
      GU:=LIST2(G,U);
      GBLnew:=COMP(GU,GBLnew);
   END;
   RETURN(GBLnew);
END SGBLwrtVO2;

PROCEDURE CWrite2(gbl: LIST);
VAR i: INTEGER;
    gb,G,U: LIST;
BEGIN
   BLINES(1); i:=1;
   WHILE gbl<>SIL DO
      ADV(gbl,gb,gbl);
      FIRST2(gb,G,U);
      AWRITE(i); SWRITE(". GB with ");
      AWRITE(LENGTH(G)); SWRITE(" equation(s)");
      BLINES(0); PWrite(0,G);
      SWRITE("   and ");
      AWRITE(LENGTH(U)); SWRITE(" inequation(s).");
      BLINES(0); PWrite(0,U);
      BLINES(1);
      i:=i+1;
   END;
END CWrite2;


(* ------------------------------------------------------------------------ *
 * 3. utilities                                                             *
 * ------------------------------------------------------------------------ *)


PROCEDURE SortF(F: LIST): LIST;
VAR Fnew, ExpPol: LIST;
BEGIN
   Fnew:=SIL;
   WHILE F<>SIL DO 	(* remove exponents *)
      ADV(F,ExpPol,F);
      Fnew:=COMP(SECOND(ExpPol),Fnew);
   END; (* WHILE F... *)
   RETURN(INV(DIPLPM(Fnew)));	(* sorting F into non-increasing order *)
END SortF;


PROCEDURE ZeroPoly(G: LIST): BOOLEAN;
(* test polynomial list G for zero-polynomial *)
VAR g: LIST;
BEGIN
   WHILE G<>SIL DO
      ADV(G,g,G);
      IF g=0 THEN RETURN(TRUE); END;
   END; (* while G... *)
   RETURN(FALSE);
END ZeroPoly;
      

PROCEDURE Init(VAR G,B: LIST); 
(* initialize critical pair list B and list
   of generating polynomials G. *)
VAR f,D: LIST; 
BEGIN
   D:=SIL; B:=SIL;
   WHILE G<>SIL DO
      ADV(G,f,G);
      DCGBopt.UpdateProc(f,D,B);
   END;
   G:=D;
END Init; 


PROCEDURE PWrite(S,P: LIST);
(* write list of polynomials *)
VAR p: LIST;
BEGIN
   IF S=1 THEN SWRITE(" List of polynomials:"); END;
   IF (S=2) OR (S=5) THEN SWRITE(" List of factors:"); END;
   IF S=3 THEN SWRITE(" List of inequations:"); END;
   IF S=4 THEN SWRITE(" List of branches to compare:"); END;
   BLINES(0);
   WHILE P<>SIL DO
      ADV(P,p,P);
      IF S=5 THEN p:=SECOND(p); END;
      SWRITE(" ");
      DIWRIT(p,VALIS);
      BLINES(0);
   END;
   BLINES(0);
END PWrite;


PROCEDURE PPWrite(PP: LIST);
(* write list of polynomial pairs *)
VAR CP,g1,g2: LIST;
BEGIN
   SWRITE(" List of critical pairs:");
   BLINES(0);
   WHILE PP<>SIL DO
      ADV(PP,CP,PP);
      FIRST2(CP,g1,g2);
      SWRITE(" < "); DIWRIT(g1,VALIS); SWRITE(" , ");
      DIWRIT(g2,VALIS); SWRITE(" >");
      BLINES(0);
   END;
   BLINES(0);
END PPWrite;

(* ------------------------------------------------------------------------ *)

BEGIN
 
   DCGBopt.TraceLevel:=0;
   DCGBopt.DecompProc:=DIPFAC; DCGBopt.DPNo:=1;
   DCGBopt.UpdateProc:=UPDATE; DCGBopt.UPNo:=1;
   DCGBopt.VarOrdOpt :=0;
   DCGBopt.FacSugar  :=0;
   DCGBopt.ReduceExp :=1;
   DCGBopt.BranchProc:=SSCO;   DCGBopt.BPNo:=1;

END DIPDCGB.

(* -EOF- *)
