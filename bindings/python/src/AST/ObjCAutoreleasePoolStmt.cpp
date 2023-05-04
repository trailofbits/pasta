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

void RegisterObjCAutoreleasePoolStmt(py::module_ &m) {
  py::class_<ObjCAutoreleasePoolStmt, Stmt>(m, "ObjCAutoreleasePoolStmt")
    .def("__hash__", [](const ObjCAutoreleasePoolStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAutoreleasePoolStmt& a, const ObjCAutoreleasePoolStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCAutoreleasePoolStmt::Children)
    .def_property_readonly("AtToken", &ObjCAutoreleasePoolStmt::AtToken)
    .def_property_readonly("BeginToken", &ObjCAutoreleasePoolStmt::BeginToken)
    .def_property_readonly("EndToken", &ObjCAutoreleasePoolStmt::EndToken)
    .def_property_readonly("SubStatement", &ObjCAutoreleasePoolStmt::SubStatement);
}
} // namespace pasta
