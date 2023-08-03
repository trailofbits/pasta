#include <pasta/Compile/Job.h>
#include <pasta/AST/AST.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>

#include "bindings.h"

#include <nanobind/stl/string_view.h>

namespace pasta {

namespace nb = nanobind;
void RegisterCompileJob(nb::module_ &m) {
  nb::class_<CompileJob>(m, "CompileJob")
    .def_prop_ro("arguments", &CompileJob::Arguments)
    .def_prop_ro("working_directory", &CompileJob::WorkingDirectory)
    .def_prop_ro("resource_directory", &CompileJob::ResourceDirectory)
    .def_prop_ro("system_root_directory", &CompileJob::SystemRootDirectory)
    .def_prop_ro("system_root_include_directory", &CompileJob::SystemRootIncludeDirectory)
    .def_prop_ro("source_file", &CompileJob::SourceFile)
    .def_prop_ro("target_triple", &CompileJob::TargetTriple)
    .def_prop_ro("auxiliary_target_triple", &CompileJob::AuxiliaryTargetTriple)
    .def("run", &CompileJob::Run);
}
}  // namespace pasta