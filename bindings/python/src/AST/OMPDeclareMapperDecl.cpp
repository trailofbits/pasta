/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterOMPDeclareMapperDecl(nb::module_ &m) {
  nb::class_<OMPDeclareMapperDecl, OMPDeclarativeDirectiveValueDecl>(m, "OMPDeclareMapperDecl")
    .def("__hash__", [](const OMPDeclareMapperDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("mapper_variable_reference", &OMPDeclareMapperDecl::MapperVariableReference)
    .def_prop_ro("prev_declaration_in_scope", &OMPDeclareMapperDecl::PrevDeclarationInScope);
}
} // namespace pasta
