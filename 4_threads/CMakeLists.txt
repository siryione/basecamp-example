cmake_minimum_required(VERSION 3.16)

project(4_threads)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB project_src "*.cpp" "*.hpp")

add_executable(4_threads ${project_src})
