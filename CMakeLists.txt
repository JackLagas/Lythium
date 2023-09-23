cmake_minimum_required(VERSION 3.22)

project(Lythium VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


option(COMPILE_EXECUTABLE "Whether to compile an executable" ON)

option(ENABLE_WARNINGS "Enable warnings for target" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors" ON)


option(ENABLE_LTO "Enable to add Link Time Optimization." ON)


set(LIBRARY_NAME "Lythium")
set(UNIT_TEST_NAME "Unit_Tests")
set(EXECUTABLE_NAME "TestApp")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(ENABLE_LTO)
    include(LTO)
endif()


add_subdirectory(configured)
add_subdirectory(src)

if (COMPILE_EXECUTABLE)
    add_subdirectory(testbed)
endif()

