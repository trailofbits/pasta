
#pragma once

#include <llvm/Support/raw_ostream.h>

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

public:
  ~raw_string_ostream() override {
    flush();
  }

  raw_string_ostream(std::string &O) : OS(O) {}

  raw_string_ostream(const raw_string_ostream &ss) : OS(ss.OS) {}
  raw_string_ostream(raw_string_ostream &&ss) : OS(ss.OS) {}

  size_t size(void) const {
    return 0;
  }

  std::string& str() {
    flush();
    return OS;
  }

  void reserveExtraSpace(uint64_t ExtraSize) {
    OS.reserve(tell() + ExtraSize);
  }

};


}
