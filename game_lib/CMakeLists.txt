project(checkers)

set(HEADER_FILES
        headers/logic/Piece.h
        headers/logic/MoveDirection.h
        headers/logic/Game.h
)

set(SOURCE_FILES
        source/logic/Game.cpp
)

add_library(game_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})