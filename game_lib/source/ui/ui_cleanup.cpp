#include "headers/ui/UI.h"

void UI::onCleanup()
{
    // close all loaded media
    TTF_CloseFont(Fonts::font);

    // destroy SDL objects
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // quit SDL
    TTF_Quit();
    SDL_Quit();
}