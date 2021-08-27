#include "Engine.hpp"

Engine::Engine() : m_Window("bitman")
{

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
    m_Window.endRender();
}

bool Engine::isRunning() const
{
    return m_Window.isOpen();
}