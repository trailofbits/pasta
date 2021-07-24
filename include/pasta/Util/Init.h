/*
 * Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.
 */

#pragma once

namespace pasta {

class InitPasta;

// RAII initializer for LLVM.
class InitLLVM {
 public:
  InitLLVM(void);
  ~InitLLVM(void);

 private:
  InitLLVM(const InitLLVM &) = delete;
  InitLLVM(InitLLVM &&) noexcept = delete;
};

// RAII initializer for file descritors.
class FileDescriptorInit {
 private:
  friend class InitPasta;

  FileDescriptorInit(void);
};

// Initialize the Pasta library.
class InitPasta {
 public:
  InitPasta(void);
  ~InitPasta(void);

 private:
  FileDescriptorInit fds;
  InitLLVM llvm;

  InitPasta(const InitPasta &) = delete;
  InitPasta(InitPasta &&) noexcept = delete;
};

}  // namespace pasta
