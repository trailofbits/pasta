
// RUN: %print-cxx-tokens %s

// CHECK: struct
// CHECK: foo
// CHECK: {
// CHECK: operator
// CHECK: int
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
  operator int () {
    return 1;
  }
};
