/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <string>

namespace clang {
class SourceManager;
class LangOptions;
class Token;
} // namespace clang

namespace pasta {

// Read the data of the token into the passed in string pointer
bool ReadRawToken(clang::SourceManager &source_manager,
                  clang::LangOptions &lang_opts,
                  const clang::Token &tok, std::string *out);

} // namespace pasta
