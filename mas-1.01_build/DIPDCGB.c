#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPDCGB
#include "DIPDCGB.h"
#endif

CHAR DIPDCGB_rcsid [] = "$Id: DIPDCGB.md,v 1.3 1994/11/28 20:52:49 dolzmann Exp $";
CHAR DIPDCGB_copyright [] = "Copyright (c) 1989 - 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPDCGB.mi,v 1.3 1994/11/28 20:52:53 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1994 Universitaet Passau";
static struct S_1 {
    INTEGER TraceLevel;
    MASLISPU_PROCF2 DecompProc;
    INTEGER DPNo;
    MASLISPU_PROCP1V2 UpdateProc;
    INTEGER UPNo;
    INTEGER VarOrdOpt;
    INTEGER FacSugar;
    INTEGER ReduceExp;
    MASLISPU_PROCF1 BranchProc;
    INTEGER BPNo;
} DCGBopt;
static MASSTOR_LIST C_78_RECGB1 ARGS((MASSTOR_LIST G, MASSTOR_LIST Fcmp));
static MASSTOR_LIST C_79_RECGB2 ARGS((MASSTOR_LIST G, MASSTOR_LIST B, MASSTOR_LIST Fcmp));
static MASSTOR_LIST newFactors ARGS((MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp));
static MASSTOR_LIST C_80_REC1 ARGS((MASSTOR_LIST G, MASSTOR_LIST Fcmp1));
static MASSTOR_LIST C_81_REC2 ARGS((MASSTOR_LIST G, MASSTOR_LIST B, MASSTOR_LIST Fcmp2));
static MASSTOR_LIST EnewFactors ARGS((MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp));
static MASSTOR_LIST SGBLwrtVO1 ARGS((MASSTOR_LIST GBL, MASSTOR_LIST invPV));
static void CWrite1 ARGS((MASSTOR_LIST gbl));
static MASSTOR_LIST LLEDIPUNEXTEND ARGS((MASSTOR_LIST P));
static MASSTOR_LIST EDIPPOLY ARGS((MASSTOR_LIST PS));
static void EDIPIRL ARGS((MASSTOR_LIST *P, BOOLEAN *CS));
static MASSTOR_LIST RECGB1 ARGS((MASSTOR_LIST G, MASSTOR_LIST U));
static MASSTOR_LIST RECGB2 ARGS((MASSTOR_LIST G, MASSTOR_LIST U, MASSTOR_LIST B));
static MASSTOR_LIST REC1 ARGS((MASSTOR_LIST G, MASSTOR_LIST U));
static MASSTOR_LIST REC2 ARGS((MASSTOR_LIST G, MASSTOR_LIST U, MASSTOR_LIST B));
static BOOLEAN TEII ARGS((MASSTOR_LIST U, MASSTOR_LIST G));
static MASSTOR_LIST SSCO ARGS((MASSTOR_LIST M));
static MASSTOR_LIST EQIEQ ARGS((MASSTOR_LIST M));
static MASSTOR_LIST SGBLwrtVO2 ARGS((MASSTOR_LIST GBL, MASSTOR_LIST invPV));
static void CWrite2 ARGS((MASSTOR_LIST gbl));
static MASSTOR_LIST SortF ARGS((MASSTOR_LIST F));
static BOOLEAN ZeroPoly ARGS((MASSTOR_LIST G));
static void Init ARGS((MASSTOR_LIST *G, MASSTOR_LIST *B));
static void PWrite ARGS((MASSTOR_LIST S, MASSTOR_LIST P));
static void PPWrite ARGS((MASSTOR_LIST PP));

static MASSTOR_LIST *G_1_VOOF;
static MASSTOR_LIST *G_2_t;
static MASSTOR_LIST *G_3_T;
static INTEGER *G_4_nocb;
static MASSTOR_LIST *G_5_VOOF;
static MASSTOR_LIST *G_6_t;
static MASSTOR_LIST *G_7_T;
static INTEGER *G_8_nocb;

void DIPDCGB_SetTraceLevel
# ifdef __STDC__
(INTEGER TL)
# else
(TL)
INTEGER TL;
# endif
{
  DCGBopt.TraceLevel = TL;
}

void DIPDCGB_SetDecompProc
# ifdef __STDC__
(INTEGER DCP)
# else
(DCP)
INTEGER DCP;
# endif
{
  switch (DCP) {
  case 1:;
    DCGBopt.DecompProc = DIPADOM_DIPFAC;
    break;
  case 2:;
    DCGBopt.DecompProc = DIPADOM_DIPSFF;
    break;
  default :
    MASERR_ERROR(MASERR_severe, "SetDecompProc: unknown DecompProc option", 40L);
    break;
  }
  DCGBopt.DPNo = DCP;
}

void DIPDCGB_SetUpdateProc
# ifdef __STDC__
(INTEGER UP)
# else
(UP)
INTEGER UP;
# endif
{
  switch (UP) {
  case 1:;
    DCGBopt.UpdateProc = DIPAGB_UPDATE;
    break;
  default :
    MASERR_ERROR(MASERR_severe, "SetUpdateProc: unknown UpdateProc option", 40L);
    break;
  }
  DCGBopt.UPNo = UP;
}

void DIPDCGB_SetVarOrdOpt
# ifdef __STDC__
(INTEGER VOO)
# else
(VOO)
INTEGER VOO;
# endif
{
  if (VOO < 0 || VOO > 3) {
    MASERR_ERROR(MASERR_severe, "SetVarOrdOpt: unknown VarOrdOpt option", 38L);
  }
  DCGBopt.VarOrdOpt = VOO;
}

void DIPDCGB_SetFacSugar
# ifdef __STDC__
(INTEGER FS)
# else
(FS)
INTEGER FS;
# endif
{
  if (FS < 0 || FS > 2) {
    MASERR_ERROR(MASERR_severe, "SetFacSugar: unknown FacSugar option", 36L);
  }
  DCGBopt.FacSugar = FS;
}

void DIPDCGB_SetReduceExp
# ifdef __STDC__
(INTEGER RE)
# else
(RE)
INTEGER RE;
# endif
{
  if (RE < 1) {
    MASERR_ERROR(MASERR_severe, "SetReduceExp: unknown ReduceExp option", 38L);
  }
  DCGBopt.ReduceExp = RE;
}

