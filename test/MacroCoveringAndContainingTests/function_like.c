// RUN: print-lowest-containing-macro-argument %s \
// RUN: | FileCheck %s -check-prefix=PLCMA
// RUN: print-highest-containing-substitution %s \
// RUN: | FileCheck %s -check-prefix=PHCS
// RUN: print-lowest-covered-stmt-or-decl %s | FileCheck %s -check-prefix=PLCSD
// RUN: print-lowest-covering-macro %s | FileCheck %s -check-prefix=PLCM
// RUN: print-covering-macros %s | FileCheck %s -check-prefix=PCM
// RUN: print-aligned-parameter-substitutions %s \
// RUN: | FileCheck %s -check-prefix=PAPS

// PLCMA: 0 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCMA: 1 * 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition MUL argument number 1 Y
// PLCMA: 3 * 4 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCMA: 4 is contained in argument of parent macro expansion of macro definition MUL argument number 1 Y
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCMA: x is contained in argument of parent macro expansion of macro definition DO_NOT_SWALLOW_SEMICOLON argument number 0 X
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition COMMAS argument number 0 ...
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition COMMAS argument number 0 ...
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition COMMAS argument number 1 <unnamed>
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition VA_OPT_TEST argument number 0 ...
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition VA_OPT_TEST argument number 1 <unnamed>
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition VA_OPT_TEST argument number 2 <unnamed>

// PHCS: 0 + 1 is contained in ADD at the highest level
// PHCS: 0 is contained in ADD at the highest level
// PHCS: 1 is contained in ADD at the highest level
// PHCS: 2 is contained in ADD at the highest level
// PHCS: 3 is contained in ADD at the highest level
// PHCS: "FIZZ" "and" "BUZZ" is contained in FIZZ_AND at the highest level
// PHCS: 1 * 2 + 3 * 4 is contained in ADD at the highest level
// PHCS: 1 * 2 is contained in ADD at the highest level
// PHCS: 1 is contained in ADD at the highest level
// PHCS: 2 is contained in ADD at the highest level
// PHCS: 3 * 4 is contained in ADD at the highest level
// PHCS: 3 is contained in ADD at the highest level
// PHCS: 4 is contained in ADD at the highest level
// PHCS: 1 + 2 + 3 is contained in STRANGE at the highest level
// PHCS: 1 + 2 is contained in STRANGE at the highest level
// PHCS: 1 is contained in STRANGE at the highest level
// PHCS: 2 is contained in STRANGE at the highest level
// PHCS: 3 is contained in STRANGE at the highest level
// PHCS: do { x ++ ; } while ( 0 ) is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: { x ++ ; } is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: x ++ is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: x is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: 0 is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
// PHCS: 1 is contained in COMMAS at the highest level
// PHCS: 1 , 2 is contained in COMMAS at the highest level
// PHCS: 1 is contained in COMMAS at the highest level
// PHCS: 2 is contained in COMMAS at the highest level
// PHCS: 1 is contained in VA_OPT_TEST at the highest level
// PHCS: 1 , 1 , 2 , 3 is contained in VA_OPT_TEST at the highest level
// PHCS: 1 , 1 , 2 is contained in VA_OPT_TEST at the highest level
// PHCS: 1 , 1 is contained in VA_OPT_TEST at the highest level
// PHCS: 1 is contained in VA_OPT_TEST at the highest level
// PHCS: 1 is contained in VA_OPT_TEST at the highest level
// PHCS: 2 is contained in VA_OPT_TEST at the highest level
// PHCS: 3 is contained in VA_OPT_TEST at the highest level
// PHCS: "string" is contained in STRINGIFY at the highest level
// PHCS: "one" , "two" is contained in STRINGIFY_SEP_COMMAS at the highest level
// PHCS: "one" is contained in STRINGIFY_SEP_COMMAS at the highest level
// PHCS: "two" is contained in STRINGIFY_SEP_COMMAS at the highest level
// PHCS: 1234 is contained in PASTE at the highest level

