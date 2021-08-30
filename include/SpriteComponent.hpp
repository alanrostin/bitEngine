#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Component.hpp"
#include "TransformComponent.hpp"
#include "ResourceManager.hpp"

class SpriteComponent : public Component
{
    public:
        SpriteComponent(Object* object);

        void setTextureManager(ResourceManager<sf::Texture>* resourceManager);
        
        void load(int textureId);
        void load(const std::string& filePath);

        void lateUpdate(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        ResourceManager<sf::Texture>* resourceManager;
        sf::Sprite sprite;
};

#endif