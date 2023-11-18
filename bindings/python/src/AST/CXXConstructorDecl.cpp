/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCXXConstructorDecl(nb::module_ &m) {
  nb::class_<CXXConstructorDecl, CXXMethodDecl>(m, "CXXConstructorDecl")
    .def_prop_ro("canonical_declaration", &CXXConstructorDecl::CanonicalDeclaration)
    .def_prop_ro("num_constructor_initializers", &CXXConstructorDecl::NumConstructorInitializers)
    .def_prop_ro("target_constructor", &CXXConstructorDecl::TargetConstructor)
    .def_prop_ro("is_converting_constructor", &CXXConstructorDecl::IsConvertingConstructor)
    .def_prop_ro("is_default_constructor", &CXXConstructorDecl::IsDefaultConstructor)
    .def_prop_ro("is_delegating_constructor", &CXXConstructorDecl::IsDelegatingConstructor)
    .def_prop_ro("is_explicit", &CXXConstructorDecl::IsExplicit)
    .def_prop_ro("is_inheriting_constructor", &CXXConstructorDecl::IsInheritingConstructor)
    .def_prop_ro("is_specialization_copying_object", &CXXConstructorDecl::IsSpecializationCopyingObject);
}
} // namespace pasta
