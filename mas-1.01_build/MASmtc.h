#define DEFINITION_MASmtc

extern struct MASmtc_1 {
    CHAR A[80 + 1];
} MASmtc_EditPrg, MASmtc_EditPrm;
extern CHAR MASmtc_rcsid[];
extern CHAR MASmtc_copyright[];
extern ADDRESS MASmtc_getstck ARGS(());
extern ADDRESS MASmtc_gettoc ARGS(());
extern BOOLEAN MASmtc_NextParm ARGS((CHAR s[], LONGCARD ));
extern INTEGER MASmtc_DOS ARGS((CHAR s[], LONGCARD ));
extern INTEGER MASmtc_EDIT ARGS((CHAR s[], LONGCARD ));
extern void BEGIN_MASmtc();
