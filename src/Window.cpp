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

sf::FloatRect Window::getViewSpace() const
{
    const sf::View& view = getView();
    const sf::Vector2f& viewCenter = view.getCenter();
    const sf::Vector2f& viewSize = view.getSize();

    sf::Vector2f viewSizeHalf(viewSize.x * 0.5f, viewSize.y * 0.5f);
    sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);

    return viewSpace;
}

const sf::View& Window::getView() const
{
    return window.getView();
}

void Window::setView(const sf::View& view)
{
    window.setView(view);
}

bool Window::isOpen() const
{
    return window.isOpen();
}