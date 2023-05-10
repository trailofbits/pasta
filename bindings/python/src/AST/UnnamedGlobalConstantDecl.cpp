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

void RegisterUnnamedGlobalConstantDecl(py::module_ &m) {
  py::class_<UnnamedGlobalConstantDecl, ValueDecl>(m, "UnnamedGlobalConstantDecl")
    .def("__hash__", [](const UnnamedGlobalConstantDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const UnnamedGlobalConstantDecl& a, const UnnamedGlobalConstantDecl& b) { return a.RawDecl() == b.RawDecl(); });
}
} // namespace pasta
