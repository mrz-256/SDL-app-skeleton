#include "../../headers/ui/UI.h"

UI::UI() : window(nullptr), renderer(nullptr), running(true)
{
    screen_size = 500;
}

int UI::onExecute()
{
    // initialization part
    if (not onInit()) return -1;
    if (not onLoadMedia()) return -2;

    // input data
    Uint64 last = SDL_GetTicks64();
    auto *input_data = new InputData{SDL_GetKeyboardState(nullptr)};

    // register scenes
    SceneManager::get()->registerScene("scene_one", [this]() {
        return new ExampleScene(window, renderer);
    });
    SceneManager::get()->registerScene("scene_two", [this]() {
        return new ExampleSceneTwo(window, renderer);
    });
    SceneManager::get()->switchScene("scene_one");


    // main loop
    SDL_ShowWindow(window);
    while (running)
    {
        Uint64 elapsed_time = SDL_GetTicks64() - last;
        if (elapsed_time < 1000 / 60) continue;
        last = SDL_GetTicks64();

        onInput(input_data);
        onLoop(input_data, elapsed_time);
        onRender();
    }

    onCleanup();
    return 0;
}


int main()
{
    UI ui;
    return ui.onExecute();
}