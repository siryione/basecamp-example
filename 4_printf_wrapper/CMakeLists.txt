cmake_minimum_required(VERSION 3.16)

project(4_printf_wrapper)

file(GLOB project_src "*.hpp" "*.cpp")

add_executable(4_printf_wrapper ${project_src} )
