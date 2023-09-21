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

void RegisterBindingDecl(nb::module_ &m) {
  nb::class_<BindingDecl, ValueDecl>(m, "BindingDecl")
    .def("__hash__", [](const BindingDecl &decl) { return reinterpret_cast<intptr_t>(decl.RawDecl()); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("binding", &BindingDecl::Binding)
    .def_prop_ro("decomposed_declaration", &BindingDecl::DecomposedDeclaration)
    .def_prop_ro("holding_variable", &BindingDecl::HoldingVariable);
}
} // namespace pasta
