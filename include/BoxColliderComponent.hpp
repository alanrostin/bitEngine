#ifndef BoxColliderComponent_hpp
#define BoxColliderComponent_hpp

#include <math.h>
#include "Component.hpp"
#include "ColliderComponent.hpp"

class BoxColliderComponent : public ColliderComponent
{
    public:
        BoxColliderComponent(Object* object);
        ~BoxColliderComponent();

        Manifold intersects(std::shared_ptr<ColliderComponent> collider) override;
        void resolveOverlap(const Manifold& manifold) override;
        void setCollidable(const sf::FloatRect& rect);
        const sf::FloatRect& getCollidable();

        void setOffset(const sf::Vector2f& offset);
        void setOffset(float x, float y);
        void setSize(const sf::Vector2f& size);
        void setSize(float width, float height);
    
    private:
        void setPosition();
        sf::FloatRect AABB;
        sf::Vector2f offset;
};

#endif