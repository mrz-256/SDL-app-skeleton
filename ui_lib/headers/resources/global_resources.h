#pragma once

#include <SDL_ttf.h>
#include <SDL_image.h>


/// if there are more resources, it may be better to use singleton and have the
/// loading there rather than in UI::onLoadMedia()

namespace Fonts
{
    // the only font used in whole game
    extern TTF_Font *font;
}

namespace Textures
{
    // cat image
    
}