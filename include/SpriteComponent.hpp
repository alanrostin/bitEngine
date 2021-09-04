#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Component.hpp"
#include "TransformComponent.hpp"
#include "ResourceManager.hpp"
#include "DrawableComponent.hpp"

class SpriteComponent : public Component, public DrawableComponent
{
    public:
        SpriteComponent(Object* object);

        void setTextureManager(ResourceManager<sf::Texture>* resourceManager);
        
        void load(int textureId);
        void load(const std::string& filePath);

        void lateUpdate(float deltaTime) override;
        void render(Window& window) override;
        bool continueToRender() const override;

        void setTextureRect(int x, int y, int width, int height);
        void setTextureRect(const sf::IntRect& rect);

        void setScale(float x, float y);
    
    private:
        ResourceManager<sf::Texture>* resourceManager;
        sf::Sprite sprite;
        int currentTextureId;
};

#endif