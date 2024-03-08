project(checkers)

set(HEADER_FILES
        headers/logic/Piece.h
        headers/logic/MoveDirection.h
        headers/logic/Game.h
        headers/ui/UI.h
        headers/resources/global_resources.h
)

set(SOURCE_FILES
        source/logic/Game.cpp
        source/ui/ui_execute.cpp
        source/ui/ui_init.cpp
        source/ui/ui_loop.cpp
        source/ui/ui_render.cpp
        source/ui/ui_input.cpp
        source/ui/ui_cleanup.cpp
        source/ui/ui_loadmedia.cpp
        source/resources/global_resources.cpp
)

add_library(game_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})