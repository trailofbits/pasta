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

void RegisterTypeTraitExpr(py::module_ &m) {
  py::class_<TypeTraitExpr, Expr, Stmt, ValueStmt>(m, "TypeTraitExpr")
    .def("__hash__", [](const TypeTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const TypeTraitExpr& a, const TypeTraitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &TypeTraitExpr::Children)
    .def_property_readonly("BeginToken", &TypeTraitExpr::BeginToken)
    .def_property_readonly("EndToken", &TypeTraitExpr::EndToken)
    .def_property_readonly("NumArguments", &TypeTraitExpr::NumArguments)
    .def_property_readonly("Trait", &TypeTraitExpr::Trait)
    .def_property_readonly("Value", &TypeTraitExpr::Value);
}
} // namespace pasta
