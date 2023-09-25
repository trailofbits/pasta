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

void RegisterCXXConstructExpr(nb::module_ &m) {
  nb::class_<CXXConstructExpr, Expr>(m, "CXXConstructExpr")
    .def("__hash__", [](const CXXConstructExpr& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("arguments", &CXXConstructExpr::Arguments)
    .def_prop_ro("children", &CXXConstructExpr::Children)
    .def_prop_ro("begin_token", &CXXConstructExpr::BeginToken)
    .def_prop_ro("construction_kind", &CXXConstructExpr::ConstructionKind)
    .def_prop_ro("constructor", &CXXConstructExpr::Constructor)
    .def_prop_ro("end_token", &CXXConstructExpr::EndToken)
    .def_prop_ro("token", &CXXConstructExpr::Token)
    .def_prop_ro("num_arguments", &CXXConstructExpr::NumArguments)
    .def_prop_ro("parenthesis_or_brace_range", &CXXConstructExpr::ParenthesisOrBraceRange)
    .def_prop_ro("had_multiple_candidates", &CXXConstructExpr::HadMultipleCandidates)
    .def_prop_ro("is_elidable", &CXXConstructExpr::IsElidable)
    .def_prop_ro("is_immediate_escalating", &CXXConstructExpr::IsImmediateEscalating)
    .def_prop_ro("is_list_initialization", &CXXConstructExpr::IsListInitialization)
    .def_prop_ro("is_std_initializer_list_initialization", &CXXConstructExpr::IsStdInitializerListInitialization)
    .def_prop_ro("requires_zero_initialization", &CXXConstructExpr::RequiresZeroInitialization);
}
} // namespace pasta
