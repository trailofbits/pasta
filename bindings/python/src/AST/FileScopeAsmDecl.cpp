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

void RegisterFileScopeAsmDecl(nb::module_ &m) {
  nb::class_<FileScopeAsmDecl, Decl>(m, "FileScopeAsmDecl")
    .def_prop_ro("assembly_token", &FileScopeAsmDecl::AssemblyToken)
    .def_prop_ro("assembly_string", &FileScopeAsmDecl::AssemblyString)
    .def_prop_ro("r_paren_token", &FileScopeAsmDecl::RParenToken);
}
} // namespace pasta
