#define DEFINITION_SACUPFAC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACUPFAC_rcsid[];
extern CHAR SACUPFAC_copyright[];
extern MASSTOR_LIST SACUPFAC_IPFLC ARGS((MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST C_1_A, MASSTOR_LIST L, MASSTOR_LIST D));
extern void SACUPFAC_IUPFAC ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST *SL, MASSTOR_LIST *CL, MASSTOR_LIST *L));
extern void SACUPFAC_IUPFDS ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST *PL, MASSTOR_LIST *F, MASSTOR_LIST *C));
extern void SACUPFAC_IUPQH ARGS((MASSTOR_LIST PL, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST C, MASSTOR_LIST *C_4_A, MASSTOR_LIST *B));
extern MASSTOR_LIST SACUPFAC_IUPQHL ARGS((MASSTOR_LIST PL, MASSTOR_LIST F, MASSTOR_LIST M, MASSTOR_LIST C));
extern MASSTOR_LIST SACUPFAC_IUSFPF ARGS((MASSTOR_LIST C_5_A));
extern void BEGIN_SACUPFAC();
