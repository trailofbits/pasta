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

void RegisterObjCStringLiteral(nb::module_ &m) {
  nb::class_<ObjCStringLiteral, Expr>(m, "ObjCStringLiteral")
    .def("__hash__", [](const ObjCStringLiteral& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCStringLiteral::Children)
    .def_prop_ro("at_token", &ObjCStringLiteral::AtToken)
    .def_prop_ro("begin_token", &ObjCStringLiteral::BeginToken)
    .def_prop_ro("end_token", &ObjCStringLiteral::EndToken)
    .def_prop_ro("string", &ObjCStringLiteral::String);
}
} // namespace pasta
