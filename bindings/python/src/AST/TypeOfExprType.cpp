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

void RegisterTypeOfExprType(py::module_ &m) {
  py::class_<TypeOfExprType, Type>(m, "TypeOfExprType")
    .def("__hash__", [](const TypeOfExprType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TypeOfExprType& a, const TypeOfExprType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &TypeOfExprType::Desugar)
    .def_property_readonly("kind", &TypeOfExprType::Kind)
    .def_property_readonly("underlying_expression", &TypeOfExprType::UnderlyingExpression)
    .def_property_readonly("is_sugared", &TypeOfExprType::IsSugared);
}
} // namespace pasta
