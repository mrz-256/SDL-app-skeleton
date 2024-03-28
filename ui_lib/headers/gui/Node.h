#pragma once

#include "../resources/global_resources.h"
#include "../ui/InputData.h"

namespace gui
{

    class Node {
    public:
        virtual ~Node();

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

        [[nodiscard]] virtual int getWidth() const = 0;

        [[nodiscard]] virtual int getHeight() const = 0;

    };

} // gui
