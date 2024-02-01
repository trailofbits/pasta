from pypasta import *

from graphtage import ListNode, StringNode, TreeNode
from graphtage.ast import Module
from graphtage.builder import BasicBuilder, Builder
from graphtage.dataclasses import DataClassNode
from graphtage.printer import Printer
from graphtage.tree import GraphtageFormatter
from graphtage.sequences import SequenceFormatter

from typing import List, Any

# TODO: define Pasta AST nodes here to allow for diff'ing by source code
# so that this includes file tokens
# class PastaNode(DataClassNode):
#     file_tokens: StringNode | None

# This class is to support the above later on.
# class FileToken(DataClassNode):
#     data: StringNode
#     kind: StringNode
#     macro_location: StringNode
#     file_location: StringNode

# ==================== Util Nodes ====================
class Name(StringNode):
    def __init__(self, name: str):
        super().__init__(name, quoted=False)

class ChildrenListNode(ListNode):
    def __init__(self, children: List[TreeNode]):
        super().__init__(children, allow_list_edits=True, allow_list_edits_when_same_length=True)

# ==================== AST Nodes ====================

class TranslationUnitDeclNode(DataClassNode):
    kind_name: Name
    decls: ChildrenListNode

class CompoundStmtNode(DataClassNode):
    kind_name: Name
    stmts: ChildrenListNode

class FunctionDeclNode(DataClassNode):
    kind_name: Name
    name: Name
    param_decls: ChildrenListNode
    cs: CompoundStmtNode

# class DeclNode(DataClassNode):
#     name: Name

class StmtNode(DataClassNode):
    kind_name: Name
    body: ChildrenListNode

class DeclStmtNode(DataClassNode):
    kind_name: Name
    decls: ListNode
    stmts: ChildrenListNode

# ==================== AST Builder ====================

def children(node: Decl | Stmt):
    if isinstance(node, DeclStmt):
        dc = DeclContext.cast(node)
        yield from dc.declarations
        yield from node.children
    if isinstance(node, Decl):
        dc = DeclContext.cast(node)
        if hasattr(node, "declarations"):
            yield from dc.declarations
    elif isinstance(node, Stmt):
        yield from node.children
    

# TODO: handle macro expansions
# def file_tokens(node):
#     # print(node)
#     seen_macros = set()
#     for tok in node.tokens:
#         ml = tok.macro_location
#         fl = tok.file_location
#         if not ml:
#             if fl:
#                 # print(fl)
#                 yield fl
#             continue
    
#     # Not a macro
#     if not ml:
#         return
    
#     while ml.parent:
#         ml = ml.parent

#         if ml in seen_macros:
#             continue

#         seen_macros.add(ml)
#         fft = node.begin_token.file_location
#         lft = node.end_token.file_location
#         file = File.containing(fft)
#         assert file == File.containing(lft)
#         file_toks = file.tokens
#         for i in range(fft.index, lft.index + 1):
#             # print(file_toks[i])
#             yield file_toks[i]

