// RUN: print-highest-containing-substitution %s \
// RUN: | FileCheck %s -check-prefix=PHCS
// RUN: print-lowest-covered-stmt-or-decl %s | FileCheck %s -check-prefix=PLCSD
// RUN: print-lowest-covering-macro %s | FileCheck %s -check-prefix=PLCM
// RUN: print-covering-macros %s | FileCheck %s -check-prefix=PCM

// PHCS: 1 is contained in ONE at the highest level
// PHCS: 'A' is contained in A at the highest level
// PHCS: - 1 is contained in NEG_ONE at the highest level
// PHCS: 1 is contained in NEG_ONE at the highest level
// PHCS: 1 + 1 is contained in MID at the highest level
// PHCS: 1 is contained in MID at the highest level
// PHCS: 1 is contained in MID at the highest level
// PHCS: 2 + 1 + 1 is contained in OUTER at the highest level
// PHCS: 2 + 1 is contained in OUTER at the highest level
// PHCS: 2 is contained in OUTER at the highest level
// PHCS: 1 is contained in OUTER at the highest level
// PHCS: 1 is contained in OUTER at the highest level
// PHCS: ( 2 + ( 1 + 1 ) ) is contained in OUTER_SAFE at the highest level
// PHCS: 2 + ( 1 + 1 ) is contained in OUTER_SAFE at the highest level
// PHCS: 2 is contained in OUTER_SAFE at the highest level
// PHCS: ( 1 + 1 ) is contained in OUTER_SAFE at the highest level
// PHCS: 1 + 1 is contained in OUTER_SAFE at the highest level
// PHCS: 1 is contained in OUTER_SAFE at the highest level
// PHCS: 1 is contained in OUTER_SAFE at the highest level
// PHCS: 1 is contained in ONE_PLUS_ONE at the highest level
// PHCS: 1 is contained in ONE_PLUS_ONE at the highest level
// PHCS: 1 is contained in ONE_PLUS at the highest level
// PHCS: weird is contained in STRANGE at the highest level
// PHCS: do { } while ( 0 ) is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: { } is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: 0 is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: do { } while ( 0 ) is contained in SWALLOW_SEMICOLON at the highest level
// PHCS: { } is contained in SWALLOW_SEMICOLON at the highest level
// PHCS: 0 is contained in SWALLOW_SEMICOLON at the highest level
// PHCS: 1 is contained in ONE_SEMI at the highest level
// PHCS: return 0 is contained in EXIT_SUCCESS at the highest level
// PHCS: 0 is contained in EXIT_SUCCESS at the highest level
// PHCS: 1 is contained in __STDC__ at the highest level
// PHCS: "object_like.c" is contained in __FILE_NAME__ at the highest level

// PLCSD: ONE covers 1
// PLCSD: A covers 'A'
// PLCSD: NEG_ONE covers - 1
// PLCSD: NOTHING covers nothing
// PLCSD: MID covers 1 + 1
// PLCSD: INNER covers 1
// PLCSD: INNER covers 1
// PLCSD: OUTER covers 2 + 1 + 1
// PLCSD: MID covers nothing
// PLCSD: INNER covers 1
// PLCSD: INNER covers 1
// PLCSD: OUTER_SAFE covers ( 2 + ( 1 + 1 ) )
// PLCSD: MID_SAFE covers ( 1 + 1 )
// PLCSD: INNER covers 1
// PLCSD: INNER covers 1
// PLCSD: ONE_PLUS_ONE covers nothing
// PLCSD: ONE_PLUS covers nothing
// PLCSD: DECLARE_INT_i covers int i ;
// PLCSD: DECLARE_INT_PTR_j covers int * j ;
// PLCSD: DECLARE_FUNC_k covers int k ( ) ;
// PLCSD: DECLARE_FUNC_l covers int l ( ) ;
// PLCSD: P covers nothing
// PLCSD: INT covers nothing
// PLCSD: STRANGE covers nothing
// PLCSD: DO_NOT_SWALLOW_SEMICOLON covers do { } while ( 0 )
// PLCSD: SWALLOW_SEMICOLON covers do { } while ( 0 )
// PLCSD: ONE_SEMI covers 1
// PLCSD: EXIT_SUCCESS covers return 0
// PLCSD: __STDC__ covers 1
// PLCSD: __FILE_NAME__ covers "object_like.c"