void DIPDCGB_SetBranchProc
# ifdef __STDC__
(INTEGER BP)
# else
(BP)
INTEGER BP;
# endif
{
  switch (BP) {
  case 1:;
    DCGBopt.BranchProc = SSCO;
    break;
  case 2:;
    DCGBopt.BranchProc = EQIEQ;
    break;
  default :
    MASERR_ERROR(MASERR_severe, "SetBranchProc: unknown BranchProc option", 40L);
    break;
  }
  DCGBopt.BPNo = BP;
}

void DIPDCGB_SetDCGBopt
# ifdef __STDC__
(MASSTOR_LIST options)
# else
(options)
MASSTOR_LIST options;
# endif
{
  INTEGER TL, DCP, UP, VOO, RE, FS, BP;

  if (options != MASSTOR_SIL) {
    MASSTOR_ADV(options, &TL, &options);
    DIPDCGB_SetTraceLevel(TL);
    if (options != MASSTOR_SIL) {
      MASSTOR_ADV(options, &DCP, &options);
      DIPDCGB_SetDecompProc(DCP);
      if (options != MASSTOR_SIL) {
        MASSTOR_ADV(options, &UP, &options);
        DIPDCGB_SetUpdateProc(UP);
        if (options != MASSTOR_SIL) {
          MASSTOR_ADV(options, &VOO, &options);
          DIPDCGB_SetVarOrdOpt(VOO);
          if (options != MASSTOR_SIL) {
            MASSTOR_ADV(options, &FS, &options);
            DIPDCGB_SetFacSugar(FS);
            if (options != MASSTOR_SIL) {
              MASSTOR_ADV(options, &RE, &options);
              DIPDCGB_SetReduceExp(RE);
              if (options != MASSTOR_SIL) {
                MASSTOR_ADV(options, &BP, &options);
                DIPDCGB_SetBranchProc(BP);
              }
            }
          }
        }
      }
    }
  }
}

void DIPDCGB_WriteDCGBopt
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_SWRITE("TraceLevel : ", 13L);
  SACLIST_AWRITE(DCGBopt.TraceLevel);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("DecompProc : ", 13L);
  switch (DCGBopt.DPNo) {
  case 1:;
    MASBIOS_SWRITE("DIPFAC", 6L);
    break;
  case 2:;
    MASBIOS_SWRITE("DIPSFF", 6L);
    break;
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("UpdateProc : ", 13L);
  switch (DCGBopt.UPNo) {
  case 1:;
    MASBIOS_SWRITE("UPDATE", 6L);
    break;
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("VarOrdOpt  : ", 13L);
  SACLIST_AWRITE(DCGBopt.VarOrdOpt);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("FacSugar   : ", 13L);
  SACLIST_AWRITE(DCGBopt.FacSugar);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("ReduceExp  : ", 13L);
  SACLIST_AWRITE(DCGBopt.ReduceExp);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("BranchProc : ", 13L);
  switch (DCGBopt.BPNo) {
  case 1:;
    MASBIOS_SWRITE("SSCO", 4L);
    break;
  case 2:;
    MASBIOS_SWRITE("EQIEQ", 5L);
    break;
  }
  MASBIOS_BLINES(0);
}

static MASSTOR_LIST C_78_RECGB1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST Fcmp)
# else
(G, Fcmp)
MASSTOR_LIST G, Fcmp;
# endif
{
  MASSTOR_LIST H, g, HTg, HTf, G1, F, GBList, f, B;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R1", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PWrite(4, Fcmp);
    MASBIOS_BLINES(1);
  }
  H = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPC_DIPTDG(g) == 0) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
        *G_4_nocb = *G_4_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    G1 = SACLIST_CCONC(G, H);
    F = newFactors(G1, g, Fcmp);
    if (DCGBopt.TraceLevel > 3) {
      PWrite(2, F);
    }
    if (F == MASSTOR_SIL) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= cancel branch =", 17L);
        *G_4_nocb = *G_4_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    MASSTOR_ADV(F, &f, &F);
    if (F == MASSTOR_SIL) {
      HTg = DIPC_DIPEVL(g);
      HTf = DIPC_DIPEVL(f);
      if (SACLIST_EQUAL(HTg, HTf) == 1) {
        H = MASSTOR_COMP(f, H);
      } else {
        G = MASSTOR_COMP(f, G1);
        DIPADOM_DIPIRL(&G, &CS);
        H = MASSTOR_SIL;
      }
    } else {
      GBList = MASSTOR_SIL;
      for (;;) {
        G = MASSTOR_COMP(f, G1);
        DIPADOM_DIPIRL(&G, &CS);
        GBList = SACLIST_CONC(GBList, C_78_RECGB1(G, Fcmp));
        if (F == MASSTOR_SIL) {
          goto EXIT_1;
        }
        Fcmp = MASSTOR_COMP(f, Fcmp);
        MASSTOR_ADV(F, &f, &F);
      } EXIT_1:;
      return GBList;
    }
  }
  Init(&H, &B);
  return C_79_RECGB2(H, B, Fcmp);
}

