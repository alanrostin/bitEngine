#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine() : scenes(0), currentScene(0)
{

}

void SceneStateMachine::processInput()
{
    if (currentScene)
    {
        currentScene -> processInput();
    }
}

void SceneStateMachine::update(float deltaTime)
{
    if (currentScene)
    {
        currentScene -> update(deltaTime);
    }
}

void SceneStateMachine::lateUpdate(float deltaTime)
{
    if (currentScene)
    {
        currentScene -> lateUpdate(deltaTime);
    }
}

void SceneStateMachine::render(Window& window)
{
    if (currentScene)
    {
        currentScene -> render(window);
    }
}

int SceneStateMachine::addScene(std::shared_ptr<Scene> scene)
{
    auto insertedScene = scenes.insert(std::make_pair(insertedSceneId, scene));
    insertedSceneId++;
    insertedScene.first -> second -> onCreate();

    return insertedSceneId - 1;
}

void SceneStateMachine::removeScene(int sceneId)
{
    auto it = scenes.find(sceneId);

    if (it != scenes.end())
    {
        if (currentScene == it -> second)
        {
            currentScene = nullptr;
        }

        it -> second -> onDestroy();
        scenes.erase(it);
    }
}

void SceneStateMachine::switchToScene(int sceneId)
{
    auto it = scenes.find(sceneId);

    if (it != scenes.end())
    {
        if (currentScene)
        {
            currentScene -> onDeactivate();
        }

        currentScene = it -> second;
        currentScene -> onActivate();
    }
}