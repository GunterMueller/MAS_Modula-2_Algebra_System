#define DEFINITION_SACLIST

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACLIST_rcsid[];
extern CHAR SACLIST_copyright[];
extern void SACLIST_ADV2 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *BL, MASSTOR_LIST *LP));
extern void SACLIST_ADV3 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *LP));
extern void SACLIST_ADV4 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4, MASSTOR_LIST *LP));
extern MASSTOR_LIST SACLIST_AREAD ARGS(());
extern void SACLIST_AWRITE ARGS((MASSTOR_LIST C_1_A));
extern MASSTOR_LIST SACLIST_CCONC ARGS((MASSTOR_LIST L1, MASSTOR_LIST L2));
extern MASSTOR_LIST SACLIST_CINV ARGS((MASSTOR_LIST L));
extern void SACLIST_CLOUT ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_COMP2 ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_COMP3 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_COMP4 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_CONC ARGS((MASSTOR_LIST L1, MASSTOR_LIST L2));
extern MASSTOR_LIST SACLIST_EQUAL ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL));
extern MASSTOR_LIST SACLIST_EXTENT ARGS((MASSTOR_LIST AL));
extern void SACLIST_FIRST2 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *BL));
extern void SACLIST_FIRST3 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3));
extern void SACLIST_FIRST4 ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL1, MASSTOR_LIST *AL2, MASSTOR_LIST *AL3, MASSTOR_LIST *AL4));
extern MASSTOR_LIST SACLIST_FOURTH ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_LAST ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_LEINST ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST IL, MASSTOR_LIST AL));
extern MASSTOR_LIST SACLIST_LELT ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST IL));
extern MASSTOR_LIST SACLIST_LEROT ARGS((MASSTOR_LIST L, MASSTOR_LIST IL, MASSTOR_LIST JL));
extern void SACLIST_LINS ARGS((MASSTOR_LIST AL, MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_LINSRT ARGS((MASSTOR_LIST AL, MASSTOR_LIST C_4_A));
extern MASSTOR_LIST SACLIST_LIST10 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5, MASSTOR_LIST AL6, MASSTOR_LIST AL7, MASSTOR_LIST AL8, MASSTOR_LIST AL9, MASSTOR_LIST AL10));
extern MASSTOR_LIST SACLIST_LIST2 ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL));
extern MASSTOR_LIST SACLIST_LIST3 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3));
extern MASSTOR_LIST SACLIST_LIST4 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4));
extern MASSTOR_LIST SACLIST_LIST5 ARGS((MASSTOR_LIST AL1, MASSTOR_LIST AL2, MASSTOR_LIST AL3, MASSTOR_LIST AL4, MASSTOR_LIST AL5));
extern MASSTOR_LIST SACLIST_LREAD ARGS(());
extern MASSTOR_LIST SACLIST_LSRCH ARGS((MASSTOR_LIST AL, MASSTOR_LIST C_5_A));
extern void SACLIST_LWRITE ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_MEMBER ARGS((MASSTOR_LIST AL, MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_ORDER ARGS((MASSTOR_LIST AL));
extern MASSTOR_LIST SACLIST_OREAD ARGS(());
extern void SACLIST_OWRITE ARGS((MASSTOR_LIST B));
extern MASSTOR_LIST SACLIST_PAIR ARGS((MASSTOR_LIST C_6_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACLIST_REDUCT ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST IL));
extern MASSTOR_LIST SACLIST_RED2 ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_RED3 ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_RED4 ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACLIST_SECOND ARGS((MASSTOR_LIST L));
extern void SACLIST_SLELT ARGS((MASSTOR_LIST C_8_A, MASSTOR_LIST IL, MASSTOR_LIST AL));
extern MASSTOR_LIST SACLIST_SUFFIX ARGS((MASSTOR_LIST L, MASSTOR_LIST BL));
extern MASSTOR_LIST SACLIST_THIRD ARGS((MASSTOR_LIST L));
extern void BEGIN_SACLIST();
