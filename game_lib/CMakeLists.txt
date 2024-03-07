project(checkers)

set(HEADER_FILES
        headers/logic/Piece.h
        headers/logic/MoveDirection.h
        headers/logic/Game.h
        headers/app/UI.h
)

set(SOURCE_FILES
        source/logic/Game.cpp
        source/app/ui_execute.cpp
        source/app/ui_init.cpp
        source/app/ui_loop.cpp
        source/app/ui_render.cpp
        source/app/ui_input.cpp
        source/app/ui_cleanup.cpp
        source/app/ui_loadmedia.cpp
)

add_library(game_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})