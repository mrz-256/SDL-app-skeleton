#pragma once

#include "../scene_logic/Scene.h"

class ExampleScene : public Scene {
public:
    ~ExampleScene() override;

    void update(InputData *input_data, Uint64 elapsed_time) override;

    void render(SDL_Window *window, SDL_Renderer *renderer) override;
};


