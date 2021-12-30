
// RUN: print-cxx-tokens %s | FileCheck %s

// CHECK: int
// CHECK: foo
// CHECK: (
// CHECK: int
// CHECK: (
// CHECK: *
// CHECK: bar
// CHECK: )
// CHECK: (
// CHECK: )
// CHECK: ...
// CHECK: )
// CHECK: {
// CHECK: return
// CHECK: 1
// CHECK: ;
// CHECK: }

int foo(int (*bar)()...) {
  return 1;
}
