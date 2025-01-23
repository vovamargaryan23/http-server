cmake_minimum_required(VERSION 3.10)

project(HttpServer VERSION 0.1.0)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/**)

add_executable(HttpServer ${SRC_FILES})
