/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterSourceLocExpr(py::module_ &m) {
  py::class_<SourceLocExpr, Expr>(m, "SourceLocExpr")
    .def("__hash__", [](const SourceLocExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &SourceLocExpr::Children)
    .def_property_readonly("begin_token", &SourceLocExpr::BeginToken)
    .def_property_readonly("builtin_string", &SourceLocExpr::BuiltinString)
    .def_property_readonly("end_token", &SourceLocExpr::EndToken)
    .def_property_readonly("identifier_kind", &SourceLocExpr::IdentifierKind)
    .def_property_readonly("token", &SourceLocExpr::Token)
    .def_property_readonly("parent_context", &SourceLocExpr::ParentContext)
    .def_property_readonly("is_int_type", &SourceLocExpr::IsIntType);
}
} // namespace pasta
