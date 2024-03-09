#pragma once


#include "../scene_logic/Scene.h"

class ExampleSceneTwo : public Scene {
public:
    ~ExampleSceneTwo() override;

    ExampleSceneTwo(SDL_Window *window, SDL_Renderer *renderer);

    void update(InputData *input_data, Uint64 elapsed_time) override;

    void render(SDL_Window *window, SDL_Renderer *renderer) override;
};


