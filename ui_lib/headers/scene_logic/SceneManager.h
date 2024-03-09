#pragma once

#include "Scene.h"

#include <unordered_map>
#include <string>
#include <functional>

using std::unordered_map;
using std::string;
using std::function;

/**
 * A singleton class used for managing concrete Scenes. Holds the already initialized
 * instances of given scenes, so that when user switches from scene to scene and then back,
 * the contents of the original scene in the instance stay the same. If there isn't an instance
 * of given scene yet, it creates one from its `factories` map. If its desired to erase
 * the contents of the switched-from scene, `closeScene()` can be used to delete the instance.
 */
class SceneManager {
private:
    /// Holds initialized instances of scenes
    unordered_map<string, Scene *> scenes;
    /// Holds factories for scenes
    unordered_map<string, function<Scene *()>> scene_factories;
    /// id of the current scene
    string current_id;
    /// id of a scene to close in the next update, most of time is null
    string scene_to_close_id;

    static SceneManager* instance;

    SceneManager();

    virtual ~SceneManager();

public:

    /**
     * Returns pointer to the singleton instance of the SceneManager
     * @return the only instance
     */
    static SceneManager* get();

    /**
     * Adds a factory for creating an instance of a scene class into inner `scene_factories`
     * map. Does not create instance nor set this as a current scene.
     * @param id identification of the newly added scene
     * @param scene_factory function returning instance of given scene
     * @return true if scene was successfully registered
     */
    bool registerScene(const string &id, function<Scene *()> scene_factory);

    /**
     * Switches to another registered scene.
     * @param id identification of the scene to switch to
     * @return true if scene was switches successfully
     */
    bool switchScene(const string &id);

    /**
     * Deletes instance of a scene with given id in the next update cycle.
     * Used to properly close scenes and not just unactivate them.
     * @param id identification of the scene to delete
     */
    void closeScene(const string &id);

    /**
     * Updates the current scene with the current input
     * @param input_data the current input data and events
     * @param elapsed_time time elapsed since last main loop iteration in milliseconds
     * @return if current scene was successfully updated
     */
    bool updateCurrent(InputData *input_data, Uint64 elapsed_time);

    /**
     * Renders the current scene onto the renderer
     * @param window the window of the app
     * @param renderer the renderer which is the scene rendered onto
     * @return true on success
     */
    bool renderCurrent(SDL_Window *window, SDL_Renderer *renderer);
};
