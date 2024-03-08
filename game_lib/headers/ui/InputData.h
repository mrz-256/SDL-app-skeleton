#pragma once

#include "../resources/global_resources.h"
#include <queue>
using std::queue;

typedef struct InputData {
    Uint8* keyboard = nullptr;
    Sint32 mouse_x=0, mouse_y=0;
    queue<SDL_Event> events;
}InputData;