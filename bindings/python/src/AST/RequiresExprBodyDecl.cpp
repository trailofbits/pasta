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

void RegisterRequiresExprBodyDecl(nb::module_ &m) {
  nb::class_<RequiresExprBodyDecl, Decl>(m, "RequiresExprBodyDecl")
    .def("__hash__", [](const RequiresExprBodyDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); });
}
} // namespace pasta
