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

void RegisterSEHTryStmt(nb::module_ &m) {
  nb::class_<SEHTryStmt, Stmt>(m, "SEHTryStmt")
    .def("__hash__", [](const SEHTryStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &SEHTryStmt::Children)
    .def_prop_ro("begin_token", &SEHTryStmt::BeginToken)
    .def_prop_ro("end_token", &SEHTryStmt::EndToken)
    .def_prop_ro("except_handler", &SEHTryStmt::ExceptHandler)
    .def_prop_ro("finally_handler", &SEHTryStmt::FinallyHandler)
    .def_prop_ro("handler", &SEHTryStmt::Handler)
    .def_prop_ro("is_cxx_try", &SEHTryStmt::IsCXXTry)
    .def_prop_ro("try_block", &SEHTryStmt::TryBlock)
    .def_prop_ro("try_token", &SEHTryStmt::TryToken);
}
} // namespace pasta
