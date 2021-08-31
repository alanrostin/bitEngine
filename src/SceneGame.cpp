#include "SceneGame.hpp"

SceneGame::SceneGame(ResourceManager<sf::Texture>& textureManager) 
    : textureManager(textureManager)
{

}

void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();
    
    // Adds a component by calling our previously written template function.
    auto sprite = player -> addComponent<SpriteComponent>();
    sprite -> setTextureManager(&textureManager);
    sprite -> load("content/player/bitman_idle.png");

    auto movement = player -> addComponent<KeyboardMovementComponent>();
    movement -> setInput(&inputManager);

    objects.addObject(player);
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
    objects.processRemoveObjects();
    objects.processNewObjects();
    objects.update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime)
{
    objects.lateUpdate(deltaTime);
}

void SceneGame::render(Window& window)
{
    objects.render(window);
}
