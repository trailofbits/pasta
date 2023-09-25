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

void RegisterCXXNullPtrLiteralExpr(nb::module_ &m) {
  nb::class_<CXXNullPtrLiteralExpr, Expr>(m, "CXXNullPtrLiteralExpr")
    .def("__hash__", [](const CXXNullPtrLiteralExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXNullPtrLiteralExpr::Children)
    .def_prop_ro("begin_token", &CXXNullPtrLiteralExpr::BeginToken)
    .def_prop_ro("end_token", &CXXNullPtrLiteralExpr::EndToken)
    .def_prop_ro("token", &CXXNullPtrLiteralExpr::Token);
}
} // namespace pasta
