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

void RegisterPragmaCommentDecl(py::module_ &m) {
  py::class_<PragmaCommentDecl, Decl>(m, "PragmaCommentDecl")
    .def("__hash__", [](const PragmaCommentDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("argument", &PragmaCommentDecl::Argument)
    .def_property_readonly("comment_kind", &PragmaCommentDecl::CommentKind);
}
} // namespace pasta
