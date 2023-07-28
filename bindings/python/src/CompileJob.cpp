/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>

#include "bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterCompileJob(nb::module_ &m) {
  nb::class_<CompileJob>(m, "CompileJob")
    .def("run", &CompileJob::Run);
}
}  // namespace pasta