// PLCSD: ADD covers 0 + 1
// PLCSD: ADD covers nothing
// PLCSD: FIZZ_AND covers "FIZZ" "and" "BUZZ"
// PLCSD: ADD covers 1 * 2 + 3 * 4
// PLCSD: STRANGE covers 1 + 2 + 3
// PLCSD: DECLARE_GENERIC_FUNC_f covers int l_UNIQUE ( ) ;
// PLCSD: DECLARE_GENERIC_FUNC_g covers char m_UNIQUE ( void ) ;
// PLCSD: DECLARE_FUNC_PTR_GENERIC_h covers int * ( * n_UNIQUE ) ( ) ;
// PLCSD: DO_NOT_SWALLOW_SEMICOLON covers do { x ++ ; } while ( 0 )
// PLCSD: COMMAS covers 1
// PLCSD: COMMAS covers 1 , 2
// PLCSD: VA_OPT_TEST covers 1
// PLCSD: VA_OPT_TEST covers 1 , 1 , 2 , 3
// PLCSD: STRINGIFY covers "string"
// PLCSD: STRINGIFY_SEP_COMMAS covers "one" , "two"
// PLCSD: PASTE covers 1234

// PLCM: 0 + 1 is covered by ADD at the lowest level
// PLCM: 0 is covered by X at the lowest level
// PLCM: 0 is covered by argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCM: 1 is covered by Y at the lowest level
// PLCM: 1 is covered by argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCM: 2 is covered by X at the lowest level
// PLCM: 2 is covered by argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCM: 3 is covered by Y at the lowest level
// PLCM: 3 is covered by argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCM: "FIZZ" "and" "BUZZ" is covered by FIZZ_AND at the lowest level
// PLCM: 1 * 2 + 3 * 4 is covered by ADD at the lowest level
// PLCM: 1 * 2 is covered by MUL at the lowest level
// PLCM: 1 * 2 is covered by X at the lowest level
// PLCM: 1 * 2 is covered by argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCM: 1 is covered by X at the lowest level
// PLCM: 1 is covered by argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCM: 2 is covered by Y at the lowest level
// PLCM: 2 is covered by argument of parent macro expansion of macro definition MUL argument number 1 Y
// PLCM: 3 * 4 is covered by MUL at the lowest level
// PLCM: 3 * 4 is covered by Y at the lowest level
// PLCM: 3 * 4 is covered by argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCM: 3 is covered by X at the lowest level
// PLCM: 3 is covered by argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCM: 4 is covered by Y at the lowest level
// PLCM: 4 is covered by argument of parent macro expansion of macro definition MUL argument number 1 Y
// PLCM: 1 + 2 + 3 is covered by STRANGE at the lowest level
// PLCM: 2 is covered by X at the lowest level
// PLCM: 2 is covered by argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCM: 3 is covered by Y at the lowest level
// PLCM: 3 is covered by argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCM: do { x ++ ; } while ( 0 ) is covered by DO_NOT_SWALLOW_SEMICOLON at the lowest level
// PLCM: x is covered by X at the lowest level
// PLCM: x is covered by argument of parent macro expansion of macro definition DO_NOT_SWALLOW_SEMICOLON argument number 0 X
// PLCM: 1 is covered by COMMAS at the lowest level
// PLCM: 1 is covered by __VA_ARGS__ at the lowest level
// PLCM: 1 is covered by argument of parent macro expansion of macro definition COMMAS argument number 0 ...
// PLCM: 1 , 2 is covered by COMMAS at the lowest level
// PLCM: 1 , 2 is covered by __VA_ARGS__ at the lowest level
// PLCM: 1 is covered by argument of parent macro expansion of macro definition COMMAS argument number 0 ...
// PLCM: 2 is covered by argument of parent macro expansion of macro definition COMMAS argument number 1 <unnamed>
// PLCM: 1 is covered by VA_OPT_TEST at the lowest level
// PLCM: 1 , 1 , 2 , 3 is covered by VA_OPT_TEST at the lowest level
// PLCM: 1 is covered by argument of parent macro expansion of macro definition VA_OPT_TEST argument number 0 ...
// PLCM: 2 is covered by argument of parent macro expansion of macro definition VA_OPT_TEST argument number 1 <unnamed>
// PLCM: 3 is covered by argument of parent macro expansion of macro definition VA_OPT_TEST argument number 2 <unnamed>
// PLCM: "string" is covered by STRINGIFY at the lowest level
// PLCM: "one" , "two" is covered by STRINGIFY_SEP_COMMAS at the lowest level
// PLCM: 1234 is covered by PASTE at the lowest level