static MASSTOR_LIST C_79_RECGB2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST B, MASSTOR_LIST Fcmp)
# else
(G, B, Fcmp)
MASSTOR_LIST G, B, Fcmp;
# endif
{
  MASSTOR_LIST CP, g1, g2, S, h, F, oldG, oldB, f, GBList;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R2", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PPWrite(B);
    PWrite(4, Fcmp);
    MASBIOS_BLINES(1);
  }
  while (B != MASSTOR_SIL) {
    MASSTOR_ADV(B, &CP, &B);
    SACLIST_FIRST2(CP, &g1, &g2);
    S = DIPADOM_DIPS(g1, g2);
    if (DCGBopt.TraceLevel > 2) {
      DIPADOM_DIWRIT(S, DIPC_VALIS);
    }
    if (S != 0) {
      h = DIPADOM_DIPNF(G, S);
      if (DCGBopt.TraceLevel > 2) {
        DIPADOM_DIWRIT(h, DIPC_VALIS);
        MASBIOS_BLINES(0);
      }
      if (h != 0) {
        if (DIPC_DIPTDG(h) == 0) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
            *G_4_nocb = *G_4_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        F = newFactors(G, h, Fcmp);
        if (DCGBopt.TraceLevel > 3) {
          PWrite(2, F);
        }
        if (F == MASSTOR_SIL) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= cancel branch =", 17L);
            *G_4_nocb = *G_4_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        MASSTOR_ADV(F, &f, &F);
        if (F == MASSTOR_SIL) {
          (*DCGBopt.UpdateProc)(f, &G, &B);
        } else {
          GBList = MASSTOR_SIL;
          oldG = G;
          oldB = B;
          for (;;) {
            G = oldG;
            B = oldB;
            (*DCGBopt.UpdateProc)(f, &G, &B);
            GBList = SACLIST_CONC(GBList, C_79_RECGB2(G, B, Fcmp));
            if (F == MASSTOR_SIL) {
              goto EXIT_2;
            }
            Fcmp = MASSTOR_COMP(f, Fcmp);
            MASSTOR_ADV(F, &f, &F);
          } EXIT_2:;
          return GBList;
        }
      }
    } else {
      if (DCGBopt.TraceLevel > 2) {
        MASBIOS_BLINES(0);
      }
    }
  }
  DIPADOM_DIPIRL(&G, &CS);
  if (CS) {
    return C_78_RECGB1(G, Fcmp);
  } else {
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_SWRITE("= groebner base =", 17L);
      MASBIOS_BLINES(0);
      if (DCGBopt.TraceLevel > 3) {
        *G_2_t = MASSTOR_TIME() - *G_3_T;
        MASBIOS_SWRITE("Time :", 6L);
        SACLIST_AWRITE(*G_2_t);
        PWrite(0, G);
        MASBIOS_BLINES(0);
      }
    }
    return MASSTOR_LIST1(G);
  }
}

static MASSTOR_LIST newFactors
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp)
# else
(G, h, Fcmp)
MASSTOR_LIST G, h, Fcmp;
# endif
{
  MASSTOR_LIST Fnew, F, ExpPol, hi, FL, g, G1;

  Fnew = MASSTOR_SIL;
  F = (*DCGBopt.DecompProc)(h, *G_1_VOOF);
  F = SortF(F);
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &hi, &F);
    G1 = MASSTOR_COMP(hi, G);
    FL = Fcmp;
    for (;;) {
      if (FL == MASSTOR_SIL) {
        Fnew = MASSTOR_COMP(hi, Fnew);
        Fcmp = MASSTOR_COMP(hi, Fcmp);
        goto EXIT_3;
      }
      MASSTOR_ADV(FL, &g, &FL);
      if (DIPADOM_DIPNF(G1, g) == 0) {
        if (DCGBopt.TraceLevel > 1) {
          MASBIOS_SWRITE("= cancel factor =", 17L);
          *G_4_nocb = *G_4_nocb + 1;
          MASBIOS_BLINES(0);
        }
        goto EXIT_3;
      }
    } EXIT_3:;
  }
  return MASSTOR_INV(Fnew);
}

static MASSTOR_LIST C_80_REC1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST Fcmp1)
# else
(G, Fcmp1)
MASSTOR_LIST G, Fcmp1;
# endif
{
  MASSTOR_LIST H, g, h, HTg, HTf, G1, F, GBList, f, B;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R1", 2L);
    MASBIOS_BLINES(0);
    DIPAGB_LEDIPWRITE(G);
    PWrite(4, Fcmp1);
    MASBIOS_BLINES(1);
  }
  H = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPC_DIPTDG(EDIPPOLY(g)) == 0) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
        *G_4_nocb = *G_4_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    G1 = SACLIST_CCONC(G, H);
    F = EnewFactors(G1, g, Fcmp1);
    if (DCGBopt.TraceLevel > 3) {
      MASBIOS_SWRITE("F = ", 4L);
      MASBIOS_BLINES(0);
      DIPAGB_LEDIPWRITE(F);
    }
    if (F == MASSTOR_SIL) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= cancel branch =", 17L);
        *G_4_nocb = *G_4_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    MASSTOR_ADV(F, &f, &F);
    if (F == MASSTOR_SIL) {
      HTg = DIPAGB_EDIPEVL(g);
      HTf = DIPAGB_EDIPEVL(f);
      if (SACLIST_EQUAL(HTg, HTf) == 1) {
        H = MASSTOR_COMP(f, H);
      } else {
        G = MASSTOR_COMP(f, G1);
        EDIPIRL(&G, &CS);
        H = MASSTOR_SIL;
      }
    } else {
      GBList = MASSTOR_SIL;
      for (;;) {
        G = MASSTOR_COMP(f, G1);
        EDIPIRL(&G, &CS);
        GBList = SACLIST_CONC(GBList, C_80_REC1(G, Fcmp1));
        if (F == MASSTOR_SIL) {
          goto EXIT_4;
        }
        Fcmp1 = MASSTOR_COMP(EDIPPOLY(f), Fcmp1);
        MASSTOR_ADV(F, &f, &F);
      } EXIT_4:;
      return GBList;
    }
  }
  Init(&H, &B);
  return C_81_REC2(H, B, Fcmp1);
}

