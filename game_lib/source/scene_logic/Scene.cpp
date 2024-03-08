#include "headers/scene_logic/Scene.h"
#include "headers/scene_logic/SceneManager.h"


Scene::Scene(SceneManager *manager) : manager(manager)
{}

Scene::~Scene() = default;

void Scene::setFocus()
{}

void Scene::loseFocus()
{}

void Scene::close()
{}