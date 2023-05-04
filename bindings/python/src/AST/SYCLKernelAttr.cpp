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

void RegisterSYCLKernelAttr(py::module_ &m) {
  py::class_<SYCLKernelAttr, Attr, InheritableAttr>(m, "SYCLKernelAttr")
    .def_property_readonly("Spelling", &SYCLKernelAttr::Spelling);
}
} // namespace pasta
