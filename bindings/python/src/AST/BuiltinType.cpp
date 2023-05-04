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

void RegisterBuiltinType(py::module_ &m) {
  py::class_<BuiltinType, Type>(m, "BuiltinType")
    .def_property_readonly("Desugar", &BuiltinType::Desugar)
    .def_property_readonly("Kind", &BuiltinType::Kind)
    .def_property_readonly("IsFloatingPoint", &BuiltinType::IsFloatingPoint)
    .def_property_readonly("IsInteger", &BuiltinType::IsInteger)
    .def_property_readonly("IsNonOverloadPlaceholderType", &BuiltinType::IsNonOverloadPlaceholderType)
    .def_property_readonly("IsPlaceholderType", &BuiltinType::IsPlaceholderType)
    .def_property_readonly("IsSVEBool", &BuiltinType::IsSVEBool)
    .def_property_readonly("IsSignedInteger", &BuiltinType::IsSignedInteger)
    .def_property_readonly("IsSugared", &BuiltinType::IsSugared)
    .def_property_readonly("IsUnsignedInteger", &BuiltinType::IsUnsignedInteger);
}
} // namespace pasta
