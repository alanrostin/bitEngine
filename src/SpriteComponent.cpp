#include "SpriteComponent.hpp"
#include "Object.hpp"

SpriteComponent::SpriteComponent(Object* object) : Component(object)
{

}

void SpriteComponent::setTextureManager(ResourceManager<sf::Texture>* resourceManager)
{
    this -> resourceManager = resourceManager;
}

void SpriteComponent::load(int textureId)
{
    if (textureId >= 0)
    {
        std::shared_ptr<sf::Texture> texture = resourceManager -> getResource(textureId);
        sprite.setTexture(*texture);
    }
}

void SpriteComponent::load(const std::string& filePath)
{
    if (resourceManager)
    {
        int textureId = resourceManager -> addResource(filePath);

        if (textureId >= 0)
        {
            std::shared_ptr<sf::Texture> texture = resourceManager -> getResource(textureId);
            sprite.setTexture(*texture);
        }
    }
}

void SpriteComponent::lateUpdate(float deltaTime)
{
    sprite.setPosition(object -> transform -> getPosition());
}

void SpriteComponent::render(Window& window)
{
    window.render(sprite);
}