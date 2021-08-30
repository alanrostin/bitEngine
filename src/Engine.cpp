#include "Engine.hpp"

Engine::Engine() : window("bitman")
{
    std::shared_ptr<SceneSplashScreen> splashScreen 
        = std::make_shared<SceneSplashScreen>(sceneStateMachine, window, textureManager);

    std::shared_ptr<SceneGame> gameScene = std::make_shared<SceneGame>(textureManager);

    unsigned int splashScreenId = sceneStateMachine.addScene(splashScreen);
    unsigned int gameSceneId = sceneStateMachine.addScene(gameScene);

    splashScreen -> setSwitchToScene(gameSceneId);
    sceneStateMachine.switchToScene(splashScreenId);

    deltaTime = clock.restart().asSeconds();
}

void Engine::processInput()
{
    sceneStateMachine.processInput();
}

void Engine::update()
{
    window.update();
    sceneStateMachine.update(deltaTime);
}

void Engine::lateUpdate()
{
    sceneStateMachine.lateUpdate(deltaTime);
}

void Engine::render()
{
    window.startRender();
    sceneStateMachine.render(window);
    window.endRender();
}

bool Engine::isRunning() const
{
    return window.isOpen();
}

void Engine::calculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}