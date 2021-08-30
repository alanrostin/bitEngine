#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Object* owner) : Component(owner)
{

}

void SpriteComponent::load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void SpriteComponent::render(Window& window)
{
    window.render(sprite);
}