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

void RegisterDeclaratorDecl(nb::module_ &m) {
  nb::class_<DeclaratorDecl, ValueDecl>(m, "DeclaratorDecl")
    .def("__hash__", [](const DeclaratorDecl &decl) { return (intptr_t)decl.RawDecl(); })
    .def("__eq__", [](const Decl &a, const Decl &b) { return a.RawDecl() == b.RawDecl(); })
    .def_prop_ro("begin_token", &DeclaratorDecl::BeginToken)
    .def_prop_ro("first_inner_token", &DeclaratorDecl::FirstInnerToken)
    .def_prop_ro("num_template_parameter_lists", &DeclaratorDecl::NumTemplateParameterLists)
    .def_prop_ro("first_outer_token", &DeclaratorDecl::FirstOuterToken)
    .def_prop_ro("trailing_requires_clause", &DeclaratorDecl::TrailingRequiresClause)
    .def_prop_ro("type", &DeclaratorDecl::Type)
    .def_prop_ro("type_spec_end_token", &DeclaratorDecl::TypeSpecEndToken)
    .def_prop_ro("type_spec_start_token", &DeclaratorDecl::TypeSpecStartToken);
}
} // namespace pasta
