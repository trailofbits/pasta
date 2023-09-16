find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)
if(DEFINED nanobind_DIR)
    message(NOTICE "nanobind_DIR is defined, using it instead of invoking module")
else()
    execute_process(
        COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
        OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR
        COMMAND_ERROR_IS_FATAL ANY)
    list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
endif()
find_package(nanobind CONFIG REQUIRED)

add_subdirectory(src/AST)

nanobind_add_module(pypasta LTO
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AST/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/ArgumentVector.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Bindings.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Bindings.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileCommand.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/CompileJob.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Compiler.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/FileSystem.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Macro.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Module.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Token.cpp"
    ${PASTA_PYTHON_AST_SOURCES})
target_link_libraries(pypasta PUBLIC pasta_force_load)