// PCM: 0 + 1 is covered by ADD (kExpansion) ADD (kExpansion)
// PCM: 0 is covered by 0 (kArgument) 0 (kArgument) X (kParameterSubstitution)
// PCM: 1 is covered by 1 (kArgument) 1 (kArgument) Y (kParameterSubstitution)
// PCM: 2 is covered by 2 (kArgument) 2 (kArgument) X (kParameterSubstitution)
// PCM: 3 is covered by 3 (kArgument) 3 (kArgument) Y (kParameterSubstitution)
// PCM: "FIZZ" "and" "BUZZ" is covered by FIZZ_AND (kExpansion) FIZZ_AND (kExpansion)
// PCM: 1 * 2 + 3 * 4 is covered by ADD (kExpansion) ADD (kExpansion)
// PCM: 1 * 2 is covered by MUL (kExpansion) MUL (kExpansion) MUL (kArgument) X (kParameterSubstitution)
// PCM: 1 is covered by 1 (kArgument) 1 (kArgument) X (kParameterSubstitution)
// PCM: 2 is covered by 2 (kArgument) 2 (kArgument) Y (kParameterSubstitution)
// PCM: 3 * 4 is covered by MUL (kExpansion) MUL (kExpansion) MUL (kArgument) Y (kParameterSubstitution)
// PCM: 3 is covered by 3 (kArgument) 3 (kArgument) X (kParameterSubstitution)
// PCM: 4 is covered by 4 (kArgument) 4 (kArgument) Y (kParameterSubstitution)
// PCM: 1 + 2 + 3 is covered by STRANGE (kExpansion) STRANGE (kExpansion)
// PCM: 2 is covered by 2 (kArgument) 2 (kArgument) X (kParameterSubstitution)
// PCM: 3 is covered by 3 (kArgument) 3 (kArgument) Y (kParameterSubstitution)
// PCM: do { x ++ ; } while ( 0 ) is covered by DO_NOT_SWALLOW_SEMICOLON (kExpansion) DO_NOT_SWALLOW_SEMICOLON (kExpansion)
// PCM: x is covered by x (kArgument) x (kArgument) X (kParameterSubstitution)
// PCM: 1 is covered by 1 (kArgument) 1 (kArgument) __VA_ARGS__ (kParameterSubstitution) COMMAS (kExpansion) COMMAS (kExpansion)
// PCM: 1 , 2 is covered by __VA_ARGS__ (kParameterSubstitution) COMMAS (kExpansion) COMMAS (kExpansion)
// PCM: 1 is covered by 1 (kArgument) 1 (kArgument)
// PCM: 2 is covered by 2 (kArgument) 2 (kArgument)
// PCM: 1 is covered by VA_OPT_TEST (kExpansion) VA_OPT_TEST (kExpansion)
// PCM: 1 , 1 , 2 , 3 is covered by VA_OPT_TEST (kExpansion) VA_OPT_TEST (kExpansion)
// PCM: 1 is covered by 1 (kArgument) 1 (kArgument)
// PCM: 2 is covered by 2 (kArgument) 2 (kArgument)
// PCM: 3 is covered by 3 (kArgument) 3 (kArgument)
// PCM: "string" is covered by # (kStringify) STRINGIFY (kExpansion) STRINGIFY (kExpansion)
// PCM: "one" , "two" is covered by STRINGIFY_SEP_COMMAS (kExpansion) STRINGIFY_SEP_COMMAS (kExpansion)
// PCM: "one" is covered by # (kStringify)
// PCM: "two" is covered by # (kStringify)
// PCM: 1234 is covered by ## (kConcatenate) PASTE (kExpansion) PASTE (kExpansion)

