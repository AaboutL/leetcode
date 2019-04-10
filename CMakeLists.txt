cmake_minimum_required(VERSION 3.5)
project(leetcode)
set(VERSION 1.1.0)

if(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

if (NOT DEFINED ARCH)
    set(ARCH x86_64-linux-gnu)
    #    set(BUILD_SHARED_LIBS ON)
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")


add_subdirectory(core)
add_subdirectory(samples)
