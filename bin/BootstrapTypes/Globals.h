/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#pragma once

#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <llvm/ADT/StringRef.h>

#include <pasta/Util/Compiler.h>

struct ClassExtends {
  std::string derived;
  std::string base;
};

extern const std::vector<llvm::StringRef> kAllClassNames;
extern const std::vector<ClassExtends> kExtends;

extern std::vector<std::string> gDeclNames;
extern std::vector<std::string> gTypeNames;

extern const std::unordered_map<std::string, std::string> kCxxMethodRenames;

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

extern std::unordered_map<std::string, uint32_t> gClassIDs;
extern std::unordered_map<std::string, std::set<std::string>> gBaseClasses;
extern std::unordered_map<std::string, std::set<std::string>> gDerivedClasses;
extern std::vector<std::string> gTopologicallyOrderedDecls;
extern std::vector<std::string> gTopologicallyOrderedTypes;

extern std::unordered_map<std::string, std::set<std::string>> gTransitiveBaseClasses;
extern std::unordered_map<std::string, std::set<std::string>> gTransitiveDerivedClasses;

extern std::unordered_map<std::string, std::vector<std::string>> gEnumerators;

#define PASTA_BEGIN_CLANG_WRAPPER(cls, id) \
  extern const std::string kClassName_ ## id;

#include "Generated.h"
