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

void RegisterEnumType(py::module_ &m) {
  py::class_<EnumType, TagType>(m, "EnumType")
    .def("__hash__", [](const EnumType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const EnumType& a, const EnumType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("desugar", &EnumType::Desugar)
    .def_property_readonly("declaration", &EnumType::Declaration)
    .def_property_readonly("is_sugared", &EnumType::IsSugared);
}
} // namespace pasta
