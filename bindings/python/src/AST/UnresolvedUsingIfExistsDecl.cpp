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

void RegisterUnresolvedUsingIfExistsDecl(py::module_ &m) {
  py::class_<UnresolvedUsingIfExistsDecl, NamedDecl>(m, "UnresolvedUsingIfExistsDecl")
    .def("__hash__", [](const UnresolvedUsingIfExistsDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UnresolvedUsingIfExistsDecl& a, const UnresolvedUsingIfExistsDecl& b) { return a.RawDecl() == b.RawDecl(); });
}
} // namespace pasta
