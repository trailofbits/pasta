/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include "Util.h"
#include "Globals.h"

std::string Capitalize(llvm::StringRef name) {
  return name.substr(0, 1).upper() + name.substr(1).str();
}

std::string CxxName(llvm::StringRef name) {

  // Disable these.
  if (name == "asOpaquePtr" ||
      name.endswith("_back") ||
      name.endswith("_front") ||
      name.endswith("_begin") ||
      name.endswith("_end") ||
      name.endswith("_rbegin") ||
      name.endswith("_rend") ||
      name.startswith("begin") ||
      name.startswith("end") ||
      name.startswith("rbegin") ||
      name.startswith("rend")) {
    return "";

  } else if (name.startswith("get")) {
    return CxxName(name.substr(3));

  } else if (name.startswith("has")) {
    return "Has" + CxxName(name.substr(3));

  } else if (name.startswith("is")) {
    return "Is" + CxxName(name.substr(2));

  // Begin/end iterators.
  } else if (name.endswith("_begin") || name.endswith("_end") ||
             name.endswith("_size") || name.endswith("_empty") ||
             name.endswith("_rbegin") || name.endswith("_rend") ||
             name.startswith("begin_") || name.startswith("end_") ||
             name.startswith("rbegin_") || name.startswith("rend_")) {
    return "";

  // Setters, ignore them.
  } else if (name.startswith("set")) {
    return "";

  } else if (name.endswith("Loc")) {
    return CxxName(name.substr(0, name.size() - 3).str()) + "Token";

  } else if (auto name_it = kCxxMethodRenames.find(name.str());
             name_it != kCxxMethodRenames.end()) {
    return name_it->second;

  } else if (name.empty()) {
    return "";

  } else if (std::islower(name.front())) {
    return CxxName(Capitalize(name));

  // Recursively apply on all capitalized sub-components.
  } else {
    auto num_upper = 1u;
    for (auto i = 1u; i < name.size(); ++i) {
      if (name[i] == '_') {
        ++num_upper;
      } else if (std::isupper(name[i]) && !std::isupper(name[i - 1u])) {
        ++num_upper;
      }
    }

    if (2u <= num_upper) {
      std::stringstream name_ss;
      std::stringstream ss;
      ss << name[0];
      for (auto i = 1u; i < name.size(); ++i) {
        if (std::isupper(name[i])) {
          if (auto sub_name = ss.str(); 1u < sub_name.size()) {
            name_ss << CxxName(sub_name);
            std::stringstream().swap(ss);
          }
        } else if (name[i] == '_') {
          name_ss << CxxName(ss.str());
          std::stringstream().swap(ss);
        }

        if (name[i] != '_') {
          ss << name[i];
        }
      }
      name_ss << CxxName(ss.str());

      return name_ss.str();

    } else {
      if (1u < name.size() && name.endswith("s")) {
        return CxxName(name.substr(0u, name.size() - 1u)) + "s";
      } else {
        return name.str();
      }
    }
  }
}
