cmake_minimum_required(VERSION 3.1)

project(Reddit_project)

find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_LINKER "/usr/bin/clang++")

set(src_dir ${CMAKE_SOURCE_DIR}/src)
set(tests_dir ${CMAKE_SOURCE_DIR}/tests)

add_subdirectory(${src_dir})
file(GLOB_RECURSE tests_src CONFIGURE_DEPENDS ${tests_dir}/*.cpp)

add_executable(tests ${tests_src})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(tests)

add_executable(exec ${src_dir}/main.cpp)
target_link_libraries(exec PRIVATE lib src include)