static MASSTOR_LIST C_81_REC2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST B, MASSTOR_LIST Fcmp2)
# else
(G, B, Fcmp2)
MASSTOR_LIST G, B, Fcmp2;
# endif
{
  MASSTOR_LIST CP, g1, g2, S, h, h1, F, oldG, oldB, f, GBList;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R2", 2L);
    MASBIOS_BLINES(0);
    DIPAGB_LEDIPWRITE(G);
    DIPAGB_LECPWRITE(B);
    PWrite(4, Fcmp2);
    MASBIOS_BLINES(1);
  }
  while (B != MASSTOR_SIL) {
    DIPAGB_ECPSELECT(B, &CP, &B);
    g1 = DIPAGB_ECPPOLY1(CP);
    g2 = DIPAGB_ECPPOLY2(CP);
    S = DIPAGB_EDIPSP(g1, g2);
    if (DCGBopt.TraceLevel > 2) {
      DIPAGB_EDIPWRITE(S);
    }
    if (MASSTOR_FIRST(S) != 0) {
      h = DIPAGB_EDIPNOR(G, S);
      if (DCGBopt.TraceLevel > 2) {
        DIPAGB_EDIPWRITE(h);
        MASBIOS_BLINES(0);
      }
      h1 = EDIPPOLY(h);
      if (h1 != 0) {
        if (DIPC_DIPTDG(h1) == 0) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
            *G_4_nocb = *G_4_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        F = EnewFactors(G, h, Fcmp2);
        if (DCGBopt.TraceLevel > 3) {
          MASBIOS_SWRITE("F = ", 4L);
          MASBIOS_BLINES(0);
          DIPAGB_LEDIPWRITE(F);
        }
        if (F == MASSTOR_SIL) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= cancel branch =", 17L);
            *G_4_nocb = *G_4_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        MASSTOR_ADV(F, &f, &F);
        if (F == MASSTOR_SIL) {
          (*DCGBopt.UpdateProc)(f, &G, &B);
        } else {
          GBList = MASSTOR_SIL;
          oldG = G;
          oldB = B;
          for (;;) {
            G = oldG;
            B = oldB;
            (*DCGBopt.UpdateProc)(f, &G, &B);
            GBList = SACLIST_CONC(GBList, C_81_REC2(G, B, Fcmp2));
            if (F == MASSTOR_SIL) {
              goto EXIT_5;
            }
            Fcmp2 = MASSTOR_COMP(EDIPPOLY(f), Fcmp2);
            MASSTOR_ADV(F, &f, &F);
          } EXIT_5:;
          return GBList;
        }
      }
    } else {
      if (DCGBopt.TraceLevel > 2) {
        MASBIOS_BLINES(0);
      }
    }
  }
  EDIPIRL(&G, &CS);
  if (CS) {
    return C_80_REC1(G, Fcmp2);
  } else {
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_SWRITE("= groebner base =", 17L);
      MASBIOS_BLINES(0);
      if (DCGBopt.TraceLevel > 3) {
        *G_2_t = MASSTOR_TIME() - *G_3_T;
        MASBIOS_SWRITE("Time :", 6L);
        SACLIST_AWRITE(*G_2_t);
        MASBIOS_BLINES(0);
        DIPAGB_LEDIPWRITE(G);
        MASBIOS_BLINES(0);
      }
    }
    return MASSTOR_LIST1(G);
  }
}

static MASSTOR_LIST EnewFactors
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp)
# else
(G, h, Fcmp)
MASSTOR_LIST G, h, Fcmp;
# endif
{
  MASSTOR_LIST Fnew, Sugar, F, ExpPol, hi, FL, g, G1, h1;

  Fnew = MASSTOR_SIL;
  SACLIST_FIRST2(h, &h1, &Sugar);
  G = DIPAGB_LEDIPUNEXTEND(G);
  F = (*DCGBopt.DecompProc)(h1, *G_1_VOOF);
  F = SortF(F);
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &hi, &F);
    G1 = MASSTOR_COMP(hi, G);
    FL = Fcmp;
    for (;;) {
      if (FL == MASSTOR_SIL) {
        Fcmp = MASSTOR_COMP(hi, Fcmp);
        switch (DCGBopt.FacSugar) {
        case 1:;
          Fnew = MASSTOR_COMP(SACLIST_LIST2(hi, SACRN_RNINT(DIPC_DIPTDG(hi))), Fnew);
          break;
        case 2:;
          Fnew = MASSTOR_COMP(SACLIST_LIST2(hi, Sugar), Fnew);
          break;
        }
        goto EXIT_6;
      }
      MASSTOR_ADV(FL, &g, &FL);
      if (DIPADOM_DIPNF(G1, g) == 0) {
        if (DCGBopt.TraceLevel > 1) {
          MASBIOS_SWRITE("= cancel factor =", 17L);
          MASBIOS_BLINES(0);
          *G_4_nocb = *G_4_nocb + 1;
        }
        goto EXIT_6;
      }
    } EXIT_6:;
  }
  return MASSTOR_INV(Fnew);
}

MASSTOR_LIST DIPDCGB_GroebnerBases1
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST GBList, T, t, OldVarL, PermV, invPV, VOOF, VOOB;
  INTEGER nocb;
  BOOLEAN CS;
  MASSTOR_LIST *L_1;
  MASSTOR_LIST *L_2;
  MASSTOR_LIST *L_3;
  INTEGER *L_4;

  L_1 = G_1_VOOF;
  G_1_VOOF = &VOOF;
  L_2 = G_2_t;
  G_2_t = &t;
  L_3 = G_3_T;
  G_3_T = &T;
  L_4 = G_4_nocb;
  G_4_nocb = &nocb;
  switch (DCGBopt.FacSugar) {
  case 0:;
    DIPAGB_SetDIPAGBStrategy(0);
    break;
  case 1:;
  case 2:;
    DIPAGB_SetDIPAGBStrategy(1);
    break;
  }
  if (G == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "GB1: undefined ideal", 20L);
  }
  if (ZeroPoly(G)) {
    MASERR_ERROR(MASERR_severe, "GB1: zero polynomial", 20L);
  }
  T = MASSTOR_TIME();
  switch (DCGBopt.VarOrdOpt) {
  case 1:;
    VOOB = 1;
    VOOF = 0;
    break;
  case 2:;
    VOOB = 0;
    VOOF = 1;
    break;
  case 3:;
    VOOB = 1;
    VOOF = 1;
    break;
  default :
    VOOB = 0;
    VOOF = 0;
    break;
  }
  if (VOOB == 1) {
    OldVarL = DIPC_VALIS;
    DIPTOO_DIPVOPP(G, OldVarL, &G, &DIPC_VALIS, &PermV);
    invPV = DIPTOO_INVPERM(PermV);
  }
  nocb = 0;
  switch (DCGBopt.FacSugar) {
  case 0:;
    DIPADOM_DIPIRL(&G, &CS);
    GBList = C_78_RECGB1(G, MASSTOR_SIL);
    break;
  case 1:;
  case 2:;
    DIPAGB_UpdateVariableWeight();
    G = DIPAGB_LDIPEXTEND(G);
    EDIPIRL(&G, &CS);
    GBList = LLEDIPUNEXTEND(C_80_REC1(G, MASSTOR_SIL));
    break;
  }
  if (VOOB == 1) {
    DIPC_VALIS = OldVarL;
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("= changed variable order =", 26L);
    GBList = SGBLwrtVO1(GBList, invPV);
  }
  if (DCGBopt.TraceLevel > 0) {
    t = MASSTOR_TIME() - T;
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Number of canceled branches/factors : ", 38L);
      SACLIST_AWRITE(nocb);
    }
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Time : ", 7L);
    SACLIST_AWRITE(t);
    MASBIOS_SWRITE(" ms", 3L);
    MASBIOS_SWRITE(" with program GB1 :", 19L);
    CWrite1(GBList);
  }
  G_1_VOOF = L_1;
  G_2_t = L_2;
  G_3_T = L_3;
  G_4_nocb = L_4;
  return GBList;
}

