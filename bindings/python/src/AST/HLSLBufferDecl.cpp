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

void RegisterHLSLBufferDecl(py::module_ &m) {
  py::class_<HLSLBufferDecl, Decl, NamedDecl>(m, "HLSLBufferDecl")
    .def_property_readonly("LBraceToken", &HLSLBufferDecl::LBraceToken)
    .def_property_readonly("TokenStart", &HLSLBufferDecl::TokenStart)
    .def_property_readonly("RBraceToken", &HLSLBufferDecl::RBraceToken)
    .def_property_readonly("IsCBuffer", &HLSLBufferDecl::IsCBuffer);
}
} // namespace pasta
