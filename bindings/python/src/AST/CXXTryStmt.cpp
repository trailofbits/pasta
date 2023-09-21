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

void RegisterCXXTryStmt(nb::module_ &m) {
  nb::class_<CXXTryStmt, Stmt>(m, "CXXTryStmt")
    .def("__hash__", [](const CXXTryStmt& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &CXXTryStmt::Children)
    .def_prop_ro("begin_token", &CXXTryStmt::BeginToken)
    .def_prop_ro("end_token", &CXXTryStmt::EndToken)
    .def_prop_ro("num_handlers", &CXXTryStmt::NumHandlers)
    .def_prop_ro("try_block", &CXXTryStmt::TryBlock)
    .def_prop_ro("try_token", &CXXTryStmt::TryToken);
}
} // namespace pasta
