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

void RegisterAddrLabelExpr(nb::module_ &m) {
  nb::class_<AddrLabelExpr, Expr>(m, "AddrLabelExpr")
    .def("__hash__", [](const AddrLabelExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &AddrLabelExpr::Children)
    .def_prop_ro("amp_amp_token", &AddrLabelExpr::AmpAmpToken)
    .def_prop_ro("begin_token", &AddrLabelExpr::BeginToken)
    .def_prop_ro("end_token", &AddrLabelExpr::EndToken)
    .def_prop_ro("label", &AddrLabelExpr::Label)
    .def_prop_ro("label_token", &AddrLabelExpr::LabelToken);
}
} // namespace pasta
