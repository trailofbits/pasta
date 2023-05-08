/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterAddrLabelExpr(py::module_ &m) {
  py::class_<AddrLabelExpr, Expr>(m, "AddrLabelExpr")
    .def("__hash__", [](const AddrLabelExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const AddrLabelExpr& a, const AddrLabelExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &AddrLabelExpr::Children)
    .def_property_readonly("amp_amp_token", &AddrLabelExpr::AmpAmpToken)
    .def_property_readonly("begin_token", &AddrLabelExpr::BeginToken)
    .def_property_readonly("end_token", &AddrLabelExpr::EndToken)
    .def_property_readonly("label", &AddrLabelExpr::Label)
    .def_property_readonly("label_token", &AddrLabelExpr::LabelToken);
}
} // namespace pasta
