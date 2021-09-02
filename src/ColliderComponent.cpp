#include "ColliderComponent.hpp"

ColliderComponent::ColliderComponent(Object* object) 
    : Component(object), collisionLayer(CollisionLayer::Default)
{

}

ColliderComponent::~ColliderComponent() {}

CollisionLayer ColliderComponent::getLayer() const
{
    return collisionLayer;
}

void ColliderComponent::setLayer(CollisionLayer collisionLayer)
{
    this -> collisionLayer = collisionLayer;
}