// PLCM: 1 is covered by ONE at the lowest level
// PLCM: 'A' is covered by A at the lowest level
// PLCM: - 1 is covered by NEG_ONE at the lowest level
// PLCM: 1 + 1 is covered by MID at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: 2 + 1 + 1 is covered by OUTER at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: ( 2 + ( 1 + 1 ) ) is covered by OUTER_SAFE at the lowest level
// PLCM: ( 1 + 1 ) is covered by MID_SAFE at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: 1 is covered by INNER at the lowest level
// PLCM: do { } while ( 0 ) is covered by DO_NOT_SWALLOW_SEMICOLON at the lowest level
// PLCM: do { } while ( 0 ) is covered by SWALLOW_SEMICOLON at the lowest level
// PLCM: 1 is covered by ONE_SEMI at the lowest level
// PLCM: return 0 is covered by EXIT_SUCCESS at the lowest level
// PLCM: 1 is covered by __STDC__ at the lowest level
// PLCM: "object_like.c" is covered by __FILE_NAME__ at the lowest level

// PCM: 1 is covered by ONE (kExpansion)
// PCM: 'A' is covered by A (kExpansion)
// PCM: - 1 is covered by NEG_ONE (kExpansion)
// PCM: 1 + 1 is covered by MID (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: 2 + 1 + 1 is covered by OUTER (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: ( 2 + ( 1 + 1 ) ) is covered by OUTER_SAFE (kExpansion)
// PCM: ( 1 + 1 ) is covered by MID_SAFE (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: 1 is covered by INNER (kExpansion)
// PCM: do { } while ( 0 ) is covered by DO_NOT_SWALLOW_SEMICOLON (kExpansion)
// PCM: do { } while ( 0 ) is covered by SWALLOW_SEMICOLON (kExpansion)
// PCM: 1 is covered by ONE_SEMI (kExpansion)
// PCM: return 0 is covered by EXIT_SUCCESS (kExpansion)
// PCM: 1 is covered by __STDC__ (kExpansion)
// PCM: "object_like.c" is covered by __FILE_NAME__ (kExpansion)

// Simple expression macros
#define ONE 1
int one = ONE;

#define A 'A'
char a = A;

#define NEG_ONE -1
int negative_one = NEG_ONE;

#define NOTHING
int nothing = NOTHING 0;

// Nested object-like macros
#define INNER 1
#define MID INNER + INNER
#define OUTER 2 + MID
int mid = MID;
// MID covers nothing because of operator precedence issues
int outer_1 = OUTER;

#define MID_SAFE (INNER + INNER)
#define OUTER_SAFE (2 + MID_SAFE)
int outer_2 = OUTER_SAFE;

// Macros that cover nothing because of operator precedence issues
#define ONE_PLUS_ONE 1 + 1

int three = 2 * ONE_PLUS_ONE;
#define ONE_PLUS 1 +
int two = ONE_PLUS 1;

// Simple declaration macros
#define DECLARE_INT_i int i
DECLARE_INT_i;

#define DECLARE_INT_PTR_j int *j
DECLARE_INT_PTR_j;

#define DECLARE_FUNC_k int k()
DECLARE_FUNC_k;

#define DECLARE_FUNC_l int l();

// NOTE: Our heuristic should enable us to find this declaration
DECLARE_FUNC_l

#define P p
int P = 1;

/* Simple type macros*/
#define INT int
INT int_ = 0;

/* Macros with misnested parentheses */
#define STRANGE weird(

int weird() {
  return 0;
}

int foo(int argc, char const *argv[]) {
  STRANGE);

// Non-Expr Stmt macros
#define DO_NOT_SWALLOW_SEMICOLON \
  do { \
  } while (0)

#define SWALLOW_SEMICOLON \
  do { \
  } while (0);

  DO_NOT_SWALLOW_SEMICOLON;

  // Note: Even though the expansion includes the semicolon, our heuristics
  // should return the do-while statement, which does not include the semicolon
  SWALLOW_SEMICOLON

#define ONE_SEMI 1;

  ONE_SEMI

#define EXIT_SUCCESS return 0;

  EXIT_SUCCESS
}

int main(int argc, char const *argv[])
{
  // Predefined object-like macro tests NOTE(bpappas):

  // We don't have automated tests for predefined outputs with dynamic output,
  // e.g. __DATE__ and __TIME__, but they can easily be tested manually.
  
  __STDC__;
  __FILE_NAME__;

  return 0;
}