static MASSTOR_LIST SGBLwrtVO1
# ifdef __STDC__
(MASSTOR_LIST GBL, MASSTOR_LIST invPV)
# else
(GBL, invPV)
MASSTOR_LIST GBL, invPV;
# endif
{
  MASSTOR_LIST GBLnew, G;

  GBLnew = MASSTOR_SIL;
  while (GBL != MASSTOR_SIL) {
    MASSTOR_ADV(GBL, &G, &GBL);
    G = DIPC_DILPERM(G, invPV);
    GBLnew = MASSTOR_COMP(G, GBLnew);
  }
  return GBLnew;
}

static void CWrite1
# ifdef __STDC__
(MASSTOR_LIST gbl)
# else
(gbl)
MASSTOR_LIST gbl;
# endif
{
  INTEGER i;
  MASSTOR_LIST G;

  MASBIOS_BLINES(1);
  i = 1;
  while (gbl != MASSTOR_SIL) {
    MASSTOR_ADV(gbl, &G, &gbl);
    SACLIST_AWRITE(i);
    MASBIOS_SWRITE(". GB with ", 10L);
    SACLIST_AWRITE(MASSTOR_LENGTH(G));
    MASBIOS_SWRITE(" equation(s)", 12L);
    MASBIOS_BLINES(0);
    PWrite(0, G);
    MASBIOS_BLINES(1);
    i = i + 1;
  }
}

static MASSTOR_LIST LLEDIPUNEXTEND
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST Pnew, PL;

  Pnew = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &PL, &P);
    Pnew = MASSTOR_COMP(DIPAGB_LEDIPUNEXTEND(PL), Pnew);
  }
  return Pnew;
}

static MASSTOR_LIST EDIPPOLY
# ifdef __STDC__
(MASSTOR_LIST PS)
# else
(PS)
MASSTOR_LIST PS;
# endif
{
  MASSTOR_LIST p;

  switch (DCGBopt.FacSugar) {
  case 0:;
    p = PS;
    break;
  case 1:;
  case 2:;
    p = MASSTOR_FIRST(PS);
    break;
  }
  return p;
}

static void EDIPIRL
# ifdef __STDC__
(MASSTOR_LIST *P, BOOLEAN *CS)
# else
(P, CS)
MASSTOR_LIST *P;
BOOLEAN *CS;
# endif
{
  MASSTOR_LIST H, f, f1, HTf1, HTg1, g, g1;
  BOOLEAN NewHT;

  *CS = FALSE;
  do {
    H = MASSTOR_SIL;
    NewHT = FALSE;
    while (*P != MASSTOR_SIL) {
      MASSTOR_ADV(*P, &f, P);
      f1 = EDIPPOLY(f);
      HTf1 = DIPC_DIPEVL(f1);
      g = DIPAGB_EDIPNOR(SACLIST_CCONC(*P, H), f);
      g1 = EDIPPOLY(g);
      if (g1 != 0) {
        HTg1 = DIPC_DIPEVL(g1);
        if (SACLIST_EQUAL(HTf1, HTg1) == 1) {
          if (SACLIST_EQUAL(f1, g1) != 1) {
            *CS = TRUE;
          }
        } else {
          NewHT = TRUE;
          *CS = TRUE;
        }
        H = MASSTOR_COMP(g, H);
      }
    }
    *P = H;
  } while (!!NewHT);
}

static MASSTOR_LIST RECGB1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST U)
# else
(G, U)
MASSTOR_LIST G, U;
# endif
{
  MASSTOR_LIST H, g, HTg, HTf, G1, F, GBList, f, B, SCL, SC, U1, G2;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R1", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PWrite(3, U);
  }
  H = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPC_DIPTDG(g) == 0) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
        *G_8_nocb = *G_8_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    G1 = SACLIST_CCONC(G, H);
    F = (*DCGBopt.DecompProc)(g, *G_5_VOOF);
    if (DCGBopt.TraceLevel > 3) {
      PWrite(5, F);
    }
    if (MASSTOR_RED(F) == MASSTOR_SIL) {
      HTg = DIPC_DIPEVL(g);
      f = SACLIST_SECOND(MASSTOR_FIRST(F));
      HTf = DIPC_DIPEVL(f);
      if (SACLIST_EQUAL(HTg, HTf) == 1) {
        H = MASSTOR_COMP(f, H);
      } else {
        G = MASSTOR_COMP(f, G1);
        DIPADOM_DIPIRL(&G, &CS);
        if (!TEII(U, G)) {
          return MASSTOR_SIL;
        }
        H = MASSTOR_SIL;
      }
    } else {
      SCL = (*DCGBopt.BranchProc)(F);
      GBList = MASSTOR_SIL;
      while (SCL != MASSTOR_SIL) {
        MASSTOR_ADV(SCL, &SC, &SCL);
        SACLIST_FIRST2(SC, &G2, &U1);
        G2 = SACLIST_CCONC(G2, G1);
        U1 = SACLIST_CCONC(U1, U);
        DIPADOM_DIPIRL(&G2, &CS);
        if (TEII(U1, G2)) {
          GBList = SACLIST_CONC(GBList, RECGB1(G2, U1));
        }
      }
      return GBList;
    }
  }
  Init(&H, &B);
  return RECGB2(H, U, B);
}

