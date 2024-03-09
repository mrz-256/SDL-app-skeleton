#pragma once

#include "InputData.h"
#include "../resources/global_resources.h"
#include "../scene_logic/SceneManager.h"
#include "../scenes/ExampleScene.h"
#include "../scenes/ExampleSceneTwo.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
using std::string;

class UI {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool running;

    int screen_size;

public:
    UI();

    /**
     * Initializes used libraries (SDL)
     * @return true on success
     */
    bool onInit();

    /**
     * Loads all media used in UI.
     * @return true on success
     */
    static bool onLoadMedia();

    int onExecute();

    /**
     * Updates the instance of InputData with current events and input.
     * Executed on every iteration of main loop.
     * @param input_data  pointer to the data struct
     */
    void onInput(InputData* input_data);

    /**
     * Updates game process on every iteration of main loop.
     * @param input_data current input and events
     * @param elapsed_time elapsed time since last iteration in milliseconds
     */
    void onLoop(InputData* input_data, Uint64 elapsed_time);

    /**
     * Renders everything on every iteration of main loop.
     */
    void onRender();

    /**
     * Cleans all loaded resources
     */
    void onCleanup();

};
