# Macro Bootstrap

This is "stage 1" of the PASTA bootstrap process. It uses a bit of PASTA and
mostly Clang to parse Clang headers, and auto-generate a massive description of
the Clang API surface, in the form of a lot of macros. The results of running
this is that `bin/BootstrapTypes/Generated/Generated.h` is modified in place.

# Usage

```shell
./bootstrap-macros
```

# Example macros

The output describes the classes, their base classes, the methods, the number
of parameters each method takes, the instance fields, the enumerations and their
enumerators, etc.

```c
PASTA_BEGIN_CLANG_WRAPPER(DeclaratorDecl, 1786001652)
  PASTA_BEGIN_BASE_CLASSES(DeclaratorDecl, 1786001652)
    PASTA_PUBLIC_BASE_CLASS(DeclaratorDecl, 1786001652, ValueDecl, 1184932858)
  PASTA_END_BASE_CLASSES(DeclaratorDecl, 1786001652)
  PASTA_BEGIN_METHODS(DeclaratorDecl, 1786001652)
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 0, getBeginLoc, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 1, getInnerLocStart, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 2, getNumTemplateParameterLists, (unsigned int))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 3, getOuterLocStart, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 4, getQualifier, (clang::NestedNameSpecifier *))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 5, getQualifierLoc, (clang::NestedNameSpecifierLoc))
    PASTA_OVERRIDE_METHOD_0(DeclaratorDecl, 1786001652, 6, getSourceRange, (clang::SourceRange))
    PASTA_INSTANCE_METHOD_1(DeclaratorDecl, 1786001652, 7, getTemplateParameterList, (clang::TemplateParameterList *), (unsigned int))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 8, getTrailingRequiresClause, (const clang::Expr *))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 9, getTypeSourceInfo, (clang::TypeSourceInfo *))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 10, getTypeSpecEndLoc, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(DeclaratorDecl, 1786001652, 11, getTypeSpecStartLoc, (clang::SourceLocation))
  PASTA_END_METHODS(DeclaratorDecl, 1786001652)
  PASTA_BEGIN_FIELDS(DeclaratorDecl, 1786001652)
    PASTA_PRIVATE_INSTANCE_FIELD(DeclaratorDecl, 1786001652, DeclInfo, (llvm::PointerUnion<clang::TypeSourceInfo *, clang::DeclaratorDecl::ExtInfo *>))
    PASTA_PRIVATE_INSTANCE_FIELD(DeclaratorDecl, 1786001652, InnerLocStart, (clang::SourceLocation))
  PASTA_END_FIELDS(DeclaratorDecl, 1786001652)
  PASTA_BEGIN_CLASS_ENUMS(DeclaratorDecl, 1786001652)
  PASTA_END_CLASS_ENUMS(DeclaratorDecl, 1786001652)
PASTA_END_CLANG_WRAPPER(DeclaratorDecl, 1786001652)
```