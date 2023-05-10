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

void RegisterOMPLoopDirective(py::module_ &m) {
  py::class_<OMPLoopDirective, OMPLoopBasedDirective>(m, "OMPLoopDirective")
    .def("__hash__", [](const OMPLoopDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPLoopDirective& a, const OMPLoopDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("counters", &OMPLoopDirective::Counters)
    .def_property_readonly("dependent_counters", &OMPLoopDirective::DependentCounters)
    .def_property_readonly("dependent_initializers", &OMPLoopDirective::DependentInitializers)
    .def_property_readonly("finals", &OMPLoopDirective::Finals)
    .def_property_readonly("finals_conditions", &OMPLoopDirective::FinalsConditions)
    .def_property_readonly("body", &OMPLoopDirective::Body)
    .def_property_readonly("calculate_last_iteration", &OMPLoopDirective::CalculateLastIteration)
    .def_property_readonly("combined_condition", &OMPLoopDirective::CombinedCondition)
    .def_property_readonly("combined_distance_condition", &OMPLoopDirective::CombinedDistanceCondition)
    .def_property_readonly("combined_ensure_upper_bound", &OMPLoopDirective::CombinedEnsureUpperBound)
    .def_property_readonly("combined_initializer", &OMPLoopDirective::CombinedInitializer)
    .def_property_readonly("combined_lower_bound_variable", &OMPLoopDirective::CombinedLowerBoundVariable)
    .def_property_readonly("combined_next_lower_bound", &OMPLoopDirective::CombinedNextLowerBound)
    .def_property_readonly("combined_next_upper_bound", &OMPLoopDirective::CombinedNextUpperBound)
    .def_property_readonly("combined_parallel_for_in_distance_condition", &OMPLoopDirective::CombinedParallelForInDistanceCondition)
    .def_property_readonly("combined_upper_bound_variable", &OMPLoopDirective::CombinedUpperBoundVariable)
    .def_property_readonly("condition", &OMPLoopDirective::Condition)
    .def_property_readonly("distance_increment", &OMPLoopDirective::DistanceIncrement)
    .def_property_readonly("ensure_upper_bound", &OMPLoopDirective::EnsureUpperBound)
    .def_property_readonly("increment", &OMPLoopDirective::Increment)
    .def_property_readonly("initializer", &OMPLoopDirective::Initializer)
    .def_property_readonly("is_last_iteration_variable", &OMPLoopDirective::IsLastIterationVariable)
    .def_property_readonly("iteration_variable", &OMPLoopDirective::IterationVariable)
    .def_property_readonly("last_iteration", &OMPLoopDirective::LastIteration)
    .def_property_readonly("lower_bound_variable", &OMPLoopDirective::LowerBoundVariable)
    .def_property_readonly("next_lower_bound", &OMPLoopDirective::NextLowerBound)
    .def_property_readonly("next_upper_bound", &OMPLoopDirective::NextUpperBound)
    .def_property_readonly("num_iterations", &OMPLoopDirective::NumIterations)
    .def_property_readonly("pre_condition", &OMPLoopDirective::PreCondition)
    .def_property_readonly("pre_initializers", &OMPLoopDirective::PreInitializers)
    .def_property_readonly("prev_ensure_upper_bound", &OMPLoopDirective::PrevEnsureUpperBound)
    .def_property_readonly("prev_lower_bound_variable", &OMPLoopDirective::PrevLowerBoundVariable)
    .def_property_readonly("prev_upper_bound_variable", &OMPLoopDirective::PrevUpperBoundVariable)
    .def_property_readonly("stride_variable", &OMPLoopDirective::StrideVariable)
    .def_property_readonly("upper_bound_variable", &OMPLoopDirective::UpperBoundVariable)
    .def_property_readonly("initializers", &OMPLoopDirective::Initializers)
    .def_property_readonly("private_counters", &OMPLoopDirective::PrivateCounters)
    .def_property_readonly("updates", &OMPLoopDirective::Updates);
}
} // namespace pasta
