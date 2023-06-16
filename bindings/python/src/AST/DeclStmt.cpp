/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <nanobind/nanobind.h>
#include <nanobind/stl/optional.h>
#include <nanobind/stl/vector.h>

namespace pasta {
namespace nb = nanobind;

void RegisterDeclStmt(nb::module_ &m) {
  nb::class_<DeclStmt, Stmt>(m, "DeclStmt")
    .def("__hash__", [](const DeclStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &DeclStmt::Children)
    .def_prop_ro("declarations", &DeclStmt::Declarations)
    .def_prop_ro("begin_token", &DeclStmt::BeginToken)
    .def_prop_ro("end_token", &DeclStmt::EndToken)
    .def_prop_ro("single_declaration", &DeclStmt::SingleDeclaration)
    .def_prop_ro("is_single_declaration", &DeclStmt::IsSingleDeclaration);
}
} // namespace pasta
