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

void RegisterArrayType(py::module_ &m) {
  py::class_<ArrayType, Type>(m, "ArrayType")
    .def_property_readonly("ElementType", &ArrayType::ElementType)
    .def_property_readonly("IndexTypeCVRQualifiers", &ArrayType::IndexTypeCVRQualifiers)
    .def_property_readonly("SizeModifier", &ArrayType::SizeModifier);
}
} // namespace pasta
