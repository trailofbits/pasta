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
    .def_property_readonly("Children", &ObjCAtSynchronizedStmt::Children)
    .def_property_readonly("AtSynchronizedToken", &ObjCAtSynchronizedStmt::AtSynchronizedToken)
    .def_property_readonly("BeginToken", &ObjCAtSynchronizedStmt::BeginToken)
    .def_property_readonly("EndToken", &ObjCAtSynchronizedStmt::EndToken)
    .def_property_readonly("SynchBody", &ObjCAtSynchronizedStmt::SynchBody)
    .def_property_readonly("SynchExpression", &ObjCAtSynchronizedStmt::SynchExpression);
}
} // namespace pasta
