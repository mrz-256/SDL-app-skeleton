#include "headers/ui/UI.h"

void UI::onRender()
{
    SceneManager::get()->renderCurrent(window, renderer);

    SDL_RenderPresent(renderer);
}