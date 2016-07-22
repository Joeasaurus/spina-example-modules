cmake_minimum_required(VERSION 3.2)
project(example-modules)
set(CMAKE_VERBOSE_MAKEFILE false)

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(flags "-O3 -std=c++11 -Wall -Wextra -Wno-unused-parameter -D__MACOSX_CORE__")

	set(CMAKE_CXX_FLAGS "${flags}"
		CACHE STRING "Flags used by the compiler during all build types." FORCE)
	set(CMAKE_C_FLAGS   "${flags}"
		CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    /usr/local/include/cppevent
	/usr/local/include/spina
)

find_library(LIBZMQ    zmq)
find_library(LIBMODULE spina-module)

add_library(example-input SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/input.cpp)
set_target_properties(example-input
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}
)
target_link_libraries(example-input
    ${LIBZMQ}
	${LIBMODULE}
)

add_library(example-output SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/output.cpp)
set_target_properties(example-output
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}
)
target_link_libraries(example-output
    ${LIBZMQ}
	${LIBMODULE}
)
