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

void RegisterTypeDecl(nb::module_ &m) {
  nb::class_<TypeDecl, NamedDecl>(m, "TypeDecl")
    .def_prop_ro("begin_token", &TypeDecl::BeginToken)
    .def_prop_ro("type_for_declaration", &TypeDecl::TypeForDeclaration);
}
} // namespace pasta
