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

void RegisterCFConsumedAttr(py::module_ &m) {
  py::class_<CFConsumedAttr, InheritableParamAttr>(m, "CFConsumedAttr")
    .def("__hash__", [](const CFConsumedAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CFConsumedAttr& a, const CFConsumedAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &CFConsumedAttr::Spelling);
}
} // namespace pasta
