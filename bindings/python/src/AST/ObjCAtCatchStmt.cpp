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

void RegisterObjCAtCatchStmt(nb::module_ &m) {
  nb::class_<ObjCAtCatchStmt, Stmt>(m, "ObjCAtCatchStmt")
    .def("__hash__", [](const ObjCAtCatchStmt& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCAtCatchStmt::Children)
    .def_prop_ro("at_catch_token", &ObjCAtCatchStmt::AtCatchToken)
    .def_prop_ro("begin_token", &ObjCAtCatchStmt::BeginToken)
    .def_prop_ro("catch_body", &ObjCAtCatchStmt::CatchBody)
    .def_prop_ro("catch_parameter_declaration", &ObjCAtCatchStmt::CatchParameterDeclaration)
    .def_prop_ro("end_token", &ObjCAtCatchStmt::EndToken)
    .def_prop_ro("r_paren_token", &ObjCAtCatchStmt::RParenToken)
    .def_prop_ro("has_ellipsis", &ObjCAtCatchStmt::HasEllipsis);
}
} // namespace pasta
