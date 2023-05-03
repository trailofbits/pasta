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

void RegisterOSReturnsRetainedOnNonZeroAttr(py::module_ &m) {
  py::class_<OSReturnsRetainedOnNonZeroAttr, Attr, InheritableAttr>(m, "OSReturnsRetainedOnNonZeroAttr")
    .def_property_readonly("Spelling", &OSReturnsRetainedOnNonZeroAttr::Spelling);
}
} // namespace ogler
