cmake_minimum_required(VERSION 3.26)
project(GameOfCheckers)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfCheckers main.cpp
        headers/logic/Game.h
        source/logic/Game.cpp
        headers/logic/Piece.h
        headers/logic/MoveDirection.h)
