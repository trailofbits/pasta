/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

// Adds mappings that translate between pointers to clang Decl types and PASTA
// Decl types.
void MapDeclRetTypes(void) {
  for (const auto &name : gDeclNames) {
    std::stringstream ss;
    ss << "(clang::" << name << " *)";
    gRetTypeMap.emplace(ss.str(), "::pasta::" + name);

    std::stringstream rvs;
    rvs
        << "  if (val) {\n"
        << "    return DeclBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss.str()] = rvs.str();

    std::stringstream ss2;
    ss2 << "(const clang::" << name << " *)";

    gRetTypeMap.emplace(ss2.str(), "::pasta::" + name);
    gRetTypeToValMap[ss2.str()] = rvs.str();
  }
}

// Adds mappings that translate between pointers to clang Stmt types and PASTA
// Stmt types.
void MapStmtRetTypes(void) {
  for (const auto &name : gStmtNames) {
    std::stringstream ss;
    ss << "(clang::" << name << " *)";
    gRetTypeMap.emplace(ss.str(), "::pasta::" + name);

    std::stringstream rvs;
    rvs
        << "  if (val) {\n"
        << "    return StmtBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss.str()] = rvs.str();

    std::stringstream ss2;
    ss2 << "(const clang::" << name << " *)";

    gRetTypeMap.emplace(ss2.str(), "::pasta::" + name);
    gRetTypeToValMap[ss2.str()] = rvs.str();
  }
}


// Adds mappings that translate between pointers to clang Type types and PASTA
// Type types.
void MapTypeRetTypes(void) {
  for (const auto &name : gTypeNames) {
    std::stringstream ss;
    ss << "(clang::" << name << " *)";
    gRetTypeMap.emplace(ss.str(), "::pasta::" + name);

    std::stringstream rvs;
    rvs
        << "  if (val) {\n"
        << "    return TypeBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss.str()] = rvs.str();

    std::stringstream ss2;
    ss2 << "(const clang::" << name << " *)";

    gRetTypeMap.emplace(ss2.str(), "::pasta::" + name);

    std::stringstream crvs;
    crvs
        << "  if (val) {\n"
        << "    return TypeBuilder::Create<::pasta::" << name << ">(ast, val);\n"
        << "  }\n";
    gRetTypeToValMap[ss2.str()] = crvs.str();
  }
}

// Adds mappings that translate between clang enumeration types and PASTA
// enumeration types.
void MapEnumRetTypes(void) {

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    do { \
      std::string rv("  return static_cast<::pasta::"); \
      rv += Capitalize(PASTA_STR(enum_name)); \
      rv += ">(static_cast<" PASTA_STR(PASTA_SPLAT underlying_type) ">(val));\n"; \
      gRetTypeToValMap.emplace("(clang::" PASTA_STR(enum_name) ")", rv); \
      gRetTypeMap.emplace("(clang::" PASTA_STR(enum_name) ")", \
                          "enum " + Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#define PASTA_DECLARE_CLASS_NAMED_ENUM(class_name, class_id, enum_name, underlying_type) \
    do { \
      std::string rv("  return static_cast<::pasta::"); \
      rv += Capitalize(PASTA_STR(enum_name)); \
      rv += ">(static_cast<" PASTA_STR(PASTA_SPLAT underlying_type) ">(val));\n"; \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", rv); \
      gRetTypeMap.emplace("(clang::" PASTA_STR(enum_name) ")", \
                          "enum " + Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#include "Generated.h"
}
