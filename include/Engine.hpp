#ifndef Engine_hpp
#define Engine_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Window.hpp"
#include "InputManager.hpp"
#include "SceneStateMachine.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneGame.hpp"

class Engine
{
    public:
        Engine();
        void processInput();
        void update();
        void lateUpdate();
        void render();
        bool isRunning() const;
        void calculateDeltaTime();
    
    private:
        sf::Clock clock;
        float deltaTime;
        Window window;
        sf::Texture bitmanTexture;
        sf::Sprite bitmanSprite;
        InputManager inputManager;
        SceneStateMachine sceneStateMachine;
        ResourceManager<sf::Texture> textureManager;
};

#endif