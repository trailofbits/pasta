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

void RegisterObjCStringLiteral(nb::module_ &m) {
  nb::class_<ObjCStringLiteral, Expr>(m, "ObjCStringLiteral")
    .def_prop_ro("children", &ObjCStringLiteral::Children)
    .def_prop_ro("at_token", &ObjCStringLiteral::AtToken)
    .def_prop_ro("begin_token", &ObjCStringLiteral::BeginToken)
    .def_prop_ro("end_token", &ObjCStringLiteral::EndToken)
    .def_prop_ro("string", &ObjCStringLiteral::String);
}
} // namespace pasta
