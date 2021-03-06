#define DEFINITION_CGBMISC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR CGBMISC_rcsid[];
extern CHAR CGBMISC_copyright[];
#define CGBMISC_zero	0
#define CGBMISC_nzero	1
#define CGBMISC_unknown	2
typedef unsigned char CGBMISC_COLOUR;
typedef struct CGBMISC_1 {
    INTEGER outputlevel;
    INTEGER factorize;
    INTEGER normalform;
    INTEGER compcond;
    INTEGER C_0_char;
    BOOLEAN genericOnly;
    MASSTOR_LIST (*Factors) ARGS((MASSTOR_LIST));
    MASSTOR_LIST (*Factorize) ARGS((MASSTOR_LIST));
    void (*NormalForm) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
    CGBMISC_COLOUR (*CondEval) ARGS((MASSTOR_LIST, MASSTOR_LIST));
    void (*CondRamif) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
    BOOLEAN (*IsCnst) ARGS((MASSTOR_LIST));
    MASSTOR_LIST TermOrderPol;
    MASSTOR_LIST TermOrderCoef;
} CGBMISC_CGBPAR;
extern CGBMISC_CGBPAR CGBMISC_PAR;
extern void CGBMISC_EvordSet ARGS((MASSTOR_LIST T));
extern void CGBMISC_EvordReset ARGS(());
extern void CGBMISC_ValisSet ARGS((MASSTOR_LIST V));
extern void CGBMISC_ValisReset ARGS(());
extern MASSTOR_LIST CGBMISC_SetInsert ARGS((MASSTOR_LIST e, MASSTOR_LIST C_1_A));
extern MASSTOR_LIST CGBMISC_SetUnion ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST B));
extern void CGBMISC_CGBOPT ARGS((MASSTOR_LIST O));
extern void CGBMISC_CGBOPTWRITE ARGS(());
extern BOOLEAN CGBMISC_dummycnst ARGS((MASSTOR_LIST C_3_A));
extern MASSTOR_LIST CGBMISC_dummyfactorize ARGS((MASSTOR_LIST C_4_A));
extern void CGBMISC_FLWRITE ARGS((MASSTOR_LIST L));
extern void CGBMISC_FILWRITE ARGS((MASSTOR_LIST L, INTEGER N));
extern MASSTOR_LIST CGBMISC_XPFDIP ARGS((MASSTOR_LIST DP, MASSTOR_LIST DOM, MASSTOR_LIST VARL));
extern MASSTOR_LIST CGBMISC_PFLDIPL ARGS((MASSTOR_LIST DIPL, MASSTOR_LIST DOM, MASSTOR_LIST VARL));
extern MASSTOR_LIST CGBMISC_XDIPFPF ARGS((MASSTOR_LIST P, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL));
extern MASSTOR_LIST CGBMISC_DIPLFPFL ARGS((MASSTOR_LIST PFL, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL));
extern MASSTOR_LIST CGBMISC_DIFPF ARGS((MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL));
extern MASSTOR_LIST CGBMISC_DILFPFL ARGS((MASSTOR_LIST PFL, MASSTOR_LIST D, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL));
extern MASSTOR_LIST CGBMISC_PFIGB ARGS((MASSTOR_LIST PFL, MASSTOR_LIST TF, BOOLEAN *ONE));
extern MASSTOR_LIST CGBMISC_PFIGBA ARGS((MASSTOR_LIST PFL, MASSTOR_LIST P, MASSTOR_LIST TF, BOOLEAN *ONE));
extern MASSTOR_LIST CGBMISC_PFILS ARGS((MASSTOR_LIST B, BOOLEAN *ONE));
extern MASSTOR_LIST CGBMISC_DIILIS ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST CGBMISC_PFINOR ARGS((MASSTOR_LIST B, MASSTOR_LIST P));
extern MASSTOR_LIST CGBMISC_PFILNOR ARGS((MASSTOR_LIST B, MASSTOR_LIST P, BOOLEAN *ZERO));
extern MASSTOR_LIST CGBMISC_PFILDS ARGS((MASSTOR_LIST B, BOOLEAN *ONE));
extern MASSTOR_LIST CGBMISC_PFIDNOR ARGS((MASSTOR_LIST B, MASSTOR_LIST P));
extern MASSTOR_LIST CGBMISC_PFILDNOR ARGS((MASSTOR_LIST B, MASSTOR_LIST P, BOOLEAN *ZERO));
extern void CGBMISC_PFWRITE ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST CGBMISC_DIIPNORM ARGS((MASSTOR_LIST P));
extern void BEGIN_CGBMISC();
