#
# Copyright (c) 2023, Trail of Bits, Inc.
# 
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

from pypasta import *
from argparse import ArgumentParser
from typing import TypedDict, List
import json
import locale
import os
import pathlib
import subprocess
import sys
import tempfile

# See `clang/Basic/Builtins.def`.
BUILTIN_TK = {
  BuiltinTypeKind.VOID: "v",
  BuiltinTypeKind.BOOLEAN: "b",
  BuiltinTypeKind.CHARACTER_S: "c",
  BuiltinTypeKind.S_CHAR: "c",
  BuiltinTypeKind.U_CHAR: "Uc",
  BuiltinTypeKind.W_CHAR_S: "w",
  BuiltinTypeKind.W_CHAR_U: "Uw",
  BuiltinTypeKind.SHORT: "s",
  BuiltinTypeKind.U_SHORT: "Us",
  BuiltinTypeKind.INT: "i",
  BuiltinTypeKind.U_INT: "Ui",
  BuiltinTypeKind.FLOAT: "f",
  BuiltinTypeKind.FLOAT16: "h",
  BuiltinTypeKind.DOUBLE: "d",
  BuiltinTypeKind.LONG: "Li",
  BuiltinTypeKind.U_LONG: "ULi",
  BuiltinTypeKind.LONG_LONG: "LLi",
  BuiltinTypeKind.U_LONG_LONG: "ULLi",
  BuiltinTypeKind.FLOAT128: "LLd",
}

def run_on_builtin_type(type: BuiltinType, sizes: List[int]) -> str:
  enc = BUILTIN_TK.get(type.builtin_kind, "?")
  if enc == "?":
    print(f"Unsupported builtin type kind: {type.builtin_kind}")
  return enc

# QI: An integer that is as wide as the smallest addressable unit, usually 8 bits.
# HI: An integer, twice as wide as a QI mode integer, usually 16 bits.
# SI: An integer, four times as wide as a QI mode integer, usually 32 bits.
# DI: An integer, eight times as wide as a QI mode integer, usually 64 bits.
# HF: A floating point value, as wide as a HI mode integer, usually 16 bits.
# SF: A floating point value, as wide as a SI mode integer, usually 32 bits.
# DF: A floating point value, as wide as a DI mode integer, usually 64 bits.

TYPEDEF_TK = {
  "size_t": "z",
  "udi": "UWi",
  "__m64": "V1Wi",

  "qi": "c",
  "v8qi": "V8c",
  "v16qi": "V16c",
  "v32qi": "V32c",
  "v64qi": "V64c",

  "hi": "s",
  "v4hi": "V4s",
  "v8hi": "V8s",
  "v16hi": "V16s",
  "v32hi": "V32s",
  "v32uhi": "V32Us",

  "int32_t": "i",
  "uint32_t": "Ui",
  "si": "i",
  "v2si": "V2i",
  "v4si": "V4i",
  "v8si": "V8i",
  "v16si": "V16i",
  "v16usi": "V16Ui",

  "int64_t": "Wi",
  "uint64_t": "UWi",
  "di": "Wi",
  "v1di": "V1Wi",
  "v2di": "V2Wi",
  "v4di": "V4Wi",
  "v8di": "V8Wi",
  "v8udi": "V8UWi",

  "hf": "h",
  "v8hf": "V8h",
  "v16hf": "V16h",
  "v32hf": "V23h",

  "sf": "f",
  "v2sf": "V2f",
  "v4sf": "V4f",
  "v8sf": "V8f",
  "v16sf": "V16f",

  "df": "d",
  "v2df": "V2d",
  "v4df": "V4d",
  "v8df": "V8d",

  "v256si": "V256i",
}

VECTOR_SIZE_BITS = {
  "v8qi": 64,
  "v16qi": 128,
  "v32qi": 256,
  "v64qi": 512,

  "v4hi": 64,
  "v8hi": 128,
  "v16hi": 256,
  "v32hi": 512,
  "v32uhi": 512,

  "v2si": 64,
  "v4si": 128,
  "v8si": 256,
  "v16si": 512,
  "v16usi": 512,
  "v256si": 8192,

  "__m64": 64,
  "v1di": 64,
  "v2di": 128,
  "v4di": 256,
  "v8di": 512,
  "v8udi": 512,

  "v8hf": 128,
  "v16hf": 256,
  "v32hf": 512,

  "v2sf": 64,
  "v4sf": 128,
  "v8sf": 256,
  "v16sf": 512,

  "v2df": 128,
  "v4df": 256,
  "v8df": 512,
}

def run_on_unsupported(type: Type, sizes: List[int]) -> str:
  print(f"Unhandled type kind: {type.kind}")
  return "?"

