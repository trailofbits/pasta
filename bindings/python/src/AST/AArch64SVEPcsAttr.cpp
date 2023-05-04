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

void RegisterAArch64SVEPcsAttr(py::module_ &m) {
  py::class_<AArch64SVEPcsAttr, Attr, InheritableAttr>(m, "AArch64SVEPcsAttr")
    .def("__hash__", [](const AArch64SVEPcsAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const AArch64SVEPcsAttr& a, const AArch64SVEPcsAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("Spelling", &AArch64SVEPcsAttr::Spelling);
}
} // namespace pasta
