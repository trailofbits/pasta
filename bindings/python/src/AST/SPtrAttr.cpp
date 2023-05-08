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

void RegisterSPtrAttr(py::module_ &m) {
  py::class_<SPtrAttr, TypeAttr>(m, "SPtrAttr")
    .def("__hash__", [](const SPtrAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const SPtrAttr& a, const SPtrAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("spelling", &SPtrAttr::Spelling);
}
} // namespace pasta
