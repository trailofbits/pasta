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

void RegisterMSDependentExistsStmt(nb::module_ &m) {
  nb::class_<MSDependentExistsStmt, Stmt>(m, "MSDependentExistsStmt")
    .def("__hash__", [](const MSDependentExistsStmt& stmt) { return reinterpret_cast<intptr_t>(stmt.RawStmt()); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &MSDependentExistsStmt::Children)
    .def_prop_ro("begin_token", &MSDependentExistsStmt::BeginToken)
    .def_prop_ro("end_token", &MSDependentExistsStmt::EndToken)
    .def_prop_ro("keyword_token", &MSDependentExistsStmt::KeywordToken)
    .def_prop_ro("sub_statement", &MSDependentExistsStmt::SubStatement)
    .def_prop_ro("is_if_exists", &MSDependentExistsStmt::IsIfExists)
    .def_prop_ro("is_if_not_exists", &MSDependentExistsStmt::IsIfNotExists);
}
} // namespace pasta
