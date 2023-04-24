set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++")
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc")


cmake_minimum_required(VERSION 3.10.2)

project(ProjektAlpha)

add_executable(${PROJECT_NAME} ./src/main.cpp)
