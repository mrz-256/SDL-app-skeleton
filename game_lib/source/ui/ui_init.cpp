#include "headers/ui/UI.h"

bool UI::onInit()
{
    // initialize SDL and SDL_ttf
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 or TTF_Init() < 0) return false;

    // create window
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            screen_size,screen_size,
            SDL_WINDOW_HIDDEN
    );

    if (window != nullptr)
    {
        // create renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer != nullptr)
        {
            // create tiles
            return true;
        }
        else
        {
            SDL_free(window);
            return false;
        }
    } else
    {
        return false;
    }
}