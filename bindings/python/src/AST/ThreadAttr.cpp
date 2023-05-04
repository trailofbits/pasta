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

void RegisterThreadAttr(py::module_ &m) {
  py::class_<ThreadAttr, Attr>(m, "ThreadAttr")
    .def("__hash__", [](const ThreadAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ThreadAttr& a, const ThreadAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ThreadAttr::Spelling);
}
} // namespace pasta
