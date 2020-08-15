/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <pasta/Compile/AST.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/FileManager.h>
#pragma clang diagnostic pop

namespace clang {
class CompilerInstance;
class TranslationUnitDecl;
}  // namespace clang
namespace llvm {
namespace vfs {
class FileSystem;
class InMemoryFileSystem;
class OverlayFileSystem;
}  // namespace vfs
}  // namespace llvm
namespace pasta {

class ASTImpl {
 public:
  ASTImpl(void);
  ~ASTImpl(void);

  llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> real_fs;
  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> overlay_fs;
  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> mem_fs;

  std::shared_ptr<clang::CompilerInstance> ci;
  llvm::IntrusiveRefCntPtr<clang::FileManager> fm;

  clang::TranslationUnitDecl *tu{nullptr};
};

}  // namespace pasta
