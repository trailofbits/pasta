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

void RegisterWeakRefAttr(py::module_ &m) {
  py::class_<WeakRefAttr, Attr, InheritableAttr>(m, "WeakRefAttr")
    .def_property_readonly("Aliasee", &WeakRefAttr::Aliasee)
    .def_property_readonly("AliaseeLength", &WeakRefAttr::AliaseeLength)
    .def_property_readonly("Spelling", &WeakRefAttr::Spelling);
}
} // namespace ogler
