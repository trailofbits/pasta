add_executable(print-token-graph
    "Main.cpp"
)

target_link_libraries(print-token-graph PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_compiler
)