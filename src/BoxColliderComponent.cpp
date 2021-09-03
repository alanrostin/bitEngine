#include "BoxColliderComponent.hpp"
#include "Object.hpp"

BoxColliderComponent::BoxColliderComponent(Object* object) 
    : ColliderComponent(object), offset(sf::Vector2f(0.0f, 0.0f))
{

}

BoxColliderComponent::~BoxColliderComponent()
{
    
}

Manifold BoxColliderComponent::intersects(std::shared_ptr<ColliderComponent> collider)
{
    Manifold manifold;
    manifold.colliding = false;

    std::shared_ptr<BoxColliderComponent> boxCollider 
        = std::dynamic_pointer_cast<BoxColliderComponent>(collider);
    
    if (boxCollider)
    {
        const sf::FloatRect& rect1 = getCollidable();
        const sf::FloatRect& rect2 = boxCollider -> getCollidable();

        if (rect1.intersects(rect2))
        {
            manifold.colliding = true;
            manifold.collider = &rect2;
        }
    }

    return manifold;
}

void BoxColliderComponent::resolveOverlap(const Manifold& manifold)
{
    auto transform = object -> transform;

    if (transform -> isStatic())
    {
        return;
    }

    const sf::FloatRect& rect1 = getCollidable();
    const sf::FloatRect* rect2 = manifold.collider;

    float resolve = 0;
    float xDiff = (rect1.left + (rect1.width * 0.5f)) - (rect2 -> left + (rect2 -> width * 0.5f));
    float yDiff = (rect1.top + (rect1.height * 0.5f)) - (rect2 -> top + (rect2 -> height * 0.5f));

    if (fabs(xDiff) > fabs(yDiff))
    {
        if (xDiff > 0)
        {
            resolve = (rect2 -> left + rect2 -> width) - rect1.left;
        }
        else
        {
            resolve = -((rect1.left + rect1.width) - rect2 -> left);
        }

        transform -> addPosition(resolve, 0);
    }
    else
    {
        if (yDiff > 0)
        {
            resolve = (rect2 -> top + rect2 -> height) - rect1.top;
        }
        else
        {
            resolve = -((rect1.top + rect1.height) - rect2 -> top);
        }

        transform -> addPosition(0, resolve);
    }
}

void BoxColliderComponent::setCollidable(const sf::FloatRect& rect)
{
    AABB = rect;
    setPosition();
}

const sf::FloatRect& BoxColliderComponent::getCollidable()
{
    setPosition();
    return AABB;
}

void BoxColliderComponent::setPosition()
{
    const sf::Vector2f& posistion = object -> transform -> getPosition();
    AABB.left = posistion.x - (AABB.width / 2) + offset.x;
    AABB.top = posistion.y - (AABB.height / 2) + offset.y;
}

void BoxColliderComponent::setOffset(const sf::Vector2f& offset)
{
    this -> offset = offset;
}

void BoxColliderComponent::setOffset(float x, float y)
{
    offset.x = x;
    offset.y = y;
}

void BoxColliderComponent::setSize(const sf::Vector2f& size)
{
    AABB.width = size.x;
    AABB.height = size.y;
}

void BoxColliderComponent::setSize(float width, float height)
{
    AABB.width = width;
    AABB.height = height;
}