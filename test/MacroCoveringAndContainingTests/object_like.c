// RUN: print-lowest-covering %s | FileCheck %s -check-prefix=PLC
// RUN: print-highest-containing-substitution %s \
// RUN: | FileCheck %s -check-prefix=PHCS

// Simple expression macros
#define ONE 1
// PLC: ONE covers 1
// PHCS: 1 is contained in ONE at the highest level
int one = ONE;

#define A 'A'
// PLC: A covers 'A'
// PHCS: 'A' is contained in A at the highest level
char a = A;

#define NEG_ONE -1
// PLC: NEG_ONE covers - 1
// PHCS: - 1 is contained in NEG_ONE
// PHCS: 1 is contained in NEG_ONE
int negative_one = NEG_ONE;

#define NOTHING
// PLC: NOTHING covers nothing
int nothing = NOTHING 0;

// Nested object-like macros
#define INNER 1
#define MID INNER + INNER
#define OUTER 2 + MID
// PLC: MID covers 1 + 1
// PLC: INNER covers 1
// PLC: INNER covers 1
// PHCS: 1 + 1 is contained in MID
// PHCS: 1 is contained in MID 
// PHCS: 1 is contained in MID
int mid = MID;
// PLC: OUTER covers 2 + 1 + 1
// COM: MID covers nothing because of operator precedence issues
// PLC: MID covers nothing
// PLC: INNER covers 1
// PLC: INNER covers 1
// PHCS: 2 + 1 + 1 is contained in OUTER at the highest level
// PHCS: 2 + 1 is contained in OUTER at the highest level
// PHCS: 2 is contained in OUTER at the highest level
// PHCS: 1 is contained in OUTER at the highest level
// PHCS: 1 is contained in OUTER at the highest level
int outer_1 = OUTER;

#define MID_SAFE (INNER + INNER)
#define OUTER_SAFE (2 + MID_SAFE)
// PLC: OUTER_SAFE covers ( 2 + ( 1 + 1 ) )
// PLC: MID_SAFE covers ( 1 + 1 )
// PLC: INNER covers 1
// PLC: INNER covers 1
// PHCS: ( 2 + ( 1 + 1 ) ) is contained in OUTER_SAFE at the highest level
// PHCS: 2 + ( 1 + 1 ) is contained in OUTER_SAFE at the highest level
// PHCS: 2 is contained in OUTER_SAFE at the highest level
// PHCS: ( 1 + 1 ) is contained in OUTER_SAFE at the highest level
// PHCS: 1 + 1 is contained in OUTER_SAFE at the highest level
// PHCS: 1 is contained in OUTER_SAFE at the highest level
// PHCS: 1 is contained in OUTER_SAFE at the highest level
int outer_2 = OUTER_SAFE;

// Macros that cover nothing because of operator precedence issues
#define ONE_PLUS_ONE 1 + 1
// PLC: ONE_PLUS_ONE covers nothing

int three = 2 * ONE_PLUS_ONE;
// PHCS: 1 is contained in ONE_PLUS_ONE at the highest level
// PHCS: 1 is contained in ONE_PLUS_ONE at the highest level
#define ONE_PLUS 1 +
// PLC: ONE_PLUS covers nothing
// PHCS: 1 is contained in ONE_PLUS at the highest level
int two = ONE_PLUS 1;

// Simple declaration macros
#define DECLARE_INT_i int i
// PLC: DECLARE_INT_i covers int i
DECLARE_INT_i;

#define DECLARE_INT_PTR_j int *j
// PLC: DECLARE_INT_PTR_j covers int * j
DECLARE_INT_PTR_j;

#define DECLARE_FUNC_k int k()
// PLC: DECLARE_FUNC_k covers int k ( )
DECLARE_FUNC_k;

#define DECLARE_FUNC_l int l();

// NOTE: Our heuristic should enable us to find this declaration
// PLC: DECLARE_FUNC_l covers int l ( ) ;
DECLARE_FUNC_l

#define P p
// PLC: P covers nothing
int P = 1;

/* Simple type macros*/
#define INT int
// PLC: INT covers nothing
INT int_ = 0;

/* Macros with misnested parentheses */
#define STRANGE weird(

int weird() {
  return 0;
}

int foo(int argc, char const *argv[]) {
  // PLC: STRANGE covers nothing
  // PHCS: weird is contained in STRANGE at the highest level
  STRANGE);

// Non-Expr Stmt macros
#define DO_NOT_SWALLOW_SEMICOLON \
  do { \
  } while (0)

#define SWALLOW_SEMICOLON \
  do { \
  } while (0);

  // PLC: DO_NOT_SWALLOW_SEMICOLON covers do { } while ( 0 )
  // PHCS: do { } while ( 0 ) is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
  // PHCS: { } is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
  // PHCS: 0 is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
  DO_NOT_SWALLOW_SEMICOLON;

  // Note: Even though the expansion includes the semicolon, our heuristics
  // should return the do-while statement, which does not include the semicolon
  // PLC: SWALLOW_SEMICOLON covers do { } while ( 0 )
  // PHCS: do { } while ( 0 ) is contained in SWALLOW_SEMICOLON at the highest level
  // PHCS: { } is contained in SWALLOW_SEMICOLON at the highest level
  // PHCS: 0 is contained in SWALLOW_SEMICOLON at the highest level
  SWALLOW_SEMICOLON

#define ONE_SEMI 1;

  // PLC: ONE_SEMI covers 1
  // PHCS: 1 is contained in ONE_SEMI at the highest level
  ONE_SEMI

#define EXIT_SUCCESS return 0;

  // PLC: EXIT_SUCCESS covers return 0
  // PHCS: return 0 is contained in EXIT_SUCCESS at the highest level
  // PHCS: 0 is contained in EXIT_SUCCESS at the highest level
  EXIT_SUCCESS
}

int main(int argc, char const *argv[])
{
  return 0;
}