def run_on_typedef(type: TypedefType, sizes: List[int]) -> str:
  typedef_name = type.declaration.name
  sizes.append(VECTOR_SIZE_BITS.get(typedef_name, 0))
  if sizes[-1] == 0:
    assert not typedef_name.startswith("v")

  enc = TYPEDEF_TK.get(typedef_name, "?")
  if enc == "?":
    print(f"Unsupported typedef name: {typedef_name}")
  return enc

def run_on_elaborated(type: ElaboratedType, sizes: List[int]) -> str:
  return run_on_type(type.named_type, sizes)

def run_on_qualified(type: QualifiedType, sizes: List[int]) -> str:
  enc: str = run_on_type(type.unqualified_type, sizes)
  if type.is_const_qualified:
    enc += "C"
  if type.is_volatile_qualified:
    enc += "D"
  if type.is_restrict_qualified:
    enc += "R"
  return enc

def run_on_pointer(type: PointerType, sizes: List[int]) -> str:
  return run_on_type(type.pointee_type, sizes) + "*"

TYPE_VISITOR = {
  TypeKind.ELABORATED: run_on_elaborated,
  TypeKind.BUILTIN: run_on_builtin_type,
  TypeKind.TYPEDEF: run_on_typedef,
  TypeKind.QUALIFIED: run_on_qualified,
  TypeKind.POINTER: run_on_pointer,
}

def run_on_type(type: Type, sizes: List[int]) -> str:
  return TYPE_VISITOR.get(type.kind, run_on_unsupported)(type, sizes)

def run_on_function(func: FunctionDecl, allow_builtins: bool,
                    treat_as_runtime_functions: bool):
  
  if func.builtin_id != 0 and not allow_builtins:
    return

  if not func.name.startswith("_"):
    return

  vec_sizes: List[int] = [0,]

  proto: str = run_on_type(func.return_type, vec_sizes)
  for param in func.parameters:
    proto += run_on_type(param.type, vec_sizes)

  if func.is_variadic:
    proto += "."

  # Find the maximum vector size.
  max_vec_size = max(vec_sizes)
  vec_enc: str = ""
  if 0 < max_vec_size:
    vec_enc = f"V:{max_vec_size}:"

  # If there's a pointer to non-constant data, then assume this might write
  # through the pointer.
  const_enc: str = "c"
  if "*" in proto and not "C*" in proto:
    const_enc = ""

  # Pointer to volatile data means each read might produce different data.
  if "D*" in proto:
    const_enc = ""

  rt_enc: str = ""
  if treat_as_runtime_functions:
    rt_enc = "f"

  # `n` for nothrow
  # `c` for const
  # `~` for PASTA!
  print(f"TARGET_BUILTIN({func.name}, \"{proto}\", \"~n{const_enc}{rt_enc}{vec_enc}\", \"\")")

def run_on_ast(ast: AST, allow_builtins: bool, treat_as_runtime_functions: bool):
  dc: DeclContext = DeclContext.cast(ast.translation_unit)
  for decl in dc.declarations:
    if isinstance(decl, FunctionDecl):
      run_on_function(decl, allow_builtins, treat_as_runtime_functions)

if __name__ == "__main__":
  parser = ArgumentParser(description='Generate TARGET_BUILTIN macro uses to handle Clang-unsupported intrinsics')
  parser.add_argument('--allow_builtins', action='store_true')
  parser.add_argument('--try_as_cxx', action='store_true')
  parser.add_argument('--treat_as_runtime_functions', action='store_true')
  parser.add_argument('builtin_declarations')
  cmd_args = parser.parse_args()

  cc_name: str = "cc"
  cc_lang: str = "c"
  if cmd_args.try_as_cxx:
    cc_name = "c++"
    cc_lang = "c++"

  gcc_h_list = list(os.path.split(__file__))
  gcc_h_list[-1] = "GCC.h"
  gcc_h = os.path.sep.join(gcc_h_list)

  fs: FileSystem = FileSystem.create_native()
  fm: FileManager = FileManager(fs)
  cc: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.C)
  args = ArgumentVector([cc_name, "-x", cc_lang, "-include", gcc_h,
                         cmd_args.builtin_declarations])
  cmd = CompileCommand.create_from_arguments(args, gcc_h_list[0])
  maybe_jobs = cc.create_jobs_for_command(cmd)
  
  if isinstance(maybe_jobs, str):
    print(maybe_jobs)
    sys.exit(1)

  for job in maybe_jobs:
    maybe_ast = job.run()
    if isinstance(maybe_ast, str):
      print(maybe_ast)
      sys.exit(1)

    elif isinstance(maybe_ast, AST):
      run_on_ast(maybe_ast, cmd_args.allow_builtins,
                 cmd_args.treat_as_runtime_functions)

