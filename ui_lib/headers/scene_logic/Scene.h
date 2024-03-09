#pragma once

#include "../resources/global_resources.h"
#include "../ui/InputData.h"

class SceneManager;

/**
 * A virtual class used for each scene in ui.
 * Each concrete Scene, inheriting from this class, should then be put into SceneManager.
 */
class Scene {
public:

    /**
     * Creates the scene.
     * @param window may be necessary to initialize some scene fields
     * @param renderer may be necessary to initialize some scene fields
     */
    Scene(SDL_Window* window, SDL_Renderer* renderer);

    virtual ~Scene();

    /**
     * Updates the scene with input data
     * @param input_data inputted data and events
     * @param elapsed_time elapsed time since last update in milliseconds
     */
    virtual void update(InputData* input_data, Uint64 elapsed_time) = 0;

    /**
     * Renders everything necessary in this scene onto provided renderer
     * @param window the window of the app
     * @param renderer the renderer which the scene is rendered to
     */
    virtual void render(SDL_Window* window, SDL_Renderer* renderer) = 0;

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
     * loaded data and such.
     */
    virtual void close();

};
