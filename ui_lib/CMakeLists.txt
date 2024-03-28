project(ui)

set(HEADER_FILES
        headers/ui/UI.h
        headers/resources/global_resources.h
        headers/scene_logic/SceneManager.h
        headers/scene_logic/Scene.h
        headers/ui/InputData.h
        headers/gui/Node.h
        headers/gui/Rectangle.h
        headers/scenes/ExampleScene.h
        headers/scenes/ExampleSceneTwo.h
        headers/gui/gui.h
)

set(SOURCE_FILES
        source/ui/ui_execute.cpp
        source/ui/ui_init.cpp
        source/ui/ui_loop.cpp
        source/ui/ui_render.cpp
        source/ui/ui_input.cpp
        source/ui/ui_cleanup.cpp
        source/ui/ui_loadmedia.cpp
        source/resources/global_resources.cpp
        source/scene_logic/SceneManager.cpp
        source/scene_logic/Scene.cpp
        source/gui/Node.cpp
        source/gui/Rectangle.cpp
        source/scenes/ExampleScene.cpp
        source/scenes/ExampleSceneTwo.cpp
)

add_library(ui_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})