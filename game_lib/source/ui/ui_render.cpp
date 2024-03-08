#include "headers/ui/UI.h"

void UI::onRender()
{
    scene_manager->renderCurrent(window, renderer);

    SDL_RenderPresent(renderer);
}