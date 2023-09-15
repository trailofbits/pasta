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

void RegisterPragmaDetectMismatchDecl(nb::module_ &m) {
  nb::class_<PragmaDetectMismatchDecl, Decl>(m, "PragmaDetectMismatchDecl")
    .def("__hash__", [](const PragmaDetectMismatchDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("name", &PragmaDetectMismatchDecl::Name)
    .def_prop_ro("value", &PragmaDetectMismatchDecl::Value);
}
} // namespace pasta
