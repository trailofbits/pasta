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

void RegisterObjCEncodeExpr(nb::module_ &m) {
  nb::class_<ObjCEncodeExpr, Expr>(m, "ObjCEncodeExpr")
    .def("__hash__", [](const ObjCEncodeExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCEncodeExpr::Children)
    .def_prop_ro("at_token", &ObjCEncodeExpr::AtToken)
    .def_prop_ro("begin_token", &ObjCEncodeExpr::BeginToken)
    .def_prop_ro("encoded_type", &ObjCEncodeExpr::EncodedType)
    .def_prop_ro("end_token", &ObjCEncodeExpr::EndToken)
    .def_prop_ro("r_paren_token", &ObjCEncodeExpr::RParenToken);
}
} // namespace pasta
