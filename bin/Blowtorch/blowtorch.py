#!/usr/bin/env python3

#
# Copyright (c) 2023 Trail of Bits, Inc.
#

from pypasta import *
from typing import TypedDict, List
from multiprocessing import Pool

class CompileCommandItem(TypedDict):
    directory: str
    command: str
    file: str

def _create_compiler_from_args(fm: FileManager, vec: ArgumentVector, cwd):
    import subprocess
    import locale
    import os
    new_args = []
    args: List[str] = vec.arguments
    skip = False
    for arg in args:
        if skip:
            skip = False
            if not arg.startswith('-') and len(arg) > 1:
                continue
        
        if arg.startswith('-Wno'):
            pass
        elif arg.startswith(('-W', '-pedantic')) or arg == '-pic-is-pie':
            continue
        elif arg in ('-mllvm', '-Xclang', '-dependency-file', '-diagnostic-log-file', '-header-include-file', '-stack-usage-file', '-mrelocation-model', '-pic-level', '-main-file-name'):
            skip = True
            continue
        elif any(arg.startswith(x) for x in ('-file=', '-dependent-lib=', '-stats-file=', '-fprofile-list=', '-fxray-always-instrument=', '-fxray-never-instrument=', '-fxray-attr-list=', '-tsan-compound-read-before-write=', '-tsan-distinguish-volatile=', '-treat')):
            continue
        elif arg == '-o':
            skip = True
            new_args.append(arg)
            new_args.append('/dev/null')
            continue
        elif arg.startswith(("'-", '"-')) and arg.endswith(arg[0]):
            continue
        new_args.append(arg)

    new_args.append('-w')
    new_args.append('-Wno-everything')
    new_args.append('-P')
    new_args.append('-v')
    new_args.append('-include')
    new_args.append('/trail/of/bits')

    sysroot = subprocess.run(new_args, stderr=subprocess.PIPE, cwd=cwd, encoding=locale.getpreferredencoding())
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

    new_args.append('-isysroot')
    new_args.append(f'{cwd}/trail_of_bits')

    no_sysroot = subprocess.run(new_args, stderr=subprocess.PIPE, cwd=cwd, encoding=locale.getpreferredencoding())
    if no_sysroot.returncode != 0 and len(no_sysroot.stderr) == 0:
        raise RuntimeError(os.strerror(no_sysroot.returncode))
    if 'End of search list.' not in no_sysroot.stderr:
        raise RuntimeError(f'Unknown error: {no_sysroot.stderr}')

    return Compiler.create(fm, new_args[0], cwd, CompilerName.UNKNOWN, TargetLanguage.CXX, sysroot_str, no_sysroot.stderr)

def _compile(cmd: CompileCommandItem):
    import sys
    import inspect
    print('Work started on', cmd['file'])

    fs = FileSystem.create_native()
    fm = FileManager(fs)

    exceptions = []
    inspected = set()
    q = []

    args = ArgumentVector(cmd['command'])
    compile_command = CompileCommand.create_from_arguments(args, cmd['directory'])
    if isinstance(compile_command, str):
        print(compile_command, file = sys.stderr)
        return []

    compiler = _create_compiler_from_args(fm, args, cmd['directory'])
    jobs = compiler.create_jobs_for_command(compile_command)
    if isinstance(jobs, str):
        print(jobs, file = sys.stderr)
        return []

    for job in jobs:
        ast = job.run()
        if isinstance(ast, str):
            print(ast, file = sys.stderr)
            continue
        q.append(ast.translation_unit)
    
    while len(q) > 0:
        elem = q.pop()
        if isinstance(elem, list):
            for value in elem:
                q.append(value)
            continue
        elif not isinstance(elem, (Attr, Decl, Type, Stmt)) or elem in inspected:
            continue
        inspected.add(elem)
        try:
            for member in inspect.getmembers(elem):
                q.append(member[1])
        except RuntimeError as e:
            print(str(e))
            exceptions.append(str(e))

    return exceptions

if __name__ == '__main__':
    from argparse import ArgumentParser
    import json

    parser = ArgumentParser(description='Stress test all PASTA APIs')
    parser.add_argument('compile_commands')
    parser.add_argument('--sequential', default=False, const=True, action='store_const')
    args = parser.parse_args()

    with open(args.compile_commands) as file:
        compile_commands: list[CompileCommandItem] = json.load(file)
        res = set()
        if args.sequential:
            try:
                for row in map(_compile, compile_commands):
                    res = res.union(set(row))
            except KeyboardInterrupt:
                pass
        else:
            with Pool() as pool:
                for row in pool.map(_compile, compile_commands):
                    res = res.union(set(row))
        for exc in res:
            print(exc)