#include "headers/scenes/ExampleSceneTwo.h"
#include "../../headers/scene_logic/SceneManager.h"

ExampleSceneTwo::~ExampleSceneTwo() = default;

ExampleSceneTwo::ExampleSceneTwo(SDL_Window *window, SDL_Renderer *renderer)
: Scene(window, renderer)
{}

void ExampleSceneTwo::update(InputData *input_data, Uint64 elapsed_time)
{
    if (input_data->keyboard[SDL_SCANCODE_LEFT])
    {
        SceneManager::get()->switchScene("scene_one");
    }
}

void ExampleSceneTwo::render(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xff, 0xaa);
    SDL_RenderClear(renderer);

    SDL_SetWindowTitle(window, "Example scene two");
}
