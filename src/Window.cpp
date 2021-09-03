#include "Window.hpp"

Window::Window(const std::string& windowTitle) : window(sf::VideoMode(1600, 900), windowTitle, sf::Style::Default)
{
    window.setVerticalSyncEnabled(true);
}

void Window::update()
{
    sf::Event event;

    if (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Window::startRender()
{
    window.clear(sf::Color::Black);
}

void Window::render(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::render(const sf::Vertex* vertices, 
    std::size_t vertexCount, sf::PrimitiveType primitiveType)
{
    window.draw(vertices, vertexCount, primitiveType);
}

void Window::endRender()
{
    window.display();
}

sf::Vector2u Window::getCenter() const
{
    sf::Vector2u size = window.getSize();
    
    return sf::Vector2u(size.x / 2, size.y / 2);
}

bool Window::isOpen() const
{
    return window.isOpen();
}