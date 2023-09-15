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

void RegisterObjCArrayLiteral(nb::module_ &m) {
  nb::class_<ObjCArrayLiteral, Expr>(m, "ObjCArrayLiteral")
    .def("__hash__", [](const ObjCArrayLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ObjCArrayLiteral::Children)
    .def_prop_ro("array_with_objects_method", &ObjCArrayLiteral::ArrayWithObjectsMethod)
    .def_prop_ro("begin_token", &ObjCArrayLiteral::BeginToken)
    .def_prop_ro("end_token", &ObjCArrayLiteral::EndToken)
    .def_prop_ro("num_elements", &ObjCArrayLiteral::NumElements)
    .def_prop_ro("tokens", &ObjCArrayLiteral::Tokens);
}
} // namespace pasta
