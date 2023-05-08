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

void RegisterMatrixType(py::module_ &m) {
  py::class_<MatrixType, Type>(m, "MatrixType")
    .def("__hash__", [](const MatrixType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const MatrixType& a, const MatrixType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &MatrixType::Desugar)
    .def_property_readonly("element_type", &MatrixType::ElementType)
    .def_property_readonly("is_sugared", &MatrixType::IsSugared);
}
} // namespace pasta
