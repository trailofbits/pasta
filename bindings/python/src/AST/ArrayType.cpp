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
    .def("__hash__", [](const ArrayType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const ArrayType& a, const ArrayType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("element_type", &ArrayType::ElementType)
    .def_property_readonly("index_type_cvr_qualifiers", &ArrayType::IndexTypeCVRQualifiers)
    .def_property_readonly("size_modifier", &ArrayType::SizeModifier);
}
} // namespace pasta
