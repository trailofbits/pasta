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

void RegisterHLSLSV_DispatchThreadIDAttr(py::module_ &m) {
  py::class_<HLSLSV_DispatchThreadIDAttr, Attr, HLSLAnnotationAttr, InheritableAttr>(m, "HLSLSV_DispatchThreadIDAttr")
    .def_property_readonly("Spelling", &HLSLSV_DispatchThreadIDAttr::Spelling);
}
} // namespace ogler