static MASSTOR_LIST RECGB2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST U, MASSTOR_LIST B)
# else
(G, U, B)
MASSTOR_LIST G, U, B;
# endif
{
  MASSTOR_LIST CP, g1, g2, S, h, F, oldG, oldB, SCL, SC, G1, U1, f, GBList;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R2", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PWrite(3, U);
    PPWrite(B);
  }
  while (B != MASSTOR_SIL) {
    MASSTOR_ADV(B, &CP, &B);
    SACLIST_FIRST2(CP, &g1, &g2);
    S = DIPADOM_DIPS(g1, g2);
    if (DCGBopt.TraceLevel > 2) {
      DIPADOM_DIWRIT(S, DIPC_VALIS);
    }
    if (S != 0) {
      h = DIPADOM_DIPNF(G, S);
      if (DCGBopt.TraceLevel > 2) {
        DIPADOM_DIWRIT(h, DIPC_VALIS);
        MASBIOS_BLINES(0);
      }
      if (h != 0) {
        if (DIPC_DIPTDG(h) == 0) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
            *G_8_nocb = *G_8_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        F = (*DCGBopt.DecompProc)(h, *G_5_VOOF);
        if (DCGBopt.TraceLevel > 3) {
          PWrite(5, F);
        }
        if (MASSTOR_RED(F) == MASSTOR_SIL) {
          f = SACLIST_SECOND(MASSTOR_FIRST(F));
          (*DCGBopt.UpdateProc)(f, &G, &B);
          if (!TEII(U, G)) {
            return MASSTOR_SIL;
          }
        } else {
          SCL = (*DCGBopt.BranchProc)(F);
          oldG = G;
          oldB = B;
          GBList = MASSTOR_SIL;
          do {
            MASSTOR_ADV(SCL, &SC, &SCL);
            SACLIST_FIRST2(SC, &G1, &U1);
            G = oldG;
            B = oldB;
            while (G1 != MASSTOR_SIL) {
              MASSTOR_ADV(G1, &f, &G1);
              (*DCGBopt.UpdateProc)(f, &G, &B);
            }
            U1 = SACLIST_CCONC(U1, U);
            if (TEII(U1, G)) {
              GBList = SACLIST_CONC(GBList, RECGB2(G, U1, B));
            }
          } while (!(SCL == MASSTOR_SIL));
          return GBList;
        }
      }
    }
  }
  DIPADOM_DIPIRL(&G, &CS);
  if (CS) {
    if (TEII(U, G)) {
      return RECGB1(G, U);
    }
    return MASSTOR_SIL;
  } else {
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_SWRITE("= groebner base =", 17L);
      MASBIOS_BLINES(0);
      if (DCGBopt.TraceLevel > 3) {
        *G_6_t = MASSTOR_TIME() - *G_7_T;
        MASBIOS_SWRITE("Time :", 6L);
        SACLIST_AWRITE(*G_6_t);
        PWrite(0, G);
        PWrite(0, U);
        MASBIOS_BLINES(0);
      }
    }
    return MASSTOR_LIST1(SACLIST_LIST2(G, U));
  }
}

static MASSTOR_LIST REC1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST U)
# else
(G, U)
MASSTOR_LIST G, U;
# endif
{
  MASSTOR_LIST H, g, HTg, HTf, G1, F, GBList, f, B, SCL, SC, U1, G2;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R1", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PWrite(3, U);
  }
  H = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPC_DIPTDG(g) == 0) {
      if (DCGBopt.TraceLevel > 1) {
        MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
        *G_8_nocb = *G_8_nocb + 1;
        MASBIOS_BLINES(0);
      }
      return MASSTOR_SIL;
    }
    G1 = SACLIST_CCONC(G, H);
    F = (*DCGBopt.DecompProc)(g, *G_5_VOOF);
    if (DCGBopt.TraceLevel > 3) {
      PWrite(5, F);
    }
    if (MASSTOR_RED(F) == MASSTOR_SIL) {
      HTg = DIPC_DIPEVL(g);
      f = SACLIST_SECOND(MASSTOR_FIRST(F));
      HTf = DIPC_DIPEVL(f);
      if (SACLIST_EQUAL(HTg, HTf) == 1) {
        H = MASSTOR_COMP(f, H);
      } else {
        G = MASSTOR_COMP(f, G1);
        DIPADOM_DIPIRL(&G, &CS);
        if (!TEII(U, G)) {
          return MASSTOR_SIL;
        }
        H = MASSTOR_SIL;
      }
    } else {
      SCL = (*DCGBopt.BranchProc)(F);
      GBList = MASSTOR_SIL;
      while (SCL != MASSTOR_SIL) {
        MASSTOR_ADV(SCL, &SC, &SCL);
        SACLIST_FIRST2(SC, &g, &U1);
        G2 = MASSTOR_COMP(g, G1);
        U1 = SACLIST_CCONC(U1, U);
        DIPADOM_DIPIRL(&G2, &CS);
        if (TEII(U1, G2)) {
          GBList = SACLIST_CONC(GBList, REC1(G2, U1));
        }
      }
      return GBList;
    }
  }
  Init(&H, &B);
  return REC2(H, U, B);
}

