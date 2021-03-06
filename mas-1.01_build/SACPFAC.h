#define DEFINITION_SACPFAC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACPFAC_rcsid[];
extern CHAR SACPFAC_copyright[];
extern void SACPFAC_IPCEVP ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_1_A, MASSTOR_LIST *B, MASSTOR_LIST *L));
extern void SACPFAC_IPFAC ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_2_A, MASSTOR_LIST *SL, MASSTOR_LIST *CL, MASSTOR_LIST *L));
extern MASSTOR_LIST SACPFAC_IPGFCB ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_3_A));
extern void SACPFAC_IPIQH ARGS((MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST C, MASSTOR_LIST *C_4_A, MASSTOR_LIST *B));
extern MASSTOR_LIST SACPFAC_ISFPF ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_5_A));
extern void SACPFAC_MIPISE ARGS((MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C_6_A, MASSTOR_LIST B, MASSTOR_LIST S, MASSTOR_LIST T, MASSTOR_LIST C, MASSTOR_LIST *U, MASSTOR_LIST *V));
extern void SACPFAC_MPIQH ARGS((MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST DP, MASSTOR_LIST C, MASSTOR_LIST *C_7_A, MASSTOR_LIST *B));
extern MASSTOR_LIST SACPFAC_MPIQHL ARGS((MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST F, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C));
extern void SACPFAC_MPIQHS ARGS((MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST SL, MASSTOR_LIST NL, MASSTOR_LIST C, MASSTOR_LIST *C_8_A, MASSTOR_LIST *B, MASSTOR_LIST *S, MASSTOR_LIST *T, MASSTOR_LIST *DP));
extern void BEGIN_SACPFAC();
