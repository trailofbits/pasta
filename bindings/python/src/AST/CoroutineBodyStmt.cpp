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

void RegisterCoroutineBodyStmt(py::module_ &m) {
  py::class_<CoroutineBodyStmt, Stmt>(m, "CoroutineBodyStmt")
    .def_property_readonly("Children", &CoroutineBodyStmt::Children)
    .def_property_readonly("Allocate", &CoroutineBodyStmt::Allocate)
    .def_property_readonly("BeginToken", &CoroutineBodyStmt::BeginToken)
    .def_property_readonly("Body", &CoroutineBodyStmt::Body)
    .def_property_readonly("Deallocate", &CoroutineBodyStmt::Deallocate)
    .def_property_readonly("EndToken", &CoroutineBodyStmt::EndToken)
    .def_property_readonly("ExceptionHandler", &CoroutineBodyStmt::ExceptionHandler)
    .def_property_readonly("FallthroughHandler", &CoroutineBodyStmt::FallthroughHandler)
    .def_property_readonly("FinalSuspendStatement", &CoroutineBodyStmt::FinalSuspendStatement)
    .def_property_readonly("InitializerSuspendStatement", &CoroutineBodyStmt::InitializerSuspendStatement)
    .def_property_readonly("ParameterMoves", &CoroutineBodyStmt::ParameterMoves)
    .def_property_readonly("PromiseDeclaration", &CoroutineBodyStmt::PromiseDeclaration)
    .def_property_readonly("PromiseDeclarationStatement", &CoroutineBodyStmt::PromiseDeclarationStatement)
    .def_property_readonly("ReturnStatement", &CoroutineBodyStmt::ReturnStatement)
    .def_property_readonly("ReturnStatementOnAllocFailure", &CoroutineBodyStmt::ReturnStatementOnAllocFailure)
    .def_property_readonly("ReturnValue", &CoroutineBodyStmt::ReturnValue)
    .def_property_readonly("ReturnValueInitializer", &CoroutineBodyStmt::ReturnValueInitializer)
    .def_property_readonly("HasDependentPromiseType", &CoroutineBodyStmt::HasDependentPromiseType);
}
} // namespace pasta
