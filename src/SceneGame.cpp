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
    
}

void SceneGame::render(Window& window)
{
    player -> render(window);
}
