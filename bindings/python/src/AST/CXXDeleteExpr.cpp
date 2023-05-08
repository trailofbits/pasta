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

namespace pasta {
namespace py = pybind11;

void RegisterCXXDeleteExpr(py::module_ &m) {
  py::class_<CXXDeleteExpr, Expr>(m, "CXXDeleteExpr")
    .def("__hash__", [](const CXXDeleteExpr& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CXXDeleteExpr& a, const CXXDeleteExpr& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CXXDeleteExpr::Children)
    .def_property_readonly("does_usual_array_delete_want_size", &CXXDeleteExpr::DoesUsualArrayDeleteWantSize)
    .def_property_readonly("argument", &CXXDeleteExpr::Argument)
    .def_property_readonly("begin_token", &CXXDeleteExpr::BeginToken)
    .def_property_readonly("destroyed_type", &CXXDeleteExpr::DestroyedType)
    .def_property_readonly("end_token", &CXXDeleteExpr::EndToken)
    .def_property_readonly("operator_delete", &CXXDeleteExpr::OperatorDelete)
    .def_property_readonly("is_array_form", &CXXDeleteExpr::IsArrayForm)
    .def_property_readonly("is_array_form_as_written", &CXXDeleteExpr::IsArrayFormAsWritten)
    .def_property_readonly("is_global_delete", &CXXDeleteExpr::IsGlobalDelete);
}
} // namespace pasta
