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

void RegisterCapturedDecl(py::module_ &m) {
  py::class_<CapturedDecl, Decl>(m, "CapturedDecl")
    .def_property_readonly("ContextParameter", &CapturedDecl::ContextParameter)
    .def_property_readonly("ContextParameterPosition", &CapturedDecl::ContextParameterPosition)
    .def_property_readonly("NumParameters", &CapturedDecl::NumParameters)
    .def_property_readonly("IsNothrow", &CapturedDecl::IsNothrow)
    .def_property_readonly("Parameters", &CapturedDecl::Parameters);
}
} // namespace pasta
