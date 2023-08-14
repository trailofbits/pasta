/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPDeclareReductionDecl(nb::module_ &m) {
  nb::class_<OMPDeclareReductionDecl, ValueDecl>(m, "OMPDeclareReductionDecl")
    .def("__hash__", [](const OMPDeclareReductionDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("combiner", &OMPDeclareReductionDecl::Combiner)
    .def_prop_ro("combiner_in", &OMPDeclareReductionDecl::CombinerIn)
    .def_prop_ro("combiner_out", &OMPDeclareReductionDecl::CombinerOut)
    .def_prop_ro("initializer_original", &OMPDeclareReductionDecl::InitializerOriginal)
    .def_prop_ro("initializer_private", &OMPDeclareReductionDecl::InitializerPrivate)
    .def_prop_ro("initializer", &OMPDeclareReductionDecl::Initializer)
    .def_prop_ro("initializer_kind", &OMPDeclareReductionDecl::InitializerKind)
    .def_prop_ro("prev_declaration_in_scope", &OMPDeclareReductionDecl::PrevDeclarationInScope);
}
} // namespace pasta
