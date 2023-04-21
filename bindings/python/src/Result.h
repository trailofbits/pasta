#pragma once

#include <pasta/Util/Result.h>

#include <pybind11/detail/common.h>
#include <pybind11/pybind11.h>

namespace PYBIND11_NAMESPACE {
namespace detail {
template <typename ValueType, typename ErrorType>
struct type_caster<pasta::Result<ValueType, ErrorType>> {
    using value_conv = make_caster<ValueType>;
    using error_conv = make_caster<ErrorType>;

    bool load(handle src, bool convert) {
        value_conv value_caster;
        error_conv error_caster;
        if (value_caster.load(src, convert)) {
            value = cast_op<ValueType>(std::move(value_caster));
            return true;
        } else if(error_caster.load(src, convert)) {
            value = cast_op<ErrorType>(std::move(value_caster));
            return true;
        }
        return false;
    }

    static handle cast(pasta::Result<ValueType, ErrorType>&& src, return_value_policy policy, handle parent) {
        if(src.Succeeded()) {
            return value_conv::cast(src.TakeValue(), policy, parent);
        } else {
            return error_conv::cast(src.TakeError(), policy, parent);
        }
    }

    PYBIND11_TYPE_CASTER(type, const_name("Union[") + detail::concat(value_conv::name, error_conv::name) + const_name("]"));
};
}
}