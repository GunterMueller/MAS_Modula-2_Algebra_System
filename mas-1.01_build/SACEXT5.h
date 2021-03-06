#define DEFINITION_SACEXT5

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACEXT5_rcsid[];
extern CHAR SACEXT5_copyright[];
extern MASSTOR_LIST SACEXT5_IPCSFB ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_1_A));
extern MASSTOR_LIST SACEXT5_IPDSCR ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_2_A));
extern void SACEXT5_IPLCPP ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_3_A, MASSTOR_LIST *C, MASSTOR_LIST *P));
extern MASSTOR_LIST SACEXT5_IPPSC ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACEXT5_IPSFBA ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_5_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACEXT5_ISPSFB ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_6_A));
extern void SACEXT5_IUPRC ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *R));
extern void SACEXT5_MUPRC ARGS((MASSTOR_LIST PL, MASSTOR_LIST C_8_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *RL));
extern void BEGIN_SACEXT5();
