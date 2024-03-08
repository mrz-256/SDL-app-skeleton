#pragma once

#include "../resources/global_resources.h"

class SceneManager;

class Scene {
protected:
    SceneManager* manager;

public:

    explicit Scene(SceneManager *manager);

    virtual ~Scene();

    virtual void update() = 0;

    virtual void render(SDL_Renderer* renderer) = 0;


};
