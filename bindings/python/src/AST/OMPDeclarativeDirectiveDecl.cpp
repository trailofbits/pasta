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

void RegisterOMPDeclarativeDirectiveDecl(py::module_ &m) {
  py::class_<OMPDeclarativeDirectiveDecl, Decl>(m, "OMPDeclarativeDirectiveDecl")
    .def("__hash__", [](const OMPDeclarativeDirectiveDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const OMPDeclarativeDirectiveDecl& a, const OMPDeclarativeDirectiveDecl& b) { return a.RawDecl() == b.RawDecl(); });
}
} // namespace pasta
