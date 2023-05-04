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

void RegisterOMPCanonicalLoop(py::module_ &m) {
  py::class_<OMPCanonicalLoop, Stmt>(m, "OMPCanonicalLoop")
    .def("__hash__", [](const OMPCanonicalLoop& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPCanonicalLoop& a, const OMPCanonicalLoop& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("Children", &OMPCanonicalLoop::Children)
    .def_property_readonly("BeginToken", &OMPCanonicalLoop::BeginToken)
    .def_property_readonly("DistanceFunc", &OMPCanonicalLoop::DistanceFunc)
    .def_property_readonly("EndToken", &OMPCanonicalLoop::EndToken)
    .def_property_readonly("LoopStatement", &OMPCanonicalLoop::LoopStatement)
    .def_property_readonly("LoopVariableFunc", &OMPCanonicalLoop::LoopVariableFunc)
    .def_property_readonly("LoopVariableReference", &OMPCanonicalLoop::LoopVariableReference);
}
} // namespace pasta
