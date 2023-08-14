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

void RegisterCXXCatchStmt(nb::module_ &m) {
  nb::class_<CXXCatchStmt, Stmt>(m, "CXXCatchStmt")
    .def("__hash__", [](const CXXCatchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXCatchStmt::Children)
    .def_prop_ro("begin_token", &CXXCatchStmt::BeginToken)
    .def_prop_ro("catch_token", &CXXCatchStmt::CatchToken)
    .def_prop_ro("caught_type", &CXXCatchStmt::CaughtType)
    .def_prop_ro("end_token", &CXXCatchStmt::EndToken)
    .def_prop_ro("exception_declaration", &CXXCatchStmt::ExceptionDeclaration)
    .def_prop_ro("handler_block", &CXXCatchStmt::HandlerBlock);
}
} // namespace pasta
