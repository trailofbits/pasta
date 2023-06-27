// RUN: print-aligned-substitutions %s | FileCheck %s -check-prefix=PAS

// PAS: 0 + 1 is covered by the following expansions:
// PAS:   ADD
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         0
// PAS:       Y (expected 1, actual 1):
// PAS:         1
// PAS: 0 is covered by the following expansions:
// PAS:   X
// PAS: 1 is covered by the following expansions:
// PAS:   Y
// PAS: 1 + 2 + 3 is covered by the following expansions:
// PAS:   ADD
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         1 + 2
// PAS:       Y (expected 1, actual 1):
// PAS:         3
// PAS: 1 + 2 is covered by the following expansions:
// PAS:   X
// PAS:   ADD
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         1
// PAS:       Y (expected 1, actual 1):
// PAS:         2
// PAS: 1 is covered by the following expansions:
// PAS:   X
// PAS: 2 is covered by the following expansions:
// PAS:   Y
// PAS: 3 is covered by the following expansions:
// PAS:   Y
// PAS: 2 is covered by the following expansions:
// PAS:   X
// PAS: 3 is covered by the following expansions:
// PAS:   Y
// PAS: "FIZZ" "and" "BUZZ" is covered by the following expansions:
// PAS:   FIZZ_AND
// PAS:     Aligned parameters:
// PAS:       A (expected 1, actual 0):
// PAS: 1 * 2 + 3 * 4 is covered by the following expansions:
// PAS:   ADD
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         1 * 2
// PAS:       Y (expected 1, actual 1):
// PAS:         3 * 4
// PAS: 1 * 2 is covered by the following expansions:
// PAS:   X
// PAS:   MUL
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         1
// PAS:       Y (expected 1, actual 1):
// PAS:         2
// PAS: 1 is covered by the following expansions:
// PAS:   X
// PAS: 2 is covered by the following expansions:
// PAS:   Y
// PAS: 3 * 4 is covered by the following expansions:
// PAS:   Y
// PAS:   MUL
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         3
// PAS:       Y (expected 1, actual 1):
// PAS:         4
// PAS: 3 is covered by the following expansions:
// PAS:   X
// PAS: 4 is covered by the following expansions:
// PAS:   Y
// PAS: 1 + 2 + 3 is covered by the following expansions:
// PAS:   STRANGE
// PAS:     Aligned parameters:
// PAS:       A (expected 1, actual 0):
// PAS: 2 is covered by the following expansions:
// PAS:   X
// PAS: 3 is covered by the following expansions:
// PAS:   Y
// PAS: do { x ++ ; } while ( 0 ) is covered by the following expansions:
// PAS:   DO_NOT_SWALLOW_SEMICOLON
// PAS:     Aligned parameters:
// PAS:       X (expected 1, actual 1):
// PAS:         x
// PAS: x is covered by the following expansions:
// PAS:   X
// PAS: 1 is covered by the following expansions:
// PAS:   COMMAS
// PAS:     Aligned parameters:
// PAS:       <a nameless parameter> (expected 1, actual 1):
// PAS:         1
// PAS:   __VA_ARGS__
// PAS: 1 , 2 is covered by the following expansions:
// PAS:   COMMAS
// PAS:     Aligned parameters:
// PAS:       <a nameless parameter> (expected 1, actual 1):
// PAS:         1 , 2
// PAS:   __VA_ARGS__
// PAS: 1 is covered by the following expansions:
// PAS:   VA_OPT_TEST
// PAS:     Aligned parameters:
// PAS:       <a nameless parameter> (expected 1, actual 0):
// PAS: 1 , 1 , 2 , 3 is covered by the following expansions:
// PAS:   VA_OPT_TEST
// PAS:     Aligned parameters:
// PAS:       <a nameless parameter> (expected 1, actual 0):
// PAS: "string" is covered by the following expansions:
// PAS:   STRINGIFY
// PAS:     Aligned parameters:
// PAS:       A (expected 0, actual 0):
// PAS:   #
// PAS: "one" , "two" is covered by the following expansions:
// PAS:   STRINGIFY_SEP_COMMAS
// PAS:     Aligned parameters:
// PAS:       A (expected 0, actual 0):
// PAS:       B (expected 0, actual 0):
// PAS: "one" is covered by the following expansions:
// PAS:   #
// PAS: "two" is covered by the following expansions:
// PAS:   #
// PAS: 1234 is covered by the following expansions:
// PAS:   ##
// PAS:   PASTE
// PAS:     Aligned parameters:
// PAS:       A (expected 1, actual 0):
// PAS:       B (expected 1, actual 0):
// PAS:       C (expected 1, actual 0):
// PAS:       D (expected 1, actual 0):

// Simple expression function-like macros
#define ADD(X, Y) X + Y

int one = ADD(0, 1);

int six = ADD(ADD(1, 2), 3);

int seven = 2 * ADD(2, 3);

#define FIZZ_AND(A) \
  "FIZZ" \
  "and" A
#define BUZZ "BUZZ"

const char bacon_and_eggs[] = FIZZ_AND(BUZZ);

// Function-like macros that accept other macros as arguments
#define MUL(X, Y) X * Y
int fourteen = ADD(MUL(1, 2), MUL(3, 4));

#define STRANGE(A) 1 + A(2
int strange = STRANGE(ADD), 3);

// Declarations
#define CONCAT(a, b) a##b
#define CONCAT_2(a, b) CONCAT(a, b)
// Removed this macro because it makes adding test cases more brittle
// #define UNIQUE_NAME(a) CONCAT_2(a, __LINE__)
#define UNIQUE_NAME(a) CONCAT_2(a, UNIQUE)

#define DECLARE_GENERIC_FUNC_f(a) a UNIQUE_NAME(l_)()
#define DECLARE_GENERIC_FUNC_g(a, b) a UNIQUE_NAME(m_)(b)
#define DECLARE_FUNC_PTR_GENERIC_h(a) a (*UNIQUE_NAME(n_))()


DECLARE_GENERIC_FUNC_f(int);

DECLARE_GENERIC_FUNC_g(char, void);

DECLARE_FUNC_PTR_GENERIC_h(int *);


// Non-expression statements
#define DO_NOT_SWALLOW_SEMICOLON(X) \
  do { \
    X++; \
  } while (0)



int main(int argc, char const *argv[]) {
  int x;
  DO_NOT_SWALLOW_SEMICOLON(x);


  // Variadic macros
  
  #define COMMAS(...) __VA_ARGS__
  COMMAS(1);
  COMMAS(1, 2);

  #define VA_OPT_TEST(...) 1 __VA_OPT__(,) __VA_ARGS__
  VA_OPT_TEST();
  VA_OPT_TEST(1, 2, 3);


  // Stringification

  #define STRINGIFY(A) #A
  STRINGIFY(string);

  #define STRINGIFY_SEP_COMMAS(A, B) #A, #B

  // Token-pasting

  STRINGIFY_SEP_COMMAS(one, two);
  #define PASTE(A, B, C, D) A ## B ## C ## D
  PASTE(1, 2, 3, 4);

  return 0;
}