class PastaASTBuilder(BasicBuilder):
    # ==================== TranslationUnitDecl ====================

    @Builder.expander(TranslationUnitDecl)
    def expand_ast(self, node: TranslationUnitDecl):
        # build only FunctionDecl nodes
        function_decls = [decl for decl in DeclContext.cast(node).declarations if isinstance(decl, FunctionDecl)]
        return function_decls

    @Builder.builder(TranslationUnitDecl)
    def build_ast(self, _, children: List[TreeNode]):
        # print("Building TranslationUnitDecl")
        return TranslationUnitDeclNode(
            kind_name=Name("TranslationUnitDecl"),
            decls=ChildrenListNode(children),
        )

    # ==================== Decl ====================

    @Builder.builder(Decl)
    def build_leaf_decl(self, node: Decl, _):
        # print("Building Decl " + node.name)
        return Name(node.name)

    @Builder.expander(FunctionDecl)
    def expand_function(self, node: FunctionDecl):
        # print("Expanding FunctionDecl " + node.name)
        context = DeclContext.cast(node)
        # only want function parameters
        param_decls = [decl for decl in context.declarations if isinstance(decl, ParmVarDecl)]
        yield from param_decls
        yield node.body # CompoundStmt

    @Builder.builder(FunctionDecl)
    def build_function(self, node: FunctionDecl, children: List[TreeNode]):
        # print("Building FunctionDecl " + node.name)
        param_decl_nodes, cs = children[:-1], children[-1]
        return FunctionDeclNode(
            kind_name=Name("FunctionDecl"),
            name=Name(node.name),
            param_decls=ChildrenListNode(param_decl_nodes),
            cs=cs,
        )

    # ==================== Stmt ====================

    @Builder.expander(Stmt)
    def expand_stmt(self, stmt: Stmt):
        # print("Expanding Stmt " + stmt.kind_name)
        yield from children(stmt)

    @Builder.builder(Stmt)
    def build_stmt(self, stmt: Stmt, children: List[TreeNode]):
        # print("Building Stmt " + stmt.kind_name)
        return StmtNode(
            kind_name=Name(stmt.kind_name),
            body=ChildrenListNode(children),
        )

    # ==================== DeclStmt ====================

    @Builder.expander(DeclStmt)
    def expand_decl_stmt(self, ds: DeclStmt):
        # print("Expanding DeclStmt")
        yield from ds.declarations
        yield from ds.children

    @Builder.builder(DeclStmt)
    def build_decl_stmt(self, stmt: DeclStmt, children: List[TreeNode]):
        # print("Building DeclStmt")
        return DeclStmtNode(
            kind_name=Name(stmt.kind_name),
            decls=ChildrenListNode(children[:len(stmt.declarations)]),
            stmts=ChildrenListNode(children[len(stmt.declarations):]),
        )

    # ==================== CompoundStmt ====================

    @Builder.expander(CompoundStmt)
    def expand_compound_stmt(self, cs: CompoundStmt):
        # print("Expanding CompoundStmt")
        yield from cs.children
    
    @Builder.builder(CompoundStmt)
    def build_compound_stmt(self, stmt: CompoundStmt, children: List[TreeNode]):
        # print("Building CompoundStmt")
        return CompoundStmtNode(
            kind_name=Name(stmt.kind_name),
            stmts=ChildrenListNode(children),
        )

# ==================== Formatter ====================

# prints out children for each node. Extension of SequenceFormatter.
class ChildrenFormatter(SequenceFormatter):
    is_partial = True

    def __init__(self):
        # for debugging
        # super().__init__('[', '', ']')
        super().__init__('', '', '')
    
    # def print_FunctionDeclNode(self, printer: Printer, node: FunctionDeclNode):
    #     printer.write("FunctionDecl ")
    #     self.print(printer, node.name)
    #     printer.newline()
    #     self.print_ListNode(printer, node.param_decls)
    #     self.print(printer, node.cs)
    
    def print_CompoundStmtNode(self, printer: Printer, node: CompoundStmtNode):
        printer.write("CompoundStmt")
        printer.newline()
        self.print_ListNode(printer, node.stmts)
    
    def print_ChildrenListNode(self, printer: Printer, *args, **kwargs):
        # printer.newline()
        # printer.write("ChildrenListNode")
        printer.indent()
        printer.newline()
        super().print_SequenceNode(printer, *args, **kwargs)

class PastaDiffFormatter(GraphtageFormatter):
    sub_format_types = [ChildrenFormatter]

    def print_Name(self, printer: Printer, node: Name):
        printer.write(node.object + " ")

    # def print_DeclNode(self, printer: Printer, node: DeclNode):
    #     printer.write("Decl")
    #     printer.newline()
    #     super().print_StringNode(printer, node.name)

    # def print_TranslationUnitDeclNode(self, printer: Printer, node: TranslationUnitDeclNode):
    #     printer.write("TranslationUnitDecl")
    #     printer.newline()
    #     for decl in node.decls:
    #         printer.indent()
    #         self.print(printer, decl)

    def print_DeclStmtNode(self, printer: Printer, node: DeclStmtNode):
        printer.write("DeclStmt")
        printer.newline()
        printer.indent()
        self.print(printer, node.decls)
        self.print(printer, node.stmts)
        # super().print_ListNode(printer, node.decls)
        # super().print_ListNode(printer, node.stmts)
    
    def print_StmtNode(self, printer: Printer, node: StmtNode):
        printer.write("Stmt ")
        self.print(printer, node.kind_name)
        printer.indent()
        # self.print(printer, node.decls)
        self.print(printer, node.body)
