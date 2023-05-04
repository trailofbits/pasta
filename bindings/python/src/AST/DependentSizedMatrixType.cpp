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

void RegisterDependentSizedMatrixType(py::module_ &m) {
  py::class_<DependentSizedMatrixType, MatrixType, Type>(m, "DependentSizedMatrixType")
    .def("__hash__", [](const DependentSizedMatrixType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentSizedMatrixType& a, const DependentSizedMatrixType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("AttributeToken", &DependentSizedMatrixType::AttributeToken)
    .def_property_readonly("ColumnExpression", &DependentSizedMatrixType::ColumnExpression)
    .def_property_readonly("RowExpression", &DependentSizedMatrixType::RowExpression);
}
} // namespace pasta
