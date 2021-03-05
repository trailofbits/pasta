/*
 * Copyright (c) 2019 Trail of Bits, Inc.
 */

#pragma once

#include <type_traits>

namespace pasta {
namespace detail {

// This is an implementation of the non-UB technique to access private
// object/class members which takes advantage of the fact that explicit
// instantiations ignore access control checks of the provided template
// arguments.
//
// See:
// https://bloglitb.blogspot.com/2010/07/access-to-private-members-thats-easy.html

template <typename T, auto tag>
inline T member_pointer_stash = nullptr;

template <auto ptr, typename T, auto tag>
inline const int steal_member_pointer = [] {
  static_assert(std::is_same_v<decltype(ptr), T>);
  member_pointer_stash<decltype(ptr), tag> = ptr;
  return 0;
}();

#define PASTA_BYPASS_MEMBER_OBJECT_ACCESS(ns, cls, member, type) \
  constexpr int __temp_tag_##ns##_##cls##_##member = 0; \
  using __temp_type_##ns##_##cls##_##member = type ns::cls::*; \
  template const int steal_member_pointer<&ns::cls::member, \
                                    __temp_type_##ns##_##cls##_##member, \
                                    &__temp_tag_##ns##_##cls##_##member>

#define PASTA_BYPASS_MEMBER_FUNCTION_ACCESS(ns, cls, member, ret_type, ...) \
  constexpr int __temp_tag_##ns##_##cls##_##member = 0; \
  using __temp_type_##ns##_##cls##_##member = \
      ret_type (ns::cls::*)(__VA_ARGS__); \
  template const int steal_member_pointer<&ns::cls::member, \
                                    __temp_type_##ns##_##cls##_##member, \
                                    &__temp_tag_##ns##_##cls##_##member>

#define PASTA_BYPASS_CONST_MEMBER_FUNCTION_ACCESS(ns, cls, member, ret_type, ...) \
  constexpr int __temp_tag_##ns##_##cls##_##member = 0; \
  using __temp_type_##ns##_##cls##_##member = \
      ret_type (ns::cls::*)(__VA_ARGS__) const; \
  template const int steal_member_pointer<&ns::cls::member, \
                                    __temp_type_##ns##_##cls##_##member, \
                                    &__temp_tag_##ns##_##cls##_##member>

#define PASTA_ACCESS_MEMBER(ns, cls, member) \
    (::pasta::detail::member_pointer_stash< \
        ::pasta::detail::__temp_type_##ns##_##cls##_##member, \
        &::pasta::detail::__temp_tag_##ns##_##cls##_##member>)

}  // namespace detail
}  // namespace mu


#define PASTA_LIKELY(x) __builtin_expect(!!(x), 1)
#define PASTA_UNLIKELY(x) __builtin_expect(!!(x), 0)

#define ___PASTA_CAT(a, b) a ## b
#define __PASTA_CAT(a, b) ___PASTA_CAT(a, b)
#define _PASTA_CAT(a, b) __PASTA_CAT(a, b)
#define PASTA_CAT(a, b) _PASTA_CAT(a, b)

#define ___PASTA_STR(a) #a
#define __PASTA_STR(a) ___PASTA_STR(a)
#define _PASTA_STR(a) __PASTA_STR(a)
#define PASTA_STR(a) _PASTA_STR(a)

#define PASTA_SPLAT(...) __VA_ARGS__
