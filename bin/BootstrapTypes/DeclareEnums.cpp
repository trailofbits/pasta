/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef enumerator_name;

static std::string RenameEnum(llvm::StringRef name) {
  if (name == "StmtClass") {
    return "StmtKind";
  } else if (name == "TypeClass") {
    return "TypeKind";
  } else {
    return Capitalize(name);
  }
}

static bool AcceptEnumerator(const std::string &name) {
  return !enumerator_name.empty() &&
         !enumerator_name.startswith("first") &&
         !enumerator_name.startswith("last") &&
         !enumerator_name.startswith("First") &&
         !enumerator_name.startswith("Last") &&
         !enumerator_name.endswith("Last") &&
         enumerator_name != "NoStmtClass";
}

static std::string RenameEnumerator(const std::string &name) {
  if (name == "StmtKind" && enumerator_name.endswith("Class")) {
    return Capitalize(enumerator_name.substr(
        0, enumerator_name.size() - 5));
  }
  return Capitalize(enumerator_name);
}

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    static void DeclareEnum_ ## enum_name(std::ostream &os) { \
      auto enum_name_str = RenameEnum(PASTA_STR(enum_name)); \
      auto &enumerators = gEnumerators[enum_name_str]; \
      os << "enum class " << enum_name_str \
         << " : " << PASTA_STR(PASTA_SPLAT underlying_type) << " {\n";

#define PASTA_NAMED_ENUMERATOR(enumerator_name_, underlying_type, val) \
      enumerator_name = #enumerator_name_; \
      for (auto prefix : kEnumPrefixesToStrip) { \
        if (enumerator_name.startswith(prefix)) { \
          enumerator_name = enumerator_name.substr(prefix.size()); \
          break; \
        } \
      } \
      if (AcceptEnumerator(enum_name_str)) { \
        auto enumerator_str = RenameEnumerator(enum_name_str); \
        os << "  k" << enumerator_str << " = " \
           << PASTA_STR(PASTA_SPLAT val) << ",\n"; \
        enumerators.emplace_back(std::move(enumerator_str)); \
      }

#define PASTA_END_NAMED_ENUM(enum_name) \
      os << "};\n\n"; \
    }

#include "Generated.h"

}  // namespace

// Declare PASTA versions of every clang enumeration type from our macro file.
void DeclareEnums(std::ostream &os) {

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    DeclareEnum_ ## enum_name(os);

#include "Generated.h"
}
