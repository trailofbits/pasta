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

void RegisterConstantMatrixType(py::module_ &m) {
  py::class_<ConstantMatrixType, MatrixType, Type>(m, "ConstantMatrixType")
    .def_property_readonly("NumColumns", &ConstantMatrixType::NumColumns)
    .def_property_readonly("NumElementsFlattened", &ConstantMatrixType::NumElementsFlattened)
    .def_property_readonly("NumRows", &ConstantMatrixType::NumRows);
}
} // namespace pasta
