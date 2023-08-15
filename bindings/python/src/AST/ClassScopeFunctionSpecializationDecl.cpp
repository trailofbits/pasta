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

void RegisterClassScopeFunctionSpecializationDecl(nb::module_ &m) {
  nb::class_<ClassScopeFunctionSpecializationDecl, Decl>(m, "ClassScopeFunctionSpecializationDecl")
    .def("__hash__", [](const ClassScopeFunctionSpecializationDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("specialization", &ClassScopeFunctionSpecializationDecl::Specialization)
    .def_prop_ro("has_explicit_template_arguments", &ClassScopeFunctionSpecializationDecl::HasExplicitTemplateArguments);
}
} // namespace pasta
