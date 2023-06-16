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

void RegisterObjCAtTryStmt(nb::module_ &m) {
  nb::class_<ObjCAtTryStmt, Stmt>(m, "ObjCAtTryStmt")
    .def("__hash__", [](const ObjCAtTryStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCAtTryStmt::Children)
    .def_prop_ro("at_try_token", &ObjCAtTryStmt::AtTryToken)
    .def_prop_ro("begin_token", &ObjCAtTryStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAtTryStmt::EndToken)
    .def_prop_ro("finally_statement", &ObjCAtTryStmt::FinallyStatement)
    .def_prop_ro("num_catch_statements", &ObjCAtTryStmt::NumCatchStatements)
    .def_prop_ro("try_body", &ObjCAtTryStmt::TryBody);
}
} // namespace pasta
