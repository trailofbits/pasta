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

void RegisterDependentSizedExtVectorType(py::module_ &m) {
  py::class_<DependentSizedExtVectorType, Type>(m, "DependentSizedExtVectorType")
    .def_property_readonly("Desugar", &DependentSizedExtVectorType::Desugar)
    .def_property_readonly("AttributeToken", &DependentSizedExtVectorType::AttributeToken)
    .def_property_readonly("ElementType", &DependentSizedExtVectorType::ElementType)
    .def_property_readonly("SizeExpression", &DependentSizedExtVectorType::SizeExpression)
    .def_property_readonly("IsSugared", &DependentSizedExtVectorType::IsSugared);
}
} // namespace pasta
