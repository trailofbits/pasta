/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include "Compiler.h"

namespace pasta {

Compiler::~Compiler(void) {}

Compiler::Compiler(CompilerImpl *impl_) : impl(impl_) {}

}  // namespace pasta
