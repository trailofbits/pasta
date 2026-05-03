/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#include "Globals.h"

std::unordered_map<std::string, std::vector<std::string>> gEnumerators;

// Maps class names to counter/nth getter methods.
std::unordered_map<std::string, std::vector<IteratorSpec>> gIterators;

const std::vector<llvm::StringRef> kAllClassNames{
  "OMPDeclarativeDirectiveDecl",
  "OMPDeclarativeDirectiveValueDecl",
  "ExceptionSpecification",
#define PASTA_BEGIN_CLANG_WRAPPER(name, id) PASTA_STR(name) ,
#include "Generated.h"
};

const std::vector<ClassExtends> kExtends{
#define PASTA_PUBLIC_BASE_CLASS(name, id, base_name, base_id) \
    {PASTA_STR(name), PASTA_STR(base_name)},
#include "Generated.h"
};

// `OMPDeclarativeDirectiveDecl` and `OMPDeclarativeDirectiveValueDecl` are
// intermediate template classes synthesized in
// `bin/BootstrapMacros/MacroGenerator.cpp`; their parent/child edges aren't
// emitted into `Generated.h` and have to be patched in here.
const std::vector<ClassExtends> kAdditionalExtends{
  {"OMPDeclarativeDirectiveDecl", "Decl"},
  {"OMPDeclarativeDirectiveValueDecl", "ValueDecl"},
  {"OMPThreadPrivateDecl", "OMPDeclarativeDirectiveDecl"},
  {"OMPAllocateDecl", "OMPDeclarativeDirectiveDecl"},
  {"OMPDeclareMapperDecl", "OMPDeclarativeDirectiveValueDecl"},
  {"OMPRequiresDecl", "OMPDeclarativeDirectiveDecl"},
};

// Names that the automatic base-chain categorization must skip. Today these
// fall into three groups:
//
// - PASTA-only helper types referenced by manual override files but not
//   wrapped as a Clang AST node (`ExceptionSpecification`).
// - Clang AST classes with no public base in `kExtends` (their base is
//   skipped because it's non-public or non-AST), so the base-chain walk has
//   nowhere to go; they're exposed by PASTA in dedicated places (`Common`,
//   `DeclContext`, `FunctionTemplateSpecializationInfo`, `TemplateArgument`,
//   `TypeSourceInfo`).
// - Classes whose category is correct but whose position in the per-category
//   vector is controlled elsewhere; auto-categorizing would reshuffle the
//   topo-ordered output and break bootstrap-determinism (`TypeWithKeyword`,
//   pushed explicitly by `Main.cpp` after categorization).
const std::set<std::string> kCategorizationOptOut{
  "ExceptionSpecification",
  "TypeWithKeyword",
  "Common",
  "DeclContext",
  "FunctionTemplateSpecializationInfo",
  "TemplateArgument",
  "TypeSourceInfo",
};

Category ResolveCategory(const std::string &name) {
  if (kCategorizationOptOut.count(name)) {
    return Category::None;
  }
  std::vector<std::string> stack{name};
  std::set<std::string> visited;
  while (!stack.empty()) {
    auto cur = std::move(stack.back());
    stack.pop_back();
    if (!visited.insert(cur).second) {
      continue;
    }
    if (cur == "Decl") return Category::Decl;
    if (cur == "Stmt") return Category::Stmt;
    if (cur == "Type") return Category::Type;
    if (cur == "Attr") return Category::Attr;
    auto it = gBaseClasses.find(cur);
    if (it != gBaseClasses.end()) {
      for (const auto &base : it->second) {
        stack.push_back(base);
      }
    }
  }
  return Category::None;
}

std::vector<std::string> gDeclNames;
std::vector<std::string> gStmtNames;
std::vector<std::string> gTypeNames;
std::vector<std::string> gAttrNames;

// All methods (class name, method name).
const std::set<std::pair<std::string, std::string>> gMethodNames{
#define PASTA_INSTANCE_METHOD_0(cls, id, meth_id, meth, rt) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_1(cls, id, meth_id, meth, rt, p0) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_2(cls, id, meth_id, meth, rt, p0, p1) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_3(cls, id, meth_id, meth, rt, p0, p1, p2) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_4(cls, id, meth_id, meth, rt, p0, p1, p2, p3) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_5(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4) {#cls, #meth},
#define PASTA_INSTANCE_METHOD_6(cls, id, meth_id, meth, rt, p0, p1, p2, p3, p4, p5) {#cls, #meth},
#include "Generated.h"
};

std::unordered_map<std::string, uint32_t> gClassIDs;
std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
std::vector<std::string> gTopologicallyOrderedDecls;
std::vector<std::string> gTopologicallyOrderedStmts;
std::vector<std::string> gTopologicallyOrderedTypes;
std::vector<std::string> gTopologicallyOrderedAttrs;

std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;

#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
  const std::string kClassName_ ## id(PASTA_STR(cls));

#include "Generated.h"
