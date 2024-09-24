/*
 * Copyright (c) 2022, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <clang/Basic/Specifiers.h>
#pragma clang diagnostic pop

namespace pasta {

inline static bool IsExplicitInstantiation(
    clang::TemplateSpecializationKind tsk,
    bool has_spec_or_partial) {

  if (tsk == clang::TSK_ExplicitSpecialization) {
    return true;
  }

  // NOTE(pag): I have observed cases where a `ClassTemplateSpecializationDecl`
  //            will report an undeclared specialization kind (lol), but have
  //            a non-null value returned by `getSpecializedTemplateOrPartial`,
  //            hence the additional condition.
  if (tsk == clang::TSK_Undeclared) {
    return !has_spec_or_partial;
  }

  return false;
}

}  // namespace pasta
