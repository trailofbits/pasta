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

void RegisterOMPAllocateDecl(py::module_ &m) {
  py::class_<OMPAllocateDecl, OMPDeclarativeDirectiveDecl>(m, "OMPAllocateDecl")
    .def("__hash__", [](const OMPAllocateDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const OMPAllocateDecl& a, const OMPAllocateDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("varlists", &OMPAllocateDecl::Varlists);
}
} // namespace pasta
