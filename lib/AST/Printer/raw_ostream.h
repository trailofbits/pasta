/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <llvm/Support/raw_ostream.h>
#include <unordered_set>

namespace pasta {

class raw_string_ostream : public clang::raw_ostream {
  std::string &OS;

  // write_impl function
  void write_impl(const char *Ptr, size_t Size) override {
    OS.append(Ptr, Size);
  };

  uint64_t current_pos() const override {
    return OS.size();
  }

  raw_string_ostream(const raw_string_ostream &ss) = delete;
  raw_string_ostream(raw_string_ostream &&ss) noexcept = delete;

public:

  // Keep track of already-printed definitions.
  std::unordered_set<void *> printed_defs;

  ~raw_string_ostream() override {
    flush();
  }

  explicit raw_string_ostream(std::string &O, int) : OS(O) {}

  size_t size(void) const {
    return 0;
  }

  std::string& str() {
    flush();
    return OS;
  }

  void reserveExtraSpace(uint64_t ExtraSize) override {
    OS.reserve(tell() + ExtraSize);
  }
};

}  // namespace pasta
