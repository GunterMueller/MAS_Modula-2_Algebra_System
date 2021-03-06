#define DEFINITION_MASYMDIP

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASYMDIP_rcsid[];
extern CHAR MASYMDIP_copyright[];
extern MASSTOR_LIST MASYMDIP_DIPVDEF ARGS((MASSTOR_LIST V));
extern MASSTOR_LIST MASYMDIP_DIPTODEF ARGS((MASSTOR_LIST T));
extern MASSTOR_LIST MASYMDIP_SYM2DIP ARGS((MASSTOR_LIST T));
extern MASSTOR_LIST MASYMDIP_DIP2SYM ARGS((MASSTOR_LIST D));
extern MASSTOR_LIST MASYMDIP_TVARS ARGS((MASSTOR_LIST T));
extern MASSTOR_LIST MASYMDIP_DIRPFT ARGS((MASSTOR_LIST T, MASSTOR_LIST V));
extern MASSTOR_LIST MASYMDIP_TFDIRP ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST V));
extern void MASYMDIP_InitExternalsI ARGS(());
extern void BEGIN_MASYMDIP();
