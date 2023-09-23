cmake_minimum_required(VERSION 3.25)
project(colb_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(colb_solver main.cpp Colb.h Game.h Color.h)
