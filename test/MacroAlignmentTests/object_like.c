// RUN: print-aligned-substitutions %s | FileCheck %s -check-prefix=PAS

// PAS: 1 is covered by the following expansions:
// PAS:   ONE
// PAS: 'A' is covered by the following expansions:
// PAS:   A
// PAS: - 1 is covered by the following expansions:
// PAS:   NEG_ONE
// PAS: 1 + 1 is covered by the following expansions:
// PAS:   MID
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: 2 + 1 + 1 is covered by the following expansions:
// PAS:   OUTER
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: ( 2 + ( 1 + 1 ) ) is covered by the following expansions:
// PAS:   OUTER_SAFE
// PAS: ( 1 + 1 ) is covered by the following expansions:
// PAS:   MID_SAFE
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: 1 is covered by the following expansions:
// PAS:   INNER
// PAS: do { } while ( 0 ) is covered by the following expansions:
// PAS:   DO_NOT_SWALLOW_SEMICOLON
// PAS: do { } while ( 0 ) is covered by the following expansions:
// PAS:   SWALLOW_SEMICOLON
// PAS: 1 is covered by the following expansions:
// PAS:   ONE_SEMI
// PAS: return 0 is covered by the following expansions:
// PAS:   EXIT_SUCCESS
// PAS: 1 is covered by the following expansions:
// PAS:   __STDC__
// PAS: "object_like.c" is covered by the following expansions:
// PAS:   __FILE_NAME__

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
