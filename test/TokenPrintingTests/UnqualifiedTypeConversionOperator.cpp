
// RUN: print-cxx-tokens %s | FileCheck %s

// CHECK: struct
// CHECK: foo
// CHECK: {
// CHECK: typedef
// CHECK: int
// CHECK: bar
// CHECK: ;
// CHECK: operator
// CHECK: bar
// CHECK: (
// CHECK: )
// CHECK: {
// CHECK: return
// CHECK: 1
// CHECK: ;
// CHECK: }
// CHECK: }
// CHECK: ;

struct foo {
  typedef int bar;
  operator bar() {
    return 1;
  }
};
