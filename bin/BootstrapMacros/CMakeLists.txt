#
# Copyright (c) 2020, Trail of Bits, Inc.
# 
# This source code is licensed in accordance with the terms specified in
# the LICENSE file found in the root directory of this source tree.
#

add_executable(bootstrap-macros
    "MacroGenerator.h"
    "MacroGenerator.cpp"
    "Main.cpp"
)

target_link_libraries(bootstrap-macros PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
    pasta_bootstrap_config
)
