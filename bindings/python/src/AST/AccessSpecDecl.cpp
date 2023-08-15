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

void RegisterAccessSpecDecl(nb::module_ &m) {
  nb::class_<AccessSpecDecl, Decl>(m, "AccessSpecDecl")
    .def("__hash__", [](const AccessSpecDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("access_specifier_token", &AccessSpecDecl::AccessSpecifierToken)
    .def_prop_ro("colon_token", &AccessSpecDecl::ColonToken);
}
} // namespace pasta
