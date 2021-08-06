/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <ostream>
#include <string>

#include "Globals.h"
#include "Util.h"

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