static MASSTOR_LIST REC2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST U, MASSTOR_LIST B)
# else
(G, U, B)
MASSTOR_LIST G, U, B;
# endif
{
  MASSTOR_LIST CP, g1, g2, S, h, F, oldG, oldB, SCL, SC, U1, f, GBList;
  BOOLEAN CS;

  if (DCGBopt.TraceLevel > 3) {
    MASBIOS_SWRITE("R2", 2L);
    MASBIOS_BLINES(0);
    PWrite(1, G);
    PWrite(3, U);
    PPWrite(B);
  }
  while (B != MASSTOR_SIL) {
    MASSTOR_ADV(B, &CP, &B);
    SACLIST_FIRST2(CP, &g1, &g2);
    S = DIPADOM_DIPS(g1, g2);
    if (DCGBopt.TraceLevel > 2) {
      DIPADOM_DIWRIT(S, DIPC_VALIS);
    }
    if (S != 0) {
      h = DIPADOM_DIPNF(G, S);
      if (DCGBopt.TraceLevel > 2) {
        DIPADOM_DIWRIT(h, DIPC_VALIS);
        MASBIOS_BLINES(0);
      }
      if (h != 0) {
        if (DIPC_DIPTDG(h) == 0) {
          if (DCGBopt.TraceLevel > 1) {
            MASBIOS_SWRITE("= branch w.o. zeros =", 21L);
            *G_8_nocb = *G_8_nocb + 1;
            MASBIOS_BLINES(0);
          }
          return MASSTOR_SIL;
        }
        F = (*DCGBopt.DecompProc)(h, *G_5_VOOF);
        if (DCGBopt.TraceLevel > 3) {
          PWrite(5, F);
        }
        if (MASSTOR_RED(F) == MASSTOR_SIL) {
          f = SACLIST_SECOND(MASSTOR_FIRST(F));
          (*DCGBopt.UpdateProc)(f, &G, &B);
          if (!TEII(U, G)) {
            return MASSTOR_SIL;
          }
        } else {
          SCL = (*DCGBopt.BranchProc)(F);
          oldG = G;
          oldB = B;
          GBList = MASSTOR_SIL;
          do {
            MASSTOR_ADV(SCL, &SC, &SCL);
            SACLIST_FIRST2(SC, &f, &U1);
            G = oldG;
            B = oldB;
            (*DCGBopt.UpdateProc)(f, &G, &B);
            U1 = SACLIST_CCONC(U1, U);
            if (TEII(U1, G)) {
              GBList = SACLIST_CONC(GBList, REC2(G, U1, B));
            }
          } while (!(SCL == MASSTOR_SIL));
          return GBList;
        }
      }
    }
  }
  DIPADOM_DIPIRL(&G, &CS);
  if (CS) {
    if (TEII(U, G)) {
      return REC1(G, U);
    }
    return MASSTOR_SIL;
  } else {
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_SWRITE("= groebner base =", 17L);
      MASBIOS_BLINES(0);
      if (DCGBopt.TraceLevel > 3) {
        *G_6_t = MASSTOR_TIME() - *G_7_T;
        MASBIOS_SWRITE("Time :", 6L);
        SACLIST_AWRITE(*G_6_t);
        PWrite(0, G);
        PWrite(0, U);
        MASBIOS_BLINES(0);
      }
    }
    return MASSTOR_LIST1(SACLIST_LIST2(G, U));
  }
}

static BOOLEAN TEII
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST G)
# else
(U, G)
MASSTOR_LIST U, G;
# endif
{
  MASSTOR_LIST u;

  if (DCGBopt.ReduceExp == 1) {
    while (U != MASSTOR_SIL) {
      MASSTOR_ADV(U, &u, &U);
      if (DIPADOM_DIPNF(G, u) == 0) {
        if (DCGBopt.TraceLevel > 1) {
          MASBIOS_SWRITE("= cancel branch =", 17L);
          *G_8_nocb = *G_8_nocb + 1;
          MASBIOS_BLINES(0);
        }
        return FALSE;
      }
    }
  } else {
    while (U != MASSTOR_SIL) {
      MASSTOR_ADV(U, &u, &U);
      u = DIPADOM_DIPEXP(u, DCGBopt.ReduceExp);
      if (DIPADOM_DIPNF(G, u) == 0) {
        if (DCGBopt.TraceLevel > 1) {
          MASBIOS_SWRITE("= cancel branch =", 17L);
          *G_8_nocb = *G_8_nocb + 1;
          MASBIOS_BLINES(0);
        }
        return FALSE;
      }
    }
  }
  return TRUE;
}

MASSTOR_LIST DIPDCGB_GroebnerBases2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST U)
# else
(G, U)
MASSTOR_LIST G, U;
# endif
{
  MASSTOR_LIST GBList, T, t, OldVarL, PermV, invPV, VOOF, VOOB;
  INTEGER nocb;
  BOOLEAN CS;
  MASSTOR_LIST *L_5;
  MASSTOR_LIST *L_6;
  MASSTOR_LIST *L_7;
  INTEGER *L_8;

  L_5 = G_5_VOOF;
  G_5_VOOF = &VOOF;
  L_6 = G_6_t;
  G_6_t = &t;
  L_7 = G_7_T;
  G_7_T = &T;
  L_8 = G_8_nocb;
  G_8_nocb = &nocb;
  DIPAGB_SetDIPAGBStrategy(0);
  if (G == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "GB2: undefined ideal", 20L);
  }
  if (ZeroPoly(G)) {
    MASERR_ERROR(MASERR_severe, "GB2: zero polynomial", 20L);
  }
  T = MASSTOR_TIME();
  switch (DCGBopt.VarOrdOpt) {
  case 1:;
    VOOB = 1;
    VOOF = 0;
    break;
  case 2:;
    VOOB = 0;
    VOOF = 1;
    break;
  case 3:;
    VOOB = 1;
    VOOF = 1;
    break;
  default :
    VOOB = 0;
    VOOF = 0;
    break;
  }
  if (VOOB == 1) {
    OldVarL = DIPC_VALIS;
    DIPTOO_DIPVOPP(G, OldVarL, &G, &DIPC_VALIS, &PermV);
    invPV = DIPTOO_INVPERM(PermV);
  }
  GBList = MASSTOR_SIL;
  nocb = 0;
  DIPADOM_DIPIRL(&G, &CS);
  if (TEII(U, G)) {
    switch (DCGBopt.BPNo) {
    case 1:;
      GBList = RECGB1(G, U);
      break;
    case 2:;
      GBList = REC1(G, U);
      break;
    }
  }
  if (VOOB == 1) {
    DIPC_VALIS = OldVarL;
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("= changed variable order =", 26L);
    GBList = SGBLwrtVO2(GBList, invPV);
  }
  if (DCGBopt.TraceLevel > 0) {
    t = MASSTOR_TIME() - T;
    if (DCGBopt.TraceLevel > 1) {
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Number of canceled branches : ", 30L);
      SACLIST_AWRITE(nocb);
    }
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Time : ", 7L);
    SACLIST_AWRITE(t);
    MASBIOS_SWRITE(" ms", 3L);
    MASBIOS_SWRITE(" with program GB2 :", 19L);
    CWrite2(GBList);
  }
  G_5_VOOF = L_5;
  G_6_t = L_6;
  G_7_T = L_7;
  G_8_nocb = L_8;
  return GBList;
}

