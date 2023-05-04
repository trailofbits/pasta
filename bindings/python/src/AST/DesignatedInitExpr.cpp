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
  py::class_<DesignatedInitExpr, Expr, Stmt, ValueStmt>(m, "DesignatedInitExpr")
    .def("__hash__", [](const DesignatedInitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const DesignatedInitExpr& a, const DesignatedInitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &DesignatedInitExpr::Children)
    .def_property_readonly("Designators", &DesignatedInitExpr::Designators)
    .def_property_readonly("BeginToken", &DesignatedInitExpr::BeginToken)
    .def("Designator", &DesignatedInitExpr::Designator)
    .def_property_readonly("DesignatorsSourceRange", &DesignatedInitExpr::DesignatorsSourceRange)
    .def_property_readonly("EndToken", &DesignatedInitExpr::EndToken)
    .def_property_readonly("EqualOrColonToken", &DesignatedInitExpr::EqualOrColonToken)
    .def_property_readonly("Initializer", &DesignatedInitExpr::Initializer)
    .def_property_readonly("NumSubExpressions", &DesignatedInitExpr::NumSubExpressions)
    .def_property_readonly("IsDirectInitializer", &DesignatedInitExpr::IsDirectInitializer)
    .def_property_readonly("Size", &DesignatedInitExpr::Size)
    .def_property_readonly("UsesGNUSyntax", &DesignatedInitExpr::UsesGNUSyntax);
}
} // namespace pasta
