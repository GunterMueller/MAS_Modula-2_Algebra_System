#define DEFINITION_MASPARSE

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASPARSE_rcsid[];
extern CHAR MASPARSE_copyright[];
extern MASSTOR_LIST MASPARSE_Parse ARGS(());
extern void MASPARSE_SwitchParse ARGS((BOOLEAN g));
extern void BEGIN_MASPARSE();
