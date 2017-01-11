#define DEFINITION_MASCONF

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

extern CHAR MASCONF_rcsid[];
extern CHAR MASCONF_copyright[];
extern MASELEM_GAMMAINT MASCONF_KBCell;
extern struct MASCONF_1 {
    CHAR A[255 + 1];
} MASCONF_InitName;
extern struct MASCONF_2 {
    CHAR A[255 + 1];
} MASCONF_FileName;
extern struct MASCONF_3 {
    CHAR A[255 + 1];
} MASCONF_OutFileName;
extern struct MASCONF_4 {
    CHAR A[1002 + 1];
} MASCONF_InitialCommand;
extern BOOLEAN MASCONF_ExitAfterFiles;
extern BOOLEAN MASCONF_ExitOnError;
extern void BEGIN_MASCONF();
