from pypasta import *
from graphtage import BuildOptions, ListNode, printer, StringNode, TreeNode
from graphtage.ast import Module
from graphtage.builder import BasicBuilder, Builder
from graphtage.dataclasses import DataClassNode
from graphtage.pydiff import PyDiffFormatter  # print_diff, build_tree
from argparse import ArgumentParser
import os, sys
from typing import List


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


class Function(DataClassNode):
    name: StringNode
    decls: ListNode
    body: ListNode


class Name(StringNode):
    def __init__(self, name: str):
        super().__init__(name, quoted=False)


class Statement(DataClassNode):
    kind_name: StringNode
    decls: ListNode
    body: ListNode


class PastaASTBuilder(BasicBuilder):
    @Builder.expander(TranslationUnitDecl)
    def expand_ast(self, node: TranslationUnitDecl):
        return (
            decl
            for decl in DeclContext.cast(node).declarations
            if isinstance(decl, FunctionDecl)
        )

    @Builder.builder(TranslationUnitDecl)
    def build_ast(self, _, children: List[TreeNode]):
        return Module(children)

    @Builder.expander(FunctionDecl)
    def expand_function(self, node: FunctionDecl):
        context = DeclContext.cast(node)
        decls = context.declarations
        children = node.body.children
        yield from decls
        yield from children

    @Builder.builder(FunctionDecl)
    def build_function(self, node: FunctionDecl, children: List[TreeNode]):
        num_children = len(node.body.children)
        num_decls = len(children) - num_children
        decl_nodes, child_nodes = children[:num_decls], children[num_decls:]
        return Function(name=StringNode(node.name), decls=ListNode(decl_nodes), body=ListNode(child_nodes))

    @Builder.builder(Decl)
    def build_leaf_decl(self, node: Decl, _):
        return Name(node.name)

    @Builder.expander(Stmt)
    def expand_stmt(self, stmt: Stmt):
        yield stmt.kind_name
        if hasattr(stmt, "declarations"):
            yield from stmt.declarations
        yield from stmt.children

    @Builder.builder(Stmt)
    def build_stmt(self, stmt: Stmt, children: List[TreeNode]):
        if hasattr(stmt, "declarations"):
            num_declarations = len(stmt.declarations)
        else:
            num_declarations = 0
        return Statement(
            kind_name=children[0],
            decls=ListNode(children[1:num_declarations+1]),
            body=ListNode(children[1+num_declarations:])
        )


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

    builder = PastaASTBuilder(options=BuildOptions(check_for_cycles=True))  # , ignore_cycles=True))

    tree1 = builder.build_tree(ast1.translation_unit)
    tree2 = builder.build_tree(ast2.translation_unit)

    # tokens1 = [t.kind for t in ast1.main_file.tokens]
    # tokens2 = [t.kind for t in ast2.main_file.tokens]

    with printer.DEFAULT_PRINTER as p:
        d = tree1.diff(tree2)
        PyDiffFormatter.DEFAULT_INSTANCE.print(p, d)


if __name__ == "__main__":
    main()
