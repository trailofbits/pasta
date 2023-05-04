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

void RegisterBuiltinTemplateDecl(py::module_ &m) {
  py::class_<BuiltinTemplateDecl, Decl, NamedDecl, TemplateDecl>(m, "BuiltinTemplateDecl")
    .def("__hash__", [](const BuiltinTemplateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const BuiltinTemplateDecl& a, const BuiltinTemplateDecl& b) { return a.RawDecl() == b.RawDecl(); });
}
} // namespace pasta