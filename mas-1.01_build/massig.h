#define DEFINITION_massig

extern CHAR massig_rcsid[];
extern CHAR massig_copyright[];
#define massig_SIGMAX	63
#define massig_SIGHUP	1
#define massig_SIGINT	2
#define massig_SIGQUIT	3
#define massig_SIGILL	4
#define massig_SIGTRAP	5
#define massig_SIGABRT	6
#define massig_SIGEMT	7
#define massig_SIGFPE	8
#define massig_SIGKILL	9
#define massig_SIGBUS	10
#define massig_SIGSEGV	11
#define massig_SIGSYS	12
#define massig_SIGPIPE	13
#define massig_SIGALRM	14
#define massig_SIGTERM	15
#define massig_SIGURG	16
#define massig_SIGSTOP	17
#define massig_SIGTSTP	18
#define massig_SIGCONT	19
#define massig_SIGCHLD	20
#define massig_SIGTTIN	21
#define massig_SIGTTOU	22
#define massig_SIGIO	23
#define massig_SIGXCPU	24
#define massig_SIGXFSZ	25
#define massig_SIGMSG	27
#define massig_SIGWINCH	28
#define massig_SIGPWR	29
#define massig_SIGUSR1	30
#define massig_SIGUSR2	31
#define massig_SIGPROF	32
#define massig_SIGDANGER	33
#define massig_SIGVTALRM	34
#define massig_SIGMIGRATE	35
#define massig_SIGPRE	36
#define massig_SIGGRANT	60
#define massig_SIGRETRACT	61
#define massig_SIGSOUND	62
#define massig_SIGSAK	63
typedef void (*massig_Action) ARGS((INTEGER));
extern massig_Action massig_SIG_DFL, massig_SIG_IGN, massig_SIG_ACK, massig_SIG_ERR;
extern massig_Action signal ARGS((INTEGER s, massig_Action h));
extern INTEGER raise ARGS((INTEGER s));
extern INTEGER sigblock ARGS((INTEGER mask));
extern INTEGER sigsetmask ARGS((INTEGER mask));
extern INTEGER SigMask ARGS((INTEGER s));
extern void BEGIN_massig();
