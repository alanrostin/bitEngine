#ifndef Window_hpp
#define Window_hpp

#include <SFML/Graphics.hpp>

class Window
{
    public:
        Window(const std::string& windowTitle);
        void update();

        void startRender();
        void render(const sf::Drawable& drawable);
        void render(const sf::Vertex* vertices, 
            std::size_t vertexCount, sf::PrimitiveType primitiveType);
        void endRender();

        sf::Vector2u getCenter() const;
        sf::FloatRect getViewSpace() const;

        const sf::View& getView() const;
        void setView(const sf::View& view);
        
        bool isOpen() const;
    
    private:
        sf::RenderWindow window;
};

#endif