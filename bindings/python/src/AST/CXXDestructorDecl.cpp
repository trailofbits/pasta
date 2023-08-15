/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXDestructorDecl(nb::module_ &m) {
  nb::class_<CXXDestructorDecl, CXXMethodDecl>(m, "CXXDestructorDecl")
    .def("__hash__", [](const CXXDestructorDecl& decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl& a, const Decl& b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("canonical_declaration", &CXXDestructorDecl::CanonicalDeclaration)
    .def_prop_ro("operator_delete", &CXXDestructorDecl::OperatorDelete)
    .def_prop_ro("operator_delete_this_argument", &CXXDestructorDecl::OperatorDeleteThisArgument);
}
} // namespace pasta
