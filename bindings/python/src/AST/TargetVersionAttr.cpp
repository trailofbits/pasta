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

void RegisterTargetVersionAttr(py::module_ &m) {
  py::class_<TargetVersionAttr, Attr, InheritableAttr>(m, "TargetVersionAttr")
    .def_property_readonly("Name", &TargetVersionAttr::Name)
    .def_property_readonly("NamesString", &TargetVersionAttr::NamesString)
    .def_property_readonly("NamesStringLength", &TargetVersionAttr::NamesStringLength)
    .def_property_readonly("Spelling", &TargetVersionAttr::Spelling)
    .def_property_readonly("IsDefaultVersion", &TargetVersionAttr::IsDefaultVersion);
}
} // namespace ogler
