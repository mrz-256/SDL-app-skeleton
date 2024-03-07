cmake_minimum_required(VERSION 3.26)
project(GameOfCheckers)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfCheckers_run game_lib/main.cpp)

include_directories(game_lib)
add_subdirectory(game_lib)

target_link_libraries(GameOfCheckers_run game_lib)

add_subdirectory(tests)