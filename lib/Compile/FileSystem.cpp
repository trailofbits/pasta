/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "FileSystem.h"

namespace pasta {
namespace {

static const auto kErrOutOfRange =
    std::make_error_code(std::errc::result_out_of_range);

static llvm::sys::fs::file_type ToLLVM(std::filesystem::file_type ft) {
  switch (ft) {
    case std::filesystem::file_type::none:
      return llvm::sys::fs::file_type::status_error;
    case std::filesystem::file_type::not_found:
      return llvm::sys::fs::file_type::file_not_found;

    // NOTE(pag): We might have to convert files to UTF-8, and so to prevent
    //            Clang from reporting an error when it detects a file size
    //            change, we report the file kind as a FIFO, i.e. a named pipe.
    case std::filesystem::file_type::regular:
      return llvm::sys::fs::file_type::fifo_file;

    case std::filesystem::file_type::directory:
      return llvm::sys::fs::file_type::directory_file;
    case std::filesystem::file_type::symlink:
      return llvm::sys::fs::file_type::symlink_file;
    case std::filesystem::file_type::block:
      return llvm::sys::fs::file_type::block_file;
    case std::filesystem::file_type::character:
      return llvm::sys::fs::file_type::character_file;
    case std::filesystem::file_type::fifo:
      return llvm::sys::fs::file_type::fifo_file;
    case std::filesystem::file_type::socket:
      return llvm::sys::fs::file_type::socket_file;
    case std::filesystem::file_type::unknown:
      return llvm::sys::fs::file_type::type_unknown;
  }
  return llvm::sys::fs::file_type::status_error;
}

static llvm::sys::fs::perms ToLLVM(std::filesystem::perms fp) {
  return static_cast<llvm::sys::fs::perms>(fp);
}

// Convert information stored in `Stat` into a clang VFS file status.
//
// NOTE(pag): Upper layers of Clang don't really handle symbolic links as
//            such, and likely assume that all file statuses are fully resolved.
//
//            In general, we want to pretend that symbolic links don't exist.
//            Yet, we have to contend with the fact that they do. We take the
//            following course: we assume all symbolic links are in fact hard
//            links, and punt on higher layers to perform de-duplication based
//            on file contents (and/or other heuristics).
static llvm::vfs::Status ToLLVM(const ::pasta::Stat &stat) {
  size_t size = 0;
  if (stat.type == std::filesystem::file_type::directory) {
    size = 4096;
  } else if (stat.size.has_value()) {
    size = stat.size.value();
  }

  auto real_path = stat.real_path.generic_string();
  auto parent_path = stat.real_path.parent_path().generic_string();

  return llvm::vfs::Status(
      stat.full_path.generic_string(),  // NOTE(pag): See function comment.
      llvm::sys::fs::UniqueID(
          std::hash<std::string>{}(parent_path) | (0xFFFFull << 48),
          std::hash<std::string>{}(real_path)),
      llvm::sys::TimePoint<>(),  // Modification time.
      0,  // User.
      0,  // Group.
      size,
      ToLLVM(stat.type),
      ToLLVM(stat.permissions));
}

}  // namespace

LLVMFile::~LLVMFile(void) {}

// Get the status of the file.
llvm::ErrorOr<llvm::vfs::Status> LLVMFile::status(void) {
  return ToLLVM(impl.Stat());
}

// Get the name of the file.
llvm::ErrorOr<std::string> LLVMFile::getName(void) {
  return impl.Stat().real_path.generic_string();
}

// Get the contents of the file as a `MemoryBuffer`.
llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>>
LLVMFile::getBuffer(const llvm::Twine &name, int64_t file_size,
                    bool requires_null_terminator, bool is_volatile) {
  auto data = impl.Data();
  if (data.Succeeded()) {
    auto ret = llvm::MemoryBuffer::getMemBuffer(
        data.TakeValue(), name.str(), false);
    return ret;
  }
  return data.TakeError();
}

/// Closes the file.
std::error_code LLVMFile::close(void) {
  return {};
}

LLVMDirectoryIterator::~LLVMDirectoryIterator(void) {}

std::error_code LLVMDirectoryIterator::increment(void) {
  if (index < paths.size()) {
    auto &stat = paths[index++];
    this->CurrentEntry = llvm::vfs::directory_entry(
        stat.full_path.generic_string(), ToLLVM(stat.type));
    return {};
  }
  return kErrOutOfRange;
}

LLVMFileSystem::~LLVMFileSystem(void) {}

// Get the status of the entry at `path`, if one exists.
llvm::ErrorOr<llvm::vfs::Status>
LLVMFileSystem::status(const llvm::Twine &path) {
  auto fs_path = file_system.ParsePath(path.str());
  auto stat = file_system.Stat(std::move(fs_path));
  if (stat.Succeeded()) {
    return ToLLVM(stat.TakeValue());
  }
  return stat.TakeError();
}

// Get an `LLVMFile` object for the file at `path`, if one exists.
llvm::ErrorOr<std::unique_ptr<llvm::vfs::File>>
LLVMFileSystem::openFileForRead(const llvm::Twine &path) {
  auto fs_path = file_system.ParsePath(path.str());
  auto maybe_stat = file_system.Stat(std::move(fs_path));
  if (maybe_stat.Succeeded()) {
    auto stat = maybe_stat.TakeValue();
    if (stat.IsDirectory()) {
      return std::make_error_code(std::errc::is_a_directory);
    }
    auto file = file_manager.OpenFile(std::move(stat));
    if (file.Succeeded()) {
      return std::unique_ptr<llvm::vfs::File>(new LLVMFile(file.TakeValue()));
    }
    return file.TakeError();
  }
  return maybe_stat.TakeError();
}

// Get a `directory_iterator` for `path`.
llvm::vfs::directory_iterator
LLVMFileSystem::dir_begin(const llvm::Twine &path, std::error_code &ec) {
  auto fs_path = file_system.ParsePath(path.str());
  auto paths = file_system.ListDirectory(std::move(fs_path));
  if (paths.Succeeded()) {
    ec = {};
    std::vector<::pasta::Stat> path_stats;
    for (auto &path : paths.TakeValue()) {
      auto maybe_stat = file_system.Stat(std::move(path));
      if (maybe_stat.Succeeded()) {
        path_stats.emplace_back(maybe_stat.TakeValue());
      }
    }
    return llvm::vfs::directory_iterator(
        std::make_shared<LLVMDirectoryIterator>(std::move(path_stats)));
  }
  ec = paths.TakeError();
  return llvm::vfs::directory_iterator();
}

// Set the current working directory to `path`.
std::error_code
LLVMFileSystem::setCurrentWorkingDirectory(const llvm::Twine &path) {
  auto fs_path = file_system.ParsePath(path.str());
  return file_system.PushWorkingDirectory(std::move(fs_path));
}

// Get the working directory of this file system.
llvm::ErrorOr<std::string>
LLVMFileSystem::getCurrentWorkingDirectory(void) const {
  return file_system.CurrentWorkingDirectory().generic_string();
}

// Gets real path of `path` e.g. collapse all `.` and `..` patterns, resolve
// symlinks.
std::error_code LLVMFileSystem::getRealPath(
    const llvm::Twine &path, llvm::SmallVectorImpl<char> &output) const {
  auto fs_path = file_system.ParsePath(path.str());
  auto maybe_stat = file_system.Stat(std::move(fs_path));
  if (maybe_stat.Succeeded()) {
    output.clear();
    auto data = maybe_stat.TakeValue().real_path.generic_string();
    output.reserve(data.size());
    output.insert(output.end(), data.begin(), data.end());
    return {};
  }
  return maybe_stat.TakeError();
}

// Is the file mounted on a local filesystem?
std::error_code LLVMFileSystem::isLocal(const llvm::Twine &, bool &result) {
  result = true;
  return {};
}

// Make `path` an absolute path.
std::error_code LLVMFileSystem::makeAbsolute(
    llvm::SmallVectorImpl<char> &path) const {
  std::string path_str;
  path_str.reserve(path.size());
  path_str.insert(path_str.end(), path.begin(), path.end());
  path_str = file_system.ParsePath(std::move(path_str)).generic_string();
  path.clear();
  path.insert(path.end(), path_str.begin(), path_str.end());
  return {};
}

}  // namespace pasta
