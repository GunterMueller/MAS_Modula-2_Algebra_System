#define DEFINITION_setjmp

typedef struct setjmp_1 {
    INTEGER A[255 + 1];
} setjmp_jmp_buf;
extern CHAR setjmp_rcsid[];
extern CHAR setjmp_copyright[];
extern INTEGER setjmp ARGS((setjmp_jmp_buf *env));
extern void longjmp ARGS((setjmp_jmp_buf *env, INTEGER rc));
extern void BEGIN_setjmp();
