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
  py::class_<TypeTraitExpr, Expr>(m, "TypeTraitExpr")
    .def("__hash__", [](const TypeTraitExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const TypeTraitExpr& a, const TypeTraitExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &TypeTraitExpr::Children)
    .def_property_readonly("begin_token", &TypeTraitExpr::BeginToken)
    .def_property_readonly("end_token", &TypeTraitExpr::EndToken)
    .def_property_readonly("num_arguments", &TypeTraitExpr::NumArguments)
    .def_property_readonly("trait", &TypeTraitExpr::Trait)
    .def_property_readonly("value", &TypeTraitExpr::Value);
}
} // namespace pasta
