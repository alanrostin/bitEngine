#include "Engine.hpp"

Engine::Engine() : m_Window("bitman")
{
    bitmanTexture.loadFromFile("content/player/bitman_idle.png");
    bitmanSprite.setTexture(bitmanTexture);
}

void Engine::update()
{
    m_Window.update();
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