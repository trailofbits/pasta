/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterObjCAtFinallyStmt(nb::module_ &m) {
  nb::class_<ObjCAtFinallyStmt, Stmt>(m, "ObjCAtFinallyStmt")
    .def("__hash__", [](const ObjCAtFinallyStmt& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCAtFinallyStmt::Children)
    .def_prop_ro("at_finally_token", &ObjCAtFinallyStmt::AtFinallyToken)
    .def_prop_ro("begin_token", &ObjCAtFinallyStmt::BeginToken)
    .def_prop_ro("end_token", &ObjCAtFinallyStmt::EndToken)
    .def_prop_ro("finally_body", &ObjCAtFinallyStmt::FinallyBody);
}
} // namespace pasta
