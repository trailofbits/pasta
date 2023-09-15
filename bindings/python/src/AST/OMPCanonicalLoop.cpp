/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterOMPCanonicalLoop(nb::module_ &m) {
  nb::class_<OMPCanonicalLoop, Stmt>(m, "OMPCanonicalLoop")
    .def("__hash__", [](const OMPCanonicalLoop& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const Stmt& a, const Stmt& b) { return a.RawStmt() == b.RawStmt(); })
    .def_prop_ro("children", &OMPCanonicalLoop::Children)
    .def_prop_ro("begin_token", &OMPCanonicalLoop::BeginToken)
    .def_prop_ro("distance_func", &OMPCanonicalLoop::DistanceFunc)
    .def_prop_ro("end_token", &OMPCanonicalLoop::EndToken)
    .def_prop_ro("loop_statement", &OMPCanonicalLoop::LoopStatement)
    .def_prop_ro("loop_variable_func", &OMPCanonicalLoop::LoopVariableFunc)
    .def_prop_ro("loop_variable_reference", &OMPCanonicalLoop::LoopVariableReference);
}
} // namespace pasta
