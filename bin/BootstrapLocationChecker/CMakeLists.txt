# Copyright (c) 2022 Trail of Bits, Inc., all rights reserved.

add_executable(bootstrap-location-checker
    "Main.cpp"
)

target_link_libraries(bootstrap-location-checker PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
    pasta_bootstrap_config
)
