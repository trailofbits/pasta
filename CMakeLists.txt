# Copyright (c) 2020 Trail of Bits, Inc., all rights reserved.

cmake_minimum_required(VERSION 3.21)

project(pasta LANGUAGES C CXX)

include(GNUInstallDirs)
include("cmake/options.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/settings.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/utils.cmake")
include("${PROJECT_SOURCE_DIR}/cmake/ccache.cmake")
list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

# --------------------------------------------
# build-time options -------------------------
# --------------------------------------------

if(PASTA_ENABLE_INSTALL)
    include("cmake/packaging.cmake")
endif(PASTA_ENABLE_INSTALL)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------
# toolchain-specific warning options ---------
# --------------------------------------------
set(GNULIKE_COMPILER_LIST "Clang" "AppleClang" "GNU")

if(CMAKE_CXX_COMPILER_ID IN_LIST GNULIKE_COMPILER_LIST)
    set(CXX_WARNING_OPTIONS -Wall -pedantic -Wconversion -Wno-unknown-pragmas)
    set(CXX_WARNINGS_AS_ERRORS_OPTION -Werror)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CXX_WARNING_OPTIONS /W4)
    set(CXX_WARNINGS_AS_ERRORS_OPTION /WX)
else()
    set(CXX_WARNING_OPTIONS)
    set(CXX_WARNINGS_AS_ERRORS_OPTION)
    message(WARNING "Unsupported C++ compiler '${CMAKE_CXX_COMPILER_ID}'; build may not work right!")
endif()

