/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// Derived from looking at AppleClang in IDA Pro.
TARGET_BUILTIN(__builtin_altivec_vec_replace_elt, "V4UiV4UiUiIi", "~t", "")
TARGET_BUILTIN(__builtin_altivec_vec_replace_unaligned, "V4UiV4UiUiIi", "~t", "")

#undef TARGET_BUILTIN
