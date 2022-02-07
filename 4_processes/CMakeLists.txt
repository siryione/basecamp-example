cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(4_processes)

file(GLOB project_src "*.hpp" "*.cpp")

add_executable(4_processes ${project_src} )
