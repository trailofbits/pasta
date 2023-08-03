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


if __name__ == "__main__":
  parser = ArgumentParser(description='Regularlize a compile_commands.json file')
  parser.add_argument('compile_commands')
  parser.add_argument('--c_compiler')
  parser.add_argument('--cxx_compiler')
  args = parser.parse_args()

  fs = FileSystem.create_native()
  fm = FileManager(fs)

  with tempfile.NamedTemporaryFile(suffix=".c") as c_file:
    cc: Compiler = _create_compiler_from_args(
        args.c_compiler, ["-x", "c", "-std=c18"],
        c_file.name, fm, TargetLanguage.C)

  with tempfile.NamedTemporaryFile(suffix=".cpp") as cxx_file:
    cxx: Compiler = _create_compiler_from_args(
        args.cxx_compiler, ["-x", "c++", "-std=c++20"],
        cxx_file.name, fm, TargetLanguage.CXX)

  with open(args.compile_commands) as file:
    for record in json.load(file):
      args = ArgumentVector(record['command'])
      cmd = CompileCommand.create_from_arguments(args, record['directory'])
      if isinstance(cmd, str):
        print(cmd, file=sys.stderr)
        continue

      if "++" in record['command']:
        jobs = cxx.create_jobs_for_command(cc)
      else:
        jobs = cc.create_jobs_for_command(cc)

      if isinstance(jobs, str):
        print(jobs, file=sys.stderr)
        continue
      
      normalized: List[NormalizedCompileCommandItem] = []

      for job in jobs:
        normalized.append({
           "file": job.source_file.path,
           "arguments": job.arguments.arguments,
           "directory": job.working_directory,
        })
      json.dump(normalized, indent=2, fp=sys.stdout)
