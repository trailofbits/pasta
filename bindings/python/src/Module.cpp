/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Bindings.h"

#include <pasta/Util/Init.h>

namespace pasta {
void RegisterAllAST(nanobind::module_&);
};

NB_MODULE(pypasta, m) {
    static pasta::InitPasta initPasta;
    pasta::RegisterArgumentVector(m);
    pasta::RegisterCompileCommand(m);
    pasta::RegisterFileSystem(m);
    pasta::RegisterFileManager(m);
    pasta::RegisterToken(m);
    pasta::RegisterMacro(m);
    pasta::RegisterPrinter(m);
    pasta::RegisterCompileJob(m);
    pasta::RegisterCompiler(m);
    pasta::RegisterAST(m);
    pasta::RegisterAllAST(m);
}
