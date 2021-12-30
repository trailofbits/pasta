
// RUN: print-cxx-tokens %s | FileCheck %s

// CHECK: int
// CHECK: foo
// CHECK: (
// CHECK: )
// CHECK: {
// CHECK: return
// CHECK: 1
// CHECK: ;
// CHECK: }

int foo() {
  return 1;
}
