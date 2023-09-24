cmake_minimum_required(VERSION 3.22)

project(Lythium VERSION 1.0.2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

option(COMPILE_EXECUTABLE "Whether to compile an executable" OFF)

option(ENABLE_WARNINGS "Enable warnings for target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors" ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

set(BUILD_SHARED_LIBS ON)


set(LIBRARY_NAME "Lythium")
set(EXECUTABLE_NAME "TestApp")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(ENABLE_LTO)
    include(LTO)
endif()


if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(ENABLE_WARNINGS_AS_ERRORS OFF)
endif()

add_subdirectory(configured)
add_subdirectory(src)

if (COMPILE_EXECUTABLE)
    add_subdirectory(testbed)
endif()

