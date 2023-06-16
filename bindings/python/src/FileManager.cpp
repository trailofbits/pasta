#include <pasta/Util/FileManager.h>

#include "bindings.h"

namespace pasta {

namespace nb = nanobind;
void RegisterFileManager(nb::module_ &m) {
  nb::class_<FileManager>(m, "FileManager")
    .def(nb::init<std::shared_ptr<FileSystem>>());
}
}  // namespace pasta