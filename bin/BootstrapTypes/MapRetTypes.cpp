/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#include "Globals.h"
#include "Util.h"

namespace {

struct CategoryRetType {
  const std::vector<std::string> *names;
  const char *builder_class;
  // Today's MapTypeRetTypes / MapAttrRetTypes write a separate (textually
  // identical) snippet for the const-pointer variant; MapDeclRetTypes /
  // MapStmtRetTypes reuse the same snippet. We preserve that distinction here
  // to keep gRetTypeToValMap byte-identical to pre-refactor output.
  bool separate_const_variant;
};

const CategoryRetType kCategoryRetTypes[] = {
  {&gDeclNames, "DeclBuilder", false},
  {&gStmtNames, "StmtBuilder", false},
  {&gTypeNames, "TypeBuilder", true},
  {&gAttrNames, "AttrBuilder", true},
};

std::string BuilderSnippet(const char *builder_class, const std::string &name) {
  std::stringstream ss;
  ss << "  if (val) {\n"
     << "    return " << builder_class << "::Create<::pasta::" << name
     << ">(ast, val);\n"
     << "  }\n";
  return ss.str();
}

}  // namespace

// Adds mappings that translate between pointers to clang AST types and PASTA
// wrapper types, for every wrapper category.
void MapAllRetTypes(void) {
  for (const auto &cat : kCategoryRetTypes) {
    for (const auto &name : *cat.names) {
      std::stringstream key;
      key << "(clang::" << name << " *)";
      auto rvs = BuilderSnippet(cat.builder_class, name);
      gRetTypeMap.emplace(key.str(), "::pasta::" + name);
      gRetTypeToValMap[key.str()] = rvs;

      std::stringstream const_key;
      const_key << "(const clang::" << name << " *)";
      gRetTypeMap.emplace(const_key.str(), "::pasta::" + name);
      // For Decl/Stmt the original code reused `rvs` for the const variant;
      // for Type/Attr it built a fresh stringstream that produced a textually
      // identical snippet. Preserve that behaviour explicitly so any future
      // semantic change is visible.
      gRetTypeToValMap[const_key.str()] =
          cat.separate_const_variant
              ? BuilderSnippet(cat.builder_class, name)
              : rvs;
    }
  }
}
