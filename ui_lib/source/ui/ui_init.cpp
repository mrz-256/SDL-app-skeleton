#include "headers/ui/UI.h"

bool UI::onInit()
{
    // initialize SDL and SDL_ttf
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 or TTF_Init() < 0) return false;
    // initialize SDL_image
    int flags = IMG_INIT_JPG | IMG_INIT_PNG;
    if (not(IMG_Init(flags) & flags)) return false;

    // create window
    window = SDL_CreateWindow(
            "ui",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            screen_size,screen_size,
            SDL_WINDOW_HIDDEN
    );

    if (window != nullptr)
    {
        // create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (renderer != nullptr)
        {
            return true;
        }
        else
        {
            SDL_DestroyWindow(window);
            return false;
        }
    } else
    {
        return false;
    }
}