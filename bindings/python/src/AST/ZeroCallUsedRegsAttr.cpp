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

void RegisterZeroCallUsedRegsAttr(py::module_ &m) {
  py::class_<ZeroCallUsedRegsAttr, Attr, InheritableAttr>(m, "ZeroCallUsedRegsAttr")
    .def("__hash__", [](const ZeroCallUsedRegsAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const ZeroCallUsedRegsAttr& a, const ZeroCallUsedRegsAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &ZeroCallUsedRegsAttr::Spelling)
    .def_property_readonly("ZeroCallUsedRegs", &ZeroCallUsedRegsAttr::ZeroCallUsedRegs);
}
} // namespace pasta