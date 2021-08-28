#include "SceneGame.hpp"

SceneGame::SceneGame()
{

}

void SceneGame::onCreate()
{
    bitmanTexture.loadFromFile("content/player/bitman_idle.png");
    bitmanSprite.setTexture(bitmanTexture);
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
    const sf::Vector2f& spritePos = bitmanSprite.getPosition();
    const int moveSpeed = 100;
    int xMove = 0;

    if (inputManager.isKeyPressed(InputManager::Key::Left))
    {
        xMove = -moveSpeed;
    }
    else if (inputManager.isKeyPressed(InputManager::Key::Right))
    {
        xMove = moveSpeed;
    }

    int yMove = 0;

    if (inputManager.isKeyDown(InputManager::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (inputManager.isKeyDown(InputManager::Key::Down))
    {
        yMove = moveSpeed;
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    bitmanSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

void SceneGame::render(Window& window)
{
    window.render(bitmanSprite);
}
