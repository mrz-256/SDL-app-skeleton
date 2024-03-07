#include "../../headers/app/UI.h"

UI::UI() : window(nullptr), renderer(nullptr), running(true)
{
    title = "Checkers";
    screen_size = 500;
}

int UI::onExecute()
{
    if (not onInit()) return -1;
    if (not onLoadMedia()) return -2;

}



int main()
{
    UI app;
    return app.onExecute();
}