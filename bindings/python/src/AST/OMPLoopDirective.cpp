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

void RegisterOMPLoopDirective(nb::module_ &m) {
  nb::class_<OMPLoopDirective, OMPLoopBasedDirective>(m, "OMPLoopDirective")
    .def_prop_ro("counters", &OMPLoopDirective::Counters)
    .def_prop_ro("dependent_counters", &OMPLoopDirective::DependentCounters)
    .def_prop_ro("dependent_initializers", &OMPLoopDirective::DependentInitializers)
    .def_prop_ro("finals", &OMPLoopDirective::Finals)
    .def_prop_ro("finals_conditions", &OMPLoopDirective::FinalsConditions)
    .def_prop_ro("body", &OMPLoopDirective::Body)
    .def_prop_ro("calculate_last_iteration", &OMPLoopDirective::CalculateLastIteration)
    .def_prop_ro("combined_condition", &OMPLoopDirective::CombinedCondition)
    .def_prop_ro("combined_distance_condition", &OMPLoopDirective::CombinedDistanceCondition)
    .def_prop_ro("combined_ensure_upper_bound", &OMPLoopDirective::CombinedEnsureUpperBound)
    .def_prop_ro("combined_initializer", &OMPLoopDirective::CombinedInitializer)
    .def_prop_ro("combined_lower_bound_variable", &OMPLoopDirective::CombinedLowerBoundVariable)
    .def_prop_ro("combined_next_lower_bound", &OMPLoopDirective::CombinedNextLowerBound)
    .def_prop_ro("combined_next_upper_bound", &OMPLoopDirective::CombinedNextUpperBound)
    .def_prop_ro("combined_parallel_for_in_distance_condition", &OMPLoopDirective::CombinedParallelForInDistanceCondition)
    .def_prop_ro("combined_upper_bound_variable", &OMPLoopDirective::CombinedUpperBoundVariable)
    .def_prop_ro("condition", &OMPLoopDirective::Condition)
    .def_prop_ro("distance_increment", &OMPLoopDirective::DistanceIncrement)
    .def_prop_ro("ensure_upper_bound", &OMPLoopDirective::EnsureUpperBound)
    .def_prop_ro("increment", &OMPLoopDirective::Increment)
    .def_prop_ro("initializer", &OMPLoopDirective::Initializer)
    .def_prop_ro("is_last_iteration_variable", &OMPLoopDirective::IsLastIterationVariable)
    .def_prop_ro("iteration_variable", &OMPLoopDirective::IterationVariable)
    .def_prop_ro("last_iteration", &OMPLoopDirective::LastIteration)
    .def_prop_ro("lower_bound_variable", &OMPLoopDirective::LowerBoundVariable)
    .def_prop_ro("next_lower_bound", &OMPLoopDirective::NextLowerBound)
    .def_prop_ro("next_upper_bound", &OMPLoopDirective::NextUpperBound)
    .def_prop_ro("num_iterations", &OMPLoopDirective::NumIterations)
    .def_prop_ro("pre_condition", &OMPLoopDirective::PreCondition)
    .def_prop_ro("pre_initializers", &OMPLoopDirective::PreInitializers)
    .def_prop_ro("prev_ensure_upper_bound", &OMPLoopDirective::PrevEnsureUpperBound)
    .def_prop_ro("prev_lower_bound_variable", &OMPLoopDirective::PrevLowerBoundVariable)
    .def_prop_ro("prev_upper_bound_variable", &OMPLoopDirective::PrevUpperBoundVariable)
    .def_prop_ro("stride_variable", &OMPLoopDirective::StrideVariable)
    .def_prop_ro("upper_bound_variable", &OMPLoopDirective::UpperBoundVariable)
    .def_prop_ro("initializers", &OMPLoopDirective::Initializers)
    .def_prop_ro("private_counters", &OMPLoopDirective::PrivateCounters)
    .def_prop_ro("updates", &OMPLoopDirective::Updates);
}
} // namespace pasta
