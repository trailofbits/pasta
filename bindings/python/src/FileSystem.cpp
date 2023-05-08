#include <pasta/Util/FileSystem.h>
#include <pasta/Compile/Compiler.h>

#include "bindings.h"

namespace pasta {

namespace py = pybind11;
void RegisterFileSystem(py::module_ &m) {
  py::class_<Stat>(m, "Stat")
    .def_property_readonly("full_path", &Stat::FullPath)
    .def_property_readonly("real_path", &Stat::RealPath)
    .def_property_readonly("type", &Stat::Type)
    .def_property_readonly("is_symbolic_link", &Stat::IsSymbolicLink)
    .def_property_readonly("is_regular_file", &Stat::IsRegularFile)
    .def_property_readonly("is_directory", &Stat::IsDirectory);

  py::class_<FileSystem, std::shared_ptr<FileSystem>>(m, "FileSystem")
    .def_static("create_from", &FileSystem::From)
    .def_static("create_native", &FileSystem::CreateNative)
    .def("parse_path", &FileSystem::ParsePath)
    .def("is_resource_dir", &FileSystem::IsResourceDir)
    .def("path_kind", &FileSystem::PathKind)
    .def("file_exists", &FileSystem::FileExists)
    .def("read_file", py::overload_cast<Stat>(&FileSystem::ReadFile))
    .def("read_file", py::overload_cast<std::filesystem::path, std::filesystem::path>(&FileSystem::ReadFile))
    .def_property_readonly("current_working_directory", &FileSystem::CurrentWorkingDirectory)
    .def("stat", &FileSystem::Stat)
    .def("list_directory", py::overload_cast<std::filesystem::path, std::filesystem::path>(&FileSystem::ListDirectory))
    .def("list_directory", py::overload_cast<Stat>(&FileSystem::ListDirectory));

  py::class_<FileSystemView, std::shared_ptr<FileSystemView>>(m, "FileSystemView")
    .def_property_readonly("underlying_file_system", &FileSystemView::UnderlyingFileSystem)
    .def_property_readonly("current_working_directory", &FileSystemView::CurrentWorkingDirectory)
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