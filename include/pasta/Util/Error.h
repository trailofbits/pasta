/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <system_error>

namespace pasta {

void ClearLastError(void);

std::error_code GetLastError(void);

}  // namespace pasta
