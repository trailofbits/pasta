/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <string>
#include <llvm/ADT/StringRef.h>

std::string Capitalize(llvm::StringRef name);

std::string CxxName(llvm::StringRef name);
