#ifndef Engine_hpp
#define Engine_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.hpp"
#include "InputManager.hpp"

class Engine
{
    public:
        Engine();
        void update();
        void lateUpdate();
        void render();
        bool isRunning() const;
        void calculateDeltaTime();
        void captureInput();
    
    private:
        sf::Clock clock;
        float deltaTime;
        Window m_Window;
        sf::Texture bitmanTexture;
        sf::Sprite bitmanSprite;
        InputManager m_InputManager;
};

#endif