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

void RegisterDependentVectorType(py::module_ &m) {
  py::class_<DependentVectorType, Type>(m, "DependentVectorType")
    .def("__hash__", [](const DependentVectorType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentVectorType& a, const DependentVectorType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &DependentVectorType::Desugar)
    .def_property_readonly("AttributeToken", &DependentVectorType::AttributeToken)
    .def_property_readonly("ElementType", &DependentVectorType::ElementType)
    .def_property_readonly("SizeExpression", &DependentVectorType::SizeExpression)
    .def_property_readonly("VectorKind", &DependentVectorType::VectorKind)
    .def_property_readonly("IsSugared", &DependentVectorType::IsSugared);
}
} // namespace pasta
