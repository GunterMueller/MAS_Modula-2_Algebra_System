#define DEFINITION_SACEXT7

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACEXT7_rcsid[];
extern CHAR SACEXT7_copyright[];
extern MASSTOR_LIST SACEXT7_IPRRRI ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST B, MASSTOR_LIST I, MASSTOR_LIST SL1, MASSTOR_LIST TL1));
extern MASSTOR_LIST SACEXT7_IPSIFI ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST I));
extern MASSTOR_LIST SACEXT7_ISFPIR ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST I, MASSTOR_LIST KL));
extern MASSTOR_LIST SACEXT7_IUPVOI ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST I));
extern void BEGIN_SACEXT7();
