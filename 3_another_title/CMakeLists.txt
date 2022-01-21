cmake_minimum_required(VERSION 3.16)

project(3_another_title)

file(GLOB project_src "*.hpp" "*.cpp")

add_executable(3_another_title ${project_src} )