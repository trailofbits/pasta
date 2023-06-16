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

void RegisterInitListExpr(nb::module_ &m) {
  nb::class_<InitListExpr, Expr>(m, "InitListExpr")
    .def("__hash__", [](const InitListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &InitListExpr::Children)
    .def_prop_ro("array_filler", &InitListExpr::ArrayFiller)
    .def_prop_ro("begin_token", &InitListExpr::BeginToken)
    .def_prop_ro("end_token", &InitListExpr::EndToken)
    .def_prop_ro("initialized_field_in_union", &InitListExpr::InitializedFieldInUnion)
    .def_prop_ro("l_brace_token", &InitListExpr::LBraceToken)
    .def_prop_ro("num_initializers", &InitListExpr::NumInitializers)
    .def_prop_ro("r_brace_token", &InitListExpr::RBraceToken)
    .def_prop_ro("semantic_form", &InitListExpr::SemanticForm)
    .def_prop_ro("syntactic_form", &InitListExpr::SyntacticForm)
    .def_prop_ro("had_array_range_designator", &InitListExpr::HadArrayRangeDesignator)
    .def_prop_ro("has_array_filler", &InitListExpr::HasArrayFiller)
    .def_prop_ro("initializers", &InitListExpr::Initializers)
    .def_prop_ro("is_explicit", &InitListExpr::IsExplicit)
    .def_prop_ro("is_semantic_form", &InitListExpr::IsSemanticForm)
    .def_prop_ro("is_string_literal_initializer", &InitListExpr::IsStringLiteralInitializer)
    .def_prop_ro("is_syntactic_form", &InitListExpr::IsSyntacticForm)
    .def_prop_ro("is_transparent", &InitListExpr::IsTransparent);
}
} // namespace pasta
