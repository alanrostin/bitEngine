#ifndef BoxColliderComponent_hpp
#define BoxColliderComponent_hpp

#include "Component.hpp"
#include "ColliderComponent.hpp"

class BoxColliderComponent : public ColliderComponent
{
    public:
        BoxColliderComponent(Object* object);
        Manifold intersects(std::shared_ptr<ColliderComponent> collider) override;
        void resolveOverlap(const Manifold& manifold) override;
        void setCollidable(const sf::FloatRect& rect);
        const sf::FloatRect& getCollidable();
    
    private:
        void setPosition();
        sf::FloatRect AABB;
        sf::Vector2f offset;
};

#endif