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

void RegisterCoroutineBodyStmt(py::module_ &m) {
  py::class_<CoroutineBodyStmt, Stmt>(m, "CoroutineBodyStmt")
    .def("__hash__", [](const CoroutineBodyStmt& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const CoroutineBodyStmt& a, const CoroutineBodyStmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("children", &CoroutineBodyStmt::Children)
    .def_property_readonly("allocate", &CoroutineBodyStmt::Allocate)
    .def_property_readonly("begin_token", &CoroutineBodyStmt::BeginToken)
    .def_property_readonly("body", &CoroutineBodyStmt::Body)
    .def_property_readonly("deallocate", &CoroutineBodyStmt::Deallocate)
    .def_property_readonly("end_token", &CoroutineBodyStmt::EndToken)
    .def_property_readonly("exception_handler", &CoroutineBodyStmt::ExceptionHandler)
    .def_property_readonly("fallthrough_handler", &CoroutineBodyStmt::FallthroughHandler)
    .def_property_readonly("final_suspend_statement", &CoroutineBodyStmt::FinalSuspendStatement)
    .def_property_readonly("initializer_suspend_statement", &CoroutineBodyStmt::InitializerSuspendStatement)
    .def_property_readonly("parameter_moves", &CoroutineBodyStmt::ParameterMoves)
    .def_property_readonly("promise_declaration", &CoroutineBodyStmt::PromiseDeclaration)
    .def_property_readonly("promise_declaration_statement", &CoroutineBodyStmt::PromiseDeclarationStatement)
    .def_property_readonly("return_statement", &CoroutineBodyStmt::ReturnStatement)
    .def_property_readonly("return_statement_on_alloc_failure", &CoroutineBodyStmt::ReturnStatementOnAllocFailure)
    .def_property_readonly("return_value", &CoroutineBodyStmt::ReturnValue)
    .def_property_readonly("return_value_initializer", &CoroutineBodyStmt::ReturnValueInitializer)
    .def_property_readonly("has_dependent_promise_type", &CoroutineBodyStmt::HasDependentPromiseType);
}
} // namespace pasta
