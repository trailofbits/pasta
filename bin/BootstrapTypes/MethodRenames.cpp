/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Globals.h"

// Renames applied to Clang method names when emitting PASTA wrappers.
// Entries mapping to an empty string are blacklisted (not exposed at all).
const std::unordered_map<std::string, std::string> kCxxMethodRenames{

  // Things to disable.
  {"asOpaquePtr", ""},

  // These are all getters that we want to disable, normally with `get` prefix.
  {"TypePtr", ""},
  {"TypePtrOrNull", ""},
  {"AsOpaquePtr", ""},
  {"UnqualifiedType", ""},
  {"PackExpansionPattern", ""},

  {"BitWidthValue", ""},  // Already have `FieldDecl::BitWidth`.

  // These are all getters, normally with `get` prefix.
  {"TypeClass", "Kind"},
  {"TypeClassName", "KindName"},
  {"StmtClass", "Kind"},
  {"StmtClassName", "KindName"},

  {"TypeSourceInfo", "Type"},
  {"TypeInfo", "Type"},

  // Things to fixup.
  {"AdjustedType", "ResolvedType"},
  {"DeducedType", "ResolvedType"},
  {"DecayedType", "ResolvedType"},

  // Things to rename, most of these are singular and `CxxName` manages the
  // plural forms.
  {"SourceLocation", "Token"},
  {"SourceRange", "Tokens"},
  {"Vbase", "VirtualBase"},
  {"VBase", "VirtualBase"},
  {"Ctor", "Constructor"},
  {"Dtor", "Destructor"},
  {"Stmt", "Statement"},
  {"Cond", "Condition"},
  {"Ret", "Return"},
  {"Expr", "Expression"},
  {"Assoc", "Association"},
  {"Init", "Initializer"},
  {"Idx", "Index"},
  {"Location", "Token"},
  {"clauselists", "Clauses"},  // `clang::OMPRequiresDecl::clauselists`
  {"Ivar", "InstanceVariable"},
  {"Arg", "Argument"},
  {"Attr", "Attribute"},
  {"Redecl", "Redeclaration"},
  {"Impl", "Implementation"},
  {"Decl", "Declaration"},
  {"Def", "Definition"},
  {"Anon", "Anonymous"},
  {"Var", "Variable"},
  {"Loc", "Location"},
  {"Asm", "Assembly"},
  {"MSAsm", "MSAssembly"},
  {"Str", "String"},
  {"Ident", "Identifier"},
  {"Ref", "Reference"},
  {"Orig", "Original"},
  {"Priv", "Private"},
  {"Pub", "Public"},
  {"Calc", "Calculate"},
  {"Par", "Parallel"},
  {"Dist", "Distance"},
  {"Iter", "Iteration"},
  {"Inc", "Increment"},
  {"Dict", "Dictionary"},
  {"Msg", "Message"},
  {"Char", "Character"},
  {"Bool", "Boolean"},
  {"Op", "Operation"},
  {"Ptr", "Pointer"},
  {"Mem", "Memory"},
  {"Parens", "Parentheses"},
  {"Paren", "Parenthesis"},
  {"Quals", "Qualifiers"},
  {"Qual", "Qualified"},
  {"Qualifieds", "Qualifiers"},
  {"Unqual", "Unqualified"},
  {"Elt", "Element"},
  {"RVVEltType", "RVVElementType"},
  {"SveEltType", "SveElementType"},
  {"noload_decls", "AlreadyLoadedDeclarations"},
  {"Noload_decls", "AlreadyLoadedDeclarations"},
  {"Param", "Parameter"},
  {"Params", "Parameters"},
  {"Brac", "Brace"},
  {"RBrac", "RightBrace"},
  {"LBrac", "LeftBrace"},
  {"NameAsString", "Name"},  // getNameAsString -> getName
  {"Val", "Value"},
  {"Val1", "Value1"},
  {"Val2", "Value2"},
  {"TInfo", "TypeInfo"},
  {"Cmd", "Command"},
  {"TST", "TemplateSpecializationType"},
  {"KW", "Keyword"},
  {"Addr", "Address"},
  {"Imp", "Implicit"},

  {"ColonLocFirst", "FirstColonToken"},
  {"ColonLocSecond", "SecondColonToken"},
  {"ArrayElementTypeNoTypeQualified", "ArrayElementTypeWithoutQualifiers"},
  {"SwitchCaseList", "FirstSwitchCase"},
  {"FindFirstNamedDataMember", "FirstNamedDataMember"},
  {"OuterLocStart", "FirstOuterToken"},
  {"InnerLocStart", "FirstInnerToken"},
  {"RightLoc", "RBracketToken"},
  {"LeftLoc", "LBracketToken"},
  {"DerefType", "DereferencedType"},
};
