cmake_minimum_required(VERSION 2.8)

project(LogView)
add_subdirectory(pcre)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++11")
include_directories(${PCRE_SOURCE_DIR})

FILE(GLOB sources ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(LogView ${sources})
target_link_libraries(LogView pcre pcrecpp)
