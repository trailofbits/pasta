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

void RegisterXRayInstrumentAttr(py::module_ &m) {
  py::class_<XRayInstrumentAttr, InheritableAttr>(m, "XRayInstrumentAttr")
    .def("__hash__", [](const XRayInstrumentAttr& attr) { return (intptr_t)attr.RawAttr(); })
    .def("__eq__", [](const XRayInstrumentAttr& a, const XRayInstrumentAttr& b) { return a.RawAttr() == b.RawAttr(); })
    .def_property_readonly("AlwaysXRayInstrument", &XRayInstrumentAttr::AlwaysXRayInstrument)
    .def_property_readonly("SemanticSpelling", &XRayInstrumentAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &XRayInstrumentAttr::Spelling)
    .def_property_readonly("NeverXRayInstrument", &XRayInstrumentAttr::NeverXRayInstrument);
}
} // namespace pasta
