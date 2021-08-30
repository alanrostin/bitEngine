#include "TransformComponent.hpp"

TransformComponent::TransformComponent(Object* object) : Component(object), position(0.0f, 0.0f)
{

}

void TransformComponent::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void TransformComponent::setPosition(const sf::Vector2f& pos)
{
    position = pos;
}

void TransformComponent::addPosition(float x, float y)
{
    position.x += x;
    position.y += y;
}

void TransformComponent::addPosition(sf::Vector2f pos)
{
    position += pos;
}

void TransformComponent::setX(float x)
{
    position.x = x;
}

void TransformComponent::setY(float y)
{
    position.y = y;
}

void TransformComponent::addX(float x)
{
    position.x += x;
}

void TransformComponent::addY(float y)
{
    position.y += y;
}

const sf::Vector2f& TransformComponent::getPosition() const
{
    return position;
}