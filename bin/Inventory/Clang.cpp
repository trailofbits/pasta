/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-int-conversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wshorten-64-to-32"
#include <clang/AST/Attr.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/DeclFriend.h>
#include <clang/AST/DeclObjC.h>
#include <clang/AST/DeclOpenMP.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/ExprConcepts.h>
#include <clang/AST/ExprObjC.h>
#include <clang/AST/ExprOpenMP.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtCXX.h>
#include <clang/AST/StmtObjC.h>
#include <clang/AST/StmtOpenMP.h>
#include <clang/AST/Type.h>
#include <clang/Basic/TokenKinds.h>
#include <llvm/TargetParser/Triple.h>
#pragma GCC diagnostic pop

// NOTE(pag): This is a bit of a hack to get our lifter to "find" `Triple` in
//            the top-level `clang` namespace.
namespace to_lift {

#define COUNTED_(counter) x ## counter
#define COUNTED(counter) COUNTED_(counter)
#define FRESH_SYMBOL COUNTED(__COUNTER__)
#define USE(name) using FRESH_SYMBOL = name

USE(llvm::Triple);
USE(clang::Decl);
USE(clang::Stmt);
USE(clang::Type);
USE(clang::Attr);

// When bootstrapping, prefix `__VA_ARGS__` with a specific Clang installation,
// e.g. `/Users/pag/Install/llvm-16/Release/include/__VA_ARGS__`.
#define TARGET_CLANG_HEADER_STR(...) #__VA_ARGS__
#define TARGET_CLANG_HEADER(...) \
  TARGET_CLANG_HEADER_STR(__VA_ARGS__)

#define TYPE(Class, Base) USE(clang::Class ## Type);
#include TARGET_CLANG_HEADER(clang/AST/TypeNodes.inc)
#undef TYPE

#define DECL(Type, Base) USE(clang::Type ## Decl);
#include TARGET_CLANG_HEADER(clang/AST/DeclNodes.inc)
#undef DECL

// #define STMT(Type, Base) using FRESH_SYMBOL = Type ## Decl;
//     acceptable_class_names.insert(#Base); \
//     acceptable_class_names.insert(#Type); \
//     acceptable_class_names.insert(#Type "Expr"); \
//     acceptable_class_names.insert(#Type "Stmt"); \
//     acceptable_class_names.insert(#Type "Directive");
// #include TARGET_CLANG_HEADER(clang/AST/StmtNodes.inc)
// #undef STMT

#define ATTR(Type) USE(clang::Type ## Attr);
#include TARGET_CLANG_HEADER(clang/Basic/AttrList.inc)
#undef ATTR

}  // namespace clang