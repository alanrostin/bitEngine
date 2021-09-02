#ifndef ColliderComponent_hpp
#define ColliderComponent_hpp

#include <SFML/Graphics.hpp>
#include <memory>
#include "Component.hpp"

enum class CollisionLayer
{
    Default = 1,
    Player = 2,
    Tile = 3
};

struct Manifold
{
    bool colliding = false;
    const sf::FloatRect* collider;
};

class ColliderComponent : public Component
{
    public:
        ColliderComponent(Object* object);
        ~ColliderComponent();
        virtual Manifold intersects(std::shared_ptr<ColliderComponent> collider) = 0;
        virtual void resolveOverlap(const Manifold& manifold) = 0;
        CollisionLayer getLayer() const;
        void setLayer(CollisionLayer collisionLayer);
    
    private:
        CollisionLayer collisionLayer;
};

#endif
