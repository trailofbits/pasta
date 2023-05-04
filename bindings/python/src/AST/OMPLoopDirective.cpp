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

void RegisterOMPLoopDirective(py::module_ &m) {
  py::class_<OMPLoopDirective, OMPExecutableDirective, OMPLoopBasedDirective, Stmt>(m, "OMPLoopDirective")
    .def_property_readonly("Counters", &OMPLoopDirective::Counters)
    .def_property_readonly("DependentCounters", &OMPLoopDirective::DependentCounters)
    .def_property_readonly("DependentInitializers", &OMPLoopDirective::DependentInitializers)
    .def_property_readonly("Finals", &OMPLoopDirective::Finals)
    .def_property_readonly("FinalsConditions", &OMPLoopDirective::FinalsConditions)
    .def_property_readonly("Body", &OMPLoopDirective::Body)
    .def_property_readonly("CalculateLastIteration", &OMPLoopDirective::CalculateLastIteration)
    .def_property_readonly("CombinedCondition", &OMPLoopDirective::CombinedCondition)
    .def_property_readonly("CombinedDistanceCondition", &OMPLoopDirective::CombinedDistanceCondition)
    .def_property_readonly("CombinedEnsureUpperBound", &OMPLoopDirective::CombinedEnsureUpperBound)
    .def_property_readonly("CombinedInitializer", &OMPLoopDirective::CombinedInitializer)
    .def_property_readonly("CombinedLowerBoundVariable", &OMPLoopDirective::CombinedLowerBoundVariable)
    .def_property_readonly("CombinedNextLowerBound", &OMPLoopDirective::CombinedNextLowerBound)
    .def_property_readonly("CombinedNextUpperBound", &OMPLoopDirective::CombinedNextUpperBound)
    .def_property_readonly("CombinedParallelForInDistanceCondition", &OMPLoopDirective::CombinedParallelForInDistanceCondition)
    .def_property_readonly("CombinedUpperBoundVariable", &OMPLoopDirective::CombinedUpperBoundVariable)
    .def_property_readonly("Condition", &OMPLoopDirective::Condition)
    .def_property_readonly("DistanceIncrement", &OMPLoopDirective::DistanceIncrement)
    .def_property_readonly("EnsureUpperBound", &OMPLoopDirective::EnsureUpperBound)
    .def_property_readonly("Increment", &OMPLoopDirective::Increment)
    .def_property_readonly("Initializer", &OMPLoopDirective::Initializer)
    .def_property_readonly("IsLastIterationVariable", &OMPLoopDirective::IsLastIterationVariable)
    .def_property_readonly("IterationVariable", &OMPLoopDirective::IterationVariable)
    .def_property_readonly("LastIteration", &OMPLoopDirective::LastIteration)
    .def_property_readonly("LowerBoundVariable", &OMPLoopDirective::LowerBoundVariable)
    .def_property_readonly("NextLowerBound", &OMPLoopDirective::NextLowerBound)
    .def_property_readonly("NextUpperBound", &OMPLoopDirective::NextUpperBound)
    .def_property_readonly("NumIterations", &OMPLoopDirective::NumIterations)
    .def_property_readonly("PreCondition", &OMPLoopDirective::PreCondition)
    .def_property_readonly("PreInitializers", &OMPLoopDirective::PreInitializers)
    .def_property_readonly("PrevEnsureUpperBound", &OMPLoopDirective::PrevEnsureUpperBound)
    .def_property_readonly("PrevLowerBoundVariable", &OMPLoopDirective::PrevLowerBoundVariable)
    .def_property_readonly("PrevUpperBoundVariable", &OMPLoopDirective::PrevUpperBoundVariable)
    .def_property_readonly("StrideVariable", &OMPLoopDirective::StrideVariable)
    .def_property_readonly("UpperBoundVariable", &OMPLoopDirective::UpperBoundVariable)
    .def_property_readonly("Initializers", &OMPLoopDirective::Initializers)
    .def_property_readonly("PrivateCounters", &OMPLoopDirective::PrivateCounters)
    .def_property_readonly("Updates", &OMPLoopDirective::Updates);
}
} // namespace pasta