# --------------------------------------------------
# `pasta_cxx_settings` for global build options ----
# --------------------------------------------------
add_library(pasta_cxx_settings INTERFACE)
target_compile_features(pasta_cxx_settings INTERFACE cxx_std_20)
set_target_properties(pasta_cxx_settings PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(pasta_cxx_settings PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(pasta_cxx_settings INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_options(pasta_cxx_settings INTERFACE ${CXX_WARNING_OPTIONS})

if(PASTA_WARNINGS_AS_ERRORS)
    target_compile_options(pasta_cxx_settings INTERFACE ${CXX_WARNINGS_AS_ERRORS_OPTION})
endif()

if(PASTA_BOOTSTRAP_MACROS OR PASTA_BOOTSTRAP_TYPES)
    target_compile_definitions(pasta_cxx_settings INTERFACE -DPASTA_IN_BOOTSTRAP)
endif()

find_package(Filesystem REQUIRED COMPONENTS Final Experimental)
if(Filesystem_FOUND)
    message(STATUS "Found filesystem: ${CXX_FILESYSTEM_HEADER}")
endif()
target_link_libraries(pasta_cxx_settings INTERFACE std::filesystem)

# --------------------------------------------
# Clang/LLVM dependencies --------------------
# --------------------------------------------

add_subdirectory(vendor)

find_package(LLVM CONFIG REQUIRED)
find_package(Clang CONFIG REQUIRED)

add_library(pasta_thirdparty_llvm INTERFACE)
if(PASTA_ENABLE_TESTING)
    list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
    include(AddLLVM)  # For LLVM lit test suite stuff.
endif(PASTA_ENABLE_TESTING)

target_link_libraries(pasta_thirdparty_llvm INTERFACE
    clangAST
    clangASTMatchers
    clangBasic
    clangCodeGen
    clangDriver
    clangFrontend
    clangSerialization
    clangTooling
)

target_include_directories(pasta_thirdparty_llvm INTERFACE
    "$<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS};${LLVM_INCLUDE_DIR};${CLANG_INCLUDE_DIRS}>"
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# TODO(pag): Not sure if `Clang_DEFINITIONS` or `CLANG_DEFINITIONS`.
target_compile_definitions(pasta_thirdparty_llvm INTERFACE
    ${LLVM_DEFINITIONS}
    ${Clang_DEFINITIONS}
)

if(PASTA_ENABLE_INSTALL)
  export(PACKAGE "${PROJECT_NAME}")
  
  set(cmake_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
  
  include(CMakePackageConfigHelpers)
  configure_package_config_file("${PROJECT_NAME}Config.cmake.in"
      "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      INSTALL_DESTINATION "${cmake_install_dir}"
  )

  install(
      FILES
          "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
          "${PROJECT_SOURCE_DIR}/cmake/modules/FindFilesystem.cmake"
      DESTINATION "${cmake_install_dir}"
  )
  install(EXPORT "${PROJECT_NAME}Targets"
      DESTINATION "${cmake_install_dir}"
      NAMESPACE "${PROJECT_NAME}::"
  )
endif(PASTA_ENABLE_INSTALL)

# --------------------------------------------
# Configure lib/Compiler/Host.h --------------
# --------------------------------------------

set(PASTA_DUMMY_SOURCE_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.x")
set(PASTA_CC_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cc.version")
set(PASTA_CXX_VERSION_OUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/pasta.cxx.version")

if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    if("x${CMAKE_C_SIMULATE_ID}" STREQUAL "xMSVC")
        set(PASTA_C_COMPILER_ID 3)  # clang-cl
    elseif(CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
        set(PASTA_C_COMPILER_ID 2)  # Apple's Clang
    else()
        set(PASTA_C_COMPILER_ID 1)  # LLVM Clang.
    endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    set(PASTA_C_COMPILER_ID 4)  # cl
elseif (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(PASTA_C_COMPILER_ID 5)  # g++
else()
    set(PASTA_C_COMPILER_ID 0)  # Unknown.
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if("x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
        set(PASTA_CXX_COMPILER_ID 3)  # clang-cl
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        set(PASTA_CXX_COMPILER_ID 2)  # Apple's Clang
    else()
        set(PASTA_CXX_COMPILER_ID 1)  # LLVM Clang.
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(PASTA_CXX_COMPILER_ID 4)  # cl
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PASTA_CXX_COMPILER_ID 5)  # g++
else()
    set(PASTA_CXX_COMPILER_ID 0)  # Unknown.
endif()

set(HOST_H_IN_FILE "${PROJECT_SOURCE_DIR}/lib/Compile/Host.h.in")
set(HOST_H_FILE "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile/Host.h")

get_compiler_paths(
    COMPILER "${CMAKE_C_COMPILER}"
    OUT_VAR CSTR_HOST_CC_VERSION_INFO
    ARGS -x c -std=c18
)
get_compiler_paths(
    COMPILER "${CMAKE_C_COMPILER}"
    OUT_VAR CSTR_HOST_CC_VERSION_INFO_FAKE_SYSROOT
    ARGS -x c -std=c18 -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz/" -Wno-missing-sysroot
)

get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO
    ARGS -x c++ -std=c++20
)
get_compiler_paths(
    COMPILER "${CMAKE_CXX_COMPILER}"
    OUT_VAR CSTR_HOST_CXX_VERSION_INFO_FAKE_SYSROOT
    ARGS -x c++ -std=c++20 -isysroot "${CMAKE_CURRENT_BINARY_DIR}/xyz" -Wno-missing-sysroot
)

configure_file("${HOST_H_IN_FILE}" "${HOST_H_FILE}" @ONLY)

# --------------------------------------------
# Main build targets -------------------------
# --------------------------------------------

set(util_HEADERS
    "include/pasta/Util/ArgumentVector.h"
    "include/pasta/Util/Compiler.h"
    "include/pasta/Util/Error.h"
    "include/pasta/Util/File.h"
    "include/pasta/Util/FileManager.h"
    "include/pasta/Util/FileSystem.h"
    "include/pasta/Util/Init.h"
    "include/pasta/Util/Result.h"
)

add_library(pasta_util STATIC
    ${util_HEADERS}
    
    "lib/Util/FileManager.h"
    
    "lib/Util/ArgumentVector.cpp"
    "lib/Util/Error.cpp"
    "lib/Util/File.cpp"
    "lib/Util/FileManager.cpp"
    "lib/Util/FileSystem.cpp"
    "lib/Util/Init.cpp"
)

target_link_libraries(pasta_util PUBLIC
    pasta_cxx_settings
    pasta_thirdparty_llvm
)

set_target_properties(
    pasta_util PROPERTIES
    POSITION_INDEPENDENT_CODE YES
)

set(ast_HEADERS
    "include/pasta/AST/AST.h"
    "include/pasta/AST/Attr.h"
    "include/pasta/AST/AttrManual.h"
    "include/pasta/AST/Decl.h"
    "include/pasta/AST/DeclHead.h"
    "include/pasta/AST/DeclTail.h"
    "include/pasta/AST/Forward.h"
    "include/pasta/AST/Macro.h"
    "include/pasta/AST/Printer.h"
    "include/pasta/AST/Stmt.h"
    "include/pasta/AST/StmtManual.h"
    "include/pasta/AST/Token.h"
    "include/pasta/AST/Type.h"
    "include/pasta/AST/TypeManual.h"
    "include/pasta/Compile/Command.h"
    "include/pasta/Compile/Compiler.h"
    "include/pasta/Compile/Job.h"
)

add_library(pasta_compiler STATIC
    ${ast_HEADERS}
    
    "lib/AST/AlignTokens.cpp"
    "lib/AST/AST.cpp"
    "lib/AST/Attr.cpp"
    "lib/AST/AttrManual.cpp"
    "lib/AST/Bounds.cpp"
    "lib/AST/Builder.cpp"
    "lib/AST/Builder.h"
    "lib/AST/Decl.cpp"
    "lib/AST/DeclHead.cpp"
    "lib/AST/Macro.h"
    "lib/AST/Macro.cpp"
    "lib/AST/Stmt.cpp"
    "lib/AST/StmtManual.cpp"
    "lib/AST/Token.cpp"
    "lib/AST/Token.h"
    "lib/AST/Type.cpp"
    "lib/AST/TypeManual.cpp"
    "lib/AST/Util.h"
    "lib/AST/Printer/DeclPrinter.cpp"
    "lib/AST/Printer/DeclStmtPrinter.h"
    "lib/AST/Printer/Printer.cpp"
    "lib/AST/Printer/Printer.h"
    "lib/AST/Printer/raw_ostream.h"
    "lib/AST/Printer/StmtPrinter.cpp"
    "lib/AST/Printer/TypePrinter.cpp"
    
    "${HOST_H_FILE}"
    "lib/Compile/Builtins.cpp"
    "lib/Compile/BuiltinsPPC.h"
    "lib/Compile/BuiltinsX86.h"
    "lib/Compile/Command.h"
    "lib/Compile/Compiler.h"
    "lib/Compile/FileSystem.h"
    "lib/Compile/Job.h"
    "lib/Compile/PatchedMacroTracker.h"
    "lib/Compile/ParsedFileTracker.h"
    
    "lib/Compile/Builtins.cpp"
    "lib/Compile/Command.cpp"
    "lib/Compile/Compiler.cpp"
    "lib/Compile/Create.cpp"
    "lib/Compile/Diagnostic.cpp"
    "lib/Compile/FileSystem.cpp"
    "lib/Compile/Job.cpp"
    "lib/Compile/PatchedMacroTracker.cpp"
    "lib/Compile/Preprocess.cpp"
    "lib/Compile/Run.cpp"
)

set_target_properties(
    pasta_compiler PROPERTIES
    VISIBILITY_INLINES_HIDDEN YES
    POSITION_INDEPENDENT_CODE YES
)

target_include_directories(pasta_compiler PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile"
)

target_link_libraries(pasta_compiler PRIVATE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_util
)

add_library("pasta" INTERFACE)
target_link_libraries("pasta" INTERFACE
    pasta_cxx_settings
    pasta_thirdparty_llvm
    pasta_util
    pasta_compiler
)

if(PASTA_BOOTSTRAP_MACROS OR PASTA_BOOTSTRAP_TYPES)

    # --------------------------------------------
    # Add bootstrap library ----------------------
    # --------------------------------------------

    add_library(pasta_bootstrap STATIC
        "include/pasta/AST/DeclBootstrap.h"
        "include/pasta/AST/StmtBootstrap.h"
        "include/pasta/AST/TypeBootstrap.h"
        
        "lib/AST/DeclBootstrap.cpp"
        "lib/AST/StmtBootstrap.cpp"
        "lib/AST/TypeBootstrap.cpp"
    )
    
    target_include_directories(pasta_bootstrap PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}/lib/Compile"
    )
    
    target_link_libraries(pasta_bootstrap PRIVATE
        pasta_cxx_settings
        pasta_thirdparty_llvm
        pasta_util
    )
    target_link_libraries("pasta" INTERFACE
        pasta_bootstrap
    )
endif()

# ---------------------------------------------------
# Configure bootstrap header files with source paths.
# ---------------------------------------------------

set(PASTA_INCLUDE_SOURCE_PATH "${PROJECT_SOURCE_DIR}/include")
set(PASTA_BINARY_PATH "${CMAKE_CURRENT_BINARY_DIR}")
set(PASTA_BIN_BOOTSTRAP_MACROS_MACRO_GENERATOR_CPP_PATH "${PROJECT_SOURCE_DIR}/bin/BootstrapMacros/MacroGenerator.cpp")
set(PASTA_BIN_BOOTSTRAP_TYPES_GENERATED_H_PATH "${PROJECT_SOURCE_DIR}/bin/BootstrapTypes/Generated.h")
set(PASTA_INCLUDE_AST_FORWARD_H_PATH "${PROJECT_SOURCE_DIR}/include/pasta/AST/Forward.h")
set(PASTA_INCLUDE_AST_DECL_H_PATH "${PROJECT_SOURCE_DIR}/include/pasta/AST/Decl.h")
set(PASTA_SRC_AST_DECL_CPP_PATH "${PROJECT_SOURCE_DIR}/lib/AST/Decl.cpp")
set(PASTA_INCLUDE_AST_TYPE_H_PATH "${PROJECT_SOURCE_DIR}/include/pasta/AST/Type.h")
set(PASTA_SRC_AST_TYPE_CPP_PATH "${PROJECT_SOURCE_DIR}/lib/AST/Type.cpp")
set(PASTA_INCLUDE_AST_STMT_H_PATH "${PROJECT_SOURCE_DIR}/include/pasta/AST/Stmt.h")
set(PASTA_SRC_AST_STMT_CPP_PATH "${PROJECT_SOURCE_DIR}/lib/AST/Stmt.cpp")
set(PASTA_INCLUDE_AST_ATTR_H_PATH "${PROJECT_SOURCE_DIR}/include/pasta/AST/Attr.h")
set(PASTA_SRC_AST_ATTR_CPP_PATH "${PROJECT_SOURCE_DIR}/lib/AST/Attr.cpp")
set(PASTA_PYTHON_BINDINGS_PATH "${PROJECT_SOURCE_DIR}/bindings/python/src/AST")

set(BOOTSTRAP_CONFIG_H_IN "${PROJECT_SOURCE_DIR}/BootstrapConfig.h.in")
set(BOOTSTRAP_CONFIG_H "${CMAKE_CURRENT_BINARY_DIR}/BootstrapConfig.h")
configure_file("${BOOTSTRAP_CONFIG_H_IN}" "${BOOTSTRAP_CONFIG_H}" @ONLY)

# --------------------------------------------
# Bootstrap build targets --------------------
# --------------------------------------------

add_library(pasta_bootstrap_config INTERFACE)
add_dependencies(pasta_bootstrap_config "${BOOTSTRAP_CONFIG_H}")
target_include_directories(pasta_bootstrap_config INTERFACE
    "${CMAKE_CURRENT_BINARY_DIR}"
)

if(NOT (PASTA_BOOTSTRAP_MACROS OR PASTA_BOOTSTRAP_TYPES))
  add_subdirectory(bindings)
endif()

if(PASTA_ENABLE_INSTALL AND NOT PASTA_BOOTSTRAP_MACROS AND NOT PASTA_BOOTSTRAP_TYPES)
  
  if(PASTA_ENABLE_PY_BINDINGS)
    set(PASTA_PY_BINDING_LIB_NAME "pypasta")
  endif()

  install(
    DIRECTORY
      "include/pasta"
    DESTINATION
      "${CMAKE_INSTALL_INCLUDEDIR}"
  )

  install(
    TARGETS
      "pasta" "pasta_compiler" "pasta_util"
      "pasta_thirdparty_llvm" "pasta_cxx_settings"
      ${PASTA_PY_BINDING_LIB_NAME}
    EXPORT
      "${PROJECT_NAME}Targets"
    RUNTIME
      DESTINATION
        "${CMAKE_INSTALL_BINDIR}"
    LIBRARY
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE
      DESTINATION
        "${CMAKE_INSTALL_LIBDIR}"
  )
endif()

add_subdirectory(bin)

if(PASTA_ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif(PASTA_ENABLE_TESTING)