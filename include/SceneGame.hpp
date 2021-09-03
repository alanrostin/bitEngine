#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "InputManager.hpp"
#include "ContentPath.hpp"
#include "Object.hpp"
#include "SpriteComponent.hpp"
#include "KeyboardMovementComponent.hpp"
#include "ResourceManager.hpp"
#include "ObjectManager.hpp"
#include "TileMapParser.hpp"
#include "AnimationComponent.hpp"
#include "BoxColliderComponent.hpp"
#include "Debug.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame(ContentPath& contentPath, ResourceManager<sf::Texture>& textureManager);
        void onCreate() override;
        void onDestroy() override;
        void processInput() override;
        void update(float deltaTime) override;
        void lateUpdate(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        // std::shared_ptr<Object> player;
        ContentPath& contentPath;
        InputManager inputManager;
        ResourceManager<sf::Texture>& textureManager;
        ObjectManager objects;
        TileMapParser tileMapParser;
};

#endif