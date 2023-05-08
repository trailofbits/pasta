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

void RegisterObjCAtSynchronizedStmt(py::module_ &m) {
  py::class_<ObjCAtSynchronizedStmt, Stmt>(m, "ObjCAtSynchronizedStmt")
    .def("__hash__", [](const ObjCAtSynchronizedStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAtSynchronizedStmt& a, const ObjCAtSynchronizedStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &ObjCAtSynchronizedStmt::Children)
    .def_property_readonly("at_synchronized_token", &ObjCAtSynchronizedStmt::AtSynchronizedToken)
    .def_property_readonly("begin_token", &ObjCAtSynchronizedStmt::BeginToken)
    .def_property_readonly("end_token", &ObjCAtSynchronizedStmt::EndToken)
    .def_property_readonly("synch_body", &ObjCAtSynchronizedStmt::SynchBody)
    .def_property_readonly("synch_expression", &ObjCAtSynchronizedStmt::SynchExpression);
}
} // namespace pasta
