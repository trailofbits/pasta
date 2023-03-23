/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <string>
#include <unordered_set>

// When bootstrapping, prefix `__VA_ARGS__` with a specific Clang installation,
// e.g. `/Users/pag/Install/llvm-16/Release/include/__VA_ARGS__`.
#define TARGET_CLANG_HEADER_STR(...) #__VA_ARGS__
#define TARGET_CLANG_HEADER(...) \
  TARGET_CLANG_HEADER_STR(/Users/pag/Install/llvm-16/Release/include/__VA_ARGS__)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/ADT/StringRef.h>
#pragma clang diagnostic pop

std::string Capitalize(llvm::StringRef name);

std::string CxxName(llvm::StringRef name);

extern const std::unordered_set<std::string> kConcreteDecls;
extern const std::unordered_set<std::string> kConcreteStmts;
extern const std::unordered_set<std::string> kConcreteTypes;
extern const std::unordered_set<std::string> kConcreteAttrs;

bool IsConcreteDecl(const std::string &decl);
bool IsConcreteType(const std::string &type);
bool IsConcreteAttr(const std::string &attr);

enum class StmtClassification {
  kStmt,
  kDirective,
  kExpr,
  kOperator,
  kLiteral,
  kAbstract,
};

StmtClassification ClassifyStmt(const std::string &stmt);
