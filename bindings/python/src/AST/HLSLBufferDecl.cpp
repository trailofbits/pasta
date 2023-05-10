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
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterHLSLBufferDecl(py::module_ &m) {
  py::class_<HLSLBufferDecl, NamedDecl>(m, "HLSLBufferDecl")
    .def("__hash__", [](const HLSLBufferDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const HLSLBufferDecl& a, const HLSLBufferDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("l_brace_token", &HLSLBufferDecl::LBraceToken)
    .def_property_readonly("token_start", &HLSLBufferDecl::TokenStart)
    .def_property_readonly("r_brace_token", &HLSLBufferDecl::RBraceToken)
    .def_property_readonly("is_c_buffer", &HLSLBufferDecl::IsCBuffer);
}
} // namespace pasta
