#pragma once

#include "../logic/Game.h"
#include "../resources/global_resources.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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

    void onLoop();

    void onInput();

    void onRender();

    /**
     * Cleans all loaded resources
     */
    void onCleanup();

};
