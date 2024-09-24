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

void RegisterObjCArrayLiteral(nb::module_ &m) {
  nb::class_<ObjCArrayLiteral, Expr>(m, "ObjCArrayLiteral")
    .def_prop_ro("children", &ObjCArrayLiteral::Children)
    .def_prop_ro("array_with_objects_method", &ObjCArrayLiteral::ArrayWithObjectsMethod)
    .def_prop_ro("begin_token", &ObjCArrayLiteral::BeginToken)
    .def_prop_ro("end_token", &ObjCArrayLiteral::EndToken)
    .def_prop_ro("num_elements", &ObjCArrayLiteral::NumElements)
    .def_prop_ro("tokens", &ObjCArrayLiteral::Tokens);
}
} // namespace pasta
