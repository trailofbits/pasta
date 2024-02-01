import os, sys
from argparse import ArgumentParser

from pypasta import *

from graphtage import BuildOptions, printer
from graphtage.pydiff import PyDiffFormatter  # print_diff, build_tree

from pastadiff import PastaASTBuilder, PastaDiffFormatter


def _generate_ast(source_file: str, cc: Compiler, system_include_dir: str) -> AST:
    """Generate a Clang AST from a source file."""
    ast = None

    argv = ArgumentVector(
        [
            str(cc.executable_path),
            "-x",
            "c",
            "-std=c18",
            "-isystem",
            str(system_include_dir),
            source_file,
        ]
    )
    cmd = CompileCommand.create_from_arguments(argv, os.path.dirname(__file__))
    jobs = cc.create_jobs_for_command(cmd)

    if isinstance(jobs, str):
        print(jobs)
        sys.exit(1)

    for job in jobs:
        ast = job.run()
        if isinstance(ast, str):
            print(ast)
            sys.exit(1)

    return ast


def _view_ast(ast: AST):
    """Prints out the Clang AST similar to https://godbolt.org/."""
    # Get TranslationUnitDecl
    tu = ast.translation_unit
    print(tu)
    dc = DeclContext.cast(tu)

    # Get FunctionDecl
    fd = None
    for decl in dc.declarations:
        if isinstance(decl, FunctionDecl):
            fd = decl
            print(decl, decl.token)
            break

    # Get ParmVarDecl
    fdc = DeclContext.cast(fd)
    for decl in fdc.declarations:
        if isinstance(decl, ParmVarDecl):
            print(decl, decl.token)

    # Get function body
    print(fd.body)
    for child in fd.body.children:
        print(child)
        if not isinstance(child, ReturnStmt):
            for decl in child.declarations:
                print(decl, decl.token)

        def _print_children(parent):
            for child in parent.children:
                print(child)
                if len(child.children) != 0:
                    _print_children(child)

        _print_children(child)


def main():
    """Using pasta, generate two Clang ASTs from two source files and diff them
    using graphtage.
    """
    parser = ArgumentParser(description="diff two Clang ASTs using pasta")
    parser.add_argument("--system-include-dir", required=True, type=str)
    parser.add_argument("source_file1", type=str)
    parser.add_argument("source_file2", type=str)

    args = parser.parse_args()

    fs: FileSystem = FileSystem.create_native()
    fm: FileManager = FileManager(fs)
    cc: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.C)

    ast1 = _generate_ast(args.source_file1, cc, args.system_include_dir)
    ast2 = _generate_ast(args.source_file2, cc, args.system_include_dir)

    builder = PastaASTBuilder(
        options=BuildOptions(check_for_cycles=True)
    )  # , ignore_cycles=True))

    tree1 = builder.build_tree(ast1.translation_unit)
    tree2 = builder.build_tree(ast2.translation_unit)

    # tokens1 = [t.kind for t in ast1.main_file.tokens]
    # tokens2 = [t.kind for t in ast2.main_file.tokens]

    with printer.DEFAULT_PRINTER as p:
        d = tree1.diff(tree2)
        PastaDiffFormatter.DEFAULT_INSTANCE.print(p, d)


if __name__ == "__main__":
    main()
