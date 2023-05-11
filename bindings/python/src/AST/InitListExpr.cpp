/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace pasta {
namespace py = pybind11;

void RegisterInitListExpr(py::module_ &m) {
  py::class_<InitListExpr, Expr>(m, "InitListExpr")
    .def("__hash__", [](const InitListExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &InitListExpr::Children)
    .def_property_readonly("array_filler", &InitListExpr::ArrayFiller)
    .def_property_readonly("begin_token", &InitListExpr::BeginToken)
    .def_property_readonly("end_token", &InitListExpr::EndToken)
    .def_property_readonly("initialized_field_in_union", &InitListExpr::InitializedFieldInUnion)
    .def_property_readonly("l_brace_token", &InitListExpr::LBraceToken)
    .def_property_readonly("num_initializers", &InitListExpr::NumInitializers)
    .def_property_readonly("r_brace_token", &InitListExpr::RBraceToken)
    .def_property_readonly("semantic_form", &InitListExpr::SemanticForm)
    .def_property_readonly("syntactic_form", &InitListExpr::SyntacticForm)
    .def_property_readonly("had_array_range_designator", &InitListExpr::HadArrayRangeDesignator)
    .def_property_readonly("has_array_filler", &InitListExpr::HasArrayFiller)
    .def_property_readonly("initializers", &InitListExpr::Initializers)
    .def_property_readonly("is_explicit", &InitListExpr::IsExplicit)
    .def_property_readonly("is_semantic_form", &InitListExpr::IsSemanticForm)
    .def_property_readonly("is_string_literal_initializer", &InitListExpr::IsStringLiteralInitializer)
    .def_property_readonly("is_syntactic_form", &InitListExpr::IsSyntacticForm)
    .def_property_readonly("is_transparent", &InitListExpr::IsTransparent);
}
} // namespace pasta
