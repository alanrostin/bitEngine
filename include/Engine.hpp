#ifndef Engine_hpp
#define Engine_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ContentPath.hpp"
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
        Window window;
        ContentPath contentPath;
        
        sf::Clock clock;
        float deltaTime;

        SceneStateMachine sceneStateMachine;
        ResourceManager<sf::Texture> textureManager;
};

#endif