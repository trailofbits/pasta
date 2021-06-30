/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Python/Bindings.h>
#include <pasta/Util/Init.h>

#include <memory>

#include "Compile/Compile.h"

namespace pasta {
namespace py {
namespace {

static std::unique_ptr<InitPasta> gPastaInitializer;

struct ModuleState {
  PyObject *error;
};

static PyMethodDef gModuleMethods[] = {
    {}  // Sentinel.
};

static struct PyModuleDef gModuleDef = {PyModuleDef_HEAD_INIT,
                                        "pasta_internal",
                                        "Peter's Amazing Syntax Tree Analyzer",
                                        sizeof(struct ModuleState),
                                        gModuleMethods,
                                        nullptr,
                                        nullptr,
                                        nullptr,
                                        nullptr};

}  // namespace

PyMODINIT_FUNC PyInit_pasta_internal(void) {
  auto m = PyModule_Create(&gModuleDef);
  if (!m) {
    return nullptr;
  }

  gPastaInitializer.reset(new InitPasta);

  if (!AST::TryAddToModule(m) || !CompileJob::TryAddToModule(m) ||
      !CompileCommand::TryAddToModule(m) || !Compiler::TryAddToModule(m) ||
      !SourceLocation::TryAddToModule(m) ||
      !TokenKind::TryAddToModule(m) || !Token::TryAddToModule(m)) {
    return nullptr;
  }

  return m;
}

}  // namespace py
}  // namespace pasta
