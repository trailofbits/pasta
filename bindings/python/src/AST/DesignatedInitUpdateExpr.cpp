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

void RegisterDesignatedInitUpdateExpr(nb::module_ &m) {
  nb::class_<DesignatedInitUpdateExpr, Expr>(m, "DesignatedInitUpdateExpr")
    .def_prop_ro("children", &DesignatedInitUpdateExpr::Children)
    .def_prop_ro("base", &DesignatedInitUpdateExpr::Base)
    .def_prop_ro("begin_token", &DesignatedInitUpdateExpr::BeginToken)
    .def_prop_ro("end_token", &DesignatedInitUpdateExpr::EndToken)
    .def_prop_ro("updater", &DesignatedInitUpdateExpr::Updater);
}
} // namespace pasta
