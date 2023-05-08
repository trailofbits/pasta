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

void RegisterPragmaDetectMismatchDecl(py::module_ &m) {
  py::class_<PragmaDetectMismatchDecl, Decl>(m, "PragmaDetectMismatchDecl")
    .def("__hash__", [](const PragmaDetectMismatchDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const PragmaDetectMismatchDecl& a, const PragmaDetectMismatchDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("name", &PragmaDetectMismatchDecl::Name)
    .def_property_readonly("value", &PragmaDetectMismatchDecl::Value);
}
} // namespace pasta
