/*
 * Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.
 */

#include <pasta/Util/Init.h>

#include <csignal>
#include <cstdlib>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/Support/CrashRecoveryContext.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/Process.h>
#include <llvm/Support/TargetSelect.h>
#pragma clang diagnostic pop

namespace pasta {

InitLLVM::InitLLVM(void) {

  // We're a library, and we *don't* want LLVM to do any crash recovery on
  // our behalf.
  llvm::CrashRecoveryContext::Disable();
  llvm::sys::DynamicLibrary::LoadLibraryPermanently(nullptr);
}

InitLLVM::~InitLLVM(void) {
  llvm::llvm_shutdown();
}

FileDescriptorInit::FileDescriptorInit(void) {
  if (llvm::sys::Process::FixupStandardFileDescriptors()) {
    exit(EXIT_FAILURE);
  }
}

InitPasta::InitPasta(void) {}

InitPasta::~InitPasta(void) {}

}  // namespace pasta
