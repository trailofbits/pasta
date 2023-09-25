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

void RegisterObjCSelectorExpr(nb::module_ &m) {
  nb::class_<ObjCSelectorExpr, Expr>(m, "ObjCSelectorExpr")
    .def("__hash__", [](const ObjCSelectorExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCSelectorExpr::Children)
    .def_prop_ro("at_token", &ObjCSelectorExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCSelectorExpr::BeginToken)
    .def_prop_ro("end_token", &ObjCSelectorExpr::EndToken)
    .def_prop_ro("num_arguments", &ObjCSelectorExpr::NumArguments)
    .def_prop_ro("r_paren_token", &ObjCSelectorExpr::RParenToken);
}
} // namespace pasta
