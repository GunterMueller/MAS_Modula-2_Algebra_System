#define DEFINITION_DIPDCGB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

extern CHAR DIPDCGB_rcsid[];
extern CHAR DIPDCGB_copyright[];
extern void DIPDCGB_SetTraceLevel ARGS((INTEGER TL));
extern void DIPDCGB_SetDecompProc ARGS((INTEGER DCP));
extern void DIPDCGB_SetUpdateProc ARGS((INTEGER UP));
extern void DIPDCGB_SetVarOrdOpt ARGS((INTEGER VOO));
extern void DIPDCGB_SetFacSugar ARGS((INTEGER FS));
extern void DIPDCGB_SetReduceExp ARGS((INTEGER RE));
extern void DIPDCGB_SetBranchProc ARGS((INTEGER BP));
extern void DIPDCGB_SetDCGBopt ARGS((MASSTOR_LIST options));
extern void DIPDCGB_WriteDCGBopt ARGS(());
extern MASSTOR_LIST DIPDCGB_GroebnerBases1 ARGS((MASSTOR_LIST G));
extern MASSTOR_LIST DIPDCGB_GroebnerBases2 ARGS((MASSTOR_LIST G, MASSTOR_LIST U));
extern void BEGIN_DIPDCGB();
