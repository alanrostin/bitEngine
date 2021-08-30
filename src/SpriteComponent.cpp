#include "SpriteComponent.hpp"
#include "Object.hpp"

SpriteComponent::SpriteComponent(Object* object) : Component(object)
{

}

void SpriteComponent::load(const std::string& filePath)
{
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

void SpriteComponent::lateUpdate(float deltaTime)
{
    sprite.setPosition(object -> transform -> getPosition());
}

void SpriteComponent::render(Window& window)
{
    window.render(sprite);
}