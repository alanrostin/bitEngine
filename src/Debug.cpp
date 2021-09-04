#include "Debug.hpp"

std::vector<sf::RectangleShape> Debug::rects = {};
std::vector<std::array<sf::Vertex, 2>> Debug::lines = {};

void Debug::handleCameraZoom(Window& window, InputManager& inputManager)
{
    if (inputManager.isKeyUp(InputManager::Key::LBracket))
    {
        sf::View view = window.getView();
        view.zoom(1.1f);
        window.setView(view);
    }
    else if (inputManager.isKeyUp(InputManager::Key::RBracket))
    {
        sf::View view = window.getView();
        view.zoom(0.9f);
        window.setView(view);
    }
}

void Debug::render(Window& window)
{
    for (auto& rect : rects)
    {
        window.render(rect);
    }

    rects.clear();

    for (auto& l : lines)
    {
        sf::Vertex line[2] = { l.at(0), l.at(1) };
        window.render(line, 2, sf::Lines);
    }

    lines.clear();
}

void Debug::drawRect(const sf::FloatRect& rect, sf::Color color)
{
    sf::Vector2f size(rect.width, rect.height);
    sf::Vector2f position(rect.left, rect.top);
    sf::RectangleShape shape(size);

    shape.setPosition(position);
    shape.setOutlineColor(color);
    shape.setOutlineThickness(3.0f);
    shape.setFillColor(sf::Color::Transparent);

    rects.push_back(shape);
}

void Debug::drawLine(const sf::Vector2f& from, 
    const sf::Vector2f& to, sf::Color color)
{
    lines.push_back({ sf::Vertex(from, color), 
        sf::Vertex(to, color)});
}

void Debug::log(const std::string& msg)
{
    std::cout << msg << std::endl;
}

void Debug::logWarning(const std::string& msg)
{
    std::cout << "WARNING: " << msg << std::endl;
}

void Debug::logError(const std::string& msg)
{
    std::cout << "ERROR: " << msg << std::endl;
}