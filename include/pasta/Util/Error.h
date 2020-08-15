/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <string>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/Support/Error.h>
#include <llvm/Support/ErrorOr.h>
#include <llvm/Support/Format.h>
#include <llvm/Support/raw_ostream.h>
#pragma clang diagnostic pop

namespace pasta {

template <typename T>
inline static bool IsError(llvm::ErrorOr<T> &val) {
  return !val;
}

template <typename T>
inline static bool IsError(llvm::Expected<T> &val) {
  return !val;
}

template <typename T>
inline static std::string ErrorString(llvm::ErrorOr<T> &val) {
  return val.getError().message();
}

inline static std::string ErrorString(llvm::Error &val) {
  std::string err;
  llvm::raw_string_ostream os(err);
  llvm::handleAllErrors(std::move(val),
                        [&os](llvm::ErrorInfoBase &eib) { eib.log(os); });
  os.flush();
  return err;
}

template <typename T>
inline static std::string ErrorString(llvm::Expected<T> &val) {
  auto err = val.takeError();
  return ErrorString(err);
}

}  // namespace pasta
