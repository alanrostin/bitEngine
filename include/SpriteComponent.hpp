#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Component.hpp"

class SpriteComponent : public Component
{
    public:
        SpriteComponent(Object* owner);
        void load(const std::string& filePath);
        void render(Window& window) override;
    
    private:
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif