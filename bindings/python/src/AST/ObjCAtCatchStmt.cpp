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

void RegisterObjCAtCatchStmt(py::module_ &m) {
  py::class_<ObjCAtCatchStmt, Stmt>(m, "ObjCAtCatchStmt")
    .def("__hash__", [](const ObjCAtCatchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCAtCatchStmt::Children)
    .def_property_readonly("at_catch_token", &ObjCAtCatchStmt::AtCatchToken)
    .def_property_readonly("begin_token", &ObjCAtCatchStmt::BeginToken)
    .def_property_readonly("catch_body", &ObjCAtCatchStmt::CatchBody)
    .def_property_readonly("catch_parameter_declaration", &ObjCAtCatchStmt::CatchParameterDeclaration)
    .def_property_readonly("end_token", &ObjCAtCatchStmt::EndToken)
    .def_property_readonly("r_paren_token", &ObjCAtCatchStmt::RParenToken)
    .def_property_readonly("has_ellipsis", &ObjCAtCatchStmt::HasEllipsis);
}
} // namespace pasta
