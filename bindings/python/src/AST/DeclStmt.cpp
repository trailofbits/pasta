/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
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

void RegisterDeclStmt(nb::module_ &m) {
  nb::class_<DeclStmt, Stmt>(m, "DeclStmt")
    .def_prop_ro("children", &DeclStmt::Children)
    .def_prop_ro("declarations", &DeclStmt::Declarations)
    .def_prop_ro("begin_token", &DeclStmt::BeginToken)
    .def_prop_ro("end_token", &DeclStmt::EndToken)
    .def_prop_ro("single_declaration", &DeclStmt::SingleDeclaration)
    .def_prop_ro("is_single_declaration", &DeclStmt::IsSingleDeclaration);
}
} // namespace pasta
