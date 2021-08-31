#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "InputManager.hpp"
#include "Object.hpp"
#include "SpriteComponent.hpp"
#include "KeyboardMovementComponent.hpp"
#include "ResourceManager.hpp"
#include "ObjectManager.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame(ResourceManager<sf::Texture>& textureManager);
        void onCreate() override;
        void onDestroy() override;
        void processInput() override;
        void update(float deltaTime) override;
        void lateUpdate(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        std::shared_ptr<Object> player;
        InputManager inputManager;
        ResourceManager<sf::Texture>& textureManager;
        ObjectManager objects;
};

#endif