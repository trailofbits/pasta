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

void RegisterDependentSizedExtVectorType(py::module_ &m) {
  py::class_<DependentSizedExtVectorType, Type>(m, "DependentSizedExtVectorType")
    .def("__hash__", [](const DependentSizedExtVectorType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentSizedExtVectorType::Desugar)
    .def_property_readonly("attribute_token", &DependentSizedExtVectorType::AttributeToken)
    .def_property_readonly("element_type", &DependentSizedExtVectorType::ElementType)
    .def_property_readonly("size_expression", &DependentSizedExtVectorType::SizeExpression)
    .def_property_readonly("is_sugared", &DependentSizedExtVectorType::IsSugared);
}
} // namespace pasta
