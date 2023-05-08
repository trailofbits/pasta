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
  py::class_<DependentSizedArrayType, ArrayType>(m, "DependentSizedArrayType")
    .def("__hash__", [](const DependentSizedArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const DependentSizedArrayType& a, const DependentSizedArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &DependentSizedArrayType::Desugar)
    .def_property_readonly("brackets_range", &DependentSizedArrayType::BracketsRange)
    .def_property_readonly("l_bracket_token", &DependentSizedArrayType::LBracketToken)
    .def_property_readonly("r_bracket_token", &DependentSizedArrayType::RBracketToken)
    .def_property_readonly("size_expression", &DependentSizedArrayType::SizeExpression)
    .def_property_readonly("is_sugared", &DependentSizedArrayType::IsSugared);
}
} // namespace pasta
