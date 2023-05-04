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

void RegisterDependentSizedArrayType(py::module_ &m) {
  py::class_<DependentSizedArrayType, ArrayType, Type>(m, "DependentSizedArrayType")
    .def("__hash__", [](const DependentSizedArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentSizedArrayType& a, const DependentSizedArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &DependentSizedArrayType::Desugar)
    .def_property_readonly("BracketsRange", &DependentSizedArrayType::BracketsRange)
    .def_property_readonly("LBracketToken", &DependentSizedArrayType::LBracketToken)
    .def_property_readonly("RBracketToken", &DependentSizedArrayType::RBracketToken)
    .def_property_readonly("SizeExpression", &DependentSizedArrayType::SizeExpression)
    .def_property_readonly("IsSugared", &DependentSizedArrayType::IsSugared);
}
} // namespace pasta
