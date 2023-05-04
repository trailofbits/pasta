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

void RegisterObjCAtFinallyStmt(py::module_ &m) {
  py::class_<ObjCAtFinallyStmt, Stmt>(m, "ObjCAtFinallyStmt")
    .def("__hash__", [](const ObjCAtFinallyStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAtFinallyStmt& a, const ObjCAtFinallyStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCAtFinallyStmt::Children)
    .def_property_readonly("AtFinallyToken", &ObjCAtFinallyStmt::AtFinallyToken)
    .def_property_readonly("BeginToken", &ObjCAtFinallyStmt::BeginToken)
    .def_property_readonly("EndToken", &ObjCAtFinallyStmt::EndToken)
    .def_property_readonly("FinallyBody", &ObjCAtFinallyStmt::FinallyBody);
}
} // namespace pasta
