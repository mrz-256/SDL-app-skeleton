#pragma once

#include "../logic/Game.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class UI {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Game *game;
    bool running;

public:
    UI();

    bool onInit();

    bool onLoadMedia();

    int onExecute();

    void onLoop();

    void onInput();

    void onRender();

    void onCleanup();

};
