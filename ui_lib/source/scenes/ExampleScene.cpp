#include "../../headers/scenes/ExampleScene.h"
#include "../../headers/scene_logic/SceneManager.h"

ExampleScene::~ExampleScene() = default;

void ExampleScene::update(InputData *input_data, Uint64 elapsed_time)
{
    if (input_data->keyboard[SDL_SCANCODE_RIGHT])
    {
        SceneManager::get()->switchScene("scene_two");
    }
}

void ExampleScene::render(SDL_Window *window, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xaa, 0xaa, 0xaa);
    SDL_RenderClear(renderer);

    SDL_SetWindowTitle(window, "Example scene");
}