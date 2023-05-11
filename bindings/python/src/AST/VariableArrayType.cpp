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

void RegisterVariableArrayType(py::module_ &m) {
  py::class_<VariableArrayType, ArrayType>(m, "VariableArrayType")
    .def("__hash__", [](const VariableArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type& a, const Type& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &VariableArrayType::Desugar)
    .def_property_readonly("brackets_range", &VariableArrayType::BracketsRange)
    .def_property_readonly("l_bracket_token", &VariableArrayType::LBracketToken)
    .def_property_readonly("r_bracket_token", &VariableArrayType::RBracketToken)
    .def_property_readonly("size_expression", &VariableArrayType::SizeExpression)
    .def_property_readonly("is_sugared", &VariableArrayType::IsSugared);
}
} // namespace pasta
