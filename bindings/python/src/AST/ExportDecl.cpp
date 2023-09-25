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

void RegisterExportDecl(nb::module_ &m) {
  nb::class_<ExportDecl, Decl>(m, "ExportDecl")
    .def("__hash__", [](const ExportDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("end_token", &ExportDecl::EndToken)
    .def_prop_ro("export_token", &ExportDecl::ExportToken)
    .def_prop_ro("r_brace_token", &ExportDecl::RBraceToken)
    .def_prop_ro("has_braces", &ExportDecl::HasBraces);
}
} // namespace pasta
