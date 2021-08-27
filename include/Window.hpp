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
        void endRender();
        bool isOpen() const;
    
    private:
        sf::RenderWindow m_Window;
};

#endif