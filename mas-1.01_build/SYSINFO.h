#define DEFINITION_SYSINFO

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

typedef struct SYSINFO_1 {
    MASELEM_GAMMAINT GarbageCollections;
    MASELEM_GAMMAINT ReclaimedCells;
    MASELEM_GAMMAINT Time;
    MASELEM_GAMMAINT UsedCells;
    MASELEM_GAMMAINT GarbageCollectionTime;
} SYSINFO_SYSINFO;
extern CHAR SYSINFO_rcsid[];
extern CHAR SYSINFO_copyright[];
extern BOOLEAN SYSINFO_Cells;
extern void SYSINFO_SysInfoStart ARGS((SYSINFO_SYSINFO *s));
extern void SYSINFO_SysInfoStop ARGS((SYSINFO_SYSINFO *s));
extern void SYSINFO_SysInfoSum ARGS((SYSINFO_SYSINFO a, SYSINFO_SYSINFO b, SYSINFO_SYSINFO *s));
extern void SYSINFO_SysInfoWrite ARGS((SYSINFO_SYSINFO s));
extern void BEGIN_SYSINFO();
