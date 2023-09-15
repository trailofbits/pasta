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

void RegisterStaticAssertDecl(nb::module_ &m) {
  nb::class_<StaticAssertDecl, Decl>(m, "StaticAssertDecl")
    .def("__hash__", [](const StaticAssertDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("assert_expression", &StaticAssertDecl::AssertExpression)
    .def_prop_ro("message", &StaticAssertDecl::Message)
    .def_prop_ro("r_paren_token", &StaticAssertDecl::RParenToken)
    .def_prop_ro("is_failed", &StaticAssertDecl::IsFailed);
}
} // namespace pasta
