/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

// Declare PASTA versions of every clang enumeration type from our macro file.
void DeclareEnums(std::ostream &os) {
  llvm::StringRef enumerator_name;

#define PASTA_BEGIN_NAMED_ENUM(enum_name, underlying_type) \
    os << "enum class " << Capitalize(PASTA_STR(enum_name)) \
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
        !enumerator_name.startswith("last")) { \
      os << "  k" << Capitalize(enumerator_name) << " = " \
         << PASTA_STR(PASTA_SPLAT val) << ",\n"; \
    }

#define PASTA_END_NAMED_ENUM(enum_name) \
    os << "};\n\n";

#include "Generated.h"
}
