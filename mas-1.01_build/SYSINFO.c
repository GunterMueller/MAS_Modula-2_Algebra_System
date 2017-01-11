#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SYSINFO
#include "SYSINFO.h"
#endif

CHAR SYSINFO_rcsid [] = "$Id: SYSINFO.md,v 1.1 1994/11/28 20:32:52 dolzmann Exp $";
CHAR SYSINFO_copyright [] = "Copyright (c) 1994 Universitaet Passau";
BOOLEAN SYSINFO_Cells;

static CHAR rcsidi [] = "$Id: SYSINFO.mi,v 1.1 1994/11/28 20:32:53 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";


void SYSINFO_SysInfoStart
# ifdef __STDC__
(SYSINFO_SYSINFO *s)
# else
(s)
SYSINFO_SYSINFO *s;
# endif
{
  {
    register SYSINFO_SYSINFO *W_1 = s;

    W_1->Time = MASSTOR_TIME();
    W_1->GarbageCollections = MASSTOR_GCC;
    W_1->ReclaimedCells = MASSTOR_GCCC;
    if (SYSINFO_Cells) {
      W_1->UsedCells = MASSTOR_CELLS();
    }
    W_1->GarbageCollectionTime = MASSTOR_TAU;
  }
}

void SYSINFO_SysInfoStop
# ifdef __STDC__
(SYSINFO_SYSINFO *s)
# else
(s)
SYSINFO_SYSINFO *s;
# endif
{
  {
    register SYSINFO_SYSINFO *W_2 = s;

    W_2->Time = MASSTOR_TIME() - W_2->Time;
    W_2->GarbageCollections = MASSTOR_GCC - W_2->GarbageCollections;
    W_2->ReclaimedCells = MASSTOR_GCCC - W_2->ReclaimedCells;
    if (SYSINFO_Cells) {
      W_2->UsedCells = MASSTOR_CELLS() - W_2->UsedCells;
    }
    W_2->GarbageCollectionTime = MASSTOR_TAU - W_2->GarbageCollectionTime;
  }
}

void SYSINFO_SysInfoSum
# ifdef __STDC__
(SYSINFO_SYSINFO a, SYSINFO_SYSINFO b, SYSINFO_SYSINFO *s)
# else
(a, b, s)
SYSINFO_SYSINFO a, b;
SYSINFO_SYSINFO *s;
# endif
{
  {
    register SYSINFO_SYSINFO *W_3 = s;

    W_3->Time = a.Time + b.Time;
    W_3->GarbageCollections = a.GarbageCollections + b.GarbageCollections;
    W_3->ReclaimedCells = a.ReclaimedCells + b.ReclaimedCells;
    if (SYSINFO_Cells) {
      W_3->UsedCells = a.UsedCells + b.UsedCells;
    }
    W_3->GarbageCollectionTime = a.GarbageCollectionTime + b.GarbageCollectionTime;
  }
}

void SYSINFO_SysInfoWrite
# ifdef __STDC__
(SYSINFO_SYSINFO s)
# else
(s)
SYSINFO_SYSINFO s;
# endif
{
  {
    register SYSINFO_SYSINFO *W_4 = &s;

    MASBIOS_SWRITE("SysInfo: Time: ", 15L);
    SACLIST_AWRITE(W_4->Time);
    if (W_4->GarbageCollections > 0) {
      MASBIOS_SWRITE(" ms plus ", 9L);
      SACLIST_AWRITE(W_4->GarbageCollectionTime);
      MASBIOS_SWRITE(" ms garbage collection time. ", 29L);
    } else {
      MASBIOS_SWRITE(" ms.", 4L);
    }
    MASBIOS_BLINES(0);
    if (SYSINFO_Cells) {
      MASBIOS_SWRITE("         ", 9L);
      MASBIOS_SWRITE("Cells: ", 7L);
      SACLIST_AWRITE(W_4->UsedCells);
      MASBIOS_SWRITE(" cells used of ", 15L);
      SACLIST_AWRITE(MASSTOR_NU);
      MASBIOS_SWRITE(" cells.", 7L);
      MASBIOS_BLINES(0);
    }
    if (W_4->GarbageCollections > 0) {
      MASBIOS_SWRITE("         ", 9L);
      MASBIOS_SWRITE("GC: ", 4L);
      SACLIST_AWRITE(W_4->ReclaimedCells);
      MASBIOS_SWRITE(" cells reclaimed in ", 20L);
      SACLIST_AWRITE(W_4->GarbageCollectionTime);
      MASBIOS_SWRITE(" ms with ", 9L);
      SACLIST_AWRITE(W_4->GarbageCollections);
      if (W_4->GarbageCollections > 1) {
        MASBIOS_SWRITE(" gc's.", 6L);
      } else {
        MASBIOS_SWRITE(" gc.", 4L);
      }
      MASBIOS_BLINES(0);
    }
  }
}

void BEGIN_SYSINFO()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

    SYSINFO_Cells = FALSE;
  }
}
