#include "headers/ui/UI.h"

void UI::onInput(InputData* input_data)
{
    SDL_PumpEvents();

    // the keyboard pointer stays the same so this could only be done once
    input_data->keyboard = SDL_GetKeyboardState(nullptr);

    SDL_GetMouseState(&input_data->mouse_x, &input_data->mouse_y);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        else
        {
            input_data->events.push(event);
        }
    }
}


