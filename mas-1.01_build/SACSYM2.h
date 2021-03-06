#define DEFINITION_SACSYM2

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACSYM2_rcsid[];
extern CHAR SACSYM2_copyright[];
extern MASSTOR_LIST SACSYM2_STBAL ARGS((MASSTOR_LIST L, MASSTOR_LIST n));
extern INTEGER SACSYM2_STBALS ARGS((MASSTOR_LIST C_1_A[], LONGCARD , INTEGER l, INTEGER r));
extern void SACSYM2_STNLST ARGS((MASSTOR_LIST T, MASSTOR_LIST *L, MASSTOR_LIST *n));
extern void SACSYM2_SSYTBAL ARGS(());
extern void BEGIN_SACSYM2();
