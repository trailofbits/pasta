/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Compile/Command.h>

#include "bindings.h"

#include <pasta/Util/ArgumentVector.h>
#include <nanobind/stl/string_view.h>

namespace pasta {

namespace nb = nanobind;
void RegisterCompileCommand(nb::module_ &m) {
  nb::class_<CompileCommand>(m, "CompileCommand")
    .def_static("create_from_arguments", &CompileCommand::CreateFromArguments)
    .def_prop_ro("arguments", &CompileCommand::Arguments)
    .def_prop_ro("working_directory", &CompileCommand::WorkingDirectory);
}
}  // namespace pasta