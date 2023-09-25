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

void RegisterSourceLocExpr(nb::module_ &m) {
  nb::class_<SourceLocExpr, Expr>(m, "SourceLocExpr")
    .def("__hash__", [](const SourceLocExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &SourceLocExpr::Children)
    .def_prop_ro("begin_token", &SourceLocExpr::BeginToken)
    .def_prop_ro("builtin_string", &SourceLocExpr::BuiltinString)
    .def_prop_ro("end_token", &SourceLocExpr::EndToken)
    .def_prop_ro("identifier_kind", &SourceLocExpr::IdentifierKind)
    .def_prop_ro("token", &SourceLocExpr::Token)
    .def_prop_ro("parent_context", &SourceLocExpr::ParentContext)
    .def_prop_ro("is_int_type", &SourceLocExpr::IsIntType);
}
} // namespace pasta
