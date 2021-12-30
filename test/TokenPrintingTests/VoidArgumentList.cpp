
// RUN: print-cxx-tokens %s | FileCheck %s

// CHECK: int
// CHECK: foo
// CHECK: (
// CHECK: void
// CHECK: )
// CHECK: {
// CHECK: return
// CHECK: 1
// CHECK: ;
// CHECK: }

int foo(void) {
  return 1;
}