static MASSTOR_LIST SSCO
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST ML, CS, f, SSL, C_77_A, SS, CO, S1, S2, ExpPol;

  ML = MASSTOR_SIL;
  CS = MASSTOR_SIL;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &ExpPol, &M);
    f = SACLIST_SECOND(ExpPol);
    SSL = MASSTOR_LIST1(SACLIST_LIST2(MASSTOR_LIST1(f), CS));
    while (ML != MASSTOR_SIL) {
      MASSTOR_ADV(ML, &C_77_A, &ML);
      SACLIST_FIRST2(C_77_A, &SS, &CO);
      S1 = SACLIST_LIST2(MASSTOR_COMP(f, SS), CO);
      SSL = MASSTOR_COMP(S1, SSL);
      S2 = SACLIST_LIST2(SS, MASSTOR_COMP(f, CO));
      SSL = MASSTOR_COMP(S2, SSL);
    }
    CS = MASSTOR_COMP(f, CS);
    ML = SSL;
  }
  return SSL;
}

static MASSTOR_LIST EQIEQ
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST ML, CS, f;

  M = SortF(M);
  ML = MASSTOR_SIL;
  CS = MASSTOR_SIL;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &f, &M);
    ML = MASSTOR_COMP(SACLIST_LIST2(f, CS), ML);
    CS = MASSTOR_COMP(f, CS);
  }
  return ML;
}

static MASSTOR_LIST SGBLwrtVO2
# ifdef __STDC__
(MASSTOR_LIST GBL, MASSTOR_LIST invPV)
# else
(GBL, invPV)
MASSTOR_LIST GBL, invPV;
# endif
{
  MASSTOR_LIST GBLnew, GU, G, U;

  GBLnew = MASSTOR_SIL;
  while (GBL != MASSTOR_SIL) {
    MASSTOR_ADV(GBL, &GU, &GBL);
    SACLIST_FIRST2(GU, &G, &U);
    G = DIPC_DILPERM(G, invPV);
    U = DIPC_DILPERM(U, invPV);
    GU = SACLIST_LIST2(G, U);
    GBLnew = MASSTOR_COMP(GU, GBLnew);
  }
  return GBLnew;
}

static void CWrite2
# ifdef __STDC__
(MASSTOR_LIST gbl)
# else
(gbl)
MASSTOR_LIST gbl;
# endif
{
  INTEGER i;
  MASSTOR_LIST gb, G, U;

  MASBIOS_BLINES(1);
  i = 1;
  while (gbl != MASSTOR_SIL) {
    MASSTOR_ADV(gbl, &gb, &gbl);
    SACLIST_FIRST2(gb, &G, &U);
    SACLIST_AWRITE(i);
    MASBIOS_SWRITE(". GB with ", 10L);
    SACLIST_AWRITE(MASSTOR_LENGTH(G));
    MASBIOS_SWRITE(" equation(s)", 12L);
    MASBIOS_BLINES(0);
    PWrite(0, G);
    MASBIOS_SWRITE("   and ", 7L);
    SACLIST_AWRITE(MASSTOR_LENGTH(U));
    MASBIOS_SWRITE(" inequation(s).", 15L);
    MASBIOS_BLINES(0);
    PWrite(0, U);
    MASBIOS_BLINES(1);
    i = i + 1;
  }
}

static MASSTOR_LIST SortF
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST Fnew, ExpPol;

  Fnew = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    Fnew = MASSTOR_COMP(SACLIST_SECOND(ExpPol), Fnew);
  }
  return MASSTOR_INV(DIPC_DIPLPM(Fnew));
}

static BOOLEAN ZeroPoly
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST g;

  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (g == 0) {
      return TRUE;
    }
  }
  return FALSE;
}

static void Init
# ifdef __STDC__
(MASSTOR_LIST *G, MASSTOR_LIST *B)
# else
(G, B)
MASSTOR_LIST *G, *B;
# endif
{
  MASSTOR_LIST f, D;

  D = MASSTOR_SIL;
  *B = MASSTOR_SIL;
  while (*G != MASSTOR_SIL) {
    MASSTOR_ADV(*G, &f, G);
    (*DCGBopt.UpdateProc)(f, &D, B);
  }
  *G = D;
}

static void PWrite
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST P)
# else
(S, P)
MASSTOR_LIST S, P;
# endif
{
  MASSTOR_LIST p;

  if (S == 1) {
    MASBIOS_SWRITE(" List of polynomials:", 21L);
  }
  if (S == 2 || S == 5) {
    MASBIOS_SWRITE(" List of factors:", 17L);
  }
  if (S == 3) {
    MASBIOS_SWRITE(" List of inequations:", 21L);
  }
  if (S == 4) {
    MASBIOS_SWRITE(" List of branches to compare:", 29L);
  }
  MASBIOS_BLINES(0);
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    if (S == 5) {
      p = SACLIST_SECOND(p);
    }
    MASBIOS_SWRITE(" ", 1L);
    DIPADOM_DIWRIT(p, DIPC_VALIS);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(0);
}

static void PPWrite
# ifdef __STDC__
(MASSTOR_LIST PP)
# else
(PP)
MASSTOR_LIST PP;
# endif
{
  MASSTOR_LIST CP, g1, g2;

  MASBIOS_SWRITE(" List of critical pairs:", 24L);
  MASBIOS_BLINES(0);
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &CP, &PP);
    SACLIST_FIRST2(CP, &g1, &g2);
    MASBIOS_SWRITE(" < ", 3L);
    DIPADOM_DIWRIT(g1, DIPC_VALIS);
    MASBIOS_SWRITE(" , ", 3L);
    DIPADOM_DIWRIT(g2, DIPC_VALIS);
    MASBIOS_SWRITE(" >", 2L);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(0);
}

void BEGIN_DIPDCGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPADOM();
    BEGIN_DIPTOO();
    BEGIN_DIPAGB();

    DCGBopt.TraceLevel = 0;
    DCGBopt.DecompProc = DIPADOM_DIPFAC;
    DCGBopt.DPNo = 1;
    DCGBopt.UpdateProc = DIPAGB_UPDATE;
    DCGBopt.UPNo = 1;
    DCGBopt.VarOrdOpt = 0;
    DCGBopt.FacSugar = 0;
    DCGBopt.ReduceExp = 1;
    DCGBopt.BranchProc = SSCO;
    DCGBopt.BPNo = 1;
  }
}
