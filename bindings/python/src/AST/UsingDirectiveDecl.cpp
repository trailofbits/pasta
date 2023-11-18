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

void RegisterUsingDirectiveDecl(nb::module_ &m) {
  nb::class_<UsingDirectiveDecl, NamedDecl>(m, "UsingDirectiveDecl")
    .def_prop_ro("common_ancestor", &UsingDirectiveDecl::CommonAncestor)
    .def_prop_ro("identifier_token", &UsingDirectiveDecl::IdentifierToken)
    .def_prop_ro("namespace_key_token", &UsingDirectiveDecl::NamespaceKeyToken)
    .def_prop_ro("nominated_namespace", &UsingDirectiveDecl::NominatedNamespace)
    .def_prop_ro("nominated_namespace_as_written", &UsingDirectiveDecl::NominatedNamespaceAsWritten)
    .def_prop_ro("using_token", &UsingDirectiveDecl::UsingToken);
}
} // namespace pasta
