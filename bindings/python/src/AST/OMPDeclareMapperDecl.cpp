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

void RegisterOMPDeclareMapperDecl(py::module_ &m) {
  py::class_<OMPDeclareMapperDecl, Decl, NamedDecl, OMPDeclarativeDirectiveValueDecl, ValueDecl>(m, "OMPDeclareMapperDecl")
    .def("__hash__", [](const OMPDeclareMapperDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const OMPDeclareMapperDecl& a, const OMPDeclareMapperDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("MapperVariableReference", &OMPDeclareMapperDecl::MapperVariableReference)
    .def_property_readonly("PrevDeclarationInScope", &OMPDeclareMapperDecl::PrevDeclarationInScope);
}
} // namespace pasta
