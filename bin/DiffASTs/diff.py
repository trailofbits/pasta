from pypasta import *
from graphtage import printer
from graphtage.pydiff import print_diff, build_tree
from argparse import ArgumentParser
import os, sys


def _generate_ast(source_file: str, cxx: Compiler) -> AST:
    """Generate a Clang AST from a source file."""
    ast = None

    argv = ArgumentVector(
        [str(cxx.executable_path), "-x", "c++", "-std=c++20", source_file]
    )
    cmd = CompileCommand.create_from_arguments(argv, os.path.dirname(__file__))
    jobs = cxx.create_jobs_for_command(cmd)

    if isinstance(jobs, str):
        print(jobs)
        sys.exit(1)

    for job in jobs:
        ast = job.run()
        if isinstance(ast, str):
            print(ast)
            sys.exit(1)

    return ast


def main():
    """Using pasta, generate two Clang ASTs from two source files and diff them
    using graphtage.
    """
    parser = ArgumentParser(description="diff two Clang ASTs using pasta")
    parser.add_argument("source_file1", type=str)
    parser.add_argument("source_file2", type=str)

    args = parser.parse_args()

    fs: FileSystem = FileSystem.create_native()
    fm: FileManager = FileManager(fs)
    cxx: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.CXX)

    ast1 = _generate_ast(args.source_file1, cxx)
    ast2 = _generate_ast(args.source_file2, cxx)

    with printer.DEFAULT_PRINTER as p:
        print_diff(str(ast1.main_file), str(ast2.main_file), printer=p)


if __name__ == "__main__":
    main()
