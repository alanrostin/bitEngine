#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Component.hpp"
#include "TransformComponent.hpp"

class SpriteComponent : public Component
{
    public:
        SpriteComponent(Object* object);

        void load(const std::string& filePath);

        void lateUpdate(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif