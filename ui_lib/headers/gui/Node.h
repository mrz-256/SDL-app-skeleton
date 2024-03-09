#pragma once

#include "../resources/global_resources.h"
#include "headers/ui/InputData.h"

namespace gui
{

    class Node {
        virtual ~Node() = default;

        virtual void close();

        virtual void update(
                InputData *input_data,
                Uint64 elapsed_time,
                int x, int y
        ) = 0;

        virtual void render(
                SDL_Window *window,
                SDL_Renderer *renderer,
                int x, int y
        ) = 0;

        virtual int width() = 0;

        virtual int height() = 0;

    };

} // gui
