#include "headers/gui/Rectangle.h"

gui::Rectangle::Rectangle()
{
    texture = nullptr;
    width = height = 0;
    vertical_scale = horizontal_scale = 1;
}

gui::Rectangle::Rectangle(SDL_Texture *texture) : texture(texture)
{
    width = height = 0;
    if (texture != nullptr)
    {
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    }
    vertical_scale = horizontal_scale = 1;
}

gui::Rectangle::~Rectangle()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

void gui::Rectangle::close()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = height = 0;
    }
}

void gui::Rectangle::update(InputData *input_data, Uint64 elapsed_time, int x, int y)
{}

void gui::Rectangle::render(SDL_Window *window, SDL_Renderer *renderer, int x, int y)
{
    if (texture == nullptr) return;

    SDL_Rect destination = {x, y};
    destination.w = (int)((double) width * horizontal_scale);
    destination.h = (int)((double) height * vertical_scale);

    SDL_RenderCopy(renderer, texture, nullptr, &destination);
}

int gui::Rectangle::getWidth() const
{
    return width;
}

int gui::Rectangle::getHeight() const
{
    return height;
}

bool gui::Rectangle::loadFrom(SDL_Renderer *renderer, const char *file, SDL_Color color_key)
{
    // to clean previous data
    close();

    // obviously invalid
    if (renderer == nullptr || file == nullptr || strlen(file) == 0) return false;

    SDL_Surface *temp = IMG_Load(file);
    if (temp != nullptr)
    {
        if (color_key.a != 0)
        {
            SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, color_key.r, color_key.g, color_key.b));
        }

        texture = SDL_CreateTextureFromSurface(renderer, temp);
        if (texture != nullptr)
        {
            width = temp->w;
            height = temp->h;
        }

    }
    SDL_FreeSurface(temp);

    return texture != nullptr;
}

void gui::Rectangle::scale(double horizontal, double vertical)
{
    horizontal_scale = horizontal;
    vertical_scale = vertical;
}

