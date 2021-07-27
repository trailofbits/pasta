/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/Util/Error.h>

#if defined(WIN32) || defined(_WIN32)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#  include <errhandlingapi.h>
#endif

namespace pasta {

void ClearLastError(void) {
#ifdef _WIN32
  ::SetLastError(0);
#else
  errno = 0;
#endif
}

std::error_code GetLastError(void) {
#ifdef _WIN32
  return std::error_code(::GetLastError(), std::system_category());
#else
  return std::error_code(errno, std::generic_category());
#endif
}

}  // namespace pasta
