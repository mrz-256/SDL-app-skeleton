#pragma once

#include "../resources/global_resources.h"

class SceneManager;

/**
 * A virtual class used for each scene in ui.
 */
class Scene {
protected:
    SceneManager* manager;

public:

    explicit Scene(SceneManager *manager);

    virtual ~Scene();

    /**
     * Updates data in this scene. TODO: PASS IN THE INPUT DATA
     */
    virtual void update() = 0;

    /**
     * Renders everything necessary in this scene onto provided renderer
     * @param renderer the renderer which the scene is rendered to
     */
    virtual void render(SDL_Renderer* renderer) = 0;

    /**
     * Executed when scene switches from being the current scene.
     * Can be used to temporally unload some unnecessary resources.
     */
    virtual void loseFocus();

    /**
     * Executed when the scene is set as the current scene.
     * Can be used to load some temporally resources.
     */
    virtual void setFocus();

    /**
     * Executed when scene is to be closed before calling destructor. Used to store
     * data and such.
     */
    virtual void close();

};
