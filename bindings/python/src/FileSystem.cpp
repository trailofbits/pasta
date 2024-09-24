/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <pasta/Compile/Compiler.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/File.h>

#include "Bindings.h"

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

  nb::class_<FileToken>(m, "FileToken")
    .def("__hash__", [](const FileToken &tok) { return reinterpret_cast<intptr_t>(tok.RawFileToken()); })
    .def("__eq__", [](const FileToken &a, const FileToken &b) { return a.RawFileToken() == b.RawFileToken(); })
    .def("__str__", &FileToken::Data)
    .def_prop_ro("kind", &FileToken::Kind)
    .def_prop_ro("line", &FileToken::Line)
    .def_prop_ro("offset", &FileToken::Offset)
    .def_prop_ro("index", &FileToken::Index)
    .def_prop_ro("column", &FileToken::Column)
    .def_prop_ro("data", &FileToken::Data);

  nb::class_<FileTokenRange>(m, "FileTokenRange")
  .def("__getitem__", &FileTokenRange::At)
  .def("__len__", &FileTokenRange::Size)
  .def("__bool__", &FileTokenRange::operator bool)
  .def("__iter__",
      [](const FileTokenRange &v) {
        return nb::make_iterator(
            nb::type<FileTokenRange>(), "FileTokenIterator", v.begin(), v.end());
      });

  nb::class_<File>(m, "File")
    .def("__hash__", [](const File &f) { return reinterpret_cast<intptr_t>(f.RawFile()); })
    .def("__eq__", [](const File &a, const File &b) { return a.RawFile() == b.RawFile(); })
    .def("__str__", &File::Data)
    .def_static("containing", nb::overload_cast<const FileToken &>(&File::Containing))
    .def_prop_ro("path", &File::Path)
    .def_prop_ro("data", &File::Data)
    .def_prop_ro("data_hash", &File::DataHash)
    .def_prop_ro("was_parsed", &File::WasParsed)
    .def_prop_ro("tokens", &File::Tokens)
    .def("stat", &File::Stat);
}
}  // namespace pasta
