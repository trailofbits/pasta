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

void RegisterTagType(py::module_ &m) {
  py::class_<TagType, Type>(m, "TagType")
    .def("__hash__", [](const TagType& type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const TagType& a, const TagType& b) { return a.RawType() == b.RawType(); })
    .def_property_readonly("declaration", &TagType::Declaration)
    .def_property_readonly("is_being_defined", &TagType::IsBeingDefined);
}
} // namespace pasta
