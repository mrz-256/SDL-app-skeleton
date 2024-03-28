#include "headers/ui/UI.h"

bool UI::onLoadMedia()
{
    Fonts::font = TTF_OpenFont("../assets/font.ttf", 12);
    if (Fonts::font == nullptr) return false;

    Textures::cat->loadFrom(renderer, "../assets/cat.jpg");

    return true;
}