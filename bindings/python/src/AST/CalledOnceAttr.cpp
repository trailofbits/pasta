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

void RegisterCalledOnceAttr(py::module_ &m) {
  py::class_<CalledOnceAttr, Attr>(m, "CalledOnceAttr")
    .def("__hash__", [](const CalledOnceAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const CalledOnceAttr& a, const CalledOnceAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &CalledOnceAttr::Spelling);
}
} // namespace pasta
