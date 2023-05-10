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

void RegisterObjCArrayLiteral(py::module_ &m) {
  py::class_<ObjCArrayLiteral, Expr>(m, "ObjCArrayLiteral")
    .def("__hash__", [](const ObjCArrayLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCArrayLiteral& a, const ObjCArrayLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCArrayLiteral::Children)
    .def_property_readonly("array_with_objects_method", &ObjCArrayLiteral::ArrayWithObjectsMethod)
    .def_property_readonly("begin_token", &ObjCArrayLiteral::BeginToken)
    .def_property_readonly("end_token", &ObjCArrayLiteral::EndToken)
    .def_property_readonly("num_elements", &ObjCArrayLiteral::NumElements)
    .def_property_readonly("tokens", &ObjCArrayLiteral::Tokens);
}
} // namespace pasta
