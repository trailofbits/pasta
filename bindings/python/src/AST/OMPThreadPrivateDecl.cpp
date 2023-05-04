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

void RegisterOMPThreadPrivateDecl(py::module_ &m) {
  py::class_<OMPThreadPrivateDecl, Decl, OMPDeclarativeDirectiveDecl>(m, "OMPThreadPrivateDecl")
    .def("__hash__", [](const OMPThreadPrivateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const OMPThreadPrivateDecl& a, const OMPThreadPrivateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Varlists", &OMPThreadPrivateDecl::Varlists);
}
} // namespace pasta
