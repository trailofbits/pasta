/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/Util/File.h>

#include "FileManager.h"

namespace pasta {

FileImpl::FileImpl(const std::shared_ptr<FileManagerImpl> &owner_, Stat stat_)
    : owner(owner_),
      stat(std::move(stat_)) {}

FileToken::~FileToken(void) {}

File::~File(void) {}

// Return the file containing a given file token.
File File::Containing(const FileToken &tok) {
  return File(tok.impl);
}

// Return the path of this file.
std::filesystem::path File::Path(void) const noexcept {
  return impl->stat.full_path;
}

// Return the contents of this file.
Result<std::string_view, std::error_code> File::Data(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->data_lock);
  if (impl->has_data) {
    if (impl->data_ec) {
      return impl->data_ec;
    } else {
      return std::string_view(impl->data.data(), impl->data.size());
    }
  }

  impl->has_data = true;

  auto fm = impl->owner.lock();
  auto maybe_file = fm->file_system->ReadFile(impl->stat);
  if (maybe_file.Failed()) {
    impl->data_ec = maybe_file.TakeError();
    return impl->data_ec;
  } else {
    maybe_file.TakeValue().swap(impl->data);
    return std::string_view(impl->data.data(), impl->data.size());
  }
}

// Do we have cached data associated with this file?
bool File::HasCachedData(void) const noexcept {
  std::unique_lock<std::mutex> locker(impl->data_lock);
  return impl->has_data;
}

// Returns the status of this file.
const ::pasta::Stat &File::Stat(void) const noexcept {
  return impl->stat;
}


}  // namespace pasta
