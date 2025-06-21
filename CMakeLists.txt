cmake_minimum_required(VERSION 3.10)
project(geombench)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(FetchContent)

set(BENCHMARK_ENABLE_TESTING off)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.0
)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG master
)

FetchContent_MakeAvailable(
    googlebenchmark
    glm
)

find_package(Threads REQUIRED)
    
add_library(geombench STATIC
    src/geomrand.h
    src/geomrand.cpp
    src/objio.h
    src/objio.cpp
)

target_link_libraries(geombench glm)
target_include_directories(geombench PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

