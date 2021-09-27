/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

namespace {

static llvm::StringRef enumerator_name;

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    static void DeclareEnum_ ## enum_name(std::ostream &os) { \
      auto enum_name_str = Capitalize(PASTA_STR(enum_name)); \
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
      if (!enumerator_name.empty() && \
          !enumerator_name.startswith("first") && \
          !enumerator_name.startswith("last") && \
          !enumerator_name.startswith("First") && \
          !enumerator_name.startswith("Last") && \
          !enumerator_name.endswith("Last")) { \
        auto enumerator_str = Capitalize(enumerator_name); \
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
