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

void RegisterBaseUsingDecl(py::module_ &m) {
  py::class_<BaseUsingDecl, NamedDecl>(m, "BaseUsingDecl")
    .def("__hash__", [](const BaseUsingDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const BaseUsingDecl& a, const BaseUsingDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("shadows", &BaseUsingDecl::Shadows);
}
} // namespace pasta
