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

void RegisterOMPDeclareReductionDecl(py::module_ &m) {
  py::class_<OMPDeclareReductionDecl, ValueDecl>(m, "OMPDeclareReductionDecl")
    .def("__hash__", [](const OMPDeclareReductionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_property_readonly("combiner", &OMPDeclareReductionDecl::Combiner)
    .def_property_readonly("combiner_in", &OMPDeclareReductionDecl::CombinerIn)
    .def_property_readonly("combiner_out", &OMPDeclareReductionDecl::CombinerOut)
    .def_property_readonly("initializer_original", &OMPDeclareReductionDecl::InitializerOriginal)
    .def_property_readonly("initializer_private", &OMPDeclareReductionDecl::InitializerPrivate)
    .def_property_readonly("initializer", &OMPDeclareReductionDecl::Initializer)
    .def_property_readonly("initializer_kind", &OMPDeclareReductionDecl::InitializerKind)
    .def_property_readonly("prev_declaration_in_scope", &OMPDeclareReductionDecl::PrevDeclarationInScope);
}
} // namespace pasta
