#define DEFINITION_ADTOOLS

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR ADTOOLS_rcsid[];
extern CHAR ADTOOLS_copyright[];
extern MASSTOR_LIST ADTOOLS_ADRFFADIP ARGS((MASSTOR_LIST adip));
extern MASSTOR_LIST ADTOOLS_ADDDFSTR ARGS((CHAR s[], LONGCARD ));
extern MASSTOR_LIST ADTOOLS_ADCAST ARGS((MASSTOR_LIST e, MASSTOR_LIST dd));
extern MASSTOR_LIST ADTOOLS_ADRMDD ARGS((MASSTOR_LIST e));
extern void ADTOOLS_AdLoadConvFunc ARGS(());
extern MASSTOR_LIST ADTOOLS_RFDDFIPDD ARGS((MASSTOR_LIST ipdd));
extern MASSTOR_LIST ADTOOLS_IPDDCMP ARGS((MASSTOR_LIST vlist));
extern MASSTOR_LIST ADTOOLS_IPDECMP ARGS((MASSTOR_LIST e, MASSTOR_LIST vlist));
extern MASSTOR_LIST ADTOOLS_INTDDCMP ARGS(());
extern void ADTOOLS_IPDDADV ARGS((MASSTOR_LIST p, MASSTOR_LIST *q, MASSTOR_LIST *r, MASSTOR_LIST *vl));
extern void ADTOOLS_RFDDADV ARGS((MASSTOR_LIST e, MASSTOR_LIST *rat, MASSTOR_LIST *vl));
extern void BEGIN_ADTOOLS();
