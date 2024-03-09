#pragma once

#include "../resources/global_resources.h"
#include <queue>
using std::queue;

/**
 * A struct used to hold new input data
 */
typedef struct InputData {
    /// the keyboard indexed with SDL_Scancode (https://wiki.libsdl.org/SDL2/SDL_Scancode)
    const Uint8* keyboard = nullptr;
    /// mouse position
    Sint32 mouse_x=0, mouse_y=0;
    /// The raw events in a que
    queue<SDL_Event> events;
}InputData;