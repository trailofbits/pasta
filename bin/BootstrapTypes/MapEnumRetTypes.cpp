/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

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
                          Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#define PASTA_DECLARE_CLASS_NAMED_ENUM(class_name, class_id, enum_name, underlying_type) \
    do { \
      std::string rv("  return static_cast<::pasta::"); \
      rv += Capitalize(PASTA_STR(enum_name)); \
      rv += ">(static_cast<" PASTA_STR(PASTA_SPLAT underlying_type) ">(val));\n"; \
      gRetTypeToValMap.emplace( \
          "(clang::" PASTA_STR(class_name) "::" PASTA_STR(enum_name) ")", rv); \
      gRetTypeMap.emplace("(clang::" PASTA_STR(enum_name) ")", \
                          Capitalize(PASTA_STR(enum_name))); \
    } while (0);

#include "Generated.h"
}
