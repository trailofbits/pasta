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

void RegisterVecTypeHintAttr(py::module_ &m) {
  py::class_<VecTypeHintAttr, Attr, InheritableAttr>(m, "VecTypeHintAttr")
    .def_property_readonly("Spelling", &VecTypeHintAttr::Spelling)
    .def_property_readonly("TypeHint", &VecTypeHintAttr::TypeHint)
    .def_property_readonly("TypeHintToken", &VecTypeHintAttr::TypeHintToken);
}
} // namespace pasta
