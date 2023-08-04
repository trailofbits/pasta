/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#include <pasta/Util/FileManager.h>

#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/string.h>

#include "bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterFileManager(nb::module_ &m) {
  nb::class_<FileManager>(m, "FileManager")
    .def(nb::init<std::shared_ptr<FileSystem>>());
}
}  // namespace pasta
