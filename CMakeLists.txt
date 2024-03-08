cmake_minimum_required(VERSION 3.26)
project(GameOfCheckers)

set(CMAKE_CXX_STANDARD 17)

link_directories(/usr/lib/x86_64-linux-gnu/)

include_directories(/usr/include/SDL2)

add_executable(GameOfCheckers_run game_lib/source/ui/ui_execute.cpp)

include_directories(game_lib)
add_subdirectory(game_lib)

target_link_libraries(GameOfCheckers_run game_lib)

add_subdirectory(tests)

target_link_libraries(GameOfCheckers_run SDL2 SDL2_ttf SDL2_image)
