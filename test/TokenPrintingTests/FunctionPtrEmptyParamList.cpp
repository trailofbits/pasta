
// RUN: print-cxx-tokens %s | FileCheck %s

// CHECK: int
// CHECK: (
// CHECK: *
// CHECK: foo
// CHECK: )
// CHECK: (
// CHECK: )
// CHECK: ;

int (*foo)();
