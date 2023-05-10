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

void RegisterModeAttr(py::module_ &m) {
  py::class_<ModeAttr, Attr>(m, "ModeAttr")
    .def("__hash__", [](const ModeAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ModeAttr& a, const ModeAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &ModeAttr::Spelling);
}
} // namespace pasta
