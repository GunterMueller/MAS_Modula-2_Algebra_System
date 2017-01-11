#define DEFINITION_RQEPRRC

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR RQEPRRC_rcsid[];
extern CHAR RQEPRRC_copyright[];
typedef struct RQEPRRC_1 {
    INTEGER TraceLevel;
    BOOLEAN DimensionZeroOnly;
} RQEPRRC_RQEOPTIONS;
extern RQEPRRC_RQEOPTIONS RQEPRRC_RqeOpt;
extern struct RQEPRRC_2 {
    MASSTOR_LIST AllVars;
    MASSTOR_LIST BoundVars;
    MASSTOR_LIST FreeVars;
    MASSTOR_LIST Permutation;
} RQEPRRC_PolFmt;
extern MASSTOR_LIST RQEPRRC_RQEQE ARGS((MASSTOR_LIST phi));
extern void RQEPRRC_RQEOPTWR ARGS(());
extern MASSTOR_LIST RQEPRRC_RQEOPTSET ARGS((MASSTOR_LIST opt));
extern void BEGIN_RQEPRRC();
