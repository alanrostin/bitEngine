#include "Window.hpp"

Window::Window(const std::string& windowTitle) : m_Window(sf::VideoMode(800, 600), windowTitle, sf::Style::Default)
{
    m_Window.setVerticalSyncEnabled(true);
}

void Window::update()
{
    sf::Event event;

    if (m_Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_Window.close();
        }
    }
}

void Window::startRender()
{
    m_Window.clear(sf::Color::Black);
}

void Window::render(const sf::Drawable& drawable)
{
    m_Window.draw(drawable);
}

void Window::endRender()
{
    m_Window.display();
}

sf::Vector2u Window::getCenter() const
{
    sf::Vector2u size = m_Window.getSize();
    
    return sf::Vector2u(size.x / 2, size.y / 2);
}

bool Window::isOpen() const
{
    return m_Window.isOpen();
}