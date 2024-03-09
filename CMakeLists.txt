cmake_minimum_required(VERSION 3.26)
project(UI)

set(CMAKE_CXX_STANDARD 17)

link_directories(/usr/lib/x86_64-linux-gnu/)

include_directories(/usr/include/SDL2)

add_executable(ui_run ui_lib/source/ui/ui_execute.cpp)

include_directories(ui_lib)
add_subdirectory(ui_lib)

target_link_libraries(ui_run ui_lib)

target_link_libraries(ui_run SDL2 SDL2_ttf SDL2_image)
