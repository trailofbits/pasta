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

void RegisterReturnStmt(nb::module_ &m) {
  nb::class_<ReturnStmt, Stmt>(m, "ReturnStmt")
    .def("__hash__", [](const ReturnStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &ReturnStmt::Children)
    .def_prop_ro("begin_token", &ReturnStmt::BeginToken)
    .def_prop_ro("end_token", &ReturnStmt::EndToken)
    .def_prop_ro("nrvo_candidate", &ReturnStmt::NRVOCandidate)
    .def_prop_ro("return_value", &ReturnStmt::ReturnValue)
    .def_prop_ro("return_token", &ReturnStmt::ReturnToken);
}
} // namespace pasta
