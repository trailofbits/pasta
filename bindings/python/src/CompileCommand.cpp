/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <pasta/Compile/Command.h>

#include "Bindings.h"

#include <pasta/Util/ArgumentVector.h>

namespace pasta {

namespace nb = nanobind;
void RegisterCompileCommand(nb::module_ &m) {
  nb::class_<CompileCommand>(m, "CompileCommand")
    .def_static("create_from_arguments", &CompileCommand::CreateFromArguments)
    .def_prop_ro("arguments", &CompileCommand::Arguments)
    .def_prop_ro("working_directory", &CompileCommand::WorkingDirectory);
}
}  // namespace pasta
