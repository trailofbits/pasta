/*
 * Copyright (c) 2021, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wbitfield-enum-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <llvm/ADT/StringRef.h>
#pragma clang diagnostic pop

#include <pasta/Util/Compiler.h>

struct ClassExtends {
  std::string derived;
  std::string base;
};

extern const std::vector<llvm::StringRef> kAllClassNames;
extern const std::vector<ClassExtends> kExtends;

// Additional (derived, base) edges contributed manually rather than via
// `Generated.h`. Used to wire intermediate template classes defined in
// `bin/BootstrapMacros/MacroGenerator.cpp` into the inheritance graph.
extern const std::vector<ClassExtends> kAdditionalExtends;

enum class Category { None, Decl, Stmt, Type, Attr };

// Names from `kAllClassNames` that intentionally don't belong to any wrapper
// category (e.g. helper classes referenced only by manual overrides). Resolving
// to `Category::None` is fatal unless the name is in this set.
extern const std::set<std::string> kCategorizationOptOut;

// Walks the inheritance graph (`gBaseClasses`) up from `name` and returns the
// first root category reached. Returns `Category::None` if no root is reached.
// Must be called after `gBaseClasses` has been populated from `kExtends` +
// `kAdditionalExtends`.
Category ResolveCategory(const std::string &name);

extern std::vector<std::string> gDeclNames;
extern std::vector<std::string> gStmtNames;
extern std::vector<std::string> gTypeNames;
extern std::vector<std::string> gAttrNames;

struct IteratorSpec {
  std::string getter_method;
  std::string list_method;
  std::string counter_method;
  std::string cxx_method;
  std::string elem_type;
};

// Maps class names to counter/nth getter methods.
extern std::unordered_map<std::string, std::vector<IteratorSpec>> gIterators;

extern const std::unordered_map<std::string, std::string> kCxxMethodRenames;

// Exact-name overrides applied before `CxxNameImpl` runs.
extern const std::unordered_map<std::string, std::string> kPreRenameOverrides;

// Names that `CxxNameImpl` disables before stripping `get`/`has`/`is`
// prefixes. Match is `==`, `ends_with`, or `starts_with` depending on the
// table.
extern const std::unordered_set<std::string> kPreStripDisableExact;
extern const std::vector<std::string> kPreStripDisableEndsWith;
extern const std::vector<std::string> kPreStripDisableStartsWith;

// Additional disables checked AFTER the `get`/`has`/`is` prefix-strip
// recursion. These can yield different outputs than the pre-strip table for
// names like `getFoo_size` whose disable pattern only appears once the prefix
// is stripped.
extern const std::vector<std::string> kPostStripDisableEndsWith;
extern const std::vector<std::string> kPostStripDisableStartsWith;

// Suffix transforms: when the name ends with `suffix`, the wrapper name is
// (recursively renamed prefix) + `replacement`. `require_non_empty_prefix`
// matches the historical guard preserving e.g. `SourceRange` itself from
// transforming.
struct SuffixTransform {
  std::string suffix;
  std::string replacement;
  bool require_non_empty_prefix;
};
extern const std::vector<SuffixTransform> kSuffixTransforms;

// Exact-name overrides applied to `CxxNameImpl`'s output (post-rename).
extern const std::unordered_map<std::string, std::string> kPostRenameOverrides;

// Maps return types from the macros file to their replacements in the
// output code.
extern std::unordered_map<std::string, std::string> gRetTypeMap;

// Maps return types from the macros file to how they should be returned
// in the generated Decl.cpp file.
extern std::unordered_map<std::string, std::string> gRetTypeToValMap;

// All methods (class name, method name).
extern const std::set<std::pair<std::string, std::string>> gMethodNames;

// Prefixes on enumerators to strip.
extern std::vector<llvm::StringRef> kEnumPrefixesToStrip;

// Set of ClassName::MethodName pairs such that the class can return a nullptr,
// and thus `std::optional` probably needs to be used.
extern std::set<std::pair<std::string, std::string>> kCanReturnNullptr;
extern std::map<std::pair<std::string, std::string>, std::string> kConditionalNullptr;

extern std::unordered_map<std::string, uint32_t> gClassIDs;
extern std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
extern std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
extern std::vector<std::string> gTopologicallyOrderedDecls;
extern std::vector<std::string> gTopologicallyOrderedStmts;
extern std::vector<std::string> gTopologicallyOrderedTypes;
extern std::vector<std::string> gTopologicallyOrderedAttrs;

extern std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
extern std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;

extern std::unordered_map<std::string, std::vector<std::string>> gEnumerators;

#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
  extern const std::string kClassName_ ## id;

#include "Generated.h"
