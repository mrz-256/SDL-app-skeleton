#include "../../headers/scenes/ExampleScene.h"
#include "../../headers/scene_logic/SceneManager.h"

ExampleScene::~ExampleScene() = default;

ExampleScene::ExampleScene(SDL_Window *window, SDL_Renderer *renderer)
        : Scene(window, renderer), cat()
{
    cat.loadFrom(renderer, "../assets/cat.jpg");
    cat.scale(0.1, 0.1);
}

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

    cat.render(window, renderer, 100, 100);

    SDL_SetWindowTitle(window, "Example scene");
}
