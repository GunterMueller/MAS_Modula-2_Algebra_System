#define DEFINITION_DIPDCIB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR DIPDCIB_rcsidi[];
extern CHAR DIPDCIB_copyrighti[];
extern void DIPDCIB_SetDCIBopt ARGS((MASSTOR_LIST options));
extern void DIPDCIB_SetDCIBTraceLevel ARGS((INTEGER TL));
extern void DIPDCIB_SetDCIBDecomp ARGS((INTEGER DCP));
extern void DIPDCIB_SetDCIBVarOrdOpt ARGS((INTEGER VOO));
extern void DIPDCIB_SetDCIBdepth ARGS((INTEGER d));
extern MASSTOR_LIST DIPDCIB_InvolutiveBases ARGS((MASSTOR_LIST G, MASSTOR_LIST V));
extern INTEGER DIPDCIB_DILNFJ ARGS((MASSTOR_LIST H, MASSTOR_LIST G));
extern void DIPDCIB_IBLWR ARGS((MASSTOR_LIST PP, MASSTOR_LIST V));
extern void DIPDCIB_DecCounter ARGS((MASSTOR_LIST *counter, INTEGER *length_of_counter));
extern void DIPDCIB_IncCounter ARGS((MASSTOR_LIST *counter, INTEGER *loc, INTEGER add));
extern void DIPDCIB_CounterWR ARGS((MASSTOR_LIST counter));
extern void BEGIN_DIPDCIB();
