project(Google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE SOURCES "game_lib/*")

add_executable(Google_Tests_run GameTest.cpp)

target_link_libraries(Google_Tests_run game_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)