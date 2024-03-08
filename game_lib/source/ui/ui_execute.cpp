#include "../../headers/ui/UI.h"

UI::UI() : window(nullptr), renderer(nullptr), running(true)
{
    title = "Checkers";
    screen_size = 500;
}

int UI::onExecute()
{
    if (not onInit()) return -1;
    if (not onLoadMedia()) return -2;

    Uint64 last = SDL_GetTicks64();
    auto* input_data = new InputData();

    SDL_ShowWindow(window);
    while (running)
    {
        Uint64 elapsed_time = SDL_GetTicks64() - last;
        if (elapsed_time < 1000/60) continue;
        last += elapsed_time;

        onInput(input_data);
        onLoop(input_data, elapsed_time);
        onRender();
    }

    onCleanup();
    return 0;
}



int main()
{
    UI app;
    return app.onExecute();
}