// PAPS: 0 + 1 is covered by the following expansions:
// PAPS: ADD
// PAPS: Aligned parameters:
// PAPS:   X (expected 1, actual 1):
// PAPS:     0
// PAPS:   Y (expected 1, actual 1):
// PAPS:     1
// PAPS: "FIZZ" "and" "BUZZ" is covered by the following expansions:
// PAPS: FIZZ_AND
// PAPS: Aligned parameters:
// PAPS:   A (expected 1, actual 0):
// PAPS: 1 * 2 + 3 * 4 is covered by the following expansions:
// PAPS: ADD
// PAPS: Aligned parameters:
// PAPS:   X (expected 1, actual 1):
// PAPS:     1 * 2
// PAPS:   Y (expected 1, actual 1):
// PAPS:     3 * 4
// PAPS: 1 * 2 is covered by the following expansions:
// PAPS: MUL
// PAPS: Aligned parameters:
// PAPS:   X (expected 1, actual 1):
// PAPS:     1
// PAPS:   Y (expected 1, actual 1):
// PAPS:     2
// PAPS: 3 * 4 is covered by the following expansions:
// PAPS: MUL
// PAPS: Aligned parameters:
// PAPS:   X (expected 1, actual 1):
// PAPS:     3
// PAPS:   Y (expected 1, actual 1):
// PAPS:     4
// PAPS: 1 + 2 + 3 is covered by the following expansions:
// PAPS: STRANGE
// PAPS: Aligned parameters:
// PAPS:   A (expected 1, actual 0):
// PAPS: do { x ++ ; } while ( 0 ) is covered by the following expansions:
// PAPS: DO_NOT_SWALLOW_SEMICOLON
// PAPS: Aligned parameters:
// PAPS:   X (expected 1, actual 1):
// PAPS:     x
// PAPS: 1 is covered by the following expansions:
// PAPS: COMMAS
// PAPS: Aligned parameters:
// PAPS:   <a nameless parameter> (expected 1, actual 1):
// PAPS:     1
// PAPS: 1 , 2 is covered by the following expansions:
// PAPS: COMMAS
// PAPS: Aligned parameters:
// PAPS:   <a nameless parameter> (expected 1, actual 1):
// PAPS:     1 , 2
// PAPS: 1 is covered by the following expansions:
// PAPS: VA_OPT_TEST
// PAPS: Aligned parameters:
// PAPS:   <a nameless parameter> (expected 1, actual 0):
// PAPS: 1 , 1 , 2 , 3 is covered by the following expansions:
// PAPS: VA_OPT_TEST
// PAPS: Aligned parameters:
// PAPS:   <a nameless parameter> (expected 1, actual 0):
// PAPS: "string" is covered by the following expansions:
// PAPS: STRINGIFY
// PAPS: Aligned parameters:
// PAPS:   A (expected 0, actual 0):
// PAPS: "one" , "two" is covered by the following expansions:
// PAPS: STRINGIFY_SEP_COMMAS
// PAPS: Aligned parameters:
// PAPS:   A (expected 0, actual 0):
// PAPS:   B (expected 0, actual 0):
// PAPS: 1234 is covered by the following expansions:
// PAPS: PASTE
// PAPS: Aligned parameters:
// PAPS:   A (expected 1, actual 0):
// PAPS:   B (expected 1, actual 0):
// PAPS:   C (expected 1, actual 0):
// PAPS:   D (expected 1, actual 0):

// Simple expression function-like macros
#define ADD(X, Y) X + Y

int one = ADD(0, 1);

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
