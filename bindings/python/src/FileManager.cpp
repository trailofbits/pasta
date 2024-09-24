/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <pasta/Util/FileManager.h>

#include "Bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterFileManager(nb::module_ &m) {
  nb::class_<FileManager>(m, "FileManager")
    .def(nb::init<std::shared_ptr<FileSystem>>());
}
}  // namespace pasta
