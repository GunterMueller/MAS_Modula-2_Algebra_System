#define DEFINITION_DIPCJ

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

extern CHAR DIPCJ_rcsid[];
extern CHAR DIPCJ_copyright[];
extern MASSTOR_LIST DIPCJ_ADDTDG ARGS((MASSTOR_LIST deg, MASSTOR_LIST P));
extern void DIPCJ_ADVTDG ARGS((MASSTOR_LIST P, MASSTOR_LIST *p, MASSTOR_LIST *PP));
extern void DIPCJ_DILEBBS ARGS((MASSTOR_LIST C_1_A));
extern void DIPCJ_DILBBS ARGS((MASSTOR_LIST C_2_A));
extern MASSTOR_LIST DIPCJ_DILEP2P ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPCJ_DILATDG ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPCJ_DILTDG ARGS((MASSTOR_LIST C_3_A));
extern MASSTOR_LIST DIPCJ_DIPCLP ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPCJ_DIPCLT ARGS((MASSTOR_LIST P));
extern void DIPCJ_DIPFIRST ARGS((MASSTOR_LIST P, BOOLEAN extended, MASSTOR_LIST *pp, MASSTOR_LIST *PP));
extern void DIPCJ_DIPSSM ARGS((MASSTOR_LIST P, BOOLEAN extended, MASSTOR_LIST *pp, MASSTOR_LIST *PP));
extern MASSTOR_LIST DIPCJ_DILCAN ARGS((MASSTOR_LIST P, MASLISPU_PROCF1 F));
extern MASSTOR_LIST DIPCJ_DIILPP ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPCJ_DIRPMV ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPCJ_EVDIF2 ARGS((MASSTOR_LIST U, MASSTOR_LIST V));
extern MASSTOR_LIST DIPCJ_EVMTJ ARGS((MASSTOR_LIST U, MASSTOR_LIST V));
extern MASSTOR_LIST DIPCJ_DIPNML ARGS((MASSTOR_LIST G));
extern MASSTOR_LIST DIPCJ_DIPPGL2 ARGS((MASSTOR_LIST F, MASSTOR_LIST V, MASSTOR_LIST LL));
extern MASSTOR_LIST DIPCJ_DIPPGL3 ARGS((MASSTOR_LIST F, MASSTOR_LIST V, MASSTOR_LIST LL));
extern MASSTOR_LIST DIPCJ_DIPPGL ARGS((MASSTOR_LIST V));
extern MASSTOR_LIST DIPCJ_DIPVL ARGS((MASSTOR_LIST V));
extern void BEGIN_DIPCJ();
