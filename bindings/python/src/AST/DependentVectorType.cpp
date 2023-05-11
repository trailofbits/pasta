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

void RegisterDependentVectorType(py::module_ &m) {
  py::class_<DependentVectorType, Type>(m, "DependentVectorType")
    .def("__hash__", [](const DependentVectorType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentVectorType::Desugar)
    .def_property_readonly("attribute_token", &DependentVectorType::AttributeToken)
    .def_property_readonly("element_type", &DependentVectorType::ElementType)
    .def_property_readonly("size_expression", &DependentVectorType::SizeExpression)
    .def_property_readonly("vector_kind", &DependentVectorType::VectorKind)
    .def_property_readonly("is_sugared", &DependentVectorType::IsSugared);
}
} // namespace pasta
