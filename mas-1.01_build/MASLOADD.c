#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPROOT
#include "DIPROOT.h"
#endif

#ifndef DEFINITION_DIPDEC0
#include "DIPDEC0.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

#ifndef DEFINITION_DIPIDEAL
#include "DIPIDEAL.h"
#endif

#ifndef DEFINITION_MASUGB
#include "MASUGB.h"
#endif

#ifndef DEFINITION_DIPIDGB
#include "DIPIDGB.h"
#endif

#ifndef DEFINITION_MASLOADD
#include "MASLOADD.h"
#endif

CHAR MASLOADD_rcsid [] = "$Id: MASLOADD.md,v 1.1 1992/01/22 15:11:51 kredel Exp $";
CHAR MASLOADD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASLOADD.mi,v 1.4 1993/05/11 10:56:34 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void ZSET ARGS((MASSTOR_LIST P, MASSTOR_LIST e));
static void DIM ARGS((MASSTOR_LIST P));
static void DEC0 ARGS((MASSTOR_LIST P));
static void DECA ARGS((MASSTOR_LIST P));


void MASLOADD_InitExternalsD
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledp1v3(DIPDIM_DILDIM, "DILDIM", 6L);
  MASLISPU_Compiledp4(DIPDIM_DIDIMWR, "DIDIMWR", 7L);
  MASLISPU_Compiledp1(DIM, "DIMENSION", 9L);
  MASLISPU_Compiledf2(DIPDEC0_DIRPDA, "DIRPDA", 6L);
  MASLISPU_Compiledf2(DIPDEC0_DIRLPD, "DIRLPD", 6L);
  MASLISPU_Compiledp3(DIPDEC0_DIRLPW, "DIRLPW", 6L);
  MASLISPU_Compiledp1(DECA, "DECOMP0A", 8L);
  MASLISPU_Compiledp1(DEC0, "DECOMP0", 7L);
  MASLISPU_Compiledf2(DIPIDEAL_DIRLCT, "DIRLCT", 6L);
  MASLISPU_Compiledf3(DIPIDEAL_DIRLIP, "DIRLIP", 6L);
  MASLISPU_Compiledp2(ZSET, "ZSET", 4L);
  MASLISPU_Compiledp2(ZSET, "ROOTS", 5L);
  MASLISPU_Compiledp3(DIPROOT_GBZSET, "GBZSET", 6L);
  MASLISPU_Compiledp0(MASUGB_UGBBIN, "UGBBIN", 6L);
  MASLISPU_Compiledp0(MASUGB_UGBBIN, "UGBIN", 5L);
  MASLISPU_Compiledf2(DIPIDGB_DIIPSPOL, "DIIPSPOL", 8L);
  MASLISPU_Compiledf2(DIPIDGB_DIIPGPOL, "DIIPGPOL", 8L);
  MASLISPU_Compiledf3(DIPIDGB_DIIPDNF, "DIIPDNF", 7L);
  MASLISPU_Compiledf3(DIPIDGB_DIIPENF, "DIIPENF", 7L);
  MASLISPU_Compiledf1(DIPIDGB_DIIPCPLMS1, "DIIPCPLMS1", 10L);
  MASLISPU_Compiledf1(DIPIDGB_DIIPELIMDGB, "DIIPELIMDGB", 11L);
  MASLISPU_Compiledf1(DIPIDGB_DIIPREDDGB, "DIIPREDDGB", 10L);
  MASLISPU_Compiledf2(DIPIDGB_DIIPLM1, "DIIPLM1", 7L);
  MASLISPU_Compiledf3(DIPIDGB_DIIPTDR, "DIIPTDR", 7L);
  MASLISPU_Compiledf2(DIPIDGB_DIIPDGB, "DIIPDGB", 7L);
  MASLISPU_Compiledf2(DIPIDGB_DIIPEGB, "DIIPEGB", 7L);
}

static void ZSET
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST e)
# else
(P, e)
MASSTOR_LIST P, e;
# endif
{
  DIPROOT_GBZSET(DIPC_VALIS, P, e);
}

static void DIM
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST DL, S, M;

  DIPDIM_DILDIM(P, &DL, &S, &M);
  DIPDIM_DIDIMWR(DL, S, M, DIPC_VALIS);
}

static void DEC0
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST L;

  L = DIPDEC0_DIRLPD(P, DIPC_VALIS);
  DIPDEC0_DIRLPW(P, DIPC_VALIS, L);
}

static void DECA
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST L;

  L = DIPDEC0_DIRPDA(P, DIPC_VALIS);
  DIPDEC0_DIRLPW(P, DIPC_VALIS, L);
}

void BEGIN_MASLOADD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_DIPC();
    BEGIN_DIPROOT();
    BEGIN_DIPDEC0();
    BEGIN_DIPDIM();
    BEGIN_DIPIDEAL();
    BEGIN_MASUGB();
    BEGIN_DIPIDGB();

  }
}
