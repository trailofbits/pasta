#
# Copyright (c) 2021, Trail of Bits, Inc.
# 
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable(print-token-graph
    "Main.cpp"
)

target_link_libraries(print-token-graph PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)