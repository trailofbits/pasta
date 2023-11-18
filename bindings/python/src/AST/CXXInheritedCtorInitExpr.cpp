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

void RegisterCXXInheritedCtorInitExpr(nb::module_ &m) {
  nb::class_<CXXInheritedCtorInitExpr, Expr>(m, "CXXInheritedCtorInitExpr")
    .def_prop_ro("children", &CXXInheritedCtorInitExpr::Children)
    .def_prop_ro("constructs_virtual_base", &CXXInheritedCtorInitExpr::ConstructsVirtualBase)
    .def_prop_ro("begin_token", &CXXInheritedCtorInitExpr::BeginToken)
    .def_prop_ro("construction_kind", &CXXInheritedCtorInitExpr::ConstructionKind)
    .def_prop_ro("constructor", &CXXInheritedCtorInitExpr::Constructor)
    .def_prop_ro("end_token", &CXXInheritedCtorInitExpr::EndToken)
    .def_prop_ro("token", &CXXInheritedCtorInitExpr::Token)
    .def_prop_ro("inherited_from_virtual_base", &CXXInheritedCtorInitExpr::InheritedFromVirtualBase);
}
} // namespace pasta
