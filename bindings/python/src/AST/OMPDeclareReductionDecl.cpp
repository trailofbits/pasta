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

void RegisterOMPDeclareReductionDecl(py::module_ &m) {
  py::class_<OMPDeclareReductionDecl, Decl, NamedDecl, ValueDecl>(m, "OMPDeclareReductionDecl")
    .def("__hash__", [](const OMPDeclareReductionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const OMPDeclareReductionDecl& a, const OMPDeclareReductionDecl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("Combiner", &OMPDeclareReductionDecl::Combiner)
    .def_property_readonly("CombinerIn", &OMPDeclareReductionDecl::CombinerIn)
    .def_property_readonly("CombinerOut", &OMPDeclareReductionDecl::CombinerOut)
    .def_property_readonly("InitializerOriginal", &OMPDeclareReductionDecl::InitializerOriginal)
    .def_property_readonly("InitializerPrivate", &OMPDeclareReductionDecl::InitializerPrivate)
    .def_property_readonly("Initializer", &OMPDeclareReductionDecl::Initializer)
    .def_property_readonly("InitializerKind", &OMPDeclareReductionDecl::InitializerKind)
    .def_property_readonly("PrevDeclarationInScope", &OMPDeclareReductionDecl::PrevDeclarationInScope);
}
} // namespace pasta
