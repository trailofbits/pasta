/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Printer.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Token.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterCoroutineBodyStmt(nb::module_ &m) {
  nb::class_<CoroutineBodyStmt, Stmt>(m, "CoroutineBodyStmt")
    .def_prop_ro("children", &CoroutineBodyStmt::Children)
    .def_prop_ro("children_excl_body", &CoroutineBodyStmt::ChildrenExclBody)
    .def_prop_ro("allocate", &CoroutineBodyStmt::Allocate)
    .def_prop_ro("begin_token", &CoroutineBodyStmt::BeginToken)
    .def_prop_ro("body", &CoroutineBodyStmt::Body)
    .def_prop_ro("deallocate", &CoroutineBodyStmt::Deallocate)
    .def_prop_ro("end_token", &CoroutineBodyStmt::EndToken)
    .def_prop_ro("exception_handler", &CoroutineBodyStmt::ExceptionHandler)
    .def_prop_ro("fallthrough_handler", &CoroutineBodyStmt::FallthroughHandler)
    .def_prop_ro("final_suspend_statement", &CoroutineBodyStmt::FinalSuspendStatement)
    .def_prop_ro("initializer_suspend_statement", &CoroutineBodyStmt::InitializerSuspendStatement)
    .def_prop_ro("parameter_moves", &CoroutineBodyStmt::ParameterMoves)
    .def_prop_ro("promise_declaration", &CoroutineBodyStmt::PromiseDeclaration)
    .def_prop_ro("promise_declaration_statement", &CoroutineBodyStmt::PromiseDeclarationStatement)
    .def_prop_ro("result_declaration", &CoroutineBodyStmt::ResultDeclaration)
    .def_prop_ro("return_statement", &CoroutineBodyStmt::ReturnStatement)
    .def_prop_ro("return_statement_on_alloc_failure", &CoroutineBodyStmt::ReturnStatementOnAllocFailure)
    .def_prop_ro("return_value", &CoroutineBodyStmt::ReturnValue)
    .def_prop_ro("return_value_initializer", &CoroutineBodyStmt::ReturnValueInitializer)
    .def_prop_ro("has_dependent_promise_type", &CoroutineBodyStmt::HasDependentPromiseType);
}
} // namespace pasta
