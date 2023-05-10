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

void RegisterVectorType(py::module_ &m) {
  py::class_<VectorType, Type>(m, "VectorType")
    .def("__hash__", [](const VectorType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const VectorType& a, const VectorType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &VectorType::Desugar)
    .def_property_readonly("element_type", &VectorType::ElementType)
    .def_property_readonly("num_elements", &VectorType::NumElements)
    .def_property_readonly("vector_kind", &VectorType::VectorKind)
    .def_property_readonly("is_sugared", &VectorType::IsSugared);
}
} // namespace pasta
