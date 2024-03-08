#pragma once

#include "InputData.h"
#include "../resources/global_resources.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
using std::string;

class UI {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;

    string title;
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
     * Updates the instance of InputData with current events and input
     * @param input_data  pointer to the data struct
     */
    void onInput(InputData* input_data);

    void onLoop(InputData* input_data);

    void onRender();

    /**
     * Cleans all loaded resources
     */
    void onCleanup();

};
