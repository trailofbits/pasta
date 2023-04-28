#include "bindings.h"

#include <pasta/Util/Init.h>

PYBIND11_MODULE(pasta, m) {
    static pasta::InitPasta initPasta;
    pasta::RegisterArgumentVector(m);
    pasta::RegisterCompileCommand(m);
    pasta::RegisterFileSystem(m);
    pasta::RegisterFileManager(m);
    pasta::RegisterCompileJob(m);
    pasta::RegisterCompiler(m);
}