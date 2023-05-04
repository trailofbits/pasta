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

void RegisterObjCStringLiteral(py::module_ &m) {
  py::class_<ObjCStringLiteral, Expr, Stmt, ValueStmt>(m, "ObjCStringLiteral")
    .def("__hash__", [](const ObjCStringLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCStringLiteral& a, const ObjCStringLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCStringLiteral::Children)
    .def_property_readonly("AtToken", &ObjCStringLiteral::AtToken)
    .def_property_readonly("BeginToken", &ObjCStringLiteral::BeginToken)
    .def_property_readonly("EndToken", &ObjCStringLiteral::EndToken)
    .def_property_readonly("String", &ObjCStringLiteral::String);
}
} // namespace pasta
