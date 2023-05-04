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

void RegisterObjCAvailabilityCheckExpr(py::module_ &m) {
  py::class_<ObjCAvailabilityCheckExpr, Expr, Stmt, ValueStmt>(m, "ObjCAvailabilityCheckExpr")
    .def_property_readonly("Children", &ObjCAvailabilityCheckExpr::Children)
    .def_property_readonly("BeginToken", &ObjCAvailabilityCheckExpr::BeginToken)
    .def_property_readonly("EndToken", &ObjCAvailabilityCheckExpr::EndToken)
    .def_property_readonly("Tokens", &ObjCAvailabilityCheckExpr::Tokens)
    .def_property_readonly("HasVersion", &ObjCAvailabilityCheckExpr::HasVersion);
}
} // namespace pasta
