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

void RegisterObjCAtTryStmt(py::module_ &m) {
  py::class_<ObjCAtTryStmt, Stmt>(m, "ObjCAtTryStmt")
    .def("__hash__", [](const ObjCAtTryStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAtTryStmt& a, const ObjCAtTryStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCAtTryStmt::Children)
    .def_property_readonly("AtTryToken", &ObjCAtTryStmt::AtTryToken)
    .def_property_readonly("BeginToken", &ObjCAtTryStmt::BeginToken)
    .def_property_readonly("EndToken", &ObjCAtTryStmt::EndToken)
    .def_property_readonly("FinallyStatement", &ObjCAtTryStmt::FinallyStatement)
    .def_property_readonly("NumCatchStatements", &ObjCAtTryStmt::NumCatchStatements)
    .def_property_readonly("TryBody", &ObjCAtTryStmt::TryBody);
}
} // namespace pasta
