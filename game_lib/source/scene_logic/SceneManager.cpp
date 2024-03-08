#include <utility>

#include "headers/scene_logic/SceneManager.h"

SceneManager::SceneManager() : scenes(), scene_factories()
{
    current_id = "";
    scene_to_close_id = "";
}

SceneManager::~SceneManager()
{
    for(auto& [id, scene] : scenes)
    {
        if (scene != nullptr)
        {
            scene->close();
            delete scene;
        }
    }
}

bool SceneManager::registerScene(const string &id, function<Scene *()> scene_factory)
{
    // id is already registered with a scene
    if (scene_factories.count(id))
    {
        return false;
    }

    scene_factories[id] = std::move(scene_factory);
    return true;
}

bool SceneManager::switchScene(const string &id)
{
    if (scene_factories.count(id) == 0) return false;

    // if there is instance of previous scene, un-focus it
    if (scenes[current_id] != nullptr){
        scenes[current_id]->loseFocus();
    }

    // if there is no instance with this id, create it
    if (scenes[id] == nullptr)
    {
        scenes[id] = scene_factories[id]();
    }

    // update current id and focus
    scenes[id]->setFocus();
    current_id = id;
    return true;
}

void SceneManager::closeScene(const string &id)
{
    scene_to_close_id = id;
}

bool SceneManager::updateCurrent(InputData *input_data, Uint64 elapsed_time)
{
    // close the to_close scene
    if (!scene_to_close_id.empty() and scenes[scene_to_close_id] != nullptr)
    {
        scenes[scene_to_close_id]->close();
        delete scenes[scene_to_close_id];
    }

    if (scenes[current_id] == nullptr) return false;

    scenes[current_id]->update(input_data, elapsed_time);
    return true;
}

bool SceneManager::renderCurrent(SDL_Window *window, SDL_Renderer *renderer)
{
    if (scenes[current_id] == nullptr) return false;

    scenes[current_id]->render(window, renderer);
    return true;
}

// define instance of singleton
SceneManager* SceneManager::instance = nullptr;

SceneManager *SceneManager::get()
{
    if (SceneManager::instance == nullptr)
    {
        SceneManager::instance = new SceneManager();
    }
    return SceneManager::instance;
}
