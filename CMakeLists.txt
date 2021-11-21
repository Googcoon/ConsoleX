cmake_minimum_required(VERSION 3.20)
project(ConsoleX)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory("C:/raylib/raylib" raylib)
add_executable(ConsoleX main.cpp ErrorHandling.h ansicolor.h color.hpp)
target_link_libraries(${PROJECT_NAME} raylib)