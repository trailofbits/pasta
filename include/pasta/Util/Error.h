/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <system_error>

namespace pasta {

void ClearLastError(void);

std::error_code GetLastError(void);

}  // namespace pasta
