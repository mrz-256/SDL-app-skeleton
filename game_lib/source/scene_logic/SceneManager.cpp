#include <utility>

#include "headers/scene_logic/SceneManager.h"

SceneManager::SceneManager() : scenes(), scene_factories()
{
    current_id = "";
    scene_to_close_id = "";
}

SceneManager::~SceneManager()
{}

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
