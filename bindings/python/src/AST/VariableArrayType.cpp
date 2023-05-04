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

void RegisterVariableArrayType(py::module_ &m) {
  py::class_<VariableArrayType, ArrayType, Type>(m, "VariableArrayType")
    .def("__hash__", [](const VariableArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const VariableArrayType& a, const VariableArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("Desugar", &VariableArrayType::Desugar)
    .def_property_readonly("BracketsRange", &VariableArrayType::BracketsRange)
    .def_property_readonly("LBracketToken", &VariableArrayType::LBracketToken)
    .def_property_readonly("RBracketToken", &VariableArrayType::RBracketToken)
    .def_property_readonly("SizeExpression", &VariableArrayType::SizeExpression)
    .def_property_readonly("IsSugared", &VariableArrayType::IsSugared);
}
} // namespace pasta
