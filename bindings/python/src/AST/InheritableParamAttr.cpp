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

void RegisterInheritableParamAttr(py::module_ &m) {
  py::class_<InheritableParamAttr, InheritableAttr>(m, "InheritableParamAttr")
    .def("__hash__", [](const InheritableParamAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const InheritableParamAttr& a, const InheritableParamAttr& b) { return a.RawAttr() == b.RawAttr(); });
}
} // namespace pasta
