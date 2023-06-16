#include <pasta/Util/FileSystem.h>
#include <pasta/Compile/Compiler.h>

#include "bindings.h"

#include <nanobind/stl/shared_ptr.h>

namespace pasta {

namespace nb = nanobind;
void RegisterFileSystem(nb::module_ &m) {
  nb::class_<Stat>(m, "Stat")
    .def_prop_ro("full_path", &Stat::FullPath)
    .def_prop_ro("real_path", &Stat::RealPath)
    .def_prop_ro("type", &Stat::Type)
    .def_prop_ro("is_symbolic_link", &Stat::IsSymbolicLink)
    .def_prop_ro("is_regular_file", &Stat::IsRegularFile)
    .def_prop_ro("is_directory", &Stat::IsDirectory);

  nb::class_<FileSystem>(m, "FileSystem")
    .def_static("create_from", &FileSystem::From)
    .def_static("create_native", &FileSystem::CreateNative)
    .def("parse_path", &FileSystem::ParsePath)
    .def("is_resource_dir", &FileSystem::IsResourceDir)
    .def("path_kind", &FileSystem::PathKind)
    .def("file_exists", &FileSystem::FileExists)
    .def("read_file", nb::overload_cast<Stat>(&FileSystem::ReadFile))
    .def("read_file", nb::overload_cast<std::filesystem::path, std::filesystem::path>(&FileSystem::ReadFile))
    .def_prop_ro("current_working_directory", &FileSystem::CurrentWorkingDirectory)
    .def("stat", &FileSystem::Stat)
    .def("list_directory", nb::overload_cast<std::filesystem::path, std::filesystem::path>(&FileSystem::ListDirectory))
    .def("list_directory", nb::overload_cast<Stat>(&FileSystem::ListDirectory));

  nb::class_<FileSystemView>(m, "FileSystemView")
    .def_prop_ro("underlying_file_system", &FileSystemView::UnderlyingFileSystem)
    .def_prop_ro("current_working_directory", &FileSystemView::CurrentWorkingDirectory)
    .def("root_directory", &FileSystemView::RootDirectory)
    .def("parse_path", overload_cast_const<std::string>(&FileSystemView::ParsePath))
    .def("parse_path", overload_cast_const<std::string, std::string>(&FileSystemView::ParsePath))
    .def("is_resource_dir", &FileSystemView::IsResourceDir)
    .def("stat", &FileSystemView::Stat)
    .def("read_file", overload_cast_const<std::filesystem::path>(&FileSystemView::ReadFile))
    .def("read_file", overload_cast_const<Stat>(&FileSystemView::ReadFile))
    .def("list_directory", overload_cast_const<std::filesystem::path>(&FileSystemView::ListDirectory))
    .def("list_directory", overload_cast_const<Stat>(&FileSystemView::ListDirectory))
    .def("push_working_driectory", &FileSystemView::PushWorkingDirectory)
    .def("pop_working_directory", &FileSystemView::PopWorkingDirectory);
}
}  // namespace pasta