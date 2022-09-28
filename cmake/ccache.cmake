# Copyright (c) 2018-present Trail of Bits, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

if(PLATFORM_LINUX OR PLATFORM_MACOS)
  find_program(ccache_executable "ccache")
  if(NOT ccache_executable STREQUAL "ccache_executable-NOTFOUND")
    message(STATUS "${PROJECT_NAME}: Enabling ccache support (${ccache_executable})")

    set(CMAKE_CXX_COMPILER_LAUNCHER "${ccache_executable}" CACHE FILEPATH "ccache")
    set(CMAKE_C_COMPILER_LAUNCHER "${ccache_executable}" CACHE FILEPATH "ccache")

  else()
    message(STATUS "${PROJECT_NAME}: No ccache executable found")
  endif()
endif()
