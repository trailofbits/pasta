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

namespace pasta {
namespace py = pybind11;

void RegisterDesignatedInitExpr(py::module_ &m) {
  py::class_<DesignatedInitExpr, Expr>(m, "DesignatedInitExpr")
    .def("__hash__", [](const DesignatedInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DesignatedInitExpr& a, const DesignatedInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &DesignatedInitExpr::Children)
    .def_property_readonly("designators", &DesignatedInitExpr::Designators)
    .def_property_readonly("begin_token", &DesignatedInitExpr::BeginToken)
    .def("designator", &DesignatedInitExpr::Designator)
    .def_property_readonly("designators_source_range", &DesignatedInitExpr::DesignatorsSourceRange)
    .def_property_readonly("end_token", &DesignatedInitExpr::EndToken)
    .def_property_readonly("equal_or_colon_token", &DesignatedInitExpr::EqualOrColonToken)
    .def_property_readonly("initializer", &DesignatedInitExpr::Initializer)
    .def_property_readonly("num_sub_expressions", &DesignatedInitExpr::NumSubExpressions)
    .def_property_readonly("is_direct_initializer", &DesignatedInitExpr::IsDirectInitializer)
    .def_property_readonly("size", &DesignatedInitExpr::Size)
    .def_property_readonly("uses_gnu_syntax", &DesignatedInitExpr::UsesGNUSyntax);
}
} // namespace pasta
