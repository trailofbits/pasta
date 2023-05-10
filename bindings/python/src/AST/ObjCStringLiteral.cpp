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

void RegisterObjCStringLiteral(py::module_ &m) {
  py::class_<ObjCStringLiteral, Expr>(m, "ObjCStringLiteral")
    .def("__hash__", [](const ObjCStringLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCStringLiteral& a, const ObjCStringLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCStringLiteral::Children)
    .def_property_readonly("at_token", &ObjCStringLiteral::AtToken)
    .def_property_readonly("begin_token", &ObjCStringLiteral::BeginToken)
    .def_property_readonly("end_token", &ObjCStringLiteral::EndToken)
    .def_property_readonly("string", &ObjCStringLiteral::String);
}
} // namespace pasta
