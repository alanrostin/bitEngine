#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "InputManager.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame();
        void onCreate() override;
        void onDestroy() override;
        void processInput() override;
        void update(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        sf::Texture bitmanTexture;
        sf::Sprite bitmanSprite;
        InputManager inputManager;
};

#endif