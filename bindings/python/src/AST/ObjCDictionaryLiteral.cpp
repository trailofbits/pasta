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

void RegisterObjCDictionaryLiteral(py::module_ &m) {
  py::class_<ObjCDictionaryLiteral, Expr>(m, "ObjCDictionaryLiteral")
    .def("__hash__", [](const ObjCDictionaryLiteral& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCDictionaryLiteral& a, const ObjCDictionaryLiteral& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCDictionaryLiteral::Children)
    .def_property_readonly("begin_token", &ObjCDictionaryLiteral::BeginToken)
    .def_property_readonly("dictionary_with_objects_method", &ObjCDictionaryLiteral::DictionaryWithObjectsMethod)
    .def_property_readonly("end_token", &ObjCDictionaryLiteral::EndToken)
    .def_property_readonly("num_elements", &ObjCDictionaryLiteral::NumElements)
    .def_property_readonly("tokens", &ObjCDictionaryLiteral::Tokens);
}
} // namespace pasta
