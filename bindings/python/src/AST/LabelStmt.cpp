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

void RegisterLabelStmt(nb::module_ &m) {
  nb::class_<LabelStmt, ValueStmt>(m, "LabelStmt")
    .def("__hash__", [](const LabelStmt& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &LabelStmt::Children)
    .def_prop_ro("begin_token", &LabelStmt::BeginToken)
    .def_prop_ro("declaration", &LabelStmt::Declaration)
    .def_prop_ro("end_token", &LabelStmt::EndToken)
    .def_prop_ro("identifier_token", &LabelStmt::IdentifierToken)
    .def_prop_ro("name", &LabelStmt::Name)
    .def_prop_ro("sub_statement", &LabelStmt::SubStatement)
    .def_prop_ro("is_side_entry", &LabelStmt::IsSideEntry);
}
} // namespace pasta
