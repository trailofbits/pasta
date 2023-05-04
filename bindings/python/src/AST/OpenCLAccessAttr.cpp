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

void RegisterOpenCLAccessAttr(py::module_ &m) {
  py::class_<OpenCLAccessAttr, Attr>(m, "OpenCLAccessAttr")
    .def_property_readonly("SemanticSpelling", &OpenCLAccessAttr::SemanticSpelling)
    .def_property_readonly("Spelling", &OpenCLAccessAttr::Spelling)
    .def_property_readonly("IsReadOnly", &OpenCLAccessAttr::IsReadOnly)
    .def_property_readonly("IsReadWrite", &OpenCLAccessAttr::IsReadWrite)
    .def_property_readonly("IsWriteOnly", &OpenCLAccessAttr::IsWriteOnly);
}
} // namespace pasta
