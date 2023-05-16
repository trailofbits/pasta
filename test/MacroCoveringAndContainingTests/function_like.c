// RUN: print-lowest-containing-macro-argument %s \
// RUN: | FileCheck %s -check-prefix=PLCMA
// RUN: print-highest-containing-substitution %s \
// RUN: | FileCheck %s -check-prefix=PHCS
// RUN: print-lowest-covered-stmt-or-decl %s | FileCheck %s -check-prefix=PLCSD
// RUN: print-lowest-covering-substitution %s | FileCheck %s -check-prefix=PLCS

// Simple expression function-like macros
#define ADD(X, Y) X + Y

// PLCSD: ADD covers 0 + 1
// PLCS: 0 + 1 is covered by ADD at the lowest level
// PLCMA: 0 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PHCS: 0 + 1 is contained in ADD at the highest level
// PHCS: 0 is contained in ADD at the highest level
// PHCS: 1 is contained in ADD at the highest level
int one = ADD(0, 1);

// PLCSD: ADD covers nothing
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PHCS: 2 is contained in ADD at the highest level
// PHCS: 3 is contained in ADD at the highest level
int seven = 2 * ADD(2, 3);

#define FIZZ_AND(A) \
  "FIZZ" \
  "and" A
#define BUZZ "BUZZ"

// PLCSD: FIZZ_AND covers "FIZZ" "and" "BUZZ"
// PLCS: "FIZZ" "and" "BUZZ" is covered by FIZZ_AND at the lowest level
// PHCS: "FIZZ" "and" "BUZZ" is contained in FIZZ_AND at the highest level
const char bacon_and_eggs[] = FIZZ_AND(BUZZ);

// Function-like macros that accept other macros as arguments
#define MUL(X, Y) X * Y
// PLCSD: ADD covers 1 * 2 + 3 * 4
// PLCS: 1 * 2 + 3 * 4 is covered by ADD at the lowest level
// PLCMA: 1 * 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 1 is contained in argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCMA: 2 is contained in argument of parent macro expansion of macro
// definition MUL argument number 1 Y
// PLCMA: 3 * 4 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition MUL argument number 0 X
// PLCMA: 4 is contained in argument of parent macro expansion of macro definition MUL argument number 1 Y
// PHCS: 1 * 2 + 3 * 4 is contained in ADD at the highest level
// PHCS: 1 * 2 is contained in ADD at the highest level
// PHCS: 1 is contained in ADD at the highest level
// PHCS: 2 is contained in ADD at the highest level
// PHCS: 3 * 4 is contained in ADD at the highest level
// PHCS: 3 is contained in ADD at the highest level
// PHCS: 4 is contained in ADD at the highest level
int fourteen = ADD(MUL(1, 2), MUL(3, 4));

// PLCSD: STRANGE covers 1 + 2 + 3
// PLCS: 1 + 2 + 3 is covered by STRANGE at the lowest level
// PLCMA: 2 is contained in argument of parent macro expansion of macro definition ADD argument number 0 X
// PLCMA: 3 is contained in argument of parent macro expansion of macro definition ADD argument number 1 Y
// PHCS: 1 + 2 + 3 is contained in STRANGE at the highest level
// PHCS: 1 + 2 is contained in STRANGE at the highest level
// PHCS: 1 is contained in STRANGE at the highest level
// PHCS: 2 is contained in STRANGE at the highest level
// PHCS: 3 is contained in STRANGE at the highest level
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


// PLCSD: DECLARE_GENERIC_FUNC_f covers int l_UNIQUE ( )
DECLARE_GENERIC_FUNC_f(int);

// PLCSD: DECLARE_GENERIC_FUNC_g covers char m_UNIQUE ( void )
DECLARE_GENERIC_FUNC_g(char, void);

// PLCSD: DECLARE_FUNC_PTR_GENERIC_h covers int * ( * n_UNIQUE ) ( )
DECLARE_FUNC_PTR_GENERIC_h(int *);


// Non-expression statements
#define DO_NOT_SWALLOW_SEMICOLON(X) \
  do { \
    X++; \
  } while (0)


int main(int argc, char const *argv[]) {
        int x;
        // PLCSD: DO_NOT_SWALLOW_SEMICOLON covers do { x ++ ; } while ( 0 )
        // PLCS: do { x ++ ; } while ( 0 ) is covered by DO_NOT_SWALLOW_SEMICOLON at the lowest level
        // PLCMA: x is contained in argument of parent macro expansion of macro definition DO_NOT_SWALLOW_SEMICOLON argument number 0 X
        // PHCS: do { x ++ ; } while ( 0 ) is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
        // PHCS: { x ++ ; } is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
        // PHCS: x ++ is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
        // PHCS: x is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
        // PHCS: 0 is contained in DO_NOT_SWALLOW_SEMICOLON at the highest level
        DO_NOT_SWALLOW_SEMICOLON(x);

        return 0;
}
