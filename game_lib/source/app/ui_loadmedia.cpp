#include "headers/app/UI.h"

bool UI::onLoadMedia()
{
    Fonts::font = TTF_OpenFont("../assets/font.ttf", 12);
    if (Fonts::font == nullptr) return false;

    return true;
}