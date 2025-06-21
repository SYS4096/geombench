cmake_minimum_required(VERSION 3.10)
project(geombench VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG master
)

FetchContent_MakeAvailable(
    glm
)

add_library(geombench STATIC
    include/geombench/geomrand.h
    src/geomrand.cpp
    include/geombench/objio.h
    src/objio.cpp
)

target_link_libraries(geombench glm)
target_include_directories(geombench PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

