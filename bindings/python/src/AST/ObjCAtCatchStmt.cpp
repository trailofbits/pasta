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

void RegisterObjCAtCatchStmt(py::module_ &m) {
  py::class_<ObjCAtCatchStmt, Stmt>(m, "ObjCAtCatchStmt")
    .def("__hash__", [](const ObjCAtCatchStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const ObjCAtCatchStmt& a, const ObjCAtCatchStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &ObjCAtCatchStmt::Children)
    .def_property_readonly("AtCatchToken", &ObjCAtCatchStmt::AtCatchToken)
    .def_property_readonly("BeginToken", &ObjCAtCatchStmt::BeginToken)
    .def_property_readonly("CatchBody", &ObjCAtCatchStmt::CatchBody)
    .def_property_readonly("CatchParameterDeclaration", &ObjCAtCatchStmt::CatchParameterDeclaration)
    .def_property_readonly("EndToken", &ObjCAtCatchStmt::EndToken)
    .def_property_readonly("RParenToken", &ObjCAtCatchStmt::RParenToken)
    .def_property_readonly("HasEllipsis", &ObjCAtCatchStmt::HasEllipsis);
}
} // namespace pasta
