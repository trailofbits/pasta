from pypasta import *

from graphtage import ListNode, StringNode, TreeNode
from graphtage.ast import Module
from graphtage.builder import BasicBuilder, Builder
from graphtage.dataclasses import DataClassNode
from graphtage.tree import GraphtageFormatter

from typing import List


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


def children(node: Decl | Stmt):
    if isinstance(node, Decl):
        dc = DeclContext.cast(node)
        if hasattr(node, "declarations"):
            yield from dc.declarations
    elif isinstance(node, Stmt):
        yield from node.children


class PastaASTBuilder(BasicBuilder):
    # ==================== TranslationUnitDecl ====================
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

    # ==================== Decl ====================

    @Builder.builder(Decl)
    def build_leaf_decl(self, node: Decl, _):
        return Name(node.name)

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
        return Function(
            name=StringNode(node.name),
            decls=ListNode(decl_nodes),
            body=ListNode(child_nodes),
        )

    # ==================== Stmt ====================

    @Builder.expander(Stmt)
    def expand_stmt(self, stmt: Stmt):
        yield stmt.kind_name
        yield from children(stmt)

    @Builder.builder(Stmt)
    def build_stmt(self, stmt: Stmt, children: List[TreeNode]):
        if hasattr(stmt, "declarations"):
            num_declarations = len(stmt.declarations)
        else:
            num_declarations = 0
        return Statement(
            kind_name=children[0],
            decls=ListNode(children[1 : num_declarations + 1]),
            body=ListNode(children[1 + num_declarations :]),
        )


class PastaDiffFormatter(GraphtageFormatter):
    pass
