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

void RegisterInitSegAttr(py::module_ &m) {
  py::class_<InitSegAttr, Attr>(m, "InitSegAttr")
    .def("__hash__", [](const InitSegAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const InitSegAttr& a, const InitSegAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Section", &InitSegAttr::Section)
    .def_property_readonly("SectionLength", &InitSegAttr::SectionLength)
    .def_property_readonly("Spelling", &InitSegAttr::Spelling);
}
} // namespace pasta
