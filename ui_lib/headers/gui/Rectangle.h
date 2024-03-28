#pragma once

#include "Node.h"
#include "../ui/InputData.h"


namespace gui
{

    class Rectangle : public Node {
    private:
        SDL_Texture *texture;
        int width, height;

        double vertical_scale, horizontal_scale;

    public:
        Rectangle();

        explicit Rectangle(SDL_Texture *texture);

        ~Rectangle() override;

        /**
         * Frees previous data
         */
        void close() override;

        /**
         * Unneeded, there is nothing to update on a texture.
         */
        void update(
                InputData *input_data,
                Uint64 elapsed_time,
                int x, int y
        ) override;

        /**
         * Renders texture at [x,y]
         * @param window the window to render to
         * @param renderer  the renderer to render to
         * @param x horizontal position of the top-left corner of the texture
         * @param y vertical position of the top-left corner of the texture
         */
        void render(
                SDL_Window *window,
                SDL_Renderer *renderer,
                int x, int y
        ) override;


        /**
         * Loads the texture from file.
         * @param renderer the renderer setting the format of the texture
         * @param file the file to load
         * @param color_key a color to key to transparency; if alpha is 0, there is none
         * @return true on success
         */
        bool loadFrom(
                SDL_Renderer *renderer,
                const char *file,
                SDL_Color color_key = {0,0,0,0}
        );

        /**
         * Scales the size of the rendered image
         * @param horizontal horizontal scale
         * @param vertical vertical scale
         */
        void scale(double horizontal = 1, double vertical = 1);

    private:
        [[nodiscard]] int getWidth() const override;

        [[nodiscard]] int getHeight() const override;
    };

}