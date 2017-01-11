#define DEFINITION_SACIPOL

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACIPOL_rcsid[];
extern CHAR SACIPOL_copyright[];
extern MASSTOR_LIST SACIPOL_IPABS ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_1_A));
extern MASSTOR_LIST SACIPOL_IPCRA ARGS((MASSTOR_LIST M, MASSTOR_LIST ML, MASSTOR_LIST MLP, MASSTOR_LIST RL, MASSTOR_LIST C_2_A, MASSTOR_LIST AL));
extern MASSTOR_LIST SACIPOL_IPDER ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_3_A, MASSTOR_LIST IL));
extern MASSTOR_LIST SACIPOL_IPDIF ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPDMV ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_5_A));
extern MASSTOR_LIST SACIPOL_IPEMV ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_6_A, MASSTOR_LIST AL));
extern MASSTOR_LIST SACIPOL_IPEVAL ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_7_A, MASSTOR_LIST IL, MASSTOR_LIST AL));
extern MASSTOR_LIST SACIPOL_IPEXP ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_8_A, MASSTOR_LIST NL));
extern MASSTOR_LIST SACIPOL_IPFCB ARGS((MASSTOR_LIST V));
extern MASSTOR_LIST SACIPOL_IPFRP ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_9_A));
extern MASSTOR_LIST SACIPOL_IPGSUB ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_10_A, MASSTOR_LIST SL, MASSTOR_LIST L));
extern MASSTOR_LIST SACIPOL_IPHDMV ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_11_A, MASSTOR_LIST KL));
extern MASSTOR_LIST SACIPOL_IPIHOM ARGS((MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_12_A));
extern MASSTOR_LIST SACIPOL_IPIP ARGS((MASSTOR_LIST RL, MASSTOR_LIST AL, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPIPR ARGS((MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_13_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPIQ ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_14_A, MASSTOR_LIST BL));
extern MASSTOR_LIST SACIPOL_IPMAXN ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_15_A));
extern MASSTOR_LIST SACIPOL_IPNEG ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_16_A));
extern MASSTOR_LIST SACIPOL_IPONE ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_17_A));
extern MASSTOR_LIST SACIPOL_IPPROD ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_18_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPPSR ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_19_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPQ ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_20_A, MASSTOR_LIST B));
extern void SACIPOL_IPQR ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_21_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R));
extern MASSTOR_LIST SACIPOL_IPRAN ARGS((MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST N));
extern void SACIPOL_IPREAD ARGS((MASSTOR_LIST *RL, MASSTOR_LIST *C_22_A, MASSTOR_LIST *V));
extern MASSTOR_LIST SACIPOL_IPSIGN ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_23_A));
extern MASSTOR_LIST SACIPOL_IPSMV ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_24_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPSUB ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_25_A, MASSTOR_LIST IL, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPSUM ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_26_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPSUMN ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_27_A));
extern MASSTOR_LIST SACIPOL_IPTPR ARGS((MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_28_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IPTRAN ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_29_A, MASSTOR_LIST T));
extern MASSTOR_LIST SACIPOL_IPTRMV ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_30_A, MASSTOR_LIST HL));
extern MASSTOR_LIST SACIPOL_IPTRUN ARGS((MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_31_A));
extern void SACIPOL_IPWRIT ARGS((MASSTOR_LIST RL, MASSTOR_LIST C_32_A, MASSTOR_LIST V));
extern MASSTOR_LIST SACIPOL_IUPBEI ARGS((MASSTOR_LIST C_33_A, MASSTOR_LIST CL, MASSTOR_LIST ML));
extern MASSTOR_LIST SACIPOL_IUPBES ARGS((MASSTOR_LIST C_34_A, MASSTOR_LIST AL));
extern MASSTOR_LIST SACIPOL_IUPBHT ARGS((MASSTOR_LIST C_35_A, MASSTOR_LIST KL));
extern MASSTOR_LIST SACIPOL_IUPBRE ARGS((MASSTOR_LIST C_36_A, MASSTOR_LIST AL));
extern MASSTOR_LIST SACIPOL_IUPCHT ARGS((MASSTOR_LIST C_37_A));
extern MASSTOR_LIST SACIPOL_IUPNT ARGS((MASSTOR_LIST C_38_A));
extern MASSTOR_LIST SACIPOL_IUPTPR ARGS((MASSTOR_LIST NL, MASSTOR_LIST C_39_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACIPOL_IUPTR ARGS((MASSTOR_LIST C_40_A, MASSTOR_LIST HL));
extern MASSTOR_LIST SACIPOL_IUPTR1 ARGS((MASSTOR_LIST C_41_A));
extern void BEGIN_SACIPOL();