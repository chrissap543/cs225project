cmake_minimum_required(VERSION 3.1)

project(REDDIT)

# Specify the C++ standard (CMake3+)
add_compile_options(-std=c++14)

# Add header files
file(GLOB INCLUDES "include/*.hpp")
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add src files
file(GLOB SOURCES "src/*.cpp")

# Add testing sources
file(GLOB TEST_SOURCES "tests/*.cpp")

# Add library interface for our files
add_library(ProjectLib ${SOURCES} ${INCLUDES})

# Link
target_include_directories(ProjectLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add the executable
add_executable(exec main.cpp)
target_link_libraries(exec ProjectLib)

target_include_directories(exec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


# Add Catch2
Include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.1
)

FetchContent_MakeAvailable(Catch2)
add_executable(tests ${SOURCES} ${TEST_SOURCES})
target_link_libraries(tests ProjectLib Catch2::Catch2)