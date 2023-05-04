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

void RegisterMSPropertyDecl(py::module_ &m) {
  py::class_<MSPropertyDecl, Decl, DeclaratorDecl, NamedDecl, ValueDecl>(m, "MSPropertyDecl")
    .def("__hash__", [](const MSPropertyDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const MSPropertyDecl& a, const MSPropertyDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("HasGetter", &MSPropertyDecl::HasGetter)
    .def_property_readonly("HasSetter", &MSPropertyDecl::HasSetter);
}
} // namespace pasta
