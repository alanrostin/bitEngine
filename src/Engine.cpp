#include "Engine.hpp"

Engine::Engine() : m_Window("bitman")
{
    bitmanTexture.loadFromFile("content/player/bitman_idle.png");
    bitmanSprite.setTexture(bitmanTexture);

    deltaTime = clock.restart().asSeconds();
}

void Engine::update()
{
    m_Window.update();

    const sf::Vector2f& spritePos = bitmanSprite.getPosition();
    const int moveSpeed = 100;
    int xMove = 0;

    if (m_InputManager.isKeyPressed(InputManager::Key::Left))
    {
        xMove = -moveSpeed;
    }
    else if (m_InputManager.isKeyPressed(InputManager::Key::Right))
    {
        xMove = moveSpeed;
    }

    int yMove = 0;
    if (m_InputManager.isKeyPressed(InputManager::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (m_InputManager.isKeyPressed(InputManager::Key::Down))
    {
        yMove = moveSpeed;
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    bitmanSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

void Engine::lateUpdate()
{

}

void Engine::render()
{
    m_Window.startRender();
    m_Window.render(bitmanSprite);
    m_Window.endRender();
}

bool Engine::isRunning() const
{
    return m_Window.isOpen();
}

void Engine::calculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}

void Engine::captureInput()
{
    m_InputManager.update();
}