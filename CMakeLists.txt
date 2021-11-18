cmake_minimum_required(VERSION 3.20)
project(Console_Game_Engine_C__)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory("C:/raylib/raylib" raylib)
add_executable(Console_Game_Engine_C__ main.cpp ErrorHandling.h)
target_link_libraries(${PROJECT_NAME} raylib)