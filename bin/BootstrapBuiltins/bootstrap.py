# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

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

class CompileCommandItem(TypedDict):
  directory: str
  command: str
  file: str

class NormalizedCompileCommandItem(TypedDict):
  directory: str
  arguments: List[str]
  file: str

def _create_compiler_from_args(cp, extra_args, fp, fm, tl):
  args: List[str] = [cp, "-E", "-c", fp, "-o", "/dev/null", "-v"] + extra_args
  sysroot = subprocess.run(args, stderr=subprocess.PIPE, encoding=locale.getpreferredencoding())
  if sysroot.returncode != 0 and len(sysroot.stderr) == 0:
      raise RuntimeError(os.strerror(sysroot.returncode))
  if 'End of search list.' not in sysroot.stderr:
      if 'error: ' in sysroot.stderr:
          pos = sysroot.stderr.find('error: ')
          sysroot_str = sysroot.stderr[pos + 7:].strip()
      else:
          raise RuntimeError(f'Unknown error: {sysroot.stderr}')
  else:
      sysroot_str = sysroot.stderr

  args.append("-Wno-missing-sysroot")
  args.append("-isysroot")
  args.append("/trail_of_bits")
  cwd = os.getcwd()

  no_sysroot = subprocess.run(args, stderr=subprocess.PIPE, cwd=cwd, encoding=locale.getpreferredencoding())
  if no_sysroot.returncode != 0 and len(no_sysroot.stderr) == 0:
      raise RuntimeError(os.strerror(no_sysroot.returncode))
  if 'End of search list.' not in no_sysroot.stderr:
      raise RuntimeError(f'Unknown error: {no_sysroot.stderr}')

  return Compiler.create(fm, pathlib.Path(cp), pathlib.Path(cwd), CompilerName.UNKNOWN, tl, sysroot_str, no_sysroot.stderr)

BUILTIN_TK = {
  BuiltinTypeKind.VOID: "v",
  BuiltinTypeKind.INT: "i",
  BuiltinTypeKind.FLOAT: "f",
  BuiltinTypeKind.DOUBLE: "d",
}

def run_on_builtin_type(type: BuiltinType):
  print(type.builtin_kind)
  return ""

TYPE_VISITOR = {
  ElaboratedType: (lambda t: run_on_type(t.named_type)),
  BuiltinType: run_on_builtin_type
}

def run_on_type(type: Type) -> str:
  return TYPE_VISITOR.get(type.__class__, lambda t: str(t.__class__))(type)

def run_on_function(func: FunctionDecl):
  if func.builtin_id != 0:
    return

  if not func.name.startswith("__builtin"):
    return

  proto: str = run_on_type(func.return_type)
  for param in func.parameters:
    proto += run_on_type(param.type)

  print(f"TARGET_BUILTIN({func.name}, \"{proto}\", \"\", \"\")")

def run_on_ast(ast: AST):
  dc: DeclContext = DeclContext.cast(ast.translation_unit)
  for decl in dc.declarations:
    if isinstance(decl, FunctionDecl):
      run_on_function(decl)

if __name__ == "__main__":
  parser = ArgumentParser(description='Regularlize a compile_commands.json file')
  parser.add_argument('builtin_declarations')
  args = parser.parse_args()

  gcc_h_list = list(os.path.split(__file__))
  gcc_h_list[-1] = "GCC.h"
  gcc_h = os.path.sep.join(gcc_h_list)

  fs: FileSystem = FileSystem.create_native()
  fm: FileManager = FileManager(fs)
  cc: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.C)
  args = ArgumentVector(["cc", "-x", "c", "-include", gcc_h,
                         args.builtin_declarations])
  cmd = CompileCommand.create_from_arguments(args, gcc_h_list[0])
  jobs = cc.create_jobs_for_command(cmd)
  
  for job in jobs:
    run_on_ast(job.run())

