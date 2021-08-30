#include "SceneGame.hpp"

SceneGame::SceneGame()
{

}

void SceneGame::onCreate()
{
    player = std::make_shared<Object>();

    // Adds a component by calling our previously written template function.
    auto sprite = player -> addComponent<SpriteComponent>();
    sprite -> load("content/player/bitman_idle.png");

    auto movement = player -> addComponent<KeyboardMovementComponent>();

    movement -> setInput(&inputManager);
}

void SceneGame::onDestroy()
{

}

void SceneGame::processInput()
{
    inputManager.update();
}

void SceneGame::update(float deltaTime)
{
    player -> update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime)
{
    player -> lateUpdate(deltaTime);
}

void SceneGame::render(Window& window)
{
    player -> render(window);
}
