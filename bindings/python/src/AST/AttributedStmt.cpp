/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterAttributedStmt(nb::module_ &m) {
  nb::class_<AttributedStmt, ValueStmt>(m, "AttributedStmt")
    .def("__hash__", [](const AttributedStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &AttributedStmt::Children)
    .def_prop_ro("attribute_token", &AttributedStmt::AttributeToken)
    .def_prop_ro("attributes", &AttributedStmt::Attributes)
    .def_prop_ro("begin_token", &AttributedStmt::BeginToken)
    .def_prop_ro("end_token", &AttributedStmt::EndToken)
    .def_prop_ro("sub_statement", &AttributedStmt::SubStatement);
}
} // namespace pasta
