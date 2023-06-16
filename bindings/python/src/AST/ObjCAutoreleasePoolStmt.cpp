/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterObjCAutoreleasePoolStmt(nb::module_ &m) {
  nb::class_<ObjCAutoreleasePoolStmt, Stmt>(m, "ObjCAutoreleasePoolStmt")
    .def("__hash__", [](const ObjCAutoreleasePoolStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCAutoreleasePoolStmt::Children)
    .def_prop_ro("at_token", &ObjCAutoreleasePoolStmt::AtToken)
    .def_prop_ro("begin_token", &ObjCAutoreleasePoolStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAutoreleasePoolStmt::EndToken)
    .def_prop_ro("sub_statement", &ObjCAutoreleasePoolStmt::SubStatement);
}
} // namespace pasta
