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

void RegisterFormatArgAttr(py::module_ &m) {
  py::class_<FormatArgAttr, Attr, InheritableAttr>(m, "FormatArgAttr")
    .def_property_readonly("Spelling", &FormatArgAttr::Spelling);
}
} // namespace ogler
