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

void RegisterTypeOfExprType(py::module_ &m) {
  py::class_<TypeOfExprType, Type>(m, "TypeOfExprType")
    .def_property_readonly("Desugar", &TypeOfExprType::Desugar)
    .def_property_readonly("Kind", &TypeOfExprType::Kind)
    .def_property_readonly("UnderlyingExpression", &TypeOfExprType::UnderlyingExpression)
    .def_property_readonly("IsSugared", &TypeOfExprType::IsSugared);
}
} // namespace pasta
