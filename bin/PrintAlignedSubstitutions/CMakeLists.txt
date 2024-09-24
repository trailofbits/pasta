#
# Copyright (c) 2023, Trail of Bits, Inc.
# 
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable(print-aligned-substitutions
    "Main.cpp"
)

target_link_libraries(print-aligned-substitutions
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)
