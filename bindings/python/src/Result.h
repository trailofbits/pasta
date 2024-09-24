/*
 * Copyright (c) 2023, Trail of Bits, Inc.
 *
 * This source code is licensed in accordance with the terms specified in
 * the LICENSE file found in the root directory of this source tree.
 */

#pragma once

#include <nanobind/nanobind.h>
#include <pasta/Util/Result.h>

NAMESPACE_BEGIN(NB_NAMESPACE)
NAMESPACE_BEGIN(detail)

template <typename ValueType, typename ErrorType>
struct type_caster<pasta::Result<ValueType, ErrorType>> {
  using Value = pasta::Result<ValueType, ErrorType>;
  using Valuei = detail::intrinsic_t<ValueType>;
  using Errori = detail::intrinsic_t<ErrorType>;
  using ValueCaster = make_caster<Valuei>;
  using ErrorCaster = make_caster<Errori>;

  static constexpr auto Name = const_name("Union[") +
                               concat(ValueCaster::Name, ErrorCaster::Name) +
                               const_name("]");
  static constexpr bool IsClass = false;

  template <typename T_>
  using Cast = movable_cast_t<T_>;

  Value value;

  bool from_python(handle src, uint8_t flags, cleanup_list *cleanup) noexcept {
    if (src.is_none()) {
      return true;
    }

    ValueCaster vcaster;
    ErrorCaster ecaster;
    if (vcaster.from_python(src, flags, cleanup)) {
      if constexpr (is_pointer_v<ValueType>) {
        static_assert(
            ValueCaster::IsClass,
            "Binding 'Result<T*, ...>' requires that 'T' can also be bound by nanobind.");
        value = vcaster.operator cast_t<ValueType>();
      } else if constexpr (ValueCaster::IsClass) {
        value = vcaster.operator cast_t<ValueType &>();
      } else {
        value = std::move(vcaster).operator cast_t<ValueType &&>();
      }
      return true;
    }

    if (ecaster.from_python(src, flags, cleanup)) {
      if constexpr (is_pointer_v<ErrorType>) {
        static_assert(
            ErrorCaster::IsClass,
            "Binding 'Result<..., T*>' requires that 'T' can also be bound by nanobind.");
        value = ecaster.operator cast_t<ErrorType>();
      } else if constexpr (ValueCaster::IsClass) {
        value = ecaster.operator cast_t<ErrorType &>();
      } else {
        value = std::move(ecaster).operator cast_t<ErrorType &&>();
      }
      return true;
    }

    return false;
  }

  static handle from_cpp(pasta::Result<ValueType, ErrorType> *value,
                         rv_policy policy, cleanup_list *cleanup) noexcept {
    if (!value) {
      return none().release();
    }
    return from_cpp(*value, policy, cleanup);
  }

  static handle from_cpp(pasta::Result<ValueType, ErrorType> &&value,
                         rv_policy policy, cleanup_list *cleanup) noexcept {
    if (value.Succeeded()) {
      return ValueCaster::from_cpp(value.TakeValue(), policy, cleanup);
    } else {
      return ErrorCaster::from_cpp(value.TakeError(), policy, cleanup);
    }
  }

  explicit operator Value *() {
    return &value;
  }
  explicit operator Value &() {
    return value;
  }
  explicit operator Value &&() && {
    return (Value &&) value;
  }
};

NAMESPACE_END(detail)
NAMESPACE_END(NB_NAMESPACE)