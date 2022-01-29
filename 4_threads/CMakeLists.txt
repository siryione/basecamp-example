cmake_minimum_required(VERSION 3.16)

project(4_threads)

file(GLOB project_src "*.cpp" "*.hpp")

add_executable(4_threads ${project_src})
