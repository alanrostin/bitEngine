#ifndef Debug_hpp
#define Debug_hpp

#include <array>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "Window.hpp"

class Debug
{
    public:
        static void render(Window& window);
        static void drawRect(const sf::FloatRect& rect, 
            sf::Color color = sf::Color::White);
        static void drawLine(const sf::Vector2f& from, 
            const sf::Vector2f& to, sf::Color color = sf::Color::White);
        static void log(const std::string& msg);
        static void logWarning(const std::string& msg);
        static void logError(const std::string& msg);
    
    private:
        static std::vector<sf::RectangleShape> rects;
        static std::vector<std::array<sf::Vertex, 2>> lines;
};

#endif